/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BUFFER_READER_SOURCE
#define BUFFER_READER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/modifier/array_modifier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../executor/porter/locker.c"
#include "../../../executor/streamer/reader/completeness_reader.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_type_mapper.c"

/**
 * Reads data indirectly from buffer (asynchronous mode).
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
    fwprintf(stdout, L"Debug: Read buffer. p3: %i\n", p3);

    // The buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item data, count, size.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bs = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    map_channel_to_type((void*) &t, p4);

    // Get buffer item from client entry.
    copy_array_forward((void*) &bi, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_CLIENT_STATE_CYBOI_NAME);
    // Get buffer mutex from client entry.
    copy_array_forward((void*) &bm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_CLIENT_STATE_CYBOI_NAME);

    //
    // Lock mutex.
    //
    // CAUTION! Set this lock BEFORE retrieving the item data and count below
    // since otherwise, a race condition might occur, e.g. when the sensing thread
    // appends data to the buffer, a new data array with bigger size might get allocated.
    // In order to get the correct data array here, the lock has to be set before.
    //
    lock(bm);

    //
    // Get buffer item data, count, size.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bs, bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    // Check for completeness by evaluating length prefix or end suffix.
    read_completeness((void*) &f, (void*) &ml, p0, p2, p3);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message is complete, that is all data
        // belonging to it have been received.
        //

        //
        // Append buffer data to destination message item.
        //
        // CAUTION! Do NOT hand over the buffer count but rather
        // the message length determined above for specifying
        // the number of characters to be appended.
        //
        // CAUTION! Do NOT use overwrite since data are read stepwise
        // as fragments and therefore have to be APPENDED to the
        // already existing data in the destination.
        //
        modify_item(p0, bd, (void*) &t, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &ml, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Remove data from buffer.
        //
        // CAUTION! This is important since otherwise,
        // the same data would be processed again and again.
        //
        // CAUTION! Do NOT EMPTY the buffer here since new data
        // might be added continuously within the sensing thread.
        //
        // CAUTION! Calling the function "modify_item" would work here,
        // but "modify_array" is used instead since the buffer item's
        // data and count have already been determined above.
        //
        // CAUTION! Do NOT hand over the buffer count but rather
        // the message length determined above for specifying
        // the number of characters to be removed.
        //
        // CAUTION! Set the adjust count flag to TRUE since otherwise,
        // the destination item will hold a wrong "count" number
        // leading to unpredictable errors in further processing.
        //
        modify_array((void*) &bd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ml, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, bc, bs, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
    }

    // Unlock mutex.
    unlock(bm);
}

/* BUFFER_READER_SOURCE */
#endif
