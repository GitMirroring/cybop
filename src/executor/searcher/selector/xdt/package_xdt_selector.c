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

#ifndef PACKAGE_XDT_SELECTOR_SOURCE
#define PACKAGE_XDT_SELECTOR_SOURCE

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
 * Selects the xdt package.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination properties
 * @param p4 the destination properties count
 * @param p5 the destination properties size
 * @param p6 the package content
 * @param p7 the package content count
 * @param p8 the package header
 * @param p9 the package header count
 * @param p10 the package footer
 * @param p11 the package footer count
 */
void select_xdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt package.");

/*??
    // The knowledge model name.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ns = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge model type.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* as = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge model model.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ms = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge model properties.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Decode package content.
    // CAUTION! Hand over a null pointer in place of the model and model count!
    // This is necessary because an EMPTY compound model is to be created.
    // The given model parametres do not represent the compound's xml file name
    // but a byte stream which gets processed further below.
    deserialise_xdt_deserialise_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL,
        (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
        (void*) STANDARD_PACKAGE_XDT_NAME, (void*) STANDARD_PACKAGE_XDT_NAME_COUNT);

    // Process xdt package content.
    deserialise_xdt_process_package(m, mc, ms, p6, p7);
    // Decode xdt package header (meta data 1).
    deserialise_xdt_select_record(d, dc, ds, p8, p9, (void*) DATA_PACKAGE_HEADER_RECORD_XDT_NAME);
    // Decode xdt package footer (meta data 2).
    deserialise_xdt_select_record(d, dc, ds, p10, p11, (void*) DATA_PACKAGE_FOOTER_RECORD_XDT_NAME);

    // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
    if ((n != *NULL_POINTER_STATE_CYBOI_MODEL) && (nc != *NULL_POINTER_STATE_CYBOI_MODEL) && (ns != *NULL_POINTER_STATE_CYBOI_MODEL)
        && (a != *NULL_POINTER_STATE_CYBOI_MODEL) && (ac != *NULL_POINTER_STATE_CYBOI_MODEL) && (as != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Add xdt package to given destination compound model.
        //
        // CAUTION! Hand over the name as reference, as it gets changed by adding
        // an index as name suffix, to uniquely identify the record within the compound.
        append_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

    } else {

        // Destroy all arrays, since they were not added to the compound.
        // CAUTION! If this was not done here, they would never be deallocated!
        // CAUTION! Use DESCENDING order, as opposed to array allocation!

        // Deallocate knowledge model properties.
        deallocate((void*) &d, ds, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        deallocate((void*) &dc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);
        deallocate((void*) &ds, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);

        // Deallocate knowledge model model.
        deallocate((void*) &m, ms, a, ac);
        deallocate((void*) &mc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);
        deallocate((void*) &ms, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);

        // Deallocate knowledge model type.
        deallocate((void*) &a, as, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT);
        deallocate((void*) &ac, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);
        deallocate((void*) &as, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);

        // A knowledge model channel was not allocated.

        // Deallocate knowledge model name.
        deallocate((void*) &n, ns, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT, (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT);
        deallocate((void*) &nc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);
        deallocate((void*) &ns, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);
    }
*/
}

/* PACKAGE_XDT_SELECTOR_SOURCE */
#endif
