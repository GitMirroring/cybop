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

#ifndef FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Flow
//
// IANA media type: not defined
// Self-defined media type: flow
// This media type is a CYBOL extension.
//

/**
 * The flow/branch logic cybol format.
 *
 * Branch control flow according to a given criterion.
 *
 * This is a CYBOL extension.
 */
static wchar_t* BRANCH_FLOW_LOGIC_CYBOL_FORMAT = L"flow/branch";
static int* BRANCH_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/loop logic cybol format.
 *
 * Loop control flow until break flag is set.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LOOP_FLOW_LOGIC_CYBOL_FORMAT = L"flow/loop";
static int* LOOP_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/sequence logic cybol format.
 *
 * Process commands as sequence.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT = L"flow/sequence";
static int* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
