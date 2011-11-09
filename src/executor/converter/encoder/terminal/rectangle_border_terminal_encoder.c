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

#ifndef RECTANGLE_BORDER_TERMINAL_ENCODER_SOURCE
#define RECTANGLE_BORDER_TERMINAL_ENCODER_SOURCE

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
 * Encodes a terminal rectangle border.
 *
 * @param p0 the horizontal character
 * @param p1 the vertical character
 * @param p2 the left top
 * @param p3 the right top
 * @param p4 the left bottom
 * @param p5 the right bottom
 * @param p6 the border
 * @param p7 the border count
 */
void encode_terminal_rectangle_border(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        wchar_t* rbc = (wchar_t*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* lbc = (wchar_t*) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                wchar_t* rtc = (wchar_t*) p3;

                if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                    wchar_t* ltc = (wchar_t*) p2;

                    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                        wchar_t* vc = (wchar_t*) p1;

                        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                            wchar_t* hc = (wchar_t*) p0;

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode terminal rectangle border.");

                            // The comparison result.
                            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) ASCII_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p7, (void*) ASCII_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p7, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_DOUBLE_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_DOUBLE_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) ROUND_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p7, (void*) ROUND_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p7, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The horizontal character is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The vertical character is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The left top character is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The right top character is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The left bottom character is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal rectangle border. The right bottom character is null.");
    }
}

/* RECTANGLE_BORDER_TERMINAL_ENCODER_SOURCE */
#endif
