/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef URI_MIME_TYPE_CONSTANTS_SOURCE
#define URI_MIME_TYPE_CONSTANTS_SOURCE

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// URI (uniform resource identifier)
//
// IANA media type: not defined
// Self-defined media type: uri
// This media type is a CYBOL extension.
//
// This MIME type was taken from/inspired by the KDE desktop.
// It is not sure yet, whether it will be useful in the context of CYBOI.
//

/**
 * The uri/mms state cybol format.
 */
static wchar_t* MMS_URI_STATE_CYBOL_FORMAT = L"uri/mms";
static int* MMS_URI_STATE_CYBOL_FORMAT_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* URI_MIME_TYPE_CONSTANTS_SOURCE */
#endif
