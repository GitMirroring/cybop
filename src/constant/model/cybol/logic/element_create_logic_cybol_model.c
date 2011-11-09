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
 * @version $RCSfile: compound_element_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE
#define ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The part element create logic cybol model. */
static wchar_t PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL = PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_ARRAY;
static int* PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The property element create logic cybol model. */
static wchar_t PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_ARRAY[] = {L'p', L'r', L'o', L'p', L'e', L'r', L't', L'y'};
static wchar_t* PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL = PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_ARRAY;
static int* PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
