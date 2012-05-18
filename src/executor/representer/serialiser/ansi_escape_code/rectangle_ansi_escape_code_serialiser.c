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
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/border_ansi_escape_code_serialiser.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/rows_ansi_escape_code_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the rectangle into ansi escape code.
 *
 * @param p0 the destination item
 * @param p1 the position x
 * @param p2 the size x
 * @param p3 the position y
 * @param p4 the size y
 * @param p5 the border data
 * @param p6 the border count
 */
void serialise_ansi_escape_code_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code rectangle.");

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

    serialise_ansi_escape_code_border((void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p5, p6);
    serialise_ansi_escape_code_rows(p0, (void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p1, p2, p3, p4);
}

/* RECTANGLE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
