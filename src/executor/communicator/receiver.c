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

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/communicator/receiver/deallocate_receiver.c"
#include "../../executor/communicator/receiver/decode_receiver.c"
#include "../../executor/communicator/receiver/deserialise_receiver.c"
//?? #include "../../executor/communicator/receiver/extract_receiver.c"
#include "../../executor/communicator/receiver/read_receiver.c"
#include "../../executor/communicator/receiver/select_receiver.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../logger/logger.c"

/**
 * Receives a message via the given channel.
 *
 * CAUTION! Do NOT rename this function to "receive",
 * as that name is already used by low-level socket functionality.
 *
 * Use the "receive" filter pipeline in the following order:
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
 * Therefore, these parametres are obsolete for serial port:  encoding, language, format.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data (e.g. the signal memory item, filename or socket number)
 * @param p3 the source model count
 * @param p4 the source properties data (e.g. the signal memory index)
 * @param p5 the source properties count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the blocking flag
 * @param p10 the minimum number of bytes to be received in one call of the read function
 * @param p11 the maximum number of bytes to be received in one call of the read function
 * @param p12 the format
 * @param p13 the language
 * @param p14 the encoding
 * @param p15 the channel
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive data.");

//?? fwprintf(stdout, L"TEST receive data p15: %i\n", *((int*) p15));

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
    // The buffer.
    // CAUTION! This is just a helper variable,
    // to be used for forwarding the correct argument.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The argument data, count.
    // CAUTION! This is just helper variables,
    // to be used for forwarding the correct argument.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // CAUTION! These items have to get allocated HERE
    // and NOT within the functions called below.
    // Otherwise, they would be deallocated before being used.
    //

    // Allocate pointer message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    // Allocate integer message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) LONG_LONG_INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Allocate compressed message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate serialised message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Initialise buffer.
    // CAUTION! The "char" buffer is used by default.
    // It applies to most channels.
    b = c;

    // Select buffer.
    receive_select((void*) &b, (void*) &p0, (void*) &p, (void*) &i, (void*) &s, p15);
    // Read message.
    receive_read((void*) &ad, (void*) &ac, b, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p15);
    if ((p13 != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) p13) == *BINARY_MESSAGE_STATE_CYBOI_LANGUAGE)) {
//?? fwprintf(stdout, L"TEST receive data read *ac: %i\n", *((int*) ac));
//?? fwprintf(stdout, L"TEST receive data read ad: %s\n", (char*) ad);
//?? fwprintf(stdout, L"TEST receive data read *p14: %i\n", *((int*) p14));
    }
    // Extract message.
//??    receive_extract((void*) &ad, (void*) &ac, e, ad, ac, p??);
    // Decode message.
    receive_decode((void*) &ad, (void*) &ac, s, ad, ac, p14);
    if ((p13 != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) p13) == *BINARY_MESSAGE_STATE_CYBOI_LANGUAGE)) {
//?? fwprintf(stdout, L"TEST receive data decode *ac: %i\n", *((int*) ac));
//?? fwprintf(stdout, L"TEST receive data decode ad: %s\n", (char*) ad);
    }
    // Deserialise message.
    // CAUTION! The buffer argument may be of e.g.
    // type "char" or type "wchar_t" or type "void*", which is IRRELEVANT.
    // This function knows how to handle it, depending on the given language.
    receive_deserialise(p0, p1, ad, ac, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p12, p13);
    if ((p13 != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) p13) == *BINARY_MESSAGE_STATE_CYBOI_LANGUAGE)) {
//?? fwprintf(stdout, L"TEST receive data deserialise *ac: %i\n", *((int*) ac));
//?? fwprintf(stdout, L"TEST receive data deserialise ad: %s\n", (char*) ad);
    }
    // Deallocate display event.
    receive_deallocate(b, p15);

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
