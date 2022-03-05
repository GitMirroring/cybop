/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONTENT_CYBOL_DESERIALISER_SOURCE
#define CONTENT_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/language/cybol/state/text_state_cybol_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cybol/cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/name_getter/array_name_getter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/node_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/test_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol part element content.
 *
 * The source properties handed over contain one node each for
 * name, channel, encoding, language, format, model.
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
 */
void deserialise_cybol_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol content.");
    // fwprintf(stdout, L"Debug: Deserialise cybol content. p0: %i\n", p0);

    //
    // Declaration
    //

    // The source name, channel, encoding, language, format, model part.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source name, channel, encoding, language, format, model part model item.
    void* snm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sem = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* slm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source name, channel, encoding, language, format, model part model item data, count.
    //
    //?? TODO: Assign default values? Better NOT. This can be done in a cybol editor tool.
    //
    void* snmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) INLINE_CYBOL_CHANNEL;
    void* scmc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) INLINE_CYBOL_CHANNEL_COUNT;
    void* semd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) UTF_8_UNICODE_CYBOL_ENCODING;
    void* semc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) UTF_8_UNICODE_CYBOL_ENCODING_COUNT;
    //
    // As an exception, a default value is assigned for language,
    // so that cybol code may be slim and without xml "language" attribute.
    //
    void* slmd = (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE;
    void* slmc = (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT;
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT;
    void* sfmc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT;
    void* smmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get source name, channel, encoding, language, format, model part.
    get_name_array((void*) &sn, p3, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sc, p3, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &se, p3, (void*) ENCODING_CYBOL_NAME, (void*) ENCODING_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sl, p3, (void*) LANGUAGE_CYBOL_NAME, (void*) LANGUAGE_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sf, p3, (void*) FORMAT_CYBOL_NAME, (void*) FORMAT_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sm, p3, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Get source name, channel, encoding, language, format, model item.
    //
    // CAUTION! Do NOT use the following names here:
    // - NAME_PART_STATE_CYBOI_NAME
    // - CHANNEL_PART_STATE_CYBOI_NAME
    // - ENCODING_PART_STATE_CYBOI_NAME
    // - LANGUAGE_PART_STATE_CYBOI_NAME
    // - FORMAT_PART_STATE_CYBOI_NAME
    // - MODEL_PART_STATE_CYBOI_NAME
    //
    // The corresponding parts were already retrieved above.
    // What is wanted here, is just their MODEL containing the actual data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &snm, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scm, sc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sem, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slm, sl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source name, channel, encoding, language, format, model data, count.
    copy_array_forward((void*) &snmd, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snmc, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmd, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmc, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semd, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semc, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmd, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmc, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfmc, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmd, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmc, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Test if this is a root node.
    deserialise_cybol_test((void*) &r, sn, sc, se, sl, sf, sm);

    // Deserialise cybol node (standard or root).
    deserialise_cybol_node(p0, snmd, snmc, scmd, scmc, semd, semc, slmd, slmc, sfmd, sfmc, smmd, smmc, p1, p2, (void*) &r);
}

/* CONTENT_CYBOL_DESERIALISER_SOURCE */
#endif
