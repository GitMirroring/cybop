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

#ifndef ELEMENT_USER_INTERFACE_SERIALISER_SOURCE
#define ELEMENT_USER_INTERFACE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the user interface element.
 *
 * @param p0 the element position x
 * @param p1 the element position y
 * @param p2 the element size x
 * @param p3 the element size y
 * @param p4 the margin size
 * @param p5 the border size
 * @param p6 the padding size
 * @param p7 the content size
 */
void serialise_user_interface_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise user interface element.");

    // The margin coordinates.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border coordinates.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The padding coordinates.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The content coordinates.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! The following coordinate structures are not
    // allocated as item, but as array instead, since their
    // size as well as position of elements is fixed:
    //
    // position x
    // position y
    // size x
    // size y

    // Allocate margin coordinates.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &m, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Allocate border coordinates.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &b, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Allocate padding coordinates.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &p, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Allocate content coordinates.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &c, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Determine margin coordinates.
    serialise_user_interface_coordinates(m, p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    // Determine border coordinates.
    serialise_user_interface_coordinates(b, m, p4);
    // Determine padding coordinates.
    serialise_user_interface_coordinates(p, b, p5);
    // Determine content coordinates.
    serialise_user_interface_coordinates(c, p, p6);

    // Deallocate margin coordinates.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &m, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate border coordinates.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &b, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate padding coordinates.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &p, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate content coordinates.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* ELEMENT_USER_INTERFACE_SERIALISER_SOURCE */
#endif
