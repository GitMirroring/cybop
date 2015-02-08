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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SELECT_SENDER_SOURCE
#define SELECT_SENDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Selects a suitable source buffer into destination.
 *
 * @param p0 the destination buffer (pointer reference)
 * @param p1 the source char buffer (pointer reference)
 * @param p2 the source wchar_t buffer (pointer reference)
 * @param p3 the encoding
 */
void send_select(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send select.");

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // An encoding WAS given.
        // That is, wide characters are to be converted into a byte form.

        // Use "wchar_t" buffer.
        copy_pointer(p0, p2);

    } else {

        // An encoding was NOT given.
        // That is, simple bytes are used.

        // Use "char" buffer.
        copy_pointer(p0, p1);
    }
}

/* SELECT_SENDER_SOURCE */
#endif
