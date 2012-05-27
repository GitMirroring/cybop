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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARGUMENT_OPTIONALISER_SOURCE
#define ARGUMENT_OPTIONALISER_SOURCE

#include <string.h>

#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/comparator/basic/integer/smaller_integer_comparator.c"
#include "../../executor/converter/decoder/utf/utf_8_decoder.c"

/**
 * Optionalises the command line argument.
 *
 * It is assumed that the argument is an option followed by a value.
 * Both are determined here and evaluated later in function "optionalise_option".
 *
 * Example:
 * --loglevel debug
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the arguments (pointer reference)
 * @param p5 the arguments count
 * @param p6 the index
 */
void optionalise_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Information: Optionalise command line argument.\n");

    // The value index, which is equal to the loop variable increased by one.
    // CAUTION! Do NOT misuse the index parametre *j handed over to this function!
    // The parametre j is the loop index and MUST NOT be altered here!
    // Therefore, a new local variable i is introduced.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The command line argument option as multibyte character array.
    void* od = *NULL_POINTER_STATE_CYBOI_MODEL;
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The command line argument value as multibyte character array.
    void* vd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The option, value as wide character item.
    void* ow = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vw = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The option, value as wide character item data, count.
    void* owd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* owc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vwd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vwc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate option, value wide character item.
    allocate_item((void*) &ow, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &vw, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get command line argument option.
    // Example: "--loglevel"
    copy_array_forward((void*) &od, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    if (od != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Get command line argument option count (number of characters).
        //
        // CAUTION! There are two possibilities to determine it:
        //
        // 1 Force the user to give it as extra command line parametre
        //   (this would be proper, but not very user-friendly)
        //
        // 2 Rely on the null termination character to determine it
        //   (this is a rather dirty workaround, but the "strlen" function can be used)
        //
        // Possibility 2 is applied here.
        //
        oc = strlen((char*) od);

        // Decode multibyte character option into wide character.
        decode_utf_8(ow, od, (void*) &oc);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument option is null.\n");
    }

    // Calculate value index, which is equal to the loop index increased by one.
    copy_integer((void*) &i, p6);
    calculate_integer_add((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // CAUTION! It was already tested through the loop break flag that
    // the index handed over as parametre to here lies within the array.
    // However, the value belonging to an option has an index which is
    // INCREASED BY ONE, so that it might lie OUTSIDE the argument array.
    // Therefore, that incremented index is tested here again,
    // in order to avoid an access violation error!
    compare_integer_smaller((void*) &r, (void*) &i, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Get command line argument value, standing after the option.
        // Example: "debug"
        copy_array_forward((void*) &vd, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (vd != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get command line argument value count (number of characters).
            //
            // There are two possibilities to determine it:
            // 1 Force the user to give it as extra command line parametre
            //   (this would be proper, but not very user-friendly)
            // 2 Rely on the null termination character to determine it
            //   (this is a rather dirty workaround, but the strlen function can be used)
            //
            // Possibility 2 is applied here.
            vc = strlen((char*) vd);

            // Decode multibyte character value into wide character.
            decode_utf_8(vw, vd, (void*) &vc);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            log_write((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument value is null.\n");
        }
    }

    // Get option, value wide character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &owd, ow, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &owc, ow, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &vwd, vw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &vwc, vw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Optionalise the option and its value.
    // CAUTION! The value gets handed over as reference, as it gets
    // copied for the cybol knowledge file name.
    optionalise_option(p0, p1, p2, p3, vwd, vwc, owd, owc);

    // Deallocate option, value wide character item.
    deallocate_item((void*) &ow, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &vw, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* ARGUMENT_OPTIONALISER_SOURCE */
#endif
