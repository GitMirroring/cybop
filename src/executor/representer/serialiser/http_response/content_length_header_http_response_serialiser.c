/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_LENGTH_HEADER_HTTP_RESPONSE_SERIALISER_SOURCE
#define CONTENT_LENGTH_HEADER_HTTP_RESPONSE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/http/http_cyboi_name.c"
#include "../../../../executor/representer/serialiser/cybol/integer/char_value_integer_cybol_serialiser.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the http response header content length.
 *
 * @param p0 the destination character item
 * @param p1 the source content length
 */
void serialise_http_response_header_content_length(void* p0, void* p1) {

    modify_item_element(p0, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    modify_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    serialise_cybol_integer_value_char(p0, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    modify_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/* CONTENT_LENGTH_HEADER_HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
