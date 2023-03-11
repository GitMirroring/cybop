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

#ifndef CHARACTER_PERCENT_ENCODING_SERIALISER_SOURCE
#define CHARACTER_PERCENT_ENCODING_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/serialiser/percent_encoding/bytes_percent_encoding_serialiser.c"
#include "logger.h"

/**
 * Serialises into a percent-encoded character.
 *
 * The source wide character gets transformed into a multibyte character.
 *
 * @param p0 the destination character item
 * @param p1 the source wide character
 */
void serialise_percent_encoding_character(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* c = (wchar_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise percent encoding character.");

        //
        // CAUTION! The following comparisons ARE POSSIBLE because the
        // glibc types "int" and "wchar_t" both have a size of 4 Byte each.
        // If this changes one day, something will have to be adapted here.
        //

        if ((i > xx) && (i < yy)) {

            //
            // Characters from the unreserved set NEVER need to be percent-encoded.
            //
            // URIs that differ only by whether an unreserved character is percent-encoded
            // or appears literally are equivalent by definition, but URI processors,
            // in practice, may not always recognize this equivalence.
            //
            // Example:
            // URI consumers should NOT treat "%41" differently from "A" or
            // "%7E" differently from "~", but some do. For maximum interoperability,
            // URI producers are DISCOURAGED from percent-encoding unreserved characters.
            //

            // CAUTION! The destination item is of type "character".
            modify_item(p0, cd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            //
            // When a character from the reserved set (a "reserved character") has
            // special meaning (a "reserved purpose") in a certain context, and a URI scheme
            // says that it is necessary to use that character for some other purpose,
            // then the character must be percent-encoded.
            //
            // Percent-encoding a reserved character involves these steps:
            // - convert the wide character to its corresponding utf-8 multibyte sequence
            // - represent each single byte as a pair of hexadecimal digits
            // - precede the digits by a percent sign ("%") which is used as an escape character
            //
            // Example:
            // The reserved character "/", if used in the "path" component of a URI,
            // has the special meaning of being a delimiter between path segments.
            // If, according to a given URI scheme, "/" needs to be in a path segment,
            // then the three characters "%2F" or "%2f" must be used in the segment
            // instead of a raw "/".
            //

            // Precede the digits by a percent sign ("%") which is used as an escape character.
            modify_item(p0, (void*) BEGIN_PERCENT_ENCODING_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BEGIN_PERCENT_ENCODING_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Convert the wide character to its corresponding utf-8 multibyte sequence.
            encode_utf_8(tmp_item, src_data, src_count);

            // Represent each single byte as a pair of hexadecimal digits.
            serialise_percent_encoding_bytes();
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise percent encoding character. The source wide character is null.");
    }
}

/* CHARACTER_PERCENT_ENCODING_SERIALISER_SOURCE */
#endif
