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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ARITHMETIC_HEADER
#define ARITHMETIC_HEADER

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// calculator
//

void calculate(void* p0, void* p1, void* p2, void* p3);

void calculate_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void calculate_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4);
void calculate_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void calculate_character(void* p0, void* p1, void* p2);
void calculate_character_absolute(void* p0, void* p1);
void calculate_character_add(void* p0, void* p1);
void calculate_character_divide(void* p0, void* p1);
void calculate_character_multiply(void* p0, void* p1);
void calculate_character_negate(void* p0, void* p1);
void calculate_character_subtract(void* p0, void* p1);

void calculate_complex(void* p0, void* p1, void* p2);
void calculate_complex_absolute(void* p0, void* p1);
void calculate_complex_add(void* p0, void* p1);
void calculate_complex_cartesian_polar(void* p0, void* p1, void* p2, void* p3);
void calculate_complex_divide(void* p0, void* p1);
void calculate_complex_multiply(void* p0, void* p1);
void calculate_complex_polar_cartesian(void* p0, void* p1, void* p2, void* p3);
void calculate_complex_subtract(void* p0, void* p1);

void calculate_double(void* p0, void* p1, void* p2);
void calculate_double_absolute(void* p0, void* p1);
void calculate_double_add(void* p0, void* p1);
void calculate_double_divide(void* p0, void* p1);
void calculate_double_floor(void* p0, void* p1);
void calculate_double_multiply(void* p0, void* p1);
void calculate_double_negate(void* p0, void* p1);
void calculate_double_normalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void calculate_double_power(void* p0, void* p1);
void calculate_double_scientific(void* p0, void* p1, void* p2);
void calculate_double_subtract(void* p0, void* p1);

void calculate_fraction(void* p0, void* p1, void* p2);
void calculate_fraction_add(void* p0, void* p1);
void calculate_fraction_divide(void* p0, void* p1);
void calculate_fraction_multiply(void* p0, void* p1);
void calculate_fraction_reduce(void* p0);
void calculate_fraction_subtract(void* p0, void* p1);

void calculate_integer(void* p0, void* p1, void* p2);
void calculate_integer_absolute(void* p0, void* p1);
void calculate_integer_add(void* p0, void* p1);
void calculate_integer_add_many(void* p0, void* p1);
void calculate_integer_decrement(void* p0, void* p1);
void calculate_integer_divide(void* p0, void* p1);
void calculate_integer_divide_many(void* p0, void* p1);
void calculate_integer_increment(void* p0, void* p1);
void calculate_integer_maximum(void* p0, void* p1);
void calculate_integer_minimum(void* p0, void* p1);
void calculate_integer_modulo(void* p0, void* p1);
void calculate_integer_multiply(void* p0, void* p1);
void calculate_integer_multiply_many(void* p0, void* p1);
void calculate_integer_negate(void* p0, void* p1);
void calculate_integer_subtract(void* p0, void* p1);
void calculate_integer_subtract_many(void* p0, void* p1);

void calculate_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void calculate_offset(void* p0, void* p1, void* p2, void* p3, void* p4);

void calculate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void calculate_pointer(void* p0, void* p1, void* p2);
void calculate_pointer_add(void* p0, void* p1);
void calculate_pointer_difference(void* p0, void* p1, void* p2);
void calculate_pointer_subtract(void* p0, void* p1);

//
// caster
//

void cast(void* p0, void* p1, void* p2, void* p3);

void cast_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void cast_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4);
void cast_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void cast_character(void* p0, void* p1, void* p2);
void cast_character_integer(void* p0, void* p1);

void cast_double(void* p0, void* p1, void* p2);
void cast_double_integer(void* p0, void* p1);

void cast_integer(void* p0, void* p1, void* p2);
void cast_integer_character(void* p0, void* p1);
void cast_integer_double(void* p0, void* p1);

void cast_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void cast_item_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

void cast_offset(void* p0, void* p1, void* p2, void* p3, void* p4);

void cast_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// checker
//

void check_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void check_count(void* p0, void* p1, void* p2);
void check_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// comparator
//

void compare(void* p0, void* p1, void* p2, void* p3, void* p4);

void compare_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void compare_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

void compare_character(void* p0, void* p1, void* p2, void* p3);
void compare_character_equal(void* p0, void* p1, void* p2);
void compare_character_greater(void* p0, void* p1, void* p2);
void compare_character_greater_or_equal(void* p0, void* p1, void* p2);
void compare_character_less(void* p0, void* p1, void* p2);
void compare_character_less_or_equal(void* p0, void* p1, void* p2);
void compare_character_unequal(void* p0, void* p1, void* p2);

void compare_complex(void* p0, void* p1, void* p2, void* p3);
void compare_complex_equal(void* p0, void* p1, void* p2);
void compare_complex_unequal(void* p0, void* p1, void* p2);

void compare_count_scalar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void compare_count_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

void compare_double(void* p0, void* p1, void* p2, void* p3);
void compare_double_equal(void* p0, void* p1, void* p2);
void compare_double_greater(void* p0, void* p1, void* p2);
void compare_double_greater_or_equal(void* p0, void* p1, void* p2);
void compare_double_less(void* p0, void* p1, void* p2);
void compare_double_less_or_equal(void* p0, void* p1, void* p2);
void compare_double_unequal(void* p0, void* p1, void* p2);

