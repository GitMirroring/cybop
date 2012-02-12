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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SENDER_SOURCE
#define FILE_SENDER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/file/stream_file_sender.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Sends a knowledge model as byte stream to the operating system's file system.
 *
 * @param p15 the destination item (file name)
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p3 the type
 * @param p0 the internal memory
 * @param p13 the source clean flag
 */
void send_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send file.");

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised wide character item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate serialised wide character array.
    allocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded character item.
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise source knowledge model into serialised wide character array.
//    serialise(s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    // Get serialised wide character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8(e, sd, sc);

    // Get encoded character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Write encoded array into file stream.
    send_file_stream((void*) &p15, p16, *NULL_POINTER_STATE_CYBOI_MODEL, ed, ec);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* FILE_SENDER_SOURCE */
#endif
