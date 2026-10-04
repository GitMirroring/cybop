/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include "time.h" // time

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Reads the current time into the destination.
 *
 * @param p0 the destination datetime
 */
void read_clock(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read clock.");

    //
    // CAUTION! A standard "int" is too small to capture a time,
    // which is of type "long int".
    // Possibly switch some "int" types within cyboi into "long int"?
    //

    //
    // Get current time of system.
    //
    // CAUTION! In the GNU C Library, time_t is equivalent to long int.
    //
    time_t t = time((time_t*) *NULL_POINTER_STATE_CYBOI_MODEL);
}
