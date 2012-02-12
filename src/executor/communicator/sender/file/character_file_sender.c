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

#ifndef CHARACTER_FILE_SENDER_SOURCE
#define CHARACTER_FILE_SENDER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Sends the source as character.
 *
 * @param p0 the destination character file stream
 * @param p1 the source character
 * @param p2 the break flag
 */
void send_file_character(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Write character to character file stream.
        int e = fputc(*((int*) p1), (FILE*) p0);

        // Test error value.
        if (e == EOF) {

            // Set break flag, so that the loop can be left in the next cycle.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file character. The source character is null.");
    }
}

/* CHARACTER_FILE_SENDER_SOURCE */
#endif
