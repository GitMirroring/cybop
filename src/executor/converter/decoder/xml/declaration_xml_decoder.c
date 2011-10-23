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

#ifndef DECLARATION_XML_DECODER_SOURCE
#define DECLARATION_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/xml/declaration_xml_selector.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the xml declaration.
 *
 * @param p0 the destination details item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void decode_xml_declaration(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml declaration.");

    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        select_xml_declaration(p0, (void*) &b, p1, p2);
    }
}

/* DECLARATION_XML_DECODER_SOURCE */
#endif
