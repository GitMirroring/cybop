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

//
// System interface
//

#include <errno.h> // errno
#include <stddef.h> // size_t
#include <stdio.h> // stdout
#include <unistd.h> // write
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Writes data.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination file descriptor (a file, serial port, terminal, socket)
 * @param p1 the source buffer item
 * @param p2 the source buffer type
 * @param p3 the source buffer mutex
 * @param p4 the loop break flag
 */
void write_basic(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic.");
        //?? fwprintf(stdout, L"Debug: Write basic. f: %i\n", f);
        //?? fwprintf(stdout, L"Debug: Write basic. *f: %i\n", *((int*) f));

        // The buffer item data, count.
        void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Lock mutex.
        //
        // CAUTION! New data may be written into the source buffer in
        // the main thread, in case this writer is called asynchronously
        // in a thread. But the already WRITTEN data are REMOVED from
        // the source buffer below. Therefore, exclusive access has
        // to be guaranteed here using a mutex.
        //
        // CAUTION! The mutex also has to cover the actual WRITE function,
        // since the buffer pointer handed over may otherwise CHANGE,
        // when the main thread writes new data into the buffer.
        // For the same reason, the mutex has to cover the
        // RETRIEVAL of data and count from the item.
        //
        lock(p3);

        //
        // Get buffer item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &bd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //
        // Cast buffer count to correct size type.
        //
        // CAUTION! It IS NECESSARY because on 64 Bit machines,
        // the "size_t" type has a size of 8 Byte, whereas
        // the "int" type has the usual size of 4 Byte.
        // When trying to dereference a pointer that uses the other type,
        // memory errors will occur and the valgrind memcheck tool report:
        // "Invalid read of size 8".
        //
        int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        copy_integer((void*) &s, bc);
        size_t st = (size_t) s;
        //?? fwprintf(stdout, L"Debug: Write basic. st: %i\n", st);

        //
        // Initialise error number.
        //
        // It is a global variable and other functions
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Write data to device given by the file descriptor.
        //
        // CAUTION! Using the function "send" is NOT necessary,
        // since its flags argument (fourth one) would be zero,
        // because no special options are needed.
        // Therefore, the function "write" suffices here.
        //
        // CAUTION! The function "write" is BLOCKING by default.
        // So, there is NO reason to set the blocking mode
        // manually using the functions "ioctl" or "setsockopt".
        //
        // CAUTION! The write operation does not necessarily
        // handle all the bytes handed over to it, because
        // its major focus is handling the (network) buffers.
        // In general, it returns when the associated
        // (network) buffers have been filled.
        // It then returns the number of handled bytes.
        //
        // Therefore, this "write" function has to be called
        // in a LOOP, until all data have been transmitted.
        //
        ssize_t nb = write(*f, bd, st);

        // Cast number of bytes actually written to general type.
        int n = (int) nb;

        if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic. Success.");
            //?? fwprintf(stdout, L"Debug: Write basic. Success. n: %i\n", n);

            //
            // Remove written data from source buffer.
            //
            // CAUTION! This is IMPORTANT, so that in the next loop
            // cycle, only the REMAINING data are transmitted.
            //
            // CAUTION! Do NOT use the function "modify_array" here,
            // but "modify_item" instead.
            //
            // CAUTION! Do NOT hand over the buffer count but rather
            // the number of bytes ACTUALLY WRITTEN for specifying
            // the number of elements to be removed.
            //
            // CAUTION! Set the adjust count flag to TRUE since otherwise,
            // the buffer item will hold a wrong COUNT number leading
            // to unpredictable errors in further processing.
            // Do NOT worry about the SIZE which does NOT get changed.
            //
            modify_item(p1, *NULL_POINTER_STATE_CYBOI_MODEL, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_greater_or_equal((void*) &r, (void*) &n, bc);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // ALL data have been transmitted.
                //

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic. All data have been transmitted.");
                //?? fwprintf(stdout, L"Debug: Write basic. All data have been transmitted. r: %i\n", r);

                //
                // Set loop break flag.
                //
                // CAUTION! The flag is set ONLY if ALL data
                // have been transmitted.
                //
                copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // Socket communication:
            //
            // A return value of ZERO means the other end (peer)
            // CLOSED the socket connexion.
            // Therefore, the socket on this side may be closed,
            // since the other side has closed its connexion.
            //
            // CAUTION! Do NOT close socket directly here.
            // If this is a client socket, then its client entry
            // resources have to be freed as well, which is done
            // in the calling function. Therefore, just set the flag.
            //

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. Setting close flag now.");
            fwprintf(stdout, L"Warning: Could not write basic. Setting close flag now. n: %i\n", n);
            fwprintf(stdout, L"Hint: Did you OPEN the device, e.g. standard terminal or file?\n");
            fwprintf(stdout, L"Hint: Possibly, the buffer is empty or null. bc: %i\n", bc);

            // Set loop break flag.
            copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. An error occured.");
            fwprintf(stdout, L"Error: Could not write basic. An error occured. Possibly, the buffer is null. n: %i\n", n);
            log_error((void*) &errno);
            fwprintf(stdout, L"Hint: Does the file path exist?\n");
            fwprintf(stdout, L"Hint: Did you OPEN the device, for example standard terminal or file?\n");
            fwprintf(stdout, L"Hint: Did you forget to specify the cybol \"mode\" property with value \"write\" when opening the file?\n");

            // Set loop break flag.
            copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        // Unlock mutex.
        unlock(p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The destination file descriptor is null.");
        fwprintf(stdout, L"Error: Could not write basic. The destination file descriptor is null. p0: %i\n", p0);
    }
}
