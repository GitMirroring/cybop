/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_GUI_DESERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_GUI_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/deserialiser/gui/button_press_mouse_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/button_release_mouse_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/enter_notify_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/expose_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/key_press_keyboard_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/key_release_keyboard_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/leave_notify_gui_deserialiser.c"
#include "../../../../executor/representer/deserialiser/gui/motion_notify_mouse_gui_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the gui part element content into an action.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the event type data
 * @param p10 the event type count
 * @param p11 the button mask
 * @param p12 the mouse x coordinate
 * @param p13 the mouse y coordinate
 * @param p14 the format data
 * @param p15 the loop break flag
 */
void deserialise_gui_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui part element content.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) EXPOSE_EVENT_GUI_STATE_CYBOL_NAME, p10, (void*) EXPOSE_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_expose(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME, p10, (void*) BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_mouse_button_press(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME, p10, (void*) BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_mouse_button_release(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME, p10, (void*) MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_mouse_motion_notify(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME, p10, (void*) ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_enter_notify(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME, p10, (void*) LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_leave_notify(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME, p10, (void*) KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_keyboard_key_press(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME, p10, (void*) KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_keyboard_key_release(p0, p1, p2, p3, p4, p5, p6, p9, p10, p11, p12, p13, p14, p15);
        }
    }
}

/* CONTENT_ELEMENT_PART_GUI_DESERIALISER_SOURCE */
#endif
