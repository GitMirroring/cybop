/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Activate
//
// IANA media type: not defined
// Self-defined media type: activate
// This media type is a CYBOL extension.
//

/**
 * The activate/disable logic cybol format.
 *
 * Disable a communication channel.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Parametres:
 * - channel (required): the channel, e.g. socket, display
 * - port (optional): the service identification, e.g. socket port 80, optional for display with default port 0 (zero)
--

--
 */
static wchar_t* DISABLE_ACTIVATE_LOGIC_CYBOL_FORMAT = L"activate/disable";
static int* DISABLE_ACTIVATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The activate/enable logic cybol format.
 *
 * Enable a communication channel.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Parametres:
 * - channel (required): the channel, e.g. socket, display
 * - port (optional): the service identification, e.g. socket port 80, optional for display with default port 0 (zero)
 * - handler (optional): the handler
 */
static wchar_t* ENABLE_ACTIVATE_LOGIC_CYBOL_FORMAT = L"activate/enable";
static int* ENABLE_ACTIVATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
