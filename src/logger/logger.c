/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include <wchar.h>

#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/level_name_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../logger/level_name_logger.c"
#include "../logger/write_logger.c"
#include "../variable/log_setting.c"

#ifdef WIN32
    #include <windows.h>
#endif

//
// CAUTION! This logger uses some CYBOI functions so that
// an ENDLESS LOOP might occur, if those functions call
// the logger in turn.
//
// In order to avoid circular references, cyboi functions
// used by the logger are NOT permitted to use the logger.
//

//
// CAUTION! Following some reflexions on logging. There are two possibilities:
//
// 1 New Console
//
// A new console has to be opened whenever a textual user interface is used.
// This way, the original console where the cyboi process was started may use
// standard ASCII characters, as can the log messages, logger and test output.
//
// 2 Logger Adaptation
//
// If using just one textual console (the one where the cyboi process was started),
// then only wide character functions may be used on it, without exception.
// The MIXING of normal characters and wide characters is NOT PERMITTED on
// one-and-the-same stream, as it would lead to unpredictable, untraceable errors,
// as the glibc documentation says.
// But this also means that all log messages have to be converted to wide characters.
//
// Since the glibc "write" function used by the old version of the logger could NOT
// handle wide characters, the functions "fputws" or "fwprintf" had to be used instead.
// But they in turn REQUIRE A TERMINATION wide character to be added.
// Adding such a termination requires the creation of a new wide character array to
// build the whole log message including: log level, actual message, termination character.
//

//
// CAUTION! Performance might suffer if allocating/ deallocating
// memory for every single log message.
//
// Just one more argument to use the global variable "LOG_MESSAGE".
//

//
// Forward declarations.
//

void calculate_integer_add(void* p0, void* p1);
void compare_integer_equal(void* p0, void* p1, void* p2);
void compare_integer_smaller_or_equal(void* p0, void* p1, void* p2);
void copy_integer(void* p0, void* p1);
void copy_pointer(void* p0, void* p1);
void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Logs the given message.
 *
 * CAUTION! This function cannot be called "log" as that name
 * is already used somewhere, probably by the glibc library.
 * If using it, the gcc compiler prints an error like the following:
 *
 * ../controller/../controller/manager/../../logger/logger.c:122: error: conflicting types for 'log'
 *
 * @param p0 the log level
 * @param p1 the log message
 * @param p2 the log message count
 */
void log_message(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_smaller_or_equal((void*) &r, p0, (void*) LOG_LEVEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Log message since the log level matches.

        // The log level name.
        void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
        int lnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The destination index.
        // CAUTION! Use zero as first destination index,
        // in order to overwrite the destination from the beginning.
        int di = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add name of the given log level to log entry.
        log_level_name((void*) &ln, (void*) &lnc, p0);

        // CAUTION! Do NOT use the "overwrite_array" function following,
        // since it resizes the destination array to make the message fit.
        // However, the log message is an array of fixed size.

        // Copy log level.
        copy_array_forward((void*) LOG_MESSAGE, ln, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &lnc, (void*) &di, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Calculate new destination index.
        calculate_integer_add((void*) &di, (void*) &lnc);

        // Copy colon.
        copy_array_forward((void*) LOG_MESSAGE, (void*) COLON_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &di, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Calculate new destination index.
        calculate_integer_add((void*) &di, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Copy space.
        copy_array_forward((void*) LOG_MESSAGE, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &di, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Calculate new destination index.
        calculate_integer_add((void*) &di, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Copy log message.
        copy_array_forward((void*) LOG_MESSAGE, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) &di, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Calculate new destination index.
        calculate_integer_add((void*) &di, p2);

        // Copy line feed control wide character.
        copy_array_forward((void*) LOG_MESSAGE, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &di, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Calculate new destination index.
        calculate_integer_add((void*) &di, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Copy null termination wide character.
        copy_array_forward((void*) LOG_MESSAGE, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &di, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Log message.
        log_write(*LOG_OUTPUT, (void*) LOG_MESSAGE);

    } else {

        // CAUTION! Do NOT write an error message here!
        // It is a wanted effect NOT to write a log message, NOR an error,
        // if the given log level is not within the log level tolerance
        // that was set as global variable at cyboi system startup.
    }
}

/**
 * Logs a null character-terminated message.
 *
 * @param p0 the log level
 * @param p1 the log message as null terminated string
 */
void log_message_terminated(void* p0, void* p1) {

    // The message count.
    int c = wcslen((wchar_t*) p1);
    // Calculate overall count.
    //
    // Some characters are added by default [Byte]:
    // 11 (the longest log level name is "information")
    //  1 (colon)
    //  1 (space)
    // xx (the actual message)
    //  1 line feed
    //  1 null termination
    // __
    // 15
    // ==
    int o = c + *NUMBER_15_INTEGER_STATE_CYBOI_MODEL;

    // Test message count.
    // CAUTION! This is important, since the destination
    // log message count is fixed and limited in size.
    if (o > *LOG_MESSAGE_SIZE) {

        // Limit message count.
        c = *LOG_MESSAGE_SIZE - o;
    }

    log_message(p0, p1, (void*) &c);
}

/**
 * Logs a windows system error.
 *
 * @param p0 the error code
 */
void log_windows_system_error(void* p0) {

#ifdef WIN32
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* e = (DWORD*) p0;

        // The local handle.
        HLOCAL l = (HLOCAL) *NULL_POINTER_STATE_CYBOI_MODEL;

        // Convert error code into message.
        BOOL b = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, (LPCVOID) *NULL_POINTER_STATE_CYBOI_MODEL, *e, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), (PTSTR) &l, 0, (va_list*) *NULL_POINTER_STATE_CYBOI_MODEL);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // A network-related error.

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not log windows system error. The FormatMessage function failed.");

            // Load dynamic link library.
            HMODULE dll = LoadLibraryEx(TEXT("netmsg.dll"), (HANDLE) *NULL_POINTER_STATE_CYBOI_MODEL, DONT_RESOLVE_DLL_REFERENCES);

            if (((void*) dll) != *NULL_POINTER_STATE_CYBOI_MODEL) {

                FormatMessage(FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM, dll, (DWORD) p0, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), (PTSTR) &l, 0, (va_list*) *NULL_POINTER_STATE_CYBOI_MODEL);
                FreeLibrary(dll);
            }
        }

        if (((void*) l) != *NULL_POINTER_STATE_CYBOI_MODEL) {

            MessageBox((HWND) *NULL_POINTER_STATE_CYBOI_MODEL, (LPCTSTR) LocalLock(l), TEXT("Windows Error in CYBOI"), MB_ICONERROR);
            LocalFree(l);
        }
    }
#endif
}

/* LOGGER_SOURCE */
#endif
