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

#ifndef LOGICVALUE_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define LOGICVALUE_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Logic value
//
// IANA media type: not defined
// Self-defined media type: logicvalue
// This media type is a CYBOL extension.
//

/**
 * The logicvalue/boolean state cybol format.
 *
 * Description:
 *
 * A boolean logic variable represents one of two possible states,
 * either true or false.
 *
 * Sometimes, a boolean value is called a flag.
 *
 * Examples:
 *
 * <node name="value" channel="inline" format="logicvalue/boolean" model="true"/>
 */
static wchar_t* BOOLEAN_LOGICVALUE_STATE_CYBOL_FORMAT = L"logicvalue/boolean";
static int* BOOLEAN_LOGICVALUE_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGICVALUE_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
