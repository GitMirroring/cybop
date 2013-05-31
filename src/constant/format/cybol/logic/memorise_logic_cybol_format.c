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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Memorise (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: memorise
// This media type is a CYBOL extension.
//

/**
 * The memorise/create logic cybol format.
 *
 * Create / allocate / reserve memory for data of the given type.
 *
 * This is a CYBOL extension.
 */
static wchar_t CREATE_MEMORISE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L'm', L'o', L'r', L'i', L's', L'e', L'/', L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT = CREATE_MEMORISE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/destroy logic cybol format.
 *
 * Destroy / deallocate / free memory of the given data.
 *
 * This is a CYBOL extension.
 */
static wchar_t DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L'm', L'o', L'r', L'i', L's', L'e', L'/', L'd', L'e', L's', L't', L'r', L'o', L'y'};
static wchar_t* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT = DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
