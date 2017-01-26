/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_GUI_SERIALISER_SOURCE
#define PART_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/representer/serialiser/gui/element_part_gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the part into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the source model data
 * @param p7 the source model count
 * @param p8 the source properties data
 * @param p9 the source properties count
 * @param p10 the knowledge memory part (pointer reference)
 * @param p11 the stack memory item
 * @param p12 the internal memory data
 */
void serialise_gui_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui part.");

fwprintf(stdout, L"TEST serialise gui part: %i\n", p7);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p7 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p7);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        serialise_gui_part_element(p0, p1, p2, p3, p4, p5, p6, (void*) &j, p8, p9, p10, p11, p12);

        // Increment loop variable.
        j++;
    }
}

/* PART_GUI_SERIALISER_SOURCE */
#endif
