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

#ifndef CONSTRAINTS_CLI_SERIALISER_SOURCE
#define CONSTRAINTS_CLI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/language_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part/name_part_getter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/serialiser/tui/newline_tui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Retrieves language properties (constraints) necessary for serialisation.
 *
 * @param p0 the destination item
 * @param p1 the language properties (constraints) data
 * @param p2 the language properties (constraints) count
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the internal memory data
 */
void serialise_cli_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cli constraints.");
    //?? fwprintf(stdout, L"Debug: Serialise cli constraints. source count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Serialise cli constraints. source count remaining *p3: %i\n", *((int*) p3));

    //
    // Declaration
    //

    // The newline part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The newline part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The newline part model item data.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get newline part.
    get_part_name((void*) &n, p1, (void*) NEWLINE_LANGUAGE_STATE_CYBOL_NAME, (void*) NEWLINE_LANGUAGE_STATE_CYBOL_NAME_COUNT, p2, p3, p4, p5);

    // Get newline part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get newline part model item data.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // Set newline flag to TRUE (enabled) by default.
    int newline = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    copy_integer((void*) &newline, nmd);

    //
    // Functionality
    //

    // Append newline.
    serialise_tui_newline(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &newline, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
}

/* CONSTRAINTS_CLI_SERIALISER_SOURCE */
#endif
