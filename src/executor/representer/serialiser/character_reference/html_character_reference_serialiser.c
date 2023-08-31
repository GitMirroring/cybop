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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises an html character into a hexadecimal numeric character reference.
 *
 * @param p0 the destination item
 * @param p1 the source wide character
 */
void serialise_character_reference_html(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* c = (wchar_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise character reference html.");

        //
        // CAUTION! The following comparisons ARE POSSIBLE because the
        // glibc types "int" and "wchar_t" both have a size of 4 Byte each.
        // If this changes one day, something will have to be adapted here.
        //

        if (
            (*c == *QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *AMPERSAND_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *APOSTROPHE_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL)
            || (*c == *GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL)
            || ((*c >= 0x00A0) && (*c <= 0x00FF))
            || (*c == 0x0152)
            || (*c == 0x0153)
            || (*c == 0x0160)
            || (*c == 0x0161)
            || (*c == 0x0178)
            || (*c == 0x0192)
            || (*c == 0x02C6)
            || (*c == 0x02DC)
            || ((*c >= 0x0391) && (*c <= 0x03A1))
            || ((*c >= 0x03A3) && (*c <= 0x03A9))
            || ((*c >= 0x03B1) && (*c <= 0x03C9))
            || (*c == 0x03D1)
            || (*c == 0x03D2)
            || (*c == 0x03D6)
            || (*c == 0x2002)
            || (*c == 0x2003)
            || (*c == 0x2009)
            || ((*c >= 0x200C) && (*c <= 0x200F))
            || (*c == 0x2013)
            || (*c == 0x2014)
            || ((*c >= 0x2018) && (*c <= 0x201A))
            || ((*c >= 0x201C) && (*c <= 0x201E))
            || ((*c >= 0x2020) && (*c <= 0x2022))
            || (*c == 0x2026)
            || (*c == 0x2030)
            || (*c == 0x2032)
            || (*c == 0x2033)
            || (*c == 0x2039)
            || (*c == 0x203A)
            || (*c == 0x203E)
            || (*c == 0x2044)
            || (*c == 0x20AC)
            || (*c == 0x2111)
            || (*c == 0x2118)
            || (*c == 0x211C)
            || (*c == 0x2122)
            || (*c == 0x2135)
            || ((*c >= 0x2190) && (*c <= 0x2194))
            || (*c == 0x21B5)
            || ((*c >= 0x21D0) && (*c <= 0x21D4))
            || (*c == 0x2200)
            || (*c == 0x2202)
            || (*c == 0x2203)
            || (*c == 0x2205)
            || ((*c >= 0x2207) && (*c <= 0x2209))
            || (*c == 0x220B)
            || (*c == 0x220F)
            || (*c == 0x2211)
            || (*c == 0x2212)
            || (*c == 0x2217)
            || (*c == 0x221A)
            || (*c == 0x221D)
            || (*c == 0x221E)
            || (*c == 0x2220)
            || ((*c >= 0x2227) && (*c <= 0x222B))
            || (*c == 0x2234)
            || (*c == 0x223C)
            || (*c == 0x2245)
            || (*c == 0x2248)
            || (*c == 0x2260)
            || (*c == 0x2261)
            || (*c == 0x2264)
            || (*c == 0x2265)
            || ((*c >= 0x2282) && (*c <= 0x2284))
            || (*c == 0x2286)
            || (*c == 0x2287)
            || (*c == 0x2295)
            || (*c == 0x2297)
            || (*c == 0x22A5)
            || (*c == 0x22C5)
            || ((*c >= 0x2308) && (*c <= 0x230B))
            || (*c == 0x2329)
            || (*c == 0x232A)
            || (*c == 0x25CA)
            || (*c == 0x2660)
            || (*c == 0x2663)
            || (*c == 0x2665)
            || (*c == 0x2666)
        ) {

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

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise character reference html. The source wide character is null.");
    }
}
