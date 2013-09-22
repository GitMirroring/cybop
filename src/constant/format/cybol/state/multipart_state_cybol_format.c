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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Multipart (archives and other objects made of more than one part).
//
// IANA media type: multipart
//

/**
 * The multipart/mixed state cybol type.
 *
 * multipart/mixed: MIME E-mail; Defined in RFC 2045 and RFC 2046
 */
static wchar_t MIXED_MULTIPART_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'a', L'r', L't', L'/', L'm', L'i', L'x', L'e', L'd'};
static wchar_t* MIXED_MULTIPART_STATE_CYBOL_FORMAT = MIXED_MULTIPART_STATE_CYBOL_FORMAT_ARRAY;
static int* MIXED_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*??
multipart/alternative: MIME E-mail; Defined in RFC 2045 and RFC 2046
multipart/related: MIME E-mail; Defined in RFC 2387 and used by MHTML (HTML mail)
multipart/form-data: MIME Webform; Defined in RFC 2388
*/

/* MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
