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

#ifndef ENCODER_SOURCE
#define ENCODER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/converter/encoder/cybol/boolean/boolean_cybol_encoder.c"
#include "../../executor/converter/encoder/cybol/double/double_cybol_encoder.c"
#include "../../executor/converter/encoder/cybol/integer/integer_cybol_encoder.c"
#include "../../executor/converter/encoder/cybol/complex_encoder.c"
#include "../../executor/converter/encoder/cybol/cybol_encoder.c"
#include "../../executor/converter/encoder/cybol/date_time_encoder.c"
#include "../../executor/converter/encoder/cybol/fraction_encoder.c"
#include "../../executor/converter/encoder/html/html_encoder.c"
#include "../../executor/converter/encoder/http_request/http_request_encoder.c"
#include "../../executor/converter/encoder/http_response/http_response_encoder.c"
#include "../../executor/converter/encoder/latex/latex_encoder.c"
#include "../../executor/converter/encoder/model_diagram/model_diagram_encoder.c"
#include "../../executor/converter/encoder/terminal/terminal_encoder.c"
#include "../../executor/converter/encoder/utf/utf_16_unicode_character_encoder.c"
#include "../../executor/converter/encoder/utf/utf_8_unicode_character_encoder.c"
#include "../../executor/converter/encoder/xdt/xdt_encoder.c"
#include "../../executor/converter/encoder/xml/xml_encoder.c"
#include "../../executor/converter/encoder/x_window_system/x_window_system_encoder.c"

/**
 * Encodes the source into the destination, according to the given type.
 *
 * @param p0 the destination item
 * @param p3 the source message name
 * @param p4 the source message name count
 * @param p5 the source message type
 * @param p6 the source message type count
 * @param p7 the source message model
 * @param p8 the source message model count
 * @param p9 the source message properties
 * @param p10 the source message properties count
 * @param p11 the source metadata name
 * @param p12 the source metadata name count
 * @param p13 the source metadata type
 * @param p14 the source metadata type count
 * @param p15 the source metadata model
 * @param p16 the source metadata model count
 * @param p17 the source metadata properties
 * @param p18 the source metadata properties count
 * @param p19 the knowledge memory
 * @param p20 the knowledge memory count
 * @param p21 the language
 * @param p22 the language count
 */
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) BOOLEAN_LOGICVALUE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) BOOLEAN_LOGICVALUE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_boolean(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_complex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) CYBOL_TEXT_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) CYBOL_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_cybol(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p8, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) TERMINAL_CYBOL_CHANNEL, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) TERMINAL_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            encode_terminal(p0, p1, p2, p7, p8, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p13, p14);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) HH_MM_SS_DATETIME_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) HH_MM_SS_DATETIME_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) HTML_TEXT_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) HTML_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_html(p0, p1, p2, p5, p6, p7, p8, p9, p10, p19, p20);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) HTTP_REQUEST_MESSAGE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) HTTP_REQUEST_MESSAGE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? encode_http_request();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_http_response(p0, p1, p2, p5, p6, p7, p8, p9, p10, p13, p14, p15, p16, p17, p18);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) INTEGER_STATE_CYBOI_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) KNOWLEDGE_PATH_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) KNOWLEDGE_PATH_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p8, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) LATEX_APPLICATION_X_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) LATEX_APPLICATION_X_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_latex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) MODEL_DIAGRAM_TEXT_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) MODEL_DIAGRAM_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) PLAIN_OPERATION_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) PLAIN_OPERATION_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p8, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) PLAIN_TEXT_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) PLAIN_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p8, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_terminal_background(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_terminal_foreground(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) VULGAR_FRACTION_NUMBER_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) VULGAR_FRACTION_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_fraction(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_x_window_system(p0, p1, p2, p7, p8, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p19, p20);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) XDT_TEXT_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) XDT_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_xdt(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p21, (void*) YYYY_MM_DD_DATETIME_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p22, (void*) YYYY_MM_DD_DATETIME_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_ddmmyyyy_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode. The language is unknown.");
    }
}

/* ENCODER_SOURCE */
#endif
