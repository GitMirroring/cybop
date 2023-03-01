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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef RANDOMISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define RANDOMISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Randomise
//
// IANA media type: not defined
// Self-defined media type: randomise
// This media type is a CYBOL extension.
//

/**
 * The randomise/retrieve logic cybol format.
 *
 * Description:
 *
 * Retrieves the next pseudo-random number in the series.
 *
 * Caution! If calling "randomise/retrieve" before a seed has been established with "randomise/sow", the value of 1 is used as default seed inside glibc.
 *
 * Examples:
 *
 * <node name="get_next_random_number" channel="inline" format="randomise/retrieve" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".game.board.field_1"/>
 *     <node name="minimum" channel="inline" format="number/integer" model="2"/>
 *     <node name="maximum" channel="inline" format="number/integer" model="14"/>
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
 * - result (required) [text/cybol-path]: The pseudo-random value delivered by the system.
 * - minimum (optional) [text/cybol-path | number/integer]: The lower bound (inclusive) of the value to be generated. If null, the default is zero.
 * - maximum (optional) [text/cybol-path | number/integer]: The upper bound (exclusive) of the value to be generated. If null, the default is RAND_MAX. The GNU C Library's RAND_MAX value 2147483647 is the largest signed integer representable in 32 bits.
 */
static wchar_t* RETRIEVE_RANDOMISE_LOGIC_CYBOL_FORMAT = L"randomise/retrieve";
static int* RETRIEVE_RANDOMISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The randomise/sow logic cybol format.
 *
 * Description:
 *
 * Sows a seed for a new series of pseudo-random numbers.
 *
 * Examples:
 *
 * <node name="set_seed" channel="inline" format="randomise/sow" model="">
 *     <node name="seed" channel="inline" format="text/cybol-path" model=".app.var.seed"/>
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
 * - seed (required) [text/cybol-path | number/integer]: The source seed to be established for a new series of pseudo-random numbers.
 */
static wchar_t* SOW_RANDOMISE_LOGIC_CYBOL_FORMAT = L"randomise/sow";
static int* SOW_RANDOMISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RANDOMISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
