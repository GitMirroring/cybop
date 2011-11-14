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

#ifndef CHARACTER_ENTITY_REFERENCE_DECODER_SOURCE
#define CHARACTER_ENTITY_REFERENCE_DECODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Decodes a character entity reference (html escape reference) into a character.
 *
 * @param p0 the destination character data
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source character entity reference (html escape reference)
 * @param p4 the source character entity reference (html escape reference) count
 */
/*??
void decode_character_entity_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*ARRAY_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE_COUNT);
                    }

                    // Add temporary value to destination.
                    overwrite_array(*d, p1, (void*) t, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode character entity reference. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode character entity reference. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode character entity reference. The destination size is null.");
    }
}
*/

/* CHARACTER_ENTITY_REFERENCE_DECODER_SOURCE */
#endif
