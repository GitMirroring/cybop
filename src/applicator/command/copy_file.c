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

#ifndef COPY_FILE_SOURCE
#define COPY_FILE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM
    //#include "copy_file_unix_shell.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifdef W32TEST
    //#include "copy_file_win32_command.c"
    #include "../../constant/model/command/win32_command_model.c"
#endif

/**
 * Copies the file resource.
 *
 * Expected parametres:
 * - destination (required): the destination to copy to
 * - source (required): the source to be copied
 * - recursive (optional): the option indicating that all sub directories should be copied as well
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_copy_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply copy file.");

    #ifdef GNU_LINUX_OPERATING_SYSTEM
        //copy_file_unix_shell(p0, p1, p2);
    #endif

    #ifdef W32TEST
        //copy_file_windows_command(p0, p1, p2);
    #endif
}
/* COPY_FILE_SOURCE */
#endif
