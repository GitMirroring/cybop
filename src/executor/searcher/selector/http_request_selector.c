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

#ifndef HTTP_REQUEST_SELECTOR_SOURCE
#define HTTP_REQUEST_SELECTOR_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../constant/name/xml_name.c"
#include "../../../logger/logger.c"

/**
 * Selects http request.
 *
 * Examples:
 *
 * GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
 * POST /wiki/Spezial:Search HTTP/1.1
 *
 * CAUTION! The methods GET and HEAD MUST be supported by all
 * general-purpose servers! All other methods are OPTIONAL.
 *
 * @param p0 the destination model item
 * @param p1 the source body
 * @param p2 the source body count
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the source request method
 * @param p6 the source request method count
 */
void select_http_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http request.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2,
                (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) POST_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) POST_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) POST_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) POST_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);

            // Decode body parameters containing model data.
            //
            // CAUTION! The POST method http request may contain a body with parameters,
            // which are listed in the same key-value pair format as those in the uri.
            decode_http_request_parameters(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set request method as action parameter within the compound model.
            decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p6, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select http request. The source request method is unknown.");
    }
}

/* HTTP_REQUEST_SELECTOR_SOURCE */
#endif
