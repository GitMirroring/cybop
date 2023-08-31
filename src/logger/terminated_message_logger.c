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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stddef.h> // wchar_t
#include <wchar.h> // wcslen, fputws, fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h" // LOG_MESSAGE_SIZE

/**
 * Logs a null character-terminated message.
 *
 * @param p0 the log level
 * @param p1 the log message as null terminated string
 */
void log_message_terminated(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* m = (wchar_t*) p1;

        // The message count.
        int c = wcslen(m);

        if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
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
            //
            int o = c + *NUMBER_15_INTEGER_STATE_CYBOI_MODEL;

            //?? fwprintf(stdout, L"Debug: Log message terminated. *LOG_MESSAGE_SIZE: %i\n", *LOG_MESSAGE_SIZE);
            //?? fwprintf(stdout, L"Debug: Log message terminated. c: %i\n", c);

            //
            // Test message count.
            //
            // CAUTION! This is important, since the destination
            // log message count is fixed and limited in size.
            //
            if (o > *LOG_MESSAGE_SIZE) {

                //
                // CAUTION! Do NOT call the logger here.
                // It cannot log itself.
                //
                fputws(L"Warning: Could not log message terminated. The message count gets limited to 1000 - 15.\n", stdout);

                // Limit message count.
                c = *LOG_MESSAGE_SIZE - *NUMBER_15_INTEGER_STATE_CYBOI_MODEL;
            }

            log_message(p0, p1, (void*) &c);

        } else if (c == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT call the logger here.
            // It cannot log itself.
            //
            fputws(L"Warning: Could not log message terminated. The message count is zero.\n", stdout);

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It cannot log itself.
            //
            fputws(L"Error: Could not log message terminated. The message count is negative.\n", stdout);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It cannot log itself.
        //
        fputws(L"Error: Could not log message terminated. The log message as null terminated string is null.\n", stdout);
    }
}
