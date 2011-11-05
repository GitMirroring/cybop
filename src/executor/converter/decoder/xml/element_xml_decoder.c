/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_XML_DECODER_SOURCE
#define ELEMENT_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
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

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml element.");

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part model, details.
    void* pm = *NULL_POINTER_MEMORY_MODEL;
    void* pd = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION);

    // Get part model, details.
    copy_array_forward((void*) &pm, p, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // Fill part.
    // CAUTION! The pre-defined constant "part" is used as name here!
    overwrite_part_element(p, (void*) NODE_XML_CYBOL_NAME, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) NODE_XML_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    // CAUTION! All xml elements are of the abstraction "part".
    // If an xml element is empty, the part (compound) will just not contain any child parts.
    overwrite_part_element(p, (void*) PART_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);

    // The has attribute flag.
    int ha = *FALSE_BOOLEAN_MEMORY_MODEL;
    // The has content flag.
    int hc = *FALSE_BOOLEAN_MEMORY_MODEL;
    // The is empty flag.
    int ie = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Decode tag name.
    decode_xml_tag_name(pd, (void*) &ha, (void*) &hc, (void*) &ie, p1, p2);

    if (ha != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // Reset has attributes flag.
        ha = *FALSE_BOOLEAN_MEMORY_MODEL;

        // Decode attribute.
        decode_xml_attribute(pd, (void*) &hc, (void*) &ie, p1, p2);
    }

    if (hc != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // Decode the element's content.
        decode_xml_element_content(pm, pd, p1, p2);
    }

    // Append part to destination model.
    // Storing many parts with identical tag name is not a problem,
    // since the tag name of a part is added to its details compound.
    append_item_element(p0, (void*) &p, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* ELEMENT_XML_DECODER_SOURCE */
#endif
