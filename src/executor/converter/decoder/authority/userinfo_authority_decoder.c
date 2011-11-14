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

#ifndef USERINFO_AUTHORITY_DECODER_SOURCE
#define USERINFO_AUTHORITY_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/authority/hostname_authority_decoder.c"
#include "../../../../executor/converter/decoder/authority/username_authority_decoder.c"
#include "../../../../executor/converter/selector/authority/userinfo_authority_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the authority userinfo.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_authority_userinfo(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode authority userinfo.");

    // The element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element.
    copy_pointer((void*) &e, p2);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The userinfo separator @ was NOT found.
            // That is, a userinfo and password were not given.
            // The source represents a hostname only,
            // possibly followed by a port number.
            //
            // CAUTION! The parametres p6 and p7 may NOT be used,
            // since their values were counted on and changed
            // inside the "select_authority_userinfo" function.
            // Instead, hand over e and ec. REFERENCES are expected!
            decode_authority_hostname(p0, p1, (void*) &e, (void*) &ec);

            break;
        }

        select_authority_userinfo(p0, p1, (void*) &b, p2, p3);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The userinfo separator @ WAS found.
            // That is, a userinfo was given,
            // possibly followed by a password.
            //
            // In this case, the hostname was already decoded
            // inside the "select_authority_userinfo" function.
            decode_authority_username(p0, p1, (void*) &e, (void*) &ec);

            break;

        } else {

            // Increment element count.
            ec++;
        }
    }
}

/* USERINFO_AUTHORITY_DECODER_SOURCE */
#endif
