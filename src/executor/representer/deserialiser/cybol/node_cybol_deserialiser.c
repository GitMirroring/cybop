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

#ifndef NODE_CYBOL_DESERIALISER_SOURCE
#define NODE_CYBOL_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/cybol/part_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/standard_cybol_deserialiser.c"
#include "logger.h"

/**
 * Deserialises a cybol tree node.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source channel data
 * @param p4 the source channel count
 * @param p5 the source format data
 * @param p6 the source format count
 * @param p7 the source model data
 * @param p8 the source model count
 * @param p9 the source properties data
 * @param p10 the source properties count
 * @param p11 the language properties (constraints) data
 * @param p12 the language properties (constraints) count
 * @param p13 the knowledge memory part (pointer reference)
 * @param p14 the stack memory item
 * @param p15 the internal memory data
 * @param p16 the decimal separator data
 * @param p17 the decimal separator count
 * @param p18 the thousands separator data
 * @param p19 the thousands separator count
 * @param p20 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p21 the root flag
 */
void deserialise_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol node.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol node. root flag p21: %i\n", p21);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol node. root flag *p21: %i\n", *((int*) p21));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since STANDARD node has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p21, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a standard node.
        //

        deserialise_cybol_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);

    } else {

        //
        // This is a root node.
        //

        //
        // Fill part properties taken from cybol source part model.
        //
        // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
        // becomes the properties (meta data) in the cyboi-internal knowledge tree.
        //
        // Therefore, hand over the source PROPERTIES becoming the source model.
        //
        deserialise_cybol_part(p0, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);
    }
}

/* NODE_CYBOL_DESERIALISER_SOURCE */
#endif
