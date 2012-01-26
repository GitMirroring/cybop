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

#ifndef STANDARD_OUTPUT_SEND_SOURCE
#define STANDARD_OUTPUT_SEND_SOURCE

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
//?? #include "../../../executor/representer/serialiser.c"
#include "../../../logger/logger.c"

/**
 * Sends a knowledge model to standard output.
 *
 * @param p0 the internal memory array
 * @param p1 the source message part
 * @param p1 the source type data
 * @param p9 the type data
 * @param p11 the clean data
 * @param p13 the new line data
 */
void send_standard_output(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send standard output.");

    // The serialised item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clean data flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The new line flag.
    int n = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    compare_integer_unequal((void*) &c, p??, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    compare_integer_unequal((void*) &n, p??, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Allocate serialised item.
    allocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded item.
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(s, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Serialise source message part.
    serialise(s, p1, p??);

    if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(s, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Get serialised item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode serialised wide character array into encoded character array.
    encode(e, sd, sc, p??);
*/

    // Get encoded item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Write multibyte character stream to standard output.
    send_file((void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL_COUNT, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL_COUNT, ed, ec);

    // Deallocate serialised item.
    deallocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* STANDARD_OUTPUT_SEND_SOURCE */
#endif
