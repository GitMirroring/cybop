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

#ifndef SHAPE_TERMINAL_ENCODER_SOURCE
#define SHAPE_TERMINAL_ENCODER_SOURCE

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
#include "../../../../executor/converter/encoder/cybol/integer/integer_cybol_encoder.c"
#include "../../../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes a terminal shape.
 *
 * @param p0 the destination control sequence code item
 * @param p3 the character
 * @param p4 the character count
 * @param p5 the character type
 * @param p6 the character type count
 * @param p7 the hidden property
 * @param p8 the hidden property count
 * @param p9 the inverse property
 * @param p10 the inverse property count
 * @param p11 the blink property
 * @param p12 the blink property count
 * @param p13 the underline property
 * @param p14 the underline property count
 * @param p15 the bold property
 * @param p16 the bold property count
 * @param p17 the background
 * @param p18 the background count
 * @param p19 the foreground
 * @param p20 the foreground count
 * @param p21 the position
 * @param p22 the position count
 * @param p23 the size
 * @param p24 the size count
 * @param p25 the whole model position
 * @param p26 the whole model position count
 * @param p27 the whole model size
 * @param p28 the whole model size count
 * @param p29 the border
 * @param p30 the border count
 * @param p31 the layout cell
 * @param p32 the layout cell count
 * @param p33 the layout
 * @param p34 the layout count
 * @param p35 the shape
 * @param p36 the shape count
 */
void encode_terminal_shape(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26,
    void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33, void* p34, void* p35, void* p36) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode terminal shape.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p35, (void*) RECTANGLE_SHAPE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p36, (void*) RECTANGLE_SHAPE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            encode_terminal_coordinates(p0, p1, p2,
                p3, p4,
                p7, p9, p11, p13, p15,
                p17, p18, p19, p20, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p35, (void*) CIRCLE_SHAPE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p36, (void*) CIRCLE_SHAPE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

/*??
            encode_terminal_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p35, (void*) POLYGON_SHAPE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p36, (void*) POLYGON_SHAPE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

/*??
            encode_terminal_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }
}

/* SHAPE_TERMINAL_ENCODER_SOURCE */
#endif
