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

#ifndef ENCODE_HEADER_ENTRY_HTTP_RESPONSE_SERIALISER_SOURCE
#define ENCODE_HEADER_ENTRY_HTTP_RESPONSE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/selector/http_response/header_entry_http_response_selector.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "logger.h"

/**
 * Serialises the http response header entry encode.
 *
 * @param p0 the destination character item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source model data
 * @param p4 the source model count
 */
void serialise_http_response_header_entry_encode(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise http response header entry encode.");

    // The character name, model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The character name, model item data, count.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate character name, model item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character array into multibyte character data.
    encode_utf_8(m, p3, p4);

    //
    // Get character name, model item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: serialise http response header entry encode p1: %ls\n", (wchar_t*) p1);
    //?? fwprintf(stdout, L"Debug: serialise http response header entry encode md: %s\n", (char*) md);
    //?? fwprintf(stdout, L"Debug: serialise http response header entry encode mc: %i\n", *((int*) mc));

    // Select entry by name and append model.
    select_http_response_header_entry(p0, p1, p2, md, mc);

    // Deallocate character name, model item.
    deallocate_item((void*) &m, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* ENCODE_HEADER_ENTRY_HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
