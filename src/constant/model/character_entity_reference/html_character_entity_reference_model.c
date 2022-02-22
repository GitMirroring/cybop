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

#ifndef HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_SOURCE
#define HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// This list of constants was built upon information taken from:
// http://en.wikipedia.org/wiki/List_of_XML_and_HTML_character_entity_references
//
// Accessed on: 2012-08-13
//

/**
 * The quotation mark html character entity reference model.
 *
 * Name: quot
 * Character: "
 * Unicode code point: U+0022 (34)
 * Standard: HTML 2.0, XML 1.0
 * Description: quotation mark
 */
static wchar_t* QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quot";
static int* QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ampersand html character entity reference model.
 *
 * Name: amp
 * Character: &
 * Unicode code point: U+0026 (38)
 * Standard: HTML 2.0, XML 1.0
 * Description: ampersand
 */
static wchar_t* AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amp";
static int* AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apostrophe html character entity reference model.
 *
 * Name: apos
 * Character: '
 * Unicode code point: U+0027 (39)
 * Standard: XML 1.0
 * Description: apostrophe (= apostrophe-quote)
 */
static wchar_t* APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apos";
static int* APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than sign html character entity reference model.
 *
 * Name: lt
 * Character: <
 * Unicode code point: U+003C (60)
 * Standard: HTML 2.0, XML 1.0
 * Description: less-than sign
 */
static wchar_t* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lt";
static int* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than sign html character entity reference model.
 *
 * Name: gt
 * Character: >
 * Unicode code point: U+003E (62)
 * Standard: HTML 2.0, XML 1.0
 * Description: greater-than sign
 */
static wchar_t* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gt";
static int* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The non-breaking space html character entity reference model.
 *
 * Name: nbsp
 * Character:
 * Unicode code point: U+00A0 (160)
 * Standard: HTML 3.2
 * Description: non-breaking space
 */
static wchar_t* NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nbsp";
static int* NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted exclamation mark html character entity reference model.
 *
 * Name: iexcl
 * Character: ¡
 * Unicode code point: U+00A1 (161)
 * Standard: HTML 3.2
 * Description: inverted exclamation mark
 */
static wchar_t* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iexcl";
static int* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cent sign html character entity reference model.
 *
 * Name: cent
 * Character: ¢
 * Unicode code point: U+00A2 (162)
 * Standard: HTML 3.2
 * Description: cent sign
 */
static wchar_t* CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cent";
static int* CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pound sign html character entity reference model.
 *
 * Name: pound
 * Character: £
 * Unicode code point: U+00A3 (163)
 * Standard: HTML 3.2
 * Description: pound sign
 */
static wchar_t* POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pound";
static int* POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The currency sign html character entity reference model.
 *
 * Name: curren
 * Character: ¤
 * Unicode code point: U+00A4 (164)
 * Standard: HTML 3.2
 * Description: currency sign
 */
static wchar_t* CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curren";
static int* CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yen sign html character entity reference model.
 *
 * Name: yen
 * Character: ¥
 * Unicode code point: U+00A5 (165)
 * Standard: HTML 3.2
 * Description: yen sign
 */
static wchar_t* YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yen";
static int* YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The broken bar html character entity reference model.
 *
 * Name: brvbar
 * Character: ¦
 * Unicode code point: U+00A6 (166)
 * Standard: HTML 3.2
 * Description: broken bar
 */
static wchar_t* BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"brvbar";
static int* BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The section sign html character entity reference model.
 *
 * Name: sect
 * Character: §
 * Unicode code point: U+00A7 (167)
 * Standard: HTML 3.2
 * Description: section sign
 */
static wchar_t* SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sect";
static int* SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diaeresis html character entity reference model.
 *
 * Name: uml
 * Character: ¨
 * Unicode code point: U+00A8 (168)
 * Standard: HTML 3.2
 * Description: diaeresis
 */
static wchar_t* DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uml";
static int* DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The copyright sign html character entity reference model.
 *
 * Name: copy
 * Character: ©
 * Unicode code point: U+00A9 (169)
 * Standard: HTML 3.2
 * Description: copyright sign
 */
static wchar_t* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copy";
static int* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The feminine ordinal indicator html character entity reference model.
 *
 * Name: ordf
 * Character: ª
 * Unicode code point: U+00AA (170)
 * Standard: HTML 3.2
 * Description: feminine ordinal indicator
 */
static wchar_t* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordf";
static int* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-pointing double angle quotation mark html character entity reference model.
 *
 * Name: laquo
 * Character: «
 * Unicode code point: U+00AB (171)
 * Standard: HTML 3.2
 * Description: left-pointing double angle quotation mark
 */
static wchar_t* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"laquo";
static int* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not sign html character entity reference model.
 *
 * Name: not
 * Character: ¬
 * Unicode code point: U+00AC (172)
 * Standard: HTML 3.2
 * Description: not sign
 */
static wchar_t* NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"not";
static int* NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The soft hyphen html character entity reference model.
 *
 * Name: shy
 * Character:
 * Unicode code point: U+00AD (173)
 * Standard: HTML 3.2
 * Description: soft hyphen
 */
static wchar_t* SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shy";
static int* SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The registered sign html character entity reference model.
 *
 * Name: reg
 * Character: ®
 * Unicode code point: U+00AE (174)
 * Standard: HTML 3.2
 * Description: registered sign
 */
static wchar_t* REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"reg";
static int* REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The macron html character entity reference model.
 *
 * Name: macr
 * Character: ¯
 * Unicode code point: U+00AF (175)
 * Standard: HTML 3.2
 * Description: macron
 */
static wchar_t* MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"macr";
static int* MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The degree sign html character entity reference model.
 *
 * Name: deg
 * Character: °
 * Unicode code point: U+00B0 (176)
 * Standard: HTML 3.2
 * Description: degree sign
 */
static wchar_t* DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"deg";
static int* DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus-minus sign html character entity reference model.
 *
 * Name: plusmn
 * Character: ±
 * Unicode code point: U+00B1 (177)
 * Standard: HTML 3.2
 * Description: plus-minus sign
 */
static wchar_t* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusmn";
static int* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript two html character entity reference model.
 *
 * Name: sup2
 * Character: ²
 * Unicode code point: U+00B2 (178)
 * Standard: HTML 3.2
 * Description: superscript two
 */
static wchar_t* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup2";
static int* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript three html character entity reference model.
 *
 * Name: sup3
 * Character:
 * Unicode code point: U+00B3 (179)
 * Standard: HTML 3.2
 * Description: superscript three
 */
static wchar_t* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup3";
static int* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acute accent html character entity reference model.
 *
 * Name: acute
 * Character: �
 * Unicode code point: U+00B4 (180)
 * Standard: HTML 3.2
 * Description: acute accent
 */
static wchar_t* ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acute";
static int* ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The micro sign html character entity reference model.
 *
 * Name: micro
 * Character: �
 * Unicode code point: U+00B5 (181)
 * Standard: HTML 3.2
 * Description: micro sign
 */
static wchar_t* MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"micro";
static int* MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pilcrow sign html character entity reference model.
 *
 * Name: para
 * Character: �
 * Unicode code point: U+00B6 (182)
 * Standard: HTML 3.2
 * Description: pilcrow sign
 */
static wchar_t* PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"para";
static int* PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The middle dot html character entity reference model.
 *
 * Name: middot
 * Character: �
 * Unicode code point: U+00B7 (183)
 * Standard: HTML 3.2
 * Description: middle dot
 */
