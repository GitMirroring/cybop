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
 * @param p2 the destination field data (pointer reference)
 * @param p3 the destination field count (pointer reference)
 * @param p4 the destination verification flag
 * @param p5 the source data position (pointer reference)
 * @param p6 the source count remaining
 */
void deserialise_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** sd = (void**) p5;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field.");

        // The count flag.
        int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // CAUTION! This comparison ensures that array boundaries are not crossed.
        compare_integer_greater_or_equal((void*) &c, p6, (void*) XDT_FIELD_SIZE_COUNT);

        if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Decode xdt field size.
            deserialise_cybol_integer_value(dest_item, *sd, (void*) XDT_FIELD_SIZE_COUNT, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Move position.
            // The xdt field length is defined to be 3 Byte.
            move_position(p5, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) XDT_FIELD_SIZE_COUNT);
        }

        // The count flag.
        int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // CAUTION! This comparison ensures that array boundaries are not crossed.
        compare_integer_greater_or_equal((void*) &c, p6, (void*) XDT_FIELD_IDENTIFICATION_COUNT);

        if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Decode xdt field identification.
            deserialise_cybol_integer_value(dest_item, *sd, (void*) XDT_FIELD_IDENTIFICATION_COUNT, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Move position.
            // The xdt field identification is defined to be 4 Byte.
            move_position(p5, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) XDT_FIELD_IDENTIFICATION_COUNT);
        }

        //
        // Calculate xdt field content count.
        //
        // CAUTION! The xdt field size comprises all characters:
        // - field size: 3 Byte
        // - field identification: 4 Byte
        // - field content: flexible
        // - carriage return: 1 Byte
        // - line feed: 1 Byte
        //

        // Determine xdt field content count.

        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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

        if (??field_size_item_data == *NULL_POINTER_STATE_CYBOI_MODEL) {

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
            compare_integer_greater((void*) &b, ??field_size_item_data, p6);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            select_xdt_field_end(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

            // Increment source xdt byte array index, so that following
            // fields may be found in the next loop cycle.
            s = s + nc;
            rem = rem - nc;
        }

        // Search for cr and lf indicating the field end.

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field. The source data is null.");
    }
}

/* FIELD_XDT_DESERIALISER_SOURCE */
#endif
