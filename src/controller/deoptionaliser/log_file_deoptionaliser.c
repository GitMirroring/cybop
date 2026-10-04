/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // FILE, fclose, EOF
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Deoptionalises the log file option.
 *
 * @param p0 the log file stream (pointer reference)
 */
void deoptionalise_log_file(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE** f = (FILE**) p0;

        //
        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        //
        // log_write((void*) stdout, L"Debug: Deoptionalise log file.\n");
        //

        //
        // CAUTION! This test is necessary! Do NOT delete it!
        // Checking the file stream argument above is not sufficient,
        // since a segmentation fault will occur here,
        // if no log file is given as command line argument at system startup.
        //
        if (((void*) *f) != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Close log file.
            int e = fclose(*f);

            if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //
                // Reset log file pointer.
                //
                // CAUTION! Hand over the log file stream AS REFERENCE!
                // This is necessary, because it is reset to null here.
                // If this was not done, subsequent logger calls would cause segmentation faults,
                // because the null pointer test within the logger would be successful,
                // even though the LOG_OUTPUT pointer would be invalid.
                //
                *f = *NULL_POINTER_STATE_CYBOI_MODEL;

            } else {

                //
                // An error occured.
                //

                if (e == EOF) {

                    fwprintf(stdout, L"Error: Could not deoptionalise log file. The error EOF was detected on closing the file. e: %i\n", e);

                    //
                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    // Do NOT show the following message, as it would only disturb the user!
                    //
                    // log_write((void*) stdout, L"Error: Could not deoptionalise log file. The error EOF was detected on closing the file.\n");
                    //

                } else {

                    fwprintf(stdout, L"Error: Could not deoptionalise log file. An unknown error was detected on closing the file. e: %i\n", e);

                    //
                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    // Do NOT show the following message, as it would only disturb the user!
                    //
                    // log_write((void*) stdout, L"Error: Could not deoptionalise log file. An unknown error was detected on closing the file.\n");
                    //
                }
            }

        } else {

            //
            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Do NOT show the following message, as it would only disturb the user!
            //
            // log_write((void*) stdout, L"Warning: Could not deoptionalise log file. No log file was given at system startup.\n");
            //
        }

    } else {

        //
        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Do NOT show the following message, as it would only disturb the user!
        //
        log_write((void*) stdout, L"Error: Could not deoptionalise log file. The file descriptor is null.\n");
    }
}
