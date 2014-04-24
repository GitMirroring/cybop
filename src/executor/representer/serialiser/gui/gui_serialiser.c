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

#ifndef GUI_SERIALISER_SOURCE
#define GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/cybol/boolean/boolean_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/colour/terminal_colour_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex/cartesian/cartesian_complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex/polar/polar_complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/datetime/utc/utc_datetime_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/duration/iso/iso_duration_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction/decimal/decimal_fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction/vulgar/vulgar_fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/byte_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/channel_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/encoding_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/language_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/type_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/gui/part_gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises a part into graphical user interface (gui).
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the win32 device context
 * @param p5 the destination text item
 * @param p6 the source model data
 * @param p7 the source model count
 * @param p8 the source properties data
 * @param p9 the source properties count
 * @param p10 the knowledge memory part
 * @param p11 the format
 */
void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // colour
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) RGB_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p5, p6, p7, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) TERMINAL_COLOUR_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_colour_terminal(p5, p6);
        }
    }

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) UTC_DATETIME_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_datetime_utc(p5, p6, p7);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Do NOT call function "serialise_gui_properties" here.
            // It is called inside the "serialise_gui_part" function.
            serialise_gui_part(p0, p1, p2, p3, p4, p6, p7, p8, p9, p10);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_boolean(p5, p6, p7);
        }
    }

    //
    // meta
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) CHANNEL_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_channel(p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) ENCODING_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_encoding(p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) LANGUAGE_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_language(p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FORMAT_META_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_format(p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) TYPE_META_STATE_CYBOI_FORMAT);

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
            serialise_cybol_type(f, p6);
            // Get temporary format item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            // Decode cybol source format (mime type as string) into cyboi-internal type (an integer).
            serialise_cybol_format(p5, fd);

            // Deallocate temporary format item.
            deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_byte(p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_complex_cartesian(p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_complex_polar(p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_fraction_decimal(p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_fraction_vulgar(p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol_integer(p5, p6, p7, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) REFERENCE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p5, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p5, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) ASCII_TEXT_STATE_CYBOI_FORMAT);

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

            decode(p5, p6, p7, (void*) UTF_8_CYBOI_ENCODING);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p5, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui. The format is unknown.");
    }
}

/* GUI_SERIALISER_SOURCE */
#endif
