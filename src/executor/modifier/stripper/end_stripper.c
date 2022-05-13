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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef END_STRIPPER_SOURCE
#define END_STRIPPER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Searches for a non-whitespace character from the END of the given array.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the member name data
 * @param p5 the member name count
 * @param p6 the array or object end flag
 * @param p7 the value end flag
 * @param p8 the object flag (true if this is an object; false for array or otherwise the default)
 */
void strip_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip end.");
    fwprintf(stdout, L"Debug: Strip end. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Strip end. count remaining *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Strip end. data position *p2: %i\n", *((void**) p2));
    fwprintf(stdout, L"Debug: Strip end. data position *p2 ls: %ls\n", (wchar_t*) *((void**) p2));
    fwprintf(stdout, L"Debug: Strip end. data position *p2 lc: %lc\n", *((wchar_t*) *((void**) p2)));
    fwprintf(stdout, L"Debug: Strip end. data position *p2 lc as int: %i\n", *((wchar_t*) *((void**) p2)));

}

/* END_STRIPPER_SOURCE */
#endif
