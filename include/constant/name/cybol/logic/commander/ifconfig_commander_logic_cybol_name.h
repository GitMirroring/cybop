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

#ifndef IFCONFIG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define IFCONFIG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The INTERFACE parameter for the IFCONFIG content logic in cybol. */
static wchar_t* INTERFACE_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"interface";
static int* INTERFACE_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UP parameter for the IFCONFIG content logic in cybol. */
static wchar_t* UP_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"up";
static int* UP_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The DOWN parameter for the IFCONFIG content logic in cybol. */
static wchar_t* DOWN_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"down";
static int* DOWN_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SHORT parameter for the IFCONFIG content logic in cybol. */
static wchar_t* SHORT_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"short";
static int* SHORT_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ALL parameter for the IFCONFIG content logic in cybol. */
static wchar_t* ALL_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"all";
static int* ALL_IFCONFIG_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* IFCONFIG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
