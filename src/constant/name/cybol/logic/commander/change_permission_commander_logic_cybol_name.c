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

#ifndef CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The path for the change permission file logic cybol name.
 *
 * It indicates the path of a directory or file for change permission
 */
static wchar_t* PATH_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The recursive change permission file logic cybol name.
 *
 * It indicates that the permissions are recursively applied to folders and files
 */
static wchar_t* RECURSIVE_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"recursive";
static int* RECURSIVE_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The silent change permission file logic cybol name.
 *
 * It indicates that the most error messages will suppressed
 */
static wchar_t* SILENT_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"silent";
static int* SILENT_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The verbose change permission file logic cybol name.
 *
 * It output a diagnostic for every file processed
 */
static wchar_t* VERBOSE_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"verbose";
static int* VERBOSE_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The user change permission file logic cybol name.
 *
 * It indicates the user permissions, for example 'rwx'
 */
static wchar_t* USER_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"user";
static int* USER_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The group change permission file logic cybol name.
 *
 * It indicates the group permissions, for example 'rwx'
 */
static wchar_t* GROUP_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"group";
static int* GROUP_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The other change permission file logic cybol name.
 *
 * It indicates the other permissions, for example 'rwx'
 */
static wchar_t* OTHER_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"other";
static int* OTHER_CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHANGE_PERMISSION_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
