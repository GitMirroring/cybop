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

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

//
// System interface
//

#include <stdio.h> // stdin, stdout, stderr

//
// Library interface
//

#include "constant.h"
#include "controller.h"

//
// Executable interface
//

//
// CAUTION! This file "copier.c" is actually NOT needed but included anyway,
// since it references file "item_allocator.c" which is needed here.
//
#include "../executor/copier/copier.c"
#include "../executor/copier/integer_copier.c"
//
// CAUTION! Do NOT include file "item_allocator.c" to avoid circular references.
// It gets included via "copier.c" and "part_allocator.c".
//
//?? #include "../executor/memoriser/allocator/item_allocator.c"
//
#include "../executor/memoriser/deallocator/item_deallocator.c"
#include "../logger/logger.c"
#include "../variable/log_setting.c"

//
// Testing functionality
//

//?? #include "../variable/reference_counter.c"

//
// Windows specific stuff
//
// (possibly OUTDATED and may be deleted once compiling on windows)
//

#ifdef _MSC_VER          // see: http://msdn.microsoft.com/de-de/library/b0084kay.aspx

    #if (_MSC_VER < 1800) // Check Visual Studio version, C99 is not supported in versions below VS2013
        #error Visual Studio 2013 or higher is required for successful build of this application
    #endif

//??    #define PTW32_STATIC_LIB //use pthread.lib built with static linking see http://www.technologische-hilfe.de/antworten/pthreads-win32-statisch-linken-support-230866062.html
    //#define WIN32_LEAN_AND_MEAN // avoids compiler errors in VS related to duplicate definitions from includes in windows.h and winsock2.h, see http://www.gamedev.net/topic/127476-define-win32_lean_and_mean/
    //#define _TM_DEFINED // avoids redeclaration of time_t in glibc time.h
    //#define _TIMESPEC_DEFINED; // avoids redeclaration of timespec in pthread.h
    #define _CRT_NONSTDC_NO_DEPRECATE // avoids errors related to deprecated CRT functions see http://msdn.microsoft.com/de-de/library/ms235384(v=vs.90).aspx
    #define _CRT_SECURE_NO_WARNINGS // allows use of unsecure functions see http://msdn.microsoft.com/de-de/library/8ef0s5kh.aspx
    #define _USE_MATH_DEFINES
#endif

/**
 * The main entry function.
 *
 * The Cybernetics Oriented Interpreter (CYBOI) can interpret
 * Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extensible Markup Language (XML) syntax.
 *
 * @param p0 the arguments count (argc) which also counts the name of the programme being run
 * @param p1 the arguments vector (argv), the first argument being the file name of the programme being run;
 *           the pointer array p1 contains null-terminated C strings;
 *           a string is a character array, i.e. pointer to the first array element;
 *           since cyboi uses wide characters everywhere possible,
 *           and also for standard input- and output streams,
 *           it can be expected that argv contains multibyte strings which
 *           have to be converted into wide character strings before being processed;
 *           this is done in the "optionaliser" module
 * @return the return value (0 for normal shutdown; 1 for error)
 */
