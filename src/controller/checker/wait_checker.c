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

#ifndef WAIT_CHECKER_SOURCE
#define WAIT_CHECKER_SOURCE

#ifdef WIN32
    #include <windows.h>
#elif defined GNU_LINUX_OPERATING_SYSTEM
    #include <xcb/xcb.h>
#endif

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../executor/runner/sleeper.c"
#include "../../logger/logger.c"

/**
 * Waits for an interrupt request.
 *
 * @param p0 the signal memory sleep time
 * @param p1 the internal memory data
 */
void check_wait(void* p0, void* p1) {

    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // The cyboi service interrupt request.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The display interrupt request.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial port interrupt request.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal interrupt request.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The www service interrupt request.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef WIN32
    // The return value.
    BOOL b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
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
#elif defined GNU_LINUX_OPERATING_SYSTEM
    // The connexion.
    void* con = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* evt = *NULL_POINTER_STATE_CYBOI_MODEL;
#endif

    // Get interrupt requests.
    //
    // CAUTION! They actually do not have to be retrieved again each time,
    // since they were allocated as steady variable at system startup.
    // That is, it would be possible to retrieve them just once at startup
    // and forward them as parametres via all function calls.
    // But this would be tedious, worsen overview and moreover, further services
    // and interrupt request variables may have to be introduced one day,
    // which would make it necessary to adapt all function signatures then.
    // Therefore, these variables are used locally just here.
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    copy_array_forward((void*) &d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &t, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &w, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
#ifdef GNU_LINUX_OPERATING_SYSTEM
    // Get connexion.
    copy_array_forward((void*) &con, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
#endif

    //
    // REMARK! The following variable checks and casts are not indented,
    // since many more variables may have to be added in the future,
    // so that indentation would lead to unreadable source code here.
    //

    if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

    if (t != *NULL_POINTER_STATE_CYBOI_MODEL) {

    if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Wait for an interrupt request.");

        //
        // Sleep for some time.
        //
        // If no signals are waiting in the signal memory (queue)
        // and no hardware requests have been received from either the:
        // - terminal
        // - display
        // - www service
        // - cyboi service
        // then cpu processing time may be saved by sending the system to sleep.
        //
        // Several possibilities have been considered to achieve this:
        //
        // 1 pause
        //
        // The simplicity of pause can conceal serious timing errors
        // that can make a program hang mysteriously.
        // One can't safely use pause to wait until one more signal
        // arrives, and then resume real work. Even if one arranges
        // for the signal handler to cooperate by setting a flag,
        // one still can't use pause reliably.
        //
        // Example:
        // // The irq flag is set by some signal handler.
        // if (irq == 0) {
        //     pause();
        // }
        // // Do work once the signal arrives.
        // ...
        //
        // This has a bug: the signal could arrive after the variable
        // irq is checked, but before the call to pause. If no further
        // signals arrive, the process would never wake up again.
        //
        // 2 sleep
        //
        // One can put an upper limit on the excess waiting by using
        // sleep in a loop, instead of using pause.
        //
        // Example:
        // // The irq flag is set by some signal handler.
        // while (irq == 0) {
        //     sleep(1);
        // }
        // // Do work once the signal arrives.
        // ...
        //
        // For some purposes, that is good enough.
        //
        // 3 signals of the operating system
        //
        // With a little more complexity, one can wait reliably until
        // a particular signal handler is run, using sigsuspend.
        //
        // Solution in CYBOI
        //
        // The signal handler approach was tried out and implemented.
        // However, when the process was sent to sleep with sigsuspend,
        // all its threads were sleeping as well. This is a problem,
        // because the input/output (including user interface control)
        // is running in special threads. Since these were sleeping,
        // there was no way to wake up the CYBOI system on user request.
        //
        // Another approach was to let the input/output run in their
        // own process (instead of only a thread), each.
        // The problem here is resource sharing between the processes.
        // While threads use the same resources as their parent process,
        // child processes copy their parent process' resources at
        // creation and afterwards work independently on their own resources.
        // This is a problem because CYBOI's signal memory needs to be
        // accessed by all input/output processes without conflicts.
        //
        // Furthermore, the usage of operating system signals enforces
        // a global interrupt request flag variable. Since a signal
        // handler procedure may receive only the numeric code of the
        // signal, but not further parametres, the interrupt request
        // flag may not be handed over within the internal memory and
        // a global flag would have to be used, which is undesirable.
        //
        // Therefore, the decision fell on the usage of a simple SLEEP
        // procedure, which seems sufficient for the purposes of CYBOI.
        //

//?? fwprintf(stdout, L"TEST wait *sl: %i\n", *((int*) p0));

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (
            (*((int*) c) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
            || (*((int*) d) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
            || (*((int*) s) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
            || (*((int*) t) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
            || (*((int*) w) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                break;

            } else {

#ifdef WIN32
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
                b = PeekMessage(&msg, wnd, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_NOREMOVE);

                if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // CAUTION! Setting a mutex is NOT necessary here,
                    // since this is the main thread and no other threads
                    // are writing to the interrupt request variable.

                    // Set display interrupt request to indicate
                    // that a message has been received via display,
                    // which may now be processed in the main thread of this system.
                    copy_integer(d, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    break;
                }

#elif defined GNU_LINUX_OPERATING_SYSTEM
                evt = (void*) xcb_poll_for_event((xcb_connection_t*) con);

                // Get next event available from the server.
                // If none is available, NULL gets returned.
                //
                // CAUTION! The event gets REMOVED from the queue
                // by the "xcb_poll_for_event" function.
                // It therefore HAS TO BE STORED temporarily
                // in internal memory, in order to be able to
                // process it later on in "executor/receiver/".
                //
                // The ideal solution would be a blocking xcb function
                // running in an own sensing thread in files
                // "x_window_system_sensor.c" and "message_x_window_system_sensor.c".
                //
                // The xcb developers have been asked to add a function like
                // "xcb_test_for_event" that would return on availability
                // of an event WITHOUT ACTUALLY REMOVING the event from the queue.
                // However, the xcb developers did not like the idea for now.
                //
                // See mailing list discussion in xcb project:
                // http://stackoverflow.com/questions/15775281/need-for-xeventsqueueddisplay-queuedafterreading-in-xcb
                // http://lists.freedesktop.org/archives/xcb/2013-April/008219.html
                // http://lists.freedesktop.org/archives/xcb/2013-May/008245.html
                // http://lists.freedesktop.org/archives/xcb/2013-May/008249.html
                // http://xcb.freedesktop.org/
                //
                // Therefore, this workaround here in the main thread is necessary.
                if (evt != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // Store event in internal memory.
                    copy_array_forward(p1, (void*) &evt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                    // CAUTION! Setting a mutex is NOT necessary here,
                    // since this is the main thread and no other threads
                    // are writing to the interrupt request variable.

                    // Set display interrupt request to indicate
                    // that a message has been received via display,
                    // which may now be processed in the main thread of this system.
                    copy_integer(d, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    break;
                }

#endif
                sleep_nano(p0);
            }
        }

/*??
fwprintf(stdout, L"TEST wait *cyboi_service_irq: %i\n", *((int*) c));
fwprintf(stdout, L"TEST wait *display_irq: %i\n", *((int*) x));
fwprintf(stdout, L"TEST wait *serial_port_irq: %i\n", *((int*) s));
fwprintf(stdout, L"TEST wait *terminal_irq: %i\n", *((int*) t));
fwprintf(stdout, L"TEST wait *www_service_irq: %i\n", *((int*) w));
*/

        // The sleep loop above is left as soon as at least one of the
        // interrupt variables is set to a value other than false (zero).
        // This may happen if some user action is noted in one of the
        // receive threads, e.g. terminal, display, tcp socket.
        // In this case, probably a signal was placed in the signal memory and
        // the corresponding interrupt variable set to true (one).

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not wait for an interrupt request. The cyboi service interrupt request is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not wait for an interrupt request. The display interrupt request is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not wait for an interrupt request. The serial port interrupt request is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not wait for an interrupt request. The terminal interrupt request is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not wait for an interrupt request. The www service interrupt request is null.");
    }
}

/* WAIT_CHECKER_SOURCE */
#endif
