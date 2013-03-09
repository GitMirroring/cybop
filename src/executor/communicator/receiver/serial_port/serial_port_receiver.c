/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_RECEIVER_SOURCE
#define SERIAL_PORT_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

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
 * @param p2 the encoding
 * @param p3 the internal memory data
 */
void receive_serial_port(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive serial port.");

    // The decoded message item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decoded message item data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate decoded message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Receive byte data via channel.
    receive_serial_port_file(d, p3);

    // Get decoded message item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Decode data.
    //
    // CAUTION! The multibyte character sequence is converted here.
    // Since serial port data are mostly evaluated bytewise within a
    // cybol application, the conversion is from unsigned char into
    // mostly integer or the ascii char elements (bytes) are just copied.
    decode(p0, dd, dc, p2);

    // CAUTION! The multibyte character sequence is NOT deserialised
    // into a cyboi-internal part, since serial port data are mostly
    // to be evaluated bytewise within a cybol application.
    // The "language" and "format" parametres are therefore obsolete.

    // Deallocate decoded message item.
    deallocate_item((void*) &d, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SERIAL_PORT_RECEIVER_SOURCE */
#endif
