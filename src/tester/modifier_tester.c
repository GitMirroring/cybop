/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODIFIER_TESTER
#define MODIFIER_TESTER

#include <wchar.h>

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/communicator/sender/file/stream_file_sender.c"
#include "../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../executor/modifier/copier/array_copier.c"
#include "../executor/modifier/copier/part_copier.c"
#include "../executor/memoriser/allocator/part_allocator.c"
#include "../executor/memoriser/deallocator/part_deallocator.c"
#include "../executor/modifier/inserter/array_inserter.c"
#include "../executor/modifier/overwriter/part_overwriter.c"
#include "../executor/modifier/remover/array_remover.c"
#include "../logger/logger.c"
#include "../tester/part_as_model_diagram_tester.c"

/**
 * Tests part modification on compound part.
 */
void test_modifier_part_compound() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test modifier part compound.");
    fwprintf(stdout, L"Output gets written into file with prefix: %ls\n", L"TEST_");

    //
    // Declare parts.
    //

    void* w1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* w2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* w3 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p2 = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate parts.
    //

    allocate_part((void*) &w1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &w2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &w3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_part((void*) &p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Initialise parts.
    //

    // Fill whole one.
    overwrite_part_element(w1, (void*) L"source", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill whole two.
    overwrite_part_element(w2, (void*) L"shallow", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w2, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill whole three.
    overwrite_part_element(w3, (void*) L"deep", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(w3, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) L"Hello, ", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) L"World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Assign parts to whole one.
    //
    // CAUTION! Hand over reference of p1, p2!
    //
    // CAUTION! Do NOT use the "overwrite_part" or "insert_part" function here,
    // since (void*) &p1 is treated as pointer ARRAY and thus requires one of
    // the two functions "overwrite_part_element" or "insert_part_element"!
    //

    // Set part one at index 0.
    overwrite_part_element(w1, (void*) &p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Insert part two BEFORE part one, at index 0.
    // The part one is moved to index 1 automatically by the "insert_part_element" function.
    insert_part_element(w1, (void*) &p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Add all pointer references of whole one to whole two.
    //
    // This is a SHALLOW COPY.
    // After copying, the elements of whole two should
    // point to the same parts as whole one.
    //
    // CAUTION! This time, the "overwrite_part" and NOT the "overwrite_part_element"
    // function is used, since a part's content is copied to another part.
    // No array is given.
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w2, w1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Copy all parts of whole one into whole three.
    //
    // This is a DEEP COPY.
    // Not the pointer references are copied, but a new part
    // is created for each part read from the source.
    // This function "dives" into the last node of the knowledge hierarchy.
    //
    // The difference to the shallow copy above is that the type
    // PART_ELEMENT_STATE_CYBOI_TYPE is given instead of POINTER_STATE_CYBOI_TYPE.
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w3, w1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Output whole one as model diagram.
    //

    test_part_as_model_diagram((void*) L"TEST_MODIFIER_TESTER_WHOLE_ONE.txt", w1);

    //
    // Output whole two as model diagram.
    //

    test_part_as_model_diagram((void*) L"TEST_MODIFIER_TESTER_WHOLE_TWO.txt", w2);

    //
    // Output whole three as model diagram.
    //

    test_part_as_model_diagram((void*) L"TEST_MODIFIER_TESTER_WHOLE_THREE.txt", w3);

    //
    // Deallocate parts.
    //

    deallocate_part((void*) &p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_part((void*) &p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_part((void*) &w1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    deallocate_part((void*) &w2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    deallocate_part((void*) &w3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
}

/**
 * Tests part modification on wide character array.
 */
void test_modifier_part_wide_character() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test modifier part wide character.");

    // The parts.
    void* p1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p2 = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate parts.
    allocate_part((void*) &p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p1, (void*) L"He, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p2, (void*) L"ABClloXYZ", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Add (model content of) part two to part one.
    //

    insert_part(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

    //
    // Output test results.
    //

    // The part elements retrieved as reference.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part elements data, count retrieved as reference.
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part elements.
    copy_array_forward((void*) &n, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &a, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get part elements data, count retrieved as reference.
    copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ad, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST nd: %ls\n", (wchar_t*) nd);
    fwprintf(stdout, L"TEST nc: %i\n", *((int*) nc));
    fwprintf(stdout, L"TEST ad: %ls\n", (wchar_t*) ad);
    fwprintf(stdout, L"TEST ac: %i\n", *((int*) ac));
    fwprintf(stdout, L"TEST md: %ls\n", (wchar_t*) md);
    fwprintf(stdout, L"TEST mc: %i\n", *((int*) mc));
    fwprintf(stdout, L"TEST dd: %i\n", dd);
    fwprintf(stdout, L"TEST dc: %i\n", *((int*) dc));

    // Deallocate parts.
    deallocate_part((void*) &p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_part((void*) &p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests array modification.
 */
void test_modifier_array() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test modifier array.");

    // The wide character array.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    allocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Append "Hello".
    insert_array((void*) &w, (void*) L"ABCHelloXYZ", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Append "World!".
    insert_array((void*) &w, (void*) L"World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Remove "llo".
    remove_array((void*) &w, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Insert "ho, ".
    insert_array((void*) &w, (void*) L"ho, ", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Append "test" outside, leaving two elements empty.
    // CAUTION! This is NOT shown when printed on screen,
    // since arrays are initialised with the null
    // termination character "\0" by default,
    // so that the "fwprintf" function stops output there.
    insert_array((void*) &w, (void*) L"test", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_20_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    deallocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests the modifier.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_modifier() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test modifier.");

//    test_modifier_part_compound();
//    test_modifier_part_wide_character();
//    test_modifier_array();
}

/* MODIFIER_TESTER */
#endif
