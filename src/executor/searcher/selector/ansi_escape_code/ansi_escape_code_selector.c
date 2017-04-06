/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ANSI_ESCAPE_CODE_SELECTOR_SOURCE
#define ANSI_ESCAPE_CODE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/ansi_escape_code/ansi_escape_code_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/selector/ansi_escape_code/character_ansi_escape_code_selector.c"
#include "../../../../executor/searcher/selector/ansi_escape_code/command_ansi_escape_code_selector.c"
#include "../../../../logger/logger.c"

/**
 * Selects the ansi escape code begin.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_ansi_escape_code(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select ansi escape code.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p1, p2, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // If ESC was pressed, then try to detect control button.
            // Otherwise, just add escape character as is.
            select_ansi_escape_code_command(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // No ESC character found, that is no control key was pressed.
        // Therefore, just add escape character as is.
        select_ansi_escape_code_character(p0, p1, p2);
    }
}

/* ANSI_ESCAPE_CODE_SELECTOR_SOURCE */
#endif
