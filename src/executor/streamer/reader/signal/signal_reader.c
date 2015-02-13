/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_READER_SOURCE
#define SIGNAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Reads a signal into the destination.
 *
 * @param p0 the destination signal item
 * @param p1 the source signal memory item
 * @param p2 the source signal memory index
 */
void read_signal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read signal.");

    // The signal part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal part from position index zero.
    //
    // CAUTION! The signal memory item's count is checked inside
    // this function. If it is smaller or equal to the given index
    // (here: zero), then the signal value s is NOT changed,
    // i.e. it remains NULL if initialised so before.
    //
    get_item_element((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST read signal s: %i\n\n", s);

    // Add signal part to destination item.
    //
    // CAUTION! Use simple POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here.
    // The signal memory just holds references to knowledge memory parts (signals),
    // but only the knowledge memory may care about rubbish (garbage) collection.
    //
    // Example:
    // Assume there are two signals in the signal memory.
    // The second references a logic part that is to be destroyed by the first.
    // If reference counting from rubbish (garbage) collection were used,
    // then the logic part serving as second signal could not be deallocated
    // as long as it is still referenced from the signal memory item.
    //
    // But probably, there is a reason the first signal wants to destroy the
    // second and consequently, the second should not be executed anymore.
    // After destruction, the second signal just points to null, which is ignored.
    // Hence, rubbish (garbage) collection would only disturb here
    // and should be left to the knowledge memory.
    //
    append_item_element(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//??    overwrite_item_element(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

//?? TEST 1

    // The signal item data.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST read signal sd: %i\n\n", sd);

//?? TEST 2

    void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int testc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int tests = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    allocate_array((void*) &testd, (void*) &tests, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    overwrite_array((void*) &testd, (void*) L"blubla-array", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &testc, (void*) &tests, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
fwprintf(stdout, L"TEST read signal testd: %i\n", testd);
fwprintf(stdout, L"TEST read signal testd: %ls\n", (wchar_t*) testd);
    deallocate_array((void*) &testd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &tests, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    void* item = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* itemd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pointer = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pointerd = *NULL_POINTER_STATE_CYBOI_MODEL;
    allocate_item((void*) &item, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &pointer, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
    append_item_element(item, (void*) L"blubla-item", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//??    overwrite_item_element(item, (void*) L"blubla-item", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &itemd, item, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST read signal itemd: %i\n", itemd);
fwprintf(stdout, L"TEST read signal itemd: %ls\n", (wchar_t*) itemd);
    append_item_element(pointer, (void*) &itemd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pointerd, pointer, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST read signal pointerd: %i\n", pointerd);
fwprintf(stdout, L"TEST read signal pointerd: %ls\n", (wchar_t*) pointerd);
fwprintf(stdout, L"TEST read signal pointerd: %i\n", *((void**) pointerd));
fwprintf(stdout, L"TEST read signal pointerd: %ls\n", (wchar_t*) *((void**) pointerd));
    deallocate_item((void*) &pointer, (void*) POINTER_STATE_CYBOI_TYPE);
    deallocate_item((void*) &item, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SIGNAL_READER_SOURCE */
#endif
