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

#ifndef WIN32_DISPLAY_SENDER_SOURCE
#define WIN32_DISPLAY_SENDER_SOURCE

#include <windowsx.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../logger/logger.c"

/**
 * Updates the win32 display window.
 *
 * @param p0 the internal memory data
 */
void send_win32_display(void* p0) {

    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send win32 display.");

        // Use win32 type.
        HWND wnd = (HWND) w;

        // The opening style.
        int o = SW_SHOWNORMAL;

        // Display window.
        ShowWindow(wnd, o);

        // Send WM_PAINT message to the window in order
        // to make sure its contents gets refreshed.
        //
        // CAUTION! The function sends a WM_PAINT message
        // directly to the window procedure of the specified
        // window, bypassing the application queue.
        // If the update region is empty, no message is sent.
        UpdateWindow(wnd);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send win32 display. The window is null.");
    }
}

/* WIN32_DISPLAY_SENDER_SOURCE */
#endif
