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

#ifndef OFFSET_COPIER_SOURCE
#define OFFSET_COPIER_SOURCE

#include "../../executor/memoriser/offset_adder.c"

//
// Forward declarations
//

void copy(void* p0, void* p1, void* p2, void* p3);

/**
 * Copies the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the index
 */
void copy_offset(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy offset.");
    //

    //?? fwprintf(stdout, L"Debug: Copy offset. p3: %i\n", p3);

    //
    // The destination value, source value.
    //
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    //
    void* d = p0;
    void* s = p1;

    // Add offset to destination value and source value.
    add_offset((void*) &d, p2, p4);
    add_offset((void*) &s, p2, p4);

    // Copy source- to destination value.
    copy(d, s, p2, p3);
}

/* OFFSET_COPIER_SOURCE */
#endif
