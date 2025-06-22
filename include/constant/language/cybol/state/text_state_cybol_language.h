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

#ifndef TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER
#define TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Text (human-readable text and source code)
//
// IANA media type: text
//

/**
 * The text/authority text state cybol language.
 *
 * CYBOL (XML)
 *
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE = L"text/authority";
static int* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/bdt text state cybol language.
 *
 * Behandlungsdaten-Transfer (BDT)
 *
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 *
 * Suffixes: bdt
 */
static wchar_t* BDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/bdt";
static int* BDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/css text state cybol language.
 *
 * Cascading Style Sheets (CSS)
 *
 * Specification: RFC 2318
 *
 * Suffixes: css
 */
static wchar_t* CSS_TEXT_STATE_CYBOL_LANGUAGE = L"text/css";
static int* CSS_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/csv text state cybol language.
 *
 * Character-separated values (csv)
 *
 * It is also known as comma-separated values, but other
 * characters than comma may be used as separator as well.
 *
 * Registered.
 *
 * Suffixes: csv
 */
static wchar_t* CSV_TEXT_STATE_CYBOL_LANGUAGE = L"text/csv";
static int* CSV_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol+json text state cybol language.
 *
 * CYBOL (JSON)
 *
 * Suffixes: cybolj
 */
static wchar_t* CYBOL_JSON_TEXT_STATE_CYBOL_LANGUAGE = L"text/cybol+json";
static int* CYBOL_JSON_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol text state cybol language.
 *
 * CYBOL (XML)
 *
 * It is identical to "text/cybol+xml" but shorter and easier to use.
 * This is the DEFAULT media type for cybol data.
 *
 * Suffixes: cybol
 */
static wchar_t* CYBOL_TEXT_STATE_CYBOL_LANGUAGE = L"text/cybol";
static int* CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol+xml text state cybol language.
 *
 * CYBOL (XML)
 *
 * Suffixes: cybol
 */
static wchar_t* CYBOL_XML_TEXT_STATE_CYBOL_LANGUAGE = L"text/cybol+xml";
static int* CYBOL_XML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/gdt text state cybol language.
 *
 * Gerätedaten-Transfer (GDT)
 *
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 *
 * Suffixes: gdt
 */
static wchar_t* GDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/gdt";
static int* GDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/html text state cybol language.
 *
 * Hypertext Markup Language (HTML)
 *
 * Specification: RFC 2854
 *
 * Suffixes: html, htm, shtml
 */
static wchar_t* HTML_TEXT_STATE_CYBOL_LANGUAGE = L"text/html";
static int* HTML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/hxp text state cybol language.
 *
 * Healthcare Exchange Protocol (HXP)
 *
 * An XML-based standard for medical data exchange.
 *
 * Specification: Defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 *
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t* HXP_TEXT_STATE_CYBOL_LANGUAGE = L"text/hxp";
static int* HXP_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/joined-string text state cybol language.
 *
 * A text string made up of several elements separated by a delimiter
 * such as a comma or semicolon.
 *
 * This is comparable to the character-separated values (csv),
 * also known as comma-separated values, only that the csv may contain
 * MANY lines, while the joined string contains just ONE line.
 *
 * Suffixes: txt
 */
static wchar_t* JOINED_STRING_TEXT_STATE_CYBOL_LANGUAGE = L"text/joined-string";
static int* JOINED_STRING_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/ldt text state cybol language.
 *
 * Labordaten-Transfer (LDT)
 *
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 *
 * Suffixes: ldt
 */
static wchar_t* LDT_TEXT_STATE_CYBOL_LANGUAGE = L"text/ldt";
static int* LDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/model-diagram text state cybol language.
 *
 * CYBOL (XML)
 *
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE = L"text/model-diagram";
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/textline-list text state cybol language.
 *
 * A text made up of potentially many lines.
 *
 * Suffixes: txt
 */
static wchar_t* TEXTLINE_LIST_TEXT_STATE_CYBOL_LANGUAGE = L"text/textline-list";
static int* TEXTLINE_LIST_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/uri text state cybol language.
 *
 * CYBOL (XML)
 *
 * Specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* URI_TEXT_STATE_CYBOL_LANGUAGE = L"text/uri";
static int* URI_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xdt-field-description text state cybol language.
 */
static wchar_t* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE = L"text/xdt-field-description";
static int* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER */
#endif
