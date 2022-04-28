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

#ifndef CONTENT_JSON_SERIALISER_SOURCE
#define CONTENT_JSON_SERIALISER_SOURCE

#include "../../../../constant/channel/cybol/cybol_channel.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/json/format_json_serialiser.c"
//?? #include "../../../../executor/representer/serialiser/json/indentation_json_serialiser.c"
#include "../../../../executor/representer/serialiser/json/separation_json_serialiser.c"
#include "../../../../executor/representer/serialiser/json/string_json_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations
//

void serialise_json(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_json_part(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Serialises the part element content into json.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source format data
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 * @param p8 the properties flag
 * @param p9 the tree level
 */
void serialise_json_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json content.");
    fwprintf(stdout, L"Debug: Serialise json content. tree level p9: %i\n", p9);
    fwprintf(stdout, L"Debug: Serialise json content. tree level p9: %i\n", *((int*) p9));

    // Append indentation.
    //?? serialise_json_indentation(p0, p8, p9);

    // Append source name.
    serialise_json_string(p0, p1, p2);

    // Append separation.
    serialise_json_separation(p0);

    // Append inline channel by default.
    serialise_json_string(p0, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT);

    // Append separation.
    serialise_json_separation(p0);

    // Append source format.
    serialise_json_format(p0, p3);

    // Append separation.
    serialise_json_separation(p0);

    // Append source model.
    //?? serialise_json(p0, p4, p5, p6, p7, p9, p3);

    // Append separation.
    //?? serialise_json_separation(p0);

    // Append source properties.
    //?? serialise_json_part(p0, p6, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p9);
}

/* CONTENT_JSON_SERIALISER_SOURCE */
#endif
