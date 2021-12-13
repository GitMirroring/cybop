/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPLETENESS_CHECK_SOCKET_SENSOR_SOURCE
#define COMPLETENESS_CHECK_SOCKET_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
//?? --
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/representer/deserialiser/message_length/message_length_deserialiser.c"
//?? #include "../../../executor/sensor/socket/length_check_socket_sensor.c"

/**
 * Checks if the message is complete, that is if
 * all data belonging to it have been received.
 *
 * @param p0 the complete flag
 * @param p1 the message length (possibly detected previously)
 * @param p2 the buffer item
 * @param p3 the language (protocol)
 */
void sense_socket_check_completeness(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* l = (int*) p1;

        //
        // CAUTION! Do NOT log messages within thread,
        // in order to avoid race conditions and other conflicts.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket check completeness.");
        fwprintf(stdout, L"Debug: Sense socket check completeness. message length p1: %i\n", p1);
        fwprintf(stdout, L"Debug: Sense socket check completeness. message length *p1: %i\n", *((int*) p1));

        // The buffer item data, count.
        void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Get buffer item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        // CAUTION! The buffer data and count HAVE TO be determined here
        // in EACH loop cycle ANEW, since the arrays inside might have
        // got reallocated and changed!
        //
        copy_array_forward((void*) &bd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bc, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // The buffer item count casted to the correct type.
        int* bct = (int*) bc;

        //
        // CAUTION! The length was initialised with -1.
        // Use >= operator and not only > since an otherwise EMPTY message
        // with length 0 might contain a termination suffix such as crlf anyway.
        //
        if (*l >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // The message length WAS DETECTED as prefix within the message
            // in a PREVIOUS loop cycle.
            //

            if (*bct >= *l) {

                //
                // The expected number (message length) of characters has been received.
                //

                // Set complete flag.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                // Reset message length.
                copy_integer(p1, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
            }

        } else {

            //
            // The message length was NOT detected as prefix within the message before.
            // Therefore, parse the message and SEARCH for either a PREFIX message length
            // or SUFFIX sequence marking the end of the message.
            //
            // Examples:
            // - http has a "Content-Length:" header entry as prefix.
            // - some binary protocols have a crlf termination
            //

            deserialise_message_length(p1, bd, bc, p3);

            //?? REPLACE the following code with function call:
            //?? sense_socket_check_length(...);

            //
            // CAUTION! The length was initialised with -1.
            // Use >= operator and not only > since an otherwise EMPTY message
            // with length 0 might contain a termination suffix such as crlf anyway.
            //
            // CAUTION! Check buffer count a SECOND TIME here (already checked once above)
            // since it may happen that the message fragment just read before contains
            // the message length and is ALREADY COMPLETE, so that a next fragment
            // does NOT have to be read.
            //
            // If the buffer count was not checked here and only in the next loop cycle
            // then the thread would BLOCK due to the next message fragment "read" call
            // (at least if no other separate message is following).
            //
            if (*l >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //
                // The message length WAS DETECTED as prefix within the message.
                //

                if (*bct >= *l) {

                    //
                    // The expected number (message length) of characters has been received.
                    //

                    // Set complete flag.
                    copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    // Reset message length.
                    copy_integer(p1, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
                }
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket check completeness. The message length is null.");
        fwprintf(stdout, L"Error: Could not sense socket check completeness. The message length is null. p1: %i\n", p1);
    }
}

/* COMPLETENESS_CHECK_SOCKET_SENSOR_SOURCE */
#endif
