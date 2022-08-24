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
 * @author Franziska Wehner
 */

#ifndef TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Text (human-readable text and source code)
//
// IANA media type: text
//

/**
 * The text/ascii text state cybol format.
 *
 * Description:
 *
 * This is pure text data, sometimes called string or character array.
 *
 * CAUTION! Use it only when SINGLE byte characters are required,
 * for example with BINARY data representing an image.
 * When working with pure text, the format text/plain should be used
 * instead, since it uses multibyte characters and allows
 * internationalisation and the usage of unicode.
 *
 * CAUTION! Do NOT mix it up with "number/byte" representing NUMBERS in the range 0..255.
 * Numbers in an array are separated by COMMA; text characters of a string are NOT.
 *
 * Examples:
 *
 * <node name="image" channel="inline" format="text/ascii" model=""/>
 * <node name="text" channel="file" format="text/ascii" model="path/to/file.txt"/>
 */
static wchar_t* ASCII_TEXT_STATE_CYBOL_FORMAT = L"text/ascii";
static int* ASCII_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/cybol-path text state cybol format.
 *
 * Description:
 *
 * A path to a node within the knowledge tree (heap memory).
 *
 * It may point to:
 * - heap memory (knowledge memory tree) root .
 * - stack memory root #
 * - signal memory root |
 * - model part using separator .
 * - property part using separator :
 * - part via index using brackets []
 * - part via name using parentheses ()
 * - part via referenced path using curly braces {}
 * - stack memory variable #
 *
 * Examples:
 *
 * <node name="stack_root" channel="inline" format="text/cybol-path" model="#"/>
 * <node name="stack_variable" channel="inline" format="text/cybol-path" model="#x"/>
 * <node name="part" channel="inline" format="text/cybol-path" model=".a"/>
 * <node name="sub_part" channel="inline" format="text/cybol-path" model=".b.a"/>
 * <node name="property" channel="inline" format="text/cybol-path" model=".b:a"/>
 * <node name="part_by_index" channel="inline" format="text/cybol-path" model=".b.[#x]"/>
 * <node name="part_and_property_by_index" channel="inline" format="text/cybol-path" model=".b.[.b:[.d]]"/>
 * <node name="part_by_name" channel="inline" format="text/cybol-path" model=".(.e)"/>
 * <node name="part_by_nested_name" channel="inline" format="text/cybol-path" model=".(.(.e)).d:p"/>
 * <node name="node_contains_path_called_reference" channel="inline" format="text/cybol-path" model="{#path}"/>
 * <node name="part_by_reference_and_its_child_node" channel="inline" format="text/cybol-path" model="{#path}.child"/>
 * <node name="double_reference_path_to_path_to_part" channel="inline" format="text/cybol-path" model="{{#path}}"/>
 * <node name="part_via_reference_and_name" channel="inline" format="text/cybol-path" model=".b.d:({#path})"/>
 * <node name="nested_path" channel="inline" format="text/cybol-path" model=".test.node2:c.node1:b"/>
 */
static wchar_t* CYBOL_PATH_TEXT_STATE_CYBOL_FORMAT = L"text/cybol-path";
static int* CYBOL_PATH_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/html text state cybol format.
 *
 * Description:
 *
 * A text marked up using the Hypertext Markup Language (HTML).
 *
 * Common file suffixes are: html, htm, shtml, inc.
 *
 * Examples:
 *
 * <node name="webpage" channel="file" format="text/html" model="path/to/webpage.html"/>
 */
static wchar_t* HTML_TEXT_STATE_CYBOL_FORMAT = L"text/html";
static int* HTML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/javascript text state cybol format.
 *
 * TODO: Description:
 *
 * A JavaScript program script.
 *
 * Common file suffixes: js
 *
 * There are three MIME assignments for javascript data:
 * - application/javascript (official)
 * - application/x-javascript (outdated)
 * - text/javascript (unofficial)
 *
 * Preference should be given to the OFFICIAL mime type "application/javascript".
 *
 * TODO: Examples:
 *
 * <node name="program_source_code" channel="file" format="text/javascript" model="path/to/file.js"/>
 */
