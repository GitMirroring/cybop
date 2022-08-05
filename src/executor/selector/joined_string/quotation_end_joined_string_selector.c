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

#ifndef QUOTATION_END_JOINED_STRING_SELECTOR_SOURCE
#define QUOTATION_END_JOINED_STRING_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/mover/mover.c"
#include "../../../logger/logger.c"

/**
 * Selects the joined string value end by searching for the given delimiter sequence,
 * consisting of a quotation and the actual delimiter.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the escape data, e.g. a DOUBLE quotation mark
 * @param p3 the escape count
 * @param p4 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p5 the quotation end PLUS delimiter count
 * @param p6 the quotation end data, e.g. a quotation mark
 * @param p7 the quotation end count
 * @param p8 the value count
 * @param p9 the break flag
 */
void select_joined_string_end_quotation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string end quotation.");
    fwprintf(stdout, L"Debug: Select joined string end quotation. source count remaining p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Select joined string end quotation. source count remaining *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The ORDER of the following function calls is IMPORTANT!
    // The escape characters have to be skipped BEFORE
    // the end delimiter sequence gets detected.
    //
    // Example: """value 1"", with comma and additional content", "value 2", "value 3"
    //
    // The double quotation marks are escaped and represent just ONE quotation mark.
    // The comma following after the double quotation marks does NOT represent
    // a delimiter, since it is standing in between the quoted sequence.
    //

    //
    // CAUTION! Do NOT skip whitespace characters here,
    // since they might belong to the actual VALUE.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Skip escape characters.
        detect((void*) &r, p0, p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Select joined string end quotation. test escape r: %i\n", r);

            //
            // Adjust value count.
            //
            // CAUTION! Do NOT just use NUMBER_1_INTEGER_STATE_CYBOI_MODEL
            // but correct quotation character sequence xx_COUNT instead!
            //
            calculate_integer_add(p8, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Detect COMBINATION of quotation and delimiter sequence.
        detect((void*) &r, p0, p1, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Select joined string end quotation. test combination r: %i\n", r);

            // Set loop break flag.
            copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Detect quotation end ONLY sequence.
        //
        // CAUTION! This is more proper than letting the loop detect a
        // remaining count <= zero, since it is a well-defined end sequence.
        // It applies for the LAST value only.
        //
        detect((void*) &r, p0, p1, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Select joined string end quotation. test quotation r: %i\n", r);

            // Set loop break flag.
            copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If a standalone delimiter (e.g. comma) character is found,
        // then it gets IGNORED and is treated like any other character,
        // since standing WITHIN the quotation.
        //

        fwprintf(stdout, L"Debug: Select joined string end quotation. test move r: %i\n", r);

        // Increment the current position by one.
        move(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust value count.
        calculate_integer_add(p8, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* QUOTATION_END_JOINED_STRING_SELECTOR_SOURCE */
#endif
