/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Sends a message via the given channel.
 *
 * CAUTION! Do NOT rename this function to "send",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used for glibc library's output.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_send(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply send.");

    //
    // Declaration
    //

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The asynchronicity part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The asynchronicity part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The asynchronicity part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) CHANNEL_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get server part.
    get_part_name((void*) &s, p0, (void*) SERVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) SERVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get port part.
    get_part_name((void*) &p, p0, (void*) PORT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) PORT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get receiver part.
    get_part_name((void*) &r, p0, (void*) RECEIVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) RECEIVER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get encoding part.
    get_part_name((void*) &e, p0, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get language part.
    get_part_name((void*) &l, p0, (void*) LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get format part.
    get_part_name((void*) &f, p0, (void*) FORMAT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) FORMAT_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get message part.
    get_part_name((void*) &m, p0, (void*) MESSAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) MESSAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get asynchronicity part.
    get_part_name((void*) &a, p0, (void*) ASYNCHRONICITY_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ASYNCHRONICITY_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get handler part.
    get_part_name((void*) &h, p0, (void*) HANDLER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) HANDLER_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get server part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get receiver part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get language part model, properties item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lp, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model, properties item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mp, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get asynchronicity part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get server part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get receiver part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get language part model, properties item data, count.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpd, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpc, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get message part model, properties item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpd, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mpc, mp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get asynchronicity part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // The type item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    // Set server flag to FALSE (client mode) by default.
    int server = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // Set port to ZERO by default.
    //
    // CAUTION! It IS necessary so that the correct client entry
    // can be found in the DISPLAY server list, which was
    // assigned to port ZERO at service startup.
    //
    int port = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate type item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! Initialise integer items with a size of ONE,
    // in order to avoid later reallocation when overwriting
    // the element and to thus increase efficiency.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Decode cyboi-internal type into cyboi runtime type.
    deserialise_cybol_type(t, fmd);
    //
    // Get type item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    copy_integer((void*) &server, smd);
    copy_integer((void*) &port, pmd);

    //
    // Functionality
    //

    send_data(rm, mmd, mmc, mpd, mpc, (void*) &m, lpd, lpc, p2, p3, p4, fmd, lmd, emd, cmd, (void*) &server, (void*) &port, (void*) &h, amd);

    // Deallocate type item.
    deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}
