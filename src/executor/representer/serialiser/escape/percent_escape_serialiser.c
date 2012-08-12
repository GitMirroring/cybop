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

#ifndef PERCENT_ESCAPE_SERIALISER_SOURCE
#define PERCENT_ESCAPE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

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

/**
 * Serialises into a percent-escaped character.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_escape_percent(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SPACE_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) SPACE_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SPACE_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NUMBER_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) NUMBER_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DOLLAR_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PERCENT_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) PERCENT_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PERCENT_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) AMPERSAND_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) AMPERSAND_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) AMPERSAND_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SOLIDUS_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) SOLIDUS_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COLON_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) COLON_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COLON_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SEMICOLON_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) SEMICOLON_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEMICOLON_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUALS_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) EQUALS_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EQUALS_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) QUESTION_MARK_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) QUESTION_MARK_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) QUESTION_MARK_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COMMERCIAL_AT_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LEFT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REVERSE_SOLIDUS_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RIGHT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CIRCUMFLEX_ACCENT_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CARET_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CARET_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GRAVE_ACCENT_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LEFT_CURLY_BRACKET_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VERTICAL_LINE_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) VERTICAL_BAR_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) VERTICAL_BAR_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RIGHT_CURLY_BRACKET_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TILDE_WIDE_CHARACTER, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TILDE_URL_ESCAPE_CODE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TILDE_URL_ESCAPE_CODE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }
}

/* PERCENT_ESCAPE_SERIALISER_SOURCE */
#endif
