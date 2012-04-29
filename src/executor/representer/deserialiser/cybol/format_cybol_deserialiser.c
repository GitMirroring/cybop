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

#ifndef FORMAT_CYBOL_DESERIALISER_SOURCE
#define FORMAT_CYBOL_DESERIALISER_SOURCE

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
#include "../../../../constant/type/cybol/state/element_state_cybol_type.c"
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
 * Deserialises the cybol format mime type into cyboi-internal format (integer).
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_format(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol format.");

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

    // ======================================================================
    //
    // State.
    //
    // ======================================================================

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) HH_MM_SS_DATETIME_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) YYYY_MM_DD_DATETIME_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PART_ELEMENT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PART_ELEMENT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) PART_ELEMENT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) BOOLEAN_LOGICVALUE_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // meta
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CHANNEL_META_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CHANNEL_META_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) CHANNEL_META_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCODING_META_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ENCODING_META_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ENCODING_META_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LANGUAGE_META_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LANGUAGE_META_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) LANGUAGE_META_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FORMAT_META_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) FORMAT_META_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) FORMAT_META_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TYPE_META_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) TYPE_META_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) TYPE_META_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) COMPLEX_POLAR_NUMBER_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) FRACTION_VULGAR_NUMBER_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTEGER_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) INTEGER_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) INTEGER_NUMBER_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCAPSULATED_PATH_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ENCAPSULATED_PATH_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ENCAPSULATED_PATH_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) KNOWLEDGE_PATH_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) KNOWLEDGE_PATH_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) KNOWLEDGE_PATH_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ASCII_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ASCII_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ASCII_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) PLAIN_TEXT_STATE_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    // ======================================================================
    //
    // Logic.
    //
    // ======================================================================

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ABSOLUTE_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ADD_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) DIVIDE_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) MULTIPLY_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) NEGATE_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) REDUCE_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) REMAINDER_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SUBTRACT_CALCULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) RECEIVE_COMMUNICATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SEND_COMMUNICATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // compare
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) EQUAL_PART_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) EQUAL_PREFIX_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) GREATER_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SMALLER_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) UNEQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) DECODE_CONVERT_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ENCODE_CONVERT_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // file
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ARCHIVE_FILE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COPY_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) COPY_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) COPY_FILE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) BRANCH_FLOW_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) LOOP_FLOW_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SEQUENCE_FLOW_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) EXIT_LIVE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) INTERRUPT_LIVE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SENSE_LIVE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) AND_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) NAND_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) NEG_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) NOR_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) NOT_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) OR_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) XNOR_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) XOR_LOGIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SHUTDOWN_MAINTAIN_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) STARTUP_MAINTAIN_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // manipulate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) GET_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) RESET_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SET_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) CREATE_MEMORISE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) DESTROY_MEMORISE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) APPEND_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) BUILD_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) COUNT_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) GET_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) INSERT_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) OVERWRITE_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) REMOVE_MODIFY_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RUN_LOGIC_CYBOL_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) RUN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, (void*) RUN_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol format. The format is unknown.");
    }
}

/* FORMAT_CYBOL_DESERIALISER_SOURCE */
#endif
