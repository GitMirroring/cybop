/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_LOGIFIER_SOURCE
#define VALUE_LOGIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/logifier/boolean_logifier.c"
#include "../../executor/logifier/integer_logifier.c"
#include "../../executor/logifier/character_logifier.c"
#include "../../logger/logger.c"


// Forward declarations.
//

void calculate_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// Models of type "complex" or "fraction" are not
// considered as container, since the comparison of their
// elements follows special rules.
//
// Example:
//
// The two fractions 4 / 2 and 2 / 1 are identical even though
// their numerators and denominators differ. If the fractions
// were treated as containers and their elements compared one by one,
// then neither the numerators 4 and 2 nor the denominators 2 and 1
// would be equal.
//
// Therefore, such constructs are static and treated as
// primitive data types, but NOT as dynamic containers.
// The number of their elements is fixed.
// The fraction has two elements: numerator and denominator.
// It needs a special comparison function that knows how to
// treat fractions correctly.
//

/**
 * Calculates the result using the given operand and operation.
 *
 * @param p0 the result, which is the operand BEFORE the operation
 * @param p1 the operand
 * @param p2 the operation type
 * @param p3 the operand type
 */
void logify_value(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify value.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // boolean
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE);
    
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_boolean(p0, p1, p2);
        }
    }

    //
    // number - CHARACTER
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
      
        compare_integer_equal((void*) &r, p3, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);
    
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
      
            logify_character(p0, p1, p2);
        }
    }
    
    //
    // number - INTEGER
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
        
            logify_integer(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate value. The operand type is unknown.");
    }
}

/* VALUE_LOGIFIER_SOURCE */
#endif
