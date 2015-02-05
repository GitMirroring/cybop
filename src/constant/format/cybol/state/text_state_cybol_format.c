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
 * @author Franziska Wehner
 */

#ifndef TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
 * The text/ascii text state cybol format.
 *
 * CYBOL (XML)
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 *
 * It is used for single-byte-characters in CYBOL.
 *
 * CAUTION! This format represents a text string of characters.
 * It is NOT to be mixed up with "number/byte" representing
 * numbers in the range 0..255.
 * Numbers in an array ARE separated by comma;
 * text characters of a string are NOT.
 */
static wchar_t* ASCII_TEXT_STATE_CYBOL_FORMAT = L"text/ascii";
static int* ASCII_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/csv text state cybol format.
 *
 * Character-separated values
 * (also known as comma-separated values,
 * but other characters than comma may be used as well)
 * Registered.
 * Suffixes: csv
 */
static wchar_t* CHARACTER_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT = L"text/csv";
static int* CHARACTER_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/css text state cybol format.
 *
 * CSS Stylesheet
 * Registered.
 * Suffixes: css
 */
static wchar_t* CSS_TEXT_STATE_CYBOL_FORMAT = L"text/css";
static int* CSS_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/html text state cybol format.
 *
 * HTML
 * Registered.
 * Suffixes: htm, html, shtml
 */
static wchar_t* HTML_TEXT_STATE_CYBOL_FORMAT = L"text/html";
static int* HTML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/javascript text state cybol format.
 *
 * JavaScript
 * Registered.
 * Suffixes: js
 */
static wchar_t* JAVASCRIPT_TEXT_STATE_CYBOL_FORMAT = L"text/javascript";
static int* JAVASCRIPT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/plain text state cybol format.
 *
 * Plain text
 * Defined in RFC 2046 and RFC 3676.
 * Suffixes: txt
 *
 * This language (media type) is also used for strings (character vectors) in CYBOL.
 */
static wchar_t* PLAIN_TEXT_STATE_CYBOL_FORMAT = L"text/plain";
static int* PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/richtext text state cybol format.
 *
 * Richtext
 * Registered.
 * Suffixes: rtx
 */
static wchar_t* RICHTEXT_TEXT_STATE_CYBOL_FORMAT = L"text/richtext";
static int* RICHTEXT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/rtf text state cybol format.
 *
 * Microsoft rich text format
 * Registered.
 * Suffixes: rtf
 */
static wchar_t* RTF_TEXT_STATE_CYBOL_FORMAT = L"text/rtf";
static int* RTF_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/tsv text state cybol format.
 *
 * tab separated values
 * Registered.
 * Suffixes: tsv
 */
static wchar_t* TAB_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT = L"text/tsv";
static int* TAB_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/vnd.wap.wml text state cybol format.
 *
 * WML (WAP)
 * Registered.
 * Suffixes: wml
 */
static wchar_t* VND_WAP_WML_TEXT_STATE_CYBOL_FORMAT = L"text/vnd.wap.wml";
static int* VND_WAP_WML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/vnd.wap.wmlscript text state cybol format.
 *
 * WML Script (WAP)
 * Registered.
 * Suffixes: wmls
 */
static wchar_t* VND_WAP_WMLSCRIPT_TEXT_STATE_CYBOL_FORMAT = L"text/vnd.wap.wmlscript";
static int* VND_WAP_WMLSCRIPT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xml text state cybol format.
 *
 * XML
 * Registered.
 * Suffixes: xml
 */
static wchar_t* XML_TEXT_STATE_CYBOL_FORMAT = L"text/xml";
static int* XML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xml-external-parsed-entity text state cybol format.
 *
 * external parsed XML
 * Registered.
 */
static wchar_t* XML_EXTERNAL_PARSED_ENTITY_TEXT_STATE_CYBOL_FORMAT = L"text/xml-external-parsed-entity";
static int* XML_EXTERNAL_PARSED_ENTITY_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/x-setext text state cybol format.
 *
 * SeText
 * Registered.
 * Suffixes: etx
 */
static wchar_t* X_SETEXT_TEXT_STATE_CYBOL_FORMAT = L"text/x-setext";
static int* X_SETEXT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/x-sgml text state cybol format.
 *
 * SGML
 * Registered.
 * Suffixes: sgm, sgml
 */
static wchar_t* X_SGML_TEXT_STATE_CYBOL_FORMAT = L"text/x-sgml";
static int* X_SGML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/x-speech text state cybol format.
 *
 * Speech
 * Registered.
 * Suffixes: talk, spc
 */
static wchar_t* X_SPEECH_TEXT_STATE_CYBOL_FORMAT = L"text/x-speech";
static int* X_SPEECH_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
