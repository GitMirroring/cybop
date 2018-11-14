/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef IO_SHUTTER_SOURCE
#define IO_SHUTTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../executor/maintainer/starter/deallocate_io_maintainer.c"
#include "../../executor/maintainer/starter/get_io_maintainer.c"
#include "../../executor/maintainer/starter/set_io_maintainer.c"
#include "../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. socket port)
 * @param p2 the socket client socket
 * @param p3 the socket mode data
 * @param p4 the socket mode count
 * @param p5 the socket network service data
 * @param p6 the socket network service count
 * @param p7 the channel
 */
void shutdown_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown.");

}

/* IO_SHUTTER_SOURCE */
#endif
