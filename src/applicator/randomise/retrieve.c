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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdlib.h> // RAND_MAX

//
// Library interface
//

#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Retrieves the next pseudo-random number in the series.
 *
 * CAUTION! If calling "randomise/retrieve" before
 * a seed has been established with "randomise/sow",
 * the value 1 is used as DEFAULT SEED inside glibc.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_retrieve(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply retrieve.");

    //
    // Declaration
    //

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part.
    void* min = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part.
    void* max = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item.
    void* minm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item.
    void* maxm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item data.
    void* minmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item data.
    void* maxmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME, (void*) RESULT_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get minimum part.
    get_part_name((void*) &min, p0, (void*) MINIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME, (void*) MINIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get maximum part.
    get_part_name((void*) &max, p0, (void*) MAXIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME, (void*) MAXIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get minimum part model item.
    copy_array_forward((void*) &minm, min, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get maximum part model item.
    copy_array_forward((void*) &maxm, max, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get minimum part model item data.
    copy_array_forward((void*) &minmd, minm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get maximum part model item data.
    copy_array_forward((void*) &maxmd, maxm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // The default minimum value is understood inclusive.
    int minimum = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //
    // The default maximum value is understood exclusive.
    //
    // In the GNU C Library, RAND_MAX is 2147483647, which is
    // the largest signed integer representable in 32 bits.
    //
    int maximum = RAND_MAX;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    // Use the explicit minimum that was given as argument.
    copy_integer((void*) &minimum, minmd);
    // Use the explicit maximum that was given as argument.
    copy_integer((void*) &maximum, maxmd);

    //
    // Functionality
    //

    // Retrieve current result from system.
    retrieve(rmd, (void*) &minimum, (void*) &maximum);
}
