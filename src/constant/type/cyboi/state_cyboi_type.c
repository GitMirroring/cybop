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

#ifndef STATE_CYBOI_TYPE_CONSTANT_HEADER
#define STATE_CYBOI_TYPE_CONSTANT_HEADER

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// datetime
//

/** The datetime state cyboi type. */
static int* DATETIME_STATE_CYBOI_TYPE = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// duration
//

/** The duration state cyboi type. */
static int* DURATION_STATE_CYBOI_TYPE = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/**
 * The part element state cyboi type.
 *
 * CAUTION! The part constant HAS TO BE defined as primitive type here,
 * in order to be able to distinguish cyboi runtime parts from other pointers.
 */
static int* PART_ELEMENT_STATE_CYBOI_TYPE = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi type. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/**
 * The byte number state cyboi type.
 *
 * CAUTION! This type internally uses the same size as "unsigned char".
 * However, it IS NECESSARY to distinguish between the two,
 * in order to interpret characters as numbers and NOT ascii codes.
 */
static int* BYTE_NUMBER_STATE_CYBOI_TYPE = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex number state cyboi type. */
static int* COMPLEX_NUMBER_STATE_CYBOI_TYPE = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The float number state cyboi type. */
static int* FLOAT_NUMBER_STATE_CYBOI_TYPE = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction number state cyboi type. */
static int* FRACTION_NUMBER_STATE_CYBOI_TYPE = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi type. */
static int* INTEGER_NUMBER_STATE_CYBOI_TYPE = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long long integer number state cyboi type.
 *
 * CAUTION! It IS NECESSARY e.g. when receiving a datetime
 * via the glibc function "time".
 */
static int* LONG_LONG_INTEGER_NUMBER_STATE_CYBOI_TYPE = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// pointer
//

/** The pointer state cyboi type. */
static int* POINTER_STATE_CYBOI_TYPE = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// signal
//

/** The atomic signal state cyboi type. */
static int* ATOMIC_SIGNAL_STATE_CYBOI_TYPE = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// socket address
//

/** The ipv4 socket address state cyboi type. */
static int* IPV4_SOCKET_ADDRESS_STATE_CYBOI_TYPE = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ipv6 socket address state cyboi type. */
static int* IPV6_SOCKET_ADDRESS_STATE_CYBOI_TYPE = NUMBER_61_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The local socket address state cyboi type. */
static int* LOCAL_SOCKET_ADDRESS_STATE_CYBOI_TYPE = NUMBER_62_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// terminal mode
//

/** The unix terminal mode state cyboi type. */
static int* UNIX_TERMINAL_MODE_STATE_CYBOI_TYPE = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The win32 console mode state cyboi type. */
static int* WIN32_CONSOLE_MODE_STATE_CYBOI_TYPE = NUMBER_71_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The character text state cyboi type. */
static int* CHARACTER_TEXT_STATE_CYBOI_TYPE = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The wide character text state cyboi type. */
static int* WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE = NUMBER_81_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// thread
//

/** The identification thread state cyboi type. */
static int* IDENTIFICATION_THREAD_STATE_CYBOI_TYPE = NUMBER_90_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mutex thread state cyboi type. */
static int* MUTEX_THREAD_STATE_CYBOI_TYPE = NUMBER_92_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_TYPE_CONSTANT_HEADER */
#endif
