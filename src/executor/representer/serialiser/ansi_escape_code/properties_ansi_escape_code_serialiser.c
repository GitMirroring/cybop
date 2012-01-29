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

#ifndef PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/begin_tag_html_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the properties into ansi escape code.
 *
 * @param p0 the destination item
 * @param p1 the source properties data
 * @param p2 the source properties count
 * @param p3 the source whole properties data
 * @param p4 the source whole properties count
 */
void serialise_ansi_escape_code_properties(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code properties.");

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part.
    void* sh = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cell part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part.
    void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part.
    void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part.
    void* bo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hidden part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The inverse part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blink part.
    void* bl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The underline part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bold part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part.
    void* wp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part.
    void* ws = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get property parts by name.
    get_name_array((void*) &super, p1, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &sh, p1, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &l, p1, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &c, p1, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &p, p1, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &s, p1, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &bg, p1, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &fg, p1, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &bo, p1, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &h, p1, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &i, p1, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &bl, p1, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &u, p1, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
    get_name_array((void*) &b, p1, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);

    //
    // Get default property parts from super part.
    //
    // If a standard property value DOES exist, it is NOT
    // overwritten with the default property value of the super part.
    // If a standard property value does NOT exist, the default
    // property value of the super part is used.
    //

    if (*sh == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &sh, supermd, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*l == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &l, supermd, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*c == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &c, supermd, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*p == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &p, supermd, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &s, supermd, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &bg, supermd, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &fg, supermd, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*bo == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &bo, supermd, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*h == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &h, supermd, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*i == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &i, supermd, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*bl == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &bl, supermd, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*u == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &u, supermd, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    if (*b == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_name_array((void*) &b, supermd, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
    }

    // Get property parts from whole part.
    get_name_array((void*) &wp, p3, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &ws, p3, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p4);

    // Encode shape.
    serialise_ansi_escape_code_shape(p0, h, i, bl, u, b, bg, fg, p, s, wp, ws, bo, c, l, sh);
}

/* PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
