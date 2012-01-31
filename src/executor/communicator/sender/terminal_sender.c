/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SENDER_SOURCE
#define TERMINAL_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Sends the terminal control sequences into a terminal.
 *
 * @param p0 the destination terminal (pointer reference)
 * @param p1 the destination terminal count
 * @param p2 the destination terminal size
 * @param p3 the source terminal control sequences as utf-8 encoded multibyte characters
 * @param p4 the source terminal control sequences as utf-8 encoded multibyte characters count
 */
void send_terminal_sequence(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE** d = (FILE**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send to terminal.");

        // The terminated control sequences.
        void* tsd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int tsc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int tss = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Allocate terminated control sequences.
        //
        // CAUTION! Use a standard (non-wide) character vector here,
        // because the source is handed over as utf-8 encoded multibyte characters
        // and will be forwarded as such to the gnu linux console!
        allocate_array((void*) &tsd, (void*) &tss, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append control sequences and null termination character.
        overwrite_array((void*) &tsd, p3, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) &tsc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &tsc, (void*) &tss, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        overwrite_array((void*) &tsd, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &tsc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &tsc, (void*) &tss, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (*d != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Send to terminal.
//??            fwprintf(*d, L"%s", (char*) ts);

            //?? This is a TEMPORARY workaround.
            //?? The UTF-8 conversion returns the total number of bytes,
            //?? of all multibyte characters that were converted from wide characters.
            //?? So the size is known, but not the actual number of characters,
            //?? since one character may occupy more than just one byte.
            //?? This may sometimes lead to problems (THIS IS AN ASSUMPTION),
            //?? so that the text user interface is not drawn properly or not at all.
            //?? Therefore, as a workaround, the source is printed on console as is,
            //?? without null termination character.
            fwprintf(*d, L"%s", (char*) p3);

            // Flush any buffered output on the stream to the file.
            //
            // If this was not done here, the buffered output on the
            // stream would only get flushed automatically when either:
            // - one tried to do output and the output buffer is full
            // - the stream was closed
            // - the program terminated by calling exit
            // - a newline was written with the stream being line buffered
            // - an input operation on any stream actually read data from its file
            fflush(*d);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to terminal. The destination terminal file is null.");
        }

        // Deallocate terminated control sequences.
        deallocate_array((void*) &tsd, (void*) &tss, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to terminal. The destination terminal file parametre is null.");
    }
}

/**
 * Sends a textual user interface (tui) via terminal.
 *
 * @param p0 the internal memory
 * @param p1 the source root type
 * @param p2 the source root type count
 * @param p3 the source root model (root window compound model)
 * @param p4 the source root model count
 * @param p5 the source root properties (meta properties of root window compound model)
 * @param p6 the source root properties count
 * @param p7 the source area to be repainted part name
 * @param p8 the source area to be repainted part name count
 * @param p9 the source clean flag
 * @param p10 the source clean flag count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void send_terminal(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send terminal.");

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised wide character item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal output stream.
    void** op = NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate serialised wide character array.
    allocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded character item.
    // CAUTION! Use a standard (non-wide) character vector here,
    // because the source is handed over as utf-8 encoded multibyte characters
    // and will be forwarded as such to the gnu linux console!
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (p9 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            append_item_element(s, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            append_item_element(s, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    // Encode textual user interface (tui) into array.
    serialise_terminal(s, p1, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p7, p8, p11, p12);

    // Get serialised wide character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8(e, sd, sc);

    // Get terminal output stream.
    get_array_elements((void*) &op, p0, (void*) TERMINAL_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE);

    // Get encoded character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Send encoded array as message to shell standard output.
    send_terminal_sequence((void*) op, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, ed, ec);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* TERMINAL_SENDER_SOURCE */
#endif
