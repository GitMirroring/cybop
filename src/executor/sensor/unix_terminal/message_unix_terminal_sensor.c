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
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Senses unix terminal message.
 *
 * @param p0 the pipe
//?? * @param p0 the write pipe stream
 * @param p1 the interrupt request
 * @param p2 the interrupt request pipe
 * @param p3 the access mutex
 * @param p4 the file stream
 * @param p5 the input/output entry identification
 */
void sense_unix_terminal_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* id = (int*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            FILE* f = (FILE*) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                mtx_t* m = (mtx_t*) p3;

                if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    void* ip = (void*) p2;

                    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        volatile sig_atomic_t* i = (volatile sig_atomic_t*) p1;

                        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* p = (int*) p0;
                            //?? FILE* p = (FILE*) p0;

                            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal message.");
                            //?? fwprintf(stdout, L"Test: Sense unix terminal message. p1: %i\n", p1);

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
                            //?? mtx_lock(m);

                            //
                            // Get character from source input stream of terminal.
                            //
                            // This is just to detect if some character is available,
                            // what is also called "peeking ahead" at the input.
                            //
                            // CAUTION! The multibyte character is converted to a
                            // wide character internally in glibc function "fgetwc".
                            //
                            // CAUTION! Use 'wint_t' instead of 'int' as return type for
                            // 'fgetwc()', since that returns 'WEOF' instead of 'EOF'!
                            //
                            // CAUTION! The return value of type "wint_t"
                            // MAY BE CASTED to "wchar_t".
                            //
                            // CAUTION! Do NOT use function "fgetwc_unlocked",
                            // since it is a gnu extension and may not exist everywhere.
                            //
                            // CAUTION! Do NOT use the function "read", which is lower-level
                            // and may even be a system call directly into the OS.
                            // Furthermore, it is NOT standard C, but part of POSIX.
                            //
                            volatile wint_t c = fgetwc(f);

                            fwprintf(stdout, L"Test: Sense unix terminal message. c: %i\n", c);

                            //
                            // The WEOF constant usually corresponds to the value -1.
                            //
                            // CAUTION! However, do NOT compare like the following:
                            //     if (c < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                            // The reason is that wint_t and int comparison might deliver
                            // wrong results, so that an input is mistakenly assumed below.
                            //
                            if (c != WEOF) {

                                // The write pipe file descriptor.
                                int wp = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                                // Get write pipe file descriptor.
                                copy_array_forward((void*) &wp, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                                fwprintf(stdout, L"Test: Sense unix terminal message. wp: %i\n", wp);
                                // Write character to write pipe file descriptor.
                                write(wp, (void*) &c, sizeof(c));

                                // Write character to write pipe stream.
                                //?? fwprintf(stdout, L"Test: Sense unix terminal message. p: %i\n", p);
                                //?? fwprintf(p, L"%lc", c);
                                //?? fflush(p);

                                // Set interrupt request.
                                //?? copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                // The write interrupt request pipe file descriptor.
                                int wip = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                                // Get write interrupt request pipe file descriptor.
                                copy_array_forward((void*) &wip, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                                fwprintf(stdout, L"Test: Sense unix terminal message. wip: %i\n", wip);
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
                                //?? fprintf(ip, "%i", *id);
                                write(wip, (void*) id, sizeof(*id));
                                //?? fflush(ip);

                            } else {

                                //
                                // The returned value is WEOF.
                                //
                                // CAUTION! This error should NEVER happen, since
                                // the terminal is set to "blocking" mode (VMIN = 1)
                                // so that it will only return when at least
                                // ONE VALID character is available.
                                //

                                //
                                //?? TODO: This is commented out temporarily,
                                // as long as operating system signal handling
                                // for interrupting the sensing thread does not work yet.
                                //
                                // Otherwise, many of these error messages are written
                                // to standard output, because on system SHUTDOWN,
                                // the sensing thread is still running but due to
                                // missing (already destroyed) resources in non-blocking mode.
                                //
                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The returned value is WEOF.");
                                fwprintf(stdout, L"Error: Could not sense unix terminal message. The returned value is WEOF. p1: %i\n", p1);
                            }

                            // Unlock mutex.
                            //?? mtx_unlock(m);

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The pipe is null.");
                            fwprintf(stdout, L"Error: Could not sense unix terminal message. The pipe is null. p0: %i\n", p0);
                            //?? log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The write pipe stream is null.");
                            //?? fwprintf(stdout, L"Error: Could not sense unix terminal message. The write pipe stream is null. p0: %i\n", p0);
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
}

/* MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE */
#endif
