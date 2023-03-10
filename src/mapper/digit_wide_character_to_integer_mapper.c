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

#ifndef DIGIT_WIDE_CHARACTER_TO_INTEGER_MAPPER_SOURCE
#define DIGIT_WIDE_CHARACTER_TO_INTEGER_MAPPER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../executor/comparator/wide_character/equal_wide_character_comparator.c"
#include "../executor/copier/integer_copier.c"
#include "../logger/logger.c"

/**
 * Maps the unicode digit wide character to an integer value.
 *
 * @param p0 the integer value
 * @param p1 the unicode wide character
 */
void map_digit_wide_character_to_integer(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map digit wide character to integer.");
    //?? fwprintf(stdout, L"Debug: Map digit wide character to integer. character p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Map digit wide character to integer. character *p1 as int: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Debug: Map digit wide character to integer. character *p1 as wchar_t: %lc\n", *((wchar_t*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_ONE_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_THREE_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_FOUR_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_FIVE_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_SIX_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_SEVEN_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_EIGHT_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) DIGIT_NINE_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_D_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_14_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_SMALL_LETTER_F_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_15_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_D_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_14_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_wide_character_equal((void*) &r, p1, (void*) LATIN_CAPITAL_LETTER_F_UNICODE_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_15_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map digit wide character to integer. The character is unknown.");
        fwprintf(stdout, L"Warning: Could not map digit wide character to integer. The character is unknown. character p1: %i\n", p1);
        fwprintf(stdout, L"Warning: Could not map digit wide character to integer. The character is unknown. character *p1 as int: %i\n", *((int*) p1));
        fwprintf(stdout, L"Warning: Could not map digit wide character to integer. The character is unknown. character *p1 as wchar_t: %lc\n", *((wchar_t*) p1));
    }
}

/* DIGIT_WIDE_CHARACTER_TO_INTEGER_MAPPER_SOURCE */
#endif
