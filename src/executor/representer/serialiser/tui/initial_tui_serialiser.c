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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Initialises the tui serialiser.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the sign flag
 * @param p6 the number base
 * @param p7 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the decimal places
 * @param p11 the scientific notation flag
 * @param p12 the newline flag
 * @param p13 the clear flag
 * @param p14 the positioning flag
 * @param p15 the knowledge memory part (pointer reference)
 * @param p16 the stack memory item
 * @param p17 the internal memory data
 * @param p18 the format
 */
void serialise_tui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui initial.");
    //?? fwprintf(stdout, L"Debug: Serialise tui initial. format p18: %i\n", p18);
    //?? fwprintf(stdout, L"Debug: Serialise tui initial. format *p18: %i\n", *((int*) p18));

    // The output.
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The tree level.
    //
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL
    // constant directly, since the value gets changed in the functions!
    //
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //
    // The original attributes.
    //
    // CAUTION! Black colour is defined by specifying no red-green-blue (rgb)
    // value at all. But if attributes were set to some colour previously,
    // then black will not be displayed.
    // On the other hand, if resetting the attributes value to zero,
    // then foreground AND background are black. But if none of them
    // is set as cybol property, e.g. for command line interface (cli)
    // output, then output will be invisible.
    //
    // Therefore, the original attributes have to be stored here,
    // in order to be forwarded as parametre and to be used
    // to reset attributes for each output.
    //
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL
    // constant directly, since the value gets changed in the functions!
    //
#if defined(__linux__) || defined(__unix__)
    //
    // CAUTION! This is just a placeholder variable, since
    // something HAS to be forwarded as parametre below.
    // It has no meaning outside win32.
    //
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
#elif defined(__APPLE__) && defined(__MACH__)
    //
    // CAUTION! This is just a placeholder variable, since
    // something HAS to be forwarded as parametre below.
    // It has no meaning outside win32.
    //
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    WORD a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

    //
    // Get output.
    //
    // CAUTION! Handing over the output item is necessary
    // for serialising into a win32 console, since
    // win32 console functions have to be called inside.
    //
    //?? copy_array_forward((void*) &op, p16, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    //
    // Serialise tui content.
    //
    // CAUTION! The text user interface (tui) serialiser is reused
    // for the command line interface (cli) language here.
    // The only difference is the CLI FLAG handed over,
    // which is used to avoid cursor positioning,
    // since that is NOT wanted for cli.
    //
    serialise_tui_content(p0, op, p1, p2, p3, p4, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, (void*) &l, (void*) &a, p18);
}
