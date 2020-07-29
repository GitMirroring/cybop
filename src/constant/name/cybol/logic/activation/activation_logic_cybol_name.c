/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The channel activation logic cybol name. */
static wchar_t* CHANNEL_ACTIVATION_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The handler activation logic cybol name. */
static wchar_t* HANDLER_ACTIVATION_LOGIC_CYBOL_NAME = L"handler";
static int* HANDLER_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification (id) activation logic cybol name. */
static wchar_t* IDENTIFICATION_ACTIVATION_LOGIC_CYBOL_NAME = L"id";
static int* IDENTIFICATION_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sender activation logic cybol name. */
static wchar_t* SENDER_ACTIVATION_LOGIC_CYBOL_NAME = L"sender";
static int* SENDER_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The (network) service activation logic cybol name. */
static wchar_t* SERVICE_ACTIVATION_LOGIC_CYBOL_NAME = L"service";
static int* SERVICE_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
