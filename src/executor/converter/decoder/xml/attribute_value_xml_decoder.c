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
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTE_VALUE_XML_DECODER_SOURCE
#define ATTRIBUTE_VALUE_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/xml/attribute_value_xml_selector.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the xml attribute value.
 *
 * @param p0 the destination attribute value (pointer reference)
 * @param p1 the destination attribute value count
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_xml_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* avc = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml attribute value.");

        // The break flag.
        int b = *FALSE_BOOLEAN_MEMORY_MODEL;

        // Initialise attribute value.
        copy_pointer(p0, p2);

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

            if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

                break;
            }

            select_xml_attribute_value((void*) &b, p2, p3);

            if (b == *FALSE_BOOLEAN_MEMORY_MODEL) {

                // Increment attribute value count.
                (*avc)++;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute value. The attribute value count is null.");
    }
}

/* ATTRIBUTE_VALUE_XML_DECODER_SOURCE */
#endif
