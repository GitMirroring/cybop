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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the part element content into tui.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source whole properties data
 * @param p7 the source whole properties count
 * @param p8 the sign flag
 * @param p9 the number base
 * @param p10 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p11 the decimal separator data
 * @param p12 the decimal separator count
 * @param p13 the decimal places
 * @param p14 the scientific notation flag
 * @param p15 the newline flag
 * @param p16 the clear flag
 * @param p17 the positioning flag
 * @param p18 the knowledge memory part (pointer reference)
 * @param p19 the stack memory item
 * @param p20 the internal memory data
 * @param p21 the tree level
 * @param p22 the original attributes
 * @param p23 the format
 */
void serialise_tui_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui content.");
    //?? fwprintf(stdout, L"Debug: Serialise tui content. format p23: %i\n", p23);
    //?? fwprintf(stdout, L"Debug: Serialise tui content. format *p23: %i\n", *((int*) p23));

    //
    // Declaration
    //

    //
    // The serialised item.
    //
    // CAUTION! This variable is necessary,
    // because translation for unix terminal and
    // win32 console is done in different ways below.
    // So, the serialised data are handed over as parametre.
    //
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef WIN32
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p21, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // If this is the first tui element being processed (tree level zero),
        // then store the current original win32 console attributes.
        //
        serialise_win32_console_state(p22, p1);

    } else {

        //
        // If this is any of the following tui elements,
        // then reset console to original attributes
        // before actually manipulating them below.
        //
        serialise_win32_console_reset(p1, p22);
    }
#endif

    //
    // Serialisation
    //

    // Clear terminal screen.
    serialise_tui_clear(p0, p1, p16, p21);

    //?? fwprintf(stdout, L"Debug: Serialise tui content. destination count 0: %i\n", *((int*) ((void**) p0)[1]));

    // Append properties.
    serialise_tui_properties(p0, p1, p4, p5, p6, p7, p18, p19, p20, p17);

    //?? fwprintf(stdout, L"Debug: Serialise tui content. destination count 1: %i\n", *((int*) ((void**) p0)[1]));

    //
    // Allocation
    //

    //
    // Allocate serialised item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! This is the ansi escape code array, which is of
    // type CHARACTER and NOT wide character.
    //
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Embedding
    //

    // Increment tree level.
    calculate_integer_add(p21, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Append EMBEDDED model.
    //
    // CAUTION! Hand over the local serisalised item s
    // and NOT the destination ansi escape code item p0.
    //
    serialise_tui(s, p1, p2, p3, p4, p5, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23);

    //?? fwprintf(stdout, L"Debug: Serialise tui content. sub sequence s count: %i\n", *((int*) ((void**) s)[1]));

    // Decrement tree level.
    calculate_integer_subtract(p21, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Retrieval
    //

    //
    // Get serialised item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

#ifdef WIN32
    serialise_win32_console_character(p1, sd, sc);
#else
    serialise_ansi_escape_code_character(p0, sd, sc);
#endif

    //?? fwprintf(stdout, L"Debug: Serialise tui content. destination count 2: %i\n", *((int*) ((void**) p0)[1]));

    // Append newline.
    serialise_tui_newline(p0, p1, p15, p21);

    //?? fwprintf(stdout, L"Debug: Serialise tui content. destination count 3: %i\n", *((int*) ((void**) p0)[1]));

    //
    // Reset terminal attributes in order to have
    // original settings in two situations:
    // - leaving cyboi
    // - painting a new part for which
    //   no properties have been specified
    //
    // Therefore, the reset is done not only
    // once after serialisation, but EVERYTIME
    // after having painted a part here.
    //
#ifdef WIN32
    serialise_win32_console_reset(p1, p22);
#else
    serialise_ansi_escape_code_reset(p0);
#endif

    //?? fwprintf(stdout, L"Debug: Serialise tui content. destination count 4: %i\n", *((int*) ((void**) p0)[1]));

    //
    // Deallocation
    //

    // Deallocate serialised item.
    deallocate_item((void*) &s, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
