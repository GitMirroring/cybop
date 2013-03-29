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

#ifndef LIST_FILE_OPERATION_CYBOL_NAME_CONSTANT_SOURCE
#define LIST_FILE_OPERATION_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The all list directory contents file operation cybol name.
 *
 * It indicates that hidden files should be listed
 * as well as the current . and upper .. directory.
 */
static wchar_t ALL_LIST_FILE_OPERATION_CYBOL_NAME_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* ALL_LIST_FILE_OPERATION_CYBOL_NAME = ALL_LIST_FILE_OPERATION_CYBOL_NAME_ARRAY;
static int* ALL_LIST_FILE_OPERATION_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long list directory contents file operation cybol name.
 *
 * It indicates the usage of a long listing including file access rights etc.
 */
static wchar_t LONG_LIST_FILE_OPERATION_CYBOL_NAME_ARRAY[] = {L'l', L'o', L'n', L'g'};
static wchar_t* LONG_LIST_FILE_OPERATION_CYBOL_NAME = LONG_LIST_FILE_OPERATION_CYBOL_NAME_ARRAY;
static int* LONG_LIST_FILE_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_FILE_OPERATION_CYBOL_NAME_CONSTANT_SOURCE */
#endif
