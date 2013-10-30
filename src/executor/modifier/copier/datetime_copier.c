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

#ifndef DATETIME_COPIER_SOURCE
#define DATETIME_COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/basic/pointer/add_pointer_calculator.c"
#include "../../../executor/modifier/copier/double_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Copies the datetime.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_datetime(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy datetime.");

    // The destination julian day, julian second.
    // CAUTION! Initialise with destination parametre.
    void* dd = p0;
    void* ds = p0;
    // The source julian day, julian second.
    // CAUTION! Initialise with source parametre.
    void* sd = p1;
    void* ss = p1;
    // The offset memory area for julian day, julian second.
    int od = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int os = od + *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE;

    // Add offset to pointer.
    // CAUTION! The pointer type is needed here, since
    // the result is a pointer to which the offset is added.
    calculate_pointer_add((void*) &dd, (void*) &od);
    calculate_pointer_add((void*) &ds, (void*) &os);
    calculate_pointer_add((void*) &sd, (void*) &od);
    calculate_pointer_add((void*) &ss, (void*) &os);

    // Set source- to destination.
    copy_integer(dd, sd);
    copy_double(ds, ss);
}

/* DATETIME_COPIER_SOURCE */
#endif
