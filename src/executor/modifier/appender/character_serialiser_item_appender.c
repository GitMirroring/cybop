/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ENCODER_ITEM_APPENDER_SOURCE
#define CHARACTER_ENCODER_ITEM_APPENDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Converts the given wide characters to characters
 * and finally appends them to the destination.
 *
 * This is a convenience method ("syntactic sugar")
 * to avoid redundant code, e.g. when converting models
 * with a lot of string processing going on.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void append_item_serialise_character(void* p0, void* p1, void* p2) {

    // The character item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The character item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character array into multibyte character data.
    encode_utf_8(i, p1, p2);

    // Get character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Append character data to destination.
    append_item_element(p0, id, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, ic, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate character item.
    deallocate_item((void*) &i, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* CHARACTER_ENCODER_ITEM_APPENDER_SOURCE */
#endif
