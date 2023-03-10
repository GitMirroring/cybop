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

#ifndef STRING_XML_DESERIALISER_SOURCE
#define STRING_XML_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/deserialiser/character_reference/character_reference_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/normalisation_xml_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Normalises the xml element content depending on the given flag.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the normalisation flag
 * @param p4 the type
 */
void deserialise_xml_string(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml string.");
    //?? fwprintf(stdout, L"Debug: Deserialise xml string. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise xml string. source count *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a string xml element.
        //
        // CAUTION! A normalisation and stripping of whitespace
        // characters makes sense ONLY for strings.
        //

        // The normalised item (possibly, if normalisation flag is set).
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The normalised item data, count.
        void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate normalised item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        // CAUTION! Use the source count as initial size, since
        // the destination will have at least the same, if not
        // a greater size if numeric character references are inserted.
        //
        allocate_item((void*) &n, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Overwrite and possibly normalise data.
        deserialise_xml_normalisation(n, p1, p2, p3);

        //
        // Get normalised item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &nc, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Replace character reference (hexadecimal, decimal, entity).
        deserialise_character_reference(p0, nd, nc);

        // Deallocate normalised item.
        deallocate_item((void*) &n, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* STRING_XML_DESERIALISER_SOURCE */
#endif
