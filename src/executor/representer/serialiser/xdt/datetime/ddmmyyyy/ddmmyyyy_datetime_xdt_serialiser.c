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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE
#define DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE

#include "../../../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../../../executor/modifier/appender/item_appender.c"
#include "../../../../../../executor/modifier/copier/array_copier.c"
#include "../../../../../../executor/representer/serialiser/cybol/integer/value_integer_cybol_serialiser.c"
#include "../../../../../../executor/representer/serialiser/time_scale/gregorian_calendar/gregorian_calendar_time_scale_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the source datetime into the destination ddmmyyyy wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source datetime
 */
void serialise_xdt_datetime_ddmmyyyy(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xdt datetime ddmmyyyy.");

    // The year/month/day/hour/minute/second.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int min = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The year/month/day wide character item.
    void* yi = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mi = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The year/month/day wide character item data/count.
    void* yd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* yc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The year/month/day comparison result.
    int yr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int mr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int dr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate year/month/day wide character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &yi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &mi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &di, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise datetime.
    serialise_time_scale_gregorian_calendar((void*) &y, (void*) &m, (void*) &d, (void*) &h, (void*) &min, (void*) &s, p1);

    // Serialise year/month/day.
    serialise_cybol_integer_value(yi, (void*) &y, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(mi, (void*) &m, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(di, (void*) &d, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);

    // Get serialised item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &yd, yi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &yc, yi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, mi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, mi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dd, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Compose destination wide character data.
    //
    // CAUTION! If a year/month/day has too few digits,
    // then it gets filled up with prepended zeros.
    //
    // CAUTION! Mind the order: ddmmyyyy
    //

    // The day.
    compare_integer_equal((void*) &dr, dc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (dr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    append_item_element(p0, dd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, dc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // The month.
    compare_integer_equal((void*) &mr, mc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (mr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    append_item_element(p0, md, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, mc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // The year.
    if (yr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &yr, yc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        if (yr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (yr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &yr, yc, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

        if (yr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (yr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &yr, yc, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

        if (yr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    append_item_element(p0, yd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, yc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Deallocate year/month/day wide character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    deallocate_item((void*) &yi, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &mi, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &di, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE */
#endif
