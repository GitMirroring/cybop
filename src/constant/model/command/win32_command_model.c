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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_COMMAND_MODEL_CONSTANT_SOURCE
#define WIN32_COMMAND_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The copy win32 command model. */
static wchar_t COPY_WIN32_COMMAND_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_WIN32_COMMAND_MODEL = COPY_WIN32_COMMAND_MODEL_ARRAY;
static int* COPY_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The delete win32 command model. */
static wchar_t DEL_WIN32_COMMAND_MODEL_ARRAY[] = {L'd', L'e', L'l'};
static wchar_t* DEL_WIN32_COMMAND_MODEL = DEL_WIN32_COMMAND_MODEL_ARRAY;
static int* DEL_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents win32 command model. */
static wchar_t DIR_WIN32_COMMAND_MODEL_ARRAY[] = {L'd', L'i', L'r'};
static wchar_t* DIR_WIN32_COMMAND_MODEL = DIR_WIN32_COMMAND_MODEL_ARRAY;
static int* DIR_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo win32 command model. */
static wchar_t ECHO_WIN32_COMMAND_MODEL_ARRAY[] = {L'e', L'c', L'h', L'o'};
static wchar_t* ECHO_WIN32_COMMAND_MODEL = ECHO_WIN32_COMMAND_MODEL_ARRAY;
static int* ECHO_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WIN32_COMMAND_MODEL_CONSTANT_SOURCE */
#endif
