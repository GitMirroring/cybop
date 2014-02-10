/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE
#define POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/accessor/getter/complex_getter.c"
#include "../../../../../../executor/accessor/setter/complex_setter.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the source complex number given in cartesian coordinates
 * into the destination complex number in polar coordinates.
 *
 * @param p0 the destination
 * @param p1 the source
 * @param p2 the
 */
void serialise_cybol_complex_polar(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol complex polar.");

/*?? TODO
    // The real and imaginary value.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The absolute value and argument.
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double a = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get real and imaginary value.
    get_complex_element((void*) &r, p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &i, p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    //
    // Transform cartesian coordinates into polar coordinates.
    //

    // TODO for students ...
    // v = ...
    // a = ...

    // Set absolute value and argument.
    //
    // CAUTION! The type structure used here for polar coordinates
    // is IDENTICAL to that of cartesian coordinates.
    // Therefore, the following name constants may be used:
    // - REAL_COMPLEX_STATE_CYBOI_NAME
    // - IMAGINARY_COMPLEX_STATE_CYBOI_NAME
    //
    // The following constants do NOT exist,
    // in order to avoid redundancy:
    // - ABSOLUTE_VALUE_COMPLEX_STATE_CYBOI_NAME
    // - ARGUMENT_COMPLEX_STATE_CYBOI_NAME
    set_complex_element(p0, (void*) &v, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element(p0, (void*) &a, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
*/
}

/* POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE */
#endif
