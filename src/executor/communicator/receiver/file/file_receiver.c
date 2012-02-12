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

#ifndef FILE_RECEIVER_SOURCE
#define FILE_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/terminal/stream_terminal_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/file/stream_file_receiver.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/converter/decoder.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives via file into the destination.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data (file name)
 * @param p3 the source count
 * @param p4 the type
 * @param p5 the encoding
 */
void receive_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive file.");

    // The encoded message item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decoded message item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded message item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decoded message item data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate encoded message item.
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate decoded message item.
    allocate_item((void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Receive byte data via channel.
    receive_file_stream(e, p2, p3);

    // Get encoded message item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Decode data via encoding.
    decode(d, ed, ec, p5);

    // Get decoded message item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Deserialise data via type (language).
    deserialise(p0, p1, dd, dc, p4);

    // Deallocate byte message item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate decoded message item.
    deallocate_item((void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_RECEIVER_SOURCE */
#endif
