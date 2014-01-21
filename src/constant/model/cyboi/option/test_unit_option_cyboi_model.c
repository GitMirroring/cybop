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

#ifndef TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE
#define TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The accessor test unit option cyboi model. */
static wchar_t* ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"accessor";
static int* ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "all" test unit option cyboi model. */
static wchar_t* ALL_TEST_UNIT_OPTION_CYBOI_MODEL = L"all";
static int* ALL_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The arithmetiser test unit option cyboi model. */
static wchar_t* ARITHMETISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"arithmetiser";
static int* ARITHMETISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The assembler test unit option cyboi model. */
static wchar_t* ASSEMBLER_TEST_UNIT_OPTION_CYBOI_MODEL = L"assembler";
static int* ASSEMBLER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The calculator test unit option cyboi model. */
static wchar_t* CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"calculator";
static int* CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The caster test unit option cyboi model. */
static wchar_t* CASTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"caster";
static int* CASTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The communicator test unit option cyboi model. */
static wchar_t* COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"communicator";
static int* COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The comparator test unit option cyboi model. */
static wchar_t* COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"comparator";
static int* COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compound test unit option cyboi model. */
static wchar_t* COMPOUND_TEST_UNIT_OPTION_CYBOI_MODEL = L"compound";
static int* COMPOUND_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The constant test unit option cyboi model. */
static wchar_t* CONSTANT_TEST_UNIT_OPTION_CYBOI_MODEL = L"constant";
static int* CONSTANT_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The converter test unit option cyboi model. */
static wchar_t* CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"converter";
static int* CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copier test unit option cyboi model. */
static wchar_t* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"copier";
static int* COPIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display test unit option cyboi model. */
static wchar_t* DISPLAY_TEST_UNIT_OPTION_CYBOI_MODEL = L"display";
static int* DISPLAY_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The example test unit option cyboi model. */
static wchar_t* EXAMPLE_TEST_UNIT_OPTION_CYBOI_MODEL = L"example";
static int* EXAMPLE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The finder test unit option cyboi model. */
static wchar_t* FINDER_TEST_UNIT_OPTION_CYBOI_MODEL = L"finder";
static int* FINDER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The logger test unit option cyboi model. */
static wchar_t* LOGGER_TEST_UNIT_OPTION_CYBOI_MODEL = L"logger";
static int* LOGGER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The memoriser test unit option cyboi model. */
static wchar_t* MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL = L"memoriser";
static int* MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The modifier test unit option cyboi model. */
static wchar_t* MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL = L"modifier";
static int* MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pointer test unit option cyboi model. */
static wchar_t* POINTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"pointer";
static int* POINTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preprocessor test unit option cyboi model. */
static wchar_t* PREPROCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL = L"preprocessor";
static int* PREPROCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referencer test unit option cyboi model. */
static wchar_t* REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL = L"referencer";
static int* REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The representer test unit option cyboi model. */
static wchar_t* REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL = L"representer";
static int* REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The serial_port test unit option cyboi model. */
static wchar_t* SERIAL_PORT_TEST_UNIT_OPTION_CYBOI_MODEL = L"serial_port";
static int* SERIAL_PORT_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The variable test unit option cyboi model. */
static wchar_t* VARIABLE_TEST_UNIT_OPTION_CYBOI_MODEL = L"variable";
static int* VARIABLE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEST_UNIT_OPTION_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
