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

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
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
 * the model AND properties are processed TOGETHER, in just one function.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data (e.g. a filename or socket number)
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the knowledge memory part
 * @param p7 the internal memory data
 * @param p8 the minimum number of bytes to be received in one call of the read function
 * @param p9 the maximum number of bytes to be received in one call of the read function
 * @param p10 the format
 * @param p11 the language
 * @param p12 the encoding
 * @param p13 the channel
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive data.");

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
    //
    // CAUTION! The "char" buffer is used by default.
    // It applies to all channels except "inline".
    b = c;

    // Select buffer.
    //
    // CAUTION! This is important for models which are already
    // available as "wchar_t", i.e. those given via channel "inline".
    // These do NOT have to get decoded below.
    //
    // CAUTION! Using the given "encoding" parametre is NOT helpful, since:
    // - for "inline" channel: it is NULL, but "wchar_t" is needed for sending;
    // - for "text/html" language: it is NOT NULL, and "char" is needed for sending.
    // Therefore, the correct buffer gets selected via CHANNEL here.
    //
    receive_select((void*) &b, (void*) &s, p13);
    // Read message.
    receive_read((void*) &ad, (void*) &ac, b, p2, p3, p4, p5, p6, p7, p8, p9, p13);
    // Extract message.
//??    receive_extract((void*) &ad, (void*) &ac, e, ad, ac, p??);
    // Decode message.
    receive_decode((void*) &ad, (void*) &ac, s, ad, ac, p12);
    // Deserialise message.
    //
    // CAUTION! The buffer argument may be of either
    // type "char" or type "wchar_t", which is IRRELEVANT.
    // This function knows how to handle it, depending on the given language.
    //
    receive_deserialise(p0, p1, ad, ac, p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p10, p11);

    // Deallocate compressed message item.
    deallocate_item((void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded message item.
    deallocate_item((void*) &e, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate serialised message item.
    deallocate_item((void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* RECEIVER_SOURCE */
#endif
