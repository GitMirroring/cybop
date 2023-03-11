/*
 * Copyright (C) 1999-2023. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UTF_8_DECODER_SOURCE
#define UTF_8_DECODER_SOURCE

#include <errno.h> // errno

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/memoriser/reallocator/item_reallocator.c"
#include "logger.h"

#if defined(__linux__) || defined(__unix__)
    #include <locale.h> // setlocale
    #include <wchar.h> // wcsnrtombs
#elif defined(__APPLE__) && defined(__MACH__)
    #include <locale.h> // setlocale
    #include <wchar.h> // wcsnrtombs
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <windows.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Reflexions on character set conversion.
//
// A Unix C library such as the GNU C library contains three different sets
// of functions in two families to handle character set conversion:
//
// 1 First Family
// - specified in the ISO C90 standard
// - portable even beyond the Unix world
// - most commonly used but the least useful one;
//   its functions should be avoided whenever possible
// - the wide character set is fixed by the implementation
//   (in the case of GNU C library it is always UCS-4 encoded ISO 10646)
// - if neither the source nor the destination character set is the character set used
//   for wchar_t representation, there is at least a two-step conversion process necessary
// - character set assumed for multibyte encoding is not specified as an argument to the functions;
//   instead, the character set specified by the LC_CTYPE category of the current locale is used;
//   for every conversion where neither the source nor the destination character set is the character set
//   of the locale for the LC_CTYPE category, one has to change the LC_CTYPE locale using "setlocale";
//   parallel conversions to and from different character sets are not possible,
//   since the LC_CTYPE selection is global and shared by all threads
// - self-made observation (not taken from the GNU C library manual):
//   not all Unicode characters are contained in one of the standard locales;
//   e.g. special Unicode Box drawing characters are useful when creating a Text User Interfaces (TUI);
//   but unfortunately, they are missing in the existing locales;
//   an example for such a missing Unicode character is this one:
//   U+2570 box drawings light arc up and right
//
// 1.1 First Function Set "Non-reentrant Conversion"
// - defined in original ISO C90 standard
// - almost entirely useless
// - one cannot first convert single characters and then strings
//   since one cannot tell the conversion functions which state to use
// - usable only in a very limited set of situations
// - one must complete converting the entire string before starting a new one
// - each string/text must be converted with the same function
// - highly requested that the "Restartable Multibyte Conversion" functions
//   be used in place of non-reentrant conversion functions
//
// 1.2 Second Function Set "Restartable Multibyte Conversion"
// - defined in Amendment 1 to ISO C90 standard
// - convert strings from a multibyte representation to wide character strings
// - functions handling more than one character at a time require NUL terminated strings as the argument
//   (converting blocks of text does not work unless one can add a NUL byte at an appropriate place);
//   the GNU C library contains some extensions to the standard that allow specifying a size,
//   but basically they also expect terminated strings
// - can be used in many contexts, e.g. if the text itself comes from a file with
//   translations and the user can decide about the current locale, which determines
//   the translation and therefore also the external encoding used
//
// 2 Second Family
// - third function set: generic charset conversion
// - introduced in the early Unix standards (XPG2)
// - still part of the latest and greatest Unix standard: Unix 98
// - defines a completely new set of most powerful and useful functions
//
// 2.1 Third Function Set "Generic Charset Conversion"
// - defines "iconv" functions as interface; does not provide an implementation
// - provide more freedom while performing the conversion
// - not at all coupled to the selected locales;
//   has no constraints on the character sets selected for source and destination;
//   only limited by the set of available conversions;
//   does not specify that any conversion at all must be available
// - problems with the specification of the iconv functions can lead to portability issues
// - since it is not practical to encode the conversions directly in the C library,
//   the conversion information must come from files outside the C library:
//
// a Loading Conversion Tables from Data Files
// - C library contains a set of generic conversion functions
// - data files are loaded when necessary
// - requires a great deal of effort to apply to all character sets (potentially an infinite set)
// - differences in the structure of the different character sets is so large,
//   that many different variants of the table-processing functions must be developed
// - the generic nature of these functions make them slower than specifically implemented functions
//
// b Dynamically Loading Object Files
// - execute the conversion functions contained in object files
// - provides much more flexibility
// - with documented interface, third parties may extend the set of available conversion modules
// - dynamic loading must be available
// - design is limiting on platforms (outside ELF) that do not support dynamic loading in statically linked programs
// - number of available conversions in iconv implementations is often very limited
// - most problematic point, that the way the iconv conversion functions are implemented on all known Unix systems:
//   the availability of the conversion functions from character set A to B and
//   the conversion from B to C does not imply that the conversion from A to C is available
//
// Because of these drawbacks of all of the three function sets described above, it seems
// inevitable to -- one day -- write "self-made", CYBOI-internal conversion functions.
//

//
// UTF-8 (8-bit UCS/Unicode Transformation Format) is a variable-length
// character encoding for Unicode.
//
// It is able to represent any character in the Unicode standard, yet the
// initial encoding of byte codes and character assignments for utf-8 is
// backwards compatible with ascii. For these reasons, it is steadily becoming
// the preferred encoding for e-mail, web pages, and other places where
// characters are stored or streamed.
//
// UTF-8 encodes each character in one to four octets (8-bit bytes):
// 1 One byte is needed to encode the 128 US-ASCII characters
//   (Unicode range U+0000 to U+007F)
// 2 Two bytes are needed for Latin letters with diacritics and for characters
//   from Greek, Cyrillic, Armenian, Hebrew, Arabic, Syriac and Thaana alphabets
//   (Unicode range U+0080 to U+07FF)
// 3 Three bytes are needed for the rest of the Basic Multilingual Plane
//   (which contains virtually all characters in common use)
// 4 Four bytes are needed for characters in the other planes of Unicode,
//   which are rarely used in practice
//
// Four bytes may seem like a lot for one character (code point). However,
// code points outside the Basic Multilingual Plane are generally very rare.
// Furthermore, utf-16 (the main alternative to utf-8) also needs four bytes
// for these code points. Whether utf-8 or utf-16 is more efficient depends
// on the range of code points being used. However, the differences between
// different encoding schemes can become negligible with the use of
// traditional compression systems like DEFLATE. For short items of text
// where traditional algorithms do not perform well and size is important,
// the Standard Compression Scheme for Unicode could be considered instead.
//
// The Internet Engineering Task Force (IETF) requires all Internet protocols
// to identify the encoding used for character data with utf-8 as at least one
// supported encoding. The Internet Mail Consortium (IMC) recommends that all
// email programs be able to display and create mail using utf-8.
//

/**
 * Decodes the utf-8 multibyte character data into utf-32 wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_utf_8(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode utf-8.");
            //?? fwprintf(stdout, L"Debug: Decode utf-8. source count p2: %i\n", p2);
            //?? fwprintf(stdout, L"Debug: Decode utf-8. source count *p2: %i\n", *((int*) p2));

            // The destination item data, count, size.
            void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The new destination size.
            int nds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Get destination item count, size.
            copy_array_forward((void*) &dc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &ds, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

            //
            // Initialise new destination size.
            //
            // CAUTION! The "worst case" is assumed, i.e. that each source character
            // represents an ascii character encoded by utf-8 with ONE single byte.
            // Therefore, the destination size is adjusted accordingly, so that
            // the source character count determines the destination character count.
            //
            // In case not all source characters are ascii characters -- even better,
            // since then more than just one source character were used for encoding,
            // and the destination wide character array will have LESS entries (count)
            // than the destination size that was set before. In this case,
            // the destination size will be too big, but that doesn't matter.
            //
            calculate_integer_add((void*) &nds, p2);

            if (ds != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // The destination item size casted to the correct type.
                int* dst = (int*) ds;

                if (nds > *dst) {

                    //
                    // The new destination size is greater than the old.
                    //
                    // CAUTION! The destination item DOES get reallocated,
                    // since its size is not great enough to store all source data.
                    //
                    // Some buffers such as for terminal ansi escape code input
                    // are filled repeatedly in a loop, so that steady reallocation
                    // would harm performance. This condition is just an optimisation.
                    //

                    if (nds > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        //
                        // Reallocate destination item.
                        //
                        // CAUTION! Due to memory allocation handling, the size MUST NOT
                        // be negative or zero, but have at least a value of ONE.
                        //
                        reallocate_item(p0, (void*) &nds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode utf-8. The new destination size is zero or negative.");
                        fwprintf(stdout, L"Error: Could not decode utf-8. The new destination size is zero or negative. nds: %i\n", nds);
                    }
                }

                //
                // Set locale.
                //
                // Possible locales are: LANG, LC_CTYPE, ..., LC_ALL
                // where LANG has the lowest and LC_ALL the highest priority.
                // That is, if LC_ALL is specified, it overwrites e.g. the LC_CTYPE setting.
                // If no value "" is given, the default will be used.
                // Note, that LC_CTYPE suffices for the purpose of character conversion,
                // since it is the category that applies to classification and conversion
                // of characters, and to multibyte and wide characters.
                //
                // CAUTION! This setting IS NECESSARY for utf-8 character conversion
                // with restartable multibyte conversion functions like "mbsnrtowcs"
                // and "wcsnrtombs" to work correctly.
                // The return value is not used; this is a GLOBAL setting.
                //
                char* loc = setlocale(LC_CTYPE, "");

                //
                // Get destination item data.
                //
                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                // Inside the structure, arrays may have been reallocated,
                // with elements pointing to different memory areas now.
                //
                copy_array_forward((void*) &dd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

                //
                // The temporary size_t variable.
                //
                // CAUTION! It IS NECESSARY because on 64 Bit machines,
                // the "size_t" type has a size of 8 Byte,
                // whereas the "int" type has the usual size of 4 Byte.
                // When trying to cast between the two, memory errors
                // will occur and the valgrind memcheck tool report:
                // "Invalid read of size 8".
                //
                // CAUTION! Initialise temporary size_t variable with final int value
                // JUST BEFORE handing that over to the glibc function requiring it.
                //
                // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
                // because values are casted to int* internally again.
                //
                size_t tds = (size_t) *dst;
                size_t tsc = (size_t) *sc;

                //
                // Initialise error number.
                //
                // It is a global variable and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                //
                // Converts the multibyte character string into a wide character string.
                // Returns the number of wide characters
                // successfully converted, except in the case of an encoding error.
                //
                // CAUTION! The multibyte source character string does NOT need to be
                // null-terminated, since the third parametre already indicates its count.
                //
                // CAUTION! Hand over the NEW destination size as fourth parametre,
                // since it indicates the maximum number of characters to be converted
                // and conversion would break too early if that parametre was too small.
                //
                // CAUTION! The fifth parametre may be NULL. In this case, a static
                // anonymous state only known to the function internally is used instead.
                // It just indicates where conversion is started.
                //
                int n = -1;
#if defined(__linux__) || defined(__unix__)
                const char* sd = (const char*) p1;
                n = (int) mbsnrtowcs((wchar_t*) dd, &sd, tsc, tds, (mbstate_t*) *NULL_POINTER_STATE_CYBOI_MODEL);
#elif defined(__APPLE__) && defined(__MACH__)
                const char* sd = (const char*) p1;
                n = (int) mbsnrtowcs((wchar_t*) dd, &sd, tsc, tds, (mbstate_t*) *NULL_POINTER_STATE_CYBOI_MODEL);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                LPCSTR sd = (LPCSTR) p1;
                int len = MultiByteToWideChar(65001, 0, sd, *sc, (LPWSTR) dd, 0);
                n =  MultiByteToWideChar(65001, 0, sd, *sc, (LPWSTR) dd, len);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

                if (n >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //?? fwprintf(stdout, L"Debug: Decode utf-8. n: %i\n", n);

                    // Set destination count to the number of WIDE characters converted.
                    copy_integer(dc, (void*) &n);

                    //?? fwprintf(stdout, L"Debug: Decode utf-8. dc: %i\n", dc);
                    //?? fwprintf(stdout, L"Debug: Decode utf-8. *dc: %i\n", *((int*) dc));
                    //?? fwprintf(stdout, L"Debug: Decode utf-8. dd: %ls\n", (wchar_t*) dd);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode utf-8. An error occured.");
                    fwprintf(stdout, L"Error: Could not decode utf-8. An error occured. n: %i\n", n);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode utf-8. The destination item size is null.");
                fwprintf(stdout, L"Error: Could not decode utf-8. The destination item size is null. ds: %i\n", ds);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode utf-8. The source data is null.");
            fwprintf(stdout, L"Error: Could not decode utf-8. The source data is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode utf-8. The source count is null.");
        fwprintf(stdout, L"Error: Could not decode utf-8. The source count is null. p2: %i\n", p2);
    }
}

/* UTF_8_DECODER_SOURCE */
#endif
