/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_CYBOL_DECODER_SOURCE
#define PART_CYBOL_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../executor/converter/decoder/cybol/root_part_cybol_decoder.c"
#include "../../../../executor/converter/decoder/cybol/standard_part_cybol_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the cybol part.
 *
 * @param p0 the destination item
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part properties data
 * @param p4 the source part properties count
 * @param p5 the root part flag
 */
void decode_cybol_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode cybol part.");

    // The root node flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This is a standard part node and NOT the root node.

        decode_cybol_part_standard(p0, p1, p2, p3, p4, p5);

    } else {

        // This IS the root node.

        // Add the meta node model and properties directly
        // to destination whole (root).
        decode_cybol_part_root(p0, p1, p2, p5);
    }
}

/* PART_CYBOL_DECODER_SOURCE */
#endif
