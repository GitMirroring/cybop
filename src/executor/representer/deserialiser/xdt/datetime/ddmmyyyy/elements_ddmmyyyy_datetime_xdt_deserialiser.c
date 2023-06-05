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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Deserialises the source ddmmyyyy elements wide character data into the destination datetime item.
 *
 * @param p0 the destination item
 * @param p1 the source data
 */
void deserialise_xdt_datetime_ddmmyyyy_elements(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt datetime ddmmyyyy elements.");

    // The temporary datetime.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The year/month/day/hour/minute/second.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int min = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The year/month/day source.
    void* ys = p1;
    void* ms = p1;
    void* ds = p1;

    // Allocate temporary datetime.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);

    // Adjust year/month/day source.
    // CAUTION! Process numbers in this order: d/m/y.
    // It should also work the other way around, but to
    // be sure, the source is read from left to right.
    move((void*) &ds, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    move((void*) &ms, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    move((void*) &ys, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Deserialise year/month/day source.
    // CAUTION! Process numbers in this order: d/m/y.
    // It should also work the other way around, but to
    // be sure, the source is read from left to right.
    deserialise_numeral_integer((void*) &d, ds, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL);
    deserialise_numeral_integer((void*) &m, ms, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL);
    deserialise_numeral_integer((void*) &y, ys, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL);

    // Deserialise year/month/day/hour/minute/second.
    deserialise_time_scale_gregorian_calendar(t, (void*) &y, (void*) &m, (void*) &d, (void*) &h, (void*) &min, (void*) &s);

    // Append temporary datetime to destination.
    modify_item(p0, t, (void*) DATETIME_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Deallocate temporary datetime.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
}
