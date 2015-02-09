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

#ifndef DISPLAY_READER_SOURCE
#define DISPLAY_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    //?? Add Cocoa support
#elif WIN32
    #include "../../../../executor/communicator/receiver/win32_display/win32_display_reader.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/communicator/receiver/x_window_system/x_window_system_reader.c"
#else
    #include "../../../../executor/communicator/receiver/x_window_system/x_window_system_reader.c"
#endif

/**
 * Reads user input to the display.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source root window data
 * @param p3 the source root window count
 * @param p4 the knowledge memory part
 * @param p5 the internal memory data
 * @param p6 the format
 * @param p7 the language
 */
void read_display(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read display.");

#ifdef __APPLE__
    //?? Add Cocoa support
#elif WIN32
    read_win32_display(p0, p1, p2, p3, p4, p5, p6, p7);
#elif GNU_LINUX_OPERATING_SYSTEM
    read_x_window_system(p0, p1, p2, p3, p4, p5, p6, p7);
#else
    read_x_window_system(p0, p1, p2, p3, p4, p5, p6, p7);
#endif
}

/* DISPLAY_READER_SOURCE */
#endif
