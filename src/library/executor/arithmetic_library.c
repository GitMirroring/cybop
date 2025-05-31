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
 * Cybernetics Oriented Programming (CYBOP) <http://www.c"ybop.org/>
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// calculator
//

#include "../../executor/calculator/character/absolute_character_calculator.c"
#include "../../executor/calculator/character/add_character_calculator.c"
#include "../../executor/calculator/character/divide_character_calculator.c"
#include "../../executor/calculator/character/multiply_character_calculator.c"
#include "../../executor/calculator/character/negate_character_calculator.c"
#include "../../executor/calculator/character/subtract_character_calculator.c"
#include "../../executor/calculator/character_calculator.c"

#include "../../executor/calculator/complex/absolute_complex_calculator.c"
#include "../../executor/calculator/complex/add_complex_calculator.c"
#include "../../executor/calculator/complex/cartesian_polar_complex_calculator.c"
#include "../../executor/calculator/complex/divide_complex_calculator.c"
#include "../../executor/calculator/complex/multiply_complex_calculator.c"
#include "../../executor/calculator/complex/polar_cartesian_complex_calculator.c"
#include "../../executor/calculator/complex/subtract_complex_calculator.c"
#include "../../executor/calculator/complex_calculator.c"

#include "../../executor/calculator/double/absolute_double_calculator.c"
#include "../../executor/calculator/double/add_double_calculator.c"
#include "../../executor/calculator/double/divide_double_calculator.c"
#include "../../executor/calculator/double/floor_double_calculator.c"
#include "../../executor/calculator/double/multiply_double_calculator.c"
#include "../../executor/calculator/double/negate_double_calculator.c"
#include "../../executor/calculator/double/normalise_double_calculator.c"
#include "../../executor/calculator/double/power_double_calculator.c"
#include "../../executor/calculator/double/scientific_double_calculator.c"
#include "../../executor/calculator/double/subtract_double_calculator.c"
#include "../../executor/calculator/double_calculator.c"

#include "../../executor/calculator/fraction/add_fraction_calculator.c"
#include "../../executor/calculator/fraction/divide_fraction_calculator.c"
#include "../../executor/calculator/fraction/multiply_fraction_calculator.c"
#include "../../executor/calculator/fraction/reduce_fraction_calculator.c"
#include "../../executor/calculator/fraction/subtract_fraction_calculator.c"
#include "../../executor/calculator/fraction_calculator.c"

#include "../../executor/calculator/integer/absolute_integer_calculator.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/calculator/integer/decrement_integer_calculator.c"
#include "../../executor/calculator/integer/divide_integer_calculator.c"
#include "../../executor/calculator/integer/increment_integer_calculator.c"
#include "../../executor/calculator/integer/maximum_integer_calculator.c"
#include "../../executor/calculator/integer/minimum_integer_calculator.c"
#include "../../executor/calculator/integer/modulo_integer_calculator.c"
#include "../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../executor/calculator/integer/negate_integer_calculator.c"
#include "../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../executor/calculator/integer_calculator.c"

#include "../../executor/calculator/pointer/add_pointer_calculator.c"
#include "../../executor/calculator/pointer/difference_pointer_calculator.c"
#include "../../executor/calculator/pointer/subtract_pointer_calculator.c"
#include "../../executor/calculator/pointer_calculator.c"

#include "../../executor/calculator/array_calculator.c"
#include "../../executor/calculator/calculator.c"
#include "../../executor/calculator/elements_array_calculator.c"
#include "../../executor/calculator/item_calculator.c"
#include "../../executor/calculator/offset_array_calculator.c"
#include "../../executor/calculator/offset_calculator.c"
#include "../../executor/calculator/part_calculator.c"

//
// caster
//

#include "../../executor/caster/array_caster.c"

#include "../../executor/caster/caster.c"

#include "../../executor/caster/character/integer_character_caster.c"
#include "../../executor/caster/character_caster.c"

#include "../../executor/caster/double/integer_double_caster.c"
#include "../../executor/caster/double_caster.c"

#include "../../executor/caster/integer/character_integer_caster.c"
#include "../../executor/caster/integer/double_integer_caster.c"
#include "../../executor/caster/integer_caster.c"

#include "../../executor/caster/item_caster.c"

#include "../../executor/caster/part_caster.c"

//
// checker
//

#include "../../executor/checker/array_checker.c"
#include "../../executor/checker/count_checker.c"
#include "../../executor/checker/operation_checker.c"

//
// comparator
//

#include "../../executor/comparator/array_comparator.c"

#include "../../executor/comparator/character/equal_character_comparator.c"
#include "../../executor/comparator/character/greater_character_comparator.c"
#include "../../executor/comparator/character/greater_or_equal_character_comparator.c"
#include "../../executor/comparator/character/less_character_comparator.c"
#include "../../executor/comparator/character/less_or_equal_character_comparator.c"
#include "../../executor/comparator/character/unequal_character_comparator.c"
#include "../../executor/comparator/character_comparator.c"

#include "../../executor/comparator/comparator.c"

#include "../../executor/comparator/complex/equal_complex_comparator.c"
#include "../../executor/comparator/complex/unequal_complex_comparator.c"
#include "../../executor/comparator/complex_comparator.c"

#include "../../executor/comparator/double/equal_double_comparator.c"
#include "../../executor/comparator/double/greater_double_comparator.c"
#include "../../executor/comparator/double/greater_or_equal_double_comparator.c"
#include "../../executor/comparator/double/less_double_comparator.c"
#include "../../executor/comparator/double/less_or_equal_double_comparator.c"
#include "../../executor/comparator/double/unequal_double_comparator.c"
#include "../../executor/comparator/double_comparator.c"

#include "../../executor/comparator/element_part_comparator.c"

