/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef EMPTY_HTML_SERIALISER_SOURCE
#define EMPTY_HTML_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/serialiser/html/break_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/end_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/indentation_html_serialiser.c"
#include "logger.h"

/**
 * Serialises the empty part element into html.
 *
 * @param p0 the destination item
 * @param p1 the tag data
 * @param p2 the tag count
 * @param p3 the indentation flag
 * @param p4 the indentation level
 * @param p5 the void flag
 */
void serialise_html_empty(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise html empty.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // If this element is ALLOWED to be void, following the
    // html specification, then NOTHING is to be done here.
    // It may be represented as EMPTY (also called VOID) tag.
    //
    // Example:
    // <img/>
    //
    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This element is NOT allowed to be void, since it contains content.
        // It therefore has to be represented with opening and closing tag.
        //
        // Example:
        // <div>
        // </div>
        //

        //
        // Serialise indentation.
        //
        // CAUTION! Use original indentation that was handed over as parametre.
        //
        serialise_html_indentation(p0, p3, p4);
        // Append end tag.
        serialise_html_end(p0, p1, p2);
        // Serialise line break.
        serialise_html_break(p0, p3);
    }
}

/* EMPTY_HTML_SERIALISER_SOURCE */
#endif
