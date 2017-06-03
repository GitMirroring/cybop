/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SWAP_BUBBLE_SORTER_SOURCE
#define SWAP_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/*
 * Swaps the given integer values.
 *
 * @param p0 the first value
 * @param p1 the second value
 */
void swap_integer(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Swap integer.");

    // The temporary value.
    int t = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    copy_integer((void*) &t, p0);
    copy_integer(p0, p1);
    copy_integer(p1, (void*) &t);
}

/* SWAP_BUBBLE_SORTER_SOURCE */
#endif