static wchar_t* JAVASCRIPT_TEXT_STATE_CYBOL_FORMAT = L"text/javascript";
static int* JAVASCRIPT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/json state cybol format.
 *
 * Description:
 *
 * Text data given in JavaScript Object Notation (JSON).
 *
 * There are three MIME assignments for json data:
 * - application/json (official)
 * - text/json (unofficial)
 * - text/javascript (unofficial)
 *
 * Preference should be given to the OFFICIAL mime type "application/json".
 *
 * Examples:
 *
 * <node name="data" channel="file" format="text/json" model="path/to/file.json"/>
 */
static wchar_t* JSON_TEXT_STATE_CYBOL_FORMAT = L"text/json";
static int* JSON_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/plain text state cybol format.
 *
 * Description:
 *
 * This is pure text data, sometimes called string or character array.
 *
 * The file suffix is commonly txt.
 *
 * The text may be encoded in various ways, which is specified in
 * a DIFFERENT property called encoding. It is usually given
 * when using the cybol operations send or receive.
 *
 * Examples:
 *
 * <node name="string" channel="inline" format="text/plain" model="Hello World!"/>
 * <node name="text" channel="file" format="text/plain" model="path/to/file.txt"/>
 */
static wchar_t* PLAIN_TEXT_STATE_CYBOL_FORMAT = L"text/plain";
static int* PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/richtext text state cybol format.
 *
 * Richtext
 * Registered.
 * Common file suffixes: rtx
 */
static wchar_t* RICHTEXT_TEXT_STATE_CYBOL_FORMAT = L"text/richtext";
static int* RICHTEXT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/rtf text state cybol format.
 *
 * Microsoft rich text format
 * Registered.
 * Common file suffixes: rtf
 */
static wchar_t* RTF_TEXT_STATE_CYBOL_FORMAT = L"text/rtf";
static int* RTF_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/tsv text state cybol format.
 *
 * tab separated values
 * Registered.
 * Common file suffixes: tsv
 */
static wchar_t* TAB_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT = L"text/tsv";
static int* TAB_SEPARATED_VALUES_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/vnd.wap.wml text state cybol format.
 *
 * WML (WAP)
 * Registered.
 * Common file suffixes: wml
 */
static wchar_t* VND_WAP_WML_TEXT_STATE_CYBOL_FORMAT = L"text/vnd.wap.wml";
static int* VND_WAP_WML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/vnd.wap.wmlscript text state cybol format.
 *
 * WML Script (WAP)
 * Registered.
 * Common file suffixes: wmls
 */
static wchar_t* VND_WAP_WMLSCRIPT_TEXT_STATE_CYBOL_FORMAT = L"text/vnd.wap.wmlscript";
static int* VND_WAP_WMLSCRIPT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/xml text state cybol format.
 *
 * Description:
 *
 * Data given in XML format.
 *
 * The Extensible Markup Language (XML) version 1.0 was defined in 1998.
 * Its structure and vocabulary can be defined freely, either as
 * Document Type Definition (DTD) or as XML Schema Definition (XSD).
 *
 * If given in form of a file, then the suffix is xml in case no DTD or XSD
 * is available. Otherwise, a suffix representing the DTD or XSD may be used.
 *
 * There are two MIME assignments for XML data:
 * - application/xml (RFC 7303, previously RFC 3023)
 * - text/xml (RFC 7303, previously RFC 3023)
 * However, since the introduction of RFC 7303, these are
 * to be regarded as the SAME in ALL aspects except name.
 *
 * Examples:
 *
 * <node name="data" channel="file" format="text/xml" model="path/to/file.xml"/>
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
 * Common file suffixes: etx
 */
static wchar_t* X_SETEXT_TEXT_STATE_CYBOL_FORMAT = L"text/x-setext";
static int* X_SETEXT_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/x-sgml text state cybol format.
 *
 * SGML
 * Registered.
 * Common file suffixes: sgm, sgml
 */
static wchar_t* X_SGML_TEXT_STATE_CYBOL_FORMAT = L"text/x-sgml";
static int* X_SGML_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The text/x-speech text state cybol format.
 *
 * Speech
 * Registered.
 * Common file suffixes: talk, spc
 */
static wchar_t* X_SPEECH_TEXT_STATE_CYBOL_FORMAT = L"text/x-speech";
static int* X_SPEECH_TEXT_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TEXT_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
