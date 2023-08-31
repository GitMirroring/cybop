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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the default character into tui.
 *
 * @param p0 the destination character
 * @param p1 the source horizontal border character
 * @param p2 the source vertical border character
 * @param p3 the source left top border character
 * @param p4 the source right top border character
 * @param p5 the source left bottom border character
 * @param p6 the source right bottom border character
 * @param p7 the left horizontal position flag
 * @param p8 the centre horizontal position flag
 * @param p9 the right horizontal position flag
 * @param p10 the top vertical position flag
 * @param p11 the middle vertical position flag
 * @param p12 the bottom vertical position flag
 */
void serialise_tui_default(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui default.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p7);
        logify_boolean_and((void*) &r, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The top left.
            //

            copy_wide_character(p0, p3);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p9);
        logify_boolean_and((void*) &r, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The top right.
            //

            copy_wide_character(p0, p4);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p8);
        logify_boolean_and((void*) &r, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The top centre.
            //

            copy_wide_character(p0, p1);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p7);
        logify_boolean_and((void*) &r, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The bottom left.
            //

            copy_wide_character(p0, p5);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p9);
        logify_boolean_and((void*) &r, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The bottom right.
            //

            copy_wide_character(p0, p6);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p8);
        logify_boolean_and((void*) &r, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The bottom centre.
            //

            copy_wide_character(p0, p1);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p7);
        logify_boolean_and((void*) &r, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The middle left.
            //

            copy_wide_character(p0, p2);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p9);
        logify_boolean_and((void*) &r, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The middle right.
            //

            copy_wide_character(p0, p2);
        }
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_or((void*) &r, p8);
        logify_boolean_and((void*) &r, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The middle centre (any other position NOT belonging to the border.
            //

            copy_wide_character(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL);
        }
    }
}