static wchar_t* MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"middot";
static int* MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cedilla html character entity reference model.
 *
 * Name: cedil
 * Character: �
 * Unicode code point: U+00B8 (184)
 * Standard: HTML 3.2
 * Description: cedilla
 */
static wchar_t* CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cedil";
static int* CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript one html character entity reference model.
 *
 * Name: sup1
 * Character: �
 * Unicode code point: U+00B9 (185)
 * Standard: HTML 3.2
 * Description: superscript one
 */
static wchar_t* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup1";
static int* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The masculine ordinal indicator html character entity reference model.
 *
 * Name: ordm
 * Character: �
 * Unicode code point: U+00BA (186)
 * Standard: HTML 3.2
 * Description: masculine ordinal indicator
 */
static wchar_t* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordm";
static int* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-pointing double angle quotation mark html character entity reference model.
 *
 * Name: raquo
 * Character: �
 * Unicode code point: U+00BB (187)
 * Standard: HTML 3.2
 * Description: right-pointing double angle quotation mark
 */
static wchar_t* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"raquo";
static int* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one quarter html character entity reference model.
 *
 * Name: frac14
 * Character: �
 * Unicode code point: U+00BC (188)
 * Standard: HTML 3.2
 * Description: vulgar fraction one quarter
 */
static wchar_t* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac14";
static int* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one half html character entity reference model.
 *
 * Name: frac12
 * Character: �
 * Unicode code point: U+00BD (189)
 * Standard: HTML 3.2
 * Description: vulgar fraction one half
 */
static wchar_t* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac12";
static int* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction three quarters html character entity reference model.
 *
 * Name: frac34
 * Character: �
 * Unicode code point: U+00BE (190)
 * Standard: HTML 3.2
 * Description: vulgar fraction three quarters
 */
static wchar_t* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac34";
static int* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted question mark html character entity reference model.
 *
 * Name: iquest
 * Character: �
 * Unicode code point: U+00BF (191)
 * Standard: HTML 3.2
 * Description: inverted question mark
 */
static wchar_t* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iquest";
static int* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with grave html character entity reference model.
 *
 * Name: Agrave
 * Character: �
 * Unicode code point: U+00C0 (192)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Agrave";
static int* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with acute html character entity reference model.
 *
 * Name: Aacute
 * Character: �
 * Unicode code point: U+00C1 (193)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aacute";
static int* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with circumflex html character entity reference model.
 *
 * Name: Acirc
 * Character: �
 * Unicode code point: U+00C2 (194)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Acirc";
static int* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with tilde html character entity reference model.
 *
 * Name: Atilde
 * Character: �
 * Unicode code point: U+00C3 (195)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Atilde";
static int* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with diaeresis html character entity reference model.
 *
 * Name: Auml
 * Character: �
 * Unicode code point: U+00C4 (196)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Auml";
static int* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter a with ring above html character entity reference model.
 *
 * Name: Aring
 * Character: �
 * Unicode code point: U+00C5 (197)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with ring above
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aring";
static int* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter ae html character entity reference model.
 *
 * Name: AElig
 * Character: �
 * Unicode code point: U+00C6 (198)
 * Standard: HTML 2.0
 * Description: Latin capital letter ae
 */
static wchar_t* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"AElig";
static int* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter c with cedilla html character entity reference model.
 *
 * Name: Ccedil
 * Character: �
 * Unicode code point: U+00C7 (199)
 * Standard: HTML 2.0
 * Description: Latin capital letter c with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccedil";
static int* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter e with grave html character entity reference model.
 *
 * Name: Egrave
 * Character: �
 * Unicode code point: U+00C8 (200)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Egrave";
static int* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter e with acute html character entity reference model.
 *
 * Name: Eacute
 * Character: �
 * Unicode code point: U+00C9 (201)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eacute";
static int* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter e with circumflex html character entity reference model.
 *
 * Name: Ecirc
 * Character: �
 * Unicode code point: U+00CA (202)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecirc";
static int* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter e with diaeresis html character entity reference model.
 *
 * Name: Euml
 * Character: �
 * Unicode code point: U+00CB (203)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Euml";
static int* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter i with grave html character entity reference model.
 *
 * Name: Igrave
 * Character: �
 * Unicode code point: U+00CC (204)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Igrave";
static int* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter i with acute html character entity reference model.
 *
 * Name: Iacute
 * Character: �
 * Unicode code point: U+00CD (205)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iacute";
static int* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter i with circumflex html character entity reference model.
 *
 * Name: Icirc
 * Character: �
 * Unicode code point: U+00CE (206)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Icirc";
static int* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter i with diaeresis html character entity reference model.
 *
 * Name: Iuml
 * Character: �
 * Unicode code point: U+00CF (207)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iuml";
static int* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter eth html character entity reference model.
 *
 * Name: ETH
 * Character: �
 * Unicode code point: U+00D0 (208)
 * Standard: HTML 2.0
 * Description: Latin capital letter eth
 */
static wchar_t* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ETH";
static int* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter n with tilde html character entity reference model.
 *
 * Name: Ntilde
 * Character: �
 * Unicode code point: U+00D1 (209)
 * Standard: HTML 2.0
 * Description: Latin capital letter n with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ntilde";
static int* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with grave html character entity reference model.
 *
 * Name: Ograve
 * Character: �
 * Unicode code point: U+00D2 (210)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ograve";
static int* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with acute html character entity reference model.
 *
 * Name: Oacute
 * Character: �
 * Unicode code point: U+00D3 (211)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oacute";
static int* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with circumflex html character entity reference model.
 *
 * Name: Ocirc
 * Character: �
 * Unicode code point: U+00D4 (212)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ocirc";
static int* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with tilde html character entity reference model.
 *
 * Name: Otilde
 * Character: �
 * Unicode code point: U+00D5 (213)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Otilde";
static int* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with diaeresis html character entity reference model.
 *
 * Name: Ouml
 * Character: �
 * Unicode code point: U+00D6 (214)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ouml";
static int* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign html character entity reference model.
 *
 * Name: times
 * Character: �
 * Unicode code point: U+00D7 (215)
 * Standard: HTML 3.2
 * Description: multiplication sign
 */
static wchar_t* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"times";
static int* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter o with stroke html character entity reference model.
 *
 * Name: Oslash
 * Character: �
 * Unicode code point: U+00D8 (216)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oslash";
static int* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter u with grave html character entity reference model.
 *
 * Name: Ugrave
 * Character: �
 * Unicode code point: U+00D9 (217)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ugrave";
static int* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter u with acute html character entity reference model.
 *
 * Name: Uacute
 * Character: �
 * Unicode code point: U+00DA (218)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uacute";
static int* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter u with circumflex html character entity reference model.
 *
 * Name: Ucirc
 * Character: �
 * Unicode code point: U+00DB (219)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ucirc";
static int* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter u with diaeresis html character entity reference model.
 *
 * Name: Uuml
 * Character: �
 * Unicode code point: U+00DC (220)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uuml";
static int* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter y with acute html character entity reference model.
 *
 * Name: Yacute
 * Character: �
 * Unicode code point: U+00DD (221)
 * Standard: HTML 2.0
 * Description: Latin capital letter y with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yacute";
static int* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter thorn html character entity reference model.
 *
 * Name: THORN
 * Character: �
 * Unicode code point: U+00DE (222)
 * Standard: HTML 2.0
 * Description: Latin capital letter thorn
 */
