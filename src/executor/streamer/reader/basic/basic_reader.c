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

#ifndef BASIC_READER_SOURCE
#define BASIC_READER_SOURCE

#include <errno.h> // errno
#include <stddef.h> // size_t
#include <unistd.h> // read

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/locker/locker.c"
#include "../../../../executor/locker/unlocker.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

//
// Reflexions on reading characters from terminal file descriptor.
//
// 1 buffer array to STORE ansi escape codes
//
// Some input arrives not as a single character but
// rather as ansi escape code SEQUENCE of many characters,
// e.g. the keyboard button "arrow up" as three characters:
// ESC + [ + A
//
// 2 fgetwc reads ONLY ONE character at a time
//
// The cyboi interpreter is using wide characters only.
// When starting up, the standard input/output/error streams
// are "oriented" to wide character. Therefore, using STREAM
// functions such as "fgetwc" would be the easy and desirable way.
//
// 3 mutex to ensure EXCLUSIVE ACCESS to the pipe
//
// An ansi escape code sequence BELONGS TOGETHER and
// must not be written in single bytes to the pipe
// since otherwise, the main thread processes them separately.
//
// 4 fread to AVOID BLOCKING
//
// The function "fgetwc" BLOCKS so that it is impossible
// to find out whether or not an escape character is standalone
// or the beginning of an ansi escape code sequence.
//
// 5 read to AVOID BUSY WAITING
//
// The function "fread" does NOT block, so that an ENDLESS LOOP
// steadily checking for new input is necessary (busy waiting).
//
// 6 decode_utf_8 for CONVERSION to wide characters
//
// The function "read" is using a file descriptor and NOT stream.
// Therefore, wide characters as mentioned above are NOT provided
// and multibyte character sequences returned instead.
// These have to be decoded into wide characters yet,
// before sending them to the pipe further below.
//

/**
 * Reads data.
 *
 * CAUTION! Do NOT rename this function to "read",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor (a file, serial port, terminal, socket)
 * @param p2 the fragment data
 * @param p3 the fragment size
 * @param p4 the destination mutex
 * @param p5 the exit flag
 * @param p6 the close flag
 */
