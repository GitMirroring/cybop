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

#ifndef CHARACTER_TERMINAL_ENCODER_SOURCE
#define CHARACTER_TERMINAL_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/operation/primitive_operation_type.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/terminal/escape_control_sequence_terminal_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../../../executor/modifier/overwriter/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the terminal character into an escape control sequence.
 *
 * @param p0 the destination control sequence code item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the background colour
 * @param p5 the background colour count
 * @param p6 the foreground colour
 * @param p7 the foreground colour count
 * @param p8 the hidden flag
 * @param p9 the inverse flag
 * @param p10 the blink flag
 * @param p11 the underline flag
 * @param p12 the bold flag
 * @param p13 the character
 */
void encode_terminal_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode terminal character.");

    // CAUTION! The top-left terminal corner is 1:1, but the given positions
    // start counting from 0, so that 1 has to be added to all positions!
    // Therefore, the coordinates handed over need to be corrected.

    // The corrected y, x.
    int cy = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cx = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Correct y, x.
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cy, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    calculate_integer_add((void*) &cx, p1);
    calculate_integer_add((void*) &cx, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

    //
    // Position cursor.
    //
    // Example:
    // printf("\033[%d;%dH", y_row, x_column)
    //

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    encode_cybol_integer_value(p0, (void*) &cy, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    append_item_element(p0, (void*) SEMICOLON_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    encode_cybol_integer_value(p0, (void*) &cx, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    append_item_element(p0, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    append_item_element(p0, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    //
    // Add background and foreground properties.
    //
    // Example:
    // printf("\033[32mgreen colour\033[0mswitched off.")
    //

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    encode_terminal_background(p0, p4, p5);
    append_item_element(p0, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    encode_terminal_foreground(p0, p6, p7);
    append_item_element(p0, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    //
    // Set character properties.
    //
    // Example:
    // printf("\033[1mbold \033[0mswitched off.")
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Set hidden property.
    compare_integer_unequal((void*) &r, p10, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        append_item_element(p0, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Set inverse property.
    compare_integer_unequal((void*) &r, p11, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        append_item_element(p0, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Set blink property.
    compare_integer_unequal((void*) &r, p12, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        append_item_element(p0, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Set underline property.
    compare_integer_unequal((void*) &r, p13, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        append_item_element(p0, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Set bold property.
    compare_integer_unequal((void*) &r, p14, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        append_item_element(p0, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }

    // Set character.
    append_item_element(p0, p15, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* CHARACTER_TERMINAL_ENCODER_SOURCE */
#endif
