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

#ifndef CHARACTER_LOGIFIER_SOURCE
#define CHARACTER_LOGIFIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/logifier/character/and_character_logifier.c"
#include "../../executor/logifier/character/not_character_logifier.c"
#include "../../executor/logifier/character/or_character_logifier.c"
#include "../../executor/logifier/character/nor_character_logifier.c"
#include "../../executor/logifier/character/xnor_character_logifier.c"
#include "../../executor/logifier/character/nand_character_logifier.c"
#include "../../executor/logifier/character/xor_character_logifier.c"
#include "../../executor/logifier/character/neg_character_logifier.c"
#include "../../logger/logger.c"

/**
 * Connects the given values following the given character bitwise logic operation.
 *
 * @param p0 the output (number 1 if true; unchanged otherwise)
 * @param p1 the input
 * @param p2 the operation type
 */
void logify_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify character.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //AND

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) AND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_and(p0, p1);
        }
    }

    //NAND

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
        compare_integer_equal((void*) &r, p2, (void*) NAND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_nand(p0, p1);
        }
    }

    //NEG

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NEG_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Only ONE parametre is required.
            logify_character_neg(p0);
        }
    }

    //NOR

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_nor(p0, p1);
        }
    }

    //NOT
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
        compare_integer_equal((void*) &r, p2, (void*) NOT_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Only ONE parametre is required.
            logify_character_not(p0);
        }
    }

    //OR

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) OR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_or(p0, p1);
        }
    }

    //XNOR

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) XNOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_xnor(p0, p1);
        }
    }

    //XOR

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) XOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            logify_character_xor(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify character. The operation type is unknown.");
    }
}

/* CHARACTER_LOGIFIER_SOURCE */
#endif
