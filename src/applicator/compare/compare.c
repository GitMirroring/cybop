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
// Library interface
//

#include "applicator.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Compares left and right operand.
 *
 * Lexicographical flag:
 * 0 == FALSE for "compare" operations, resulting in standard comparison
 * 1 == TRUE for "check" operations, resulting in lexicographical comparison
 *
 * The flag gets set in file "operation_handler.c", depending on the given operation.
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

    //
    // Declaration
    //

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

    // The result part type, model item.
    void* rt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part type, model item.
    void* lot = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part type, model item.
    void* rot = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left index part model item.
    void* lim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right index part model item.
    void* rim = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part type, model item data, count.
    void* rtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part type, model item data, count.
    void* lotd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lomc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part type, model item data, count.
    void* rotd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* romc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left index part model item data.
    void* limd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right index part model item data.
    void* rimd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

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

    // Get result part type, model item.
    copy_array_forward((void*) &rt, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get left operand part type, model item.
    copy_array_forward((void*) &lot, lo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lom, lo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right operand part type, model item.
    copy_array_forward((void*) &rot, ro, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rom, ro, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get left index part model item.
    copy_array_forward((void*) &lim, li, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right index part model item.
    copy_array_forward((void*) &rim, ri, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part type, model item data, count.
    copy_array_forward((void*) &rtd, rt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get left operand part type, model item data, count.
    copy_array_forward((void*) &lotd, lot, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lomc, lom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get right operand part type, model item data, count.
    copy_array_forward((void*) &rotd, rot, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &romc, rom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get left index part model item data.
    copy_array_forward((void*) &limd, lim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get right index part model item data.
    copy_array_forward((void*) &rimd, rim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // The default values.
    int type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int left_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int right_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    // Use the left operand part type data by default.
    copy_integer((void*) &type, lotd);
    // Use the left operand part model count by default.
    copy_integer((void*) &count, lomc);
    // Determine minimum of left and right operand.
    calculate_integer_minimum((void*) &count, romc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the given left index.
    copy_integer((void*) &left_index, limd);
    // Use the given right index.
    copy_integer((void*) &right_index, rimd);

    //
    // Functionality
    //

    // Compare left- and right operand type.
    apply_compare_result(rmd, lo, ro, p5, (void*) &type, (void*) &count, (void*) &left_index, (void*) &right_index, rmc, p6, rotd, rtd);
}
