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

#ifndef HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE
#define HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/http/header/entity_header_http_cyboi_name.c"
#include "../../../../constant/name/cyboi/http/header/general_header_http_cyboi_name.c"
#include "../../../../constant/name/cyboi/http/header/request_header_http_cyboi_name.c"
#include "../../../../constant/name/cyboi/http/header/response_header_http_cyboi_name.c"
#include "../../../../constant/name/http/header/entity_header_http_name.c"
#include "../../../../constant/name/http/header/general_header_http_name.c"
#include "../../../../constant/name/http/header/request_header_http_name.c"
#include "../../../../constant/name/http/header/response_header_http_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/character_decoder_part_allocator_item_appender.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

//
// CAUTION! This comment is valid for all "select" functions below.
//
// The comparison result HAS TO BE ZERO (r == 0),
// if a detection is to be taking place!
//
// Many "detect" functions are called in a sequence, below.
// If the result of one detection function was positive (r == 1), then that
// function increments the current position and decrements the remaining count.
// In this case, further detection functions following afterwards might detect
// further characters and CHANGE the current position and remaining count,
// and so forth, which would have the effect of "JUMPING" over some characters
// and produce WRONG RESULTS!
//
// Therefore, the checks for (r == 0) below avoid another detection,
// if the result already has a value unequal zero.
//
// CAUTION! If a detection was successful, then the current position and remaining count
// were already adapted within the corresponding "detect" function (as called below),
// so that they now point to the first character following the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the http request header field.
 *
 * @param p0 the destination properties item
 * @param p1 the header argument
 * @param p2 the header argument count
 * @param p3 the header value
 * @param p4 the header value count
 */
void select_http_request_header_field(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http request header field.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // The entity headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    //
    // The request headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ACCEPT_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) ACCEPT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) EXPECT_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) EXPECT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FROM_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) FROM_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) FROM_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) FROM_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) HOST_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) HOST_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) HOST_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) HOST_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) IF_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) IF_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) IF_RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) IF_RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RANGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REFERER_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) REFERER_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) REFERER_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) REFERER_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) TE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) TE_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) TE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) USER_AGENT_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) USER_AGENT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VARY_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VARY_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) VARY_REQUEST_HEADER_HTTP_CYBOI_NAME, (void*) VARY_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    //
    // The response headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) AGE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) AGE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) AGE_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) AGE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) ETAG_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) ETAG_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) LOCATION_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) LOCATION_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) SERVER_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) SERVER_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    //
    // The general headers.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DATE_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) DATE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) DATE_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) DATE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VIA_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VIA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) VIA_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) VIA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WARNING_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) WARNING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_allocate_part_deserialise_character(p0, (void*) WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME, (void*) WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT, p3, p4);
        }
    }
}

/* HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE */
#endif
