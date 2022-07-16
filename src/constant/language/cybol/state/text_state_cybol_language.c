/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Text (human-readable text and source code)
//
// IANA media type: text
//

/**
 * The text/authority state cybol language.
 *
 * CYBOL (XML)
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE = L"text/authority";
static int* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/bdt state cybol language.
 *
 * Behandlungsdaten-Transfer (BDT)
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: bdt
 */
static wchar_t* BDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/bdt";
static int* BDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/css state cybol language.
 *
 * Cascading Style Sheets (CSS)
 * Specification: RFC 2318
 * Suffixes: css
 */
static wchar_t* CSS_TEXT_STATE_CYBOL_LANGUAGE = L"text/css";
static int* CSS_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol state cybol language.
 *
 * CYBOL (XML)
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 * Suffixes: cybol
 */
static wchar_t* CYBOL_TEXT_STATE_CYBOL_LANGUAGE = L"text/cybol";
static int* CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/gdt state cybol language.
 *
 * Gerätedaten-Transfer (GDT)
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: gdt
 */
static wchar_t* GDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/gdt";
static int* GDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/html state cybol language.
 *
 * Hypertext Markup Language (HTML)
 * Specification: RFC 2854
 * Suffixes: html, htm, shtml
 */
static wchar_t* HTML_TEXT_STATE_CYBOL_LANGUAGE = L"text/html";
static int* HTML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/hxp state cybol language.
 *
 * Healthcare Exchange Protocol (HXP)
 * An XML-based standard for medical data exchange.
 *
 * Specification: Defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t* HXP_TEXT_STATE_CYBOL_LANGUAGE = L"text/hxp";
static int* HXP_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/ldt state cybol language.
 *
 * Labordaten-Transfer (LDT)
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: ldt
 */
static wchar_t* LDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/ldt";
static int* LDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/model-diagram state cybol language.
 *
 * CYBOL (XML)
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE = L"text/model-diagram";
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/uri state cybol language.
 *
 * CYBOL (XML)
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* URI_TEXT_STATE_CYBOL_LANGUAGE = L"text/uri";
static int* URI_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xdt-field-description state cybol language.
 */
static wchar_t* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE = L"text/xdt-field-description";
static int* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
