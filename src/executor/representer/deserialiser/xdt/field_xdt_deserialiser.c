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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FIELD_XDT_DESERIALISER_SOURCE
#define FIELD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/name/xdt/package_xdt_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Deserialises an xdt field.
 *
 * @param p0 the destination field size (pointer reference)
 * @param p1 the destination field identification (pointer reference)
 * @param p2 the destination field content (pointer reference)
 * @param p3 the destination field content count (pointer reference)
 * @param p4 the destination verification flag
 * @param p5 the source byte array (pointer reference)
 * @param p6 the source byte array count
 */
void deserialise_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p6;

        if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** s = (void**) p5;

            if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* v = (int*) p4;

                if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* fcc = (int*) p3;

                    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        void** fc = (void**) p2;

                        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* fs = (int*) p0;

                            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field.");

                            // The remaining bytes in the source byte array.
                            // They are used to check that the array border is not crossed.
                            int rem = (*sc * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                            if (rem >= (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Decode xdt field size.
//??                                deserialise_cybol_integer(p0, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *s, (void*) XDT_FIELD_SIZE_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                                rem = rem - (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                            }

                            if (rem >= (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Decode xdt field identification.
//??                                deserialise_cybol_integer(p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *s, (void*) XDT_FIELD_IDENTIFICATION_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                                rem = rem - (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                            }

                            if (*fs >= ((*XDT_FIELD_SIZE_COUNT + *XDT_FIELD_IDENTIFICATION_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Calculate xdt field content count.
                                //
                                // CAUTION! The xdt field size comprises all characters:
                                // - field size (3 bytes)
                                // - field identification (4 bytes)
                                // - field content (VARIABLE!)
                                // - carriage return (1 byte)
                                // - line feed (1 byte)
                                //
                                // It therefore has to be decremented here, so that
                                // only the actual xdt field content count remains.
                                *fcc = *fs - ((*XDT_FIELD_SIZE_COUNT + *XDT_FIELD_IDENTIFICATION_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                if (rem >= *fcc) {

                                    // Store xdt field content, to be returned.
                                    *fc = *s;

                                    // Increment source xdt byte array index.
                                    *s = *s + *fcc;
                                    rem = rem - *fcc;
                                }

                            } else {

                                // Store xdt field content, to be returned.
                                *fc = *NULL_POINTER_STATE_CYBOI_MODEL;
                                *fcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                            }

                            if (rem >= ((*PRIMITIVE_STATE_CYBOI_MODEL_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Verify if field end is reached (carriage return and line feed).

                                if (*((wchar_t*) *s) == *CARRIAGE_RETURN_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                    // Increment source xdt byte array index.
                                    *s = *s + (*PRIMITIVE_STATE_CYBOI_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                    if (*((wchar_t*) *s) == *LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                        // Increment source xdt byte array index.
                                        *s = *s + (*PRIMITIVE_STATE_CYBOI_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                        // Set verification flag indicating that
                                        // the xdt field was decoded correctly.
                                        *v = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                                    }
                                }
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The field size is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The field content is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The field content count is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The verification flag is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The source byte array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The source count is null.");
    }
}

/**
 * Deserialises the next xdt field.
 *
 * @param p0 the next field count = number of bytes to the next field (pointer reference)
 * @param p1 the byte array
 * @param p2 the byte array count
 */
void deserialise_xdt_next_field(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ac = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* a = (wchar_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* nc = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise next xdt field.");

                // The loop variable.
                int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (j >= *ac) {

                        // Set next field count to the end, that is to the
                        // full array count, as the carriage return plus
                        // line feed characters have not been found or
                        // the remaining array count was too small.
                        *nc = *ac;

                        break;
                    }

                    if ((j + (*PRIMITIVE_STATE_CYBOI_MODEL_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT)) <= *ac) {

                        if (*(a + (j * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) == *CARRIAGE_RETURN_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                            if (*(a + (j * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE) + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT) == *LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                // Set next field count to the first character following
                                // the carriage return plus line feed characters.
                                *nc = j + (*PRIMITIVE_STATE_CYBOI_MODEL_COUNT + *PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

                                // Set loop variable to full array count ac, as the next
                                // field has been found, so that the loop can be left.
                                j = *ac;
                            }
                        }
                    }

                    // Increment loop variable.
                    j++;
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise for next xdt field. The next field count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise for next xdt field. The byte array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise for next xdt field. The byte array count is null.");
    }
}

/* FIELD_XDT_DESERIALISER_SOURCE */
#endif
