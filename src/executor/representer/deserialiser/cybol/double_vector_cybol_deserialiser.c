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

#ifndef DOUBLE_VECTOR_DESERIALISER_SOURCE
#define DOUBLE_VECTOR_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the wide character data into a double vector.
 *
 * @param p0 the destination vector data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void deserialise_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** s = (void**) p3;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** d = (void**) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise double vector.");

/*??
                // The loop count.
                int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // The comma index.
                int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                // The double vector element count.
                void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The double number.
                int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (j >= *sc) {

                        break;
                    }

                    get_character_array_elements_index(p3, p4, (void*) COMMA_CHARACTER_CODE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i);

                    if (i > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // Determine double vector element count.
                        c = *s + i;

                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as vector element (source) count: index i
                        // (which is 3, as needed for the length)
                        deserialise_double(d, dc, ds, p3, &i);

                        // Recursively call this procedure for the remaining double vector elements.
                        deserialise_double_vector(d, dc, ds, new_start_vector, sc);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise double vector. The source string starts with a comma character.");
                    }

                    j++;
                }

                // Read input stream and transform to double vector.
                //??    fscanf(p1, %d, &(m->x));
                //??    fscanf(p1, %d, &(m->y));
                //??    fscanf(p1, %d, &(m->z));

                // Initialise elements.
                int z = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Set elements.
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
*/

/*??
                int i1 = s.indexOf(",");

                if (i1 != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

                    char[] x = s.substring(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL, i1);
                    char[] yz = s.substring(i1 + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                    int i2 = yz.indexOf(",");

                    if (i2 != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

                        char[] y = yz.substring(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL, i2);
                        char[] z = yz.substring(i2 + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

                        p.x = java.lang.Integer.parseInt(x);
                        p.y = java.lang.Integer.parseInt(y);
                        p.z = java.lang.Integer.parseInt(z);

                    } else {

            //??            log_message((void*) &ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) &"Could not create double vector. The vector does not contain a z coordinate.");
                    }

                } else {

            //??        log_message((void*) &ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) &"Could not create double vector. The vector does not contain an y coordinate.");
                }
*/

            } else {

//??                log_message((void*) &ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/* DOUBLE_VECTOR_DESERIALISER_SOURCE */
#endif
