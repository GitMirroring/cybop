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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../../executor/communicator/receiver.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
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
 * - channel (required): the channel via which to receive the message (terminal, www, x_window_system etc.)
 * - encoding (required): the encoding (utf-8, utf-32 for inline channel etc.)
 * - language (required): the language of the data received (cybol, http_request, xdt etc.)
 * - format (required): the format of the data received (boolean, character, integer etc.)
 * - message (required): the source (knowledge template) from where to receive data
 * - meta message (optional): the source (knowledge template) from where to receive meta data (properties)
 * - model (required): the model to be filled with the data received
 * - properties (optional): the properties to be filled with the data received
 * - minimum (optional): the minimum number of bytes to be received in one call of the read function
 * - maximum (optional): the maximum number of bytes to be received in one call of the read function
 * - root (required): the knowledge model that will serve as the root
 * - style (optional, only if channel is www, cyboi or similar): the style of socket communication
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory data
 */
void apply_receive(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply receive.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    // CAUTION! If a file is read, then this is the file name.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part.
    void* me = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part.
    void* mi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part.
    void* ma = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part model item.
    void* mem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part model, properties item.
    void* mom = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mop = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item.
    void* mim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item.
    void* mam = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part model item.
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model item data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The meta message part model item data, count.
    void* memd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* memc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The minimum part model item data.
    void* mimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The maximum part model item data.
    void* mamd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The root part model item data, count.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket communication style part model item data, count.
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_knowledge((void*) &c, p0, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get encoding part.
    get_part_knowledge((void*) &e, p0, (void*) ENCODING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ENCODING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get language part.
    get_part_knowledge((void*) &l, p0, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get format part.
    get_part_knowledge((void*) &f, p0, (void*) FORMAT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) FORMAT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get message part.
    get_part_knowledge((void*) &m, p0, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get meta message part.
    get_part_knowledge((void*) &me, p0, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get model part.
    get_part_knowledge((void*) &mo, p0, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get minimum part.
    get_part_knowledge((void*) &mi, p0, (void*) MINIMUM_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MINIMUM_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get maximum part.
    get_part_knowledge((void*) &ma, p0, (void*) MAXIMUM_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MAXIMUM_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get root part.
    get_part_knowledge((void*) &r, p0, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get socket communication style part.
    get_part_knowledge((void*) &st, p0, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get language part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get meta message part model item.
    copy_array_forward((void*) &mem, me, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get model part model, properties item.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mop, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get minimum part model item.
    copy_array_forward((void*) &mim, mi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get maximum part model item.
    copy_array_forward((void*) &mam, ma, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get root part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket communication style part model item.
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get language part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get message part model item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get meta message part model item data, count.
    copy_array_forward((void*) &memd, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &memc, mem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get minimum part model item data.
    copy_array_forward((void*) &mimd, mim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get maximum part model item data.
    copy_array_forward((void*) &mamd, mam, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get root part model item data, count.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket communication style part model item data, count.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stmc, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
fwprintf(stdout, L"TEST receive cmd: %i\n", *((int*) cmd));
fwprintf(stdout, L"TEST receive lmd: %i\n", *((int*) lmd));
fwprintf(stdout, L"TEST receive fmd: %i\n", *((int*) fmd));
fwprintf(stdout, L"TEST receive motd: %i\n", *((int*) motd));
fwprintf(stdout, L"TEST receive INTEGER_NUMBER_STATE_CYBOI_FORMAT: %i\n", *INTEGER_NUMBER_STATE_CYBOI_FORMAT);
fwprintf(stdout, L"TEST receive mmc: %i\n", *((int*) mmc));
fwprintf(stdout, L"TEST receive mmd*: %i\n", mmd);
fwprintf(stdout, L"TEST receive mmd: %i\n", *((int*) mmd));
*/

/*??
test_item_as_model_diagram((void*) L"TEST_MESSAGE.txt", *NULL_POINTER_STATE_CYBOI_MODEL, mot, mm, mem);
test_item_as_model_diagram((void*) L"TEST_PRE.txt", *NULL_POINTER_STATE_CYBOI_MODEL, mot, mom, mop);
*/

    receive_data(mom, mop, mmd, mmc, mimd, mamd, fmd, lmd, emd, p3, cmd);

/*??
test_item_as_model_diagram((void*) L"TEST_POST.txt", *NULL_POINTER_STATE_CYBOI_MODEL, mot, mom, mop);
*/
}

/* RECEIVE_SOURCE */
#endif