static wchar_t* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"THORN";
static int* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter sharp s (German Eszett)html character entity.
 *
 * Name: szlig
 * Character: �
 * Unicode code point: U+00DF (223)
 * Standard: HTML 2.0
 * Description: Latin small letter sharp s (German Eszett)
 */
static wchar_t* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"szlig";
static int* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with grave html character entity reference model.
 *
 * Name: agrave
 * Character: �
 * Unicode code point: U+00E0 (224)
 * Standard: HTML 2.0
 * Description: Latin small letter a with grave
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"agrave";
static int* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with acute html character entity reference model.
 *
 * Name: aacute
 * Character: �
 * Unicode code point: U+00E1 (225)
 * Standard: HTML 2.0
 * Description: Latin small letter a with acute
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aacute";
static int* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with circumflex html character entity reference model.
 *
 * Name: acirc
 * Character: �
 * Unicode code point: U+00E2 (226)
 * Standard: HTML 2.0
 * Description: Latin small letter a with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acirc";
static int* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with tilde html character entity reference model.
 *
 * Name: atilde
 * Character: �
 * Unicode code point: U+00E3 (227)
 * Standard: HTML 2.0
 * Description: Latin small letter a with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"atilde";
static int* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with diaeresis html character entity reference model.
 *
 * Name: auml
 * Character: �
 * Unicode code point: U+00E4 (228)
 * Standard: HTML 2.0
 * Description: Latin small letter a with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"auml";
static int* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter a with ring above html character entity reference model.
 *
 * Name: aring
 * Character: �
 * Unicode code point: U+00E5 (229)
 * Standard: HTML 2.0
 * Description: Latin small letter a with ring above
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aring";
static int* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin lowercase ligature ae html character entity reference model.
 *
 * Name: aelig
 * Character: �
 * Unicode code point: U+00E6 (230)
 * Standard: HTML 2.0
 * Description: Latin lowercase ligature ae
 */
static wchar_t* LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aelig";
static int* LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter c with cedilla html character entity reference model.
 *
 * Name: ccedil
 * Character: �
 * Unicode code point: U+00E7 (231)
 * Standard: HTML 2.0
 * Description: Latin small letter c with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccedil";
static int* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter e with grave html character entity reference model.
 *
 * Name: egrave
 * Character: �
 * Unicode code point: U+00E8 (232)
 * Standard: HTML 2.0
 * Description: Latin small letter e with grave
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egrave";
static int* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter e with acute html character entity reference model.
 *
 * Name: eacute
 * Character: �
 * Unicode code point: U+00E9 (233)
 * Standard: HTML 2.0
 * Description: Latin small letter e with acute
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eacute";
static int* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter e with circumflex html character entity reference model.
 *
 * Name: ecirc
 * Character: �
 * Unicode code point: U+00EA (234)
 * Standard: HTML 2.0
 * Description: Latin small letter e with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecirc";
static int* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter e with diaeresis html character entity reference model.
 *
 * Name: euml
 * Character: �
 * Unicode code point: U+00EB (235)
 * Standard: HTML 2.0
 * Description: Latin small letter e with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euml";
static int* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter i with grave html character entity reference model.
 *
 * Name: igrave
 * Character: �
 * Unicode code point: U+00EC (236)
 * Standard: HTML 2.0
 * Description: Latin small letter i with grave
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"igrave";
static int* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter i with acute html character entity reference model.
 *
 * Name: iacute
 * Character: �
 * Unicode code point: U+00ED (237)
 * Standard: HTML 2.0
 * Description: Latin small letter i with acute
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iacute";
static int* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter i with circumflex html character entity reference model.
 *
 * Name: icirc
 * Character: �
 * Unicode code point: U+00EE (238)
 * Standard: HTML 2.0
 * Description: Latin small letter i with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"icirc";
static int* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter i with diaeresis html character entity reference model.
 *
 * Name: iuml
 * Character: �
 * Unicode code point: U+00EF (239)
 * Standard: HTML 2.0
 * Description: Latin small letter i with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iuml";
static int* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter eth html character entity reference model.
 *
 * Name: eth
 * Character: �
 * Unicode code point: U+00F0 (240)
 * Standard: HTML 2.0
 * Description: Latin small letter eth
 */
static wchar_t* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eth";
static int* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter n with tilde html character entity reference model.
 *
 * Name: ntilde
 * Character: �
 * Unicode code point: U+00F1 (241)
 * Standard: HTML 2.0
 * Description: Latin small letter n with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntilde";
static int* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with grave html character entity reference model.
 *
 * Name: ograve
 * Character: �
 * Unicode code point: U+00F2 (242)
 * Standard: HTML 2.0
 * Description: Latin small letter o with grave
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ograve";
static int* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with acute html character entity reference model.
 *
 * Name: oacute
 * Character: �
 * Unicode code point: U+00F3 (243)
 * Standard: HTML 2.0
 * Description: Latin small letter o with acute
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oacute";
static int* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with circumflex html character entity reference model.
 *
 * Name: ocirc
 * Character: �
 * Unicode code point: U+00F4 (244)
 * Standard: HTML 2.0
 * Description: Latin small letter o with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocirc";
static int* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with tilde html character entity reference model.
 *
 * Name: otilde
 * Character: �
 * Unicode code point: U+00F5 (245)
 * Standard: HTML 2.0
 * Description: Latin small letter o with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otilde";
static int* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with diaeresis html character entity reference model.
 *
 * Name: ouml
 * Character: �
 * Unicode code point: U+00F6 (246)
 * Standard: HTML 2.0
 * Description: Latin small letter o with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ouml";
static int* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The division sign html character entity reference model.
 *
 * Name: divide
 * Character: �
 * Unicode code point: U+00F7 (247)
 * Standard: HTML 3.2
 * Description: division sign
 */
static wchar_t* DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"divide";
static int* DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter o with stroke html character entity reference model.
 *
 * Name: oslash
 * Character: �
 * Unicode code point: U+00F8 (248)
 * Standard: HTML 2.0
 * Description: Latin small letter o with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oslash";
static int* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter u with grave html character entity reference model.
 *
 * Name: ugrave
 * Character: �
 * Unicode code point: U+00F9 (249)
 * Standard: HTML 2.0
 * Description: Latin small letter u with grave
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ugrave";
static int* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter u with acute html character entity reference model.
 *
 * Name: uacute
 * Character: �
 * Unicode code point: U+00FA (250)
 * Standard: HTML 2.0
 * Description: Latin small letter u with acute
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uacute";
static int* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter u with circumflex html character entity reference model.
 *
 * Name: ucirc
 * Character: �
 * Unicode code point: U+00FB (251)
 * Standard: HTML 2.0
 * Description: Latin small letter u with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ucirc";
static int* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter u with diaeresis html character entity reference model.
 *
 * Name: uuml
 * Character: �
 * Unicode code point: U+00FC (252)
 * Standard: HTML 2.0
 * Description: Latin small letter u with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uuml";
static int* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter y with acute html character entity reference model.
 *
 * Name: yacute
 * Character: �
 * Unicode code point: U+00FD (253)
 * Standard: HTML 2.0
 * Description: Latin small letter y with acute
 */
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yacute";
static int* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter thorn html character entity reference model.
 *
 * Name: thorn
 * Character: �
 * Unicode code point: U+00FE (254)
 * Standard: HTML 2.0
 * Description: Latin small letter thorn
 */
