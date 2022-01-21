/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/sensor/loop_sensor.c"
#include "../../logger/logger.c"

/**
 * Senses data on the given channel.
 *
 * @param p0 the client entry
 * @param p1 the handler part (pointer reference)
 * @param p2 the sender client (pointer reference)
 * @param p3 the language (pointer reference)
 * @param p4 the channel (pointer reference)
 */
void sense(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");
    //?? fwprintf(stdout, L"Debug: Sense. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Sense. *p0: %i\n", *((int*) p0));

    // The client entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Determine client entry.
    //?? TODO

    // Assign data handed over from cybol application to client entry.
    sense_entry(e, p1, p2, p3, p4, p5, p6, TODO ??);

    // Invoke sense function WITHIN a new thread.
    sense_thread(e);
}

/* SENSOR_SOURCE */
#endif
