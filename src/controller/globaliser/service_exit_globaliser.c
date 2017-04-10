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

#ifndef SERVICE_EXIT_GLOBALISER_SOURCE
#define SERVICE_EXIT_GLOBALISER_SOURCE

#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../variable/service_interrupt.c"

/**
 * Initialises service thread exit global variables.
 */
void globalise_service_exit() {

    //
    // The service exit variables are accessed in the system signal handler.
    // Since the "interrupt_service_system_signal_handler" function
    // receives no parametres besides a simple signal numeric code,
    // neither the exit variables nor the internal memory can be
    // handed over as argument.
    //
    // Therefore, they HAVE TO be defined as GLOBAL variables here.
    //

    *DISPLAY_EXIT = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    *SERIAL_EXIT = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    *SOCKET_EXIT = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    *TERMINAL_EXIT = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
}

/* SERVICE_EXIT_GLOBALISER_SOURCE */
#endif
