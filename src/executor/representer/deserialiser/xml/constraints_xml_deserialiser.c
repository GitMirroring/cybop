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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONSTRAINTS_XML_DESERIALISER_SOURCE
#define CONSTRAINTS_XML_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "xml.h"

/**
 * Retrieves language properties (constraints) necessary for deserialisation.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the language properties (constraints) data
 * @param p5 the language properties (constraints) count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 */
void deserialise_xml_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml constraints.");
    //?? fwprintf(stdout, L"Debug: Deserialise xml constraints. source xml count p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise xml constraints. source xml count *p3: %i\n", *((int*) p3));

    //
    // Declaration
    //

    // The normalisation part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The normalisation part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The normalisation part model item data.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get normalisation part.
    get_part_name((void*) &n, p4, (void*) NORMALISATION_LANGUAGE_STATE_CYBOL_NAME, (void*) NORMALISATION_LANGUAGE_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);

    // Get normalisation part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get normalisation part model item data.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // Set normalisation flag to TRUE (enabled) by default.
    int normalisation = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    copy_integer((void*) &normalisation, nmd);

    //?? fwprintf(stdout, L"Debug: Deserialise xml constraints. TEST normalisation: %i\n", normalisation);
    //?? fwprintf(stdout, L"Debug: Deserialise xml constraints. TEST nmd: %i\n", nmd);
    //?? fwprintf(stdout, L"Debug: Deserialise xml constraints. TEST *nmd: %i\n", *((int*) nmd));

    //
    // Functionality
    //

    // Deserialise xml element content.
    deserialise_xml_content(p0, p1, p2, p3, (void*) &normalisation, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
}

/* CONSTRAINTS_XML_DESERIALISER_SOURCE */
#endif
