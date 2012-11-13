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

#ifndef SIZE_DETERMINER_SOURCE
#define SIZE_DETERMINER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/pointer_type_size.c"
#include "../../variable/type_size/real_type_size.c"

/**
 * Determines the size of the given type.
 *
 * @param p0 the size
 * @param p1 the type
 */
void determine_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p1;

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Determine size.");

        //
        // datetime
        //

        if (*t == *DATETIME_STATE_CYBOI_TYPE) {

            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part.
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        //
        // element
        //

        } else if (*t == *PART_ELEMENT_STATE_CYBOI_TYPE) {

            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part
            // or when setting the references of a part
            // for rubbish (garbage) collection.
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        //
        // logicvalue
        //

        } else if (*t == *BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        //
        // number
        //

        } else if (*t == *COMPLEX_NUMBER_STATE_CYBOI_TYPE) {

            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part.
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*t == *DOUBLE_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);

        } else if (*t == *FRACTION_NUMBER_STATE_CYBOI_TYPE) {

            // CAUTION! This type IS NEEDED, e.g. when DEEP copying a part.
            // It is actually a pointer array, of which each
            // pointer references a structure element.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*t == *INTEGER_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*t == *UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

        //
        // pointer
        //

        } else if (*t == *POINTER_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        //
        // text
        //

        } else if (*t == *CHARACTER_TEXT_STATE_CYBOI_TYPE) {

            // CAUTION! Using SIGNED character is NOT sufficient!
            // It covers the range -127..+127.
            // But ASCII extended by ISO-8859 occupies the range 0..+255.
            // Therefore, the UNSIGNED character is used here.
            copy_integer(p0, (void*) UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*t == *WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE) {

            copy_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else {

            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not determine size. The type is unknown.");
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not determine size. The type is null.");
    }
}

/* SIZE_DETERMINER_SOURCE */
#endif
