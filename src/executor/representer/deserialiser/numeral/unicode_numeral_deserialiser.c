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

#ifndef UNICODE_NUMERAL_DESERIALISER_SOURCE
#define UNICODE_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../logger/logger.c"
#include "../../../../mapper/digit_wide_character_to_integer_mapper.c"

/**
 * Deserialises the unicode wide character into an integer value.
 *
 * @param p0 the destination integer value
 * @param p1 the source wide character data
 * @param p2 the source type
 * @param p3 the source wide character index
 */
void deserialise_numeral_unicode(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral unicode.");
    fwprintf(stdout, L"Debug: Deserialise numeral unicode. source index p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise numeral unicode. source index *p3: %i\n", *((int*) p3));

    // The digit wide character.
    wchar_t c = *NULL_UNICODE_CHARACTER_CODE_MODEL;

    // Get digit wide character at given index.
    copy_array_forward((void*) &c, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    //
    // Determine integer value from digit wide character.
    //
    // CAUTION! One could subtract the zero wide character UNICODE value
    // from the current digit wide character UNICODE value, in order to
    // get the actual numeric integer value.
    // However, using unicode values for calculation is NOT considered
    // proper here. Therefore, a MAPPING table is used instead.
    //
    map_digit_wide_character_to_integer(p0, (void*) &c);
}

/* UNICODE_NUMERAL_DESERIALISER_SOURCE */
#endif
