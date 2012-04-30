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

#ifndef TAG_NAME_XML_DESERIALISER_SOURCE
#define TAG_NAME_XML_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/searcher/selector/xml/attribute_begin_or_tag_end_xml_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the xml tag name.
 *
 * @param p0 the destination properties item
 * @param p1 the has attribute flag
 * @param p2 the has content flag
 * @param p3 the is empty flag
 * @param p4 the source data position (pointer reference)
 * @param p5 the source count remaining
 */
void deserialise_xml_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ie = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* hc = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* ha = (int*) p1;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml tag name.");

                // The source tag name.
                void* tn = *NULL_POINTER_STATE_CYBOI_MODEL;
                int tnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // The break flag.
                int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                // Initialise element.
                copy_pointer((void*) &tn, p4);

                if (p5 == *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // CAUTION! If the loop count handed over as parametre is NULL,
                    // then the break flag will NEVER be set to true, because the loop
                    // variable comparison does (correctly) not consider null values.
                    // Therefore, in this case, the break flag is set to true already here.
                    // Initialising the break flag with true will NOT work either, since it:
                    // a) will be left untouched if a comparison operand is null;
                    // b) would have to be reset to true in each loop cycle.
                    copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_smaller_or_equal((void*) &b, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                    if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        break;
                    }

                    select_xml_attribute_begin_or_tag_end(p1, p2, p3, p4, p5);

                    if ((*ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (*hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (*ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                        // A space character as indicator of subsequent attributes or
                        // a tag end character as indicator of subsequent element content or
                        // an empty tag end character was detected.

                        // The part.
                        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

                        // Allocate part.
                        allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

                        // Fill part.
                        overwrite_part_element(p, (void*) NODE_NAME_XML_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NODE_NAME_XML_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
                        overwrite_part_element(p, (void*) PLAIN_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
                        overwrite_part_element(p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
                        overwrite_part_element(p, tn, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &tnc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

                        // Append part to destination model.
                        append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                        break;

                    } else {

                        // Increment tag name count.
                        tnc++;
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml tag name. The has attributes flag is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml tag name. The has content flag is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml tag name. The is empty flag is null.");
    }
}

/* TAG_NAME_XML_DESERIALISER_SOURCE */
#endif
