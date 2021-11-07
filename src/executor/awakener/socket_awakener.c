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

#ifndef SOCKET_AWAKENER_SOURCE
#define SOCKET_AWAKENER_SOURCE

#include <sys/ioctl.h> // ioctl
#include <errno.h> // errno

#include "../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Let the system send an input to itself over socket.
 *
 * @param p0 the input/output entry
 */
void awake_socket(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake socket.");
    fwprintf(stdout, L"Debug: Awake socket. p0: %i\n", p0);

    // Write data to ALL server socket client sensing threads,
    // so that it can be detected by the sensing thread function.

    // Loop through client list.

    // Write data to socket.
    // write();
}

/* SOCKET_AWAKENER_SOURCE */
#endif