void read_basic(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ms = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* f = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read basic.");
                    fwprintf(stdout, L"Debug: Read basic. s: %i\n", f);
                    fwprintf(stdout, L"Debug: Read basic. *s: %i\n", *((int*) f));

                    // Cast fragment size to correct type.
                    size_t mst = (size_t) *ms;
                    fwprintf(stdout, L"Debug: Read basic. mst: %i\n", mst);

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
                    // Read data from file descriptor.
                    //
                    // CAUTION! Using the function "recv" is NOT necessary,
                    // since its flags argument (fourth one) would be zero,
                    // because no special options are needed.
                    // Therefore, the function "read" suffices here.
                    //
                    // CAUTION! The function "read" is BLOCKING by default.
                    // So, there is NO reason to set the blocking mode
                    // manually using the functions "ioctl" or "setsockopt".
                    //
                    // CAUTION! Do NOT set the option MSG_WAITALL, which requests
                    // the operation to block until all data have been received.
                    // It is impossible to predict the size of the incoming data,
                    // so that it is not clear how big the buffer array shall be.
                    // Therefore, call "read" in a loop until no more data are available.
                    //
                    fwprintf(stdout, L"Debug: Read basic. Waiting for input on file descriptor *f: %i\n", *f);
                    ssize_t nb = read(*f, p2, mst);

//?? TEST BEGIN --
                    //?? int test = fileno(stdin);
                    //?? fwprintf(stdout, L"Debug: Read basic. Waiting for input on file descriptor test: %i\n", test);
                    //?? ssize_t nb = read(test, p2, mst);
//?? TEST END --

                    // Cast number of bytes actually read to general type.
                    int n = (int) nb;

                    fwprintf(stdout, L"Debug: Read basic. n: %i\n", n);
                    fwprintf(stdout, L"Debug: Read basic. p2 + 0: %i\n", *((char*) (p2 + 0)));
                    fwprintf(stdout, L"Debug: Read basic. p2 + 1: %i\n", *((char*) (p2 + 1)));
                    fwprintf(stdout, L"Debug: Read basic. p2 + 2: %i\n", *((char*) (p2 + 2)));

                    if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read basic. Copy fragment data into destination item.");
                        fwprintf(stdout, L"Debug: Read basic. Copy fragment data into destination item. p2: %s\n", (char*) p2);

                        // The comparison result.
                        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        //
                        // Lock mutex.
                        //
                        // CAUTION! Set this lock BEFORE comparing with the exit flag below
                        // since otherwise, a race condition might occur.
                        //
                        // Example:
                        // - the exit flag is not set
                        // - the sensing child thread enters the block with r != 0
                        // - the main thread receives some shutdown cybol operation
                        // - the main thread sets the exit flag only now
                        // - the main thread shuts down and deallocates the destination item
                        // - the sensing child thread decodes characters
                        // - the sensing child thread possibly reallocates the (non-existing) destination item
                        // - this leads to memory errors such as "corrupted double-linked list"
                        //
                        // The reallocation of a non-existing array would lead to the error
                        // "realloc(): invalid pointer".
                        //
                        lock(p4);

                        compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            //
                            // The exit flag was NOT set in the main thread.
                            // Therefore, proceed normally.
                            //

                            fwprintf(stdout, L"Debug: Read basic. Modify destination item. r: %i\n", r);

                            //
                            // Copy fragment data into destination item.
                            //
                            // CAUTION! Use APPEND and NOT overwrite here, since data
                            // still standing in the destination item must not be overwritten.
                            // This can happen if reading data from terminal in the
                            // child thread is faster than their processing in the main thread.
                            //
                            modify_item(p0, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            //?? TEST BEGIN
                            void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
                            void* testc = *NULL_POINTER_STATE_CYBOI_MODEL;
                            copy_array_forward((void*) &testd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                            copy_array_forward((void*) &testc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
                            fwprintf(stdout, L"Debug: Read basic. testc: %i\n", testc);
                            fwprintf(stdout, L"Debug: Read basic. *testc: %i\n", *((int*) testc));
                            fwprintf(stdout, L"Debug: Read basic. testd + 0: %i\n", *((char*) (testd + 0)));
                            fwprintf(stdout, L"Debug: Read basic. testd + 1: %i\n", *((char*) (testd + 1)));
                            fwprintf(stdout, L"Debug: Read basic. testd + 2: %i\n", *((char*) (testd + 2)));
                            //?? TEST END
                        }

                        // Unlock mutex.
                        unlock(p4);

                    } else if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        //
                        // A return value of zero indicates end-of-file
                        // (except if the fragment size is also zero).
                        // This is NOT considered an error.
                        //

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read basic. Set close flag.");
                        fwprintf(stdout, L"Debug: Read basic. Set close flag. n: %i\n", n);

                        //
                        // Set close flag.
                        //
                        // CAUTION! This is relevant for socket communication.
                        // A return value of ZERO means the other end (peer, server)
                        // CLOSED the socket connexion. It never means there was no data.
                        //
                        // Standard behaviour:
                        // - blocking mode: "read" will block
                        // - non-blocking mode: it will return -1 if there is no data
                        //   with errno set to EAGAIN or EWOULDBLOCK, depending on the platform
                        //
                        // https://stackoverflow.com/questions/12773509/read-is-not-blocking-in-socket-programming
                        //
                        // Therefore, the socket on this side may be closed,
                        // since the other side has closed its connexion.
                        //
                        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. An error occured.");
                        fwprintf(stdout, L"Error: Could not read basic. An error occured. %i\n", r);
                        log_errno((void*) &errno);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The destination item is null.");
                    fwprintf(stdout, L"Error: Could not read basic. The destination item is null. p0: %i\n", p0);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The source file descriptor is null.");
                fwprintf(stdout, L"Error: Could not read basic. The source file descriptor is null. p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The fragment data is null.");
            fwprintf(stdout, L"Error: Could not read basic. The fragment data is null. p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The input memory size is null.");
        fwprintf(stdout, L"Error: Could not read basic. The input memory size is null. p3: %i\n", p3);
    }
}

/* BASIC_READER_SOURCE */
#endif
