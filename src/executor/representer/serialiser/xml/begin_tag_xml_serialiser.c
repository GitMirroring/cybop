/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BEGIN_TAG_XML_SERIALISER_SOURCE
#define BEGIN_TAG_XML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/representer/serialiser/xml/attributes_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the xml begin tag into xml format.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the empty flag
 * @param p6 the void flag
 */
void serialise_xml_begin_tag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml begin tag.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Append less than character.
    append_item_element(p0, (void*) LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Append xml tag.
    append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Append xml tag properties.
    serialise_xml_attributes(p0, p3, p4);

    // Initialise comparison result.
    logify_boolean_or((void*) &r, p5);

    // Check if content is empty AND element is allowed to be void.
    logify_boolean_and((void*) &r, p6);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append solidus slash / character.
        append_item_element(p0, (void*) SOLIDUS_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Append greater than character.
    append_item_element(p0, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* BEGIN_TAG_XML_SERIALISER_SOURCE */
#endif
