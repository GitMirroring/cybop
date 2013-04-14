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

#ifndef CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/ansi_escape_code/ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/tui/properties_tui_serialiser.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/representer/serialiser/win32_console/reset_win32_console_serialiser.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/ansi_escape_code/reset_ansi_escape_code_serialiser.c"
#endif

//
// Forward declarations.
//

void serialise_tui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Serialises the part element content into tui.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the source whole properties data
 * @param p6 the source whole properties count
 * @param p7 the knowledge memory part
 * @param p8 the format data
 */
void serialise_tui_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui part element content.");

    // Append properties.
    serialise_tui_properties(p0, p3, p4, p5, p6, p7);

    // Append model.
    serialise_tui(p0, p1, p2, p3, p4, p7, p8);

    // Reset terminal attributes in order to
    // have original settings when leaving cyboi.
#ifdef WIN32
        serialise_win32_console_reset(p0);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
        serialise_ansi_escape_code_reset(p0);
#endif
}

/* CONTENT_ELEMENT_PART_TUI_SERIALISER_SOURCE */
#endif
