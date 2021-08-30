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
 * @param p0 the pipe
 * @param p1 the interrupt request
 * @param p2 the interrupt request pipe
 * @param p3 the access mutex
 * @param p4 the file descriptor
 * @param p5 the input/output entry identification
 * @param p6 the buffer data
 * @param p7 the buffer count
 * @param p8 the wide character buffer item
 */
void sense_unix_terminal_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* bc = (int*) p7;

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* f = (int*) p4;

                        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            mtx_t* m = (mtx_t*) p3;

                            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                void* ip = (void*) p2;

                                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    volatile sig_atomic_t* i = (volatile sig_atomic_t*) p1;

                                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                        int* p = (int*) p0;

                                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal message.");
                                        //?? fwprintf(stdout, L"Test: Sense unix terminal message. p1: %i\n", p1);

                                        // Cast buffer size to expected type.
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

                                        // Decode multibyte character into wide character.
                                        decode_utf_8(p8, p6, (void*) &n);

                                        // The wide character buffer item data, count.
                                        void* wd = *NULL_POINTER_STATE_CYBOI_MODEL;
                                        void* wc = *NULL_POINTER_STATE_CYBOI_MODEL;

                                        //
                                        // Get wide character buffer item data, count.
                                        //
                                        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                                        // Inside the structure, arrays may have been reallocated,
                                        // with elements pointing to different memory areas now.
                                        //
                                        copy_array_forward((void*) &wd, p8, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                                        copy_array_forward((void*) &wc, p8, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                                        fwprintf(stdout, L"Test: Sense unix terminal message. wc: %i\n", wc);
                                        fwprintf(stdout, L"Test: Sense unix terminal message. *wc: %i\n", *((int*) wc));
                                        fwprintf(stdout, L"Test: Sense unix terminal message. wd: %ls\n", (wchar_t*) wd);

                                        // The loop count.
                                        int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                        // The wide character.
                                        wint_t c = EOF;
                                        // The pipe write file descriptor.
                                        int pw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                                        // Get pipe write file descriptor.
                                        copy_array_forward((void*) &pw, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                                        fwprintf(stdout, L"Test: Sense unix terminal message. pw: %i\n", pw);

                                        //
                                        // Lock mutex.
                                        //
                                        // CAUTION! This function call blocks the current thread
                                        // until the mutex is locked.
                                        //
                                        // CAUTION! This guarantees exclusive access to
                                        // input/output resources as well as the interrupt request,
                                        // which are shared between input sensing (child) threads
                                        // and the main (parent) thread.
                                        //
                                        // CAUTION! Not all input/output channels use sensing threads.
                                        // Sometimes, the main thread is the only one accessing resources.
                                        //
                                        mtx_lock(m);

                                        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                            if (j >= n) {

                                                break;
                                            }

                                            // Get wide character from wide character buffer.
                                            copy_array_forward((void*) &c, wd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);
                                            fwprintf(stdout, L"Test: Sense unix terminal message. j: %i\n", j);
                                            fwprintf(stdout, L"Test: Sense unix terminal message. c: %i\n", c);
                                            fwprintf(stdout, L"Test: Sense unix terminal message. c as char: %lc\n", (wchar_t) c);

                                            // Write wide character to pipe write file descriptor.
                                            write(pw, (void*) &c, sizeof(wint_t));

                                            // Increment loop count.
                                            j++;
                                        }

                                        // Unlock mutex.
                                        mtx_unlock(m);

                                        // Set interrupt request.
                                        //?? copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                        // The interrupt request pipe write file descriptor.
                                        int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                                        // Get interrupt request pipe write file descriptor.
                                        copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                                        fwprintf(stdout, L"Test: Sense unix terminal message. ipw: %i\n", ipw);
                                        //
                                        // Write input/output entry identification to interrupt request pipe.
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
                                        write(ipw, p5, sizeof(int));

                                    } else {

                                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The pipe is null.");
                                        fwprintf(stdout, L"Error: Could not sense unix terminal message. The pipe is null. p0: %i\n", p0);
                                    }

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The interrupt request is null.");
                                    fwprintf(stdout, L"Error: Could not sense unix terminal message. The interrupt request is null. p1: %i\n", p1);
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The interrupt request pipe is null.");
                                fwprintf(stdout, L"Error: Could not sense unix terminal message. The interrupt request pipe is null. p2: %i\n", p2);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The access mutex is null.");
                            fwprintf(stdout, L"Error: Could not sense unix terminal message. The access mutex is null. p3: %i\n", p3);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The file stream is null.");
                        fwprintf(stdout, L"Error: Could not sense unix terminal message. The file stream is null. p4: %i\n", p4);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The input/output entry identification is null.");
                    fwprintf(stdout, L"Error: Could not sense unix terminal message. The input/output entry identification is null. p5: %i\n", p5);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The buffer data is null.");
                fwprintf(stdout, L"Error: Could not sense unix terminal message. The buffer data is null. p6: %i\n", p6);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The buffer count is null.");
            fwprintf(stdout, L"Error: Could not sense unix terminal message. The buffer count is null. p7: %i\n", p7);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The wide character buffer item is null.");
        fwprintf(stdout, L"Error: Could not sense unix terminal message. The wide character buffer item is null. p8: %i\n", p8);
    }
}

/* MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE */
#endif
