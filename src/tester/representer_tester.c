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

#ifndef REPRESENTER_TESTER
#define REPRESENTER_TESTER

#include <stdio.h>
#include <stdlib.h>

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/modifier/copier/array_copier.c"
#include "../executor/memoriser/allocator/item_allocator.c"
#include "../executor/memoriser/deallocator/item_deallocator.c"
#include "../executor/modifier/overwriter/item_overwriter.c"
#include "../executor/representer/deserialiser.c"
//?? #include "../executor/representer/serialiser.c"

/**
 * Tests the representer number byte.
 */
void test_representer_number_byte() {

    fwprintf(stdout, L"TEST representer number byte.\n");

    // The destination item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination item data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source byte sequence with just one single number.
    void* sd = (void*) L"123";
    int sc = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;
    // The source byte sequence with many single byte elements.
//??    void* sd = (void*) L"1,2,3";
//??    int sc = *NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);

    deserialise(d, *NULL_POINTER_STATE_CYBOI_MODEL, sd, (void*) &sc, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

    // Get destination item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST representer number byte dc: %i\n", *((int*) dc));
    fwprintf(stdout, L"TEST representer number byte dd as char: %c\n", *((char*) dd));
    fwprintf(stdout, L"TEST representer number byte dd as int: %i\n", *((char*) dd));

    // Deallocate destination item.
    deallocate_item((void*) &d, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);
}

/**
 * Tests the representer.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_representer() {

    fwprintf(stdout, L"TEST representer.\n");

    test_representer_number_byte();
}

/* REPRESENTER_TESTER */
#endif
