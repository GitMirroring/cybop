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
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the character into ansi escape code.
 *
 * @param p0 the destination item
 * @param p3 the character data
 * @param p4 the character count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p20 the border data
 * @param p21 the border count
 */
void serialise_ansi_escape_code_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code character.");

    // Place cursor at right position.
    serialise_ansi_escape_code_position(p0, (void*) &x, (void*) &y);

    if (y == *py) {

        if (x == *px) {

            // Append left top border character.
            append_item_element(p0, (void*) &ltc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

            // Append right top border character.
            append_item_element(p0, (void*) &rtc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            // Append horizontal border character.
            append_item_element(p0, (void*) &hc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

    } else if (y == (yl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

        if (x == *px) {

            // Append left bottom border character.
            append_item_element(p0, (void*) &lbc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

            // Append right bottom border character.
            append_item_element(p0, (void*) &rbc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            // Append horizontal border character.
            append_item_element(p0, (void*) &hc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

    } else {

        if (x == *px) {

            // Append vertical border character.
            append_item_element(p0, (void*) &vc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (x == (xl - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

            // Append vertical border character.
            append_item_element(p0, (void*) &vc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }
}

/**
 * Serialises the row into ansi escape code.
 *
 * @param p0 the destination item
 * @param p3 the character data
 * @param p4 the character count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p20 the border data
 * @param p21 the border count
 */
void serialise_ansi_escape_code_row(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code row.");

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (x >= xl) {

            break;
        }

        serialise_ansi_escape_code_character();

        // The character index ci does not have to be reset,
        // as it is always calculated before getting a character.

        // Reset character.
        c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

        x++;
    }
}

/**
 * Serialises the rows into ansi escape code.
 *
 * @param p0 the destination item
 * @param p3 the character data
 * @param p4 the character count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p20 the border data
 * @param p21 the border count
 */
void serialise_ansi_escape_code_rows(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code rows.");

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (y >= yl) {

            break;
        }

        serialise_ansi_escape_code_row();

        // Reset x loop count.
        x = *px;

        y++;
    }
}

/**
 * Serialises the rectangle into ansi escape code.
 *
 * @param p0 the destination item
 * @param p3 the character data
 * @param p4 the character count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p20 the border data
 * @param p21 the border count
 */
void serialise_ansi_escape_code_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code rectangle.");

    // The y loop count.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The x loop count.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The y loop limit as sum of position and size.
    int yl = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The x loop limit as sum of position and size.
    int xl = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The character index.
    int ci = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The character.
    void* c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

    // The horizontal border character.
    wchar_t hc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
    // The vertical border character.
    wchar_t vc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
    // The left top border character.
    wchar_t ltc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
    // The right top border character.
    wchar_t rtc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
    // The left bottom border character.
    wchar_t lbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
    // The right bottom border character.
    wchar_t rbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;

    // Initialise y loop count.
    calculate_integer_add((void*) &y, p??[py]);
    // Initialise x loop count.
    calculate_integer_add((void*) &x, p??[px]);
    // Initialise y loop limit.
    calculate_integer_add((void*) &yl, p??[py]);
    calculate_integer_add((void*) &yl, p??[sy]);
    // Initialise x loop limit.
    calculate_integer_add((void*) &xl, p??[px]);
    calculate_integer_add((void*) &xl, p??[sx]);

    // Determine border characters.
    serialise_ansi_escape_code_border((void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p20, p21);

    serialise_ansi_escape_code_rows();
}

/* RECTANGLE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
