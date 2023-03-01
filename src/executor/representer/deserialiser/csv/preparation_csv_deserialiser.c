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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PREPARATION_CSV_DESERIALISER_SOURCE
#define PREPARATION_CSV_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/deserialiser/csv/content_csv_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Prepares variables necessary for deserialisation.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source textline list data
 * @param p3 the source textline list count
 * @param p4 the delimiter data
 * @param p5 the delimiter count
 * @param p6 the quotation data
 * @param p7 the quotation count
 * @param p8 the header flag
 */
void deserialise_csv_preparation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise csv preparation.");
    //?? fwprintf(stdout, L"Debug: Deserialise csv preparation. source count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise csv preparation. source count remaining *p3: %i\n", *((int*) p3));

    // The escape item, e.g. a DOUBLE quotation mark.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The quotation end PLUS delimiter item, e.g. a quotation mark + comma OR apostrophe + semicolon.
    void* q = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The escape item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The quotation end PLUS delimiter item data, count.
    void* qd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* qc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // CAUTION! Do NOT delete the following check for null since otherwise,
    // the created items with arrays are EMPTY but NOT null and therefore
    // would lead to false results in the detector later on when comparing
    // strings, since empty strings are considered EQUAL on purpose
    // (so that two parts may be equal even if some cybol properties are missing).
    // Therefore, it is important to use NULL values instead of empty arrays here.
    //

    if ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p7 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // Allocate escape item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append quotation TWICE becoming the escape sequence.
        modify_item(e, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p7, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        modify_item(e, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p7, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Get escape item data, count.
        copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    }

    if ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p5 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // Allocate quotation end PLUS delimiter item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &q, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append quotation AND delimiter becoming the combination of both.
        modify_item(q, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p7, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        modify_item(q, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p5, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Get quotation end PLUS delimiter item data, count.
        copy_array_forward((void*) &qd, q, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &qc, q, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    }

/*??
    fwprintf(stdout, L"Debug: Deserialise csv preparation. delimiter data p4: %ls\n", (wchar_t*) p4);
    fwprintf(stdout, L"Debug: Deserialise csv preparation. delimiter count p5: %i\n", p5);
    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise csv preparation. delimiter count *p5: %i\n", *((int*) p5));
    }

    fwprintf(stdout, L"Debug: Deserialise csv preparation. escape data ed: %ls\n", (wchar_t*) ed);
    fwprintf(stdout, L"Debug: Deserialise csv preparation. escape count ec: %i\n", ec);
    if (ec != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise csv preparation. escape count *ec: %i\n", *((int*) ec));
    }

    fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation end PLUS delimiter data qd: %ls\n", (wchar_t*) qd);
    fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation end PLUS delimiter count qc: %i\n", qc);
    if (qc != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation end PLUS delimiter count *qc: %i\n", *((int*) qc));
    }

    fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation data p6: %ls\n", (wchar_t*) p6);
    fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation count p7: %i\n", p7);
    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise csv preparation. quotation count *p7: %i\n", *((int*) p7));
    }
*/

    // Deserialise csv content.
    deserialise_csv_content(p0, p1, p2, p3, p4, p5, ed, ec, qd, qc, p6, p7, p6, p7, p8);

    if ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p7 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Deallocate escape item.
        deallocate_item((void*) &e, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }

    if ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p5 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Deallocate quotation end PLUS delimiter item.
        deallocate_item((void*) &q, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* PREPARATION_CSV_DESERIALISER_SOURCE */
#endif
