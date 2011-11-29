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

#ifndef RECTANGLE_COMPASS_LAYOUT_TERMINAL_SERIALISER_SOURCE
#define RECTANGLE_COMPASS_LAYOUT_TERMINAL_SERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/terminal/escape_control_sequence_terminal_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_background_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_foreground_serialiser.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Serialises a terminal rectangle compass layout.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the free area position x (remaining space within the whole)
 * @param p7 the free area position y
 * @param p8 the free area position z
 * @param p9 the free area size x (remaining space within the whole)
 * @param p10 the free area size y
 * @param p11 the free area size z
 * @param p12 the layout cell
 * @param p13 the layout cell count
 */
void serialise_terminal_rectangle_compass_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise terminal rectangle compass layout.");

    int* cpx = (int*) p0;
    int* cpy = (int*) p1;
    int* cpz = (int*) p2;
    int* csx = (int*) p3;
    int* csy = (int*) p4;
    int* csz = (int*) p5;
    int* fapx = (int*) p6;
    int* fapy = (int*) p7;
    int* fapz = (int*) p8;
    int* fasx = (int*) p9;
    int* fasy = (int*) p10;
    int* fasz = (int*) p11;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p12, (void*) NORTH_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p13, (void*) NORTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            *csz = *fasz;
            // Set free area coordinates.
            *fapy = *fapy + *csy;
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p12, (void*) SOUTH_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p13, (void*) SOUTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy + (*fasy - *csy);
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            *csz = *fasz;
            // Set free area coordinates.
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p12, (void*) WEST_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p13, (void*) WEST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fapx = *fapx + *csx;
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p12, (void*) EAST_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p13, (void*) EAST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx + (*fasx - *csx);
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p12, (void*) CENTRE_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p13, (void*) CENTRE_COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *fasx;
            *fasy = *fasy - *fasy;
            *fasz = *fasz - *fasz;
        }
    }
}

/* RECTANGLE_COMPASS_LAYOUT_TERMINAL_SERIALISER_SOURCE */
#endif
