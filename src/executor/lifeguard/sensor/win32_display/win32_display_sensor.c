/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_DISPLAY_SENSOR_SOURCE
#define WIN32_DISPLAY_SENSOR_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Senses win32 display messages.
 *
 * @param p0 the interrupt request
 * @param p1 the break flag
 */
void sense_win32_display(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense win32 display.");

    // The message structure.
    //
    // It just serves as placeholder here, since
    // the message is read and removed only later,
    // in the main thread.
    MSG msg;
    // The window.
    //
    // CAUTION! It is initialised with null,
    // so that not only the main window's messages,
    // but all messages of the thread are received.
    //
    // This is important if using a dialogue window
    // besides the main window, for example.
    // CYBOI will then have to find out internally,
    // to which window a message belongs.
    // It thus has to keep a list of existing windows
    // in a container structure stored in internal memory.
    HWND wnd = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! Moving the following code to an own thread in files
    // "win32_display_sensor.c" and "message_win32_display_sensor.c"
    // does NOT work, since the "PeekMessage" function
    // checks the message queue of the CALLING thread ONLY.
    //
    // If it was called within an external "sensing" thread,
    // then messages of the cyboi main thread
    // (to which all windows belong) would never get recognised.
    // Therefore, this main thread has to check for messages.
    //
    // CAUTION! The message MUST NOT be removed here,
    // since it has to be read again in a "receive" function,
    // where the actual processing happens.
    // This call here is just made to detect available messages.
    BOOL b = PeekMessage(&msg, wnd, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_NOREMOVE);

    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // CAUTION! Setting a mutex is NOT necessary here,
        // since this is the main thread and no other threads
        // are writing to the interrupt request variable.

        // Set display interrupt request to indicate
        // that a message has been received via display,
        // which may now be processed in the main thread of this system.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // Set break flag.
        copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* WIN32_DISPLAY_SENSOR_SOURCE */
#endif
