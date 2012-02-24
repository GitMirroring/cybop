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

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/communication/send_communication_operation_cybol_name.c"
#include "../../executor/communicator/sender.c"
#include "../../executor/modifier/name_getter/array_name_getter.c"
#include "../../logger/logger.c"

/**
 * Sends a message via the given channel.
 *
 * CAUTION! Do NOT rename this function to "send",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used for glibc library's output.
 *
 * Expected parametres:
 * - channel (required): the channel via which to send the message (e.g. http)
 * - encoding (optional): the encoding to be used, e.g. ascii; the default is utf-8
 * - type (required): the language into which to encode the message before sending it (e.g. html)
 * - message (required): the source message to be sent to another system
 * - receiver (optional): the destination receiving the message
 * - mode (optional, only if channel is http): the mode of communication
 * - namespace (optional, only if channel is http): the namespace of the socket
 * - style (optional, only if channel is http): the style of communication
 * - area (optional, only if type is tui or gui): the user interface area to be repainted
 * - clean (optional, only if type is terminal or tui): the flag indicating whether or not to clear the screen before painting a user interface
 * - new_line (optional, only if channel is terminal): the flag indicating whether or not to add a new line after having printed the message on screen
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the internal memory array
 */
void apply_send(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply send.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication mode part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The area part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clean part.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part.
    void* nl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model, properties.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clean part model.
    void* clm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part model.
    void* nlm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model data, count.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* cmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model, properties data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mpc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clean part model data.
    void* clmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part model data.
    void* nlmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_name_array((void*) &c, p0, (void*) CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get encoding part.
    get_name_array((void*) &e, p0, (void*) ENCODING_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ENCODING_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get type part.
    get_name_array((void*) &t, p0, (void*) TYPE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) TYPE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get message part.
    get_name_array((void*) &m, p0, (void*) MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get receiver part.
    get_name_array((void*) &r, p0, (void*) RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get communication mode part.
    get_name_array((void*) &mo, p0, (void*) MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket namespace part.
    get_name_array((void*) &n, p0, (void*) NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket communication style part.
    get_name_array((void*) &st, p0, (void*) STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get area part.
    get_name_array((void*) &a, p0, (void*) AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get clean flag part.
    get_name_array((void*) &cl, p0, (void*) CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get new line part.
    get_name_array((void*) &nl, p0, (void*) NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get channel part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model, properties.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mp, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get receiver part model.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get clean part model.
    copy_array_forward((void*) &clm, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get new line part model.
    copy_array_forward((void*) &nlm, nl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &cmc, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get message part model, properties data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpd, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpc, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get clean part model data.
    copy_array_forward((void*) &clmd, clm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get new line part model data.
    copy_array_forward((void*) &nlmd, nlm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Convert some cybol source data (strings) into cyboi destination data (integer).
    //

    // The destination channel.
    int dc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination encoding.
    int de = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination type cybol form.
    // CAUTION! This is a cyboi integer representing a cybol mime type.
    int dtc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination type cyboi form.
    // CAUTION! This is a cyboi integer representing a cyboi-internal type.
    int dt = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Decode cybol source channel into cyboi destination channel.
    deserialise_cybol_channel((void*) &dc, cmd, cmc);
    // Decode cybol source encoding into cyboi destination encoding.
    deserialise_cybol_encoding((void*) &de, emd, emc);
    // Decode cybol source type into cybol cyboi destination type.
    deserialise_cybol_type((void*) &dtc, tmd, tmc);
    // Decode cybol cyboi destination type into cyboi destination type.
    // CAUTION! A cybol type is of type "wchar_t"; a cyboi-internal type of type "int".
    // Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a cyboi "part".
    // Therefore, the type has to be converted here.
    deserialise_cybol_cyboi_type((void*) &dt, (void*) &dtc);

    // Send data.
    send_data(rm, mmd, mmc, mpd, mpc, (void*) &dt, (void*) &de, p2, m, clmd, nlmd, (void*) &dc);
}

/* SEND_SOURCE */
#endif
