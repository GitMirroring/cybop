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

#ifndef CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE
#define CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Encodes a character into a character entity reference (html escape reference).
 *
 * @param p0 the destination character entity reference (html escape reference)
 * @param p1 the destination character entity reference (html escape reference) count
 * @param p2 the destination character entity reference (html escape reference) size
 * @param p3 the source character
 * @param p4 the source character count
 */
/*??
void encode_character_entity_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                    compare_all_array((void*) &r, p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHARACTER_STATE_CYBOI_TYPE);

                    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

/*??
                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*ARRAY_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
                    }

                    // Add temporary value to destination.
                    overwrite_array(*d, p1, (void*) t, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode character entity reference. The destination is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode character entity reference. The destination count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode character entity reference. The destination size is null.");
    }
}
*/

/* CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE */
#endif
