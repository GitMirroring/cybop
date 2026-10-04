/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SPELLCHECK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define SPELLCHECK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The mode spellcheck unix command option name. */
static wchar_t* MODE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-mode=";
static int* MODE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The don't backup spellcheck unix command option name. */
static wchar_t* DONT_BACKUP_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"–dont-backup";
static int* DONT_BACKUP_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The suggestion mode spellcheck unix command option name. */
static wchar_t* SUG_MODE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-sug-mode=";
static int* SUG_MODE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language spellcheck unix command option name. */
static wchar_t* LANGUAGE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-lang=";
static int* LANGUAGE_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding spellcheck unix command option name. */
static wchar_t* ENCODING_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-encoding=";
static int* ENCODING_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The master spellcheck unix command option name. */
static wchar_t* MASTER_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-master=";
static int* MASTER_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The keymapping spellcheck unix command option name. */
static wchar_t* KEYMAPPING_SPELLCHECK_UNIX_COMMAND_OPTION_NAME = L"-keymapping=";
static int* KEYMAPPING_SPELLCHECK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SPELLCHECK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
