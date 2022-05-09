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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_JSON_DESERIALISER_SOURCE
#define ELEMENT_JSON_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/json/value_json_deserialiser.c"
#include "../../../../executor/selector/json/end_string_json_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the json array element.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the member name data
 * @param p5 the member name count
 */
void deserialise_json_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise json element.");
    fwprintf(stdout, L"Debug: Deserialise json element. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise json element. count remaining *p3: %i\n", *((int*) p3));

    //
    // CAUTION! Do NOT call function "select_json_value_begin" directly,
    // but function "deserialise_json_value" instead, since that contains
    // a loop which is necessary for detecting and skipping unnecessary characters.
    //
    deserialise_json_value(p0, p1, p2, p3, p4, p5);
}

/* ELEMENT_JSON_DESERIALISER_SOURCE */
#endif
