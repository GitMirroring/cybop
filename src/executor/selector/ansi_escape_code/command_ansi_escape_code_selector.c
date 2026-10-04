/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects ansi escape code command and deserialises it into a cyboi-internal keyboard constant.
 *
 * This function changes the ansi escape codes into real names as defined by CYBOL.
 *
 * Example:
 *
 * The UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL (ESC[A sequence) gets converted into the constant
 * ARROW_UP_KEYBOARD_STATE_CYBOL_NAME with the value "arrow_up", which is used so in CYBOL files.
 *
 * @param p0 the destination wide character item
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void select_ansi_escape_code_command(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select ansi escape code command.");
    //?? fwprintf(stdout, L"Debug: Select ansi escape code command. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select ansi escape code command. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, (void*) ARROW_DOWN_KEYBOARD_STATE_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARROW_DOWN_KEYBOARD_STATE_CYBOL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, (void*) ARROW_LEFT_KEYBOARD_STATE_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARROW_LEFT_KEYBOARD_STATE_CYBOL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, (void*) ARROW_RIGHT_KEYBOARD_STATE_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARROW_RIGHT_KEYBOARD_STATE_CYBOL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, (void*) ARROW_UP_KEYBOARD_STATE_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARROW_UP_KEYBOARD_STATE_CYBOL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select ansi escape code command. The ansi escape code is unknown.");
        fwprintf(stdout, L"Warning: Could not select ansi escape code command. The ansi escape code is unknown. count remaining p2: %i\n", p2);
        fwprintf(stdout, L"Warning: Could not select ansi escape code command. The ansi escape code is unknown. count remaining *p2: %i\n", *((int*) p2));
    }
}
