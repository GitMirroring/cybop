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

#ifndef COPIER_TESTER
#define COPIER_TESTER

/**
 * Tests the part copier.
 *
 * The test tree is to have the following structure.
 * Arabic numbers are used for nodes; roman numbers for properties.
 *
 * [selected_node] | element/part |
 * +-original | element/part |
 * | +-node_1 | element/part |
 * | | +-node_11 | text/plain | pre
 * | | | #-property_11i | text/plain | prop1
 * | | | #-property_11ii | text/plain | prop2
 * | | +-node_12 | element/part |
 * | | | +-node_121 | element/part |
 * | | | | +-node_1211 | text/plain | Hello
 * | | | | +-node_1212 | text/plain | World
 * | | | +-node_122 | text/plain | blu
 * | | | +-node_123 | text/plain | bla
 * | | +-node_13 | text/plain | post
 * | +-node_2 | text/plain | proptree
 * | | #-property_2i | element/part |
 * | | | +-node_2i1 | number/integer | 123
 * | | | | #-property_2i1i | number/integer | 456
 * +-clone | element/part |
 */
void test_copier_part() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test copier part.");

    // The parts (original, clone, nodes, properties).
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n11 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p11i = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p11ii = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n12 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n121 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n1211 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n1212 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n122 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n123 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n13 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p2i = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* n2i1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p2i1i = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate parts.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &o, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n11, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p11i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p11ii, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n12, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n121, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n1211, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n1212, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n122, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n123, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n13, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &p2i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    allocate_part((void*) &n2i1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_part((void*) &p2i1i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_part((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    //
    // Assign name, format, type, model, properties.
    // CAUTION! Assigning the type IS ESSENTIAL for properly
    // deallocating the part and its child parts at shutdown.
    //

    // Assign details of part o.
    overwrite_part_element(o, (void*) L"o", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(o, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(o, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(o, (void*) L"Hello", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    //?? TODO ...

    // Append parts to whole (parent) parts.
    append_part_element(o, (void*) &n1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    //?? TODO ...

    //
    // Get one of two parts from the whole.
    // In this case, the second part (with index 1) is retrieved.
    //

    // The part retrieved as reference.
    void* part = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part elements retrieved as reference.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part elements data, count retrieved as reference.
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part with index 1 from whole.
    get_part_metadata((void*) &part, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part elements.
    copy_array_forward((void*) &n, part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &t, part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &p, part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get part elements data, count retrieved as reference.
    copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST nd: %ls\n", (wchar_t*) nd);
    fwprintf(stdout, L"TEST nc: %i\n", *((int*) nc));
    fwprintf(stdout, L"TEST td: %i\n", *((int*) td));
    fwprintf(stdout, L"TEST tc: %i\n", *((int*) tc));
    fwprintf(stdout, L"TEST md: %ls\n", (wchar_t*) md);
    fwprintf(stdout, L"TEST mc: %i\n", *((int*) mc));
    fwprintf(stdout, L"TEST pd: %i\n", pd);
    fwprintf(stdout, L"TEST pc: %i\n", *((int*) pc));

    //
    // Encode and output part as model diagram.
    //

    test_part_as_model_diagram((void*) L"test_copier_part.txt", w);

    // Deallocate parts.
    deallocate_part((void*) &p1);
    deallocate_part((void*) &p2);
    deallocate_part((void*) &w);
}

/**
 * Tests the copier.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_copier() {

    fwprintf(stdout, L"Test copier.\n");

    test_copier_part();
}

/* COPIER_TESTER */
#endif
