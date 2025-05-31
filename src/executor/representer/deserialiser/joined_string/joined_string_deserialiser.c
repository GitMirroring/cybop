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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the joined string into separate parts.
 *
 * Prepares variables necessary for deserialisation.
 *
 * @param p0 the destination item
 * @param p1 the source model wide character data
 * @param p2 the source model wide character count
 * @param p3 the delimiter data
 * @param p4 the delimiter count
 * @param p5 the quotation data
 * @param p6 the quotation count
 */
void deserialise_joined_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise joined string.");
    //?? fwprintf(stdout, L"Debug: Deserialise joined string. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise joined string. source count remaining *p2: %i\n", *((int*) p2));

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

    if ((p5 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p6 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // Allocate escape item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append quotation TWICE becoming the escape sequence.
        modify_item(e, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        modify_item(e, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Get escape item data, count.
        copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    }

    if ((p5 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // Allocate quotation end PLUS delimiter item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &q, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append quotation AND delimiter becoming the combination of both.
        modify_item(q, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        modify_item(q, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Get quotation end PLUS delimiter item data, count.
        copy_array_forward((void*) &qd, q, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &qc, q, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    }

/*??
    fwprintf(stdout, L"Debug: Deserialise joined string. delimiter data p3: %ls\n", (wchar_t*) p3);
    fwprintf(stdout, L"Debug: Deserialise joined string. delimiter count p4: %i\n", p4);
    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise joined string. delimiter count *p4: %i\n", *((int*) p4));
    }

    fwprintf(stdout, L"Debug: Deserialise joined string. escape data ed: %ls\n", (wchar_t*) ed);
    fwprintf(stdout, L"Debug: Deserialise joined string. escape count ec: %i\n", ec);
    if (ec != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise joined string. escape count *ec: %i\n", *((int*) ec));
    }

    fwprintf(stdout, L"Debug: Deserialise joined string. quotation end PLUS delimiter data qd: %ls\n", (wchar_t*) qd);
    fwprintf(stdout, L"Debug: Deserialise joined string. quotation end PLUS delimiter count qc: %i\n", qc);
    if (qc != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise joined string. quotation end PLUS delimiter count *qc: %i\n", *((int*) qc));
    }

    fwprintf(stdout, L"Debug: Deserialise joined string. quotation data p5: %ls\n", (wchar_t*) p5);
    fwprintf(stdout, L"Debug: Deserialise joined string. quotation count p6: %i\n", p6);
    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"Debug: Deserialise joined string. quotation count *p6: %i\n", *((int*) p6));
    }
*/

    // Deserialise list of values.
    deserialise_joined_string_reference(p0, p1, p2, p3, p4, ed, ec, qd, qc, p5, p6, p5, p6);

    if ((p5 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p6 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Deallocate escape item.
        deallocate_item((void*) &e, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }

    if ((p5 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Deallocate quotation end PLUS delimiter item.
        deallocate_item((void*) &q, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}
