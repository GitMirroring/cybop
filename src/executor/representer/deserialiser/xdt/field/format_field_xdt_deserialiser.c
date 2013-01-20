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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FORMAT_FIELD_XDT_DESERIALISER_SOURCE
#define FORMAT_FIELD_XDT_DESERIALISER_SOURCE

#include "../../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the xdt field format into a cyboi format.
 *
 * All fields listed in the xdt standard have one of
 * the following defined formats (types), e.g.:
 * - num
 * - float
 * - datum
 * - alnum
 *
 * The following constants may be returned:
 * - INTEGER_NUMBER_STATE_CYBOI_FORMAT
 * - FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT
 * - XDT_DATE_DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT
 * - PLAIN_TEXT_STATE_CYBOI_FORMAT
 *
 * @param p0 the destination cyboi format data
 * @param p1 the source xdt field identification data
 */
void deserialise_xdt_field_format(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field format.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) KBV_TEST_NUMBER_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RESPONSIBLE_ENTITY_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SOFTWARE_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    //?? Copy types for ALL possible xdt fields here ...

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RECORD_IDENTIFICATION_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field format. The field identification is unknown.");
    }
}

/* FORMAT_FIELD_XDT_DESERIALISER_SOURCE */
#endif
