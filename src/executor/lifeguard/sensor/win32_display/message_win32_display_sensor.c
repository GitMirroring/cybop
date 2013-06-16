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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_WIN32_DISPLAY_SENSOR_SOURCE
#define MESSAGE_WIN32_DISPLAY_SENSOR_SOURCE

#include <pthread.h>
#include <windows.h>

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/runner/sleeper.c"

/**
 * Senses win32 display message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 */
void sense_win32_display_message(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* irq = (int*) p0;

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // Also, this function runs in an endless loop and would produce huge log files.

            // The message structure.
            //
            // It just serves as placeholder here, since
            // the message is read and removed only later,
            // in the main thread.
            MSG m;

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
            HWND w = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Get message from application's message queue.
            //
            // The Win32 API:
            // http://msdn.microsoft.com/en-us/library/windows/desktop/ms632590(v=vs.85).aspx
            //
            // describes, among others, these functions:
            // - GetMessage (blocking)
            // - PeekMessage (non-blocking)
            //
            // Also, there are these functions:
            // - GetQueueStatus
            // - GetInputState
            //
            // Some reasons for why they might be useful are here:
            // http://msdn.microsoft.com/en-us/library/windows/desktop/ms644928(v=vs.85).aspx#examining_queue
            //
            // Using "PeekMessage", one can choose between "PM_NOREMOVE" and
            // "PM_REMOVE", to be handed over as last argument.
            //
            // CAUTION! Do NOT remove the message from the queue with flag PM_REMOVE here!
            // The message is read and removed only later, in the main thread.
            //
            // IF a message is available, the return value is NONZERO (TRUE).
            // If NO messages are available, the return value is ZERO (FALSE).
            // The loop sleeps if no messages are available.
            //
fwprintf(stdout, L"TEST sense win32 display message time: %i\n", *((int*) p2));
            while (!PeekMessage(&m, w, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_NOREMOVE)) {

fwprintf(stdout, L"TEST sense win32 display message loop: %i\n", irq);
                sleep_nano(p2);
            }

fwprintf(stdout, L"TEST sense win32 display message post: %i\n", *((int*) p2));

            // Lock display mutex.
            pthread_mutex_lock(mt);

            // Set display interrupt request to indicate
            // that a message has been received via display,
            // which may now be processed in the main thread of this system.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Unlock display mutex.
            pthread_mutex_unlock(mt);

            // Access irq as atomic variable.
            // CAUTION! Therefore better don't use the following line:
            // while (*irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            while (*irq) {

                // Sleep as long as the display interrupt is not handled and reset yet.
                //
                // This is to give the central processing unit (cpu) some
                // time to breathe, that is to be idle or to process other signals.
                //
                // Also, many window inputs are processed at once in the main thread
                // and only if there are no further inputs to be read, the irq flag is reset,
                // so that this endless loop can be left and new inputs detected.
                sleep_nano(p2);
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense win32 display message. The interrupt is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense win32 display message. The mutex is null.");
    }
}

/* MESSAGE_WIN32_DISPLAY_SENSOR_SOURCE */
#endif
