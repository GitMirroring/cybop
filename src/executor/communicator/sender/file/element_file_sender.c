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

#ifndef ELEMENT_FILE_SENDER_SOURCE
#define ELEMENT_FILE_SENDER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/file/character_file_sender.c"
#include "../../../../executor/communicator/sender/file/wide_character_file_sender.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Sends the source element to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the break flag
 * @param p4 the wide character flag (FALSE_BOOLEAN_STATE_CYBOI_MODEL - char; TRUE_BOOLEAN_STATE_CYBOI_MODEL - wchar_t)
 */
void send_file_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The character.
    char c = *NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Read character from source array.
    copy_array_forward((void*) &c, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    compare_integer_equal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        send_file_character(p0, (void*) &c, p3);

    } else {

        send_file_wide_character(p0, (void*) &c, p3);
    }
}

/* ELEMENT_FILE_SENDER_SOURCE */
#endif
