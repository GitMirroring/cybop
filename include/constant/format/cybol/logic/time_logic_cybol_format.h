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

#ifndef TIME_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define TIME_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Time
//
// IANA media type: not defined
// Self-defined media type: time
// This media type is a CYBOL extension.
//

/**
 * The time/current logic cybol format.
 *
 * Description:
 *
 * Retrieves the current system time in nano seconds, divided by 1000.
 *
 * Examples:
 *
 * <node name="determine_current_time" channel="inline" format="time/current" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".integer_variable"/>
 * </node>
 *
 * <!--
 *     Operation calls using the same seed deliver identical pseudo random numbers.
 *     Ideally, the seed should change with every call.
 *     Therefore, the current time is determined as seed here.
 * -->
 * <node name="get_time" channel="inline" format="time/current" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".seed"/>
 * </node>
 * <node name="set_seed" channel="inline" format="randomise/sow" model="">
 *     <node name="seed" channel="inline" format="text/cybol-path" model=".seed"/>
 * </node>
 * <node name="get_random_number" channel="inline" format="randomise/retrieve" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="minimum" channel="inline" format="number/integer" model="1"/>
 *     <node name="maximum" channel="inline" format="number/integer" model="9"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The node storing the result value.
 */
static wchar_t* CURRENT_TIME_LOGIC_CYBOL_FORMAT = L"time/current";
static int* CURRENT_TIME_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TIME_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
