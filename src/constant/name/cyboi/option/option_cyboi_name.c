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

#ifndef OPTION_CYBOI_NAME_CONSTANT_SOURCE
#define OPTION_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The "--help" option cyboi name. */
static wchar_t HELP_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L'h', L'e', L'l', L'p'};
static wchar_t* HELP_OPTION_CYBOI_NAME = HELP_OPTION_CYBOI_NAME_ARRAY;
static int* HELP_OPTION_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--knowledge" option cyboi name. */
static wchar_t KNOWLEDGE_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* KNOWLEDGE_OPTION_CYBOI_NAME = KNOWLEDGE_OPTION_CYBOI_NAME_ARRAY;
static int* KNOWLEDGE_OPTION_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--logfile" option cyboi name. */
static wchar_t LOG_FILE_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'f', L'i', L'l', L'e'};
static wchar_t* LOG_FILE_OPTION_CYBOI_NAME = LOG_FILE_OPTION_CYBOI_NAME_ARRAY;
static int* LOG_FILE_OPTION_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--loglevel" option cyboi name. */
static wchar_t LOG_LEVEL_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'l', L'e', L'v', L'e', L'l'};
static wchar_t* LOG_LEVEL_OPTION_CYBOI_NAME = LOG_LEVEL_OPTION_CYBOI_NAME_ARRAY;
static int* LOG_LEVEL_OPTION_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--test" option cyboi name. */
static wchar_t TEST_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L't', L'e', L's', L't'};
static wchar_t* TEST_OPTION_CYBOI_NAME = TEST_OPTION_CYBOI_NAME_ARRAY;
static int* TEST_OPTION_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--version" option cyboi name. */
static wchar_t VERSION_OPTION_CYBOI_NAME_ARRAY[] = {L'-', L'-', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* VERSION_OPTION_CYBOI_NAME = VERSION_OPTION_CYBOI_NAME_ARRAY;
static int* VERSION_OPTION_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* OPTION_CYBOI_NAME_CONSTANT_SOURCE */
#endif
