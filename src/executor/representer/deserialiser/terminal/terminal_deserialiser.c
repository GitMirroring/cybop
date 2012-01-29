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

#ifndef TERMINAL_DESERIALISER_SOURCE
#define TERMINAL_DESERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/terminal/ansi_escape_code_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the escape control sequence character data into a cyboi command.
 *
 * This function changes the escape control sequences into real names as defined by CYBOL.
 * Example: The ARROW_UP_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL (ESC[A sequence) gets converted into the
 * constant ARROW_UP_KEYBOARD_KEY_CYBOL_NAME with the value "arrow_up", which is used so in CYBOL files.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void deserialise_ansi_escape_code_escape_control_sequence(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise terminal escape control sequence.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_UP_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) ARROW_UP_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ARROW_UP_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARROW_UP_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ARROW_DOWN_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARROW_DOWN_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ARROW_LEFT_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARROW_LEFT_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ARROW_RIGHT_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARROW_RIGHT_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    // Just don't do anything, if none of the escape control sequences above matched.
    // This was to be an escape control sequence, as it started with the corresponding prefix.
    // If the sequence's values are not recognised, they probably do not make sense anyway.
    // So, just ignore this and wait for other, proper sequences and characters to be converted.
}

/**
 * Deserialises the terminal character data into a command.
 *
 * This function changes the key codes into real names as defined by CYBOL.
 * Example: The LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL (<enter> key) gets converted into the
 * constant ENTER_KEYBOARD_KEY_CYBOL_NAME with the value "enter", which is used so in CYBOL files.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void deserialise_ansi_escape_code_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise terminal character.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ENTER_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ENTER_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) ESCAPE_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // None of the control characters above matched.
        // Pass along character without modification.
        overwrite_array(p0, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/**
 * Deserialises the terminal character data into a command.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void deserialise_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise terminal.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*sc > *ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT) {

                // Only do the following comparison if the source array
                // is greater than the escape control sequence prefix,
                // since a value has to follow after the escape control sequence prefix.

                // CAUTION! Use the "ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT" for both comparison values,
                // since they would not be equal if their size differed.
                compare_all_array((void*) &r, p3, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // Initialise temporary character sequence with pointer to the
                    // first character AFTER the escape control sequence prefix.
                    void* t = p3 + (*ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                    int tc = *sc - *ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT;

                    deserialise_ansi_escape_code_escape_control_sequence(p0, p1, p2, t, (void*) &tc);
                }
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_ansi_escape_code_character(p0, p1, p2, p3, p4);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise terminal. The source character array count is null.");
    }
}

/* TERMINAL_DESERIALISER_SOURCE */
#endif
