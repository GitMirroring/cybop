/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DISPLAY_AWAKENER_SOURCE
#define DISPLAY_AWAKENER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Let the system send an input to itself over display.
 *
 * @param p0 the input/output entry
 */
void awake_display(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake display.");
    fwprintf(stdout, L"Debug: Awake display. p0: %i\n", p0);

/*??
    #include <xcb/xtest.h>
    //?? xcb_test_fake_input(c, XCB_KEY_PRESS, keycode, XCB_CURRENT_TIME, XCB_NONE, 0, 0, 0);
    xcb_test_fake_input(c, XCB_KEY_PRESS, 0, XCB_CURRENT_TIME, XCB_NONE, 0, 0, 0);
*/
}

/* DISPLAY_AWAKENER_SOURCE */
#endif
