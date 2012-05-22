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

#ifndef MODEL_DIAGRAM_TYPE_SOURCE
#define MODEL_DIAGRAM_TYPE_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// element
//

/** The part model diagram type. */
static wchar_t PART_MODEL_DIAGRAM_TYPE_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PART_MODEL_DIAGRAM_TYPE = PART_MODEL_DIAGRAM_TYPE_ARRAY;
static int* PART_MODEL_DIAGRAM_TYPE_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// pointer
//

/** The pointer model diagram type. */
static wchar_t POINTER_MODEL_DIAGRAM_TYPE_ARRAY[] = {L'p', L'o', L'i', L'n', L't', L'e', L'r'};
static wchar_t* POINTER_MODEL_DIAGRAM_TYPE = POINTER_MODEL_DIAGRAM_TYPE_ARRAY;
static int* POINTER_MODEL_DIAGRAM_TYPE_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODEL_DIAGRAM_TYPE_SOURCE */
#endif
