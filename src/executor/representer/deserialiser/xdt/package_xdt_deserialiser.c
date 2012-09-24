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

#ifndef PACKAGE_XDT_DESERIALISER_SOURCE
#define PACKAGE_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/name/xdt/package_xdt_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Deserialises an xdt package.
 *
 * @param p0 the package size (pointer reference)
 * @param p1 the package header data (pointer reference)
 * @param p2 the package header count (pointer reference)
 * @param p3 the package footer data (pointer reference)
 * @param p4 the package footer count (pointer reference)
 * @param p5 the package content data (pointer reference)
 * @param p6 the package content count (pointer reference)
 * @param p7 the source data (pointer reference)
 * @param p8 the source count
 */
void deserialise_xdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt package.");

    // Reset package size.
    *ps = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The record size.
    int rs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The record identification.
    int rid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;
        }

        // Decode xdt record (size, identification, content).
        //
        // CAUTION! The package header and -footer count are
        // handed over as parametres to get the record content.
        // A local variable defined in this function may NOT
        // be used as its value is lost when returning from
        // this function. But a valid value has to be
        // returned to the calling function.
        deserialise_xdt_record((void*) &rs, (void*) &rid, p3, p4, p7, (void*) &rem);

        // Decrement remaining bytes in the source byte array.
        rem = rem - rs;

        // Increment package size.
        *ps = *ps + rs;

        // Increment loop variable.
        j = j + rs;

        if (rid == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

            // Store xdt package header.
            //
            // CAUTION! This is only the record content
            // WITHOUT the record size and -identification!
            *ph = *pf;
            *phc = *pfc;

            // Store xdt package content.
            //
            // CAUTION! Everything following this package
            // header record up to the package footer
            // record belongs to the package's content.
            *pc = *s;

            // Reset loop variable.
            j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        } else if (rid == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

            // CAUTION! The package footer does NOT
            // have to be stored here explicitly.
            // It was already handed over as parametre
            // to the "deserialise_xdt_record" function,
            // so that its value is already set.

            // Decrement package content count.
            //
            // CAUTION! The package content count pcc was
            // reset when the data package header record
            // was found and steadily increased since then.
            //
            // It needs to be decremented here, because
            // the current record size rs was added above,
            // but this data package footer record does
            // NOT belong to the data package content
            // and hence should not be counted.
            *pcc = j - rs;

            // CAUTION! Do NOT decrement the package
            // size, as this package footer record
            // DOES belong to the package!

            // Set remaining bytes to zero, as the package footer
            // has been detected and the loop can be left now.
            rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        }
    }
}

/**
 * Processes the xdt package.
 *
 * @param p0 the destination model item
 * @param p3 the source package data
 * @param p4 the source package count
 */
void deserialise_xdt_process_package(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Process xdt package.");

    // The record size.
    int rs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The record identification.
    int rid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The record content.
    void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;
        }

        // Decode xdt record (size, identification, content).
        deserialise_xdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, (void*) &s, (void*) &rem);

        select_xdt_record(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);
    }
}

/* PACKAGE_XDT_DESERIALISER_SOURCE */
#endif
