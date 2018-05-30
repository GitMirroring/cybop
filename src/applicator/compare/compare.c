/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../../applicator/compare/type_compare.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/comparison/comparison_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Compares left and right operand.
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored (of type boolean)
 * - left (required): the left operand
 * - right (required): the right operand
 * - count (optional): the number of elements to be compared
 * - left index (optional): the left index from where to start the comparison from
 * - right index (optional): the right index from where to start the comparison from
 *
 * 1 Standard comparison
 *
 * Left and right operand as well as the boolean result are treated as vector,
 * i.e. ONE boolean result value is returned PER EACH operand vector element.
 *
 * When comparing single elements, the vectors contain just one single value.
 *
 * Most operand types may be used. For instance, numbers may be given as vectors,
 * e.g. the integer sequence "1,2,3". If using text operands, e.g. "Hello, World!",
 * then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * operation: equal
 * left operand: 10,2,3
 * right operand: 1,2,3
 * result vector: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * operation: equal
 * left operand: 33
 * right operand: 3
 * result value: 0 (which corresponds to "false")
 *
 * 2 Lexicographical comparison
 *
 * Left and right operand may be a vector, but there is ALWAYS
 * just ONE boolean result value ALTOGETHER.
 *
 * Usually, lexicographical comparison applies for text,
 * i.e. strings of type "wide_character" or "character".
 *
 * But also compound parts of type "element/part" may use
 * and set the lexicographical flag to TRUE, so that their
 * contained text nodes are compared lexicographically
 * with deep comparison.
 *
 * Example with text:
 *
 * operation: equal
 * left operand: "Hello"
 * right operand: "World"
 * result value: 0 (which corresponds to "false")
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 * @param p6 the lexicographical flag
 */
void apply_compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply compare.");

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part.
    void* lo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part.
    void* ro = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left index part.
    void* li = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right index part.
    void* ri = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part type item.
    void* lot = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part type item.
    void* rot = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left index part model item.
    void* lim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right index part model item.
    void* rim = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part type item data.
    void* lotd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part type item data.
    void* rotd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left index part model item data.
    void* limd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right index part model item data.
    void* rimd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_COMPARISON_LOGIC_CYBOL_NAME, (void*) RESULT_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get left operand part.
    get_part_name((void*) &lo, p0, (void*) LEFT_COMPARISON_LOGIC_CYBOL_NAME, (void*) LEFT_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get right operand part.
    get_part_name((void*) &ro, p0, (void*) RIGHT_COMPARISON_LOGIC_CYBOL_NAME, (void*) RIGHT_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_COMPARISON_LOGIC_CYBOL_NAME, (void*) COUNT_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get left index part.
    get_part_name((void*) &li, p0, (void*) LEFT_INDEX_COMPARISON_LOGIC_CYBOL_NAME, (void*) LEFT_INDEX_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get right index part.
    get_part_name((void*) &ri, p0, (void*) RIGHT_INDEX_COMPARISON_LOGIC_CYBOL_NAME, (void*) RIGHT_INDEX_COMPARISON_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get left operand part type item.
    copy_array_forward((void*) &lot, lo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get right operand part type item.
    copy_array_forward((void*) &rot, ro, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get left index part model item.
    copy_array_forward((void*) &lim, li, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right index part model item.
    copy_array_forward((void*) &rim, ri, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get left operand part type item data.
    copy_array_forward((void*) &lotd, lot, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get right operand part type item data.
    copy_array_forward((void*) &rotd, rot, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get left index part model item data.
    copy_array_forward((void*) &limd, lim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get right index part model item data.
    copy_array_forward((void*) &rimd, rim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int count = *PRIMITIVE_STATE_CYBOI_MODEL_COUNT;
    int left_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int right_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the left operand part type data by default.
    copy_integer((void*) &type, lotd);
    // Use the given count.
    copy_integer((void*) &count, cmd);
    // Use the given left index.
    copy_integer((void*) &left_index, limd);
    // Use the given right index.
    copy_integer((void*) &right_index, rimd);

    // Compare left- and right operand type.
    apply_compare_type(rmd, lo, ro, p5, (void*) &type, (void*) &count, (void*) &left_index, (void*) &right_index, p6, rotd);
}

/* COMPARE_SOURCE */
#endif
