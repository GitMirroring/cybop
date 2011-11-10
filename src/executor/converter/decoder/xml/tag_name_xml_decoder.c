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

#ifndef TAG_NAME_XML_DECODER_SOURCE
#define TAG_NAME_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/xml/attribute_begin_or_tag_end_xml_selector.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the xml tag name.
 *
 * @param p0 the destination properties item
 * @param p1 the has attribute flag
 * @param p2 the has content flag
 * @param p3 the is empty flag
 * @param p4 the source data position (pointer reference)
 * @param p5 the source count remaining
 */
void decode_xml_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ie = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* hc = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* ha = (int*) p1;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml tag name.");

                // The source tag name.
                void* tn = *NULL_POINTER_MEMORY_MODEL;
                int tnc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Initialise element.
                copy_pointer((void*) &tn, p4);

                while (*TRUE_BOOLEAN_MEMORY_MODEL) {

                    compare_integer_smaller_or_equal((void*) &b, p5, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

                    if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

                        break;
                    }

                    select_xml_attribute_begin_or_tag_end(p1, p2, p3, p4, p5);

                    if ((*ha != *FALSE_BOOLEAN_MEMORY_MODEL) || (*hc != *FALSE_BOOLEAN_MEMORY_MODEL) || (*ie != *FALSE_BOOLEAN_MEMORY_MODEL)) {

                        // A space character as indicator of subsequent attributes or
                        // a tag end character as indicator of subsequent element content or
                        // an empty tag end character was detected.

                        // The part.
                        void* p = *NULL_POINTER_MEMORY_MODEL;

                        // Allocate part.
                        allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE);

                        // Fill part.
                        overwrite_part_element(p, (void*) NODE_NAME_XML_CYBOL_NAME, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) NODE_NAME_XML_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
                        overwrite_part_element(p, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) INTEGER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
                        overwrite_part_element(p, tn, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) &tnc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

                        // Append part to destination model.
                        append_item_element(p0, (void*) &p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

                        break;

                    } else {

                        // Increment tag name count.
                        tnc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml tag name. The has attributes flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml tag name. The has content flag is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml tag name. The is empty flag is null.");
    }
}

/* TAG_NAME_XML_DECODER_SOURCE */
#endif
