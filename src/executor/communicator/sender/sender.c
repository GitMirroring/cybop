/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Sends the source via the given channel.
 *
 * CAUTION! Do NOT rename this function to "send", since that name is
 * already used by low-level glibc functionality in header file "sys/socket.h".
 * Function: ssize_t send (int socket, const void *buffer, size_t size, int flags)
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the source part (pointer reference), e.g. a signal
 * @param p6 the language properties (constraints) data
 * @param p7 the language properties (constraints) count
 * @param p8 the knowledge memory part (pointer reference)
 * @param p9 the stack memory item
 * @param p10 the internal memory
 * @param p11 the format
 * @param p12 the language
 * @param p13 the encoding
 * @param p14 the channel
 * @param p15 the server flag
 * @param p16 the port
 * @param p17 the output writer handler (pointer reference)
 * @param p18 the asynchronicity flag
 */
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send data.");
    //?? fwprintf(stdout, L"Information: Send data. channel p14: %i\n", p14);
    //?? fwprintf(stdout, L"Information: Send data. channel *p14: %i\n", *((int*) p14));

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compressed character item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The buffer.
    //
    // CAUTION! This is just a helper variable,
    // to be used for forwarding the correct argument.
    //
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The argument data, count.
    //
    // CAUTION! This is just helper variables,
    // to be used for forwarding the correct argument.
    //
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // CAUTION! These items have to get allocated HERE
    // and NOT within the functions called below.
    // Otherwise, they would be deallocated before being used.
    //

    //
    // Allocate serialised wide character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate encoded character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate compressed character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //?? fwprintf(stdout, L"Debug: Send. s: %i\n", s);
    //?? fwprintf(stdout, L"Debug: Send. e: %i\n", e);
    //?? fwprintf(stdout, L"Debug: Send. c: %i\n", c);

    //
    // Initialise buffer.
    //
    // CAUTION! The "wchar_t" buffer is used by default. It applies to
    // languages like for example "text/cybol" and "text/html".
    // Also, text given via "inline" channel is processed as wide characters.
    // Therefore, setting the buffer to "wchar_t" by default IS IMPORTANT.
    //
    b = s;

    //?? fwprintf(stdout, L"Debug: Send. b after s: %i\n", b);

    //
    // Select buffer.
    //
    // CAUTION! Hand over the ENCODED character item and NOT the
    // compressed character item, if wide characters are not wanted.
    // In this case, the encoding is SKIPPED, since it is either
    // not necessary, or the serialisation does it inside.
    //
    send_select((void*) &b, (void*) &e, p12);

    //?? fwprintf(stdout, L"Debug: Send. b after e: %i\n", b);

    //
    // Serialise message.
    //
    // CAUTION! The buffer argument may be of either
    // type "char" or type "wchar_t", which is IRRELEVANT.
    // This function knows how to handle it, depending on the given language.
    //
    send_serialise((void*) &ad, (void*) &ac, b, p1, p2, p3, p4, p6, p7, p8, p9, p10, p0, p11, p12);

    //?? fwprintf(stdout, L"Debug: send data serialise *ac: %i\n", *((int*) ac));
    //?? fwprintf(stdout, L"Debug: send data serialise ad: %s\n", (char*) ad);

    // Encode message.
    send_encode((void*) &ad, (void*) &ac, e, ad, ac, p13);

    //?? fwprintf(stdout, L"Debug: send data encode *ac: %i\n", *((int*) ac));
    //?? fwprintf(stdout, L"Debug: send data encode ad: %s\n", (char*) ad);

    // Compress message.
    //?? send_compress((void*) &ad, (void*) &ac, c, ad, ac, p??);

    //?? fwprintf(stdout, L"Debug: send data compress *ac: %i\n", *((int*) ac));
    //?? fwprintf(stdout, L"Debug: send data compress ad: %s\n", (char*) ad);

    //
    // Write message.
    //
    // CAUTION! Hand over message as POINTER REFERENCE, not just pointer.
    // The pointer is used inside to count sent data due to socket buffer limit.
    //
    send_write(p0, ad, ac, p5, p10, p14, p15, p16, p17, p18);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate compressed character item.
    deallocate_item((void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
