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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROTOCOL_VERSION_HTTP_MODEL_CONSTANT_SOURCE
#define PROTOCOL_VERSION_HTTP_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The 1.0 protocol version http model. */
static unsigned char NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_ARRAY[] = {'H', 'T', 'T', 'P', '/', '1', '.', '0'};
static unsigned char* NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL = NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_ARRAY;
static int* NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 1.1 protocol version http model. */
static unsigned char NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_ARRAY[] = {'H', 'T', 'T', 'P', '/', '1', '.', '1'};
static unsigned char* NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL = NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_ARRAY;
static int* NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PROTOCOL_VERSION_HTTP_MODEL_CONSTANT_SOURCE */
#endif
