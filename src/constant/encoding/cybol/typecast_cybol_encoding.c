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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TYPECAST_CYBOL_ENCODING_CONSTANT_SOURCE
#define TYPECAST_CYBOL_ENCODING_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The constants in this file do NOT represent character set encodings.
// Instead, the are used for typecasting.
//

/*
 * The typecast-integer cybol encoding.
 *
 * It is used for decoding char into int
 * and encoding int into char.
 */
static wchar_t INTEGER_TYPECAST_CYBOL_ENCODING_ARRAY[] = {L't', L'y', L'p', L'e', L'c', L'a', L's', L't', L'-', L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* INTEGER_TYPECAST_CYBOL_ENCODING = INTEGER_TYPECAST_CYBOL_ENCODING_ARRAY;
static int* INTEGER_TYPECAST_CYBOL_ENCODING_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TYPECAST_CYBOL_ENCODING_CONSTANT_SOURCE */
#endif
