/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_CONTENT_XML_SELECTOR_SOURCE
#define ELEMENT_CONTENT_XML_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/xml/xml_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/deserialiser/xml/declaration_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/definition_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/comment_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/end_tag_xml_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/element_xml_deserialiser.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

/**
 * Selects the xml element content.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the destination break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void select_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xml element content.");

    //
    // CAUTION! The ORDER of the comparisons is IMPORTANT! Do NOT change it easily!
    // Before arbitrary elements -- beginning with just "<" and a term -- can be identified,
    // all other possibilities (declaration, definition, comment) have to have
    // been processed, in order to be excluded.
    // Also, the comment begin <!-- has to be searched BEFORE the definition begin <!.
    // The very first comparison, however, is to search for the end tag begin "</".
    // The reason is that all elements begin with a "<" character:
    // - declaration: <?
    // - comment: <!--
    // - definition: <!
    // - element: <
    //
    // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
    // if a detection is to be taking place!
    // Many "detect" functions are called in a sequence, below.
    // If the result of one detection function was positive (r == 1),
    // then that function increments the current position and decrements the remaining count.
    // In this case, further detection functions following afterwards might detect
    // further characters and CHANGE the current position and remaining count, and so forth,
    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
    // Therefore, the checks for (r == 0) below avoid another detection,
    // if the result already has a value unequal zero.
    //
    // CAUTION! If a detection was successful, then the current position and remaining count
    // were already adapted within the corresponding "detect" function (as called below),
    // so that they now point to the first character following the detected character sequence.
    // Any "decode" function called afterwards can rely on this and start processing right away.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) END_TAG_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_TAG_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xml_end_tag(p3, p4);

            // Set break flag, because this xml element's end tag
            // has been reached and its content fully been decoded.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) DECLARATION_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The data contained in an XML declaration are added to the destination properties.
            deserialise_xml_declaration(p1, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) COMMENT_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The data contained in an XML comment are just ignored.
            deserialise_xml_comment(p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) DEFINITION_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The data contained in an XML definition are added to the destination properties.
            deserialise_xml_definition(p1, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) START_TAG_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The data contained in an XML element are added to the destination model.
            deserialise_xml_element(p0, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // None of the comparisons above delivered a positive (r != 0) result.
        // Therefore, increment the current position by one (pointer size).

        move_position(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* ELEMENT_CONTENT_XML_SELECTOR_SOURCE */
#endif
