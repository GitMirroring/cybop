/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "shell.h"

/**
 * Configures the network.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_config_network(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply config network.");

    //
    // Declaration
    //

    // The resolver part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stats part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The version part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The resolver part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stats part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The version part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The resolver part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stats part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The version part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part mdoel item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get resolve part.
    get_part_name((void*) &r, p0, (void*) RESOLVE_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME, (void*) RESOLVE_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get statistics part.
    get_part_name((void*) &s, p0, (void*) STATISTICS_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME, (void*) STATISTICS_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get version part.
    get_part_name((void*) &v, p0, (void*) VERSION_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME, (void*) VERSION_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get all part.
    get_part_name((void*) &a, p0, (void*) ALL_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALL_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get resolve part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get statistics part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get version part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get all part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get resolve part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get statistics part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get version part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get all part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_config_network(rmd, smd, vmd, amd);
}