#include "../../executor/comparator/fraction/equal_fraction_comparator.c"
#include "../../executor/comparator/fraction/greater_fraction_comparator.c"
#include "../../executor/comparator/fraction/greater_or_equal_fraction_comparator.c"
#include "../../executor/comparator/fraction/less_fraction_comparator.c"
#include "../../executor/comparator/fraction/less_or_equal_fraction_comparator.c"
#include "../../executor/comparator/fraction/unequal_fraction_comparator.c"
#include "../../executor/comparator/fraction_comparator.c"

#include "../../executor/comparator/index_comparator.c"

#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../executor/comparator/integer_comparator.c"

#include "../../executor/comparator/item_comparator.c"

#include "../../executor/comparator/lexicographical_comparator.c"

#include "../../executor/comparator/offset_array_comparator.c"
#include "../../executor/comparator/offset_comparator.c"

#include "../../executor/comparator/part/equal_part_comparator.c"
#include "../../executor/comparator/part/unequal_part_comparator.c"
#include "../../executor/comparator/part_comparator.c"

#include "../../executor/comparator/pointer/equal_pointer_comparator.c"
#include "../../executor/comparator/pointer/greater_or_equal_pointer_comparator.c"
#include "../../executor/comparator/pointer/greater_pointer_comparator.c"
#include "../../executor/comparator/pointer/less_or_equal_pointer_comparator.c"
#include "../../executor/comparator/pointer/less_pointer_comparator.c"
#include "../../executor/comparator/pointer/unequal_pointer_comparator.c"
#include "../../executor/comparator/pointer_comparator.c"

#include "../../executor/comparator/scalar_count_comparator.c"

#include "../../executor/comparator/vector_comparator.c"
#include "../../executor/comparator/vector_count_comparator.c"

#include "../../executor/comparator/wide_character/equal_wide_character_comparator.c"
#include "../../executor/comparator/wide_character/greater_or_equal_wide_character_comparator.c"
#include "../../executor/comparator/wide_character/greater_wide_character_comparator.c"
#include "../../executor/comparator/wide_character/less_or_equal_wide_character_comparator.c"
#include "../../executor/comparator/wide_character/less_wide_character_comparator.c"
#include "../../executor/comparator/wide_character/unequal_wide_character_comparator.c"
#include "../../executor/comparator/wide_character_comparator.c"

//
// logifier
//

#include "../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../executor/logifier/boolean/nand_boolean_logifier.c"
#include "../../executor/logifier/boolean/nor_boolean_logifier.c"
#include "../../executor/logifier/boolean/not_boolean_logifier.c"
#include "../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../executor/logifier/boolean/xnor_boolean_logifier.c"
#include "../../executor/logifier/boolean/xor_boolean_logifier.c"
#include "../../executor/logifier/boolean_logifier.c"

#include "../../executor/logifier/character/and_character_logifier.c"
#include "../../executor/logifier/character/nand_character_logifier.c"
#include "../../executor/logifier/character/neg_character_logifier.c"
#include "../../executor/logifier/character/nor_character_logifier.c"
#include "../../executor/logifier/character/not_character_logifier.c"
#include "../../executor/logifier/character/or_character_logifier.c"
#include "../../executor/logifier/character/xnor_character_logifier.c"
#include "../../executor/logifier/character/xor_character_logifier.c"
#include "../../executor/logifier/character_logifier.c"

#include "../../executor/logifier/integer/and_integer_logifier.c"
#include "../../executor/logifier/integer/nand_integer_logifier.c"
#include "../../executor/logifier/integer/neg_integer_logifier.c"
#include "../../executor/logifier/integer/nor_integer_logifier.c"
#include "../../executor/logifier/integer/not_integer_logifier.c"
#include "../../executor/logifier/integer/or_integer_logifier.c"
#include "../../executor/logifier/integer/xnor_integer_logifier.c"
#include "../../executor/logifier/integer/xor_integer_logifier.c"
#include "../../executor/logifier/integer_logifier.c"

#include "../../executor/logifier/logifier.c"

//
// manipulator
//

#include "../../executor/manipulator/array_manipulator.c"

#include "../../executor/manipulator/character/check_character_manipulator.c"
#include "../../executor/manipulator/character/clear_character_manipulator.c"
#include "../../executor/manipulator/character/rotate_left_character_manipulator.c"
#include "../../executor/manipulator/character/rotate_right_character_manipulator.c"
#include "../../executor/manipulator/character/set_character_manipulator.c"
#include "../../executor/manipulator/character/shift_left_character_manipulator.c"
#include "../../executor/manipulator/character/shift_right_character_manipulator.c"
#include "../../executor/manipulator/character/toggle_character_manipulator.c"
#include "../../executor/manipulator/character_manipulator.c"

#include "../../executor/manipulator/elements_array_manipulator.c"

#include "../../executor/manipulator/integer/check_integer_manipulator.c"
#include "../../executor/manipulator/integer/clear_integer_manipulator.c"
#include "../../executor/manipulator/integer/rotate_left_integer_manipulator.c"
#include "../../executor/manipulator/integer/rotate_right_integer_manipulator.c"
#include "../../executor/manipulator/integer/set_integer_manipulator.c"
#include "../../executor/manipulator/integer/shift_left_integer_manipulator.c"
#include "../../executor/manipulator/integer/shift_right_integer_manipulator.c"
#include "../../executor/manipulator/integer/toggle_integer_manipulator.c"
#include "../../executor/manipulator/integer_manipulator.c"

#include "../../executor/manipulator/item_manipulator.c"

#include "../../executor/manipulator/offset_value_manipulator.c"

#include "../../executor/manipulator/part_manipulator.c"

#include "../../executor/manipulator/value_manipulator.c"
