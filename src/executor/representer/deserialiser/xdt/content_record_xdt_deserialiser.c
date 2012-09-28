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

#ifndef CONTENT_RECORD_XDT_DESERIALISER_SOURCE
#define CONTENT_RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/searcher/selector/xml/element_content_xml_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the xdt record content.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_xdt_record_content(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record content.");

    // Determine field data.
    deserialise_xdt_field();

    // CAUTION! Peeking forward is possibly NOT necessary,
    // Each field id may be assigned a type as constant, following the xdt standard.
    // This type constant my be e.g. integer or element/part (compound)
    // and be used for creating the new part representing the field.

    //?? The following comparison of the field hierarchy is ONLY needed
    // for free-self-defined records and fields.
    // All fields listed in the xdt standard have a defined type.

    // Peek forward to next field's hierarchy number.
    if (peek-forward-hierarchy greater current-hierarchy) {
        create compound part here
        assign field content to part's NAME (not model)
        make new part the future parent part when handing it over as parametre
    } else {
        determine type of field id; DEFINE constants in new file assigning a type constant like INTEGER_TYPE to an xdt field id, for all possible xdt fields
        create new part here using type constant assigned to the current field's id
        assign field content to part's MODEL (not name)
    }

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

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_xdt_record_content(p0, p1, (void*) &b, p2, p3);
    }
}

/* CONTENT_RECORD_XDT_DESERIALISER_SOURCE */
#endif
