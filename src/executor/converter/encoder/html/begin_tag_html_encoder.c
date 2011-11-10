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

#ifndef BEGIN_TAG_HTML_ENCODER_SOURCE
#define BEGIN_TAG_HTML_ENCODER_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/converter/encoder/html/attributes_html_encoder.c"
#include "../../../../executor/converter/encoder/html/indentation_html_encoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the html begin tag into html format.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the indentation level
 */
void encode_html_begin_tag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode html begin tag.");

    // Encode indentation.
    encode_html_indentation(p0, p5);
    // Append less than character.
    append_item_element(p0, (void*) LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Append html tag.
    append_item_element(p0, p1, (void*) WIDE_CHARACTER_MEMORY_TYPE, p2, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Append html tag properties.
    encode_html_attributes(p0, p3, p4);
    // Append greater than character.
    append_item_element(p0, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Append line feed character, for better source reading.
    append_item_element(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* BEGIN_TAG_HTML_ENCODER_SOURCE */
#endif
