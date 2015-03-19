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
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source channel data
 * @param p4 the source encoding data
 * @param p5 the source language data
 * @param p6 the source format data
 * @param p7 the source type data
 * @param p8 the source model data
 * @param p9 the source model count
 * @param p10 the source properties data
 * @param p11 the source properties count
 */
void serialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol part element content.");

    //?? TEST for root node ??

/*??
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name, channel, encoding, language, format, type, model, properties item.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pe = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pl = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the cyboi runtime type (NOT the mime type format)!
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p7);

    // Get part name, channel, encoding, language, format, type, model, properties item.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pe, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENCODING_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pl, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pf, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    //?? TODO: Allocate one single new wide_character item for each (name, channel etc.)!
    //?? Serialise source parametre arguments p1, p2 etc. into these new items using the function:
    //?? serialise_cybol_language(new_language_item, p5);
    //?? Append new items to destination properties.
    //?? Append source properties p10, p11 to destination model.

    //?? TODO: Use default values for channel, encoding etc.,
    //?? since the real source values are already added to properties.
    //?? TODO: Therefore, the parametres: name, channel etc. may be deleted again, also in file "element_part_cybol_serialiser.c".

    // Fill part name item.
    overwrite_item_element(pn, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part channel item.
    overwrite_item_element(pc, p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part encoding item.
    overwrite_item_element(pe, p4, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part language item.
    overwrite_item_element(pl, p5, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);


--
    // Allocate part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the cyboi runtime type determined above
    // (NOT the mime type format)!
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

    allocate_part_for_each_part_detail(name, channel, encoding, language, format, model, properties)
    // CAUTION! Serialise first, if array; if item, it doesn't matter, since only the array pointer inside the item might change on reallocation.
    overwrite(part-name-item, any, e.g. "node", see deserialiser);
    overwrite(part-channel-item, not needed, e.g. "inline", possibly deleted from schema in the future);
    overwrite(part-encoding-item, not needed, e.g. "utf-8", possibly deleted from schema in the future);
    overwrite(part-language-item, not needed, e.g. "text/cybol", possibly deleted from schema in the future);
    overwrite(part-format-item, p5);
    overwrite(part-type-item, determine from format p5);
    // Do not use: overwrite(new_model_part, p1, p2);
    // because the model may be primitive data but also compound element/part.
    serialise_cybol(part-model-item, md, mc, pd, pc, p5);
    ...

    // The model elements (e.g. part, integer, character etc.) become an xml attribute.
    add_name_part_to_p-properties
    add_channel_part_to_p-properties
    add_encoding_part_to_p-properties
    add_language_part_to_p-properties
    add_format_part_to_p-properties
    add_model_part_to_p-properties

    // The properties (e.g. operation arguments) become an xml tag, each.
    // It is always a compound part (container).
    serialise_cybol_part(part-model-item "pm", p3, p4);
*/
}

/* CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE */
#endif
