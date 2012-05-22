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

#ifndef WIDE_CHARACTER_COMPARATOR_SOURCE
#define WIDE_CHARACTER_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Compares the left- with the right wide character.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation type
 */
void compare_wide_character(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* a = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* rv = (wchar_t*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                wchar_t* lv = (wchar_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* res = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare wide character.");

                    // The comparison result.
                    // CAUTION! It is used instead of if-else statements.
                    // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
                    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (*a == *EQUAL_COMPARE_LOGIC_FORMAT_TYPE) {

                            r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            if (*lv == *rv) {

                                *res = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (*a == *SMALLER_COMPARE_LOGIC_CYBOI_FORMAT) {

                            r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            if (*lv < *rv) {

                                *res = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (*a == *GREATER_COMPARE_LOGIC_CYBOI_FORMAT) {

                            r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            if (*lv > *rv) {

                                *res = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (*a == *SMALLER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE) {

                            r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            if (*lv <= *rv) {

                                *res = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (*a == *GREATER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE) {

                            r = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            if (*lv >= *rv) {

                                *res = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare wide character. The operation type is unknown.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare wide character. The result is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare wide character. The left value is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare wide character. The right value is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare wide character. The operation type is null.");
    }
}

/* WIDE_CHARACTER_COMPARATOR_SOURCE */
#endif
