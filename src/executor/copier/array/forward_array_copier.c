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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FORWARD_ARRAY_COPIER_SOURCE
#define FORWARD_ARRAY_COPIER_SOURCE

#include "../../../executor/copier/array/forward_elements_array_copier.c"
#include "../../../executor/memoriser/offset_adder.c"

/**
 * Copies source- into destination array,
 * starting from the given offset.
 *
 * This is the FORWARD version.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if source- or destination array are null!
    // All other modifier functions are based on this copier function,
    // so that checking for null pointer right here suffices.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            //
            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array forward.");
            //

            //
            // The destination array, source array.
            //
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            //
            void* d = p0;
            void* s = p1;

            add_offset((void*) &d, p2, p5);
            add_offset((void*) &s, p2, p6);

            copy_array_elements_forward(d, s, p2, p3, p4);

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array forward. The destination array is null.");
            //

            fwprintf(stdout, L"Error: Could not copy array forward. The destination array is null. p0: %i\n", p0);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array forward. The source array is null.");
        //

        //?? fwprintf(stdout, L"Error: Could not copy array forward. The source array is null. p1: %i\n", p1);
    }
}

/* FORWARD_ARRAY_COPIER_SOURCE */
#endif
