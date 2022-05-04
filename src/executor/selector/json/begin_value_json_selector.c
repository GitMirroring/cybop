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

#ifndef BEGIN_VALUE_JSON_SELECTOR_SOURCE
#define BEGIN_VALUE_JSON_SELECTOR_SOURCE

#include "../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/model/json/json_model.c"
#include "../../../constant/name/json/json_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/modifier/appender/item/part_item_appender.c"
#include "../../../executor/mover/mover.c"
#include "../../../executor/representer/deserialiser/json/object_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/string_json_deserialiser.c"
#include "../../../logger/logger.c"

/**
 * Selects the json value begin.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the member name data
 * @param p5 the member name count
 * @param p6 the break flag
 */
void select_json_value_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json value begin.");
    fwprintf(stdout, L"Debug: Select json value begin. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Select json value begin. count remaining *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // whitespace
    //

    //
    // The json standard defines five kinds of white space:
    // - empty: ""
    // - space: 0020
    // - line feed: 000A
    // - carriage return: 000D
    // - character tabulation: 0009
    //
    // Reference:
    // https://www.json.org/
    //
    // The first (empty) can obviously not be considered.
    // Therefore, just four comparisons are done below.
    // All kinds of whitespace characters are skipped.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment the current position by one primitive count.
            move(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment the current position by one primitive count.
            move(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) CARRIAGE_RETURN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment the current position by one primitive count.
            move(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) CHARACTER_TABULATION_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment the current position by one primitive count.
            move(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // standard elements
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_ARRAY_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? deserialise_json_array(p0, p1, p2, p3, p4, p5);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_OBJECT_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_OBJECT_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_object(p0, p1, p2, p3, p4, p5);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_END_STRING_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_END_STRING_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_string(p0, p1, p2, p3, p4, p5);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // primitive values
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) NULL_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NULL_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Allocate null part and append it to the destination model item.
            //
            // CAUTION! Process NULL value like a standard object.
            //
            // Since the json value is "null" and no type is given,
            // the PART_ELEMENT_STATE_CYBOI_TYPE is used default.
            //
            // The model and properties are left EMPTY.
            //
            append_item_part(p0, p4, p5, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) TRUE_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TRUE_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_part(p0, p4, p5, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) FALSE_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_part(p0, p4, p5, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set break flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Any other characters get interpreted as number.
        //

        //?? deserialise_json_number(p0, p1, p2, p3);

        // Set break flag.
        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* BEGIN_VALUE_JSON_SELECTOR_SOURCE */
#endif
