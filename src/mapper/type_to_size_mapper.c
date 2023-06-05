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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

/**
 * Maps the data type to a size.
 *
 * @param p0 the size
 * @param p1 the data type
 */
void map_type_to_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p1;

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map type to size.");
        //

        //
        // datetime
        //

        if (*t == *DATETIME_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) DATETIME_COMPOUND_TYPE_SIZE);

        //
        // duration
        //

        } else if (*t == *DURATION_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) DURATION_COMPOUND_TYPE_SIZE);

        //
        // element
        //

        } else if (*t == *PART_ELEMENT_STATE_CYBOI_TYPE) {

            //
            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part
            // or when setting the references of a part
            // for rubbish (garbage) collection.
            //
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            //
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

/*??
        } else if (*t == *PROPERTY_ELEMENT_STATE_CYBOI_TYPE) {

            //
            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part
            // or when setting the references of a part
            // for rubbish (garbage) collection.
            //
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            //
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);
*/

        //
        // logicvalue
        //

        } else if (*t == *BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        //
        // number
        //

        } else if (*t == *BYTE_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*t == *COMPLEX_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) COMPLEX_COMPOUND_TYPE_SIZE);

        } else if (*t == *FLOAT_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);

        } else if (*t == *FRACTION_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) FRACTION_COMPOUND_TYPE_SIZE);

        } else if (*t == *INTEGER_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*t == *LONG_LONG_INTEGER_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

        //
        // pointer
        //

        } else if (*t == *POINTER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        //
        // socket address
        //

        } else if (*t == *IPV4_SOCKET_ADDRESS_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        } else if (*t == *IPV6_SOCKET_ADDRESS_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        } else if (*t == *LOCAL_SOCKET_ADDRESS_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        //
        // terminal mode
        //

        } else if (*t == *UNIX_TERMINAL_MODE_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) UNIX_TERMINAL_MODE_TYPE_SIZE);

        } else if (*t == *WIN32_CONSOLE_MODE_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) WIN32_CONSOLE_MODE_TYPE_SIZE);

        //
        // text
        //

        } else if (*t == *CHARACTER_TEXT_STATE_CYBOI_TYPE) {

            //
            // CAUTION! Using SIGNED character is NOT sufficient!
            // It covers the range -127..+127.
            // But ASCII extended by ISO-8859 occupies the range 0..+255.
            // Therefore, the UNSIGNED character is used here.
            //
            copy_integer(p0, (void*) UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*t == *WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

        //
        // thread
        //

        } else if (*t == *IDENTIFICATION_THREAD_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) IDENTIFICATION_THREAD_TYPE_SIZE);

        } else if (*t == *MUTEX_THREAD_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) MUTEX_THREAD_TYPE_SIZE);

        //
        // unknown
        //

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            //
            // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map type to size. The type is unknown. This is unproblematic, since the type is set to -1 when not using asynchronous communication with buffer.");
            fwprintf(stdout, L"Warning: Could not map type to size. The type is unknown. The type is unknown. This is unproblematic, since the type is set to -1 when not using asynchronous communication with buffer. *t: %i\n", *t);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map type to size. The type is null.");
        fwprintf(stdout, L"Error: Could not map type to size. The type is null. p1: %i\n", p1);
    }
}
