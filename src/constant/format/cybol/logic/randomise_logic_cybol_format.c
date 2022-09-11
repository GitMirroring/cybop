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
 * Retrieve next pseudo-random number in the series.
 *
 * Description:
 *
Retrieve next pseudo-random number in the series.
 *
 * Examples:
 *
 * <node name="get_random_number_1" channel="inline" format="randomise/retrieve" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".app.var.field_1"/>
 *     <node name="minimum" channel="inline" format="number/integer" model="2"/>
 *     <node name="maximum" channel="inline" format="number/integer" model="14"/>
 *     <node name="seed" channel="inline" format="text/cybol-path" model=".app.var.seed"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The path where the retrieved random value is written to.	true	text/cybol-path
minimum	The lower bound of the to generate value. (inclusive)	true	meta/type
maximum	The upper bound of the to generate value.	true	meta/type
seed	The path to the seed used for generating the random value.	true	text/cybol-path
 *
 * Expected parametres:
 * - result (required): the time
 * - minimum (optional; if null, the value of zero will be used instead):
 *   the minimum (inclusive)
 * - maximum (optional; if null, the GNU C Library's RAND_MAX value 2147483647 which is the largest signed integer representable in 32 bits will be used instead):
 *   the maximum (exclusive)
 */
static wchar_t* RETRIEVE_RANDOMISE_LOGIC_CYBOL_FORMAT = L"randomise/retrieve";
static int* RETRIEVE_RANDOMISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The randomise/sow logic cybol format.
 *
 * Sow a seed for a new series of pseudo-random numbers.
 *
 * Description:
 *
Sow a seed for a new series of pseudo-random numbers.
 *
 * Examples:
 *
 * <node name="set_seed" channel="inline" format="randomise/sow" model="">
 *     <node name="seed" channel="inline" format="text/cybol-path" model=".app.var.seed"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
seed	The path where the seed is written to.	true	text/cybol-path
 *
 * Expected parametres:
 * - seed (required): the source seed to be established for a new series of pseudo-random numbers
 */
static wchar_t* SOW_RANDOMISE_LOGIC_CYBOL_FORMAT = L"randomise/sow";
static int* SOW_RANDOMISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RANDOMISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
