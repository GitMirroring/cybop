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

#ifndef CONTENT_MODEL_DIAGRAM_SERIALISER_SOURCE
#define CONTENT_MODEL_DIAGRAM_SERIALISER_SOURCE

//
// Executable interface
//

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/indentation_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/line_model_diagram_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forbidden includes
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "../../../../executor/representer/serialiser/model_diagram/model_diagram_serialiser.c"
// #include "../../../../executor/representer/serialiser/model_diagram/part_model_diagram_serialiser.c"

//
// Forward declarations
//

void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_model_diagram_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Serialises the part element content into model diagram.
 *
 * @param p0 the destination wide character item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the sign flag
 * @param p6 the number base
 * @param p7 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the decimal places
 * @param p11 the scientific notation flag
 * @param p12 the source format
 * @param p13 the tree level
 * @param p14 the source name data
 * @param p15 the source name count
 * @param p16 the properties flag
 * @param p17 the part pointer reference (for TESTING only)
 */
void serialise_model_diagram_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise model diagram content.");
    //?? fwprintf(stdout, L"Debug: Serialise model diagram content. tree level p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Serialise model diagram content. tree level *p13: %i\n", *((int*) p13));

    // Append indentation.
    serialise_model_diagram_indentation(p0, p16, p13);
    // Append part name.
    modify_item(p0, p14, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p15, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

/*??
    if (p17 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Append line.
        serialise_model_diagram_line(p0);
        //
        // Append part pointer reference.
        //
        // CAUTION! This is only for TESTING and normally commented out.
        //
        long tmp = (long) *((void**) p17);
        int test = (long) *((void**) p17);
        fwprintf(stdout, L"Debug: Serialise model diagram content. part pointer reference tmp: %ld\n", tmp);
        serialise_numeral(p0, (void*) &test, p5, p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p7, p8, p9, p10, p11, p12);
    }
*/

    // Append line.
    serialise_model_diagram_line(p0);
    // Append part format.
    serialise_cybol_format(p0, p12);
    // Append line.
    serialise_model_diagram_line(p0);
    // Append part model.
    serialise_model_diagram(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    // Append part properties.
    serialise_model_diagram_part(p0, p3, p4, p5, p6, p7, p8, p9, p10, p11, p13, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
}

/* CONTENT_MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
