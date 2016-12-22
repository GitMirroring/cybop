/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_STARTER_SOURCE
#define SERIAL_PORT_STARTER_SOURCE

#include <fcntl.h>
#include <stdio.h>
#ifdef __APPLE__
    #include <termios.h>
#elif WIN32
    //Not needed
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#else
    #include <termios.h>
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/serial_port/open_serial_port_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the serial port.
 *
 * @param p0 the internal memory data
 * @param p1 the filename data
 * @param p2 the filename count
 * @param p3 the baudrate
 */
void startup_serial_port(void* p0, void* p1, void* p2, void* p3) {
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port.");

    // The terminated file name item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminated file name item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate terminated file name item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character file name into multibyte character data.
    encode_utf_8(t, p1, p2);

    // Add null termination character to terminated file name.
    append_item_element(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Get terminated file name item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    startup_serial_port_open(p0, td, p3);

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SERIAL_PORT_STARTER_SOURCE */
#endif
