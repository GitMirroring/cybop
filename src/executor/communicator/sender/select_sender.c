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

#ifndef SELECT_SENDER_SOURCE
#define SELECT_SENDER_SOURCE

#include "../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Selects a suitable source buffer into destination.
 *
 * This is important since buffers differ for the various channels.
 *
 * CAUTION! Using the "encoding" parametre as criterion is NOT helpful, since:
 * - for "inline" channel: it is NULL, but "wchar_t" is needed for sending;
 * - for "text/html" language: it is NOT NULL, and "char" is needed for sending.
 * Therefore, the correct buffer gets selected via LANGUAGE here.
 *
 * @param p0 the destination buffer (pointer reference)
 * @param p1 the source char buffer (pointer reference)
 * @param p2 the language
 */
void send_select(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send select.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) BINARY_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Use "char" buffer for arbitrary binary data.
            copy_pointer(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Use "char" buffer.
            // A pure "char" byte buffer is needed due to
            // possible attachments in form of byte code.
            copy_pointer(p0, p1);
        }
    }
}

/* SELECT_SENDER_SOURCE */
#endif
