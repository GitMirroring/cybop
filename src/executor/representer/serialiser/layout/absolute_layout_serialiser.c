/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSOLUTE_LAYOUT_SERIALISER_SOURCE
#define ABSOLUTE_LAYOUT_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/layout/part_layout_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'sense_terminal' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &sense_terminal
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void serialise_layout_formula_absolute(void* p0);

/**
 * Serialises absolute layout coordinates.
 *
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 * @param p8 the knowledge memory part
 * @param p9 the whole position x
 * @param p10 the whole position y
 * @param p11 the whole width
 * @param p12 the whole height
 * @param p12 the whole layout properties
 */
void serialise_layout_absolute(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout absolute.");

    // Serialise layout part and all of its children.
    //
    // CAUTION! A layout-dependent formula has to be applied inside,
    // for calculating the position (x, y) of child elements.
    // This formula is handed over as FUNCTION POINTER parametre.
    //
    // The reason is avoidance of redundant source code.
    // Otherwise, all recursively called functions would
    // have to be copied for each and every layout.
    serialise_layout_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, (void*) &serialise_layout_formula_absolute);
}

/* ABSOLUTE_LAYOUT_SERIALISER_SOURCE */
#endif
