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

#ifndef CONTENT_XML_SERIALISER_SOURCE
#define CONTENT_XML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/wui/tag_wui_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/character_reference/character_reference_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/begin_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/break_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/empty_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/end_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/filled_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the part element content into xml.
 *
 * @param p0 the destination item
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
 * @param p12 the indentation flag
 * @param p13 the indentation level
 * @param p14 the void flag
 * @param p15 the format
 */
void serialise_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml content.");
    //?? fwprintf(stdout, L"Debug: Serialise xml content. format p15: %i\n", p15);
    //?? fwprintf(stdout, L"Debug: Serialise xml content. format *p15: %i\n", *((int*) p15));

    // The tag part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The tag part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part model.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The tag part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part model data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The empty flag.
    int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get tag part by name.
    get_name_array((void*) &t, p3, (void*) TAG_WUI_STATE_CYBOL_NAME, (void*) TAG_WUI_STATE_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Get preformatted part by name.
    get_name_array((void*) &p, p3, (void*) PREFORMATTED_WUI_STATE_CYBOL_NAME, (void*) PREFORMATTED_WUI_STATE_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Get tag part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get preformatted part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get tag part model item data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get preformatted part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Assign DEFAULT TAG name for each nameless tag,
    // for which no "tag" property has been specified.
    //
    if ((tmd == *NULL_POINTER_STATE_CYBOI_MODEL) || (tmc == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        tmd = (void*) NODE_XML_CYBOL_NAME;
        tmc = (void*) NODE_XML_CYBOL_NAME_COUNT;
    }

    // Test if source model count is empty.
    compare_integer_less_or_equal((void*) &e, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    // Serialise indentation.
    serialise_xml_indentation(p0, p12, p13);
    // Append begin tag.
    serialise_xml_begin(p0, tmd, tmc, p3, p4, (void*) &e, p14);
    // Serialise line break.
    serialise_xml_break(p0, p12);

    if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The content IS empty.
        serialise_xml_empty(p0, tmd, tmc, p12, p13, p14);

    } else {

        // The content is NOT empty.
        serialise_xml_filled(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, tmd, tmc, pmd, p12, p13, p14, p15);
    }
}

/* CONTENT_XML_SERIALISER_SOURCE */
#endif
