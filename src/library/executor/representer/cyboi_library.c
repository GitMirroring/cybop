/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// command line
//

#include "../../../executor/representer/deserialiser/command_line/argument_command_line_deserialiser.c"
#include "../../../executor/representer/deserialiser/command_line/command_line_deserialiser.c"
#include "../../../executor/representer/deserialiser/command_line/option_command_line_deserialiser.c"
#include "../../../executor/representer/deserialiser/command_line/wide_argument_command_line_deserialiser.c"

#include "../../../executor/selector/command_line/log_level_command_line_selector.c"
#include "../../../executor/selector/command_line/mode_command_line_selector.c"
#include "../../../executor/selector/command_line/option_command_line_selector.c"
