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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_TUI_SERIALISER_SOURCE
#define CHARACTER_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/logifier/and_boolean_logifier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the character into tui.
 *
 * @param p0 the destination character
 * @param p1 the horizontal border character
 * @param p2 the vertical border character
 * @param p3 the left top border character
 * @param p4 the right top border character
 * @param p5 the left bottom border character
 * @param p6 the right bottom border character
 * @param p7 the left horizontal position flag
 * @param p8 the centre horizontal position flag
 * @param p9 the right horizontal position flag
 * @param p10 the top vertical position flag
 * @param p11 the middle vertical position flag
 * @param p12 the bottom vertical position flag
 */
void serialise_tui_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui character.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p7, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p9, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p8, p10);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p7, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p9, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p8, p12);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p7, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p9, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        logify_boolean_and((void*) &r, p8, p11);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_wide_character(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL);
        }
    }
}

/* CHARACTER_TUI_SERIALISER_SOURCE */
#endif
