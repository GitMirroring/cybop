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

#include <stdlib.h> // free

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h"

/**
 * Deallocates the array.
 *
 * @param p0 the array (pointer reference)
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the array element type
 */
void deallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** a = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate array.");

        // CAUTION! Test array for null value.
        // It is true, the "free" function normally does not
        // cause an error when handing over a null value.
        // However, the code is cleaner when testing for null.
        if (*a != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // This function may cause an error if some wrong pointer
            // is forwarded to it as argument.
            // If this happens and the system crashes right here showing
            // a "Segmentation fault" or the like, then it is not the fault
            // of the "free" function but of the pointer passed on to it.
            // Somewhere else in the code, the pointer was manipulated
            // and probably set wrong, e.g. outside an allocated area.
            free(*a);

            // Reset array to null value.
            // CAUTION! This is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            *a = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Decrement array reference counter.
            // CAUTION! This is ONLY needed for debugging.
            (*ARRAY_REFERENCE_COUNTER)--;

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate array. The dereferenced array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate array. The array is null.");
    }
}
