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

#ifndef STATE_CYBOI_LANGUAGE_CONSTANT_SOURCE
#define STATE_CYBOI_LANGUAGE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// CAUTION! However, STATE and LOGIC constants have been split into TWO files.
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..499
// - logic constants: 500..999
//

//
// interface
//

/** The graphical interface state cyboi language. */
static int* GRAPHICAL_INTERFACE_STATE_CYBOI_LANGUAGE = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-winamp-skin interface state cyboi language. */
static int* X_WINAMP_SKIN_INTERFACE_STATE_CYBOI_LANGUAGE = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// message
//

/** The ansi escape code message state cyboi language. */
static int* ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http message state cyboi language. */
static int* HTTP_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-request message state cyboi language. */
static int* HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-response message state cyboi language. */
static int* HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The news message state cyboi language. */
static int* NEWS_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The authority text state cyboi language. */
static int* AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The css text state cyboi language. */
static int* CSS_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol text state cyboi language. */
static int* CYBOL_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The html text state cyboi language. */
static int* HTML_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hxp text state cyboi language. */
static int* HXP_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model-diagram text state cyboi language. */
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uri text state cyboi language. */
static int* URI_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt text state cyboi language. */
static int* XDT_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_207_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml text state cyboi language. */
static int* XML_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_208_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_LANGUAGE_CONSTANT_SOURCE */
#endif
