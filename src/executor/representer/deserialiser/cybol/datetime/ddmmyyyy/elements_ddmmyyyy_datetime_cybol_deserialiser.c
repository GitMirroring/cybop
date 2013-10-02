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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENTS_DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE
#define ELEMENTS_DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/calculator/basic/pointer/add_pointer_calculator.c"
#include "../../../../../../executor/representer/deserialiser/cybol/integer/primitive_value_integer_cybol_deserialiser.c"
#include "../../../../../../executor/searcher/mover/position_mover.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the ddmmyyyy elements wide character data into a datetime model.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 */
void deserialise_cybol_datetime_ddmmyyyy_elements(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol datetime ddmmyyyy elements.");

    // The day destination and source.
    int dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    void* ds = p1;
    // The month destination and source.
    int md = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    void* ms = p1;
    // The year destination and source.
    int yd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    void* ys = p1;

    // Adjust day/month/year source.
    move_position((void*) &ds, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    move_position((void*) &ms, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    move_position((void*) &ys, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Deserialise day/month/year source.
    deserialise_cybol_integer_value_primitive((void*) &dd, ds, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
    deserialise_cybol_integer_value_primitive((void*) &md, ms, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
    deserialise_cybol_integer_value_primitive((void*) &yd, ys, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

fwprintf(stdout, L"TEST deserialise cybol datetime ddmmyyyy elements dd: %i\n", dd);
fwprintf(stdout, L"TEST deserialise cybol datetime ddmmyyyy elements md: %i\n", md);
fwprintf(stdout, L"TEST deserialise cybol datetime ddmmyyyy elements yd: %i\n", yd);

    // The result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //?? TODO: Do calculations here!
    // See e.g.:
    // Method "computeTime" in:
    // http://docjar.com/html/api/java/util/GregorianCalendar.java.html
    // also:
    // http://docjar.com/html/api/java/util/Date.java.html
    // and also comment "Data flow in Calendar" in:
    // http://www.docjar.com/html/api/java/util/Calendar.java.html

    // Copy result to destination.
    overwrite_item_element(p0, (void*) &r, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST deserialise cybol datetime ddmmyyyy elements p0 data: %i\n", *((int*) *((void**) p0)));
fwprintf(stdout, L"TEST deserialise cybol datetime ddmmyyyy elements p0 count: %i\n", *((int*) *((void**) (p0 + sizeof(void*)))));
}

/* ELEMENTS_DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE */
#endif
