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

#ifndef FILE_XDT_DESERIALISER_SOURCE
#define FILE_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/name/xdt/file_xdt_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Deserialises an xdt file.
 *
 * @param p0 the file size (pointer reference)
 * @param p1 the file header data (pointer reference)
 * @param p2 the file header count (pointer reference)
 * @param p3 the file footer data (pointer reference)
 * @param p4 the file footer count (pointer reference)
 * @param p5 the file content data (pointer reference)
 * @param p6 the file content count (pointer reference)
 * @param p7 the source data (pointer reference)
 * @param p8 the source count
 */
void deserialise_xdt_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt file.");

    // The record identification.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    deserialise_xdt_record((void*) &id);
    select_xdt_file_header_begin(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;
        }

        // Decode xdt record (size, identification, content).
        //
        // CAUTION! The file header and -footer count are
        // handed over as parametres to get the record content.
        // A local variable defined in this function may NOT
        // be used as its value is lost when returning from
        // this function. But a valid value has to be
        // returned to the calling function.
        deserialise_xdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, (void*) &s, (void*) &rem);

        select_xdt_record(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);

        // Increment loop variable.
        j = j + rs;

        if (rid == *DATA_FILE_HEADER_RECORD_XDT_NAME) {

            // Store xdt file header.
            //
            // CAUTION! This is only the record content
            // WITHOUT the record size and -identification!
            *ph = *pf;
            *phc = *pfc;

            // Store xdt file content.
            //
            // CAUTION! Everything following this file
            // header record up to the file footer
            // record belongs to the file's content.
            *pc = *s;

            // Reset loop variable.
            j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        } else if (rid == *DATA_FILE_FOOTER_RECORD_XDT_NAME) {

            // CAUTION! The file footer does NOT
            // have to be stored here explicitly.
            // It was already handed over as parametre
            // to the "deserialise_xdt_record" function,
            // so that its value is already set.

            // Decrement file content count.
            //
            // CAUTION! The file content count pcc was
            // reset when the data file header record
            // was found and steadily increased since then.
            //
            // It needs to be decremented here, because
            // the current record size rs was added above,
            // but this data file footer record does
            // NOT belong to the data file content
            // and hence should not be counted.
            *pcc = j - rs;

            // CAUTION! Do NOT decrement the file
            // size, as this file footer record
            // DOES belong to the file!

            // Set remaining bytes to zero, as the file footer
            // has been detected and the loop can be left now.
            rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        }
    }
}

/* FILE_XDT_DESERIALISER_SOURCE */
#endif
