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

#ifndef TERMINAL_SENDER_SOURCE
#define TERMINAL_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/terminal/file_terminal_sender.c"
#include "../../../../executor/converter/encoder.c"
#include "../../../../executor/representer/serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the terminal.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the format
 * @param p5 the language
 * @param p6 the encoding
 * @param p7 the internal memory
 * @param p8 the clean flag
 * @param p9 the new line flag
 */
void send_terminal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send terminal.");

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised wide character item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate serialised wide character array.
    allocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded character item.
    // CAUTION! Use standard (non-wide) character data here,
    // since the source is handed over as utf-8 encoded multibyte characters
    // and will be forwarded as such to the terminal.
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Compare clean flag.
    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(s, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        append_item_element(s, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }

    // Serialise source knowledge model into serialised wide character array.
    serialise(s, p0, p1, p2, p3, p4, p5);

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Compare new line flag.
    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(s, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Get serialised wide character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode serialised wide character array into encoded character array.
    encode(e, sd, sc, p6);

    // Add null termination character.
    // CAUTION! Appending a wide character null termination to the
    // serialised wide character item above does NOT make sense,
    // since it WON'T get converted into an ascii character null
    // termination of the resulting multibyte character sequence.
    // The encode function above only converts the actual characters
    // whose count is given, but NOT a null termination character.
    // Therefore, the null termination is only added here, as ascii character.
    append_item_element(e, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Get encoded character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Write encoded array to terminal.
    send_terminal_file(ed, ec, p7);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* TERMINAL_SENDER_SOURCE */
#endif
