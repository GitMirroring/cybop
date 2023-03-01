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

#ifndef FOREGROUND_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define FOREGROUND_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include "../../../../constant/model/ansi_escape_code/foreground_ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/colour/terminal_colour_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the terminal foreground colour into ansi escape code.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count (pointer reference)
 * @param p2 the source data
 */
void serialise_ansi_escape_code_foreground(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code foreground.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) BLACK_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) BLUE_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) CYAN_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) GREEN_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) MAGENTA_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) RED_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WHITE_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) YELLOW_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL);
            copy_pointer(p1, (void*) &YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT);
        }
    }
}

/* FOREGROUND_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