int main(int p0, char** p1) {

/*??
#ifdef _MSC_VER
    #ifdef PTW32_STATIC_LIB
        pthread_win32_process_attach_np(); // see README.NONPORTABLE in pthread source directory
        pthread_win32_thread_attach_np(); // Currently a no-op
    #endif
#endif
*/

    //
    // One note about dynamic memory allocation:
    //
    // There is no point in freeing blocks at the end of an application programme,
    // because all of the programme's space is given back to the operating system
    // when the process terminates.
    //
    // Of course, all dynamically allocated memory should also be freed properly.
    // However, if some memory to be deallocated is forgotten accidentally,
    // it will not harm the operating system, as the memory occupied by
    // the application will be freed automatically on process shutdown.
    //

    // Return 1 to indicate an error, by default.
    int r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // There is NO use to test the parametre p0, because it
    // always has at least the value 1, since it also
    // counts the name of the programme being run.
    //
    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT log message here, since the logger gets initialised only further below.
        //

        // Startup global variables.
        globalise();

        //
        // Orient streams.
        //
        // CAUTION! This is important for internationalisation!
        // A stream can be used EITHER for wide operations OR for normal operations.
        // Once it is decided there is NO WAY BACK.
        // Only a call to freopen or freopen64 can reset the orientation.
        //
        // The orientation can be decided in three ways:
        // 1 If any of the normal character functions is used
        //   (this includes the fread and fwrite functions)
        //   the stream is marked as not wide oriented.
        // 2 If any of the wide character functions is used the stream is marked as wide oriented.
        // 3 The fwide function can be used to set the orientation either way.
        //
        // It is important to NEVER MIX the use of wide and not wide operations on a stream!
        // There are no diagnostics issued. The application behavior will simply be strange
        // or the application will simply crash. The "fwide" function can help avoiding this.
        // It can be used to set and query the state of the orientation of a stream.
        // Note, that it is NOT possible to overwrite previous orientations with "fwide".
        // That is, if a stream was already oriented before, NOTHING is done!
        //
        // It is generally a good idea to orient a stream as early as possible.
        // This can prevent surprise and hard to reproduce errors,
        // especially for the standard streams stdin, stdout, and stdout.
        //
        // Since a stream is created in the unoriented state
        // it has at that point no conversion associated with it.
        // The conversion which will be used is determined by the
        // LC_CTYPE category selected at the time the stream is oriented.
        // If the locales are changed at the runtime this might
        // produce surprising results unless one pays attention.
        // This is just another good reason to orient the stream
        // explicitly as soon as possible, perhaps with a call to "fwide".
        //
        // The encoding used for the wchar_t values is unspecified
        // and the user must not make any assumptions about it.
        // For I/O of wchar_t values this means that it is impossible
        // to write these values directly to the stream.
        // This is not what follows from the ISO C locale model either.
        // What happens instead is that the bytes read from or written
        // to the underlying media are first converted into the internal
        // encoding chosen by the implementation for wchar_t.
        // The external encoding is determined by the LC_CTYPE category
        // of the current locale or by the ccs part of the mode specification
        // given to fopen, fopen64, freopen, or freopen64.
        // How and when the conversion happens is unspecified and it happens invisible to the user.
        //
        // CAUTION! The orientations of the following streams have to be set HERE,
        // because command line parametres will be expected to be multibyte characters,
        // read from the standard input stream in function "optionalise" further below.
        // They will also get converted into wide characters of type "wchar_t" there.
        //
        orient((void*) stdin, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        orient((void*) stdout, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        orient((void*) stderr, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        //?? fwprintf(stdout, L"Debug: ARRAY_REFERENCE_COUNTER BEGIN: %i\n", *ARRAY_REFERENCE_COUNTER);
        //?? fwprintf(stdout, L"Debug: ITEM_REFERENCE_COUNTER BEGIN: %i\n", *ITEM_REFERENCE_COUNTER);
        //?? fwprintf(stdout, L"Debug: PART_REFERENCE_COUNTER BEGIN: %i\n", *PART_REFERENCE_COUNTER);

        //
        // The operation mode.
        //
        // CAUTION! It is initialised with the help operation mode,
        // in order to display the help message by default,
        // if no command line argument is given by the user.
        //
        int m = *HELP_OPERATION_MODE_CYBOI_MODEL;
        // The cybol knowledge file path item.
        void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The test unit.
        int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        //
        // Allocate cybol knowledge file path item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &k, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Optionalise command line argument options.
        optionalise((void*) &m, k, (void*) LOG_LEVEL, (void*) &t, (void*) &LOG_OUTPUT, (void*) p1, (void*) &p0);

        //
        // Orient log output file stream.
        //
        // CAUTION! This can only be done AFTER having read the command line options,
        // since one of the options determines the log output file name.
        //
        orient(LOG_OUTPUT, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Run cyboi.");
        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Globalised global variables already.");
        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Optionalised log file already.");

        if (m == *VERSION_OPERATION_MODE_CYBOI_MODEL) {

            // Print version information on screen.
            inform((void*) stdout);

        } else if (m == *HELP_OPERATION_MODE_CYBOI_MODEL) {

            // Print help message on screen.
            help((void*) stdout);

        } else if (m == *KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL) {

            // Manage system startup and shutdown using the given cybol knowledge file.
            manage(k);
        }

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Unglobalise global variables yet.");

        //
        // Deoptionalise command line argument options.
        //
        // CAUTION! Hand over the LOG_OUTPUT variable AS REFERENCE!
        // This is necessary, because it is reset to NULL internally.
        // If this was not done, subsequent logger calls would cause segmentation faults,
        // because the null pointer test within the logger would be successful,
        // even though the LOG_OUTPUT pointer would be invalid.
        //
        deoptionalise((void*) &LOG_OUTPUT);

        // Deallocate cybol knowledge file path.
        deallocate_item((void*) &k, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        //?? fwprintf(stdout, L"Debug: ARRAY_REFERENCE_COUNTER END: %i\n", *ARRAY_REFERENCE_COUNTER);
        //?? fwprintf(stdout, L"Debug: ITEM_REFERENCE_COUNTER END: %i\n", *ITEM_REFERENCE_COUNTER);
        //?? fwprintf(stdout, L"Debug: PART_REFERENCE_COUNTER END: %i\n", *PART_REFERENCE_COUNTER);

        // Shutdown global variables.
        unglobalise();

        log_write(stdout, L"Information: Exit cyboi normally.\n");

        // Set return value to 0, to indicate proper shutdown.
        copy_integer((void*) &r, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        log_write(stdout, L"Error: Could not execute cyboi. The command line argument vector is null.\n");
    }

/*??
#ifdef _MSC_VER
    #ifdef PTW32_STATIC_LIB
        pthread_win32_process_detach_np();
        pthread_win32_thread_detach_np();
    #endif
#endif
*/

/*??
#ifdef _DEBUG
    getchar();
#endif
*/

    return r;
}

/* CYBOI_SOURCE */
#endif
