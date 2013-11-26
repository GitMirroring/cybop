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

#ifndef FRACTION_COPIER_SOURCE
#define FRACTION_COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/fraction_state_cyboi_name.c"
#include "../../../executor/accessor/getter/fraction_getter.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Copies the fraction.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_fraction(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy fraction.");

    // The destination numerator, denominator.
    void* dn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source numerator, denominator.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination numerator, denominator.
    get_fraction_element((void*) &dn, (void*) p0, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &dd, (void*) p0, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator, denominator.
    get_fraction_element((void*) &sn, (void*) p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, (void*) p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Copy source- to destination values.
    copy_integer(dn, sn);
    copy_integer(dd, sd);
}

/* FRACTION_COPIER_SOURCE */
#endif
