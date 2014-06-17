/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLEANUP_CONTEXT_GUI_SERIALISER_SOURCE
#define CLEANUP_CONTEXT_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    //?? Add support for Cocoa
#elif WIN32
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/x_window_system/cleanup_context_x_window_system_serialiser.c"
#else
    #include "../../../../executor/representer/serialiser/x_window_system/cleanup_context_x_window_system_serialiser.c"
#endif

/**
 * Cleans up the gui context.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 */
void serialise_gui_context_cleanup(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui context cleanup.");

#ifdef __APPLE__
    //?? Add support for Cocoa
#elif WIN32
#elif GNU_LINUX_OPERATING_SYSTEM
    serialise_x_window_system_context_cleanup(p0, p1, p2, p3, p4);
#else
    serialise_x_window_system_context_cleanup(p0, p1, p2, p3, p4);
#endif
}

/* CLEANUP_CONTEXT_GUI_SERIALISER_SOURCE */
#endif
