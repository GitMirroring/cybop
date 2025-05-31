/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Resets the terminal attributes.
 *
 * Example:
 * printf("\033[0m")
 *
 * @param p0 the destination item
 */
void serialise_ansi_escape_code_reset(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code reset.");

    serialise_ansi_escape_code_character(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);
    serialise_ansi_escape_code_character(p0, (void*) OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL, (void*) OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT);
    serialise_ansi_escape_code_character(p0, (void*) ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL, (void*) ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);
}
