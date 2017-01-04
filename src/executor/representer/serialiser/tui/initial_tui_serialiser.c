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

#ifndef INITIAL_TUI_SERIALISER_SOURCE
#define INITIAL_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
// CAUTION! Do NOT include the "content_element_part_tui_serialiser.c" module.
// It is true, the "serialise_tui_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "tui_serialiser.c" module is included here.
#include "../../../../executor/representer/serialiser/tui/tui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the tui serialiser.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the knowledge memory part
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the clear flag
 * @param p9 the newline flag
 * @param p10 the cli flag
 * @param p11 the format
 */
void serialise_tui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui initial.");

    // The output.
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The tree level.
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL
    // constant directly, since the value gets changed in the functions!
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The original attributes.
    //
    // CAUTION! Black colour is defined by specifying no red-green-blue (rgb)
    // value at all. But if attributes were set to some colour previously,
    // then black will not be displayed.
    // On the other hand, if resetting the attributes value to zero,
    // then foreground AND background are black. But if none of them
    // is set as cybol property, e.g. for command line interface (cli)
    // output, then output will be invisible.
    // Therefore, the original attributes have to be stored here,
    // in order to be forwarded as parametre and to be used
    // to reset attributes for each output.
    //
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL
    // constant directly, since the value gets changed in the functions!
#ifdef WIN32
    WORD a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
#else
    // CAUTION! This is just a placeholder variable, since
    // something HAS to be forwarded as parametre below.
    // It has no meaning outside win32.
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
#endif

    // Get output.
    copy_array_forward((void*) &op, p7, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // CAUTION! Handing over the output item is necessary
    // for serialising into a win32 console, since
    // win32 console functions have to be called inside.
    //
    // CAUTION! The text user interface (tui) serialiser is reused
    // for the command line interface (cli) language here.
    // The only difference is the CLI FLAG handed over,
    // which is used to avoid cursor positioning,
    // since that is NOT wanted for cli.
    serialise_tui_part_element_content(p0, op, p1, p2, p3, p4, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, (void*) &l, p10, (void*) &a, p11);
}

/* INITIAL_TUI_SERIALISER_SOURCE */
#endif