static wchar_t* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thorn";
static int* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter y with diaeresis html character entity reference model.
 *
 * Name: yuml
 * Character: �
 * Unicode code point: U+00FF (255)
 * Standard: HTML 2.0
 * Description: Latin small letter y with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yuml";
static int* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital ligature oe html character entity reference model.
 *
 * Name: OElig
 * Character: �
 * Unicode code point: U+0152 (338)
 * Standard: HTML 4.0
 * Description: Latin capital ligature oe
 */
static wchar_t* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OElig";
static int* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small ligature oe html character entity reference model.
 *
 * Name: oelig
 * Character: �
 * Unicode code point: U+0153 (339)
 * Standard: HTML 4.0
 * Description: Latin small ligature oe
 */
static wchar_t* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oelig";
static int* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter s with caron html character entity reference model.
 *
 * Name: Scaron
 * Character: �
 * Unicode code point: U+0160 (352)
 * Standard: HTML 4.0
 * Description: Latin capital letter s with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scaron";
static int* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter s with caron html character entity reference model.
 *
 * Name: scaron
 * Character: �
 * Unicode code point: U+0161 (353)
 * Standard: HTML 4.0
 * Description: Latin small letter s with caron
 */
static wchar_t* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scaron";
static int* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin capital letter y with diaeresis html character entity reference model.
 *
 * Name: Yuml
 * Character: �
 * Unicode code point: U+0178 (376)
 * Standard: HTML 4.0
 * Description: Latin capital letter y with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yuml";
static int* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Latin small letter f with hook html character entity reference model.
 *
 * Name: fnof
 * Character: �
 * Unicode code point: U+0192 (402)
 * Standard: HTML 4.0
 * Description: Latin small letter f with hook
 */
static wchar_t* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fnof";
static int* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modifier letter circumflex accent html character entity reference model.
 *
 * Name: circ
 * Character: �
 * Unicode code point: U+02C6 (710)
 * Standard: HTML 4.0
 * Description: modifier letter circumflex accent
 */
static wchar_t* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circ";
static int* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small tilde html character entity reference model.
 *
 * Name: tilde
 * Character: �
 * Unicode code point: U+02DC (732)
 * Standard: HTML 4.0
 * Description: small tilde
 */
static wchar_t* SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tilde";
static int* SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter alpha html character entity reference model.
 *
 * Name: Alpha
 * Character: ?
 * Unicode code point: U+0391 (913)
 * Standard: HTML 4.0
 * Description: Greek capital letter alpha
 */
static wchar_t* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Alpha";
static int* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter beta html character entity reference model.
 *
 * Name: Beta
 * Character: ?
 * Unicode code point: U+0392 (914)
 * Standard: HTML 4.0
 * Description: Greek capital letter beta
 */
static wchar_t* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Beta";
static int* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter gamma html character entity reference model.
 *
 * Name: Gamma
 * Character: G
 * Unicode code point: U+0393 (915)
 * Standard: HTML 4.0
 * Description: Greek capital letter gamma
 */
static wchar_t* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gamma";
static int* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter delta html character entity reference model.
 *
 * Name: Delta
 * Character: ?
 * Unicode code point: U+0394 (916)
 * Standard: HTML 4.0
 * Description: Greek capital letter delta
 */
static wchar_t* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Delta";
static int* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter epsilon html character entity reference model.
 *
 * Name: Epsilon
 * Character: ?
 * Unicode code point: U+0395 (917)
 * Standard: HTML 4.0
 * Description: Greek capital letter epsilon
 */
static wchar_t* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Epsilon";
static int* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter zeta html character entity reference model.
 *
 * Name: Zeta
 * Character: ?
 * Unicode code point: U+0396 (918)
 * Standard: HTML 4.0
 * Description: Greek capital letter zeta
 */
static wchar_t* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zeta";
static int* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter eta html character entity reference model.
 *
 * Name: Eta
 * Character: ?
 * Unicode code point: U+0397 (919)
 * Standard: HTML 4.0
 * Description: Greek capital letter eta
 */
static wchar_t* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eta";
static int* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter theta html character entity reference model.
 *
 * Name: Theta
 * Character: T
 * Unicode code point: U+0398 (920)
 * Standard: HTML 4.0
 * Description: Greek capital letter theta
 */
static wchar_t* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Theta";
static int* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter iota html character entity reference model.
 *
 * Name: Iota
 * Character: ?
 * Unicode code point: U+0399 (921)
 * Standard: HTML 4.0
 * Description: Greek capital letter iota
 */
static wchar_t* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iota";
static int* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter kappa html character entity reference model.
 *
 * Name: Kappa
 * Character: ?
 * Unicode code point: U+039A (922)
 * Standard: HTML 4.0
 * Description: Greek capital letter kappa
 */
static wchar_t* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kappa";
static int* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter lambda html character entity reference model.
 *
 * Name: Lambda
 * Character: ?
 * Unicode code point: U+039B (923)
 * Standard: HTML 4.0
 * Description: Greek capital letter lambda
 */
static wchar_t* GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lambda";
static int* GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter mu html character entity reference model.
 *
 * Name: Mu
 * Character: ?
 * Unicode code point: U+039C (924)
 * Standard: HTML 4.0
 * Description: Greek capital letter mu
 */
static wchar_t* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mu";
static int* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter nu html character entity reference model.
 *
 * Name: Nu
 * Character: ?
 * Unicode code point: U+039D (925)
 * Standard: HTML 4.0
 * Description: Greek capital letter nu
 */
static wchar_t* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nu";
static int* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter xi html character entity reference model.
 *
 * Name: Xi
 * Character: ?
 * Unicode code point: U+039E (926)
 * Standard: HTML 4.0
 * Description: Greek capital letter xi
 */
static wchar_t* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xi";
static int* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter omicron html character entity reference model.
 *
 * Name: Omicron
 * Character: ?
 * Unicode code point: U+039F (927)
 * Standard: HTML 4.0
 * Description: Greek capital letter omicron
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omicron";
static int* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter pi html character entity reference model.
 *
 * Name: Pi
 * Character: ?
 * Unicode code point: U+03A0 (928)
 * Standard: HTML 4.0
 * Description: Greek capital letter pi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pi";
static int* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter rho html character entity reference model.
 *
 * Name: Rho
 * Character: ?
 * Unicode code point: U+03A1 (929)
 * Standard: HTML 4.0
 * Description: Greek capital letter rho
 */
static wchar_t* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rho";
static int* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter sigma html character entity reference model.
 *
 * Name: Sigma
 * Character: S
 * Unicode code point: U+03A3 (931)
 * Standard: HTML 4.0
 * Description: Greek capital letter sigma
 */
static wchar_t* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sigma";
static int* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter tau html character entity reference model.
 *
 * Name: Tau
 * Character: ?
 * Unicode code point: U+03A4 (932)
 * Standard: HTML 4.0
 * Description: Greek capital letter tau
 */
static wchar_t* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tau";
static int* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter upsilon html character entity reference model.
 *
 * Name: Upsilon
 * Character: ?
 * Unicode code point: U+03A5 (933)
 * Standard: HTML 4.0
 * Description: Greek capital letter upsilon
 */
static wchar_t* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Upsilon";
static int* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter phi html character entity reference model.
 *
 * Name: Phi
 * Character: F
 * Unicode code point: U+03A6 (934)
 * Standard: HTML 4.0
 * Description: Greek capital letter phi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Phi";
static int* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter chi html character entity reference model.
 *
 * Name: Chi
 * Character: ?
 * Unicode code point: U+03A7 (935)
 * Standard: HTML 4.0
 * Description: Greek capital letter chi
 */
