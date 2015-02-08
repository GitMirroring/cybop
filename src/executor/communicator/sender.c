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

#ifndef SENDER_SOURCE
#define SENDER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
//?? #include "../../executor/communicator/sender/compress_sender.c"
#include "../../executor/communicator/sender/encode_sender.c"
#include "../../executor/communicator/sender/select_sender.c"
#include "../../executor/communicator/sender/serialise_sender.c"
#include "../../executor/communicator/sender/write_sender.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../logger/logger.c"

/**
 * Sends the source via the given channel.
 *
 * CAUTION! Do NOT rename this function to "send",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! The properties are handed over as well,
 * since the model might also contain meta data.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the knowledge memory part
 * @param p6 the internal memory data
 * @param p7 the format
 * @param p8 the indentation flag
 * @param p9 the language
 * @param p10 the encoding
 * @param p11 the source part (pointer reference)
 * @param p12 the clear flag
 * @param p13 the new line flag
 * @param p14 the null termination flag
 * @param p15 the channel
 */
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send.");

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compressed character item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
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

    // Allocate serialised wide character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate compressed character item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Select buffer.
    // CAUTION! This is important because some models are serialised
    // into "char" (e.g. HTTP due to possible attachments in byte code),
    // but other models into "wchar_t" (e.g. HTML).
    // This may be found out by using the given "encoding" parametre.
    // If a model got serialised into "wchar_t", then that yet
    // has to get text-encoded below, into a byte format.
    send_select((void*) &b, (void*) &e, (void*) &s, p10);
    // Serialise message.
    //
    // CAUTION! The buffer argument may be of either
    // type "char" or type "wchar_t", which is IRRELEVANT.
    // The latter applies when a character encoding has been given.
    // The function "serialise" knows how to handle it,
    // depending on the given language.
    //
    send_serialise((void*) &ad, (void*) &ac, b, p1, p2, p3, p4, p5, p6, p12, p13, p7, p8, p9);
    // Encode message.
    send_encode((void*) &ad, (void*) &ac, e, ad, ac, p10);
    // Compress message.
//??    send_compress((void*) &ad, (void*) &ac, c, ad, ac, p??);
    // Write message.
    // CAUTION! Hand over message as POINTER REFERENCE, not just pointer.
    // The pointer is used inside to count sent data due to socket buffer limit.
    send_write(p0, (void*) &ad, ac, p6, p11, p15);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate compressed character item.
    deallocate_item((void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SENDER_SOURCE */
#endif
