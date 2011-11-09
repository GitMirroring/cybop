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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BODY_HTTP_RESPONSE_ENCODER_SOURCE
#define BODY_HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/http_request/protocol_http_request_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the http response body.
 *
 * @param p0 the destination character item
 * @param p1 the source type
 * @param p2 the source type count
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source details
 * @param p6 the source details count
 */
void encode_http_response_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response body.");

    // The character model.
    void* md = *NULL_POINTER_MEMORY_MODEL;
    int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate character array.
    allocate_model((void*) &md, (void*) &ms, (void*) CHARACTER_MEMORY_TYPE);

    // Encode wide character array into multibyte character array.
    encode_utf_8_unicode_character_vector((void*) &md, (void*) &mc, (void*) &ms, p3, p4);

    append_item_element(p0, md, (void*) CHARACTER_MEMORY_TYPE, mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Deallocate character model.
    deallocate_model((void*) &md, (void*) &ms, (void*) CHARACTER_MEMORY_TYPE);
}

/* BODY_HTTP_RESPONSE_ENCODER_SOURCE */
#endif
