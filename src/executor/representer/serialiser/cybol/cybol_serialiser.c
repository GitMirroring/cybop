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

#ifndef CYBOL_SERIALISER_SOURCE
#define CYBOL_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/converter/decoder.c"
#include "../../../../executor/representer/serialiser/cybol/boolean/boolean_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/colour/terminal_colour_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex/cartesian/cartesian_complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex/polar/polar_complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/gregorian/gregorian_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/jd/jd_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/jd/mjd_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/jd/tjd_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/julian/julian_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/posix/posix_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/tai/tai_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/ti/ti_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/utc/utc_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/duration/iso/iso_duration_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/duration/jd/jd_duration_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/duration/julian/julian_duration_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/duration/si/si_duration_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction/decimal/decimal_fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction/vulgar/vulgar_fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/byte_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/channel_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/element_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/encoding_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/language_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/type_cybol_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source into the destination, according to the given format.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the format
 */
void serialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol.");

    // The functions below are for STATE models only.
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // colour
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) RGB_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p0, p1, p2, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_colour_terminal(p0, p1);
        }
    }

    //
    // datetime
    //

    //??
    //?? TODO: TEST only. Delete the DDMMYYYY block below later.
    //??
// Forward declaration.
void serialise_xdt_datetime_ddmmyyyy(void* p0, void* p1);
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_xdt_datetime_ddmmyyyy(p0, p1);
        }
    }
    //?? TODO: END OF DELETION

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GREGORIAN_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_gregorian(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) JD_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_jd(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) JULIAN_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_julian(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) MJD_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_mjd(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) POSIX_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_posix(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TAI_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_tai(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TI_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_ti(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TJD_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_tjd(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) UTC_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_utc(p0, p1, p2);
        }
    }

    //
    // duration
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) ISO_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_duration_iso(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) JD_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_duration_jd(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) JULIAN_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_duration_julian(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) SI_DURATION_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_duration_si(p0, p1, p2);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_element(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) PROPERTY_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_element(p0, p1, p2, p3, p4);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_boolean(p0, p1, p2);
        }
    }

    //
    // meta
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CHANNEL_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_channel(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) ENCODING_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_encoding(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LANGUAGE_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_language(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) FORMAT_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_format(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TYPE_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary format item.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary format item data.
            void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary format item.
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            // CAUTION! Initialise integer items with a size of ONE,
            // in order to avoid later reallocation when overwriting
            // the element and to thus increase efficiency.
            allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Decode cyboi runtime type into cyboi format.
            // CAUTION! For one cyboi runtime type, many formats may exist (1:n).
            // For example, a complex number may be given in cartesian or polar coordinates.
            // Since this is ambiguous, a DEFAULT FORMAT is assigned to each type.
            serialise_cybol_type(f, p1);
            // Get temporary format item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            // Decode cybol source format (mime type as string) into cyboi-internal type (an integer).
            serialise_cybol_format(p0, fd);

            // Deallocate temporary format item.
            deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_byte(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_complex_cartesian(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_complex_polar(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_fraction_decimal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p0, p1, p2, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p0, p1, p2, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) REFERENCE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) ASCII_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The data are available in various formats.
            // They ALL are serialised uniformly into wide character strings.
            //
            // So do data with format "text/ascii".
            // Since they are available with type "char",
            // they have to get serialised into "wchar_t" here.
            //
            // When sending data over some channel, they are mostly
            // encoded back into a multibyte character sequence of type "char".
            // It is true, this double-conversion could be avoided if catching
            // data with format "text/ascii" in file "file_sender.c".
            // But in order to be able to uniformly process all data,
            // this loss in efficiency is taken.

            decode(p0, p1, p2, (void*) UTF_8_CYBOI_ENCODING);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol. The format is unknown.");
    }
}

/* CYBOL_SERIALISER_SOURCE */
#endif
