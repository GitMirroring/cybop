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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FIELD_BDT_XDT_SELECTOR_SOURCE
#define FIELD_BDT_XDT_SELECTOR_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/accessor/name_getter/array_name_getter.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/representer/deserialiser/cybol/integer/primitive_value_integer_cybol_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/xdt/record/part_record_xdt_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Selects an xdt bdt field by filtering its name (number).
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source record model data
 * @param p3 the source record model index
 * @param p4 the source record name data
 * @param p5 the source record name count
 * @param p6 the source field part (pointer reference)
 * @param p7 the source field model data
 * @param p8 the source field model index
 * @param p9 the source field name as integer
 */
void select_xdt_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt field.");

    //
    // Only COMPOUND xdt fields need special treatment here, since they
    // represent new parent nodes to which child nodes will be added.
    //
    // Those xdt fields with primitive data type are NOT filtered here.
    // They may be processed uniformly by just adding the source part
    // to the destination in the last if-else-branch below.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //?? TEST ONLY
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SOFTWARE_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST select xdt bdt field SOFTWARE: %i\n", *((int*) p9));

//??            deserialise_xdt_bdt_field_xyz();
        }
    }

    //
    // Record ??
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Field xdt name: 6200
        compare_integer_equal((void*) &r, p9, (void*) TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_field_compound();
        }
    }

    //
    // Record "spec"
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Field xdt name: 9900
        compare_integer_equal((void*) &r, p9, (void*) SPECIFICATION_IDENTIFICATION_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_field_xyz();
        }
    }

