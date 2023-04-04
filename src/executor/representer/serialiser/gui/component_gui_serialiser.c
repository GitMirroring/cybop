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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPONENT_GUI_SERIALISER_SOURCE
#define COMPONENT_GUI_SERIALISER_SOURCE

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
 * Serialises the gui component.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the source model data
 * @param p7 the source model count
 * @param p8 the position x
 * @param p9 the position y
 * @param p10 the size width
 * @param p11 the size height
 * @param p12 the source properties data
 * @param p13 the source properties count
 * @param p14 the knowledge memory part (pointer reference)
 * @param p15 the stack memory item
 * @param p16 the internal memory data
 * @param p17 the format
 */
void serialise_gui_component(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui component.");
    //?? fwprintf(stdout, L"Debug: Serialise gui component. Connexion p0: %i\n", p0);

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part.
    void* sh = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The super part model item.
    void* superm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part model item.
    void* shm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The super part model item data, count.
    void* supermd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* supermc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part model item data, count.
    void* shmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* shmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_name((void*) &super, p12, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p13, p14, p15, p16);
    get_part_name((void*) &sh, p12, (void*) SHAPE_GUI_STATE_CYBOL_NAME, (void*) SHAPE_GUI_STATE_CYBOL_NAME_COUNT, p13, p14, p15, p16);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (sh == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &sh, supermd, (void*) SHAPE_GUI_STATE_CYBOL_NAME, (void*) SHAPE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p14, p15, p16);
    }

    // Get part model items.
    copy_array_forward((void*) &shm, sh, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part model item data, count.
    copy_array_forward((void*) &shmd, shm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &shmc, shm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Serialise context (colours etc.).
    serialise_gui_context(p0, p1, p2, p3, p4, p5, p12, p13, p14, p15, p16);
    // Serialise shape (e.g. rectangle).
    serialise_gui_shape(p0, p1, p2, p3, p5, p8, p9, p10, p11, shmd, shmc);

    compare_integer_equal((void*) &r, p17, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is NOT a part.
        //

        //
        // Serialise text.
        //
        // CAUTION! Part elements MUST NOT be serialised since
        // this would lead to hieroglyphic output on screen.
        // The reason is that part values are just pointers to child parts.
        //
        // CAUTION! This has to be done for ALL shapes.
        // A text is NOT treated as shape itself,
        // but may instead be drawn into the shape.
        //
        serialise_gui_text(p0, p1, p2, p3, p5, p6, p7, p8, p9, p10, p11);
    }

    // Cleanup context.
    serialise_gui_cleanup(p0, p1, p2, p3, p4, p5);
}

/* COMPONENT_GUI_SERIALISER_SOURCE */
#endif
