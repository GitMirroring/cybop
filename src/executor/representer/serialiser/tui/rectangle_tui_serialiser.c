/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises the rectangle into tui.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the position x
 * @param p3 the size x
 * @param p4 the position y
 * @param p5 the size y
 * @param p6 the border data
 * @param p7 the border count
 */
void serialise_tui_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui rectangle.");
    //?? fwprintf(stdout, L"Debug: Serialise tui rectangle. position x p1: %i\n", p1);

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

    // Serialise tui border.
    serialise_tui_border((void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p6, p7);

    // Serialise tui rows.
    serialise_tui_rows(p0, p1, (void*) &hc, (void*) &vc, (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p2, p3, p4, p5);
}
