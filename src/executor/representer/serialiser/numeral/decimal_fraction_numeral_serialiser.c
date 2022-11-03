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

#ifndef DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE
#define DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/numeral/power_numeral_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/double/scientific_double_calculator.c"
#include "../../../../executor/calculator/double/subtract_double_calculator.c"
#include "../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../executor/caster/integer/double_integer_caster.c"
#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/copier/double_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/numeral/decimals_numeral_serialiser.c"
#include "../../../../executor/representer/serialiser/numeral/integer_numeral_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the decimal fraction into a wide character sequence.
 *
 * @param p0 the destination wide character item
 * @param p1 the source number
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p5 the decimal separator data
 * @param p6 the decimal separator count
 * @param p7 the decimal places
 * @param p8 the scientific notation flag
 */
void serialise_numeral_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral fraction decimal.");
    fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. source number p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. source number *p1: %f\n", *((double*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The temporary floating point number.
    double n = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The power exponent.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The pre-point value.
    int pre = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The pre-point value as double.
    double pred = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The post-point value.
    double post = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Initialise temporary floating point number.
    copy_double((void*) &n, p1);

    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Convert floating point number into scientific notation.
        calculate_double_scientific((void*) &n, (void*) &p, p3);
    }

    //
    // Determine pre-point value.
    //
    // CAUTION! Convert floating-point number to integer by CASTING it to int.
    // This is a legitimate method of truncating a floating-point value,
    // as mentioned in the glibc documentation:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
    //
    cast_integer_double((void*) &pre, (void*) &n);

    //
    // Determine post-point value (decimal places).
    //

    // Initialise post-point value with original number.
    copy_double((void*) &post, (void*) &n);
    // Cast pre-point value to double.
    cast_double_integer((void*) &pred, (void*) &pre);
    //
    // Subtract pre-point value so that only the relevant decimal places (decimals)
    // remain and a ZERO is standing before the decimal separator.
    //
    calculate_double_subtract((void*) &post, (void*) &pred);

    // Serialise pre-point value.
    serialise_numeral_integer(p0, (void*) &pre, p2, p3, p4);

    // Append decimal separator wide character to destination item.
    modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Serialise post-point value.
    serialise_numeral_decimals(p0, (void*) &post, p3, p7);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append power exponent letter "e" wide character to destination item.
        modify_item(p0, (void*) SMALL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) SMALL_POWER_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Serialise power exponent value.
        serialise_numeral_integer(p0, (void*) &p, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4);
    }
}

/* DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE */
#endif
