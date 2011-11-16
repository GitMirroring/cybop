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

#ifndef CHANNEL_DECODER_SOURCE
#define CHANNEL_DECODER_SOURCE

#include "../../../../constant/type/cybol/compare_cybol_type.c"
#include "../../../../constant/type/cybol/datetime_cybol_type.c"
#include "../../../../constant/type/cybol/logicvalue_cybol_type.c"
//?? Delete this later. Superfluous since replaced with compare/equal etc.
#include "../../../../constant/type/cybol/operation_cybol_type.c"
#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/operation/operation_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the wide character channel into an integer channel.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_channel(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode channel.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FILE_SYSTEM_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GNU_LINUX_CONSOLE_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INLINE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) INLINE_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INLINE_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHELL_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SHELL_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SHELL_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SOCKET_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SOCKET_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SOCKET_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WWW_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) WWW_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WWW_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) X_WINDOW_SYSTEM_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode channel. The source channel is unknown.");
    }
}

/* CHANNEL_DECODER_SOURCE */
#endif
