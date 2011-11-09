/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: cybop_name.c,v $ $Revision: 1.5 $ $Date: 2009-02-10 01:01:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_NAME_CONSTANT_SOURCE
#define CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The name cybol name. */
static wchar_t NAME_CYBOL_NAME_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* NAME_CYBOL_NAME = NAME_CYBOL_NAME_ARRAY;
static int* NAME_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The channel cybol name. */
static wchar_t CHANNEL_CYBOL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_CYBOL_NAME = CHANNEL_CYBOL_NAME_ARRAY;
static int* CHANNEL_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The type cybol name. */
static wchar_t TYPE_CYBOL_NAME_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* TYPE_CYBOL_NAME = TYPE_CYBOL_NAME_ARRAY;
static int* TYPE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The model cybol name. */
static wchar_t MODEL_CYBOL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_CYBOL_NAME = MODEL_CYBOL_NAME_ARRAY;
static int* MODEL_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOL_NAME_CONSTANT_SOURCE */
#endif
