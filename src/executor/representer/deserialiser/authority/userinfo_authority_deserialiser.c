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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the authority userinfo.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_authority_userinfo(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise authority userinfo.");

    // The userinfo data, count.
    void* ud = *NULL_POINTER_STATE_CYBOI_MODEL;
    int uc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    // Initialise userinfo data.
    copy_pointer((void*) &ud, p2);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The userinfo separator @ was NOT found.
            // That is, a userinfo and password were not given.
            // The source represents a hostname only,
            // possibly followed by a port number.
            //
            // CAUTION! The parametres p6 and p7 may NOT be used,
            // since their values were counted on and changed
            // inside the "select_authority_userinfo" function.
            // Instead, hand over e and ec. REFERENCES are expected!
            //
            deserialise_authority_hostname(p0, p1, (void*) &ud, (void*) &uc);

            break;
        }

        select_authority_userinfo(p0, p1, p2, p3, (void*) &uc, (void*) &b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The userinfo separator @ WAS found.
            // That is, a userinfo was given,
            // possibly followed by a password.
            //
            // In this case, the hostname was already decoded
            // inside the "select_authority_userinfo" function.
            //
            deserialise_authority_username(p0, p1, (void*) &ud, (void*) &uc);

            break;
        }
    }
}
