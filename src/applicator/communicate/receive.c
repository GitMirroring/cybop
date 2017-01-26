/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/communication/receive_communication_logic_cybol_name.c"
#include "../../executor/communicator/receiver.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
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
 * Properties:
 * - channel (required): the channel via which to receive the message (terminal, display, www etc.)
 * - encoding (required): the encoding (utf-8, utf-32 for inline channel etc.)
 * - language (required): the language of the data received (cybol, http_request, xdt etc.)
 * - format (required): the format of the data received (boolean, character, integer etc.)
 * - sender (required): the source from where to receive data, e.g. a file, socket, gui root window
 * - message (required): the model to be filled with the data received
 * - metadata (optional): the source (knowledge template) from where to receive meta data (properties)
 * - blocking (optional): the blocking flag indicating whether or not the read should wait endlessly for data at input
 * - minimum (optional): the minimum number of bytes to be received in one call of the read function
 * - maximum (optional): the maximum number of bytes to be received in one call of the read function
 *
 * Constraints:
 * - binary (optional): the flag indicating whether or not the file should be read in binary mode, i.e. WITHOUT altering any characters or line end cr+lf; the default is text mode
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_receive(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply receive.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The metadata part.
    void* me = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blocking part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part.
    void* mi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part.
    void* ma = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part model, properties item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model, properties item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The metadata part model item.
    void* mem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blocking part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item.
    void* mim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item.
    void* mam = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sender part model, properties item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The metadata part model item data, count.
    void* memd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* memc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blocking part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item data.
    void* mimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item data.
    void* mamd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) CHANNEL_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get encoding part.
    get_part_name((void*) &e, p0, (void*) ENCODING_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ENCODING_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get language part.
    get_part_name((void*) &l, p0, (void*) LANGUAGE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) LANGUAGE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get format part.
    get_part_name((void*) &f, p0, (void*) FORMAT_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) FORMAT_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get sender part.
    get_part_name((void*) &s, p0, (void*) SENDER_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) SENDER_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get message part.
    get_part_name((void*) &m, p0, (void*) MESSAGE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) MESSAGE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get metadata part.
    get_part_name((void*) &me, p0, (void*) METADATA_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) METADATA_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get blocking part.
    get_part_name((void*) &b, p0, (void*) BLOCKING_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) BLOCKING_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get minimum part.
    get_part_name((void*) &mi, p0, (void*) MINIMUM_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) MINIMUM_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get maximum part.
    get_part_name((void*) &ma, p0, (void*) MAXIMUM_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) MAXIMUM_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get language part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sender part model, properties item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sp, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get message part model, properties item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mp, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get metadata part model item.
    copy_array_forward((void*) &mem, me, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get blocking part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get minimum part model item.
    copy_array_forward((void*) &mim, mi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get maximum part model item.
    copy_array_forward((void*) &mam, ma, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get language part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get sender part model, properties item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spd, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spc, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get metadata part model item data, count.
    copy_array_forward((void*) &memd, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &memc, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get blocking part model item data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get minimum part model item data.
    copy_array_forward((void*) &mimd, mim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get maximum part model item data.
    copy_array_forward((void*) &mamd, mam, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default blocking value.
    int blocking = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the explicit blocking value that was given as argument.
    copy_integer((void*) &blocking, bmd);

    receive_data(mm, mp, smd, smc, spd, spc, p2, p3, p4, (void*) &blocking, mimd, mamd, fmd, lmd, emd, cmd);
}

/* RECEIVE_SOURCE */
#endif
