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

#ifndef NUMBER_NUMERAL_DESERIALISER_SOURCE
#define NUMBER_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/deserialiser/numeral/existence_numeral_deserialiser.c"
#include "../../../../executor/representer/deserialiser/numeral/part_numeral_deserialiser.c"
#include "../../../../executor/selector/numeral/assembler_numeral_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the number value.
 *
 * CAUTION! The destination number item is a REFERENCE,
 * so that it can be assigned a new value, in case
 * a new number part has to be allocated inside.
 *
 * @param p0 the destination number item (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the number part name data
 * @param p5 the number part name count
 * @param p6 the destination number item format
 */
void deserialise_numeral_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral number.");
        fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining p3: %i\n", p3);
        fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining *p3: %i\n", *((int*) p3));

        // The first algebraic sign factor with PLUS (positive number one) as default.
        int s1 = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        // The first pre point value (Vorkommastelle).
        int v1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The first post point value (Nachkommastelle, also called "decimals").
        int d1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The first number base power (Potenz).
        double po1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // The second algebraic sign factor with PLUS (positive number one) as default.
        int s2 = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        // The second pre point value (Vorkommastelle).
        int v2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The second post point value (Nachkommastelle, also called "decimals").
        int d2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The second number base power (Potenz).
        double po2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // The format with INTEGER as default.
        int f = *INTEGER_NUMERAL_STATE_CYBOI_FORMAT;
        // The type with INTEGER as default.
        int t = *INTEGER_NUMERAL_STATE_CYBOI_TYPE;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The temporary number.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The destination item count.
        void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Deserialise FIRST part of number.
        deserialise_numeral_part((void*) &s1, (void*) &v1, (void*) &d1, (void*) &po1, p2, p3, (void*) &f, (void*) &t);

        if ((t == FRACTION_NUMBER_STATE_CYBOI_TYPE) || (t == *COMPLEX_NUMBER_STATE_CYBOI_TYPE)) {

            //
            // A second number part has been found.
            //

            //
            // Deserialise SECOND part of number.
            //
            // CAUTION! Do NOT hand over format and type parametre again
            // but NULL instead since otherwise, they would get overwritten
            // even though they should remain on fraction or complex.
            //
            // For fraction and complex it is clearly defined
            // which format and type the two parts have inside:
            // - fraction: numerator and denominator part as INTEGER
            // - complex: real and imaginary part as FLOAT
            //
            deserialise_numeral_part((void*) &s2, (void*) &v2, (void*) &d2, (void*) &po2, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        }

        // Verify detected format.
        compare_integer_equal((void*) &r, (void*) &f, p6);

        //
        // CAUTION! When parsing json, for example, then a format is NOT given
        // but has to be detected instead.
        // In such cases, the destination number item format parametre is NULL.
        // Therefore, do not only compare the detected and given format here,
        // but also compare with null in order to cover these cases.
        //
        if ((p6 == *NULL_POINTER_STATE_CYBOI_MODEL) || (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

            //
            // A destination number item format was NOT given
            // OR it is IDENTICAL to the detected format.
            //

            //
            // Allocate temporary number.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            // CAUTION! This has to be an ARRAY and NOT an item since
            // it represents a primitive number value to be added to
            // the actual destination number item further below.
            //
            allocate_array((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);

            // Assemble number.
            select_numeral_assembler(n, s1, v1, d1, po1, s2, v2, d2, po2, (void*) &f);

            //
            // Make sure a destination number item exists.
            //
            // If it does not, then a part gets allocated inside
            // and its model item assigned as destination number item.
            //
            // Background:
            //
            // The cybol deserialiser DOES allocate an item already,
            // since the format and hence type are given there.
            //
            // The json deserialiser does NOT allocate an item,
            // since the number format is unknown and yet has to be detected.
            //
            deserialise_numeral_existence(p0, p1, p4, p5, (void*) &f, (void*) &t);

            // Get destination item count.
            copy_array_forward((void*) &ic, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            //
            // Add number to destination number part model item.
            //
            // CAUTION! The "adjust count" flag is set to NULL here,
            // since the destination count gets ALWAYS adjusted.
            //
            // CAUTION! While parsing a vector, the programme DIVES into the vector FIRST,
            // so that last values are added first. If values were now just appended,
            // the order of vector values would be swapped, which is NOT wanted.
            // On the other hand, inserting values at the beginning of the
            // destination item is WRONG if values are already present.
            // Therefore, the destination item's OLD element count is
            // remembered here, so that new values may be INSERTED
            // starting from that count used as INDEX, which has the
            // effect that elements are appended in the correct order.
            //
            modify_item(*i, n, (void*) &t, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, ic, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

            //
            // CAUTION Do NOT append the part to some destination here,
            // since this is done in other deserialisers' files such as:
            //
            // - CYBOL: "standard_cybol_deserialiser.c"
            // - JSON: "number_json_deserialiser.c", "string_json_deserialiser.c"
            //

            //
            // Deallocate temporary number.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array((void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral number. The detected format and given destination number item format are not identical.");
            fwprintf(stdout, L"Error: Could not deserialise numeral number. The detected format: %i and given destination number item format: p6 are not identical.\n", f, p6);
            fwprintf(stdout, L"Error: Could not deserialise numeral number. The detected format: %i and given destination number item format: *p6 are not identical.\n", f, *((int*) p6));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral number. The destination number item is null.");
        fwprintf(stdout, L"Error: Could not deserialise numeral number. The destination number item is null. p0: %i\n", p0);
    }
}

/* NUMBER_NUMERAL_DESERIALISER_SOURCE */
#endif
