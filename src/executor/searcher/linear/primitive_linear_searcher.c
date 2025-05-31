/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "constant.h"
#include "logger.h"

/**
 * Process primitive list element.
 *
 * @param p0 the found flag (set to TRUE if found; unchanged otherwise)
 * @param p1 the primitive array (list data position)
 * @param p2 the list count remaining
 * @param p3 the list type
 * @param p4 the searchword data
 * @param p5 the searchword count
 * @param p6 the searchword type
 * @param p7 the perfect match flag (requesting equal count)
 */
void search_linear_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear primitive.");
    //?? fwprintf(stdout, L"Debug: Search linear primitive. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The element count.
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The perfect match flag is NOT set.
        //

        //
        // Use searchword count as element count.
        //
        // CAUTION! Since the operation "check" called further below does
        // lexicographical comparison, the COUNTS of both operands have to
        // be EQUAL for a positive result. But the list count remaining
        // is mostly greater than the searchword count. Therefore, the
        // SEARCHWORD COUNT gets assigned to the element count here.
        //
        search_linear_elementcount((void*) &ec, p5, p2);

    } else {

        //
        // The perfect match flag IS set.
        //

        //
        // Use list count remaining as element count.
        //
        // CAUTION! When searching through the child nodes of a compound part,
        // then the name has to match perfectly and NO MORE characters are
        // allowed to remain. Therefore, the LIST COUNT REMAINING is used
        // for comparison and has to be identical to the searchword count.
        //
        // Example:
        //
        // +-logic | element/part |
        // | +-create | element/part |
        // | | +-choices | element/part |
        // | | | +-rows | element/part |
        // ...
        // | | | +-row | element/part |
        // ...
        //
        // Searched path: .logic.create.choices.row
        //
        // Using the standard search, the node "rows" would be returned FALSELY
        // as result, since it contains the letters "row". Therefore, the length
        // of both comparison operands has to match PERFECTLY.
        //
        copy_integer((void*) &ec, p2);
    }

    // Check if element type and searchword type are equal.
    search_linear_comparison(p0, p1, (void*) &ec, p3, p4, p5, p6);
}
