/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BASE_INTEGER_CYBOL_SERIALISER_SOURCE
#define BASE_INTEGER_CYBOL_SERIALISER_SOURCE

#ifdef WIN32
    #include <windows.h>
    #define swprintf _snwprintf
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises integer value according to the given base.
 *
 * @param p0 the destination data
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source value
 * @param p4 the number base:
 *           8 - octal, e.g. 083
 *           10 - decimal, e.g. 1234
 *           16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
 */
void serialise_cybol_integer_base(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol integer base.");

                    // Transform source value to destination string.
                    // A null wide character is written to mark the end of the string.
                    // The return value is the number of characters generated
                    // for the given input, excluding the trailing null.
                    // If not all output fits into the provided buffer,
                    // a negative value is returned.

                    // The comparison result.
                    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        compare_integer_equal((void*) &r, p4, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL);

                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            *dc = swprintf(p0, *ds, L"%o", *s);

                        }
                    }

                    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        compare_integer_equal((void*) &r, p4, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);

                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            *dc = swprintf(p0, *ds, L"%d", *s);

                        }
                    }

                    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        compare_integer_equal((void*) &r, p4, (void*) NUMBER_16_INTEGER_STATE_CYBOI_MODEL);

                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            *dc = swprintf(p0, *ds, L"%X", *s);

                        }
                    }

                    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer base. The number base is invalid.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer base. The destination data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer base. The destination count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer base. The destination size is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer base. The source value is null.");
    }
}

/* BASE_INTEGER_CYBOL_SERIALISER_SOURCE */
#endif
