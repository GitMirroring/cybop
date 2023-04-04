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

#ifndef LIVE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define LIVE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Live
//
// IANA media type: not defined
// Self-defined media type: live
// This media type is a CYBOL extension.
//

/**
 * The live/exit logic cybol format.
 *
 * Description:
 *
 * Exits the cyboi system and closes the running application.
 *
 * Internally, an exit flag gets set so that the event loop gets left.
 * Interrupt threads get exited, too. All objects in memory get deallocated.
 * The cyboi interpreter finally exits.
 *
 * Examples:
 *
 * <node name="exit_application" channel="inline" format="live/exit" model=""/>
 */
static wchar_t* EXIT_LIVE_LOGIC_CYBOL_FORMAT = L"live/exit";
static int* EXIT_LIVE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIVE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
