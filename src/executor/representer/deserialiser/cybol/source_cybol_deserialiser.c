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

#ifndef SOURCE_CYBOL_DESERIALISER_SOURCE
#define SOURCE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
//
// CAUTION! Do NOT include file "receiver",
// since it would cause a circular reference.
// Mention the function via forward declaration instead (see below).
// #include "../../../../executor/communicator/receiver/receiver.c"
//
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/cybol/file_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declaration
//

//
// CAUTION! Either of the following two functions may be called here:
// "deserialise_cybol" OR "receive_data".
// However, "deserialise_cybol" is used since it is the shorter path
// and reading from a file is NOT necessary with INLINE channel.
// Further, language properties constraints like decimal separator
// can be handed over DIRECTLY while via "receive_data", they would
// have to be retrieved once again.
//
// void deserialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
// void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
//

void deserialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

/**
 * Deserialises a cybol source.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the language properties (constraints) data
 * @param p4 the language properties (constraints) count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the thousands separator data
 * @param p11 the thousands separator count
 * @param p12 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p13 the format
 * @param p14 the channel
 */
void deserialise_cybol_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol source.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol source. channel p14: %i\n", p14);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol source. channel *p14: %i\n", *((int*) p14));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_file(p0, p1, p2, p3, p4, p5, p6, p7, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Fill part model item taken from cybol source part properties.
            //
            // CAUTION! Use the cybol FORMAT and NOT the cyboi destination type.
            //
            // CAUTION! Hand over an encoding value of NULL by default,
            // since an INLINE model is already available as wide character array,
            // so that decoding it would cause wrong data and processing errors.
            //
            // CAUTION! Either of the following two functions may be called here:
            // "deserialise_cybol" OR "receive_data".
            // However, "deserialise_cybol" is used since it is the shorter path
            // and reading from a file is NOT necessary with INLINE channel.
            // Further, language properties constraints like decimal separator
            // can be handed over DIRECTLY while via "receive_data", they would
            // have to be retrieved once again.
            //
            // receive_data(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p3, p4, p5, p6, p7, p13, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p14);
            // deserialise_cybol(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
            //
            deserialise_cybol(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol source. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. p14: %i\n", p14);
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. *p14: %i\n", *((int*) p14));
    }
}

/* SOURCE_CYBOL_DESERIALISER_SOURCE */
#endif
