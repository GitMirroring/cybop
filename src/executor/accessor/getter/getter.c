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

#ifndef GETTER_SOURCE
#define GETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/item_getter.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/overwriter/part_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Gets the source part element given by the source part element index
 * as reference copied to the destination pointer array.
 *
 * CAUTION! The parametre p0 does NOT have to be a reference!
 * It points to a memory area to which the source element is copied.
 * If using a local variable, then the memory area is allocated
 * automatically by the function, on the stack.
 *
 * Example:
 *
 * void* part_reference = *NULL_POINTER_STATE_CYBOI_MODEL;
 * get_part_element((void*) &part_reference, whole_part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j, (void*) MODEL_PART_STATE_CYBOI_NAME);
 *
 * @param p0 the destination element part
 * @param p1 the source part
 * @param p2 the operation type
 */
void get(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The source part item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get source part name item.
            copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        }
    }

    // Get source part item data, count.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // CAUTION! If, one day, it is necessary to not only copy a part's name,
    // but also its name, channel, encoding, language, format, type,
    // then just move the following line into the if-else blocks above.
    // The reason is that the name is of type "wchar_t", but the others of type "int",
    // so that different types have to be given as parametre to the "overwrite" function.

    // Copy part name into destination element.
    overwrite_part_element(p0, sd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, sc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
}

/* GETTER_SOURCE */
#endif
