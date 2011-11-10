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

#ifndef HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE
#define HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/decoder/uri/http_uri_decoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Selects http response header entry.
 *
 * @param p0 the destination item
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source model
 * @param p4 the source model count
 */
void select_http_response_header_entry(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http response header entry.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // The entity headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Nothing is to be done here.
            // The content length is ALWAYS added.
            // See function "encode_http_response_header"!
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    //
    // The request headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) FROM_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) FROM_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) HOST_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HOST_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) REFERER_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) TE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) VARY_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) VARY_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    //
    // The response headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) AGE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    //
    // The general headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) DATE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) DATE_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) VIA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) VIA_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p2, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) WARNING_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_element(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            append_item_encode_character(p0, p3, p4);
            append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }
}

/* HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE */
#endif
