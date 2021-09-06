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

#ifndef MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE
#define MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE

#include <stdio.h> // fdopen
#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <wchar.h> // fgetwc, fgetwc_unlocked

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Senses unix terminal message.
 *
 * @param p0 the destination wide character buffer item
 * @param p1 the source file descriptor
 * @param p2 the interrupt pipe write file descriptor
 * @param p3 the input/output entry identification
 * @param p4 the terminal mutex (destination wide character buffer item)
 * @param p5 the interrupt mutex
 * @param p6 the character buffer data
 * @param p7 the character buffer count
 */
void sense_unix_terminal_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* bc = (int*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                mtx_t* im = (mtx_t*) p5;

                if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    mtx_t* m = (mtx_t*) p4;

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* ipw = (int*) p2;

                            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                int* f = (int*) p1;

                                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal message.");

                                    // Cast buffer size to correct type.
                                    size_t s = (size_t) *bc;

                                    //
                                    // Read characters from terminal file descriptor.
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
                                    fwprintf(stdout, L"Test: Sense unix terminal message. *bc: %i\n", *bc);
                                    fwprintf(stdout, L"Test: Sense unix terminal message. s: %i\n", s);
                                    int n = read(*f, p6, s);
                                    fwprintf(stdout, L"Test: Sense unix terminal message. n: %i\n", n);
                                    fwprintf(stdout, L"Test: Sense unix terminal message. *p6 as c: %c\n", *((char*) p6));
                                    fwprintf(stdout, L"Test: Sense unix terminal message. p6 as s: %s\n", (char*) p6);

                                    // Lock terminal mutex.
                                    mtx_lock(m);
                                    // Decode multibyte character into wide character.
                                    decode_utf_8(p0, p6, (void*) &n);
                                    // Unlock terminal mutex.
                                    mtx_unlock(m);

                                    fwprintf(stdout, L"Test: Sense unix terminal message. *ipw: %i\n", *ipw);

                                    // Lock interrupt mutex.
                                    mtx_lock(im);
                                    //
                                    // Write input/output entry identification to interrupt pipe.
                                    //
                                    // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
                                    // However, if both processes were created using the same compiler version,
                                    // one can take advantage of the fact that anything in C can be
                                    // read or written as an array of char (byte).
                                    //
                                    // Example:
                                    //
                                    // int n = something();
                                    // write(pipe_w, &n, sizeof(n));
                                    // int n;
                                    // read(pipe_r, &n, sizeof(n));
                                    //
                                    // https://stackoverflow.com/questions/5237041/how-to-send-integer-with-pipe-between-two-processes
                                    //
                                    write(*ipw, p3, sizeof(int));
                                    // Unlock interrupt mutex.
                                    mtx_unlock(im);

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The destination wide character buffer item is null.");
                                    fwprintf(stdout, L"Error: Could not sense unix terminal message. The destination wide character buffer item is null. p0: %i\n", p0);
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The source file descriptor is null.");
                                fwprintf(stdout, L"Error: Could not sense unix terminal message. The source file descriptor is null. p1: %i\n", p1);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The interrupt pipe is null.");
                            fwprintf(stdout, L"Error: Could not sense unix terminal message. The interrupt pipe is null. p2: %i\n", p2);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The input/output entry identification is null.");
                        fwprintf(stdout, L"Error: Could not sense unix terminal message. The input/output entry identification is null. p3: %i\n", p3);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The terminal mutex is null.");
                    fwprintf(stdout, L"Error: Could not sense unix terminal message. The terminal mutex is null. p4: %i\n", p4);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The interrupt mutex is null.");
                fwprintf(stdout, L"Error: Could not sense unix terminal message. The interrupt mutex is null. p5: %i\n", p5);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The buffer data is null.");
            fwprintf(stdout, L"Error: Could not sense unix terminal message. The buffer data is null. p6: %i\n", p6);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The buffer count is null.");
        fwprintf(stdout, L"Error: Could not sense unix terminal message. The buffer count is null. p7: %i\n", p7);
    }
}

/* MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE */
#endif
