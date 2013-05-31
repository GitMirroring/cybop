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

#ifndef ARCHIVE_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define ARCHIVE_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The bzip2 archive file logic cybol name. */
static wchar_t BZIP2_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'b', L'z', L'i', L'p', L'2'};
static wchar_t* BZIP2_ARCHIVE_FILE_LOGIC_CYBOL_NAME = BZIP2_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* BZIP2_ARCHIVE_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create archive file logic cybol name. */
static wchar_t CREATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* CREATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME = CREATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* CREATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The update archive file logic cybol name. */
static wchar_t UPDATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'u', L'p', L'd', L'a', L't', L'e'};
static wchar_t* UPDATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME = UPDATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* UPDATE_ARCHIVE_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ARCHIVE_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
