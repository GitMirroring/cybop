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

#ifndef CLEAR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define CLEAR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include "../../../../constant/model/ansi_escape_code/ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Clears the terminal.
 *
 * Example:
 * printf("\033[2J")
 *
 * @param p0 the destination item
 */
void serialise_ansi_escape_code_clear(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code clear.");

    append_item_element(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    append_item_element(p0, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
}

/* CLEAR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
