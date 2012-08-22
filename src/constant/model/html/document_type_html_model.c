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

#ifndef DOCUMENT_TYPE_HTML_MODEL_CONSTANT_SOURCE
#define DOCUMENT_TYPE_HTML_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The html document type html model.
 *
 * <!DOCTYPE html>
 *
 * It was introduced with the html5 specification:
 * http://www.w3.org/TR/html-markup/
 */
static wchar_t HTML_DOCUMENT_TYPE_HTML_MODEL_ARRAY[] = {L'<', L'!', L'D', L'O', L'C', L'T', L'Y', L'P', L'E', L' ', L'h', L't', L'm', L'l', L'>'};
static wchar_t* HTML_DOCUMENT_TYPE_HTML_MODEL = HTML_DOCUMENT_TYPE_HTML_MODEL_ARRAY;
static int* HTML_DOCUMENT_TYPE_HTML_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DOCUMENT_TYPE_HTML_MODEL_CONSTANT_SOURCE */
#endif
