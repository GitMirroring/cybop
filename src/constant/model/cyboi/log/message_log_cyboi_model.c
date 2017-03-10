/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_LOG_CYBOI_MODEL_CONSTANT_SOURCE
#define MESSAGE_LOG_CYBOI_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Array log messages.
//

/** The "Could not create array. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not create array. The type is null.";
static int* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not destroy array. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not destroy array. The type is null.";
static int* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not resize array. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not resize array. The type is null.";
static int* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not compare array elements. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not compare array elements. The type is null.";
static int* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not set array elements. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not set array elements. The type is null.";
static int* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_47_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not remove array elements. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not remove array elements. The type is null";
static int* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not get array elements. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not get array elements. The type is null.";
static int* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_47_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not get array elements index. The type is null." message log cyboi model. */
static wchar_t* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not get array elements index. The type is null.";
static int* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Operation log messages.
//

/** The "Create operation." message log cyboi model. */
static wchar_t* CREATE_OPERATION_MESSAGE_LOG_CYBOI_MODEL = L"Create operation.";
static int* CREATE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Destroy operation." message log cyboi model. */
static wchar_t* DESTROY_OPERATION_MESSAGE_LOG_CYBOI_MODEL = L"Destroy operation.";
static int* DESTROY_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Initialise operation." message log cyboi model. */
static wchar_t* INITIALIZE_OPERATION_MESSAGE_LOG_CYBOI_MODEL = L"Initialise operation.";
static int* INITIALIZE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Finalise operation." message log cyboi model. */
static wchar_t* FINALIZE_OPERATION_MESSAGE_LOG_CYBOI_MODEL = L"Finalise operation.";
static int* FINALIZE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Signal memory log messages.
//

/** The "Create signal memory." message log cyboi model. */
static wchar_t* CREATE_SIGNAL_MEMORY_MESSAGE_LOG_CYBOI_MODEL = L"Create signal memory.";
static int* CREATE_SIGNAL_MEMORY_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Destroy signal memory." message log cyboi model. */
static wchar_t* DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_CYBOI_MODEL = L"Destroy signal memory.";
static int* DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Handle part." message log cyboi model. */
static wchar_t* HANDLE_PART_MESSAGE_LOG_CYBOI_MODEL = L"Handle part.";
static int* HANDLE_PART_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Handle operation." message log cyboi model. */
static wchar_t* HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL = L"Handle operation.";
static int* HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Set shutdown flag." message log cyboi model. */
static wchar_t* SET_SHUTDOWN_FLAG_MESSAGE_LOG_CYBOI_MODEL = L"Set shutdown flag.";
static int* SET_SHUTDOWN_FLAG_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Cyboi log messages.
//

/** The "Check for signals." message log cyboi model. */
static wchar_t* CHECK_FOR_SIGNALS_MESSAGE_LOG_CYBOI_MODEL = L"Check for signals.";
static int* CHECK_FOR_SIGNALS_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not handle signal. The signal type is unknown." message log cyboi model. */
static wchar_t* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_TYPE_IS_UNKNOWN_MESSAGE_LOG_CYBOI_MODEL = L"Could not handle signal. The signal type is unknown.";
static int* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_TYPE_IS_UNKNOWN_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_59_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not check for signals. The internal is null." message log cyboi model. */
static wchar_t* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not check for signals. The internal is null.";
static int* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Exit CYBOI normally." message log cyboi model. */
static wchar_t* EXIT_CYBOI_NORMALLY_MESSAGE_LOG_CYBOI_MODEL = L"Exit CYBOI normally.";
static int* EXIT_CYBOI_NORMALLY_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "Could not execute CYBOI. The command line argument vector is null." message log cyboi model. */
static wchar_t* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_CYBOI_MODEL = L"Could not execute CYBOI. The command line argument vector is null.";
static int* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_CYBOI_MODEL_COUNT = NUMBER_66_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MESSAGE_LOG_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
