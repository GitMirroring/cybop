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

#ifndef ELEMENT_FILE_WRITER_SOURCE
#define ELEMENT_FILE_WRITER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Writes the source element to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the break flag
 */
void write_file_element(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The character.
        int c = *NULL_ASCII_CHARACTER_CODE_MODEL;

        // Read character from source array.
        copy_array_forward((void*) &c, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

        if (c != *NULL_ASCII_CHARACTER_CODE_MODEL) {

            // Write character to character file stream.
            int e = fputc(c, (FILE*) p0);

            // Test error value.
            //
            // CAUTION! The macro EOF is an integer value that is
            // returned by fputc to indicate an end-of-file
            // condition, or some other error situation.
            //
            // With the GNU library, EOF is -1. In other libraries,
            // its value may be some other negative number.
            //
            // Therefore, this test checks for negative values in general.
            // The EOF symbol which is declared in stdio.h then does
            // not have to be considered explicitly here anymore.
            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Set break flag, so that the loop can be left in the next cycle.
                copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file element. The character is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file element. The file stream is null.");
    }
}

/* ELEMENT_FILE_WRITER_SOURCE */
#endif
