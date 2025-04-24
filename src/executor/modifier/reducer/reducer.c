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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Processes the elements of the source collection using the given function
 * and stores the result in destination node.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the repetition number
 * @param p6 the type
 */
void reduce(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reduce.");
    fwprintf(stdout, L"Information: Reduce. source count p2: %i\n", p2);
    fwprintf(stdout, L"Information: Reduce. source count *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Information: Reduce. source data p1: %ls\n", (wchar_t*) p1);

    //
    // CAUTION! The destination is NOT an item, but an array,
    // since this function is called from file "array_modifier.c".
    //

/*??
    //
    // Declaration
    //

    // The destination element part.
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source element part.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source element part format, type item.
    void* sef = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* set = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source element part format, type item data.
    void* sefd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* setd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Functionality
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    //?? int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //
    // The direct execution flag.
    //
    // CAUTION! The flag has to be set to true, because otherwise,
    // each loop cycle places a new signal in signal memory so that
    // these would only be processed with a delay.
    // But this is not desirable, since follow-up signals of this
    // loop may rely on its full execution, including all cycles.
    //
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    if (src_count == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, index, src_count);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The break flag is TRUE.
            //

            // Leave the loop.
            break;

        } else {

            //
            // The break flag is FALSE (not set).
            //

            fwprintf(stdout, L"Debug: Apply reduce. 0 src_count: %i\n", src_count);
            fwprintf(stdout, L"Debug: Apply reduce. 0 *src_count: %i\n", *((int*) src_count));
            fwprintf(stdout, L"Debug: Apply reduce. 0 index: %i\n", index);
            fwprintf(stdout, L"Debug: Apply reduce. 0 *index: %i\n", *((int*) index));

            // Get source element part with given index.
            copy_array_forward((void*) &se, src_data, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, index);

            fwprintf(stdout, L"Debug: Apply reduce. 1 se: %i\n", se);

            // Get source element part format, type item.
            copy_array_forward((void*) &sef, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &set, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);

            copy_array_forward((void*) &sefd, sef, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &setd, set, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            fwprintf(stdout, L"Debug: Apply reduce. 2a sefd: %i\n", sefd);
            fwprintf(stdout, L"Debug: Apply reduce. 2a *sefd: %i\n", *((int*) sefd));

            fwprintf(stdout, L"Debug: Apply reduce. 2b setd: %i\n", setd);
            fwprintf(stdout, L"Debug: Apply reduce. 2b *setd: %i\n", *((int*) setd));

            //
            // Allocate destination element part with the same type as the source.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            fwprintf(stdout, L"Debug: Apply reduce. 3 de pre: %i\n", de);
            //?? allocate_part((void*) &de, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, setd);
            fwprintf(stdout, L"Debug: Apply reduce. 3 de post: %i\n", de);

            //
            // Fill destination element part with the same format and type as the source.
            //
            // A name is NOT assigned here since it is not
            // considered as useful or necessary.
            //
            //?? modify_part(de, sefd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
            //?? modify_part(de, setd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

            fwprintf(stdout, L"Debug: Apply reduce. 4 de: %i\n", de);

            //
            // Assign destination element part to element part which was given as property.
            //
            // CAUTION! This assignment is IMPORTANT, so that the element may get
            // accessed and processed within the function in cybol source code.
            //
            //?? modify_part(e, (void*) &de, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) MODEL_PART_STATE_CYBOI_NAME);

            fwprintf(stdout, L"Debug: Apply reduce. 5: %i\n", b);

            // Handle the function as new operation.
            handle(f, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

            fwprintf(stdout, L"Debug: Apply reduce. 6 *index: %i\n", *((int*) index));

            //
            // Append destination element part to output.
            //
            // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
            // This is necessary in order to activate rubbish (garbage) collection.
            //
            //?? modify_part(o, (void*) &de, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) MODEL_PART_STATE_CYBOI_NAME);

            fwprintf(stdout, L"Debug: Apply reduce. 7 *index: %i\n", *((int*) index));

            // Increment loop variable.
            calculate_integer_add(index, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
            //?? TODO: Verwende increment statt calculate_integer_add ??

            fwprintf(stdout, L"Debug: Apply reduce. 8 *index: %i\n", *((int*) index));
        }
    }
*/
}
