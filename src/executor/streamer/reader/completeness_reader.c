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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Checks if the message is complete, with prefix or suffix
 * depending upon the given channel.
 *
 * @param p0 the complete flag
 * @param p1 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p2 the message item
 * @param p3 the language (protocol)
 * @param p4 the eof-or-close flag (that was possibly set inside the fragment-basic reader)
 * @param p5 the channel
 */
void read_completeness(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read completeness.");
    //?? fwprintf(stdout, L"Debug: Read completeness. channel p5: %i\n", p5);
    //?? fwprintf(stdout, L"Debug: Read completeness. channel *p5: %i\n", *((int*) p5));

    //
    // CAUTION! Setting the message LENGTH is IMPORTANT for
    // appending to and removing data from the buffer properly,
    // which is done in buffer reader used in ASYNCHRONOUS communication.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The close comparison result.
    int cr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set message length.
            //
            // CAUTION! Each event is complete in itself and just a pointer.
            // Therefore, the event message length is ONE.
            //
            copy_integer(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one event has been received.
            // Each event is complete in itself and just a pointer.
            // Therefore, a detection of a length prefix or end suffix
            // is NOT necessary here and the complete flag can be set right away.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! The message length does NOT have to be set here.
            //
            // It is used by the buffer reader in asynchronous communication,
            // but this channel CANNOT be read asynchronously.
            //

            //
            // Copy eof-or-close flag value.
            //
            // It was possibly set inside the fragment (basic) reader,
            // if the end-of-file (EOF) was reached.
            //
            copy_integer(p0, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! The message length does NOT have to be set here.
            //
            // It is used by the buffer reader in asynchronous communication,
            // but this channel CANNOT be read asynchronously.
            //

            //
            // Set complete flag.
            //
            // The inline data are always read at ONCE
            // and do NOT need the loop.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_length(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &cr, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (cr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The client socket peer closed the connexion.
                //
                // Therefore, the close flag was set inside
                // the fragment (basic) reader.
                //
                // CAUTION! There is NO use in detecting the
                // message length afterwards, since it is EMPTY.
                //

                // Copy eof-or-close flag value.
                copy_integer(p0, p4);

            } else {

                //
                // The client is still open for communication.
                //
                // CAUTION! Do NOT assign the eof-or-close flag
                // value afterwards since if doing so, it would
                // OVERWRITE the complete flag that was returned
                // from function "read_length".
                //

                read_length(p0, p1, p2, p3);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_length(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read completeness. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not read completeness. The channel is unknown. p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not read completeness. The channel is unknown. *p5: %i\n", *((int*) p5));
    }
}
