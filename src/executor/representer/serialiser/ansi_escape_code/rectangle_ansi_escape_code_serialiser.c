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

#ifndef RECTANGLE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define RECTANGLE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
//?? #include "../../../../constant/model/cybol/border_cybol_model.c"
//?? #include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
//?? #include "../../../../constant/model/terminal/ansi_escape_code_model.c"
//?? #include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
//?? #include "../../../../constant/name/cybol/super_cybol_name.c"
//?? #include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
//?? #include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
//?? #include "../../../../executor/accessor/getter/compound_getter.c"
//?? #include "../../../../executor/accessor/getter.c"
//?? #include "../../../../executor/modifier/overwriter/array_overwriter.c"
//?? #include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
//?? #include "../../../../executor/representer/serialiser/terminal_background_serialiser.c"
//?? #include "../../../../executor/representer/serialiser/terminal_foreground_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the rectangle into ansi escape code.
 *
 * @param p0 the destination item
 * @param p3 the character data
 * @param p4 the character count
 * @param p5 the hidden flag
 * @param p6 the inverse flag
 * @param p7 the blink flag
 * @param p8 the underline flag
 * @param p9 the bold flag
 * @param p10 the background data
 * @param p11 the background count
 * @param p12 the foreground data
 * @param p13 the foreground count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p20 the border data
 * @param p21 the border count
 */
void serialise_ansi_escape_code_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21) {

    if (p18 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sy = (int*) p18;

        if (p17 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sx = (int*) p17;

            if (p15 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* py = (int*) p15;

                if (p14 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* px = (int*) p14;

                    int* cc = (int*) p4;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code rectangle.");

                    // The horizontal character.
                    wchar_t hc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                    // The vertical character.
                    wchar_t vc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                    // The left top character.
                    wchar_t ltc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                    // The right top character.
                    wchar_t rtc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                    // The left bottom character.
                    wchar_t lbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                    // The right bottom character.
                    wchar_t rbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;

                    // Determine border characters.
                    serialise_ansi_escape_code_rectangle_border((void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p20, p21);

                    // The y loop count.
                    int y = *py;
                    // The x loop count.
                    int x = *px;
                    // The y loop limit as sum of position and size.
                    int yl = *py + *sy;
                    // The x loop limit as sum of position and size.
                    int xl = *px + *sx;

                    // The character index.
                    int ci = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    // The character.
                    void* c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

                    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                        if (y >= yl) {

                            break;
                        }

                        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                            if (x >= xl) {

                                break;
                            }

                            if (p20 == *NULL_POINTER_STATE_CYBOI_MODEL) {

                                // A border is NOT given.

                                if (cc != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    // Calculate character index.
                                    ci = x - *px;

                                    if (ci < *cc) {

                                        // Get character value at position x.
                                        get((void*) &c, p3, (void*) &ci, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                                    }

                                    // Encode character using escape codes.
                                    serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, c);

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
                                }

                            } else {

                                // A border IS given.

                                if (y == *py) {

                                    if (x == *px) {

                                        // Encode left top border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &ltc);

                                    } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

                                        // Encode right top border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &rtc);

                                    } else {

                                        // Encode horizontal border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                    }

                                } else if (y == (yl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

                                    if (x == *px) {

                                        // Encode left bottom border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &lbc);

                                    } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

                                        // Encode right bottom border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &rbc);

                                    } else {

                                        // Encode horizontal border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                    }

                                } else {

                                    if (x == *px) {

                                        // Encode left bottom border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                    } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

                                        // Encode right bottom border character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                    } else {

                                        if (cc != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                            // Calculate character index.
                                            // CAUTION! Subtract one because of the left border.
                                            ci = x - *px - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                                            if (ci < *cc) {

                                                // Get character value at position x.
                                                get(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                                            }

                                        } else {

                                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
                                        }

                                        // Encode character using escape codes.
                                        serialise_ansi_escape_code_character(p0, p1, p2, &x, &y, p10, p11, p12, p13, p5, p6, p7, p8, p9, c);
                                    }
                                }
                            }

                            // The character index ci does not have to be reset,
                            // as it is always calculated before getting a character.

                            // Reset character.
                            c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

                            x++;
                        }

                        // Reset x loop count.
                        x = *px;

                        y++;
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code rectangle. The character count is null.");
    }
}

/* RECTANGLE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
