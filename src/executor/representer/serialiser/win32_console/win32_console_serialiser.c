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

#ifndef WIN32_CONSOLE_SERIALISER_SOURCE
#define WIN32_CONSOLE_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/boolean/boolean_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/decimal_fraction/decimal_fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/date_time_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction_cybol_serialiser.c"
//?? #include "../../../../executor/representer/serialiser/win32_console/part_win32_console_serialiser.c"
#include "../../../../logger/logger.c"

// Win32 console applications are often mistaken for MS-DOS applications,
// especially on Windows 9x and Windows Me. However, a Win32 console
// application is, virtually, just a special form of a native Win32 application.
// Indeed, 32-bit Windows can run MS-DOS programs in Win32 console
// through the use of the NT Virtual DOS Machine (NTVDM).
//
// Programmes may access a Win32 console either via high-level functions
// (such as ReadConsole and WriteConsole) or via low-level functions
// (e.g. ReadConsoleInput and WriteConsoleOutput).
// These high-level functions are more limited than a Win32 GUI;
// for instance it is not possible for a programme to change the color palette,
// nor is it possible to modify the font used by the console using these functions.
//
// The input buffer is a queue where events are stored (from keyboard, mouse etc.).
// The output buffer is a rectangular grid where characters are stored,
// together with their attributes. A console window may have several output
// buffers, only one of which is active (i.e. displayed) for a given moment.
//
// Unfortunately, the display mode is locked in background intensity mode,
// thus BLINKING does NOT work. Also, the UNDERSCORE attribute is NOT available.

/**
 * Serialises the source part into win32 console function calls.
 *
 * @param p0 the internal memory data
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 */
void serialise_win32_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // Set current cursor position.
    // SetConsoleCursorPosition();

    // Set foreground and background colour.
    // SetConsoleTextAttribute();

    //
    // Write to screen buffer.
    //
    //?? CAUTION! flush needed at the end of all in "send_terminal"?
    //
    // The "WriteConsole" function writes characters to the
    // console screen buffer at the current cursor position.
    // The cursor position ADVANCES as characters are written.
    //
    // Characters are written using the foreground and background
    // colour attributes associated with the console screen buffer.
    // Information: To determine the current color attributes and
    // the current cursor position, use "GetConsoleScreenBufferInfo".
    //
    // WriteConsole();

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console.");
}

/* WIN32_CONSOLE_SERIALISER_SOURCE */
#endif
