/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OPEN_SOURCE
#define OPEN_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/name/cybol/logic/dispatching/open_dispatching_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/dispatcher/opener/opener.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../logger/logger.c"

/**
 * Opens up a client on the given channel.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the internal memory data (pointer reference)
 */
void apply_open(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply open.");

    //
    // Declaration
    //

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part.
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace (family) part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file open mode part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part model item.
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace (family) part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part model item.
    void* prm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file open mode part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item.
    void* idm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part model item data.
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace (family) part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part model item data, count.
    void* prmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* prmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file open mode part model item data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part model item data, count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item data.
    void* idmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get server flag part.
    get_part_name((void*) &sf, p0, (void*) SERVER_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) SERVER_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get port part.
    get_part_name((void*) &p, p0, (void*) PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get namespace (family) part.
    get_part_name((void*) &n, p0, (void*) NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get style part.
    get_part_name((void*) &s, p0, (void*) STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get protocol part.
    get_part_name((void*) &pr, p0, (void*) PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get file open mode part.
    get_part_name((void*) &m, p0, (void*) MODE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) MODE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get device part.
    get_part_name((void*) &d, p0, (void*) DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get identification part.
    get_part_name((void*) &id, p0, (void*) IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get server flag part model item.
    copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get namespace (family) part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get style part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get protocol part model item.
    copy_array_forward((void*) &prm, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get file open mode part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get device part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get identification part model item.
    copy_array_forward((void*) &idm, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get server flag part model item data.
    copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get namespace (family) part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get style part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get protocol part model item data, count.
    copy_array_forward((void*) &prmd, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &prmc, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get file open mode part model item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get device part model item data, count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get identification part model item data.
    copy_array_forward((void*) &idmd, idm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // Set server flag to FALSE (client mode) by default.
    int server = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // Set port to ZERO by default.
    //
    // CAUTION! It IS necessary so that the correct client entry
    // can be found in the DISPLAY server list, which was
    // assigned to port ZERO at service startup.
    //
    int port = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The file open mode default item.
    void* mode = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file open mode default item data, count.
    void* moded = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* modec = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate file open mode default item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &mode, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Set file open mode to READ by default.
    modify_item(mode, (void*) READ_OPEN_MODE_FILE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) READ_OPEN_MODE_FILE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    copy_integer((void*) &server, sfmd);
    copy_integer((void*) &port, pmd);

    //
    // Copy file open mode property values only if not null.
    //
    // CAUTION! If this comparison was not done here, then the model COUNT integer value
    // would get overwritten with ZERO inside, leading to errors like the following:
    //
    // Warning: Could not open file mode. The open mode is unknown. open mode count p2: -1012090544
    // Warning: Could not open file mode. The open mode is unknown. open mode count *p2: 0
    // Warning: Could not open file mode. The open mode is unknown. open mode data p1: read
    //
    if ((mmd != *NULL_POINTER_STATE_CYBOI_MODEL) && (mmc != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        modify_item(mode, mmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, mmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
    }

    // Get file open mode default item data, count.
    copy_array_forward((void*) &moded, mode, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &modec, mode, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Open up client.
    open_client(idmd, (void*) &port, dmd, dmc, moded, modec, nmd, nmc, smd, smc, prmd, prmc, cmd, (void*) &server, p4, p5);

    // Deallocate file open mode default item.
    deallocate_item((void*) &mode, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* OPEN_SOURCE */
#endif
