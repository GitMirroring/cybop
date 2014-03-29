/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE
#define TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The "all" test unit option cyboi model. */
static wchar_t* ALL_TEST_UNIT_OPTION_CYBOI_MODEL = L"all";
static int* ALL_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The applicator module test units.
 * Test IDs range from 1 to 99.
 */

/** The overall applicator test unit option model.*/
static wchar_t* APPLICATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator";
static int* APPLICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The access test unit option cyboi model. */
static wchar_t* APPLICATOR_ACCESS_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/access";
static int* APPLICATOR_ACCESS_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/calculate test unit option cyboi model. */
static wchar_t* APPLICATOR_CALCULATE_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/calculate";
static int* APPLICATOR_CALCULATE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/cast test unit option cyboi model. */
static wchar_t* APPLICATOR_CAST_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/cast";
static int* APPLICATOR_CAST_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/command test unit option cyboi model. */
static wchar_t* APPLICATOR_COMMAND_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/command";
static int* APPLICATOR_COMMAND_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/compare test unit option cyboi model. */
static wchar_t* APPLICATOR_COMPARE_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/compare";
static int* APPLICATOR_COMPARE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/flow test unit option cyboi model. */
static wchar_t* APPLICATOR_FLOW_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/flow";
static int* APPLICATOR_FLOW_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/live test unit option cyboi model. */
static wchar_t* APPLICATOR_LIVE_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/live";
static int* APPLICATOR_LIVE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/logify test unit option cyboi model. */
static wchar_t* APPLICATOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/logifier";
static int* APPLICATOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/maintain test unit option cyboi model. */
static wchar_t* APPLICATOR_MAINTAIN_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/maintain";
static int* APPLICATOR_MAINTAIN_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/manipulate test unit option cyboi model. */
static wchar_t* APPLICATOR_MANIPULATE_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/manipulate";
static int* APPLICATOR_MANIPULATE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/memorise test unit option cyboi model. */
static wchar_t* APPLICATOR_MEMORISE_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/memorise";
static int* APPLICATOR_MEMORISE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/modify test unit option cyboi model. */
static wchar_t* APPLICATOR_MODIFY_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/modify";
static int* APPLICATOR_MODIFY_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/represent test unit option cyboi model. */
static wchar_t* APPLICATOR_REPRESENT_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/represent";
static int* APPLICATOR_REPRESENT_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/run test unit option cyboi model. */
static wchar_t* APPLICATOR_RUN_TEST_UNIT_OPTION_CYBOI_MODEL = L"applicator/run";
static int* APPLICATOR_RUN_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;


///**
 //* The controller modul test units
 //* The test IDs range from 100 to 199.
 //*/

/** The overall controller test unit option cyboi model. */
static wchar_t* CONTROLLER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller";
static int* CONTROLLER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/checker test unit option cyboi model. */
static wchar_t* CONTROLLER_CHECKER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/checker";
static int* CONTROLLER_CHECKER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/deoptionaliser test unit option cyboi model. */
static wchar_t* CONTROLLER_DEOPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/deoptionaliser";
static int* CONTROLLER_DEOPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/globaliser test unit option cyboi model. */
static wchar_t* CONTROLLER_GLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/globaliser";
static int* CONTROLLER_GLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/handler test unit option cyboi model. */
static wchar_t* CONTROLLER_HANDLER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/handler";
static int* CONTROLLER_HANDLER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/manager test unit option cyboi model. */
static wchar_t* CONTROLLER_MANAGER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/manager";
static int* CONTROLLER_MANAGER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/optionaliser test unit option cyboi model. */
static wchar_t* CONTROLLER_OPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/optionaliser";
static int* CONTROLLER_OPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/unglobaliser test unit option cyboi model. */
static wchar_t* CONTROLLER_UNGLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"controller/unglobaliser";
static int* CONTROLLER_UNGLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
* The executer modul test units.
* The Test IDs range from 200 to 299.
*/

/** The overall executer test unit option cyboi model. */
static wchar_t* EXECUTOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor";
static int* EXECUTOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/accessor test unit option cyboi model. */
static wchar_t* EXECUTOR_ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/accessor";
static int* EXECUTOR_ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/calculator test unit option cyboi model. */
static wchar_t* EXECUTOR_CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/calculator";
static int* EXECUTOR_CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/caster test unit option cyboi model. */
static wchar_t* EXECUTOR_CASTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/caster";
static int* EXECUTOR_CASTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/commander test unit option cyboi model. */
static wchar_t* EXECUTOR_COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/commander";
static int* EXECUTOR_COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/communicator test unit option cyboi model. */
static wchar_t* EXECUTOR_COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/communicator";
static int* EXECUTOR_COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/comparator test unit option cyboi model. */
static wchar_t* EXECUTOR_COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/comparator";
static int* EXECUTOR_COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/converter test unit option cyboi model. */
static wchar_t* EXECUTOR_CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/converter";
static int* EXECUTOR_CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/lifeguard test unit option cyboi model. */
static wchar_t* EXECUTOR_LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/lifeguard";
static int* EXECUTOR_LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/logifier test unit option cyboi model. */
static wchar_t* EXECUTOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/logifier";
static int* EXECUTOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/maintainer test unit option cyboi model. */
static wchar_t* EXECUTOR_MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/maintainer";
static int* EXECUTOR_MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/manipulator test unit option cyboi model. */
static wchar_t* EXECUTOR_MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/manipulator";
static int* EXECUTOR_MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/memoriser test unit option cyboi model. */
static wchar_t* EXECUTOR_MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/memoriser";
static int* EXECUTOR_MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/modifier test unit option cyboi model. */
static wchar_t* EXECUTOR_MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/modifier";
static int* EXECUTOR_MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/referencer test unit option cyboi model. */
static wchar_t* EXECUTOR_REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/referencer";
static int* EXECUTOR_REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/representer test unit option cyboi model. */
static wchar_t* EXECUTOR_REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/representer";
static int* EXECUTOR_REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/runner test unit option cyboi model. */
static wchar_t* EXECUTOR_RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/runner";
static int* EXECUTOR_RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executor/searcher test unit option cyboi model. */
static wchar_t* EXECUTOR_SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL = L"executor/searcher";
static int* EXECUTOR_SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
