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

#ifndef SOCKET_RECEIVER_SOURCE
#define SOCKET_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Receives message via socket.
 *
 * @param p0 the destination model item
 * @param p3 the destination properties item
 * @param p3 the source socket
 * @param p9 the language
 * @param p11 the knowledge memory
 */
void receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive socket.");

    // The encoded item.
    // CAUTION! Its size has to be GREATER than zero, e.g. 1024!
    // Otherwise, there will be no place for the data to be received.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The buffer.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;

    // Allocate encoded data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &ed, (void*) &es, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Loop until all bytes have been received.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Receive data until buffer is filled.
        receive_socket_buffer((void*) &ed, (void*) &ec, (void*) &es, p6);

        // Append buffer to destination data.
        append_item_element(i, b);
    }

    // Deserialise serialised wide character array into destination knowledge model.
    // The http request's parametres are written into the destination compound model.
    deserialise(p0, p1, p2, p3, p4, p5, ed, (void*) &ec, p9, p10);

    // Deallocate encoded data.
    deallocate_array((void*) &ed, (void*) &ec, (void*) &es, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //?? TODO: The destination compound model content needs to be RESET every time since
    //?? otherwise, new commands are just added to the "action" part entry, for example.
    //?? Instead, all values should be replaced!

    /** The index parametre. */
    static wchar_t INDEX_PARAMETRE_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
    static wchar_t* INDEX_PARAMETRE = INDEX_PARAMETRE_ARRAY;
    static int* INDEX_PARAMETRE_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    // Get default index command, since the given command is null.
    // INDEX_PARAMETRE, INDEX_PARAMETRE_COUNT,

/*??
    // The url basename.
    wchar_t* url_basename = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int url_basename_count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Create url basename.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Get url base name.
    receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

    // The parametre.
    wchar_t* param = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int param_count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Create paramater.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &param, (void*) &param_count, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Get parametres.
    receive_socket_parametre(msg, &msg_count, &param, &param_count);

    // The firefox web browser makes a second request
    // to determine the favicon.
    char firefox_request[] = "favicon.ico";
    wchar_t* p_firefox_request = &firefox_request[*NUMBER_0_INTEGER_STATE_CYBOI_MODEL];
    int firefox_request_count = *NUMBER_11_INTEGER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_all_array((void*) &r, (void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // Close partner socket, since the request was just intended to retrieve the icon.
        close(*ps);

    } else {

        // query string handling
        set_signals_for_all_parametres((void*) param, (void*) &param_count, p0);

        //?? The OLD solution created a signal here from a cybol knowledge template.
        //?? This is NOW easier, since the commands already exist in the knowledge tree
        //?? and only have to be referenced from here.
    }
*/
}

/* SOCKET_RECEIVER_SOURCE */
#endif
