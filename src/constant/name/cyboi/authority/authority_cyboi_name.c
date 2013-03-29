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

#ifndef AUTHORITY_CYBOI_NAME_CONSTANT_SOURCE
#define AUTHORITY_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - URI parts do not have a name at all, so that CYBOI has to invent some
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The username authority cyboi name. */
static wchar_t USERNAME_AUTHORITY_CYBOI_NAME_ARRAY[] = {L'u', L's', L'e', L'r', L'n', L'a', L'm', L'e'};
static wchar_t* USERNAME_AUTHORITY_CYBOI_NAME = USERNAME_AUTHORITY_CYBOI_NAME_ARRAY;
static int* USERNAME_AUTHORITY_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The password authority cyboi name. */
static wchar_t PASSWORD_AUTHORITY_CYBOI_NAME_ARRAY[] = {L'p', L'a', L's', L's', L'w', L'o', L'r', L'd'};
static wchar_t* PASSWORD_AUTHORITY_CYBOI_NAME = PASSWORD_AUTHORITY_CYBOI_NAME_ARRAY;
static int* PASSWORD_AUTHORITY_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hostname authority cyboi name. */
static wchar_t HOSTNAME_AUTHORITY_CYBOI_NAME_ARRAY[] = {L'h', L'o', L's', L't', L'n', L'a', L'm', L'e'};
static wchar_t* HOSTNAME_AUTHORITY_CYBOI_NAME = HOSTNAME_AUTHORITY_CYBOI_NAME_ARRAY;
static int* HOSTNAME_AUTHORITY_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port authority cyboi name. */
static wchar_t PORT_AUTHORITY_CYBOI_NAME_ARRAY[] = {L'p', L'o', L'r', L't'};
static wchar_t* PORT_AUTHORITY_CYBOI_NAME = PORT_AUTHORITY_CYBOI_NAME_ARRAY;
static int* PORT_AUTHORITY_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* AUTHORITY_CYBOI_NAME_CONSTANT_SOURCE */
#endif
