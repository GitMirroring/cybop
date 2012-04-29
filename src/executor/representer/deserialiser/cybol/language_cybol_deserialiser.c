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

#ifndef LANGUAGE_CYBOL_DESERIALISER_SOURCE
#define LANGUAGE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/type/cybol/logic/calculate_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/communicate_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/compare_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/convert_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/file_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/flow_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/live_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/logify_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/maintain_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/manipulate_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/memorise_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/modify_logic_cybol_type.c"
#include "../../../../constant/type/cybol/logic/run_logic_cybol_type.c"
#include "../../../../constant/type/cybol/state/application_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/application_vnd_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/application_x_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/audio_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/bluetooth_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/colour_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/datetime_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/example_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/fonts_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/image_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/inode_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/interface_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/logicvalue_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/media_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/message_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/meta_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/model_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/multipart_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/number_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/path_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/print_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/text_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/uri_state_cybol_type.c"
#include "../../../../constant/type/cybol/state/video_state_cybol_type.c"
#include "../../../../constant/type/format/logic_format_type.c"
#include "../../../../constant/type/format/state_format_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol language mime type into cyboi-internal language (integer).
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_language(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol language.");

    // CAUTION! Do NOT use the "append" function here!
    // The type of each part has been given a size of ONE,
    // so that reallocation is not necessary for adding an element.
    // Therefore, the "overwrite" function has to be used instead.
    //
    // CAUTION! The "true" flag HAS TO BE SET for the "overwrite" function
    // since a type may be handed over not only as cybol xml attribute
    // (for which a default size of one has been set when allocating a part),
    // but also as model of a cybol property
    // (which gets assigned a default size of zero).

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOL_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CYBOL_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) CYBOL_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) MODEL_DIAGRAM_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XDT_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) XDT_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) XDT_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol language. The language is unknown.");
    }
}

/* LANGUAGE_CYBOL_DESERIALISER_SOURCE */
#endif
