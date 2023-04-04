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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WIN32_DISPLAY_ENABLER_SOURCE
#define WIN32_DISPLAY_ENABLER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf
#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Enables win32 display event delivery.
 *
 * Remark concerning thread usage:
 *
 * CAUTION! Moving the following code to an own thread in files
 * "win32_display_sensor.c" and "message_win32_display_sensor.c"
 * does NOT work, since the "PeekMessage" function
 * checks the message queue of the CALLING thread ONLY.
 *
 * If it was called within an external "sensing" thread,
 * then messages of the cyboi main thread
 * (to which all windows belong) would never get recognised.
 * Therefore, this MAIN THREAD has to check for messages.
 *
 * @param p0 the destination sender client window identification
 * @param p1 the server entry
 */
void enable_win32_display(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable win32 display.");
    fwprintf(stdout, L"Debug: Enable win32 display. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Enable win32 display. *p0: %i\n", *((int*) p0));

    //
    // The event message.
    //
    // CAUTION! It gets stored in input/output entry below,
    // in order to forward and use it in further functions.
    //
    // It is cyboi's responsibility to FREE this
    // event message again later on.
    //
    void* msg = malloc(sizeof (MSG));
    //
    // The window.
    //
    // CAUTION! It is initialised with NULL, so that ALL messages
    // of the current thread are received, which includes BOTH:
    //
    // - window messages of any window that belongs to the current thread
    // - thread messages whose window handle is null (hwnd value NULL in MSG structure)
    //
    HWND wnd = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get message from application's message queue.
    //
    // Meaning of the return value:
    // - NONZERO (TRUE): a message IS available;
    // - ZERO (FALSE): there is NO message available.
    //
    // The third and fourth argument may be used for message filtering.
    // They are BOTH set to ZERO in order to DEACTIVATE filtering
    // and to return ALL available messages.
    //
    // For the last argument, one can choose between:
    // - PM_NOREMOVE: just peek ahead and leave message in queue;
    // - PM_REMOVE: finally remove message from queue.
    //
    BOOL b = PeekMessage((MSG*) msg, wnd, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_REMOVE);

    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // Set event into ?? TODO: client OR server entry input buffer.
        copy_array_forward(p1, (void*) &msg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* WIN32_DISPLAY_ENABLER_SOURCE */
#endif
