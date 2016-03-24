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

#ifndef COMPARATOR_TESTER
#define COMPARATOR_TESTER

/**
 * Tests the ascii character - wide character equality.
 */
void test_comparator_ascii_character() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test comparator ascii character.");
    fwprintf(stdout, L"TEST comparator ascii character.\n");

    char test = 'a';

    if (test == *LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL) {

        log_write((void*) stdout, L"Characters ARE equal.\n");

    } else {

        log_write((void*) stdout, L"Characters are NOT equal.\n");
    }
}

/**
 * Tests the array comparator.
 */
void test_comparator_array() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test comparator array.");
    fwprintf(stdout, L"TEST comparator array.\n");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // All.
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_all_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST all true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_all_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST all false r: %i\n", r);

    // Prefix.
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_prefix_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hell", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST prefix true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_prefix_array((void*) &r, (void*) L"Hello, World!", (void*) L"ello", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST prefix false r: %i\n", r);

    // Suffix.
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_suffix_array((void*) &r, (void*) L"Hello, World!", (void*) L"World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST suffix true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_suffix_array((void*) &r, (void*) L"Hello, World!", (void*) L"World", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST suffix false r: %i\n", r);

    // Subsequence.
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST subsequence complete word true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o, Wor", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST subsequence letters middle true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST subsequence one letter true r: %i\n", r);
    // The following is a crash test.
    // The right array "o" count is too high (100).
    // But since the counts are compared inside,
    // the array boundaries are not crossed and errors prevented.
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_100_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST subsequence count false r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"blubla", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST subsequence different words false r: %i\n", r);

    // Integer equal, smaller or equal, greater.
    int i1 = *NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;
    int* i2 = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST integer equal false r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST integer smaller or equal true r: %i\n", r);
    r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST integer greater false r: %i\n", r);
}

/**
 * Tests the part comparator.
 */
void test_comparator_part() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test comparator part.");
    fwprintf(stdout, L"TEST comparator part.\n");

    // Declare parts.
    void* w1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* w2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* w3 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* w4 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p3 = *NULL_POINTER_STATE_CYBOI_MODEL;
    // Declare comparison results.
    int r1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int r2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int r3 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate parts.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &w1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &w2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &w3, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &w4, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p3, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Initialise parts.
    //

    // Fill whole one.
    overwrite_part_element(w1, (void*) L"one", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill whole two.
    overwrite_part_element(w2, (void*) L"two", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w2, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill whole three.
    overwrite_part_element(w3, (void*) L"three", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w3, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill whole four.
    overwrite_part_element(w4, (void*) L"four", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w4, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) L"Hello, ", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) L"World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Fill part three.
    // CAUTION! This part differs from part two only in its model,
    // which is "World" (WITHOUT exclamation mark) and not "World!"
    overwrite_part_element(p3, (void*) L"bla", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p3, (void*) L"World", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Assign parts to whole one.
    //
    // one | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Set part one at index 0.
    overwrite_part_element(w1, (void*) &p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Insert part two BEFORE part one, at index 0.
    // The part one is moved to index 1 automatically by the "insert_part_element" function.
    insert_part_element(w1, (void*) &p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Copy all parts of whole one into whole two.
    // This is a DEEP COPY.
    //
    // two | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w2, w1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Copy all parts of whole one into whole three.
    // This is a DEEP COPY.
    // Adds a third part to whole three afterwards.
    //
    // three | part
    // bla | wide_character | World!
    // blu | wide_character | Hello,
    // bla | wide_character | World
    //

    // Copy all parts of whole one into whole three.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w3, w1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Insert part three at index 2, so that the
    // whole three contains three parts altogether.
    insert_part_element(w3, (void*) &p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Assign parts to whole four.
    // This is almost identical to the assignment of part one,
    // only that part three is added instead of part two here.
    // Both differ slightly in only one letter of their model.
    //
    // four | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Set part one at index 0.
    overwrite_part_element(w4, (void*) &p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Insert part two BEFORE part one, at index 0.
    // The part one is moved to index 1 automatically by the "insert_part_element" function.
    insert_part_element(w4, (void*) &p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Compare parts:
    // - one and two are equal
    // - one (or two) and three differ in their number of parts
    // - one (or two) and four differ in their model
    //   (wide character array of a contained part)
    //
    compare_all_part((void*) &r1, w1, w2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    compare_all_part((void*) &r2, w1, w3, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    compare_all_part((void*) &r3, w1, w4, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"TEST r1: %i\n", r1);
    fwprintf(stdout, L"TEST r2: %i\n", r2);
    fwprintf(stdout, L"TEST r3: %i\n", r3);

    //
    // Deallocate parts.
    //

    deallocate_part((void*) &p1);
    deallocate_part((void*) &p2);
    deallocate_part((void*) &p3);
    deallocate_part((void*) &w1);
    deallocate_part((void*) &w2);
    deallocate_part((void*) &w3);
    deallocate_part((void*) &w4);
}

/**
 * Tests the pointer comparator.
 */
void test_comparator_pointer() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test comparator pointer.");
    fwprintf(stdout, L"TEST comparator pointer.\n");

    int i = 1;
    int n = 2;
    int p0 = 0;
    void* p1 = (void*) &i;
    void* p2 = (void*) &n;

    fwprintf(stdout, L"left  value: %i\n", p1);
    fwprintf(stdout, L"right value: %i\n", p2);

    p0 = 0;
    compare_pointer((void*) &p0, &p1, &p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"= result: %i\n", p0);

    p0 = 0;
    compare_pointer(&p0, &p1, &p2, (void*) SMALLER_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"< result: %i\n", p0);

    p0 = 0;
    compare_pointer(&p0, &p1, &p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"> result: %i\n", p0);

    p0 = 0;
    compare_pointer(&p0, &p1, &p2, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"<= result: %i\n", p0);

    p0 = 0;
    compare_pointer(&p0, &p1, &p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L">= result: %i\n", p0);

    p0 = 0;
    compare_pointer(&p0, &p1, &p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"<> result: %i\n", p0);
}

/**
 * Tests the double comparator.
 */
void test_comparator_double() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test comparator double.");
    fwprintf(stdout, L"TEST comparator double.\n");

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    fwprintf(stdout, L"left  value: %f\n", l);
    fwprintf(stdout, L"right value: %f\n", r);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"= result: %d\n", res);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) SMALLER_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"< result: %d\n", res);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"> result: %d\n", res);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"<= result: %d\n", res);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L">= result: %d\n", res);

    res = 0;
    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"<> result: %d\n", res);
}



/**
 * Tests the comparator.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_comparator() {

    fwprintf(stdout, L"TEST executor/comparator.\n");
    test_comparator_ascii_character();
    test_comparator_array();
    //test_comparator_part(); //@TODO: segmentation fault!
    fwprintf(stdout, L"TEST segmentation fault for test_comparator_part.\n");
    test_comparator_pointer();
    test_comparator_double();
}

/* COMPARATOR_TESTER */
#endif
