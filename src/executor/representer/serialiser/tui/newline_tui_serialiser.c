/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NEWLINE_TUI_SERIALISER_SOURCE
#define NEWLINE_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/text/newline_text_model.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Appends a newline to the data.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the newline flag
 * @param p3 the tree level
 */
void serialise_tui_newline(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui newline.");

    // The root tree level comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The newline flag comparison result.
    int n = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Check if this is the root tree level,
    // which means that this is the initial
    // (and not a recursive) call of this function.
    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &n, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (n != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#ifdef WIN32
            // CAUTION! Do NOT use the following source code here:
            // append_item_element(p0, (void*) CARRIAGE_RETURN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // append_item_element(p0, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            //
            // The reason is that win32 console function calls are used,
            // but NOT the destination item (encapsulating a wide character array).
            // Therefore, delegate newline generation to a function.
            serialise_win32_console_character(p1, (void*) WINDOWS_NEWLINE_TEXT_MODEL, (void*) WINDOWS_NEWLINE_TEXT_MODEL_COUNT);
#endif
#ifdef MAC
            append_item_element(p0, (void*) MACINTOSH_NEWLINE_TEXT_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MACINTOSH_NEWLINE_TEXT_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
            append_item_element(p0, (void*) UNIX_NEWLINE_TEXT_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UNIX_NEWLINE_TEXT_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif
        }
    }
}

/* NEWLINE_TUI_SERIALISER_SOURCE */
#endif
