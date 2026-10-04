/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the attributes into an ansi escape code.
 *
 * Example:
 * printf("\033[1mbold \033[0mswitched off.")
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source background
 * @param p2 the source foreground
 * @param p3 the source hidden
 * @param p4 the source inverse
 * @param p5 the source blink
 * @param p6 the source underline
 * @param p7 the source bold
 */
void serialise_ansi_escape_code_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code attributes.");

    // The background colour.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground colour.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The prefix flag.
    int p = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get colours.
    serialise_ansi_escape_code_background((void*) &bd, (void*) &bc, p1);
    serialise_ansi_escape_code_foreground((void*) &fd, (void*) &fc, p2);

    // Set colours.
    serialise_ansi_escape_code_colour(p0, bd, bc, (void*) &p);
    serialise_ansi_escape_code_colour(p0, fd, fc, (void*) &p);

    //
    // Set further attributes.
    //
    // CAUTION! The "bold" attribute influences ONLY
    // text (foreground) colour, NOT the background.
    // In win32, on the contrary, there are two different
    // "intensity" values, for foreground AND background.
    //
    serialise_ansi_escape_code_effect(p0, (void*) HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) &p, p3);
    serialise_ansi_escape_code_effect(p0, (void*) INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) &p, p4);
    serialise_ansi_escape_code_effect(p0, (void*) BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) &p, p5);
    serialise_ansi_escape_code_effect(p0, (void*) UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) &p, p6);
    serialise_ansi_escape_code_effect(p0, (void*) BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) &p, p7);

    compare_integer_unequal((void*) &r, (void*) &p, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The prefix flag HAS been set.
        // That is, attributes have been added.
        // Therefore, add the suffix here.
        //

        serialise_ansi_escape_code_character(p0, (void*) ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL, (void*) ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);
    }
}
