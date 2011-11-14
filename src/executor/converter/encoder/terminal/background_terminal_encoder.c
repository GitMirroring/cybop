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

#ifndef BACKGROUND_TERMINAL_ENCODER_SOURCE
#define BACKGROUND_TERMINAL_ENCODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/model/cybol/colour/terminal_colour_cybol_model.c"
#include "../../../../constant/model/terminal/escape_control_sequence_terminal_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the terminal background colour name into a control sequence code.
 *
 * @param p0 the destination control sequence code item
 * @param p1 the source colour data
 * @param p2 the source colour count
 */
void encode_terminal_background(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BLACK_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BLACK_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RED_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) RED_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREEN_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GREEN_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) YELLOW_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) YELLOW_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BLUE_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BLUE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COBALT_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) COBALT_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WHITE_TERMINAL_COLOUR_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) WHITE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }
}

/* BACKGROUND_TERMINAL_ENCODER_SOURCE */
#endif
