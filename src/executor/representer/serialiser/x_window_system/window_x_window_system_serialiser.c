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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOW_X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define WINDOW_X_WINDOW_SYSTEM_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the window into x window system.
 *
 * @param p0 the connexion
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source whole properties data
 * @param p7 the source whole properties count
 * @param p8 the knowledge memory part
 */
void serialise_x_window_system_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise x window system window.");

    //?? TODO:
    // http://xcb.freedesktop.org/manual/group__XCB____API.html

    // The title model data terminated item.
    void* tmdt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon title model data terminated item.
    void* itmdt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The title model data terminated item data.
    void* tmdtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon title model data terminated item data.
    void* itmdtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The value mask.
    // CAUTION! It is possible to set several attributes
    // at the same time by OR'ing these values in valuemask.
    uint32_t mask = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y | XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
    // The values.
    // CAUTION! They have to be IN THE SAME ORDER
    // as given in the value mask above.
    uint32_t values[4];

    // Allocate title model data terminated item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &tmdt, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate icon title model data terminated item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &itmdt, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode title model data terminated wide character- into multibyte character data.
    encode_utf_8(tmdt, tmd, tmc);
    // Encode icon title model data terminated wide character- into multibyte character data.
    encode_utf_8(itmdt, itmd, itmc);

    // Initialise values.
    // CAUTION! Initialise values BEFORE using them
    // in function calls further below.
    // Otherwise, the window configuration will fail.
    values[0] = pmdx;
    values[1] = pmdy;
    values[2] = smdx;
    values[3] = smdy;

    // Add null termination character to title model data terminated.
    append_item_element(tmdt, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Add null termination character to icon title model data terminated.
    append_item_element(itmdt, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Get title model data terminated item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &tmdtd, tmdt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get icon title model data terminated item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &itmdtd, itmdt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Set title.
    // CAUTION! The sixth parametre specifies
    // the format of the property (8, 16, 32).
    // However, number 32 (= 4 byte) for
    // specifying "wchar_t" data did NOT work.
    // Therefore, "char" data with string
    // termination character are used now.
    xcb_change_property(connexion, XCB_PROP_MODE_REPLACE, *window, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, *NUMBER_8_INTEGER_STATE_CYBOI_MODEL, strlen(tmdtd), tmdtd);
    // Set icon title.
    xcb_change_property(connexion, XCB_PROP_MODE_REPLACE, *window, XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING, *NUMBER_8_INTEGER_STATE_CYBOI_MODEL, strlen(itmdtd), itmdtd);
    // Set icon
    //?? TODO
    //?? xcb_change_property(connexion, XCB_PROP_MODE_REPLACE, *window, XCB_ATOM_WM_ICON, XCB_ATOM_CARDINAL, *NUMBER_32_INTEGER_STATE_CYBOI_MODEL, *imci, imd);
    // Configure window position and size.
    xcb_configure_window(connexion, *window, mask, values);

    // Deallocate title model data terminated item.
    deallocate_item((void*) &tmdt, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate icon title model data terminated item.
    deallocate_item((void*) &itmdt, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* WINDOW_X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
