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

#ifndef ELEMENT_XML_DECODER_SOURCE
#define ELEMENT_XML_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/xml/attribute_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/tag_name_xml_decoder.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void decode_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Decodes the xml element.
 *
 * @param p0 the destination model item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void decode_xml_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode xml element.");

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model, properties.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE);

    // Get part model, properties.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Fill part.
    // CAUTION! The pre-defined constant "part" is used as name here!
    overwrite_part_element(p, (void*) NODE_XML_CYBOL_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) NODE_XML_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    // CAUTION! All xml elements are of the type "part".
    // If an xml element is empty, the part (compound) will just not contain any child parts.
    overwrite_part_element(p, (void*) PART_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // The has attribute flag.
    int ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The has content flag.
    int hc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The is empty flag.
    int ie = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Decode tag name.
    decode_xml_tag_name(pd, (void*) &ha, (void*) &hc, (void*) &ie, p1, p2);

    if (ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Reset has attributes flag.
        ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Decode attribute.
        decode_xml_attribute(pd, (void*) &hc, (void*) &ie, p1, p2);
    }

    if (hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Decode the element's content.
        decode_xml_element_content(pm, pd, p1, p2);
    }

    // Append part to destination model.
    // Storing many parts with identical tag name is not a problem,
    // since the tag name of a part is added to its properties compound.
    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ELEMENT_XML_DECODER_SOURCE */
#endif
