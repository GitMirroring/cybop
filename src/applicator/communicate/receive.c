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

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../../executor/communicator/receiver.c"
#include "../../executor/modifier/name_getter/array_name_getter.c"
#include "../../logger/logger.c"

/**
 * Receives a message via the given channel.
 *
 * CAUTION! Do NOT rename this function to "receive",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "read",
 * as that name is already used for glibc library's input.
 *
 * CAUTION! Some file formats (like the German xDT format for medical data exchange)
 * contain both, the model AND the properties, in one file. To cover these cases,
 * the model AND properties are received TOGETHER, in just one operation.
 *
 * Expected parametres:
 * - channel (required): the channel via which to receive the message (terminal, www, x_window_system etc.)
 * - encoding (required): the encoding (utf-8, utf-32 for inline channel etc.)
 * - type (required): the language (type, type, structure) of the data received (http_request, xdt, boolean, character etc.)
 * - message (required): the source (knowledge template) from where to receive data
 * - meta message (optional): the source (knowledge template) from where to receive meta data (properties)
 * - model (required): the compound model to be filled with the data received
 * - properties (required): the compound properties to be filled with the data received
 * - root (required): the knowledge model that will serve as the root
 * - style (optional, only if channel is www, cyboi or similar): the style of socket communication
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void apply_receive(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply receive.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part (containing the format type, NOT runtime cyboi type).
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    // CAUTION! If a file is read, then this is the file name.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part.
    void* me = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part model.
    void* mem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part model, properties.
    void* mom = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mop = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part model.
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model data, count.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part model data, count.
    void* memd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* memc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part model data, count.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part model data, count.
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_name_array((void*) &c, p0, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get encoding part.
    get_name_array((void*) &e, p0, (void*) ENCODING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ENCODING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get type part.
    get_name_array((void*) &t, p0, (void*) TYPE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) TYPE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get message part.
    get_name_array((void*) &m, p0, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get meta message part.
    get_name_array((void*) &me, p0, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get model part.
    get_name_array((void*) &mo, p0, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get root part.
    get_name_array((void*) &r, p0, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket communication style part.
    get_name_array((void*) &st, p0, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get channel part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get meta message part model.
    copy_array_forward((void*) &mem, me, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get model part model, properties.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mop, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get root part model.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket communication style part model.
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get type part model data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get message part model data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get meta message part model data, count.
    copy_array_forward((void*) &memd, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &memc, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get root part model data, count.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket communication style part model data, count.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stmc, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    receive_data(mom, mop, mmd, mmc, tmd, emd, p3, cmd);
}

/* RECEIVE_SOURCE */
#endif
