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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ESCAPE_DESERIALISER_SOURCE
#define PERCENT_ESCAPE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

//
// Reflexions on character set conversion.
//
// A URI is composed from a limited set of characters consisting of
// digits, letters, and a few graphic symbols. A reserved subset of
// those characters may be used to delimit syntax components within a
// URI while the remaining characters, including both the unreserved set
// and those reserved characters not acting as delimiters, define each
// component's identifying data.
//
// A percent-encoding mechanism is used to represent a data octet in a
// component when that octet's corresponding character is outside the
// allowed set or is being used as a delimiter of, or within, the component.
// A percent-encoded octet is encoded as a character triplet,
// consisting of the percent character "%" followed by the two
// hexadecimal digits representing that octet's numeric value.
//
// Example:
//
// percent-encoding: %20
// binary octet: 00100000
// ABNF: %x20
// US-ASCII: space character (SP)
//
// The uppercase hexadecimal digits 'A' through 'F' are equivalent to
// the lowercase digits 'a' through 'f', respectively. If two URIs
// differ only in the case of hexadecimal digits used in percent-encoded
// octets, they are equivalent. For consistency, URI producers and
// normalisers should use uppercase hexadecimal digits for all
// percent-encodings.
//
// Reserved characters:
// - generic delimiters: : / ? # [ ] @
// - sub delimiters: ! $ & ' ( ) * + , ; =
//
// URI producing applications should percent-encode data octets that
// correspond to characters in the reserved set unless these characters
// are specifically allowed by the URI scheme to represent data in that
// component. If a reserved character is found in a URI component and
// no delimiting role is known for that character, then it must be
// interpreted as representing the data octet corresponding to that
// character's encoding in US-ASCII.
//
// Characters that are allowed in a URI but do not have a reserved
// purpose are called unreserved. These include uppercase and lowercase
// letters, decimal digits, hyphen, period, underscore, and tilde.
//
// Unreserved characters: ALPHA DIGIT - . _ ~
//
// URIs that differ in the replacement of an unreserved character
// with its corresponding percent-encoded US-ASCII octet are
// equivalent: they identify the same resource. However, URI
// comparison implementations do not always perform normalisation
// prior to comparison. For consistency, percent-encoded octets
// in the ranges of:
// - ALPHA (%41-%5A and %61-%7A)
// - DIGIT (%30-%39)
// - hyphen (%2D)
// - period (%2E)
// - underscore (%5F)
// - tilde (%7E)
// should NOT BE created by URI producers and, when found in a URI,
// SHOULD BE decoded to their corresponding unreserved characters.
//
// http://tools.ietf.org/html/rfc3986
// (Chapter 2 "Characters")
//

//
// CAUTION! Percent-encoding may be used for all URI, including URL and URN.
//

//
// A percent-encoding mechanism is used to represent a data octet in a
// component when that octet's corresponding character is outside the
// allowed set or is being used as a delimiter of, or within, the component.
// A percent-encoded octet is encoded as a character triplet,
// consisting of the percent character "%" followed by the two
// hexadecimal digits representing that octet's numeric value.
//
// Example:
//
// percent-encoding: %20
// binary octet: 00100000
// ABNF: %x20
// US-ASCII: space character (SP)
//

//
// RFC 3986 does not determine which character set to use for decoding
// non-ASCII characters (e.g. Umlauts like �, �, �). Since a two-digit
// hexadecimal number (which corresponds to eight Bit) is used for url
// encoding, it would be theoretically possible to use an 8 Bit character
// set (e.g. ISO-8859-1 for Umlauts).
//
// However, since many languages have their own 8 Bit character sets, it
// would be rather tedious to handle all these different character sets.
// Moreover, some languages (e.g. Chinese) may not be represented using an
// 8 Bit character set. For this reason, RFC 3629 suggests to represent
// non-ASCII characters using the UTF-8 character set.
//

//
// Example:
// http://de.wikipedia.org/wiki/Gem%C3%BCse
// The German word for vegetable: Gemüse
// The Umlaut letter ü gets percent-escaped as: %C3%BC
//

/**
 * Deserialises the percent-escaped character.
 *
 * All percent-escaped characters are resolved, no matter whether
 * or not they are reserved characters according to the URI specification.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_escape_percent(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Simply using "copy_pointer" is NOT enough!
    // This would only copy a reference to the source,
    // but what is wanted here is a REAL COPY of a wide character.
    // Therefore, the "overwrite_array" function has to be used.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SPACE_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) SPACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SPACE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) NUMBER_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) NUMBER_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) NUMBER_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) DOLLAR_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) PERCENT_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) PERCENT_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) PERCENT_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) AMPERSAND_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) AMPERSAND_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) AMPERSAND_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SOLIDUS_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) SOLIDUS_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SOLIDUS_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COLON_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) COLON_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) COLON_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SEMICOLON_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) SEMICOLON_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SEMICOLON_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) EQUALS_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) EQUALS_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) EQUALS_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) QUESTION_MARK_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) QUESTION_MARK_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) QUESTION_MARK_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) COMMERCIAL_AT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LEFT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) REVERSE_SOLIDUS_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) RIGHT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CARET_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) CARET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) CIRCUMFLEX_ACCENT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) GRAVE_ACCENT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LEFT_CURLY_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) VERTICAL_BAR_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) VERTICAL_BAR_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) VERTICAL_LINE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) RIGHT_CURLY_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) TILDE_URL_ESCAPE_CODE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) TILDE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) TILDE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }
}

/* PERCENT_ESCAPE_DESERIALISER_SOURCE */
#endif
