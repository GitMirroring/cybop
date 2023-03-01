/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VULGAR_FRACTION_NUMERAL_SERIALISER_SOURCE
#define VULGAR_FRACTION_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/fraction_state_cyboi_name.c"
#include "../../../../constant/name/numeral/sign_numeral_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/fraction_getter.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/numeral/integer_numeral_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the vulgar fraction into a wide character sequence.
 *
 * @param p0 the destination wide character item
 * @param p1 the source number
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag (some conversions like html numeric references do not want a "0x" prefix and prepend "&#x" themselves instead)
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 */
void serialise_numeral_fraction_vulgar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral fraction vulgar.");
    fwprintf(stdout, L"Debug: Serialise numeral fraction vulgar. source number p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Serialise numeral fraction vulgar. source number *p1: %i\n", *((int*) p1));

    // The numerator.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The denominator.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get vulgar fraction numerator.
    get_fraction_element((void*) &n, p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    // Get vulgar fraction denominator.
    get_fraction_element((void*) &d, p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Serialise numerator.
    serialise_numeral_integer(p0, (void*) &n, p2, p3, p4, p5);
    // Append fraction slash to destination item.
    modify_item(p0, (void*) SLASH_FRACTION_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) SLASH_FRACTION_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Serialise denominator.
    serialise_numeral_integer(p0, (void*) &d, p2, p3, p4, p5);
}

/* VULGAR_FRACTION_NUMERAL_SERIALISER_SOURCE */
#endif
