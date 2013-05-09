/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
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

    // The single destination item.
    void* d1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The multi destination item.
    void* d2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The single destination item data, count.
    void* d1d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d1c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The multi destination item data, count.
    void* d2d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d2c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The single source data as byte sequence with just one number.
    // CAUTION! Due to the data type, the value has to be in range 0..255.
    void* s1d = (void*) L"104";
    int s1c = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;
    // The multi source data as byte sequence with many byte elements.
    // CAUTION! Due to the data type, the values have to be in range 0..255.
    void* s2d = (void*) L"1,0,4";
    int s2c = *NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    // Allocate single destination item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);
    // Allocate multi destination item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);

    // Deserialise single source data.
    deserialise(d1, *NULL_POINTER_STATE_CYBOI_MODEL, s1d, (void*) &s1c, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);
    // Deserialise multi source data.
    deserialise(d2, *NULL_POINTER_STATE_CYBOI_MODEL, s2d, (void*) &s2c, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

    // Get single destination item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &d1d, d1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &d1c, d1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get multi destination item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &d2d, d2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &d2c, d2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST representer number byte d1c: %i\n", *((int*) d1c));
    fwprintf(stdout, L"TEST representer number byte d1d as char: %c\n", *((char*) d1d));
    fwprintf(stdout, L"TEST representer number byte d1d as int: %i\n", *((char*) d1d));

    fwprintf(stdout, L"TEST representer number byte d2c: %i\n", *((int*) d2c));
    fwprintf(stdout, L"TEST representer number byte d2d element 1 as int: %i\n", *((char*) (d2d + 0)));
    fwprintf(stdout, L"TEST representer number byte d2d element 2 as int: %i\n", *((char*) (d2d + 1)));
    fwprintf(stdout, L"TEST representer number byte d2d element 3 as int: %i\n", *((char*) (d2d + 2)));

    // Deallocate single destination item.
    deallocate_item((void*) &d1, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate multi destination item.
    deallocate_item((void*) &d2, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE);
}

/**
 * Tests the representer.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_representer() {

//    fwprintf(stdout, L"TEST representer.\n");

//    test_representer_number_byte();
}

/* REPRESENTER_TESTER */
#endif