static wchar_t* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Chi";
static int* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter psi html character entity reference model.
 *
 * Name: Psi
 * Character: ?
 * Unicode code point: U+03A8 (936)
 * Standard: HTML 4.0
 * Description: Greek capital letter psi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Psi";
static int* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek capital letter omega html character entity reference model.
 *
 * Name: Omega
 * Character: O
 * Unicode code point: U+03A9 (937)
 * Standard: HTML 4.0
 * Description: Greek capital letter omega
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omega";
static int* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter alpha html character entity reference model.
 *
 * Name: alpha
 * Character: a
 * Unicode code point: U+03B1 (945)
 * Standard: HTML 4.0
 * Description: Greek small letter alpha
 */
static wchar_t* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"alpha";
static int* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter beta html character entity reference model.
 *
 * Name: beta
 * Character: �
 * Unicode code point: U+03B2 (946)
 * Standard: HTML 4.0
 * Description: Greek small letter beta
 */
static wchar_t* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"beta";
static int* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter gamma html character entity reference model.
 *
 * Name: gamma
 * Character: ?
 * Unicode code point: U+03B3 (947)
 * Standard: HTML 4.0
 * Description: Greek small letter gamma
 */
static wchar_t* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gamma";
static int* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter delta html character entity reference model.
 *
 * Name: delta
 * Character: d
 * Unicode code point: U+03B4 (948)
 * Standard: HTML 4.0
 * Description: Greek small letter delta
 */
static wchar_t* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"delta";
static int* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter epsilon html character entity reference model.
 *
 * Name: epsilon
 * Character: e
 * Unicode code point: U+03B5 (949)
 * Standard: HTML 4.0
 * Description: Greek small letter epsilon
 */
static wchar_t* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epsilon";
static int* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter zeta html character entity reference model.
 *
 * Name: zeta
 * Character: ?
 * Unicode code point: U+03B6 (950)
 * Standard: HTML 4.0
 * Description: Greek small letter zeta
 */
static wchar_t* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zeta";
static int* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter eta html character entity reference model.
 *
 * Name: eta
 * Character: ?
 * Unicode code point: U+03B7 (951)
 * Standard: HTML 4.0
 * Description: Greek small letter eta
 */
static wchar_t* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eta";
static int* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter theta html character entity reference model.
 *
 * Name: theta
 * Character: ?
 * Unicode code point: U+03B8 (952)
 * Standard: HTML 4.0
 * Description: Greek small letter theta
 */
static wchar_t* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"theta";
static int* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter iota html character entity reference model.
 *
 * Name: iota
 * Character: ?
 * Unicode code point: U+03B9 (953)
 * Standard: HTML 4.0
 * Description: Greek small letter iota
 */
static wchar_t* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iota";
static int* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter kappa html character entity reference model.
 *
 * Name: kappa
 * Character: ?
 * Unicode code point: U+03BA (954)
 * Standard: HTML 4.0
 * Description: Greek small letter kappa
 */
static wchar_t* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kappa";
static int* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter lambda html character entity reference model.
 *
 * Name: lambda
 * Character: ?
 * Unicode code point: U+03BB (955)
 * Standard: HTML 4.0
 * Description: Greek small letter lambda
 */
static wchar_t* GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lambda";
static int* GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter mu html character entity reference model.
 *
 * Name: mu
 * Character: �
 * Unicode code point: U+03BC (956)
 * Standard: HTML 4.0
 * Description: Greek small letter mu
 */
static wchar_t* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mu";
static int* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter nu html character entity reference model.
 *
 * Name: nu
 * Character: ?
 * Unicode code point: U+03BD (957)
 * Standard: HTML 4.0
 * Description: Greek small letter nu
 */
static wchar_t* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nu";
static int* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter xi html character entity reference model.
 *
 * Name: xi
 * Character: ?
 * Unicode code point: U+03BE (958)
 * Standard: HTML 4.0
 * Description: Greek small letter xi
 */
static wchar_t* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xi";
static int* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter omicron html character entity reference model.
 *
 * Name: omicron
 * Character: ?
 * Unicode code point: U+03BF (959)
 * Standard: HTML 4.0
 * Description: Greek small letter omicron
 */
static wchar_t* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omicron";
static int* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter pi html character entity reference model.
 *
 * Name: pi
 * Character: p
 * Unicode code point: U+03C0 (960)
 * Standard: HTML 4.0
 * Description: Greek small letter pi
 */
static wchar_t* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pi";
static int* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter rho html character entity reference model.
 *
 * Name: rho
 * Character: ?
 * Unicode code point: U+03C1 (961)
 * Standard: HTML 4.0
 * Description: Greek small letter rho
 */
static wchar_t* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rho";
static int* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter final sigma html character entity reference model.
 *
 * Name: sigmaf
 * Character: ?
 * Unicode code point: U+03C2 (962)
 * Standard: HTML 4.0
 * Description: Greek small letter final sigma
 */
static wchar_t* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sigmaf";
static int* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter sigma html character entity reference model.
 *
 * Name: sigma
 * Character: s
 * Unicode code point: U+03C3 (963)
 * Standard: HTML 4.0
 * Description: Greek small letter sigma
 */
static wchar_t* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sigma";
static int* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter tau html character entity reference model.
 *
 * Name: tau
 * Character: t
 * Unicode code point: U+03C4 (964)
 * Standard: HTML 4.0
 * Description: Greek small letter tau
 */
static wchar_t* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tau";
static int* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter upsilon html character entity reference model.
 *
 * Name: upsilon
 * Character: ?
 * Unicode code point: U+03C5 (965)
 * Standard: HTML 4.0
 * Description: Greek small letter upsilon
 */
static wchar_t* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upsilon";
static int* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter phi html character entity reference model.
 *
 * Name: phi
 * Character: f
 * Unicode code point: U+03C6 (966)
 * Standard: HTML 4.0
 * Description: Greek small letter phi
 */
static wchar_t* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phi";
static int* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter chi html character entity reference model.
 *
 * Name: chi
 * Character: ?
 * Unicode code point: U+03C7 (967)
 * Standard: HTML 4.0
 * Description: Greek small letter chi
 */
static wchar_t* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"chi";
static int* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter psi html character entity reference model.
 *
 * Name: psi
 * Character: ?
 * Unicode code point: U+03C8 (968)
 * Standard: HTML 4.0
 * Description: Greek small letter psi
 */
static wchar_t* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"psi";
static int* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek small letter omega html character entity reference model.
 *
 * Name: omega
 * Character: ?
 * Unicode code point: U+03C9 (969)
 * Standard: HTML 4.0
 * Description: Greek small letter omega
 */
static wchar_t* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omega";
static int* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek theta symbol html character entity reference model.
 *
 * Name: thetasym
 * Character: ?
 * Unicode code point: U+03D1 (977)
 * Standard: HTML 4.0
 * Description: Greek theta symbol
 */
static wchar_t* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thetasym";
static int* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek upsilon with hook symbol html character entity reference model.
 *
 * Name: upsih
 * Character: ?
 * Unicode code point: U+03D2 (978)
 * Standard: HTML 4.0
 * Description: Greek upsilon with hook symbol
 */
static wchar_t* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upsih";
static int* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Greek pi symbol html character entity reference model.
 *
 * Name: piv
 * Character: ?
 * Unicode code point: U+03D6 (982)
 * Standard: HTML 4.0
 * Description: Greek pi symbol
 */
