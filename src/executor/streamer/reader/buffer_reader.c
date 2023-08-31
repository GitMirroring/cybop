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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "mapper.h"

/**
 * Reads data indirectly from buffer, since the asynchronicity flag was set.
 *
 * That is, the data are not read from device, but from the client buffer,
 * into which they had been stored by a separate sensing thread before.
 *
 * @param p0 the destination item
 * @param p1 the client entry
 * @param p2 the language (protocol)
 * @param p3 the channel
 */
void read_buffer(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read buffer.");
    //?? fwprintf(stdout, L"Debug: Read buffer. p3: %i\n", p3);

    // The buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The message length.
    //
    // Since it gets compared inside, it should be initialised
    // with a value < 0, e.g. with -1.
    //
    int ml = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The data type.
    int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Map channel to datatype.
    map_channel_to_type((void*) &t, p3);

    // Get buffer item from client entry.
    copy_array_forward((void*) &bi, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get buffer mutex from client entry.
    copy_array_forward((void*) &bm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);

/*??
    //?? TEST BEGIN. Delete later.
    void* bic = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &bic, bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read buffer. client entry p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Read buffer. buffer item count bic: %i\n", bic);
    fwprintf(stdout, L"Debug: Read buffer. buffer item count *bic: %i\n", *((int*) bic));
    void* test_id = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &test_id, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read buffer. client identification test_id: %i\n", test_id);
    fwprintf(stdout, L"Debug: Read buffer. client identification *test_id: %i\n", *((int*) test_id));
    //?? TEST END
*/

    //
    // Check for completeness by evaluating length prefix and end suffix.
    //
    // The value of parametre "eof-or-close flag" may be NULL,
    // since it is only relevant for channel FILE,
    // which is not used in asynchronous mode, however.
    //
    read_completeness((void*) &f, (void*) &ml, bi, p2, *NULL_POINTER_STATE_CYBOI_MODEL, p3);

    //?? fwprintf(stdout, L"Debug: Read buffer. complete flag f: %i\n", f);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Read buffer. message length ml: %i\n", ml);

        if (ml >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // The message is complete, that is all data
            // belonging to it have been received.
            //

            // Read data indirectly from buffer and store them in destination item.
            read_storage(p0, bi, bm, (void*) &t, (void*) &ml);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read buffer. The message length is invalid.");
            fwprintf(stdout, L"Warning: Could not read buffer. The message length is invalid. ml: %i\n", ml);
        }
    }
}