void compare_fraction(void* p0, void* p1, void* p2, void* p3);
void compare_fraction_equal(void* p0, void* p1, void* p2);
void compare_fraction_greater(void* p0, void* p1, void* p2);
void compare_fraction_greater_or_equal(void* p0, void* p1, void* p2);
void compare_fraction_less(void* p0, void* p1, void* p2);
void compare_fraction_less_or_equal(void* p0, void* p1, void* p2);
void compare_fraction_unequal(void* p0, void* p1, void* p2);

void compare_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

void compare_integer(void* p0, void* p1, void* p2, void* p3);
void compare_integer_equal(void* p0, void* p1, void* p2);
void compare_integer_greater(void* p0, void* p1, void* p2);
void compare_integer_greater_or_equal(void* p0, void* p1, void* p2);
void compare_integer_less(void* p0, void* p1, void* p2);
void compare_integer_less_or_equal(void* p0, void* p1, void* p2);
void compare_integer_unequal(void* p0, void* p1, void* p2);

void compare_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

void compare_lexicographical(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

void compare_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void compare_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void compare_part_element(void* p0, void* p1, void* p2, void* p3);
void compare_part_equal(void* p0, void* p1, void* p2);
void compare_part_unequal(void* p0, void* p1, void* p2);

void compare_pointer(void* p0, void* p1, void* p2, void* p3);
void compare_pointer_equal(void* p0, void* p1, void* p2);
void compare_pointer_greater(void* p0, void* p1, void* p2);
void compare_pointer_greater_or_equal(void* p0, void* p1, void* p2);
void compare_pointer_less(void* p0, void* p1, void* p2);
void compare_pointer_less_or_equal(void* p0, void* p1, void* p2);
void compare_pointer_unequal(void* p0, void* p1, void* p2);

void compare_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void compare_wide_character(void* p0, void* p1, void* p2, void* p3);
void compare_wide_character_equal(void* p0, void* p1, void* p2);
void compare_wide_character_greater(void* p0, void* p1, void* p2);
void compare_wide_character_greater_or_equal(void* p0, void* p1, void* p2);
void compare_wide_character_less(void* p0, void* p1, void* p2);
void compare_wide_character_less_or_equal(void* p0, void* p1, void* p2);
void compare_wide_character_unequal(void* p0, void* p1, void* p2);

//
// logifier
//

void logify(void* p0, void* p1, void* p2, void* p3);

void logify_boolean(void* p0, void* p1, void* p2);
void logify_boolean_and(void* p0, void* p1);
void logify_boolean_nand(void* p0, void* p1);
void logify_boolean_nor(void* p0, void* p1);
void logify_boolean_not(void* p0);
void logify_boolean_or(void* p0, void* p1);
void logify_boolean_xnor(void* p0, void* p1);
void logify_boolean_xor(void* p0, void* p1);

void logify_character(void* p0, void* p1, void* p2);
void logify_character_and(void* p0, void* p1);
void logify_character_nand(void* p0, void* p1);
void logify_character_neg(void* p0);
void logify_character_nor(void* p0, void* p1);
void logify_character_not(void* p0);
void logify_character_or(void* p0, void* p1);
void logify_character_xnor(void* p0, void* p1);
void logify_character_xor(void* p0, void* p1);

void logify_integer(void* p0, void* p1, void* p2);
void logify_integer_and(void* p0, void* p1);
void logify_integer_nand(void* p0, void* p1);
void logify_integer_neg(void* p0);
void logify_integer_nor(void* p0, void* p1);
void logify_integer_not(void* p0);
void logify_integer_or(void* p0, void* p1);
void logify_integer_xnor(void* p0, void* p1);
void logify_integer_xor(void* p0, void* p1);

//
// manipulator
//

void manipulate_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void manipulate_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4);

void manipulate_character(void* p0, void* p1, void* p2);
void manipulate_character_check(void* p0, void* p1);
void manipulate_character_clear(void* p0, void* p1);
void manipulate_character_rotate_left(void* p0, void* p1);
void manipulate_character_rotate_right(void* p0, void* p1);
void manipulate_character_set(void* p0, void* p1);
void manipulate_character_shift_left(void* p0, void* p1);
void manipulate_character_shift_right(void* p0, void* p1);
void manipulate_character_toggle(void* p0, void* p1);

void manipulate_integer(void* p0, void* p1, void* p2);
void manipulate_integer_check(void* p0, void* p1);
void manipulate_integer_clear(void* p0, void* p1);
void manipulate_integer_rotate_left(void* p0, void* p1);
void manipulate_integer_rotate_right(void* p0, void* p1);
void manipulate_integer_set(void* p0, void* p1);
void manipulate_integer_shift_left(void* p0, void* p1);
void manipulate_integer_shift_right(void* p0, void* p1);
void manipulate_integer_toggle(void* p0, void* p1);

void manipulate_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void manipulate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void manipulate_value(void* p0, void* p1, void* p2, void* p3);
void manipulate_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4);

/* ARITHMETIC_HEADER */
#endif
