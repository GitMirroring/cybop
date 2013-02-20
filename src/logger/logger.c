/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
#include "../variable/log_setting.c"

//?? TEMPORARY TEST
static int TEST_REFERENCE_COUNT = 0;

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
// (The following remark is possibly OUTDATED, since threads are now
// limited to sensing signals and do NOT use logging anymore.)
//
// CAUTION! The logger must not allocate any memory area, since it
// might be used not only by the main process, but in threads as well.
// Therefore, a log message array gets allocated at cyboi system startup,
// and is forwarded as global variable "LOG_MESSAGE" to the logger.
// Whenever a log message is copied to this array and written to console,
// a MUTEX has to be set BEFORE, so that the log output does not conflict
// between the main program flow and threads.
// Trying to allocate memory in a thread would result in an error like:
//
// *** glibc detected *** malloc(): memory corruption (fast): 0x080e0470 ***
// Aborted
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
 * Writes a terminated log message to the given output stream.
 *
 * CAUTION! The "write" function is not used here, because it expects
 * a multibyte character sequence.
 * The log message, however, is handed over with a null termination wide character,
 * so that it may be passed on to either of the "fputws" or "fwprintf" function.
 * Since it seems simpler and presumably is faster, the decision here fell on the "fputws" function.
 *
 * @param p0 the log output stream
 * @param p1 the log message
 */
void log_write(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* m = (wchar_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            FILE* s = (FILE*) p0;

            fputws(m, s);

        } else {

            // CAUTION! Do NOT call the logger here.
            // It cannot log itself.
            // This is commented out, in order to avoid annoying messages.
            // fputws(L"Error: Could not write terminated log message. The log output stream is null.\n", stdout);
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It cannot log itself.
        fputws(L"Error: Could not write terminated log message. The log message is null.\n", stdout);
    }
}

/**
 * Gets the log level name.
 *
 * @param p0 the log level name (pointer reference)
 * @param p1 the log level name count
 * @param p2 the log level
 */
void log_get_level_name(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DEBUG_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) ERROR_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &ERROR_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) ERROR_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WARNING_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &WARNING_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) WARNING_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }
}

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
        log_get_level_name((void*) &ln, (void*) &lnc, p0);

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

/* LOGGER_SOURCE */
#endif
