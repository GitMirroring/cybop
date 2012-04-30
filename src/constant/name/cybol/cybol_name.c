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

#ifndef CYBOL_NAME_CONSTANT_SOURCE
#define CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The name cybol name. */
static wchar_t NAME_CYBOL_NAME_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* NAME_CYBOL_NAME = NAME_CYBOL_NAME_ARRAY;
static int* NAME_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The channel cybol name. */
static wchar_t CHANNEL_CYBOL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_CYBOL_NAME = CHANNEL_CYBOL_NAME_ARRAY;
static int* CHANNEL_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding cybol name. */
static wchar_t ENCODING_CYBOL_NAME_ARRAY[] = {L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* ENCODING_CYBOL_NAME = ENCODING_CYBOL_NAME_ARRAY;
static int* ENCODING_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language cybol name. */
static wchar_t LANGUAGE_CYBOL_NAME_ARRAY[] = {L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* LANGUAGE_CYBOL_NAME = LANGUAGE_CYBOL_NAME_ARRAY;
static int* LANGUAGE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format cybol name. */
static wchar_t FORMAT_CYBOL_NAME_ARRAY[] = {L'f', L'o', L'r', L'm', L'a', L't'};
static wchar_t* FORMAT_CYBOL_NAME = FORMAT_CYBOL_NAME_ARRAY;
static int* FORMAT_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model cybol name. */
static wchar_t MODEL_CYBOL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_CYBOL_NAME = MODEL_CYBOL_NAME_ARRAY;
static int* MODEL_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOL_NAME_CONSTANT_SOURCE */
#endif
