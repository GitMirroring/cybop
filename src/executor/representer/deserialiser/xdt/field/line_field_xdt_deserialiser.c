/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LINE_FIELD_XDT_DESERIALISER_SOURCE
#define LINE_FIELD_XDT_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/model/numeral/base_numeral_model.c"
#include "../../../../../constant/name/xdt/bdt_xdt_name.c"
#include "../../../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../executor/representer/deserialiser/numeral/integer_numeral_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/whitespace/whitespace_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/xdt/field/content_field_xdt_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/xdt/field/identification_field_xdt_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/xdt/field/part_field_xdt_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/xdt/field/size_field_xdt_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises xdt field line.
 *
 * An xdt field consists of the following elements:
 * - size: 3 Byte
 * - identification: 4 Byte
 * - content: variable length
 * - end (carriage return + line feed): 2 Byte
 *
 * content count = size value - 9 Byte (3 + 4 + 2)
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the language properties (constraints) data
 * @param p4 the language properties (constraints) count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 */
void deserialise_xdt_field_line(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field line.");

    //
    // The field size.
    //
    // CAUTION! It seems to be useless, since a field's end is defined
    // as line feed + carriage return and may thus be detected and
    // the length of the field thereby be counted.
    //
    // However, it is used below for VERIFYING if calculated and
    // given field size match.
    //
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ic = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification as integer primitive.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The calculated field content count.
    int cc2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Skip any whitespace characters.
    deserialise_whitespace(p1, p2);
    // Deserialise size.
    deserialise_xdt_field_size((void*) &s, p1, p2, (void*) SIZE_FIELD_BDT_XDT_NAME_COUNT);
    // Deserialise identification.
    deserialise_xdt_field_identification((void*) &id, (void*) &ic, p1, p2, (void*) IDENTIFICATION_FIELD_BDT_XDT_NAME_COUNT);
    // Deserialise identification as integer primitive.
    deserialise_numeral_integer((void*) &i, id, (void*) &ic, (void*) DECIMAL_BASE_NUMERAL_MODEL);
    // Deserialise content.
    deserialise_xdt_field_content((void*) &cd, (void*) &cc, p1, p2);

    //
    // Calculate field content count.
    //
    // CAUTION! The xdt field size comprises ALL elements, even itself.
    //
    copy_integer((void*) &cc2, (void*) &s);
    //
    // Subtract meta bytes.
    //
    // content count = size value - 9 Byte (3 size + 4 identification + 2 cr and lf)
    //
    calculate_integer_subtract((void*) &cc2, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL);

/*??
    fwprintf(stdout, L"Debug: deserialise xdt field s: %i\n", s);
    fwprintf(stdout, L"Debug: deserialise xdt field ic: %i\n", ic);
    //?? fwprintf(stdout, L"Debug: deserialise xdt field id: %ls\n", (wchar_t*) id);
    fwprintf(stdout, L"Debug: deserialise xdt field i: %i\n", i);
    fwprintf(stdout, L"Debug: deserialise xdt field cc: %i\n", cc);
    //?? fwprintf(stdout, L"Debug: deserialise xdt field cd: %ls\n", (wchar_t*) cd);
    fwprintf(stdout, L"Debug: deserialise xdt field cc2: %i\n", cc2);
*/

    //
    // Verify correctness by comparing the following two field content counts:
    // - calculated above from size given at beginning of xdt field
    // - incremented until the xdt field end (cr, lf) was detected
    //
    compare_integer_equal((void*) &r, (void*) &cc, (void*) &cc2);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Both field content counts match, i.e. everything is fine.
        //

        deserialise_xdt_field_part(p0, id, (void*) &ic, cd, (void*) &cc, p3, p4, p5, p6, p7, (void*) &i);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field line. The field size is not correct.");
    }
}

/* LINE_FIELD_XDT_DESERIALISER_SOURCE */
#endif
