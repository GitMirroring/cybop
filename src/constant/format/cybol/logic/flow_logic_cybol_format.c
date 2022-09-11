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
 * Branches the programme flow, depending on the criterion flag.
 *
 * Description:
 *
Branches the programme flow, depending on the criterion flag.
 *
 * Examples:
 *
 * <node name="branch_voltage" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".settings.voltage_criterion"/>
 *     <node name="true" channel="file" format="element/part" model="indoor_climate/add_voltage.cybol"/>
 *     <node name="false" channel="file" format="element/part"
      model="indoor_climate/report_voltage_failure.cybol"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
criterion	the flag specifying which of the two models to execute	true	path/* | logicvalue/boolean
true	the logic knowledge model to be executed if the condition is true	true	element/part
false	the logic knowledge model to be executed if the condition is false	true	element/part
 *
 * Parametres:
 * - criterion (required): the flag specifying which of the two models to execute
 * - true (optional): the logic knowledge model to be executed if the condition is true
 * - false (optional): the logic knowledge model to be executed if the condition is false
 */
static wchar_t* BRANCH_FLOW_LOGIC_CYBOL_FORMAT = L"flow/branch";
static int* BRANCH_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/loop logic cybol format.
 *
 * Loop control flow until break flag is set.
 * Loops the programme flow endlessly, until the break flag is set.
 *
 * Description:
 *
Loops the programme flow endlessly, until the break flag is set.
 *
 * Examples:
 *
 * <node name="collect_voltages" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model=".settings.adc_break"/>
 *     <node name="model" channel="file" format="element/part" model="adc/collect_voltages.cybol"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
break	the break flag; once set, the loop will be left (exited)	true	path/* | logicvalue/boolean
model	the logic knowledge model to be executed repeatedly by the loop	true	path/* | element/part
 *
 * Parametres:
 * - break (required): the break flag; once set, the loop will be left (exited)
 * - model (required): the logic knowledge model to be executed repeatedly by the loop
 */
static wchar_t* LOOP_FLOW_LOGIC_CYBOL_FORMAT = L"flow/loop";
static int* LOOP_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/sequence logic cybol format.
 *
 * Process commands as sequence.
 * Executes the given programme flow as sequence.
 *
 * Description:
 *
Executes the given programme flow as sequence.
 *
 * Examples:
 *
 * <node name="start_playerinput" channel="inline" format="flow/sequence" model="">
  <node name="model" channel="inline" format="text/cybol-path" model=".app.setrandom"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
model	the logic knowledge model to be executed as sequence	true	text/cybol-path
 *
 * Parametres:
 * - model (required): the logic knowledge model to be executed as sequence
 */
static wchar_t* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT = L"flow/sequence";
static int* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
