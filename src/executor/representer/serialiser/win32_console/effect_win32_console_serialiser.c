/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EFFECT_WIN32_CONSOLE_SERIALISER_SOURCE
#define EFFECT_WIN32_CONSOLE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/attribute_ansi_escape_code_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the effect into a win32 console attribute.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the flag
 */
void serialise_win32_console_effect(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console effect.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? TMP: Replace later with bit manipulation function "manipulate_bit_or" of file "or_bit_manipulator.c"
        WORD* s = (WORD*) p1;

        //?? TMP: Replace later with bit manipulation function "manipulate_bit_or" of file "or_bit_manipulator.c"
        WORD* d = (WORD*) p0;

        //?? TMP: Replace later with bit manipulation function "manipulate_bit_or" of file "or_bit_manipulator.c"
        *d = *d | *s;
    }
}

/* EFFECT_WIN32_CONSOLE_SERIALISER_SOURCE */
#endif
