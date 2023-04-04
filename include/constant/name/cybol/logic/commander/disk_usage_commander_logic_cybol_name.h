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

#ifndef DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The human-readable option for the disk usage logic in cybol. */
static wchar_t* HUMAN_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME = L"human";
static int* HUMAN_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The summarize option for the disk usage logic in cybol. */
static wchar_t* SUMMARIZE_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME = L"summarize";
static int* SUMMARIZE_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The all option for the disk usage logic in cybol. */
static wchar_t* ALL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME = L"all";
static int* ALL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bytes option for the disk usage logic in cybol. */
static wchar_t* BYTES_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME = L"bytes";
static int* BYTES_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The total option for the disk usage logic in cybol. */
static wchar_t* TOTAL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME = L"total";
static int* TOTAL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
