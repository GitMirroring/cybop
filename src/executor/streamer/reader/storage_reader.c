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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Reads data indirectly from buffer and stores them in the destination item.
 *
 * @param p0 the destination item
 * @param p1 the source buffer item
 * @param p2 the source buffer mutex
 * @param p3 the type
 * @param p4 the message length
 */
void read_storage(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read storage.");
    //?? fwprintf(stdout, L"Debug: Read storage. message length p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Read storage. message length *p4: %i\n", *((int*) p4));

    // The buffer item data.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Lock mutex.
    //
    // CAUTION! Set this lock BEFORE retrieving the item data and count below
    // since otherwise, a race condition might occur, e.g. when the sensing thread
    // appends data to the buffer, a new data array with bigger size might get allocated.
    // In order to get the correct data array here, the lock has to be set before.
    //
    lock(p2);

    //
    // Get buffer item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Append buffer data to destination message item.
    //
    // CAUTION! Do NOT hand over the buffer count but rather
    // the message LENGTH determined above for specifying
    // the number of characters to be appended.
    //
    // CAUTION! Do NOT use overwrite since data are read stepwise
    // as fragments and therefore have to be APPENDED to the
    // already existing data in the destination.
    //
    modify_item(p0, bd, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Remove data from buffer.
    //
    // CAUTION! This is important since otherwise,
    // the same data would be processed again and again.
    //
    // CAUTION! Do NOT EMPTY the buffer here since new data
    // might be added continuously within the sensing thread.
    //
    // CAUTION! Do NOT use the function "modify_array" here,
    // but "modify_item" instead. The destination item data
    // array pointer has most likely been changed above,
    // due to reallocation when appending the buffer data.
    // Using the variable bd as determined above would lead to errors.
    //
    // CAUTION! Do NOT hand over the buffer count but rather
    // the message length determined above for specifying
    // the number of characters to be removed.
    //
    // CAUTION! Set the adjust count flag to TRUE since otherwise,
    // the destination item will hold a wrong "count" number
    // leading to unpredictable errors in further processing.
    //
    modify_item(p1, *NULL_POINTER_STATE_CYBOI_MODEL, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(p2);
}
