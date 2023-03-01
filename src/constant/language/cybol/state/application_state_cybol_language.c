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
 */

#ifndef APPLICATION_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define APPLICATION_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Application
//
// IANA media type: application
//

/**
 * The application/json application state cybol language.
 *
 * Java Script Object Notation (JSON)
 *
 * Specification: RFC 8259, ECMA-404
 * https://www.json.org/
 * Suffixes: json
 *
 * CAUTION! Do NOT use "text/json", since the standard
 * recommends "application/json".
 */
static wchar_t* JSON_APPLICATION_STATE_CYBOL_LANGUAGE = L"application/json";
static int* JSON_APPLICATION_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xml application state cybol language.
 *
 * Extensible Markup Language (XML)
 *
 * Specification: RFC 3023
 * Suffixes: xml
 *
 * The standard defines TWO possible mime types:
 * application/xml is RECOMMENDED as of RFC 7303
 * text/xml is still used sometimes
 */
static wchar_t* XML_APPLICATION_STATE_CYBOL_LANGUAGE = L"application/xml";
static int* XML_APPLICATION_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* APPLICATION_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
