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

#ifndef CHARACTER_ENCODER_ITEM_APPENDER_SOURCE
#define CHARACTER_ENCODER_ITEM_APPENDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
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
 * @param p2 the source data count
 */
void append_item_encode_character(void* p0, void* p1, void* p2) {

    // The character data, count, size.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate character data.
    allocate_array((void*) &d, (void*) &s, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character array into multibyte character data.
    encode_utf_8_unicode_character_vector((void*) &d, (void*) &c, (void*) &s, p1, p2);

    // Append character data to destination.
    append_item_element(p0, d, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &c, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate character data.
    deallocate_array((void*) &d, (void*) &s, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* CHARACTER_ENCODER_ITEM_APPENDER_SOURCE */
#endif
