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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATETIME_DEALLOCATOR_SOURCE
#define DATETIME_DEALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the datetime.
 *
 * @param p0 the datetime (pointer reference)
 */
void deallocate_datetime(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** dt = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate datetime.");

        // The julian day, julian second.
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get julian day, julian second.
        copy_array_forward((void*) &d, *dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
        copy_array_forward((void*) &s, *dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

        // Deallocate julian day, julian second.
        deallocate_array((void*) &d, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);

        // Deallocate datetime.
        deallocate_array(p0, (void*) DATETIME_STATE_CYBOI_MODEL_COUNT, (void*) DATETIME_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate datetime. The datetime is null.");
    }
}

/* DATETIME_DEALLOCATOR_SOURCE */
#endif
