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

#ifndef LINE_STYLE_XCB_SERIALISER_SOURCE
#define LINE_STYLE_XCB_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cybol/xcb/line_style_xcb_cybol_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source data into the destination xcb integer constant.
 *
 * @param p0 the destination integer data
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void serialise_xcb_line_style(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xcb line style.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The value.
    //
    // CAUTION! The xcb sources store many constants
    // in an enumeration, so that handing over one
    // of its values as parametre fails.
    //
    // Example:
    // copy_integer(p0, (void*) &XCB_LINE_STYLE_SOLID);
    //
    // leads to the error:
    // lvalue required as unary ‘&’ operand
    //
    // Therefore, this temporary variable
    // had to be introduced.
    //
    int v = XCB_LINE_STYLE_SOLID;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) SOLID_LINE_STYLE_XCB_CYBOL_MODEL, p2, (void*) SOLID_LINE_STYLE_XCB_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            v = XCB_LINE_STYLE_SOLID;
            copy_integer(p0, (void*) &v);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) DOUBLE_DASH_LINE_STYLE_XCB_CYBOL_MODEL, p2, (void*) DOUBLE_DASH_LINE_STYLE_XCB_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            v = XCB_LINE_STYLE_DOUBLE_DASH;
            copy_integer(p0, (void*) &v);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) ON_OFF_DASH_LINE_STYLE_XCB_CYBOL_MODEL, p2, (void*) ON_OFF_DASH_LINE_STYLE_XCB_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            v = XCB_LINE_STYLE_ON_OFF_DASH;
            copy_integer(p0, (void*) &v);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb line style. The line style is unknown.");
    }
}

/* LINE_STYLE_XCB_SERIALISER_SOURCE */
#endif