static wchar_t* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"piv";
static int* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The en space [1] html character entity reference model.
 *
 * Name: ensp
 * Character:
 * Unicode code point: U+2002 (8194)
 * Standard: HTML 4.0
 * Description: en space [1]
 */
static wchar_t* EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ensp";
static int* EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The em space [2] html character entity reference model.
 *
 * Name: emsp
 * Character:
 * Unicode code point: U+2003 (8195)
 * Standard: HTML 4.0
 * Description: em space [2]
 */
static wchar_t* EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp";
static int* EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thin space [3] html character entity reference model.
 *
 * Name: thinsp
 * Character: ?
 * Unicode code point: U+2009 (8201)
 * Standard: HTML 4.0
 * Description: thin space [3]
 */
static wchar_t* THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thinsp";
static int* THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zero width non-joiner html character entity reference model.
 *
 * Name: zwnj
 * Character: ?
 * Unicode code point: U+200C (8204)
 * Standard: HTML 4.0
 * Description: zero width non-joiner
 */
static wchar_t* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwnj";
static int* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zero width joiner html character entity reference model.
 *
 * Name: zwj
 * Character: ?
 * Unicode code point: U+200D (8205)
 * Standard: HTML 4.0
 * Description: zero width joiner
 */
static wchar_t* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwj";
static int* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-to-right mark html character entity reference model.
 *
 * Name: lrm
 * Character: ?
 * Unicode code point: U+200E (8206)
 * Standard: HTML 4.0
 * Description: left-to-right mark
 */
static wchar_t* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrm";
static int* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-to-left mark html character entity reference model.
 *
 * Name: rlm
 * Character: ?
 * Unicode code point: U+200F (8207)
 * Standard: HTML 4.0
 * Description: right-to-left mark
 */
static wchar_t* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rlm";
static int* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The en dash html character entity reference model.
 *
 * Name: ndash
 * Character: �
 * Unicode code point: U+2013 (8211)
 * Standard: HTML 4.0
 * Description: en dash
 */
static wchar_t* EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ndash";
static int* EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The em dash html character entity reference model.
 *
 * Name: mdash
 * Character: �
 * Unicode code point: U+2014 (8212)
 * Standard: HTML 4.0
 * Description: em dash
 */
static wchar_t* EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mdash";
static int* EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left single quotation mark html character entity reference model.
 *
 * Name: lsquo
 * Character: �
 * Unicode code point: U+2018 (8216)
 * Standard: HTML 4.0
 * Description: left single quotation mark
 */
static wchar_t* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsquo";
static int* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right single quotation mark html character entity reference model.
 *
 * Name: rsquo
 * Character: �
 * Unicode code point: U+2019 (8217)
 * Standard: HTML 4.0
 * Description: right single quotation mark
 */
static wchar_t* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsquo";
static int* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single low-9 quotation mark html character entity reference model.
 *
 * Name: sbquo
 * Character: �
 * Unicode code point: U+201A (8218)
 * Standard: HTML 4.0
 * Description: single low-9 quotation mark
 */
static wchar_t* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sbquo";
static int* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left double quotation mark html character entity reference model.
 *
 * Name: ldquo
 * Character: �
 * Unicode code point: U+201C (8220)
 * Standard: HTML 4.0
 * Description: left double quotation mark
 */
static wchar_t* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldquo";
static int* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right double quotation mark html character entity reference model.
 *
 * Name: rdquo
 * Character: �
 * Unicode code point: U+201D (8221)
 * Standard: HTML 4.0
 * Description: right double quotation mark
 */
static wchar_t* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdquo";
static int* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double low-9 quotation mark html character entity reference model.
 *
 * Name: bdquo
 * Character: �
 * Unicode code point: U+201E (8222)
 * Standard: HTML 4.0
 * Description: double low-9 quotation mark
 */
static wchar_t* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bdquo";
static int* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dagger html character entity reference model.
 *
 * Name: dagger
 * Character: �
 * Unicode code point: U+2020 (8224)
 * Standard: HTML 4.0
 * Description: dagger
 */
static wchar_t* DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dagger";
static int* DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double dagger html character entity reference model.
 *
 * Name: Dagger
 * Character: �
 * Unicode code point: U+2021 (8225)
 * Standard: HTML 4.0
 * Description: double dagger
 */
static wchar_t* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dagger";
static int* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bullet html character entity reference model.
 *
 * Name: bull
 * Character: �
 * Unicode code point: U+2022 (8226)
 * Standard: HTML 4.0
 * Description: bullet
 */
static wchar_t* BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bull";
static int* BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The horizontal ellipsis html character entity reference model.
 *
 * Name: hellip
 * Character: �
 * Unicode code point: U+2026 (8230)
 * Standard: HTML 4.0
 * Description: horizontal ellipsis
 */
static wchar_t* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hellip";
static int* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The per mille sign html character entity reference model.
 *
 * Name: permil
 * Character: �
 * Unicode code point: U+2030 (8240)
 * Standard: HTML 4.0
 * Description: per mille sign
 */
static wchar_t* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"permil";
static int* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prime html character entity reference model.
 *
 * Name: prime
 * Character: '
 * Unicode code point: U+2032 (8242)
 * Standard: HTML 4.0
 * Description: prime
 */
static wchar_t* PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prime";
static int* PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double prime html character entity reference model.
 *
 * Name: Prime
 * Character: ?
 * Unicode code point: U+2033 (8243)
 * Standard: HTML 4.0
 * Description: double prime
 */
static wchar_t* DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Prime";
static int* DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single left-pointing angle quotation mark html character entity reference model.
 *
 * Name: lsaquo
 * Character: �
 * Unicode code point: U+2039 (8249)
 * Standard: HTML 4.0
 * Description: single left-pointing angle quotation mark
 */
static wchar_t* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsaquo";
static int* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single right-pointing angle quotation mark html character entity reference model.
 *
 * Name: rsaquo
 * Character: �
 * Unicode code point: U+203A (8250)
 * Standard: HTML 4.0
 * Description: single right-pointing angle quotation mark
 */
static wchar_t* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsaquo";
static int* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The overline html character entity reference model.
 *
 * Name: oline
 * Character: ?
 * Unicode code point: U+203E (8254)
 * Standard: HTML 4.0
 * Description: overline
 */
static wchar_t* OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oline";
static int* OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fraction slash html character entity reference model.
 *
 * Name: frasl
 * Character: /
 * Unicode code point: U+2044 (8260)
 * Standard: HTML 4.0
 * Description: fraction slash
 */
static wchar_t* FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frasl";
static int* FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The euro sign html character entity reference model.
 *
 * Name: euro
 * Character: �
 * Unicode code point: U+20AC (8364)
 * Standard: HTML 4.0
 * Description: euro sign
 */
static wchar_t* EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euro";
static int* EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital i html character entity reference model.
 *
 * Name: image
 * Character: I
 * Unicode code point: U+2111 (8465)
 * Standard: HTML 4.0
 * Description: black-letter capital i
 */
static wchar_t* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"image";
static int* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital p (Weierstrass p)html character entity.
 *
 * Name: weierp
 * Character: P
 * Unicode code point: U+2118 (8472)
 * Standard: HTML 4.0
 * Description: script capital p (Weierstrass p)
 */
static wchar_t* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"weierp";
static int* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital r html character entity reference model.
 *
 * Name: real
 * Character: R
 * Unicode code point: U+211C (8476)
 * Standard: HTML 4.0
 * Description: black-letter capital r
 */
