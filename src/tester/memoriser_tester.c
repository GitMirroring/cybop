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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORISER_TESTER
#define MEMORISER_TESTER

#include <wchar.h>

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/modifier/copier/array_copier.c"
#include "../executor/modifier/copier/item_copier.c"
#include "../executor/modifier/copier/part_copier.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/allocator/item_allocator.c"
#include "../executor/memoriser/allocator/part_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"
#include "../executor/memoriser/deallocator/item_deallocator.c"
#include "../executor/memoriser/deallocator/part_deallocator.c"
#include "../executor/modifier/overwriter/item_overwriter.c"
#include "../executor/modifier/overwriter/part_overwriter.c"
#include "../logger/logger.c"

/**
 * Tests the array resizing.
 */
void test_memoriser_array_resizing() {

    log_write((void*) stdout, L"Test memoriser array resizing:\n");

    // The text.
    wchar_t ta[] = {L't', L'e', L's', L't', L'\n', L'\0'};
    wchar_t* t = ta;
    int* tc = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    // The original array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int os = *tc;
    // The copied array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cs = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate original array.
    allocate_array((void*) &o, (void*) &os, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate copied array.
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Fill original array with text.
    overwrite_array(o, (void*) t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) tc, (void*) &oc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &oc, (void*) &os, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Print original array content.
    log_write((void*) stdout, t);

    // Reallocate copied array.
    os = os + *NUMBER_10_INTEGER_STATE_CYBOI_MODEL;
    reallocate_array((void*) &o, (void*) &oc, (void*) &os, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Print original array content.
    log_write((void*) stdout, t);

    // Deallocate original array.
    deallocate_array((void*) &o, (void*) &os, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate copied array.
    deallocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests the part.
 */
void test_memoriser_part() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test memoriser part.");

    // The part container.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part container.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Fill part container.
    overwrite_part_element(p, (void*) L"test_$0", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) L"Hello, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

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
    copy_array_forward((void*) &n, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &a, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &d, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
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

    // Deallocate part container.
    deallocate_part((void*) &p);
}

/**
 * Tests the item.
 */
void test_memoriser_item() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test memoriser item.");

    // The item container.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate item container.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Fill item container.
    overwrite_item_element(i, (void*) L"Hello, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The item elements retrieved as reference.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get item container elements.
    copy_array_forward((void*) &d, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST item data: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"TEST item count: %i\n", *((int*) c));
    fwprintf(stdout, L"TEST item size: %i\n", *((int*) s));

    // Deallocate item container.
    deallocate_item((void*) &i, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests the array.
 */
void test_memoriser_array() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test array.");

    // The pointer array.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character array.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer array.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &p, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    allocate_array((void*) &w, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_array((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    copy_array_forward(w, (void*) L"Hello, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    copy_array_forward(i, (void*) NUMBER_10000_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // CAUTION! The reference for rubbish (garbage) collection is ONLY set,
    // when using one of the functions: "overwrite", "insert" or "remove".
    // However, for testing as done here, this is NOT needed.
    // Further, it would ONLY have sense when storing parts,
    // since only those have a field called "reference".
    copy_array_forward(p, &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    copy_array_forward(p, &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST p: %i\n", p);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST i: %i\n", *((int*) i));

    // The wide character array retrieved as reference from the pointer array.
    void* wr = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer array retrieved as reference from the pointer array.
    void* ir = *NULL_POINTER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"TEST NULL_POINTER_STATE_CYBOI_MODEL: %i\n", NULL_POINTER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST *NULL_POINTER_STATE_CYBOI_MODEL: %i\n", *NULL_POINTER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST wr: %i\n", wr);
    fwprintf(stdout, L"TEST ir: %i\n", ir);

    copy_array_forward((void*) &wr, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
    copy_array_forward((void*) &ir, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"TEST NULL_POINTER_STATE_CYBOI_MODEL: %i\n", NULL_POINTER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST *NULL_POINTER_STATE_CYBOI_MODEL: %i\n", *NULL_POINTER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST wr: %i\n", wr);
    fwprintf(stdout, L"TEST ir: %i\n", ir);
    fwprintf(stdout, L"TEST *wr: %ls\n", (wchar_t*) wr);
    fwprintf(stdout, L"TEST *ir: %i\n", *((int*) ir));

    deallocate_array((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    deallocate_array((void*) &w, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_array((void*) &p, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
}

/**
 * Tests the wide character array.
 */
void test_memoriser_array_wide_character() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test wide character array.");

    // The wide character array.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &w, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Copy wide characters with zero indices.
    // This is identical to the following simplified function call:
    // copy_array_forward(a, L"Hello, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
    copy_array_forward(w, (void*) L"Hello, World!", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different destination index.
    copy_array_forward(w, (void*) L"again", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different source index.
    copy_array_forward(w, (void*) L"blublablublaHehooblubla", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different destination- and source index.
    copy_array_forward(w, (void*) L"xxxxxxxxxxxlloxxxxxxx", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    deallocate_array((void*) &w, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests the memoriser.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_memoriser() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test memoriser.");

//    test_memoriser_array_resizing();

//    test_memoriser_part();
//    test_memoriser_item();
//    test_memoriser_array();
//    test_memoriser_array_wide_character();
}

/* MEMORISER_TESTER */
#endif
