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

#ifndef LANGUAGE_CYBOL_SERIALISER_SOURCE
#define LANGUAGE_CYBOL_SERIALISER_SOURCE

#include "../../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../../constant/language/cybol/state/chronology_state_cybol_language.c"
#include "../../../../constant/language/cybol/state/interface_state_cybol_language.c"
#include "../../../../constant/language/cybol/state/message_state_cybol_language.c"
#include "../../../../constant/language/cybol/state/number_state_cybol_language.c"
#include "../../../../constant/language/cybol/state/text_state_cybol_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the cyboi runtime language into a cybol language.
 *
 * @param p0 the destination item
 * @param p1 the source data
 */
void serialise_cybol_language(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol language.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // ======================================================================
    //
    // State.
    //
    // ======================================================================

    //
    // chronology
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BUDDHIST_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) COPTIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ETHIOPIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREGORIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ISLAMIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ISO_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) JD_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) JD_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) JD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) JULIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) MJD_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) MJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) POSIX_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) POSIX_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) POSIX_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TAI_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TAI_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TAI_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TI_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TI_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TI_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TJD_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) UTC_CHRONOLOGY_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) UTC_CHRONOLOGY_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UTC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // interface
    //

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BINARY_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BINARY_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BINARY_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CLI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CLI_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CLI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GUI_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GUI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NEWS_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) NEWS_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NEWS_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TUI_MESSAGE_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TUI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_MODE_NUMBER_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TERMINAL_MODE_NUMBER_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TERMINAL_MODE_NUMBER_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BDT_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) GDT_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) HTML_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HTML_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) LDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) LDT_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol language. The cyboi language is unknown.");
    }
}

/* LANGUAGE_CYBOL_SERIALISER_SOURCE */
#endif
