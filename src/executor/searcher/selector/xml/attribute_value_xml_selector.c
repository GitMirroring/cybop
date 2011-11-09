/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: xml_selector.c,v $ $Revision: 1.13 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTE_VALUE_XML_SELECTOR_SOURCE
#define ATTRIBUTE_VALUE_XML_SELECTOR_SOURCE

#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the attribute value.
 *
 * @param p0 the destination break flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_xml_attribute_value(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute value.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        detect_array((void*) &r, p1, p2, (void*) ATTRIBUTE_VALUE_END_XML_NAME, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //
            // The attribute value end was found.
            //
            // CAUTION! The current position and remaining count were already
            // changed in the called function, to be processed further.
            //
            // The attribute value and count are left as they are.
            //

            // Set break flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        move_position(p1, p2, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    }
}

/* ATTRIBUTE_VALUE_XML_SELECTOR_SOURCE */
#endif
