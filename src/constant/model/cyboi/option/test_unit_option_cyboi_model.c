/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE
#define TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The "all" test unit option cyboi model. */
static wchar_t* ALL_TEST_UNIT_OPTION_CYBOI_MODEL = L"all";
static int* ALL_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accessor test unit option cyboi model. */
/*??
static wchar_t* ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"accessor";
static int* ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The calculator test unit option cyboi model. */
/*??
static wchar_t* CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"calculator";
static int* CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The caster test unit option cyboi model. */
/*??
static wchar_t* CASTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"caster";
static int* CASTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The commander test unit option cyboi model. */
/*??
static wchar_t* COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL = L"commander";
static int* COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The communicator test unit option cyboi model. */
/*??
static wchar_t* COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"communicator";
static int* COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The comparator test unit option cyboi model. */
/*??
static wchar_t* COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"comparator";
static int* COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The container test unit option cyboi model. */
/*??
static wchar_t* CONTAINER_TEST_UNIT_OPTION_CYBOI_MODEL = L"container";
static int* CONTAINER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The converter test unit option cyboi model. */
/*??
static wchar_t* CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"converter";
static int* CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copier test unit option cyboi model. */
static wchar_t* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"copier";
static int* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The lifeguard test unit option cyboi model. */
/*??
static wchar_t* LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL = L"lifeguard";
static int* LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The logifier test unit option cyboi model. */
/*??
static wchar_t* LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"logifier";
static int* LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The maintainer test unit option cyboi model. */
/*??
static wchar_t* MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL = L"maintainer";
static int* MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The manipulator test unit option cyboi model. */
/*??
static wchar_t* MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"manipulator";
static int* MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The memoriser test unit option cyboi model. */
/*??
static wchar_t* MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"memoriser";
static int* MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The modifier test unit option cyboi model. */
/*??
static wchar_t* MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"modifier";
static int* MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copier test unit option cyboi model. */
/*??
static wchar_t* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"copier";
static int* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The packer test unit option cyboi model. */
/*??
static wchar_t* PACKER_TEST_UNIT_OPTION_CYBOI_MODEL = L"packer";
static int* PACKER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pointer test unit option cyboi model. */
static wchar_t* POINTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"pointer";
static int* POINTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The randomiser test unit option cyboi model. */
/*??
static wchar_t* RANDOMISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"randomiser";
static int* RANDOMISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referencer test unit option cyboi model. */
/*??
static wchar_t* REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL = L"referencer";
static int* REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The representer test unit option cyboi model. */
/*??
static wchar_t* REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"representer";
static int* REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The runner test unit option cyboi model. */
/*??
static wchar_t* RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL = L"runner";
static int* RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The searcher test unit option cyboi model. */
/*??
static wchar_t* SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL = L"searcher";
static int* SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The streamer test unit option cyboi model. */
/*??
static wchar_t* STREAMER_TEST_UNIT_OPTION_CYBOI_MODEL = L"streamer";
static int* STREAMER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The timer test unit option cyboi model. */
/*??
static wchar_t* TIMER_TEST_UNIT_OPTION_CYBOI_MODEL = L"timer";
static int* TIMER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/* TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