static wchar_t* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"real";
static int* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trademark sign html character entity reference model.
 *
 * Name: trade
 * Character: �
 * Unicode code point: U+2122 (8482)
 * Standard: HTML 4.0
 * Description: trademark sign
 */
static wchar_t* TRADEMARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trade";
static int* TRADEMARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alef symbol html character entity reference model.
 *
 * Name: alefsym
 * Character: ?
 * Unicode code point: U+2135 (8501)
 * Standard: HTML 4.0
 * Description: alef symbol
 */
static wchar_t* ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"alefsym";
static int* ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow html character entity reference model.
 *
 * Name: larr
 * Character: ?
 * Unicode code point: U+2190 (8592)
 * Standard: HTML 4.0
 * Description: leftwards arrow
 */
static wchar_t* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larr";
static int* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow html character entity reference model.
 *
 * Name: uarr
 * Character: ?
 * Unicode code point: U+2191 (8593)
 * Standard: HTML 4.0
 * Description: upwards arrow
 */
static wchar_t* UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uarr";
static int* UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow html character entity reference model.
 *
 * Name: rarr
 * Character: ?
 * Unicode code point: U+2192 (8594)
 * Standard: HTML 4.0
 * Description: rightwards arrow
 */
static wchar_t* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarr";
static int* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow html character entity reference model.
 *
 * Name: darr
 * Character: ?
 * Unicode code point: U+2193 (8595)
 * Standard: HTML 4.0
 * Description: downwards arrow
 */
static wchar_t* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"darr";
static int* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right arrow html character entity reference model.
 *
 * Name: harr
 * Character: ?
 * Unicode code point: U+2194 (8596)
 * Standard: HTML 4.0
 * Description: left right arrow
 */
static wchar_t* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harr";
static int* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow with corner leftwards html character entity reference model.
 *
 * Name: crarr
 * Character: ?
 * Unicode code point: U+21B5 (8629)
 * Standard: HTML 4.0
 * Description: downwards arrow with corner leftwards
 */
static wchar_t* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"crarr";
static int* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double arrow html character entity reference model.
 *
 * Name: lArr
 * Character: ?
 * Unicode code point: U+21D0 (8656)
 * Standard: HTML 4.0
 * Description: leftwards double arrow
 */
static wchar_t* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lArr";
static int* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards double arrow html character entity reference model.
 *
 * Name: uArr
 * Character: ?
 * Unicode code point: U+21D1 (8657)
 * Standard: HTML 4.0
 * Description: upwards double arrow
 */
static wchar_t* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uArr";
static int* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double arrow html character entity reference model.
 *
 * Name: rArr
 * Character: ?
 * Unicode code point: U+21D2 (8658)
 * Standard: HTML 4.0
 * Description: rightwards double arrow
 */
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rArr";
static int* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards double arrow html character entity reference model.
 *
 * Name: dArr
 * Character: ?
 * Unicode code point: U+21D3 (8659)
 * Standard: HTML 4.0
 * Description: downwards double arrow
 */
static wchar_t* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dArr";
static int* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right double arrow html character entity reference model.
 *
 * Name: hArr
 * Character: ?
 * Unicode code point: U+21D4 (8660)
 * Standard: HTML 4.0
 * Description: left right double arrow
 */
static wchar_t* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hArr";
static int* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The for all html character entity reference model.
 *
 * Name: forall
 * Character: ?
 * Unicode code point: U+2200 (8704)
 * Standard: HTML 4.0
 * Description: for all
 */
static wchar_t* FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"forall";
static int* FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The partial differential html character entity reference model.
 *
 * Name: part
 * Character: ?
 * Unicode code point: U+2202 (8706)
 * Standard: HTML 4.0
 * Description: partial differential
 */
static wchar_t* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"part";
static int* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The there exists html character entity reference model.
 *
 * Name: exist
 * Character: ?
 * Unicode code point: U+2203 (8707)
 * Standard: HTML 4.0
 * Description: there exists
 */
static wchar_t* THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"exist";
static int* THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set html character entity reference model.
 *
 * Name: empty
 * Character: �
 * Unicode code point: U+2205 (8709)
 * Standard: HTML 4.0
 * Description: empty set
 */
static wchar_t* EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"empty";
static int* EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nabla html character entity reference model.
 *
 * Name: nabla
 * Character: ?
 * Unicode code point: U+2207 (8711)
 * Standard: HTML 4.0
 * Description: nabla
 */
static wchar_t* NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nabla";
static int* NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of html character entity reference model.
 *
 * Name: isin
 * Character: ?
 * Unicode code point: U+2208 (8712)
 * Standard: HTML 4.0
 * Description: element of
 */
static wchar_t* ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isin";
static int* ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not an element of html character entity reference model.
 *
 * Name: notin
 * Character: ?
 * Unicode code point: U+2209 (8713)
 * Standard: HTML 4.0
 * Description: not an element of
 */
static wchar_t* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notin";
static int* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains as member html character entity reference model.
 *
 * Name: ni
 * Character: ?
 * Unicode code point: U+220B (8715)
 * Standard: HTML 4.0
 * Description: contains as member
 */
static wchar_t* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ni";
static int* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary product html character entity reference model.
 *
 * Name: prod
 * Character: ?
 * Unicode code point: U+220F (8719)
 * Standard: HTML 4.0
 * Description: n-ary product
 */
static wchar_t* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prod";
static int* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary summation html character entity reference model.
 *
 * Name: sum
 * Character: ?
 * Unicode code point: U+2211 (8721)
 * Standard: HTML 4.0
 * Description: n-ary summation
 */
static wchar_t* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sum";
static int* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus sign html character entity reference model.
 *
 * Name: minus
 * Character: -
 * Unicode code point: U+2212 (8722)
 * Standard: HTML 4.0
 * Description: minus sign
 */
static wchar_t* MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minus";
static int* MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asterisk operator html character entity reference model.
 *
 * Name: lowast
 * Character: *
 * Unicode code point: U+2217 (8727)
 * Standard: HTML 4.0
 * Description: asterisk operator
 */
static wchar_t* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lowast";
static int* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square root html character entity reference model.
 *
 * Name: radic
 * Character: v
 * Unicode code point: U+221A (8730)
 * Standard: HTML 4.0
 * Description: square root
 */
static wchar_t* SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"radic";
static int* SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The proportional to html character entity reference model.
 *
 * Name: prop
 * Character: ?
 * Unicode code point: U+221D (8733)
 * Standard: HTML 4.0
 * Description: proportional to
 */
static wchar_t* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prop";
static int* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The infinity html character entity reference model.
 *
 * Name: infin
 * Character: 8
 * Unicode code point: U+221E (8734)
 * Standard: HTML 4.0
 * Description: infinity
 */
static wchar_t* INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"infin";
static int* INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angle html character entity reference model.
 *
 * Name: ang
 * Character: ?
 * Unicode code point: U+2220 (8736)
 * Standard: HTML 4.0
 * Description: angle
 */
static wchar_t* ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ang";
static int* ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical and html character entity reference model.
 *
 * Name: and
 * Character: ?
 * Unicode code point: U+2227 (8743)
 * Standard: HTML 4.0
 * Description: logical and
 */
static wchar_t* LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"and";
static int* LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical or html character entity reference model.
 *
 * Name: or
 * Character: ?
 * Unicode code point: U+2228 (8744)
 * Standard: HTML 4.0
 * Description: logical or
 */
