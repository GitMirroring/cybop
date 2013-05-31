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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_RECEIVER_SOURCE
#define SERIAL_PORT_RECEIVER_SOURCE

#include <errno.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/serial_port/file_serial_port_receiver.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Receives data via serial port.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the minimum number of bytes to be received in one call of the read function
 * @param p3 the maximum number of bytes to be received in one call of the read function
 * @param p4 the internal memory data
 */
void receive_serial_port(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive serial port.");

    // Receive byte data via channel.
    receive_serial_port_file(p0, p2, p3, p4);

    // CAUTION! The multibyte character sequence is NOT decoded
    // into a wide character array, since serial port data are mostly
    // evaluated bytewise within a cybol application.
    // The "encoding" parametre is therefore obsolete.

    // CAUTION! The byte data are NOT deserialised into a
    // cyboi-internal part, since serial port data are mostly
    // evaluated bytewise within a cybol application.
    // The "language" and "format" parametres are therefore obsolete.
}

/* SERIAL_PORT_RECEIVER_SOURCE */
#endif
