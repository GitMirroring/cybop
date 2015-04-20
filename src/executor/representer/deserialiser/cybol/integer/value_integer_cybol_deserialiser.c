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

#ifndef VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE
#define VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE

#ifdef WIN32
    #include <windows.h>
#endif

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../../executor/modifier/appender/item_appender.c"
#include "../../../../../executor/modifier/inserter/item_inserter.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the wide character data into an integer value.
 *
 * @param p0 the destination item
 * @param p1 the source wchar_t data
 * @param p2 the source wchar_t count
 * @param p3 the number base:
 *           0 - tries to automatically identify the correct number base
 *           8 - octal, e.g. 083
 *           10 - decimal, e.g. 1234
 *           16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
 * @param p4 the prepend flag (false - append value at destination end; true - prepend value at destination beginning)
 * @param p5 the old destination item count (only needed if prepend flag is true, for insertion; may otherwise be null)
 */
void deserialise_cybol_integer_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* nb = (int*) p3;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol integer value.");

        // The temporary null-terminated string item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The temporary null-terminated string item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate temporary null-terminated string item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &t, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Copy original string to temporary null-terminated string.
        append_item_element(t, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Add null termination character.
        append_item_element(t, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Get temporary null-terminated string item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // The tail variable is useless here and only needed for the string
        // transformation function. If the whole string array consists of
        // many sub strings, separated by space characters, then each sub
        // string gets interpreted as integer number.
        // The tail variable in this case points to the remaining sub string.
        wchar_t* tail = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Transform string to integer value.
        //
        // The third parametre is the number base:
        // 0 - tries to automatically identify the correct number base
        // 8 - octal, e.g. 083
        // 10 - decimal, e.g. 1234
        // 16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
        //
        // If the string is empty, contains only whitespace,
        // or does not contain an initial substring that
        // has the expected syntax for an integer in the
        // specified base, NO conversion is performed.
        // In this case, strtol returns a value of ZERO and
        // the value stored in *tailptr is the value of string.
        // This is ideal for cyboi, since a value of zero is assigned
        // internally, in case the given cybol model string is empty.
        int i = wcstol((wchar_t*) td, &tail, *nb);

        if (errno == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The comparison flag.
            int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &b, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                insert_item_element(p0, (void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            } else {

                append_item_element(p0, (void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol integer value. An error (probably overflow) occured.");
        }

        // Deallocate temporary null-terminated string item.
        deallocate_item((void*) &t, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol integer value. The number base is null.");
    }
}

/* VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE */
#endif
