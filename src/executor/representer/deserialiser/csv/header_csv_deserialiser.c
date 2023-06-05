/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"

/**
 * Checks whether or not this is the FIRST record (row).
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source textline model data
 * @param p3 the source textline model count
 * @param p4 the delimiter data, e.g. a comma OR semicolon OR some character sequence
 * @param p5 the delimiter count
 * @param p6 the escape data, e.g. a DOUBLE quotation mark
 * @param p7 the escape count
 * @param p8 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p9 the quotation end PLUS delimiter count
 * @param p10 the quotation end data, e.g. a quotation mark
 * @param p11 the quotation end count
 * @param p12 the quotation begin data, e.g. a quotation mark
 * @param p13 the quotation begin count
 * @param p14 the loop index
 */
void deserialise_csv_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise csv header.");
    //?? fwprintf(stdout, L"Debug: Deserialise csv header. source textline model count p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise csv header. source textline model count *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p14, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is the FIRST record.
        //

        //
        // Deserialise standard data record.
        //
        // CAUTION! Hand over destination PROPERTIES item.
        //
        deserialise_csv_part(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, (void*) HEADER_CSV_CYBOI_NAME, (void*) HEADER_CSV_CYBOI_NAME_COUNT);

    } else {

        //
        // This is NOT the first record.
        //

        // The index.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise index.
        copy_integer((void*) &i, p14);

        //
        // Subtract ONE from index.
        //
        // CAUTION! The first record with index zero was the header
        // and following records continue with index one.
        // But they should be named starting with ZERO again.
        // Therefore, decrement index here.
        //
        calculate_integer_subtract((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        //
        // Serialise index.
        //
        // CAUTION! Hand over destination MODEL item.
        //
        // CAUTION! Hand over DECREMENTED index.
        //
        deserialise_csv_index(p0, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, (void*) &i);
    }
}
