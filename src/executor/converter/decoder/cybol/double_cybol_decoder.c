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

#ifndef DOUBLE_VECTOR_DECODER_SOURCE
#define DOUBLE_VECTOR_DECODER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the wide character data into a double.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data
 * @param p4 the source count
 */
void decode_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL ) {

            void** d = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode double.");

            // The temporary null-terminated string.
            void* tmp = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* tmpc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* tmps = *NULL_POINTER_STATE_CYBOI_MODEL;

            int s = *sc + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

            // Create temporary null-terminated string.
            allocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) &s, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE_COUNT);

            // The index.
            int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Copy original string to temporary null-terminated string.
            overwrite_array(tmp, p3, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p4, (void*) &i, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // This is used as index to set the termination character.
            i = *sc;

            // Add string termination to temporary null-terminated string.
            overwrite_array(tmp, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            wchar_t* tail = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;

            // Transform string to double value.
            // The strtod function recognizes four special input strings.
            // The strings "inf" and "infinity" are converted to @math{@infinity{}},
            // or to the largest representable value if the floating-point format
            // doesn't support infinities.
            // One can prepend a "+" or "-" to specify the sign.
            // Case is ignored when scanning these strings.
            // The strings "nan" and "nan(chars...)" are converted to NaN.
            // Again, case is ignored.
            // If chars... are provided, they are used in some unspecified fashion
            // to select a particular representation of NaN (there can be several).
            double v = wcstod((wchar_t*) tmp, &tail);

            //?? p0 (pointer reference)
            //?? Doesn't p0 need to be reallocated from size 0 to size 1,
            //?? to be able to take the double value?

            // Set double value.
            overwrite_array(p0, (void*) &v, (void*) DOUBLE_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Destroy temporary null-terminated string.
            deallocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) &s, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE_COUNT);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode double. The destination is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode double. The source count is null.");
    }
}

/* DOUBLE_VECTOR_DECODER_SOURCE */
#endif
