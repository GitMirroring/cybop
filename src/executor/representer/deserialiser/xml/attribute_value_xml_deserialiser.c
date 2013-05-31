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

#ifndef ATTRIBUTE_VALUE_XML_DESERIALISER_SOURCE
#define ATTRIBUTE_VALUE_XML_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/searcher/selector/xml/attribute_value_xml_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the xml attribute value.
 *
 * @param p0 the destination attribute value (pointer reference)
 * @param p1 the destination attribute value count
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_xml_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* avc = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml attribute value.");

        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // CAUTION! If the loop count handed over as parametre is NULL,
            // then the break flag will NEVER be set to true, because the loop
            // variable comparison does (correctly) not consider null values.
            // Therefore, in this case, the break flag is set to true already here.
            // Initialising the break flag with true will NOT work either, since it:
            // a) will be left untouched if a comparison operand is null;
            // b) would have to be reset to true in each loop cycle.
            copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        // Initialise attribute value.
        copy_pointer(p0, p2);

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            select_xml_attribute_value((void*) &b, p2, p3);

            if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Increment attribute value count.
                (*avc)++;
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml attribute value. The attribute value count is null.");
    }
}

/* ATTRIBUTE_VALUE_XML_DESERIALISER_SOURCE */
#endif
