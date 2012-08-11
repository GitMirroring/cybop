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

#ifndef NUMERIC_CHARACTER_REFERENCE_SERIALISER_SOURCE
#define NUMERIC_CHARACTER_REFERENCE_SERIALISER_SOURCE

#include "../../../../constant/character/character_constants.c"
#include "../../../../constant/character/numeric_character_reference_constants.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Serialises a character into a numeric character reference (html escape code).
 *
 * @param p0 the destination numeric character reference (html escape code) (pointer reference)
 * @param p1 the destination numeric character reference (html escape code) count
 * @param p2 the destination numeric character reference (html escape code) size
 * @param p3 the source character
 * @param p4 the source character count
 */
void serialise_numeric_character_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER_STATE_CYBOI_MODEL;
                int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                int ts = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // The comparison result.
                int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

/*??
                if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    compare_all_array((void*) &r, p3, p4, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

                    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Add temporary value to destination.
                    overwrite_array(p0, (void*) t, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &tc, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise numeric character reference. The destination is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise numeric character reference. The destination count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise numeric character reference. The destination size is null.");
    }
}

/* NUMERIC_CHARACTER_REFERENCE_SERIALISER_SOURCE */
#endif
