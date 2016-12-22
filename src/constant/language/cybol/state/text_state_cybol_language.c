/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

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
// Text (human-readable text and source code).
//
// IANA media type: text
//

/**
 * The text/authority state cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE = L"text/authority";
static int* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/bdt state cybol language.
 *
 * Behandlungsdaten-Transfer (BDT) format.
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
 * Cascading Style Sheets.
 * Defined in RFC 2318.
 * Suffixes: css
 */
static wchar_t* CSS_TEXT_STATE_CYBOL_LANGUAGE = L"text/css";
static int* CSS_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol state cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 * Suffixes: cybol
 */
static wchar_t* CYBOL_TEXT_STATE_CYBOL_LANGUAGE = L"text/cybol";
static int* CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/gdt state cybol language.
 *
 * Gerätedaten-Transfer (GDT) format.
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
 * Hypertext Markup Language (HTML) format.
 * Defined in RFC 2854.
 * Suffixes: html, htm, shtml
 */
static wchar_t* HTML_TEXT_STATE_CYBOL_LANGUAGE = L"text/html";
static int* HTML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/hxp state cybol language.
 *
 * Healthcare Exchange Protocol (HXP) format.
 * An XML-based standard for medical data exchange.
 *
 * It was defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t* HXP_TEXT_STATE_CYBOL_LANGUAGE = L"text/hxp";
static int* HXP_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/ldt state cybol language.
 *
 * Labordaten-Transfer (LDT) format.
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
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE = L"text/model-diagram";
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/uri state cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* URI_TEXT_STATE_CYBOL_LANGUAGE = L"text/uri";
static int* URI_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xdt-field-description state cybol language.
 */
static wchar_t* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE = L"text/xdt-field-description";
static int* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xml state cybol language.
 *
 * Extensible Markup Language.
 * Defined in RFC 3023.
 * Suffixes: xml
 */
static wchar_t* XML_TEXT_STATE_CYBOL_LANGUAGE = L"text/xml";
static int* XML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
