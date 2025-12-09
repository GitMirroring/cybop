/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Branches programme flow depending upon xml or json, in order to get source node data.
 *
 * @param p0 the destination source name part (pointer reference)
 * @param p1 the destination source channel part (pointer reference)
 * @param p2 the destination source format part (pointer reference)
 * @param p3 the destination source model part (pointer reference)
 * @param p4 the destination source properties part (pointer reference)
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p9 the language
 */
void deserialise_cybol_branching1(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol branching1.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) CYBOL_JSON_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol+json file.
            //

            //
            // Get source name, channel, format, model, properties part.
            //
            // CAUTION! The parts are retrieved by their INDEX.
            // This means that the ORDER of parts within the given JSON
            // source model data (whole part) has to be exactly that:
            // name, channel, format, model, properties
            //
            copy_array_forward(p0, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_JSON_CYBOL_NAME);
            copy_array_forward(p1, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_JSON_CYBOL_NAME);
            copy_array_forward(p2, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_JSON_CYBOL_NAME);
            copy_array_forward(p3, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_JSON_CYBOL_NAME);
            copy_array_forward(p4, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_JSON_CYBOL_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol file, which is identical to a text/cybol+xml file.
            //

            //
            // Get source name, channel, format, model part.
            //
            // CAUTION! The parts are retrieved by their NAME.
            //
            // CAUTION! The properties are NOT retrieved here and handled differently later.
            //
            get_name_array(p0, p7, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p1, p7, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p2, p7, (void*) FORMAT_CYBOL_NAME, (void*) FORMAT_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p3, p7, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) CYBOL_XML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol+xml file.
            //

            //
            // Get source name, channel, format, model part.
            //
            // CAUTION! The parts are retrieved by their NAME.
            //
            // CAUTION! The properties are NOT retrieved here and handled differently later.
            //
            get_name_array(p0, p7, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p1, p7, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p2, p7, (void*) FORMAT_CYBOL_NAME, (void*) FORMAT_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            get_name_array(p3, p7, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol branching1. The language is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol branching1. The language is unknown. language p9: %i\n", p9);
        fwprintf(stdout, L"Warning: Could not deserialise cybol branching1. The language is unknown. language *p9: %i\n", *((int*) p9));
    }
}
