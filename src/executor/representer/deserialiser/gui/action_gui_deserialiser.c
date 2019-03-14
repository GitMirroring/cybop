/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ACTION_GUI_DESERIALISER_SOURCE
#define ACTION_GUI_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cybol/logic/communication/receive_communication_logic_cybol_name.c"
#include "../../../../constant/name/cybol/state/gui/action_gui_state_cybol_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part/name_part_getter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/gui_event/values_gui_event_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the gui action properties.
 *
 * @param p0 the destination properties data
 * @param p1 the destination properties count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the event
 */
void deserialise_gui_action(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui action.");

    // The event name part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
    // The window identification part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed x part.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed y part.
    void* ey = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed width part.
    void* ew = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed height part.
    void* eh = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part.
    void* x = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part.
    void* y = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The button part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The keycode part.
    void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mask part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mode part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    // The event name part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window identification part model item.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed x part model item.
    void* exm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed y part model item.
    void* eym = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed width part model item.
    void* ewm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed height part model item.
    void* ehm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part model item.
    void* xm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part model item.
    void* ym = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The button part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The keycode part model item.
    void* km = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mask part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mode part model item.
    void* mom = *NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    // The window identification part model item data.
    void* wmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed x part model item data.
    void* exmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed y part model item data.
    void* eymd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed width part model item data.
    void* ewmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exposed height part model item data.
    void* ehmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part model item data.
    void* xmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part model item data.
    void* ymd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The button part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The keycode part model item data.
    void* kmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mask part model item data.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mode part model item data.
    void* momd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get event name part.
    get_part_name((void*) &e, p0, (void*) EVENT_ACTION_GUI_STATE_CYBOL_NAME, (void*) EVENT_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
/*??
    // Get window identification part.
    get_part_name((void*) &w, p0, (void*) WINDOW_ACTION_GUI_STATE_CYBOL_NAME, (void*) WINDOW_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get exposed x part.
    get_part_name((void*) &ex, p0, (void*) EXPOSED_X_ACTION_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_X_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get exposed y part.
    get_part_name((void*) &ey, p0, (void*) EXPOSED_Y_ACTION_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_Y_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get exposed width part.
    get_part_name((void*) &ew, p0, (void*) EXPOSED_WIDTH_ACTION_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_WIDTH_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get exposed height part.
    get_part_name((void*) &eh, p0, (void*) EXPOSED_HEIGHT_ACTION_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_HEIGHT_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get mouse x part.
    get_part_name((void*) &x, p0, (void*) X_ACTION_GUI_STATE_CYBOL_NAME, (void*) X_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get mouse y part.
    get_part_name((void*) &y, p0, (void*) Y_ACTION_GUI_STATE_CYBOL_NAME, (void*) Y_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get button part.
    get_part_name((void*) &b, p0, (void*) BUTTON_ACTION_GUI_STATE_CYBOL_NAME, (void*) BUTTON_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get keycode part.
    get_part_name((void*) &k, p0, (void*) KEYCODE_ACTION_GUI_STATE_CYBOL_NAME, (void*) KEYCODE_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get mask part.
    get_part_name((void*) &m, p0, (void*) MASK_ACTION_GUI_STATE_CYBOL_NAME, (void*) MASK_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get mode part.
    get_part_name((void*) &mo, p0, (void*) MODE_ACTION_GUI_STATE_CYBOL_NAME, (void*) MODE_ACTION_GUI_STATE_CYBOL_NAME_COUNT, p1, p2, p3, p4);

/*??
    // Get event name part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get window identification part model item.
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get exposed x part model item.
    copy_array_forward((void*) &exm, ex, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get exposed y part model item.
    copy_array_forward((void*) &eym, ey, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get exposed width part model item.
    copy_array_forward((void*) &ewm, ew, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get exposed height part model item.
    copy_array_forward((void*) &ehm, eh, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mouse x part model item.
    copy_array_forward((void*) &xm, x, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mouse y part model item.
    copy_array_forward((void*) &ym, y, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get button part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get keycode part model item.
    copy_array_forward((void*) &km, k, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mask part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mode part model item.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

/*??
    // Get window identification part model item data.
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get exposed x part model item data.
    copy_array_forward((void*) &exmd, exm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get exposed y part model item data.
    copy_array_forward((void*) &eymd, eym, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get exposed width part model item data.
    copy_array_forward((void*) &ewmd, ewm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get exposed height part model item data.
    copy_array_forward((void*) &ehmd, ehm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mouse x part model item data.
    copy_array_forward((void*) &xmd, xm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mouse y part model item data.
    copy_array_forward((void*) &ymd, ym, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get button part model item data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get keycode part model item data.
    copy_array_forward((void*) &kmd, km, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mask part model item data.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mode part model item data.
    copy_array_forward((void*) &momd, mom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // The default values.
    //
    // CAUTION! If a cybol property is not given, then its value is NULL.
    // In this case, it would cause errors inside the function
    // "deserialise_gui_event_values", which is called below.
    // Therefore, valid DEFAULT values are assigned here.
    //

    // The window identification.
    int window = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The exposed x.
    int exposed_x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The exposed y.
    int exposed_y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The exposed width.
    int exposed_width = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The exposed height.
    int exposed_height = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse x.
    int mouse_x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse y.
    int mouse_y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The button.
    int button = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The keycode.
    int keycode = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mask.
    int mask = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mode.
    int mode = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    copy_integer((void*) &window, w);
    copy_integer((void*) &exposed_x, ex);
    copy_integer((void*) &exposed_y, ey);
    copy_integer((void*) &exposed_width, ew);
    copy_integer((void*) &exposed_height, eh);
    copy_integer((void*) &mouse_x, x);
    copy_integer((void*) &mouse_y, y);
    copy_integer((void*) &button, b);
    copy_integer((void*) &keycode, k);
    copy_integer((void*) &mask, m);
    copy_integer((void*) &mode, mo);

    deserialise_gui_event_values(em, wmd, exmd, eymd, ewmd, ehmd, xmd, ymd, bmd, kmd, mmd, momd, p5);
}

/* ACTION_GUI_DESERIALISER_SOURCE */
#endif
