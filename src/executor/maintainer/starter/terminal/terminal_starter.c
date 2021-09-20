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

#ifndef TERMINAL_STARTER_SOURCE
#define TERMINAL_STARTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/maintainer/starter/terminal/stream_terminal_starter.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the terminal.
 *
 * @param p0 the input/output entry
 */
void startup_terminal(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal.");

    //
    // Declaration.
    //

    // The blocking mode.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The canonical mode.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The echo mode.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The character buffer data, count.
    //?? void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    //?? void* cc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character buffer item.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocation.
    //

    //
    // Allocate blocking mode.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &b, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate canonical mode.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate echo mode.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &e, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate character buffer data, count.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! The size of 64 was chosen here for the following reason:
    // Pressing special keyboard buttons like "left arrow" does result
    // in an ansi escape code sequence to be stored in this buffer.
    // A sequence has at least three signs: escape + left bracket + character code.
    // Therefore, the buffer size must be at least 3 * typesize bytes.
    //
    // Since cyboi is using the terminal in wide character mode,
    // the single control characters have a size of "wint_t".
    // In the gnu c library, "wchar_t" is always 32 bit wide.
    // The types "wchar_t" and "wint_t" have the same representation
    // and their size is 32 bit = 4 byte in glibc.
    //
    // So, the buffer size should be at least 3 * 4 = 12 byte.
    // But sometimes, more than just three control characters arrive.
    // Therefore, the size was set to 64 byte, which covers a maximum
    // of 16 possible control characters.
    //
    //?? allocate_array((void*) &cd, (void*) NUMBER_64_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //?? allocate_array((void*) &cc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate wide character buffer item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! The size is IDENTICAL to that of the buffer above.
    // A multibyte sequence converted to wide characters can have
    // at most the same number of characters or less than
    // the original character buffer.
    //
    allocate_item((void*) &w, (void*) NUMBER_64_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Initialisation.
    //

    // Initialise blocking mode.
    copy_integer(b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise canonical mode.
    copy_integer(c, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise echo mode.
    copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise character buffer count.
    //?? copy_integer(cc, (void*) NUMBER_64_INTEGER_STATE_CYBOI_MODEL);

    //
    // Storage.
    //

    // Set blocking mode into input/output entry.
    copy_array_forward(p0, (void*) &b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BLOCKING_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set canonical mode into input/output entry.
    copy_array_forward(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CANONICAL_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set echo mode into input/output entry.
    copy_array_forward(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ECHO_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set character buffer data, count into input/output entry.
    //?? copy_array_forward(p0, (void*) &cd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHARACTER_BUFFER_DATA_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //?? copy_array_forward(p0, (void*) &cc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHARACTER_BUFFER_COUNT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set wide character buffer item into input/output entry.
    copy_array_forward(p0, (void*) &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    //
    // The output- and input file streams.
    //
    // CAUTION! The standard input/output streams "stdin"
    // and "stdout" exist on posix as well as on win32.
    //
    void* os = (void*) stdout;
    void* is = (void*) stdin;

    //
    // Linux:
    //
    // Although some functions specify the terminal device with a file descriptor,
    // the attributes are those of the terminal device itself and NOT of the file descriptor.
    // This means that the effects of changing terminal attributes are persistent;
    // if another process opens the same terminal file later on, it will see
    // the CHANGED attributes even though it doesn't have anything to do with
    // the open file descriptor originally specified in changing the attributes.
    //
    // Similarly, if a single process has multiple or duplicated file descriptors
    // for the same terminal device, changing the terminal attributes affects
    // INPUT AND OUTPUT to ALL of these file descriptors.
    //
    // This means, for example, that one can't open one file descriptor or stream
    // to read from a terminal in the normal line-buffered, echoed mode;
    // and simultaneously have another file descriptor for the same terminal
    // that one uses to read from it in single-character, non-echoed mode.
    // Instead, one has to EXPLICITLY SWITCH the terminal back and forth between the two modes.
    //
    // Reference:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Mode-Functions
    //
    // Since linux terminal modes are valid for input AND output,
    // it does NOT matter whether the input- or output file descriptor
    // is handed over as argument here. Either may be used.
    // A redundant storage of mode settings does not make sense.
    //
    // However, output- AND input stream have to be stored here in
    // the input/output entry. It is true that both streams have
    // identical terminal settings. But if only the output stream was stored,
    // then the missing input stream would cause read errors.
    //
    // Windows:
    //
    // A console consists of an input buffer and one or more output (screen) buffers.
    // The mode of a console buffer determines how the console behaves
    // during input and output (I/O) operations.
    // ONE SET OF FLAG CONSTANTS is used with INPUT handles,
    // and ANOTHER SET is used with screen buffer (OUTPUT) handles.
    // Setting the output modes of one screen buffer does not affect
    // the output modes of other screen buffers.
    //
    // Reference:
    // https://docs.microsoft.com/en-us/windows/console/setconsolemode
    //
    // The sets of flag constants are definitely different, to be verified here:
    // https://docs.microsoft.com/en-us/windows/console/setconsolemode
    // The input- and output constants have OVERLAPPING VALUES (identification),
    // so that both MUST NOT be combined or set together.
    //
    // Since windows distinguishes between the input and output mode settings
    // and uses a DIFFERENT SET OF FLAGS for each, both are treated SEPARATELY here.
    // Therefore, the function "startup_terminal_mode" is called twice,
    // once for input and another time for output.
    //
    // Arguments:
    //
    // The second argument is the file stream.
    // CAUTION! Hand it over as pointer REFERENCE.
    //
    // The third argument is a boolean value (flag)
    // indicating input (true) or output (false).
    // CAUTION! Do NOT set it to *NULL_POINTER_STATE_CYBOI_MODEL
    // since it is evaluated not only for the windows operating system
    // but also in function "startup_terminal_mode_store".
    //

#if defined(__linux__) || defined(__unix__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#elif defined(__APPLE__) && defined(__MACH__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_STARTER_SOURCE */
#endif
