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

/*??
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/socket/datagram_socket_receiver.c"
#include "../../../../executor/communicator/receiver/socket/raw_socket_receiver.c"
#include "../../../../executor/communicator/receiver/socket/stream_socket_receiver.c"
#include "../../../../logger/logger.c"

/**
 * Receives message via socket.
 *
 * @param p0 the destination model (pointer reference)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination properties (pointer reference)
 * @param p4 the destination properties count
 * @param p5 the destination properties size
 * @param p6 the source communication partner-connected socket of this system
 * @param p7 the socket communication style model
 * @param p8 the socket communication style model count
 * @param p9 the language
 * @param p10 the language count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void apply_receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply receive socket.");

/*??
    fwprintf(stdout, L"TEST 1 l: %s \n", (wchar_t*) p9);
    fwprintf(stdout, L"TEST 1 lc: %i \n", *((int*) p10));
*/

    // The encoded character array.
    // CAUTION! Its size has to be GREATER than zero, e.g. 1024!
    // Otherwise, there will be no place for the data to be received.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;

    // Allocate encoded character array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &ed, (void*) &es, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Receive message from stream.
    receive_stream_socket((void*) &ed, (void*) &ec, (void*) &es, p6);

    // Deserialise serialised wide character array into destination knowledge model.
    // The http request's parametres are written into the destination compound model.
//??    deserialise(p0, p1, p2, p3, p4, p5, ed, (void*) &ec, p9, p10);

    // Deallocate encoded character array.
    deallocate_array((void*) &ed, (void*) &ec, (void*) &es, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //?? TODO: The destination compound model content needs to be RESET every time since
    //?? otherwise, new commands are just added to the "action" part entry, for example.
    //?? Instead, all values should be replaced!

/*??
    fwprintf(stdout, L"TEST 2 l: %s \n", (wchar_t*) p9);
    fwprintf(stdout, L"TEST 2 lc: %i \n", *((int*) p10));
*/

/*??
    // The action name, type, model, properties.
    void** an = NULL_POINTER_STATE_CYBOI_MODEL;
    void** anc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ans = NULL_POINTER_STATE_CYBOI_MODEL;
    void** aa = NULL_POINTER_STATE_CYBOI_MODEL;
    void** aac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** aas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** am = NULL_POINTER_STATE_CYBOI_MODEL;
    void** amc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ams = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ad = NULL_POINTER_STATE_CYBOI_MODEL;
    void** adc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ads = NULL_POINTER_STATE_CYBOI_MODEL;
*/

/*??
    // Get action.
    // It is just one of many possibly parametres that were sensed as
    // http request and added to the compound model above.
    get_universal_compound_element_by_name(
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        *m, p9,
        (void*) SENSE_MODEL_ACTION_NAME, (void*) SENSE_MODEL_ACTION_NAME_COUNT,
        p0, p1);

    fwprintf(stdout, L"TEST 3 bc: %i \n", *((int*) p29));
    fwprintf(stdout, L"TEST 3 bs: %i \n", *((int*) p30));

    if (*am != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The action parametre is NOT null, so it
        // will be used for generating a signal.

    fwprintf(stdout, L"TEST 4 am: %s \n", (wchar_t*) *am);
    fwprintf(stdout, L"TEST 4 amc: %i \n", **((int**) amc));

        // Receive socket signal.
        receive_socket_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, *am, *amc, p23, p26);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive socket message. The action parametre is null.");
    }

    fwprintf(stdout, L"TEST 5 bc: %i \n", *((int*) p29));
    fwprintf(stdout, L"TEST 5 bs: %i \n", *((int*) p30));
*/

    /** The index parametre. */
    static wchar_t INDEX_PARAMETRE_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
    static wchar_t* INDEX_PARAMETRE = INDEX_PARAMETRE_ARRAY;
    static int* INDEX_PARAMETRE_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    // The command name, type, model, properties.
    void** n = NULL_POINTER_STATE_CYBOI_MODEL;
    void** nc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** a = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** as = NULL_POINTER_STATE_CYBOI_MODEL;
    void** m = NULL_POINTER_STATE_CYBOI_MODEL;
    void** mc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** d = NULL_POINTER_STATE_CYBOI_MODEL;
    void** dc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ds = NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    if (p16 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get actual command belonging to the command name.
        // If the name is not known, the command parametre is left untouched.
        get_universal_compound_element_by_name(
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p14, p15,
            p16, p17,
            p0, p1);

    } else {

        // Get default index command, since the given command is null.
        get_universal_compound_element_by_name(
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p14, p15,
            INDEX_PARAMETRE, INDEX_PARAMETRE_COUNT,
            p0, p1);
    }
*/

/*??
    fwprintf(stdout, L"TEST: receive socket signal actual command n: %s \n", (wchar_t*) *n);
    fwprintf(stdout, L"TEST: receive socket signal actual command nc: %i \n", **((int**) nc));
    fwprintf(stdout, L"TEST: receive socket signal actual command a: %s \n", (wchar_t*) *a);
    fwprintf(stdout, L"TEST: receive socket signal actual command ac: %i \n", **((int**) ac));
    fwprintf(stdout, L"TEST: receive socket signal actual command m: %s \n", (wchar_t*) *m);
    fwprintf(stdout, L"TEST: receive socket signal actual command mc: %i \n", **((int**) mc));
    fwprintf(stdout, L"TEST: receive socket signal actual command d: %i \n", *d);
    fwprintf(stdout, L"TEST: receive socket signal actual command dc: %i \n", **((int**) dc));
*/

/*??
    // The communication partner-connected socket of this system
    // (the client socket to accept, receive data from and attach as parametre to the
    // cyboi signal generated later, so that this server may reply to the correct client)
    void** s = NULL_POINTER_STATE_CYBOI_MODEL;

    // Get integer number reference for client socket.
    //
    //?? TODO: Rename this function to a more neutral name later and
    //?? possibly move it away from "signal_memory_accessor.c" into another file.
    set_new_signal_identification((void*) &s, p18);

    fwprintf(stdout, L"TEST: receive socket signal p18: %i \n", *((int*) p18));
    fwprintf(stdout, L"TEST: receive socket signal sock: %i \n", **((int**) s));

    // Set signal into signal memory.
    replace_signal_memory(p3, p4, p5, a, ac, m, mc, d, dc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) s);
*/

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

    //?? TODO: Also store the communication partner-connected socket of this system in internal memory!
    //?? (It is the client socket to accept, receive data from and attach as parametre to the
    //?? cyboi signal generated later, so that this server may reply to the correct client.)
}

/* SOCKET_RECEIVER_SOURCE */
#endif
