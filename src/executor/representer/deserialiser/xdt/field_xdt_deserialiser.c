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

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../executor/calculator/basic/integer/subtract_integer_calculator.c"
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
 * @param p4 the source data position (pointer reference)
 * @param p5 the source count remaining
 */
void deserialise_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* dc = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field.");

        // The field size.
        // It seems to be useless, since a field's end
        // is defined as line feed + carriage return
        // and may thus be detected and thereby
        // count the length of the field.
        // However, it may be used for verification,
        // i.e. if calculated and given field size match.
        int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The field content count.
        int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Deserialise size.
        deserialise_xdt_field_element((void*) &s, p4, p5, (void*) SIZE_FIELD_XDT_NAME_COUNT);
        // Deserialise dependency hierarchy.
        //?? Not defined in the standard yet. Possibly to be implemented later.
        //?? deserialise_xdt_field_element(p3, p4, p5, (void*) HIERARCHY_FIELD_XDT_NAME_COUNT);
        // Deserialise identification.
        deserialise_xdt_field_element(p2, p4, p5, (void*) IDENTIFICATION_FIELD_XDT_NAME_COUNT);

        // Calculate field content count.
        // CAUTION! The xdt field size comprises ALL elements, even itself.
        // content count = size value - 10 Byte (3 + 1 + 4 + 2)
        calculate_integer_add((void*) &cc, (void*) &s);
        //?? Subtract 10 instead of 9 as soon as the dependency hierarchy field element is used!
        //?? calculate_integer_subtract((void*) &cc, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_subtract((void*) &cc, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL);

        // Initialise field content data.
        copy_pointer(p0, p4);

        if (p5 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

            compare_integer_smaller_or_equal((void*) &b, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            select_xdt_field_end((void*) &b, p4, p5);

            if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Increment destination field content count.
                (*dc)++;
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The destination field content count is null.");
    }
}

/* FIELD_XDT_DESERIALISER_SOURCE */
#endif
