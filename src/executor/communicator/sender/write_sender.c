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

#ifndef WRITE_SENDER_SOURCE
#define WRITE_SENDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/streamer/writer.c"
#include "../../../logger/logger.c"

/**
 * Writes source to destination.
 *
 * @param p0 the destination item (e.g. filename, client socket number, service identification, gui window id)
 * @param p1 the source model data (pointer reference)
 * @param p2 the source model count
 * @param p3 the source properties data (e.g. signal memory index)
 * @param p4 the source properties count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the source part (pointer reference), e.g. a signal
 * @param p9 the channel
 */
void send_write(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p9 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send write.");

        // Write message.
        write_data(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

    } else {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send write. The channel is null.");
    }
}

/* WRITE_SENDER_SOURCE */
#endif
