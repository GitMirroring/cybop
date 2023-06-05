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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"

/**
 * Determines the model of the source part at the given index.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source textline list data
 * @param p3 the source textline list index (loop index)
 * @param p4 the delimiter data, e.g. a comma OR semicolon OR some character sequence
 * @param p5 the delimiter count
 * @param p6 the escape data, e.g. a DOUBLE quotation mark
 * @param p7 the escape count
 * @param p8 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p9 the quotation end PLUS delimiter count
 * @param p10 the quotation end data, e.g. a quotation mark
 * @param p11 the quotation end count
 * @param p12 the quotation begin data, e.g. a quotation mark
 * @param p13 the quotation begin count
 * @param p14 the header flag
 */
void deserialise_csv_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise csv source.");
    //?? fwprintf(stdout, L"Debug: Deserialise csv source. source textline list index p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise csv source. source textline list index *p3: %i\n", *((int*) p3));

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model item data, count.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part from source whole at current index.
    copy_array_forward((void*) &p, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);
    // Get part model item.
    copy_array_forward((void*) &m, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part model item data, count.
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Branch control flow depending on header flag.
    deserialise_csv_flag(p0, p1, md, mc, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p3);
}
