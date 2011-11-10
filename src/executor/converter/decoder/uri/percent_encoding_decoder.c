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

#ifndef PERCENT_ENCODING_DECODER_SOURCE
#define PERCENT_ENCODING_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

//
// A percent-encoding mechanism is used to represent a data octet in a
// component when that octet's corresponding character is outside the
// allowed set or is being used as a delimiter of, or within, the component.
// A percent-encoded octet is encoded as a character triplet,
// consisting of the percent character "%" followed by the two
// hexadecimal digits representing that octet's numeric value.
//
// Example:
//
// percent-encoding: %20
// binary octet: 00100000
// ABNF: %x20
// US-ASCII: space character (SP)
//

/**
 * Decodes the percent-encoded character data into non-percent-encoded character data.
 *
 * All percent-encoded (escaped) characters are resolved,
 * no matter whether or not they are reserved characters
 * according to the URI specification.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void decode_percent_encoding(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** pos = (void**) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode percent-encoding.");

        // The character value.
        unsigned char v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        /*??
        // Decode integer.
        // A percent-encoding is a hexadecimal value consisting of two digits.
        // Therefore, a size of two is handed over as parameter here.
        decode_integer((void*) &v, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *pos, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
        */

        //
        //?? --- The following code is temporary and should be moved into an own file!
        //

        // The temporary null-terminated string.
        void* tmp = *NULL_POINTER_STATE_CYBOI_MODEL;
        int tmpc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int tmps = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;

        // Allocate temporary null-terminated string.
        allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_MEMORY_TYPE);

        // Copy original string to temporary null-terminated string.
        overwrite_array((void*) &tmp, *pos, (void*) CHARACTER_MEMORY_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, tmpc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        // Add string termination to temporary null-terminated string.
        // The source count is used as index for the termination character.
        overwrite_array((void*) &tmp, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, tmpc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // The tail variable is useless here and only needed for the string
        // transformation function. If the whole string array consists of
        // many sub strings, separated by space characters, then each sub
        // string gets interpreted as integer number.
        // The tail variable in this case points to the remaining sub string.
        char* tail = (char*) *NULL_POINTER_STATE_CYBOI_MODEL;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Set integer value.
        //
        // Transform string to integer value.
        // The third parameter is the number base:
        // 0 - tries to automatically identify the correct number base
        // 8 - octal, e.g. 083
        // 10 - decimal, e.g. 1234
        // 16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
        v = strtol((char*) tmp, &tail, *NUMBER_16_INTEGER_STATE_CYBOI_MODEL);

//??    fwprintf(stdout, L"TEST tmp: %s\n", (char*) tmp);
//??    fwprintf(stdout, L"TEST v: %i\n", v);

        if (errno != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode integer. An error (probably overflow) occured.");
        }

        // Deallocate temporary null-terminated string.
        deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_MEMORY_TYPE);

        //
        //?? --- The code above is temporary and should be moved into an own file!
        //

        overwrite_array(p0, (void*) &v, (void*) CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        move_position(p3, p4, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode percent-encoding. The current position is null.");
    }
}

/* PERCENT_ENCODING_DECODER_SOURCE */
#endif
