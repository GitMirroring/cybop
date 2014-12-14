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

#ifndef SYMBOLIC_NAME_GLOBALISER_SOURCE
#define SYMBOLIC_NAME_GLOBALISER_SOURCE

//??#include "../../controller/globaliser/symbolic_name/address_family_socket_symbolic_name_globaliser.c"
#include "../../controller/globaliser/symbolic_name/baudrate_serial_symbolic_name_globaliser.c"
//??#include "../../controller/globaliser/symbolic_name/protocol_family_socket_symbolic_name_globaliser.c"
//??#include "../../controller/globaliser/symbolic_name/protocol_socket_symbolic_name_globaliser.c"

/**
 * Initialises symbolic name (pre-processor-defined) global variables.
 */
void globalise_symbolic_name() {

    //
    // Socket.
    //

//??    globalise_symbolic_name_socket_protocol_family();
//??    globalise_symbolic_name_socket_address_family();
//??    globalise_symbolic_name_socket_protocol();

    //
    // Serial port.
    //

    globalise_symbolic_name_serial_baudrate();
}

/* SYMBOLIC_NAME_GLOBALISER_SOURCE */
#endif
