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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Writes source data into inline destination item.
 *
 * @param p0 the destination item
 * @param p1 the source buffer item
 * @param p2 the source buffer type
 * @param p3 the source buffer mutex
 * @param p4 the loop break flag
 */
void write_inline(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write inline.");
    fwprintf(stdout, L"Debug: Write inline. p0: %i\n", p0);

    // The buffer item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Lock mutex.
    //
    // CAUTION! New data may be written into the source buffer in
    // the main thread, in case this writer is called asynchronously
    // in a thread. But the already WRITTEN data are REMOVED from
    // the source buffer below. Therefore, exclusive access has
    // to be guaranteed here using a mutex.
    //
    // CAUTION! The mutex also has to cover the actual MODIFY function,
    // since the buffer pointer handed over may otherwise CHANGE,
    // when the main thread writes new data into the buffer.
    // For the same reason, the mutex has to cover the
    // RETRIEVAL of data and count from the item.
    //
    lock(p3);

    //
    // Get buffer item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Copy source to destination.
    modify_item(p0, bd, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, bc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Remove written data from source buffer.
    //
    // CAUTION! This is IMPORTANT, so that in the next loop
    // cycle, only the REMAINING data are transmitted.
    //
    // CAUTION! Do NOT use the function "modify_array" here,
    // but "modify_item" instead.
    //
    // CAUTION! Hand over the buffer COUNT for specifying
    // the number of elements to be removed.
    //
    // CAUTION! Set the adjust count flag to TRUE since otherwise,
    // the buffer item will hold a wrong COUNT number leading
    // to unpredictable errors in further processing.
    // Do NOT worry about the SIZE which does NOT get changed.
    //
    modify_item(p1, *NULL_POINTER_STATE_CYBOI_MODEL, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, bc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(p3);

    //
    // Set loop break flag.
    //
    // The buffer data have been copied ALL AT ONCE.
    // Therefore, further loop cycles are not necessary.
    //
    copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
}
