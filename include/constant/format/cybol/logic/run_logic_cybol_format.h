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

#ifndef RUN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define RUN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Run
//
// IANA media type: not defined
// Self-defined media type: run
// This media type is a CYBOL extension.
//

/**
 * The run/run logic cybol format.
 *
 * Description:
 *
 * Executes a local programme.
 *
 * Examples:
 *
 * <node name="start_mc" channel="inline" format="run/run" model="">
 *     <node name="programme" channel="inline" format="text/plain" model="mc"/>
 * </node>
 *
 * <node name="start_dosemu" channel="inline" format="run/run" model="">
 *     <node name="programme" channel="inline" format="text/plain" model="xdosemu"/>
 * </node>
 *
 * <!-- Sleep for some time so that the output can be read by the user. -->
 * <node name="run_shell_command" channel="inline" format="run/run" model="">
 *     <node name="programme" channel="inline" format="text/plain" model="sleep 1.8"/>
 * </node>
 *
 * <node name="execute_shell_script" channel="inline" format="run/run" model="">
 *     <node name="programme" channel="file" format="text/plain" model="password_generator/sleep_timer.sh"/>
 * </node>
 *
 * Properties:
 *
 * - programme (required) [text/cybol-path]: The programme to be executed.
 */
static wchar_t* RUN_LOGIC_CYBOL_FORMAT = L"run/run";
static int* RUN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The run/sleep-nano logic cybol format.
 *
 * Description:
 *
 * Puts the executing thread to sleep for at least x nanoseconds.
 *
 * Caution! The actual duration may differ depending on the system's load and timer accuracy.
 *
 * Examples:
 *
 * <node name="sleep" channel="inline" format="run/sleep-nano" model="">
 *     <node name="duration" channel="inline" format="text/cybol-path" model=".settings.voltage_sleep"/>
 * </node>
 *
 * Properties:
 *
 * - duration (required) [text/cybol-path | number/integer]: The time as amount of nanoseconds to sleep.
 */
static wchar_t* NANO_SLEEP_RUN_LOGIC_CYBOL_FORMAT = L"run/sleep-nano";
static int* NANO_SLEEP_RUN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The run/sleep-second logic cybol format.
 *
 * Description:
 *
 * Puts the executing thread to sleep for at least x seconds.
 *
 * Caution! The actual duration may differ depending on the system's load and timer accuracy.
 *
 * Examples:
 *
 * <node name="sleep" channel="inline" format="run/sleep-second" model="">
 *     <node name="duration" channel="inline" format="text/cybol-path" model=".var.sleeptime"/>
 * </node>
 *
 * Properties:
 *
 * - duration (required) [text/cybol-path | number/integer]: The time as amount of seconds to sleep.
 */
static wchar_t* SECOND_SLEEP_RUN_LOGIC_CYBOL_FORMAT = L"run/sleep-second";
static int* SECOND_SLEEP_RUN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RUN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
