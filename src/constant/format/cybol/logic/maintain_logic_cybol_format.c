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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Maintain
//
// IANA media type: not defined
// Self-defined media type: maintain
// This media type is a CYBOL extension.
//

/**
 * The maintain/shutdown logic cybol format.
 *
 * Shutdown sensing service.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/shutdown";
static int* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maintain/startup logic cybol format.
 *
 * Startup sensing service.
 *
 * This is a CYBOL extension.
 */
static wchar_t* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/startup";
static int* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
