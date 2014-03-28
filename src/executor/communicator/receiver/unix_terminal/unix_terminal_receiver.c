/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_TERMINAL_RECEIVER_SOURCE
#define UNIX_TERMINAL_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/unix_terminal/file_unix_terminal_receiver.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Receives data via unix terminal.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the format
 * @param p3 the language
 * @param p4 the internal memory data
 */
void receive_unix_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*?? TEST ONLY! Commented out, since error occured on computers without path "/Users/markushinkelmann/".
    FILE* pFile = fopen("/Users/markushinkelmann/log.log","a+");
    fwprintf(pFile, L"Recive unix terminal");
    fclose (pFile);
*/

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive unix terminal.");

    // The decoded message item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decoded message item data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate decoded message item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Receive byte data via channel.
    receive_unix_terminal_file(d, p4);

    // CAUTION! The multibyte character sequence is converted to
    // wide character internally (in glibc function "fgetwc").
    // Calling the "decode" or "decode_utf_8" function
    // is therefore NOT necessary here!

    // Get decoded message item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
fwprintf(stdout, L"TEST receive unix terminal *dc: %i\n", *((int*) dc));
fwprintf(stdout, L"TEST receive unix terminal dd: %ls\n", (wchar_t*) dd);
*/

    // Deserialise data.
    deserialise(p0, p1, dd, dc, *NULL_POINTER_STATE_CYBOI_MODEL, p4, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3);

/*?? TEST only! Delete later.
void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
void* testc = *NULL_POINTER_STATE_CYBOI_MODEL;
copy_array_forward((void*) &testd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
copy_array_forward((void*) &testc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST receive unix terminal *testc: %i\n", *((int*) testc));
fwprintf(stdout, L"TEST receive unix terminal testd: %ls\n", (wchar_t*) testd);
*/

    // Deallocate decoded message item.
    deallocate_item((void*) &d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* UNIX_TERMINAL_RECEIVER_SOURCE */
#endif
