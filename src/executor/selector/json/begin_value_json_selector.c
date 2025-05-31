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

#include "algorithm.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"

/**
 * Selects the json value begin.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the decimal separator data
 * @param p5 the decimal separator count
 * @param p6 the thousands separator data
 * @param p7 the thousands separator count
 * @param p8 the member name data
 * @param p9 the member name count
 * @param p10 the array or object end flag
 * @param p11 the value end flag
 * @param p12 the object flag (true if this is an object; false for array or otherwise the default)
 */
void select_json_value_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json value begin.");
    //?? fwprintf(stdout, L"Debug: Select json value begin. count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Select json value begin. count remaining *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Debug: Select json value begin. data position *p2: %i\n", *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Select json value begin. data position *p2 ls: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Select json value begin. data position *p2 lc: %lc\n", *((wchar_t*) *((void**) p2)));
    //?? fwprintf(stdout, L"Debug: Select json value begin. data position *p2 lc as int: %i\n", *((wchar_t*) *((void**) p2)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // end characters
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // ]
        detect((void*) &r, p2, p3, (void*) END_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_ARRAY_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Set BOTH flags here.
            // One is for leaving the value deserialisation loop
            // and the other one is for leaving the array or object loop.
            //

            // Set array or object end flag.
            copy_integer(p10, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // }
        detect((void*) &r, p2, p3, (void*) END_OBJECT_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_OBJECT_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Set BOTH flags here.
            // One is for leaving the value deserialisation loop
            // and the other one is for leaving the array or object loop.
            //

            // Set array or object end flag.
            copy_integer(p10, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // separation characters
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // ,
        detect((void*) &r, p2, p3, (void*) SEPARATION_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEPARATION_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // :
        detect((void*) &r, p2, p3, (void*) NAME_VALUE_SEPARATION_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NAME_VALUE_SEPARATION_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    //
    // whitespace
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Detect whitespace character.
        select_whitespace((void*) &r, p2, p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    //
    // compound data
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // [
        detect((void*) &r, p2, p3, (void*) BEGIN_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_ARRAY_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_array(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // {
        detect((void*) &r, p2, p3, (void*) BEGIN_OBJECT_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_OBJECT_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_object(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // primitive text data
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // "
        detect((void*) &r, p2, p3, (void*) BEGIN_END_STRING_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_END_STRING_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_json_string_type(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p11, p12);
        }
    }

    //
    // pre-defined values
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // null
        detect((void*) &r, p2, p3, (void*) NULL_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NULL_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Allocate null part and append it to the destination model item.
            //
            // CAUTION! Process NULL value like a standard object.
            //
            // Since the json value is "null" and no type is given,
            // the PART_ELEMENT_STATE_CYBOI_TYPE is used default.
            //
            // The model and properties are left EMPTY.
            //
            append_part(p0, p8, p9, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // true
        detect((void*) &r, p2, p3, (void*) TRUE_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TRUE_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_part(p0, p8, p9, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // false
        detect((void*) &r, p2, p3, (void*) FALSE_JSON_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_JSON_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_part(p0, p8, p9, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // primitive number data
    //
    // categories:
    // - sign +/-
    // - digits 0..9
    // - full stop (decimal separator) .
    // - hexadecimal digits A..F and a..f
    //
    // CAUTION! Set last parametre move flag to FALSE, so that
    // the number deserialiser can detect the digit once again.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // +
        detect((void*) &r, p2, p3, (void*) PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // -
        detect((void*) &r, p2, p3, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 0
        detect((void*) &r, p2, p3, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 1
        detect((void*) &r, p2, p3, (void*) DIGIT_ONE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 2
        detect((void*) &r, p2, p3, (void*) DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 3
        detect((void*) &r, p2, p3, (void*) DIGIT_THREE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 4
        detect((void*) &r, p2, p3, (void*) DIGIT_FOUR_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 5
        detect((void*) &r, p2, p3, (void*) DIGIT_FIVE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 6
        detect((void*) &r, p2, p3, (void*) DIGIT_SIX_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 7
        detect((void*) &r, p2, p3, (void*) DIGIT_SEVEN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 8
        detect((void*) &r, p2, p3, (void*) DIGIT_EIGHT_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // 9
        detect((void*) &r, p2, p3, (void*) DIGIT_NINE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    // The number might start with a decimal separator without leading zero.
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // .
        detect((void*) &r, p2, p3, (void*) FULL_STOP_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // A
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // B
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // C
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // D
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_D_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // E
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // F
        detect((void*) &r, p2, p3, (void*) LATIN_CAPITAL_LETTER_F_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // a
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // b
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // c
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // d
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_D_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // e
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // f
        detect((void*) &r, p2, p3, (void*) LATIN_SMALL_LETTER_F_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_json_number(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

            // Set value end flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // unknown character
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select json value begin. The character is unknown and gets skipped.");
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. count remaining p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. count remaining *p3: %i\n", *((int*) p3));
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. data position *p2: %i\n", *((void**) p2));
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. data position *p2 ls: %ls\n", (wchar_t*) *((void**) p2));
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. data position *p2 lc: %lc\n", *((wchar_t*) *((void**) p2)));
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. BEGIN_OBJECT_JSON_NAME: %ls\n", BEGIN_OBJECT_JSON_NAME);
        fwprintf(stdout, L"Warning: Could not select json value begin. The character is unknown and gets skipped. BEGIN_OBJECT_JSON_NAME_COUNT: %i\n", *BEGIN_OBJECT_JSON_NAME_COUNT);

        // Increment the current position by one.
        move(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
