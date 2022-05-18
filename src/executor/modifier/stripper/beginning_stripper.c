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

#ifndef BEGINNING_STRIPPER_SOURCE
#define BEGINNING_STRIPPER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../executor/modifier/stripper/character_stripper.c"
#include "../../../executor/modifier/array_modifier.c"
#include "../../../logger/logger.c"

/**
 * Searches for a non-whitespace character from the BEGINNING of the given array.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 */
void strip_beginning(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip beginning.");
    fwprintf(stdout, L"Debug: Strip beginning. count remaining p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Strip beginning. count remaining *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Strip beginning. data position p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Strip beginning. data position p1 ls: %ls\n", (wchar_t*) p1);
    fwprintf(stdout, L"Debug: Strip beginning. data position *p1 lc: %lc\n", *((wchar_t*) p1));
    fwprintf(stdout, L"Debug: Strip beginning. data position *p1 lc as int: %i\n", *((wchar_t*) p1));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p3);
    // Copy source count remaining.
    copy_integer((void*) &c, p4);

    if (p4 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT copy anything to the destination if the
            // source is EMPTY or NO non-whitespace character could be found.
            //

            break;
        }

        // Search for a non-whitespace character within the given array.
        strip_character((void*) &b, (void*) &d, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A non-whitespace character has been found.
            //

            //
            // Overwrite string destination item.
            //
            // CAUTION! The source count remaining got already adapted
            // within the function "strip_character" above and can be
            // used as COUNT parametre AS IS.
            //
            modify_array(p0, d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }
    }
}

/* BEGINNING_STRIPPER_SOURCE */
#endif
