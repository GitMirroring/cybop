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

#ifndef COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE
#define COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the cartesian coordinates into polar coordinates.
 *
 * @param p0 the destination polar coordinates absolute value
 * @param p1 the destination polar coordinates argument
 * @param p2 the source cartesian coordinates real part
 * @param p3 the source cartesian coordinates imaginary part
 */
void serialise_cybol_complex_polar_coordinates(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol complex polar coordinates.");

    // TODO for students ...

    // v = ...
    // a = ...

    //?? Use calculation functions, e.g.:
    // calculate_double_add(p0, p2);

    //?? DELETE THE FOLLOWING LATER! This is just for TESTING:
    copy_double(p0, p2);
    copy_double(p1, p3);
}

/* COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE */
#endif
