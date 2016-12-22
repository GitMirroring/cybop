/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_CYBOL_DESERIALISER_SOURCE
#define ELEMENT_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/converter/encoder.c"
#include "../../../../executor/representer/deserialiser/cybol/part_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/xml_deserialiser.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../../../tester/data_as_model_diagram_tester.c"
#include "../../../../tester/item_as_model_diagram_tester.c"

//
// Forward declarations.
//

void deserialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_xml(void* p0, void* p1, void* p2, void* p3);

/**
 * Deserialises the cybol element (part or property).
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the format
 */
void deserialise_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol element.");

    // The temporary format, type, model, properties item.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary model, properties data, count.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate temporary format, type, model, properties item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Initialise integer items with a size of ONE,
    // in order to avoid later reallocation when overwriting
    // the element and to thus increase efficiency.
    allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    // Deserialise source message (cybol file) into temporary model, properties item.
    deserialise_xml(m, p, p2, p3);

    // Get temporary model, properties data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
    //?? TEST: Delete the following block later!
    // CAUTION! Since the temporary model and properties are of PART_ELEMENT_STATE_CYBOI_TYPE,
    // the PART_ELEMENT_STATE_CYBOI_FORMAT may be used as parametre here.
    test_data_as_model_diagram((void*) L"TEST_DESERIALISE_XML.txt", (void*) L"[selected_node]", (void*) NUMBER_15_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, md, mc, pd, pc);
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise temporary model, properties item into cyboi model using temporary type, format.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            deserialise_cybol_part_element_content(p0, md, mc, pd, pc, t, f);

/*??
            //?? TEST: Delete the following block later!
            void* p0d = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p0c = *NULL_POINTER_STATE_CYBOI_MODEL;
            copy_array_forward((void*) &p0d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &p0c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            test_data_as_model_diagram((void*) L"TEST_DESERIALISE_CYBOL_PART.txt", (void*) L"[selected_node]", (void*) NUMBER_20_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, p0d, p0c, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PROPERTY_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise temporary model, properties item into cyboi model using temporary type, format.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            deserialise_cybol_part_element_content(p1, md, mc, pd, pc, t, f);

/*??
            //?? TEST: Delete the following block later!
            void* p1d = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p1c = *NULL_POINTER_STATE_CYBOI_MODEL;
            copy_array_forward((void*) &p1d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &p1c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            test_data_as_model_diagram((void*) L"TEST_DESERIALISE_CYBOL_PROPERTY.txt", (void*) L"[selected_node]", (void*) NUMBER_24_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, p1d, p1c, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
*/
        }
    }

    // Deallocate temporary format, type, model, properties item.
    deallocate_item((void*) &m, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* ELEMENT_CYBOL_DESERIALISER_SOURCE */
#endif
