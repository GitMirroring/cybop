/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIT_TEST_CYBOI_MODEL_CONSTANT_SOURCE
#define UNIT_TEST_CYBOI_MODEL_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"


/** The "all" test unit option cyboi model. */
static int* ALL_UNIT_TEST_CYBOI_MODEL = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The applicator module test units.
 * Test IDs range from 1 to 99.
 */

/** The overall applicator test unit option model.*/
static int* APPLICATOR_UNIT_TEST_CYBOI_MODEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The access test unit option cyboi model. */
static int* APPLICATOR_ACCESS_UNIT_TEST_CYBOI_MODEL = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/calculate test unit option cyboi model. */
static int* APPLICATOR_CALCULATE_UNIT_TEST_CYBOI_MODEL = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/cast test unit option cyboi model. */
static int* APPLICATOR_CAST_UNIT_TEST_CYBOI_MODEL = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/command test unit option cyboi model. */
static int* APPLICATOR_COMMAND_UNIT_TEST_CYBOI_MODEL = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/compare test unit option cyboi model. */
static int* APPLICATOR_COMPARE_UNIT_TEST_CYBOI_MODEL = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/flow test unit option cyboi model. */
static int* APPLICATOR_FLOW_UNIT_TEST_CYBOI_MODEL = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/live test unit option cyboi model. */
static int* APPLICATOR_LIVE_UNIT_TEST_CYBOI_MODEL = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/logify test unit option cyboi model. */
static int* APPLICATOR_LOGIFIER_UNIT_TEST_CYBOI_MODEL = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/maintain test unit option cyboi model. */
static int* APPLICATOR_MAINTAIN_UNIT_TEST_CYBOI_MODEL = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/manipulate test unit option cyboi model. */
static int* APPLICATOR_MANIPULATE_UNIT_TEST_CYBOI_MODEL = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/memorise test unit option cyboi model. */
static int* APPLICATOR_MEMORISE_UNIT_TEST_CYBOI_MODEL = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/modify test unit option cyboi model. */
static int* APPLICATOR_MODIFY_UNIT_TEST_CYBOI_MODEL = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/represent test unit option cyboi model. */
static int* APPLICATOR_REPRESENT_UNIT_TEST_CYBOI_MODEL = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applicator/run test unit option cyboi model. */
static int* APPLICATOR_RUN_UNIT_TEST_CYBOI_MODEL = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The controller modul test units
 * The test IDs range from 100 to 199.
 */

/** The overall controller test unit option cyboi model. */
static int* CONTROLLER_UNIT_TEST_CYBOI_MODEL = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/checker test unit option cyboi model. */
static int* CONTROLLER_CHECKER_UNIT_TEST_CYBOI_MODEL = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/deoptionaliser test unit option cyboi model. */
static int* CONTROLLER_DEOPTIONALISER_UNIT_OPTION_CYBOI_MODEL = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The controller/globaliser test unit option cyboi model. */
static int* CONTROLLER_GLOBALISER_UNIT_TEST_CYBOI_MODEL = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/handler test unit option cyboi model. */
static int* CONTROLLER_HANDLER_UNIT_TEST_CYBOI_MODEL = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/manager test unit option cyboi model. */
static int* CONTROLLER_MANAGER_UNIT_TEST_CYBOI_MODEL = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/optionaliser test unit option cyboi model. */
static int* CONTROLLER_OPTIONALISER_UNIT_OPTION_CYBOI_MODEL = NUMBER_106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overall controller/unglobaliser test unit option cyboi model. */
static int* CONTROLLER_UNGLOBALISER_UNIT_TEST_CYBOI_MODEL = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The executer modul test units.
 * The Test IDs range from 200 to 299.
 */

/** The overall executer test unit option cyboi model. */
static int* EXECUTER_UNIT_TEST_CYBOI_MODEL = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/accessor test unit option cyboi model. */
static int* EXECUTER_ACCESSOR_UNIT_TEST_CYBOI_MODEL = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/calculator test unit option cyboi model. */
static int* EXECUTER_CALCULATOR_UNIT_TEST_CYBOI_MODEL = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/caster test unit option cyboi model. */
static int* EXECUTER_CASTER_UNIT_TEST_CYBOI_MODEL = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/commander test unit option cyboi model. */
static int* EXECUTER_COMMANDER_UNIT_TEST_CYBOI_MODEL = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/communicator test unit option cyboi model. */
static int* EXECUTER_COMMUNICATOR_UNIT_TEST_CYBOI_MODEL = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/comparator test unit option cyboi model. */
static int* EXECUTER_COMPARATOR_UNIT_TEST_CYBOI_MODEL = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/converter test unit option cyboi model. */
static int* EXECUTER_CONVERTER_UNIT_TEST_CYBOI_MODEL = NUMBER_207_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/lifeguard test unit option cyboi model. */
static int* EXECUTER_LIFEGUARD_UNIT_TEST_CYBOI_MODEL = NUMBER_208_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/logifier test unit option cyboi model. */
static int* EXECUTER_LOGIFIER_UNIT_TEST_CYBOI_MODEL = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/maintainer test unit option cyboi model. */
static int* EXECUTER_MAINTAINER_UNIT_TEST_CYBOI_MODEL = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/manipulator test unit option cyboi model. */
static int* EXECUTER_MANIPULATOR_UNIT_TEST_CYBOI_MODEL = NUMBER_211_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/memoriser test unit option cyboi model. */
static int* EXECUTER_MEMORISER_UNIT_TEST_CYBOI_MODEL = NUMBER_212_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/modifier test unit option cyboi model. */
static int* EXECUTER_MODIFIER_UNIT_TEST_CYBOI_MODEL = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/referencer test unit option cyboi model. */
static int* EXECUTER_REFERENCER_UNIT_TEST_CYBOI_MODEL = NUMBER_214_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/representer test unit option cyboi model. */
static int* EXECUTER_REPRESENTER_UNIT_TEST_CYBOI_MODEL = NUMBER_215_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/runner test unit option cyboi model. */
static int* EXECUTER_RUNNER_UNIT_TEST_CYBOI_MODEL = NUMBER_216_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The executer/searcher test unit option cyboi model. */
static int* EXECUTER_SEARCHER_UNIT_TEST_CYBOI_MODEL = NUMBER_217_INTEGER_STATE_CYBOI_MODEL_ARRAY;
/* UNIT_TEST_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
