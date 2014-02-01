/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECTANGLE_WIN32_DISPLAY_SERIALISER_SOURCE
#define RECTANGLE_WIN32_DISPLAY_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the rectangle into win32 display.
 *
 * @param p0 the connexion
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source whole properties data
 * @param p7 the source whole properties count
 * @param p8 the knowledge memory part
 */
void serialise_win32_display_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 display rectangle.");

    //?? TODO:
    // Line and Curve Functions:
    // http://msdn.microsoft.com/en-us/library/windows/desktop/dd145031%28v=vs.85%29.aspx
    // Filled Shape Functions:
    // http://msdn.microsoft.com/en-us/library/windows/desktop/dd162715%28v=vs.85%29.aspx
    // DrawTextEx function:
    // http://msdn.microsoft.com/en-us/library/windows/desktop/dd162499%28v=vs.85%29.aspx

    //?? xcb_poly_rectangle(c, *d, *gc, rc, &r);
}

/* RECTANGLE_WIN32_DISPLAY_SERIALISER_SOURCE */
#endif