static wchar_t* LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"or";
static int* LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection html character entity reference model.
 *
 * Name: cap
 * Character: n
 * Unicode code point: U+2229 (8745)
 * Standard: HTML 4.0
 * Description: intersection
 */
static wchar_t* INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cap";
static int* INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union html character entity reference model.
 *
 * Name: cup
 * Character: ?
 * Unicode code point: U+222A (8746)
 * Standard: HTML 4.0
 * Description: union
 */
static wchar_t* UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cup";
static int* UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The integral html character entity reference model.
 *
 * Name: int
 * Character: ?
 * Unicode code point: U+222B (8747)
 * Standard: HTML 4.0
 * Description: integral
 */
static wchar_t* INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"int";
static int* INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The therefore html character entity reference model.
 *
 * Name: there4
 * Character: ?
 * Unicode code point: U+2234 (8756)
 * Standard: HTML 4.0
 * Description: therefore
 */
static wchar_t* THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"there4";
static int* THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde operator html character entity reference model.
 *
 * Name: sim
 * Character: ~
 * Unicode code point: U+223C (8764)
 * Standard: HTML 4.0
 * Description: tilde operator
 */
static wchar_t* TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sim";
static int* TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The congruent to html character entity reference model.
 *
 * Name: cong
 * Character: ?
 * Unicode code point: U+2245 (8773)
 * Standard: HTML 4.0
 * Description: congruent to
 */
static wchar_t* CONGRUENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cong";
static int* CONGRUENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The almost equal to html character entity reference model.
 *
 * Name: asymp
 * Character: �
 * Unicode code point: U+2248 (8776)
 * Standard: HTML 4.0
 * Description: almost equal to
 */
static wchar_t* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"asymp";
static int* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not equal to html character entity reference model.
 *
 * Name: ne
 * Character: ?
 * Unicode code point: U+2260 (8800)
 * Standard: HTML 4.0
 * Description: not equal to
 */
static wchar_t* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ne";
static int* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identical to (equivalent to)html character entity.
 *
 * Name: equiv
 * Character: =
 * Unicode code point: U+2261 (8801)
 * Standard: HTML 4.0
 * Description: identical to (equivalent to)
 */
static wchar_t* IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equiv";
static int* IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or equal to html character entity reference model.
 *
 * Name: le
 * Character: =
 * Unicode code point: U+2264 (8804)
 * Standard: HTML 4.0
 * Description: less-than or equal to
 */
static wchar_t* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"le";
static int* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or equal to html character entity reference model.
 *
 * Name: ge
 * Character: =
 * Unicode code point: U+2265 (8805)
 * Standard: HTML 4.0
 * Description: greater-than or equal to
 */
static wchar_t* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ge";
static int* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of html character entity reference model.
 *
 * Name: sub
 * Character: ?
 * Unicode code point: U+2282 (8834)
 * Standard: HTML 4.0
 * Description: subset of
 */
static wchar_t* SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sub";
static int* SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of html character entity reference model.
 *
 * Name: sup
 * Character: ?
 * Unicode code point: U+2283 (8835)
 * Standard: HTML 4.0
 * Description: superset of
 */
static wchar_t* SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup";
static int* SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not a subset of html character entity reference model.
 *
 * Name: nsub
 * Character: ?
 * Unicode code point: U+2284 (8836)
 * Standard: HTML 4.0
 * Description: not a subset of
 */
static wchar_t* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsub";
static int* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of or equal to html character entity reference model.
 *
 * Name: sube
 * Character: ?
 * Unicode code point: U+2286 (8838)
 * Standard: HTML 4.0
 * Description: subset of or equal to
 */
static wchar_t* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sube";
static int* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of or equal to html character entity reference model.
 *
 * Name: supe
 * Character: ?
 * Unicode code point: U+2287 (8839)
 * Standard: HTML 4.0
 * Description: superset of or equal to
 */
static wchar_t* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supe";
static int* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled plus html character entity reference model.
 *
 * Name: oplus
 * Character: ?
 * Unicode code point: U+2295 (8853)
 * Standard: HTML 4.0
 * Description: circled plus
 */
static wchar_t* CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oplus";
static int* CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled times html character entity reference model.
 *
 * Name: otimes
 * Character: ?
 * Unicode code point: U+2297 (8855)
 * Standard: HTML 4.0
 * Description: circled times
 */
static wchar_t* CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otimes";
static int* CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up tack (perpendicular sign in math)html character entity.
 *
 * Name: perp
 * Character: ?
 * Unicode code point: U+22A5 (8869)
 * Standard: HTML 4.0
 * Description: up tack (perpendicular sign in math)
 */
static wchar_t* UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"perp";
static int* UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot operator html character entity reference model.
 *
 * Name: sdot
 * Character: �
 * Unicode code point: U+22C5 (8901)
 * Standard: HTML 4.0
 * Description: dot operator
 */
static wchar_t* DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdot";
static int* DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left ceiling html character entity reference model.
 *
 * Name: lceil
 * Character: ?
 * Unicode code point: U+2308 (8968)
 * Standard: HTML 4.0
 * Description: left ceiling
 */
static wchar_t* LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lceil";
static int* LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right ceiling html character entity reference model.
 *
 * Name: rceil
 * Character: ?
 * Unicode code point: U+2309 (8969)
 * Standard: HTML 4.0
 * Description: right ceiling
 */
static wchar_t* RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rceil";
static int* RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left floor html character entity reference model.
 *
 * Name: lfloor
 * Character: ?
 * Unicode code point: U+230A (8970)
 * Standard: HTML 4.0
 * Description: left floor
 */
static wchar_t* LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfloor";
static int* LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right floor html character entity reference model.
 *
 * Name: rfloor
 * Character: ?
 * Unicode code point: U+230B (8971)
 * Standard: HTML 4.0
 * Description: right floor
 */
static wchar_t* RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfloor";
static int* RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-pointing angle bracket html character entity reference model.
 *
 * Name: lang
 * Character: <
 * Unicode code point: U+2329 (9001)
 * Standard: HTML 4.0
 * Description: left-pointing angle bracket
 */
static wchar_t* LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lang";
static int* LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-pointing angle bracket html character entity reference model.
 *
 * Name: rang
 * Character: >
 * Unicode code point: U+232A (9002)
 * Standard: HTML 4.0
 * Description: right-pointing angle bracket
 */
static wchar_t* RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rang";
static int* RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lozenge html character entity reference model.
 *
 * Name: loz
 * Character: ?
 * Unicode code point: U+25CA (9674)
 * Standard: HTML 4.0
 * Description: lozenge
 */
static wchar_t* LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loz";
static int* LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black spade suit html character entity reference model.
 *
 * Name: spades
 * Character: ?
 * Unicode code point: U+2660 (9824)
 * Standard: HTML 4.0
 * Description: black spade suit
 */
static wchar_t* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"spades";
static int* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black club suit html character entity reference model.
 *
 * Name: clubs
 * Character: ?
 * Unicode code point: U+2663 (9827)
 * Standard: HTML 4.0
 * Description: black club suit
 */
static wchar_t* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"clubs";
static int* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black heart suit html character entity reference model.
 *
 * Name: hearts
 * Character: ?
 * Unicode code point: U+2665 (9829)
 * Standard: HTML 4.0
 * Description: black heart suit
 */
static wchar_t* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hearts";
static int* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black diamond suit html character entity reference model.
 *
 * Name: diams
 * Character: ?
 * Unicode code point: U+2666 (9830)
 * Standard: HTML 4.0
 * Description: black diamond suit
 */
static wchar_t* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diams";
static int* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_SOURCE */
#endif
