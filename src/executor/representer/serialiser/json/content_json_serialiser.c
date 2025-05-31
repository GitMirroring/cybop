/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the part element content into json.
 *
 * @param p0 the destination wide character item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the sign flag
 * @param p6 the number base
 * @param p7 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the decimal places
 * @param p11 the scientific notation flag
 * @param p12 the indentation flag
 * @param p13 the tree level
 * @param p14 the source format
 * @param p15 the source name data
 * @param p16 the source name count
 */
void serialise_json_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json content.");
    //?? fwprintf(stdout, L"Debug: Serialise json content. tree level p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Serialise json content. tree level p13: %i\n", *((int*) p13));

    // Append indentation.
    serialise_json_indentation(p0, p13, p12);
    // Append array begin character.
    modify_item(p0, (void*) BEGIN_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BEGIN_ARRAY_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Append source name.
    serialise_json_string(p0, p15, p16, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, p10, p11, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
    // Append separation.
    serialise_json_separation(p0, p12);
    // Append inline channel by default.
    serialise_json_string(p0, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, p10, p11, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
    // Append separation.
    serialise_json_separation(p0, p12);
    // Append source format.
    serialise_json_format(p0, p14);
    // Append separation.
    serialise_json_separation(p0, p12);
    // Append source model.
    serialise_json(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    // Append separation.
    serialise_json_separation(p0, p12);
    // Append source properties.
    serialise_json_part(p0, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    // Append array end character.
    modify_item(p0, (void*) END_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) END_ARRAY_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}
