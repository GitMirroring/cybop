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

#ifndef WIN32_COMMAND_MODEL_CONSTANT_SOURCE
#define WIN32_COMMAND_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The copy win32 command model. */
static wchar_t XCOPY_WIN32_COMMAND_MODEL_ARRAY[] = {L'x', L'c', L'o', L'p', L'y'};
static wchar_t* XCOPY_WIN32_COMMAND_MODEL = XCOPY_WIN32_COMMAND_MODEL_ARRAY;
static int* XCOPY_WIN32_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/** The move win32 command model. */
static wchar_t MOVE_WIN32_COMMAND_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_WIN32_COMMAND_MODEL = MOVE_WIN32_COMMAND_MODEL_ARRAY;
static int* MOVE_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver win32 command model. */
static wchar_t SEVEN_ZIP_WIN32_COMMAND_MODEL_ARRAY[] = {L'7', L'z', L'.', L'e', L'x', L'e'};
static wchar_t* SEVEN_ZIP_WIN32_COMMAND_MODEL = SEVEN_ZIP_WIN32_COMMAND_MODEL_ARRAY;
static int* SEVEN_ZIP_WIN32_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WIN32_COMMAND_MODEL_CONSTANT_SOURCE */
#endif
