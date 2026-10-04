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

#include "client.h"
#include "communication.h"
#include "constant.h"

//
// Forward declaration
//

void calculate_integer_add(void* p0, void* p1);

/**
 * Inspects the given part model item data.
 *
 * They get written into a file in model diagram format.
 *
 * Usage example:
 *
 * #include "inspector.h"
 * fwprintf(stdout, L"Debug: Deserialise cybol standard. inspect source model count p8: %i\n", p8);
 * fwprintf(stdout, L"Debug: Deserialise cybol standard. inspect source model count *p8: %i\n", *((int*) p8));
 * inspect_knowledge_data((void*) L"inspect_1", (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL, p7, p8, p13, p14, p15);
 *
 * @param p0 the filename data
 * @param p1 the filename count
 * @param p2 the part model item data
 * @param p3 the part model item count
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 */
void inspect_knowledge_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    fwprintf(stdout, L"Debug: CAUTION! The current directory is used as path. So the written inspection file will be found there. p0 %i\n", p0);

    // The identification item.
    // This is the file descriptor.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification item data.
    void* idd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate identification item.
    allocate_item((void*) &id, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Get identification item data.
    copy_array_forward((void*) &idd, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"Debug: Inspect knowledge data. 0 idd: %i\n", idd);
    fwprintf(stdout, L"Debug: Inspect knowledge data. 1 *idd: %i\n", *((int*) idd));

    // Open file.
    open_file(idd, p0, p1, (void*) WRITE_OPEN_MODE_FILE_MODEL, (void*) WRITE_OPEN_MODE_FILE_MODEL_COUNT);

    fwprintf(stdout, L"Debug: Inspect knowledge data. 2 *idd: %i\n", *((int*) idd));
    // Send data to file.
    send_data(id, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p4, p5, p6, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE, (void*) UTF_8_CYBOI_ENCODING, (void*) FILE_CYBOI_CHANNEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Debug: Inspect knowledge data. 3 *idd: %i\n", *((int*) idd));

    // Close file.
    close_basic(idd);

    // Deallocate identification item.
    deallocate_item((void*) &id, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}
