/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CHANNEL_SHUTDOWN_MANAGER_SOURCE
#define CHANNEL_SHUTDOWN_MANAGER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/manager/input_output_shutdown_manager.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"
#include "../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Shuts down the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the channel
 */
void manage_shutdown_channel(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage shutdown channel.");
    // fwprintf(stdout, L"Debug: Manage shutdown channel. p1: %i\n", p1);
    // fwprintf(stdout, L"Debug: Manage shutdown channel. *p1: %i\n", *((int*) p1));

    // The internal memory name.
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get internal memory name by channel.
    map_channel_to_internal_memory((void*) &n, p1);
    // Get input output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &n);

    // Shutdown input output entry.
    manage_shutdown_input_output(io, p1, p0);
}

/* CHANNEL_SHUTDOWN_MANAGER_SOURCE */
#endif