/*??
    if (*id == *KBV_TEST_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *RESPONSIBLE_ENTITY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) RESPONSIBLE_ENTITY_FIELD_XDT_CYBOI_NAME, (void*) RESPONSIBLE_ENTITY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SOFTWARE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SOFTWARE_FIELD_XDT_CYBOI_NAME, (void*) SOFTWARE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *HARDWARE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) HARDWARE_FIELD_XDT_CYBOI_NAME, (void*) HARDWARE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SOFTWARE_RELEASE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SOFTWARE_RELEASE_FIELD_XDT_CYBOI_NAME, (void*) SOFTWARE_RELEASE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PHYSICIAN_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_CATEGORY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_CATEGORY_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_STREET_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_STREET_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_STREET_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_PHONE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_PHONE_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_PHONE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_FAX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_FAX_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_FAX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_MODEM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PHYSICIAN_MODEM_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_MODEM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_CYBOI_NAME, (void*) PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_NAME_AFFIX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_NAME_AFFIX_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_NAME_AFFIX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_LAST_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_LAST_NAME_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_LAST_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_FIRST_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_FIRST_NAME_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_FIRST_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_BIRTH_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_TITLE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_TITLE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_TITLE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_RESIDENCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_RESIDENCE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_STREET_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_STREET_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_STREET_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_SEX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_SEX_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_SEX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_EMPLOYER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_EMPLOYER_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_EMPLOYER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_LAST_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INSURANT_LAST_NAME_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_LAST_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_FIRST_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INSURANT_FIRST_NAME_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_FIRST_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_BIRTH_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) INSURANT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_RESIDENCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INSURANT_RESIDENCE_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_STREET_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INSURANT_STREET_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_STREET_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INJURED_PHONE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INJURED_PHONE_FIELD_XDT_CYBOI_NAME, (void*) INJURED_PHONE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INSURANT_SEX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INSURANT_SEX_FIELD_XDT_CYBOI_NAME, (void*) INSURANT_SEX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_X_RAY_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_X_RAY_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_X_RAY_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_SINCE_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_SINCE_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_SINCE_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PROFESSION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PROFESSION_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PROFESSION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_BODY_HEIGHT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_BODY_HEIGHT_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_BODY_HEIGHT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_BODY_WEIGHT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_BODY_WEIGHT_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_BODY_WEIGHT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PHONE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PHONE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PHONE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_NATIONALITY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_MOTHER_TONGUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_MOTHER_TONGUE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_MOTHER_TONGUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PERMANENT_DRUGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PERMANENT_DRUGS_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PERMANENT_DRUGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_RISK_FACTORS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_RISK_FACTORS_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_RISK_FACTORS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_ALLERGIES_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_ALLERGIES_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_ALLERGIES_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_ACCIDENTS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_ACCIDENTS_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_ACCIDENTS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_SURGERIES_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_SURGERIES_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_SURGERIES_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_ANAMNESIS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_ANAMNESIS_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_ANAMNESIS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_PERMANENT_THERAPY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_PERMANENT_THERAPY_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_PERMANENT_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_CYBOI_NAME, (void*) PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_QUARTER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_QUARTER_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_QUARTER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_ISSUANCE_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) INVOICE_ISSUANCE_DATE_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_ISSUANCE_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_VALIDITY_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) INVOICE_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_INSURANCE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_INSURANCE_OFFICE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INVOICE_INSURANCE_OFFICE_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_INSURANCE_OFFICE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_BILLING_CATEGORY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_BILLING_CATEGORY_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_BILLING_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_MMYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_MMYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_BILLING_SCALE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_BILLING_SCALE_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_BILLING_SCALE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_BILLING_AREA_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_BILLING_AREA_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_BILLING_AREA_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_DIAGNOSIS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) REFERRAL_DIAGNOSIS_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_EXPLANATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) REFERRAL_EXPLANATION_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_EXPLANATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CHECK_BOX_AK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_CHECK_BOX_AK_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_CHECK_BOX_AK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME, (void*) REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_CYBOI_NAME, (void*) INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_CYBOI_NAME, (void*) INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INPATIENT_TREATMENT_CLASS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INPATIENT_TREATMENT_CLASS_FIELD_XDT_CYBOI_NAME, (void*) INPATIENT_TREATMENT_CLASS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INPATIENT_HOSPITAL_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) INPATIENT_HOSPITAL_NAME_FIELD_XDT_CYBOI_NAME, (void*) INPATIENT_HOSPITAL_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INPATIENT_HOSPITAL_STAY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INPATIENT_HOSPITAL_STAY_FIELD_XDT_CYBOI_NAME, (void*) INPATIENT_HOSPITAL_STAY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *INVOICE_SUB_CATEGORY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) INVOICE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME, (void*) INVOICE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME, (void*) EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EMERGENCY_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) EMERGENCY_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) EMERGENCY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EMERGENCY_SYMPTOMS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) EMERGENCY_SYMPTOMS_FIELD_XDT_CYBOI_NAME, (void*) EMERGENCY_SYMPTOMS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_DATE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_TIME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_TIME_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_TIME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_LOCATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_LOCATION_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_LOCATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_COMPANY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_COMPANY_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_COMPANY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_X_RAY_RESULT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_X_RAY_RESULT_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_X_RAY_RESULT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_ABLE_TO_WORK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_ABLE_TO_WORK_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_ABLE_TO_WORK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_KIND_OF_BILL_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_KIND_OF_BILL_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_KIND_OF_BILL_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_CYBOI_NAME, (void*) ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) BILLING_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_ADDRESS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_ADDRESS_FIELD_XDT_CYBOI_NAME, (void*) BILLING_ADDRESS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME, (void*) BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_DATE_FIELD_XDT_CYBOI_NAME, (void*) BILLING_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_TOTAL_SUM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_TOTAL_SUM_FIELD_XDT_CYBOI_NAME, (void*) BILLING_TOTAL_SUM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_CYBOI_NAME, (void*) BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_CYBOI_NAME, (void*) BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_ATTACHMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) BILLING_ATTACHMENT_FIELD_XDT_CYBOI_NAME, (void*) BILLING_ATTACHMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_HEADER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_HEADER_FIELD_XDT_CYBOI_NAME, (void*) BILLING_HEADER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_FOOTER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_FOOTER_FIELD_XDT_CYBOI_NAME, (void*) BILLING_FOOTER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_TREATMENT_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_GNR_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_GNR_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_GNR_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_ADDRESSEE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_ADDRESSEE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_ADDRESSEE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_MULTIPLIER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_MULTIPLIER_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_MULTIPLIER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_TIME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_TIME_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_TIME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_ORDER_EXECUTION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_ORDER_EXECUTION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_ORDER_EXECUTION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_DKM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_DKM_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_DKM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_EXPLANATORY_DRUG_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_EXPLANATORY_DRUG_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_EXPLANATORY_DRUG_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_ORGAN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_ORGAN_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_ORGAN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_LOCATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_LOCATION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_LOCATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_ZONE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_ZONE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_ZONE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_GNR_DESCRIPTION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_GNR_DESCRIPTION_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_GNR_DESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_FEE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_FEE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_FEE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_FACTOR_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_FACTOR_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_FACTOR_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_SUM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_SUM_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_SUM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_TOTAL_SUM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) SERVICE_TOTAL_SUM_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_TOTAL_SUM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_POINT_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_POINT_VALUE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_POINT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_FEE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_FEE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_FEE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_CYBOI_NAME, (void*) SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_DIAGNOSIS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_DIAGNOSIS_FIELD_XDT_CYBOI_NAME, (void*) BILLING_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *BILLING_ICD_KEY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) BILLING_ICD_KEY_FIELD_XDT_CYBOI_NAME, (void*) BILLING_ICD_KEY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMMSS_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMMSS_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_X_RAY_FINDINGS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_X_RAY_FINDINGS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_X_RAY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_COMMENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_COMMENT_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_COMMENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_BLOOD_PRESSURE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_BLOOD_PRESSURE_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_BLOOD_PRESSURE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_SYMPTOMS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_SYMPTOMS_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_SYMPTOMS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_THERAPY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_THERAPY_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_REFERRAL_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_REFERRAL_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_REFERRAL_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_HOSPITALISATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_HOSPITALISATION_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_HOSPITALISATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_CYBOI_NAME, (void*) TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_CERTIFICATE_KIND_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_CERTIFICATE_KIND_FIELD_XDT_CYBOI_NAME, (void*) LETTER_CERTIFICATE_KIND_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_CERTIFICATE_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_CERTIFICATE_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_CERTIFICATE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_FILE_FORMAT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_FILE_FORMAT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_FILE_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_FILE_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_FILE_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_FILE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_FILE_URL_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_FILE_URL_FIELD_XDT_CYBOI_NAME, (void*) LETTER_FILE_URL_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_ATTESTATION_KIND_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_ATTESTATION_KIND_FIELD_XDT_CYBOI_NAME, (void*) LETTER_ATTESTATION_KIND_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_ATTESTATION_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_ATTESTATION_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_ATTESTATION_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_ADDRESSEE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_ADDRESSEE_FIELD_XDT_CYBOI_NAME, (void*) LETTER_ADDRESSEE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_SALUTATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_SALUTATION_FIELD_XDT_CYBOI_NAME, (void*) LETTER_SALUTATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_STREET_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_STREET_FIELD_XDT_CYBOI_NAME, (void*) LETTER_STREET_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_POSTCODE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_POSTCODE_FIELD_XDT_CYBOI_NAME, (void*) LETTER_POSTCODE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_RESIDENCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_RESIDENCE_FIELD_XDT_CYBOI_NAME, (void*) LETTER_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME, (void*) LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_PHONE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_PHONE_FIELD_XDT_CYBOI_NAME, (void*) LETTER_PHONE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_FAX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_FAX_FIELD_XDT_CYBOI_NAME, (void*) LETTER_FAX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) LETTER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_GRAPHIC_FORMAT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_GRAPHIC_FORMAT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_GRAPHIC_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *LETTER_IMAGE_CONTENT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) LETTER_IMAGE_CONTENT_FIELD_XDT_CYBOI_NAME, (void*) LETTER_IMAGE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *RECORD_IDENTIFICATION_FIELD_XDT_NAME) {

        //?? 8000

        deserialise_xdt_record();

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) RECORD_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) RECORD_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *RECORD_SIZE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) RECORD_SIZE_FIELD_XDT_CYBOI_NAME, (void*) RECORD_SIZE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DEVICE_RECEIVER_GDT_ID_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) DEVICE_RECEIVER_GDT_ID_FIELD_XDT_CYBOI_NAME, (void*) DEVICE_RECEIVER_GDT_ID_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DEVICE_SENDER_GDT_ID_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) DEVICE_SENDER_GDT_ID_FIELD_XDT_CYBOI_NAME, (void*) DEVICE_SENDER_GDT_ID_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_KIND_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_KIND_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_KIND_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_TEST_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_TEST_NAME_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_TEST_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_TEST_STATUS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_TEST_STATUS_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_TEST_STATUS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_LIMIT_INDICATOR_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_LIMIT_INDICATOR_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_LIMIT_INDICATOR_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMM_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_DATA_STREAM_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_DATA_STREAM_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_DATA_STREAM_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_HHMMSS_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_HHMMSS_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_GERM_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_GERM_NAME_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_GERM_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_GERM_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_GERM_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_GERM_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_RESISTANCE_METHOD_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_RESISTANCE_METHOD_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_RESISTANCE_METHOD_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT,
            (void*) FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_REMARK_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_REMARK_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_REMARK_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_RESULT_TEXT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_RESULT_TEXT_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_RESULT_TEXT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *FINDINGS_SIGNATURE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) FINDINGS_SIGNATURE_FIELD_XDT_CYBOI_NAME, (void*) FINDINGS_SIGNATURE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_MEDIUM_CREATION_DATE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT, (void*) XDT_DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT,
            (void*) DATA_MEDIUM_CREATION_DATE_FIELD_XDT_CYBOI_NAME, (void*) DATA_MEDIUM_CREATION_DATE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_CYBOI_NAME, (void*) DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_CYBOI_NAME, (void*) DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_SIZE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_SIZE_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_SIZE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_ADT_VERSION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) DATA_PACKAGE_ADT_VERSION_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_ADT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_BDT_VERSION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) DATA_PACKAGE_BDT_VERSION_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_BDT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_GDT_VERSION_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) DATA_PACKAGE_GDT_VERSION_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_GDT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT,
            (void*) DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_CYBOI_NAME, (void*) DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *SYSTEM_INTERNAL_PARAMETRE_FIELD_XDT_NAME) {

        deserialise_xdt_deserialise_model(p0, p1, p2, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT,
            (void*) SYSTEM_INTERNAL_PARAMETRE_FIELD_XDT_CYBOI_NAME, (void*) SYSTEM_INTERNAL_PARAMETRE_FIELD_XDT_CYBOI_NAME_COUNT);
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append source field part to destination model item.
        //
        // CAUTION! All xdt fields with PRIMITIVE data type are
        // processed uniformly and just added to the destination here.
        // The COMPOUND xdt fields have been filtered above.
        //
        // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
        // This is necessary in order to activate rubbish (garbage) collection.
        append_item_element(p0, p6, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* FIELD_BDT_XDT_SELECTOR_SOURCE */
#endif
