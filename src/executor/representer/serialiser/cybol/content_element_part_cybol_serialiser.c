/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
//?? #include "../../../../constant/name/cybol/state/wui/tag_wui_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the part element content into cybol.
 *
 * Example:
 *
 *  | compound [The root node has no name.]
 * +-node_$0 | compound
 * | +-node_$0 | compound
 * | | +-node_$0 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | left
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.count
 * | | +-node_$1 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | right
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.maximum
 * | | +-node_$2 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | result
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.break
 * | | #- | wide_character | part [This is the xml tag name.]
 * | | #-name | wide_character | compare_count
 * | | #-channel | wide_character | inline
 * | | #-format | wide_character | operation/plain
 * | | #-model | wide_character | greater_or_equal
 * | +-node_$1 | compound
 * ...
 * | #- | wide_character | model [This is the xml tag name.]
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the tree level
 * @param p6 the format
 */
void serialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol part element content.");

/*??
    // Allocate part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the cyboi runtime type determined above
    // (NOT the mime type format)!
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

    copy(m);
    copy(p);

    // CYBOI model elements (e.g. part, int etc.) become one new property (part) node each.
    serialise_cybol_part_element_content_model(p0, p1, p2);
    // CYBOI properties (e.g. operation arguments) become one new model (part) node each.
    serialise_cybol_part_element_content_properties(p3, p4);
    serialise_cybol();

    serialise_cybol(dest_item, md, mc, pd, pc, tree_level, format);
*/
}

/* CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE */
#endif
