/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "client.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Deserialises a cybol file.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the language properties (constraints) data
 * @param p4 the language properties (constraints) count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the format
 * @param p9 the language
 * @param p10 the channel
 */
void deserialise_cybol_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol file.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. channel p10: %i\n", p10);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. channel *p10: %i\n", *((int*) p10));

    //
    // CAUTION! The default encoding value MUST NOT be assigned
    // in general and for all parts above, since the function
    // "receive_data" below tests the encoding for null.
    //
    // If the language is for example "message/binary", then NO encoding
    // is given, since it does not make sense for images etc.
    //
    // Therefore, assign standard encoding ONLY for channel "file".
    //

    // The file identification (descriptor).
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Open file.
    open_file((void*) &id, p1, p2, (void*) READ_OPEN_MODE_FILE_MODEL, (void*) READ_OPEN_MODE_FILE_MODEL_COUNT);

    //
    // Fill part model item taken from cybol source part properties.
    //
    // CAUTION! Use the cybol FORMAT and NOT the cyboi destination type.
    //
    // CAUTION! Hand over utf-8 encoding since cybol files are using it by default.
    //
    receive_data(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p3, p4, p5, p6, p7, p8, p9, (void*) UTF_8_CYBOI_ENCODING, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p10);

    // Close file.
    close_basic((void*) &id);
}
