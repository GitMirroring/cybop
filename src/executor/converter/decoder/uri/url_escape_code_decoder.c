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

#ifndef URL_ESCAPE_CODE_DECODER_SOURCE
#define URL_ESCAPE_CODE_DECODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/character/character_constants.c"
#include "../../../../constant/http/url_escape_code_constants.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"
#include "../../../../variable/reallocation_factor.c"

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
 * Decodes the url escape code character data into unmasked character data.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void decode_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Simply using "copy_pointer" is NOT enough!
    // This would only copy a reference to the source,
    // but what is wanted here is a REAL COPY of a wide character.
    // Therefore, the "overwrite_array" function has to be used.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SPACE_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) SPACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SPACE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) NUMBER_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) NUMBER_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) NUMBER_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) DOLLAR_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) PERCENT_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) PERCENT_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) PERCENT_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) AMPERSAND_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) AMPERSAND_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) AMPERSAND_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SOLIDUS_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) SOLIDUS_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SOLIDUS_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COLON_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) COLON_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) COLON_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SEMICOLON_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) SEMICOLON_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) SEMICOLON_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) EQUALS_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) EQUALS_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) EQUALS_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) QUESTION_MARK_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) QUESTION_MARK_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) QUESTION_MARK_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) COMMERCIAL_AT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LEFT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) REVERSE_SOLIDUS_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) RIGHT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CARET_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) CARET_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) CIRCUMFLEX_ACCENT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) GRAVE_ACCENT_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) LEFT_CURLY_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) VERTICAL_BAR_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) VERTICAL_BAR_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) VERTICAL_LINE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) RIGHT_CURLY_BRACKET_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) TILDE_URL_ESCAPE_CODE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) TILDE_URL_ESCAPE_CODE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, (void*) TILDE_WIDE_CHARACTER, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            copy_integer(p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }
}

/* URL_ESCAPE_CODE_DECODER_SOURCE */
#endif
