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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WHITESPACE_SELECTOR_NORMALISER_SOURCE
#define WHITESPACE_SELECTOR_NORMALISER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/modifier/normaliser/whitespace_normaliser.c"
#include "../../../executor/modifier/array_modifier.c"
#include "../../../executor/mover/mover.c"
#include "../../../executor/selector/whitespace/whitespace_selector.c"
#include "../../../logger/logger.c"

/**
 * Searches for a whitespace character.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void normalise_select_whitespace(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise select whitespace.");
/*??
    fwprintf(stdout, L"Debug: Normalise select whitespace. count remaining p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Normalise select whitespace. count remaining *p4: %i\n", *((int*) p4));
    fwprintf(stdout, L"Debug: Normalise select whitespace. data position *p3: %i\n", *((void**) p3));
    fwprintf(stdout, L"Debug: Normalise select whitespace. data position *p3 ls: %ls\n", (wchar_t*) *((void**) p3));
    fwprintf(stdout, L"Debug: Normalise select whitespace. data position *p3 lc: %lc\n", *((wchar_t*) *((void**) p3)));
    fwprintf(stdout, L"Debug: Normalise select whitespace. data position *p3 lc as int: %i\n", *((wchar_t*) *((void**) p3)));
*/

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Detect non-whitespace character.
    select_whitespace((void*) &r, p3, p4);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A WHITESPACE character HAS been found
        //

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise select whitespace. Found whitespace character.");
        //?? fwprintf(stdout, L"Debug: Normalise select whitespace. Found whitespace character. count remaining p4: %i\n", p4);
        //?? fwprintf(stdout, L"Debug: Normalise select whitespace. Found whitespace character. count remaining *p4: %i\n", *((int*) p4));

        // Parse whitespace characters.
        normalise_whitespace(p0, p1, p2, p3, p4);

    } else {

        //
        // This is a NON-whitespace character
        //

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise select whitespace. Found non-whitespace character.");
/*??
        fwprintf(stdout, L"Debug: Normalise select whitespace. Found non-whitespace character. count remaining p4: %i\n", p4);
        fwprintf(stdout, L"Debug: Normalise select whitespace. Found non-whitespace character. count remaining *p4: %i\n", *((int*) p4));
        fwprintf(stdout, L"Debug: Normalise select whitespace. Found non-whitespace character. data position *p3: %i\n", *((void**) p3));
        fwprintf(stdout, L"Debug: Normalise select whitespace. Found non-whitespace character. data position *p3 ls: %ls\n", (wchar_t*) *((void**) p3));
        fwprintf(stdout, L"Debug: Normalise select whitespace. Found non-whitespace character. data position *p3 lc: %lc\n", *((wchar_t*) *((void**) p3)));
*/

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The source data.
            void** d = (void**) p3;

            // Append character AS IS to destination.
            modify_array(p0, *d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Increment the current position by one.
            move(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not normalise select whitespace. The source data position is null.");
            fwprintf(stdout, L"Error: Could not normalise select whitespace. The source data position is null. p3: %i\n", p3);
        }
    }
}

/* WHITESPACE_SELECTOR_NORMALISER_SOURCE */
#endif
