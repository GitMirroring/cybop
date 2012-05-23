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

#ifndef FILE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define FILE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// File (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: file
// This media type is a CYBOL extension.
//

/**
 * The file/archive logic cybol format.
 *
 * Archive the given files into a packed format.
 *
 * This is a CYBOL extension.
 */
static wchar_t ARCHIVE_FILE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'f', L'i', L'l', L'e', L'/', L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* ARCHIVE_FILE_LOGIC_CYBOL_FORMAT = ARCHIVE_FILE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* ARCHIVE_FILE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The file/copy logic cybol format.
 *
 * Copy the given file into another.
 *
 * This is a CYBOL extension.
 */
static wchar_t COPY_FILE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'f', L'i', L'l', L'e', L'/', L'c', L'o', L'p', L'y'};
static wchar_t* COPY_FILE_LOGIC_CYBOL_FORMAT = COPY_FILE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* COPY_FILE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The file/list-directory-contents logic cybol format.
 *
 * List contents of the given directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'f', L'i', L'l', L'e', L'/', L'l', L'i', L's', L't', L'-', L'd', L'i', L'r', L'e', L'c', L't', L'o', L'r', L'y', L'-', L'c', L'o', L'n', L't', L'e', L'n', L't', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_FORMAT = LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FILE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
