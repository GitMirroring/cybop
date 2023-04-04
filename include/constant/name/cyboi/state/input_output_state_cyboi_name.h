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

#ifndef INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_HEADER
#define INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! The input output entry size is set in file "state_cyboi_model.h"!
//

//
// CAUTION! There is NOT just one global server list, but SEPARATE ones
// for each channel. Only display and socket do have servers anyway.
// Likewise, there is one SEPARATE client list per channel.
//
// The reasons are that:
//
// (1) identification numbers are different only WITHIN,
//     but NOT across channels
//
// (2) client and server identification numbers MUST NOT be mixed,
//     since a cybol application may act as client AND server at the same time
//

//
// Communication partner lists
//
// CAUTION! These are ITEMS, not just pure arrays.
//

static int* CLIENTS_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Backlink
//

static int* INTERNAL_MEMORY_BACKLINK_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_HEADER */
#endif
