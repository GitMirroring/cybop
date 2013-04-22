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

#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "list_directory_contents_unix_shell.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifdef WIN32
    #include "list_directory_contents_win32_command.c"
    #include "../../constant/model/command/win32_command_model.c"
#endif

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

    #ifdef GNU_LINUX_OPERATING_SYSTEM
        apply_list_directory_contents_unix_shell(p0, p1, p2);
    #endif

    #ifdef WIN32
        apply_list_directory_contents_win32_command(p0, p1, p2);
    #endif
}

/* LIST_DIRECTORY_CONTENTS_SOURCE */
#endif
