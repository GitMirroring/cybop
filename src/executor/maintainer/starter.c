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

#ifndef STARTER_SOURCE
#define STARTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/editor.c"
#include "../../executor/maintainer/starter/display/display_starter.c"
#include "../../executor/maintainer/starter/serial_port/serial_port_starter.c"
#include "../../executor/maintainer/starter/socket/socket_starter.c"
#include "../../executor/maintainer/starter/terminal/terminal_starter.c"
#include "../../executor/maintainer/io_starter.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'sense_terminal' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &sense_unix_terminal
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void sense_serial_port(void* p0);
int sense_unix_terminal(void* p0);

/**
 * Starts up the given service.
 *
 * CAUTION! Do NOT rename this function to "startup",
 * since it should be consistent with "shutdown_service",
 * which cannot be renamed to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory data
 * @param p1 the serial filename data
 * @param p2 the serial filename count
 * @param p3 the serial baudrate
 * @param p4 the socket family data (namespace)
 * @param p5 the socket family count
 * @param p6 the socket style data (communication type)
 * @param p7 the socket style count
 * @param p8 the socket protocol data
 * @param p9 the socket protocol count
 * @param p10 the blocking flag
 * @param p11 the socket filename data
 * @param p12 the socket filename count
 * @param p13 the socket host address data
 * @param p14 the socket host address count
 * @param p15 the socket port
 * @param p16 the socket connexions (number of possible pending client requests)
 * @param p17 the socket timeout
 * @param p18 the interrupt request pipe (pointer reference)
 * @param p19 the channel
 */
void startup_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup service.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15);
            // Startup input/output entry.
            startup_io((void*) &io, p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
            // Startup service.
            startup_display(io);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15);
            // Startup input/output entry.
            startup_io((void*) &io, p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
            // Startup service.
            //?? startup_serial_port(io, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15);
            // Startup input/output entry.
            startup_io((void*) &io, p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
            // Startup service.
            startup_socket(io, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The thread function.
            //
            // CAUTION! The function pointer can be determined
            // in TWO WAYS, with or without address operator.
            // Both are resulting in the same pointer (address):
            //
            // void* f = (void*) sense_unix_terminal;
            // void* f = (void*) &sense_unix_terminal;
            //
            void* f = (void*) &sense_unix_terminal;

            //?? fwprintf(stdout, L"Test: Startup (section terminal). f: %i\n", f);

            //
            // Provide thread function ONLY for unix terminal below.
            //
            // CAUTION! A sensing thread for win32 console is NOT necessary,
            // since its input gets sensed in the main thread.
            // Therefore, the function "sense_unix_terminal"
            // and NOT "sense_terminal" is called here.
            //

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15);
            // Startup input/output entry.
#if defined(__linux__) || defined(__unix__)
            startup_io((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, (void*) &f, p18);
#elif defined(__APPLE__) && defined(__MACH__)
            startup_io((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, (void*) &f, p18);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            startup_io((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p15, *NULL_POINTER_STATE_CYBOI_MODEL, p18);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
            // Startup service.
            startup_terminal(io);
            // Configure service.
            edit_service(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TERMINAL_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not startup. The channel is unknown. p19: %i\n", p19);
        fwprintf(stdout, L"Warning: Could not startup. The channel is unknown. *p19: %i\n", *((int*) p19));
    }
}

/* STARTER_SOURCE */
#endif
