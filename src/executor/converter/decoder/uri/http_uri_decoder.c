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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_URI_DECODER_SOURCE
#define HTTP_URI_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../executor/converter/decoder/uri/http/authority_http_uri_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the http uri into a part model and -properties.
 *
 * CAUTION! The source character array MUST NOT be given
 * as percent-encoded octets. In other words, it has to
 * have been decoded before being handed over to this function.
 *
 * CAUTION! The source character array MUST NOT be given
 * as sequence of wide characters. Standard octets are expected.
 * The detected parts will get converted to wide characters inside,
 * yet before being added to the destination.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 */
void decode_http_uri(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode http uri.");

    // The source data position.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    decode_http_uri_authority(p0, p1, (void*) &d, (void*) &c);
}

/* HTTP_URI_DECODER_SOURCE */
#endif
