/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_DIRECTORY_CONTENTS_SOURCE
#define LIST_DIRECTORY_CONTENTS_SOURCE

#include <unistd.h>

#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/command_option/unix/list_unix_command_option_name.c"
#include "../../constant/name/cybol/logic/file/list_file_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/*??
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "list_directory_contents_unix_shell.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifdef WIN32
    #include "list_directory_contents_win32_command.c"
    #include "../../constant/model/command/win32_command_model.c"
#endif
*/

/**
 * Lists the directory contents.
 *
 * Expected parametres:
 * - all (optional): the list all option (showing hidden, current . and upper .. directory)
 * - long (optional): the long listing option (showing user rights etc.)
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_list_directory_contents(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply list directory contents.");

    // The all part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The all part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The all part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get all part.
    get_part_knowledge((void*) &a, p0, (void*) ALL_LIST_FILE_LOGIC_CYBOL_NAME, (void*) ALL_LIST_FILE_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get long part.
    get_part_knowledge((void*) &l, p0, (void*) LONG_LIST_FILE_LOGIC_CYBOL_NAME, (void*) LONG_LIST_FILE_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get all part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get long part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get all part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get long part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

#ifdef GNU_LINUX_OPERATING_SYSTEM
//??    list_directory_contents_unix_commander(p0, p1, p2);
#endif

#ifdef WIN32
//??    list_directory_contents_windows_commander(p0, p1, p2);
#endif
}

/* LIST_DIRECTORY_CONTENTS_SOURCE */
#endif
