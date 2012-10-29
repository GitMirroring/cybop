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

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/xdt/bdt_xdt_name.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../executor/calculator/basic/integer/subtract_integer_calculator.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/comparator/basic/integer/smaller_integer_comparator.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/xdt/element_field_xdt_deserialiser.c"
#include "../../../../executor/searcher/selector/xdt/end_field_xdt_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises an xdt field.
 *
 * An xdt field consists of the following elements:
 * - size: 3 Byte
 * - dependency hierarchy: 1 Byte
 * - identification: 4 Byte
 * - content: variable
 * - end (carriage return + line feed): 2 Byte
 *
 * content count = size value - 10 Byte (3 + 1 + 4 + 2)
 *
 * @param p0 the destination field content data (pointer reference)
 * @param p1 the destination field content count
 * @param p2 the destination field identification
 * @param p3 the destination field dependency hierarchy
 * @param p4 the destination field size
 * @param p5 the source data position (pointer reference)
 * @param p6 the source count remaining
 * @param p7 the bdt standard main version
 */
void deserialise_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field.");

    // The field size.
    // CAUTION! It seems to be useless, since a field's end
    // is defined as line feed + carriage return
    // and may thus be detected and thereby
    // count the length of the field.
    // However, it is used below for verifying if
    // calculated and given field size match.
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The first field flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The bdt standard legacy flag (true for main version < 3).
    int l = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The field dependency hierarchy.
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The calculated field content count.
    int cc2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Deserialise size.
    deserialise_xdt_field_element((void*) &s, p5, p6, (void*) SIZE_FIELD_BDT_XDT_NAME_COUNT);

    // Compare for first field.
    compare_integer_equal((void*) &f, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The bdt standard main version handed over as parametre is zero.
        // Therefore, this is the first xdt field processed within the file.

        // Figure out bdt standard main version using field size.
        // The bdt versions >= 3 contain an additional dependency hierarchy byte.
        //
        // Example for first bdt field in version (cr + lf = 2 byte are invisible):
        // 2.x: 01380000020
        // 3.x: 014180000020
        // The first three bytes represent the size, either 13 or 14.
        if (s > *NUMBER_13_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p7, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

        } else {

            copy_integer(p7, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    // Compare for bdt standard legacy version.
    compare_integer_smaller((void*) &l, p7, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

    if (l == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The bdt version is >= 3.
        // The dependency hierarchy byte exists.

        // Deserialise dependency hierarchy.
        deserialise_xdt_field_element((void*) &h, p5, p6, (void*) HIERARCHY_FIELD_BDT_XDT_NAME_COUNT);
    }

    // Deserialise identification.
    deserialise_xdt_field_element((void*) &i, p5, p6, (void*) IDENTIFICATION_FIELD_BDT_XDT_NAME_COUNT);

    // Calculate field content count.
    // CAUTION! The xdt field size comprises ALL elements, even itself.
    copy_integer((void*) &cc2, (void*) &s);

    if (l == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The bdt version is >= 3.
        // The dependency hierarchy byte DOES exist.

        // Subtract meta bytes.
        // content count = size value - 10 Byte (3 size + 1 dependency hierarchy + 4 identification + 2 cr and lf)
        calculate_integer_subtract((void*) &cc2, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);

    } else {

        // The bdt version is < 3.
        // The dependency hierarchy byte does NOT exist.

        // Subtract meta bytes.
        // content count = size value - 9 Byte (3 size + 4 identification + 2 cr and lf)
        calculate_integer_subtract((void*) &cc2, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL);
    }

    // Initialise field content data.
    copy_pointer((void*) &cd, p5);

    if (p6 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p6, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_xdt_field_end((void*) &b, p5, p6);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment destination field content count.
            calculate_integer_add((void*) &cc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    // Verify correctness by comparing the following two field content counts:
    // - calculated above from size given at beginning of xdt field
    // - incremented until the xdt field end (cr, lf) was detected
    compare_integer_equal((void*) &r, (void*) &cc, (void*) &cc2);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Both field content counts match, i.e. everything is fine.

        // Assign destination field elements.
        copy_pointer(p0, (void*) &cd);
        copy_integer(p1, (void*) &cc);
        copy_integer(p2, (void*) &i);

        if (l == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p3, (void*) &h);
        }

        copy_integer(p4, (void*) &s);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The field size is not correct.");
    }
}

/* FIELD_XDT_DESERIALISER_SOURCE */
#endif
