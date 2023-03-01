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

#ifndef XML_CHARACTER_REFERENCE_SERIALISER_SOURCE
#define XML_CHARACTER_REFERENCE_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/character_reference/character_reference_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/numeral/integer_numeral_serialiser.c"
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

            //
            // This IS a reserved character/predefined entity.
            //

            // Append &#x begin hexadecimal numeric character reference name.
            modify_item(p0, (void*) SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
            //
            // Serialise source character code into wide character sequence.
            //
            // CAUTION! Hand over HEXADECIMAL number base as parametre!
            //
            // CAUTION! Hand over prefix flag value FALSE, since a prefix "&#x"
            // was already prepended above and the "0x" prefix is NOT wanted.
            //
            serialise_numeral_integer(p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
            // Append ; end character reference name.
            modify_item(p0, (void*) END_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) END_CHARACTER_REFERENCE_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            //
            // This is NOT a reserved character/ predefined entity.
            //

            //
            // Append source character code directly.
            //
            // CAUTION! The destination item is of type "wide character".
            //
            modify_item(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise character reference xml. The source wide character is null.");
    }
}

/* XML_CHARACTER_REFERENCE_SERIALISER_SOURCE */
#endif
