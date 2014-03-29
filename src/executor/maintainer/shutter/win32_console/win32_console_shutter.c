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

#ifndef WIN32_CONSOLE_SHUTTER_SOURCE
#define WIN32_CONSOLE_SHUTTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/shutter/win32_console/mode_win32_console_shutter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the win32 console.
 *
 * @param p0 the input handle data
 * @param p1 the output handle data
 * @param p2 the internal memory data
 */
void shutdown_win32_console(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown win32 console.");

    // Restore original console mode.
    shutdown_win32_console_mode(p0, p2, (void*) INPUT_MODE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    shutdown_win32_console_mode(p1, p2, (void*) OUTPUT_MODE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    //
    // CAUTION! The input- and output file descriptors are NOT closed here,
    // since they reference the "stdin" and "stdout" streams of the system,
    // which MUST NOT be closed.
    //
    // However, if they have to be closed one day for some reason,
    // then do NOT put these function calls in the if-else branch
    // of the attributes above!
    // Whilst the attributes have to be reset just ONCE for the terminal,
    // no matter which of the file descriptors are given,
    // the file descriptors themselves have to be closed each, one by one.
    //
    // shutdown_unix_terminal_close(p0);
    // shutdown_unix_terminal_close(p1);
}

/* WIN32_CONSOLE_SHUTTER_SOURCE */
#endif
