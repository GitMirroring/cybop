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
// System interface
//

#include <windowsx.h>

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Updates the win32 display window.
 *
 * @param p0 the internal memory data
 */
void write_win32_display(void* p0) {

    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write win32 display.");

        // Use win32 type.
        HWND wnd = (HWND) w;

        // The opening style.
        int o = SW_SHOWNORMAL;

        // Display window.
        ShowWindow(wnd, o);

        // Write WM_PAINT message to the window in order
        // to make sure its contents gets refreshed.
        //
        // CAUTION! The function sends a WM_PAINT message
        // directly to the window procedure of the specified
        // window, bypassing the application queue.
        // If the update region is empty, no message is sent.
        UpdateWindow(wnd);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write win32 display. The window is null.");
    }
}
