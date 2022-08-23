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
// https://de.wikipedia.org/wiki/Entit%C3%A4t_(Auszeichnungssprache)
//
// XML (2010)
//
// 2007–2010 wurden alle gebräuchlichen Namen zusammengetragen und in einem Entwurf vereinigt.
// In einer DTD sind 2237 Namen auf Zeichencodierungen abgebildet:
// www.w3.org/2003/entities/2007/w3centities-f.ent
//
// Insbesondere SGML (1986) und MathML sind abgedeckt; damit ist auch HTML vollständig enthalten.
// Im Einzelfall wurde auch auf die praktikabelste Variante standardisiert,
// wo für den gleichen Zweck unterschiedliche Abbildungen auf mehrere Zeichencodes existierten.
//

/**
 * The character tabulation html character entity reference model.
 *
 * Name: Tab
 * Character: 	
 * Unicode code point: U+0009 (9)
 * Description: character tabulation
 */
static wchar_t* CHARACTER_TABULATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tab";
static int* CHARACTER_TABULATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The line feed (lf) html character entity reference model.
 *
 * Name: NewLine
 * Character: 

 * Unicode code point: U+000a (10)
 * Description: line feed (lf)
 */
static wchar_t* LINE_FEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NewLine";
static int* LINE_FEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The exclamation mark html character entity reference model.
 *
 * Name: excl
 * Character: !
 * Unicode code point: U+0021 (33)
 * Description: exclamation mark
 */
static wchar_t* EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"excl";
static int* EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quotation mark html character entity reference model.
 *
 * Name: QUOT
 * Character: "
 * Unicode code point: U+0022 (34)
 * Description: quotation mark
 */
static wchar_t* QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"QUOT";
static int* QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number sign html character entity reference model.
 *
 * Name: num
 * Character: #
 * Unicode code point: U+0023 (35)
 * Description: number sign
 */
static wchar_t* NUMBER_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"num";
static int* NUMBER_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dollar sign html character entity reference model.
 *
 * Name: dollar
 * Character: $
 * Unicode code point: U+0024 (36)
 * Description: dollar sign
 */
static wchar_t* DOLLAR_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dollar";
static int* DOLLAR_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The percent sign html character entity reference model.
 *
 * Name: percnt
 * Character: %
 * Unicode code point: U+0025 (37)
 * Description: percent sign
 */
static wchar_t* PERCENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"percnt";
static int* PERCENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ampersand html character entity reference model.
 *
 * Name: AMP
 * Character: &
 * Unicode code point: U+0026 (38)
 * Description: ampersand
 */
static wchar_t* AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"AMP";
static int* AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apostrophe html character entity reference model.
 *
 * Name: apos
 * Character: '
 * Unicode code point: U+0027 (39)
 * Description: apostrophe
 */
static wchar_t* APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apos";
static int* APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left parenthesis html character entity reference model.
 *
 * Name: lpar
 * Character: (
 * Unicode code point: U+0028 (40)
 * Description: left parenthesis
 */
static wchar_t* LEFT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lpar";
static int* LEFT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right parenthesis html character entity reference model.
 *
 * Name: rpar
 * Character: )
 * Unicode code point: U+0029 (41)
 * Description: right parenthesis
 */
static wchar_t* RIGHT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rpar";
static int* RIGHT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asterisk html character entity reference model.
 *
 * Name: ast
 * Character: *
 * Unicode code point: U+002a (42)
 * Description: asterisk
 */
static wchar_t* ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ast";
static int* ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign html character entity reference model.
 *
 * Name: plus
 * Character: +
 * Unicode code point: U+002b (43)
 * Description: plus sign
 */
static wchar_t* PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plus";
static int* PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The comma html character entity reference model.
 *
 * Name: comma
 * Character: ,
 * Unicode code point: U+002c (44)
 * Description: comma
 */
static wchar_t* COMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"comma";
static int* COMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The full stop html character entity reference model.
 *
 * Name: period
 * Character: .
 * Unicode code point: U+002e (46)
 * Description: full stop
 */
static wchar_t* FULL_STOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"period";
static int* FULL_STOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The solidus html character entity reference model.
 *
 * Name: sol
 * Character: /
 * Unicode code point: U+002f (47)
 * Description: solidus
 */
static wchar_t* SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sol";
static int* SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colon html character entity reference model.
 *
 * Name: colon
 * Character: :
 * Unicode code point: U+003a (58)
 * Description: colon
 */
static wchar_t* COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"colon";
static int* COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The semicolon html character entity reference model.
 *
 * Name: semi
 * Character: ;
 * Unicode code point: U+003b (59)
 * Description: semicolon
 */
static wchar_t* SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"semi";
static int* SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than sign html character entity reference model.
 *
 * Name: LT
 * Character: <
 * Unicode code point: U+003c (60)
 * Description: less-than sign
 */
static wchar_t* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LT";
static int* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than sign with vertical line html character entity reference model.
 *
 * Name: nvlt
 * Character: <⃒
 * Unicode code point: U+003c;U+20d2 (60;8402)
 * Description: less-than sign with vertical line
 */
static wchar_t* LESS_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvlt";
static int* LESS_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign with reverse slash html character entity reference model.
 *
 * Name: bne
 * Character: =⃥
 * Unicode code point: U+003d;U+20e5 (61;8421)
 * Description: equals sign with reverse slash
 */
static wchar_t* EQUALS_SIGN_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bne";
static int* EQUALS_SIGN_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign html character entity reference model.
 *
 * Name: equals
 * Character: =
 * Unicode code point: U+003d (61)
 * Description: equals sign
 */
static wchar_t* EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equals";
static int* EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than sign html character entity reference model.
 *
 * Name: GT
 * Character: >
 * Unicode code point: U+003e (62)
 * Description: greater-than sign
 */
static wchar_t* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GT";
static int* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than sign with vertical line html character entity reference model.
 *
 * Name: nvgt
 * Character: >⃒
 * Unicode code point: U+003e;U+20d2 (62;8402)
 * Description: greater-than sign with vertical line
 */
static wchar_t* GREATER_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvgt";
static int* GREATER_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The question mark html character entity reference model.
 *
 * Name: quest
 * Character: ?
 * Unicode code point: U+003f (63)
 * Description: question mark
 */
static wchar_t* QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quest";
static int* QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The commercial at html character entity reference model.
 *
 * Name: commat
 * Character: @
 * Unicode code point: U+0040 (64)
 * Description: commercial at
 */
static wchar_t* COMMERCIAL_AT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"commat";
static int* COMMERCIAL_AT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left square bracket html character entity reference model.
 *
 * Name: lbrack
 * Character: [
 * Unicode code point: U+005b (91)
 * Description: left square bracket
 */
static wchar_t* LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrack";
static int* LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reverse solidus html character entity reference model.
 *
 * Name: bsol
 * Character: \
 * Unicode code point: U+005c (92)
 * Description: reverse solidus
 */
static wchar_t* REVERSE_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsol";
static int* REVERSE_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right square bracket html character entity reference model.
 *
 * Name: rbrack
 * Character: ]
 * Unicode code point: U+005d (93)
 * Description: right square bracket
 */
static wchar_t* RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrack";
static int* RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circumflex accent html character entity reference model.
 *
 * Name: Hat
 * Character: ^
 * Unicode code point: U+005e (94)
 * Description: circumflex accent
 */
static wchar_t* CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hat";
static int* CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The low line html character entity reference model.
 *
 * Name: UnderBar
 * Character: _
 * Unicode code point: U+005f (95)
 * Description: low line
 */
static wchar_t* LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBar";
static int* LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The grave accent html character entity reference model.
 *
 * Name: DiacriticalGrave
 * Character: `
 * Unicode code point: U+0060 (96)
 * Description: grave accent
 */
static wchar_t* GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalGrave";
static int* GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fj ligature html character entity reference model.
 *
 * Name: fjlig
 * Character: fj
 * Unicode code point: U+0066;U+006a (102;106)
 * Description: fj ligature
 */
static wchar_t* FJ_LIGATURE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fjlig";
static int* FJ_LIGATURE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left curly bracket html character entity reference model.
 *
 * Name: lbrace
 * Character: {
 * Unicode code point: U+007b (123)
 * Description: left curly bracket
 */
static wchar_t* LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrace";
static int* LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical line html character entity reference model.
 *
 * Name: VerticalLine
 * Character: |
 * Unicode code point: U+007c (124)
 * Description: vertical line
 */
static wchar_t* VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalLine";
static int* VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right curly bracket html character entity reference model.
 *
 * Name: rbrace
 * Character: }
 * Unicode code point: U+007d (125)
 * Description: right curly bracket
 */
static wchar_t* RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrace";
static int* RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The no-break space html character entity reference model.
 *
 * Name: NonBreakingSpace
 * Character:  
 * Unicode code point: U+00a0 (160)
 * Description: no-break space
 */
static wchar_t* NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NonBreakingSpace";
static int* NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted exclamation mark html character entity reference model.
 *
 * Name: iexcl
 * Character: ¡
 * Unicode code point: U+00a1 (161)
 * Description: inverted exclamation mark
 */
static wchar_t* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iexcl";
static int* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cent sign html character entity reference model.
 *
 * Name: cent
 * Character: ¢
 * Unicode code point: U+00a2 (162)
 * Description: cent sign
 */
static wchar_t* CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cent";
static int* CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pound sign html character entity reference model.
 *
 * Name: pound
 * Character: £
 * Unicode code point: U+00a3 (163)
 * Description: pound sign
 */
static wchar_t* POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pound";
static int* POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The currency sign html character entity reference model.
 *
 * Name: curren
 * Character: ¤
 * Unicode code point: U+00a4 (164)
 * Description: currency sign
 */
static wchar_t* CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curren";
static int* CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yen sign html character entity reference model.
 *
 * Name: yen
 * Character: ¥
 * Unicode code point: U+00a5 (165)
 * Description: yen sign
 */
static wchar_t* YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yen";
static int* YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The broken bar html character entity reference model.
 *
 * Name: brvbar
 * Character: ¦
 * Unicode code point: U+00a6 (166)
 * Description: broken bar
 */
static wchar_t* BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"brvbar";
static int* BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The section sign html character entity reference model.
 *
 * Name: sect
 * Character: §
 * Unicode code point: U+00a7 (167)
 * Description: section sign
 */
static wchar_t* SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sect";
static int* SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diaeresis html character entity reference model.
 *
 * Name: Dot
 * Character: ¨
 * Unicode code point: U+00a8 (168)
 * Description: diaeresis
 */
static wchar_t* DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dot";
static int* DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The copyright sign html character entity reference model.
 *
 * Name: COPY
 * Character: ©
 * Unicode code point: U+00a9 (169)
 * Description: copyright sign
 */
static wchar_t* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"COPY";
static int* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The feminine ordinal indicator html character entity reference model.
 *
 * Name: ordf
 * Character: ª
 * Unicode code point: U+00aa (170)
 * Description: feminine ordinal indicator
 */
static wchar_t* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordf";
static int* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-pointing double angle quotation mark html character entity reference model.
 *
 * Name: laquo
 * Character: «
 * Unicode code point: U+00ab (171)
 * Description: left-pointing double angle quotation mark
 */
static wchar_t* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"laquo";
static int* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not sign html character entity reference model.
 *
 * Name: not
 * Character: ¬
 * Unicode code point: U+00ac (172)
 * Description: not sign
 */
static wchar_t* NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"not";
static int* NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The soft hyphen html character entity reference model.
 *
 * Name: shy
 * Character: ­
 * Unicode code point: U+00ad (173)
 * Description: soft hyphen
 */
static wchar_t* SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shy";
static int* SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The registered sign html character entity reference model.
 *
 * Name: REG
 * Character: ®
 * Unicode code point: U+00ae (174)
 * Description: registered sign
 */
static wchar_t* REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"REG";
static int* REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The macron html character entity reference model.
 *
 * Name: macr
 * Character: ¯
 * Unicode code point: U+00af (175)
 * Description: macron
 */
static wchar_t* MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"macr";
static int* MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The degree sign html character entity reference model.
 *
 * Name: deg
 * Character: °
 * Unicode code point: U+00b0 (176)
 * Description: degree sign
 */
static wchar_t* DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"deg";
static int* DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus-minus sign html character entity reference model.
 *
 * Name: PlusMinus
 * Character: ±
 * Unicode code point: U+00b1 (177)
 * Description: plus-minus sign
 */
static wchar_t* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PlusMinus";
static int* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript two html character entity reference model.
 *
 * Name: sup2
 * Character: ²
 * Unicode code point: U+00b2 (178)
 * Description: superscript two
 */
static wchar_t* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup2";
static int* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript three html character entity reference model.
 *
 * Name: sup3
 * Character: ³
 * Unicode code point: U+00b3 (179)
 * Description: superscript three
 */
static wchar_t* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup3";
static int* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acute accent html character entity reference model.
 *
 * Name: DiacriticalAcute
 * Character: ´
 * Unicode code point: U+00b4 (180)
 * Description: acute accent
 */
static wchar_t* ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalAcute";
static int* ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The micro sign html character entity reference model.
 *
 * Name: micro
 * Character: µ
 * Unicode code point: U+00b5 (181)
 * Description: micro sign
 */
static wchar_t* MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"micro";
static int* MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pilcrow sign html character entity reference model.
 *
 * Name: para
 * Character: ¶
 * Unicode code point: U+00b6 (182)
 * Description: pilcrow sign
 */
static wchar_t* PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"para";
static int* PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The middle dot html character entity reference model.
 *
 * Name: CenterDot
 * Character: ·
 * Unicode code point: U+00b7 (183)
 * Description: middle dot
 */
static wchar_t* MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CenterDot";
static int* MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cedilla html character entity reference model.
 *
 * Name: Cedilla
 * Character: ¸
 * Unicode code point: U+00b8 (184)
 * Description: cedilla
 */
static wchar_t* CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cedilla";
static int* CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superscript one html character entity reference model.
 *
 * Name: sup1
 * Character: ¹
 * Unicode code point: U+00b9 (185)
 * Description: superscript one
 */
static wchar_t* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup1";
static int* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The masculine ordinal indicator html character entity reference model.
 *
 * Name: ordm
 * Character: º
 * Unicode code point: U+00ba (186)
 * Description: masculine ordinal indicator
 */
static wchar_t* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordm";
static int* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-pointing double angle quotation mark html character entity reference model.
 *
 * Name: raquo
 * Character: »
 * Unicode code point: U+00bb (187)
 * Description: right-pointing double angle quotation mark
 */
static wchar_t* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"raquo";
static int* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one quarter html character entity reference model.
 *
 * Name: frac14
 * Character: ¼
 * Unicode code point: U+00bc (188)
 * Description: vulgar fraction one quarter
 */
static wchar_t* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac14";
static int* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one half html character entity reference model.
 *
 * Name: frac12
 * Character: ½
 * Unicode code point: U+00bd (189)
 * Description: vulgar fraction one half
 */
static wchar_t* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac12";
static int* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction three quarters html character entity reference model.
 *
 * Name: frac34
 * Character: ¾
 * Unicode code point: U+00be (190)
 * Description: vulgar fraction three quarters
 */
static wchar_t* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac34";
static int* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted question mark html character entity reference model.
 *
 * Name: iquest
 * Character: ¿
 * Unicode code point: U+00bf (191)
 * Description: inverted question mark
 */
static wchar_t* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iquest";
static int* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with grave html character entity reference model.
 *
 * Name: Agrave
 * Character: À
 * Unicode code point: U+00c0 (192)
 * Description: latin capital letter a with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Agrave";
static int* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with acute html character entity reference model.
 *
 * Name: Aacute
 * Character: Á
 * Unicode code point: U+00c1 (193)
 * Description: latin capital letter a with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aacute";
static int* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with circumflex html character entity reference model.
 *
 * Name: Acirc
 * Character: Â
 * Unicode code point: U+00c2 (194)
 * Description: latin capital letter a with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Acirc";
static int* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with tilde html character entity reference model.
 *
 * Name: Atilde
 * Character: Ã
 * Unicode code point: U+00c3 (195)
 * Description: latin capital letter a with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Atilde";
static int* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with diaeresis html character entity reference model.
 *
 * Name: Auml
 * Character: Ä
 * Unicode code point: U+00c4 (196)
 * Description: latin capital letter a with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Auml";
static int* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with ring above html character entity reference model.
 *
 * Name: Aring
 * Character: Å
 * Unicode code point: U+00c5 (197)
 * Description: latin capital letter a with ring above
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aring";
static int* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter ae html character entity reference model.
 *
 * Name: AElig
 * Character: Æ
 * Unicode code point: U+00c6 (198)
 * Description: latin capital letter ae
 */
static wchar_t* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"AElig";
static int* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter c with cedilla html character entity reference model.
 *
 * Name: Ccedil
 * Character: Ç
 * Unicode code point: U+00c7 (199)
 * Description: latin capital letter c with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccedil";
static int* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with grave html character entity reference model.
 *
 * Name: Egrave
 * Character: È
 * Unicode code point: U+00c8 (200)
 * Description: latin capital letter e with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Egrave";
static int* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with acute html character entity reference model.
 *
 * Name: Eacute
 * Character: É
 * Unicode code point: U+00c9 (201)
 * Description: latin capital letter e with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eacute";
static int* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with circumflex html character entity reference model.
 *
 * Name: Ecirc
 * Character: Ê
 * Unicode code point: U+00ca (202)
 * Description: latin capital letter e with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecirc";
static int* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with diaeresis html character entity reference model.
 *
 * Name: Euml
 * Character: Ë
 * Unicode code point: U+00cb (203)
 * Description: latin capital letter e with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Euml";
static int* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with grave html character entity reference model.
 *
 * Name: Igrave
 * Character: Ì
 * Unicode code point: U+00cc (204)
 * Description: latin capital letter i with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Igrave";
static int* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with acute html character entity reference model.
 *
 * Name: Iacute
 * Character: Í
 * Unicode code point: U+00cd (205)
 * Description: latin capital letter i with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iacute";
static int* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with circumflex html character entity reference model.
 *
 * Name: Icirc
 * Character: Î
 * Unicode code point: U+00ce (206)
 * Description: latin capital letter i with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Icirc";
static int* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with diaeresis html character entity reference model.
 *
 * Name: Iuml
 * Character: Ï
 * Unicode code point: U+00cf (207)
 * Description: latin capital letter i with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iuml";
static int* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter eth html character entity reference model.
 *
 * Name: ETH
 * Character: Ð
 * Unicode code point: U+00d0 (208)
 * Description: latin capital letter eth
 */
static wchar_t* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ETH";
static int* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter n with tilde html character entity reference model.
 *
 * Name: Ntilde
 * Character: Ñ
 * Unicode code point: U+00d1 (209)
 * Description: latin capital letter n with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ntilde";
static int* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with grave html character entity reference model.
 *
 * Name: Ograve
 * Character: Ò
 * Unicode code point: U+00d2 (210)
 * Description: latin capital letter o with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ograve";
static int* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with acute html character entity reference model.
 *
 * Name: Oacute
 * Character: Ó
 * Unicode code point: U+00d3 (211)
 * Description: latin capital letter o with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oacute";
static int* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with circumflex html character entity reference model.
 *
 * Name: Ocirc
 * Character: Ô
 * Unicode code point: U+00d4 (212)
 * Description: latin capital letter o with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ocirc";
static int* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with tilde html character entity reference model.
 *
 * Name: Otilde
 * Character: Õ
 * Unicode code point: U+00d5 (213)
 * Description: latin capital letter o with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Otilde";
static int* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with diaeresis html character entity reference model.
 *
 * Name: Ouml
 * Character: Ö
 * Unicode code point: U+00d6 (214)
 * Description: latin capital letter o with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ouml";
static int* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign html character entity reference model.
 *
 * Name: times
 * Character: ×
 * Unicode code point: U+00d7 (215)
 * Description: multiplication sign
 */
static wchar_t* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"times";
static int* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with stroke html character entity reference model.
 *
 * Name: Oslash
 * Character: Ø
 * Unicode code point: U+00d8 (216)
 * Description: latin capital letter o with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oslash";
static int* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with grave html character entity reference model.
 *
 * Name: Ugrave
 * Character: Ù
 * Unicode code point: U+00d9 (217)
 * Description: latin capital letter u with grave
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ugrave";
static int* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with acute html character entity reference model.
 *
 * Name: Uacute
 * Character: Ú
 * Unicode code point: U+00da (218)
 * Description: latin capital letter u with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uacute";
static int* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with circumflex html character entity reference model.
 *
 * Name: Ucirc
 * Character: Û
 * Unicode code point: U+00db (219)
 * Description: latin capital letter u with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ucirc";
static int* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with diaeresis html character entity reference model.
 *
 * Name: Uuml
 * Character: Ü
 * Unicode code point: U+00dc (220)
 * Description: latin capital letter u with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uuml";
static int* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter y with acute html character entity reference model.
 *
 * Name: Yacute
 * Character: Ý
 * Unicode code point: U+00dd (221)
 * Description: latin capital letter y with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yacute";
static int* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter thorn html character entity reference model.
 *
 * Name: THORN
 * Character: Þ
 * Unicode code point: U+00de (222)
 * Description: latin capital letter thorn
 */
static wchar_t* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"THORN";
static int* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter sharp s html character entity reference model.
 *
 * Name: szlig
 * Character: ß
 * Unicode code point: U+00df (223)
 * Description: latin small letter sharp s
 */
static wchar_t* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"szlig";
static int* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with grave html character entity reference model.
 *
 * Name: agrave
 * Character: à
 * Unicode code point: U+00e0 (224)
 * Description: latin small letter a with grave
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"agrave";
static int* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with acute html character entity reference model.
 *
 * Name: aacute
 * Character: á
 * Unicode code point: U+00e1 (225)
 * Description: latin small letter a with acute
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aacute";
static int* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with circumflex html character entity reference model.
 *
 * Name: acirc
 * Character: â
 * Unicode code point: U+00e2 (226)
 * Description: latin small letter a with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acirc";
static int* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with tilde html character entity reference model.
 *
 * Name: atilde
 * Character: ã
 * Unicode code point: U+00e3 (227)
 * Description: latin small letter a with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"atilde";
static int* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with diaeresis html character entity reference model.
 *
 * Name: auml
 * Character: ä
 * Unicode code point: U+00e4 (228)
 * Description: latin small letter a with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"auml";
static int* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with ring above html character entity reference model.
 *
 * Name: aring
 * Character: å
 * Unicode code point: U+00e5 (229)
 * Description: latin small letter a with ring above
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aring";
static int* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter ae html character entity reference model.
 *
 * Name: aelig
 * Character: æ
 * Unicode code point: U+00e6 (230)
 * Description: latin small letter ae
 */
static wchar_t* LATIN_SMALL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aelig";
static int* LATIN_SMALL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter c with cedilla html character entity reference model.
 *
 * Name: ccedil
 * Character: ç
 * Unicode code point: U+00e7 (231)
 * Description: latin small letter c with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccedil";
static int* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with grave html character entity reference model.
 *
 * Name: egrave
 * Character: è
 * Unicode code point: U+00e8 (232)
 * Description: latin small letter e with grave
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egrave";
static int* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with acute html character entity reference model.
 *
 * Name: eacute
 * Character: é
 * Unicode code point: U+00e9 (233)
 * Description: latin small letter e with acute
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eacute";
static int* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with circumflex html character entity reference model.
 *
 * Name: ecirc
 * Character: ê
 * Unicode code point: U+00ea (234)
 * Description: latin small letter e with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecirc";
static int* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with diaeresis html character entity reference model.
 *
 * Name: euml
 * Character: ë
 * Unicode code point: U+00eb (235)
 * Description: latin small letter e with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euml";
static int* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with grave html character entity reference model.
 *
 * Name: igrave
 * Character: ì
 * Unicode code point: U+00ec (236)
 * Description: latin small letter i with grave
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"igrave";
static int* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with acute html character entity reference model.
 *
 * Name: iacute
 * Character: í
 * Unicode code point: U+00ed (237)
 * Description: latin small letter i with acute
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iacute";
static int* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with circumflex html character entity reference model.
 *
 * Name: icirc
 * Character: î
 * Unicode code point: U+00ee (238)
 * Description: latin small letter i with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"icirc";
static int* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with diaeresis html character entity reference model.
 *
 * Name: iuml
 * Character: ï
 * Unicode code point: U+00ef (239)
 * Description: latin small letter i with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iuml";
static int* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter eth html character entity reference model.
 *
 * Name: eth
 * Character: ð
 * Unicode code point: U+00f0 (240)
 * Description: latin small letter eth
 */
static wchar_t* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eth";
static int* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter n with tilde html character entity reference model.
 *
 * Name: ntilde
 * Character: ñ
 * Unicode code point: U+00f1 (241)
 * Description: latin small letter n with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntilde";
static int* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with grave html character entity reference model.
 *
 * Name: ograve
 * Character: ò
 * Unicode code point: U+00f2 (242)
 * Description: latin small letter o with grave
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ograve";
static int* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with acute html character entity reference model.
 *
 * Name: oacute
 * Character: ó
 * Unicode code point: U+00f3 (243)
 * Description: latin small letter o with acute
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oacute";
static int* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with circumflex html character entity reference model.
 *
 * Name: ocirc
 * Character: ô
 * Unicode code point: U+00f4 (244)
 * Description: latin small letter o with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocirc";
static int* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with tilde html character entity reference model.
 *
 * Name: otilde
 * Character: õ
 * Unicode code point: U+00f5 (245)
 * Description: latin small letter o with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otilde";
static int* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with diaeresis html character entity reference model.
 *
 * Name: ouml
 * Character: ö
 * Unicode code point: U+00f6 (246)
 * Description: latin small letter o with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ouml";
static int* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The division sign html character entity reference model.
 *
 * Name: div
 * Character: ÷
 * Unicode code point: U+00f7 (247)
 * Description: division sign
 */
static wchar_t* DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"div";
static int* DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with stroke html character entity reference model.
 *
 * Name: oslash
 * Character: ø
 * Unicode code point: U+00f8 (248)
 * Description: latin small letter o with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oslash";
static int* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with grave html character entity reference model.
 *
 * Name: ugrave
 * Character: ù
 * Unicode code point: U+00f9 (249)
 * Description: latin small letter u with grave
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ugrave";
static int* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with acute html character entity reference model.
 *
 * Name: uacute
 * Character: ú
 * Unicode code point: U+00fa (250)
 * Description: latin small letter u with acute
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uacute";
static int* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with circumflex html character entity reference model.
 *
 * Name: ucirc
 * Character: û
 * Unicode code point: U+00fb (251)
 * Description: latin small letter u with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ucirc";
static int* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with diaeresis html character entity reference model.
 *
 * Name: uuml
 * Character: ü
 * Unicode code point: U+00fc (252)
 * Description: latin small letter u with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uuml";
static int* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter y with acute html character entity reference model.
 *
 * Name: yacute
 * Character: ý
 * Unicode code point: U+00fd (253)
 * Description: latin small letter y with acute
 */
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yacute";
static int* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter thorn html character entity reference model.
 *
 * Name: thorn
 * Character: þ
 * Unicode code point: U+00fe (254)
 * Description: latin small letter thorn
 */
static wchar_t* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thorn";
static int* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter y with diaeresis html character entity reference model.
 *
 * Name: yuml
 * Character: ÿ
 * Unicode code point: U+00ff (255)
 * Description: latin small letter y with diaeresis
 */
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yuml";
static int* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with macron html character entity reference model.
 *
 * Name: Amacr
 * Character: Ā
 * Unicode code point: U+0100 (256)
 * Description: latin capital letter a with macron
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Amacr";
static int* LATIN_CAPITAL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with macron html character entity reference model.
 *
 * Name: amacr
 * Character: ā
 * Unicode code point: U+0101 (257)
 * Description: latin small letter a with macron
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amacr";
static int* LATIN_SMALL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with breve html character entity reference model.
 *
 * Name: Abreve
 * Character: Ă
 * Unicode code point: U+0102 (258)
 * Description: latin capital letter a with breve
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Abreve";
static int* LATIN_CAPITAL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with breve html character entity reference model.
 *
 * Name: abreve
 * Character: ă
 * Unicode code point: U+0103 (259)
 * Description: latin small letter a with breve
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"abreve";
static int* LATIN_SMALL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter a with ogonek html character entity reference model.
 *
 * Name: Aogon
 * Character: Ą
 * Unicode code point: U+0104 (260)
 * Description: latin capital letter a with ogonek
 */
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aogon";
static int* LATIN_CAPITAL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter a with ogonek html character entity reference model.
 *
 * Name: aogon
 * Character: ą
 * Unicode code point: U+0105 (261)
 * Description: latin small letter a with ogonek
 */
static wchar_t* LATIN_SMALL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aogon";
static int* LATIN_SMALL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter c with acute html character entity reference model.
 *
 * Name: Cacute
 * Character: Ć
 * Unicode code point: U+0106 (262)
 * Description: latin capital letter c with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cacute";
static int* LATIN_CAPITAL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter c with acute html character entity reference model.
 *
 * Name: cacute
 * Character: ć
 * Unicode code point: U+0107 (263)
 * Description: latin small letter c with acute
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cacute";
static int* LATIN_SMALL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter c with circumflex html character entity reference model.
 *
 * Name: Ccirc
 * Character: Ĉ
 * Unicode code point: U+0108 (264)
 * Description: latin capital letter c with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccirc";
static int* LATIN_CAPITAL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter c with circumflex html character entity reference model.
 *
 * Name: ccirc
 * Character: ĉ
 * Unicode code point: U+0109 (265)
 * Description: latin small letter c with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccirc";
static int* LATIN_SMALL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter c with dot above html character entity reference model.
 *
 * Name: Cdot
 * Character: Ċ
 * Unicode code point: U+010a (266)
 * Description: latin capital letter c with dot above
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cdot";
static int* LATIN_CAPITAL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter c with dot above html character entity reference model.
 *
 * Name: cdot
 * Character: ċ
 * Unicode code point: U+010b (267)
 * Description: latin small letter c with dot above
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cdot";
static int* LATIN_SMALL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter c with caron html character entity reference model.
 *
 * Name: Ccaron
 * Character: Č
 * Unicode code point: U+010c (268)
 * Description: latin capital letter c with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccaron";
static int* LATIN_CAPITAL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter c with caron html character entity reference model.
 *
 * Name: ccaron
 * Character: č
 * Unicode code point: U+010d (269)
 * Description: latin small letter c with caron
 */
static wchar_t* LATIN_SMALL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccaron";
static int* LATIN_SMALL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter d with caron html character entity reference model.
 *
 * Name: Dcaron
 * Character: Ď
 * Unicode code point: U+010e (270)
 * Description: latin capital letter d with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dcaron";
static int* LATIN_CAPITAL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter d with caron html character entity reference model.
 *
 * Name: dcaron
 * Character: ď
 * Unicode code point: U+010f (271)
 * Description: latin small letter d with caron
 */
static wchar_t* LATIN_SMALL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dcaron";
static int* LATIN_SMALL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter d with stroke html character entity reference model.
 *
 * Name: Dstrok
 * Character: Đ
 * Unicode code point: U+0110 (272)
 * Description: latin capital letter d with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dstrok";
static int* LATIN_CAPITAL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter d with stroke html character entity reference model.
 *
 * Name: dstrok
 * Character: đ
 * Unicode code point: U+0111 (273)
 * Description: latin small letter d with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dstrok";
static int* LATIN_SMALL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with macron html character entity reference model.
 *
 * Name: Emacr
 * Character: Ē
 * Unicode code point: U+0112 (274)
 * Description: latin capital letter e with macron
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Emacr";
static int* LATIN_CAPITAL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with macron html character entity reference model.
 *
 * Name: emacr
 * Character: ē
 * Unicode code point: U+0113 (275)
 * Description: latin small letter e with macron
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emacr";
static int* LATIN_SMALL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with dot above html character entity reference model.
 *
 * Name: Edot
 * Character: Ė
 * Unicode code point: U+0116 (278)
 * Description: latin capital letter e with dot above
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Edot";
static int* LATIN_CAPITAL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with dot above html character entity reference model.
 *
 * Name: edot
 * Character: ė
 * Unicode code point: U+0117 (279)
 * Description: latin small letter e with dot above
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"edot";
static int* LATIN_SMALL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with ogonek html character entity reference model.
 *
 * Name: Eogon
 * Character: Ę
 * Unicode code point: U+0118 (280)
 * Description: latin capital letter e with ogonek
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eogon";
static int* LATIN_CAPITAL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with ogonek html character entity reference model.
 *
 * Name: eogon
 * Character: ę
 * Unicode code point: U+0119 (281)
 * Description: latin small letter e with ogonek
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eogon";
static int* LATIN_SMALL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter e with caron html character entity reference model.
 *
 * Name: Ecaron
 * Character: Ě
 * Unicode code point: U+011a (282)
 * Description: latin capital letter e with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecaron";
static int* LATIN_CAPITAL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter e with caron html character entity reference model.
 *
 * Name: ecaron
 * Character: ě
 * Unicode code point: U+011b (283)
 * Description: latin small letter e with caron
 */
static wchar_t* LATIN_SMALL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecaron";
static int* LATIN_SMALL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter g with circumflex html character entity reference model.
 *
 * Name: Gcirc
 * Character: Ĝ
 * Unicode code point: U+011c (284)
 * Description: latin capital letter g with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcirc";
static int* LATIN_CAPITAL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter g with circumflex html character entity reference model.
 *
 * Name: gcirc
 * Character: ĝ
 * Unicode code point: U+011d (285)
 * Description: latin small letter g with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gcirc";
static int* LATIN_SMALL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter g with breve html character entity reference model.
 *
 * Name: Gbreve
 * Character: Ğ
 * Unicode code point: U+011e (286)
 * Description: latin capital letter g with breve
 */
static wchar_t* LATIN_CAPITAL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gbreve";
static int* LATIN_CAPITAL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter g with breve html character entity reference model.
 *
 * Name: gbreve
 * Character: ğ
 * Unicode code point: U+011f (287)
 * Description: latin small letter g with breve
 */
static wchar_t* LATIN_SMALL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gbreve";
static int* LATIN_SMALL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter g with dot above html character entity reference model.
 *
 * Name: Gdot
 * Character: Ġ
 * Unicode code point: U+0120 (288)
 * Description: latin capital letter g with dot above
 */
static wchar_t* LATIN_CAPITAL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gdot";
static int* LATIN_CAPITAL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter g with dot above html character entity reference model.
 *
 * Name: gdot
 * Character: ġ
 * Unicode code point: U+0121 (289)
 * Description: latin small letter g with dot above
 */
static wchar_t* LATIN_SMALL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gdot";
static int* LATIN_SMALL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter g with cedilla html character entity reference model.
 *
 * Name: Gcedil
 * Character: Ģ
 * Unicode code point: U+0122 (290)
 * Description: latin capital letter g with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_G_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcedil";
static int* LATIN_CAPITAL_LETTER_G_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter h with circumflex html character entity reference model.
 *
 * Name: Hcirc
 * Character: Ĥ
 * Unicode code point: U+0124 (292)
 * Description: latin capital letter h with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hcirc";
static int* LATIN_CAPITAL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter h with circumflex html character entity reference model.
 *
 * Name: hcirc
 * Character: ĥ
 * Unicode code point: U+0125 (293)
 * Description: latin small letter h with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hcirc";
static int* LATIN_SMALL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter h with stroke html character entity reference model.
 *
 * Name: Hstrok
 * Character: Ħ
 * Unicode code point: U+0126 (294)
 * Description: latin capital letter h with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hstrok";
static int* LATIN_CAPITAL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter h with stroke html character entity reference model.
 *
 * Name: hstrok
 * Character: ħ
 * Unicode code point: U+0127 (295)
 * Description: latin small letter h with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hstrok";
static int* LATIN_SMALL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with tilde html character entity reference model.
 *
 * Name: Itilde
 * Character: Ĩ
 * Unicode code point: U+0128 (296)
 * Description: latin capital letter i with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Itilde";
static int* LATIN_CAPITAL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with tilde html character entity reference model.
 *
 * Name: itilde
 * Character: ĩ
 * Unicode code point: U+0129 (297)
 * Description: latin small letter i with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"itilde";
static int* LATIN_SMALL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with macron html character entity reference model.
 *
 * Name: Imacr
 * Character: Ī
 * Unicode code point: U+012a (298)
 * Description: latin capital letter i with macron
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Imacr";
static int* LATIN_CAPITAL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with macron html character entity reference model.
 *
 * Name: imacr
 * Character: ī
 * Unicode code point: U+012b (299)
 * Description: latin small letter i with macron
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imacr";
static int* LATIN_SMALL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with ogonek html character entity reference model.
 *
 * Name: Iogon
 * Character: Į
 * Unicode code point: U+012e (302)
 * Description: latin capital letter i with ogonek
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iogon";
static int* LATIN_CAPITAL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter i with ogonek html character entity reference model.
 *
 * Name: iogon
 * Character: į
 * Unicode code point: U+012f (303)
 * Description: latin small letter i with ogonek
 */
static wchar_t* LATIN_SMALL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iogon";
static int* LATIN_SMALL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter i with dot above html character entity reference model.
 *
 * Name: Idot
 * Character: İ
 * Unicode code point: U+0130 (304)
 * Description: latin capital letter i with dot above
 */
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Idot";
static int* LATIN_CAPITAL_LETTER_I_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter dotless i html character entity reference model.
 *
 * Name: imath
 * Character: ı
 * Unicode code point: U+0131 (305)
 * Description: latin small letter dotless i
 */
static wchar_t* LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imath";
static int* LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital ligature ij html character entity reference model.
 *
 * Name: IJlig
 * Character: Ĳ
 * Unicode code point: U+0132 (306)
 * Description: latin capital ligature ij
 */
static wchar_t* LATIN_CAPITAL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IJlig";
static int* LATIN_CAPITAL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature ij html character entity reference model.
 *
 * Name: ijlig
 * Character: ĳ
 * Unicode code point: U+0133 (307)
 * Description: latin small ligature ij
 */
static wchar_t* LATIN_SMALL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ijlig";
static int* LATIN_SMALL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter j with circumflex html character entity reference model.
 *
 * Name: Jcirc
 * Character: Ĵ
 * Unicode code point: U+0134 (308)
 * Description: latin capital letter j with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jcirc";
static int* LATIN_CAPITAL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter j with circumflex html character entity reference model.
 *
 * Name: jcirc
 * Character: ĵ
 * Unicode code point: U+0135 (309)
 * Description: latin small letter j with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jcirc";
static int* LATIN_SMALL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter k with cedilla html character entity reference model.
 *
 * Name: Kcedil
 * Character: Ķ
 * Unicode code point: U+0136 (310)
 * Description: latin capital letter k with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kcedil";
static int* LATIN_CAPITAL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter k with cedilla html character entity reference model.
 *
 * Name: kcedil
 * Character: ķ
 * Unicode code point: U+0137 (311)
 * Description: latin small letter k with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kcedil";
static int* LATIN_SMALL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter kra html character entity reference model.
 *
 * Name: kgreen
 * Character: ĸ
 * Unicode code point: U+0138 (312)
 * Description: latin small letter kra
 */
static wchar_t* LATIN_SMALL_LETTER_KRA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kgreen";
static int* LATIN_SMALL_LETTER_KRA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter l with acute html character entity reference model.
 *
 * Name: Lacute
 * Character: Ĺ
 * Unicode code point: U+0139 (313)
 * Description: latin capital letter l with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lacute";
static int* LATIN_CAPITAL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter l with acute html character entity reference model.
 *
 * Name: lacute
 * Character: ĺ
 * Unicode code point: U+013a (314)
 * Description: latin small letter l with acute
 */
static wchar_t* LATIN_SMALL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lacute";
static int* LATIN_SMALL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter l with cedilla html character entity reference model.
 *
 * Name: Lcedil
 * Character: Ļ
 * Unicode code point: U+013b (315)
 * Description: latin capital letter l with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcedil";
static int* LATIN_CAPITAL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter l with cedilla html character entity reference model.
 *
 * Name: lcedil
 * Character: ļ
 * Unicode code point: U+013c (316)
 * Description: latin small letter l with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcedil";
static int* LATIN_SMALL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter l with caron html character entity reference model.
 *
 * Name: Lcaron
 * Character: Ľ
 * Unicode code point: U+013d (317)
 * Description: latin capital letter l with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcaron";
static int* LATIN_CAPITAL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter l with caron html character entity reference model.
 *
 * Name: lcaron
 * Character: ľ
 * Unicode code point: U+013e (318)
 * Description: latin small letter l with caron
 */
static wchar_t* LATIN_SMALL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcaron";
static int* LATIN_SMALL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter l with middle dot html character entity reference model.
 *
 * Name: Lmidot
 * Character: Ŀ
 * Unicode code point: U+013f (319)
 * Description: latin capital letter l with middle dot
 */
static wchar_t* LATIN_CAPITAL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lmidot";
static int* LATIN_CAPITAL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter l with middle dot html character entity reference model.
 *
 * Name: lmidot
 * Character: ŀ
 * Unicode code point: U+0140 (320)
 * Description: latin small letter l with middle dot
 */
static wchar_t* LATIN_SMALL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lmidot";
static int* LATIN_SMALL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter l with stroke html character entity reference model.
 *
 * Name: Lstrok
 * Character: Ł
 * Unicode code point: U+0141 (321)
 * Description: latin capital letter l with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lstrok";
static int* LATIN_CAPITAL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter l with stroke html character entity reference model.
 *
 * Name: lstrok
 * Character: ł
 * Unicode code point: U+0142 (322)
 * Description: latin small letter l with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lstrok";
static int* LATIN_SMALL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter n with acute html character entity reference model.
 *
 * Name: Nacute
 * Character: Ń
 * Unicode code point: U+0143 (323)
 * Description: latin capital letter n with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nacute";
static int* LATIN_CAPITAL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter n with acute html character entity reference model.
 *
 * Name: nacute
 * Character: ń
 * Unicode code point: U+0144 (324)
 * Description: latin small letter n with acute
 */
static wchar_t* LATIN_SMALL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nacute";
static int* LATIN_SMALL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter n with cedilla html character entity reference model.
 *
 * Name: Ncedil
 * Character: Ņ
 * Unicode code point: U+0145 (325)
 * Description: latin capital letter n with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncedil";
static int* LATIN_CAPITAL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter n with cedilla html character entity reference model.
 *
 * Name: ncedil
 * Character: ņ
 * Unicode code point: U+0146 (326)
 * Description: latin small letter n with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncedil";
static int* LATIN_SMALL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter n with caron html character entity reference model.
 *
 * Name: Ncaron
 * Character: Ň
 * Unicode code point: U+0147 (327)
 * Description: latin capital letter n with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncaron";
static int* LATIN_CAPITAL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter n with caron html character entity reference model.
 *
 * Name: ncaron
 * Character: ň
 * Unicode code point: U+0148 (328)
 * Description: latin small letter n with caron
 */
static wchar_t* LATIN_SMALL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncaron";
static int* LATIN_SMALL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter n preceded by apostrophe html character entity reference model.
 *
 * Name: napos
 * Character: ŉ
 * Unicode code point: U+0149 (329)
 * Description: latin small letter n preceded by apostrophe
 */
static wchar_t* LATIN_SMALL_LETTER_N_PRECEDED_BY_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napos";
static int* LATIN_SMALL_LETTER_N_PRECEDED_BY_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter eng html character entity reference model.
 *
 * Name: ENG
 * Character: Ŋ
 * Unicode code point: U+014a (330)
 * Description: latin capital letter eng
 */
static wchar_t* LATIN_CAPITAL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ENG";
static int* LATIN_CAPITAL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter eng html character entity reference model.
 *
 * Name: eng
 * Character: ŋ
 * Unicode code point: U+014b (331)
 * Description: latin small letter eng
 */
static wchar_t* LATIN_SMALL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eng";
static int* LATIN_SMALL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with macron html character entity reference model.
 *
 * Name: Omacr
 * Character: Ō
 * Unicode code point: U+014c (332)
 * Description: latin capital letter o with macron
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omacr";
static int* LATIN_CAPITAL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with macron html character entity reference model.
 *
 * Name: omacr
 * Character: ō
 * Unicode code point: U+014d (333)
 * Description: latin small letter o with macron
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omacr";
static int* LATIN_SMALL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter o with double acute html character entity reference model.
 *
 * Name: Odblac
 * Character: Ő
 * Unicode code point: U+0150 (336)
 * Description: latin capital letter o with double acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Odblac";
static int* LATIN_CAPITAL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter o with double acute html character entity reference model.
 *
 * Name: odblac
 * Character: ő
 * Unicode code point: U+0151 (337)
 * Description: latin small letter o with double acute
 */
static wchar_t* LATIN_SMALL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odblac";
static int* LATIN_SMALL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital ligature oe html character entity reference model.
 *
 * Name: OElig
 * Character: Œ
 * Unicode code point: U+0152 (338)
 * Description: latin capital ligature oe
 */
static wchar_t* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OElig";
static int* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature oe html character entity reference model.
 *
 * Name: oelig
 * Character: œ
 * Unicode code point: U+0153 (339)
 * Description: latin small ligature oe
 */
static wchar_t* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oelig";
static int* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter r with acute html character entity reference model.
 *
 * Name: Racute
 * Character: Ŕ
 * Unicode code point: U+0154 (340)
 * Description: latin capital letter r with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Racute";
static int* LATIN_CAPITAL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter r with acute html character entity reference model.
 *
 * Name: racute
 * Character: ŕ
 * Unicode code point: U+0155 (341)
 * Description: latin small letter r with acute
 */
static wchar_t* LATIN_SMALL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"racute";
static int* LATIN_SMALL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter r with cedilla html character entity reference model.
 *
 * Name: Rcedil
 * Character: Ŗ
 * Unicode code point: U+0156 (342)
 * Description: latin capital letter r with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcedil";
static int* LATIN_CAPITAL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter r with cedilla html character entity reference model.
 *
 * Name: rcedil
 * Character: ŗ
 * Unicode code point: U+0157 (343)
 * Description: latin small letter r with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcedil";
static int* LATIN_SMALL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter r with caron html character entity reference model.
 *
 * Name: Rcaron
 * Character: Ř
 * Unicode code point: U+0158 (344)
 * Description: latin capital letter r with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcaron";
static int* LATIN_CAPITAL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter r with caron html character entity reference model.
 *
 * Name: rcaron
 * Character: ř
 * Unicode code point: U+0159 (345)
 * Description: latin small letter r with caron
 */
static wchar_t* LATIN_SMALL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcaron";
static int* LATIN_SMALL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter s with acute html character entity reference model.
 *
 * Name: Sacute
 * Character: Ś
 * Unicode code point: U+015a (346)
 * Description: latin capital letter s with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sacute";
static int* LATIN_CAPITAL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter s with acute html character entity reference model.
 *
 * Name: sacute
 * Character: ś
 * Unicode code point: U+015b (347)
 * Description: latin small letter s with acute
 */
static wchar_t* LATIN_SMALL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sacute";
static int* LATIN_SMALL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter s with circumflex html character entity reference model.
 *
 * Name: Scirc
 * Character: Ŝ
 * Unicode code point: U+015c (348)
 * Description: latin capital letter s with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scirc";
static int* LATIN_CAPITAL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter s with circumflex html character entity reference model.
 *
 * Name: scirc
 * Character: ŝ
 * Unicode code point: U+015d (349)
 * Description: latin small letter s with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scirc";
static int* LATIN_SMALL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter s with cedilla html character entity reference model.
 *
 * Name: Scedil
 * Character: Ş
 * Unicode code point: U+015e (350)
 * Description: latin capital letter s with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scedil";
static int* LATIN_CAPITAL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter s with cedilla html character entity reference model.
 *
 * Name: scedil
 * Character: ş
 * Unicode code point: U+015f (351)
 * Description: latin small letter s with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scedil";
static int* LATIN_SMALL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter s with caron html character entity reference model.
 *
 * Name: Scaron
 * Character: Š
 * Unicode code point: U+0160 (352)
 * Description: latin capital letter s with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scaron";
static int* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter s with caron html character entity reference model.
 *
 * Name: scaron
 * Character: š
 * Unicode code point: U+0161 (353)
 * Description: latin small letter s with caron
 */
static wchar_t* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scaron";
static int* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter t with cedilla html character entity reference model.
 *
 * Name: Tcedil
 * Character: Ţ
 * Unicode code point: U+0162 (354)
 * Description: latin capital letter t with cedilla
 */
static wchar_t* LATIN_CAPITAL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcedil";
static int* LATIN_CAPITAL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter t with cedilla html character entity reference model.
 *
 * Name: tcedil
 * Character: ţ
 * Unicode code point: U+0163 (355)
 * Description: latin small letter t with cedilla
 */
static wchar_t* LATIN_SMALL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcedil";
static int* LATIN_SMALL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter t with caron html character entity reference model.
 *
 * Name: Tcaron
 * Character: Ť
 * Unicode code point: U+0164 (356)
 * Description: latin capital letter t with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcaron";
static int* LATIN_CAPITAL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter t with caron html character entity reference model.
 *
 * Name: tcaron
 * Character: ť
 * Unicode code point: U+0165 (357)
 * Description: latin small letter t with caron
 */
static wchar_t* LATIN_SMALL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcaron";
static int* LATIN_SMALL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter t with stroke html character entity reference model.
 *
 * Name: Tstrok
 * Character: Ŧ
 * Unicode code point: U+0166 (358)
 * Description: latin capital letter t with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tstrok";
static int* LATIN_CAPITAL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter t with stroke html character entity reference model.
 *
 * Name: tstrok
 * Character: ŧ
 * Unicode code point: U+0167 (359)
 * Description: latin small letter t with stroke
 */
static wchar_t* LATIN_SMALL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tstrok";
static int* LATIN_SMALL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with tilde html character entity reference model.
 *
 * Name: Utilde
 * Character: Ũ
 * Unicode code point: U+0168 (360)
 * Description: latin capital letter u with tilde
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Utilde";
static int* LATIN_CAPITAL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with tilde html character entity reference model.
 *
 * Name: utilde
 * Character: ũ
 * Unicode code point: U+0169 (361)
 * Description: latin small letter u with tilde
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utilde";
static int* LATIN_SMALL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with macron html character entity reference model.
 *
 * Name: Umacr
 * Character: Ū
 * Unicode code point: U+016a (362)
 * Description: latin capital letter u with macron
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Umacr";
static int* LATIN_CAPITAL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with macron html character entity reference model.
 *
 * Name: umacr
 * Character: ū
 * Unicode code point: U+016b (363)
 * Description: latin small letter u with macron
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"umacr";
static int* LATIN_SMALL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with breve html character entity reference model.
 *
 * Name: Ubreve
 * Character: Ŭ
 * Unicode code point: U+016c (364)
 * Description: latin capital letter u with breve
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ubreve";
static int* LATIN_CAPITAL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with breve html character entity reference model.
 *
 * Name: ubreve
 * Character: ŭ
 * Unicode code point: U+016d (365)
 * Description: latin small letter u with breve
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ubreve";
static int* LATIN_SMALL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with ring above html character entity reference model.
 *
 * Name: Uring
 * Character: Ů
 * Unicode code point: U+016e (366)
 * Description: latin capital letter u with ring above
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uring";
static int* LATIN_CAPITAL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with ring above html character entity reference model.
 *
 * Name: uring
 * Character: ů
 * Unicode code point: U+016f (367)
 * Description: latin small letter u with ring above
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uring";
static int* LATIN_SMALL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with double acute html character entity reference model.
 *
 * Name: Udblac
 * Character: Ű
 * Unicode code point: U+0170 (368)
 * Description: latin capital letter u with double acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Udblac";
static int* LATIN_CAPITAL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with double acute html character entity reference model.
 *
 * Name: udblac
 * Character: ű
 * Unicode code point: U+0171 (369)
 * Description: latin small letter u with double acute
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udblac";
static int* LATIN_SMALL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter u with ogonek html character entity reference model.
 *
 * Name: Uogon
 * Character: Ų
 * Unicode code point: U+0172 (370)
 * Description: latin capital letter u with ogonek
 */
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uogon";
static int* LATIN_CAPITAL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter u with ogonek html character entity reference model.
 *
 * Name: uogon
 * Character: ų
 * Unicode code point: U+0173 (371)
 * Description: latin small letter u with ogonek
 */
static wchar_t* LATIN_SMALL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uogon";
static int* LATIN_SMALL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter w with circumflex html character entity reference model.
 *
 * Name: Wcirc
 * Character: Ŵ
 * Unicode code point: U+0174 (372)
 * Description: latin capital letter w with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wcirc";
static int* LATIN_CAPITAL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter w with circumflex html character entity reference model.
 *
 * Name: wcirc
 * Character: ŵ
 * Unicode code point: U+0175 (373)
 * Description: latin small letter w with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wcirc";
static int* LATIN_SMALL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter y with circumflex html character entity reference model.
 *
 * Name: Ycirc
 * Character: Ŷ
 * Unicode code point: U+0176 (374)
 * Description: latin capital letter y with circumflex
 */
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ycirc";
static int* LATIN_CAPITAL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter y with circumflex html character entity reference model.
 *
 * Name: ycirc
 * Character: ŷ
 * Unicode code point: U+0177 (375)
 * Description: latin small letter y with circumflex
 */
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ycirc";
static int* LATIN_SMALL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter y with diaeresis html character entity reference model.
 *
 * Name: Yuml
 * Character: Ÿ
 * Unicode code point: U+0178 (376)
 * Description: latin capital letter y with diaeresis
 */
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yuml";
static int* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter z with acute html character entity reference model.
 *
 * Name: Zacute
 * Character: Ź
 * Unicode code point: U+0179 (377)
 * Description: latin capital letter z with acute
 */
static wchar_t* LATIN_CAPITAL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zacute";
static int* LATIN_CAPITAL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter z with acute html character entity reference model.
 *
 * Name: zacute
 * Character: ź
 * Unicode code point: U+017a (378)
 * Description: latin small letter z with acute
 */
static wchar_t* LATIN_SMALL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zacute";
static int* LATIN_SMALL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter z with dot above html character entity reference model.
 *
 * Name: Zdot
 * Character: Ż
 * Unicode code point: U+017b (379)
 * Description: latin capital letter z with dot above
 */
static wchar_t* LATIN_CAPITAL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zdot";
static int* LATIN_CAPITAL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter z with dot above html character entity reference model.
 *
 * Name: zdot
 * Character: ż
 * Unicode code point: U+017c (380)
 * Description: latin small letter z with dot above
 */
static wchar_t* LATIN_SMALL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zdot";
static int* LATIN_SMALL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter z with caron html character entity reference model.
 *
 * Name: Zcaron
 * Character: Ž
 * Unicode code point: U+017d (381)
 * Description: latin capital letter z with caron
 */
static wchar_t* LATIN_CAPITAL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zcaron";
static int* LATIN_CAPITAL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter z with caron html character entity reference model.
 *
 * Name: zcaron
 * Character: ž
 * Unicode code point: U+017e (382)
 * Description: latin small letter z with caron
 */
static wchar_t* LATIN_SMALL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zcaron";
static int* LATIN_SMALL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter f with hook html character entity reference model.
 *
 * Name: fnof
 * Character: ƒ
 * Unicode code point: U+0192 (402)
 * Description: latin small letter f with hook
 */
static wchar_t* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fnof";
static int* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin capital letter z with stroke html character entity reference model.
 *
 * Name: imped
 * Character: Ƶ
 * Unicode code point: U+01b5 (437)
 * Description: latin capital letter z with stroke
 */
static wchar_t* LATIN_CAPITAL_LETTER_Z_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imped";
static int* LATIN_CAPITAL_LETTER_Z_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter g with acute html character entity reference model.
 *
 * Name: gacute
 * Character: ǵ
 * Unicode code point: U+01f5 (501)
 * Description: latin small letter g with acute
 */
static wchar_t* LATIN_SMALL_LETTER_G_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gacute";
static int* LATIN_SMALL_LETTER_G_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small letter dotless j html character entity reference model.
 *
 * Name: jmath
 * Character: ȷ
 * Unicode code point: U+0237 (567)
 * Description: latin small letter dotless j
 */
static wchar_t* LATIN_SMALL_LETTER_DOTLESS_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jmath";
static int* LATIN_SMALL_LETTER_DOTLESS_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modifier letter circumflex accent html character entity reference model.
 *
 * Name: circ
 * Character: ˆ
 * Unicode code point: U+02c6 (710)
 * Description: modifier letter circumflex accent
 */
static wchar_t* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circ";
static int* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The caron html character entity reference model.
 *
 * Name: Hacek
 * Character: ˇ
 * Unicode code point: U+02c7 (711)
 * Description: caron
 */
static wchar_t* CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hacek";
static int* CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The breve html character entity reference model.
 *
 * Name: Breve
 * Character: ˘
 * Unicode code point: U+02d8 (728)
 * Description: breve
 */
static wchar_t* BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Breve";
static int* BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot above html character entity reference model.
 *
 * Name: DiacriticalDot
 * Character: ˙
 * Unicode code point: U+02d9 (729)
 * Description: dot above
 */
static wchar_t* DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalDot";
static int* DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ring above html character entity reference model.
 *
 * Name: ring
 * Character: ˚
 * Unicode code point: U+02da (730)
 * Description: ring above
 */
static wchar_t* RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ring";
static int* RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ogonek html character entity reference model.
 *
 * Name: ogon
 * Character: ˛
 * Unicode code point: U+02db (731)
 * Description: ogonek
 */
static wchar_t* OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogon";
static int* OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small tilde html character entity reference model.
 *
 * Name: DiacriticalTilde
 * Character: ˜
 * Unicode code point: U+02dc (732)
 * Description: small tilde
 */
static wchar_t* SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalTilde";
static int* SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double acute accent html character entity reference model.
 *
 * Name: DiacriticalDoubleAcute
 * Character: ˝
 * Unicode code point: U+02dd (733)
 * Description: double acute accent
 */
static wchar_t* DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalDoubleAcute";
static int* DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The combining inverted breve html character entity reference model.
 *
 * Name: DownBreve
 * Character:  ̑
 * Unicode code point: U+0311 (785)
 * Description: combining inverted breve
 */
static wchar_t* COMBINING_INVERTED_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownBreve";
static int* COMBINING_INVERTED_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter alpha with tonos html character entity reference model.
 *
 * Name: Aacgr
 * Character: Ά
 * Unicode code point: U+0386 (902)
 * Description: greek capital letter alpha with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aacgr";
static int* GREEK_CAPITAL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter epsilon with tonos html character entity reference model.
 *
 * Name: Eacgr
 * Character: Έ
 * Unicode code point: U+0388 (904)
 * Description: greek capital letter epsilon with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eacgr";
static int* GREEK_CAPITAL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter eta with tonos html character entity reference model.
 *
 * Name: EEacgr
 * Character: Ή
 * Unicode code point: U+0389 (905)
 * Description: greek capital letter eta with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EEacgr";
static int* GREEK_CAPITAL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter iota with tonos html character entity reference model.
 *
 * Name: Iacgr
 * Character: Ί
 * Unicode code point: U+038a (906)
 * Description: greek capital letter iota with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iacgr";
static int* GREEK_CAPITAL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter omicron with tonos html character entity reference model.
 *
 * Name: Oacgr
 * Character: Ό
 * Unicode code point: U+038c (908)
 * Description: greek capital letter omicron with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oacgr";
static int* GREEK_CAPITAL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter upsilon with tonos html character entity reference model.
 *
 * Name: Uacgr
 * Character: Ύ
 * Unicode code point: U+038e (910)
 * Description: greek capital letter upsilon with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uacgr";
static int* GREEK_CAPITAL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter omega with tonos html character entity reference model.
 *
 * Name: OHacgr
 * Character: Ώ
 * Unicode code point: U+038f (911)
 * Description: greek capital letter omega with tonos
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OHacgr";
static int* GREEK_CAPITAL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter iota with dialytika and tonos html character entity reference model.
 *
 * Name: idiagr
 * Character: ΐ
 * Unicode code point: U+0390 (912)
 * Description: greek small letter iota with dialytika and tonos
 */
static wchar_t* GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"idiagr";
static int* GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter alpha html character entity reference model.
 *
 * Name: Agr
 * Character: Α
 * Unicode code point: U+0391 (913)
 * Description: greek capital letter alpha
 */
static wchar_t* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Agr";
static int* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter beta html character entity reference model.
 *
 * Name: Beta
 * Character: Β
 * Unicode code point: U+0392 (914)
 * Description: greek capital letter beta
 */
static wchar_t* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Beta";
static int* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter gamma html character entity reference model.
 *
 * Name: Gamma
 * Character: Γ
 * Unicode code point: U+0393 (915)
 * Description: greek capital letter gamma
 */
static wchar_t* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gamma";
static int* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter delta html character entity reference model.
 *
 * Name: Delta
 * Character: Δ
 * Unicode code point: U+0394 (916)
 * Description: greek capital letter delta
 */
static wchar_t* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Delta";
static int* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter epsilon html character entity reference model.
 *
 * Name: Egr
 * Character: Ε
 * Unicode code point: U+0395 (917)
 * Description: greek capital letter epsilon
 */
static wchar_t* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Egr";
static int* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter zeta html character entity reference model.
 *
 * Name: Zeta
 * Character: Ζ
 * Unicode code point: U+0396 (918)
 * Description: greek capital letter zeta
 */
static wchar_t* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zeta";
static int* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter eta html character entity reference model.
 *
 * Name: EEgr
 * Character: Η
 * Unicode code point: U+0397 (919)
 * Description: greek capital letter eta
 */
static wchar_t* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EEgr";
static int* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter theta html character entity reference model.
 *
 * Name: THgr
 * Character: Θ
 * Unicode code point: U+0398 (920)
 * Description: greek capital letter theta
 */
static wchar_t* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"THgr";
static int* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter iota html character entity reference model.
 *
 * Name: Igr
 * Character: Ι
 * Unicode code point: U+0399 (921)
 * Description: greek capital letter iota
 */
static wchar_t* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Igr";
static int* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter kappa html character entity reference model.
 *
 * Name: Kappa
 * Character: Κ
 * Unicode code point: U+039a (922)
 * Description: greek capital letter kappa
 */
static wchar_t* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kappa";
static int* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter lamda html character entity reference model.
 *
 * Name: Lambda
 * Character: Λ
 * Unicode code point: U+039b (923)
 * Description: greek capital letter lamda
 */
static wchar_t* GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lambda";
static int* GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter mu html character entity reference model.
 *
 * Name: Mgr
 * Character: Μ
 * Unicode code point: U+039c (924)
 * Description: greek capital letter mu
 */
static wchar_t* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mgr";
static int* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter nu html character entity reference model.
 *
 * Name: Ngr
 * Character: Ν
 * Unicode code point: U+039d (925)
 * Description: greek capital letter nu
 */
static wchar_t* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ngr";
static int* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter xi html character entity reference model.
 *
 * Name: Xgr
 * Character: Ξ
 * Unicode code point: U+039e (926)
 * Description: greek capital letter xi
 */
static wchar_t* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xgr";
static int* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter omicron html character entity reference model.
 *
 * Name: Ogr
 * Character: Ο
 * Unicode code point: U+039f (927)
 * Description: greek capital letter omicron
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ogr";
static int* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter pi html character entity reference model.
 *
 * Name: Pgr
 * Character: Π
 * Unicode code point: U+03a0 (928)
 * Description: greek capital letter pi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pgr";
static int* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter rho html character entity reference model.
 *
 * Name: Rgr
 * Character: Ρ
 * Unicode code point: U+03a1 (929)
 * Description: greek capital letter rho
 */
static wchar_t* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rgr";
static int* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter sigma html character entity reference model.
 *
 * Name: Sgr
 * Character: Σ
 * Unicode code point: U+03a3 (931)
 * Description: greek capital letter sigma
 */
static wchar_t* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sgr";
static int* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter tau html character entity reference model.
 *
 * Name: Tau
 * Character: Τ
 * Unicode code point: U+03a4 (932)
 * Description: greek capital letter tau
 */
static wchar_t* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tau";
static int* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter upsilon html character entity reference model.
 *
 * Name: Ugr
 * Character: Υ
 * Unicode code point: U+03a5 (933)
 * Description: greek capital letter upsilon
 */
static wchar_t* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ugr";
static int* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter phi html character entity reference model.
 *
 * Name: PHgr
 * Character: Φ
 * Unicode code point: U+03a6 (934)
 * Description: greek capital letter phi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PHgr";
static int* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter chi html character entity reference model.
 *
 * Name: Chi
 * Character: Χ
 * Unicode code point: U+03a7 (935)
 * Description: greek capital letter chi
 */
static wchar_t* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Chi";
static int* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter psi html character entity reference model.
 *
 * Name: PSgr
 * Character: Ψ
 * Unicode code point: U+03a8 (936)
 * Description: greek capital letter psi
 */
static wchar_t* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PSgr";
static int* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter omega html character entity reference model.
 *
 * Name: OHgr
 * Character: Ω
 * Unicode code point: U+03a9 (937)
 * Description: greek capital letter omega
 */
static wchar_t* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OHgr";
static int* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter iota with dialytika html character entity reference model.
 *
 * Name: Idigr
 * Character: Ϊ
 * Unicode code point: U+03aa (938)
 * Description: greek capital letter iota with dialytika
 */
static wchar_t* GREEK_CAPITAL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Idigr";
static int* GREEK_CAPITAL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek capital letter upsilon with dialytika html character entity reference model.
 *
 * Name: Udigr
 * Character: Ϋ
 * Unicode code point: U+03ab (939)
 * Description: greek capital letter upsilon with dialytika
 */
static wchar_t* GREEK_CAPITAL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Udigr";
static int* GREEK_CAPITAL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter alpha with tonos html character entity reference model.
 *
 * Name: aacgr
 * Character: ά
 * Unicode code point: U+03ac (940)
 * Description: greek small letter alpha with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aacgr";
static int* GREEK_SMALL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter epsilon with tonos html character entity reference model.
 *
 * Name: eacgr
 * Character: έ
 * Unicode code point: U+03ad (941)
 * Description: greek small letter epsilon with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eacgr";
static int* GREEK_SMALL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter eta with tonos html character entity reference model.
 *
 * Name: eeacgr
 * Character: ή
 * Unicode code point: U+03ae (942)
 * Description: greek small letter eta with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eeacgr";
static int* GREEK_SMALL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter iota with tonos html character entity reference model.
 *
 * Name: iacgr
 * Character: ί
 * Unicode code point: U+03af (943)
 * Description: greek small letter iota with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iacgr";
static int* GREEK_SMALL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter upsilon with dialytika and tonos html character entity reference model.
 *
 * Name: udiagr
 * Character: ΰ
 * Unicode code point: U+03b0 (944)
 * Description: greek small letter upsilon with dialytika and tonos
 */
static wchar_t* GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udiagr";
static int* GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter alpha html character entity reference model.
 *
 * Name: agr
 * Character: α
 * Unicode code point: U+03b1 (945)
 * Description: greek small letter alpha
 */
static wchar_t* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"agr";
static int* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter beta html character entity reference model.
 *
 * Name: beta
 * Character: β
 * Unicode code point: U+03b2 (946)
 * Description: greek small letter beta
 */
static wchar_t* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"beta";
static int* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter gamma html character entity reference model.
 *
 * Name: gamma
 * Character: γ
 * Unicode code point: U+03b3 (947)
 * Description: greek small letter gamma
 */
static wchar_t* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gamma";
static int* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter delta html character entity reference model.
 *
 * Name: delta
 * Character: δ
 * Unicode code point: U+03b4 (948)
 * Description: greek small letter delta
 */
static wchar_t* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"delta";
static int* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter epsilon html character entity reference model.
 *
 * Name: egr
 * Character: ε
 * Unicode code point: U+03b5 (949)
 * Description: greek small letter epsilon
 */
static wchar_t* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egr";
static int* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter zeta html character entity reference model.
 *
 * Name: zeta
 * Character: ζ
 * Unicode code point: U+03b6 (950)
 * Description: greek small letter zeta
 */
static wchar_t* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zeta";
static int* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter eta html character entity reference model.
 *
 * Name: eegr
 * Character: η
 * Unicode code point: U+03b7 (951)
 * Description: greek small letter eta
 */
static wchar_t* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eegr";
static int* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter theta html character entity reference model.
 *
 * Name: theta
 * Character: θ
 * Unicode code point: U+03b8 (952)
 * Description: greek small letter theta
 */
static wchar_t* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"theta";
static int* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter iota html character entity reference model.
 *
 * Name: igr
 * Character: ι
 * Unicode code point: U+03b9 (953)
 * Description: greek small letter iota
 */
static wchar_t* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"igr";
static int* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter kappa html character entity reference model.
 *
 * Name: kappa
 * Character: κ
 * Unicode code point: U+03ba (954)
 * Description: greek small letter kappa
 */
static wchar_t* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kappa";
static int* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter lamda html character entity reference model.
 *
 * Name: lambda
 * Character: λ
 * Unicode code point: U+03bb (955)
 * Description: greek small letter lamda
 */
static wchar_t* GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lambda";
static int* GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter mu html character entity reference model.
 *
 * Name: mgr
 * Character: μ
 * Unicode code point: U+03bc (956)
 * Description: greek small letter mu
 */
static wchar_t* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mgr";
static int* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter nu html character entity reference model.
 *
 * Name: ngr
 * Character: ν
 * Unicode code point: U+03bd (957)
 * Description: greek small letter nu
 */
static wchar_t* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngr";
static int* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter xi html character entity reference model.
 *
 * Name: xgr
 * Character: ξ
 * Unicode code point: U+03be (958)
 * Description: greek small letter xi
 */
static wchar_t* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xgr";
static int* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter omicron html character entity reference model.
 *
 * Name: ogr
 * Character: ο
 * Unicode code point: U+03bf (959)
 * Description: greek small letter omicron
 */
static wchar_t* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogr";
static int* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter pi html character entity reference model.
 *
 * Name: pgr
 * Character: π
 * Unicode code point: U+03c0 (960)
 * Description: greek small letter pi
 */
static wchar_t* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pgr";
static int* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter rho html character entity reference model.
 *
 * Name: rgr
 * Character: ρ
 * Unicode code point: U+03c1 (961)
 * Description: greek small letter rho
 */
static wchar_t* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rgr";
static int* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter final sigma html character entity reference model.
 *
 * Name: sfgr
 * Character: ς
 * Unicode code point: U+03c2 (962)
 * Description: greek small letter final sigma
 */
static wchar_t* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sfgr";
static int* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter sigma html character entity reference model.
 *
 * Name: sgr
 * Character: σ
 * Unicode code point: U+03c3 (963)
 * Description: greek small letter sigma
 */
static wchar_t* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sgr";
static int* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter tau html character entity reference model.
 *
 * Name: tau
 * Character: τ
 * Unicode code point: U+03c4 (964)
 * Description: greek small letter tau
 */
static wchar_t* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tau";
static int* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter upsilon html character entity reference model.
 *
 * Name: ugr
 * Character: υ
 * Unicode code point: U+03c5 (965)
 * Description: greek small letter upsilon
 */
static wchar_t* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ugr";
static int* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter phi html character entity reference model.
 *
 * Name: phgr
 * Character: φ
 * Unicode code point: U+03c6 (966)
 * Description: greek small letter phi
 */
static wchar_t* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phgr";
static int* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter chi html character entity reference model.
 *
 * Name: chi
 * Character: χ
 * Unicode code point: U+03c7 (967)
 * Description: greek small letter chi
 */
static wchar_t* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"chi";
static int* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter psi html character entity reference model.
 *
 * Name: psgr
 * Character: ψ
 * Unicode code point: U+03c8 (968)
 * Description: greek small letter psi
 */
static wchar_t* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"psgr";
static int* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter omega html character entity reference model.
 *
 * Name: ohgr
 * Character: ω
 * Unicode code point: U+03c9 (969)
 * Description: greek small letter omega
 */
static wchar_t* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohgr";
static int* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter iota with dialytika html character entity reference model.
 *
 * Name: idigr
 * Character: ϊ
 * Unicode code point: U+03ca (970)
 * Description: greek small letter iota with dialytika
 */
static wchar_t* GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"idigr";
static int* GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter upsilon with dialytika html character entity reference model.
 *
 * Name: udigr
 * Character: ϋ
 * Unicode code point: U+03cb (971)
 * Description: greek small letter upsilon with dialytika
 */
static wchar_t* GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udigr";
static int* GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter omicron with tonos html character entity reference model.
 *
 * Name: oacgr
 * Character: ό
 * Unicode code point: U+03cc (972)
 * Description: greek small letter omicron with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oacgr";
static int* GREEK_SMALL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter upsilon with tonos html character entity reference model.
 *
 * Name: uacgr
 * Character: ύ
 * Unicode code point: U+03cd (973)
 * Description: greek small letter upsilon with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uacgr";
static int* GREEK_SMALL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter omega with tonos html character entity reference model.
 *
 * Name: ohacgr
 * Character: ώ
 * Unicode code point: U+03ce (974)
 * Description: greek small letter omega with tonos
 */
static wchar_t* GREEK_SMALL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohacgr";
static int* GREEK_SMALL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek theta symbol html character entity reference model.
 *
 * Name: thetasym
 * Character: ϑ
 * Unicode code point: U+03d1 (977)
 * Description: greek theta symbol
 */
static wchar_t* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thetasym";
static int* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek upsilon with hook symbol html character entity reference model.
 *
 * Name: Upsi
 * Character: ϒ
 * Unicode code point: U+03d2 (978)
 * Description: greek upsilon with hook symbol
 */
static wchar_t* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Upsi";
static int* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek phi symbol html character entity reference model.
 *
 * Name: phiv
 * Character: ϕ
 * Unicode code point: U+03d5 (981)
 * Description: greek phi symbol
 */
static wchar_t* GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phiv";
static int* GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek pi symbol html character entity reference model.
 *
 * Name: piv
 * Character: ϖ
 * Unicode code point: U+03d6 (982)
 * Description: greek pi symbol
 */
static wchar_t* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"piv";
static int* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek letter digamma html character entity reference model.
 *
 * Name: Gammad
 * Character: Ϝ
 * Unicode code point: U+03dc (988)
 * Description: greek letter digamma
 */
static wchar_t* GREEK_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gammad";
static int* GREEK_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek small letter digamma html character entity reference model.
 *
 * Name: digamma
 * Character: ϝ
 * Unicode code point: U+03dd (989)
 * Description: greek small letter digamma
 */
static wchar_t* GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"digamma";
static int* GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek kappa symbol html character entity reference model.
 *
 * Name: kappav
 * Character: ϰ
 * Unicode code point: U+03f0 (1008)
 * Description: greek kappa symbol
 */
static wchar_t* GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kappav";
static int* GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek rho symbol html character entity reference model.
 *
 * Name: rhov
 * Character: ϱ
 * Unicode code point: U+03f1 (1009)
 * Description: greek rho symbol
 */
static wchar_t* GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rhov";
static int* GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek lunate epsilon symbol html character entity reference model.
 *
 * Name: epsiv
 * Character: ϵ
 * Unicode code point: U+03f5 (1013)
 * Description: greek lunate epsilon symbol
 */
static wchar_t* GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epsiv";
static int* GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greek reversed lunate epsilon symbol html character entity reference model.
 *
 * Name: backepsilon
 * Character: ϶
 * Unicode code point: U+03f6 (1014)
 * Description: greek reversed lunate epsilon symbol
 */
static wchar_t* GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backepsilon";
static int* GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter io html character entity reference model.
 *
 * Name: IOcy
 * Character: Ё
 * Unicode code point: U+0401 (1025)
 * Description: cyrillic capital letter io
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IOcy";
static int* CYRILLIC_CAPITAL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter dje html character entity reference model.
 *
 * Name: DJcy
 * Character: Ђ
 * Unicode code point: U+0402 (1026)
 * Description: cyrillic capital letter dje
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DJcy";
static int* CYRILLIC_CAPITAL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter gje html character entity reference model.
 *
 * Name: GJcy
 * Character: Ѓ
 * Unicode code point: U+0403 (1027)
 * Description: cyrillic capital letter gje
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GJcy";
static int* CYRILLIC_CAPITAL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ukrainian ie html character entity reference model.
 *
 * Name: Jukcy
 * Character: Є
 * Unicode code point: U+0404 (1028)
 * Description: cyrillic capital letter ukrainian ie
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jukcy";
static int* CYRILLIC_CAPITAL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter dze html character entity reference model.
 *
 * Name: DScy
 * Character: Ѕ
 * Unicode code point: U+0405 (1029)
 * Description: cyrillic capital letter dze
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DScy";
static int* CYRILLIC_CAPITAL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter byelorussian-ukrainian i html character entity reference model.
 *
 * Name: Iukcy
 * Character: І
 * Unicode code point: U+0406 (1030)
 * Description: cyrillic capital letter byelorussian-ukrainian i
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iukcy";
static int* CYRILLIC_CAPITAL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter yi html character entity reference model.
 *
 * Name: YIcy
 * Character: Ї
 * Unicode code point: U+0407 (1031)
 * Description: cyrillic capital letter yi
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YIcy";
static int* CYRILLIC_CAPITAL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter je html character entity reference model.
 *
 * Name: Jsercy
 * Character: Ј
 * Unicode code point: U+0408 (1032)
 * Description: cyrillic capital letter je
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jsercy";
static int* CYRILLIC_CAPITAL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter lje html character entity reference model.
 *
 * Name: LJcy
 * Character: Љ
 * Unicode code point: U+0409 (1033)
 * Description: cyrillic capital letter lje
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LJcy";
static int* CYRILLIC_CAPITAL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter nje html character entity reference model.
 *
 * Name: NJcy
 * Character: Њ
 * Unicode code point: U+040a (1034)
 * Description: cyrillic capital letter nje
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NJcy";
static int* CYRILLIC_CAPITAL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter tshe html character entity reference model.
 *
 * Name: TSHcy
 * Character: Ћ
 * Unicode code point: U+040b (1035)
 * Description: cyrillic capital letter tshe
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TSHcy";
static int* CYRILLIC_CAPITAL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter kje html character entity reference model.
 *
 * Name: KJcy
 * Character: Ќ
 * Unicode code point: U+040c (1036)
 * Description: cyrillic capital letter kje
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"KJcy";
static int* CYRILLIC_CAPITAL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter short u html character entity reference model.
 *
 * Name: Ubrcy
 * Character: Ў
 * Unicode code point: U+040e (1038)
 * Description: cyrillic capital letter short u
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ubrcy";
static int* CYRILLIC_CAPITAL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter dzhe html character entity reference model.
 *
 * Name: DZcy
 * Character: Џ
 * Unicode code point: U+040f (1039)
 * Description: cyrillic capital letter dzhe
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DZcy";
static int* CYRILLIC_CAPITAL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter a html character entity reference model.
 *
 * Name: Acy
 * Character: А
 * Unicode code point: U+0410 (1040)
 * Description: cyrillic capital letter a
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Acy";
static int* CYRILLIC_CAPITAL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter be html character entity reference model.
 *
 * Name: Bcy
 * Character: Б
 * Unicode code point: U+0411 (1041)
 * Description: cyrillic capital letter be
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bcy";
static int* CYRILLIC_CAPITAL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ve html character entity reference model.
 *
 * Name: Vcy
 * Character: В
 * Unicode code point: U+0412 (1042)
 * Description: cyrillic capital letter ve
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vcy";
static int* CYRILLIC_CAPITAL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ghe html character entity reference model.
 *
 * Name: Gcy
 * Character: Г
 * Unicode code point: U+0413 (1043)
 * Description: cyrillic capital letter ghe
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcy";
static int* CYRILLIC_CAPITAL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter de html character entity reference model.
 *
 * Name: Dcy
 * Character: Д
 * Unicode code point: U+0414 (1044)
 * Description: cyrillic capital letter de
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dcy";
static int* CYRILLIC_CAPITAL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ie html character entity reference model.
 *
 * Name: IEcy
 * Character: Е
 * Unicode code point: U+0415 (1045)
 * Description: cyrillic capital letter ie
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IEcy";
static int* CYRILLIC_CAPITAL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter zhe html character entity reference model.
 *
 * Name: ZHcy
 * Character: Ж
 * Unicode code point: U+0416 (1046)
 * Description: cyrillic capital letter zhe
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ZHcy";
static int* CYRILLIC_CAPITAL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ze html character entity reference model.
 *
 * Name: Zcy
 * Character: З
 * Unicode code point: U+0417 (1047)
 * Description: cyrillic capital letter ze
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zcy";
static int* CYRILLIC_CAPITAL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter i html character entity reference model.
 *
 * Name: Icy
 * Character: И
 * Unicode code point: U+0418 (1048)
 * Description: cyrillic capital letter i
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Icy";
static int* CYRILLIC_CAPITAL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter short i html character entity reference model.
 *
 * Name: Jcy
 * Character: Й
 * Unicode code point: U+0419 (1049)
 * Description: cyrillic capital letter short i
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jcy";
static int* CYRILLIC_CAPITAL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ka html character entity reference model.
 *
 * Name: Kcy
 * Character: К
 * Unicode code point: U+041a (1050)
 * Description: cyrillic capital letter ka
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kcy";
static int* CYRILLIC_CAPITAL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter el html character entity reference model.
 *
 * Name: Lcy
 * Character: Л
 * Unicode code point: U+041b (1051)
 * Description: cyrillic capital letter el
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcy";
static int* CYRILLIC_CAPITAL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter em html character entity reference model.
 *
 * Name: Mcy
 * Character: М
 * Unicode code point: U+041c (1052)
 * Description: cyrillic capital letter em
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mcy";
static int* CYRILLIC_CAPITAL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter en html character entity reference model.
 *
 * Name: Ncy
 * Character: Н
 * Unicode code point: U+041d (1053)
 * Description: cyrillic capital letter en
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncy";
static int* CYRILLIC_CAPITAL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter o html character entity reference model.
 *
 * Name: Ocy
 * Character: О
 * Unicode code point: U+041e (1054)
 * Description: cyrillic capital letter o
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ocy";
static int* CYRILLIC_CAPITAL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter pe html character entity reference model.
 *
 * Name: Pcy
 * Character: П
 * Unicode code point: U+041f (1055)
 * Description: cyrillic capital letter pe
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pcy";
static int* CYRILLIC_CAPITAL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter er html character entity reference model.
 *
 * Name: Rcy
 * Character: Р
 * Unicode code point: U+0420 (1056)
 * Description: cyrillic capital letter er
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcy";
static int* CYRILLIC_CAPITAL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter es html character entity reference model.
 *
 * Name: Scy
 * Character: С
 * Unicode code point: U+0421 (1057)
 * Description: cyrillic capital letter es
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scy";
static int* CYRILLIC_CAPITAL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter te html character entity reference model.
 *
 * Name: Tcy
 * Character: Т
 * Unicode code point: U+0422 (1058)
 * Description: cyrillic capital letter te
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcy";
static int* CYRILLIC_CAPITAL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter u html character entity reference model.
 *
 * Name: Ucy
 * Character: У
 * Unicode code point: U+0423 (1059)
 * Description: cyrillic capital letter u
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ucy";
static int* CYRILLIC_CAPITAL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ef html character entity reference model.
 *
 * Name: Fcy
 * Character: Ф
 * Unicode code point: U+0424 (1060)
 * Description: cyrillic capital letter ef
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fcy";
static int* CYRILLIC_CAPITAL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ha html character entity reference model.
 *
 * Name: KHcy
 * Character: Х
 * Unicode code point: U+0425 (1061)
 * Description: cyrillic capital letter ha
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"KHcy";
static int* CYRILLIC_CAPITAL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter tse html character entity reference model.
 *
 * Name: TScy
 * Character: Ц
 * Unicode code point: U+0426 (1062)
 * Description: cyrillic capital letter tse
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TScy";
static int* CYRILLIC_CAPITAL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter che html character entity reference model.
 *
 * Name: CHcy
 * Character: Ч
 * Unicode code point: U+0427 (1063)
 * Description: cyrillic capital letter che
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CHcy";
static int* CYRILLIC_CAPITAL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter sha html character entity reference model.
 *
 * Name: SHcy
 * Character: Ш
 * Unicode code point: U+0428 (1064)
 * Description: cyrillic capital letter sha
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SHcy";
static int* CYRILLIC_CAPITAL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter shcha html character entity reference model.
 *
 * Name: SHCHcy
 * Character: Щ
 * Unicode code point: U+0429 (1065)
 * Description: cyrillic capital letter shcha
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SHCHcy";
static int* CYRILLIC_CAPITAL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter hard sign html character entity reference model.
 *
 * Name: HARDcy
 * Character: Ъ
 * Unicode code point: U+042a (1066)
 * Description: cyrillic capital letter hard sign
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HARDcy";
static int* CYRILLIC_CAPITAL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter yeru html character entity reference model.
 *
 * Name: Ycy
 * Character: Ы
 * Unicode code point: U+042b (1067)
 * Description: cyrillic capital letter yeru
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ycy";
static int* CYRILLIC_CAPITAL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter soft sign html character entity reference model.
 *
 * Name: SOFTcy
 * Character: Ь
 * Unicode code point: U+042c (1068)
 * Description: cyrillic capital letter soft sign
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SOFTcy";
static int* CYRILLIC_CAPITAL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter e html character entity reference model.
 *
 * Name: Ecy
 * Character: Э
 * Unicode code point: U+042d (1069)
 * Description: cyrillic capital letter e
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecy";
static int* CYRILLIC_CAPITAL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter yu html character entity reference model.
 *
 * Name: YUcy
 * Character: Ю
 * Unicode code point: U+042e (1070)
 * Description: cyrillic capital letter yu
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YUcy";
static int* CYRILLIC_CAPITAL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic capital letter ya html character entity reference model.
 *
 * Name: YAcy
 * Character: Я
 * Unicode code point: U+042f (1071)
 * Description: cyrillic capital letter ya
 */
static wchar_t* CYRILLIC_CAPITAL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YAcy";
static int* CYRILLIC_CAPITAL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter a html character entity reference model.
 *
 * Name: acy
 * Character: а
 * Unicode code point: U+0430 (1072)
 * Description: cyrillic small letter a
 */
static wchar_t* CYRILLIC_SMALL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acy";
static int* CYRILLIC_SMALL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter be html character entity reference model.
 *
 * Name: bcy
 * Character: б
 * Unicode code point: U+0431 (1073)
 * Description: cyrillic small letter be
 */
static wchar_t* CYRILLIC_SMALL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bcy";
static int* CYRILLIC_SMALL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ve html character entity reference model.
 *
 * Name: vcy
 * Character: в
 * Unicode code point: U+0432 (1074)
 * Description: cyrillic small letter ve
 */
static wchar_t* CYRILLIC_SMALL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vcy";
static int* CYRILLIC_SMALL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ghe html character entity reference model.
 *
 * Name: gcy
 * Character: г
 * Unicode code point: U+0433 (1075)
 * Description: cyrillic small letter ghe
 */
static wchar_t* CYRILLIC_SMALL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gcy";
static int* CYRILLIC_SMALL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter de html character entity reference model.
 *
 * Name: dcy
 * Character: д
 * Unicode code point: U+0434 (1076)
 * Description: cyrillic small letter de
 */
static wchar_t* CYRILLIC_SMALL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dcy";
static int* CYRILLIC_SMALL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ie html character entity reference model.
 *
 * Name: iecy
 * Character: е
 * Unicode code point: U+0435 (1077)
 * Description: cyrillic small letter ie
 */
static wchar_t* CYRILLIC_SMALL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iecy";
static int* CYRILLIC_SMALL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter zhe html character entity reference model.
 *
 * Name: zhcy
 * Character: ж
 * Unicode code point: U+0436 (1078)
 * Description: cyrillic small letter zhe
 */
static wchar_t* CYRILLIC_SMALL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zhcy";
static int* CYRILLIC_SMALL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ze html character entity reference model.
 *
 * Name: zcy
 * Character: з
 * Unicode code point: U+0437 (1079)
 * Description: cyrillic small letter ze
 */
static wchar_t* CYRILLIC_SMALL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zcy";
static int* CYRILLIC_SMALL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter i html character entity reference model.
 *
 * Name: icy
 * Character: и
 * Unicode code point: U+0438 (1080)
 * Description: cyrillic small letter i
 */
static wchar_t* CYRILLIC_SMALL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"icy";
static int* CYRILLIC_SMALL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter short i html character entity reference model.
 *
 * Name: jcy
 * Character: й
 * Unicode code point: U+0439 (1081)
 * Description: cyrillic small letter short i
 */
static wchar_t* CYRILLIC_SMALL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jcy";
static int* CYRILLIC_SMALL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ka html character entity reference model.
 *
 * Name: kcy
 * Character: к
 * Unicode code point: U+043a (1082)
 * Description: cyrillic small letter ka
 */
static wchar_t* CYRILLIC_SMALL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kcy";
static int* CYRILLIC_SMALL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter el html character entity reference model.
 *
 * Name: lcy
 * Character: л
 * Unicode code point: U+043b (1083)
 * Description: cyrillic small letter el
 */
static wchar_t* CYRILLIC_SMALL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcy";
static int* CYRILLIC_SMALL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter em html character entity reference model.
 *
 * Name: mcy
 * Character: м
 * Unicode code point: U+043c (1084)
 * Description: cyrillic small letter em
 */
static wchar_t* CYRILLIC_SMALL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mcy";
static int* CYRILLIC_SMALL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter en html character entity reference model.
 *
 * Name: ncy
 * Character: н
 * Unicode code point: U+043d (1085)
 * Description: cyrillic small letter en
 */
static wchar_t* CYRILLIC_SMALL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncy";
static int* CYRILLIC_SMALL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter o html character entity reference model.
 *
 * Name: ocy
 * Character: о
 * Unicode code point: U+043e (1086)
 * Description: cyrillic small letter o
 */
static wchar_t* CYRILLIC_SMALL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocy";
static int* CYRILLIC_SMALL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter pe html character entity reference model.
 *
 * Name: pcy
 * Character: п
 * Unicode code point: U+043f (1087)
 * Description: cyrillic small letter pe
 */
static wchar_t* CYRILLIC_SMALL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pcy";
static int* CYRILLIC_SMALL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter er html character entity reference model.
 *
 * Name: rcy
 * Character: р
 * Unicode code point: U+0440 (1088)
 * Description: cyrillic small letter er
 */
static wchar_t* CYRILLIC_SMALL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcy";
static int* CYRILLIC_SMALL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter es html character entity reference model.
 *
 * Name: scy
 * Character: с
 * Unicode code point: U+0441 (1089)
 * Description: cyrillic small letter es
 */
static wchar_t* CYRILLIC_SMALL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scy";
static int* CYRILLIC_SMALL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter te html character entity reference model.
 *
 * Name: tcy
 * Character: т
 * Unicode code point: U+0442 (1090)
 * Description: cyrillic small letter te
 */
static wchar_t* CYRILLIC_SMALL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcy";
static int* CYRILLIC_SMALL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter u html character entity reference model.
 *
 * Name: ucy
 * Character: у
 * Unicode code point: U+0443 (1091)
 * Description: cyrillic small letter u
 */
static wchar_t* CYRILLIC_SMALL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ucy";
static int* CYRILLIC_SMALL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ef html character entity reference model.
 *
 * Name: fcy
 * Character: ф
 * Unicode code point: U+0444 (1092)
 * Description: cyrillic small letter ef
 */
static wchar_t* CYRILLIC_SMALL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fcy";
static int* CYRILLIC_SMALL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ha html character entity reference model.
 *
 * Name: khcy
 * Character: х
 * Unicode code point: U+0445 (1093)
 * Description: cyrillic small letter ha
 */
static wchar_t* CYRILLIC_SMALL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"khcy";
static int* CYRILLIC_SMALL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter tse html character entity reference model.
 *
 * Name: tscy
 * Character: ц
 * Unicode code point: U+0446 (1094)
 * Description: cyrillic small letter tse
 */
static wchar_t* CYRILLIC_SMALL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tscy";
static int* CYRILLIC_SMALL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter che html character entity reference model.
 *
 * Name: chcy
 * Character: ч
 * Unicode code point: U+0447 (1095)
 * Description: cyrillic small letter che
 */
static wchar_t* CYRILLIC_SMALL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"chcy";
static int* CYRILLIC_SMALL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter sha html character entity reference model.
 *
 * Name: shcy
 * Character: ш
 * Unicode code point: U+0448 (1096)
 * Description: cyrillic small letter sha
 */
static wchar_t* CYRILLIC_SMALL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shcy";
static int* CYRILLIC_SMALL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter shcha html character entity reference model.
 *
 * Name: shchcy
 * Character: щ
 * Unicode code point: U+0449 (1097)
 * Description: cyrillic small letter shcha
 */
static wchar_t* CYRILLIC_SMALL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shchcy";
static int* CYRILLIC_SMALL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter hard sign html character entity reference model.
 *
 * Name: hardcy
 * Character: ъ
 * Unicode code point: U+044a (1098)
 * Description: cyrillic small letter hard sign
 */
static wchar_t* CYRILLIC_SMALL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hardcy";
static int* CYRILLIC_SMALL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter yeru html character entity reference model.
 *
 * Name: ycy
 * Character: ы
 * Unicode code point: U+044b (1099)
 * Description: cyrillic small letter yeru
 */
static wchar_t* CYRILLIC_SMALL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ycy";
static int* CYRILLIC_SMALL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter soft sign html character entity reference model.
 *
 * Name: softcy
 * Character: ь
 * Unicode code point: U+044c (1100)
 * Description: cyrillic small letter soft sign
 */
static wchar_t* CYRILLIC_SMALL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"softcy";
static int* CYRILLIC_SMALL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter e html character entity reference model.
 *
 * Name: ecy
 * Character: э
 * Unicode code point: U+044d (1101)
 * Description: cyrillic small letter e
 */
static wchar_t* CYRILLIC_SMALL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecy";
static int* CYRILLIC_SMALL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter yu html character entity reference model.
 *
 * Name: yucy
 * Character: ю
 * Unicode code point: U+044e (1102)
 * Description: cyrillic small letter yu
 */
static wchar_t* CYRILLIC_SMALL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yucy";
static int* CYRILLIC_SMALL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ya html character entity reference model.
 *
 * Name: yacy
 * Character: я
 * Unicode code point: U+044f (1103)
 * Description: cyrillic small letter ya
 */
static wchar_t* CYRILLIC_SMALL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yacy";
static int* CYRILLIC_SMALL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter io html character entity reference model.
 *
 * Name: iocy
 * Character: ё
 * Unicode code point: U+0451 (1105)
 * Description: cyrillic small letter io
 */
static wchar_t* CYRILLIC_SMALL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iocy";
static int* CYRILLIC_SMALL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter dje html character entity reference model.
 *
 * Name: djcy
 * Character: ђ
 * Unicode code point: U+0452 (1106)
 * Description: cyrillic small letter dje
 */
static wchar_t* CYRILLIC_SMALL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"djcy";
static int* CYRILLIC_SMALL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter gje html character entity reference model.
 *
 * Name: gjcy
 * Character: ѓ
 * Unicode code point: U+0453 (1107)
 * Description: cyrillic small letter gje
 */
static wchar_t* CYRILLIC_SMALL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gjcy";
static int* CYRILLIC_SMALL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter ukrainian ie html character entity reference model.
 *
 * Name: jukcy
 * Character: є
 * Unicode code point: U+0454 (1108)
 * Description: cyrillic small letter ukrainian ie
 */
static wchar_t* CYRILLIC_SMALL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jukcy";
static int* CYRILLIC_SMALL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter dze html character entity reference model.
 *
 * Name: dscy
 * Character: ѕ
 * Unicode code point: U+0455 (1109)
 * Description: cyrillic small letter dze
 */
static wchar_t* CYRILLIC_SMALL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dscy";
static int* CYRILLIC_SMALL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter byelorussian-ukrainian i html character entity reference model.
 *
 * Name: iukcy
 * Character: і
 * Unicode code point: U+0456 (1110)
 * Description: cyrillic small letter byelorussian-ukrainian i
 */
static wchar_t* CYRILLIC_SMALL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iukcy";
static int* CYRILLIC_SMALL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter yi html character entity reference model.
 *
 * Name: yicy
 * Character: ї
 * Unicode code point: U+0457 (1111)
 * Description: cyrillic small letter yi
 */
static wchar_t* CYRILLIC_SMALL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yicy";
static int* CYRILLIC_SMALL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter je html character entity reference model.
 *
 * Name: jsercy
 * Character: ј
 * Unicode code point: U+0458 (1112)
 * Description: cyrillic small letter je
 */
static wchar_t* CYRILLIC_SMALL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jsercy";
static int* CYRILLIC_SMALL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter lje html character entity reference model.
 *
 * Name: ljcy
 * Character: љ
 * Unicode code point: U+0459 (1113)
 * Description: cyrillic small letter lje
 */
static wchar_t* CYRILLIC_SMALL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ljcy";
static int* CYRILLIC_SMALL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter nje html character entity reference model.
 *
 * Name: njcy
 * Character: њ
 * Unicode code point: U+045a (1114)
 * Description: cyrillic small letter nje
 */
static wchar_t* CYRILLIC_SMALL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"njcy";
static int* CYRILLIC_SMALL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter tshe html character entity reference model.
 *
 * Name: tshcy
 * Character: ћ
 * Unicode code point: U+045b (1115)
 * Description: cyrillic small letter tshe
 */
static wchar_t* CYRILLIC_SMALL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tshcy";
static int* CYRILLIC_SMALL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter kje html character entity reference model.
 *
 * Name: kjcy
 * Character: ќ
 * Unicode code point: U+045c (1116)
 * Description: cyrillic small letter kje
 */
static wchar_t* CYRILLIC_SMALL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kjcy";
static int* CYRILLIC_SMALL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter short u html character entity reference model.
 *
 * Name: ubrcy
 * Character: ў
 * Unicode code point: U+045e (1118)
 * Description: cyrillic small letter short u
 */
static wchar_t* CYRILLIC_SMALL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ubrcy";
static int* CYRILLIC_SMALL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cyrillic small letter dzhe html character entity reference model.
 *
 * Name: dzcy
 * Character: џ
 * Unicode code point: U+045f (1119)
 * Description: cyrillic small letter dzhe
 */
static wchar_t* CYRILLIC_SMALL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dzcy";
static int* CYRILLIC_SMALL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The en space html character entity reference model.
 *
 * Name: ensp
 * Character:  
 * Unicode code point: U+2002 (8194)
 * Description: en space
 */
static wchar_t* EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ensp";
static int* EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The em space html character entity reference model.
 *
 * Name: emsp
 * Character:  
 * Unicode code point: U+2003 (8195)
 * Description: em space
 */
static wchar_t* EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp";
static int* EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The three-per-em space html character entity reference model.
 *
 * Name: emsp13
 * Character:  
 * Unicode code point: U+2004 (8196)
 * Description: three-per-em space
 */
static wchar_t* THREE_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp13";
static int* THREE_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The four-per-em space html character entity reference model.
 *
 * Name: emsp14
 * Character:  
 * Unicode code point: U+2005 (8197)
 * Description: four-per-em space
 */
static wchar_t* FOUR_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp14";
static int* FOUR_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The figure space html character entity reference model.
 *
 * Name: numsp
 * Character:  
 * Unicode code point: U+2007 (8199)
 * Description: figure space
 */
static wchar_t* FIGURE_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"numsp";
static int* FIGURE_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The punctuation space html character entity reference model.
 *
 * Name: puncsp
 * Character:  
 * Unicode code point: U+2008 (8200)
 * Description: punctuation space
 */
static wchar_t* PUNCTUATION_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"puncsp";
static int* PUNCTUATION_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thin space html character entity reference model.
 *
 * Name: ThinSpace
 * Character:  
 * Unicode code point: U+2009 (8201)
 * Description: thin space
 */
static wchar_t* THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ThinSpace";
static int* THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hair space html character entity reference model.
 *
 * Name: VeryThinSpace
 * Character:  
 * Unicode code point: U+200a (8202)
 * Description: hair space
 */
static wchar_t* HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VeryThinSpace";
static int* HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zero width space html character entity reference model.
 *
 * Name: NegativeMediumSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NegativeMediumSpace";
static int* ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zero width non-joiner html character entity reference model.
 *
 * Name: zwnj
 * Character: ‌
 * Unicode code point: U+200c (8204)
 * Description: zero width non-joiner
 */
static wchar_t* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwnj";
static int* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zero width joiner html character entity reference model.
 *
 * Name: zwj
 * Character: ‍
 * Unicode code point: U+200d (8205)
 * Description: zero width joiner
 */
static wchar_t* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwj";
static int* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-to-right mark html character entity reference model.
 *
 * Name: lrm
 * Character: ‎
 * Unicode code point: U+200e (8206)
 * Description: left-to-right mark
 */
static wchar_t* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrm";
static int* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-to-left mark html character entity reference model.
 *
 * Name: rlm
 * Character: ‏
 * Unicode code point: U+200f (8207)
 * Description: right-to-left mark
 */
static wchar_t* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rlm";
static int* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hyphen html character entity reference model.
 *
 * Name: dash
 * Character: ‐
 * Unicode code point: U+2010 (8208)
 * Description: hyphen
 */
static wchar_t* HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dash";
static int* HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The en dash html character entity reference model.
 *
 * Name: ndash
 * Character: –
 * Unicode code point: U+2013 (8211)
 * Description: en dash
 */
static wchar_t* EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ndash";
static int* EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The em dash html character entity reference model.
 *
 * Name: mdash
 * Character: —
 * Unicode code point: U+2014 (8212)
 * Description: em dash
 */
static wchar_t* EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mdash";
static int* EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The horizontal bar html character entity reference model.
 *
 * Name: horbar
 * Character: ―
 * Unicode code point: U+2015 (8213)
 * Description: horizontal bar
 */
static wchar_t* HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"horbar";
static int* HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double vertical line html character entity reference model.
 *
 * Name: Verbar
 * Character: ‖
 * Unicode code point: U+2016 (8214)
 * Description: double vertical line
 */
static wchar_t* DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Verbar";
static int* DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left single quotation mark html character entity reference model.
 *
 * Name: OpenCurlyQuote
 * Character: ‘
 * Unicode code point: U+2018 (8216)
 * Description: left single quotation mark
 */
static wchar_t* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OpenCurlyQuote";
static int* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right single quotation mark html character entity reference model.
 *
 * Name: CloseCurlyQuote
 * Character: ’
 * Unicode code point: U+2019 (8217)
 * Description: right single quotation mark
 */
static wchar_t* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CloseCurlyQuote";
static int* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single low-9 quotation mark html character entity reference model.
 *
 * Name: lsquor
 * Character: ‚
 * Unicode code point: U+201a (8218)
 * Description: single low-9 quotation mark
 */
static wchar_t* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsquor";
static int* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left double quotation mark html character entity reference model.
 *
 * Name: OpenCurlyDoubleQuote
 * Character: “
 * Unicode code point: U+201c (8220)
 * Description: left double quotation mark
 */
static wchar_t* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OpenCurlyDoubleQuote";
static int* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right double quotation mark html character entity reference model.
 *
 * Name: CloseCurlyDoubleQuote
 * Character: ”
 * Unicode code point: U+201d (8221)
 * Description: right double quotation mark
 */
static wchar_t* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CloseCurlyDoubleQuote";
static int* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double low-9 quotation mark html character entity reference model.
 *
 * Name: bdquo
 * Character: „
 * Unicode code point: U+201e (8222)
 * Description: double low-9 quotation mark
 */
static wchar_t* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bdquo";
static int* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dagger html character entity reference model.
 *
 * Name: dagger
 * Character: †
 * Unicode code point: U+2020 (8224)
 * Description: dagger
 */
static wchar_t* DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dagger";
static int* DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double dagger html character entity reference model.
 *
 * Name: Dagger
 * Character: ‡
 * Unicode code point: U+2021 (8225)
 * Description: double dagger
 */
static wchar_t* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dagger";
static int* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bullet html character entity reference model.
 *
 * Name: bull
 * Character: •
 * Unicode code point: U+2022 (8226)
 * Description: bullet
 */
static wchar_t* BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bull";
static int* BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The two dot leader html character entity reference model.
 *
 * Name: nldr
 * Character: ‥
 * Unicode code point: U+2025 (8229)
 * Description: two dot leader
 */
static wchar_t* TWO_DOT_LEADER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nldr";
static int* TWO_DOT_LEADER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The horizontal ellipsis html character entity reference model.
 *
 * Name: hellip
 * Character: …
 * Unicode code point: U+2026 (8230)
 * Description: horizontal ellipsis
 */
static wchar_t* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hellip";
static int* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The per mille sign html character entity reference model.
 *
 * Name: permil
 * Character: ‰
 * Unicode code point: U+2030 (8240)
 * Description: per mille sign
 */
static wchar_t* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"permil";
static int* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The per ten thousand sign html character entity reference model.
 *
 * Name: pertenk
 * Character: ‱
 * Unicode code point: U+2031 (8241)
 * Description: per ten thousand sign
 */
static wchar_t* PER_TEN_THOUSAND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pertenk";
static int* PER_TEN_THOUSAND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prime html character entity reference model.
 *
 * Name: prime
 * Character: ′
 * Unicode code point: U+2032 (8242)
 * Description: prime
 */
static wchar_t* PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prime";
static int* PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double prime html character entity reference model.
 *
 * Name: Prime
 * Character: ″
 * Unicode code point: U+2033 (8243)
 * Description: double prime
 */
static wchar_t* DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Prime";
static int* DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triple prime html character entity reference model.
 *
 * Name: tprime
 * Character: ‴
 * Unicode code point: U+2034 (8244)
 * Description: triple prime
 */
static wchar_t* TRIPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tprime";
static int* TRIPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed prime html character entity reference model.
 *
 * Name: backprime
 * Character: ‵
 * Unicode code point: U+2035 (8245)
 * Description: reversed prime
 */
static wchar_t* REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backprime";
static int* REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single left-pointing angle quotation mark html character entity reference model.
 *
 * Name: lsaquo
 * Character: ‹
 * Unicode code point: U+2039 (8249)
 * Description: single left-pointing angle quotation mark
 */
static wchar_t* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsaquo";
static int* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The single right-pointing angle quotation mark html character entity reference model.
 *
 * Name: rsaquo
 * Character: ›
 * Unicode code point: U+203a (8250)
 * Description: single right-pointing angle quotation mark
 */
static wchar_t* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsaquo";
static int* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The overline html character entity reference model.
 *
 * Name: OverBar
 * Character: ‾
 * Unicode code point: U+203e (8254)
 * Description: overline
 */
static wchar_t* OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBar";
static int* OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The caret insertion point html character entity reference model.
 *
 * Name: caret
 * Character: ⁁
 * Unicode code point: U+2041 (8257)
 * Description: caret insertion point
 */
static wchar_t* CARET_INSERTION_POINT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"caret";
static int* CARET_INSERTION_POINT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hyphen bullet html character entity reference model.
 *
 * Name: hybull
 * Character: ⁃
 * Unicode code point: U+2043 (8259)
 * Description: hyphen bullet
 */
static wchar_t* HYPHEN_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hybull";
static int* HYPHEN_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fraction slash html character entity reference model.
 *
 * Name: frasl
 * Character: ⁄
 * Unicode code point: U+2044 (8260)
 * Description: fraction slash
 */
static wchar_t* FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frasl";
static int* FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed semicolon html character entity reference model.
 *
 * Name: bsemi
 * Character: ⁏
 * Unicode code point: U+204f (8271)
 * Description: reversed semicolon
 */
static wchar_t* REVERSED_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsemi";
static int* REVERSED_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quadruple prime html character entity reference model.
 *
 * Name: qprime
 * Character: ⁗
 * Unicode code point: U+2057 (8279)
 * Description: quadruple prime
 */
static wchar_t* QUADRUPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qprime";
static int* QUADRUPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The medium mathematical space html character entity reference model.
 *
 * Name: MediumSpace
 * Character:  
 * Unicode code point: U+205f (8287)
 * Description: medium mathematical space
 */
static wchar_t* MEDIUM_MATHEMATICAL_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"MediumSpace";
static int* MEDIUM_MATHEMATICAL_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The space of width 5/18 em html character entity reference model.
 *
 * Name: ThickSpace
 * Character:   
 * Unicode code point: U+205f;U+200a (8287;8202)
 * Description: space of width 5/18 em
 */
static wchar_t* SPACE_OF_WIDTH_5_18_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ThickSpace";
static int* SPACE_OF_WIDTH_5_18_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The word joiner html character entity reference model.
 *
 * Name: NoBreak
 * Character: ⁠
 * Unicode code point: U+2060 (8288)
 * Description: word joiner
 */
static wchar_t* WORD_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NoBreak";
static int* WORD_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The function application html character entity reference model.
 *
 * Name: ApplyFunction
 * Character: ⁡
 * Unicode code point: U+2061 (8289)
 * Description: function application
 */
static wchar_t* FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ApplyFunction";
static int* FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The invisible times html character entity reference model.
 *
 * Name: InvisibleTimes
 * Character: ⁢
 * Unicode code point: U+2062 (8290)
 * Description: invisible times
 */
static wchar_t* INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"InvisibleTimes";
static int* INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The invisible separator html character entity reference model.
 *
 * Name: InvisibleComma
 * Character: ⁣
 * Unicode code point: U+2063 (8291)
 * Description: invisible separator
 */
static wchar_t* INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"InvisibleComma";
static int* INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The euro sign html character entity reference model.
 *
 * Name: euro
 * Character: €
 * Unicode code point: U+20ac (8364)
 * Description: euro sign
 */
static wchar_t* EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euro";
static int* EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The combining three dots above html character entity reference model.
 *
 * Name: TripleDot
 * Character:  ⃛
 * Unicode code point: U+20db (8411)
 * Description: combining three dots above
 */
static wchar_t* COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TripleDot";
static int* COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The combining four dots above html character entity reference model.
 *
 * Name: DotDot
 * Character:  ⃜
 * Unicode code point: U+20dc (8412)
 * Description: combining four dots above
 */
static wchar_t* COMBINING_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DotDot";
static int* COMBINING_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital c html character entity reference model.
 *
 * Name: Copf
 * Character: ℂ
 * Unicode code point: U+2102 (8450)
 * Description: double-struck capital c
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Copf";
static int* DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The care of html character entity reference model.
 *
 * Name: incare
 * Character: ℅
 * Unicode code point: U+2105 (8453)
 * Description: care of
 */
static wchar_t* CARE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"incare";
static int* CARE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script small g html character entity reference model.
 *
 * Name: gscr
 * Character: ℊ
 * Unicode code point: U+210a (8458)
 * Description: script small g
 */
static wchar_t* SCRIPT_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gscr";
static int* SCRIPT_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital h html character entity reference model.
 *
 * Name: HilbertSpace
 * Character: ℋ
 * Unicode code point: U+210b (8459)
 * Description: script capital h
 */
static wchar_t* SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HilbertSpace";
static int* SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital h html character entity reference model.
 *
 * Name: Hfr
 * Character: ℌ
 * Unicode code point: U+210c (8460)
 * Description: black-letter capital h
 */
static wchar_t* BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hfr";
static int* BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital h html character entity reference model.
 *
 * Name: Hopf
 * Character: ℍ
 * Unicode code point: U+210d (8461)
 * Description: double-struck capital h
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hopf";
static int* DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The planck constant html character entity reference model.
 *
 * Name: planckh
 * Character: ℎ
 * Unicode code point: U+210e (8462)
 * Description: planck constant
 */
static wchar_t* PLANCK_CONSTANT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"planckh";
static int* PLANCK_CONSTANT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The planck constant over two pi html character entity reference model.
 *
 * Name: hbar
 * Character: ℏ
 * Unicode code point: U+210f (8463)
 * Description: planck constant over two pi
 */
static wchar_t* PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hbar";
static int* PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital i html character entity reference model.
 *
 * Name: Iscr
 * Character: ℐ
 * Unicode code point: U+2110 (8464)
 * Description: script capital i
 */
static wchar_t* SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iscr";
static int* SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital i html character entity reference model.
 *
 * Name: Ifr
 * Character: ℑ
 * Unicode code point: U+2111 (8465)
 * Description: black-letter capital i
 */
static wchar_t* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ifr";
static int* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital l html character entity reference model.
 *
 * Name: Laplacetrf
 * Character: ℒ
 * Unicode code point: U+2112 (8466)
 * Description: script capital l
 */
static wchar_t* SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Laplacetrf";
static int* SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script small l html character entity reference model.
 *
 * Name: ell
 * Character: ℓ
 * Unicode code point: U+2113 (8467)
 * Description: script small l
 */
static wchar_t* SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ell";
static int* SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital n html character entity reference model.
 *
 * Name: Nopf
 * Character: ℕ
 * Unicode code point: U+2115 (8469)
 * Description: double-struck capital n
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nopf";
static int* DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The numero sign html character entity reference model.
 *
 * Name: numero
 * Character: №
 * Unicode code point: U+2116 (8470)
 * Description: numero sign
 */
static wchar_t* NUMERO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"numero";
static int* NUMERO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sound recording copyright html character entity reference model.
 *
 * Name: copysr
 * Character: ℗
 * Unicode code point: U+2117 (8471)
 * Description: sound recording copyright
 */
static wchar_t* SOUND_RECORDING_COPYRIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copysr";
static int* SOUND_RECORDING_COPYRIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital p html character entity reference model.
 *
 * Name: weierp
 * Character: ℘
 * Unicode code point: U+2118 (8472)
 * Description: script capital p
 */
static wchar_t* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"weierp";
static int* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital p html character entity reference model.
 *
 * Name: Popf
 * Character: ℙ
 * Unicode code point: U+2119 (8473)
 * Description: double-struck capital p
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Popf";
static int* DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital q html character entity reference model.
 *
 * Name: Qopf
 * Character: ℚ
 * Unicode code point: U+211a (8474)
 * Description: double-struck capital q
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qopf";
static int* DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital r html character entity reference model.
 *
 * Name: Rscr
 * Character: ℛ
 * Unicode code point: U+211b (8475)
 * Description: script capital r
 */
static wchar_t* SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rscr";
static int* SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital r html character entity reference model.
 *
 * Name: Re
 * Character: ℜ
 * Unicode code point: U+211c (8476)
 * Description: black-letter capital r
 */
static wchar_t* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Re";
static int* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital r html character entity reference model.
 *
 * Name: Ropf
 * Character: ℝ
 * Unicode code point: U+211d (8477)
 * Description: double-struck capital r
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ropf";
static int* DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prescription take html character entity reference model.
 *
 * Name: rx
 * Character: ℞
 * Unicode code point: U+211e (8478)
 * Description: prescription take
 */
static wchar_t* PRESCRIPTION_TAKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rx";
static int* PRESCRIPTION_TAKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trade mark sign html character entity reference model.
 *
 * Name: TRADE
 * Character: ™
 * Unicode code point: U+2122 (8482)
 * Description: trade mark sign
 */
static wchar_t* TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TRADE";
static int* TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck capital z html character entity reference model.
 *
 * Name: Zopf
 * Character: ℤ
 * Unicode code point: U+2124 (8484)
 * Description: double-struck capital z
 */
static wchar_t* DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zopf";
static int* DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted ohm sign html character entity reference model.
 *
 * Name: mho
 * Character: ℧
 * Unicode code point: U+2127 (8487)
 * Description: inverted ohm sign
 */
static wchar_t* INVERTED_OHM_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mho";
static int* INVERTED_OHM_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital z html character entity reference model.
 *
 * Name: Zfr
 * Character: ℨ
 * Unicode code point: U+2128 (8488)
 * Description: black-letter capital z
 */
static wchar_t* BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zfr";
static int* BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The turned greek small letter iota html character entity reference model.
 *
 * Name: iiota
 * Character: ℩
 * Unicode code point: U+2129 (8489)
 * Description: turned greek small letter iota
 */
static wchar_t* TURNED_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiota";
static int* TURNED_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital b html character entity reference model.
 *
 * Name: Bernoullis
 * Character: ℬ
 * Unicode code point: U+212c (8492)
 * Description: script capital b
 */
static wchar_t* SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bernoullis";
static int* SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black-letter capital c html character entity reference model.
 *
 * Name: Cayleys
 * Character: ℭ
 * Unicode code point: U+212d (8493)
 * Description: black-letter capital c
 */
static wchar_t* BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cayleys";
static int* BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script small e html character entity reference model.
 *
 * Name: escr
 * Character: ℯ
 * Unicode code point: U+212f (8495)
 * Description: script small e
 */
static wchar_t* SCRIPT_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"escr";
static int* SCRIPT_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital e html character entity reference model.
 *
 * Name: Escr
 * Character: ℰ
 * Unicode code point: U+2130 (8496)
 * Description: script capital e
 */
static wchar_t* SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Escr";
static int* SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital f html character entity reference model.
 *
 * Name: Fouriertrf
 * Character: ℱ
 * Unicode code point: U+2131 (8497)
 * Description: script capital f
 */
static wchar_t* SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fouriertrf";
static int* SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script capital m html character entity reference model.
 *
 * Name: Mellintrf
 * Character: ℳ
 * Unicode code point: U+2133 (8499)
 * Description: script capital m
 */
static wchar_t* SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mellintrf";
static int* SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The script small o html character entity reference model.
 *
 * Name: order
 * Character: ℴ
 * Unicode code point: U+2134 (8500)
 * Description: script small o
 */
static wchar_t* SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"order";
static int* SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alef symbol html character entity reference model.
 *
 * Name: alefsym
 * Character: ℵ
 * Unicode code point: U+2135 (8501)
 * Description: alef symbol
 */
static wchar_t* ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"alefsym";
static int* ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bet symbol html character entity reference model.
 *
 * Name: beth
 * Character: ℶ
 * Unicode code point: U+2136 (8502)
 * Description: bet symbol
 */
static wchar_t* BET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"beth";
static int* BET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gimel symbol html character entity reference model.
 *
 * Name: gimel
 * Character: ℷ
 * Unicode code point: U+2137 (8503)
 * Description: gimel symbol
 */
static wchar_t* GIMEL_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gimel";
static int* GIMEL_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dalet symbol html character entity reference model.
 *
 * Name: daleth
 * Character: ℸ
 * Unicode code point: U+2138 (8504)
 * Description: dalet symbol
 */
static wchar_t* DALET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"daleth";
static int* DALET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck italic capital d html character entity reference model.
 *
 * Name: CapitalDifferentialD
 * Character: ⅅ
 * Unicode code point: U+2145 (8517)
 * Description: double-struck italic capital d
 */
static wchar_t* DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CapitalDifferentialD";
static int* DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck italic small d html character entity reference model.
 *
 * Name: DifferentialD
 * Character: ⅆ
 * Unicode code point: U+2146 (8518)
 * Description: double-struck italic small d
 */
static wchar_t* DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DifferentialD";
static int* DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck italic small e html character entity reference model.
 *
 * Name: ExponentialE
 * Character: ⅇ
 * Unicode code point: U+2147 (8519)
 * Description: double-struck italic small e
 */
static wchar_t* DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ExponentialE";
static int* DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-struck italic small i html character entity reference model.
 *
 * Name: ImaginaryI
 * Character: ⅈ
 * Unicode code point: U+2148 (8520)
 * Description: double-struck italic small i
 */
static wchar_t* DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ImaginaryI";
static int* DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one third html character entity reference model.
 *
 * Name: frac13
 * Character: ⅓
 * Unicode code point: U+2153 (8531)
 * Description: vulgar fraction one third
 */
static wchar_t* VULGAR_FRACTION_ONE_THIRD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac13";
static int* VULGAR_FRACTION_ONE_THIRD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction two thirds html character entity reference model.
 *
 * Name: frac23
 * Character: ⅔
 * Unicode code point: U+2154 (8532)
 * Description: vulgar fraction two thirds
 */
static wchar_t* VULGAR_FRACTION_TWO_THIRDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac23";
static int* VULGAR_FRACTION_TWO_THIRDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one fifth html character entity reference model.
 *
 * Name: frac15
 * Character: ⅕
 * Unicode code point: U+2155 (8533)
 * Description: vulgar fraction one fifth
 */
static wchar_t* VULGAR_FRACTION_ONE_FIFTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac15";
static int* VULGAR_FRACTION_ONE_FIFTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction two fifths html character entity reference model.
 *
 * Name: frac25
 * Character: ⅖
 * Unicode code point: U+2156 (8534)
 * Description: vulgar fraction two fifths
 */
static wchar_t* VULGAR_FRACTION_TWO_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac25";
static int* VULGAR_FRACTION_TWO_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction three fifths html character entity reference model.
 *
 * Name: frac35
 * Character: ⅗
 * Unicode code point: U+2157 (8535)
 * Description: vulgar fraction three fifths
 */
static wchar_t* VULGAR_FRACTION_THREE_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac35";
static int* VULGAR_FRACTION_THREE_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction four fifths html character entity reference model.
 *
 * Name: frac45
 * Character: ⅘
 * Unicode code point: U+2158 (8536)
 * Description: vulgar fraction four fifths
 */
static wchar_t* VULGAR_FRACTION_FOUR_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac45";
static int* VULGAR_FRACTION_FOUR_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one sixth html character entity reference model.
 *
 * Name: frac16
 * Character: ⅙
 * Unicode code point: U+2159 (8537)
 * Description: vulgar fraction one sixth
 */
static wchar_t* VULGAR_FRACTION_ONE_SIXTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac16";
static int* VULGAR_FRACTION_ONE_SIXTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction five sixths html character entity reference model.
 *
 * Name: frac56
 * Character: ⅚
 * Unicode code point: U+215a (8538)
 * Description: vulgar fraction five sixths
 */
static wchar_t* VULGAR_FRACTION_FIVE_SIXTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac56";
static int* VULGAR_FRACTION_FIVE_SIXTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction one eighth html character entity reference model.
 *
 * Name: frac18
 * Character: ⅛
 * Unicode code point: U+215b (8539)
 * Description: vulgar fraction one eighth
 */
static wchar_t* VULGAR_FRACTION_ONE_EIGHTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac18";
static int* VULGAR_FRACTION_ONE_EIGHTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction three eighths html character entity reference model.
 *
 * Name: frac38
 * Character: ⅜
 * Unicode code point: U+215c (8540)
 * Description: vulgar fraction three eighths
 */
static wchar_t* VULGAR_FRACTION_THREE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac38";
static int* VULGAR_FRACTION_THREE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction five eighths html character entity reference model.
 *
 * Name: frac58
 * Character: ⅝
 * Unicode code point: U+215d (8541)
 * Description: vulgar fraction five eighths
 */
static wchar_t* VULGAR_FRACTION_FIVE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac58";
static int* VULGAR_FRACTION_FIVE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vulgar fraction seven eighths html character entity reference model.
 *
 * Name: frac78
 * Character: ⅞
 * Unicode code point: U+215e (8542)
 * Description: vulgar fraction seven eighths
 */
static wchar_t* VULGAR_FRACTION_SEVEN_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac78";
static int* VULGAR_FRACTION_SEVEN_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow html character entity reference model.
 *
 * Name: LeftArrow
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrow";
static int* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow html character entity reference model.
 *
 * Name: ShortUpArrow
 * Character: ↑
 * Unicode code point: U+2191 (8593)
 * Description: upwards arrow
 */
static wchar_t* UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ShortUpArrow";
static int* UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow html character entity reference model.
 *
 * Name: RightArrow
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrow";
static int* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow html character entity reference model.
 *
 * Name: DownArrow
 * Character: ↓
 * Unicode code point: U+2193 (8595)
 * Description: downwards arrow
 */
static wchar_t* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrow";
static int* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right arrow html character entity reference model.
 *
 * Name: LeftRightArrow
 * Character: ↔
 * Unicode code point: U+2194 (8596)
 * Description: left right arrow
 */
static wchar_t* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftRightArrow";
static int* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up down arrow html character entity reference model.
 *
 * Name: UpDownArrow
 * Character: ↕
 * Unicode code point: U+2195 (8597)
 * Description: up down arrow
 */
static wchar_t* UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpDownArrow";
static int* UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north west arrow html character entity reference model.
 *
 * Name: UpperLeftArrow
 * Character: ↖
 * Unicode code point: U+2196 (8598)
 * Description: north west arrow
 */
static wchar_t* NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpperLeftArrow";
static int* NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north east arrow html character entity reference model.
 *
 * Name: UpperRightArrow
 * Character: ↗
 * Unicode code point: U+2197 (8599)
 * Description: north east arrow
 */
static wchar_t* NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpperRightArrow";
static int* NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south east arrow html character entity reference model.
 *
 * Name: LowerRightArrow
 * Character: ↘
 * Unicode code point: U+2198 (8600)
 * Description: south east arrow
 */
static wchar_t* SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LowerRightArrow";
static int* SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south west arrow html character entity reference model.
 *
 * Name: LowerLeftArrow
 * Character: ↙
 * Unicode code point: U+2199 (8601)
 * Description: south west arrow
 */
static wchar_t* SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LowerLeftArrow";
static int* SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow with stroke html character entity reference model.
 *
 * Name: nlarr
 * Character: ↚
 * Unicode code point: U+219a (8602)
 * Description: leftwards arrow with stroke
 */
static wchar_t* LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlarr";
static int* LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with stroke html character entity reference model.
 *
 * Name: nrarr
 * Character: ↛
 * Unicode code point: U+219b (8603)
 * Description: rightwards arrow with stroke
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarr";
static int* RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards wave arrow with slash html character entity reference model.
 *
 * Name: nrarrw
 * Character: ↝̸
 * Unicode code point: U+219d;U+0338 (8605;824)
 * Description: rightwards wave arrow with slash
 */
static wchar_t* RIGHTWARDS_WAVE_ARROW_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarrw";
static int* RIGHTWARDS_WAVE_ARROW_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards wave arrow html character entity reference model.
 *
 * Name: rarrw
 * Character: ↝
 * Unicode code point: U+219d (8605)
 * Description: rightwards wave arrow
 */
static wchar_t* RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrw";
static int* RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards two headed arrow html character entity reference model.
 *
 * Name: Larr
 * Character: ↞
 * Unicode code point: U+219e (8606)
 * Description: leftwards two headed arrow
 */
static wchar_t* LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Larr";
static int* LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards two headed arrow html character entity reference model.
 *
 * Name: Uarr
 * Character: ↟
 * Unicode code point: U+219f (8607)
 * Description: upwards two headed arrow
 */
static wchar_t* UPWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uarr";
static int* UPWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards two headed arrow html character entity reference model.
 *
 * Name: Rarr
 * Character: ↠
 * Unicode code point: U+21a0 (8608)
 * Description: rightwards two headed arrow
 */
static wchar_t* RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rarr";
static int* RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards two headed arrow html character entity reference model.
 *
 * Name: Darr
 * Character: ↡
 * Unicode code point: U+21a1 (8609)
 * Description: downwards two headed arrow
 */
static wchar_t* DOWNWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Darr";
static int* DOWNWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow with tail html character entity reference model.
 *
 * Name: larrtl
 * Character: ↢
 * Unicode code point: U+21a2 (8610)
 * Description: leftwards arrow with tail
 */
static wchar_t* LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrtl";
static int* LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with tail html character entity reference model.
 *
 * Name: rarrtl
 * Character: ↣
 * Unicode code point: U+21a3 (8611)
 * Description: rightwards arrow with tail
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrtl";
static int* RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow from bar html character entity reference model.
 *
 * Name: LeftTeeArrow
 * Character: ↤
 * Unicode code point: U+21a4 (8612)
 * Description: leftwards arrow from bar
 */
static wchar_t* LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTeeArrow";
static int* LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow from bar html character entity reference model.
 *
 * Name: UpTeeArrow
 * Character: ↥
 * Unicode code point: U+21a5 (8613)
 * Description: upwards arrow from bar
 */
static wchar_t* UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpTeeArrow";
static int* UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow from bar html character entity reference model.
 *
 * Name: RightTeeArrow
 * Character: ↦
 * Unicode code point: U+21a6 (8614)
 * Description: rightwards arrow from bar
 */
static wchar_t* RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTeeArrow";
static int* RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow from bar html character entity reference model.
 *
 * Name: DownTeeArrow
 * Character: ↧
 * Unicode code point: U+21a7 (8615)
 * Description: downwards arrow from bar
 */
static wchar_t* DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownTeeArrow";
static int* DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow with hook html character entity reference model.
 *
 * Name: hookleftarrow
 * Character: ↩
 * Unicode code point: U+21a9 (8617)
 * Description: leftwards arrow with hook
 */
static wchar_t* LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hookleftarrow";
static int* LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with hook html character entity reference model.
 *
 * Name: hookrightarrow
 * Character: ↪
 * Unicode code point: U+21aa (8618)
 * Description: rightwards arrow with hook
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hookrightarrow";
static int* RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow with loop html character entity reference model.
 *
 * Name: larrlp
 * Character: ↫
 * Unicode code point: U+21ab (8619)
 * Description: leftwards arrow with loop
 */
static wchar_t* LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrlp";
static int* LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with loop html character entity reference model.
 *
 * Name: looparrowright
 * Character: ↬
 * Unicode code point: U+21ac (8620)
 * Description: rightwards arrow with loop
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"looparrowright";
static int* RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right wave arrow html character entity reference model.
 *
 * Name: harrw
 * Character: ↭
 * Unicode code point: U+21ad (8621)
 * Description: left right wave arrow
 */
static wchar_t* LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harrw";
static int* LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right arrow with stroke html character entity reference model.
 *
 * Name: nharr
 * Character: ↮
 * Unicode code point: U+21ae (8622)
 * Description: left right arrow with stroke
 */
static wchar_t* LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nharr";
static int* LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow with tip leftwards html character entity reference model.
 *
 * Name: Lsh
 * Character: ↰
 * Unicode code point: U+21b0 (8624)
 * Description: upwards arrow with tip leftwards
 */
static wchar_t* UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lsh";
static int* UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow with tip rightwards html character entity reference model.
 *
 * Name: Rsh
 * Character: ↱
 * Unicode code point: U+21b1 (8625)
 * Description: upwards arrow with tip rightwards
 */
static wchar_t* UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rsh";
static int* UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow with tip leftwards html character entity reference model.
 *
 * Name: ldsh
 * Character: ↲
 * Unicode code point: U+21b2 (8626)
 * Description: downwards arrow with tip leftwards
 */
static wchar_t* DOWNWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldsh";
static int* DOWNWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow with tip rightwards html character entity reference model.
 *
 * Name: rdsh
 * Character: ↳
 * Unicode code point: U+21b3 (8627)
 * Description: downwards arrow with tip rightwards
 */
static wchar_t* DOWNWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdsh";
static int* DOWNWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow with corner leftwards html character entity reference model.
 *
 * Name: crarr
 * Character: ↵
 * Unicode code point: U+21b5 (8629)
 * Description: downwards arrow with corner leftwards
 */
static wchar_t* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"crarr";
static int* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The anticlockwise top semicircle arrow html character entity reference model.
 *
 * Name: cularr
 * Character: ↶
 * Unicode code point: U+21b6 (8630)
 * Description: anticlockwise top semicircle arrow
 */
static wchar_t* ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cularr";
static int* ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clockwise top semicircle arrow html character entity reference model.
 *
 * Name: curarr
 * Character: ↷
 * Unicode code point: U+21b7 (8631)
 * Description: clockwise top semicircle arrow
 */
static wchar_t* CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curarr";
static int* CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The anticlockwise open circle arrow html character entity reference model.
 *
 * Name: circlearrowleft
 * Character: ↺
 * Unicode code point: U+21ba (8634)
 * Description: anticlockwise open circle arrow
 */
static wchar_t* ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circlearrowleft";
static int* ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clockwise open circle arrow html character entity reference model.
 *
 * Name: circlearrowright
 * Character: ↻
 * Unicode code point: U+21bb (8635)
 * Description: clockwise open circle arrow
 */
static wchar_t* CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circlearrowright";
static int* CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb upwards html character entity reference model.
 *
 * Name: LeftVector
 * Character: ↼
 * Unicode code point: U+21bc (8636)
 * Description: leftwards harpoon with barb upwards
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftVector";
static int* LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb downwards html character entity reference model.
 *
 * Name: DownLeftVector
 * Character: ↽
 * Unicode code point: U+21bd (8637)
 * Description: leftwards harpoon with barb downwards
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftVector";
static int* LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb rightwards html character entity reference model.
 *
 * Name: RightUpVector
 * Character: ↾
 * Unicode code point: U+21be (8638)
 * Description: upwards harpoon with barb rightwards
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpVector";
static int* UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb leftwards html character entity reference model.
 *
 * Name: LeftUpVector
 * Character: ↿
 * Unicode code point: U+21bf (8639)
 * Description: upwards harpoon with barb leftwards
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpVector";
static int* UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb upwards html character entity reference model.
 *
 * Name: RightVector
 * Character: ⇀
 * Unicode code point: U+21c0 (8640)
 * Description: rightwards harpoon with barb upwards
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightVector";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb downwards html character entity reference model.
 *
 * Name: DownRightVector
 * Character: ⇁
 * Unicode code point: U+21c1 (8641)
 * Description: rightwards harpoon with barb downwards
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightVector";
static int* RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb rightwards html character entity reference model.
 *
 * Name: RightDownVector
 * Character: ⇂
 * Unicode code point: U+21c2 (8642)
 * Description: downwards harpoon with barb rightwards
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownVector";
static int* DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb leftwards html character entity reference model.
 *
 * Name: LeftDownVector
 * Character: ⇃
 * Unicode code point: U+21c3 (8643)
 * Description: downwards harpoon with barb leftwards
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownVector";
static int* DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow over leftwards arrow html character entity reference model.
 *
 * Name: RightArrowLeftArrow
 * Character: ⇄
 * Unicode code point: U+21c4 (8644)
 * Description: rightwards arrow over leftwards arrow
 */
static wchar_t* RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrowLeftArrow";
static int* RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow leftwards of downwards arrow html character entity reference model.
 *
 * Name: UpArrowDownArrow
 * Character: ⇅
 * Unicode code point: U+21c5 (8645)
 * Description: upwards arrow leftwards of downwards arrow
 */
static wchar_t* UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpArrowDownArrow";
static int* UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow over rightwards arrow html character entity reference model.
 *
 * Name: LeftArrowRightArrow
 * Character: ⇆
 * Unicode code point: U+21c6 (8646)
 * Description: leftwards arrow over rightwards arrow
 */
static wchar_t* LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrowRightArrow";
static int* LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards paired arrows html character entity reference model.
 *
 * Name: leftleftarrows
 * Character: ⇇
 * Unicode code point: U+21c7 (8647)
 * Description: leftwards paired arrows
 */
static wchar_t* LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftleftarrows";
static int* LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards paired arrows html character entity reference model.
 *
 * Name: upuparrows
 * Character: ⇈
 * Unicode code point: U+21c8 (8648)
 * Description: upwards paired arrows
 */
static wchar_t* UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upuparrows";
static int* UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards paired arrows html character entity reference model.
 *
 * Name: rightrightarrows
 * Character: ⇉
 * Unicode code point: U+21c9 (8649)
 * Description: rightwards paired arrows
 */
static wchar_t* RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightrightarrows";
static int* RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards paired arrows html character entity reference model.
 *
 * Name: ddarr
 * Character: ⇊
 * Unicode code point: U+21ca (8650)
 * Description: downwards paired arrows
 */
static wchar_t* DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ddarr";
static int* DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon over rightwards harpoon html character entity reference model.
 *
 * Name: ReverseEquilibrium
 * Character: ⇋
 * Unicode code point: U+21cb (8651)
 * Description: leftwards harpoon over rightwards harpoon
 */
static wchar_t* LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseEquilibrium";
static int* LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon over leftwards harpoon html character entity reference model.
 *
 * Name: Equilibrium
 * Character: ⇌
 * Unicode code point: U+21cc (8652)
 * Description: rightwards harpoon over leftwards harpoon
 */
static wchar_t* RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Equilibrium";
static int* RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double arrow with stroke html character entity reference model.
 *
 * Name: nLeftarrow
 * Character: ⇍
 * Unicode code point: U+21cd (8653)
 * Description: leftwards double arrow with stroke
 */
static wchar_t* LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLeftarrow";
static int* LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right double arrow with stroke html character entity reference model.
 *
 * Name: nLeftrightarrow
 * Character: ⇎
 * Unicode code point: U+21ce (8654)
 * Description: left right double arrow with stroke
 */
static wchar_t* LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLeftrightarrow";
static int* LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double arrow with stroke html character entity reference model.
 *
 * Name: nRightarrow
 * Character: ⇏
 * Unicode code point: U+21cf (8655)
 * Description: rightwards double arrow with stroke
 */
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nRightarrow";
static int* RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double arrow html character entity reference model.
 *
 * Name: DoubleLeftArrow
 * Character: ⇐
 * Unicode code point: U+21d0 (8656)
 * Description: leftwards double arrow
 */
static wchar_t* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLeftArrow";
static int* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards double arrow html character entity reference model.
 *
 * Name: DoubleUpArrow
 * Character: ⇑
 * Unicode code point: U+21d1 (8657)
 * Description: upwards double arrow
 */
static wchar_t* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleUpArrow";
static int* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double arrow html character entity reference model.
 *
 * Name: DoubleRightArrow
 * Character: ⇒
 * Unicode code point: U+21d2 (8658)
 * Description: rightwards double arrow
 */
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleRightArrow";
static int* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards double arrow html character entity reference model.
 *
 * Name: DoubleDownArrow
 * Character: ⇓
 * Unicode code point: U+21d3 (8659)
 * Description: downwards double arrow
 */
static wchar_t* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleDownArrow";
static int* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right double arrow html character entity reference model.
 *
 * Name: DoubleLeftRightArrow
 * Character: ⇔
 * Unicode code point: U+21d4 (8660)
 * Description: left right double arrow
 */
static wchar_t* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLeftRightArrow";
static int* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up down double arrow html character entity reference model.
 *
 * Name: DoubleUpDownArrow
 * Character: ⇕
 * Unicode code point: U+21d5 (8661)
 * Description: up down double arrow
 */
static wchar_t* UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleUpDownArrow";
static int* UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north west double arrow html character entity reference model.
 *
 * Name: nwArr
 * Character: ⇖
 * Unicode code point: U+21d6 (8662)
 * Description: north west double arrow
 */
static wchar_t* NORTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwArr";
static int* NORTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north east double arrow html character entity reference model.
 *
 * Name: neArr
 * Character: ⇗
 * Unicode code point: U+21d7 (8663)
 * Description: north east double arrow
 */
static wchar_t* NORTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"neArr";
static int* NORTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south east double arrow html character entity reference model.
 *
 * Name: seArr
 * Character: ⇘
 * Unicode code point: U+21d8 (8664)
 * Description: south east double arrow
 */
static wchar_t* SOUTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"seArr";
static int* SOUTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south west double arrow html character entity reference model.
 *
 * Name: swArr
 * Character: ⇙
 * Unicode code point: U+21d9 (8665)
 * Description: south west double arrow
 */
static wchar_t* SOUTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swArr";
static int* SOUTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards triple arrow html character entity reference model.
 *
 * Name: Lleftarrow
 * Character: ⇚
 * Unicode code point: U+21da (8666)
 * Description: leftwards triple arrow
 */
static wchar_t* LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lleftarrow";
static int* LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards triple arrow html character entity reference model.
 *
 * Name: Rrightarrow
 * Character: ⇛
 * Unicode code point: U+21db (8667)
 * Description: rightwards triple arrow
 */
static wchar_t* RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rrightarrow";
static int* RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards squiggle arrow html character entity reference model.
 *
 * Name: zigrarr
 * Character: ⇝
 * Unicode code point: U+21dd (8669)
 * Description: rightwards squiggle arrow
 */
static wchar_t* RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zigrarr";
static int* RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow to bar html character entity reference model.
 *
 * Name: LeftArrowBar
 * Character: ⇤
 * Unicode code point: U+21e4 (8676)
 * Description: leftwards arrow to bar
 */
static wchar_t* LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrowBar";
static int* LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow to bar html character entity reference model.
 *
 * Name: RightArrowBar
 * Character: ⇥
 * Unicode code point: U+21e5 (8677)
 * Description: rightwards arrow to bar
 */
static wchar_t* RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrowBar";
static int* RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow leftwards of upwards arrow html character entity reference model.
 *
 * Name: DownArrowUpArrow
 * Character: ⇵
 * Unicode code point: U+21f5 (8693)
 * Description: downwards arrow leftwards of upwards arrow
 */
static wchar_t* DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrowUpArrow";
static int* DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards open-headed arrow html character entity reference model.
 *
 * Name: loarr
 * Character: ⇽
 * Unicode code point: U+21fd (8701)
 * Description: leftwards open-headed arrow
 */
static wchar_t* LEFTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loarr";
static int* LEFTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards open-headed arrow html character entity reference model.
 *
 * Name: roarr
 * Character: ⇾
 * Unicode code point: U+21fe (8702)
 * Description: rightwards open-headed arrow
 */
static wchar_t* RIGHTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roarr";
static int* RIGHTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right open-headed arrow html character entity reference model.
 *
 * Name: hoarr
 * Character: ⇿
 * Unicode code point: U+21ff (8703)
 * Description: left right open-headed arrow
 */
static wchar_t* LEFT_RIGHT_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hoarr";
static int* LEFT_RIGHT_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The for all html character entity reference model.
 *
 * Name: ForAll
 * Character: ∀
 * Unicode code point: U+2200 (8704)
 * Description: for all
 */
static wchar_t* FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ForAll";
static int* FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The complement html character entity reference model.
 *
 * Name: comp
 * Character: ∁
 * Unicode code point: U+2201 (8705)
 * Description: complement
 */
static wchar_t* COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"comp";
static int* COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The partial differential html character entity reference model.
 *
 * Name: PartialD
 * Character: ∂
 * Unicode code point: U+2202 (8706)
 * Description: partial differential
 */
static wchar_t* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PartialD";
static int* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The partial differential with slash html character entity reference model.
 *
 * Name: npart
 * Character: ∂̸
 * Unicode code point: U+2202;U+0338 (8706;824)
 * Description: partial differential with slash
 */
static wchar_t* PARTIAL_DIFFERENTIAL_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npart";
static int* PARTIAL_DIFFERENTIAL_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The there exists html character entity reference model.
 *
 * Name: Exists
 * Character: ∃
 * Unicode code point: U+2203 (8707)
 * Description: there exists
 */
static wchar_t* THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Exists";
static int* THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The there does not exist html character entity reference model.
 *
 * Name: NotExists
 * Character: ∄
 * Unicode code point: U+2204 (8708)
 * Description: there does not exist
 */
static wchar_t* THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotExists";
static int* THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set html character entity reference model.
 *
 * Name: empty
 * Character: ∅
 * Unicode code point: U+2205 (8709)
 * Description: empty set
 */
static wchar_t* EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"empty";
static int* EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nabla html character entity reference model.
 *
 * Name: Del
 * Character: ∇
 * Unicode code point: U+2207 (8711)
 * Description: nabla
 */
static wchar_t* NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Del";
static int* NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of html character entity reference model.
 *
 * Name: Element
 * Character: ∈
 * Unicode code point: U+2208 (8712)
 * Description: element of
 */
static wchar_t* ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Element";
static int* ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not an element of html character entity reference model.
 *
 * Name: NotElement
 * Character: ∉
 * Unicode code point: U+2209 (8713)
 * Description: not an element of
 */
static wchar_t* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotElement";
static int* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains as member html character entity reference model.
 *
 * Name: ReverseElement
 * Character: ∋
 * Unicode code point: U+220b (8715)
 * Description: contains as member
 */
static wchar_t* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseElement";
static int* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not contain as member html character entity reference model.
 *
 * Name: NotReverseElement
 * Character: ∌
 * Unicode code point: U+220c (8716)
 * Description: does not contain as member
 */
static wchar_t* DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotReverseElement";
static int* DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary product html character entity reference model.
 *
 * Name: Product
 * Character: ∏
 * Unicode code point: U+220f (8719)
 * Description: n-ary product
 */
static wchar_t* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Product";
static int* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary coproduct html character entity reference model.
 *
 * Name: Coproduct
 * Character: ∐
 * Unicode code point: U+2210 (8720)
 * Description: n-ary coproduct
 */
static wchar_t* N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Coproduct";
static int* N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary summation html character entity reference model.
 *
 * Name: Sum
 * Character: ∑
 * Unicode code point: U+2211 (8721)
 * Description: n-ary summation
 */
static wchar_t* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sum";
static int* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus sign html character entity reference model.
 *
 * Name: minus
 * Character: −
 * Unicode code point: U+2212 (8722)
 * Description: minus sign
 */
static wchar_t* MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minus";
static int* MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus-or-plus sign html character entity reference model.
 *
 * Name: MinusPlus
 * Character: ∓
 * Unicode code point: U+2213 (8723)
 * Description: minus-or-plus sign
 */
static wchar_t* MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"MinusPlus";
static int* MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot plus html character entity reference model.
 *
 * Name: dotplus
 * Character: ∔
 * Unicode code point: U+2214 (8724)
 * Description: dot plus
 */
static wchar_t* DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotplus";
static int* DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The set minus html character entity reference model.
 *
 * Name: Backslash
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Backslash";
static int* SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asterisk operator html character entity reference model.
 *
 * Name: lowast
 * Character: ∗
 * Unicode code point: U+2217 (8727)
 * Description: asterisk operator
 */
static wchar_t* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lowast";
static int* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ring operator html character entity reference model.
 *
 * Name: SmallCircle
 * Character: ∘
 * Unicode code point: U+2218 (8728)
 * Description: ring operator
 */
static wchar_t* RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SmallCircle";
static int* RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square root html character entity reference model.
 *
 * Name: Sqrt
 * Character: √
 * Unicode code point: U+221a (8730)
 * Description: square root
 */
static wchar_t* SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sqrt";
static int* SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The proportional to html character entity reference model.
 *
 * Name: Proportional
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Proportional";
static int* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The infinity html character entity reference model.
 *
 * Name: infin
 * Character: ∞
 * Unicode code point: U+221e (8734)
 * Description: infinity
 */
static wchar_t* INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"infin";
static int* INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right angle html character entity reference model.
 *
 * Name: angrt
 * Character: ∟
 * Unicode code point: U+221f (8735)
 * Description: right angle
 */
static wchar_t* RIGHT_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrt";
static int* RIGHT_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angle html character entity reference model.
 *
 * Name: ang
 * Character: ∠
 * Unicode code point: U+2220 (8736)
 * Description: angle
 */
static wchar_t* ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ang";
static int* ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angle with vertical line html character entity reference model.
 *
 * Name: nang
 * Character: ∠⃒
 * Unicode code point: U+2220;U+20d2 (8736;8402)
 * Description: angle with vertical line
 */
static wchar_t* ANGLE_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nang";
static int* ANGLE_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle html character entity reference model.
 *
 * Name: angmsd
 * Character: ∡
 * Unicode code point: U+2221 (8737)
 * Description: measured angle
 */
static wchar_t* MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsd";
static int* MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The spherical angle html character entity reference model.
 *
 * Name: angsph
 * Character: ∢
 * Unicode code point: U+2222 (8738)
 * Description: spherical angle
 */
static wchar_t* SPHERICAL_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angsph";
static int* SPHERICAL_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The divides html character entity reference model.
 *
 * Name: VerticalBar
 * Character: ∣
 * Unicode code point: U+2223 (8739)
 * Description: divides
 */
static wchar_t* DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalBar";
static int* DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not divide html character entity reference model.
 *
 * Name: NotVerticalBar
 * Character: ∤
 * Unicode code point: U+2224 (8740)
 * Description: does not divide
 */
static wchar_t* DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotVerticalBar";
static int* DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parallel to html character entity reference model.
 *
 * Name: DoubleVerticalBar
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleVerticalBar";
static int* PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not parallel to html character entity reference model.
 *
 * Name: NotDoubleVerticalBar
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotDoubleVerticalBar";
static int* NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical and html character entity reference model.
 *
 * Name: and
 * Character: ∧
 * Unicode code point: U+2227 (8743)
 * Description: logical and
 */
static wchar_t* LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"and";
static int* LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical or html character entity reference model.
 *
 * Name: or
 * Character: ∨
 * Unicode code point: U+2228 (8744)
 * Description: logical or
 */
static wchar_t* LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"or";
static int* LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection html character entity reference model.
 *
 * Name: cap
 * Character: ∩
 * Unicode code point: U+2229 (8745)
 * Description: intersection
 */
static wchar_t* INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cap";
static int* INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection with serifs html character entity reference model.
 *
 * Name: caps
 * Character: ∩︀
 * Unicode code point: U+2229;U+fe00 (8745;65024)
 * Description: intersection with serifs
 */
static wchar_t* INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"caps";
static int* INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union html character entity reference model.
 *
 * Name: cup
 * Character: ∪
 * Unicode code point: U+222a (8746)
 * Description: union
 */
static wchar_t* UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cup";
static int* UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union with serifs html character entity reference model.
 *
 * Name: cups
 * Character: ∪︀
 * Unicode code point: U+222a;U+fe00 (8746;65024)
 * Description: union with serifs
 */
static wchar_t* UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cups";
static int* UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The integral html character entity reference model.
 *
 * Name: Integral
 * Character: ∫
 * Unicode code point: U+222b (8747)
 * Description: integral
 */
static wchar_t* INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Integral";
static int* INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double integral html character entity reference model.
 *
 * Name: Int
 * Character: ∬
 * Unicode code point: U+222c (8748)
 * Description: double integral
 */
static wchar_t* DOUBLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Int";
static int* DOUBLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triple integral html character entity reference model.
 *
 * Name: iiint
 * Character: ∭
 * Unicode code point: U+222d (8749)
 * Description: triple integral
 */
static wchar_t* TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiint";
static int* TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contour integral html character entity reference model.
 *
 * Name: ContourIntegral
 * Character: ∮
 * Unicode code point: U+222e (8750)
 * Description: contour integral
 */
static wchar_t* CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ContourIntegral";
static int* CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The surface integral html character entity reference model.
 *
 * Name: Conint
 * Character: ∯
 * Unicode code point: U+222f (8751)
 * Description: surface integral
 */
static wchar_t* SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Conint";
static int* SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The volume integral html character entity reference model.
 *
 * Name: Cconint
 * Character: ∰
 * Unicode code point: U+2230 (8752)
 * Description: volume integral
 */
static wchar_t* VOLUME_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cconint";
static int* VOLUME_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clockwise integral html character entity reference model.
 *
 * Name: cwint
 * Character: ∱
 * Unicode code point: U+2231 (8753)
 * Description: clockwise integral
 */
static wchar_t* CLOCKWISE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cwint";
static int* CLOCKWISE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clockwise contour integral html character entity reference model.
 *
 * Name: ClockwiseContourIntegral
 * Character: ∲
 * Unicode code point: U+2232 (8754)
 * Description: clockwise contour integral
 */
static wchar_t* CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ClockwiseContourIntegral";
static int* CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The anticlockwise contour integral html character entity reference model.
 *
 * Name: CounterClockwiseContourIntegral
 * Character: ∳
 * Unicode code point: U+2233 (8755)
 * Description: anticlockwise contour integral
 */
static wchar_t* ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CounterClockwiseContourIntegral";
static int* ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The therefore html character entity reference model.
 *
 * Name: Therefore
 * Character: ∴
 * Unicode code point: U+2234 (8756)
 * Description: therefore
 */
static wchar_t* THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Therefore";
static int* THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The because html character entity reference model.
 *
 * Name: Because
 * Character: ∵
 * Unicode code point: U+2235 (8757)
 * Description: because
 */
static wchar_t* BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Because";
static int* BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ratio html character entity reference model.
 *
 * Name: ratio
 * Character: ∶
 * Unicode code point: U+2236 (8758)
 * Description: ratio
 */
static wchar_t* RATIO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ratio";
static int* RATIO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The proportion html character entity reference model.
 *
 * Name: Colon
 * Character: ∷
 * Unicode code point: U+2237 (8759)
 * Description: proportion
 */
static wchar_t* PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Colon";
static int* PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot minus html character entity reference model.
 *
 * Name: dotminus
 * Character: ∸
 * Unicode code point: U+2238 (8760)
 * Description: dot minus
 */
static wchar_t* DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotminus";
static int* DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geometric proportion html character entity reference model.
 *
 * Name: mDDot
 * Character: ∺
 * Unicode code point: U+223a (8762)
 * Description: geometric proportion
 */
static wchar_t* GEOMETRIC_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mDDot";
static int* GEOMETRIC_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The homothetic html character entity reference model.
 *
 * Name: homtht
 * Character: ∻
 * Unicode code point: U+223b (8763)
 * Description: homothetic
 */
static wchar_t* HOMOTHETIC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"homtht";
static int* HOMOTHETIC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde operator html character entity reference model.
 *
 * Name: Tilde
 * Character: ∼
 * Unicode code point: U+223c (8764)
 * Description: tilde operator
 */
static wchar_t* TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tilde";
static int* TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde operator with vertical line html character entity reference model.
 *
 * Name: nvsim
 * Character: ∼⃒
 * Unicode code point: U+223c;U+20d2 (8764;8402)
 * Description: tilde operator with vertical line
 */
static wchar_t* TILDE_OPERATOR_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvsim";
static int* TILDE_OPERATOR_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed tilde html character entity reference model.
 *
 * Name: backsim
 * Character: ∽
 * Unicode code point: U+223d (8765)
 * Description: reversed tilde
 */
static wchar_t* REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backsim";
static int* REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed tilde with underline html character entity reference model.
 *
 * Name: race
 * Character: ∽̱
 * Unicode code point: U+223d;U+0331 (8765;817)
 * Description: reversed tilde with underline
 */
static wchar_t* REVERSED_TILDE_WITH_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"race";
static int* REVERSED_TILDE_WITH_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted lazy s html character entity reference model.
 *
 * Name: ac
 * Character: ∾
 * Unicode code point: U+223e (8766)
 * Description: inverted lazy s
 */
static wchar_t* INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ac";
static int* INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverted lazy s with double underline html character entity reference model.
 *
 * Name: acE
 * Character: ∾̳
 * Unicode code point: U+223e;U+0333 (8766;819)
 * Description: inverted lazy s with double underline
 */
static wchar_t* INVERTED_LAZY_S_WITH_DOUBLE_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acE";
static int* INVERTED_LAZY_S_WITH_DOUBLE_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sine wave html character entity reference model.
 *
 * Name: acd
 * Character: ∿
 * Unicode code point: U+223f (8767)
 * Description: sine wave
 */
static wchar_t* SINE_WAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acd";
static int* SINE_WAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wreath product html character entity reference model.
 *
 * Name: VerticalTilde
 * Character: ≀
 * Unicode code point: U+2240 (8768)
 * Description: wreath product
 */
static wchar_t* WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalTilde";
static int* WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not tilde html character entity reference model.
 *
 * Name: NotTilde
 * Character: ≁
 * Unicode code point: U+2241 (8769)
 * Description: not tilde
 */
static wchar_t* NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTilde";
static int* NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus tilde html character entity reference model.
 *
 * Name: EqualTilde
 * Character: ≂
 * Unicode code point: U+2242 (8770)
 * Description: minus tilde
 */
static wchar_t* MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EqualTilde";
static int* MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus tilde with slash html character entity reference model.
 *
 * Name: NotEqualTilde
 * Character: ≂̸
 * Unicode code point: U+2242;U+0338 (8770;824)
 * Description: minus tilde with slash
 */
static wchar_t* MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotEqualTilde";
static int* MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asymptotically equal to html character entity reference model.
 *
 * Name: TildeEqual
 * Character: ≃
 * Unicode code point: U+2243 (8771)
 * Description: asymptotically equal to
 */
static wchar_t* ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeEqual";
static int* ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not asymptotically equal to html character entity reference model.
 *
 * Name: NotTildeEqual
 * Character: ≄
 * Unicode code point: U+2244 (8772)
 * Description: not asymptotically equal to
 */
static wchar_t* NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeEqual";
static int* NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approximately equal to html character entity reference model.
 *
 * Name: TildeFullEqual
 * Character: ≅
 * Unicode code point: U+2245 (8773)
 * Description: approximately equal to
 */
static wchar_t* APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeFullEqual";
static int* APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approximately but not actually equal to html character entity reference model.
 *
 * Name: simne
 * Character: ≆
 * Unicode code point: U+2246 (8774)
 * Description: approximately but not actually equal to
 */
static wchar_t* APPROXIMATELY_BUT_NOT_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simne";
static int* APPROXIMATELY_BUT_NOT_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither approximately nor actually equal to html character entity reference model.
 *
 * Name: NotTildeFullEqual
 * Character: ≇
 * Unicode code point: U+2247 (8775)
 * Description: neither approximately nor actually equal to
 */
static wchar_t* NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeFullEqual";
static int* NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The almost equal to html character entity reference model.
 *
 * Name: TildeTilde
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeTilde";
static int* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not almost equal to html character entity reference model.
 *
 * Name: NotTildeTilde
 * Character: ≉
 * Unicode code point: U+2249 (8777)
 * Description: not almost equal to
 */
static wchar_t* NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeTilde";
static int* NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The almost equal or equal to html character entity reference model.
 *
 * Name: ape
 * Character: ≊
 * Unicode code point: U+224a (8778)
 * Description: almost equal or equal to
 */
static wchar_t* ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ape";
static int* ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triple tilde html character entity reference model.
 *
 * Name: apid
 * Character: ≋
 * Unicode code point: U+224b (8779)
 * Description: triple tilde
 */
static wchar_t* TRIPLE_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apid";
static int* TRIPLE_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triple tilde with slash html character entity reference model.
 *
 * Name: napid
 * Character: ≋̸
 * Unicode code point: U+224b;U+0338 (8779;824)
 * Description: triple tilde with slash
 */
static wchar_t* TRIPLE_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napid";
static int* TRIPLE_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The all equal to html character entity reference model.
 *
 * Name: backcong
 * Character: ≌
 * Unicode code point: U+224c (8780)
 * Description: all equal to
 */
static wchar_t* ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backcong";
static int* ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equivalent to html character entity reference model.
 *
 * Name: CupCap
 * Character: ≍
 * Unicode code point: U+224d (8781)
 * Description: equivalent to
 */
static wchar_t* EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CupCap";
static int* EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equivalent to with vertical line html character entity reference model.
 *
 * Name: nvap
 * Character: ≍⃒
 * Unicode code point: U+224d;U+20d2 (8781;8402)
 * Description: equivalent to with vertical line
 */
static wchar_t* EQUIVALENT_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvap";
static int* EQUIVALENT_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geometrically equivalent to html character entity reference model.
 *
 * Name: Bumpeq
 * Character: ≎
 * Unicode code point: U+224e (8782)
 * Description: geometrically equivalent to
 */
static wchar_t* GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bumpeq";
static int* GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geometrically equivalent to with slash html character entity reference model.
 *
 * Name: NotHumpDownHump
 * Character: ≎̸
 * Unicode code point: U+224e;U+0338 (8782;824)
 * Description: geometrically equivalent to with slash
 */
static wchar_t* GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotHumpDownHump";
static int* GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The difference between html character entity reference model.
 *
 * Name: HumpEqual
 * Character: ≏
 * Unicode code point: U+224f (8783)
 * Description: difference between
 */
static wchar_t* DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HumpEqual";
static int* DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The difference between with slash html character entity reference model.
 *
 * Name: NotHumpEqual
 * Character: ≏̸
 * Unicode code point: U+224f;U+0338 (8783;824)
 * Description: difference between with slash
 */
static wchar_t* DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotHumpEqual";
static int* DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approaches the limit html character entity reference model.
 *
 * Name: DotEqual
 * Character: ≐
 * Unicode code point: U+2250 (8784)
 * Description: approaches the limit
 */
static wchar_t* APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DotEqual";
static int* APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approaches the limit with slash html character entity reference model.
 *
 * Name: nedot
 * Character: ≐̸
 * Unicode code point: U+2250;U+0338 (8784;824)
 * Description: approaches the limit with slash
 */
static wchar_t* APPROACHES_THE_LIMIT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nedot";
static int* APPROACHES_THE_LIMIT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geometrically equal to html character entity reference model.
 *
 * Name: doteqdot
 * Character: ≑
 * Unicode code point: U+2251 (8785)
 * Description: geometrically equal to
 */
static wchar_t* GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"doteqdot";
static int* GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approximately equal to or the image of html character entity reference model.
 *
 * Name: efDot
 * Character: ≒
 * Unicode code point: U+2252 (8786)
 * Description: approximately equal to or the image of
 */
static wchar_t* APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"efDot";
static int* APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image of or approximately equal to html character entity reference model.
 *
 * Name: erDot
 * Character: ≓
 * Unicode code point: U+2253 (8787)
 * Description: image of or approximately equal to
 */
static wchar_t* IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"erDot";
static int* IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colon equals html character entity reference model.
 *
 * Name: Assign
 * Character: ≔
 * Unicode code point: U+2254 (8788)
 * Description: colon equals
 */
static wchar_t* COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Assign";
static int* COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals colon html character entity reference model.
 *
 * Name: ecolon
 * Character: ≕
 * Unicode code point: U+2255 (8789)
 * Description: equals colon
 */
static wchar_t* EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecolon";
static int* EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ring in equal to html character entity reference model.
 *
 * Name: ecir
 * Character: ≖
 * Unicode code point: U+2256 (8790)
 * Description: ring in equal to
 */
static wchar_t* RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecir";
static int* RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ring equal to html character entity reference model.
 *
 * Name: circeq
 * Character: ≗
 * Unicode code point: U+2257 (8791)
 * Description: ring equal to
 */
static wchar_t* RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circeq";
static int* RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The estimates html character entity reference model.
 *
 * Name: wedgeq
 * Character: ≙
 * Unicode code point: U+2259 (8793)
 * Description: estimates
 */
static wchar_t* ESTIMATES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wedgeq";
static int* ESTIMATES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equiangular to html character entity reference model.
 *
 * Name: veeeq
 * Character: ≚
 * Unicode code point: U+225a (8794)
 * Description: equiangular to
 */
static wchar_t* EQUIANGULAR_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"veeeq";
static int* EQUIANGULAR_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The delta equal to html character entity reference model.
 *
 * Name: triangleq
 * Character: ≜
 * Unicode code point: U+225c (8796)
 * Description: delta equal to
 */
static wchar_t* DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangleq";
static int* DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The questioned equal to html character entity reference model.
 *
 * Name: equest
 * Character: ≟
 * Unicode code point: U+225f (8799)
 * Description: questioned equal to
 */
static wchar_t* QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equest";
static int* QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not equal to html character entity reference model.
 *
 * Name: NotEqual
 * Character: ≠
 * Unicode code point: U+2260 (8800)
 * Description: not equal to
 */
static wchar_t* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotEqual";
static int* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identical to html character entity reference model.
 *
 * Name: Congruent
 * Character: ≡
 * Unicode code point: U+2261 (8801)
 * Description: identical to
 */
static wchar_t* IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Congruent";
static int* IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identical to with reverse slash html character entity reference model.
 *
 * Name: bnequiv
 * Character: ≡⃥
 * Unicode code point: U+2261;U+20e5 (8801;8421)
 * Description: identical to with reverse slash
 */
static wchar_t* IDENTICAL_TO_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bnequiv";
static int* IDENTICAL_TO_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not identical to html character entity reference model.
 *
 * Name: NotCongruent
 * Character: ≢
 * Unicode code point: U+2262 (8802)
 * Description: not identical to
 */
static wchar_t* NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotCongruent";
static int* NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or equal to html character entity reference model.
 *
 * Name: le
 * Character: ≤
 * Unicode code point: U+2264 (8804)
 * Description: less-than or equal to
 */
static wchar_t* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"le";
static int* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or equal to with vertical line html character entity reference model.
 *
 * Name: nvle
 * Character: ≤⃒
 * Unicode code point: U+2264;U+20d2 (8804;8402)
 * Description: less-than or equal to with vertical line
 */
static wchar_t* LESS_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvle";
static int* LESS_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or equal to html character entity reference model.
 *
 * Name: GreaterEqual
 * Character: ≥
 * Unicode code point: U+2265 (8805)
 * Description: greater-than or equal to
 */
static wchar_t* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterEqual";
static int* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or equal to with vertical line html character entity reference model.
 *
 * Name: nvge
 * Character: ≥⃒
 * Unicode code point: U+2265;U+20d2 (8805;8402)
 * Description: greater-than or equal to with vertical line
 */
static wchar_t* GREATER_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvge";
static int* GREATER_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than over equal to html character entity reference model.
 *
 * Name: LessFullEqual
 * Character: ≦
 * Unicode code point: U+2266 (8806)
 * Description: less-than over equal to
 */
static wchar_t* LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessFullEqual";
static int* LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than over equal to with slash html character entity reference model.
 *
 * Name: nlE
 * Character: ≦̸
 * Unicode code point: U+2266;U+0338 (8806;824)
 * Description: less-than over equal to with slash
 */
static wchar_t* LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlE";
static int* LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than over equal to html character entity reference model.
 *
 * Name: GreaterFullEqual
 * Character: ≧
 * Unicode code point: U+2267 (8807)
 * Description: greater-than over equal to
 */
static wchar_t* GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterFullEqual";
static int* GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than over equal to with slash html character entity reference model.
 *
 * Name: NotGreaterFullEqual
 * Character: ≧̸
 * Unicode code point: U+2267;U+0338 (8807;824)
 * Description: greater-than over equal to with slash
 */
static wchar_t* GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterFullEqual";
static int* GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than but not equal to html character entity reference model.
 *
 * Name: lnE
 * Character: ≨
 * Unicode code point: U+2268 (8808)
 * Description: less-than but not equal to
 */
static wchar_t* LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnE";
static int* LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than but not equal to - with vertical stroke html character entity reference model.
 *
 * Name: lvertneqq
 * Character: ≨︀
 * Unicode code point: U+2268;U+fe00 (8808;65024)
 * Description: less-than but not equal to - with vertical stroke
 */
static wchar_t* LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lvertneqq";
static int* LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than but not equal to html character entity reference model.
 *
 * Name: gnE
 * Character: ≩
 * Unicode code point: U+2269 (8809)
 * Description: greater-than but not equal to
 */
static wchar_t* GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnE";
static int* GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than but not equal to - with vertical stroke html character entity reference model.
 *
 * Name: gvertneqq
 * Character: ≩︀
 * Unicode code point: U+2269;U+fe00 (8809;65024)
 * Description: greater-than but not equal to - with vertical stroke
 */
static wchar_t* GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gvertneqq";
static int* GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much less-than html character entity reference model.
 *
 * Name: Lt
 * Character: ≪
 * Unicode code point: U+226a (8810)
 * Description: much less-than
 */
static wchar_t* MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lt";
static int* MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much less than with slash html character entity reference model.
 *
 * Name: NotLessLess
 * Character: ≪̸
 * Unicode code point: U+226a;U+0338 (8810;824)
 * Description: much less than with slash
 */
static wchar_t* MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessLess";
static int* MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much less than with vertical line html character entity reference model.
 *
 * Name: nLt
 * Character: ≪⃒
 * Unicode code point: U+226a;U+20d2 (8810;8402)
 * Description: much less than with vertical line
 */
static wchar_t* MUCH_LESS_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLt";
static int* MUCH_LESS_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much greater-than html character entity reference model.
 *
 * Name: Gt
 * Character: ≫
 * Unicode code point: U+226b (8811)
 * Description: much greater-than
 */
static wchar_t* MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gt";
static int* MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much greater than with slash html character entity reference model.
 *
 * Name: NotGreaterGreater
 * Character: ≫̸
 * Unicode code point: U+226b;U+0338 (8811;824)
 * Description: much greater than with slash
 */
static wchar_t* MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterGreater";
static int* MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The much greater than with vertical line html character entity reference model.
 *
 * Name: nGt
 * Character: ≫⃒
 * Unicode code point: U+226b;U+20d2 (8811;8402)
 * Description: much greater than with vertical line
 */
static wchar_t* MUCH_GREATER_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nGt";
static int* MUCH_GREATER_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The between html character entity reference model.
 *
 * Name: between
 * Character: ≬
 * Unicode code point: U+226c (8812)
 * Description: between
 */
static wchar_t* BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"between";
static int* BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not equivalent to html character entity reference model.
 *
 * Name: NotCupCap
 * Character: ≭
 * Unicode code point: U+226d (8813)
 * Description: not equivalent to
 */
static wchar_t* NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotCupCap";
static int* NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not less-than html character entity reference model.
 *
 * Name: NotLess
 * Character: ≮
 * Unicode code point: U+226e (8814)
 * Description: not less-than
 */
static wchar_t* NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLess";
static int* NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not greater-than html character entity reference model.
 *
 * Name: NotGreater
 * Character: ≯
 * Unicode code point: U+226f (8815)
 * Description: not greater-than
 */
static wchar_t* NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreater";
static int* NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither less-than nor equal to html character entity reference model.
 *
 * Name: NotLessEqual
 * Character: ≰
 * Unicode code point: U+2270 (8816)
 * Description: neither less-than nor equal to
 */
static wchar_t* NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessEqual";
static int* NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither greater-than nor equal to html character entity reference model.
 *
 * Name: NotGreaterEqual
 * Character: ≱
 * Unicode code point: U+2271 (8817)
 * Description: neither greater-than nor equal to
 */
static wchar_t* NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterEqual";
static int* NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or equivalent to html character entity reference model.
 *
 * Name: LessTilde
 * Character: ≲
 * Unicode code point: U+2272 (8818)
 * Description: less-than or equivalent to
 */
static wchar_t* LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessTilde";
static int* LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or equivalent to html character entity reference model.
 *
 * Name: GreaterTilde
 * Character: ≳
 * Unicode code point: U+2273 (8819)
 * Description: greater-than or equivalent to
 */
static wchar_t* GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterTilde";
static int* GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither less-than nor equivalent to html character entity reference model.
 *
 * Name: NotLessTilde
 * Character: ≴
 * Unicode code point: U+2274 (8820)
 * Description: neither less-than nor equivalent to
 */
static wchar_t* NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessTilde";
static int* NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither greater-than nor equivalent to html character entity reference model.
 *
 * Name: NotGreaterTilde
 * Character: ≵
 * Unicode code point: U+2275 (8821)
 * Description: neither greater-than nor equivalent to
 */
static wchar_t* NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterTilde";
static int* NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or greater-than html character entity reference model.
 *
 * Name: LessGreater
 * Character: ≶
 * Unicode code point: U+2276 (8822)
 * Description: less-than or greater-than
 */
static wchar_t* LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessGreater";
static int* LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or less-than html character entity reference model.
 *
 * Name: GreaterLess
 * Character: ≷
 * Unicode code point: U+2277 (8823)
 * Description: greater-than or less-than
 */
static wchar_t* GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterLess";
static int* GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither less-than nor greater-than html character entity reference model.
 *
 * Name: NotLessGreater
 * Character: ≸
 * Unicode code point: U+2278 (8824)
 * Description: neither less-than nor greater-than
 */
static wchar_t* NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessGreater";
static int* NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither greater-than nor less-than html character entity reference model.
 *
 * Name: NotGreaterLess
 * Character: ≹
 * Unicode code point: U+2279 (8825)
 * Description: neither greater-than nor less-than
 */
static wchar_t* NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterLess";
static int* NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes html character entity reference model.
 *
 * Name: Precedes
 * Character: ≺
 * Unicode code point: U+227a (8826)
 * Description: precedes
 */
static wchar_t* PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Precedes";
static int* PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds html character entity reference model.
 *
 * Name: Succeeds
 * Character: ≻
 * Unicode code point: U+227b (8827)
 * Description: succeeds
 */
static wchar_t* SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Succeeds";
static int* SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes or equal to html character entity reference model.
 *
 * Name: PrecedesSlantEqual
 * Character: ≼
 * Unicode code point: U+227c (8828)
 * Description: precedes or equal to
 */
static wchar_t* PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesSlantEqual";
static int* PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds or equal to html character entity reference model.
 *
 * Name: SucceedsSlantEqual
 * Character: ≽
 * Unicode code point: U+227d (8829)
 * Description: succeeds or equal to
 */
static wchar_t* SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsSlantEqual";
static int* SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes or equivalent to html character entity reference model.
 *
 * Name: PrecedesTilde
 * Character: ≾
 * Unicode code point: U+227e (8830)
 * Description: precedes or equivalent to
 */
static wchar_t* PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesTilde";
static int* PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds or equivalent to with slash html character entity reference model.
 *
 * Name: NotSucceedsTilde
 * Character: ≿̸
 * Unicode code point: U+227f;U+0338 (8831;824)
 * Description: succeeds or equivalent to with slash
 */
static wchar_t* SUCCEEDS_OR_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsTilde";
static int* SUCCEEDS_OR_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds or equivalent to html character entity reference model.
 *
 * Name: SucceedsTilde
 * Character: ≿
 * Unicode code point: U+227f (8831)
 * Description: succeeds or equivalent to
 */
static wchar_t* SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsTilde";
static int* SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not precede html character entity reference model.
 *
 * Name: NotPrecedes
 * Character: ⊀
 * Unicode code point: U+2280 (8832)
 * Description: does not precede
 */
static wchar_t* DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedes";
static int* DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not succeed html character entity reference model.
 *
 * Name: NotSucceeds
 * Character: ⊁
 * Unicode code point: U+2281 (8833)
 * Description: does not succeed
 */
static wchar_t* DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceeds";
static int* DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of with vertical line html character entity reference model.
 *
 * Name: NotSubset
 * Character: ⊂⃒
 * Unicode code point: U+2282;U+20d2 (8834;8402)
 * Description: subset of with vertical line
 */
static wchar_t* SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSubset";
static int* SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of html character entity reference model.
 *
 * Name: sub
 * Character: ⊂
 * Unicode code point: U+2282 (8834)
 * Description: subset of
 */
static wchar_t* SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sub";
static int* SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of with vertical line html character entity reference model.
 *
 * Name: NotSuperset
 * Character: ⊃⃒
 * Unicode code point: U+2283;U+20d2 (8835;8402)
 * Description: superset of with vertical line
 */
static wchar_t* SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSuperset";
static int* SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of html character entity reference model.
 *
 * Name: Superset
 * Character: ⊃
 * Unicode code point: U+2283 (8835)
 * Description: superset of
 */
static wchar_t* SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Superset";
static int* SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not a subset of html character entity reference model.
 *
 * Name: nsub
 * Character: ⊄
 * Unicode code point: U+2284 (8836)
 * Description: not a subset of
 */
static wchar_t* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsub";
static int* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not a superset of html character entity reference model.
 *
 * Name: nsup
 * Character: ⊅
 * Unicode code point: U+2285 (8837)
 * Description: not a superset of
 */
static wchar_t* NOT_A_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsup";
static int* NOT_A_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of or equal to html character entity reference model.
 *
 * Name: SubsetEqual
 * Character: ⊆
 * Unicode code point: U+2286 (8838)
 * Description: subset of or equal to
 */
static wchar_t* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SubsetEqual";
static int* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of or equal to html character entity reference model.
 *
 * Name: SupersetEqual
 * Character: ⊇
 * Unicode code point: U+2287 (8839)
 * Description: superset of or equal to
 */
static wchar_t* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SupersetEqual";
static int* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither a subset of nor equal to html character entity reference model.
 *
 * Name: NotSubsetEqual
 * Character: ⊈
 * Unicode code point: U+2288 (8840)
 * Description: neither a subset of nor equal to
 */
static wchar_t* NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSubsetEqual";
static int* NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neither a superset of nor equal to html character entity reference model.
 *
 * Name: NotSupersetEqual
 * Character: ⊉
 * Unicode code point: U+2289 (8841)
 * Description: neither a superset of nor equal to
 */
static wchar_t* NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSupersetEqual";
static int* NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of with not equal to html character entity reference model.
 *
 * Name: subne
 * Character: ⊊
 * Unicode code point: U+228a (8842)
 * Description: subset of with not equal to
 */
static wchar_t* SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subne";
static int* SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of with not equal to - variant with stroke through bottom members html character entity reference model.
 *
 * Name: varsubsetneq
 * Character: ⊊︀
 * Unicode code point: U+228a;U+fe00 (8842;65024)
 * Description: subset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsubsetneq";
static int* SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of with not equal to html character entity reference model.
 *
 * Name: supne
 * Character: ⊋
 * Unicode code point: U+228b (8843)
 * Description: superset of with not equal to
 */
static wchar_t* SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supne";
static int* SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of with not equal to - variant with stroke through bottom members html character entity reference model.
 *
 * Name: varsupsetneq
 * Character: ⊋︀
 * Unicode code point: U+228b;U+fe00 (8843;65024)
 * Description: superset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsupsetneq";
static int* SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiset multiplication html character entity reference model.
 *
 * Name: cupdot
 * Character: ⊍
 * Unicode code point: U+228d (8845)
 * Description: multiset multiplication
 */
static wchar_t* MULTISET_MULTIPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupdot";
static int* MULTISET_MULTIPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiset union html character entity reference model.
 *
 * Name: UnionPlus
 * Character: ⊎
 * Unicode code point: U+228e (8846)
 * Description: multiset union
 */
static wchar_t* MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnionPlus";
static int* MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square image of with slash html character entity reference model.
 *
 * Name: NotSquareSubset
 * Character: ⊏̸
 * Unicode code point: U+228f;U+0338 (8847;824)
 * Description: square image of with slash
 */
static wchar_t* SQUARE_IMAGE_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSubset";
static int* SQUARE_IMAGE_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square image of html character entity reference model.
 *
 * Name: SquareSubset
 * Character: ⊏
 * Unicode code point: U+228f (8847)
 * Description: square image of
 */
static wchar_t* SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSubset";
static int* SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square original of with slash html character entity reference model.
 *
 * Name: NotSquareSuperset
 * Character: ⊐̸
 * Unicode code point: U+2290;U+0338 (8848;824)
 * Description: square original of with slash
 */
static wchar_t* SQUARE_ORIGINAL_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSuperset";
static int* SQUARE_ORIGINAL_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square original of html character entity reference model.
 *
 * Name: SquareSuperset
 * Character: ⊐
 * Unicode code point: U+2290 (8848)
 * Description: square original of
 */
static wchar_t* SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSuperset";
static int* SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square image of or equal to html character entity reference model.
 *
 * Name: SquareSubsetEqual
 * Character: ⊑
 * Unicode code point: U+2291 (8849)
 * Description: square image of or equal to
 */
static wchar_t* SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSubsetEqual";
static int* SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square original of or equal to html character entity reference model.
 *
 * Name: SquareSupersetEqual
 * Character: ⊒
 * Unicode code point: U+2292 (8850)
 * Description: square original of or equal to
 */
static wchar_t* SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSupersetEqual";
static int* SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square cap html character entity reference model.
 *
 * Name: SquareIntersection
 * Character: ⊓
 * Unicode code point: U+2293 (8851)
 * Description: square cap
 */
static wchar_t* SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareIntersection";
static int* SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square cap with serifs html character entity reference model.
 *
 * Name: sqcaps
 * Character: ⊓︀
 * Unicode code point: U+2293;U+fe00 (8851;65024)
 * Description: square cap with serifs
 */
static wchar_t* SQUARE_CAP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcaps";
static int* SQUARE_CAP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square cup html character entity reference model.
 *
 * Name: SquareUnion
 * Character: ⊔
 * Unicode code point: U+2294 (8852)
 * Description: square cup
 */
static wchar_t* SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareUnion";
static int* SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square cup with serifs html character entity reference model.
 *
 * Name: sqcups
 * Character: ⊔︀
 * Unicode code point: U+2294;U+fe00 (8852;65024)
 * Description: square cup with serifs
 */
static wchar_t* SQUARE_CUP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcups";
static int* SQUARE_CUP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled plus html character entity reference model.
 *
 * Name: CirclePlus
 * Character: ⊕
 * Unicode code point: U+2295 (8853)
 * Description: circled plus
 */
static wchar_t* CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CirclePlus";
static int* CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled minus html character entity reference model.
 *
 * Name: CircleMinus
 * Character: ⊖
 * Unicode code point: U+2296 (8854)
 * Description: circled minus
 */
static wchar_t* CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleMinus";
static int* CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled times html character entity reference model.
 *
 * Name: CircleTimes
 * Character: ⊗
 * Unicode code point: U+2297 (8855)
 * Description: circled times
 */
static wchar_t* CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleTimes";
static int* CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled division slash html character entity reference model.
 *
 * Name: osol
 * Character: ⊘
 * Unicode code point: U+2298 (8856)
 * Description: circled division slash
 */
static wchar_t* CIRCLED_DIVISION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"osol";
static int* CIRCLED_DIVISION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled dot operator html character entity reference model.
 *
 * Name: CircleDot
 * Character: ⊙
 * Unicode code point: U+2299 (8857)
 * Description: circled dot operator
 */
static wchar_t* CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleDot";
static int* CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled ring operator html character entity reference model.
 *
 * Name: circledcirc
 * Character: ⊚
 * Unicode code point: U+229a (8858)
 * Description: circled ring operator
 */
static wchar_t* CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledcirc";
static int* CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled asterisk operator html character entity reference model.
 *
 * Name: circledast
 * Character: ⊛
 * Unicode code point: U+229b (8859)
 * Description: circled asterisk operator
 */
static wchar_t* CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledast";
static int* CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled dash html character entity reference model.
 *
 * Name: circleddash
 * Character: ⊝
 * Unicode code point: U+229d (8861)
 * Description: circled dash
 */
static wchar_t* CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circleddash";
static int* CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared plus html character entity reference model.
 *
 * Name: boxplus
 * Character: ⊞
 * Unicode code point: U+229e (8862)
 * Description: squared plus
 */
static wchar_t* SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxplus";
static int* SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared minus html character entity reference model.
 *
 * Name: boxminus
 * Character: ⊟
 * Unicode code point: U+229f (8863)
 * Description: squared minus
 */
static wchar_t* SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxminus";
static int* SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared times html character entity reference model.
 *
 * Name: boxtimes
 * Character: ⊠
 * Unicode code point: U+22a0 (8864)
 * Description: squared times
 */
static wchar_t* SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxtimes";
static int* SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared dot operator html character entity reference model.
 *
 * Name: dotsquare
 * Character: ⊡
 * Unicode code point: U+22a1 (8865)
 * Description: squared dot operator
 */
static wchar_t* SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotsquare";
static int* SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right tack html character entity reference model.
 *
 * Name: RightTee
 * Character: ⊢
 * Unicode code point: U+22a2 (8866)
 * Description: right tack
 */
static wchar_t* RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTee";
static int* RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left tack html character entity reference model.
 *
 * Name: LeftTee
 * Character: ⊣
 * Unicode code point: U+22a3 (8867)
 * Description: left tack
 */
static wchar_t* LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTee";
static int* LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The down tack html character entity reference model.
 *
 * Name: DownTee
 * Character: ⊤
 * Unicode code point: U+22a4 (8868)
 * Description: down tack
 */
static wchar_t* DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownTee";
static int* DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up tack html character entity reference model.
 *
 * Name: UpTee
 * Character: ⊥
 * Unicode code point: U+22a5 (8869)
 * Description: up tack
 */
static wchar_t* UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpTee";
static int* UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The models html character entity reference model.
 *
 * Name: models
 * Character: ⊧
 * Unicode code point: U+22a7 (8871)
 * Description: models
 */
static wchar_t* MODELS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"models";
static int* MODELS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The true html character entity reference model.
 *
 * Name: DoubleRightTee
 * Character: ⊨
 * Unicode code point: U+22a8 (8872)
 * Description: true
 */
static wchar_t* TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleRightTee";
static int* TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The forces html character entity reference model.
 *
 * Name: Vdash
 * Character: ⊩
 * Unicode code point: U+22a9 (8873)
 * Description: forces
 */
static wchar_t* FORCES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vdash";
static int* FORCES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triple vertical bar right turnstile html character entity reference model.
 *
 * Name: Vvdash
 * Character: ⊪
 * Unicode code point: U+22aa (8874)
 * Description: triple vertical bar right turnstile
 */
static wchar_t* TRIPLE_VERTICAL_BAR_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vvdash";
static int* TRIPLE_VERTICAL_BAR_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double vertical bar double right turnstile html character entity reference model.
 *
 * Name: VDash
 * Character: ⊫
 * Unicode code point: U+22ab (8875)
 * Description: double vertical bar double right turnstile
 */
static wchar_t* DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VDash";
static int* DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not prove html character entity reference model.
 *
 * Name: nvdash
 * Character: ⊬
 * Unicode code point: U+22ac (8876)
 * Description: does not prove
 */
static wchar_t* DOES_NOT_PROVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvdash";
static int* DOES_NOT_PROVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not true html character entity reference model.
 *
 * Name: nvDash
 * Character: ⊭
 * Unicode code point: U+22ad (8877)
 * Description: not true
 */
static wchar_t* NOT_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvDash";
static int* NOT_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not force html character entity reference model.
 *
 * Name: nVdash
 * Character: ⊮
 * Unicode code point: U+22ae (8878)
 * Description: does not force
 */
static wchar_t* DOES_NOT_FORCE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nVdash";
static int* DOES_NOT_FORCE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The negated double vertical bar double right turnstile html character entity reference model.
 *
 * Name: nVDash
 * Character: ⊯
 * Unicode code point: U+22af (8879)
 * Description: negated double vertical bar double right turnstile
 */
static wchar_t* NEGATED_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nVDash";
static int* NEGATED_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes under relation html character entity reference model.
 *
 * Name: prurel
 * Character: ⊰
 * Unicode code point: U+22b0 (8880)
 * Description: precedes under relation
 */
static wchar_t* PRECEDES_UNDER_RELATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prurel";
static int* PRECEDES_UNDER_RELATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The normal subgroup of html character entity reference model.
 *
 * Name: LeftTriangle
 * Character: ⊲
 * Unicode code point: U+22b2 (8882)
 * Description: normal subgroup of
 */
static wchar_t* NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangle";
static int* NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains as normal subgroup html character entity reference model.
 *
 * Name: RightTriangle
 * Character: ⊳
 * Unicode code point: U+22b3 (8883)
 * Description: contains as normal subgroup
 */
static wchar_t* CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangle";
static int* CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The normal subgroup of or equal to html character entity reference model.
 *
 * Name: LeftTriangleEqual
 * Character: ⊴
 * Unicode code point: U+22b4 (8884)
 * Description: normal subgroup of or equal to
 */
static wchar_t* NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangleEqual";
static int* NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The normal subgroup of or equal to with vertical line html character entity reference model.
 *
 * Name: nvltrie
 * Character: ⊴⃒
 * Unicode code point: U+22b4;U+20d2 (8884;8402)
 * Description: normal subgroup of or equal to with vertical line
 */
static wchar_t* NORMAL_SUBGROUP_OF_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvltrie";
static int* NORMAL_SUBGROUP_OF_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains as normal subgroup or equal to html character entity reference model.
 *
 * Name: RightTriangleEqual
 * Character: ⊵
 * Unicode code point: U+22b5 (8885)
 * Description: contains as normal subgroup or equal to
 */
static wchar_t* CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangleEqual";
static int* CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains as normal subgroup or equal to with vertical line html character entity reference model.
 *
 * Name: nvrtrie
 * Character: ⊵⃒
 * Unicode code point: U+22b5;U+20d2 (8885;8402)
 * Description: contains as normal subgroup or equal to with vertical line
 */
static wchar_t* CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvrtrie";
static int* CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The original of html character entity reference model.
 *
 * Name: origof
 * Character: ⊶
 * Unicode code point: U+22b6 (8886)
 * Description: original of
 */
static wchar_t* ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"origof";
static int* ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image of html character entity reference model.
 *
 * Name: imof
 * Character: ⊷
 * Unicode code point: U+22b7 (8887)
 * Description: image of
 */
static wchar_t* IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imof";
static int* IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multimap html character entity reference model.
 *
 * Name: multimap
 * Character: ⊸
 * Unicode code point: U+22b8 (8888)
 * Description: multimap
 */
static wchar_t* MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"multimap";
static int* MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hermitian conjugate matrix html character entity reference model.
 *
 * Name: hercon
 * Character: ⊹
 * Unicode code point: U+22b9 (8889)
 * Description: hermitian conjugate matrix
 */
static wchar_t* HERMITIAN_CONJUGATE_MATRIX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hercon";
static int* HERMITIAN_CONJUGATE_MATRIX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intercalate html character entity reference model.
 *
 * Name: intcal
 * Character: ⊺
 * Unicode code point: U+22ba (8890)
 * Description: intercalate
 */
static wchar_t* INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intcal";
static int* INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xor html character entity reference model.
 *
 * Name: veebar
 * Character: ⊻
 * Unicode code point: U+22bb (8891)
 * Description: xor
 */
static wchar_t* XOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"veebar";
static int* XOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nor html character entity reference model.
 *
 * Name: barvee
 * Character: ⊽
 * Unicode code point: U+22bd (8893)
 * Description: nor
 */
static wchar_t* NOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"barvee";
static int* NOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right angle with arc html character entity reference model.
 *
 * Name: angrtvb
 * Character: ⊾
 * Unicode code point: U+22be (8894)
 * Description: right angle with arc
 */
static wchar_t* RIGHT_ANGLE_WITH_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrtvb";
static int* RIGHT_ANGLE_WITH_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right triangle html character entity reference model.
 *
 * Name: lrtri
 * Character: ⊿
 * Unicode code point: U+22bf (8895)
 * Description: right triangle
 */
static wchar_t* RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrtri";
static int* RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary logical and html character entity reference model.
 *
 * Name: Wedge
 * Character: ⋀
 * Unicode code point: U+22c0 (8896)
 * Description: n-ary logical and
 */
static wchar_t* N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wedge";
static int* N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary logical or html character entity reference model.
 *
 * Name: Vee
 * Character: ⋁
 * Unicode code point: U+22c1 (8897)
 * Description: n-ary logical or
 */
static wchar_t* N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vee";
static int* N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary intersection html character entity reference model.
 *
 * Name: Intersection
 * Character: ⋂
 * Unicode code point: U+22c2 (8898)
 * Description: n-ary intersection
 */
static wchar_t* N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Intersection";
static int* N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary union html character entity reference model.
 *
 * Name: Union
 * Character: ⋃
 * Unicode code point: U+22c3 (8899)
 * Description: n-ary union
 */
static wchar_t* N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Union";
static int* N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diamond operator html character entity reference model.
 *
 * Name: Diamond
 * Character: ⋄
 * Unicode code point: U+22c4 (8900)
 * Description: diamond operator
 */
static wchar_t* DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Diamond";
static int* DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot operator html character entity reference model.
 *
 * Name: sdot
 * Character: ⋅
 * Unicode code point: U+22c5 (8901)
 * Description: dot operator
 */
static wchar_t* DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdot";
static int* DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The star operator html character entity reference model.
 *
 * Name: Star
 * Character: ⋆
 * Unicode code point: U+22c6 (8902)
 * Description: star operator
 */
static wchar_t* STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Star";
static int* STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The division times html character entity reference model.
 *
 * Name: divideontimes
 * Character: ⋇
 * Unicode code point: U+22c7 (8903)
 * Description: division times
 */
static wchar_t* DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"divideontimes";
static int* DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bowtie html character entity reference model.
 *
 * Name: bowtie
 * Character: ⋈
 * Unicode code point: U+22c8 (8904)
 * Description: bowtie
 */
static wchar_t* BOWTIE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bowtie";
static int* BOWTIE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left normal factor semidirect product html character entity reference model.
 *
 * Name: ltimes
 * Character: ⋉
 * Unicode code point: U+22c9 (8905)
 * Description: left normal factor semidirect product
 */
static wchar_t* LEFT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltimes";
static int* LEFT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right normal factor semidirect product html character entity reference model.
 *
 * Name: rtimes
 * Character: ⋊
 * Unicode code point: U+22ca (8906)
 * Description: right normal factor semidirect product
 */
static wchar_t* RIGHT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtimes";
static int* RIGHT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left semidirect product html character entity reference model.
 *
 * Name: leftthreetimes
 * Character: ⋋
 * Unicode code point: U+22cb (8907)
 * Description: left semidirect product
 */
static wchar_t* LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftthreetimes";
static int* LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right semidirect product html character entity reference model.
 *
 * Name: rightthreetimes
 * Character: ⋌
 * Unicode code point: U+22cc (8908)
 * Description: right semidirect product
 */
static wchar_t* RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightthreetimes";
static int* RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed tilde equals html character entity reference model.
 *
 * Name: backsimeq
 * Character: ⋍
 * Unicode code point: U+22cd (8909)
 * Description: reversed tilde equals
 */
static wchar_t* REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backsimeq";
static int* REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curly logical or html character entity reference model.
 *
 * Name: curlyvee
 * Character: ⋎
 * Unicode code point: U+22ce (8910)
 * Description: curly logical or
 */
static wchar_t* CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlyvee";
static int* CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curly logical and html character entity reference model.
 *
 * Name: curlywedge
 * Character: ⋏
 * Unicode code point: U+22cf (8911)
 * Description: curly logical and
 */
static wchar_t* CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlywedge";
static int* CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double subset html character entity reference model.
 *
 * Name: Sub
 * Character: ⋐
 * Unicode code point: U+22d0 (8912)
 * Description: double subset
 */
static wchar_t* DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sub";
static int* DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double superset html character entity reference model.
 *
 * Name: Sup
 * Character: ⋑
 * Unicode code point: U+22d1 (8913)
 * Description: double superset
 */
static wchar_t* DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sup";
static int* DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double intersection html character entity reference model.
 *
 * Name: Cap
 * Character: ⋒
 * Unicode code point: U+22d2 (8914)
 * Description: double intersection
 */
static wchar_t* DOUBLE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cap";
static int* DOUBLE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double union html character entity reference model.
 *
 * Name: Cup
 * Character: ⋓
 * Unicode code point: U+22d3 (8915)
 * Description: double union
 */
static wchar_t* DOUBLE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cup";
static int* DOUBLE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pitchfork html character entity reference model.
 *
 * Name: fork
 * Character: ⋔
 * Unicode code point: U+22d4 (8916)
 * Description: pitchfork
 */
static wchar_t* PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fork";
static int* PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equal and parallel to html character entity reference model.
 *
 * Name: epar
 * Character: ⋕
 * Unicode code point: U+22d5 (8917)
 * Description: equal and parallel to
 */
static wchar_t* EQUAL_AND_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epar";
static int* EQUAL_AND_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than with dot html character entity reference model.
 *
 * Name: lessdot
 * Character: ⋖
 * Unicode code point: U+22d6 (8918)
 * Description: less-than with dot
 */
static wchar_t* LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lessdot";
static int* LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than with dot html character entity reference model.
 *
 * Name: gtdot
 * Character: ⋗
 * Unicode code point: U+22d7 (8919)
 * Description: greater-than with dot
 */
static wchar_t* GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtdot";
static int* GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The very much less-than html character entity reference model.
 *
 * Name: Ll
 * Character: ⋘
 * Unicode code point: U+22d8 (8920)
 * Description: very much less-than
 */
static wchar_t* VERY_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ll";
static int* VERY_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The very much less-than with slash html character entity reference model.
 *
 * Name: nLl
 * Character: ⋘̸
 * Unicode code point: U+22d8;U+0338 (8920;824)
 * Description: very much less-than with slash
 */
static wchar_t* VERY_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLl";
static int* VERY_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The very much greater-than html character entity reference model.
 *
 * Name: Gg
 * Character: ⋙
 * Unicode code point: U+22d9 (8921)
 * Description: very much greater-than
 */
static wchar_t* VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gg";
static int* VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The very much greater-than with slash html character entity reference model.
 *
 * Name: nGg
 * Character: ⋙̸
 * Unicode code point: U+22d9;U+0338 (8921;824)
 * Description: very much greater-than with slash
 */
static wchar_t* VERY_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nGg";
static int* VERY_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than equal to or greater-than html character entity reference model.
 *
 * Name: LessEqualGreater
 * Character: ⋚
 * Unicode code point: U+22da (8922)
 * Description: less-than equal to or greater-than
 */
static wchar_t* LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessEqualGreater";
static int* LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than slanted equal to or greater-than html character entity reference model.
 *
 * Name: lesg
 * Character: ⋚︀
 * Unicode code point: U+22da;U+fe00 (8922;65024)
 * Description: less-than slanted equal to or greater-than
 */
static wchar_t* LESS_THAN_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesg";
static int* LESS_THAN_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than equal to or less-than html character entity reference model.
 *
 * Name: GreaterEqualLess
 * Character: ⋛
 * Unicode code point: U+22db (8923)
 * Description: greater-than equal to or less-than
 */
static wchar_t* GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterEqualLess";
static int* GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than slanted equal to or less-than html character entity reference model.
 *
 * Name: gesl
 * Character: ⋛︀
 * Unicode code point: U+22db;U+fe00 (8923;65024)
 * Description: greater-than slanted equal to or less-than
 */
static wchar_t* GREATER_THAN_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesl";
static int* GREATER_THAN_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equal to or precedes html character entity reference model.
 *
 * Name: cuepr
 * Character: ⋞
 * Unicode code point: U+22de (8926)
 * Description: equal to or precedes
 */
static wchar_t* EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuepr";
static int* EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equal to or succeeds html character entity reference model.
 *
 * Name: cuesc
 * Character: ⋟
 * Unicode code point: U+22df (8927)
 * Description: equal to or succeeds
 */
static wchar_t* EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuesc";
static int* EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not precede or equal html character entity reference model.
 *
 * Name: NotPrecedesSlantEqual
 * Character: ⋠
 * Unicode code point: U+22e0 (8928)
 * Description: does not precede or equal
 */
static wchar_t* DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedesSlantEqual";
static int* DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not succeed or equal html character entity reference model.
 *
 * Name: NotSucceedsSlantEqual
 * Character: ⋡
 * Unicode code point: U+22e1 (8929)
 * Description: does not succeed or equal
 */
static wchar_t* DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsSlantEqual";
static int* DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not square image of or equal to html character entity reference model.
 *
 * Name: NotSquareSubsetEqual
 * Character: ⋢
 * Unicode code point: U+22e2 (8930)
 * Description: not square image of or equal to
 */
static wchar_t* NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSubsetEqual";
static int* NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not square original of or equal to html character entity reference model.
 *
 * Name: NotSquareSupersetEqual
 * Character: ⋣
 * Unicode code point: U+22e3 (8931)
 * Description: not square original of or equal to
 */
static wchar_t* NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSupersetEqual";
static int* NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than but not equivalent to html character entity reference model.
 *
 * Name: lnsim
 * Character: ⋦
 * Unicode code point: U+22e6 (8934)
 * Description: less-than but not equivalent to
 */
static wchar_t* LESS_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnsim";
static int* LESS_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than but not equivalent to html character entity reference model.
 *
 * Name: gnsim
 * Character: ⋧
 * Unicode code point: U+22e7 (8935)
 * Description: greater-than but not equivalent to
 */
static wchar_t* GREATER_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnsim";
static int* GREATER_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes but not equivalent to html character entity reference model.
 *
 * Name: precnsim
 * Character: ⋨
 * Unicode code point: U+22e8 (8936)
 * Description: precedes but not equivalent to
 */
static wchar_t* PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precnsim";
static int* PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds but not equivalent to html character entity reference model.
 *
 * Name: scnsim
 * Character: ⋩
 * Unicode code point: U+22e9 (8937)
 * Description: succeeds but not equivalent to
 */
static wchar_t* SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnsim";
static int* SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not normal subgroup of html character entity reference model.
 *
 * Name: NotLeftTriangle
 * Character: ⋪
 * Unicode code point: U+22ea (8938)
 * Description: not normal subgroup of
 */
static wchar_t* NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangle";
static int* NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not contain as normal subgroup html character entity reference model.
 *
 * Name: NotRightTriangle
 * Character: ⋫
 * Unicode code point: U+22eb (8939)
 * Description: does not contain as normal subgroup
 */
static wchar_t* DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangle";
static int* DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not normal subgroup of or equal to html character entity reference model.
 *
 * Name: NotLeftTriangleEqual
 * Character: ⋬
 * Unicode code point: U+22ec (8940)
 * Description: not normal subgroup of or equal to
 */
static wchar_t* NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangleEqual";
static int* NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not contain as normal subgroup or equal html character entity reference model.
 *
 * Name: NotRightTriangleEqual
 * Character: ⋭
 * Unicode code point: U+22ed (8941)
 * Description: does not contain as normal subgroup or equal
 */
static wchar_t* DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangleEqual";
static int* DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical ellipsis html character entity reference model.
 *
 * Name: vellip
 * Character: ⋮
 * Unicode code point: U+22ee (8942)
 * Description: vertical ellipsis
 */
static wchar_t* VERTICAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vellip";
static int* VERTICAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The midline horizontal ellipsis html character entity reference model.
 *
 * Name: ctdot
 * Character: ⋯
 * Unicode code point: U+22ef (8943)
 * Description: midline horizontal ellipsis
 */
static wchar_t* MIDLINE_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ctdot";
static int* MIDLINE_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up right diagonal ellipsis html character entity reference model.
 *
 * Name: utdot
 * Character: ⋰
 * Unicode code point: U+22f0 (8944)
 * Description: up right diagonal ellipsis
 */
static wchar_t* UP_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utdot";
static int* UP_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The down right diagonal ellipsis html character entity reference model.
 *
 * Name: dtdot
 * Character: ⋱
 * Unicode code point: U+22f1 (8945)
 * Description: down right diagonal ellipsis
 */
static wchar_t* DOWN_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dtdot";
static int* DOWN_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with long horizontal stroke html character entity reference model.
 *
 * Name: disin
 * Character: ⋲
 * Unicode code point: U+22f2 (8946)
 * Description: element of with long horizontal stroke
 */
static wchar_t* ELEMENT_OF_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"disin";
static int* ELEMENT_OF_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with vertical bar at end of horizontal stroke html character entity reference model.
 *
 * Name: isinsv
 * Character: ⋳
 * Unicode code point: U+22f3 (8947)
 * Description: element of with vertical bar at end of horizontal stroke
 */
static wchar_t* ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isinsv";
static int* ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small element of with vertical bar at end of horizontal stroke html character entity reference model.
 *
 * Name: isins
 * Character: ⋴
 * Unicode code point: U+22f4 (8948)
 * Description: small element of with vertical bar at end of horizontal stroke
 */
static wchar_t* SMALL_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isins";
static int* SMALL_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with dot above html character entity reference model.
 *
 * Name: isindot
 * Character: ⋵
 * Unicode code point: U+22f5 (8949)
 * Description: element of with dot above
 */
static wchar_t* ELEMENT_OF_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isindot";
static int* ELEMENT_OF_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with dot above with slash html character entity reference model.
 *
 * Name: notindot
 * Character: ⋵̸
 * Unicode code point: U+22f5;U+0338 (8949;824)
 * Description: element of with dot above with slash
 */
static wchar_t* ELEMENT_OF_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notindot";
static int* ELEMENT_OF_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with overbar html character entity reference model.
 *
 * Name: notinvc
 * Character: ⋶
 * Unicode code point: U+22f6 (8950)
 * Description: element of with overbar
 */
static wchar_t* ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinvc";
static int* ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small element of with overbar html character entity reference model.
 *
 * Name: notinvb
 * Character: ⋷
 * Unicode code point: U+22f7 (8951)
 * Description: small element of with overbar
 */
static wchar_t* SMALL_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinvb";
static int* SMALL_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with two horizontal strokes html character entity reference model.
 *
 * Name: isinE
 * Character: ⋹
 * Unicode code point: U+22f9 (8953)
 * Description: element of with two horizontal strokes
 */
static wchar_t* ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isinE";
static int* ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of with two horizontal strokes with slash html character entity reference model.
 *
 * Name: notinE
 * Character: ⋹̸
 * Unicode code point: U+22f9;U+0338 (8953;824)
 * Description: element of with two horizontal strokes with slash
 */
static wchar_t* ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinE";
static int* ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains with long horizontal stroke html character entity reference model.
 *
 * Name: nisd
 * Character: ⋺
 * Unicode code point: U+22fa (8954)
 * Description: contains with long horizontal stroke
 */
static wchar_t* CONTAINS_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nisd";
static int* CONTAINS_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains with vertical bar at end of horizontal stroke html character entity reference model.
 *
 * Name: xnis
 * Character: ⋻
 * Unicode code point: U+22fb (8955)
 * Description: contains with vertical bar at end of horizontal stroke
 */
static wchar_t* CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xnis";
static int* CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small contains with vertical bar at end of horizontal stroke html character entity reference model.
 *
 * Name: nis
 * Character: ⋼
 * Unicode code point: U+22fc (8956)
 * Description: small contains with vertical bar at end of horizontal stroke
 */
static wchar_t* SMALL_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nis";
static int* SMALL_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contains with overbar html character entity reference model.
 *
 * Name: notnivc
 * Character: ⋽
 * Unicode code point: U+22fd (8957)
 * Description: contains with overbar
 */
static wchar_t* CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notnivc";
static int* CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The small contains with overbar html character entity reference model.
 *
 * Name: notnivb
 * Character: ⋾
 * Unicode code point: U+22fe (8958)
 * Description: small contains with overbar
 */
static wchar_t* SMALL_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notnivb";
static int* SMALL_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The projective html character entity reference model.
 *
 * Name: barwed
 * Character: ⌅
 * Unicode code point: U+2305 (8965)
 * Description: projective
 */
static wchar_t* PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"barwed";
static int* PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The perspective html character entity reference model.
 *
 * Name: Barwed
 * Character: ⌆
 * Unicode code point: U+2306 (8966)
 * Description: perspective
 */
static wchar_t* PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Barwed";
static int* PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left ceiling html character entity reference model.
 *
 * Name: LeftCeiling
 * Character: ⌈
 * Unicode code point: U+2308 (8968)
 * Description: left ceiling
 */
static wchar_t* LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftCeiling";
static int* LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right ceiling html character entity reference model.
 *
 * Name: RightCeiling
 * Character: ⌉
 * Unicode code point: U+2309 (8969)
 * Description: right ceiling
 */
static wchar_t* RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightCeiling";
static int* RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left floor html character entity reference model.
 *
 * Name: LeftFloor
 * Character: ⌊
 * Unicode code point: U+230a (8970)
 * Description: left floor
 */
static wchar_t* LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftFloor";
static int* LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right floor html character entity reference model.
 *
 * Name: RightFloor
 * Character: ⌋
 * Unicode code point: U+230b (8971)
 * Description: right floor
 */
static wchar_t* RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightFloor";
static int* RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom right crop html character entity reference model.
 *
 * Name: drcrop
 * Character: ⌌
 * Unicode code point: U+230c (8972)
 * Description: bottom right crop
 */
static wchar_t* BOTTOM_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"drcrop";
static int* BOTTOM_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom left crop html character entity reference model.
 *
 * Name: dlcrop
 * Character: ⌍
 * Unicode code point: U+230d (8973)
 * Description: bottom left crop
 */
static wchar_t* BOTTOM_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dlcrop";
static int* BOTTOM_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top right crop html character entity reference model.
 *
 * Name: urcrop
 * Character: ⌎
 * Unicode code point: U+230e (8974)
 * Description: top right crop
 */
static wchar_t* TOP_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urcrop";
static int* TOP_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top left crop html character entity reference model.
 *
 * Name: ulcrop
 * Character: ⌏
 * Unicode code point: U+230f (8975)
 * Description: top left crop
 */
static wchar_t* TOP_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ulcrop";
static int* TOP_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed not sign html character entity reference model.
 *
 * Name: bnot
 * Character: ⌐
 * Unicode code point: U+2310 (8976)
 * Description: reversed not sign
 */
static wchar_t* REVERSED_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bnot";
static int* REVERSED_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The arc html character entity reference model.
 *
 * Name: profline
 * Character: ⌒
 * Unicode code point: U+2312 (8978)
 * Description: arc
 */
static wchar_t* ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profline";
static int* ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The segment html character entity reference model.
 *
 * Name: profsurf
 * Character: ⌓
 * Unicode code point: U+2313 (8979)
 * Description: segment
 */
static wchar_t* SEGMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profsurf";
static int* SEGMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The telephone recorder html character entity reference model.
 *
 * Name: telrec
 * Character: ⌕
 * Unicode code point: U+2315 (8981)
 * Description: telephone recorder
 */
static wchar_t* TELEPHONE_RECORDER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"telrec";
static int* TELEPHONE_RECORDER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The position indicator html character entity reference model.
 *
 * Name: target
 * Character: ⌖
 * Unicode code point: U+2316 (8982)
 * Description: position indicator
 */
static wchar_t* POSITION_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"target";
static int* POSITION_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top left corner html character entity reference model.
 *
 * Name: ulcorn
 * Character: ⌜
 * Unicode code point: U+231c (8988)
 * Description: top left corner
 */
static wchar_t* TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ulcorn";
static int* TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top right corner html character entity reference model.
 *
 * Name: urcorn
 * Character: ⌝
 * Unicode code point: U+231d (8989)
 * Description: top right corner
 */
static wchar_t* TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urcorn";
static int* TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom left corner html character entity reference model.
 *
 * Name: dlcorn
 * Character: ⌞
 * Unicode code point: U+231e (8990)
 * Description: bottom left corner
 */
static wchar_t* BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dlcorn";
static int* BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom right corner html character entity reference model.
 *
 * Name: drcorn
 * Character: ⌟
 * Unicode code point: U+231f (8991)
 * Description: bottom right corner
 */
static wchar_t* BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"drcorn";
static int* BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frown html character entity reference model.
 *
 * Name: frown
 * Character: ⌢
 * Unicode code point: U+2322 (8994)
 * Description: frown
 */
static wchar_t* FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frown";
static int* FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smile html character entity reference model.
 *
 * Name: smile
 * Character: ⌣
 * Unicode code point: U+2323 (8995)
 * Description: smile
 */
static wchar_t* SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smile";
static int* SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cylindricity html character entity reference model.
 *
 * Name: cylcty
 * Character: ⌭
 * Unicode code point: U+232d (9005)
 * Description: cylindricity
 */
static wchar_t* CYLINDRICITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cylcty";
static int* CYLINDRICITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The all around-profile html character entity reference model.
 *
 * Name: profalar
 * Character: ⌮
 * Unicode code point: U+232e (9006)
 * Description: all around-profile
 */
static wchar_t* ALL_AROUND_PROFILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profalar";
static int* ALL_AROUND_PROFILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apl functional symbol i-beam html character entity reference model.
 *
 * Name: topbot
 * Character: ⌶
 * Unicode code point: U+2336 (9014)
 * Description: apl functional symbol i-beam
 */
static wchar_t* APL_FUNCTIONAL_SYMBOL_I_BEAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topbot";
static int* APL_FUNCTIONAL_SYMBOL_I_BEAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apl functional symbol circle stile html character entity reference model.
 *
 * Name: ovbar
 * Character: ⌽
 * Unicode code point: U+233d (9021)
 * Description: apl functional symbol circle stile
 */
static wchar_t* APL_FUNCTIONAL_SYMBOL_CIRCLE_STILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ovbar";
static int* APL_FUNCTIONAL_SYMBOL_CIRCLE_STILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apl functional symbol slash bar html character entity reference model.
 *
 * Name: solbar
 * Character: ⌿
 * Unicode code point: U+233f (9023)
 * Description: apl functional symbol slash bar
 */
static wchar_t* APL_FUNCTIONAL_SYMBOL_SLASH_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"solbar";
static int* APL_FUNCTIONAL_SYMBOL_SLASH_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right angle with downwards zigzag arrow html character entity reference model.
 *
 * Name: angzarr
 * Character: ⍼
 * Unicode code point: U+237c (9084)
 * Description: right angle with downwards zigzag arrow
 */
static wchar_t* RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angzarr";
static int* RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upper left or lower right curly bracket section html character entity reference model.
 *
 * Name: lmoust
 * Character: ⎰
 * Unicode code point: U+23b0 (9136)
 * Description: upper left or lower right curly bracket section
 */
static wchar_t* UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lmoust";
static int* UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upper right or lower left curly bracket section html character entity reference model.
 *
 * Name: rmoust
 * Character: ⎱
 * Unicode code point: U+23b1 (9137)
 * Description: upper right or lower left curly bracket section
 */
static wchar_t* UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rmoust";
static int* UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top square bracket html character entity reference model.
 *
 * Name: OverBracket
 * Character: ⎴
 * Unicode code point: U+23b4 (9140)
 * Description: top square bracket
 */
static wchar_t* TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBracket";
static int* TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom square bracket html character entity reference model.
 *
 * Name: UnderBracket
 * Character: ⎵
 * Unicode code point: U+23b5 (9141)
 * Description: bottom square bracket
 */
static wchar_t* BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBracket";
static int* BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom square bracket over top square bracket html character entity reference model.
 *
 * Name: bbrktbrk
 * Character: ⎶
 * Unicode code point: U+23b6 (9142)
 * Description: bottom square bracket over top square bracket
 */
static wchar_t* BOTTOM_SQUARE_BRACKET_OVER_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bbrktbrk";
static int* BOTTOM_SQUARE_BRACKET_OVER_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top parenthesis html character entity reference model.
 *
 * Name: OverParenthesis
 * Character: ⏜
 * Unicode code point: U+23dc (9180)
 * Description: top parenthesis
 */
static wchar_t* TOP_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverParenthesis";
static int* TOP_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom parenthesis html character entity reference model.
 *
 * Name: UnderParenthesis
 * Character: ⏝
 * Unicode code point: U+23dd (9181)
 * Description: bottom parenthesis
 */
static wchar_t* BOTTOM_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderParenthesis";
static int* BOTTOM_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top curly bracket html character entity reference model.
 *
 * Name: OverBrace
 * Character: ⏞
 * Unicode code point: U+23de (9182)
 * Description: top curly bracket
 */
static wchar_t* TOP_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBrace";
static int* TOP_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom curly bracket html character entity reference model.
 *
 * Name: UnderBrace
 * Character: ⏟
 * Unicode code point: U+23df (9183)
 * Description: bottom curly bracket
 */
static wchar_t* BOTTOM_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBrace";
static int* BOTTOM_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white trapezium html character entity reference model.
 *
 * Name: trpezium
 * Character: ⏢
 * Unicode code point: U+23e2 (9186)
 * Description: white trapezium
 */
static wchar_t* WHITE_TRAPEZIUM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trpezium";
static int* WHITE_TRAPEZIUM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The electrical intersection html character entity reference model.
 *
 * Name: elinters
 * Character: ⏧
 * Unicode code point: U+23e7 (9191)
 * Description: electrical intersection
 */
static wchar_t* ELECTRICAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"elinters";
static int* ELECTRICAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The open box html character entity reference model.
 *
 * Name: blank
 * Character: ␣
 * Unicode code point: U+2423 (9251)
 * Description: open box
 */
static wchar_t* OPEN_BOX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blank";
static int* OPEN_BOX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled latin capital letter s html character entity reference model.
 *
 * Name: circledS
 * Character: Ⓢ
 * Unicode code point: U+24c8 (9416)
 * Description: circled latin capital letter s
 */
static wchar_t* CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledS";
static int* CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light horizontal html character entity reference model.
 *
 * Name: HorizontalLine
 * Character: ─
 * Unicode code point: U+2500 (9472)
 * Description: box drawings light horizontal
 */
static wchar_t* BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HorizontalLine";
static int* BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light vertical html character entity reference model.
 *
 * Name: boxv
 * Character: │
 * Unicode code point: U+2502 (9474)
 * Description: box drawings light vertical
 */
static wchar_t* BOX_DRAWINGS_LIGHT_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxv";
static int* BOX_DRAWINGS_LIGHT_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light down and right html character entity reference model.
 *
 * Name: boxdr
 * Character: ┌
 * Unicode code point: U+250c (9484)
 * Description: box drawings light down and right
 */
static wchar_t* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdr";
static int* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light down and left html character entity reference model.
 *
 * Name: boxdl
 * Character: ┐
 * Unicode code point: U+2510 (9488)
 * Description: box drawings light down and left
 */
static wchar_t* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdl";
static int* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light up and right html character entity reference model.
 *
 * Name: boxur
 * Character: └
 * Unicode code point: U+2514 (9492)
 * Description: box drawings light up and right
 */
static wchar_t* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxur";
static int* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light up and left html character entity reference model.
 *
 * Name: boxul
 * Character: ┘
 * Unicode code point: U+2518 (9496)
 * Description: box drawings light up and left
 */
static wchar_t* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxul";
static int* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light vertical and right html character entity reference model.
 *
 * Name: boxvr
 * Character: ├
 * Unicode code point: U+251c (9500)
 * Description: box drawings light vertical and right
 */
static wchar_t* BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvr";
static int* BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light vertical and left html character entity reference model.
 *
 * Name: boxvl
 * Character: ┤
 * Unicode code point: U+2524 (9508)
 * Description: box drawings light vertical and left
 */
static wchar_t* BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvl";
static int* BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light down and horizontal html character entity reference model.
 *
 * Name: boxhd
 * Character: ┬
 * Unicode code point: U+252c (9516)
 * Description: box drawings light down and horizontal
 */
static wchar_t* BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhd";
static int* BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light up and horizontal html character entity reference model.
 *
 * Name: boxhu
 * Character: ┴
 * Unicode code point: U+2534 (9524)
 * Description: box drawings light up and horizontal
 */
static wchar_t* BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhu";
static int* BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings light vertical and horizontal html character entity reference model.
 *
 * Name: boxvh
 * Character: ┼
 * Unicode code point: U+253c (9532)
 * Description: box drawings light vertical and horizontal
 */
static wchar_t* BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvh";
static int* BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double horizontal html character entity reference model.
 *
 * Name: boxH
 * Character: ═
 * Unicode code point: U+2550 (9552)
 * Description: box drawings double horizontal
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxH";
static int* BOX_DRAWINGS_DOUBLE_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double vertical html character entity reference model.
 *
 * Name: boxV
 * Character: ║
 * Unicode code point: U+2551 (9553)
 * Description: box drawings double vertical
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxV";
static int* BOX_DRAWINGS_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down single and right double html character entity reference model.
 *
 * Name: boxdR
 * Character: ╒
 * Unicode code point: U+2552 (9554)
 * Description: box drawings down single and right double
 */
static wchar_t* BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdR";
static int* BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down double and right single html character entity reference model.
 *
 * Name: boxDr
 * Character: ╓
 * Unicode code point: U+2553 (9555)
 * Description: box drawings down double and right single
 */
static wchar_t* BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDr";
static int* BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double down and right html character entity reference model.
 *
 * Name: boxDR
 * Character: ╔
 * Unicode code point: U+2554 (9556)
 * Description: box drawings double down and right
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDR";
static int* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down single and left double html character entity reference model.
 *
 * Name: boxdL
 * Character: ╕
 * Unicode code point: U+2555 (9557)
 * Description: box drawings down single and left double
 */
static wchar_t* BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdL";
static int* BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down double and left single html character entity reference model.
 *
 * Name: boxDl
 * Character: ╖
 * Unicode code point: U+2556 (9558)
 * Description: box drawings down double and left single
 */
static wchar_t* BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDl";
static int* BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double down and left html character entity reference model.
 *
 * Name: boxDL
 * Character: ╗
 * Unicode code point: U+2557 (9559)
 * Description: box drawings double down and left
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDL";
static int* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up single and right double html character entity reference model.
 *
 * Name: boxuR
 * Character: ╘
 * Unicode code point: U+2558 (9560)
 * Description: box drawings up single and right double
 */
static wchar_t* BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxuR";
static int* BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up double and right single html character entity reference model.
 *
 * Name: boxUr
 * Character: ╙
 * Unicode code point: U+2559 (9561)
 * Description: box drawings up double and right single
 */
static wchar_t* BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUr";
static int* BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double up and right html character entity reference model.
 *
 * Name: boxUR
 * Character: ╚
 * Unicode code point: U+255a (9562)
 * Description: box drawings double up and right
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUR";
static int* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up single and left double html character entity reference model.
 *
 * Name: boxuL
 * Character: ╛
 * Unicode code point: U+255b (9563)
 * Description: box drawings up single and left double
 */
static wchar_t* BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxuL";
static int* BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up double and left single html character entity reference model.
 *
 * Name: boxUl
 * Character: ╜
 * Unicode code point: U+255c (9564)
 * Description: box drawings up double and left single
 */
static wchar_t* BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUl";
static int* BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double up and left html character entity reference model.
 *
 * Name: boxUL
 * Character: ╝
 * Unicode code point: U+255d (9565)
 * Description: box drawings double up and left
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUL";
static int* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical single and right double html character entity reference model.
 *
 * Name: boxvR
 * Character: ╞
 * Unicode code point: U+255e (9566)
 * Description: box drawings vertical single and right double
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvR";
static int* BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical double and right single html character entity reference model.
 *
 * Name: boxVr
 * Character: ╟
 * Unicode code point: U+255f (9567)
 * Description: box drawings vertical double and right single
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVr";
static int* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double vertical and right html character entity reference model.
 *
 * Name: boxVR
 * Character: ╠
 * Unicode code point: U+2560 (9568)
 * Description: box drawings double vertical and right
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVR";
static int* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical single and left double html character entity reference model.
 *
 * Name: boxvL
 * Character: ╡
 * Unicode code point: U+2561 (9569)
 * Description: box drawings vertical single and left double
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvL";
static int* BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical double and left single html character entity reference model.
 *
 * Name: boxVl
 * Character: ╢
 * Unicode code point: U+2562 (9570)
 * Description: box drawings vertical double and left single
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVl";
static int* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double vertical and left html character entity reference model.
 *
 * Name: boxVL
 * Character: ╣
 * Unicode code point: U+2563 (9571)
 * Description: box drawings double vertical and left
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVL";
static int* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down single and horizontal double html character entity reference model.
 *
 * Name: boxHd
 * Character: ╤
 * Unicode code point: U+2564 (9572)
 * Description: box drawings down single and horizontal double
 */
static wchar_t* BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHd";
static int* BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings down double and horizontal single html character entity reference model.
 *
 * Name: boxhD
 * Character: ╥
 * Unicode code point: U+2565 (9573)
 * Description: box drawings down double and horizontal single
 */
static wchar_t* BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhD";
static int* BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double down and horizontal html character entity reference model.
 *
 * Name: boxHD
 * Character: ╦
 * Unicode code point: U+2566 (9574)
 * Description: box drawings double down and horizontal
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHD";
static int* BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up single and horizontal double html character entity reference model.
 *
 * Name: boxHu
 * Character: ╧
 * Unicode code point: U+2567 (9575)
 * Description: box drawings up single and horizontal double
 */
static wchar_t* BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHu";
static int* BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings up double and horizontal single html character entity reference model.
 *
 * Name: boxhU
 * Character: ╨
 * Unicode code point: U+2568 (9576)
 * Description: box drawings up double and horizontal single
 */
static wchar_t* BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhU";
static int* BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double up and horizontal html character entity reference model.
 *
 * Name: boxHU
 * Character: ╩
 * Unicode code point: U+2569 (9577)
 * Description: box drawings double up and horizontal
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHU";
static int* BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical single and horizontal double html character entity reference model.
 *
 * Name: boxvH
 * Character: ╪
 * Unicode code point: U+256a (9578)
 * Description: box drawings vertical single and horizontal double
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvH";
static int* BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings vertical double and horizontal single html character entity reference model.
 *
 * Name: boxVh
 * Character: ╫
 * Unicode code point: U+256b (9579)
 * Description: box drawings vertical double and horizontal single
 */
static wchar_t* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVh";
static int* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The box drawings double vertical and horizontal html character entity reference model.
 *
 * Name: boxVH
 * Character: ╬
 * Unicode code point: U+256c (9580)
 * Description: box drawings double vertical and horizontal
 */
static wchar_t* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVH";
static int* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upper half block html character entity reference model.
 *
 * Name: uhblk
 * Character: ▀
 * Unicode code point: U+2580 (9600)
 * Description: upper half block
 */
static wchar_t* UPPER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uhblk";
static int* UPPER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lower half block html character entity reference model.
 *
 * Name: lhblk
 * Character: ▄
 * Unicode code point: U+2584 (9604)
 * Description: lower half block
 */
static wchar_t* LOWER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lhblk";
static int* LOWER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The full block html character entity reference model.
 *
 * Name: block
 * Character: █
 * Unicode code point: U+2588 (9608)
 * Description: full block
 */
static wchar_t* FULL_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"block";
static int* FULL_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The light shade html character entity reference model.
 *
 * Name: blk14
 * Character: ░
 * Unicode code point: U+2591 (9617)
 * Description: light shade
 */
static wchar_t* LIGHT_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk14";
static int* LIGHT_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The medium shade html character entity reference model.
 *
 * Name: blk12
 * Character: ▒
 * Unicode code point: U+2592 (9618)
 * Description: medium shade
 */
static wchar_t* MEDIUM_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk12";
static int* MEDIUM_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dark shade html character entity reference model.
 *
 * Name: blk34
 * Character: ▓
 * Unicode code point: U+2593 (9619)
 * Description: dark shade
 */
static wchar_t* DARK_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk34";
static int* DARK_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white square html character entity reference model.
 *
 * Name: Square
 * Character: □
 * Unicode code point: U+25a1 (9633)
 * Description: white square
 */
static wchar_t* WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Square";
static int* WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black small square html character entity reference model.
 *
 * Name: FilledVerySmallSquare
 * Character: ▪
 * Unicode code point: U+25aa (9642)
 * Description: black small square
 */
static wchar_t* BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"FilledVerySmallSquare";
static int* BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white small square html character entity reference model.
 *
 * Name: EmptyVerySmallSquare
 * Character: ▫
 * Unicode code point: U+25ab (9643)
 * Description: white small square
 */
static wchar_t* WHITE_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EmptyVerySmallSquare";
static int* WHITE_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white rectangle html character entity reference model.
 *
 * Name: rect
 * Character: ▭
 * Unicode code point: U+25ad (9645)
 * Description: white rectangle
 */
static wchar_t* WHITE_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rect";
static int* WHITE_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black vertical rectangle html character entity reference model.
 *
 * Name: marker
 * Character: ▮
 * Unicode code point: U+25ae (9646)
 * Description: black vertical rectangle
 */
static wchar_t* BLACK_VERTICAL_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"marker";
static int* BLACK_VERTICAL_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white parallelogram html character entity reference model.
 *
 * Name: fltns
 * Character: ▱
 * Unicode code point: U+25b1 (9649)
 * Description: white parallelogram
 */
static wchar_t* WHITE_PARALLELOGRAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fltns";
static int* WHITE_PARALLELOGRAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white up-pointing triangle html character entity reference model.
 *
 * Name: bigtriangleup
 * Character: △
 * Unicode code point: U+25b3 (9651)
 * Description: white up-pointing triangle
 */
static wchar_t* WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigtriangleup";
static int* WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black up-pointing small triangle html character entity reference model.
 *
 * Name: blacktriangle
 * Character: ▴
 * Unicode code point: U+25b4 (9652)
 * Description: black up-pointing small triangle
 */
static wchar_t* BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangle";
static int* BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white up-pointing small triangle html character entity reference model.
 *
 * Name: triangle
 * Character: ▵
 * Unicode code point: U+25b5 (9653)
 * Description: white up-pointing small triangle
 */
static wchar_t* WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangle";
static int* WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black right-pointing small triangle html character entity reference model.
 *
 * Name: blacktriangleright
 * Character: ▸
 * Unicode code point: U+25b8 (9656)
 * Description: black right-pointing small triangle
 */
static wchar_t* BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangleright";
static int* BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white right-pointing small triangle html character entity reference model.
 *
 * Name: rtri
 * Character: ▹
 * Unicode code point: U+25b9 (9657)
 * Description: white right-pointing small triangle
 */
static wchar_t* WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtri";
static int* WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white down-pointing triangle html character entity reference model.
 *
 * Name: bigtriangledown
 * Character: ▽
 * Unicode code point: U+25bd (9661)
 * Description: white down-pointing triangle
 */
static wchar_t* WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigtriangledown";
static int* WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black down-pointing small triangle html character entity reference model.
 *
 * Name: blacktriangledown
 * Character: ▾
 * Unicode code point: U+25be (9662)
 * Description: black down-pointing small triangle
 */
static wchar_t* BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangledown";
static int* BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white down-pointing small triangle html character entity reference model.
 *
 * Name: dtri
 * Character: ▿
 * Unicode code point: U+25bf (9663)
 * Description: white down-pointing small triangle
 */
static wchar_t* WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dtri";
static int* WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black left-pointing small triangle html character entity reference model.
 *
 * Name: blacktriangleleft
 * Character: ◂
 * Unicode code point: U+25c2 (9666)
 * Description: black left-pointing small triangle
 */
static wchar_t* BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangleleft";
static int* BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white left-pointing small triangle html character entity reference model.
 *
 * Name: ltri
 * Character: ◃
 * Unicode code point: U+25c3 (9667)
 * Description: white left-pointing small triangle
 */
static wchar_t* WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltri";
static int* WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lozenge html character entity reference model.
 *
 * Name: loz
 * Character: ◊
 * Unicode code point: U+25ca (9674)
 * Description: lozenge
 */
static wchar_t* LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loz";
static int* LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white circle html character entity reference model.
 *
 * Name: cir
 * Character: ○
 * Unicode code point: U+25cb (9675)
 * Description: white circle
 */
static wchar_t* WHITE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cir";
static int* WHITE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white up-pointing triangle with dot html character entity reference model.
 *
 * Name: tridot
 * Character: ◬
 * Unicode code point: U+25ec (9708)
 * Description: white up-pointing triangle with dot
 */
static wchar_t* WHITE_UP_POINTING_TRIANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tridot";
static int* WHITE_UP_POINTING_TRIANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The large circle html character entity reference model.
 *
 * Name: bigcirc
 * Character: ◯
 * Unicode code point: U+25ef (9711)
 * Description: large circle
 */
static wchar_t* LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigcirc";
static int* LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upper left triangle html character entity reference model.
 *
 * Name: ultri
 * Character: ◸
 * Unicode code point: U+25f8 (9720)
 * Description: upper left triangle
 */
static wchar_t* UPPER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ultri";
static int* UPPER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upper right triangle html character entity reference model.
 *
 * Name: urtri
 * Character: ◹
 * Unicode code point: U+25f9 (9721)
 * Description: upper right triangle
 */
static wchar_t* UPPER_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urtri";
static int* UPPER_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lower left triangle html character entity reference model.
 *
 * Name: lltri
 * Character: ◺
 * Unicode code point: U+25fa (9722)
 * Description: lower left triangle
 */
static wchar_t* LOWER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lltri";
static int* LOWER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white medium square html character entity reference model.
 *
 * Name: EmptySmallSquare
 * Character: ◻
 * Unicode code point: U+25fb (9723)
 * Description: white medium square
 */
static wchar_t* WHITE_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EmptySmallSquare";
static int* WHITE_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black medium square html character entity reference model.
 *
 * Name: FilledSmallSquare
 * Character: ◼
 * Unicode code point: U+25fc (9724)
 * Description: black medium square
 */
static wchar_t* BLACK_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"FilledSmallSquare";
static int* BLACK_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black star html character entity reference model.
 *
 * Name: bigstar
 * Character: ★
 * Unicode code point: U+2605 (9733)
 * Description: black star
 */
static wchar_t* BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigstar";
static int* BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The white star html character entity reference model.
 *
 * Name: star
 * Character: ☆
 * Unicode code point: U+2606 (9734)
 * Description: white star
 */
static wchar_t* WHITE_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"star";
static int* WHITE_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black telephone html character entity reference model.
 *
 * Name: phone
 * Character: ☎
 * Unicode code point: U+260e (9742)
 * Description: black telephone
 */
static wchar_t* BLACK_TELEPHONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phone";
static int* BLACK_TELEPHONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The female sign html character entity reference model.
 *
 * Name: female
 * Character: ♀
 * Unicode code point: U+2640 (9792)
 * Description: female sign
 */
static wchar_t* FEMALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"female";
static int* FEMALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The male sign html character entity reference model.
 *
 * Name: male
 * Character: ♂
 * Unicode code point: U+2642 (9794)
 * Description: male sign
 */
static wchar_t* MALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"male";
static int* MALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black spade suit html character entity reference model.
 *
 * Name: spades
 * Character: ♠
 * Unicode code point: U+2660 (9824)
 * Description: black spade suit
 */
static wchar_t* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"spades";
static int* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black club suit html character entity reference model.
 *
 * Name: clubs
 * Character: ♣
 * Unicode code point: U+2663 (9827)
 * Description: black club suit
 */
static wchar_t* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"clubs";
static int* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black heart suit html character entity reference model.
 *
 * Name: hearts
 * Character: ♥
 * Unicode code point: U+2665 (9829)
 * Description: black heart suit
 */
static wchar_t* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hearts";
static int* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black diamond suit html character entity reference model.
 *
 * Name: diamondsuit
 * Character: ♦
 * Unicode code point: U+2666 (9830)
 * Description: black diamond suit
 */
static wchar_t* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diamondsuit";
static int* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eighth note html character entity reference model.
 *
 * Name: sung
 * Character: ♪
 * Unicode code point: U+266a (9834)
 * Description: eighth note
 */
static wchar_t* EIGHTH_NOTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sung";
static int* EIGHTH_NOTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The music flat sign html character entity reference model.
 *
 * Name: flat
 * Character: ♭
 * Unicode code point: U+266d (9837)
 * Description: music flat sign
 */
static wchar_t* MUSIC_FLAT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"flat";
static int* MUSIC_FLAT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The music natural sign html character entity reference model.
 *
 * Name: natur
 * Character: ♮
 * Unicode code point: U+266e (9838)
 * Description: music natural sign
 */
static wchar_t* MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"natur";
static int* MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The music sharp sign html character entity reference model.
 *
 * Name: sharp
 * Character: ♯
 * Unicode code point: U+266f (9839)
 * Description: music sharp sign
 */
static wchar_t* MUSIC_SHARP_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sharp";
static int* MUSIC_SHARP_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check mark html character entity reference model.
 *
 * Name: check
 * Character: ✓
 * Unicode code point: U+2713 (10003)
 * Description: check mark
 */
static wchar_t* CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"check";
static int* CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ballot x html character entity reference model.
 *
 * Name: cross
 * Character: ✗
 * Unicode code point: U+2717 (10007)
 * Description: ballot x
 */
static wchar_t* BALLOT_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cross";
static int* BALLOT_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maltese cross html character entity reference model.
 *
 * Name: malt
 * Character: ✠
 * Unicode code point: U+2720 (10016)
 * Description: maltese cross
 */
static wchar_t* MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"malt";
static int* MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The six pointed black star html character entity reference model.
 *
 * Name: sext
 * Character: ✶
 * Unicode code point: U+2736 (10038)
 * Description: six pointed black star
 */
static wchar_t* SIX_POINTED_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sext";
static int* SIX_POINTED_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The light vertical bar html character entity reference model.
 *
 * Name: VerticalSeparator
 * Character: ❘
 * Unicode code point: U+2758 (10072)
 * Description: light vertical bar
 */
static wchar_t* LIGHT_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalSeparator";
static int* LIGHT_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The light left tortoise shell bracket ornament html character entity reference model.
 *
 * Name: lbbrk
 * Character: ❲
 * Unicode code point: U+2772 (10098)
 * Description: light left tortoise shell bracket ornament
 */
static wchar_t* LIGHT_LEFT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbbrk";
static int* LIGHT_LEFT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The light right tortoise shell bracket ornament html character entity reference model.
 *
 * Name: rbbrk
 * Character: ❳
 * Unicode code point: U+2773 (10099)
 * Description: light right tortoise shell bracket ornament
 */
static wchar_t* LIGHT_RIGHT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbbrk";
static int* LIGHT_RIGHT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reverse solidus preceding subset html character entity reference model.
 *
 * Name: bsolhsub
 * Character: ⟈
 * Unicode code point: U+27c8 (10184)
 * Description: reverse solidus preceding subset
 */
static wchar_t* REVERSE_SOLIDUS_PRECEDING_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsolhsub";
static int* REVERSE_SOLIDUS_PRECEDING_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset preceding solidus html character entity reference model.
 *
 * Name: suphsol
 * Character: ⟉
 * Unicode code point: U+27c9 (10185)
 * Description: superset preceding solidus
 */
static wchar_t* SUPERSET_PRECEDING_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suphsol";
static int* SUPERSET_PRECEDING_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical left white square bracket html character entity reference model.
 *
 * Name: LeftDoubleBracket
 * Character: ⟦
 * Unicode code point: U+27e6 (10214)
 * Description: mathematical left white square bracket
 */
static wchar_t* MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDoubleBracket";
static int* MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical right white square bracket html character entity reference model.
 *
 * Name: RightDoubleBracket
 * Character: ⟧
 * Unicode code point: U+27e7 (10215)
 * Description: mathematical right white square bracket
 */
static wchar_t* MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDoubleBracket";
static int* MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical left angle bracket html character entity reference model.
 *
 * Name: LeftAngleBracket
 * Character: ⟨
 * Unicode code point: U+27e8 (10216)
 * Description: mathematical left angle bracket
 */
static wchar_t* MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftAngleBracket";
static int* MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical right angle bracket html character entity reference model.
 *
 * Name: RightAngleBracket
 * Character: ⟩
 * Unicode code point: U+27e9 (10217)
 * Description: mathematical right angle bracket
 */
static wchar_t* MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightAngleBracket";
static int* MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical left double angle bracket html character entity reference model.
 *
 * Name: Lang
 * Character: ⟪
 * Unicode code point: U+27ea (10218)
 * Description: mathematical left double angle bracket
 */
static wchar_t* MATHEMATICAL_LEFT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lang";
static int* MATHEMATICAL_LEFT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical right double angle bracket html character entity reference model.
 *
 * Name: Rang
 * Character: ⟫
 * Unicode code point: U+27eb (10219)
 * Description: mathematical right double angle bracket
 */
static wchar_t* MATHEMATICAL_RIGHT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rang";
static int* MATHEMATICAL_RIGHT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical left white tortoise shell bracket html character entity reference model.
 *
 * Name: loang
 * Character: ⟬
 * Unicode code point: U+27ec (10220)
 * Description: mathematical left white tortoise shell bracket
 */
static wchar_t* MATHEMATICAL_LEFT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loang";
static int* MATHEMATICAL_LEFT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical right white tortoise shell bracket html character entity reference model.
 *
 * Name: roang
 * Character: ⟭
 * Unicode code point: U+27ed (10221)
 * Description: mathematical right white tortoise shell bracket
 */
static wchar_t* MATHEMATICAL_RIGHT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roang";
static int* MATHEMATICAL_RIGHT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long leftwards arrow html character entity reference model.
 *
 * Name: LongLeftArrow
 * Character: ⟵
 * Unicode code point: U+27f5 (10229)
 * Description: long leftwards arrow
 */
static wchar_t* LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongLeftArrow";
static int* LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long rightwards arrow html character entity reference model.
 *
 * Name: LongRightArrow
 * Character: ⟶
 * Unicode code point: U+27f6 (10230)
 * Description: long rightwards arrow
 */
static wchar_t* LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongRightArrow";
static int* LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long left right arrow html character entity reference model.
 *
 * Name: LongLeftRightArrow
 * Character: ⟷
 * Unicode code point: U+27f7 (10231)
 * Description: long left right arrow
 */
static wchar_t* LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongLeftRightArrow";
static int* LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long leftwards double arrow html character entity reference model.
 *
 * Name: DoubleLongLeftArrow
 * Character: ⟸
 * Unicode code point: U+27f8 (10232)
 * Description: long leftwards double arrow
 */
static wchar_t* LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongLeftArrow";
static int* LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long rightwards double arrow html character entity reference model.
 *
 * Name: DoubleLongRightArrow
 * Character: ⟹
 * Unicode code point: U+27f9 (10233)
 * Description: long rightwards double arrow
 */
static wchar_t* LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongRightArrow";
static int* LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long left right double arrow html character entity reference model.
 *
 * Name: DoubleLongLeftRightArrow
 * Character: ⟺
 * Unicode code point: U+27fa (10234)
 * Description: long left right double arrow
 */
static wchar_t* LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongLeftRightArrow";
static int* LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long rightwards arrow from bar html character entity reference model.
 *
 * Name: longmapsto
 * Character: ⟼
 * Unicode code point: U+27fc (10236)
 * Description: long rightwards arrow from bar
 */
static wchar_t* LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"longmapsto";
static int* LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long rightwards squiggle arrow html character entity reference model.
 *
 * Name: dzigrarr
 * Character: ⟿
 * Unicode code point: U+27ff (10239)
 * Description: long rightwards squiggle arrow
 */
static wchar_t* LONG_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dzigrarr";
static int* LONG_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double arrow with vertical stroke html character entity reference model.
 *
 * Name: nvlArr
 * Character: ⤂
 * Unicode code point: U+2902 (10498)
 * Description: leftwards double arrow with vertical stroke
 */
static wchar_t* LEFTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvlArr";
static int* LEFTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double arrow with vertical stroke html character entity reference model.
 *
 * Name: nvrArr
 * Character: ⤃
 * Unicode code point: U+2903 (10499)
 * Description: rightwards double arrow with vertical stroke
 */
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvrArr";
static int* RIGHTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right double arrow with vertical stroke html character entity reference model.
 *
 * Name: nvHarr
 * Character: ⤄
 * Unicode code point: U+2904 (10500)
 * Description: left right double arrow with vertical stroke
 */
static wchar_t* LEFT_RIGHT_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvHarr";
static int* LEFT_RIGHT_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards two-headed arrow from bar html character entity reference model.
 *
 * Name: Map
 * Character: ⤅
 * Unicode code point: U+2905 (10501)
 * Description: rightwards two-headed arrow from bar
 */
static wchar_t* RIGHTWARDS_TWO_HEADED_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Map";
static int* RIGHTWARDS_TWO_HEADED_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double dash arrow html character entity reference model.
 *
 * Name: lbarr
 * Character: ⤌
 * Unicode code point: U+290c (10508)
 * Description: leftwards double dash arrow
 */
static wchar_t* LEFTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbarr";
static int* LEFTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double dash arrow html character entity reference model.
 *
 * Name: bkarow
 * Character: ⤍
 * Unicode code point: U+290d (10509)
 * Description: rightwards double dash arrow
 */
static wchar_t* RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bkarow";
static int* RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards triple dash arrow html character entity reference model.
 *
 * Name: lBarr
 * Character: ⤎
 * Unicode code point: U+290e (10510)
 * Description: leftwards triple dash arrow
 */
static wchar_t* LEFTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lBarr";
static int* LEFTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards triple dash arrow html character entity reference model.
 *
 * Name: dbkarow
 * Character: ⤏
 * Unicode code point: U+290f (10511)
 * Description: rightwards triple dash arrow
 */
static wchar_t* RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dbkarow";
static int* RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards two-headed triple dash arrow html character entity reference model.
 *
 * Name: RBarr
 * Character: ⤐
 * Unicode code point: U+2910 (10512)
 * Description: rightwards two-headed triple dash arrow
 */
static wchar_t* RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RBarr";
static int* RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with dotted stem html character entity reference model.
 *
 * Name: DDotrahd
 * Character: ⤑
 * Unicode code point: U+2911 (10513)
 * Description: rightwards arrow with dotted stem
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_DOTTED_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DDotrahd";
static int* RIGHTWARDS_ARROW_WITH_DOTTED_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards arrow to bar html character entity reference model.
 *
 * Name: UpArrowBar
 * Character: ⤒
 * Unicode code point: U+2912 (10514)
 * Description: upwards arrow to bar
 */
static wchar_t* UPWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpArrowBar";
static int* UPWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards arrow to bar html character entity reference model.
 *
 * Name: DownArrowBar
 * Character: ⤓
 * Unicode code point: U+2913 (10515)
 * Description: downwards arrow to bar
 */
static wchar_t* DOWNWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrowBar";
static int* DOWNWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards two-headed arrow with tail html character entity reference model.
 *
 * Name: Rarrtl
 * Character: ⤖
 * Unicode code point: U+2916 (10518)
 * Description: rightwards two-headed arrow with tail
 */
static wchar_t* RIGHTWARDS_TWO_HEADED_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rarrtl";
static int* RIGHTWARDS_TWO_HEADED_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow-tail html character entity reference model.
 *
 * Name: latail
 * Character: ⤙
 * Unicode code point: U+2919 (10521)
 * Description: leftwards arrow-tail
 */
static wchar_t* LEFTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"latail";
static int* LEFTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow-tail html character entity reference model.
 *
 * Name: ratail
 * Character: ⤚
 * Unicode code point: U+291a (10522)
 * Description: rightwards arrow-tail
 */
static wchar_t* RIGHTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ratail";
static int* RIGHTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards double arrow-tail html character entity reference model.
 *
 * Name: lAtail
 * Character: ⤛
 * Unicode code point: U+291b (10523)
 * Description: leftwards double arrow-tail
 */
static wchar_t* LEFTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lAtail";
static int* LEFTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards double arrow-tail html character entity reference model.
 *
 * Name: rAtail
 * Character: ⤜
 * Unicode code point: U+291c (10524)
 * Description: rightwards double arrow-tail
 */
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rAtail";
static int* RIGHTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow to black diamond html character entity reference model.
 *
 * Name: larrfs
 * Character: ⤝
 * Unicode code point: U+291d (10525)
 * Description: leftwards arrow to black diamond
 */
static wchar_t* LEFTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrfs";
static int* LEFTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow to black diamond html character entity reference model.
 *
 * Name: rarrfs
 * Character: ⤞
 * Unicode code point: U+291e (10526)
 * Description: rightwards arrow to black diamond
 */
static wchar_t* RIGHTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrfs";
static int* RIGHTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow from bar to black diamond html character entity reference model.
 *
 * Name: larrbfs
 * Character: ⤟
 * Unicode code point: U+291f (10527)
 * Description: leftwards arrow from bar to black diamond
 */
static wchar_t* LEFTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrbfs";
static int* LEFTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow from bar to black diamond html character entity reference model.
 *
 * Name: rarrbfs
 * Character: ⤠
 * Unicode code point: U+2920 (10528)
 * Description: rightwards arrow from bar to black diamond
 */
static wchar_t* RIGHTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrbfs";
static int* RIGHTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north west arrow with hook html character entity reference model.
 *
 * Name: nwarhk
 * Character: ⤣
 * Unicode code point: U+2923 (10531)
 * Description: north west arrow with hook
 */
static wchar_t* NORTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwarhk";
static int* NORTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north east arrow with hook html character entity reference model.
 *
 * Name: nearhk
 * Character: ⤤
 * Unicode code point: U+2924 (10532)
 * Description: north east arrow with hook
 */
static wchar_t* NORTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nearhk";
static int* NORTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south east arrow with hook html character entity reference model.
 *
 * Name: hksearow
 * Character: ⤥
 * Unicode code point: U+2925 (10533)
 * Description: south east arrow with hook
 */
static wchar_t* SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hksearow";
static int* SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south west arrow with hook html character entity reference model.
 *
 * Name: hkswarow
 * Character: ⤦
 * Unicode code point: U+2926 (10534)
 * Description: south west arrow with hook
 */
static wchar_t* SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hkswarow";
static int* SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north west arrow and north east arrow html character entity reference model.
 *
 * Name: nwnear
 * Character: ⤧
 * Unicode code point: U+2927 (10535)
 * Description: north west arrow and north east arrow
 */
static wchar_t* NORTH_WEST_ARROW_AND_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwnear";
static int* NORTH_WEST_ARROW_AND_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The north east arrow and south east arrow html character entity reference model.
 *
 * Name: nesear
 * Character: ⤨
 * Unicode code point: U+2928 (10536)
 * Description: north east arrow and south east arrow
 */
static wchar_t* NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nesear";
static int* NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south east arrow and south west arrow html character entity reference model.
 *
 * Name: seswar
 * Character: ⤩
 * Unicode code point: U+2929 (10537)
 * Description: south east arrow and south west arrow
 */
static wchar_t* SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"seswar";
static int* SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The south west arrow and north west arrow html character entity reference model.
 *
 * Name: swnwar
 * Character: ⤪
 * Unicode code point: U+292a (10538)
 * Description: south west arrow and north west arrow
 */
static wchar_t* SOUTH_WEST_ARROW_AND_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swnwar";
static int* SOUTH_WEST_ARROW_AND_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wave arrow pointing directly right with slash html character entity reference model.
 *
 * Name: nrarrc
 * Character: ⤳̸
 * Unicode code point: U+2933;U+0338 (10547;824)
 * Description: wave arrow pointing directly right with slash
 */
static wchar_t* WAVE_ARROW_POINTING_DIRECTLY_RIGHT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarrc";
static int* WAVE_ARROW_POINTING_DIRECTLY_RIGHT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wave arrow pointing directly right html character entity reference model.
 *
 * Name: rarrc
 * Character: ⤳
 * Unicode code point: U+2933 (10547)
 * Description: wave arrow pointing directly right
 */
static wchar_t* WAVE_ARROW_POINTING_DIRECTLY_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrc";
static int* WAVE_ARROW_POINTING_DIRECTLY_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The arrow pointing rightwards then curving downwards html character entity reference model.
 *
 * Name: cudarrr
 * Character: ⤵
 * Unicode code point: U+2935 (10549)
 * Description: arrow pointing rightwards then curving downwards
 */
static wchar_t* ARROW_POINTING_RIGHTWARDS_THEN_CURVING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cudarrr";
static int* ARROW_POINTING_RIGHTWARDS_THEN_CURVING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The arrow pointing downwards then curving leftwards html character entity reference model.
 *
 * Name: ldca
 * Character: ⤶
 * Unicode code point: U+2936 (10550)
 * Description: arrow pointing downwards then curving leftwards
 */
static wchar_t* ARROW_POINTING_DOWNWARDS_THEN_CURVING_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldca";
static int* ARROW_POINTING_DOWNWARDS_THEN_CURVING_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The arrow pointing downwards then curving rightwards html character entity reference model.
 *
 * Name: rdca
 * Character: ⤷
 * Unicode code point: U+2937 (10551)
 * Description: arrow pointing downwards then curving rightwards
 */
static wchar_t* ARROW_POINTING_DOWNWARDS_THEN_CURVING_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdca";
static int* ARROW_POINTING_DOWNWARDS_THEN_CURVING_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right-side arc clockwise arrow html character entity reference model.
 *
 * Name: cudarrl
 * Character: ⤸
 * Unicode code point: U+2938 (10552)
 * Description: right-side arc clockwise arrow
 */
static wchar_t* RIGHT_SIDE_ARC_CLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cudarrl";
static int* RIGHT_SIDE_ARC_CLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left-side arc anticlockwise arrow html character entity reference model.
 *
 * Name: larrpl
 * Character: ⤹
 * Unicode code point: U+2939 (10553)
 * Description: left-side arc anticlockwise arrow
 */
static wchar_t* LEFT_SIDE_ARC_ANTICLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrpl";
static int* LEFT_SIDE_ARC_ANTICLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top arc clockwise arrow with minus html character entity reference model.
 *
 * Name: curarrm
 * Character: ⤼
 * Unicode code point: U+293c (10556)
 * Description: top arc clockwise arrow with minus
 */
static wchar_t* TOP_ARC_CLOCKWISE_ARROW_WITH_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curarrm";
static int* TOP_ARC_CLOCKWISE_ARROW_WITH_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top arc anticlockwise arrow with plus html character entity reference model.
 *
 * Name: cularrp
 * Character: ⤽
 * Unicode code point: U+293d (10557)
 * Description: top arc anticlockwise arrow with plus
 */
static wchar_t* TOP_ARC_ANTICLOCKWISE_ARROW_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cularrp";
static int* TOP_ARC_ANTICLOCKWISE_ARROW_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow with plus below html character entity reference model.
 *
 * Name: rarrpl
 * Character: ⥅
 * Unicode code point: U+2945 (10565)
 * Description: rightwards arrow with plus below
 */
static wchar_t* RIGHTWARDS_ARROW_WITH_PLUS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrpl";
static int* RIGHTWARDS_ARROW_WITH_PLUS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left right arrow through small circle html character entity reference model.
 *
 * Name: harrcir
 * Character: ⥈
 * Unicode code point: U+2948 (10568)
 * Description: left right arrow through small circle
 */
static wchar_t* LEFT_RIGHT_ARROW_THROUGH_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harrcir";
static int* LEFT_RIGHT_ARROW_THROUGH_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards two-headed arrow from small circle html character entity reference model.
 *
 * Name: Uarrocir
 * Character: ⥉
 * Unicode code point: U+2949 (10569)
 * Description: upwards two-headed arrow from small circle
 */
static wchar_t* UPWARDS_TWO_HEADED_ARROW_FROM_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uarrocir";
static int* UPWARDS_TWO_HEADED_ARROW_FROM_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left barb up right barb down harpoon html character entity reference model.
 *
 * Name: lurdshar
 * Character: ⥊
 * Unicode code point: U+294a (10570)
 * Description: left barb up right barb down harpoon
 */
static wchar_t* LEFT_BARB_UP_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lurdshar";
static int* LEFT_BARB_UP_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left barb down right barb up harpoon html character entity reference model.
 *
 * Name: ldrushar
 * Character: ⥋
 * Unicode code point: U+294b (10571)
 * Description: left barb down right barb up harpoon
 */
static wchar_t* LEFT_BARB_DOWN_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldrushar";
static int* LEFT_BARB_DOWN_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left barb up right barb up harpoon html character entity reference model.
 *
 * Name: LeftRightVector
 * Character: ⥎
 * Unicode code point: U+294e (10574)
 * Description: left barb up right barb up harpoon
 */
static wchar_t* LEFT_BARB_UP_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftRightVector";
static int* LEFT_BARB_UP_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up barb right down barb right harpoon html character entity reference model.
 *
 * Name: RightUpDownVector
 * Character: ⥏
 * Unicode code point: U+294f (10575)
 * Description: up barb right down barb right harpoon
 */
static wchar_t* UP_BARB_RIGHT_DOWN_BARB_RIGHT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpDownVector";
static int* UP_BARB_RIGHT_DOWN_BARB_RIGHT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left barb down right barb down harpoon html character entity reference model.
 *
 * Name: DownLeftRightVector
 * Character: ⥐
 * Unicode code point: U+2950 (10576)
 * Description: left barb down right barb down harpoon
 */
static wchar_t* LEFT_BARB_DOWN_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftRightVector";
static int* LEFT_BARB_DOWN_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up barb left down barb left harpoon html character entity reference model.
 *
 * Name: LeftUpDownVector
 * Character: ⥑
 * Unicode code point: U+2951 (10577)
 * Description: up barb left down barb left harpoon
 */
static wchar_t* UP_BARB_LEFT_DOWN_BARB_LEFT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpDownVector";
static int* UP_BARB_LEFT_DOWN_BARB_LEFT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb up to bar html character entity reference model.
 *
 * Name: LeftVectorBar
 * Character: ⥒
 * Unicode code point: U+2952 (10578)
 * Description: leftwards harpoon with barb up to bar
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftVectorBar";
static int* LEFTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb up to bar html character entity reference model.
 *
 * Name: RightVectorBar
 * Character: ⥓
 * Unicode code point: U+2953 (10579)
 * Description: rightwards harpoon with barb up to bar
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightVectorBar";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb right to bar html character entity reference model.
 *
 * Name: RightUpVectorBar
 * Character: ⥔
 * Unicode code point: U+2954 (10580)
 * Description: upwards harpoon with barb right to bar
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpVectorBar";
static int* UPWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb right to bar html character entity reference model.
 *
 * Name: RightDownVectorBar
 * Character: ⥕
 * Unicode code point: U+2955 (10581)
 * Description: downwards harpoon with barb right to bar
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownVectorBar";
static int* DOWNWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb down to bar html character entity reference model.
 *
 * Name: DownLeftVectorBar
 * Character: ⥖
 * Unicode code point: U+2956 (10582)
 * Description: leftwards harpoon with barb down to bar
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftVectorBar";
static int* LEFTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb down to bar html character entity reference model.
 *
 * Name: DownRightVectorBar
 * Character: ⥗
 * Unicode code point: U+2957 (10583)
 * Description: rightwards harpoon with barb down to bar
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightVectorBar";
static int* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb left to bar html character entity reference model.
 *
 * Name: LeftUpVectorBar
 * Character: ⥘
 * Unicode code point: U+2958 (10584)
 * Description: upwards harpoon with barb left to bar
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpVectorBar";
static int* UPWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb left to bar html character entity reference model.
 *
 * Name: LeftDownVectorBar
 * Character: ⥙
 * Unicode code point: U+2959 (10585)
 * Description: downwards harpoon with barb left to bar
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownVectorBar";
static int* DOWNWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb up from bar html character entity reference model.
 *
 * Name: LeftTeeVector
 * Character: ⥚
 * Unicode code point: U+295a (10586)
 * Description: leftwards harpoon with barb up from bar
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTeeVector";
static int* LEFTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb up from bar html character entity reference model.
 *
 * Name: RightTeeVector
 * Character: ⥛
 * Unicode code point: U+295b (10587)
 * Description: rightwards harpoon with barb up from bar
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTeeVector";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb right from bar html character entity reference model.
 *
 * Name: RightUpTeeVector
 * Character: ⥜
 * Unicode code point: U+295c (10588)
 * Description: upwards harpoon with barb right from bar
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpTeeVector";
static int* UPWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb right from bar html character entity reference model.
 *
 * Name: RightDownTeeVector
 * Character: ⥝
 * Unicode code point: U+295d (10589)
 * Description: downwards harpoon with barb right from bar
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownTeeVector";
static int* DOWNWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb down from bar html character entity reference model.
 *
 * Name: DownLeftTeeVector
 * Character: ⥞
 * Unicode code point: U+295e (10590)
 * Description: leftwards harpoon with barb down from bar
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftTeeVector";
static int* LEFTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb down from bar html character entity reference model.
 *
 * Name: DownRightTeeVector
 * Character: ⥟
 * Unicode code point: U+295f (10591)
 * Description: rightwards harpoon with barb down from bar
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightTeeVector";
static int* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb left from bar html character entity reference model.
 *
 * Name: LeftUpTeeVector
 * Character: ⥠
 * Unicode code point: U+2960 (10592)
 * Description: upwards harpoon with barb left from bar
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpTeeVector";
static int* UPWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb left from bar html character entity reference model.
 *
 * Name: LeftDownTeeVector
 * Character: ⥡
 * Unicode code point: U+2961 (10593)
 * Description: downwards harpoon with barb left from bar
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownTeeVector";
static int* DOWNWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb up above leftwards harpoon with barb down html character entity reference model.
 *
 * Name: lHar
 * Character: ⥢
 * Unicode code point: U+2962 (10594)
 * Description: leftwards harpoon with barb up above leftwards harpoon with barb down
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lHar";
static int* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb left beside upwards harpoon with barb right html character entity reference model.
 *
 * Name: uHar
 * Character: ⥣
 * Unicode code point: U+2963 (10595)
 * Description: upwards harpoon with barb left beside upwards harpoon with barb right
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uHar";
static int* UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb up above rightwards harpoon with barb down html character entity reference model.
 *
 * Name: rHar
 * Character: ⥤
 * Unicode code point: U+2964 (10596)
 * Description: rightwards harpoon with barb up above rightwards harpoon with barb down
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rHar";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb left beside downwards harpoon with barb right html character entity reference model.
 *
 * Name: dHar
 * Character: ⥥
 * Unicode code point: U+2965 (10597)
 * Description: downwards harpoon with barb left beside downwards harpoon with barb right
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dHar";
static int* DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb up above rightwards harpoon with barb up html character entity reference model.
 *
 * Name: luruhar
 * Character: ⥦
 * Unicode code point: U+2966 (10598)
 * Description: leftwards harpoon with barb up above rightwards harpoon with barb up
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"luruhar";
static int* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb down above rightwards harpoon with barb down html character entity reference model.
 *
 * Name: ldrdhar
 * Character: ⥧
 * Unicode code point: U+2967 (10599)
 * Description: leftwards harpoon with barb down above rightwards harpoon with barb down
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldrdhar";
static int* LEFTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb up above leftwards harpoon with barb up html character entity reference model.
 *
 * Name: ruluhar
 * Character: ⥨
 * Unicode code point: U+2968 (10600)
 * Description: rightwards harpoon with barb up above leftwards harpoon with barb up
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ruluhar";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb down above leftwards harpoon with barb down html character entity reference model.
 *
 * Name: rdldhar
 * Character: ⥩
 * Unicode code point: U+2969 (10601)
 * Description: rightwards harpoon with barb down above leftwards harpoon with barb down
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdldhar";
static int* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb up above long dash html character entity reference model.
 *
 * Name: lharul
 * Character: ⥪
 * Unicode code point: U+296a (10602)
 * Description: leftwards harpoon with barb up above long dash
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lharul";
static int* LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards harpoon with barb down below long dash html character entity reference model.
 *
 * Name: llhard
 * Character: ⥫
 * Unicode code point: U+296b (10603)
 * Description: leftwards harpoon with barb down below long dash
 */
static wchar_t* LEFTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"llhard";
static int* LEFTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb up above long dash html character entity reference model.
 *
 * Name: rharul
 * Character: ⥬
 * Unicode code point: U+296c (10604)
 * Description: rightwards harpoon with barb up above long dash
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rharul";
static int* RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards harpoon with barb down below long dash html character entity reference model.
 *
 * Name: lrhard
 * Character: ⥭
 * Unicode code point: U+296d (10605)
 * Description: rightwards harpoon with barb down below long dash
 */
static wchar_t* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrhard";
static int* RIGHTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upwards harpoon with barb left beside downwards harpoon with barb right html character entity reference model.
 *
 * Name: UpEquilibrium
 * Character: ⥮
 * Unicode code point: U+296e (10606)
 * Description: upwards harpoon with barb left beside downwards harpoon with barb right
 */
static wchar_t* UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpEquilibrium";
static int* UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downwards harpoon with barb left beside upwards harpoon with barb right html character entity reference model.
 *
 * Name: ReverseUpEquilibrium
 * Character: ⥯
 * Unicode code point: U+296f (10607)
 * Description: downwards harpoon with barb left beside upwards harpoon with barb right
 */
static wchar_t* DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseUpEquilibrium";
static int* DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right double arrow with rounded head html character entity reference model.
 *
 * Name: RoundImplies
 * Character: ⥰
 * Unicode code point: U+2970 (10608)
 * Description: right double arrow with rounded head
 */
static wchar_t* RIGHT_DOUBLE_ARROW_WITH_ROUNDED_HEAD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RoundImplies";
static int* RIGHT_DOUBLE_ARROW_WITH_ROUNDED_HEAD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign above rightwards arrow html character entity reference model.
 *
 * Name: erarr
 * Character: ⥱
 * Unicode code point: U+2971 (10609)
 * Description: equals sign above rightwards arrow
 */
static wchar_t* EQUALS_SIGN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"erarr";
static int* EQUALS_SIGN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde operator above rightwards arrow html character entity reference model.
 *
 * Name: simrarr
 * Character: ⥲
 * Unicode code point: U+2972 (10610)
 * Description: tilde operator above rightwards arrow
 */
static wchar_t* TILDE_OPERATOR_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simrarr";
static int* TILDE_OPERATOR_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftwards arrow above tilde operator html character entity reference model.
 *
 * Name: larrsim
 * Character: ⥳
 * Unicode code point: U+2973 (10611)
 * Description: leftwards arrow above tilde operator
 */
static wchar_t* LEFTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrsim";
static int* LEFTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow above tilde operator html character entity reference model.
 *
 * Name: rarrsim
 * Character: ⥴
 * Unicode code point: U+2974 (10612)
 * Description: rightwards arrow above tilde operator
 */
static wchar_t* RIGHTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrsim";
static int* RIGHTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightwards arrow above almost equal to html character entity reference model.
 *
 * Name: rarrap
 * Character: ⥵
 * Unicode code point: U+2975 (10613)
 * Description: rightwards arrow above almost equal to
 */
static wchar_t* RIGHTWARDS_ARROW_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrap";
static int* RIGHTWARDS_ARROW_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above leftwards arrow html character entity reference model.
 *
 * Name: ltlarr
 * Character: ⥶
 * Unicode code point: U+2976 (10614)
 * Description: less-than above leftwards arrow
 */
static wchar_t* LESS_THAN_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltlarr";
static int* LESS_THAN_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above rightwards arrow html character entity reference model.
 *
 * Name: gtrarr
 * Character: ⥸
 * Unicode code point: U+2978 (10616)
 * Description: greater-than above rightwards arrow
 */
static wchar_t* GREATER_THAN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrarr";
static int* GREATER_THAN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset above rightwards arrow html character entity reference model.
 *
 * Name: subrarr
 * Character: ⥹
 * Unicode code point: U+2979 (10617)
 * Description: subset above rightwards arrow
 */
static wchar_t* SUBSET_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subrarr";
static int* SUBSET_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset above leftwards arrow html character entity reference model.
 *
 * Name: suplarr
 * Character: ⥻
 * Unicode code point: U+297b (10619)
 * Description: superset above leftwards arrow
 */
static wchar_t* SUPERSET_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suplarr";
static int* SUPERSET_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left fish tail html character entity reference model.
 *
 * Name: lfisht
 * Character: ⥼
 * Unicode code point: U+297c (10620)
 * Description: left fish tail
 */
static wchar_t* LEFT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfisht";
static int* LEFT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right fish tail html character entity reference model.
 *
 * Name: rfisht
 * Character: ⥽
 * Unicode code point: U+297d (10621)
 * Description: right fish tail
 */
static wchar_t* RIGHT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfisht";
static int* RIGHT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up fish tail html character entity reference model.
 *
 * Name: ufisht
 * Character: ⥾
 * Unicode code point: U+297e (10622)
 * Description: up fish tail
 */
static wchar_t* UP_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ufisht";
static int* UP_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The down fish tail html character entity reference model.
 *
 * Name: dfisht
 * Character: ⥿
 * Unicode code point: U+297f (10623)
 * Description: down fish tail
 */
static wchar_t* DOWN_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dfisht";
static int* DOWN_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left white parenthesis html character entity reference model.
 *
 * Name: lopar
 * Character: ⦅
 * Unicode code point: U+2985 (10629)
 * Description: left white parenthesis
 */
static wchar_t* LEFT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lopar";
static int* LEFT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right white parenthesis html character entity reference model.
 *
 * Name: ropar
 * Character: ⦆
 * Unicode code point: U+2986 (10630)
 * Description: right white parenthesis
 */
static wchar_t* RIGHT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ropar";
static int* RIGHT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left square bracket with underbar html character entity reference model.
 *
 * Name: lbrke
 * Character: ⦋
 * Unicode code point: U+298b (10635)
 * Description: left square bracket with underbar
 */
static wchar_t* LEFT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrke";
static int* LEFT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right square bracket with underbar html character entity reference model.
 *
 * Name: rbrke
 * Character: ⦌
 * Unicode code point: U+298c (10636)
 * Description: right square bracket with underbar
 */
static wchar_t* RIGHT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrke";
static int* RIGHT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left square bracket with tick in top corner html character entity reference model.
 *
 * Name: lbrkslu
 * Character: ⦍
 * Unicode code point: U+298d (10637)
 * Description: left square bracket with tick in top corner
 */
static wchar_t* LEFT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrkslu";
static int* LEFT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right square bracket with tick in bottom corner html character entity reference model.
 *
 * Name: rbrksld
 * Character: ⦎
 * Unicode code point: U+298e (10638)
 * Description: right square bracket with tick in bottom corner
 */
static wchar_t* RIGHT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrksld";
static int* RIGHT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left square bracket with tick in bottom corner html character entity reference model.
 *
 * Name: lbrksld
 * Character: ⦏
 * Unicode code point: U+298f (10639)
 * Description: left square bracket with tick in bottom corner
 */
static wchar_t* LEFT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrksld";
static int* LEFT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right square bracket with tick in top corner html character entity reference model.
 *
 * Name: rbrkslu
 * Character: ⦐
 * Unicode code point: U+2990 (10640)
 * Description: right square bracket with tick in top corner
 */
static wchar_t* RIGHT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrkslu";
static int* RIGHT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left angle bracket with dot html character entity reference model.
 *
 * Name: langd
 * Character: ⦑
 * Unicode code point: U+2991 (10641)
 * Description: left angle bracket with dot
 */
static wchar_t* LEFT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"langd";
static int* LEFT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right angle bracket with dot html character entity reference model.
 *
 * Name: rangd
 * Character: ⦒
 * Unicode code point: U+2992 (10642)
 * Description: right angle bracket with dot
 */
static wchar_t* RIGHT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rangd";
static int* RIGHT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left arc less-than bracket html character entity reference model.
 *
 * Name: lparlt
 * Character: ⦓
 * Unicode code point: U+2993 (10643)
 * Description: left arc less-than bracket
 */
static wchar_t* LEFT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lparlt";
static int* LEFT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right arc greater-than bracket html character entity reference model.
 *
 * Name: rpargt
 * Character: ⦔
 * Unicode code point: U+2994 (10644)
 * Description: right arc greater-than bracket
 */
static wchar_t* RIGHT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rpargt";
static int* RIGHT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double left arc greater-than bracket html character entity reference model.
 *
 * Name: gtlPar
 * Character: ⦕
 * Unicode code point: U+2995 (10645)
 * Description: double left arc greater-than bracket
 */
static wchar_t* DOUBLE_LEFT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtlPar";
static int* DOUBLE_LEFT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double right arc less-than bracket html character entity reference model.
 *
 * Name: ltrPar
 * Character: ⦖
 * Unicode code point: U+2996 (10646)
 * Description: double right arc less-than bracket
 */
static wchar_t* DOUBLE_RIGHT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltrPar";
static int* DOUBLE_RIGHT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical zigzag line html character entity reference model.
 *
 * Name: vzigzag
 * Character: ⦚
 * Unicode code point: U+299a (10650)
 * Description: vertical zigzag line
 */
static wchar_t* VERTICAL_ZIGZAG_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vzigzag";
static int* VERTICAL_ZIGZAG_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right angle variant with square html character entity reference model.
 *
 * Name: vangrt
 * Character: ⦜
 * Unicode code point: U+299c (10652)
 * Description: right angle variant with square
 */
static wchar_t* RIGHT_ANGLE_VARIANT_WITH_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vangrt";
static int* RIGHT_ANGLE_VARIANT_WITH_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured right angle with dot html character entity reference model.
 *
 * Name: angrtvbd
 * Character: ⦝
 * Unicode code point: U+299d (10653)
 * Description: measured right angle with dot
 */
static wchar_t* MEASURED_RIGHT_ANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrtvbd";
static int* MEASURED_RIGHT_ANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angle with underbar html character entity reference model.
 *
 * Name: ange
 * Character: ⦤
 * Unicode code point: U+29a4 (10660)
 * Description: angle with underbar
 */
static wchar_t* ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ange";
static int* ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed angle with underbar html character entity reference model.
 *
 * Name: range
 * Character: ⦥
 * Unicode code point: U+29a5 (10661)
 * Description: reversed angle with underbar
 */
static wchar_t* REVERSED_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"range";
static int* REVERSED_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oblique angle opening up html character entity reference model.
 *
 * Name: dwangle
 * Character: ⦦
 * Unicode code point: U+29a6 (10662)
 * Description: oblique angle opening up
 */
static wchar_t* OBLIQUE_ANGLE_OPENING_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dwangle";
static int* OBLIQUE_ANGLE_OPENING_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oblique angle opening down html character entity reference model.
 *
 * Name: uwangle
 * Character: ⦧
 * Unicode code point: U+29a7 (10663)
 * Description: oblique angle opening down
 */
static wchar_t* OBLIQUE_ANGLE_OPENING_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uwangle";
static int* OBLIQUE_ANGLE_OPENING_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing up and right html character entity reference model.
 *
 * Name: angmsdaa
 * Character: ⦨
 * Unicode code point: U+29a8 (10664)
 * Description: measured angle with open arm ending in arrow pointing up and right
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdaa";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing up and left html character entity reference model.
 *
 * Name: angmsdab
 * Character: ⦩
 * Unicode code point: U+29a9 (10665)
 * Description: measured angle with open arm ending in arrow pointing up and left
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdab";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing down and right html character entity reference model.
 *
 * Name: angmsdac
 * Character: ⦪
 * Unicode code point: U+29aa (10666)
 * Description: measured angle with open arm ending in arrow pointing down and right
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdac";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing down and left html character entity reference model.
 *
 * Name: angmsdad
 * Character: ⦫
 * Unicode code point: U+29ab (10667)
 * Description: measured angle with open arm ending in arrow pointing down and left
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdad";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing right and up html character entity reference model.
 *
 * Name: angmsdae
 * Character: ⦬
 * Unicode code point: U+29ac (10668)
 * Description: measured angle with open arm ending in arrow pointing right and up
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdae";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing left and up html character entity reference model.
 *
 * Name: angmsdaf
 * Character: ⦭
 * Unicode code point: U+29ad (10669)
 * Description: measured angle with open arm ending in arrow pointing left and up
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdaf";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing right and down html character entity reference model.
 *
 * Name: angmsdag
 * Character: ⦮
 * Unicode code point: U+29ae (10670)
 * Description: measured angle with open arm ending in arrow pointing right and down
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdag";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measured angle with open arm ending in arrow pointing left and down html character entity reference model.
 *
 * Name: angmsdah
 * Character: ⦯
 * Unicode code point: U+29af (10671)
 * Description: measured angle with open arm ending in arrow pointing left and down
 */
static wchar_t* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdah";
static int* MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed empty set html character entity reference model.
 *
 * Name: bemptyv
 * Character: ⦰
 * Unicode code point: U+29b0 (10672)
 * Description: reversed empty set
 */
static wchar_t* REVERSED_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bemptyv";
static int* REVERSED_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set with overbar html character entity reference model.
 *
 * Name: demptyv
 * Character: ⦱
 * Unicode code point: U+29b1 (10673)
 * Description: empty set with overbar
 */
static wchar_t* EMPTY_SET_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"demptyv";
static int* EMPTY_SET_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set with small circle above html character entity reference model.
 *
 * Name: cemptyv
 * Character: ⦲
 * Unicode code point: U+29b2 (10674)
 * Description: empty set with small circle above
 */
static wchar_t* EMPTY_SET_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cemptyv";
static int* EMPTY_SET_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set with right arrow above html character entity reference model.
 *
 * Name: raemptyv
 * Character: ⦳
 * Unicode code point: U+29b3 (10675)
 * Description: empty set with right arrow above
 */
static wchar_t* EMPTY_SET_WITH_RIGHT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"raemptyv";
static int* EMPTY_SET_WITH_RIGHT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty set with left arrow above html character entity reference model.
 *
 * Name: laemptyv
 * Character: ⦴
 * Unicode code point: U+29b4 (10676)
 * Description: empty set with left arrow above
 */
static wchar_t* EMPTY_SET_WITH_LEFT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"laemptyv";
static int* EMPTY_SET_WITH_LEFT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circle with horizontal bar html character entity reference model.
 *
 * Name: ohbar
 * Character: ⦵
 * Unicode code point: U+29b5 (10677)
 * Description: circle with horizontal bar
 */
static wchar_t* CIRCLE_WITH_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohbar";
static int* CIRCLE_WITH_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled vertical bar html character entity reference model.
 *
 * Name: omid
 * Character: ⦶
 * Unicode code point: U+29b6 (10678)
 * Description: circled vertical bar
 */
static wchar_t* CIRCLED_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omid";
static int* CIRCLED_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled parallel html character entity reference model.
 *
 * Name: opar
 * Character: ⦷
 * Unicode code point: U+29b7 (10679)
 * Description: circled parallel
 */
static wchar_t* CIRCLED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"opar";
static int* CIRCLED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled perpendicular html character entity reference model.
 *
 * Name: operp
 * Character: ⦹
 * Unicode code point: U+29b9 (10681)
 * Description: circled perpendicular
 */
static wchar_t* CIRCLED_PERPENDICULAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"operp";
static int* CIRCLED_PERPENDICULAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circle with superimposed x html character entity reference model.
 *
 * Name: olcross
 * Character: ⦻
 * Unicode code point: U+29bb (10683)
 * Description: circle with superimposed x
 */
static wchar_t* CIRCLE_WITH_SUPERIMPOSED_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olcross";
static int* CIRCLE_WITH_SUPERIMPOSED_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled anticlockwise-rotated division sign html character entity reference model.
 *
 * Name: odsold
 * Character: ⦼
 * Unicode code point: U+29bc (10684)
 * Description: circled anticlockwise-rotated division sign
 */
static wchar_t* CIRCLED_ANTICLOCKWISE_ROTATED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odsold";
static int* CIRCLED_ANTICLOCKWISE_ROTATED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled white bullet html character entity reference model.
 *
 * Name: olcir
 * Character: ⦾
 * Unicode code point: U+29be (10686)
 * Description: circled white bullet
 */
static wchar_t* CIRCLED_WHITE_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olcir";
static int* CIRCLED_WHITE_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled bullet html character entity reference model.
 *
 * Name: ofcir
 * Character: ⦿
 * Unicode code point: U+29bf (10687)
 * Description: circled bullet
 */
static wchar_t* CIRCLED_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ofcir";
static int* CIRCLED_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled less-than html character entity reference model.
 *
 * Name: olt
 * Character: ⧀
 * Unicode code point: U+29c0 (10688)
 * Description: circled less-than
 */
static wchar_t* CIRCLED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olt";
static int* CIRCLED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled greater-than html character entity reference model.
 *
 * Name: ogt
 * Character: ⧁
 * Unicode code point: U+29c1 (10689)
 * Description: circled greater-than
 */
static wchar_t* CIRCLED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogt";
static int* CIRCLED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circle with small circle to the right html character entity reference model.
 *
 * Name: cirscir
 * Character: ⧂
 * Unicode code point: U+29c2 (10690)
 * Description: circle with small circle to the right
 */
static wchar_t* CIRCLE_WITH_SMALL_CIRCLE_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirscir";
static int* CIRCLE_WITH_SMALL_CIRCLE_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circle with two horizontal strokes to the right html character entity reference model.
 *
 * Name: cirE
 * Character: ⧃
 * Unicode code point: U+29c3 (10691)
 * Description: circle with two horizontal strokes to the right
 */
static wchar_t* CIRCLE_WITH_TWO_HORIZONTAL_STROKES_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirE";
static int* CIRCLE_WITH_TWO_HORIZONTAL_STROKES_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared rising diagonal slash html character entity reference model.
 *
 * Name: solb
 * Character: ⧄
 * Unicode code point: U+29c4 (10692)
 * Description: squared rising diagonal slash
 */
static wchar_t* SQUARED_RISING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"solb";
static int* SQUARED_RISING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squared falling diagonal slash html character entity reference model.
 *
 * Name: bsolb
 * Character: ⧅
 * Unicode code point: U+29c5 (10693)
 * Description: squared falling diagonal slash
 */
static wchar_t* SQUARED_FALLING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsolb";
static int* SQUARED_FALLING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The two joined squares html character entity reference model.
 *
 * Name: boxbox
 * Character: ⧉
 * Unicode code point: U+29c9 (10697)
 * Description: two joined squares
 */
static wchar_t* TWO_JOINED_SQUARES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxbox";
static int* TWO_JOINED_SQUARES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangle with serifs at bottom html character entity reference model.
 *
 * Name: trisb
 * Character: ⧍
 * Unicode code point: U+29cd (10701)
 * Description: triangle with serifs at bottom
 */
static wchar_t* TRIANGLE_WITH_SERIFS_AT_BOTTOM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trisb";
static int* TRIANGLE_WITH_SERIFS_AT_BOTTOM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right triangle above left triangle html character entity reference model.
 *
 * Name: rtriltri
 * Character: ⧎
 * Unicode code point: U+29ce (10702)
 * Description: right triangle above left triangle
 */
static wchar_t* RIGHT_TRIANGLE_ABOVE_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtriltri";
static int* RIGHT_TRIANGLE_ABOVE_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left triangle beside vertical bar html character entity reference model.
 *
 * Name: LeftTriangleBar
 * Character: ⧏
 * Unicode code point: U+29cf (10703)
 * Description: left triangle beside vertical bar
 */
static wchar_t* LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangleBar";
static int* LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left triangle beside vertical bar with slash html character entity reference model.
 *
 * Name: NotLeftTriangleBar
 * Character: ⧏̸
 * Unicode code point: U+29cf;U+0338 (10703;824)
 * Description: left triangle beside vertical bar with slash
 */
static wchar_t* LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangleBar";
static int* LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical bar beside right triangle with slash html character entity reference model.
 *
 * Name: NotRightTriangleBar
 * Character: ⧐̸
 * Unicode code point: U+29d0;U+0338 (10704;824)
 * Description: vertical bar beside right triangle with slash
 */
static wchar_t* VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangleBar";
static int* VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical bar beside right triangle html character entity reference model.
 *
 * Name: RightTriangleBar
 * Character: ⧐
 * Unicode code point: U+29d0 (10704)
 * Description: vertical bar beside right triangle
 */
static wchar_t* VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangleBar";
static int* VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The incomplete infinity html character entity reference model.
 *
 * Name: iinfin
 * Character: ⧜
 * Unicode code point: U+29dc (10716)
 * Description: incomplete infinity
 */
static wchar_t* INCOMPLETE_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iinfin";
static int* INCOMPLETE_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tie over infinity html character entity reference model.
 *
 * Name: infintie
 * Character: ⧝
 * Unicode code point: U+29dd (10717)
 * Description: tie over infinity
 */
static wchar_t* TIE_OVER_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"infintie";
static int* TIE_OVER_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The infinity negated with vertical bar html character entity reference model.
 *
 * Name: nvinfin
 * Character: ⧞
 * Unicode code point: U+29de (10718)
 * Description: infinity negated with vertical bar
 */
static wchar_t* INFINITY_NEGATED_WITH_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvinfin";
static int* INFINITY_NEGATED_WITH_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign and slanted parallel html character entity reference model.
 *
 * Name: eparsl
 * Character: ⧣
 * Unicode code point: U+29e3 (10723)
 * Description: equals sign and slanted parallel
 */
static wchar_t* EQUALS_SIGN_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eparsl";
static int* EQUALS_SIGN_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign and slanted parallel with tilde above html character entity reference model.
 *
 * Name: smeparsl
 * Character: ⧤
 * Unicode code point: U+29e4 (10724)
 * Description: equals sign and slanted parallel with tilde above
 */
static wchar_t* EQUALS_SIGN_AND_SLANTED_PARALLEL_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smeparsl";
static int* EQUALS_SIGN_AND_SLANTED_PARALLEL_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identical to and slanted parallel html character entity reference model.
 *
 * Name: eqvparsl
 * Character: ⧥
 * Unicode code point: U+29e5 (10725)
 * Description: identical to and slanted parallel
 */
static wchar_t* IDENTICAL_TO_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqvparsl";
static int* IDENTICAL_TO_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The black lozenge html character entity reference model.
 *
 * Name: blacklozenge
 * Character: ⧫
 * Unicode code point: U+29eb (10731)
 * Description: black lozenge
 */
static wchar_t* BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacklozenge";
static int* BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rule-delayed html character entity reference model.
 *
 * Name: RuleDelayed
 * Character: ⧴
 * Unicode code point: U+29f4 (10740)
 * Description: rule-delayed
 */
static wchar_t* RULE_DELAYED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RuleDelayed";
static int* RULE_DELAYED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The solidus with overbar html character entity reference model.
 *
 * Name: dsol
 * Character: ⧶
 * Unicode code point: U+29f6 (10742)
 * Description: solidus with overbar
 */
static wchar_t* SOLIDUS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dsol";
static int* SOLIDUS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary circled dot operator html character entity reference model.
 *
 * Name: bigodot
 * Character: ⨀
 * Unicode code point: U+2a00 (10752)
 * Description: n-ary circled dot operator
 */
static wchar_t* N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigodot";
static int* N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary circled plus operator html character entity reference model.
 *
 * Name: bigoplus
 * Character: ⨁
 * Unicode code point: U+2a01 (10753)
 * Description: n-ary circled plus operator
 */
static wchar_t* N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigoplus";
static int* N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary circled times operator html character entity reference model.
 *
 * Name: bigotimes
 * Character: ⨂
 * Unicode code point: U+2a02 (10754)
 * Description: n-ary circled times operator
 */
static wchar_t* N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigotimes";
static int* N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary union operator with plus html character entity reference model.
 *
 * Name: biguplus
 * Character: ⨄
 * Unicode code point: U+2a04 (10756)
 * Description: n-ary union operator with plus
 */
static wchar_t* N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"biguplus";
static int* N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The n-ary square union operator html character entity reference model.
 *
 * Name: bigsqcup
 * Character: ⨆
 * Unicode code point: U+2a06 (10758)
 * Description: n-ary square union operator
 */
static wchar_t* N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigsqcup";
static int* N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quadruple integral operator html character entity reference model.
 *
 * Name: iiiint
 * Character: ⨌
 * Unicode code point: U+2a0c (10764)
 * Description: quadruple integral operator
 */
static wchar_t* QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiiint";
static int* QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The finite part integral html character entity reference model.
 *
 * Name: fpartint
 * Character: ⨍
 * Unicode code point: U+2a0d (10765)
 * Description: finite part integral
 */
static wchar_t* FINITE_PART_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fpartint";
static int* FINITE_PART_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circulation function html character entity reference model.
 *
 * Name: cirfnint
 * Character: ⨐
 * Unicode code point: U+2a10 (10768)
 * Description: circulation function
 */
static wchar_t* CIRCULATION_FUNCTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirfnint";
static int* CIRCULATION_FUNCTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The anticlockwise integration html character entity reference model.
 *
 * Name: awint
 * Character: ⨑
 * Unicode code point: U+2a11 (10769)
 * Description: anticlockwise integration
 */
static wchar_t* ANTICLOCKWISE_INTEGRATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"awint";
static int* ANTICLOCKWISE_INTEGRATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The line integration with rectangular path around pole html character entity reference model.
 *
 * Name: rppolint
 * Character: ⨒
 * Unicode code point: U+2a12 (10770)
 * Description: line integration with rectangular path around pole
 */
static wchar_t* LINE_INTEGRATION_WITH_RECTANGULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rppolint";
static int* LINE_INTEGRATION_WITH_RECTANGULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The line integration with semicircular path around pole html character entity reference model.
 *
 * Name: scpolint
 * Character: ⨓
 * Unicode code point: U+2a13 (10771)
 * Description: line integration with semicircular path around pole
 */
static wchar_t* LINE_INTEGRATION_WITH_SEMICIRCULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scpolint";
static int* LINE_INTEGRATION_WITH_SEMICIRCULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The line integration not including the pole html character entity reference model.
 *
 * Name: npolint
 * Character: ⨔
 * Unicode code point: U+2a14 (10772)
 * Description: line integration not including the pole
 */
static wchar_t* LINE_INTEGRATION_NOT_INCLUDING_THE_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npolint";
static int* LINE_INTEGRATION_NOT_INCLUDING_THE_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The integral around a point operator html character entity reference model.
 *
 * Name: pointint
 * Character: ⨕
 * Unicode code point: U+2a15 (10773)
 * Description: integral around a point operator
 */
static wchar_t* INTEGRAL_AROUND_A_POINT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pointint";
static int* INTEGRAL_AROUND_A_POINT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quaternion integral operator html character entity reference model.
 *
 * Name: quatint
 * Character: ⨖
 * Unicode code point: U+2a16 (10774)
 * Description: quaternion integral operator
 */
static wchar_t* QUATERNION_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quatint";
static int* QUATERNION_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The integral with leftwards arrow with hook html character entity reference model.
 *
 * Name: intlarhk
 * Character: ⨗
 * Unicode code point: U+2a17 (10775)
 * Description: integral with leftwards arrow with hook
 */
static wchar_t* INTEGRAL_WITH_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intlarhk";
static int* INTEGRAL_WITH_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with small circle above html character entity reference model.
 *
 * Name: pluscir
 * Character: ⨢
 * Unicode code point: U+2a22 (10786)
 * Description: plus sign with small circle above
 */
static wchar_t* PLUS_SIGN_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pluscir";
static int* PLUS_SIGN_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with circumflex accent above html character entity reference model.
 *
 * Name: plusacir
 * Character: ⨣
 * Unicode code point: U+2a23 (10787)
 * Description: plus sign with circumflex accent above
 */
static wchar_t* PLUS_SIGN_WITH_CIRCUMFLEX_ACCENT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusacir";
static int* PLUS_SIGN_WITH_CIRCUMFLEX_ACCENT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with tilde above html character entity reference model.
 *
 * Name: simplus
 * Character: ⨤
 * Unicode code point: U+2a24 (10788)
 * Description: plus sign with tilde above
 */
static wchar_t* PLUS_SIGN_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simplus";
static int* PLUS_SIGN_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with dot below html character entity reference model.
 *
 * Name: plusdu
 * Character: ⨥
 * Unicode code point: U+2a25 (10789)
 * Description: plus sign with dot below
 */
static wchar_t* PLUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusdu";
static int* PLUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with tilde below html character entity reference model.
 *
 * Name: plussim
 * Character: ⨦
 * Unicode code point: U+2a26 (10790)
 * Description: plus sign with tilde below
 */
static wchar_t* PLUS_SIGN_WITH_TILDE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plussim";
static int* PLUS_SIGN_WITH_TILDE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign with subscript two html character entity reference model.
 *
 * Name: plustwo
 * Character: ⨧
 * Unicode code point: U+2a27 (10791)
 * Description: plus sign with subscript two
 */
static wchar_t* PLUS_SIGN_WITH_SUBSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plustwo";
static int* PLUS_SIGN_WITH_SUBSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus sign with comma above html character entity reference model.
 *
 * Name: mcomma
 * Character: ⨩
 * Unicode code point: U+2a29 (10793)
 * Description: minus sign with comma above
 */
static wchar_t* MINUS_SIGN_WITH_COMMA_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mcomma";
static int* MINUS_SIGN_WITH_COMMA_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus sign with dot below html character entity reference model.
 *
 * Name: minusdu
 * Character: ⨪
 * Unicode code point: U+2a2a (10794)
 * Description: minus sign with dot below
 */
static wchar_t* MINUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minusdu";
static int* MINUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign in left half circle html character entity reference model.
 *
 * Name: loplus
 * Character: ⨭
 * Unicode code point: U+2a2d (10797)
 * Description: plus sign in left half circle
 */
static wchar_t* PLUS_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loplus";
static int* PLUS_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign in right half circle html character entity reference model.
 *
 * Name: roplus
 * Character: ⨮
 * Unicode code point: U+2a2e (10798)
 * Description: plus sign in right half circle
 */
static wchar_t* PLUS_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roplus";
static int* PLUS_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vector or cross product html character entity reference model.
 *
 * Name: Cross
 * Character: ⨯
 * Unicode code point: U+2a2f (10799)
 * Description: vector or cross product
 */
static wchar_t* VECTOR_OR_CROSS_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cross";
static int* VECTOR_OR_CROSS_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign with dot above html character entity reference model.
 *
 * Name: timesd
 * Character: ⨰
 * Unicode code point: U+2a30 (10800)
 * Description: multiplication sign with dot above
 */
static wchar_t* MULTIPLICATION_SIGN_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"timesd";
static int* MULTIPLICATION_SIGN_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign with underbar html character entity reference model.
 *
 * Name: timesbar
 * Character: ⨱
 * Unicode code point: U+2a31 (10801)
 * Description: multiplication sign with underbar
 */
static wchar_t* MULTIPLICATION_SIGN_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"timesbar";
static int* MULTIPLICATION_SIGN_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smash product html character entity reference model.
 *
 * Name: smashp
 * Character: ⨳
 * Unicode code point: U+2a33 (10803)
 * Description: smash product
 */
static wchar_t* SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smashp";
static int* SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign in left half circle html character entity reference model.
 *
 * Name: lotimes
 * Character: ⨴
 * Unicode code point: U+2a34 (10804)
 * Description: multiplication sign in left half circle
 */
static wchar_t* MULTIPLICATION_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lotimes";
static int* MULTIPLICATION_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign in right half circle html character entity reference model.
 *
 * Name: rotimes
 * Character: ⨵
 * Unicode code point: U+2a35 (10805)
 * Description: multiplication sign in right half circle
 */
static wchar_t* MULTIPLICATION_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rotimes";
static int* MULTIPLICATION_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled multiplication sign with circumflex accent html character entity reference model.
 *
 * Name: otimesas
 * Character: ⨶
 * Unicode code point: U+2a36 (10806)
 * Description: circled multiplication sign with circumflex accent
 */
static wchar_t* CIRCLED_MULTIPLICATION_SIGN_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otimesas";
static int* CIRCLED_MULTIPLICATION_SIGN_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign in double circle html character entity reference model.
 *
 * Name: Otimes
 * Character: ⨷
 * Unicode code point: U+2a37 (10807)
 * Description: multiplication sign in double circle
 */
static wchar_t* MULTIPLICATION_SIGN_IN_DOUBLE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Otimes";
static int* MULTIPLICATION_SIGN_IN_DOUBLE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circled division sign html character entity reference model.
 *
 * Name: odiv
 * Character: ⨸
 * Unicode code point: U+2a38 (10808)
 * Description: circled division sign
 */
static wchar_t* CIRCLED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odiv";
static int* CIRCLED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign in triangle html character entity reference model.
 *
 * Name: triplus
 * Character: ⨹
 * Unicode code point: U+2a39 (10809)
 * Description: plus sign in triangle
 */
static wchar_t* PLUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triplus";
static int* PLUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus sign in triangle html character entity reference model.
 *
 * Name: triminus
 * Character: ⨺
 * Unicode code point: U+2a3a (10810)
 * Description: minus sign in triangle
 */
static wchar_t* MINUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triminus";
static int* MINUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multiplication sign in triangle html character entity reference model.
 *
 * Name: tritime
 * Character: ⨻
 * Unicode code point: U+2a3b (10811)
 * Description: multiplication sign in triangle
 */
static wchar_t* MULTIPLICATION_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tritime";
static int* MULTIPLICATION_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The interior product html character entity reference model.
 *
 * Name: intprod
 * Character: ⨼
 * Unicode code point: U+2a3c (10812)
 * Description: interior product
 */
static wchar_t* INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intprod";
static int* INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The amalgamation or coproduct html character entity reference model.
 *
 * Name: amalg
 * Character: ⨿
 * Unicode code point: U+2a3f (10815)
 * Description: amalgamation or coproduct
 */
static wchar_t* AMALGAMATION_OR_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amalg";
static int* AMALGAMATION_OR_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection with dot html character entity reference model.
 *
 * Name: capdot
 * Character: ⩀
 * Unicode code point: U+2a40 (10816)
 * Description: intersection with dot
 */
static wchar_t* INTERSECTION_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capdot";
static int* INTERSECTION_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union with overbar html character entity reference model.
 *
 * Name: ncup
 * Character: ⩂
 * Unicode code point: U+2a42 (10818)
 * Description: union with overbar
 */
static wchar_t* UNION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncup";
static int* UNION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection with overbar html character entity reference model.
 *
 * Name: ncap
 * Character: ⩃
 * Unicode code point: U+2a43 (10819)
 * Description: intersection with overbar
 */
static wchar_t* INTERSECTION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncap";
static int* INTERSECTION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection with logical and html character entity reference model.
 *
 * Name: capand
 * Character: ⩄
 * Unicode code point: U+2a44 (10820)
 * Description: intersection with logical and
 */
static wchar_t* INTERSECTION_WITH_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capand";
static int* INTERSECTION_WITH_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union with logical or html character entity reference model.
 *
 * Name: cupor
 * Character: ⩅
 * Unicode code point: U+2a45 (10821)
 * Description: union with logical or
 */
static wchar_t* UNION_WITH_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupor";
static int* UNION_WITH_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union above intersection html character entity reference model.
 *
 * Name: cupcap
 * Character: ⩆
 * Unicode code point: U+2a46 (10822)
 * Description: union above intersection
 */
static wchar_t* UNION_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupcap";
static int* UNION_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection above union html character entity reference model.
 *
 * Name: capcup
 * Character: ⩇
 * Unicode code point: U+2a47 (10823)
 * Description: intersection above union
 */
static wchar_t* INTERSECTION_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capcup";
static int* INTERSECTION_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union above bar above intersection html character entity reference model.
 *
 * Name: cupbrcap
 * Character: ⩈
 * Unicode code point: U+2a48 (10824)
 * Description: union above bar above intersection
 */
static wchar_t* UNION_ABOVE_BAR_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupbrcap";
static int* UNION_ABOVE_BAR_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection above bar above union html character entity reference model.
 *
 * Name: capbrcup
 * Character: ⩉
 * Unicode code point: U+2a49 (10825)
 * Description: intersection above bar above union
 */
static wchar_t* INTERSECTION_ABOVE_BAR_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capbrcup";
static int* INTERSECTION_ABOVE_BAR_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The union beside and joined with union html character entity reference model.
 *
 * Name: cupcup
 * Character: ⩊
 * Unicode code point: U+2a4a (10826)
 * Description: union beside and joined with union
 */
static wchar_t* UNION_BESIDE_AND_JOINED_WITH_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupcup";
static int* UNION_BESIDE_AND_JOINED_WITH_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intersection beside and joined with intersection html character entity reference model.
 *
 * Name: capcap
 * Character: ⩋
 * Unicode code point: U+2a4b (10827)
 * Description: intersection beside and joined with intersection
 */
static wchar_t* INTERSECTION_BESIDE_AND_JOINED_WITH_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capcap";
static int* INTERSECTION_BESIDE_AND_JOINED_WITH_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed union with serifs html character entity reference model.
 *
 * Name: ccups
 * Character: ⩌
 * Unicode code point: U+2a4c (10828)
 * Description: closed union with serifs
 */
static wchar_t* CLOSED_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccups";
static int* CLOSED_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed intersection with serifs html character entity reference model.
 *
 * Name: ccaps
 * Character: ⩍
 * Unicode code point: U+2a4d (10829)
 * Description: closed intersection with serifs
 */
static wchar_t* CLOSED_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccaps";
static int* CLOSED_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed union with serifs and smash product html character entity reference model.
 *
 * Name: ccupssm
 * Character: ⩐
 * Unicode code point: U+2a50 (10832)
 * Description: closed union with serifs and smash product
 */
static wchar_t* CLOSED_UNION_WITH_SERIFS_AND_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccupssm";
static int* CLOSED_UNION_WITH_SERIFS_AND_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double logical and html character entity reference model.
 *
 * Name: And
 * Character: ⩓
 * Unicode code point: U+2a53 (10835)
 * Description: double logical and
 */
static wchar_t* DOUBLE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"And";
static int* DOUBLE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double logical or html character entity reference model.
 *
 * Name: Or
 * Character: ⩔
 * Unicode code point: U+2a54 (10836)
 * Description: double logical or
 */
static wchar_t* DOUBLE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Or";
static int* DOUBLE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The two intersecting logical and html character entity reference model.
 *
 * Name: andand
 * Character: ⩕
 * Unicode code point: U+2a55 (10837)
 * Description: two intersecting logical and
 */
static wchar_t* TWO_INTERSECTING_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andand";
static int* TWO_INTERSECTING_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The two intersecting logical or html character entity reference model.
 *
 * Name: oror
 * Character: ⩖
 * Unicode code point: U+2a56 (10838)
 * Description: two intersecting logical or
 */
static wchar_t* TWO_INTERSECTING_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oror";
static int* TWO_INTERSECTING_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sloping large or html character entity reference model.
 *
 * Name: orslope
 * Character: ⩗
 * Unicode code point: U+2a57 (10839)
 * Description: sloping large or
 */
static wchar_t* SLOPING_LARGE_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orslope";
static int* SLOPING_LARGE_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sloping large and html character entity reference model.
 *
 * Name: andslope
 * Character: ⩘
 * Unicode code point: U+2a58 (10840)
 * Description: sloping large and
 */
static wchar_t* SLOPING_LARGE_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andslope";
static int* SLOPING_LARGE_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical and with middle stem html character entity reference model.
 *
 * Name: andv
 * Character: ⩚
 * Unicode code point: U+2a5a (10842)
 * Description: logical and with middle stem
 */
static wchar_t* LOGICAL_AND_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andv";
static int* LOGICAL_AND_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical or with middle stem html character entity reference model.
 *
 * Name: orv
 * Character: ⩛
 * Unicode code point: U+2a5b (10843)
 * Description: logical or with middle stem
 */
static wchar_t* LOGICAL_OR_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orv";
static int* LOGICAL_OR_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical and with horizontal dash html character entity reference model.
 *
 * Name: andd
 * Character: ⩜
 * Unicode code point: U+2a5c (10844)
 * Description: logical and with horizontal dash
 */
static wchar_t* LOGICAL_AND_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andd";
static int* LOGICAL_AND_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical or with horizontal dash html character entity reference model.
 *
 * Name: ord
 * Character: ⩝
 * Unicode code point: U+2a5d (10845)
 * Description: logical or with horizontal dash
 */
static wchar_t* LOGICAL_OR_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ord";
static int* LOGICAL_OR_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logical and with underbar html character entity reference model.
 *
 * Name: wedbar
 * Character: ⩟
 * Unicode code point: U+2a5f (10847)
 * Description: logical and with underbar
 */
static wchar_t* LOGICAL_AND_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wedbar";
static int* LOGICAL_AND_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign with dot below html character entity reference model.
 *
 * Name: sdote
 * Character: ⩦
 * Unicode code point: U+2a66 (10854)
 * Description: equals sign with dot below
 */
static wchar_t* EQUALS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdote";
static int* EQUALS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde operator with dot above html character entity reference model.
 *
 * Name: simdot
 * Character: ⩪
 * Unicode code point: U+2a6a (10858)
 * Description: tilde operator with dot above
 */
static wchar_t* TILDE_OPERATOR_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simdot";
static int* TILDE_OPERATOR_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The congruent with dot above html character entity reference model.
 *
 * Name: congdot
 * Character: ⩭
 * Unicode code point: U+2a6d (10861)
 * Description: congruent with dot above
 */
static wchar_t* CONGRUENT_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"congdot";
static int* CONGRUENT_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The congruent with dot above with slash html character entity reference model.
 *
 * Name: ncongdot
 * Character: ⩭̸
 * Unicode code point: U+2a6d;U+0338 (10861;824)
 * Description: congruent with dot above with slash
 */
static wchar_t* CONGRUENT_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncongdot";
static int* CONGRUENT_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals with asterisk html character entity reference model.
 *
 * Name: easter
 * Character: ⩮
 * Unicode code point: U+2a6e (10862)
 * Description: equals with asterisk
 */
static wchar_t* EQUALS_WITH_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"easter";
static int* EQUALS_WITH_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The almost equal to with circumflex accent html character entity reference model.
 *
 * Name: apacir
 * Character: ⩯
 * Unicode code point: U+2a6f (10863)
 * Description: almost equal to with circumflex accent
 */
static wchar_t* ALMOST_EQUAL_TO_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apacir";
static int* ALMOST_EQUAL_TO_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approximately equal or equal to html character entity reference model.
 *
 * Name: apE
 * Character: ⩰
 * Unicode code point: U+2a70 (10864)
 * Description: approximately equal or equal to
 */
static wchar_t* APPROXIMATELY_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apE";
static int* APPROXIMATELY_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approximately equal or equal to with slash html character entity reference model.
 *
 * Name: napE
 * Character: ⩰̸
 * Unicode code point: U+2a70;U+0338 (10864;824)
 * Description: approximately equal or equal to with slash
 */
static wchar_t* APPROXIMATELY_EQUAL_OR_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napE";
static int* APPROXIMATELY_EQUAL_OR_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign above plus sign html character entity reference model.
 *
 * Name: eplus
 * Character: ⩱
 * Unicode code point: U+2a71 (10865)
 * Description: equals sign above plus sign
 */
static wchar_t* EQUALS_SIGN_ABOVE_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eplus";
static int* EQUALS_SIGN_ABOVE_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus sign above equals sign html character entity reference model.
 *
 * Name: pluse
 * Character: ⩲
 * Unicode code point: U+2a72 (10866)
 * Description: plus sign above equals sign
 */
static wchar_t* PLUS_SIGN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pluse";
static int* PLUS_SIGN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign above tilde operator html character entity reference model.
 *
 * Name: Esim
 * Character: ⩳
 * Unicode code point: U+2a73 (10867)
 * Description: equals sign above tilde operator
 */
static wchar_t* EQUALS_SIGN_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Esim";
static int* EQUALS_SIGN_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double colon equal html character entity reference model.
 *
 * Name: Colone
 * Character: ⩴
 * Unicode code point: U+2a74 (10868)
 * Description: double colon equal
 */
static wchar_t* DOUBLE_COLON_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Colone";
static int* DOUBLE_COLON_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The two consecutive equals signs html character entity reference model.
 *
 * Name: Equal
 * Character: ⩵
 * Unicode code point: U+2a75 (10869)
 * Description: two consecutive equals signs
 */
static wchar_t* TWO_CONSECUTIVE_EQUALS_SIGNS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Equal";
static int* TWO_CONSECUTIVE_EQUALS_SIGNS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign with two dots above and two dots below html character entity reference model.
 *
 * Name: ddotseq
 * Character: ⩷
 * Unicode code point: U+2a77 (10871)
 * Description: equals sign with two dots above and two dots below
 */
static wchar_t* EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ddotseq";
static int* EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equivalent with four dots above html character entity reference model.
 *
 * Name: equivDD
 * Character: ⩸
 * Unicode code point: U+2a78 (10872)
 * Description: equivalent with four dots above
 */
static wchar_t* EQUIVALENT_WITH_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equivDD";
static int* EQUIVALENT_WITH_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than with circle inside html character entity reference model.
 *
 * Name: ltcir
 * Character: ⩹
 * Unicode code point: U+2a79 (10873)
 * Description: less-than with circle inside
 */
static wchar_t* LESS_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltcir";
static int* LESS_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than with circle inside html character entity reference model.
 *
 * Name: gtcir
 * Character: ⩺
 * Unicode code point: U+2a7a (10874)
 * Description: greater-than with circle inside
 */
static wchar_t* GREATER_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtcir";
static int* GREATER_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than with question mark above html character entity reference model.
 *
 * Name: ltquest
 * Character: ⩻
 * Unicode code point: U+2a7b (10875)
 * Description: less-than with question mark above
 */
static wchar_t* LESS_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltquest";
static int* LESS_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than with question mark above html character entity reference model.
 *
 * Name: gtquest
 * Character: ⩼
 * Unicode code point: U+2a7c (10876)
 * Description: greater-than with question mark above
 */
static wchar_t* GREATER_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtquest";
static int* GREATER_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or slanted equal to html character entity reference model.
 *
 * Name: LessSlantEqual
 * Character: ⩽
 * Unicode code point: U+2a7d (10877)
 * Description: less-than or slanted equal to
 */
static wchar_t* LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessSlantEqual";
static int* LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or slanted equal to with slash html character entity reference model.
 *
 * Name: NotLessSlantEqual
 * Character: ⩽̸
 * Unicode code point: U+2a7d;U+0338 (10877;824)
 * Description: less-than or slanted equal to with slash
 */
static wchar_t* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessSlantEqual";
static int* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or slanted equal to html character entity reference model.
 *
 * Name: GreaterSlantEqual
 * Character: ⩾
 * Unicode code point: U+2a7e (10878)
 * Description: greater-than or slanted equal to
 */
static wchar_t* GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterSlantEqual";
static int* GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or slanted equal to with slash html character entity reference model.
 *
 * Name: NotGreaterSlantEqual
 * Character: ⩾̸
 * Unicode code point: U+2a7e;U+0338 (10878;824)
 * Description: greater-than or slanted equal to with slash
 */
static wchar_t* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterSlantEqual";
static int* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or slanted equal to with dot inside html character entity reference model.
 *
 * Name: lesdot
 * Character: ⩿
 * Unicode code point: U+2a7f (10879)
 * Description: less-than or slanted equal to with dot inside
 */
static wchar_t* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdot";
static int* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or slanted equal to with dot inside html character entity reference model.
 *
 * Name: gesdot
 * Character: ⪀
 * Unicode code point: U+2a80 (10880)
 * Description: greater-than or slanted equal to with dot inside
 */
static wchar_t* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdot";
static int* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or slanted equal to with dot above html character entity reference model.
 *
 * Name: lesdoto
 * Character: ⪁
 * Unicode code point: U+2a81 (10881)
 * Description: less-than or slanted equal to with dot above
 */
static wchar_t* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdoto";
static int* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or slanted equal to with dot above html character entity reference model.
 *
 * Name: gesdoto
 * Character: ⪂
 * Unicode code point: U+2a82 (10882)
 * Description: greater-than or slanted equal to with dot above
 */
static wchar_t* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdoto";
static int* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or slanted equal to with dot above right html character entity reference model.
 *
 * Name: lesdotor
 * Character: ⪃
 * Unicode code point: U+2a83 (10883)
 * Description: less-than or slanted equal to with dot above right
 */
static wchar_t* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdotor";
static int* LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or slanted equal to with dot above left html character entity reference model.
 *
 * Name: gesdotol
 * Character: ⪄
 * Unicode code point: U+2a84 (10884)
 * Description: greater-than or slanted equal to with dot above left
 */
static wchar_t* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdotol";
static int* GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than or approximate html character entity reference model.
 *
 * Name: lap
 * Character: ⪅
 * Unicode code point: U+2a85 (10885)
 * Description: less-than or approximate
 */
static wchar_t* LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lap";
static int* LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than or approximate html character entity reference model.
 *
 * Name: gap
 * Character: ⪆
 * Unicode code point: U+2a86 (10886)
 * Description: greater-than or approximate
 */
static wchar_t* GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gap";
static int* GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than and single-line not equal to html character entity reference model.
 *
 * Name: lne
 * Character: ⪇
 * Unicode code point: U+2a87 (10887)
 * Description: less-than and single-line not equal to
 */
static wchar_t* LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lne";
static int* LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than and single-line not equal to html character entity reference model.
 *
 * Name: gne
 * Character: ⪈
 * Unicode code point: U+2a88 (10888)
 * Description: greater-than and single-line not equal to
 */
static wchar_t* GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gne";
static int* GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than and not approximate html character entity reference model.
 *
 * Name: lnap
 * Character: ⪉
 * Unicode code point: U+2a89 (10889)
 * Description: less-than and not approximate
 */
static wchar_t* LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnap";
static int* LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than and not approximate html character entity reference model.
 *
 * Name: gnap
 * Character: ⪊
 * Unicode code point: U+2a8a (10890)
 * Description: greater-than and not approximate
 */
static wchar_t* GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnap";
static int* GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above double-line equal above greater-than html character entity reference model.
 *
 * Name: lEg
 * Character: ⪋
 * Unicode code point: U+2a8b (10891)
 * Description: less-than above double-line equal above greater-than
 */
static wchar_t* LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lEg";
static int* LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above double-line equal above less-than html character entity reference model.
 *
 * Name: gEl
 * Character: ⪌
 * Unicode code point: U+2a8c (10892)
 * Description: greater-than above double-line equal above less-than
 */
static wchar_t* GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gEl";
static int* GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above similar or equal html character entity reference model.
 *
 * Name: lsime
 * Character: ⪍
 * Unicode code point: U+2a8d (10893)
 * Description: less-than above similar or equal
 */
static wchar_t* LESS_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsime";
static int* LESS_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above similar or equal html character entity reference model.
 *
 * Name: gsime
 * Character: ⪎
 * Unicode code point: U+2a8e (10894)
 * Description: greater-than above similar or equal
 */
static wchar_t* GREATER_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gsime";
static int* GREATER_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above similar above greater-than html character entity reference model.
 *
 * Name: lsimg
 * Character: ⪏
 * Unicode code point: U+2a8f (10895)
 * Description: less-than above similar above greater-than
 */
static wchar_t* LESS_THAN_ABOVE_SIMILAR_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsimg";
static int* LESS_THAN_ABOVE_SIMILAR_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above similar above less-than html character entity reference model.
 *
 * Name: gsiml
 * Character: ⪐
 * Unicode code point: U+2a90 (10896)
 * Description: greater-than above similar above less-than
 */
static wchar_t* GREATER_THAN_ABOVE_SIMILAR_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gsiml";
static int* GREATER_THAN_ABOVE_SIMILAR_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above greater-than above double-line equal html character entity reference model.
 *
 * Name: lgE
 * Character: ⪑
 * Unicode code point: U+2a91 (10897)
 * Description: less-than above greater-than above double-line equal
 */
static wchar_t* LESS_THAN_ABOVE_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lgE";
static int* LESS_THAN_ABOVE_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above less-than above double-line equal html character entity reference model.
 *
 * Name: glE
 * Character: ⪒
 * Unicode code point: U+2a92 (10898)
 * Description: greater-than above less-than above double-line equal
 */
static wchar_t* GREATER_THAN_ABOVE_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"glE";
static int* GREATER_THAN_ABOVE_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than above slanted equal above greater-than above slanted equal html character entity reference model.
 *
 * Name: lesges
 * Character: ⪓
 * Unicode code point: U+2a93 (10899)
 * Description: less-than above slanted equal above greater-than above slanted equal
 */
static wchar_t* LESS_THAN_ABOVE_SLANTED_EQUAL_ABOVE_GREATER_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesges";
static int* LESS_THAN_ABOVE_SLANTED_EQUAL_ABOVE_GREATER_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than above slanted equal above less-than above slanted equal html character entity reference model.
 *
 * Name: gesles
 * Character: ⪔
 * Unicode code point: U+2a94 (10900)
 * Description: greater-than above slanted equal above less-than above slanted equal
 */
static wchar_t* GREATER_THAN_ABOVE_SLANTED_EQUAL_ABOVE_LESS_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesles";
static int* GREATER_THAN_ABOVE_SLANTED_EQUAL_ABOVE_LESS_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The slanted equal to or less-than html character entity reference model.
 *
 * Name: els
 * Character: ⪕
 * Unicode code point: U+2a95 (10901)
 * Description: slanted equal to or less-than
 */
static wchar_t* SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"els";
static int* SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The slanted equal to or greater-than html character entity reference model.
 *
 * Name: egs
 * Character: ⪖
 * Unicode code point: U+2a96 (10902)
 * Description: slanted equal to or greater-than
 */
static wchar_t* SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egs";
static int* SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The slanted equal to or less-than with dot inside html character entity reference model.
 *
 * Name: elsdot
 * Character: ⪗
 * Unicode code point: U+2a97 (10903)
 * Description: slanted equal to or less-than with dot inside
 */
static wchar_t* SLANTED_EQUAL_TO_OR_LESS_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"elsdot";
static int* SLANTED_EQUAL_TO_OR_LESS_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The slanted equal to or greater-than with dot inside html character entity reference model.
 *
 * Name: egsdot
 * Character: ⪘
 * Unicode code point: U+2a98 (10904)
 * Description: slanted equal to or greater-than with dot inside
 */
static wchar_t* SLANTED_EQUAL_TO_OR_GREATER_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egsdot";
static int* SLANTED_EQUAL_TO_OR_GREATER_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-line equal to or less-than html character entity reference model.
 *
 * Name: el
 * Character: ⪙
 * Unicode code point: U+2a99 (10905)
 * Description: double-line equal to or less-than
 */
static wchar_t* DOUBLE_LINE_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"el";
static int* DOUBLE_LINE_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double-line equal to or greater-than html character entity reference model.
 *
 * Name: eg
 * Character: ⪚
 * Unicode code point: U+2a9a (10906)
 * Description: double-line equal to or greater-than
 */
static wchar_t* DOUBLE_LINE_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eg";
static int* DOUBLE_LINE_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The similar or less-than html character entity reference model.
 *
 * Name: siml
 * Character: ⪝
 * Unicode code point: U+2a9d (10909)
 * Description: similar or less-than
 */
static wchar_t* SIMILAR_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"siml";
static int* SIMILAR_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The similar or greater-than html character entity reference model.
 *
 * Name: simg
 * Character: ⪞
 * Unicode code point: U+2a9e (10910)
 * Description: similar or greater-than
 */
static wchar_t* SIMILAR_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simg";
static int* SIMILAR_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The similar above less-than above equals sign html character entity reference model.
 *
 * Name: simlE
 * Character: ⪟
 * Unicode code point: U+2a9f (10911)
 * Description: similar above less-than above equals sign
 */
static wchar_t* SIMILAR_ABOVE_LESS_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simlE";
static int* SIMILAR_ABOVE_LESS_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The similar above greater-than above equals sign html character entity reference model.
 *
 * Name: simgE
 * Character: ⪠
 * Unicode code point: U+2aa0 (10912)
 * Description: similar above greater-than above equals sign
 */
static wchar_t* SIMILAR_ABOVE_GREATER_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simgE";
static int* SIMILAR_ABOVE_GREATER_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double nested less-than html character entity reference model.
 *
 * Name: LessLess
 * Character: ⪡
 * Unicode code point: U+2aa1 (10913)
 * Description: double nested less-than
 */
static wchar_t* DOUBLE_NESTED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessLess";
static int* DOUBLE_NESTED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double nested less-than with slash html character entity reference model.
 *
 * Name: NotNestedLessLess
 * Character: ⪡̸
 * Unicode code point: U+2aa1;U+0338 (10913;824)
 * Description: double nested less-than with slash
 */
static wchar_t* DOUBLE_NESTED_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotNestedLessLess";
static int* DOUBLE_NESTED_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double nested greater-than html character entity reference model.
 *
 * Name: GreaterGreater
 * Character: ⪢
 * Unicode code point: U+2aa2 (10914)
 * Description: double nested greater-than
 */
static wchar_t* DOUBLE_NESTED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterGreater";
static int* DOUBLE_NESTED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double nested greater-than with slash html character entity reference model.
 *
 * Name: NotNestedGreaterGreater
 * Character: ⪢̸
 * Unicode code point: U+2aa2;U+0338 (10914;824)
 * Description: double nested greater-than with slash
 */
static wchar_t* DOUBLE_NESTED_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotNestedGreaterGreater";
static int* DOUBLE_NESTED_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than overlapping less-than html character entity reference model.
 *
 * Name: glj
 * Character: ⪤
 * Unicode code point: U+2aa4 (10916)
 * Description: greater-than overlapping less-than
 */
static wchar_t* GREATER_THAN_OVERLAPPING_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"glj";
static int* GREATER_THAN_OVERLAPPING_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than beside less-than html character entity reference model.
 *
 * Name: gla
 * Character: ⪥
 * Unicode code point: U+2aa5 (10917)
 * Description: greater-than beside less-than
 */
static wchar_t* GREATER_THAN_BESIDE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gla";
static int* GREATER_THAN_BESIDE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than closed by curve html character entity reference model.
 *
 * Name: ltcc
 * Character: ⪦
 * Unicode code point: U+2aa6 (10918)
 * Description: less-than closed by curve
 */
static wchar_t* LESS_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltcc";
static int* LESS_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than closed by curve html character entity reference model.
 *
 * Name: gtcc
 * Character: ⪧
 * Unicode code point: U+2aa7 (10919)
 * Description: greater-than closed by curve
 */
static wchar_t* GREATER_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtcc";
static int* GREATER_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The less-than closed by curve above slanted equal html character entity reference model.
 *
 * Name: lescc
 * Character: ⪨
 * Unicode code point: U+2aa8 (10920)
 * Description: less-than closed by curve above slanted equal
 */
static wchar_t* LESS_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lescc";
static int* LESS_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The greater-than closed by curve above slanted equal html character entity reference model.
 *
 * Name: gescc
 * Character: ⪩
 * Unicode code point: U+2aa9 (10921)
 * Description: greater-than closed by curve above slanted equal
 */
static wchar_t* GREATER_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gescc";
static int* GREATER_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smaller than html character entity reference model.
 *
 * Name: smt
 * Character: ⪪
 * Unicode code point: U+2aaa (10922)
 * Description: smaller than
 */
static wchar_t* SMALLER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smt";
static int* SMALLER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larger than html character entity reference model.
 *
 * Name: lat
 * Character: ⪫
 * Unicode code point: U+2aab (10923)
 * Description: larger than
 */
static wchar_t* LARGER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lat";
static int* LARGER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smaller than or equal to html character entity reference model.
 *
 * Name: smte
 * Character: ⪬
 * Unicode code point: U+2aac (10924)
 * Description: smaller than or equal to
 */
static wchar_t* SMALLER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smte";
static int* SMALLER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smaller than or slanted equal html character entity reference model.
 *
 * Name: smtes
 * Character: ⪬︀
 * Unicode code point: U+2aac;U+fe00 (10924;65024)
 * Description: smaller than or slanted equal
 */
static wchar_t* SMALLER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smtes";
static int* SMALLER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larger than or equal to html character entity reference model.
 *
 * Name: late
 * Character: ⪭
 * Unicode code point: U+2aad (10925)
 * Description: larger than or equal to
 */
static wchar_t* LARGER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"late";
static int* LARGER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larger than or slanted equal html character entity reference model.
 *
 * Name: lates
 * Character: ⪭︀
 * Unicode code point: U+2aad;U+fe00 (10925;65024)
 * Description: larger than or slanted equal
 */
static wchar_t* LARGER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lates";
static int* LARGER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals sign with bumpy above html character entity reference model.
 *
 * Name: bumpE
 * Character: ⪮
 * Unicode code point: U+2aae (10926)
 * Description: equals sign with bumpy above
 */
static wchar_t* EQUALS_SIGN_WITH_BUMPY_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bumpE";
static int* EQUALS_SIGN_WITH_BUMPY_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above single-line equals sign with slash html character entity reference model.
 *
 * Name: NotPrecedesEqual
 * Character: ⪯̸
 * Unicode code point: U+2aaf;U+0338 (10927;824)
 * Description: precedes above single-line equals sign with slash
 */
static wchar_t* PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedesEqual";
static int* PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above single-line equals sign html character entity reference model.
 *
 * Name: PrecedesEqual
 * Character: ⪯
 * Unicode code point: U+2aaf (10927)
 * Description: precedes above single-line equals sign
 */
static wchar_t* PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesEqual";
static int* PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above single-line equals sign with slash html character entity reference model.
 *
 * Name: NotSucceedsEqual
 * Character: ⪰̸
 * Unicode code point: U+2ab0;U+0338 (10928;824)
 * Description: succeeds above single-line equals sign with slash
 */
static wchar_t* SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsEqual";
static int* SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above single-line equals sign html character entity reference model.
 *
 * Name: SucceedsEqual
 * Character: ⪰
 * Unicode code point: U+2ab0 (10928)
 * Description: succeeds above single-line equals sign
 */
static wchar_t* SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsEqual";
static int* SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above equals sign html character entity reference model.
 *
 * Name: prE
 * Character: ⪳
 * Unicode code point: U+2ab3 (10931)
 * Description: precedes above equals sign
 */
static wchar_t* PRECEDES_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prE";
static int* PRECEDES_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above equals sign html character entity reference model.
 *
 * Name: scE
 * Character: ⪴
 * Unicode code point: U+2ab4 (10932)
 * Description: succeeds above equals sign
 */
static wchar_t* SUCCEEDS_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scE";
static int* SUCCEEDS_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above not equal to html character entity reference model.
 *
 * Name: precneqq
 * Character: ⪵
 * Unicode code point: U+2ab5 (10933)
 * Description: precedes above not equal to
 */
static wchar_t* PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precneqq";
static int* PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above not equal to html character entity reference model.
 *
 * Name: scnE
 * Character: ⪶
 * Unicode code point: U+2ab6 (10934)
 * Description: succeeds above not equal to
 */
static wchar_t* SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnE";
static int* SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above almost equal to html character entity reference model.
 *
 * Name: prap
 * Character: ⪷
 * Unicode code point: U+2ab7 (10935)
 * Description: precedes above almost equal to
 */
static wchar_t* PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prap";
static int* PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above almost equal to html character entity reference model.
 *
 * Name: scap
 * Character: ⪸
 * Unicode code point: U+2ab8 (10936)
 * Description: succeeds above almost equal to
 */
static wchar_t* SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scap";
static int* SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precedes above not almost equal to html character entity reference model.
 *
 * Name: precnapprox
 * Character: ⪹
 * Unicode code point: U+2ab9 (10937)
 * Description: precedes above not almost equal to
 */
static wchar_t* PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precnapprox";
static int* PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeeds above not almost equal to html character entity reference model.
 *
 * Name: scnap
 * Character: ⪺
 * Unicode code point: U+2aba (10938)
 * Description: succeeds above not almost equal to
 */
static wchar_t* SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnap";
static int* SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double precedes html character entity reference model.
 *
 * Name: Pr
 * Character: ⪻
 * Unicode code point: U+2abb (10939)
 * Description: double precedes
 */
static wchar_t* DOUBLE_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pr";
static int* DOUBLE_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double succeeds html character entity reference model.
 *
 * Name: Sc
 * Character: ⪼
 * Unicode code point: U+2abc (10940)
 * Description: double succeeds
 */
static wchar_t* DOUBLE_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sc";
static int* DOUBLE_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset with dot html character entity reference model.
 *
 * Name: subdot
 * Character: ⪽
 * Unicode code point: U+2abd (10941)
 * Description: subset with dot
 */
static wchar_t* SUBSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subdot";
static int* SUBSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset with dot html character entity reference model.
 *
 * Name: supdot
 * Character: ⪾
 * Unicode code point: U+2abe (10942)
 * Description: superset with dot
 */
static wchar_t* SUPERSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supdot";
static int* SUPERSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset with plus sign below html character entity reference model.
 *
 * Name: subplus
 * Character: ⪿
 * Unicode code point: U+2abf (10943)
 * Description: subset with plus sign below
 */
static wchar_t* SUBSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subplus";
static int* SUBSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset with plus sign below html character entity reference model.
 *
 * Name: supplus
 * Character: ⫀
 * Unicode code point: U+2ac0 (10944)
 * Description: superset with plus sign below
 */
static wchar_t* SUPERSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supplus";
static int* SUPERSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset with multiplication sign below html character entity reference model.
 *
 * Name: submult
 * Character: ⫁
 * Unicode code point: U+2ac1 (10945)
 * Description: subset with multiplication sign below
 */
static wchar_t* SUBSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"submult";
static int* SUBSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset with multiplication sign below html character entity reference model.
 *
 * Name: supmult
 * Character: ⫂
 * Unicode code point: U+2ac2 (10946)
 * Description: superset with multiplication sign below
 */
static wchar_t* SUPERSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supmult";
static int* SUPERSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of or equal to with dot above html character entity reference model.
 *
 * Name: subedot
 * Character: ⫃
 * Unicode code point: U+2ac3 (10947)
 * Description: subset of or equal to with dot above
 */
static wchar_t* SUBSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subedot";
static int* SUBSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of or equal to with dot above html character entity reference model.
 *
 * Name: supedot
 * Character: ⫄
 * Unicode code point: U+2ac4 (10948)
 * Description: superset of or equal to with dot above
 */
static wchar_t* SUPERSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supedot";
static int* SUPERSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of above equals sign with slash html character entity reference model.
 *
 * Name: nsubE
 * Character: ⫅̸
 * Unicode code point: U+2ac5;U+0338 (10949;824)
 * Description: subset of above equals sign with slash
 */
static wchar_t* SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsubE";
static int* SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of above equals sign html character entity reference model.
 *
 * Name: subE
 * Character: ⫅
 * Unicode code point: U+2ac5 (10949)
 * Description: subset of above equals sign
 */
static wchar_t* SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subE";
static int* SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of above equals sign with slash html character entity reference model.
 *
 * Name: nsupE
 * Character: ⫆̸
 * Unicode code point: U+2ac6;U+0338 (10950;824)
 * Description: superset of above equals sign with slash
 */
static wchar_t* SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupE";
static int* SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of above equals sign html character entity reference model.
 *
 * Name: supE
 * Character: ⫆
 * Unicode code point: U+2ac6 (10950)
 * Description: superset of above equals sign
 */
static wchar_t* SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supE";
static int* SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of above tilde operator html character entity reference model.
 *
 * Name: subsim
 * Character: ⫇
 * Unicode code point: U+2ac7 (10951)
 * Description: subset of above tilde operator
 */
static wchar_t* SUBSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsim";
static int* SUBSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of above tilde operator html character entity reference model.
 *
 * Name: supsim
 * Character: ⫈
 * Unicode code point: U+2ac8 (10952)
 * Description: superset of above tilde operator
 */
static wchar_t* SUPERSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsim";
static int* SUPERSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of above not equal to html character entity reference model.
 *
 * Name: subnE
 * Character: ⫋
 * Unicode code point: U+2acb (10955)
 * Description: subset of above not equal to
 */
static wchar_t* SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subnE";
static int* SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset of above not equal to - variant with stroke through bottom members html character entity reference model.
 *
 * Name: varsubsetneqq
 * Character: ⫋︀
 * Unicode code point: U+2acb;U+fe00 (10955;65024)
 * Description: subset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsubsetneqq";
static int* SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of above not equal to html character entity reference model.
 *
 * Name: supnE
 * Character: ⫌
 * Unicode code point: U+2acc (10956)
 * Description: superset of above not equal to
 */
static wchar_t* SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supnE";
static int* SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset of above not equal to - variant with stroke through bottom members html character entity reference model.
 *
 * Name: varsupsetneqq
 * Character: ⫌︀
 * Unicode code point: U+2acc;U+fe00 (10956;65024)
 * Description: superset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsupsetneqq";
static int* SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed subset html character entity reference model.
 *
 * Name: csub
 * Character: ⫏
 * Unicode code point: U+2acf (10959)
 * Description: closed subset
 */
static wchar_t* CLOSED_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csub";
static int* CLOSED_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed superset html character entity reference model.
 *
 * Name: csup
 * Character: ⫐
 * Unicode code point: U+2ad0 (10960)
 * Description: closed superset
 */
static wchar_t* CLOSED_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csup";
static int* CLOSED_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed subset or equal to html character entity reference model.
 *
 * Name: csube
 * Character: ⫑
 * Unicode code point: U+2ad1 (10961)
 * Description: closed subset or equal to
 */
static wchar_t* CLOSED_SUBSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csube";
static int* CLOSED_SUBSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The closed superset or equal to html character entity reference model.
 *
 * Name: csupe
 * Character: ⫒
 * Unicode code point: U+2ad2 (10962)
 * Description: closed superset or equal to
 */
static wchar_t* CLOSED_SUPERSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csupe";
static int* CLOSED_SUPERSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset above superset html character entity reference model.
 *
 * Name: subsup
 * Character: ⫓
 * Unicode code point: U+2ad3 (10963)
 * Description: subset above superset
 */
static wchar_t* SUBSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsup";
static int* SUBSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset above subset html character entity reference model.
 *
 * Name: supsub
 * Character: ⫔
 * Unicode code point: U+2ad4 (10964)
 * Description: superset above subset
 */
static wchar_t* SUPERSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsub";
static int* SUPERSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset above subset html character entity reference model.
 *
 * Name: subsub
 * Character: ⫕
 * Unicode code point: U+2ad5 (10965)
 * Description: subset above subset
 */
static wchar_t* SUBSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsub";
static int* SUBSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset above superset html character entity reference model.
 *
 * Name: supsup
 * Character: ⫖
 * Unicode code point: U+2ad6 (10966)
 * Description: superset above superset
 */
static wchar_t* SUPERSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsup";
static int* SUPERSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset beside subset html character entity reference model.
 *
 * Name: suphsub
 * Character: ⫗
 * Unicode code point: U+2ad7 (10967)
 * Description: superset beside subset
 */
static wchar_t* SUPERSET_BESIDE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suphsub";
static int* SUPERSET_BESIDE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The superset beside and joined by dash with subset html character entity reference model.
 *
 * Name: supdsub
 * Character: ⫘
 * Unicode code point: U+2ad8 (10968)
 * Description: superset beside and joined by dash with subset
 */
static wchar_t* SUPERSET_BESIDE_AND_JOINED_BY_DASH_WITH_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supdsub";
static int* SUPERSET_BESIDE_AND_JOINED_BY_DASH_WITH_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element of opening downwards html character entity reference model.
 *
 * Name: forkv
 * Character: ⫙
 * Unicode code point: U+2ad9 (10969)
 * Description: element of opening downwards
 */
static wchar_t* ELEMENT_OF_OPENING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"forkv";
static int* ELEMENT_OF_OPENING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pitchfork with tee top html character entity reference model.
 *
 * Name: topfork
 * Character: ⫚
 * Unicode code point: U+2ada (10970)
 * Description: pitchfork with tee top
 */
static wchar_t* PITCHFORK_WITH_TEE_TOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topfork";
static int* PITCHFORK_WITH_TEE_TOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The transversal intersection html character entity reference model.
 *
 * Name: mlcp
 * Character: ⫛
 * Unicode code point: U+2adb (10971)
 * Description: transversal intersection
 */
static wchar_t* TRANSVERSAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mlcp";
static int* TRANSVERSAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical bar double left turnstile html character entity reference model.
 *
 * Name: Dashv
 * Character: ⫤
 * Unicode code point: U+2ae4 (10980)
 * Description: vertical bar double left turnstile
 */
static wchar_t* VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dashv";
static int* VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long dash from left member of double vertical html character entity reference model.
 *
 * Name: Vdashl
 * Character: ⫦
 * Unicode code point: U+2ae6 (10982)
 * Description: long dash from left member of double vertical
 */
static wchar_t* LONG_DASH_FROM_LEFT_MEMBER_OF_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vdashl";
static int* LONG_DASH_FROM_LEFT_MEMBER_OF_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The short down tack with overbar html character entity reference model.
 *
 * Name: Barv
 * Character: ⫧
 * Unicode code point: U+2ae7 (10983)
 * Description: short down tack with overbar
 */
static wchar_t* SHORT_DOWN_TACK_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Barv";
static int* SHORT_DOWN_TACK_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The short up tack with underbar html character entity reference model.
 *
 * Name: vBar
 * Character: ⫨
 * Unicode code point: U+2ae8 (10984)
 * Description: short up tack with underbar
 */
static wchar_t* SHORT_UP_TACK_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vBar";
static int* SHORT_UP_TACK_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The short up tack above short down tack html character entity reference model.
 *
 * Name: vBarv
 * Character: ⫩
 * Unicode code point: U+2ae9 (10985)
 * Description: short up tack above short down tack
 */
static wchar_t* SHORT_UP_TACK_ABOVE_SHORT_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vBarv";
static int* SHORT_UP_TACK_ABOVE_SHORT_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double up tack html character entity reference model.
 *
 * Name: Vbar
 * Character: ⫫
 * Unicode code point: U+2aeb (10987)
 * Description: double up tack
 */
static wchar_t* DOUBLE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vbar";
static int* DOUBLE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double stroke not sign html character entity reference model.
 *
 * Name: Not
 * Character: ⫬
 * Unicode code point: U+2aec (10988)
 * Description: double stroke not sign
 */
static wchar_t* DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Not";
static int* DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reversed double stroke not sign html character entity reference model.
 *
 * Name: bNot
 * Character: ⫭
 * Unicode code point: U+2aed (10989)
 * Description: reversed double stroke not sign
 */
static wchar_t* REVERSED_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bNot";
static int* REVERSED_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The does not divide with reversed negation slash html character entity reference model.
 *
 * Name: rnmid
 * Character: ⫮
 * Unicode code point: U+2aee (10990)
 * Description: does not divide with reversed negation slash
 */
static wchar_t* DOES_NOT_DIVIDE_WITH_REVERSED_NEGATION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rnmid";
static int* DOES_NOT_DIVIDE_WITH_REVERSED_NEGATION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical line with circle above html character entity reference model.
 *
 * Name: cirmid
 * Character: ⫯
 * Unicode code point: U+2aef (10991)
 * Description: vertical line with circle above
 */
static wchar_t* VERTICAL_LINE_WITH_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirmid";
static int* VERTICAL_LINE_WITH_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vertical line with circle below html character entity reference model.
 *
 * Name: midcir
 * Character: ⫰
 * Unicode code point: U+2af0 (10992)
 * Description: vertical line with circle below
 */
static wchar_t* VERTICAL_LINE_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"midcir";
static int* VERTICAL_LINE_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The down tack with circle below html character entity reference model.
 *
 * Name: topcir
 * Character: ⫱
 * Unicode code point: U+2af1 (10993)
 * Description: down tack with circle below
 */
static wchar_t* DOWN_TACK_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topcir";
static int* DOWN_TACK_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parallel with horizontal stroke html character entity reference model.
 *
 * Name: nhpar
 * Character: ⫲
 * Unicode code point: U+2af2 (10994)
 * Description: parallel with horizontal stroke
 */
static wchar_t* PARALLEL_WITH_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nhpar";
static int* PARALLEL_WITH_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parallel with tilde operator html character entity reference model.
 *
 * Name: parsim
 * Character: ⫳
 * Unicode code point: U+2af3 (10995)
 * Description: parallel with tilde operator
 */
static wchar_t* PARALLEL_WITH_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"parsim";
static int* PARALLEL_WITH_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double solidus operator with reverse slash html character entity reference model.
 *
 * Name: nparsl
 * Character: ⫽⃥
 * Unicode code point: U+2afd;U+20e5 (11005;8421)
 * Description: double solidus operator with reverse slash
 */
static wchar_t* DOUBLE_SOLIDUS_OPERATOR_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nparsl";
static int* DOUBLE_SOLIDUS_OPERATOR_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The double solidus operator html character entity reference model.
 *
 * Name: parsl
 * Character: ⫽
 * Unicode code point: U+2afd (11005)
 * Description: double solidus operator
 */
static wchar_t* DOUBLE_SOLIDUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"parsl";
static int* DOUBLE_SOLIDUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital a html character entity reference model.
 *
 * Name: Ascr
 * Character: 𝒜
 * Unicode code point: U+d49c (54428)
 * Description: mathematical script capital a
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ascr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital c html character entity reference model.
 *
 * Name: Cscr
 * Character: 𝒞
 * Unicode code point: U+d49e (54430)
 * Description: mathematical script capital c
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital d html character entity reference model.
 *
 * Name: Dscr
 * Character: 𝒟
 * Unicode code point: U+d49f (54431)
 * Description: mathematical script capital d
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital g html character entity reference model.
 *
 * Name: Gscr
 * Character: 𝒢
 * Unicode code point: U+d4a2 (54434)
 * Description: mathematical script capital g
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital j html character entity reference model.
 *
 * Name: Jscr
 * Character: 𝒥
 * Unicode code point: U+d4a5 (54437)
 * Description: mathematical script capital j
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital k html character entity reference model.
 *
 * Name: Kscr
 * Character: 𝒦
 * Unicode code point: U+d4a6 (54438)
 * Description: mathematical script capital k
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital n html character entity reference model.
 *
 * Name: Nscr
 * Character: 𝒩
 * Unicode code point: U+d4a9 (54441)
 * Description: mathematical script capital n
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital o html character entity reference model.
 *
 * Name: Oscr
 * Character: 𝒪
 * Unicode code point: U+d4aa (54442)
 * Description: mathematical script capital o
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital p html character entity reference model.
 *
 * Name: Pscr
 * Character: 𝒫
 * Unicode code point: U+d4ab (54443)
 * Description: mathematical script capital p
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital q html character entity reference model.
 *
 * Name: Qscr
 * Character: 𝒬
 * Unicode code point: U+d4ac (54444)
 * Description: mathematical script capital q
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital s html character entity reference model.
 *
 * Name: Sscr
 * Character: 𝒮
 * Unicode code point: U+d4ae (54446)
 * Description: mathematical script capital s
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital t html character entity reference model.
 *
 * Name: Tscr
 * Character: 𝒯
 * Unicode code point: U+d4af (54447)
 * Description: mathematical script capital t
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital u html character entity reference model.
 *
 * Name: Uscr
 * Character: 𝒰
 * Unicode code point: U+d4b0 (54448)
 * Description: mathematical script capital u
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital v html character entity reference model.
 *
 * Name: Vscr
 * Character: 𝒱
 * Unicode code point: U+d4b1 (54449)
 * Description: mathematical script capital v
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital w html character entity reference model.
 *
 * Name: Wscr
 * Character: 𝒲
 * Unicode code point: U+d4b2 (54450)
 * Description: mathematical script capital w
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital x html character entity reference model.
 *
 * Name: Xscr
 * Character: 𝒳
 * Unicode code point: U+d4b3 (54451)
 * Description: mathematical script capital x
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital y html character entity reference model.
 *
 * Name: Yscr
 * Character: 𝒴
 * Unicode code point: U+d4b4 (54452)
 * Description: mathematical script capital y
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script capital z html character entity reference model.
 *
 * Name: Zscr
 * Character: 𝒵
 * Unicode code point: U+d4b5 (54453)
 * Description: mathematical script capital z
 */
static wchar_t* MATHEMATICAL_SCRIPT_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zscr";
static int* MATHEMATICAL_SCRIPT_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small a html character entity reference model.
 *
 * Name: ascr
 * Character: 𝒶
 * Unicode code point: U+d4b6 (54454)
 * Description: mathematical script small a
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ascr";
static int* MATHEMATICAL_SCRIPT_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small b html character entity reference model.
 *
 * Name: bscr
 * Character: 𝒷
 * Unicode code point: U+d4b7 (54455)
 * Description: mathematical script small b
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bscr";
static int* MATHEMATICAL_SCRIPT_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small c html character entity reference model.
 *
 * Name: cscr
 * Character: 𝒸
 * Unicode code point: U+d4b8 (54456)
 * Description: mathematical script small c
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cscr";
static int* MATHEMATICAL_SCRIPT_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small d html character entity reference model.
 *
 * Name: dscr
 * Character: 𝒹
 * Unicode code point: U+d4b9 (54457)
 * Description: mathematical script small d
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dscr";
static int* MATHEMATICAL_SCRIPT_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small f html character entity reference model.
 *
 * Name: fscr
 * Character: 𝒻
 * Unicode code point: U+d4bb (54459)
 * Description: mathematical script small f
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fscr";
static int* MATHEMATICAL_SCRIPT_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small h html character entity reference model.
 *
 * Name: hscr
 * Character: 𝒽
 * Unicode code point: U+d4bd (54461)
 * Description: mathematical script small h
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hscr";
static int* MATHEMATICAL_SCRIPT_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small i html character entity reference model.
 *
 * Name: iscr
 * Character: 𝒾
 * Unicode code point: U+d4be (54462)
 * Description: mathematical script small i
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iscr";
static int* MATHEMATICAL_SCRIPT_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small j html character entity reference model.
 *
 * Name: jscr
 * Character: 𝒿
 * Unicode code point: U+d4bf (54463)
 * Description: mathematical script small j
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jscr";
static int* MATHEMATICAL_SCRIPT_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small k html character entity reference model.
 *
 * Name: kscr
 * Character: 𝓀
 * Unicode code point: U+d4c0 (54464)
 * Description: mathematical script small k
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kscr";
static int* MATHEMATICAL_SCRIPT_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small l html character entity reference model.
 *
 * Name: lscr
 * Character: 𝓁
 * Unicode code point: U+d4c1 (54465)
 * Description: mathematical script small l
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lscr";
static int* MATHEMATICAL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small m html character entity reference model.
 *
 * Name: mscr
 * Character: 𝓂
 * Unicode code point: U+d4c2 (54466)
 * Description: mathematical script small m
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mscr";
static int* MATHEMATICAL_SCRIPT_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small n html character entity reference model.
 *
 * Name: nscr
 * Character: 𝓃
 * Unicode code point: U+d4c3 (54467)
 * Description: mathematical script small n
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nscr";
static int* MATHEMATICAL_SCRIPT_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small p html character entity reference model.
 *
 * Name: pscr
 * Character: 𝓅
 * Unicode code point: U+d4c5 (54469)
 * Description: mathematical script small p
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pscr";
static int* MATHEMATICAL_SCRIPT_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small q html character entity reference model.
 *
 * Name: qscr
 * Character: 𝓆
 * Unicode code point: U+d4c6 (54470)
 * Description: mathematical script small q
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qscr";
static int* MATHEMATICAL_SCRIPT_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small r html character entity reference model.
 *
 * Name: rscr
 * Character: 𝓇
 * Unicode code point: U+d4c7 (54471)
 * Description: mathematical script small r
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rscr";
static int* MATHEMATICAL_SCRIPT_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small s html character entity reference model.
 *
 * Name: sscr
 * Character: 𝓈
 * Unicode code point: U+d4c8 (54472)
 * Description: mathematical script small s
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sscr";
static int* MATHEMATICAL_SCRIPT_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small t html character entity reference model.
 *
 * Name: tscr
 * Character: 𝓉
 * Unicode code point: U+d4c9 (54473)
 * Description: mathematical script small t
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tscr";
static int* MATHEMATICAL_SCRIPT_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small u html character entity reference model.
 *
 * Name: uscr
 * Character: 𝓊
 * Unicode code point: U+d4ca (54474)
 * Description: mathematical script small u
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uscr";
static int* MATHEMATICAL_SCRIPT_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small v html character entity reference model.
 *
 * Name: vscr
 * Character: 𝓋
 * Unicode code point: U+d4cb (54475)
 * Description: mathematical script small v
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vscr";
static int* MATHEMATICAL_SCRIPT_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small w html character entity reference model.
 *
 * Name: wscr
 * Character: 𝓌
 * Unicode code point: U+d4cc (54476)
 * Description: mathematical script small w
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wscr";
static int* MATHEMATICAL_SCRIPT_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small x html character entity reference model.
 *
 * Name: xscr
 * Character: 𝓍
 * Unicode code point: U+d4cd (54477)
 * Description: mathematical script small x
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xscr";
static int* MATHEMATICAL_SCRIPT_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small y html character entity reference model.
 *
 * Name: yscr
 * Character: 𝓎
 * Unicode code point: U+d4ce (54478)
 * Description: mathematical script small y
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yscr";
static int* MATHEMATICAL_SCRIPT_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical script small z html character entity reference model.
 *
 * Name: zscr
 * Character: 𝓏
 * Unicode code point: U+d4cf (54479)
 * Description: mathematical script small z
 */
static wchar_t* MATHEMATICAL_SCRIPT_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zscr";
static int* MATHEMATICAL_SCRIPT_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital a html character entity reference model.
 *
 * Name: Afr
 * Character: 𝔄
 * Unicode code point: U+d504 (54532)
 * Description: mathematical fraktur capital a
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Afr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital b html character entity reference model.
 *
 * Name: Bfr
 * Character: 𝔅
 * Unicode code point: U+d505 (54533)
 * Description: mathematical fraktur capital b
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital d html character entity reference model.
 *
 * Name: Dfr
 * Character: 𝔇
 * Unicode code point: U+d507 (54535)
 * Description: mathematical fraktur capital d
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital e html character entity reference model.
 *
 * Name: Efr
 * Character: 𝔈
 * Unicode code point: U+d508 (54536)
 * Description: mathematical fraktur capital e
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Efr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital f html character entity reference model.
 *
 * Name: Ffr
 * Character: 𝔉
 * Unicode code point: U+d509 (54537)
 * Description: mathematical fraktur capital f
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ffr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital g html character entity reference model.
 *
 * Name: Gfr
 * Character: 𝔊
 * Unicode code point: U+d50a (54538)
 * Description: mathematical fraktur capital g
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital j html character entity reference model.
 *
 * Name: Jfr
 * Character: 𝔍
 * Unicode code point: U+d50d (54541)
 * Description: mathematical fraktur capital j
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital k html character entity reference model.
 *
 * Name: Kfr
 * Character: 𝔎
 * Unicode code point: U+d50e (54542)
 * Description: mathematical fraktur capital k
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital l html character entity reference model.
 *
 * Name: Lfr
 * Character: 𝔏
 * Unicode code point: U+d50f (54543)
 * Description: mathematical fraktur capital l
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital m html character entity reference model.
 *
 * Name: Mfr
 * Character: 𝔐
 * Unicode code point: U+d510 (54544)
 * Description: mathematical fraktur capital m
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital n html character entity reference model.
 *
 * Name: Nfr
 * Character: 𝔑
 * Unicode code point: U+d511 (54545)
 * Description: mathematical fraktur capital n
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital o html character entity reference model.
 *
 * Name: Ofr
 * Character: 𝔒
 * Unicode code point: U+d512 (54546)
 * Description: mathematical fraktur capital o
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ofr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital p html character entity reference model.
 *
 * Name: Pfr
 * Character: 𝔓
 * Unicode code point: U+d513 (54547)
 * Description: mathematical fraktur capital p
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital q html character entity reference model.
 *
 * Name: Qfr
 * Character: 𝔔
 * Unicode code point: U+d514 (54548)
 * Description: mathematical fraktur capital q
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital s html character entity reference model.
 *
 * Name: Sfr
 * Character: 𝔖
 * Unicode code point: U+d516 (54550)
 * Description: mathematical fraktur capital s
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital t html character entity reference model.
 *
 * Name: Tfr
 * Character: 𝔗
 * Unicode code point: U+d517 (54551)
 * Description: mathematical fraktur capital t
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital u html character entity reference model.
 *
 * Name: Ufr
 * Character: 𝔘
 * Unicode code point: U+d518 (54552)
 * Description: mathematical fraktur capital u
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ufr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital v html character entity reference model.
 *
 * Name: Vfr
 * Character: 𝔙
 * Unicode code point: U+d519 (54553)
 * Description: mathematical fraktur capital v
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital w html character entity reference model.
 *
 * Name: Wfr
 * Character: 𝔚
 * Unicode code point: U+d51a (54554)
 * Description: mathematical fraktur capital w
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital x html character entity reference model.
 *
 * Name: Xfr
 * Character: 𝔛
 * Unicode code point: U+d51b (54555)
 * Description: mathematical fraktur capital x
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur capital y html character entity reference model.
 *
 * Name: Yfr
 * Character: 𝔜
 * Unicode code point: U+d51c (54556)
 * Description: mathematical fraktur capital y
 */
static wchar_t* MATHEMATICAL_FRAKTUR_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yfr";
static int* MATHEMATICAL_FRAKTUR_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small a html character entity reference model.
 *
 * Name: afr
 * Character: 𝔞
 * Unicode code point: U+d51e (54558)
 * Description: mathematical fraktur small a
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"afr";
static int* MATHEMATICAL_FRAKTUR_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small b html character entity reference model.
 *
 * Name: bfr
 * Character: 𝔟
 * Unicode code point: U+d51f (54559)
 * Description: mathematical fraktur small b
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small c html character entity reference model.
 *
 * Name: cfr
 * Character: 𝔠
 * Unicode code point: U+d520 (54560)
 * Description: mathematical fraktur small c
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small d html character entity reference model.
 *
 * Name: dfr
 * Character: 𝔡
 * Unicode code point: U+d521 (54561)
 * Description: mathematical fraktur small d
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small e html character entity reference model.
 *
 * Name: efr
 * Character: 𝔢
 * Unicode code point: U+d522 (54562)
 * Description: mathematical fraktur small e
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"efr";
static int* MATHEMATICAL_FRAKTUR_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small f html character entity reference model.
 *
 * Name: ffr
 * Character: 𝔣
 * Unicode code point: U+d523 (54563)
 * Description: mathematical fraktur small f
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffr";
static int* MATHEMATICAL_FRAKTUR_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small g html character entity reference model.
 *
 * Name: gfr
 * Character: 𝔤
 * Unicode code point: U+d524 (54564)
 * Description: mathematical fraktur small g
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small h html character entity reference model.
 *
 * Name: hfr
 * Character: 𝔥
 * Unicode code point: U+d525 (54565)
 * Description: mathematical fraktur small h
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small i html character entity reference model.
 *
 * Name: ifr
 * Character: 𝔦
 * Unicode code point: U+d526 (54566)
 * Description: mathematical fraktur small i
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ifr";
static int* MATHEMATICAL_FRAKTUR_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small j html character entity reference model.
 *
 * Name: jfr
 * Character: 𝔧
 * Unicode code point: U+d527 (54567)
 * Description: mathematical fraktur small j
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small k html character entity reference model.
 *
 * Name: kfr
 * Character: 𝔨
 * Unicode code point: U+d528 (54568)
 * Description: mathematical fraktur small k
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small l html character entity reference model.
 *
 * Name: lfr
 * Character: 𝔩
 * Unicode code point: U+d529 (54569)
 * Description: mathematical fraktur small l
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small m html character entity reference model.
 *
 * Name: mfr
 * Character: 𝔪
 * Unicode code point: U+d52a (54570)
 * Description: mathematical fraktur small m
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small n html character entity reference model.
 *
 * Name: nfr
 * Character: 𝔫
 * Unicode code point: U+d52b (54571)
 * Description: mathematical fraktur small n
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small o html character entity reference model.
 *
 * Name: ofr
 * Character: 𝔬
 * Unicode code point: U+d52c (54572)
 * Description: mathematical fraktur small o
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ofr";
static int* MATHEMATICAL_FRAKTUR_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small p html character entity reference model.
 *
 * Name: pfr
 * Character: 𝔭
 * Unicode code point: U+d52d (54573)
 * Description: mathematical fraktur small p
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small q html character entity reference model.
 *
 * Name: qfr
 * Character: 𝔮
 * Unicode code point: U+d52e (54574)
 * Description: mathematical fraktur small q
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small r html character entity reference model.
 *
 * Name: rfr
 * Character: 𝔯
 * Unicode code point: U+d52f (54575)
 * Description: mathematical fraktur small r
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small s html character entity reference model.
 *
 * Name: sfr
 * Character: 𝔰
 * Unicode code point: U+d530 (54576)
 * Description: mathematical fraktur small s
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small t html character entity reference model.
 *
 * Name: tfr
 * Character: 𝔱
 * Unicode code point: U+d531 (54577)
 * Description: mathematical fraktur small t
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small u html character entity reference model.
 *
 * Name: ufr
 * Character: 𝔲
 * Unicode code point: U+d532 (54578)
 * Description: mathematical fraktur small u
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ufr";
static int* MATHEMATICAL_FRAKTUR_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small v html character entity reference model.
 *
 * Name: vfr
 * Character: 𝔳
 * Unicode code point: U+d533 (54579)
 * Description: mathematical fraktur small v
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small w html character entity reference model.
 *
 * Name: wfr
 * Character: 𝔴
 * Unicode code point: U+d534 (54580)
 * Description: mathematical fraktur small w
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small x html character entity reference model.
 *
 * Name: xfr
 * Character: 𝔵
 * Unicode code point: U+d535 (54581)
 * Description: mathematical fraktur small x
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small y html character entity reference model.
 *
 * Name: yfr
 * Character: 𝔶
 * Unicode code point: U+d536 (54582)
 * Description: mathematical fraktur small y
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical fraktur small z html character entity reference model.
 *
 * Name: zfr
 * Character: 𝔷
 * Unicode code point: U+d537 (54583)
 * Description: mathematical fraktur small z
 */
static wchar_t* MATHEMATICAL_FRAKTUR_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zfr";
static int* MATHEMATICAL_FRAKTUR_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital a html character entity reference model.
 *
 * Name: Aopf
 * Character: 𝔸
 * Unicode code point: U+d538 (54584)
 * Description: mathematical double-struck capital a
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital b html character entity reference model.
 *
 * Name: Bopf
 * Character: 𝔹
 * Unicode code point: U+d539 (54585)
 * Description: mathematical double-struck capital b
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital d html character entity reference model.
 *
 * Name: Dopf
 * Character: 𝔻
 * Unicode code point: U+d53b (54587)
 * Description: mathematical double-struck capital d
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital e html character entity reference model.
 *
 * Name: Eopf
 * Character: 𝔼
 * Unicode code point: U+d53c (54588)
 * Description: mathematical double-struck capital e
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital f html character entity reference model.
 *
 * Name: Fopf
 * Character: 𝔽
 * Unicode code point: U+d53d (54589)
 * Description: mathematical double-struck capital f
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital g html character entity reference model.
 *
 * Name: Gopf
 * Character: 𝔾
 * Unicode code point: U+d53e (54590)
 * Description: mathematical double-struck capital g
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital i html character entity reference model.
 *
 * Name: Iopf
 * Character: 𝕀
 * Unicode code point: U+d540 (54592)
 * Description: mathematical double-struck capital i
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital j html character entity reference model.
 *
 * Name: Jopf
 * Character: 𝕁
 * Unicode code point: U+d541 (54593)
 * Description: mathematical double-struck capital j
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital k html character entity reference model.
 *
 * Name: Kopf
 * Character: 𝕂
 * Unicode code point: U+d542 (54594)
 * Description: mathematical double-struck capital k
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital l html character entity reference model.
 *
 * Name: Lopf
 * Character: 𝕃
 * Unicode code point: U+d543 (54595)
 * Description: mathematical double-struck capital l
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital m html character entity reference model.
 *
 * Name: Mopf
 * Character: 𝕄
 * Unicode code point: U+d544 (54596)
 * Description: mathematical double-struck capital m
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital o html character entity reference model.
 *
 * Name: Oopf
 * Character: 𝕆
 * Unicode code point: U+d546 (54598)
 * Description: mathematical double-struck capital o
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital s html character entity reference model.
 *
 * Name: Sopf
 * Character: 𝕊
 * Unicode code point: U+d54a (54602)
 * Description: mathematical double-struck capital s
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital t html character entity reference model.
 *
 * Name: Topf
 * Character: 𝕋
 * Unicode code point: U+d54b (54603)
 * Description: mathematical double-struck capital t
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Topf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital u html character entity reference model.
 *
 * Name: Uopf
 * Character: 𝕌
 * Unicode code point: U+d54c (54604)
 * Description: mathematical double-struck capital u
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital v html character entity reference model.
 *
 * Name: Vopf
 * Character: 𝕍
 * Unicode code point: U+d54d (54605)
 * Description: mathematical double-struck capital v
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital w html character entity reference model.
 *
 * Name: Wopf
 * Character: 𝕎
 * Unicode code point: U+d54e (54606)
 * Description: mathematical double-struck capital w
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital x html character entity reference model.
 *
 * Name: Xopf
 * Character: 𝕏
 * Unicode code point: U+d54f (54607)
 * Description: mathematical double-struck capital x
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck capital y html character entity reference model.
 *
 * Name: Yopf
 * Character: 𝕐
 * Unicode code point: U+d550 (54608)
 * Description: mathematical double-struck capital y
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small a html character entity reference model.
 *
 * Name: aopf
 * Character: 𝕒
 * Unicode code point: U+d552 (54610)
 * Description: mathematical double-struck small a
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small b html character entity reference model.
 *
 * Name: bopf
 * Character: 𝕓
 * Unicode code point: U+d553 (54611)
 * Description: mathematical double-struck small b
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small c html character entity reference model.
 *
 * Name: copf
 * Character: 𝕔
 * Unicode code point: U+d554 (54612)
 * Description: mathematical double-struck small c
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small d html character entity reference model.
 *
 * Name: dopf
 * Character: 𝕕
 * Unicode code point: U+d555 (54613)
 * Description: mathematical double-struck small d
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small e html character entity reference model.
 *
 * Name: eopf
 * Character: 𝕖
 * Unicode code point: U+d556 (54614)
 * Description: mathematical double-struck small e
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small f html character entity reference model.
 *
 * Name: fopf
 * Character: 𝕗
 * Unicode code point: U+d557 (54615)
 * Description: mathematical double-struck small f
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small g html character entity reference model.
 *
 * Name: gopf
 * Character: 𝕘
 * Unicode code point: U+d558 (54616)
 * Description: mathematical double-struck small g
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small h html character entity reference model.
 *
 * Name: hopf
 * Character: 𝕙
 * Unicode code point: U+d559 (54617)
 * Description: mathematical double-struck small h
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small i html character entity reference model.
 *
 * Name: iopf
 * Character: 𝕚
 * Unicode code point: U+d55a (54618)
 * Description: mathematical double-struck small i
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small j html character entity reference model.
 *
 * Name: jopf
 * Character: 𝕛
 * Unicode code point: U+d55b (54619)
 * Description: mathematical double-struck small j
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small k html character entity reference model.
 *
 * Name: kopf
 * Character: 𝕜
 * Unicode code point: U+d55c (54620)
 * Description: mathematical double-struck small k
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small l html character entity reference model.
 *
 * Name: lopf
 * Character: 𝕝
 * Unicode code point: U+d55d (54621)
 * Description: mathematical double-struck small l
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small m html character entity reference model.
 *
 * Name: mopf
 * Character: 𝕞
 * Unicode code point: U+d55e (54622)
 * Description: mathematical double-struck small m
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small n html character entity reference model.
 *
 * Name: nopf
 * Character: 𝕟
 * Unicode code point: U+d55f (54623)
 * Description: mathematical double-struck small n
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small o html character entity reference model.
 *
 * Name: oopf
 * Character: 𝕠
 * Unicode code point: U+d560 (54624)
 * Description: mathematical double-struck small o
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small p html character entity reference model.
 *
 * Name: popf
 * Character: 𝕡
 * Unicode code point: U+d561 (54625)
 * Description: mathematical double-struck small p
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"popf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small q html character entity reference model.
 *
 * Name: qopf
 * Character: 𝕢
 * Unicode code point: U+d562 (54626)
 * Description: mathematical double-struck small q
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small r html character entity reference model.
 *
 * Name: ropf
 * Character: 𝕣
 * Unicode code point: U+d563 (54627)
 * Description: mathematical double-struck small r
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ropf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small s html character entity reference model.
 *
 * Name: sopf
 * Character: 𝕤
 * Unicode code point: U+d564 (54628)
 * Description: mathematical double-struck small s
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small t html character entity reference model.
 *
 * Name: topf
 * Character: 𝕥
 * Unicode code point: U+d565 (54629)
 * Description: mathematical double-struck small t
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small u html character entity reference model.
 *
 * Name: uopf
 * Character: 𝕦
 * Unicode code point: U+d566 (54630)
 * Description: mathematical double-struck small u
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small v html character entity reference model.
 *
 * Name: vopf
 * Character: 𝕧
 * Unicode code point: U+d567 (54631)
 * Description: mathematical double-struck small v
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small w html character entity reference model.
 *
 * Name: wopf
 * Character: 𝕨
 * Unicode code point: U+d568 (54632)
 * Description: mathematical double-struck small w
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small x html character entity reference model.
 *
 * Name: xopf
 * Character: 𝕩
 * Unicode code point: U+d569 (54633)
 * Description: mathematical double-struck small x
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small y html character entity reference model.
 *
 * Name: yopf
 * Character: 𝕪
 * Unicode code point: U+d56a (54634)
 * Description: mathematical double-struck small y
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical double-struck small z html character entity reference model.
 *
 * Name: zopf
 * Character: 𝕫
 * Unicode code point: U+d56b (54635)
 * Description: mathematical double-struck small z
 */
static wchar_t* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zopf";
static int* MATHEMATICAL_DOUBLE_STRUCK_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital gamma html character entity reference model.
 *
 * Name: b.Gamma
 * Character: 𝚪
 * Unicode code point: U+d6aa (54954)
 * Description: mathematical bold capital gamma
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Gamma";
static int* MATHEMATICAL_BOLD_CAPITAL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital delta html character entity reference model.
 *
 * Name: b.Delta
 * Character: 𝚫
 * Unicode code point: U+d6ab (54955)
 * Description: mathematical bold capital delta
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Delta";
static int* MATHEMATICAL_BOLD_CAPITAL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital theta html character entity reference model.
 *
 * Name: b.Theta
 * Character: 𝚯
 * Unicode code point: U+d6af (54959)
 * Description: mathematical bold capital theta
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Theta";
static int* MATHEMATICAL_BOLD_CAPITAL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital lamda html character entity reference model.
 *
 * Name: b.Lambda
 * Character: 𝚲
 * Unicode code point: U+d6b2 (54962)
 * Description: mathematical bold capital lamda
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Lambda";
static int* MATHEMATICAL_BOLD_CAPITAL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital xi html character entity reference model.
 *
 * Name: b.Xi
 * Character: 𝚵
 * Unicode code point: U+d6b5 (54965)
 * Description: mathematical bold capital xi
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Xi";
static int* MATHEMATICAL_BOLD_CAPITAL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital pi html character entity reference model.
 *
 * Name: b.Pi
 * Character: 𝚷
 * Unicode code point: U+d6b7 (54967)
 * Description: mathematical bold capital pi
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Pi";
static int* MATHEMATICAL_BOLD_CAPITAL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital sigma html character entity reference model.
 *
 * Name: b.Sigma
 * Character: 𝚺
 * Unicode code point: U+d6ba (54970)
 * Description: mathematical bold capital sigma
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Sigma";
static int* MATHEMATICAL_BOLD_CAPITAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital upsilon html character entity reference model.
 *
 * Name: b.Upsi
 * Character: 𝚼
 * Unicode code point: U+d6bc (54972)
 * Description: mathematical bold capital upsilon
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Upsi";
static int* MATHEMATICAL_BOLD_CAPITAL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital phi html character entity reference model.
 *
 * Name: b.Phi
 * Character: 𝚽
 * Unicode code point: U+d6bd (54973)
 * Description: mathematical bold capital phi
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Phi";
static int* MATHEMATICAL_BOLD_CAPITAL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital psi html character entity reference model.
 *
 * Name: b.Psi
 * Character: 𝚿
 * Unicode code point: U+d6bf (54975)
 * Description: mathematical bold capital psi
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Psi";
static int* MATHEMATICAL_BOLD_CAPITAL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital omega html character entity reference model.
 *
 * Name: b.Omega
 * Character: 𝛀
 * Unicode code point: U+d6c0 (54976)
 * Description: mathematical bold capital omega
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Omega";
static int* MATHEMATICAL_BOLD_CAPITAL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small alpha html character entity reference model.
 *
 * Name: b.alpha
 * Character: 𝛂
 * Unicode code point: U+d6c2 (54978)
 * Description: mathematical bold small alpha
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.alpha";
static int* MATHEMATICAL_BOLD_SMALL_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small beta html character entity reference model.
 *
 * Name: b.beta
 * Character: 𝛃
 * Unicode code point: U+d6c3 (54979)
 * Description: mathematical bold small beta
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.beta";
static int* MATHEMATICAL_BOLD_SMALL_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small gamma html character entity reference model.
 *
 * Name: b.gamma
 * Character: 𝛄
 * Unicode code point: U+d6c4 (54980)
 * Description: mathematical bold small gamma
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.gamma";
static int* MATHEMATICAL_BOLD_SMALL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small delta html character entity reference model.
 *
 * Name: b.delta
 * Character: 𝛅
 * Unicode code point: U+d6c5 (54981)
 * Description: mathematical bold small delta
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.delta";
static int* MATHEMATICAL_BOLD_SMALL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small epsilon html character entity reference model.
 *
 * Name: b.epsi
 * Character: 𝛆
 * Unicode code point: U+d6c6 (54982)
 * Description: mathematical bold small epsilon
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.epsi";
static int* MATHEMATICAL_BOLD_SMALL_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small zeta html character entity reference model.
 *
 * Name: b.zeta
 * Character: 𝛇
 * Unicode code point: U+d6c7 (54983)
 * Description: mathematical bold small zeta
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.zeta";
static int* MATHEMATICAL_BOLD_SMALL_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small eta html character entity reference model.
 *
 * Name: b.eta
 * Character: 𝛈
 * Unicode code point: U+d6c8 (54984)
 * Description: mathematical bold small eta
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.eta";
static int* MATHEMATICAL_BOLD_SMALL_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small theta html character entity reference model.
 *
 * Name: b.thetas
 * Character: 𝛉
 * Unicode code point: U+d6c9 (54985)
 * Description: mathematical bold small theta
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.thetas";
static int* MATHEMATICAL_BOLD_SMALL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small iota html character entity reference model.
 *
 * Name: b.iota
 * Character: 𝛊
 * Unicode code point: U+d6ca (54986)
 * Description: mathematical bold small iota
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.iota";
static int* MATHEMATICAL_BOLD_SMALL_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small kappa html character entity reference model.
 *
 * Name: b.kappa
 * Character: 𝛋
 * Unicode code point: U+d6cb (54987)
 * Description: mathematical bold small kappa
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.kappa";
static int* MATHEMATICAL_BOLD_SMALL_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small lamda html character entity reference model.
 *
 * Name: b.lambda
 * Character: 𝛌
 * Unicode code point: U+d6cc (54988)
 * Description: mathematical bold small lamda
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.lambda";
static int* MATHEMATICAL_BOLD_SMALL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small mu html character entity reference model.
 *
 * Name: b.mu
 * Character: 𝛍
 * Unicode code point: U+d6cd (54989)
 * Description: mathematical bold small mu
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.mu";
static int* MATHEMATICAL_BOLD_SMALL_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small nu html character entity reference model.
 *
 * Name: b.nu
 * Character: 𝛎
 * Unicode code point: U+d6ce (54990)
 * Description: mathematical bold small nu
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.nu";
static int* MATHEMATICAL_BOLD_SMALL_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small xi html character entity reference model.
 *
 * Name: b.xi
 * Character: 𝛏
 * Unicode code point: U+d6cf (54991)
 * Description: mathematical bold small xi
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.xi";
static int* MATHEMATICAL_BOLD_SMALL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small pi html character entity reference model.
 *
 * Name: b.pi
 * Character: 𝛑
 * Unicode code point: U+d6d1 (54993)
 * Description: mathematical bold small pi
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.pi";
static int* MATHEMATICAL_BOLD_SMALL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small rho html character entity reference model.
 *
 * Name: b.rho
 * Character: 𝛒
 * Unicode code point: U+d6d2 (54994)
 * Description: mathematical bold small rho
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.rho";
static int* MATHEMATICAL_BOLD_SMALL_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small final sigma html character entity reference model.
 *
 * Name: b.sigmav
 * Character: 𝛓
 * Unicode code point: U+d6d3 (54995)
 * Description: mathematical bold small final sigma
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.sigmav";
static int* MATHEMATICAL_BOLD_SMALL_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small sigma html character entity reference model.
 *
 * Name: b.sigma
 * Character: 𝛔
 * Unicode code point: U+d6d4 (54996)
 * Description: mathematical bold small sigma
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.sigma";
static int* MATHEMATICAL_BOLD_SMALL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small tau html character entity reference model.
 *
 * Name: b.tau
 * Character: 𝛕
 * Unicode code point: U+d6d5 (54997)
 * Description: mathematical bold small tau
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.tau";
static int* MATHEMATICAL_BOLD_SMALL_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small upsilon html character entity reference model.
 *
 * Name: b.upsi
 * Character: 𝛖
 * Unicode code point: U+d6d6 (54998)
 * Description: mathematical bold small upsilon
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.upsi";
static int* MATHEMATICAL_BOLD_SMALL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small phi html character entity reference model.
 *
 * Name: b.phi
 * Character: 𝛗
 * Unicode code point: U+d6d7 (54999)
 * Description: mathematical bold small phi
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.phi";
static int* MATHEMATICAL_BOLD_SMALL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small chi html character entity reference model.
 *
 * Name: b.chi
 * Character: 𝛘
 * Unicode code point: U+d6d8 (55000)
 * Description: mathematical bold small chi
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.chi";
static int* MATHEMATICAL_BOLD_SMALL_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small psi html character entity reference model.
 *
 * Name: b.psi
 * Character: 𝛙
 * Unicode code point: U+d6d9 (55001)
 * Description: mathematical bold small psi
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.psi";
static int* MATHEMATICAL_BOLD_SMALL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small omega html character entity reference model.
 *
 * Name: b.omega
 * Character: 𝛚
 * Unicode code point: U+d6da (55002)
 * Description: mathematical bold small omega
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.omega";
static int* MATHEMATICAL_BOLD_SMALL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold epsilon symbol html character entity reference model.
 *
 * Name: b.epsiv
 * Character: 𝛜
 * Unicode code point: U+d6dc (55004)
 * Description: mathematical bold epsilon symbol
 */
static wchar_t* MATHEMATICAL_BOLD_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.epsiv";
static int* MATHEMATICAL_BOLD_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold theta symbol html character entity reference model.
 *
 * Name: b.thetav
 * Character: 𝛝
 * Unicode code point: U+d6dd (55005)
 * Description: mathematical bold theta symbol
 */
static wchar_t* MATHEMATICAL_BOLD_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.thetav";
static int* MATHEMATICAL_BOLD_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold kappa symbol html character entity reference model.
 *
 * Name: b.kappav
 * Character: 𝛞
 * Unicode code point: U+d6de (55006)
 * Description: mathematical bold kappa symbol
 */
static wchar_t* MATHEMATICAL_BOLD_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.kappav";
static int* MATHEMATICAL_BOLD_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold phi symbol html character entity reference model.
 *
 * Name: b.phiv
 * Character: 𝛟
 * Unicode code point: U+d6df (55007)
 * Description: mathematical bold phi symbol
 */
static wchar_t* MATHEMATICAL_BOLD_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.phiv";
static int* MATHEMATICAL_BOLD_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold rho symbol html character entity reference model.
 *
 * Name: b.rhov
 * Character: 𝛠
 * Unicode code point: U+d6e0 (55008)
 * Description: mathematical bold rho symbol
 */
static wchar_t* MATHEMATICAL_BOLD_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.rhov";
static int* MATHEMATICAL_BOLD_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold pi symbol html character entity reference model.
 *
 * Name: b.piv
 * Character: 𝛡
 * Unicode code point: U+d6e1 (55009)
 * Description: mathematical bold pi symbol
 */
static wchar_t* MATHEMATICAL_BOLD_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.piv";
static int* MATHEMATICAL_BOLD_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold capital digamma html character entity reference model.
 *
 * Name: b.Gammad
 * Character: 𝟊
 * Unicode code point: U+d7ca (55242)
 * Description: mathematical bold capital digamma
 */
static wchar_t* MATHEMATICAL_BOLD_CAPITAL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.Gammad";
static int* MATHEMATICAL_BOLD_CAPITAL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mathematical bold small digamma html character entity reference model.
 *
 * Name: b.gammad
 * Character: 𝟋
 * Unicode code point: U+d7cb (55243)
 * Description: mathematical bold small digamma
 */
static wchar_t* MATHEMATICAL_BOLD_SMALL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b.gammad";
static int* MATHEMATICAL_BOLD_SMALL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature ff html character entity reference model.
 *
 * Name: fflig
 * Character: ﬀ
 * Unicode code point: U+fb00 (64256)
 * Description: latin small ligature ff
 */
static wchar_t* LATIN_SMALL_LIGATURE_FF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fflig";
static int* LATIN_SMALL_LIGATURE_FF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature fi html character entity reference model.
 *
 * Name: filig
 * Character: ﬁ
 * Unicode code point: U+fb01 (64257)
 * Description: latin small ligature fi
 */
static wchar_t* LATIN_SMALL_LIGATURE_FI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"filig";
static int* LATIN_SMALL_LIGATURE_FI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature fl html character entity reference model.
 *
 * Name: fllig
 * Character: ﬂ
 * Unicode code point: U+fb02 (64258)
 * Description: latin small ligature fl
 */
static wchar_t* LATIN_SMALL_LIGATURE_FL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fllig";
static int* LATIN_SMALL_LIGATURE_FL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature ffi html character entity reference model.
 *
 * Name: ffilig
 * Character: ﬃ
 * Unicode code point: U+fb03 (64259)
 * Description: latin small ligature ffi
 */
static wchar_t* LATIN_SMALL_LIGATURE_FFI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffilig";
static int* LATIN_SMALL_LIGATURE_FFI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latin small ligature ffl html character entity reference model.
 *
 * Name: ffllig
 * Character: ﬄ
 * Unicode code point: U+fb04 (64260)
 * Description: latin small ligature ffl
 */
static wchar_t* LATIN_SMALL_LIGATURE_FFL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffllig";
static int* LATIN_SMALL_LIGATURE_FFL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_SOURCE */
#endif
