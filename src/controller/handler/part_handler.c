/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: compound_handler.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:31:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_HANDLER_SOURCE
#define PART_HANDLER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Handles the part signal.
 *
 * @param p0 the signal model array (operation)
 * @param p1 the signal model array (operation) count
 * @param p2 the signal details array (parametres)
 * @param p3 the signal details array (parametres) count
 * @param p4 the direct execution flag
 * @param p5 the shutdown flag
 * @param p6 the knowledge memory part
 * @param p7 the internal memory array
 * @param p8 the signal memory item
 * @param p9 the signal memory interrupt request flag
 * @param p10 the signal memory mutex
 */
void handle_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_PART_MESSAGE_LOG_MODEL, (void*) HANDLE_PART_MESSAGE_LOG_MODEL_COUNT);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

fwprintf(stdout, L"TEST handle part *mc: %i\n", *mc);

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p1);

        if (b != FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

fwprintf(stdout, L"TEST handle part j: %i\n", j);

        handle_part_element(p0, (void*) &j, p2, p3, p4, p5, p6, p7, p8, p9, p10);

        // Increment loop variable.
        j++;
    }
}

/* PART_HANDLER_SOURCE */
#endif
