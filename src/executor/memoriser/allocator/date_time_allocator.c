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

#ifndef DATE_TIME_ALLOCATOR_SOURCE
#define DATE_TIME_ALLOCATOR_SOURCE

#include "../../../constant/type/cybol/text_cybol_type.c"
#include "../../../constant/type/memory/memory_type.c"
#include "../../../constant/type/memory/memory_type.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Allocates the date time.
 *
 * It consists of the following parts:
 * year (y)
 * month (m)
 * day (d)
 * hour (h)
 * minute (m)
 * second (s)
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_date_time(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate date time.");

    allocate_array(p0, p1, (void*) INTEGER_MEMORY_TYPE);
}

/* DATE_TIME_ALLOCATOR_SOURCE */
#endif
