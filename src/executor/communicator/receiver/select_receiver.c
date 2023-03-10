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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SELECT_RECEIVER_SOURCE
#define SELECT_RECEIVER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Selects a suitable source buffer and stores it in the destination.
 *
 * This is important since buffers differ for the various channels.
 *
 * CAUTION! Using the "encoding" parametre as criterion is NOT helpful, since:
 * - for "inline" channel: it is NULL, but "wchar_t" is needed for sending;
 * - for "text/html" language: it is NOT NULL, and "char" is needed for sending.
 * Therefore, the correct buffer gets selected via CHANNEL here.
 *
 * @param p0 the destination buffer (pointer reference)
 * @param p1 the source model buffer (pointer reference)
 * @param p2 the source void* buffer (pointer reference)
 * @param p3 the source long long int buffer (pointer reference)
 * @param p4 the source wchar_t buffer (pointer reference)
 * @param p5 the channel
 */
void receive_select(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive select.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CLOCK_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use long long int buffer.
            //
            // For instance, a time is returned by the system as long int,
            // so that it matches into a long long int variable.
            //
            copy_pointer(p0, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use void* buffer.
            //
            // An event is returned as message with special structure,
            // which is why a simple void* gets used as pointer to
            // that event message.
            //
            copy_pointer(p0, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use wchar_t buffer.
            //
            // All inline models are already available as wide character,
            // and do NOT have to get decoded below, so that wchar_t is used.
            //
            copy_pointer(p0, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) RANDOMISER_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use long long int buffer.
            //
            // Even if randomisation functions return a simple int,
            // that one matches into a long long int variable.
            //
            copy_pointer(p0, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use model buffer.
            //
            // A next signal part retrieved from signal memory,
            // does NOT have to be processed further here in any form,
            // i.e. the model can be used DIRECTLY.
            //
            copy_pointer(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use wchar_t buffer for most platforms,
            // since the multibyte character is converted to a
            // wide character internally in glibc function "fgetwc".
            //
            // Use void* buffer for win32, since it uses
            // a special INPUT_RECORD structure for storage.
            //

#if defined(__linux__) || defined(__unix__)
            // Use the CHARACTER buffer, which was assigned
            // as default in file "receiver.c" already.
            // Therefore, do NOTHING here.
#elif defined(__APPLE__) && defined(__MACH__)
            // Use the CHARACTER buffer, which was assigned
            // as default in file "receiver.c" already.
            // Therefore, do NOTHING here.
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            copy_pointer(p0, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }
}

/* SELECT_RECEIVER_SOURCE */
#endif
