/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_CHANNEL_CONSTANT_SOURCE
#define CYBOI_CHANNEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The cyboi cyboi channel. */
static int* CYBOI_CYBOI_CHANNEL = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file system cyboi channel. */
static int* FILE_SYSTEM_CYBOI_CHANNEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inline cyboi channel. */
static int* INLINE_CYBOI_CHANNEL = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shell cyboi channel. */
static int* SHELL_CYBOI_CHANNEL = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The signal cyboi channel. */
static int* SIGNAL_CYBOI_CHANNEL = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The socket cyboi channel. */
static int* SOCKET_CYBOI_CHANNEL = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal cyboi channel. */
static int* TERMINAL_CYBOI_CHANNEL = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The world wide web (www) cyboi channel. */
static int* WWW_CYBOI_CHANNEL = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x window system cyboi channel. */
static int* X_WINDOW_SYSTEM_CYBOI_CHANNEL = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOI_CHANNEL_CONSTANT_SOURCE */
#endif
