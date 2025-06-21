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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Deserialises the cybol part element content given in json format.
 *
 * Example:
 *
 * [selected_node] | element/part |
 * +-root | element/part |
 * | +-0 | element/part |
 * | | +-0 | text/plain | string
 * | | +-1 | text/plain | inline
 * | | +-2 | text/plain | text/plain
 * | | +-3 | text/plain | Hello JSON!
 * | | +-4 | element/part |
 * | +-1 | element/part |
 * | | +-0 | text/plain | path
 * | | +-1 | text/plain | inline
 * | | +-2 | text/plain | text/cybol-path
 * | | +-3 | text/plain | .non-existing.test.path
 * | | +-4 | element/part |
 * | +-2 | element/part |
 * | | +-0 | text/plain | integer
 * | | +-1 | text/plain | inline
 * | | +-2 | text/plain | number/integer
 * | | +-3 | text/plain | 2
 * | | +-4 | element/part |
 * | +-3 | element/part |
 * | | ...
 *
 * The source MODEL handed over contains one node each for:
 * name, channel, format, model, properties.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the language properties (constraints) data
 * @param p6 the language properties (constraints) count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the language
 * @param p11 the decimal separator data
 * @param p12 the decimal separator count
 * @param p13 the thousands separator data
 * @param p14 the thousands separator count
 * @param p15 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 */
void deserialise_cybol_content_json(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol content json.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol content json. source model count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol content json. source model count *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise cybol content json. source properties count p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol content json. source properties count *p4: %i\n", *((int*) p4));

    //
    // Declaration
    //

    // The source name, channel, format, model, properties part.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source name, channel, format, model, properties part model item.
    void* snm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source name, channel, format, model, properties part model item data, count.
    void* snmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The count comparison result.
    int rc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    compare_integer_equal((void*) &rc, p2, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL);

    if (rc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Get source name, channel, format, model, properties part.
        //
        // CAUTION! The parts are retrieved by their INDEX.
        // This means that the ORDER of parts within the given
        // source model data (whole part) has to be exactly that:
        // name, channel, format, model, properties
        //
        copy_array_forward((void*) &sn, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_JSON_CYBOL_NAME);
        copy_array_forward((void*) &sc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_JSON_CYBOL_NAME);
        copy_array_forward((void*) &sf, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_JSON_CYBOL_NAME);
        copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_JSON_CYBOL_NAME);
        copy_array_forward((void*) &sp, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_JSON_CYBOL_NAME);

        //
        // Get source name, channel, format, model, properties part model item.
        //
        // CAUTION! Do NOT use the following names here:
        // - NAME_PART_STATE_CYBOI_NAME
        // - CHANNEL_PART_STATE_CYBOI_NAME
        // - FORMAT_PART_STATE_CYBOI_NAME
        // - MODEL_PART_STATE_CYBOI_NAME
        // - PROPERTIES_PART_STATE_CYBOI_NAME
        //
        // The corresponding parts were already retrieved above.
        // What is wanted here, is just their MODEL containing the actual data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &snm, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &scm, sc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

        // Get source name, channel, format, model, properties part model item data, count.
        copy_array_forward((void*) &snmd, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &snmc, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &scmd, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &scmc, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sfmc, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smmd, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smmc, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //
        // Functionality
        //

        // Test if this is a root node.
        deserialise_cybol_test((void*) &r, sn, sc, sf, sm);

        // Deserialise cybol node (standard or root).
        deserialise_cybol_node(p0, snmd, snmc, scmd, scmc, sfmd, sfmc, smmd, smmc, spmd, spmc, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, (void*) &r);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol content json. The source model count is not 5.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol content json. The source model count is not 5. source model count p2: %i\n", p2);
        fwprintf(stdout, L"Warning: Could not deserialise cybol content json. The source model count is not 5. source model count *p2: %i\n", *((int*) p2));
    }
}
