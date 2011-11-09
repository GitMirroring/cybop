/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: integer_converter.c,v $ $Revision: 1.37 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_DECODER_SOURCE
#define INTEGER_DECODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the wide character data into an integer.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * CAUTION! This operation has an integer as result, so a normal integer pointer
 * and NOT an integer pointer reference (integer array) is handed over as p0.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void decode_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* d = (int*) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode integer.");

        // The temporary null-terminated string.
        void* tmp = *NULL_POINTER_MEMORY_MODEL;
        int tmpc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int tmps = *NUMBER_2_INTEGER_MEMORY_MODEL;

        // Allocate temporary null-terminated string.
        allocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_MEMORY_TYPE);

        // Copy original string to temporary null-terminated string.
        overwrite_array((void*) &tmp, p3, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, tmpc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &tmpc, (void*) &tmps, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
        // Add string termination to temporary null-terminated string.
        // The source count is used as index for the termination character.
        overwrite_array((void*) &tmp, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, tmpc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &tmpc, (void*) &tmps, (void*) TRUE_BOOLEAN_MEMORY_MODEL);

        // The tail variable is useless here and only needed for the string
        // transformation function. If the whole string array consists of
        // many sub strings, separated by space characters, then each sub
        // string gets interpreted as integer number.
        // The tail variable in this case points to the remaining sub string.
        wchar_t* tail = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Set integer value.
        //
        // Transform string to integer value.
        // The third parameter is the number base:
        // 0 - tries to automatically identify the correct number base
        // 8 - octal, e.g. 083
        // 10 - decimal, e.g. 1234
        // 16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
        *d = wcstol((wchar_t*) tmp, &tail, *NUMBER_10_INTEGER_MEMORY_MODEL);

        if (errno != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer. An error (probably overflow) occured.");
        }

        // Deallocate temporary null-terminated string.
        deallocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_MEMORY_TYPE);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer. The destination is null.");
    }
}

/* INTEGER_DECODER_SOURCE */
#endif
