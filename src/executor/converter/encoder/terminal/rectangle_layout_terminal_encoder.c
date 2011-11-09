/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: terminal_converter.c,v $ $Revision: 1.38 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECTANGLE_LAYOUT_TERMINAL_ENCODER_SOURCE
#define RECTANGLE_LAYOUT_TERMINAL_ENCODER_SOURCE

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
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes a terminal rectangle layout.
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
 * @param p12 the original area position x (of the whole)
 * @param p13 the original area position y
 * @param p14 the original area position z
 * @param p15 the original area size x (of the whole)
 * @param p16 the original area size y
 * @param p17 the original area size z
 * @param p18 the layout cell
 * @param p19 the layout cell count
 * @param p20 the layout
 * @param p21 the layout count
 */
void encode_terminal_rectangle_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode terminal rectangle layout.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p20, (void*) COORDINATES_LAYOUT_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p21, (void*) COORDINATES_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Determine new position and size coordinates for part.
            encode_terminal_rectangle_coordinates_layout(p0, p1, p2, p3, p4, p5, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p20, (void*) COMPASS_LAYOUT_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p21, (void*) COMPASS_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Determine new position and size coordinates for part.
            encode_terminal_rectangle_compass_layout(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p18, p19);
        }
    }

    //?? The original area position and size are necessary to calculate
    //?? coordinates of further layout models.
}

/* RECTANGLE_LAYOUT_TERMINAL_ENCODER_SOURCE */
#endif
