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

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/communication/send_communication_logic_cybol_name.c"
#include "../../executor/communicator/sender.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
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
 * Properties:
 * - channel (required): the channel via which to send the message (e.g. http)
 * - encoding (optional): the encoding to be used, e.g. ascii; the default is utf-8
 * - language (required): the language into which to serialise the message before sending it (e.g. html, model-diagram etc.)
 * - format (required): the format into which to serialise the message before sending (e.g. element/part, number/integer)
 * - message (required): the source message to be sent to another system
 * - receiver (optional): the destination receiving the message
 * - area (optional, only if type is tui or gui): the user interface area to be repainted
 * - clear (optional, only if type is terminal or tui): the flag indicating whether or not to clear the screen before painting a user interface
 * - newline (optional, only if channel is terminal): the flag indicating whether or not to add a new line after having printed the message on screen
 * - null-termination (optional, only if channel is serial-port): the flag indicating whether or not to add an ascii null termination character '\0' at the end of the (multibyte) message (after encoding)
 *
 * Constraints:
 * - indentation (optional): the flag indicating whether or not the generated message is to be pretty-formatted (e.g. indented html tags)
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory data
 */
void apply_send(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply send.");

    //
    // Properties.
    //

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part (e.g. a filename or socket number).
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The area part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part.
    void* nl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The null termination part.
    void* nt = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model, properties item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model, properties item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part model item.
    void* clm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part model item.
    void* nlm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The null termination part model item.
    void* ntm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model, properties item data, count.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lpc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model, properties item data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mpc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part model item data.
    void* clmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new line part model item data.
    void* nlmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The null termination part model item data.
    void* ntmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_knowledge((void*) &c, p0, (void*) CHANNEL_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) CHANNEL_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get encoding part.
    get_part_knowledge((void*) &e, p0, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get language part.
    get_part_knowledge((void*) &l, p0, (void*) LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get format part.
    get_part_knowledge((void*) &f, p0, (void*) FORMAT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) FORMAT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get message part.
    get_part_knowledge((void*) &m, p0, (void*) MESSAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) MESSAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get receiver part.
    get_part_knowledge((void*) &r, p0, (void*) RECEIVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) RECEIVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get area part.
    get_part_knowledge((void*) &a, p0, (void*) AREA_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) AREA_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get clear flag part.
    get_part_knowledge((void*) &cl, p0, (void*) CLEAR_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) CLEAR_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get new line part.
    get_part_knowledge((void*) &nl, p0, (void*) NEWLINE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) NEWLINE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get null termination part.
    get_part_knowledge((void*) &nt, p0, (void*) NULL_TERMINATION_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) NULL_TERMINATION_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get language part, properties model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lp, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model, properties item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mp, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get receiver part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get clear part model item.
    copy_array_forward((void*) &clm, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get new line part model item.
    copy_array_forward((void*) &nlm, nl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get null termination part model item.
    copy_array_forward((void*) &ntm, nt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get language part model, properties item data, count.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpd, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpc, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get message part model, properties item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpd, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpc, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get clear part model item data.
    copy_array_forward((void*) &clmd, clm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get new line part model item data.
    copy_array_forward((void*) &nlmd, nlm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get null termination part model item data.
    copy_array_forward((void*) &ntmd, ntm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Constraints.
    //

    // The indentation flag part.
    void* li = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The indentation flag part model item.
    void* lim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The indentation flag part model item data.
    void* limd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get indentation flag part.
    get_part_knowledge((void*) &li, lpd, (void*) INDENTATION_LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) INDENTATION_LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, lpc, p2);
    // Get indentation flag part model item.
    copy_array_forward((void*) &lim, li, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get indentation flag part model item data.
    copy_array_forward((void*) &limd, lim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    send_data(rm, mmd, mmc, mpd, mpc, p2, p3, fmd, limd, lmd, emd, (void*) &m, clmd, nlmd, ntmd, cmd);
}

/* SEND_SOURCE */
#endif
