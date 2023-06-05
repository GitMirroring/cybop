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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"

/**
 * Copies the value.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the type
 * @param p3 the deep copying flag
 */
void copy(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy.");
    //

    //?? fwprintf(stdout, L"Debug: Copy. p3: %i\n", p3);

    // The comparison result.
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

            //
            // CAUTION! The type "element/part" IS important for activating
            // the rubbish (garbage) collection when calling modifier functions like:
            // append, empty, fill, insert, overwrite, remove.
            //

            // The comparison result.
            int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Evaluate flag indicating shallow or deep copy.
            compare_integer_unequal((void*) &r2, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r2 == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // This is going to be a SHALLOW COPY.
                //
                // In this case, the destination node POINTER gets OVERWRITTEN.
                // Child nodes are NOT copied, since this is a shallow copy,
                // so that the destination part points to the same children
                // as the original source part.
                //
                // Why is shallow copying necessary?
                //
                // When inserting or removing elements to/from an array,
                // the neighbour elements have to be moved.
                // In these cases, only the pointer to a part is to be copied,
                // but not a part's child parts.
                //
                // Therefore, do NOT offer shallow copying as a property (option)
                // to cybol container operations like "overwrite" or "insert"!
                // Take deep copying AS DEFAULT inside.
                // Otherwise, the knowledge tree might get mixed up, for example
                // with circular references. But it should always be a
                // Directed Acyclic Graph (DAG) with unidirectional references.
                //

                //?? fwprintf(stdout, L"Debug: copy shallow pre: %i\n", r);

                //
                // Copy pointer.
                //
                // CAUTION! Both, the destination- as well as the source value
                // will get interpreted as pointer reference inside.
                //
                copy_pointer(p0, p1);

                //?? fwprintf(stdout, L"Debug: copy shallow post: %i\n", r);

            } else {

                //
                // This is going to be a DEEP COPY, also called CLONING.
                //
                // In this case, the destination node already HAS TO EXIST.
                // Only the source's child nodes are copied to the destination,
                // but the destination part pointer itself is left untouched.
                //
                // Why is deep copying necessary?
                //
                // For copying whole sub trees to another place.
                //

                //?? fwprintf(stdout, L"Debug: copy deep pre: %i\n", r);

                //
                // Copy part.
                //
                // CAUTION! Both, the destination- as well as the source value
                // will get interpreted as pointer reference inside.
                //
                copy_part(p0, p1);

                //?? fwprintf(stdout, L"Debug: copy deep post: %i\n", r);
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

        compare_integer_equal((void*) &r, p2, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

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

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy. The operand type is unknown.");
        //
        fwprintf(stdout, L"Warning: Could not copy. The operand type is unknown. p2: %i\n", p2);
        fwprintf(stdout, L"Warning: Could not copy. The operand type is unknown. *p2: %i\n", *((int*) p2));
    }
}
