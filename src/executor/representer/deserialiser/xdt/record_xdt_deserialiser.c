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

#ifndef RECORD_XDT_DESERIALISER_SOURCE
#define RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises an xdt record.
 *
 * @param p0 the record size (pointer reference)
 * @param p1 the record identification (pointer reference)
 * @param p2 the record data (pointer reference)
 * @param p3 the record count (pointer reference)
 * @param p4 the source data (pointer reference)
 * @param p5 the source count
 */
void deserialise_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record.");

    // The field content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field dependency hierarchy.
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification.
    int id = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;
        }

        // Decode xdt field (size, identification, content).
        deserialise_xdt_field((void*) &cd, (void*) &cc, (void*) &id, (void*) &h, pos, rem);

        //?? TODO
        select_xdt_record_end(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

        if (id == *RECORD_IDENTIFICATION_FIELD_XDT_NAME) {

            // Decode xdt record identification.
            //?? deserialise_cybol_integer(p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, fc, (void*) &fcc);

        } else if (id == *RECORD_SIZE_FIELD_XDT_NAME) {

            // Decode xdt record size.
            //
            // CAUTION! Do NOT use the following line:
            // deserialise_cybol_integer(p0, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, fc, (void*) &fcc);
            //
            // This is because the record content size is
            // counted using the loop variable j.
            // This is safer than relying on the given record size.

            // Store xdt record content.
            //
            // CAUTION! Everything following this record
            // size field belongs to its content.
            // The pointer s was already increased above,
            // so that the record size and -identification
            // are NOT included!
            // The current value of s points to the beginning
            // of the first field of the record's CONTENT.
            *rc = *s;

            // Reset record content count, in order to
            // count the xdt record content now following.
            *rcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        }
    }
}

/* RECORD_XDT_DESERIALISER_SOURCE */
#endif
