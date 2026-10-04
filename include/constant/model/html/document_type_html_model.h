/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DOCUMENT_TYPE_HTML_MODEL_CONSTANT_HEADER
#define DOCUMENT_TYPE_HTML_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The html document type html model.
 *
 * <!DOCTYPE html>
 *
 * It was introduced with the html5 specification:
 * http://www.w3.org/TR/html-markup/
 */
static wchar_t* HTML_DOCUMENT_TYPE_HTML_MODEL = L"DOCTYPE";
static int* HTML_DOCUMENT_TYPE_HTML_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? TODO: Possibly add the old html document types (very long lines) here, used up to version HTML 4

/* DOCUMENT_TYPE_HTML_MODEL_CONSTANT_HEADER */
#endif
