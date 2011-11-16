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

#ifndef HOSTNAME_AUTHORITY_DECODER_SOURCE
#define HOSTNAME_AUTHORITY_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/authority/hostname_authority_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the authority hostname.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_authority_hostname(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode authority hostname.");

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

            break;
        }

        select_authority_hostname(p0, p1, (void*) &b, p2, p3);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment element count.
            ec++;
        }
    }

    //
    // If the hostname-port separator : was NOT found,
    // then no port was given.
    // In this case, the source represents a hostname only.
    //
    // If the hostname-port separator : WAS found,
    // then a port was given.
    // In this case, the port was already decoded
    // inside the "select_authority_hostname" function.
    //

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Fill part.
    overwrite_part_element(p, (void*) CYBOI_HOSTNAME_AUTHORITY_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) CYBOI_HOSTNAME_AUTHORITY_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, e, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) &ec, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Append part to destination model.
    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* HOSTNAME_AUTHORITY_DECODER_SOURCE */
#endif
