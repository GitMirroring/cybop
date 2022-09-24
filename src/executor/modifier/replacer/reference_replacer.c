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

#ifndef REFERENCE_REPLACER_SOURCE
#define REFERENCE_REPLACER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../executor/modifier/replacer/item_replacer.c"
#include "../../../logger/logger.c"

/**
 * Makes the source data position a pointer reference.
 *
 * @param p0 the destination wide character array (pointer reference)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source wide character data
 * @param p4 the source wide character count
 * @param p5 the target sequence data
 * @param p6 the target sequence count
 * @param p7 the replacement sequence data
 * @param p8 the replacement sequence count
 */
void replace_reference(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Replace reference.");
    fwprintf(stdout, L"Debug: Replace reference. source count p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Replace reference. source count *p4: %i\n", *((int*) p4));
    fwprintf(stdout, L"Debug: Replace reference. source data p3: %ls\n", (wchar_t*) p3);

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p3);
    // Copy source count remaining.
    copy_integer((void*) &c, p4);

    //
    // Retrieve language properties (constraints) necessary for deserialisation.
    //
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    replace_item(p0, p1, p2, (void*) &d, (void*) &c, p5, p6, p7, p8);
}

/* REFERENCE_REPLACER_SOURCE */
#endif
