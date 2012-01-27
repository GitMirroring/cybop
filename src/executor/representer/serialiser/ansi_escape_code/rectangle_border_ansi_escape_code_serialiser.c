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

#ifndef RECTANGLE_BORDER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define RECTANGLE_BORDER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

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
#include "../../../../constant/model/terminal/ansi_escape_code_model.c"
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
 * Serialises a terminal rectangle border.
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
void serialise_terminal_rectangle_border(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* rbc = (wchar_t*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* lbc = (wchar_t*) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                wchar_t* rtc = (wchar_t*) p3;

                if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    wchar_t* ltc = (wchar_t*) p2;

                    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        wchar_t* vc = (wchar_t*) p1;

                        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            wchar_t* hc = (wchar_t*) p0;

                            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise terminal rectangle border.");

                            // The comparison result.
                            int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) ASCII_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) ASCII_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    *hc = *HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    *hc = *BOX_DRAWINGS_DOUBLE_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_DOUBLE_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) ROUND_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) ROUND_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                compare_all_array((void*) &r, p6, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL_COUNT);

                                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    *hc = *DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The horizontal character is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The vertical character is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The left top character is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The right top character is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The left bottom character is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal rectangle border. The right bottom character is null.");
    }
}

/* RECTANGLE_BORDER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
