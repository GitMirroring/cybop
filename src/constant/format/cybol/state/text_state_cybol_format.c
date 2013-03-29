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

#ifndef TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The CYBOL type constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

//
// Text (human-readable text and source code).
//
// IANA media type: text
//

/**
 * The text/ascii state cybol type.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 *
 * It is used for single-byte-characters in CYBOL.
 */
static wchar_t ASCII_TEXT_STATE_CYBOL_FORMAT_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'a', L's', L'c', L'i', L'i'};
static wchar_t* ASCII_TEXT_STATE_CYBOL_FORMAT = ASCII_TEXT_STATE_CYBOL_FORMAT_ARRAY;
static int* ASCII_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/plain state cybol type.
 *
 * Textual data.
 * Defined in RFC 2046 and RFC 3676.
 * Suffixes: txt
 *
 * This language (media type) is also used for strings (character vectors) in CYBOL.
 */
static wchar_t PLAIN_TEXT_STATE_CYBOL_FORMAT_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* PLAIN_TEXT_STATE_CYBOL_FORMAT = PLAIN_TEXT_STATE_CYBOL_FORMAT_ARRAY;
static int* PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
