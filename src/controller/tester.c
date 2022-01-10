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

#ifndef TESTER_SOURCE
#define TESTER_SOURCE

#include <wchar.h>

#include "../executor/streamer/writer/file/stream_file_writer.c"
#include "../logger/logger.c"

/**
 * Writes the data as model diagram into a file with the given name.
 *
 * @param p0 the destination file name
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source format data
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 */
void test(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test data as model diagram.");

    // The destination file name count, size.
    int fc = wcslen((wchar_t*) p0);

    // The model diagram item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The multibyte character stream item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model diagram item data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The multibyte character stream item model data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The tree level.
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
    // since the tree level value gets changed in the following functions!
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate model diagram item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate multibyte character stream item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &b, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise model into model diagram item.
    // CAUTION! Do NOT forward NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
    // since the tree level value gets changed in the following functions!
    serialise_model_diagram_part_element_content(d, p1, p2, p3, p4, p5, p6, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &l);

    // Get model diagram item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: data as model diagram dc: %i\n", dc);
    //?? fwprintf(stdout, L"Debug: data as model diagram *dc: %i\n", *((int*) dc));

    // Encode model diagram into multibyte character stream.
    encode_utf_8(b, dd, dc);

    //?? fwprintf(stdout, L"Debug: data as model diagram encode post: %i\n", b);

    // Get multibyte character stream item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: data as model diagram bc: %i\n", bc);
    //?? fwprintf(stdout, L"Debug: data as model diagram *bc: %i\n", *((int*) bc));

    // Write multibyte character stream to file system.
    write_file_stream(p0, (void*) &fc, bd, bc);

    //?? fwprintf(stdout, L"Debug: data as model diagram write post fc: %i\n", fc);

    // Deallocate model diagram item.
    deallocate_item((void*) &d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate multibyte character stream.
    deallocate_item((void*) &b, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* TESTER_SOURCE */
#endif
