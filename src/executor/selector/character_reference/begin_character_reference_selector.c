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

#include "algorithm.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the character reference begin.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_character_reference_begin(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select character reference begin.");
    //?? fwprintf(stdout, L"Debug: Select character reference begin. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select character reference begin. source count remaining *p2: %i\n", *((int*) p2));

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // The hexadecimal numeric character reference has to be searched BEFORE
    // the decimal numeric character reference, which itself has to be searched BEFORE
    // the character entity reference.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Set last flag to TRUE, so that the pointer is
        // moved forward and only the actual character reference remains.
        //
        detect((void*) &r, p1, p2, (void*) SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_character_reference_hexadecimal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Set last flag to TRUE, so that the pointer is
        // moved forward and only the actual character reference remains.
        //
        detect((void*) &r, p1, p2, (void*) CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_character_reference_hexadecimal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Set last flag to TRUE, so that the pointer is
        // moved forward and only the actual character reference remains.
        //
        detect((void*) &r, p1, p2, (void*) DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_character_reference_decimal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Set last flag to TRUE, so that the pointer is
        // moved forward and only the actual character reference remains.
        //
        // CAUTION! Parsing for the begin entity character & does NOT conflict
        // with standard ampersand characters, since the latter have to be
        // ENCODED as &amp; in order to conform to the xml specification.
        //
        detect((void*) &r, p1, p2, (void*) ENTITY_BEGIN_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ENTITY_BEGIN_CHARACTER_REFERENCE_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_character_reference_entity(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a STANDARD character.
        //

        // The character.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Copy character.
        copy_pointer((void*) &c, p1);

        // Append character to destination item.
        modify_item(p0, c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Increment the current position by one.
        move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
