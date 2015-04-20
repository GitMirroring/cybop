/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DISPLAY_WRITER_SOURCE
#define DISPLAY_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    //?? Add cocoa support for Apple
#elif WIN32
    #include "../../../../executor/streamer/writer/win32_display/win32_display_writer.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/streamer/writer/xcb/xcb_writer.c"
#else
    #include "../../../../executor/streamer/writer/xcb/xcb_writer.c"
#endif

/**
 * Writes the source to the display.
 *
 * @param p0 the internal memory data
 */
void write_display(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write display.");

#ifdef __APPLE__
    //?? Add cocoa support for Apple
#elif WIN32
    write_win32_display(p0);
#elif GNU_LINUX_OPERATING_SYSTEM
    write_xcb(p0);
#else
    write_xcb(p0);
#endif
}

/* DISPLAY_WRITER_SOURCE */
#endif
