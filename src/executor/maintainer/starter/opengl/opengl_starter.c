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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPENGL_STARTER_SOURCE
#define OPENGL_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/x_window_system/x_window_system_starter.c"
#include "../../../../logger/logger.c"

//
// CAUTION! It is known that Xlib has several unfixable
// runtime issues that manifest in concurent access situations.
//
// This is one among the reasons why Xcb was created in the
// first place: Fix the problems of Xlib.
//
// GLX is specified against Xlib so this might seem
// like a show stopper when it comes to OpenGL.
// However there is a Xlib wrapping around Xcb
// and one can safely use that to interface with GLX
// and still use Xcb for the rest of the program:
//
// http://xcb.freedesktop.org/opengl/
//
// I see two possible solutions:
//
// Put a XLockDisplay/Mutex around XNextEvent and the GLX calls each;
// you don't have to lock for ordinary OpenGL, just the functions prefixed glX...
//
// Use Xcb to get runtime correct behaviour and follow
// the guide I linked above to make it work with OpenGL/GLX.
//

/**
 * Starts up the opengl system.
 *
 * @param p0 the internal memory data
 */
void startup_opengl(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup opengl.");

#ifdef GNU_LINUX_OPERATING_SYSTEM

    // Startup x window system AT FIRST.
    // The opengl environment needs its windows to have something to paint on.
    startup_x_window_system(p0);

/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/* OPENGL_STARTER_SOURCE */
#endif
