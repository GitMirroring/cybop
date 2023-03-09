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

#ifndef ELEMENT_XML_DESERIALISER_SOURCE
#define ELEMENT_XML_DESERIALISER_SOURCE

//
// Executable interface
//

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/modifier/part_modifier.c"
#include "../../../../executor/representer/deserialiser/xml/attribute_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/compound_check_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/content_check_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/tag_name_xml_deserialiser.c"
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

// #include "../../../../executor/representer/deserialiser/xml/content_xml_deserialiser.c"

//
// Forward declarations
//

void deserialise_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Deserialises the xml element.
 *
 * @param p0 the destination model item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_xml_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml element.");
    //?? fwprintf(stdout, L"Debug: Deserialise xml element. p2: %i\n", p2);

    // The compound flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The part format, type.
    int f = *PLAIN_TEXT_STATE_CYBOI_FORMAT;
    int t = *WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE;
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name, model, properties item.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The has attribute flag.
    int ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The has content flag.
    int hc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The is empty flag.
    int ie = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check if this is going to be a compound node.
    deserialise_xml_check_compound((void*) &c, p1, p2);

    if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The default format is "text/plain".
        // However, if an xml element contains child elements,
        // then the compound type "element/part" is used.
        //
        // Using the string type by default is IMPORTANT
        // in order to avoid data loss. If all allocated parts
        // were compound parts, then deserialised text
        // situated in between opening and closing xml tag
        // like for example in: <test>Some text</test>
        // could NOT be stored, since a compound part
        // can only store POINTERS to child elements.
        //

        f = *PART_ELEMENT_STATE_CYBOI_FORMAT;
        t = *PART_ELEMENT_STATE_CYBOI_TYPE;
    }

    //
    // Allocate part.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);

    // Initialise part.
    modify_part(p, (void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(p, (void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);
    //
    // Get part name, model, properties item.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Deserialise tag name into part name item.
    deserialise_xml_tag_name(pn, p1, p2, (void*) &ha, (void*) &hc, (void*) &ie);

    if (ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Reset has attributes flag.
        ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Deserialise attribute.
        deserialise_xml_attribute(pp, p1, p2, (void*) &hc, (void*) &ie);
    }

    if (hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Deserialise the element's content.
        deserialise_xml_content(pm, pp, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &t);
    }

    //
    // Append part to destination model.
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    //
    modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* ELEMENT_XML_DESERIALISER_SOURCE */
#endif
