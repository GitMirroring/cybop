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

#ifndef LANGUAGE_STATE_CYBOL_NAME_CONSTANT_HEADER
#define LANGUAGE_STATE_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// These name constants are to be used as constraint for the cybol
// property "language" with one of the following cybol operations:
//
// - communicate/send
// - communicate/receive
// - represent/serialise
// - represent/deserialise
//

/**
 * The base language state cybol name.
 *
 * It is used as number base in the numeral serialiser.
 *
 * Used with numeral serialiser.
 */
static wchar_t* BASE_LANGUAGE_STATE_CYBOL_NAME = L"base";
static int* BASE_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The classicoctal language state cybol name.
 *
 * It is used as classic octal prefix in the numeral serialiser.
 *
 * Used with numeral serialiser.
 */
static wchar_t* CLASSICOCTAL_LANGUAGE_STATE_CYBOL_NAME = L"classicoctal";
static int* CLASSICOCTAL_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clear language state cybol name.
 *
 * Clears the terminal screen before printing characters on it.
 *
 * Used with text user interface (tui) serialiser for text (pseudo) terminal.
 */
static wchar_t* CLEAR_LANGUAGE_STATE_CYBOL_NAME = L"clear";
static int* CLEAR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The decimals language state cybol name.
 *
 * Used with numeral serialiser.
 */
static wchar_t* DECIMALS_LANGUAGE_STATE_CYBOL_NAME = L"decimals";
static int* DECIMALS_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The delimiter language state cybol name.
 *
 * Separates the single fields (values).
 * The delimiter may be a comma, for example.
 *
 * Used with joined string or character (comma) separated values (csv) serialiser.
 *
 * Example:
 *
 * blu,bla,test
 */
static wchar_t* DELIMITER_LANGUAGE_STATE_CYBOL_NAME = L"delimiter";
static int* DELIMITER_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fill language state cybol name.
 *
 * The characters (or digit) to be used to fill free places in a value whose width is greater.
 *
 * Used with character (comma) separated values (csv) serialiser.
 */
static wchar_t* FILL_LANGUAGE_STATE_CYBOL_NAME = L"fill";
static int* FILL_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The grouping language state cybol name.
 *
 * Defines the thousands separator.
 *
 * Used with numeral serialiser.
 */
static wchar_t* GROUPING_LANGUAGE_STATE_CYBOL_NAME = L"grouping";
static int* GROUPING_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The header language state cybol name.
 *
 * Defines as flag whether or not the data contain a header,
 * so that the deserialiser can treat the first line differently.
 *
 * Used with character (comma) separated values (csv) serialiser.
 */
static wchar_t* HEADER_LANGUAGE_STATE_CYBOL_NAME = L"header";
static int* HEADER_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The headermodel language state cybol name.
 *
 * It is used as header data to be written as first line, yet before
 * the actual content, with character (comma) separated values (csv).
 *
 * Used with character (comma) separated values (csv) serialiser.
 */
static wchar_t* HEADERMODEL_LANGUAGE_STATE_CYBOL_NAME = L"headermodel";
static int* HEADERMODEL_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The indentation language state cybol name.
 *
 * Beautifies the serialised data by indenting the single lines
 * depending on the current hierarchical level.
 *
 * Used with xml or html or json serialiser.
 */
static wchar_t* INDENTATION_LANGUAGE_STATE_CYBOL_NAME = L"indentation";
static int* INDENTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maximum language state cybol name.
 *
 * Defines the number of data to be transmitted.
 *
 * Used with binary serialiser for serial (port) interface.
 */
static wchar_t* MAXIMUM_LANGUAGE_STATE_CYBOL_NAME = L"maximum";
static int* MAXIMUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The medium language state cybol name.
 *
 * References the window to which the mouse button or keyboard key refers,
 * in order to search through the gui elements for a suitable action.
 *
 * Used with graphical user interface (gui) serialiser.
 */
static wchar_t* MEDIUM_LANGUAGE_STATE_CYBOL_NAME = L"medium";
static int* MEDIUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minimum language state cybol name.
 *
 * Defines the number of data to be transmitted.
 *
 * Used with binary serialiser for serial (port) interface.
 */
static wchar_t* MINIMUM_LANGUAGE_STATE_CYBOL_NAME = L"minimum";
static int* MINIMUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The newline language state cybol name.
 *
 * Adds a line break (newline) at the end of the printed characters.
 *
 * Used with text user interface (tui) serialiser for text (pseudo) terminal.
 */
static wchar_t* NEWLINE_LANGUAGE_STATE_CYBOL_NAME = L"newline";
static int* NEWLINE_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The normalisation language state cybol name.
 *
 * Summarises (condenses) spaces and line breaks to just ONE space.
 *
 * Used with xml or html or json serialiser.
 */
static wchar_t* NORMALISATION_LANGUAGE_STATE_CYBOL_NAME = L"normalisation";
static int* NORMALISATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The polar language state cybol name.
 *
 * The flag indicating whether or not to write the complex number using polar coordinates.
 *
 * Used with numeral serialiser.
 */
static wchar_t* POLAR_LANGUAGE_STATE_CYBOL_NAME = L"polar";
static int* POLAR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The positioning language state cybol name.
 *
 * Repositions the cursor as needed for printing characters on terminal screen.
 *
 * Used with text user interface (tui) serialiser for text (pseudo) terminal.
 */
static wchar_t* POSITIONING_LANGUAGE_STATE_CYBOL_NAME = L"positioning";
static int* POSITIONING_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prefix language state cybol name.
 *
 * The flag indicating whether or not to consider the number base prefix
 * in the numeral deserialiser.
 *
 * The flag indicating whether or not to prepend a number base prefix
 * in the numeral serialiser.
 */
static wchar_t* PREFIX_LANGUAGE_STATE_CYBOL_NAME = L"prefix";
static int* PREFIX_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quotation language state cybol name.
 *
 * Quotes the single fields (values).
 * This is necessary if the delimiter character (for example comma) is part of the value.
 *
 * Used with joined strings or character (comma) separated values (csv) serialiser.
 *
 * Example:
 *
 * "test_1","test_2","comma_,_end","test_3"
 */
static wchar_t* QUOTATION_LANGUAGE_STATE_CYBOL_NAME = L"quotation";
static int* QUOTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scientific language state cybol name.
 *
 * It defines whether or not to use scientific notation.
 *
 * Used with numeral serialiser.
 */
static wchar_t* SCIENTIFIC_LANGUAGE_STATE_CYBOL_NAME = L"scientific";
static int* SCIENTIFIC_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The separator language state cybol name.
 *
 * It is used as decimal separator.
 *
 * Used with numeral serialiser.
 */
static wchar_t* SEPARATOR_LANGUAGE_STATE_CYBOL_NAME = L"separator";
static int* SEPARATOR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sign language state cybol name.
 *
 * The flag indicating whether or not to add a plus sign for positive numbers.
 *
 * Used with numeral serialiser.
 */
static wchar_t* SIGN_LANGUAGE_STATE_CYBOL_NAME = L"sign";
static int* SIGN_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The width language state cybol name.
 *
 * Fills up any free spaces with zero.
 * This was defined in the original specification of csv,
 * in order to have fields (values) with equal width.
 *
 * Used with joined strings or character (comma) separated values (csv) serialiser.
 *
 * Example:
 *
 * serialised values with "width" set to "3":
 *
 * "001","005","010","100"
 */
static wchar_t* WIDTH_LANGUAGE_STATE_CYBOL_NAME = L"width";
static int* WIDTH_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LANGUAGE_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
