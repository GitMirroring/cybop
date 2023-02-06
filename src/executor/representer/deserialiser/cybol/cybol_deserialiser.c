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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CYBOL_DESERIALISER_SOURCE
#define CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/converter/encoder.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/deserialiser/ansi_escape_code/ansi_escape_code_deserialiser.c"
#include "../../../../executor/representer/deserialiser/boolean/boolean_deserialiser.c"
#include "../../../../executor/representer/deserialiser/colour/terminal_colour_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/byte_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/compound_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/format_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/language_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/gregorian/gregorian_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/jd/jd_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/jd/mjd_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/jd/tjd_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/julian/julian_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/posix/posix_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/tai/tai_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/ti/ti_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/datetime/utc/utc_datetime_deserialiser.c"
#include "../../../../executor/representer/deserialiser/duration/iso/iso_duration_deserialiser.c"
#include "../../../../executor/representer/deserialiser/duration/jd/jd_duration_deserialiser.c"
#include "../../../../executor/representer/deserialiser/duration/julian/julian_duration_deserialiser.c"
#include "../../../../executor/representer/deserialiser/duration/si/si_duration_deserialiser.c"
#include "../../../../executor/representer/deserialiser/numeral_vector/numeral_vector_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xml/xml_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the source into the destination, according to the given format.
 *
 * The decimal separator and thousands separator have been retrieved before
 * and are already available here as parametre, in order to be forwarded
 * to function "deserialise_numeral_vector".
 *
 * However, the language properties (constraints) are FORWARDED to here
 * AND ON as well, so that child nodes can access them. Since cybol
 * language constraints are given together with the destination node,
 * but NOT for each single child node, they have to get forwarded.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the language properties (constraints) data
 * @param p5 the language properties (constraints) count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the decimal separator data
 * @param p10 the decimal separator count
 * @param p11 the thousands separator data
 * @param p12 the thousands separator count
 * @param p13 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p14 the format
 */
void deserialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol.");
    //?? fwprintf(stdout, L"Information: Deserialise cybol. format p14: %i\n", p14);
    //?? fwprintf(stdout, L"Information: Deserialise cybol. format *p14: %i\n", *((int*) p14));

    //
    // The functions below are for STATE models only.
    //
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // application
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) OCTET_STREAM_APPLICATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! The data are available as wide character strings.
            // They ALL are deserialised uniformly into various formats.
            //
            // So do data with format "application/octet-stream".
            // Since they are available with type "wchar_t",
            // they have to get deserialised into "char" here.
            //
            // When receiving data over some channel, they are mostly
            // decoded back into a multibyte character sequence of type "char".
            // It is true, this double-conversion could be avoided if catching
            // data with format "application/octet-stream", e.g. in file "file_receiver.c".
            // But in order to be able to uniformly process all data,
            // this loss in efficiency is taken.
            //

            encode(p0, p2, p3, (void*) UTF_8_CYBOI_ENCODING);
        }
    }

    //
    // colour
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) RGB_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) TERMINAL_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_colour_terminal(p0, p2, p3);
        }
    }

    //
    // datetime
    //

    //??
    //?? TODO: TEST only. Delete the DDMMYYYY block below later.
    //??
// Forward declaration.
void deserialise_xdt_datetime_ddmmyyyy(void* p0, void* p1, void* p2);
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_datetime_ddmmyyyy(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) ISO_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_chronology_gregorian_iso(p0, p2, p3);
        }
    }

    //
    // duration
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) ISO_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_duration_iso(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) JD_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_duration_jd(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) JULIAN_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_duration_julian(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) SI_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_duration_si(p0, p2, p3);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PROPERTY_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) REFERENCE_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_boolean(p0, p2, p3);
        }
    }

    //
    // meta
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) CHANNEL_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_channel(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) ENCODING_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_encoding(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) LANGUAGE_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_language(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) FORMAT_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_format(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) TYPE_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary format item.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary format item data.
            void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate temporary format item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            // CAUTION! Initialise integer items with a size of ONE,
            // in order to avoid later reallocation when overwriting
            // the element and to thus increase efficiency.
            //
            allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            fwprintf(stdout, L"Information: Deserialise cybol. section meta/type p2: %ls\n", (wchar_t*) p2);
            fwprintf(stdout, L"Information: Deserialise cybol. section meta/type p3: %i\n", p3);
            fwprintf(stdout, L"Information: Deserialise cybol. section meta/type *p3: %i\n", *((int*) p3));

            // Deserialise cybol source format (mime type as string) into cyboi-internal type (an integer).
            deserialise_cybol_format(f, p2, p3);
            //
            // Get temporary format item data.
            //
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            //
            copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            //
            // Deserialise cyboi-internal type into cyboi runtime type.
            //
            // CAUTION! Both are not always equal in their meaning.
            // For example, an "xdt" file is converted into a cyboi "part".
            // Therefore, a runtime type has to be figured out here.
            // The latter is needed for allocating the new part.
            //
            deserialise_cybol_type(p0, fd);

            // Deallocate temporary format item.
            deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_byte(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Deserialise numeral.
            deserialise_numeral_vector(p0, p2, p3, p9, p10, p11, p12, p13, p14);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) CYBOL_PATH_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_item(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT log this warning.
        // The source is unknown for LOGIC formats.
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol. The format is unknown.");
        // fwprintf(stdout, L"Warning: Could not deserialise cybol. The format is unknown. format p14: %i\n", p14);
        // fwprintf(stdout, L"Warning: Could not deserialise cybol. The format is unknown. format *p14: %i\n", *((int*) p14));
        //
    }
}

/* CYBOL_DESERIALISER_SOURCE */
#endif
