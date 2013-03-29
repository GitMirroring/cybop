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

#ifndef DOS_CYBOL_ENCODING_CONSTANT_SOURCE
#define DOS_CYBOL_ENCODING_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character encoding constants.
//

/*
 * The dos-850 cybol encoding.
 *
 * Disk Operating System (DOS) Code page 850.
 */
static wchar_t DOS_850_CYBOL_ENCODING_ARRAY[] = {L'd', L'o', L's', L'-', L'8', L'5', L'0'};
static wchar_t* DOS_850_CYBOL_ENCODING = DOS_850_CYBOL_ENCODING_ARRAY;
static int* DOS_850_CYBOL_ENCODING_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DOS_CYBOL_ENCODING_CONSTANT_SOURCE */
#endif
