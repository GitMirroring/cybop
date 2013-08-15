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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_FIELD_BDT_XDT_DESERIALISER_SOURCE
#define COMPOUND_FIELD_BDT_XDT_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/representer/deserialiser/xdt/bdt/records_bdt_xdt_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises an xdt bdt compound field.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source bdt data
 * @param p3 the source bdt count
 */
void deserialise_xdt_bdt_field_compound(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt bdt field compound.");

    // Allocate part of type "element/part".

    // Copy source field model to part's name.

    // Process following source fields.
    // CAUTION! Hand over part as new parent node.
//??    deserialise_xdt_bdt_fields(p0, p1, pmd, pmc, pnd, pnc);

    // CONTINUE: Call "select" function in "deserialise_fields"
    // (or in "deserialise_field" called from there), in order to
    // set break flag.
    // If a loop is left, then the next higher level loop will
    // check again for break calling a "select" function etc.
    // Possibly, the tree level has to be forwarded as parametre,
    // since zero level fields (directly below the record)
    // do not have to be checked for an end of loop/sub hierarchy.
    // Therefore, possibly check for (loop level == 0) first.

    // Add part to destination node.
}

/* COMPOUND_FIELD_BDT_XDT_DESERIALISER_SOURCE */
#endif
