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

#ifndef MEDICAL_PRACTICE_CORE_DATA_RECORD_XDT_SELECTOR_SOURCE
#define MEDICAL_PRACTICE_CORE_DATA_RECORD_XDT_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Selects the xdt record medical practice core data.
 *
 * @param p0 the destination model item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the source field content
 * @param p3 the source field identification
 * @param p3 the source field hierarchy
 */
void select_xdt_record_medical_practice_core_data(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt record medical practice core data.");

    // Compare for valid fields and add them.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) TAG_END_XML_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // e.g. 0105 KBV-Prüfnummer
            // Assign KBV-Prüfnummer (field content) to destination model item
            // (which was created new beforehand in medical_practice_core_data_record_xdt_deserialiser.c).
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The field does NOT belong to the current record,
        // following the xdt standard specification.

        // This is done for each field in each kind of record,
        // so that the functions return and jump up the hierarchy,
        // if a field does not match to the kind of record.
        // If a new record is found, the deserialiser dives down
        // its hierarchy again.

        // Set break flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* MEDICAL_PRACTICE_CORE_DATA_RECORD_XDT_SELECTOR_SOURCE */
#endif
