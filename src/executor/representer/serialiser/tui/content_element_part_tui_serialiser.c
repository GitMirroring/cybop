/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/ansi_escape_code/ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/serialiser/tui/clear_tui_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/newline_tui_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/properties_tui_serialiser.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include <windows.h>
    #include "../../../../executor/representer/serialiser/win32_console/character_win32_console_serialiser.c"
    #include "../../../../executor/representer/serialiser/win32_console/reset_win32_console_serialiser.c"
    #include "../../../../executor/representer/serialiser/win32_console/state_win32_console_serialiser.c"
#else
    #include "../../../../executor/representer/serialiser/ansi_escape_code/character_ansi_escape_code_serialiser.c"
    #include "../../../../executor/representer/serialiser/ansi_escape_code/reset_ansi_escape_code_serialiser.c"
#endif

//
// Forward declarations.
//

void serialise_tui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);

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
 * @param p8 the knowledge memory part
 * @param p9 the stack memory item
 * @param p10 the clear flag
 * @param p11 the newline flag
 * @param p12 the tree level
 * @param p13 the cli flag
 * @param p14 the original attributes
 * @param p15 the format data
 */
void serialise_tui_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui part element content.");

    // The serialised item.
    // CAUTION! This variable is necessary,
    // because translation for unix terminal and
    // win32 console is done in different ways below.
    // So, the serialised data are handed over as parametre.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef WIN32
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p12, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // If this is the first tui element being processed (tree level zero),
        // then store the current original win32 console attributes.
        serialise_win32_console_state(p14, p1);

    } else {

        // If this is any of the following tui elements,
        // then reset console to original attributes
        // before actually manipulating them below.
        serialise_win32_console_reset(p1, p14);
    }
#endif

    // Allocate serialised item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Clear terminal screen.
    serialise_tui_clear(p0, p1, p10, p12);

    // Append properties.
    serialise_tui_properties(p0, p1, p4, p5, p6, p7, p8, p9, p13);

    // Increment tree level.
    calculate_integer_add(p12, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    // Append embedded model.
    serialise_tui(s, p1, p2, p3, p4, p5, p8, p9, p10, p11, p12, p13, p14, p15);
    // Decrement tree level.
    calculate_integer_subtract(p12, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Get serialised item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

#ifdef WIN32
    serialise_win32_console_character(p1, sd, sc);
#else
    serialise_ansi_escape_code_character(p0, sd, sc);
#endif

    // Append newline.
    serialise_tui_newline(p0, p1, p11, p12);

    // Reset terminal attributes in order to have
    // original settings in two situations:
    // - leaving cyboi
    // - painting a new part for which
    //   no properties have been specified
    //
    // Therefore, the reset is done not only
    // once after serialisation, but EVERYTIME
    // after having painted a part here.
#ifdef WIN32
    serialise_win32_console_reset(p1, p14);
#else
    serialise_ansi_escape_code_reset(p0);
#endif

    // Deallocate serialised item.
    deallocate_item((void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE */
#endif
