/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
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
 * The text/authority cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {'t', L'e', L'x', L't', L'/', L'a', L'u', L't', L'h', L'o', L'r', L'i', L't', L'y'};
static wchar_t* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE = AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* AUTHORITY_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/bdt cybol language.
 *
 * Behandlungsdaten-Transfer (BDT) format.
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: bdt
 */
static wchar_t BDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'b', L'd', L't'};
static wchar_t* BDT_TEXT_STATE_CYBOL_LANGUAGE = BDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* BDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/css cybol language.
 *
 * Cascading Style Sheets.
 * Defined in RFC 2318.
 * Suffixes: css
 */
static wchar_t CSS_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L's', L's'};
static wchar_t* CSS_TEXT_STATE_CYBOL_LANGUAGE = CSS_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* CSS_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 * Suffixes: cybol
 */
static wchar_t CYBOL_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L'y', L'b', L'o', L'l'};
static wchar_t* CYBOL_TEXT_STATE_CYBOL_LANGUAGE = CYBOL_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/gdt cybol language.
 *
 * Gerätedaten-Transfer (GDT) format.
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: gdt
 */
static wchar_t GDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'g', L'd', L't'};
static wchar_t* GDT_TEXT_STATE_CYBOL_LANGUAGE = GDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* GDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/html cybol language.
 *
 * Hypertext Markup Language (HTML) format.
 * Defined in RFC 2854.
 * Suffixes: html, htm, shtml
 */
static wchar_t HTML_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L't', L'm', L'l'};
static wchar_t* HTML_TEXT_STATE_CYBOL_LANGUAGE = HTML_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* HTML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/hxp cybol language.
 *
 * Healthcare Exchange Protocol (HXP) format.
 * An XML-based standard for medical data exchange.
 *
 * It was defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t HXP_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L'x', L'p'};
static wchar_t* HXP_TEXT_STATE_CYBOL_LANGUAGE = HXP_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* HXP_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/ldt cybol language.
 *
 * Labordaten-Transfer (LDT) format.
 * It belongs to the x Datentransfer (xDT) group of
 * compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: ldt
 */
static wchar_t LDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'l', L'd', L't'};
static wchar_t* LDT_TEXT_STATE_CYBOL_LANGUAGE = LDT_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* LDT_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/model-diagram cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'm', L'o', L'd', L'e', L'l', L'-', L'd', L'i', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE = MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/uri cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t URI_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {'t', L'e', L'x', L't', L'/', L'u', L'r', L'i'};
static wchar_t* URI_TEXT_STATE_CYBOL_LANGUAGE = URI_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* URI_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xdt-field-description cybol language.
 */
static wchar_t XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'd', L't', L'-', L'f', L'i', L'e', L'l', L'd', L'-', L'd', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE = XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xml cybol language.
 *
 * Extensible Markup Language.
 * Defined in RFC 3023.
 * Suffixes: xml
 */
static wchar_t XML_TEXT_STATE_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'm', L'l'};
static wchar_t* XML_TEXT_STATE_CYBOL_LANGUAGE = XML_TEXT_STATE_CYBOL_LANGUAGE_ARRAY;
static int* XML_TEXT_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
