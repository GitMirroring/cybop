/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef QUOTATION_BEGIN_JOINED_STRING_SELECTOR_SOURCE
#define QUOTATION_BEGIN_JOINED_STRING_SELECTOR_SOURCE

#include "../../../constant/model/backslash_escape/backslash_escape_model.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/name/json/json_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/mover/mover.c"
#include "../../../logger/logger.c"

/**
 * Selects the joined string quotation begin.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the value count
 * @param p3 the break flag
 */
void select_joined_string_begin_quotation(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string quotation begin.");
    fwprintf(stdout, L"Debug: Select joined string quotation begin. count remaining p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Select joined string quotation begin. count remaining *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //?? TODO: skip_whitespace_characters

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // arbitrary quotation character sequence (handed over as parametre)
        detect((void*) &r, p0, p1, (void*) BEGIN_END_STRING_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_END_STRING_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise value.
            deserialise_joined_string_value(p2, p3, (void*) &vc, (void*) &b);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // comma or other delimiter
        detect((void*) &r, p0, p1, (void*) BEGIN_END_STRING_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_END_STRING_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A quotation character could NOT be found.
            // Instead, a delimiter was detected UNEXPECTEDLY.
            // However, this is NOT an empty value since that
            // would have to be put in quotation characters.
            // Therefore, do NOT allocate a part here.
            //

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select joined string quotation begin. A quotation sequence could not be found. Instead, a delimiter was detected unexpectedly.");
            fwprintf(stdout, L"Debug: Could not select joined string quotation begin. A quotation sequence could not be found. Instead, a delimiter was detected unexpectedly. count remaining p1: %i\n", p1);
            fwprintf(stdout, L"Debug: Could not select joined string quotation begin. A quotation sequence could not be found. Instead, a delimiter was detected unexpectedly. count remaining *p1: %i\n", *((int*) p1));

            // Set loop break flag.
            copy_integer(px, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select joined string quotation begin. This should not happen. Neither a whitespace, nor a quotation character, nor a delimiter was found.");
        fwprintf(stdout, L"Debug: Could not select joined string quotation begin. This should not happen. Neither a whitespace, nor a quotation character, nor a delimiter was found. count remaining p1: %i\n", p1);
        fwprintf(stdout, L"Debug: Could not select joined string quotation begin. This should not happen. Neither a whitespace, nor a quotation character, nor a delimiter was found. count remaining *p1: %i\n", *((int*) p1));

        // Set loop break flag.
        copy_integer(px, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* QUOTATION_BEGIN_JOINED_STRING_SELECTOR_SOURCE */
#endif
