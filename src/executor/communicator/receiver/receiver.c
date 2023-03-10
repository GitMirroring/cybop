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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/communicator/receiver/decode_receiver.c"
#include "../../../executor/communicator/receiver/deserialise_receiver.c"
//?? #include "../../../executor/communicator/receiver/extract_receiver.c"
#include "../../../executor/communicator/receiver/read_receiver.c"
#include "../../../executor/communicator/receiver/select_receiver.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/streamer/reader/deallocation_reader.c"
#include "../../../logger/logger.c"

/**
 * Receives a message via the given channel.
 *
 * CAUTION! Do NOT rename this function to "receive", since that name is
 * already used by low-level glibc functionality in header file "sys/socket.h".
 * Function: ssize_t recv (int socket, void *buffer, size_t size, int flags)
 * It is actually the "send" function name which is used in glibc, but
 * in order to be uniform, this "receive" function is renamed as well.
 *
 * Use the "receive" filter processing pipeline in the following order:
 * - read: mandatory, in order to have some data
 * - extract: optional, if compression is given
 * - decode: optional, if encoding is given
 * - deserialise: mandatory, in order to correctly interpret data
 *
 * CAUTION! Some file formats (like the German xDT format for
 * medical data exchange or HTTP request/response) contain both,
 * the model AND the properties, in one file. To cover these cases,
 * the model AND properties are handed over as parametre and processed TOGETHER.
 *
 * Serial port:
 *
 * The multibyte character sequence is NOT decoded into a wide character array,
 * since serial port data are mostly evaluated bytewise within a cybol application.
 * For the same reason, the byte data are NOT deserialised into a cyboi-internal part.
 * Therefore, these parametres are obsolete for serial port: encoding, language, format.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source device identification (e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p3 the source device count
 * @param p4 the source properties data (e.g. the signal memory index)
 * @param p5 the source properties count
 * @param p6 the language properties (constraints) data
 * @param p7 the language properties (constraints) count
 * @param p8 the knowledge memory part (pointer reference)
 * @param p9 the stack memory item
 * @param p10 the internal memory data
 * @param p11 the format
 * @param p12 the language (protocol)
 * @param p13 the encoding
 * @param p14 the asynchronicity flag (true if reading indirectly from buffer; false or null if reading directly from device)
 * @param p15 the service port
 * @param p16 the server flag
 * @param p17 the channel
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive data.");
    //?? fwprintf(stdout, L"Information: Receive data. channel p17: %i\n", p17);
    //?? fwprintf(stdout, L"Information: Receive data. channel *p17: %i\n", *((int*) p17));

    // The pointer message item, e.g. an xcb display event or win32 input record.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer message item, e.g. a datetime or random number.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compressed message item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded message item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised message item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The buffer.
    //
    // CAUTION! This is just a helper variable,
    // to be used for forwarding the correct argument.
    //
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The buffer data, count.
    //
    // CAUTION! This is just helper variables,
    // to be used for forwarding the correct argument.
    //
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // CAUTION! These items have to get allocated HERE
    // and NOT within the functions called below.
    // Otherwise, they would be deallocated before being used.
    //

    //
    // Allocate pointer message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    //
    // Allocate integer message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) LONG_LONG_INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate compressed message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate encoded message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate serialised message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Initialise buffer.
    //
    // CAUTION! The "char" buffer is used by default.
    // It applies to most channels.
    //
    b = c;

    // Select buffer.
    receive_select((void*) &b, (void*) &p0, (void*) &p, (void*) &i, (void*) &s, p17);

    // Read message.
    receive_read((void*) &bd, (void*) &bc, b, p2, p3, p12, p10, p17, p16, p15, p14);

    // Extract message.
    //?? receive_extract((void*) &bd, (void*) &bc, e, bd, bc, p??);

    // Decode message.
    receive_decode((void*) &bd, (void*) &bc, s, bd, bc, p13);

    //
    // Deserialise message.
    //
    // CAUTION! The buffer argument may be of e.g.
    // type "char" or type "wchar_t" or type "void*", which is IRRELEVANT.
    // This function knows how to handle it, depending on the given language.
    //
    receive_deserialise(p0, p1, bd, bc, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    //
    // Deallocate any resources that had been allocated by the system, e.g. an event.
    //
    // CAUTION! Do NOT deallocate the event within function "read_data",
    // since it has to be PROCESSED yet afterwards, e.g. deserialised.
    // Therefore, call function "read_deallocation" ONLY here and not before.
    //
    read_deallocation(bd, bc, *NULL_POINTER_STATE_CYBOI_MODEL, p17);

    // Deallocate pointer message item.
    deallocate_item((void*) &p, (void*) POINTER_STATE_CYBOI_TYPE);
    // Deallocate integer message item.
    deallocate_item((void*) &i, (void*) LONG_LONG_INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate compressed message item.
    deallocate_item((void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded message item.
    deallocate_item((void*) &e, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate serialised message item.
    deallocate_item((void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* RECEIVER_SOURCE */
#endif
