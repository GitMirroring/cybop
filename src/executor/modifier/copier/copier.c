/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPIER_SOURCE
#define COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/modifier/copier/character_copier.c"
#include "../../../executor/modifier/copier/complex_copier.c"
// The module "content_part_copier.c" includes inside: part, item, array.
#include "../../../executor/modifier/copier/content_part_copier.c"
#include "../../../executor/modifier/copier/datetime_copier.c"
#include "../../../executor/modifier/copier/duration_copier.c"
#include "../../../executor/modifier/copier/double_copier.c"
#include "../../../executor/modifier/copier/duration_copier.c"
#include "../../../executor/modifier/copier/fraction_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../executor/modifier/copier/wide_character_copier.c"
#include "../../../logger/logger.c"

/**
 * Copies the value.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the type
 * @param p3 the deep copying flag
 */
void copy(void* p0, void* p1, void* p2, void* p3) {

    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy.");

    // The comparison result.
    // CAUTION! It is used instead of if-else statements.
    // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DATETIME_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_datetime(p0, p1);
        }
    }

    //
    // duration
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DURATION_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_duration(p0, p1);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The type "element/part" IS important for activating
            // the rubbish (garbage) collection when calling modifier functions like:
            // append, empty, insert, overwrite, remove.

            // CAUTION! Both, the destination- as well as the source value
            // will get interpreted as pointer reference inside.

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &r, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // This is going to be a DEEP COPY, also called CLONING.

fwprintf(stdout, L"TEST copy deep pre: %i\n", r);
                copy_part_content(p0, p1);
fwprintf(stdout, L"TEST copy deep post: %i\n", r);

            } else {

                // This is going to be a SHALLOW COPY.

                //?? TODO: Just copying the pointer for shallow copy is NOT correct,
                // since it will overwrite the destination element,
                // which is lost and may never be destroyed,
                // not even by the garbage collector, leading to a memory leak.
                // Possible solution: Hand over flag indicating shallow or deep copy.
                // A simple branch may distinguish between the two,
                // Source children have to be processed anyway,
                // but the destination nodes are to be:
                // - created for deep copy
                // - copied (appended) for shallow copy

fwprintf(stdout, L"TEST copy shallow pre: %i\n", r);
                copy_pointer(p0, p1);
fwprintf(stdout, L"TEST copy shallow post: %i\n", r);
            }
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, p1);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_complex(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_double(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_fraction(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, p1);
        }
    }

    //
    // pointer
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) POINTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, p1);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy. The operand type is unknown.");
    }
}

/**
 * Copies the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the index
 */
void copy_offset(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy offset.");

    // The destination value, source value.
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    void* d = p0;
    void* s = p1;

    // Add offset to destination value and source value.
    add_offset((void*) &d, p2, p4);
    add_offset((void*) &s, p2, p4);

    // Copy source- to destination value.
    copy(d, s, p2, p3);
}

/* COPIER_SOURCE */
#endif
