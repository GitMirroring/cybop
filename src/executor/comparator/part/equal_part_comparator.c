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
#include "logger.h"

/**
 * Compares the left- with the right part for equality.
 *
 * It considers the following meta elements: name, type, model, properties.
 *
 * This is DEEP COMPARISON, i.e. all child nodes will be compared as well.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 */
void compare_part_equal(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** r = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** l = (void**) p1;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare part equal.");

            // The left part name, type, model, properties item.
            void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lt = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lp = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part name, type, model, properties item.
            void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rt = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rp = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The left part name, type, model, properties item data, count.
            void* lnc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* ltd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lmc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lpc = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part model item count.
            void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The name, type, model, properties comparison results.
            int nr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int tr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int mr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int pr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get left name, type, model, properties item.
            copy_array_forward((void*) &ln, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lt, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lm, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lp, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            // Get right part name, type, model, properties item.
            copy_array_forward((void*) &rn, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rt, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rm, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rp, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            // Get left part name, type, model, properties item data, count.
            copy_array_forward((void*) &lnc, ln, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &ltd, lt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lpc, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            // Get right part model item count.
            copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            //
            // CAUTION! The following comparisons of type, name, model, properties
            // are nested, in this order.
            //
            // This is to gain more efficiency.
            // As soon as one comparison fails, the others are not processed anymore.
            //

            //
            // Compare left- with right part type item.
            //
            // CAUTION! The last argument (lexicographical flag) is FALSE,
            // since the values to be compared are of primitive type "INTEGER".
            //
            compare_item((void*) &tr, lt, rt, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            //?? fwprintf(stdout, L"Debug: compare part equal 0 tr: %i\n", tr);
            //?? fwprintf(stdout, L"Debug: compare part equal 0 *ltd: %i\n", *((int*) ltd));

            if (tr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The left and right type are identical.
                // This is a PREREQUISITE to comparing the part models below.
                // If using a wrong type for either left or right part model,
                // then severe memory access errors might occur.
                //

                //
                // Compare left- with right part name item.
                //
                // CAUTION! The last argument (lexicographical flag) is TRUE,
                // since the values to be compared are of type "WIDE CHARACTER".
                //
                compare_item((void*) &nr, ln, rn, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, lnc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

/*??
                //?? TEST ONLY
                void* lnd = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* rnd = *NULL_POINTER_STATE_CYBOI_MODEL;
                copy_array_forward((void*) &lnd, ln, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &rnd, rn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                fwprintf(stdout, L"Debug: compare part equal 1 lnd: %ls\n", (wchar_t*) lnd);
                fwprintf(stdout, L"Debug: compare part equal 1 rnd: %ls\n", (wchar_t*) rnd);
                fwprintf(stdout, L"Debug: compare part equal 1 nr: %i\n", nr);
*/

                if (nr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // The default values.
                    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    //
                    // CAUTION! The following values are ONLY copied,
                    // if the source value is NOT NULL.
                    // This is tested inside the "copy_integer" function.
                    // Otherwise, the destination value remains as is.
                    //

                    // Use the left operand part model count by default.
                    copy_integer((void*) &count, lmc);
                    // Determine minimum of left and right operand.
                    calculate_integer_minimum((void*) &count, rmc);

                    //
                    // Compare left- with right part model item.
                    //
                    // CAUTION! The last argument (lexicographical flag) is TRUE,
                    // since this is a compound part element.
                    // And DEEP comparison of compound parts may always
                    // return just ONE scalar result value.
                    // But this is only the case with lexicographical comparison
                    // and NOT with standard comparison which may return a vector.
                    //
                    compare_item((void*) &mr, lm, rm, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, ltd, (void*) &count, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

/*??
                    //?? TEST ONLY
                    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
                    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                    fwprintf(stdout, L"Debug: compare part equal 2 lmd: %ls\n", (wchar_t*) lmd);
                    fwprintf(stdout, L"Debug: compare part equal 2 rmd: %ls\n", (wchar_t*) rmd);
                    fwprintf(stdout, L"Debug: compare part equal 2 mr: %i\n", mr);

                    fwprintf(stdout, L"Debug: compare part equal lpc: %i\n", lpc);
                    fwprintf(stdout, L"Debug: compare part equal *lpc: %i\n", *((int*) lpc));
*/

                    if (mr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        //
                        // Compare left- with right part properties item.
                        //
                        // CAUTION! The operation EQUAL_COMPARE_LOGIC_CYBOI_FORMAT is always used to compare properties.
                        // The operation type ltd given as argument above is ONLY used to compare models, but not properties.
                        //
                        // CAUTION! The properties are given as part of a compound "part".
                        // Therefore, the operand type is always PART_ELEMENT_STATE_CYBOI_TYPE.
                        //
                        // CAUTION! The last argument (lexicographical flag) is TRUE,
                        // since the properties are always a compound part element.
                        // And DEEP comparison of compound parts may always
                        // return just ONE scalar result value.
                        // But this is only the case with lexicographical comparison
                        // and NOT with standard comparison which may return a vector.
                        //
                        compare_item((void*) &pr, lp, rp, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, lpc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                        //?? fwprintf(stdout, L"Debug: compare part equal 3 pr: %i\n", pr);

                        if (pr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            //
                            // Set final result to TRUE since ALL four comparisons
                            // above (type, name, model, properties) delivered true.
                            //
                            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        }
                    }
                }
            }

            //?? fwprintf(stdout, L"Debug: compare part equal 4 p0: %i\n", p0);
            //?? fwprintf(stdout, L"Debug: compare part equal 4 *p0: %i\n", *((int*) p0));

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.
            //
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part equal. The left part is null.");
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It might use functions that cause circular references.
        //
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part equal. The right part is null.");
    }
}
