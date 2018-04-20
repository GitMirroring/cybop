/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_STARTER_SOURCE
#define TERMINAL_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/terminal/open_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the terminal.
 *
 * @param p0 the internal memory data
 */
void startup_terminal(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal.");

    //
    // This place might be needed in the future.
    // In case a special terminal device like /dev/tty0
    // is given, its file name needs to be handed over
    // as null-terminated character array.
    // The file name may be prepared here then
    // by adding the null-termination.
    // See "serial_port_starter.c"!
    //

    startup_terminal_open(p0);
}

/* TERMINAL_STARTER_SOURCE */
#endif
