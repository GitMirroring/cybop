/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef GET_FILE_NUMBER_TERMINAL_EDITOR_SOURCE
#define GET_FILE_NUMBER_TERMINAL_EDITOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/maintainer/editor/unix_terminal/get_file_number_unix_terminal_editor.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/maintainer/editor/unix_terminal/get_file_number_unix_terminal_editor.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/editor/win32_console/get_file_number_win32_console_editor.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Gets the file number from the given file stream.
 *
 * The file number has various synonyms:
 * - posix: file descriptor of type int, used in direct file access functions
 * - win32: file handle of type DWORD, used in alternative input/output functions
 *
 * @param p0 the file number
 * @param p1 the file stream
 */
void edit_terminal_file_number_get(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Edit terminal file number get.");

#if defined(__linux__) || defined(__unix__)
    edit_unix_terminal_file_number_get(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    edit_unix_terminal_file_number_get(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    edit_win32_console_file_number_get(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* GET_FILE_NUMBER_TERMINAL_EDITOR_SOURCE */
#endif
