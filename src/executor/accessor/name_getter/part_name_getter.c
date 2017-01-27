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

#ifndef PART_NAME_GETTER_SOURCE
#define PART_NAME_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/name_getter/item_name_getter.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part by name array, from the given whole part.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the destination part element index
 * @param p5 the lifo flag (use last-in-first-out instead of first-in-first-out)
 */
void get_name_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get name part element.");

fwprintf(stdout, L"TEST get name part element name data p2: %ls\n", (wchar_t*) p2);
fwprintf(stdout, L"TEST get name part element name count p3: %i\n", *((int*) p3));

    // The source whole item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

//?? -- TEST BEGIN
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snc = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &sn, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snd, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snc, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"TEST get name part element snd: %ls\n", (wchar_t*) snd);
    fwprintf(stdout, L"TEST get name part element snc: %i\n", *((int*) snc));
//?? -- TEST END

    // Get source whole item.
    copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4);

fwprintf(stdout, L"TEST get name part element s: %i\n", s);

    // Get destination part with given name from source whole data item.
    get_name_item_element(p0, s, p2, p3, p5);
}

/**
 * Gets the knowledge part by name part, from the given whole part.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the part name part
 * @param p3 the lifo flag (use last-in-first-out instead of first-in-first-out)
 */
void get_name_part(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get name part.");

    // The source whole part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source whole part.
    copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part name part.
    copy_array_forward((void*) &n, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);

    // Get destination part with given name from source whole data item.
    get_name_item(p0, s, n, p3);
}

/* PART_NAME_GETTER_SOURCE */
#endif
