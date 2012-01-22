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

#ifndef INLINE_SENDER_SOURCE
#define INLINE_SENDER_SOURCE

#include <stdio.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Sends a knowledge model to the receiving array.
 *
 * @param p0 the destination wide character data (pointer reference)
 * @param p1 the destination wide character count
 * @param p2 the destination wide character size
 * @param p3 the source message type data
 * @param p4 the source message type count
 * @param p5 the source message model data
 * @param p6 the source message model count
 * @param p7 the source message properties data
 * @param p8 the source message properties count
 * @param p9 the source metadata type data
 * @param p10 the source metadata type count
 * @param p11 the source metadata model data
 * @param p12 the source metadata model count
 * @param p13 the source metadata properties data
 * @param p14 the source metadata properties count
 * @param p15 the language
 * @param p16 the language count
 */
void send_inline(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply send inline message.");

    // The converted array.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ac = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int as = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate array.
    allocate_model((void*) &ad, (void*) &as, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode source knowledge model into array.
    serialise((void*) &ad, (void*) &ac, (void*) &as, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);

/*??
    fwprintf(stdout, L"TEST sending inline a: %ls\n", (wchar_t*) a);
    fwprintf(stdout, L"TEST sending inline ac: %i\n", *((int*) ac));
*/

    // Write encoded array into destination array.
    send_data(p0, p1, p2, ad, (void*) &ac, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT);

/*??
    fwprintf(stdout, L"TEST sending inline p0: %ls\n", *((wchar_t**) p0));
    fwprintf(stdout, L"TEST sending inline p1: %i\n", *((int*) p1));
*/

    // Deallocate array.
    deallocate_model((void*) &ad, (void*) &as, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* INLINE_SENDER_SOURCE */
#endif
