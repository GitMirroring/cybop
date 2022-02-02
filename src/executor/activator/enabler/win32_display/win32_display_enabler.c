/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WIN32_DISPLAY_ENABLER_SOURCE
#define WIN32_DISPLAY_ENABLER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

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
 * @param p0 the data available flag
 * @param p1 the input/output entry (containing e.g. event)
 */
void enable_win32_display(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable win32 display.");

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
    // CAUTION! It is initialised with null,
    // so that not only the main window's messages,
    // but ALL messages of the thread are received.
    //
    // This is important if using a dialogue window
    // besides the main window, for example.
    // CYBOI will then have to find out internally,
    // to which window a message belongs.
    // It thus has to keep a list of existing windows.
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
    // They are BOTH set to zero in order to deactivate filtering
    // and to return ALL available messages.
    //
    // CAUTION! The message MUST NOT be removed here,
    // since it has to be read again in a "receive" function,
    // where the actual processing happens.
    // This call here is just made to detect available messages.
    //
    // For the last argument, one can choose between:
    // - PM_NOREMOVE: just peek ahead and leave message in queue;
    // - PM_REMOVE: finally remove message from queue.
    //
    // CAUTION! Since xcb for the x window system under linux does NOT
    // offer peeking ahead, the message gets removed there and
    // therefore has to be stored in input/output entry of internal memory.
    // The win32 functions DO ALLOW peeking ahead.
    // However, in order to have a UNIFORM HANDLING,
    // it was decided to REMOVE the message here as well,
    // just as is done in file "xcb_sensor.c".
    // The event stored in the input/output entry of internal memory
    // gets processed later, within the deserialiser.
    //
    BOOL b = PeekMessage((MSG*) msg, wnd, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_REMOVE);

    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        //
        // Set event into input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        copy_array_forward(p1, (void*) &msg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Set data available flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* WIN32_DISPLAY_ENABLER_SOURCE */
#endif
