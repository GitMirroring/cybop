/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
#include "type.h"
#include "xdt.h"

/**
 * Deserialises the xdt field model.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the decimal separator data
 * @param p4 the decimal separator count
 * @param p5 the thousands separator data
 * @param p6 the thousands separator count
 * @param p7 the format
 */
void deserialise_xdt_field_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field model.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The xDT format uses the extended ASCII format "ISO 8859-15",
    // but the deserialisation functions used here expect wide characters.
    // Therefore, a CONVERSION of source data is done when reading xdt
    // into cyboi, using the cybol "encoding" attribute.
    //

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_datetime_ddmmyyyy(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) MMYY_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_datetime_mmyy(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) QYYYY_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_datetime_qyyyy(p0, p1, p2);
        }
    }

    //
    // duration
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_duration_ddmmyyyyddmmyyyy(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) HHMMHHMM_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_duration_hhmmhhmm(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) YYYY_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_duration_yyyy(p0, p1, p2);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p1, p2, p3, p4, p5, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p1, p2, p3, p4, p5, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p7);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field model. The format is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise xdt field model. The format is unknown. format p7: %i\n", p7);
        fwprintf(stdout, L"Warning: Could not deserialise xdt field model. The format is unknown. format *p7: %i\n", *((int*) p7));
    }
}
