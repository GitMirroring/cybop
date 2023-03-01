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

#ifndef SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The path parameter for the spellcheck logic in cybol. */
static wchar_t* PATH_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mode parameter for the spellcheck logic in cybol. */
static wchar_t* MODE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"mode";
static int* MODE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The suggestion mode parameter for the spellcheck logic in cybol. */
static wchar_t* SUG_MODE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"sug-mode";
static int* SUG_MODE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language parameter for the spellcheck logic in cybol. */
static wchar_t* LANGUAGE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"language";
static int* LANGUAGE_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding parameter for the spellcheck logic in cybol. */
static wchar_t* ENCODING_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"encoding";
static int* ENCODING_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The master parameter for the spellcheck logic in cybol. */
static wchar_t* MASTER_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"master";
static int* MASTER_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The keymapping parameter for the spellcheck logic in cybol. */
static wchar_t* KEYMAPPING_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"language";
static int* KEYMAPPING_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dont backup option for the spellcheck logic in cybol. */
static wchar_t* DONT_BACKUP_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME = L"dont-backup";
static int* DONT_BACKUP_SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SPELLCHECK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
