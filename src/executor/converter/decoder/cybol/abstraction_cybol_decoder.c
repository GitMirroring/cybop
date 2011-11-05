/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: abstraction_converter.c,v $ $Revision: 1.17 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_DECODER_SOURCE
#define ABSTRACTION_DECODER_SOURCE

#include "../../../../constant/abstraction/cybol/compare_cybol_abstraction.c"
#include "../../../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
//?? Delete this later. Superfluous since replaced with compare/equal etc.
#include "../../../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/operation_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the abstraction wide character data into an abstraction integer.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_abstraction(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode abstraction.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ASCII_TEXT_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) ASCII_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) INTEGER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) COMPLEX_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) PART_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) FRACTION_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) EQUAL_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) GREATER_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) GREATER_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) GREATER_OR_EQUAL_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) DATETIME_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) INTEGER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PART_EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) PART_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) PART_EQUAL_OPERATION_ABSTRACTION);
        }
    }

    //?? Delete "plain operation" later, as it was replaced with cybol mime types like compare/equal etc.
    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) OPERATION_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) POLAR_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) POLAR_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) COMPLEX_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PREFIX_EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) PREFIX_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) PREFIX_EQUAL_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) SMALLER_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) SMALLER_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) SMALLER_OR_EQUAL_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SUFFIX_EQUAL_COMPARE_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) SUFFIX_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) SUFFIX_EQUAL_OPERATION_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) FRACTION_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p2, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) PART_MEMORY_ABSTRACTION);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode abstraction. The abstraction is unknown.");
    }
}

/* ABSTRACTION_DECODER_SOURCE */
#endif
