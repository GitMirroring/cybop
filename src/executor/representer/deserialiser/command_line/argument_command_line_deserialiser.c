/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h>
#include <string.h> // strlen
#include <wchar.h>

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cyboi.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the command line argument.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the test unit
 * @param p4 the terminated log file name item (multibyte character data)
 * @param p5 the command line data (pointer reference)
 * @param p6 the command line index
 */
void deserialise_command_line_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    //
    // log_write((void*) stdout, L"Information: Deserialise command line.\n");
    //

    //
    // The argument data, count.
    //
    // It is handed over as multibyte character array.
    //
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ac = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Get argument data.
    //
    // Example: "--loglevel=error"
    //
    // CAUTION! The command line data handed over are of type char**.
    // This is coming from the "main" function and due to the C standard.
    // Pointer arithmetic differs between a void* and char*.
    // Incrementing by one adds:
    // - for void*: 8 byte (on 64 bit systems) or 4 byte (on 32 bit systems)
    // - for char*: 1 byte
    //
    // However, since the parametre is given as pointer REFERENCE char**,
    // the size of void* (and NOT char*) is used in the called function.
    // Therefore, the function CAN be used without danger,
    // even though the char** gets casted to void** inside.
    //
    // A workaround as the following is NOT necessary:
    // char** tmp1 = (char**) p5;
    // char** tmp2 = tmp1 + (*((int*) p6));
    // ad = (void*) *tmp2;
    //
    copy_array_forward((void*) &ad, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    if (ad != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Get command line argument count (number of characters).
        //
        // CAUTION! There are two possibilities to determine it:
        //
        // 1 Force the user to give it as extra command line parametre
        //   (this would be proper, but not very user-friendly)
        //
        // 2 Rely on the null termination character to determine it
        //   (this is a rather dirty workaround, but the "strlen" function can be used)
        //
        // Possibility 2 is applied here.
        //
        ac = strlen((char*) ad);

        deserialise_command_line_argument_wide(p0, p1, p2, p3, p4, ad, (void*) &ac);

    } else {

        //
        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        //
        log_write((void*) stdout, L"Error: Could not deserialise command line argument. The command line argument is null.\n");
    }
}
