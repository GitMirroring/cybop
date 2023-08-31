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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "logger.h"

/**
 * Gets the knowledge part by knowledge path.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source part (pointer reference)
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void get_part_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part knowledge.");

        // The source part format, model item.
        void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source part format, model item data, count.
        void* sfd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source part format, model item.
        copy_array_forward((void*) &sf, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sm, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get source part format, model item data, count.
        copy_array_forward((void*) &sfd, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &r, sfd, (void*) CYBOL_PATH_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This IS a cybol PATH.
            //

/*??
            //?? TEST only
            if (smc == *NULL_POINTER_STATE_CYBOI_MODEL) {
                fwprintf(stdout, L"Debug: get part knowledge smc: %i\n", smc);
            } else {
                fwprintf(stdout, L"Debug: get part knowledge *smc: %i\n", *((int*) smc));
            }
            fwprintf(stdout, L"Debug: get part knowledge smd: %ls\n", (wchar_t*) smd);
*/

            // The source data position.
            void* pathd = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The source count remaining.
            int pathc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Copy source data position.
            copy_pointer((void*) &pathd, (void*) &smd);
            // Copy source count remaining.
            copy_integer((void*) &pathc, smc);

            //
            // Get knowledge part from knowledge memory.
            //
            // CAUTION! A copy of source count remaining is forwarded here,
            // so that the original source value does not get changed.
            //
            // CAUTION! The source data position does NOT have to be copied,
            // since the parametre that was handed over is already a copy.
            // A local copy was made anyway, not to risk parametre falsification.
            // Its reference is forwarded, as it gets incremented by sub routines inside.
            //
            deserialise_knowledge(p0, p2, (void*) &pathd, (void*) &pathc, p2, p3, p4, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        } else {

            //
            // This is NOT a cybol PATH.
            //

            //
            // Get source part as DIRECT model (inline literal).
            //
            // CAUTION! The source part was handed over as parametre,
            // so that it may just be copied here.
            //
            // CAUTION! The destination pointer handed over has a size
            // of ONE and thus does NOT need to be resized. Therefore,
            // using the "overwrite" function is NOT necessary here.
            //

            // Copy source part pointer reference.
            copy_pointer(p0, p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part knowledge. The source part is null.");
        fwprintf(stdout, L"Error: Could not get part knowledge. The source part is null. p1: %i\n", p1);
    }
}
