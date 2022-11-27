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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LANGUAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE
#define LANGUAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
 * The classic octal prefix language state cybol name.
 *
 * It is used in the numeral serialiser.
 */
static wchar_t* CLASSIC_OCTAL_PREFIX_LANGUAGE_STATE_CYBOL_NAME = L"classic_octal_prefix";
static int* CLASSIC_OCTAL_PREFIX_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clear language state cybol name.
 *
 * Used with text (pseudo) terminal.
 * Clears the terminal screen before printing characters on it.
 */
static wchar_t* CLEAR_LANGUAGE_STATE_CYBOL_NAME = L"clear";
static int* CLEAR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The consider number base prefix language state cybol name.
 *
 * It is used in the numeral deserialiser.
 */
static wchar_t* CONSIDER_NUMBER_BASE_PREFIX_LANGUAGE_STATE_CYBOL_NAME = L"consider_number_base_prefix";
static int* CONSIDER_NUMBER_BASE_PREFIX_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The decimal places language state cybol name.
 *
 * It is used in the numeral serialiser.
 */
static wchar_t* DECIMAL_PLACES_LANGUAGE_STATE_CYBOL_NAME = L"decimal_places";
static int* DECIMAL_PLACES_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The decimal separator language state cybol name.
 *
 * Used in data formats containing numbers, for example xml or json.
 */
static wchar_t* DECIMAL_SEPARATOR_LANGUAGE_STATE_CYBOL_NAME = L"decimal_separator";
static int* DECIMAL_SEPARATOR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The delimiter language state cybol name.
 *
 * Used with joined strings or character (comma) separated values (csv).
 * Separates the single fields (values).
 * The delimiter may be a comma, for example.
 *
 * Example:
 *
 * blu,bla,test
 */
static wchar_t* DELIMITER_LANGUAGE_STATE_CYBOL_NAME = L"delimiter";
static int* DELIMITER_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The header language state cybol name.
 *
 * Used with character (comma) separated values (csv).
 * Defines as flag whether or not the data contain a header,
 * so that the deserialiser can treat the first line differently.
 */
static wchar_t* HEADER_LANGUAGE_STATE_CYBOL_NAME = L"header";
static int* HEADER_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The indentation language state cybol name.
 *
 * Used with for example xml or html.
 * Beautifies the serialised data by indenting the single lines
 * depending on the current hierarchical level.
 */
static wchar_t* INDENTATION_LANGUAGE_STATE_CYBOL_NAME = L"indentation";
static int* INDENTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maximum language state cybol name.
 *
 * Used with serial (port) interface.
 * Defines the number of data to be transmitted.
 */
static wchar_t* MAXIMUM_LANGUAGE_STATE_CYBOL_NAME = L"maximum";
static int* MAXIMUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The medium language state cybol name.
 *
 * Used with graphical user interface (gui).
 * References the window to which the mouse button or keyboard key refers,
 * in order to search through the gui elements for a suitable action.
 */
static wchar_t* MEDIUM_LANGUAGE_STATE_CYBOL_NAME = L"medium";
static int* MEDIUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minimum language state cybol name.
 *
 * Used with serial (port) interface.
 * Defines the number of data to be transmitted.
 */
static wchar_t* MINIMUM_LANGUAGE_STATE_CYBOL_NAME = L"minimum";
static int* MINIMUM_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The newline language state cybol name.
 *
 * Used with text (pseudo) terminal.
 * Adds a line break (newline) at the end of the characters printed on the terminal screen.
 */
static wchar_t* NEWLINE_LANGUAGE_STATE_CYBOL_NAME = L"newline";
static int* NEWLINE_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The normalisation language state cybol name.
 *
 * Used with for example xml or html.
 * Summarises (condenses) spaces and line breaks to just ONE space.
 */
static wchar_t* NORMALISATION_LANGUAGE_STATE_CYBOL_NAME = L"normalisation";
static int* NORMALISATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number base language state cybol name.
 *
 * It is used in the numeral serialiser.
 */
static wchar_t* NUMBER_BASE_LANGUAGE_STATE_CYBOL_NAME = L"number_base";
static int* NUMBER_BASE_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The positioning language state cybol name.
 *
 * Used with text (pseudo) terminal.
 * Repositions the cursor as needed for printing characters on terminal screen.
 */
static wchar_t* POSITIONING_LANGUAGE_STATE_CYBOL_NAME = L"positioning";
static int* POSITIONING_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quotation language state cybol name.
 *
 * Used with joined strings or character (comma) separated values (csv).
 * Quotes the single fields (values).
 * This is necessary if the delimiter character (for example comma) is part of the value.
 *
 * Example:
 *
 * "test_1","test_2","comma_,_end","test_3"
 */
static wchar_t* QUOTATION_LANGUAGE_STATE_CYBOL_NAME = L"quotation";
static int* QUOTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scientific notation language state cybol name.
 *
 * It is used in the numeral serialiser.
 */
static wchar_t* SCIENTIFIC_NOTATION_LANGUAGE_STATE_CYBOL_NAME = L"scientific_notation";
static int* SCIENTIFIC_NOTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sign language state cybol name.
 *
 * It is used in the numeral serialiser as FLAG indicating whether or not
 * a plus sign shall be printed at the beginning of positive numbers.
 * A minus sign, on the other hand, gets ALWAYS printed if a number is negative.
 */
static wchar_t* SIGN_LANGUAGE_STATE_CYBOL_NAME = L"sign";
static int* SIGN_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thousands separator language state cybol name.
 *
 * Used in data formats containing numbers, for example xml or json.
 */
static wchar_t* THOUSANDS_SEPARATOR_LANGUAGE_STATE_CYBOL_NAME = L"thousands_separator";
static int* THOUSANDS_SEPARATOR_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The width language state cybol name.
 *
 * Used with joined strings or character (comma) separated values (csv).
 * Fills up any free spaces with zero.
 * This was defined in the original specification of csv,
 * in order to have fields (values) with equal width.
 *
 * Example:
 *
 * serialised values with "width" set to "3":
 *
 * "001","005","010","100"
 */
static wchar_t* WIDTH_LANGUAGE_STATE_CYBOL_NAME = L"width";
static int* WIDTH_LANGUAGE_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LANGUAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE */
#endif
