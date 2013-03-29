/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CHARACTER_REFERENCE_SERIALISER_SOURCE
#define XML_CHARACTER_REFERENCE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/character_reference/character_reference_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises an xml character into a hexadecimal numeric character reference.
 *
 * @param p0 the destination item
 * @param p1 the source wide character
 */
void serialise_character_reference_xml(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* c = (wchar_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise character reference xml.");

        //
        // CAUTION! The following comparisons ARE POSSIBLE because the
        // glibc types "int" and "wchar_t" both have a size of 4 Byte each.
        // If this changes one day, something will have to be adapted here.
        //

        if ((*c == *QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *AMPERSAND_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *APOSTROPHE_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL)) {

            // This IS a reserved character/ predefined entity.

            // Append &#x begin hexadecimal numeric character reference name.
            append_item_element(p0, (void*) BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Serialise source character code into wide character sequence.
            // CAUTION! Hand over NUMBER BASE 16 as parametre!
            serialise_cybol_integer_value(p0, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_16_INTEGER_STATE_CYBOI_MODEL);
            // Append ; end character reference name.
            append_item_element(p0, (void*) END_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_CHARACTER_REFERENCE_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            // This is NOT a reserved character/ predefined entity.

            // Append source character code directly.
            // CAUTION! The destination item is of type "wide character".
            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise character reference xml. The source wide character is null.");
    }
}

/* XML_CHARACTER_REFERENCE_SERIALISER_SOURCE */
#endif
