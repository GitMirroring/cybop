/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_SOURCE
#define SENSE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/name/cybol/logic/life/sense_life_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/lifeguard/sensor.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Senses an interrupt request happening on the given channel.
 *
 * In order to sense interrupt requests of various devices, special mechanisms
 * for interrupt detection have to be started. To these mechanisms belong:
 * - serial
 * - terminal
 * - display
 * - socket
 *
 * All of them have their own internal signal/ action/ event/ interrupt waiting loops
 * which get (re-)activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi-internal interrupt request by setting the corresponding flag.
 * The cyboi signal checker loop then senses the interrupt and receives the
 * corresponding message via the channel the interrupt belongs to.
 *
 * Expected parametres:
 * - channel (required): the channel via which to receive the message (terminal, www, x-window-system etc.)
 * - id (optional): the service identification if having multiple terminals/displays/sockets etc., e.g. socket port 80; either port or service may be specified; port has higher priority; if missing, zero will be used (first io entry)
 * - service (optional): the network service, e.g. http; either port or service may be specified; port has higher priority; useful only if channel is "socket"
 * - handler (optional): the handler (usually a receive operation) that parses an input and filters out a command that the system is to react to
 * - sender (required): the source where to sense data, e.g. a socket
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory data
 */
void apply_sense(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply sense.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service name part.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service name part model item.
    void* sem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service name part model item data, count.
    void* semd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* semc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_knowledge((void*) &c, p0, (void*) CHANNEL_SENSE_LIFE_LOGIC_CYBOL_NAME, (void*) CHANNEL_SENSE_LIFE_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get service id part.
    get_part_knowledge((void*) &i, p0, (void*) IDENTIFICATION_SENSE_LIFE_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_SENSE_LIFE_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get service name part.
    get_part_knowledge((void*) &se, p0, (void*) SERVICE_SENSE_LIFE_LOGIC_CYBOL_NAME, (void*) SERVICE_SENSE_LIFE_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get handler part.
    get_part_knowledge((void*) &h, p0, (void*) HANDLER_SENSE_LIFE_LOGIC_CYBOL_NAME, (void*) HANDLER_SENSE_LIFE_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get sender part.
    get_part_knowledge((void*) &s, p0, (void*) SENDER_SENSE_LIFE_LOGIC_CYBOL_NAME, (void*) SENDER_SENSE_LIFE_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get service id part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get service name part model item.
    copy_array_forward((void*) &sem, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sender part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get service id part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get service name part model item data, count.
    copy_array_forward((void*) &semd, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semc, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get sender part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    sense(p3, imd, (void*) &h, semd, semc, cmd);
}

/* SENSE_SOURCE */
#endif
