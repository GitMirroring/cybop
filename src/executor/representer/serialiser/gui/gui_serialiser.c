/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GUI_SERIALISER_SOURCE
#define GUI_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/representer/serialiser/cybol/cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/gui/part_gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises a part into graphical user interface (gui).
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the destination text item
 * @param p7 the source model data
 * @param p8 the source model count
 * @param p9 the source properties data
 * @param p10 the source properties count
 * @param p11 the knowledge memory part
 * @param p12 the format
 */
void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Do NOT call function "serialise_gui_properties" here.
            // It is called inside the "serialise_gui_part" function.
            serialise_gui_part(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10, p11);
        }
    }

    //
    // other formats
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Leave processing of other formats to cybol serialiser.
        serialise_cybol(p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p12, *NULL_POINTER_STATE_CYBOI_MODEL, p7, p8, p9, p10);
    }
}

/* GUI_SERIALISER_SOURCE */
#endif
