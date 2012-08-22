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

#ifndef PATH_STATE_CYBOL_FORMAT_CONSTANTS_SOURCE
#define PATH_STATE_CYBOL_FORMAT_CONSTANTS_SOURCE

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
// Path (parts in a knowledge tree accessed at runtime).
//
// IANA media type: not defined
// Self-defined media type: path
// This media type is a CYBOL extension.
//

/**
 * The path/reference state cybol type.
 *
 * A knowledge path pointing to an item of a knowledge tree,
 * that contains a knowledge path.
 * In other words, the item pointed to just "wraps" or "encapsulates"
 * a knowledge path which in turn points to the actual item.
 *
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 *
 * The same rules as for the "path/knowledge" language apply here.
 */
static wchar_t REFERENCE_PATH_STATE_CYBOL_FORMAT_ARRAY[] = {L'p', L'a', L't', L'h', L'/', L'r', L'e', L'f', L'e', L'r', L'e', L'n', L'c', L'e'};
static wchar_t* REFERENCE_PATH_STATE_CYBOL_FORMAT = REFERENCE_PATH_STATE_CYBOL_FORMAT_ARRAY;
static int* REFERENCE_PATH_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The path/knowledge state cybol type.
 *
 * A knowledge path pointing to an item of a knowledge tree, whereby:
 * - "part" tree node names are dot (.) separated
 * - "meta" tree node names are number sign (#) separated
 *
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 *
 * Example:
 * .application.gui.menu_bar.file_menu#background_colour
 * points to the meta property "background colour" of the
 * knowledge tree item ".application.gui.menu_bar.file_menu"
 */
static wchar_t KNOWLEDGE_PATH_STATE_CYBOL_FORMAT_ARRAY[] = {L'p', L'a', L't', L'h', L'/', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* KNOWLEDGE_PATH_STATE_CYBOL_FORMAT = KNOWLEDGE_PATH_STATE_CYBOL_FORMAT_ARRAY;
static int* KNOWLEDGE_PATH_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PATH_STATE_CYBOL_FORMAT_CONSTANTS_SOURCE */
#endif
