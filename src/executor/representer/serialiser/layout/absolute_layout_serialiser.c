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

/**
 * Serialises absolute layout coordinates.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source layout properties data
 * @param p3 the source layout properties count
 * @param p4 the source whole position x
 * @param p5 the source whole position y
 * @param p6 the source whole width
 * @param p7 the source whole height
 * @param p8 the knowledge memory part
 */
void serialise_layout_absolute(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout absolute.");

    // Serialise layout part and all of its children.
    //
    // CAUTION! Grand children are NOT considered.
    //
    // CAUTION! A layout-dependent formula has to be applied inside,
    // for calculating the position (x, y) of child elements.
    // The formula gets selected depending on the last parametre.
    serialise_layout_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, (void*) ABSOLUTE_LAYOUT_STATE_CYBOI_LANGUAGE);
}

/* ABSOLUTE_LAYOUT_SERIALISER_SOURCE */
#endif
