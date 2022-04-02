/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
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

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);

/**
 * Deserialises a cybol source.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the channel data
 * @param p4 the encoding data
 * @param p5 the language data
 * @param p6 the format data
 * @param p7 the encoding item
 */
void deserialise_cybol_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol source.");
    // fwprintf(stdout, L"Debug: Deserialise cybol source. p3: %i\n", p3);
    // fwprintf(stdout, L"Debug: Deserialise cybol source. *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_file(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Leave ENCODING undefined at value "NULL".
            //
            // Since an INLINE model is available already as
            // wchar_t array, decoding it is NOT necessary.
            //

            //
            // Fill part model item taken from cybol source part properties.
            //
            // CAUTION! What is the properties in a parsed xml/cybol file,
            // becomes the model in the cyboi-internal knowledge tree.
            //
            // CAUTION! Use the cybol FORMAT and NOT the cyboi destination type.
            //
            receive_data(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, p5, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol source. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. *p3: %i\n", *((int*) p3));
    }
}

/* SOURCE_CYBOL_DESERIALISER_SOURCE */
#endif
