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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_SERIALISER_SOURCE
#define HTML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/boolean/boolean_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/double/double_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/date_time_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/language_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/html/part_html_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source into the destination, according to the given format.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the tree level
 * @param p6 the format
 */
void serialise_html(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise html.");

    // The functions below are for STATE models only.
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    //
    // colour
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) TERMINAL_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_colour_terminal(p0, p1);
        }
    }
*/

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) HH_MM_SS_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_hhmmss_date_time(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_ddmmyyyy_date_time(p0, p1, p2);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_html_part(p0, p1, p2, p5);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_boolean(p0, p1, p2);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_complex(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_double(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_vulgar_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p0, p1, p2);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) REFERENCE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise html. The format is unknown.");
    }
}

/* HTML_SERIALISER_SOURCE */
#endif
