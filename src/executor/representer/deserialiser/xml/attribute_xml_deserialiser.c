/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTE_XML_DESERIALISER_SOURCE
#define ATTRIBUTE_XML_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/xml/attribute_name_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/attribute_value_xml_deserialiser.c"
#include "../../../../executor/searcher/selector/xml/attribute_begin_or_tag_end_xml_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the xml attribute.
 *
 * @param p0 the destination properties item
 * @param p1 the has content flag
 * @param p2 the is empty flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void deserialise_xml_attribute(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ie = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* hc = (int*) p1;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml attribute.");

            // The source attribute name.
            void* an = *NULL_POINTER_STATE_CYBOI_MODEL;
            int anc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The source attribute value.
            void* av = *NULL_POINTER_STATE_CYBOI_MODEL;
            int avc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The part.
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The has attribute flag.
            // CAUTION! This HAS TO BE a local variable, because the function
            // may be called recursively and if the flag were handed over
            // as argument to this function, then it would have an initial value
            // from a previous call of this function, which might lead to wrong results.
            int ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            // The break flag.
            int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            deserialise_xml_attribute_name((void*) &an, (void*) &anc, p3, p4);
            deserialise_xml_attribute_value((void*) &av, (void*) &avc, p3, p4);

            // Allocate part.
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Fill part.
            overwrite_part_element(p, an, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &anc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
            overwrite_part_element(p, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
            overwrite_part_element(p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
            overwrite_part_element(p, av, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &avc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);

            // Append part to destination model.
            // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
            // This is necessary in order to activate rubbish (garbage) collection.
            append_item_element(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            if (p4 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

                compare_integer_smaller_or_equal((void*) &b, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    break;
                }

                select_xml_attribute_begin_or_tag_end((void*) &ha, p1, p2, p3, p4);

                if (ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // A space character as indicator of subsequent attributes was detected.

                    // Call this function itself recursively.
                    deserialise_xml_attribute(p0, p1, p2, p3, p4);
                }

                if ((*hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (*ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                    // A tag end character as indicator of subsequent element content or
                    // an empty tag end character was detected.

                    break;
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml attribute. The has content flag is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xml attribute. The is empty flag is null.");
    }
}

/* ATTRIBUTE_XML_DESERIALISER_SOURCE */
#endif
