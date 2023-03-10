/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Franziska Wehner>
 */

#ifndef APPLICATION_VND_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define APPLICATION_VND_STATE_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// Application (vendor-specific)
//
// IANA media type: application/vnd.
//

/**
 * The application/vnd.mozilla.xul+xml state cybol format.
 *
 * Mozilla XUL files
 */
static wchar_t* VND_MOZILLA_XUL_XML_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.mozilla.xul+xml";
static int* VND_MOZILLA_XUL_XML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.ms-excel state cybol format.
 *
 * Microsoft Excel files.
 * Common file suffixes: xls, xla
 */
static wchar_t* VND_MS_EXCEL_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.ms-excel";
static int* VND_MS_EXCEL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.ms-powerpoint state cybol format.
 *
 * Microsoft Powerpoint files
 */
static wchar_t* VND_MS_POWERPOINT_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.ms-powerpoint";
static int* VND_MS_POWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.msword state cybol format.
 *
 * Microsoft Word files
 */
static wchar_t* VND_MSWORD_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.msword";
static int* VND_MSWORD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* APPLICATION_VND_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
