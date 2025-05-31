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

#ifndef TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * Starts top in Batch mode, which could be useful
 * for sending output from top to other programmes
 * or to a file.
 *
 * In this mode, top will not accept input and runs
 * until the iterations limit you've set with the
 * '-n' command-line option or until killed.
 */
static wchar_t* BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME = L"batch";
static int* BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * Starts top with the last remembered 'c' state reversed.
 *
 * Thus, if top was displaying command lines, now that field
 * will show programme names, and visa versa.
 *
 * See the 'c' interactive command for additional information.
 */
static wchar_t* COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME = L"command";
static int* COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * Instructs top to display individual threads.
 *
 * Without this command-line option, a summation of all threads
 * in each process is shown. Later this can be changed with the
 * 'H' interactive command.
 */
static wchar_t* THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME = L"thread";
static int* THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * Starts top with the last remembered 'i' state reversed.
 *
 * When this toggle is off, tasks that have not used any CPU
 * since the last update will not be displayed.
 */
static wchar_t* IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME = L"idle";
static int* IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * Starts top with secure mode forced, even for root.
 *
 * This mode is far better controlled through the
 * system configuration file.
 */
static wchar_t* SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME = L"secure";
static int* SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
