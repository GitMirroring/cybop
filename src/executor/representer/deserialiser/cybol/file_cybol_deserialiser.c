/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FILE_CYBOL_DESERIALISER_SOURCE
#define FILE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/encoding/cyboi/cyboi_encoding.c"
#include "../../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/file/open_mode_file_model.c"
//
// CAUTION! Do NOT include file "receiver",
// in order to avoid circular references.
// Use a forward declaration instead (see below).
// #include "../../../../executor/communicator/receiver/receiver.c"
//
#include "../../../../executor/dispatcher/closer/basic/basic_closer.c"
#include "../../../../executor/dispatcher/opener/file/file_opener.c"
#include "../../../../logger/logger.c"

//
// Forward declaration
//

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);

/**
 * Deserialises a cybol file.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the channel
 * @param p4 the format
 */
void deserialise_cybol_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol file.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. *p3: %i\n", *((int*) p3));

    //
    // CAUTION! The default encoding value MUST NOT be assigned
    // in general and for all parts above, since the function
    // "receive_data" below tests the encoding for null.
    //
    // If the language is e.g. "message/binary", then NO encoding
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
    // CAUTION! What is the properties in a parsed xml/cybol file,
    // becomes the model in the cyboi-internal knowledge tree.
    //
    // CAUTION! Use the CYBOL cyboi destination type determined above
    // (and NOT the cyboi destination type)!
    //
    receive_data(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p4, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE, (void*) UTF_8_CYBOI_ENCODING, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3);

    // Close file.
    close_basic((void*) &id);
}

/* FILE_CYBOL_DESERIALISER_SOURCE */
#endif
