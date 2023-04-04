/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_HEADER
#define HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
 * The Tab html character entity reference model.
 *
 * Name: Tab
 * Character:
 * Unicode code point: U+0009 (9)
 * Description: character tabulation
 */
static wchar_t* TAB_CHARACTER_TABULATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tab";
static int* TAB_CHARACTER_TABULATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NewLine html character entity reference model.
 *
 * Name: NewLine
 * Character:

 * Unicode code point: U+000a (10)
 * Description: line feed (lf)
 */
static wchar_t* NEWLINE_LINE_FEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NewLine";
static int* NEWLINE_LINE_FEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The excl html character entity reference model.
 *
 * Name: excl
 * Character: !
 * Unicode code point: U+0021 (33)
 * Description: exclamation mark
 */
static wchar_t* EXCL_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"excl";
static int* EXCL_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The QUOT html character entity reference model.
 *
 * Name: QUOT
 * Character: "
 * Unicode code point: U+0022 (34)
 * Description: quotation mark
 */
static wchar_t* CAPITAL_QUOT_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"QUOT";
static int* CAPITAL_QUOT_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quot html character entity reference model.
 *
 * Name: quot
 * Character: "
 * Unicode code point: U+0022 (34)
 * Description: quotation mark
 */
static wchar_t* SMALL_QUOT_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quot";
static int* SMALL_QUOT_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The num html character entity reference model.
 *
 * Name: num
 * Character: #
 * Unicode code point: U+0023 (35)
 * Description: number sign
 */
static wchar_t* NUM_NUMBER_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"num";
static int* NUM_NUMBER_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dollar html character entity reference model.
 *
 * Name: dollar
 * Character: $
 * Unicode code point: U+0024 (36)
 * Description: dollar sign
 */
static wchar_t* DOLLAR_DOLLAR_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dollar";
static int* DOLLAR_DOLLAR_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The percnt html character entity reference model.
 *
 * Name: percnt
 * Character: %
 * Unicode code point: U+0025 (37)
 * Description: percent sign
 */
static wchar_t* PERCNT_PERCENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"percnt";
static int* PERCNT_PERCENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The AMP html character entity reference model.
 *
 * Name: AMP
 * Character: &
 * Unicode code point: U+0026 (38)
 * Description: ampersand
 */
static wchar_t* CAPITAL_AMP_AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"AMP";
static int* CAPITAL_AMP_AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The amp html character entity reference model.
 *
 * Name: amp
 * Character: &
 * Unicode code point: U+0026 (38)
 * Description: ampersand
 */
static wchar_t* SMALL_AMP_AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amp";
static int* SMALL_AMP_AMPERSAND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apos html character entity reference model.
 *
 * Name: apos
 * Character: '
 * Unicode code point: U+0027 (39)
 * Description: apostrophe
 */
static wchar_t* APOS_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apos";
static int* APOS_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lpar html character entity reference model.
 *
 * Name: lpar
 * Character: (
 * Unicode code point: U+0028 (40)
 * Description: left parenthesis
 */
static wchar_t* LPAR_LEFT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lpar";
static int* LPAR_LEFT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rpar html character entity reference model.
 *
 * Name: rpar
 * Character: )
 * Unicode code point: U+0029 (41)
 * Description: right parenthesis
 */
static wchar_t* RPAR_RIGHT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rpar";
static int* RPAR_RIGHT_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ast html character entity reference model.
 *
 * Name: ast
 * Character: *
 * Unicode code point: U+002a (42)
 * Description: asterisk
 */
static wchar_t* AST_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ast";
static int* AST_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The midast html character entity reference model.
 *
 * Name: midast
 * Character: *
 * Unicode code point: U+002a (42)
 * Description: asterisk
 */
static wchar_t* MIDAST_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"midast";
static int* MIDAST_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plus html character entity reference model.
 *
 * Name: plus
 * Character: +
 * Unicode code point: U+002b (43)
 * Description: plus sign
 */
static wchar_t* PLUS_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plus";
static int* PLUS_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The comma html character entity reference model.
 *
 * Name: comma
 * Character: ,
 * Unicode code point: U+002c (44)
 * Description: comma
 */
static wchar_t* COMMA_COMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"comma";
static int* COMMA_COMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The period html character entity reference model.
 *
 * Name: period
 * Character: .
 * Unicode code point: U+002e (46)
 * Description: full stop
 */
static wchar_t* PERIOD_FULL_STOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"period";
static int* PERIOD_FULL_STOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sol html character entity reference model.
 *
 * Name: sol
 * Character: /
 * Unicode code point: U+002f (47)
 * Description: solidus
 */
static wchar_t* SOL_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sol";
static int* SOL_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colon html character entity reference model.
 *
 * Name: colon
 * Character: :
 * Unicode code point: U+003a (58)
 * Description: colon
 */
static wchar_t* COLON_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"colon";
static int* COLON_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The semi html character entity reference model.
 *
 * Name: semi
 * Character: ;
 * Unicode code point: U+003b (59)
 * Description: semicolon
 */
static wchar_t* SEMI_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"semi";
static int* SEMI_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LT html character entity reference model.
 *
 * Name: LT
 * Character: <
 * Unicode code point: U+003c (60)
 * Description: less-than sign
 */
static wchar_t* CAPITAL_LT_LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LT";
static int* CAPITAL_LT_LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lt html character entity reference model.
 *
 * Name: lt
 * Character: <
 * Unicode code point: U+003c (60)
 * Description: less-than sign
 */
static wchar_t* SMALL_LT_LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lt";
static int* SMALL_LT_LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvlt html character entity reference model.
 *
 * Name: nvlt
 * Character: <⃒
 * Unicode code point: U+003c;U+20d2 (60;8402)
 * Description: less-than sign with vertical line
 */
static wchar_t* NVLT_LESS_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvlt";
static int* NVLT_LESS_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bne html character entity reference model.
 *
 * Name: bne
 * Character: =⃥
 * Unicode code point: U+003d;U+20e5 (61;8421)
 * Description: equals sign with reverse slash
 */
static wchar_t* BNE_EQUALS_SIGN_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bne";
static int* BNE_EQUALS_SIGN_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equals html character entity reference model.
 *
 * Name: equals
 * Character: =
 * Unicode code point: U+003d (61)
 * Description: equals sign
 */
static wchar_t* EQUALS_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equals";
static int* EQUALS_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GT html character entity reference model.
 *
 * Name: GT
 * Character: >
 * Unicode code point: U+003e (62)
 * Description: greater-than sign
 */
static wchar_t* CAPITAL_GT_GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GT";
static int* CAPITAL_GT_GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gt html character entity reference model.
 *
 * Name: gt
 * Character: >
 * Unicode code point: U+003e (62)
 * Description: greater-than sign
 */
static wchar_t* SMALL_GT_GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gt";
static int* SMALL_GT_GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvgt html character entity reference model.
 *
 * Name: nvgt
 * Character: >⃒
 * Unicode code point: U+003e;U+20d2 (62;8402)
 * Description: greater-than sign with vertical line
 */
static wchar_t* NVGT_GREATER_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvgt";
static int* NVGT_GREATER_THAN_SIGN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quest html character entity reference model.
 *
 * Name: quest
 * Character: ?
 * Unicode code point: U+003f (63)
 * Description: question mark
 */
static wchar_t* QUEST_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quest";
static int* QUEST_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The commat html character entity reference model.
 *
 * Name: commat
 * Character: @
 * Unicode code point: U+0040 (64)
 * Description: commercial at
 */
static wchar_t* COMMAT_COMMERCIAL_AT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"commat";
static int* COMMAT_COMMERCIAL_AT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbrack html character entity reference model.
 *
 * Name: lbrack
 * Character: [
 * Unicode code point: U+005b (91)
 * Description: left square bracket
 */
static wchar_t* LBRACK_LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrack";
static int* LBRACK_LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsqb html character entity reference model.
 *
 * Name: lsqb
 * Character: [
 * Unicode code point: U+005b (91)
 * Description: left square bracket
 */
static wchar_t* LSQB_LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsqb";
static int* LSQB_LEFT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsol html character entity reference model.
 *
 * Name: bsol
 * Character: \
 * Unicode code point: U+005c (92)
 * Description: reverse solidus
 */
static wchar_t* BSOL_REVERSE_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsol";
static int* BSOL_REVERSE_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbrack html character entity reference model.
 *
 * Name: rbrack
 * Character: ]
 * Unicode code point: U+005d (93)
 * Description: right square bracket
 */
static wchar_t* RBRACK_RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrack";
static int* RBRACK_RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rsqb html character entity reference model.
 *
 * Name: rsqb
 * Character: ]
 * Unicode code point: U+005d (93)
 * Description: right square bracket
 */
static wchar_t* RSQB_RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsqb";
static int* RSQB_RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hat html character entity reference model.
 *
 * Name: Hat
 * Character: ^
 * Unicode code point: U+005e (94)
 * Description: circumflex accent
 */
static wchar_t* HAT_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hat";
static int* HAT_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UnderBar html character entity reference model.
 *
 * Name: UnderBar
 * Character: _
 * Unicode code point: U+005f (95)
 * Description: low line
 */
static wchar_t* UNDERBAR_LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBar";
static int* UNDERBAR_LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lowbar html character entity reference model.
 *
 * Name: lowbar
 * Character: _
 * Unicode code point: U+005f (95)
 * Description: low line
 */
static wchar_t* LOWBAR_LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lowbar";
static int* LOWBAR_LOW_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DiacriticalGrave html character entity reference model.
 *
 * Name: DiacriticalGrave
 * Character: `
 * Unicode code point: U+0060 (96)
 * Description: grave accent
 */
static wchar_t* DIACRITICALGRAVE_GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalGrave";
static int* DIACRITICALGRAVE_GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The grave html character entity reference model.
 *
 * Name: grave
 * Character: `
 * Unicode code point: U+0060 (96)
 * Description: grave accent
 */
static wchar_t* GRAVE_GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"grave";
static int* GRAVE_GRAVE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fjlig html character entity reference model.
 *
 * Name: fjlig
 * Character: fj
 * Unicode code point: U+0066;U+006a (102;106)
 * Description: fj ligature
 */
static wchar_t* FJLIG_FJ_LIGATURE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fjlig";
static int* FJLIG_FJ_LIGATURE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbrace html character entity reference model.
 *
 * Name: lbrace
 * Character: {
 * Unicode code point: U+007b (123)
 * Description: left curly bracket
 */
static wchar_t* LBRACE_LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrace";
static int* LBRACE_LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lcub html character entity reference model.
 *
 * Name: lcub
 * Character: {
 * Unicode code point: U+007b (123)
 * Description: left curly bracket
 */
static wchar_t* LCUB_LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcub";
static int* LCUB_LEFT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VerticalLine html character entity reference model.
 *
 * Name: VerticalLine
 * Character: |
 * Unicode code point: U+007c (124)
 * Description: vertical line
 */
static wchar_t* VERTICALLINE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalLine";
static int* VERTICALLINE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The verbar html character entity reference model.
 *
 * Name: verbar
 * Character: |
 * Unicode code point: U+007c (124)
 * Description: vertical line
 */
static wchar_t* VERBAR_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"verbar";
static int* VERBAR_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vert html character entity reference model.
 *
 * Name: vert
 * Character: |
 * Unicode code point: U+007c (124)
 * Description: vertical line
 */
static wchar_t* VERT_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vert";
static int* VERT_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbrace html character entity reference model.
 *
 * Name: rbrace
 * Character: }
 * Unicode code point: U+007d (125)
 * Description: right curly bracket
 */
static wchar_t* RBRACE_RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrace";
static int* RBRACE_RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rcub html character entity reference model.
 *
 * Name: rcub
 * Character: }
 * Unicode code point: U+007d (125)
 * Description: right curly bracket
 */
static wchar_t* RCUB_RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcub";
static int* RCUB_RIGHT_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NonBreakingSpace html character entity reference model.
 *
 * Name: NonBreakingSpace
 * Character:
 * Unicode code point: U+00a0 (160)
 * Description: no-break space
 */
static wchar_t* NONBREAKINGSPACE_NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NonBreakingSpace";
static int* NONBREAKINGSPACE_NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nbsp html character entity reference model.
 *
 * Name: nbsp
 * Character:
 * Unicode code point: U+00a0 (160)
 * Description: no-break space
 */
static wchar_t* NBSP_NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nbsp";
static int* NBSP_NO_BREAK_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iexcl html character entity reference model.
 *
 * Name: iexcl
 * Character: ¡
 * Unicode code point: U+00a1 (161)
 * Description: inverted exclamation mark
 */
static wchar_t* IEXCL_INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iexcl";
static int* IEXCL_INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cent html character entity reference model.
 *
 * Name: cent
 * Character: ¢
 * Unicode code point: U+00a2 (162)
 * Description: cent sign
 */
static wchar_t* CENT_CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cent";
static int* CENT_CENT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pound html character entity reference model.
 *
 * Name: pound
 * Character: £
 * Unicode code point: U+00a3 (163)
 * Description: pound sign
 */
static wchar_t* POUND_POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pound";
static int* POUND_POUND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curren html character entity reference model.
 *
 * Name: curren
 * Character: ¤
 * Unicode code point: U+00a4 (164)
 * Description: currency sign
 */
static wchar_t* CURREN_CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curren";
static int* CURREN_CURRENCY_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yen html character entity reference model.
 *
 * Name: yen
 * Character: ¥
 * Unicode code point: U+00a5 (165)
 * Description: yen sign
 */
static wchar_t* YEN_YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yen";
static int* YEN_YEN_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The brvbar html character entity reference model.
 *
 * Name: brvbar
 * Character: ¦
 * Unicode code point: U+00a6 (166)
 * Description: broken bar
 */
static wchar_t* BRVBAR_BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"brvbar";
static int* BRVBAR_BROKEN_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sect html character entity reference model.
 *
 * Name: sect
 * Character: §
 * Unicode code point: U+00a7 (167)
 * Description: section sign
 */
static wchar_t* SECT_SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sect";
static int* SECT_SECTION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dot html character entity reference model.
 *
 * Name: Dot
 * Character: ¨
 * Unicode code point: U+00a8 (168)
 * Description: diaeresis
 */
static wchar_t* DOT_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dot";
static int* DOT_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleDot html character entity reference model.
 *
 * Name: DoubleDot
 * Character: ¨
 * Unicode code point: U+00a8 (168)
 * Description: diaeresis
 */
static wchar_t* DOUBLEDOT_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleDot";
static int* DOUBLEDOT_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The die html character entity reference model.
 *
 * Name: die
 * Character: ¨
 * Unicode code point: U+00a8 (168)
 * Description: diaeresis
 */
static wchar_t* DIE_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"die";
static int* DIE_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uml html character entity reference model.
 *
 * Name: uml
 * Character: ¨
 * Unicode code point: U+00a8 (168)
 * Description: diaeresis
 */
static wchar_t* UML_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uml";
static int* UML_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The COPY html character entity reference model.
 *
 * Name: COPY
 * Character: ©
 * Unicode code point: U+00a9 (169)
 * Description: copyright sign
 */
static wchar_t* CAPITAL_COPY_COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"COPY";
static int* CAPITAL_COPY_COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The copy html character entity reference model.
 *
 * Name: copy
 * Character: ©
 * Unicode code point: U+00a9 (169)
 * Description: copyright sign
 */
static wchar_t* SMALL_COPY_COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copy";
static int* SMALL_COPY_COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ordf html character entity reference model.
 *
 * Name: ordf
 * Character: ª
 * Unicode code point: U+00aa (170)
 * Description: feminine ordinal indicator
 */
static wchar_t* ORDF_FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordf";
static int* ORDF_FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The laquo html character entity reference model.
 *
 * Name: laquo
 * Character: «
 * Unicode code point: U+00ab (171)
 * Description: left-pointing double angle quotation mark
 */
static wchar_t* LAQUO_LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"laquo";
static int* LAQUO_LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The not html character entity reference model.
 *
 * Name: not
 * Character: ¬
 * Unicode code point: U+00ac (172)
 * Description: not sign
 */
static wchar_t* NOT_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"not";
static int* NOT_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The shy html character entity reference model.
 *
 * Name: shy
 * Character: ­
 * Unicode code point: U+00ad (173)
 * Description: soft hyphen
 */
static wchar_t* SHY_SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shy";
static int* SHY_SOFT_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The REG html character entity reference model.
 *
 * Name: REG
 * Character: ®
 * Unicode code point: U+00ae (174)
 * Description: registered sign
 */
static wchar_t* CAPITAL_REG_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"REG";
static int* CAPITAL_REG_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circledR html character entity reference model.
 *
 * Name: circledR
 * Character: ®
 * Unicode code point: U+00ae (174)
 * Description: registered sign
 */
static wchar_t* CIRCLEDR_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledR";
static int* CIRCLEDR_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reg html character entity reference model.
 *
 * Name: reg
 * Character: ®
 * Unicode code point: U+00ae (174)
 * Description: registered sign
 */
static wchar_t* SMALL_REG_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"reg";
static int* SMALL_REG_REGISTERED_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The macr html character entity reference model.
 *
 * Name: macr
 * Character: ¯
 * Unicode code point: U+00af (175)
 * Description: macron
 */
static wchar_t* MACR_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"macr";
static int* MACR_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The strns html character entity reference model.
 *
 * Name: strns
 * Character: ¯
 * Unicode code point: U+00af (175)
 * Description: macron
 */
static wchar_t* STRNS_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"strns";
static int* STRNS_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The deg html character entity reference model.
 *
 * Name: deg
 * Character: °
 * Unicode code point: U+00b0 (176)
 * Description: degree sign
 */
static wchar_t* DEG_DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"deg";
static int* DEG_DEGREE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PlusMinus html character entity reference model.
 *
 * Name: PlusMinus
 * Character: ±
 * Unicode code point: U+00b1 (177)
 * Description: plus-minus sign
 */
static wchar_t* PLUSMINUS_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PlusMinus";
static int* PLUSMINUS_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plusmn html character entity reference model.
 *
 * Name: plusmn
 * Character: ±
 * Unicode code point: U+00b1 (177)
 * Description: plus-minus sign
 */
static wchar_t* PLUSMN_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusmn";
static int* PLUSMN_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pm html character entity reference model.
 *
 * Name: pm
 * Character: ±
 * Unicode code point: U+00b1 (177)
 * Description: plus-minus sign
 */
static wchar_t* PM_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pm";
static int* PM_PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sup2 html character entity reference model.
 *
 * Name: sup2
 * Character: ²
 * Unicode code point: U+00b2 (178)
 * Description: superscript two
 */
static wchar_t* SUP2_SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup2";
static int* SUP2_SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sup3 html character entity reference model.
 *
 * Name: sup3
 * Character: ³
 * Unicode code point: U+00b3 (179)
 * Description: superscript three
 */
static wchar_t* SUP3_SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup3";
static int* SUP3_SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DiacriticalAcute html character entity reference model.
 *
 * Name: DiacriticalAcute
 * Character: ´
 * Unicode code point: U+00b4 (180)
 * Description: acute accent
 */
static wchar_t* DIACRITICALACUTE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalAcute";
static int* DIACRITICALACUTE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acute html character entity reference model.
 *
 * Name: acute
 * Character: ´
 * Unicode code point: U+00b4 (180)
 * Description: acute accent
 */
static wchar_t* ACUTE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acute";
static int* ACUTE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The micro html character entity reference model.
 *
 * Name: micro
 * Character: µ
 * Unicode code point: U+00b5 (181)
 * Description: micro sign
 */
static wchar_t* MICRO_MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"micro";
static int* MICRO_MICRO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The para html character entity reference model.
 *
 * Name: para
 * Character: ¶
 * Unicode code point: U+00b6 (182)
 * Description: pilcrow sign
 */
static wchar_t* PARA_PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"para";
static int* PARA_PILCROW_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CenterDot html character entity reference model.
 *
 * Name: CenterDot
 * Character: ·
 * Unicode code point: U+00b7 (183)
 * Description: middle dot
 */
static wchar_t* CAMEL_CENTERDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CenterDot";
static int* CAMEL_CENTERDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The centerdot html character entity reference model.
 *
 * Name: centerdot
 * Character: ·
 * Unicode code point: U+00b7 (183)
 * Description: middle dot
 */
static wchar_t* SMALL_CENTERDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"centerdot";
static int* SMALL_CENTERDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The middot html character entity reference model.
 *
 * Name: middot
 * Character: ·
 * Unicode code point: U+00b7 (183)
 * Description: middle dot
 */
static wchar_t* MIDDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"middot";
static int* MIDDOT_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cedilla html character entity reference model.
 *
 * Name: Cedilla
 * Character: ¸
 * Unicode code point: U+00b8 (184)
 * Description: cedilla
 */
static wchar_t* CEDILLA_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cedilla";
static int* CEDILLA_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cedil html character entity reference model.
 *
 * Name: cedil
 * Character: ¸
 * Unicode code point: U+00b8 (184)
 * Description: cedilla
 */
static wchar_t* CEDIL_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cedil";
static int* CEDIL_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sup1 html character entity reference model.
 *
 * Name: sup1
 * Character: ¹
 * Unicode code point: U+00b9 (185)
 * Description: superscript one
 */
static wchar_t* SUP1_SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup1";
static int* SUP1_SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ordm html character entity reference model.
 *
 * Name: ordm
 * Character: º
 * Unicode code point: U+00ba (186)
 * Description: masculine ordinal indicator
 */
static wchar_t* ORDM_MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ordm";
static int* ORDM_MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The raquo html character entity reference model.
 *
 * Name: raquo
 * Character: »
 * Unicode code point: U+00bb (187)
 * Description: right-pointing double angle quotation mark
 */
static wchar_t* RAQUO_RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"raquo";
static int* RAQUO_RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac14 html character entity reference model.
 *
 * Name: frac14
 * Character: ¼
 * Unicode code point: U+00bc (188)
 * Description: vulgar fraction one quarter
 */
static wchar_t* FRAC14_VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac14";
static int* FRAC14_VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac12 html character entity reference model.
 *
 * Name: frac12
 * Character: ½
 * Unicode code point: U+00bd (189)
 * Description: vulgar fraction one half
 */
static wchar_t* FRAC12_VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac12";
static int* FRAC12_VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The half html character entity reference model.
 *
 * Name: half
 * Character: ½
 * Unicode code point: U+00bd (189)
 * Description: vulgar fraction one half
 */
static wchar_t* HALF_VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"half";
static int* HALF_VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac34 html character entity reference model.
 *
 * Name: frac34
 * Character: ¾
 * Unicode code point: U+00be (190)
 * Description: vulgar fraction three quarters
 */
static wchar_t* FRAC34_VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac34";
static int* FRAC34_VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iquest html character entity reference model.
 *
 * Name: iquest
 * Character: ¿
 * Unicode code point: U+00bf (191)
 * Description: inverted question mark
 */
static wchar_t* IQUEST_INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iquest";
static int* IQUEST_INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Agrave html character entity reference model.
 *
 * Name: Agrave
 * Character: À
 * Unicode code point: U+00c0 (192)
 * Description: latin capital letter a with grave
 */
static wchar_t* AGRAVE_LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Agrave";
static int* AGRAVE_LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Aacute html character entity reference model.
 *
 * Name: Aacute
 * Character: Á
 * Unicode code point: U+00c1 (193)
 * Description: latin capital letter a with acute
 */
static wchar_t* AACUTE_LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aacute";
static int* AACUTE_LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Acirc html character entity reference model.
 *
 * Name: Acirc
 * Character: Â
 * Unicode code point: U+00c2 (194)
 * Description: latin capital letter a with circumflex
 */
static wchar_t* ACIRC_LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Acirc";
static int* ACIRC_LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Atilde html character entity reference model.
 *
 * Name: Atilde
 * Character: Ã
 * Unicode code point: U+00c3 (195)
 * Description: latin capital letter a with tilde
 */
static wchar_t* ATILDE_LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Atilde";
static int* ATILDE_LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Auml html character entity reference model.
 *
 * Name: Auml
 * Character: Ä
 * Unicode code point: U+00c4 (196)
 * Description: latin capital letter a with diaeresis
 */
static wchar_t* AUML_LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Auml";
static int* AUML_LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Aring html character entity reference model.
 *
 * Name: Aring
 * Character: Å
 * Unicode code point: U+00c5 (197)
 * Description: latin capital letter a with ring above
 */
static wchar_t* ARING_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aring";
static int* ARING_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angst html character entity reference model.
 *
 * Name: angst
 * Character: Å
 * Unicode code point: U+00c5 (197)
 * Description: latin capital letter a with ring above
 */
static wchar_t* ANGST_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angst";
static int* ANGST_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The AElig html character entity reference model.
 *
 * Name: AElig
 * Character: Æ
 * Unicode code point: U+00c6 (198)
 * Description: latin capital letter ae
 */
static wchar_t* AELIG_LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"AElig";
static int* AELIG_LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ccedil html character entity reference model.
 *
 * Name: Ccedil
 * Character: Ç
 * Unicode code point: U+00c7 (199)
 * Description: latin capital letter c with cedilla
 */
static wchar_t* CCEDIL_LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccedil";
static int* CCEDIL_LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Egrave html character entity reference model.
 *
 * Name: Egrave
 * Character: È
 * Unicode code point: U+00c8 (200)
 * Description: latin capital letter e with grave
 */
static wchar_t* EGRAVE_LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Egrave";
static int* EGRAVE_LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Eacute html character entity reference model.
 *
 * Name: Eacute
 * Character: É
 * Unicode code point: U+00c9 (201)
 * Description: latin capital letter e with acute
 */
static wchar_t* EACUTE_LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eacute";
static int* EACUTE_LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ecirc html character entity reference model.
 *
 * Name: Ecirc
 * Character: Ê
 * Unicode code point: U+00ca (202)
 * Description: latin capital letter e with circumflex
 */
static wchar_t* ECIRC_LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecirc";
static int* ECIRC_LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Euml html character entity reference model.
 *
 * Name: Euml
 * Character: Ë
 * Unicode code point: U+00cb (203)
 * Description: latin capital letter e with diaeresis
 */
static wchar_t* EUML_LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Euml";
static int* EUML_LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Igrave html character entity reference model.
 *
 * Name: Igrave
 * Character: Ì
 * Unicode code point: U+00cc (204)
 * Description: latin capital letter i with grave
 */
static wchar_t* IGRAVE_LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Igrave";
static int* IGRAVE_LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iacute html character entity reference model.
 *
 * Name: Iacute
 * Character: Í
 * Unicode code point: U+00cd (205)
 * Description: latin capital letter i with acute
 */
static wchar_t* IACUTE_LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iacute";
static int* IACUTE_LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Icirc html character entity reference model.
 *
 * Name: Icirc
 * Character: Î
 * Unicode code point: U+00ce (206)
 * Description: latin capital letter i with circumflex
 */
static wchar_t* ICIRC_LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Icirc";
static int* ICIRC_LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iuml html character entity reference model.
 *
 * Name: Iuml
 * Character: Ï
 * Unicode code point: U+00cf (207)
 * Description: latin capital letter i with diaeresis
 */
static wchar_t* IUML_LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iuml";
static int* IUML_LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ETH html character entity reference model.
 *
 * Name: ETH
 * Character: Ð
 * Unicode code point: U+00d0 (208)
 * Description: latin capital letter eth
 */
static wchar_t* ETH_LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ETH";
static int* ETH_LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ntilde html character entity reference model.
 *
 * Name: Ntilde
 * Character: Ñ
 * Unicode code point: U+00d1 (209)
 * Description: latin capital letter n with tilde
 */
static wchar_t* NTILDE_LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ntilde";
static int* NTILDE_LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ograve html character entity reference model.
 *
 * Name: Ograve
 * Character: Ò
 * Unicode code point: U+00d2 (210)
 * Description: latin capital letter o with grave
 */
static wchar_t* OGRAVE_LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ograve";
static int* OGRAVE_LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Oacute html character entity reference model.
 *
 * Name: Oacute
 * Character: Ó
 * Unicode code point: U+00d3 (211)
 * Description: latin capital letter o with acute
 */
static wchar_t* OACUTE_LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oacute";
static int* OACUTE_LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ocirc html character entity reference model.
 *
 * Name: Ocirc
 * Character: Ô
 * Unicode code point: U+00d4 (212)
 * Description: latin capital letter o with circumflex
 */
static wchar_t* OCIRC_LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ocirc";
static int* OCIRC_LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Otilde html character entity reference model.
 *
 * Name: Otilde
 * Character: Õ
 * Unicode code point: U+00d5 (213)
 * Description: latin capital letter o with tilde
 */
static wchar_t* OTILDE_LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Otilde";
static int* OTILDE_LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ouml html character entity reference model.
 *
 * Name: Ouml
 * Character: Ö
 * Unicode code point: U+00d6 (214)
 * Description: latin capital letter o with diaeresis
 */
static wchar_t* OUML_LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ouml";
static int* OUML_LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The times html character entity reference model.
 *
 * Name: times
 * Character: ×
 * Unicode code point: U+00d7 (215)
 * Description: multiplication sign
 */
static wchar_t* TIMES_MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"times";
static int* TIMES_MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Oslash html character entity reference model.
 *
 * Name: Oslash
 * Character: Ø
 * Unicode code point: U+00d8 (216)
 * Description: latin capital letter o with stroke
 */
static wchar_t* OSLASH_LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oslash";
static int* OSLASH_LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ugrave html character entity reference model.
 *
 * Name: Ugrave
 * Character: Ù
 * Unicode code point: U+00d9 (217)
 * Description: latin capital letter u with grave
 */
static wchar_t* UGRAVE_LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ugrave";
static int* UGRAVE_LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uacute html character entity reference model.
 *
 * Name: Uacute
 * Character: Ú
 * Unicode code point: U+00da (218)
 * Description: latin capital letter u with acute
 */
static wchar_t* UACUTE_LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uacute";
static int* UACUTE_LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ucirc html character entity reference model.
 *
 * Name: Ucirc
 * Character: Û
 * Unicode code point: U+00db (219)
 * Description: latin capital letter u with circumflex
 */
static wchar_t* UCIRC_LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ucirc";
static int* UCIRC_LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uuml html character entity reference model.
 *
 * Name: Uuml
 * Character: Ü
 * Unicode code point: U+00dc (220)
 * Description: latin capital letter u with diaeresis
 */
static wchar_t* UUML_LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uuml";
static int* UUML_LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Yacute html character entity reference model.
 *
 * Name: Yacute
 * Character: Ý
 * Unicode code point: U+00dd (221)
 * Description: latin capital letter y with acute
 */
static wchar_t* YACUTE_LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yacute";
static int* YACUTE_LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The THORN html character entity reference model.
 *
 * Name: THORN
 * Character: Þ
 * Unicode code point: U+00de (222)
 * Description: latin capital letter thorn
 */
static wchar_t* THORN_LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"THORN";
static int* THORN_LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The szlig html character entity reference model.
 *
 * Name: szlig
 * Character: ß
 * Unicode code point: U+00df (223)
 * Description: latin small letter sharp s
 */
static wchar_t* SZLIG_LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"szlig";
static int* SZLIG_LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The agrave html character entity reference model.
 *
 * Name: agrave
 * Character: à
 * Unicode code point: U+00e0 (224)
 * Description: latin small letter a with grave
 */
static wchar_t* AGRAVE_LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"agrave";
static int* AGRAVE_LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aacute html character entity reference model.
 *
 * Name: aacute
 * Character: á
 * Unicode code point: U+00e1 (225)
 * Description: latin small letter a with acute
 */
static wchar_t* AACUTE_LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aacute";
static int* AACUTE_LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acirc html character entity reference model.
 *
 * Name: acirc
 * Character: â
 * Unicode code point: U+00e2 (226)
 * Description: latin small letter a with circumflex
 */
static wchar_t* ACIRC_LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acirc";
static int* ACIRC_LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The atilde html character entity reference model.
 *
 * Name: atilde
 * Character: ã
 * Unicode code point: U+00e3 (227)
 * Description: latin small letter a with tilde
 */
static wchar_t* ATILDE_LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"atilde";
static int* ATILDE_LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The auml html character entity reference model.
 *
 * Name: auml
 * Character: ä
 * Unicode code point: U+00e4 (228)
 * Description: latin small letter a with diaeresis
 */
static wchar_t* AUML_LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"auml";
static int* AUML_LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aring html character entity reference model.
 *
 * Name: aring
 * Character: å
 * Unicode code point: U+00e5 (229)
 * Description: latin small letter a with ring above
 */
static wchar_t* ARING_LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aring";
static int* ARING_LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aelig html character entity reference model.
 *
 * Name: aelig
 * Character: æ
 * Unicode code point: U+00e6 (230)
 * Description: latin small letter ae
 */
static wchar_t* AELIG_LATIN_SMALL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aelig";
static int* AELIG_LATIN_SMALL_LETTER_AE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccedil html character entity reference model.
 *
 * Name: ccedil
 * Character: ç
 * Unicode code point: U+00e7 (231)
 * Description: latin small letter c with cedilla
 */
static wchar_t* CCEDIL_LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccedil";
static int* CCEDIL_LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The egrave html character entity reference model.
 *
 * Name: egrave
 * Character: è
 * Unicode code point: U+00e8 (232)
 * Description: latin small letter e with grave
 */
static wchar_t* EGRAVE_LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egrave";
static int* EGRAVE_LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eacute html character entity reference model.
 *
 * Name: eacute
 * Character: é
 * Unicode code point: U+00e9 (233)
 * Description: latin small letter e with acute
 */
static wchar_t* EACUTE_LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eacute";
static int* EACUTE_LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ecirc html character entity reference model.
 *
 * Name: ecirc
 * Character: ê
 * Unicode code point: U+00ea (234)
 * Description: latin small letter e with circumflex
 */
static wchar_t* ECIRC_LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecirc";
static int* ECIRC_LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The euml html character entity reference model.
 *
 * Name: euml
 * Character: ë
 * Unicode code point: U+00eb (235)
 * Description: latin small letter e with diaeresis
 */
static wchar_t* EUML_LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euml";
static int* EUML_LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The igrave html character entity reference model.
 *
 * Name: igrave
 * Character: ì
 * Unicode code point: U+00ec (236)
 * Description: latin small letter i with grave
 */
static wchar_t* IGRAVE_LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"igrave";
static int* IGRAVE_LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iacute html character entity reference model.
 *
 * Name: iacute
 * Character: í
 * Unicode code point: U+00ed (237)
 * Description: latin small letter i with acute
 */
static wchar_t* IACUTE_LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iacute";
static int* IACUTE_LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The icirc html character entity reference model.
 *
 * Name: icirc
 * Character: î
 * Unicode code point: U+00ee (238)
 * Description: latin small letter i with circumflex
 */
static wchar_t* ICIRC_LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"icirc";
static int* ICIRC_LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iuml html character entity reference model.
 *
 * Name: iuml
 * Character: ï
 * Unicode code point: U+00ef (239)
 * Description: latin small letter i with diaeresis
 */
static wchar_t* IUML_LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iuml";
static int* IUML_LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eth html character entity reference model.
 *
 * Name: eth
 * Character: ð
 * Unicode code point: U+00f0 (240)
 * Description: latin small letter eth
 */
static wchar_t* ETH_LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eth";
static int* ETH_LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntilde html character entity reference model.
 *
 * Name: ntilde
 * Character: ñ
 * Unicode code point: U+00f1 (241)
 * Description: latin small letter n with tilde
 */
static wchar_t* NTILDE_LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntilde";
static int* NTILDE_LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ograve html character entity reference model.
 *
 * Name: ograve
 * Character: ò
 * Unicode code point: U+00f2 (242)
 * Description: latin small letter o with grave
 */
static wchar_t* OGRAVE_LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ograve";
static int* OGRAVE_LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oacute html character entity reference model.
 *
 * Name: oacute
 * Character: ó
 * Unicode code point: U+00f3 (243)
 * Description: latin small letter o with acute
 */
static wchar_t* OACUTE_LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oacute";
static int* OACUTE_LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ocirc html character entity reference model.
 *
 * Name: ocirc
 * Character: ô
 * Unicode code point: U+00f4 (244)
 * Description: latin small letter o with circumflex
 */
static wchar_t* OCIRC_LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocirc";
static int* OCIRC_LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The otilde html character entity reference model.
 *
 * Name: otilde
 * Character: õ
 * Unicode code point: U+00f5 (245)
 * Description: latin small letter o with tilde
 */
static wchar_t* OTILDE_LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otilde";
static int* OTILDE_LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ouml html character entity reference model.
 *
 * Name: ouml
 * Character: ö
 * Unicode code point: U+00f6 (246)
 * Description: latin small letter o with diaeresis
 */
static wchar_t* OUML_LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ouml";
static int* OUML_LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The div html character entity reference model.
 *
 * Name: div
 * Character: ÷
 * Unicode code point: U+00f7 (247)
 * Description: division sign
 */
static wchar_t* DIV_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"div";
static int* DIV_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The divide html character entity reference model.
 *
 * Name: divide
 * Character: ÷
 * Unicode code point: U+00f7 (247)
 * Description: division sign
 */
static wchar_t* DIVIDE_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"divide";
static int* DIVIDE_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oslash html character entity reference model.
 *
 * Name: oslash
 * Character: ø
 * Unicode code point: U+00f8 (248)
 * Description: latin small letter o with stroke
 */
static wchar_t* OSLASH_LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oslash";
static int* OSLASH_LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ugrave html character entity reference model.
 *
 * Name: ugrave
 * Character: ù
 * Unicode code point: U+00f9 (249)
 * Description: latin small letter u with grave
 */
static wchar_t* UGRAVE_LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ugrave";
static int* UGRAVE_LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uacute html character entity reference model.
 *
 * Name: uacute
 * Character: ú
 * Unicode code point: U+00fa (250)
 * Description: latin small letter u with acute
 */
static wchar_t* UACUTE_LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uacute";
static int* UACUTE_LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ucirc html character entity reference model.
 *
 * Name: ucirc
 * Character: û
 * Unicode code point: U+00fb (251)
 * Description: latin small letter u with circumflex
 */
static wchar_t* UCIRC_LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ucirc";
static int* UCIRC_LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uuml html character entity reference model.
 *
 * Name: uuml
 * Character: ü
 * Unicode code point: U+00fc (252)
 * Description: latin small letter u with diaeresis
 */
static wchar_t* UUML_LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uuml";
static int* UUML_LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yacute html character entity reference model.
 *
 * Name: yacute
 * Character: ý
 * Unicode code point: U+00fd (253)
 * Description: latin small letter y with acute
 */
static wchar_t* YACUTE_LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yacute";
static int* YACUTE_LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thorn html character entity reference model.
 *
 * Name: thorn
 * Character: þ
 * Unicode code point: U+00fe (254)
 * Description: latin small letter thorn
 */
static wchar_t* THORN_LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thorn";
static int* THORN_LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yuml html character entity reference model.
 *
 * Name: yuml
 * Character: ÿ
 * Unicode code point: U+00ff (255)
 * Description: latin small letter y with diaeresis
 */
static wchar_t* YUML_LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yuml";
static int* YUML_LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Amacr html character entity reference model.
 *
 * Name: Amacr
 * Character: Ā
 * Unicode code point: U+0100 (256)
 * Description: latin capital letter a with macron
 */
static wchar_t* AMACR_LATIN_CAPITAL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Amacr";
static int* AMACR_LATIN_CAPITAL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The amacr html character entity reference model.
 *
 * Name: amacr
 * Character: ā
 * Unicode code point: U+0101 (257)
 * Description: latin small letter a with macron
 */
static wchar_t* AMACR_LATIN_SMALL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amacr";
static int* AMACR_LATIN_SMALL_LETTER_A_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Abreve html character entity reference model.
 *
 * Name: Abreve
 * Character: Ă
 * Unicode code point: U+0102 (258)
 * Description: latin capital letter a with breve
 */
static wchar_t* ABREVE_LATIN_CAPITAL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Abreve";
static int* ABREVE_LATIN_CAPITAL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The abreve html character entity reference model.
 *
 * Name: abreve
 * Character: ă
 * Unicode code point: U+0103 (259)
 * Description: latin small letter a with breve
 */
static wchar_t* ABREVE_LATIN_SMALL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"abreve";
static int* ABREVE_LATIN_SMALL_LETTER_A_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Aogon html character entity reference model.
 *
 * Name: Aogon
 * Character: Ą
 * Unicode code point: U+0104 (260)
 * Description: latin capital letter a with ogonek
 */
static wchar_t* AOGON_LATIN_CAPITAL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aogon";
static int* AOGON_LATIN_CAPITAL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aogon html character entity reference model.
 *
 * Name: aogon
 * Character: ą
 * Unicode code point: U+0105 (261)
 * Description: latin small letter a with ogonek
 */
static wchar_t* AOGON_LATIN_SMALL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aogon";
static int* AOGON_LATIN_SMALL_LETTER_A_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cacute html character entity reference model.
 *
 * Name: Cacute
 * Character: Ć
 * Unicode code point: U+0106 (262)
 * Description: latin capital letter c with acute
 */
static wchar_t* CACUTE_LATIN_CAPITAL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cacute";
static int* CACUTE_LATIN_CAPITAL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cacute html character entity reference model.
 *
 * Name: cacute
 * Character: ć
 * Unicode code point: U+0107 (263)
 * Description: latin small letter c with acute
 */
static wchar_t* CACUTE_LATIN_SMALL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cacute";
static int* CACUTE_LATIN_SMALL_LETTER_C_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ccirc html character entity reference model.
 *
 * Name: Ccirc
 * Character: Ĉ
 * Unicode code point: U+0108 (264)
 * Description: latin capital letter c with circumflex
 */
static wchar_t* CCIRC_LATIN_CAPITAL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccirc";
static int* CCIRC_LATIN_CAPITAL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccirc html character entity reference model.
 *
 * Name: ccirc
 * Character: ĉ
 * Unicode code point: U+0109 (265)
 * Description: latin small letter c with circumflex
 */
static wchar_t* CCIRC_LATIN_SMALL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccirc";
static int* CCIRC_LATIN_SMALL_LETTER_C_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cdot html character entity reference model.
 *
 * Name: Cdot
 * Character: Ċ
 * Unicode code point: U+010a (266)
 * Description: latin capital letter c with dot above
 */
static wchar_t* CDOT_LATIN_CAPITAL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cdot";
static int* CDOT_LATIN_CAPITAL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cdot html character entity reference model.
 *
 * Name: cdot
 * Character: ċ
 * Unicode code point: U+010b (267)
 * Description: latin small letter c with dot above
 */
static wchar_t* CDOT_LATIN_SMALL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cdot";
static int* CDOT_LATIN_SMALL_LETTER_C_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ccaron html character entity reference model.
 *
 * Name: Ccaron
 * Character: Č
 * Unicode code point: U+010c (268)
 * Description: latin capital letter c with caron
 */
static wchar_t* CCARON_LATIN_CAPITAL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ccaron";
static int* CCARON_LATIN_CAPITAL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccaron html character entity reference model.
 *
 * Name: ccaron
 * Character: č
 * Unicode code point: U+010d (269)
 * Description: latin small letter c with caron
 */
static wchar_t* CCARON_LATIN_SMALL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccaron";
static int* CCARON_LATIN_SMALL_LETTER_C_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dcaron html character entity reference model.
 *
 * Name: Dcaron
 * Character: Ď
 * Unicode code point: U+010e (270)
 * Description: latin capital letter d with caron
 */
static wchar_t* DCARON_LATIN_CAPITAL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dcaron";
static int* DCARON_LATIN_CAPITAL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dcaron html character entity reference model.
 *
 * Name: dcaron
 * Character: ď
 * Unicode code point: U+010f (271)
 * Description: latin small letter d with caron
 */
static wchar_t* DCARON_LATIN_SMALL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dcaron";
static int* DCARON_LATIN_SMALL_LETTER_D_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dstrok html character entity reference model.
 *
 * Name: Dstrok
 * Character: Đ
 * Unicode code point: U+0110 (272)
 * Description: latin capital letter d with stroke
 */
static wchar_t* DSTROK_LATIN_CAPITAL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dstrok";
static int* DSTROK_LATIN_CAPITAL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dstrok html character entity reference model.
 *
 * Name: dstrok
 * Character: đ
 * Unicode code point: U+0111 (273)
 * Description: latin small letter d with stroke
 */
static wchar_t* DSTROK_LATIN_SMALL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dstrok";
static int* DSTROK_LATIN_SMALL_LETTER_D_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Emacr html character entity reference model.
 *
 * Name: Emacr
 * Character: Ē
 * Unicode code point: U+0112 (274)
 * Description: latin capital letter e with macron
 */
static wchar_t* EMACR_LATIN_CAPITAL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Emacr";
static int* EMACR_LATIN_CAPITAL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emacr html character entity reference model.
 *
 * Name: emacr
 * Character: ē
 * Unicode code point: U+0113 (275)
 * Description: latin small letter e with macron
 */
static wchar_t* EMACR_LATIN_SMALL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emacr";
static int* EMACR_LATIN_SMALL_LETTER_E_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Edot html character entity reference model.
 *
 * Name: Edot
 * Character: Ė
 * Unicode code point: U+0116 (278)
 * Description: latin capital letter e with dot above
 */
static wchar_t* EDOT_LATIN_CAPITAL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Edot";
static int* EDOT_LATIN_CAPITAL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The edot html character entity reference model.
 *
 * Name: edot
 * Character: ė
 * Unicode code point: U+0117 (279)
 * Description: latin small letter e with dot above
 */
static wchar_t* EDOT_LATIN_SMALL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"edot";
static int* EDOT_LATIN_SMALL_LETTER_E_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Eogon html character entity reference model.
 *
 * Name: Eogon
 * Character: Ę
 * Unicode code point: U+0118 (280)
 * Description: latin capital letter e with ogonek
 */
static wchar_t* EOGON_LATIN_CAPITAL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eogon";
static int* EOGON_LATIN_CAPITAL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eogon html character entity reference model.
 *
 * Name: eogon
 * Character: ę
 * Unicode code point: U+0119 (281)
 * Description: latin small letter e with ogonek
 */
static wchar_t* EOGON_LATIN_SMALL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eogon";
static int* EOGON_LATIN_SMALL_LETTER_E_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ecaron html character entity reference model.
 *
 * Name: Ecaron
 * Character: Ě
 * Unicode code point: U+011a (282)
 * Description: latin capital letter e with caron
 */
static wchar_t* ECARON_LATIN_CAPITAL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecaron";
static int* ECARON_LATIN_CAPITAL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ecaron html character entity reference model.
 *
 * Name: ecaron
 * Character: ě
 * Unicode code point: U+011b (283)
 * Description: latin small letter e with caron
 */
static wchar_t* ECARON_LATIN_SMALL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecaron";
static int* ECARON_LATIN_SMALL_LETTER_E_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gcirc html character entity reference model.
 *
 * Name: Gcirc
 * Character: Ĝ
 * Unicode code point: U+011c (284)
 * Description: latin capital letter g with circumflex
 */
static wchar_t* GCIRC_LATIN_CAPITAL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcirc";
static int* GCIRC_LATIN_CAPITAL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gcirc html character entity reference model.
 *
 * Name: gcirc
 * Character: ĝ
 * Unicode code point: U+011d (285)
 * Description: latin small letter g with circumflex
 */
static wchar_t* GCIRC_LATIN_SMALL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gcirc";
static int* GCIRC_LATIN_SMALL_LETTER_G_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gbreve html character entity reference model.
 *
 * Name: Gbreve
 * Character: Ğ
 * Unicode code point: U+011e (286)
 * Description: latin capital letter g with breve
 */
static wchar_t* GBREVE_LATIN_CAPITAL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gbreve";
static int* GBREVE_LATIN_CAPITAL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gbreve html character entity reference model.
 *
 * Name: gbreve
 * Character: ğ
 * Unicode code point: U+011f (287)
 * Description: latin small letter g with breve
 */
static wchar_t* GBREVE_LATIN_SMALL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gbreve";
static int* GBREVE_LATIN_SMALL_LETTER_G_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gdot html character entity reference model.
 *
 * Name: Gdot
 * Character: Ġ
 * Unicode code point: U+0120 (288)
 * Description: latin capital letter g with dot above
 */
static wchar_t* GDOT_LATIN_CAPITAL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gdot";
static int* GDOT_LATIN_CAPITAL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gdot html character entity reference model.
 *
 * Name: gdot
 * Character: ġ
 * Unicode code point: U+0121 (289)
 * Description: latin small letter g with dot above
 */
static wchar_t* GDOT_LATIN_SMALL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gdot";
static int* GDOT_LATIN_SMALL_LETTER_G_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gcedil html character entity reference model.
 *
 * Name: Gcedil
 * Character: Ģ
 * Unicode code point: U+0122 (290)
 * Description: latin capital letter g with cedilla
 */
static wchar_t* GCEDIL_LATIN_CAPITAL_LETTER_G_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcedil";
static int* GCEDIL_LATIN_CAPITAL_LETTER_G_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hcirc html character entity reference model.
 *
 * Name: Hcirc
 * Character: Ĥ
 * Unicode code point: U+0124 (292)
 * Description: latin capital letter h with circumflex
 */
static wchar_t* HCIRC_LATIN_CAPITAL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hcirc";
static int* HCIRC_LATIN_CAPITAL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hcirc html character entity reference model.
 *
 * Name: hcirc
 * Character: ĥ
 * Unicode code point: U+0125 (293)
 * Description: latin small letter h with circumflex
 */
static wchar_t* HCIRC_LATIN_SMALL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hcirc";
static int* HCIRC_LATIN_SMALL_LETTER_H_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hstrok html character entity reference model.
 *
 * Name: Hstrok
 * Character: Ħ
 * Unicode code point: U+0126 (294)
 * Description: latin capital letter h with stroke
 */
static wchar_t* HSTROK_LATIN_CAPITAL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hstrok";
static int* HSTROK_LATIN_CAPITAL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hstrok html character entity reference model.
 *
 * Name: hstrok
 * Character: ħ
 * Unicode code point: U+0127 (295)
 * Description: latin small letter h with stroke
 */
static wchar_t* HSTROK_LATIN_SMALL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hstrok";
static int* HSTROK_LATIN_SMALL_LETTER_H_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Itilde html character entity reference model.
 *
 * Name: Itilde
 * Character: Ĩ
 * Unicode code point: U+0128 (296)
 * Description: latin capital letter i with tilde
 */
static wchar_t* ITILDE_LATIN_CAPITAL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Itilde";
static int* ITILDE_LATIN_CAPITAL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The itilde html character entity reference model.
 *
 * Name: itilde
 * Character: ĩ
 * Unicode code point: U+0129 (297)
 * Description: latin small letter i with tilde
 */
static wchar_t* ITILDE_LATIN_SMALL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"itilde";
static int* ITILDE_LATIN_SMALL_LETTER_I_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Imacr html character entity reference model.
 *
 * Name: Imacr
 * Character: Ī
 * Unicode code point: U+012a (298)
 * Description: latin capital letter i with macron
 */
static wchar_t* IMACR_LATIN_CAPITAL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Imacr";
static int* IMACR_LATIN_CAPITAL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imacr html character entity reference model.
 *
 * Name: imacr
 * Character: ī
 * Unicode code point: U+012b (299)
 * Description: latin small letter i with macron
 */
static wchar_t* IMACR_LATIN_SMALL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imacr";
static int* IMACR_LATIN_SMALL_LETTER_I_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iogon html character entity reference model.
 *
 * Name: Iogon
 * Character: Į
 * Unicode code point: U+012e (302)
 * Description: latin capital letter i with ogonek
 */
static wchar_t* IOGON_LATIN_CAPITAL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iogon";
static int* IOGON_LATIN_CAPITAL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iogon html character entity reference model.
 *
 * Name: iogon
 * Character: į
 * Unicode code point: U+012f (303)
 * Description: latin small letter i with ogonek
 */
static wchar_t* IOGON_LATIN_SMALL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iogon";
static int* IOGON_LATIN_SMALL_LETTER_I_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Idot html character entity reference model.
 *
 * Name: Idot
 * Character: İ
 * Unicode code point: U+0130 (304)
 * Description: latin capital letter i with dot above
 */
static wchar_t* IDOT_LATIN_CAPITAL_LETTER_I_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Idot";
static int* IDOT_LATIN_CAPITAL_LETTER_I_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imath html character entity reference model.
 *
 * Name: imath
 * Character: ı
 * Unicode code point: U+0131 (305)
 * Description: latin small letter dotless i
 */
static wchar_t* IMATH_LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imath";
static int* IMATH_LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inodot html character entity reference model.
 *
 * Name: inodot
 * Character: ı
 * Unicode code point: U+0131 (305)
 * Description: latin small letter dotless i
 */
static wchar_t* INODOT_LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"inodot";
static int* INODOT_LATIN_SMALL_LETTER_DOTLESS_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The IJlig html character entity reference model.
 *
 * Name: IJlig
 * Character: Ĳ
 * Unicode code point: U+0132 (306)
 * Description: latin capital ligature ij
 */
static wchar_t* IJLIG_LATIN_CAPITAL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IJlig";
static int* IJLIG_LATIN_CAPITAL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ijlig html character entity reference model.
 *
 * Name: ijlig
 * Character: ĳ
 * Unicode code point: U+0133 (307)
 * Description: latin small ligature ij
 */
static wchar_t* IJLIG_LATIN_SMALL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ijlig";
static int* IJLIG_LATIN_SMALL_LIGATURE_IJ_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jcirc html character entity reference model.
 *
 * Name: Jcirc
 * Character: Ĵ
 * Unicode code point: U+0134 (308)
 * Description: latin capital letter j with circumflex
 */
static wchar_t* JCIRC_LATIN_CAPITAL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jcirc";
static int* JCIRC_LATIN_CAPITAL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jcirc html character entity reference model.
 *
 * Name: jcirc
 * Character: ĵ
 * Unicode code point: U+0135 (309)
 * Description: latin small letter j with circumflex
 */
static wchar_t* JCIRC_LATIN_SMALL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jcirc";
static int* JCIRC_LATIN_SMALL_LETTER_J_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kcedil html character entity reference model.
 *
 * Name: Kcedil
 * Character: Ķ
 * Unicode code point: U+0136 (310)
 * Description: latin capital letter k with cedilla
 */
static wchar_t* KCEDIL_LATIN_CAPITAL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kcedil";
static int* KCEDIL_LATIN_CAPITAL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kcedil html character entity reference model.
 *
 * Name: kcedil
 * Character: ķ
 * Unicode code point: U+0137 (311)
 * Description: latin small letter k with cedilla
 */
static wchar_t* KCEDIL_LATIN_SMALL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kcedil";
static int* KCEDIL_LATIN_SMALL_LETTER_K_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kgreen html character entity reference model.
 *
 * Name: kgreen
 * Character: ĸ
 * Unicode code point: U+0138 (312)
 * Description: latin small letter kra
 */
static wchar_t* KGREEN_LATIN_SMALL_LETTER_KRA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kgreen";
static int* KGREEN_LATIN_SMALL_LETTER_KRA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lacute html character entity reference model.
 *
 * Name: Lacute
 * Character: Ĺ
 * Unicode code point: U+0139 (313)
 * Description: latin capital letter l with acute
 */
static wchar_t* LACUTE_LATIN_CAPITAL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lacute";
static int* LACUTE_LATIN_CAPITAL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lacute html character entity reference model.
 *
 * Name: lacute
 * Character: ĺ
 * Unicode code point: U+013a (314)
 * Description: latin small letter l with acute
 */
static wchar_t* LACUTE_LATIN_SMALL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lacute";
static int* LACUTE_LATIN_SMALL_LETTER_L_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lcedil html character entity reference model.
 *
 * Name: Lcedil
 * Character: Ļ
 * Unicode code point: U+013b (315)
 * Description: latin capital letter l with cedilla
 */
static wchar_t* LCEDIL_LATIN_CAPITAL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcedil";
static int* LCEDIL_LATIN_CAPITAL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lcedil html character entity reference model.
 *
 * Name: lcedil
 * Character: ļ
 * Unicode code point: U+013c (316)
 * Description: latin small letter l with cedilla
 */
static wchar_t* LCEDIL_LATIN_SMALL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcedil";
static int* LCEDIL_LATIN_SMALL_LETTER_L_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lcaron html character entity reference model.
 *
 * Name: Lcaron
 * Character: Ľ
 * Unicode code point: U+013d (317)
 * Description: latin capital letter l with caron
 */
static wchar_t* LCARON_LATIN_CAPITAL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcaron";
static int* LCARON_LATIN_CAPITAL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lcaron html character entity reference model.
 *
 * Name: lcaron
 * Character: ľ
 * Unicode code point: U+013e (318)
 * Description: latin small letter l with caron
 */
static wchar_t* LCARON_LATIN_SMALL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcaron";
static int* LCARON_LATIN_SMALL_LETTER_L_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lmidot html character entity reference model.
 *
 * Name: Lmidot
 * Character: Ŀ
 * Unicode code point: U+013f (319)
 * Description: latin capital letter l with middle dot
 */
static wchar_t* LMIDOT_LATIN_CAPITAL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lmidot";
static int* LMIDOT_LATIN_CAPITAL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lmidot html character entity reference model.
 *
 * Name: lmidot
 * Character: ŀ
 * Unicode code point: U+0140 (320)
 * Description: latin small letter l with middle dot
 */
static wchar_t* LMIDOT_LATIN_SMALL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lmidot";
static int* LMIDOT_LATIN_SMALL_LETTER_L_WITH_MIDDLE_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lstrok html character entity reference model.
 *
 * Name: Lstrok
 * Character: Ł
 * Unicode code point: U+0141 (321)
 * Description: latin capital letter l with stroke
 */
static wchar_t* LSTROK_LATIN_CAPITAL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lstrok";
static int* LSTROK_LATIN_CAPITAL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lstrok html character entity reference model.
 *
 * Name: lstrok
 * Character: ł
 * Unicode code point: U+0142 (322)
 * Description: latin small letter l with stroke
 */
static wchar_t* LSTROK_LATIN_SMALL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lstrok";
static int* LSTROK_LATIN_SMALL_LETTER_L_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Nacute html character entity reference model.
 *
 * Name: Nacute
 * Character: Ń
 * Unicode code point: U+0143 (323)
 * Description: latin capital letter n with acute
 */
static wchar_t* NACUTE_LATIN_CAPITAL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nacute";
static int* NACUTE_LATIN_CAPITAL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nacute html character entity reference model.
 *
 * Name: nacute
 * Character: ń
 * Unicode code point: U+0144 (324)
 * Description: latin small letter n with acute
 */
static wchar_t* NACUTE_LATIN_SMALL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nacute";
static int* NACUTE_LATIN_SMALL_LETTER_N_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ncedil html character entity reference model.
 *
 * Name: Ncedil
 * Character: Ņ
 * Unicode code point: U+0145 (325)
 * Description: latin capital letter n with cedilla
 */
static wchar_t* NCEDIL_LATIN_CAPITAL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncedil";
static int* NCEDIL_LATIN_CAPITAL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncedil html character entity reference model.
 *
 * Name: ncedil
 * Character: ņ
 * Unicode code point: U+0146 (326)
 * Description: latin small letter n with cedilla
 */
static wchar_t* NCEDIL_LATIN_SMALL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncedil";
static int* NCEDIL_LATIN_SMALL_LETTER_N_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ncaron html character entity reference model.
 *
 * Name: Ncaron
 * Character: Ň
 * Unicode code point: U+0147 (327)
 * Description: latin capital letter n with caron
 */
static wchar_t* NCARON_LATIN_CAPITAL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncaron";
static int* NCARON_LATIN_CAPITAL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncaron html character entity reference model.
 *
 * Name: ncaron
 * Character: ň
 * Unicode code point: U+0148 (328)
 * Description: latin small letter n with caron
 */
static wchar_t* NCARON_LATIN_SMALL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncaron";
static int* NCARON_LATIN_SMALL_LETTER_N_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The napos html character entity reference model.
 *
 * Name: napos
 * Character: ŉ
 * Unicode code point: U+0149 (329)
 * Description: latin small letter n preceded by apostrophe
 */
static wchar_t* NAPOS_LATIN_SMALL_LETTER_N_PRECEDED_BY_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napos";
static int* NAPOS_LATIN_SMALL_LETTER_N_PRECEDED_BY_APOSTROPHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ENG html character entity reference model.
 *
 * Name: ENG
 * Character: Ŋ
 * Unicode code point: U+014a (330)
 * Description: latin capital letter eng
 */
static wchar_t* ENG_LATIN_CAPITAL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ENG";
static int* ENG_LATIN_CAPITAL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eng html character entity reference model.
 *
 * Name: eng
 * Character: ŋ
 * Unicode code point: U+014b (331)
 * Description: latin small letter eng
 */
static wchar_t* ENG_LATIN_SMALL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eng";
static int* ENG_LATIN_SMALL_LETTER_ENG_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Omacr html character entity reference model.
 *
 * Name: Omacr
 * Character: Ō
 * Unicode code point: U+014c (332)
 * Description: latin capital letter o with macron
 */
static wchar_t* OMACR_LATIN_CAPITAL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omacr";
static int* OMACR_LATIN_CAPITAL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The omacr html character entity reference model.
 *
 * Name: omacr
 * Character: ō
 * Unicode code point: U+014d (333)
 * Description: latin small letter o with macron
 */
static wchar_t* OMACR_LATIN_SMALL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omacr";
static int* OMACR_LATIN_SMALL_LETTER_O_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Odblac html character entity reference model.
 *
 * Name: Odblac
 * Character: Ő
 * Unicode code point: U+0150 (336)
 * Description: latin capital letter o with double acute
 */
static wchar_t* ODBLAC_LATIN_CAPITAL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Odblac";
static int* ODBLAC_LATIN_CAPITAL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The odblac html character entity reference model.
 *
 * Name: odblac
 * Character: ő
 * Unicode code point: U+0151 (337)
 * Description: latin small letter o with double acute
 */
static wchar_t* ODBLAC_LATIN_SMALL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odblac";
static int* ODBLAC_LATIN_SMALL_LETTER_O_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OElig html character entity reference model.
 *
 * Name: OElig
 * Character: Œ
 * Unicode code point: U+0152 (338)
 * Description: latin capital ligature oe
 */
static wchar_t* OELIG_LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OElig";
static int* OELIG_LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oelig html character entity reference model.
 *
 * Name: oelig
 * Character: œ
 * Unicode code point: U+0153 (339)
 * Description: latin small ligature oe
 */
static wchar_t* OELIG_LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oelig";
static int* OELIG_LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Racute html character entity reference model.
 *
 * Name: Racute
 * Character: Ŕ
 * Unicode code point: U+0154 (340)
 * Description: latin capital letter r with acute
 */
static wchar_t* RACUTE_LATIN_CAPITAL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Racute";
static int* RACUTE_LATIN_CAPITAL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The racute html character entity reference model.
 *
 * Name: racute
 * Character: ŕ
 * Unicode code point: U+0155 (341)
 * Description: latin small letter r with acute
 */
static wchar_t* RACUTE_LATIN_SMALL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"racute";
static int* RACUTE_LATIN_SMALL_LETTER_R_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rcedil html character entity reference model.
 *
 * Name: Rcedil
 * Character: Ŗ
 * Unicode code point: U+0156 (342)
 * Description: latin capital letter r with cedilla
 */
static wchar_t* RCEDIL_LATIN_CAPITAL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcedil";
static int* RCEDIL_LATIN_CAPITAL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rcedil html character entity reference model.
 *
 * Name: rcedil
 * Character: ŗ
 * Unicode code point: U+0157 (343)
 * Description: latin small letter r with cedilla
 */
static wchar_t* RCEDIL_LATIN_SMALL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcedil";
static int* RCEDIL_LATIN_SMALL_LETTER_R_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rcaron html character entity reference model.
 *
 * Name: Rcaron
 * Character: Ř
 * Unicode code point: U+0158 (344)
 * Description: latin capital letter r with caron
 */
static wchar_t* RCARON_LATIN_CAPITAL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcaron";
static int* RCARON_LATIN_CAPITAL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rcaron html character entity reference model.
 *
 * Name: rcaron
 * Character: ř
 * Unicode code point: U+0159 (345)
 * Description: latin small letter r with caron
 */
static wchar_t* RCARON_LATIN_SMALL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcaron";
static int* RCARON_LATIN_SMALL_LETTER_R_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sacute html character entity reference model.
 *
 * Name: Sacute
 * Character: Ś
 * Unicode code point: U+015a (346)
 * Description: latin capital letter s with acute
 */
static wchar_t* SACUTE_LATIN_CAPITAL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sacute";
static int* SACUTE_LATIN_CAPITAL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sacute html character entity reference model.
 *
 * Name: sacute
 * Character: ś
 * Unicode code point: U+015b (347)
 * Description: latin small letter s with acute
 */
static wchar_t* SACUTE_LATIN_SMALL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sacute";
static int* SACUTE_LATIN_SMALL_LETTER_S_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Scirc html character entity reference model.
 *
 * Name: Scirc
 * Character: Ŝ
 * Unicode code point: U+015c (348)
 * Description: latin capital letter s with circumflex
 */
static wchar_t* SCIRC_LATIN_CAPITAL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scirc";
static int* SCIRC_LATIN_CAPITAL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scirc html character entity reference model.
 *
 * Name: scirc
 * Character: ŝ
 * Unicode code point: U+015d (349)
 * Description: latin small letter s with circumflex
 */
static wchar_t* SCIRC_LATIN_SMALL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scirc";
static int* SCIRC_LATIN_SMALL_LETTER_S_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Scedil html character entity reference model.
 *
 * Name: Scedil
 * Character: Ş
 * Unicode code point: U+015e (350)
 * Description: latin capital letter s with cedilla
 */
static wchar_t* SCEDIL_LATIN_CAPITAL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scedil";
static int* SCEDIL_LATIN_CAPITAL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scedil html character entity reference model.
 *
 * Name: scedil
 * Character: ş
 * Unicode code point: U+015f (351)
 * Description: latin small letter s with cedilla
 */
static wchar_t* SCEDIL_LATIN_SMALL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scedil";
static int* SCEDIL_LATIN_SMALL_LETTER_S_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Scaron html character entity reference model.
 *
 * Name: Scaron
 * Character: Š
 * Unicode code point: U+0160 (352)
 * Description: latin capital letter s with caron
 */
static wchar_t* SCARON_LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scaron";
static int* SCARON_LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scaron html character entity reference model.
 *
 * Name: scaron
 * Character: š
 * Unicode code point: U+0161 (353)
 * Description: latin small letter s with caron
 */
static wchar_t* SCARON_LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scaron";
static int* SCARON_LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tcedil html character entity reference model.
 *
 * Name: Tcedil
 * Character: Ţ
 * Unicode code point: U+0162 (354)
 * Description: latin capital letter t with cedilla
 */
static wchar_t* TCEDIL_LATIN_CAPITAL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcedil";
static int* TCEDIL_LATIN_CAPITAL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tcedil html character entity reference model.
 *
 * Name: tcedil
 * Character: ţ
 * Unicode code point: U+0163 (355)
 * Description: latin small letter t with cedilla
 */
static wchar_t* TCEDIL_LATIN_SMALL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcedil";
static int* TCEDIL_LATIN_SMALL_LETTER_T_WITH_CEDILLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tcaron html character entity reference model.
 *
 * Name: Tcaron
 * Character: Ť
 * Unicode code point: U+0164 (356)
 * Description: latin capital letter t with caron
 */
static wchar_t* TCARON_LATIN_CAPITAL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcaron";
static int* TCARON_LATIN_CAPITAL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tcaron html character entity reference model.
 *
 * Name: tcaron
 * Character: ť
 * Unicode code point: U+0165 (357)
 * Description: latin small letter t with caron
 */
static wchar_t* TCARON_LATIN_SMALL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcaron";
static int* TCARON_LATIN_SMALL_LETTER_T_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tstrok html character entity reference model.
 *
 * Name: Tstrok
 * Character: Ŧ
 * Unicode code point: U+0166 (358)
 * Description: latin capital letter t with stroke
 */
static wchar_t* TSTROK_LATIN_CAPITAL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tstrok";
static int* TSTROK_LATIN_CAPITAL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tstrok html character entity reference model.
 *
 * Name: tstrok
 * Character: ŧ
 * Unicode code point: U+0167 (359)
 * Description: latin small letter t with stroke
 */
static wchar_t* TSTROK_LATIN_SMALL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tstrok";
static int* TSTROK_LATIN_SMALL_LETTER_T_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Utilde html character entity reference model.
 *
 * Name: Utilde
 * Character: Ũ
 * Unicode code point: U+0168 (360)
 * Description: latin capital letter u with tilde
 */
static wchar_t* UTILDE_LATIN_CAPITAL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Utilde";
static int* UTILDE_LATIN_CAPITAL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The utilde html character entity reference model.
 *
 * Name: utilde
 * Character: ũ
 * Unicode code point: U+0169 (361)
 * Description: latin small letter u with tilde
 */
static wchar_t* UTILDE_LATIN_SMALL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utilde";
static int* UTILDE_LATIN_SMALL_LETTER_U_WITH_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Umacr html character entity reference model.
 *
 * Name: Umacr
 * Character: Ū
 * Unicode code point: U+016a (362)
 * Description: latin capital letter u with macron
 */
static wchar_t* UMACR_LATIN_CAPITAL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Umacr";
static int* UMACR_LATIN_CAPITAL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The umacr html character entity reference model.
 *
 * Name: umacr
 * Character: ū
 * Unicode code point: U+016b (363)
 * Description: latin small letter u with macron
 */
static wchar_t* UMACR_LATIN_SMALL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"umacr";
static int* UMACR_LATIN_SMALL_LETTER_U_WITH_MACRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ubreve html character entity reference model.
 *
 * Name: Ubreve
 * Character: Ŭ
 * Unicode code point: U+016c (364)
 * Description: latin capital letter u with breve
 */
static wchar_t* UBREVE_LATIN_CAPITAL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ubreve";
static int* UBREVE_LATIN_CAPITAL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ubreve html character entity reference model.
 *
 * Name: ubreve
 * Character: ŭ
 * Unicode code point: U+016d (365)
 * Description: latin small letter u with breve
 */
static wchar_t* UBREVE_LATIN_SMALL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ubreve";
static int* UBREVE_LATIN_SMALL_LETTER_U_WITH_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uring html character entity reference model.
 *
 * Name: Uring
 * Character: Ů
 * Unicode code point: U+016e (366)
 * Description: latin capital letter u with ring above
 */
static wchar_t* URING_LATIN_CAPITAL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uring";
static int* URING_LATIN_CAPITAL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uring html character entity reference model.
 *
 * Name: uring
 * Character: ů
 * Unicode code point: U+016f (367)
 * Description: latin small letter u with ring above
 */
static wchar_t* URING_LATIN_SMALL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uring";
static int* URING_LATIN_SMALL_LETTER_U_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Udblac html character entity reference model.
 *
 * Name: Udblac
 * Character: Ű
 * Unicode code point: U+0170 (368)
 * Description: latin capital letter u with double acute
 */
static wchar_t* UDBLAC_LATIN_CAPITAL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Udblac";
static int* UDBLAC_LATIN_CAPITAL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udblac html character entity reference model.
 *
 * Name: udblac
 * Character: ű
 * Unicode code point: U+0171 (369)
 * Description: latin small letter u with double acute
 */
static wchar_t* UDBLAC_LATIN_SMALL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udblac";
static int* UDBLAC_LATIN_SMALL_LETTER_U_WITH_DOUBLE_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uogon html character entity reference model.
 *
 * Name: Uogon
 * Character: Ų
 * Unicode code point: U+0172 (370)
 * Description: latin capital letter u with ogonek
 */
static wchar_t* UOGON_LATIN_CAPITAL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uogon";
static int* UOGON_LATIN_CAPITAL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uogon html character entity reference model.
 *
 * Name: uogon
 * Character: ų
 * Unicode code point: U+0173 (371)
 * Description: latin small letter u with ogonek
 */
static wchar_t* UOGON_LATIN_SMALL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uogon";
static int* UOGON_LATIN_SMALL_LETTER_U_WITH_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Wcirc html character entity reference model.
 *
 * Name: Wcirc
 * Character: Ŵ
 * Unicode code point: U+0174 (372)
 * Description: latin capital letter w with circumflex
 */
static wchar_t* WCIRC_LATIN_CAPITAL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wcirc";
static int* WCIRC_LATIN_CAPITAL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wcirc html character entity reference model.
 *
 * Name: wcirc
 * Character: ŵ
 * Unicode code point: U+0175 (373)
 * Description: latin small letter w with circumflex
 */
static wchar_t* WCIRC_LATIN_SMALL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wcirc";
static int* WCIRC_LATIN_SMALL_LETTER_W_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ycirc html character entity reference model.
 *
 * Name: Ycirc
 * Character: Ŷ
 * Unicode code point: U+0176 (374)
 * Description: latin capital letter y with circumflex
 */
static wchar_t* YCIRC_LATIN_CAPITAL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ycirc";
static int* YCIRC_LATIN_CAPITAL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ycirc html character entity reference model.
 *
 * Name: ycirc
 * Character: ŷ
 * Unicode code point: U+0177 (375)
 * Description: latin small letter y with circumflex
 */
static wchar_t* YCIRC_LATIN_SMALL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ycirc";
static int* YCIRC_LATIN_SMALL_LETTER_Y_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Yuml html character entity reference model.
 *
 * Name: Yuml
 * Character: Ÿ
 * Unicode code point: U+0178 (376)
 * Description: latin capital letter y with diaeresis
 */
static wchar_t* YUML_LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yuml";
static int* YUML_LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zacute html character entity reference model.
 *
 * Name: Zacute
 * Character: Ź
 * Unicode code point: U+0179 (377)
 * Description: latin capital letter z with acute
 */
static wchar_t* ZACUTE_LATIN_CAPITAL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zacute";
static int* ZACUTE_LATIN_CAPITAL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zacute html character entity reference model.
 *
 * Name: zacute
 * Character: ź
 * Unicode code point: U+017a (378)
 * Description: latin small letter z with acute
 */
static wchar_t* ZACUTE_LATIN_SMALL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zacute";
static int* ZACUTE_LATIN_SMALL_LETTER_Z_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zdot html character entity reference model.
 *
 * Name: Zdot
 * Character: Ż
 * Unicode code point: U+017b (379)
 * Description: latin capital letter z with dot above
 */
static wchar_t* ZDOT_LATIN_CAPITAL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zdot";
static int* ZDOT_LATIN_CAPITAL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zdot html character entity reference model.
 *
 * Name: zdot
 * Character: ż
 * Unicode code point: U+017c (380)
 * Description: latin small letter z with dot above
 */
static wchar_t* ZDOT_LATIN_SMALL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zdot";
static int* ZDOT_LATIN_SMALL_LETTER_Z_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zcaron html character entity reference model.
 *
 * Name: Zcaron
 * Character: Ž
 * Unicode code point: U+017d (381)
 * Description: latin capital letter z with caron
 */
static wchar_t* ZCARON_LATIN_CAPITAL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zcaron";
static int* ZCARON_LATIN_CAPITAL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zcaron html character entity reference model.
 *
 * Name: zcaron
 * Character: ž
 * Unicode code point: U+017e (382)
 * Description: latin small letter z with caron
 */
static wchar_t* ZCARON_LATIN_SMALL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zcaron";
static int* ZCARON_LATIN_SMALL_LETTER_Z_WITH_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fnof html character entity reference model.
 *
 * Name: fnof
 * Character: ƒ
 * Unicode code point: U+0192 (402)
 * Description: latin small letter f with hook
 */
static wchar_t* FNOF_LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fnof";
static int* FNOF_LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imped html character entity reference model.
 *
 * Name: imped
 * Character: Ƶ
 * Unicode code point: U+01b5 (437)
 * Description: latin capital letter z with stroke
 */
static wchar_t* IMPED_LATIN_CAPITAL_LETTER_Z_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imped";
static int* IMPED_LATIN_CAPITAL_LETTER_Z_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gacute html character entity reference model.
 *
 * Name: gacute
 * Character: ǵ
 * Unicode code point: U+01f5 (501)
 * Description: latin small letter g with acute
 */
static wchar_t* GACUTE_LATIN_SMALL_LETTER_G_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gacute";
static int* GACUTE_LATIN_SMALL_LETTER_G_WITH_ACUTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jmath html character entity reference model.
 *
 * Name: jmath
 * Character: ȷ
 * Unicode code point: U+0237 (567)
 * Description: latin small letter dotless j
 */
static wchar_t* JMATH_LATIN_SMALL_LETTER_DOTLESS_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jmath";
static int* JMATH_LATIN_SMALL_LETTER_DOTLESS_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circ html character entity reference model.
 *
 * Name: circ
 * Character: ˆ
 * Unicode code point: U+02c6 (710)
 * Description: modifier letter circumflex accent
 */
static wchar_t* CIRC_MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circ";
static int* CIRC_MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hacek html character entity reference model.
 *
 * Name: Hacek
 * Character: ˇ
 * Unicode code point: U+02c7 (711)
 * Description: caron
 */
static wchar_t* HACEK_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hacek";
static int* HACEK_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The caron html character entity reference model.
 *
 * Name: caron
 * Character: ˇ
 * Unicode code point: U+02c7 (711)
 * Description: caron
 */
static wchar_t* CARON_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"caron";
static int* CARON_CARON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Breve html character entity reference model.
 *
 * Name: Breve
 * Character: ˘
 * Unicode code point: U+02d8 (728)
 * Description: breve
 */
static wchar_t* CAMEL_BREVE_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Breve";
static int* CAMEL_BREVE_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The breve html character entity reference model.
 *
 * Name: breve
 * Character: ˘
 * Unicode code point: U+02d8 (728)
 * Description: breve
 */
static wchar_t* SMALL_BREVE_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"breve";
static int* SMALL_BREVE_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DiacriticalDot html character entity reference model.
 *
 * Name: DiacriticalDot
 * Character: ˙
 * Unicode code point: U+02d9 (729)
 * Description: dot above
 */
static wchar_t* DIACRITICALDOT_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalDot";
static int* DIACRITICALDOT_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dot html character entity reference model.
 *
 * Name: dot
 * Character: ˙
 * Unicode code point: U+02d9 (729)
 * Description: dot above
 */
static wchar_t* DOT_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dot";
static int* DOT_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ring html character entity reference model.
 *
 * Name: ring
 * Character: ˚
 * Unicode code point: U+02da (730)
 * Description: ring above
 */
static wchar_t* RING_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ring";
static int* RING_RING_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ogon html character entity reference model.
 *
 * Name: ogon
 * Character: ˛
 * Unicode code point: U+02db (731)
 * Description: ogonek
 */
static wchar_t* OGON_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogon";
static int* OGON_OGONEK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DiacriticalTilde html character entity reference model.
 *
 * Name: DiacriticalTilde
 * Character: ˜
 * Unicode code point: U+02dc (732)
 * Description: small tilde
 */
static wchar_t* DIACRITICALTILDE_SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalTilde";
static int* DIACRITICALTILDE_SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tilde html character entity reference model.
 *
 * Name: tilde
 * Character: ˜
 * Unicode code point: U+02dc (732)
 * Description: small tilde
 */
static wchar_t* TILDE_SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tilde";
static int* TILDE_SMALL_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DiacriticalDoubleAcute html character entity reference model.
 *
 * Name: DiacriticalDoubleAcute
 * Character: ˝
 * Unicode code point: U+02dd (733)
 * Description: double acute accent
 */
static wchar_t* DIACRITICALDOUBLEACUTE_DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DiacriticalDoubleAcute";
static int* DIACRITICALDOUBLEACUTE_DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dblac html character entity reference model.
 *
 * Name: dblac
 * Character: ˝
 * Unicode code point: U+02dd (733)
 * Description: double acute accent
 */
static wchar_t* DBLAC_DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dblac";
static int* DBLAC_DOUBLE_ACUTE_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownBreve html character entity reference model.
 *
 * Name: DownBreve
 * Character:  ̑
 * Unicode code point: U+0311 (785)
 * Description: combining inverted breve
 */
static wchar_t* DOWNBREVE_COMBINING_INVERTED_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownBreve";
static int* DOWNBREVE_COMBINING_INVERTED_BREVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Aacgr html character entity reference model.
 *
 * Name: Aacgr
 * Character: Ά
 * Unicode code point: U+0386 (902)
 * Description: greek capital letter alpha with tonos
 */
static wchar_t* AACGR_GREEK_CAPITAL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aacgr";
static int* AACGR_GREEK_CAPITAL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Eacgr html character entity reference model.
 *
 * Name: Eacgr
 * Character: Έ
 * Unicode code point: U+0388 (904)
 * Description: greek capital letter epsilon with tonos
 */
static wchar_t* EACGR_GREEK_CAPITAL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eacgr";
static int* EACGR_GREEK_CAPITAL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The EEacgr html character entity reference model.
 *
 * Name: EEacgr
 * Character: Ή
 * Unicode code point: U+0389 (905)
 * Description: greek capital letter eta with tonos
 */
static wchar_t* EEACGR_GREEK_CAPITAL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EEacgr";
static int* EEACGR_GREEK_CAPITAL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iacgr html character entity reference model.
 *
 * Name: Iacgr
 * Character: Ί
 * Unicode code point: U+038a (906)
 * Description: greek capital letter iota with tonos
 */
static wchar_t* IACGR_GREEK_CAPITAL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iacgr";
static int* IACGR_GREEK_CAPITAL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Oacgr html character entity reference model.
 *
 * Name: Oacgr
 * Character: Ό
 * Unicode code point: U+038c (908)
 * Description: greek capital letter omicron with tonos
 */
static wchar_t* OACGR_GREEK_CAPITAL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oacgr";
static int* OACGR_GREEK_CAPITAL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uacgr html character entity reference model.
 *
 * Name: Uacgr
 * Character: Ύ
 * Unicode code point: U+038e (910)
 * Description: greek capital letter upsilon with tonos
 */
static wchar_t* UACGR_GREEK_CAPITAL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uacgr";
static int* UACGR_GREEK_CAPITAL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OHacgr html character entity reference model.
 *
 * Name: OHacgr
 * Character: Ώ
 * Unicode code point: U+038f (911)
 * Description: greek capital letter omega with tonos
 */
static wchar_t* OHACGR_GREEK_CAPITAL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OHacgr";
static int* OHACGR_GREEK_CAPITAL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The idiagr html character entity reference model.
 *
 * Name: idiagr
 * Character: ΐ
 * Unicode code point: U+0390 (912)
 * Description: greek small letter iota with dialytika and tonos
 */
static wchar_t* IDIAGR_GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"idiagr";
static int* IDIAGR_GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Agr html character entity reference model.
 *
 * Name: Agr
 * Character: Α
 * Unicode code point: U+0391 (913)
 * Description: greek capital letter alpha
 */
static wchar_t* AGR_GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Agr";
static int* AGR_GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Alpha html character entity reference model.
 *
 * Name: Alpha
 * Character: Α
 * Unicode code point: U+0391 (913)
 * Description: greek capital letter alpha
 */
static wchar_t* ALPHA_GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Alpha";
static int* ALPHA_GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Beta html character entity reference model.
 *
 * Name: Beta
 * Character: Β
 * Unicode code point: U+0392 (914)
 * Description: greek capital letter beta
 */
static wchar_t* BETA_GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Beta";
static int* BETA_GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bgr html character entity reference model.
 *
 * Name: Bgr
 * Character: Β
 * Unicode code point: U+0392 (914)
 * Description: greek capital letter beta
 */
static wchar_t* BGR_GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bgr";
static int* BGR_GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gamma html character entity reference model.
 *
 * Name: Gamma
 * Character: Γ
 * Unicode code point: U+0393 (915)
 * Description: greek capital letter gamma
 */
static wchar_t* GAMMA_GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gamma";
static int* GAMMA_GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ggr html character entity reference model.
 *
 * Name: Ggr
 * Character: Γ
 * Unicode code point: U+0393 (915)
 * Description: greek capital letter gamma
 */
static wchar_t* GGR_GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ggr";
static int* GGR_GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Delta html character entity reference model.
 *
 * Name: Delta
 * Character: Δ
 * Unicode code point: U+0394 (916)
 * Description: greek capital letter delta
 */
static wchar_t* DELTA_GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Delta";
static int* DELTA_GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dgr html character entity reference model.
 *
 * Name: Dgr
 * Character: Δ
 * Unicode code point: U+0394 (916)
 * Description: greek capital letter delta
 */
static wchar_t* DGR_GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dgr";
static int* DGR_GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Egr html character entity reference model.
 *
 * Name: Egr
 * Character: Ε
 * Unicode code point: U+0395 (917)
 * Description: greek capital letter epsilon
 */
static wchar_t* EGR_GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Egr";
static int* EGR_GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Epsilon html character entity reference model.
 *
 * Name: Epsilon
 * Character: Ε
 * Unicode code point: U+0395 (917)
 * Description: greek capital letter epsilon
 */
static wchar_t* EPSILON_GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Epsilon";
static int* EPSILON_GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zeta html character entity reference model.
 *
 * Name: Zeta
 * Character: Ζ
 * Unicode code point: U+0396 (918)
 * Description: greek capital letter zeta
 */
static wchar_t* ZETA_GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zeta";
static int* ZETA_GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zgr html character entity reference model.
 *
 * Name: Zgr
 * Character: Ζ
 * Unicode code point: U+0396 (918)
 * Description: greek capital letter zeta
 */
static wchar_t* ZGR_GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zgr";
static int* ZGR_GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The EEgr html character entity reference model.
 *
 * Name: EEgr
 * Character: Η
 * Unicode code point: U+0397 (919)
 * Description: greek capital letter eta
 */
static wchar_t* EEGR_GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EEgr";
static int* EEGR_GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Eta html character entity reference model.
 *
 * Name: Eta
 * Character: Η
 * Unicode code point: U+0397 (919)
 * Description: greek capital letter eta
 */
static wchar_t* ETA_GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eta";
static int* ETA_GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The THgr html character entity reference model.
 *
 * Name: THgr
 * Character: Θ
 * Unicode code point: U+0398 (920)
 * Description: greek capital letter theta
 */
static wchar_t* THGR_GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"THgr";
static int* THGR_GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Theta html character entity reference model.
 *
 * Name: Theta
 * Character: Θ
 * Unicode code point: U+0398 (920)
 * Description: greek capital letter theta
 */
static wchar_t* THETA_GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Theta";
static int* THETA_GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Igr html character entity reference model.
 *
 * Name: Igr
 * Character: Ι
 * Unicode code point: U+0399 (921)
 * Description: greek capital letter iota
 */
static wchar_t* IGR_GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Igr";
static int* IGR_GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iota html character entity reference model.
 *
 * Name: Iota
 * Character: Ι
 * Unicode code point: U+0399 (921)
 * Description: greek capital letter iota
 */
static wchar_t* IOTA_GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iota";
static int* IOTA_GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kappa html character entity reference model.
 *
 * Name: Kappa
 * Character: Κ
 * Unicode code point: U+039a (922)
 * Description: greek capital letter kappa
 */
static wchar_t* KAPPA_GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kappa";
static int* KAPPA_GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kgr html character entity reference model.
 *
 * Name: Kgr
 * Character: Κ
 * Unicode code point: U+039a (922)
 * Description: greek capital letter kappa
 */
static wchar_t* KGR_GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kgr";
static int* KGR_GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lambda html character entity reference model.
 *
 * Name: Lambda
 * Character: Λ
 * Unicode code point: U+039b (923)
 * Description: greek capital letter lamda
 */
static wchar_t* LAMBDA_GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lambda";
static int* LAMBDA_GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lgr html character entity reference model.
 *
 * Name: Lgr
 * Character: Λ
 * Unicode code point: U+039b (923)
 * Description: greek capital letter lamda
 */
static wchar_t* LGR_GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lgr";
static int* LGR_GREEK_CAPITAL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mgr html character entity reference model.
 *
 * Name: Mgr
 * Character: Μ
 * Unicode code point: U+039c (924)
 * Description: greek capital letter mu
 */
static wchar_t* MGR_GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mgr";
static int* MGR_GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mu html character entity reference model.
 *
 * Name: Mu
 * Character: Μ
 * Unicode code point: U+039c (924)
 * Description: greek capital letter mu
 */
static wchar_t* MU_GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mu";
static int* MU_GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ngr html character entity reference model.
 *
 * Name: Ngr
 * Character: Ν
 * Unicode code point: U+039d (925)
 * Description: greek capital letter nu
 */
static wchar_t* NGR_GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ngr";
static int* NGR_GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Nu html character entity reference model.
 *
 * Name: Nu
 * Character: Ν
 * Unicode code point: U+039d (925)
 * Description: greek capital letter nu
 */
static wchar_t* NU_GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nu";
static int* NU_GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Xgr html character entity reference model.
 *
 * Name: Xgr
 * Character: Ξ
 * Unicode code point: U+039e (926)
 * Description: greek capital letter xi
 */
static wchar_t* XGR_GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xgr";
static int* XGR_GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Xi html character entity reference model.
 *
 * Name: Xi
 * Character: Ξ
 * Unicode code point: U+039e (926)
 * Description: greek capital letter xi
 */
static wchar_t* XI_GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xi";
static int* XI_GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ogr html character entity reference model.
 *
 * Name: Ogr
 * Character: Ο
 * Unicode code point: U+039f (927)
 * Description: greek capital letter omicron
 */
static wchar_t* OGR_GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ogr";
static int* OGR_GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Omicron html character entity reference model.
 *
 * Name: Omicron
 * Character: Ο
 * Unicode code point: U+039f (927)
 * Description: greek capital letter omicron
 */
static wchar_t* OMICRON_GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omicron";
static int* OMICRON_GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pgr html character entity reference model.
 *
 * Name: Pgr
 * Character: Π
 * Unicode code point: U+03a0 (928)
 * Description: greek capital letter pi
 */
static wchar_t* PGR_GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pgr";
static int* PGR_GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pi html character entity reference model.
 *
 * Name: Pi
 * Character: Π
 * Unicode code point: U+03a0 (928)
 * Description: greek capital letter pi
 */
static wchar_t* PI_GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pi";
static int* PI_GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rgr html character entity reference model.
 *
 * Name: Rgr
 * Character: Ρ
 * Unicode code point: U+03a1 (929)
 * Description: greek capital letter rho
 */
static wchar_t* RGR_GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rgr";
static int* RGR_GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rho html character entity reference model.
 *
 * Name: Rho
 * Character: Ρ
 * Unicode code point: U+03a1 (929)
 * Description: greek capital letter rho
 */
static wchar_t* RHO_GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rho";
static int* RHO_GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sgr html character entity reference model.
 *
 * Name: Sgr
 * Character: Σ
 * Unicode code point: U+03a3 (931)
 * Description: greek capital letter sigma
 */
static wchar_t* SGR_GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sgr";
static int* SGR_GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sigma html character entity reference model.
 *
 * Name: Sigma
 * Character: Σ
 * Unicode code point: U+03a3 (931)
 * Description: greek capital letter sigma
 */
static wchar_t* SIGMA_GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sigma";
static int* SIGMA_GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tau html character entity reference model.
 *
 * Name: Tau
 * Character: Τ
 * Unicode code point: U+03a4 (932)
 * Description: greek capital letter tau
 */
static wchar_t* TAU_GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tau";
static int* TAU_GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tgr html character entity reference model.
 *
 * Name: Tgr
 * Character: Τ
 * Unicode code point: U+03a4 (932)
 * Description: greek capital letter tau
 */
static wchar_t* TGR_GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tgr";
static int* TGR_GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ugr html character entity reference model.
 *
 * Name: Ugr
 * Character: Υ
 * Unicode code point: U+03a5 (933)
 * Description: greek capital letter upsilon
 */
static wchar_t* UGR_GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ugr";
static int* UGR_GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Upsilon html character entity reference model.
 *
 * Name: Upsilon
 * Character: Υ
 * Unicode code point: U+03a5 (933)
 * Description: greek capital letter upsilon
 */
static wchar_t* UPSILON_GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Upsilon";
static int* UPSILON_GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PHgr html character entity reference model.
 *
 * Name: PHgr
 * Character: Φ
 * Unicode code point: U+03a6 (934)
 * Description: greek capital letter phi
 */
static wchar_t* PHGR_GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PHgr";
static int* PHGR_GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Phi html character entity reference model.
 *
 * Name: Phi
 * Character: Φ
 * Unicode code point: U+03a6 (934)
 * Description: greek capital letter phi
 */
static wchar_t* PHI_GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Phi";
static int* PHI_GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Chi html character entity reference model.
 *
 * Name: Chi
 * Character: Χ
 * Unicode code point: U+03a7 (935)
 * Description: greek capital letter chi
 */
static wchar_t* CHI_GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Chi";
static int* CHI_GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The KHgr html character entity reference model.
 *
 * Name: KHgr
 * Character: Χ
 * Unicode code point: U+03a7 (935)
 * Description: greek capital letter chi
 */
static wchar_t* KHGR_GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"KHgr";
static int* KHGR_GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PSgr html character entity reference model.
 *
 * Name: PSgr
 * Character: Ψ
 * Unicode code point: U+03a8 (936)
 * Description: greek capital letter psi
 */
static wchar_t* PSGR_GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PSgr";
static int* PSGR_GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Psi html character entity reference model.
 *
 * Name: Psi
 * Character: Ψ
 * Unicode code point: U+03a8 (936)
 * Description: greek capital letter psi
 */
static wchar_t* PSI_GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Psi";
static int* PSI_GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OHgr html character entity reference model.
 *
 * Name: OHgr
 * Character: Ω
 * Unicode code point: U+03a9 (937)
 * Description: greek capital letter omega
 */
static wchar_t* OHGR_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OHgr";
static int* OHGR_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Omega html character entity reference model.
 *
 * Name: Omega
 * Character: Ω
 * Unicode code point: U+03a9 (937)
 * Description: greek capital letter omega
 */
static wchar_t* OMEGA_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Omega";
static int* OMEGA_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ohm html character entity reference model.
 *
 * Name: ohm
 * Character: Ω
 * Unicode code point: U+03a9 (937)
 * Description: greek capital letter omega
 */
static wchar_t* OHM_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohm";
static int* OHM_GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Idigr html character entity reference model.
 *
 * Name: Idigr
 * Character: Ϊ
 * Unicode code point: U+03aa (938)
 * Description: greek capital letter iota with dialytika
 */
static wchar_t* IDIGR_GREEK_CAPITAL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Idigr";
static int* IDIGR_GREEK_CAPITAL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Udigr html character entity reference model.
 *
 * Name: Udigr
 * Character: Ϋ
 * Unicode code point: U+03ab (939)
 * Description: greek capital letter upsilon with dialytika
 */
static wchar_t* UDIGR_GREEK_CAPITAL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Udigr";
static int* UDIGR_GREEK_CAPITAL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aacgr html character entity reference model.
 *
 * Name: aacgr
 * Character: ά
 * Unicode code point: U+03ac (940)
 * Description: greek small letter alpha with tonos
 */
static wchar_t* AACGR_GREEK_SMALL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aacgr";
static int* AACGR_GREEK_SMALL_LETTER_ALPHA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eacgr html character entity reference model.
 *
 * Name: eacgr
 * Character: έ
 * Unicode code point: U+03ad (941)
 * Description: greek small letter epsilon with tonos
 */
static wchar_t* EACGR_GREEK_SMALL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eacgr";
static int* EACGR_GREEK_SMALL_LETTER_EPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eeacgr html character entity reference model.
 *
 * Name: eeacgr
 * Character: ή
 * Unicode code point: U+03ae (942)
 * Description: greek small letter eta with tonos
 */
static wchar_t* EEACGR_GREEK_SMALL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eeacgr";
static int* EEACGR_GREEK_SMALL_LETTER_ETA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iacgr html character entity reference model.
 *
 * Name: iacgr
 * Character: ί
 * Unicode code point: U+03af (943)
 * Description: greek small letter iota with tonos
 */
static wchar_t* IACGR_GREEK_SMALL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iacgr";
static int* IACGR_GREEK_SMALL_LETTER_IOTA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udiagr html character entity reference model.
 *
 * Name: udiagr
 * Character: ΰ
 * Unicode code point: U+03b0 (944)
 * Description: greek small letter upsilon with dialytika and tonos
 */
static wchar_t* UDIAGR_GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udiagr";
static int* UDIAGR_GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_AND_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The agr html character entity reference model.
 *
 * Name: agr
 * Character: α
 * Unicode code point: U+03b1 (945)
 * Description: greek small letter alpha
 */
static wchar_t* AGR_GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"agr";
static int* AGR_GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alpha html character entity reference model.
 *
 * Name: alpha
 * Character: α
 * Unicode code point: U+03b1 (945)
 * Description: greek small letter alpha
 */
static wchar_t* ALPHA_GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"alpha";
static int* ALPHA_GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The beta html character entity reference model.
 *
 * Name: beta
 * Character: β
 * Unicode code point: U+03b2 (946)
 * Description: greek small letter beta
 */
static wchar_t* BETA_GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"beta";
static int* BETA_GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bgr html character entity reference model.
 *
 * Name: bgr
 * Character: β
 * Unicode code point: U+03b2 (946)
 * Description: greek small letter beta
 */
static wchar_t* BGR_GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bgr";
static int* BGR_GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gamma html character entity reference model.
 *
 * Name: gamma
 * Character: γ
 * Unicode code point: U+03b3 (947)
 * Description: greek small letter gamma
 */
static wchar_t* GAMMA_GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gamma";
static int* GAMMA_GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ggr html character entity reference model.
 *
 * Name: ggr
 * Character: γ
 * Unicode code point: U+03b3 (947)
 * Description: greek small letter gamma
 */
static wchar_t* GGR_GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ggr";
static int* GGR_GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The delta html character entity reference model.
 *
 * Name: delta
 * Character: δ
 * Unicode code point: U+03b4 (948)
 * Description: greek small letter delta
 */
static wchar_t* DELTA_GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"delta";
static int* DELTA_GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dgr html character entity reference model.
 *
 * Name: dgr
 * Character: δ
 * Unicode code point: U+03b4 (948)
 * Description: greek small letter delta
 */
static wchar_t* DGR_GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dgr";
static int* DGR_GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The egr html character entity reference model.
 *
 * Name: egr
 * Character: ε
 * Unicode code point: U+03b5 (949)
 * Description: greek small letter epsilon
 */
static wchar_t* EGR_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egr";
static int* EGR_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The epsi html character entity reference model.
 *
 * Name: epsi
 * Character: ε
 * Unicode code point: U+03b5 (949)
 * Description: greek small letter epsilon
 */
static wchar_t* EPSI_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epsi";
static int* EPSI_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The epsilon html character entity reference model.
 *
 * Name: epsilon
 * Character: ε
 * Unicode code point: U+03b5 (949)
 * Description: greek small letter epsilon
 */
static wchar_t* EPSILON_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epsilon";
static int* EPSILON_GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zeta html character entity reference model.
 *
 * Name: zeta
 * Character: ζ
 * Unicode code point: U+03b6 (950)
 * Description: greek small letter zeta
 */
static wchar_t* ZETA_GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zeta";
static int* ZETA_GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zgr html character entity reference model.
 *
 * Name: zgr
 * Character: ζ
 * Unicode code point: U+03b6 (950)
 * Description: greek small letter zeta
 */
static wchar_t* ZGR_GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zgr";
static int* ZGR_GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eegr html character entity reference model.
 *
 * Name: eegr
 * Character: η
 * Unicode code point: U+03b7 (951)
 * Description: greek small letter eta
 */
static wchar_t* EEGR_GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eegr";
static int* EEGR_GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eta html character entity reference model.
 *
 * Name: eta
 * Character: η
 * Unicode code point: U+03b7 (951)
 * Description: greek small letter eta
 */
static wchar_t* ETA_GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eta";
static int* ETA_GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The theta html character entity reference model.
 *
 * Name: theta
 * Character: θ
 * Unicode code point: U+03b8 (952)
 * Description: greek small letter theta
 */
static wchar_t* THETA_GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"theta";
static int* THETA_GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thgr html character entity reference model.
 *
 * Name: thgr
 * Character: θ
 * Unicode code point: U+03b8 (952)
 * Description: greek small letter theta
 */
static wchar_t* THGR_GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thgr";
static int* THGR_GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The igr html character entity reference model.
 *
 * Name: igr
 * Character: ι
 * Unicode code point: U+03b9 (953)
 * Description: greek small letter iota
 */
static wchar_t* IGR_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"igr";
static int* IGR_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iota html character entity reference model.
 *
 * Name: iota
 * Character: ι
 * Unicode code point: U+03b9 (953)
 * Description: greek small letter iota
 */
static wchar_t* IOTA_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iota";
static int* IOTA_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kappa html character entity reference model.
 *
 * Name: kappa
 * Character: κ
 * Unicode code point: U+03ba (954)
 * Description: greek small letter kappa
 */
static wchar_t* KAPPA_GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kappa";
static int* KAPPA_GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kgr html character entity reference model.
 *
 * Name: kgr
 * Character: κ
 * Unicode code point: U+03ba (954)
 * Description: greek small letter kappa
 */
static wchar_t* KGR_GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kgr";
static int* KGR_GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lambda html character entity reference model.
 *
 * Name: lambda
 * Character: λ
 * Unicode code point: U+03bb (955)
 * Description: greek small letter lamda
 */
static wchar_t* LAMBDA_GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lambda";
static int* LAMBDA_GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lgr html character entity reference model.
 *
 * Name: lgr
 * Character: λ
 * Unicode code point: U+03bb (955)
 * Description: greek small letter lamda
 */
static wchar_t* LGR_GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lgr";
static int* LGR_GREEK_SMALL_LETTER_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mgr html character entity reference model.
 *
 * Name: mgr
 * Character: μ
 * Unicode code point: U+03bc (956)
 * Description: greek small letter mu
 */
static wchar_t* MGR_GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mgr";
static int* MGR_GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mu html character entity reference model.
 *
 * Name: mu
 * Character: μ
 * Unicode code point: U+03bc (956)
 * Description: greek small letter mu
 */
static wchar_t* MU_GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mu";
static int* MU_GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngr html character entity reference model.
 *
 * Name: ngr
 * Character: ν
 * Unicode code point: U+03bd (957)
 * Description: greek small letter nu
 */
static wchar_t* NGR_GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngr";
static int* NGR_GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nu html character entity reference model.
 *
 * Name: nu
 * Character: ν
 * Unicode code point: U+03bd (957)
 * Description: greek small letter nu
 */
static wchar_t* NU_GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nu";
static int* NU_GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xgr html character entity reference model.
 *
 * Name: xgr
 * Character: ξ
 * Unicode code point: U+03be (958)
 * Description: greek small letter xi
 */
static wchar_t* XGR_GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xgr";
static int* XGR_GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xi html character entity reference model.
 *
 * Name: xi
 * Character: ξ
 * Unicode code point: U+03be (958)
 * Description: greek small letter xi
 */
static wchar_t* XI_GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xi";
static int* XI_GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ogr html character entity reference model.
 *
 * Name: ogr
 * Character: ο
 * Unicode code point: U+03bf (959)
 * Description: greek small letter omicron
 */
static wchar_t* OGR_GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogr";
static int* OGR_GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The omicron html character entity reference model.
 *
 * Name: omicron
 * Character: ο
 * Unicode code point: U+03bf (959)
 * Description: greek small letter omicron
 */
static wchar_t* OMICRON_GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omicron";
static int* OMICRON_GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pgr html character entity reference model.
 *
 * Name: pgr
 * Character: π
 * Unicode code point: U+03c0 (960)
 * Description: greek small letter pi
 */
static wchar_t* PGR_GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pgr";
static int* PGR_GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pi html character entity reference model.
 *
 * Name: pi
 * Character: π
 * Unicode code point: U+03c0 (960)
 * Description: greek small letter pi
 */
static wchar_t* PI_GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pi";
static int* PI_GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rgr html character entity reference model.
 *
 * Name: rgr
 * Character: ρ
 * Unicode code point: U+03c1 (961)
 * Description: greek small letter rho
 */
static wchar_t* RGR_GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rgr";
static int* RGR_GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rho html character entity reference model.
 *
 * Name: rho
 * Character: ρ
 * Unicode code point: U+03c1 (961)
 * Description: greek small letter rho
 */
static wchar_t* RHO_GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rho";
static int* RHO_GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sfgr html character entity reference model.
 *
 * Name: sfgr
 * Character: ς
 * Unicode code point: U+03c2 (962)
 * Description: greek small letter final sigma
 */
static wchar_t* SFGR_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sfgr";
static int* SFGR_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sigmaf html character entity reference model.
 *
 * Name: sigmaf
 * Character: ς
 * Unicode code point: U+03c2 (962)
 * Description: greek small letter final sigma
 */
static wchar_t* SIGMAF_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sigmaf";
static int* SIGMAF_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sigmav html character entity reference model.
 *
 * Name: sigmav
 * Character: ς
 * Unicode code point: U+03c2 (962)
 * Description: greek small letter final sigma
 */
static wchar_t* SIGMAV_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sigmav";
static int* SIGMAV_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varsigma html character entity reference model.
 *
 * Name: varsigma
 * Character: ς
 * Unicode code point: U+03c2 (962)
 * Description: greek small letter final sigma
 */
static wchar_t* VARSIGMA_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsigma";
static int* VARSIGMA_GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sgr html character entity reference model.
 *
 * Name: sgr
 * Character: σ
 * Unicode code point: U+03c3 (963)
 * Description: greek small letter sigma
 */
static wchar_t* SGR_GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sgr";
static int* SGR_GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sigma html character entity reference model.
 *
 * Name: sigma
 * Character: σ
 * Unicode code point: U+03c3 (963)
 * Description: greek small letter sigma
 */
static wchar_t* SIGMA_GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sigma";
static int* SIGMA_GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tau html character entity reference model.
 *
 * Name: tau
 * Character: τ
 * Unicode code point: U+03c4 (964)
 * Description: greek small letter tau
 */
static wchar_t* TAU_GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tau";
static int* TAU_GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tgr html character entity reference model.
 *
 * Name: tgr
 * Character: τ
 * Unicode code point: U+03c4 (964)
 * Description: greek small letter tau
 */
static wchar_t* TGR_GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tgr";
static int* TGR_GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ugr html character entity reference model.
 *
 * Name: ugr
 * Character: υ
 * Unicode code point: U+03c5 (965)
 * Description: greek small letter upsilon
 */
static wchar_t* UGR_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ugr";
static int* UGR_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upsi html character entity reference model.
 *
 * Name: upsi
 * Character: υ
 * Unicode code point: U+03c5 (965)
 * Description: greek small letter upsilon
 */
static wchar_t* UPSI_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upsi";
static int* UPSI_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upsilon html character entity reference model.
 *
 * Name: upsilon
 * Character: υ
 * Unicode code point: U+03c5 (965)
 * Description: greek small letter upsilon
 */
static wchar_t* UPSILON_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upsilon";
static int* UPSILON_GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The phgr html character entity reference model.
 *
 * Name: phgr
 * Character: φ
 * Unicode code point: U+03c6 (966)
 * Description: greek small letter phi
 */
static wchar_t* PHGR_GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phgr";
static int* PHGR_GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The phi html character entity reference model.
 *
 * Name: phi
 * Character: φ
 * Unicode code point: U+03c6 (966)
 * Description: greek small letter phi
 */
static wchar_t* PHI_GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phi";
static int* PHI_GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chi html character entity reference model.
 *
 * Name: chi
 * Character: χ
 * Unicode code point: U+03c7 (967)
 * Description: greek small letter chi
 */
static wchar_t* CHI_GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"chi";
static int* CHI_GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The khgr html character entity reference model.
 *
 * Name: khgr
 * Character: χ
 * Unicode code point: U+03c7 (967)
 * Description: greek small letter chi
 */
static wchar_t* KHGR_GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"khgr";
static int* KHGR_GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The psgr html character entity reference model.
 *
 * Name: psgr
 * Character: ψ
 * Unicode code point: U+03c8 (968)
 * Description: greek small letter psi
 */
static wchar_t* PSGR_GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"psgr";
static int* PSGR_GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The psi html character entity reference model.
 *
 * Name: psi
 * Character: ψ
 * Unicode code point: U+03c8 (968)
 * Description: greek small letter psi
 */
static wchar_t* PSI_GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"psi";
static int* PSI_GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ohgr html character entity reference model.
 *
 * Name: ohgr
 * Character: ω
 * Unicode code point: U+03c9 (969)
 * Description: greek small letter omega
 */
static wchar_t* OHGR_GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohgr";
static int* OHGR_GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The omega html character entity reference model.
 *
 * Name: omega
 * Character: ω
 * Unicode code point: U+03c9 (969)
 * Description: greek small letter omega
 */
static wchar_t* OMEGA_GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omega";
static int* OMEGA_GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The idigr html character entity reference model.
 *
 * Name: idigr
 * Character: ϊ
 * Unicode code point: U+03ca (970)
 * Description: greek small letter iota with dialytika
 */
static wchar_t* IDIGR_GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"idigr";
static int* IDIGR_GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udigr html character entity reference model.
 *
 * Name: udigr
 * Character: ϋ
 * Unicode code point: U+03cb (971)
 * Description: greek small letter upsilon with dialytika
 */
static wchar_t* UDIGR_GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udigr";
static int* UDIGR_GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oacgr html character entity reference model.
 *
 * Name: oacgr
 * Character: ό
 * Unicode code point: U+03cc (972)
 * Description: greek small letter omicron with tonos
 */
static wchar_t* OACGR_GREEK_SMALL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oacgr";
static int* OACGR_GREEK_SMALL_LETTER_OMICRON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uacgr html character entity reference model.
 *
 * Name: uacgr
 * Character: ύ
 * Unicode code point: U+03cd (973)
 * Description: greek small letter upsilon with tonos
 */
static wchar_t* UACGR_GREEK_SMALL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uacgr";
static int* UACGR_GREEK_SMALL_LETTER_UPSILON_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ohacgr html character entity reference model.
 *
 * Name: ohacgr
 * Character: ώ
 * Unicode code point: U+03ce (974)
 * Description: greek small letter omega with tonos
 */
static wchar_t* OHACGR_GREEK_SMALL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohacgr";
static int* OHACGR_GREEK_SMALL_LETTER_OMEGA_WITH_TONOS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thetasym html character entity reference model.
 *
 * Name: thetasym
 * Character: ϑ
 * Unicode code point: U+03d1 (977)
 * Description: greek theta symbol
 */
static wchar_t* THETASYM_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thetasym";
static int* THETASYM_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thetav html character entity reference model.
 *
 * Name: thetav
 * Character: ϑ
 * Unicode code point: U+03d1 (977)
 * Description: greek theta symbol
 */
static wchar_t* THETAV_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thetav";
static int* THETAV_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vartheta html character entity reference model.
 *
 * Name: vartheta
 * Character: ϑ
 * Unicode code point: U+03d1 (977)
 * Description: greek theta symbol
 */
static wchar_t* VARTHETA_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vartheta";
static int* VARTHETA_GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Upsi html character entity reference model.
 *
 * Name: Upsi
 * Character: ϒ
 * Unicode code point: U+03d2 (978)
 * Description: greek upsilon with hook symbol
 */
static wchar_t* UPSI_GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Upsi";
static int* UPSI_GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upsih html character entity reference model.
 *
 * Name: upsih
 * Character: ϒ
 * Unicode code point: U+03d2 (978)
 * Description: greek upsilon with hook symbol
 */
static wchar_t* UPSIH_GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upsih";
static int* UPSIH_GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The phiv html character entity reference model.
 *
 * Name: phiv
 * Character: ϕ
 * Unicode code point: U+03d5 (981)
 * Description: greek phi symbol
 */
static wchar_t* PHIV_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phiv";
static int* PHIV_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The straightphi html character entity reference model.
 *
 * Name: straightphi
 * Character: ϕ
 * Unicode code point: U+03d5 (981)
 * Description: greek phi symbol
 */
static wchar_t* STRAIGHTPHI_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"straightphi";
static int* STRAIGHTPHI_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varphi html character entity reference model.
 *
 * Name: varphi
 * Character: ϕ
 * Unicode code point: U+03d5 (981)
 * Description: greek phi symbol
 */
static wchar_t* VARPHI_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varphi";
static int* VARPHI_GREEK_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The piv html character entity reference model.
 *
 * Name: piv
 * Character: ϖ
 * Unicode code point: U+03d6 (982)
 * Description: greek pi symbol
 */
static wchar_t* PIV_GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"piv";
static int* PIV_GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varpi html character entity reference model.
 *
 * Name: varpi
 * Character: ϖ
 * Unicode code point: U+03d6 (982)
 * Description: greek pi symbol
 */
static wchar_t* VARPI_GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varpi";
static int* VARPI_GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gammad html character entity reference model.
 *
 * Name: Gammad
 * Character: Ϝ
 * Unicode code point: U+03dc (988)
 * Description: greek letter digamma
 */
static wchar_t* GAMMAD_GREEK_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gammad";
static int* GAMMAD_GREEK_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The digamma html character entity reference model.
 *
 * Name: digamma
 * Character: ϝ
 * Unicode code point: U+03dd (989)
 * Description: greek small letter digamma
 */
static wchar_t* DIGAMMA_GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"digamma";
static int* DIGAMMA_GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gammad html character entity reference model.
 *
 * Name: gammad
 * Character: ϝ
 * Unicode code point: U+03dd (989)
 * Description: greek small letter digamma
 */
static wchar_t* GAMMAD_GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gammad";
static int* GAMMAD_GREEK_SMALL_LETTER_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kappav html character entity reference model.
 *
 * Name: kappav
 * Character: ϰ
 * Unicode code point: U+03f0 (1008)
 * Description: greek kappa symbol
 */
static wchar_t* KAPPAV_GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kappav";
static int* KAPPAV_GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varkappa html character entity reference model.
 *
 * Name: varkappa
 * Character: ϰ
 * Unicode code point: U+03f0 (1008)
 * Description: greek kappa symbol
 */
static wchar_t* VARKAPPA_GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varkappa";
static int* VARKAPPA_GREEK_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rhov html character entity reference model.
 *
 * Name: rhov
 * Character: ϱ
 * Unicode code point: U+03f1 (1009)
 * Description: greek rho symbol
 */
static wchar_t* RHOV_GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rhov";
static int* RHOV_GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varrho html character entity reference model.
 *
 * Name: varrho
 * Character: ϱ
 * Unicode code point: U+03f1 (1009)
 * Description: greek rho symbol
 */
static wchar_t* VARRHO_GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varrho";
static int* VARRHO_GREEK_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The epsiv html character entity reference model.
 *
 * Name: epsiv
 * Character: ϵ
 * Unicode code point: U+03f5 (1013)
 * Description: greek lunate epsilon symbol
 */
static wchar_t* EPSIV_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epsiv";
static int* EPSIV_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The straightepsilon html character entity reference model.
 *
 * Name: straightepsilon
 * Character: ϵ
 * Unicode code point: U+03f5 (1013)
 * Description: greek lunate epsilon symbol
 */
static wchar_t* STRAIGHTEPSILON_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"straightepsilon";
static int* STRAIGHTEPSILON_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varepsilon html character entity reference model.
 *
 * Name: varepsilon
 * Character: ϵ
 * Unicode code point: U+03f5 (1013)
 * Description: greek lunate epsilon symbol
 */
static wchar_t* VAREPSILON_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varepsilon";
static int* VAREPSILON_GREEK_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The backepsilon html character entity reference model.
 *
 * Name: backepsilon
 * Character: ϶
 * Unicode code point: U+03f6 (1014)
 * Description: greek reversed lunate epsilon symbol
 */
static wchar_t* BACKEPSILON_GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backepsilon";
static int* BACKEPSILON_GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bepsi html character entity reference model.
 *
 * Name: bepsi
 * Character: ϶
 * Unicode code point: U+03f6 (1014)
 * Description: greek reversed lunate epsilon symbol
 */
static wchar_t* BEPSI_GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bepsi";
static int* BEPSI_GREEK_REVERSED_LUNATE_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The IOcy html character entity reference model.
 *
 * Name: IOcy
 * Character: Ё
 * Unicode code point: U+0401 (1025)
 * Description: cyrillic capital letter io
 */
static wchar_t* IOCY_CYRILLIC_CAPITAL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IOcy";
static int* IOCY_CYRILLIC_CAPITAL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DJcy html character entity reference model.
 *
 * Name: DJcy
 * Character: Ђ
 * Unicode code point: U+0402 (1026)
 * Description: cyrillic capital letter dje
 */
static wchar_t* DJCY_CYRILLIC_CAPITAL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DJcy";
static int* DJCY_CYRILLIC_CAPITAL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GJcy html character entity reference model.
 *
 * Name: GJcy
 * Character: Ѓ
 * Unicode code point: U+0403 (1027)
 * Description: cyrillic capital letter gje
 */
static wchar_t* GJCY_CYRILLIC_CAPITAL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GJcy";
static int* GJCY_CYRILLIC_CAPITAL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jukcy html character entity reference model.
 *
 * Name: Jukcy
 * Character: Є
 * Unicode code point: U+0404 (1028)
 * Description: cyrillic capital letter ukrainian ie
 */
static wchar_t* JUKCY_CYRILLIC_CAPITAL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jukcy";
static int* JUKCY_CYRILLIC_CAPITAL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DScy html character entity reference model.
 *
 * Name: DScy
 * Character: Ѕ
 * Unicode code point: U+0405 (1029)
 * Description: cyrillic capital letter dze
 */
static wchar_t* DSCY_CYRILLIC_CAPITAL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DScy";
static int* DSCY_CYRILLIC_CAPITAL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iukcy html character entity reference model.
 *
 * Name: Iukcy
 * Character: І
 * Unicode code point: U+0406 (1030)
 * Description: cyrillic capital letter byelorussian-ukrainian i
 */
static wchar_t* IUKCY_CYRILLIC_CAPITAL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iukcy";
static int* IUKCY_CYRILLIC_CAPITAL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The YIcy html character entity reference model.
 *
 * Name: YIcy
 * Character: Ї
 * Unicode code point: U+0407 (1031)
 * Description: cyrillic capital letter yi
 */
static wchar_t* YICY_CYRILLIC_CAPITAL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YIcy";
static int* YICY_CYRILLIC_CAPITAL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jsercy html character entity reference model.
 *
 * Name: Jsercy
 * Character: Ј
 * Unicode code point: U+0408 (1032)
 * Description: cyrillic capital letter je
 */
static wchar_t* JSERCY_CYRILLIC_CAPITAL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jsercy";
static int* JSERCY_CYRILLIC_CAPITAL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LJcy html character entity reference model.
 *
 * Name: LJcy
 * Character: Љ
 * Unicode code point: U+0409 (1033)
 * Description: cyrillic capital letter lje
 */
static wchar_t* LJCY_CYRILLIC_CAPITAL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LJcy";
static int* LJCY_CYRILLIC_CAPITAL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NJcy html character entity reference model.
 *
 * Name: NJcy
 * Character: Њ
 * Unicode code point: U+040a (1034)
 * Description: cyrillic capital letter nje
 */
static wchar_t* NJCY_CYRILLIC_CAPITAL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NJcy";
static int* NJCY_CYRILLIC_CAPITAL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TSHcy html character entity reference model.
 *
 * Name: TSHcy
 * Character: Ћ
 * Unicode code point: U+040b (1035)
 * Description: cyrillic capital letter tshe
 */
static wchar_t* TSHCY_CYRILLIC_CAPITAL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TSHcy";
static int* TSHCY_CYRILLIC_CAPITAL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The KJcy html character entity reference model.
 *
 * Name: KJcy
 * Character: Ќ
 * Unicode code point: U+040c (1036)
 * Description: cyrillic capital letter kje
 */
static wchar_t* KJCY_CYRILLIC_CAPITAL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"KJcy";
static int* KJCY_CYRILLIC_CAPITAL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ubrcy html character entity reference model.
 *
 * Name: Ubrcy
 * Character: Ў
 * Unicode code point: U+040e (1038)
 * Description: cyrillic capital letter short u
 */
static wchar_t* UBRCY_CYRILLIC_CAPITAL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ubrcy";
static int* UBRCY_CYRILLIC_CAPITAL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DZcy html character entity reference model.
 *
 * Name: DZcy
 * Character: Џ
 * Unicode code point: U+040f (1039)
 * Description: cyrillic capital letter dzhe
 */
static wchar_t* DZCY_CYRILLIC_CAPITAL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DZcy";
static int* DZCY_CYRILLIC_CAPITAL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Acy html character entity reference model.
 *
 * Name: Acy
 * Character: А
 * Unicode code point: U+0410 (1040)
 * Description: cyrillic capital letter a
 */
static wchar_t* ACY_CYRILLIC_CAPITAL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Acy";
static int* ACY_CYRILLIC_CAPITAL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bcy html character entity reference model.
 *
 * Name: Bcy
 * Character: Б
 * Unicode code point: U+0411 (1041)
 * Description: cyrillic capital letter be
 */
static wchar_t* BCY_CYRILLIC_CAPITAL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bcy";
static int* BCY_CYRILLIC_CAPITAL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vcy html character entity reference model.
 *
 * Name: Vcy
 * Character: В
 * Unicode code point: U+0412 (1042)
 * Description: cyrillic capital letter ve
 */
static wchar_t* VCY_CYRILLIC_CAPITAL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vcy";
static int* VCY_CYRILLIC_CAPITAL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gcy html character entity reference model.
 *
 * Name: Gcy
 * Character: Г
 * Unicode code point: U+0413 (1043)
 * Description: cyrillic capital letter ghe
 */
static wchar_t* GCY_CYRILLIC_CAPITAL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gcy";
static int* GCY_CYRILLIC_CAPITAL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dcy html character entity reference model.
 *
 * Name: Dcy
 * Character: Д
 * Unicode code point: U+0414 (1044)
 * Description: cyrillic capital letter de
 */
static wchar_t* DCY_CYRILLIC_CAPITAL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dcy";
static int* DCY_CYRILLIC_CAPITAL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The IEcy html character entity reference model.
 *
 * Name: IEcy
 * Character: Е
 * Unicode code point: U+0415 (1045)
 * Description: cyrillic capital letter ie
 */
static wchar_t* IECY_CYRILLIC_CAPITAL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"IEcy";
static int* IECY_CYRILLIC_CAPITAL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ZHcy html character entity reference model.
 *
 * Name: ZHcy
 * Character: Ж
 * Unicode code point: U+0416 (1046)
 * Description: cyrillic capital letter zhe
 */
static wchar_t* ZHCY_CYRILLIC_CAPITAL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ZHcy";
static int* ZHCY_CYRILLIC_CAPITAL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zcy html character entity reference model.
 *
 * Name: Zcy
 * Character: З
 * Unicode code point: U+0417 (1047)
 * Description: cyrillic capital letter ze
 */
static wchar_t* ZCY_CYRILLIC_CAPITAL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zcy";
static int* ZCY_CYRILLIC_CAPITAL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Icy html character entity reference model.
 *
 * Name: Icy
 * Character: И
 * Unicode code point: U+0418 (1048)
 * Description: cyrillic capital letter i
 */
static wchar_t* ICY_CYRILLIC_CAPITAL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Icy";
static int* ICY_CYRILLIC_CAPITAL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jcy html character entity reference model.
 *
 * Name: Jcy
 * Character: Й
 * Unicode code point: U+0419 (1049)
 * Description: cyrillic capital letter short i
 */
static wchar_t* JCY_CYRILLIC_CAPITAL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jcy";
static int* JCY_CYRILLIC_CAPITAL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kcy html character entity reference model.
 *
 * Name: Kcy
 * Character: К
 * Unicode code point: U+041a (1050)
 * Description: cyrillic capital letter ka
 */
static wchar_t* KCY_CYRILLIC_CAPITAL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kcy";
static int* KCY_CYRILLIC_CAPITAL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lcy html character entity reference model.
 *
 * Name: Lcy
 * Character: Л
 * Unicode code point: U+041b (1051)
 * Description: cyrillic capital letter el
 */
static wchar_t* LCY_CYRILLIC_CAPITAL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lcy";
static int* LCY_CYRILLIC_CAPITAL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mcy html character entity reference model.
 *
 * Name: Mcy
 * Character: М
 * Unicode code point: U+041c (1052)
 * Description: cyrillic capital letter em
 */
static wchar_t* MCY_CYRILLIC_CAPITAL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mcy";
static int* MCY_CYRILLIC_CAPITAL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ncy html character entity reference model.
 *
 * Name: Ncy
 * Character: Н
 * Unicode code point: U+041d (1053)
 * Description: cyrillic capital letter en
 */
static wchar_t* NCY_CYRILLIC_CAPITAL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ncy";
static int* NCY_CYRILLIC_CAPITAL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ocy html character entity reference model.
 *
 * Name: Ocy
 * Character: О
 * Unicode code point: U+041e (1054)
 * Description: cyrillic capital letter o
 */
static wchar_t* OCY_CYRILLIC_CAPITAL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ocy";
static int* OCY_CYRILLIC_CAPITAL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pcy html character entity reference model.
 *
 * Name: Pcy
 * Character: П
 * Unicode code point: U+041f (1055)
 * Description: cyrillic capital letter pe
 */
static wchar_t* PCY_CYRILLIC_CAPITAL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pcy";
static int* PCY_CYRILLIC_CAPITAL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rcy html character entity reference model.
 *
 * Name: Rcy
 * Character: Р
 * Unicode code point: U+0420 (1056)
 * Description: cyrillic capital letter er
 */
static wchar_t* RCY_CYRILLIC_CAPITAL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rcy";
static int* RCY_CYRILLIC_CAPITAL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Scy html character entity reference model.
 *
 * Name: Scy
 * Character: С
 * Unicode code point: U+0421 (1057)
 * Description: cyrillic capital letter es
 */
static wchar_t* SCY_CYRILLIC_CAPITAL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Scy";
static int* SCY_CYRILLIC_CAPITAL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tcy html character entity reference model.
 *
 * Name: Tcy
 * Character: Т
 * Unicode code point: U+0422 (1058)
 * Description: cyrillic capital letter te
 */
static wchar_t* TCY_CYRILLIC_CAPITAL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tcy";
static int* TCY_CYRILLIC_CAPITAL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ucy html character entity reference model.
 *
 * Name: Ucy
 * Character: У
 * Unicode code point: U+0423 (1059)
 * Description: cyrillic capital letter u
 */
static wchar_t* UCY_CYRILLIC_CAPITAL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ucy";
static int* UCY_CYRILLIC_CAPITAL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Fcy html character entity reference model.
 *
 * Name: Fcy
 * Character: Ф
 * Unicode code point: U+0424 (1060)
 * Description: cyrillic capital letter ef
 */
static wchar_t* FCY_CYRILLIC_CAPITAL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fcy";
static int* FCY_CYRILLIC_CAPITAL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The KHcy html character entity reference model.
 *
 * Name: KHcy
 * Character: Х
 * Unicode code point: U+0425 (1061)
 * Description: cyrillic capital letter ha
 */
static wchar_t* KHCY_CYRILLIC_CAPITAL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"KHcy";
static int* KHCY_CYRILLIC_CAPITAL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TScy html character entity reference model.
 *
 * Name: TScy
 * Character: Ц
 * Unicode code point: U+0426 (1062)
 * Description: cyrillic capital letter tse
 */
static wchar_t* TSCY_CYRILLIC_CAPITAL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TScy";
static int* TSCY_CYRILLIC_CAPITAL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CHcy html character entity reference model.
 *
 * Name: CHcy
 * Character: Ч
 * Unicode code point: U+0427 (1063)
 * Description: cyrillic capital letter che
 */
static wchar_t* CHCY_CYRILLIC_CAPITAL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CHcy";
static int* CHCY_CYRILLIC_CAPITAL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SHcy html character entity reference model.
 *
 * Name: SHcy
 * Character: Ш
 * Unicode code point: U+0428 (1064)
 * Description: cyrillic capital letter sha
 */
static wchar_t* SHCY_CYRILLIC_CAPITAL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SHcy";
static int* SHCY_CYRILLIC_CAPITAL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SHCHcy html character entity reference model.
 *
 * Name: SHCHcy
 * Character: Щ
 * Unicode code point: U+0429 (1065)
 * Description: cyrillic capital letter shcha
 */
static wchar_t* SHCHCY_CYRILLIC_CAPITAL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SHCHcy";
static int* SHCHCY_CYRILLIC_CAPITAL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The HARDcy html character entity reference model.
 *
 * Name: HARDcy
 * Character: Ъ
 * Unicode code point: U+042a (1066)
 * Description: cyrillic capital letter hard sign
 */
static wchar_t* HARDCY_CYRILLIC_CAPITAL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HARDcy";
static int* HARDCY_CYRILLIC_CAPITAL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ycy html character entity reference model.
 *
 * Name: Ycy
 * Character: Ы
 * Unicode code point: U+042b (1067)
 * Description: cyrillic capital letter yeru
 */
static wchar_t* YCY_CYRILLIC_CAPITAL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ycy";
static int* YCY_CYRILLIC_CAPITAL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SOFTcy html character entity reference model.
 *
 * Name: SOFTcy
 * Character: Ь
 * Unicode code point: U+042c (1068)
 * Description: cyrillic capital letter soft sign
 */
static wchar_t* SOFTCY_CYRILLIC_CAPITAL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SOFTcy";
static int* SOFTCY_CYRILLIC_CAPITAL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ecy html character entity reference model.
 *
 * Name: Ecy
 * Character: Э
 * Unicode code point: U+042d (1069)
 * Description: cyrillic capital letter e
 */
static wchar_t* ECY_CYRILLIC_CAPITAL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ecy";
static int* ECY_CYRILLIC_CAPITAL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The YUcy html character entity reference model.
 *
 * Name: YUcy
 * Character: Ю
 * Unicode code point: U+042e (1070)
 * Description: cyrillic capital letter yu
 */
static wchar_t* YUCY_CYRILLIC_CAPITAL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YUcy";
static int* YUCY_CYRILLIC_CAPITAL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The YAcy html character entity reference model.
 *
 * Name: YAcy
 * Character: Я
 * Unicode code point: U+042f (1071)
 * Description: cyrillic capital letter ya
 */
static wchar_t* YACY_CYRILLIC_CAPITAL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"YAcy";
static int* YACY_CYRILLIC_CAPITAL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acy html character entity reference model.
 *
 * Name: acy
 * Character: а
 * Unicode code point: U+0430 (1072)
 * Description: cyrillic small letter a
 */
static wchar_t* ACY_CYRILLIC_SMALL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acy";
static int* ACY_CYRILLIC_SMALL_LETTER_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bcy html character entity reference model.
 *
 * Name: bcy
 * Character: б
 * Unicode code point: U+0431 (1073)
 * Description: cyrillic small letter be
 */
static wchar_t* BCY_CYRILLIC_SMALL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bcy";
static int* BCY_CYRILLIC_SMALL_LETTER_BE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vcy html character entity reference model.
 *
 * Name: vcy
 * Character: в
 * Unicode code point: U+0432 (1074)
 * Description: cyrillic small letter ve
 */
static wchar_t* VCY_CYRILLIC_SMALL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vcy";
static int* VCY_CYRILLIC_SMALL_LETTER_VE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gcy html character entity reference model.
 *
 * Name: gcy
 * Character: г
 * Unicode code point: U+0433 (1075)
 * Description: cyrillic small letter ghe
 */
static wchar_t* GCY_CYRILLIC_SMALL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gcy";
static int* GCY_CYRILLIC_SMALL_LETTER_GHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dcy html character entity reference model.
 *
 * Name: dcy
 * Character: д
 * Unicode code point: U+0434 (1076)
 * Description: cyrillic small letter de
 */
static wchar_t* DCY_CYRILLIC_SMALL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dcy";
static int* DCY_CYRILLIC_SMALL_LETTER_DE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iecy html character entity reference model.
 *
 * Name: iecy
 * Character: е
 * Unicode code point: U+0435 (1077)
 * Description: cyrillic small letter ie
 */
static wchar_t* IECY_CYRILLIC_SMALL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iecy";
static int* IECY_CYRILLIC_SMALL_LETTER_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zhcy html character entity reference model.
 *
 * Name: zhcy
 * Character: ж
 * Unicode code point: U+0436 (1078)
 * Description: cyrillic small letter zhe
 */
static wchar_t* ZHCY_CYRILLIC_SMALL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zhcy";
static int* ZHCY_CYRILLIC_SMALL_LETTER_ZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zcy html character entity reference model.
 *
 * Name: zcy
 * Character: з
 * Unicode code point: U+0437 (1079)
 * Description: cyrillic small letter ze
 */
static wchar_t* ZCY_CYRILLIC_SMALL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zcy";
static int* ZCY_CYRILLIC_SMALL_LETTER_ZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The icy html character entity reference model.
 *
 * Name: icy
 * Character: и
 * Unicode code point: U+0438 (1080)
 * Description: cyrillic small letter i
 */
static wchar_t* ICY_CYRILLIC_SMALL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"icy";
static int* ICY_CYRILLIC_SMALL_LETTER_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jcy html character entity reference model.
 *
 * Name: jcy
 * Character: й
 * Unicode code point: U+0439 (1081)
 * Description: cyrillic small letter short i
 */
static wchar_t* JCY_CYRILLIC_SMALL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jcy";
static int* JCY_CYRILLIC_SMALL_LETTER_SHORT_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kcy html character entity reference model.
 *
 * Name: kcy
 * Character: к
 * Unicode code point: U+043a (1082)
 * Description: cyrillic small letter ka
 */
static wchar_t* KCY_CYRILLIC_SMALL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kcy";
static int* KCY_CYRILLIC_SMALL_LETTER_KA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lcy html character entity reference model.
 *
 * Name: lcy
 * Character: л
 * Unicode code point: U+043b (1083)
 * Description: cyrillic small letter el
 */
static wchar_t* LCY_CYRILLIC_SMALL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lcy";
static int* LCY_CYRILLIC_SMALL_LETTER_EL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mcy html character entity reference model.
 *
 * Name: mcy
 * Character: м
 * Unicode code point: U+043c (1084)
 * Description: cyrillic small letter em
 */
static wchar_t* MCY_CYRILLIC_SMALL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mcy";
static int* MCY_CYRILLIC_SMALL_LETTER_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncy html character entity reference model.
 *
 * Name: ncy
 * Character: н
 * Unicode code point: U+043d (1085)
 * Description: cyrillic small letter en
 */
static wchar_t* NCY_CYRILLIC_SMALL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncy";
static int* NCY_CYRILLIC_SMALL_LETTER_EN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ocy html character entity reference model.
 *
 * Name: ocy
 * Character: о
 * Unicode code point: U+043e (1086)
 * Description: cyrillic small letter o
 */
static wchar_t* OCY_CYRILLIC_SMALL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocy";
static int* OCY_CYRILLIC_SMALL_LETTER_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pcy html character entity reference model.
 *
 * Name: pcy
 * Character: п
 * Unicode code point: U+043f (1087)
 * Description: cyrillic small letter pe
 */
static wchar_t* PCY_CYRILLIC_SMALL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pcy";
static int* PCY_CYRILLIC_SMALL_LETTER_PE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rcy html character entity reference model.
 *
 * Name: rcy
 * Character: р
 * Unicode code point: U+0440 (1088)
 * Description: cyrillic small letter er
 */
static wchar_t* RCY_CYRILLIC_SMALL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rcy";
static int* RCY_CYRILLIC_SMALL_LETTER_ER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scy html character entity reference model.
 *
 * Name: scy
 * Character: с
 * Unicode code point: U+0441 (1089)
 * Description: cyrillic small letter es
 */
static wchar_t* SCY_CYRILLIC_SMALL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scy";
static int* SCY_CYRILLIC_SMALL_LETTER_ES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tcy html character entity reference model.
 *
 * Name: tcy
 * Character: т
 * Unicode code point: U+0442 (1090)
 * Description: cyrillic small letter te
 */
static wchar_t* TCY_CYRILLIC_SMALL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tcy";
static int* TCY_CYRILLIC_SMALL_LETTER_TE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ucy html character entity reference model.
 *
 * Name: ucy
 * Character: у
 * Unicode code point: U+0443 (1091)
 * Description: cyrillic small letter u
 */
static wchar_t* UCY_CYRILLIC_SMALL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ucy";
static int* UCY_CYRILLIC_SMALL_LETTER_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fcy html character entity reference model.
 *
 * Name: fcy
 * Character: ф
 * Unicode code point: U+0444 (1092)
 * Description: cyrillic small letter ef
 */
static wchar_t* FCY_CYRILLIC_SMALL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fcy";
static int* FCY_CYRILLIC_SMALL_LETTER_EF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The khcy html character entity reference model.
 *
 * Name: khcy
 * Character: х
 * Unicode code point: U+0445 (1093)
 * Description: cyrillic small letter ha
 */
static wchar_t* KHCY_CYRILLIC_SMALL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"khcy";
static int* KHCY_CYRILLIC_SMALL_LETTER_HA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tscy html character entity reference model.
 *
 * Name: tscy
 * Character: ц
 * Unicode code point: U+0446 (1094)
 * Description: cyrillic small letter tse
 */
static wchar_t* TSCY_CYRILLIC_SMALL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tscy";
static int* TSCY_CYRILLIC_SMALL_LETTER_TSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chcy html character entity reference model.
 *
 * Name: chcy
 * Character: ч
 * Unicode code point: U+0447 (1095)
 * Description: cyrillic small letter che
 */
static wchar_t* CHCY_CYRILLIC_SMALL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"chcy";
static int* CHCY_CYRILLIC_SMALL_LETTER_CHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The shcy html character entity reference model.
 *
 * Name: shcy
 * Character: ш
 * Unicode code point: U+0448 (1096)
 * Description: cyrillic small letter sha
 */
static wchar_t* SHCY_CYRILLIC_SMALL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shcy";
static int* SHCY_CYRILLIC_SMALL_LETTER_SHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The shchcy html character entity reference model.
 *
 * Name: shchcy
 * Character: щ
 * Unicode code point: U+0449 (1097)
 * Description: cyrillic small letter shcha
 */
static wchar_t* SHCHCY_CYRILLIC_SMALL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shchcy";
static int* SHCHCY_CYRILLIC_SMALL_LETTER_SHCHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hardcy html character entity reference model.
 *
 * Name: hardcy
 * Character: ъ
 * Unicode code point: U+044a (1098)
 * Description: cyrillic small letter hard sign
 */
static wchar_t* HARDCY_CYRILLIC_SMALL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hardcy";
static int* HARDCY_CYRILLIC_SMALL_LETTER_HARD_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ycy html character entity reference model.
 *
 * Name: ycy
 * Character: ы
 * Unicode code point: U+044b (1099)
 * Description: cyrillic small letter yeru
 */
static wchar_t* YCY_CYRILLIC_SMALL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ycy";
static int* YCY_CYRILLIC_SMALL_LETTER_YERU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The softcy html character entity reference model.
 *
 * Name: softcy
 * Character: ь
 * Unicode code point: U+044c (1100)
 * Description: cyrillic small letter soft sign
 */
static wchar_t* SOFTCY_CYRILLIC_SMALL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"softcy";
static int* SOFTCY_CYRILLIC_SMALL_LETTER_SOFT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ecy html character entity reference model.
 *
 * Name: ecy
 * Character: э
 * Unicode code point: U+044d (1101)
 * Description: cyrillic small letter e
 */
static wchar_t* ECY_CYRILLIC_SMALL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecy";
static int* ECY_CYRILLIC_SMALL_LETTER_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yucy html character entity reference model.
 *
 * Name: yucy
 * Character: ю
 * Unicode code point: U+044e (1102)
 * Description: cyrillic small letter yu
 */
static wchar_t* YUCY_CYRILLIC_SMALL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yucy";
static int* YUCY_CYRILLIC_SMALL_LETTER_YU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yacy html character entity reference model.
 *
 * Name: yacy
 * Character: я
 * Unicode code point: U+044f (1103)
 * Description: cyrillic small letter ya
 */
static wchar_t* YACY_CYRILLIC_SMALL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yacy";
static int* YACY_CYRILLIC_SMALL_LETTER_YA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iocy html character entity reference model.
 *
 * Name: iocy
 * Character: ё
 * Unicode code point: U+0451 (1105)
 * Description: cyrillic small letter io
 */
static wchar_t* IOCY_CYRILLIC_SMALL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iocy";
static int* IOCY_CYRILLIC_SMALL_LETTER_IO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The djcy html character entity reference model.
 *
 * Name: djcy
 * Character: ђ
 * Unicode code point: U+0452 (1106)
 * Description: cyrillic small letter dje
 */
static wchar_t* DJCY_CYRILLIC_SMALL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"djcy";
static int* DJCY_CYRILLIC_SMALL_LETTER_DJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gjcy html character entity reference model.
 *
 * Name: gjcy
 * Character: ѓ
 * Unicode code point: U+0453 (1107)
 * Description: cyrillic small letter gje
 */
static wchar_t* GJCY_CYRILLIC_SMALL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gjcy";
static int* GJCY_CYRILLIC_SMALL_LETTER_GJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jukcy html character entity reference model.
 *
 * Name: jukcy
 * Character: є
 * Unicode code point: U+0454 (1108)
 * Description: cyrillic small letter ukrainian ie
 */
static wchar_t* JUKCY_CYRILLIC_SMALL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jukcy";
static int* JUKCY_CYRILLIC_SMALL_LETTER_UKRAINIAN_IE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dscy html character entity reference model.
 *
 * Name: dscy
 * Character: ѕ
 * Unicode code point: U+0455 (1109)
 * Description: cyrillic small letter dze
 */
static wchar_t* DSCY_CYRILLIC_SMALL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dscy";
static int* DSCY_CYRILLIC_SMALL_LETTER_DZE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iukcy html character entity reference model.
 *
 * Name: iukcy
 * Character: і
 * Unicode code point: U+0456 (1110)
 * Description: cyrillic small letter byelorussian-ukrainian i
 */
static wchar_t* IUKCY_CYRILLIC_SMALL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iukcy";
static int* IUKCY_CYRILLIC_SMALL_LETTER_BYELORUSSIAN_UKRAINIAN_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yicy html character entity reference model.
 *
 * Name: yicy
 * Character: ї
 * Unicode code point: U+0457 (1111)
 * Description: cyrillic small letter yi
 */
static wchar_t* YICY_CYRILLIC_SMALL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yicy";
static int* YICY_CYRILLIC_SMALL_LETTER_YI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jsercy html character entity reference model.
 *
 * Name: jsercy
 * Character: ј
 * Unicode code point: U+0458 (1112)
 * Description: cyrillic small letter je
 */
static wchar_t* JSERCY_CYRILLIC_SMALL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jsercy";
static int* JSERCY_CYRILLIC_SMALL_LETTER_JE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ljcy html character entity reference model.
 *
 * Name: ljcy
 * Character: љ
 * Unicode code point: U+0459 (1113)
 * Description: cyrillic small letter lje
 */
static wchar_t* LJCY_CYRILLIC_SMALL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ljcy";
static int* LJCY_CYRILLIC_SMALL_LETTER_LJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The njcy html character entity reference model.
 *
 * Name: njcy
 * Character: њ
 * Unicode code point: U+045a (1114)
 * Description: cyrillic small letter nje
 */
static wchar_t* NJCY_CYRILLIC_SMALL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"njcy";
static int* NJCY_CYRILLIC_SMALL_LETTER_NJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tshcy html character entity reference model.
 *
 * Name: tshcy
 * Character: ћ
 * Unicode code point: U+045b (1115)
 * Description: cyrillic small letter tshe
 */
static wchar_t* TSHCY_CYRILLIC_SMALL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tshcy";
static int* TSHCY_CYRILLIC_SMALL_LETTER_TSHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kjcy html character entity reference model.
 *
 * Name: kjcy
 * Character: ќ
 * Unicode code point: U+045c (1116)
 * Description: cyrillic small letter kje
 */
static wchar_t* KJCY_CYRILLIC_SMALL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kjcy";
static int* KJCY_CYRILLIC_SMALL_LETTER_KJE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ubrcy html character entity reference model.
 *
 * Name: ubrcy
 * Character: ў
 * Unicode code point: U+045e (1118)
 * Description: cyrillic small letter short u
 */
static wchar_t* UBRCY_CYRILLIC_SMALL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ubrcy";
static int* UBRCY_CYRILLIC_SMALL_LETTER_SHORT_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dzcy html character entity reference model.
 *
 * Name: dzcy
 * Character: џ
 * Unicode code point: U+045f (1119)
 * Description: cyrillic small letter dzhe
 */
static wchar_t* DZCY_CYRILLIC_SMALL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dzcy";
static int* DZCY_CYRILLIC_SMALL_LETTER_DZHE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ensp html character entity reference model.
 *
 * Name: ensp
 * Character:
 * Unicode code point: U+2002 (8194)
 * Description: en space
 */
static wchar_t* ENSP_EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ensp";
static int* ENSP_EN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emsp html character entity reference model.
 *
 * Name: emsp
 * Character:
 * Unicode code point: U+2003 (8195)
 * Description: em space
 */
static wchar_t* EMSP_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp";
static int* EMSP_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emsp13 html character entity reference model.
 *
 * Name: emsp13
 * Character:
 * Unicode code point: U+2004 (8196)
 * Description: three-per-em space
 */
static wchar_t* EMSP13_THREE_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp13";
static int* EMSP13_THREE_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emsp14 html character entity reference model.
 *
 * Name: emsp14
 * Character:
 * Unicode code point: U+2005 (8197)
 * Description: four-per-em space
 */
static wchar_t* EMSP14_FOUR_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emsp14";
static int* EMSP14_FOUR_PER_EM_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The numsp html character entity reference model.
 *
 * Name: numsp
 * Character:
 * Unicode code point: U+2007 (8199)
 * Description: figure space
 */
static wchar_t* NUMSP_FIGURE_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"numsp";
static int* NUMSP_FIGURE_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The puncsp html character entity reference model.
 *
 * Name: puncsp
 * Character:
 * Unicode code point: U+2008 (8200)
 * Description: punctuation space
 */
static wchar_t* PUNCSP_PUNCTUATION_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"puncsp";
static int* PUNCSP_PUNCTUATION_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ThinSpace html character entity reference model.
 *
 * Name: ThinSpace
 * Character:
 * Unicode code point: U+2009 (8201)
 * Description: thin space
 */
static wchar_t* THINSPACE_THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ThinSpace";
static int* THINSPACE_THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thinsp html character entity reference model.
 *
 * Name: thinsp
 * Character:
 * Unicode code point: U+2009 (8201)
 * Description: thin space
 */
static wchar_t* THINSP_THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thinsp";
static int* THINSP_THIN_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VeryThinSpace html character entity reference model.
 *
 * Name: VeryThinSpace
 * Character:
 * Unicode code point: U+200a (8202)
 * Description: hair space
 */
static wchar_t* VERYTHINSPACE_HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VeryThinSpace";
static int* VERYTHINSPACE_HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hairsp html character entity reference model.
 *
 * Name: hairsp
 * Character:
 * Unicode code point: U+200a (8202)
 * Description: hair space
 */
static wchar_t* HAIRSP_HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hairsp";
static int* HAIRSP_HAIR_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NegativeMediumSpace html character entity reference model.
 *
 * Name: NegativeMediumSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* NEGATIVEMEDIUMSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NegativeMediumSpace";
static int* NEGATIVEMEDIUMSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NegativeThickSpace html character entity reference model.
 *
 * Name: NegativeThickSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* NEGATIVETHICKSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NegativeThickSpace";
static int* NEGATIVETHICKSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NegativeThinSpace html character entity reference model.
 *
 * Name: NegativeThinSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* NEGATIVETHINSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NegativeThinSpace";
static int* NEGATIVETHINSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NegativeVeryThinSpace html character entity reference model.
 *
 * Name: NegativeVeryThinSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* NEGATIVEVERYTHINSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NegativeVeryThinSpace";
static int* NEGATIVEVERYTHINSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ZeroWidthSpace html character entity reference model.
 *
 * Name: ZeroWidthSpace
 * Character: ​
 * Unicode code point: U+200b (8203)
 * Description: zero width space
 */
static wchar_t* ZEROWIDTHSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ZeroWidthSpace";
static int* ZEROWIDTHSPACE_ZERO_WIDTH_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zwnj html character entity reference model.
 *
 * Name: zwnj
 * Character: ‌
 * Unicode code point: U+200c (8204)
 * Description: zero width non-joiner
 */
static wchar_t* ZWNJ_ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwnj";
static int* ZWNJ_ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zwj html character entity reference model.
 *
 * Name: zwj
 * Character: ‍
 * Unicode code point: U+200d (8205)
 * Description: zero width joiner
 */
static wchar_t* ZWJ_ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zwj";
static int* ZWJ_ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrm html character entity reference model.
 *
 * Name: lrm
 * Character: ‎
 * Unicode code point: U+200e (8206)
 * Description: left-to-right mark
 */
static wchar_t* LRM_LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrm";
static int* LRM_LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rlm html character entity reference model.
 *
 * Name: rlm
 * Character: ‏
 * Unicode code point: U+200f (8207)
 * Description: right-to-left mark
 */
static wchar_t* RLM_RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rlm";
static int* RLM_RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dash html character entity reference model.
 *
 * Name: dash
 * Character: ‐
 * Unicode code point: U+2010 (8208)
 * Description: hyphen
 */
static wchar_t* DASH_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dash";
static int* DASH_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hyphen html character entity reference model.
 *
 * Name: hyphen
 * Character: ‐
 * Unicode code point: U+2010 (8208)
 * Description: hyphen
 */
static wchar_t* HYPHEN_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hyphen";
static int* HYPHEN_HYPHEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ndash html character entity reference model.
 *
 * Name: ndash
 * Character: –
 * Unicode code point: U+2013 (8211)
 * Description: en dash
 */
static wchar_t* NDASH_EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ndash";
static int* NDASH_EN_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mdash html character entity reference model.
 *
 * Name: mdash
 * Character: —
 * Unicode code point: U+2014 (8212)
 * Description: em dash
 */
static wchar_t* MDASH_EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mdash";
static int* MDASH_EM_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The horbar html character entity reference model.
 *
 * Name: horbar
 * Character: ―
 * Unicode code point: U+2015 (8213)
 * Description: horizontal bar
 */
static wchar_t* HORBAR_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"horbar";
static int* HORBAR_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Verbar html character entity reference model.
 *
 * Name: Verbar
 * Character: ‖
 * Unicode code point: U+2016 (8214)
 * Description: double vertical line
 */
static wchar_t* VERBAR_DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Verbar";
static int* VERBAR_DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vert html character entity reference model.
 *
 * Name: Vert
 * Character: ‖
 * Unicode code point: U+2016 (8214)
 * Description: double vertical line
 */
static wchar_t* VERT_DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vert";
static int* VERT_DOUBLE_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OpenCurlyQuote html character entity reference model.
 *
 * Name: OpenCurlyQuote
 * Character: ‘
 * Unicode code point: U+2018 (8216)
 * Description: left single quotation mark
 */
static wchar_t* OPENCURLYQUOTE_LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OpenCurlyQuote";
static int* OPENCURLYQUOTE_LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsquo html character entity reference model.
 *
 * Name: lsquo
 * Character: ‘
 * Unicode code point: U+2018 (8216)
 * Description: left single quotation mark
 */
static wchar_t* LSQUO_LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsquo";
static int* LSQUO_LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CloseCurlyQuote html character entity reference model.
 *
 * Name: CloseCurlyQuote
 * Character: ’
 * Unicode code point: U+2019 (8217)
 * Description: right single quotation mark
 */
static wchar_t* CLOSECURLYQUOTE_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CloseCurlyQuote";
static int* CLOSECURLYQUOTE_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rsquo html character entity reference model.
 *
 * Name: rsquo
 * Character: ’
 * Unicode code point: U+2019 (8217)
 * Description: right single quotation mark
 */
static wchar_t* RSQUO_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsquo";
static int* RSQUO_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rsquor html character entity reference model.
 *
 * Name: rsquor
 * Character: ’
 * Unicode code point: U+2019 (8217)
 * Description: right single quotation mark
 */
static wchar_t* RSQUOR_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsquor";
static int* RSQUOR_RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsquor html character entity reference model.
 *
 * Name: lsquor
 * Character: ‚
 * Unicode code point: U+201a (8218)
 * Description: single low-9 quotation mark
 */
static wchar_t* LSQUOR_SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsquor";
static int* LSQUOR_SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sbquo html character entity reference model.
 *
 * Name: sbquo
 * Character: ‚
 * Unicode code point: U+201a (8218)
 * Description: single low-9 quotation mark
 */
static wchar_t* SBQUO_SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sbquo";
static int* SBQUO_SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OpenCurlyDoubleQuote html character entity reference model.
 *
 * Name: OpenCurlyDoubleQuote
 * Character: “
 * Unicode code point: U+201c (8220)
 * Description: left double quotation mark
 */
static wchar_t* OPENCURLYDOUBLEQUOTE_LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OpenCurlyDoubleQuote";
static int* OPENCURLYDOUBLEQUOTE_LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldquo html character entity reference model.
 *
 * Name: ldquo
 * Character: “
 * Unicode code point: U+201c (8220)
 * Description: left double quotation mark
 */
static wchar_t* LDQUO_LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldquo";
static int* LDQUO_LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CloseCurlyDoubleQuote html character entity reference model.
 *
 * Name: CloseCurlyDoubleQuote
 * Character: ”
 * Unicode code point: U+201d (8221)
 * Description: right double quotation mark
 */
static wchar_t* CLOSECURLYDOUBLEQUOTE_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CloseCurlyDoubleQuote";
static int* CLOSECURLYDOUBLEQUOTE_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rdquo html character entity reference model.
 *
 * Name: rdquo
 * Character: ”
 * Unicode code point: U+201d (8221)
 * Description: right double quotation mark
 */
static wchar_t* RDQUO_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdquo";
static int* RDQUO_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rdquor html character entity reference model.
 *
 * Name: rdquor
 * Character: ”
 * Unicode code point: U+201d (8221)
 * Description: right double quotation mark
 */
static wchar_t* RDQUOR_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdquor";
static int* RDQUOR_RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bdquo html character entity reference model.
 *
 * Name: bdquo
 * Character: „
 * Unicode code point: U+201e (8222)
 * Description: double low-9 quotation mark
 */
static wchar_t* BDQUO_DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bdquo";
static int* BDQUO_DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldquor html character entity reference model.
 *
 * Name: ldquor
 * Character: „
 * Unicode code point: U+201e (8222)
 * Description: double low-9 quotation mark
 */
static wchar_t* LDQUOR_DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldquor";
static int* LDQUOR_DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dagger html character entity reference model.
 *
 * Name: dagger
 * Character: †
 * Unicode code point: U+2020 (8224)
 * Description: dagger
 */
static wchar_t* DAGGER_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dagger";
static int* DAGGER_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dagger html character entity reference model.
 *
 * Name: Dagger
 * Character: ‡
 * Unicode code point: U+2021 (8225)
 * Description: double dagger
 */
static wchar_t* DAGGER_DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dagger";
static int* DAGGER_DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ddagger html character entity reference model.
 *
 * Name: ddagger
 * Character: ‡
 * Unicode code point: U+2021 (8225)
 * Description: double dagger
 */
static wchar_t* DDAGGER_DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ddagger";
static int* DDAGGER_DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bull html character entity reference model.
 *
 * Name: bull
 * Character: •
 * Unicode code point: U+2022 (8226)
 * Description: bullet
 */
static wchar_t* BULL_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bull";
static int* BULL_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bullet html character entity reference model.
 *
 * Name: bullet
 * Character: •
 * Unicode code point: U+2022 (8226)
 * Description: bullet
 */
static wchar_t* BULLET_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bullet";
static int* BULLET_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nldr html character entity reference model.
 *
 * Name: nldr
 * Character: ‥
 * Unicode code point: U+2025 (8229)
 * Description: two dot leader
 */
static wchar_t* NLDR_TWO_DOT_LEADER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nldr";
static int* NLDR_TWO_DOT_LEADER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hellip html character entity reference model.
 *
 * Name: hellip
 * Character: …
 * Unicode code point: U+2026 (8230)
 * Description: horizontal ellipsis
 */
static wchar_t* HELLIP_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hellip";
static int* HELLIP_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mldr html character entity reference model.
 *
 * Name: mldr
 * Character: …
 * Unicode code point: U+2026 (8230)
 * Description: horizontal ellipsis
 */
static wchar_t* MLDR_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mldr";
static int* MLDR_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The permil html character entity reference model.
 *
 * Name: permil
 * Character: ‰
 * Unicode code point: U+2030 (8240)
 * Description: per mille sign
 */
static wchar_t* PERMIL_PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"permil";
static int* PERMIL_PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pertenk html character entity reference model.
 *
 * Name: pertenk
 * Character: ‱
 * Unicode code point: U+2031 (8241)
 * Description: per ten thousand sign
 */
static wchar_t* PERTENK_PER_TEN_THOUSAND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pertenk";
static int* PERTENK_PER_TEN_THOUSAND_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prime html character entity reference model.
 *
 * Name: prime
 * Character: ′
 * Unicode code point: U+2032 (8242)
 * Description: prime
 */
static wchar_t* PRIME_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prime";
static int* PRIME_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Prime html character entity reference model.
 *
 * Name: Prime
 * Character: ″
 * Unicode code point: U+2033 (8243)
 * Description: double prime
 */
static wchar_t* PRIME_DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Prime";
static int* PRIME_DOUBLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tprime html character entity reference model.
 *
 * Name: tprime
 * Character: ‴
 * Unicode code point: U+2034 (8244)
 * Description: triple prime
 */
static wchar_t* TPRIME_TRIPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tprime";
static int* TPRIME_TRIPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The backprime html character entity reference model.
 *
 * Name: backprime
 * Character: ‵
 * Unicode code point: U+2035 (8245)
 * Description: reversed prime
 */
static wchar_t* BACKPRIME_REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backprime";
static int* BACKPRIME_REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bprime html character entity reference model.
 *
 * Name: bprime
 * Character: ‵
 * Unicode code point: U+2035 (8245)
 * Description: reversed prime
 */
static wchar_t* BPRIME_REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bprime";
static int* BPRIME_REVERSED_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsaquo html character entity reference model.
 *
 * Name: lsaquo
 * Character: ‹
 * Unicode code point: U+2039 (8249)
 * Description: single left-pointing angle quotation mark
 */
static wchar_t* LSAQUO_SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsaquo";
static int* LSAQUO_SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rsaquo html character entity reference model.
 *
 * Name: rsaquo
 * Character: ›
 * Unicode code point: U+203a (8250)
 * Description: single right-pointing angle quotation mark
 */
static wchar_t* RSAQUO_SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsaquo";
static int* RSAQUO_SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OverBar html character entity reference model.
 *
 * Name: OverBar
 * Character: ‾
 * Unicode code point: U+203e (8254)
 * Description: overline
 */
static wchar_t* OVERBAR_OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBar";
static int* OVERBAR_OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oline html character entity reference model.
 *
 * Name: oline
 * Character: ‾
 * Unicode code point: U+203e (8254)
 * Description: overline
 */
static wchar_t* OLINE_OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oline";
static int* OLINE_OVERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The caret html character entity reference model.
 *
 * Name: caret
 * Character: ⁁
 * Unicode code point: U+2041 (8257)
 * Description: caret insertion point
 */
static wchar_t* CARET_CARET_INSERTION_POINT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"caret";
static int* CARET_CARET_INSERTION_POINT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hybull html character entity reference model.
 *
 * Name: hybull
 * Character: ⁃
 * Unicode code point: U+2043 (8259)
 * Description: hyphen bullet
 */
static wchar_t* HYBULL_HYPHEN_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hybull";
static int* HYBULL_HYPHEN_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frasl html character entity reference model.
 *
 * Name: frasl
 * Character: ⁄
 * Unicode code point: U+2044 (8260)
 * Description: fraction slash
 */
static wchar_t* FRASL_FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frasl";
static int* FRASL_FRACTION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsemi html character entity reference model.
 *
 * Name: bsemi
 * Character: ⁏
 * Unicode code point: U+204f (8271)
 * Description: reversed semicolon
 */
static wchar_t* BSEMI_REVERSED_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsemi";
static int* BSEMI_REVERSED_SEMICOLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qprime html character entity reference model.
 *
 * Name: qprime
 * Character: ⁗
 * Unicode code point: U+2057 (8279)
 * Description: quadruple prime
 */
static wchar_t* QPRIME_QUADRUPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qprime";
static int* QPRIME_QUADRUPLE_PRIME_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The MediumSpace html character entity reference model.
 *
 * Name: MediumSpace
 * Character:
 * Unicode code point: U+205f (8287)
 * Description: medium mathematical space
 */
static wchar_t* MEDIUMSPACE_MEDIUM_MATHEMATICAL_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"MediumSpace";
static int* MEDIUMSPACE_MEDIUM_MATHEMATICAL_SPACE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ThickSpace html character entity reference model.
 *
 * Name: ThickSpace
 * Character:
 * Unicode code point: U+205f;U+200a (8287;8202)
 * Description: space of width 5/18 em
 */
static wchar_t* THICKSPACE_SPACE_OF_WIDTH_5_18_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ThickSpace";
static int* THICKSPACE_SPACE_OF_WIDTH_5_18_EM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NoBreak html character entity reference model.
 *
 * Name: NoBreak
 * Character: ⁠
 * Unicode code point: U+2060 (8288)
 * Description: word joiner
 */
static wchar_t* NOBREAK_WORD_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NoBreak";
static int* NOBREAK_WORD_JOINER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ApplyFunction html character entity reference model.
 *
 * Name: ApplyFunction
 * Character: ⁡
 * Unicode code point: U+2061 (8289)
 * Description: function application
 */
static wchar_t* APPLYFUNCTION_FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ApplyFunction";
static int* APPLYFUNCTION_FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The af html character entity reference model.
 *
 * Name: af
 * Character: ⁡
 * Unicode code point: U+2061 (8289)
 * Description: function application
 */
static wchar_t* AF_FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"af";
static int* AF_FUNCTION_APPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The InvisibleTimes html character entity reference model.
 *
 * Name: InvisibleTimes
 * Character: ⁢
 * Unicode code point: U+2062 (8290)
 * Description: invisible times
 */
static wchar_t* INVISIBLETIMES_INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"InvisibleTimes";
static int* INVISIBLETIMES_INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The it html character entity reference model.
 *
 * Name: it
 * Character: ⁢
 * Unicode code point: U+2062 (8290)
 * Description: invisible times
 */
static wchar_t* IT_INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"it";
static int* IT_INVISIBLE_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The InvisibleComma html character entity reference model.
 *
 * Name: InvisibleComma
 * Character: ⁣
 * Unicode code point: U+2063 (8291)
 * Description: invisible separator
 */
static wchar_t* INVISIBLECOMMA_INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"InvisibleComma";
static int* INVISIBLECOMMA_INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ic html character entity reference model.
 *
 * Name: ic
 * Character: ⁣
 * Unicode code point: U+2063 (8291)
 * Description: invisible separator
 */
static wchar_t* IC_INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ic";
static int* IC_INVISIBLE_SEPARATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The euro html character entity reference model.
 *
 * Name: euro
 * Character: €
 * Unicode code point: U+20ac (8364)
 * Description: euro sign
 */
static wchar_t* EURO_EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"euro";
static int* EURO_EURO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TripleDot html character entity reference model.
 *
 * Name: TripleDot
 * Character:  ⃛
 * Unicode code point: U+20db (8411)
 * Description: combining three dots above
 */
static wchar_t* TRIPLEDOT_COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TripleDot";
static int* TRIPLEDOT_COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tdot html character entity reference model.
 *
 * Name: tdot
 * Character:  ⃛
 * Unicode code point: U+20db (8411)
 * Description: combining three dots above
 */
static wchar_t* TDOT_COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tdot";
static int* TDOT_COMBINING_THREE_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DotDot html character entity reference model.
 *
 * Name: DotDot
 * Character:  ⃜
 * Unicode code point: U+20dc (8412)
 * Description: combining four dots above
 */
static wchar_t* DOTDOT_COMBINING_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DotDot";
static int* DOTDOT_COMBINING_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Copf html character entity reference model.
 *
 * Name: Copf
 * Character: ℂ
 * Unicode code point: U+2102 (8450)
 * Description: double-struck capital c
 */
static wchar_t* COPF_DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Copf";
static int* COPF_DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The complexes html character entity reference model.
 *
 * Name: complexes
 * Character: ℂ
 * Unicode code point: U+2102 (8450)
 * Description: double-struck capital c
 */
static wchar_t* COMPLEXES_DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"complexes";
static int* COMPLEXES_DOUBLE_STRUCK_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The incare html character entity reference model.
 *
 * Name: incare
 * Character: ℅
 * Unicode code point: U+2105 (8453)
 * Description: care of
 */
static wchar_t* INCARE_CARE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"incare";
static int* INCARE_CARE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gscr html character entity reference model.
 *
 * Name: gscr
 * Character: ℊ
 * Unicode code point: U+210a (8458)
 * Description: script small g
 */
static wchar_t* GSCR_SCRIPT_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gscr";
static int* GSCR_SCRIPT_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The HilbertSpace html character entity reference model.
 *
 * Name: HilbertSpace
 * Character: ℋ
 * Unicode code point: U+210b (8459)
 * Description: script capital h
 */
static wchar_t* HILBERTSPACE_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HilbertSpace";
static int* HILBERTSPACE_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hscr html character entity reference model.
 *
 * Name: Hscr
 * Character: ℋ
 * Unicode code point: U+210b (8459)
 * Description: script capital h
 */
static wchar_t* HSCR_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hscr";
static int* HSCR_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hamilt html character entity reference model.
 *
 * Name: hamilt
 * Character: ℋ
 * Unicode code point: U+210b (8459)
 * Description: script capital h
 */
static wchar_t* HAMILT_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hamilt";
static int* HAMILT_SCRIPT_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hfr html character entity reference model.
 *
 * Name: Hfr
 * Character: ℌ
 * Unicode code point: U+210c (8460)
 * Description: black-letter capital h
 */
static wchar_t* HFR_BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hfr";
static int* HFR_BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Poincareplane html character entity reference model.
 *
 * Name: Poincareplane
 * Character: ℌ
 * Unicode code point: U+210c (8460)
 * Description: black-letter capital h
 */
static wchar_t* POINCAREPLANE_BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Poincareplane";
static int* POINCAREPLANE_BLACK_LETTER_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Hopf html character entity reference model.
 *
 * Name: Hopf
 * Character: ℍ
 * Unicode code point: U+210d (8461)
 * Description: double-struck capital h
 */
static wchar_t* HOPF_DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Hopf";
static int* HOPF_DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quaternions html character entity reference model.
 *
 * Name: quaternions
 * Character: ℍ
 * Unicode code point: U+210d (8461)
 * Description: double-struck capital h
 */
static wchar_t* QUATERNIONS_DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quaternions";
static int* QUATERNIONS_DOUBLE_STRUCK_CAPITAL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The planckh html character entity reference model.
 *
 * Name: planckh
 * Character: ℎ
 * Unicode code point: U+210e (8462)
 * Description: planck constant
 */
static wchar_t* PLANCKH_PLANCK_CONSTANT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"planckh";
static int* PLANCKH_PLANCK_CONSTANT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hbar html character entity reference model.
 *
 * Name: hbar
 * Character: ℏ
 * Unicode code point: U+210f (8463)
 * Description: planck constant over two pi
 */
static wchar_t* HBAR_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hbar";
static int* HBAR_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hslash html character entity reference model.
 *
 * Name: hslash
 * Character: ℏ
 * Unicode code point: U+210f (8463)
 * Description: planck constant over two pi
 */
static wchar_t* HSLASH_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hslash";
static int* HSLASH_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The planck html character entity reference model.
 *
 * Name: planck
 * Character: ℏ
 * Unicode code point: U+210f (8463)
 * Description: planck constant over two pi
 */
static wchar_t* PLANCK_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"planck";
static int* PLANCK_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plankv html character entity reference model.
 *
 * Name: plankv
 * Character: ℏ
 * Unicode code point: U+210f (8463)
 * Description: planck constant over two pi
 */
static wchar_t* PLANKV_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plankv";
static int* PLANKV_PLANCK_CONSTANT_OVER_TWO_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iscr html character entity reference model.
 *
 * Name: Iscr
 * Character: ℐ
 * Unicode code point: U+2110 (8464)
 * Description: script capital i
 */
static wchar_t* ISCR_SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iscr";
static int* ISCR_SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imagline html character entity reference model.
 *
 * Name: imagline
 * Character: ℐ
 * Unicode code point: U+2110 (8464)
 * Description: script capital i
 */
static wchar_t* IMAGLINE_SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imagline";
static int* IMAGLINE_SCRIPT_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ifr html character entity reference model.
 *
 * Name: Ifr
 * Character: ℑ
 * Unicode code point: U+2111 (8465)
 * Description: black-letter capital i
 */
static wchar_t* IFR_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ifr";
static int* IFR_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Im html character entity reference model.
 *
 * Name: Im
 * Character: ℑ
 * Unicode code point: U+2111 (8465)
 * Description: black-letter capital i
 */
static wchar_t* IM_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Im";
static int* IM_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image html character entity reference model.
 *
 * Name: image
 * Character: ℑ
 * Unicode code point: U+2111 (8465)
 * Description: black-letter capital i
 */
static wchar_t* IMAGE_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"image";
static int* IMAGE_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imagpart html character entity reference model.
 *
 * Name: imagpart
 * Character: ℑ
 * Unicode code point: U+2111 (8465)
 * Description: black-letter capital i
 */
static wchar_t* IMAGPART_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imagpart";
static int* IMAGPART_BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Laplacetrf html character entity reference model.
 *
 * Name: Laplacetrf
 * Character: ℒ
 * Unicode code point: U+2112 (8466)
 * Description: script capital l
 */
static wchar_t* LAPLACETRF_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Laplacetrf";
static int* LAPLACETRF_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lscr html character entity reference model.
 *
 * Name: Lscr
 * Character: ℒ
 * Unicode code point: U+2112 (8466)
 * Description: script capital l
 */
static wchar_t* LSCR_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lscr";
static int* LSCR_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lagran html character entity reference model.
 *
 * Name: lagran
 * Character: ℒ
 * Unicode code point: U+2112 (8466)
 * Description: script capital l
 */
static wchar_t* LAGRAN_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lagran";
static int* LAGRAN_SCRIPT_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ell html character entity reference model.
 *
 * Name: ell
 * Character: ℓ
 * Unicode code point: U+2113 (8467)
 * Description: script small l
 */
static wchar_t* ELL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ell";
static int* ELL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Nopf html character entity reference model.
 *
 * Name: Nopf
 * Character: ℕ
 * Unicode code point: U+2115 (8469)
 * Description: double-struck capital n
 */
static wchar_t* NOPF_DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nopf";
static int* NOPF_DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The naturals html character entity reference model.
 *
 * Name: naturals
 * Character: ℕ
 * Unicode code point: U+2115 (8469)
 * Description: double-struck capital n
 */
static wchar_t* NATURALS_DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"naturals";
static int* NATURALS_DOUBLE_STRUCK_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The numero html character entity reference model.
 *
 * Name: numero
 * Character: №
 * Unicode code point: U+2116 (8470)
 * Description: numero sign
 */
static wchar_t* NUMERO_NUMERO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"numero";
static int* NUMERO_NUMERO_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The copysr html character entity reference model.
 *
 * Name: copysr
 * Character: ℗
 * Unicode code point: U+2117 (8471)
 * Description: sound recording copyright
 */
static wchar_t* COPYSR_SOUND_RECORDING_COPYRIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copysr";
static int* COPYSR_SOUND_RECORDING_COPYRIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The weierp html character entity reference model.
 *
 * Name: weierp
 * Character: ℘
 * Unicode code point: U+2118 (8472)
 * Description: script capital p
 */
static wchar_t* WEIERP_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"weierp";
static int* WEIERP_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wp html character entity reference model.
 *
 * Name: wp
 * Character: ℘
 * Unicode code point: U+2118 (8472)
 * Description: script capital p
 */
static wchar_t* WP_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wp";
static int* WP_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Popf html character entity reference model.
 *
 * Name: Popf
 * Character: ℙ
 * Unicode code point: U+2119 (8473)
 * Description: double-struck capital p
 */
static wchar_t* POPF_DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Popf";
static int* POPF_DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The primes html character entity reference model.
 *
 * Name: primes
 * Character: ℙ
 * Unicode code point: U+2119 (8473)
 * Description: double-struck capital p
 */
static wchar_t* PRIMES_DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"primes";
static int* PRIMES_DOUBLE_STRUCK_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Qopf html character entity reference model.
 *
 * Name: Qopf
 * Character: ℚ
 * Unicode code point: U+211a (8474)
 * Description: double-struck capital q
 */
static wchar_t* QOPF_DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qopf";
static int* QOPF_DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rationals html character entity reference model.
 *
 * Name: rationals
 * Character: ℚ
 * Unicode code point: U+211a (8474)
 * Description: double-struck capital q
 */
static wchar_t* RATIONALS_DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rationals";
static int* RATIONALS_DOUBLE_STRUCK_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rscr html character entity reference model.
 *
 * Name: Rscr
 * Character: ℛ
 * Unicode code point: U+211b (8475)
 * Description: script capital r
 */
static wchar_t* RSCR_SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rscr";
static int* RSCR_SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The realine html character entity reference model.
 *
 * Name: realine
 * Character: ℛ
 * Unicode code point: U+211b (8475)
 * Description: script capital r
 */
static wchar_t* REALINE_SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"realine";
static int* REALINE_SCRIPT_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Re html character entity reference model.
 *
 * Name: Re
 * Character: ℜ
 * Unicode code point: U+211c (8476)
 * Description: black-letter capital r
 */
static wchar_t* RE_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Re";
static int* RE_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rfr html character entity reference model.
 *
 * Name: Rfr
 * Character: ℜ
 * Unicode code point: U+211c (8476)
 * Description: black-letter capital r
 */
static wchar_t* RFR_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rfr";
static int* RFR_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The real html character entity reference model.
 *
 * Name: real
 * Character: ℜ
 * Unicode code point: U+211c (8476)
 * Description: black-letter capital r
 */
static wchar_t* REAL_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"real";
static int* REAL_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The realpart html character entity reference model.
 *
 * Name: realpart
 * Character: ℜ
 * Unicode code point: U+211c (8476)
 * Description: black-letter capital r
 */
static wchar_t* REALPART_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"realpart";
static int* REALPART_BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ropf html character entity reference model.
 *
 * Name: Ropf
 * Character: ℝ
 * Unicode code point: U+211d (8477)
 * Description: double-struck capital r
 */
static wchar_t* ROPF_DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ropf";
static int* ROPF_DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reals html character entity reference model.
 *
 * Name: reals
 * Character: ℝ
 * Unicode code point: U+211d (8477)
 * Description: double-struck capital r
 */
static wchar_t* REALS_DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"reals";
static int* REALS_DOUBLE_STRUCK_CAPITAL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rx html character entity reference model.
 *
 * Name: rx
 * Character: ℞
 * Unicode code point: U+211e (8478)
 * Description: prescription take
 */
static wchar_t* RX_PRESCRIPTION_TAKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rx";
static int* RX_PRESCRIPTION_TAKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TRADE html character entity reference model.
 *
 * Name: TRADE
 * Character: ™
 * Unicode code point: U+2122 (8482)
 * Description: trade mark sign
 */
static wchar_t* CAPITAL_TRADE_TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TRADE";
static int* CAPITAL_TRADE_TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trade html character entity reference model.
 *
 * Name: trade
 * Character: ™
 * Unicode code point: U+2122 (8482)
 * Description: trade mark sign
 */
static wchar_t* SMALL_TRADE_TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trade";
static int* SMALL_TRADE_TRADE_MARK_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zopf html character entity reference model.
 *
 * Name: Zopf
 * Character: ℤ
 * Unicode code point: U+2124 (8484)
 * Description: double-struck capital z
 */
static wchar_t* ZOPF_DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zopf";
static int* ZOPF_DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The integers html character entity reference model.
 *
 * Name: integers
 * Character: ℤ
 * Unicode code point: U+2124 (8484)
 * Description: double-struck capital z
 */
static wchar_t* INTEGERS_DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"integers";
static int* INTEGERS_DOUBLE_STRUCK_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mho html character entity reference model.
 *
 * Name: mho
 * Character: ℧
 * Unicode code point: U+2127 (8487)
 * Description: inverted ohm sign
 */
static wchar_t* MHO_INVERTED_OHM_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mho";
static int* MHO_INVERTED_OHM_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zfr html character entity reference model.
 *
 * Name: Zfr
 * Character: ℨ
 * Unicode code point: U+2128 (8488)
 * Description: black-letter capital z
 */
static wchar_t* ZFR_BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zfr";
static int* ZFR_BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zeetrf html character entity reference model.
 *
 * Name: zeetrf
 * Character: ℨ
 * Unicode code point: U+2128 (8488)
 * Description: black-letter capital z
 */
static wchar_t* ZEETRF_BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zeetrf";
static int* ZEETRF_BLACK_LETTER_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iiota html character entity reference model.
 *
 * Name: iiota
 * Character: ℩
 * Unicode code point: U+2129 (8489)
 * Description: turned greek small letter iota
 */
static wchar_t* IIOTA_TURNED_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiota";
static int* IIOTA_TURNED_GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bernoullis html character entity reference model.
 *
 * Name: Bernoullis
 * Character: ℬ
 * Unicode code point: U+212c (8492)
 * Description: script capital b
 */
static wchar_t* BERNOULLIS_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bernoullis";
static int* BERNOULLIS_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bscr html character entity reference model.
 *
 * Name: Bscr
 * Character: ℬ
 * Unicode code point: U+212c (8492)
 * Description: script capital b
 */
static wchar_t* BSCR_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bscr";
static int* BSCR_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bernou html character entity reference model.
 *
 * Name: bernou
 * Character: ℬ
 * Unicode code point: U+212c (8492)
 * Description: script capital b
 */
static wchar_t* BERNOU_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bernou";
static int* BERNOU_SCRIPT_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cayleys html character entity reference model.
 *
 * Name: Cayleys
 * Character: ℭ
 * Unicode code point: U+212d (8493)
 * Description: black-letter capital c
 */
static wchar_t* CAYLEYS_BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cayleys";
static int* CAYLEYS_BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cfr html character entity reference model.
 *
 * Name: Cfr
 * Character: ℭ
 * Unicode code point: U+212d (8493)
 * Description: black-letter capital c
 */
static wchar_t* CFR_BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cfr";
static int* CFR_BLACK_LETTER_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The escr html character entity reference model.
 *
 * Name: escr
 * Character: ℯ
 * Unicode code point: U+212f (8495)
 * Description: script small e
 */
static wchar_t* ESCR_SCRIPT_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"escr";
static int* ESCR_SCRIPT_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Escr html character entity reference model.
 *
 * Name: Escr
 * Character: ℰ
 * Unicode code point: U+2130 (8496)
 * Description: script capital e
 */
static wchar_t* ESCR_SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Escr";
static int* ESCR_SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The expectation html character entity reference model.
 *
 * Name: expectation
 * Character: ℰ
 * Unicode code point: U+2130 (8496)
 * Description: script capital e
 */
static wchar_t* EXPECTATION_SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"expectation";
static int* EXPECTATION_SCRIPT_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Fouriertrf html character entity reference model.
 *
 * Name: Fouriertrf
 * Character: ℱ
 * Unicode code point: U+2131 (8497)
 * Description: script capital f
 */
static wchar_t* FOURIERTRF_SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fouriertrf";
static int* FOURIERTRF_SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Fscr html character entity reference model.
 *
 * Name: Fscr
 * Character: ℱ
 * Unicode code point: U+2131 (8497)
 * Description: script capital f
 */
static wchar_t* FSCR_SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fscr";
static int* FSCR_SCRIPT_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mellintrf html character entity reference model.
 *
 * Name: Mellintrf
 * Character: ℳ
 * Unicode code point: U+2133 (8499)
 * Description: script capital m
 */
static wchar_t* MELLINTRF_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mellintrf";
static int* MELLINTRF_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mscr html character entity reference model.
 *
 * Name: Mscr
 * Character: ℳ
 * Unicode code point: U+2133 (8499)
 * Description: script capital m
 */
static wchar_t* MSCR_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mscr";
static int* MSCR_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The phmmat html character entity reference model.
 *
 * Name: phmmat
 * Character: ℳ
 * Unicode code point: U+2133 (8499)
 * Description: script capital m
 */
static wchar_t* PHMMAT_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phmmat";
static int* PHMMAT_SCRIPT_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The order html character entity reference model.
 *
 * Name: order
 * Character: ℴ
 * Unicode code point: U+2134 (8500)
 * Description: script small o
 */
static wchar_t* ORDER_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"order";
static int* ORDER_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The orderof html character entity reference model.
 *
 * Name: orderof
 * Character: ℴ
 * Unicode code point: U+2134 (8500)
 * Description: script small o
 */
static wchar_t* ORDEROF_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orderof";
static int* ORDEROF_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oscr html character entity reference model.
 *
 * Name: oscr
 * Character: ℴ
 * Unicode code point: U+2134 (8500)
 * Description: script small o
 */
static wchar_t* OSCR_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oscr";
static int* OSCR_SCRIPT_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alefsym html character entity reference model.
 *
 * Name: alefsym
 * Character: ℵ
 * Unicode code point: U+2135 (8501)
 * Description: alef symbol
 */
static wchar_t* ALEFSYM_ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"alefsym";
static int* ALEFSYM_ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aleph html character entity reference model.
 *
 * Name: aleph
 * Character: ℵ
 * Unicode code point: U+2135 (8501)
 * Description: alef symbol
 */
static wchar_t* ALEPH_ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aleph";
static int* ALEPH_ALEF_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The beth html character entity reference model.
 *
 * Name: beth
 * Character: ℶ
 * Unicode code point: U+2136 (8502)
 * Description: bet symbol
 */
static wchar_t* BETH_BET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"beth";
static int* BETH_BET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gimel html character entity reference model.
 *
 * Name: gimel
 * Character: ℷ
 * Unicode code point: U+2137 (8503)
 * Description: gimel symbol
 */
static wchar_t* GIMEL_GIMEL_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gimel";
static int* GIMEL_GIMEL_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The daleth html character entity reference model.
 *
 * Name: daleth
 * Character: ℸ
 * Unicode code point: U+2138 (8504)
 * Description: dalet symbol
 */
static wchar_t* DALETH_DALET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"daleth";
static int* DALETH_DALET_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CapitalDifferentialD html character entity reference model.
 *
 * Name: CapitalDifferentialD
 * Character: ⅅ
 * Unicode code point: U+2145 (8517)
 * Description: double-struck italic capital d
 */
static wchar_t* CAPITALDIFFERENTIALD_DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CapitalDifferentialD";
static int* CAPITALDIFFERENTIALD_DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DD html character entity reference model.
 *
 * Name: DD
 * Character: ⅅ
 * Unicode code point: U+2145 (8517)
 * Description: double-struck italic capital d
 */
static wchar_t* DD_DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DD";
static int* DD_DOUBLE_STRUCK_ITALIC_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DifferentialD html character entity reference model.
 *
 * Name: DifferentialD
 * Character: ⅆ
 * Unicode code point: U+2146 (8518)
 * Description: double-struck italic small d
 */
static wchar_t* DIFFERENTIALD_DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DifferentialD";
static int* DIFFERENTIALD_DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dd html character entity reference model.
 *
 * Name: dd
 * Character: ⅆ
 * Unicode code point: U+2146 (8518)
 * Description: double-struck italic small d
 */
static wchar_t* DD_DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dd";
static int* DD_DOUBLE_STRUCK_ITALIC_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ExponentialE html character entity reference model.
 *
 * Name: ExponentialE
 * Character: ⅇ
 * Unicode code point: U+2147 (8519)
 * Description: double-struck italic small e
 */
static wchar_t* CAMEL_EXPONENTIALE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ExponentialE";
static int* CAMEL_EXPONENTIALE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ee html character entity reference model.
 *
 * Name: ee
 * Character: ⅇ
 * Unicode code point: U+2147 (8519)
 * Description: double-struck italic small e
 */
static wchar_t* EE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ee";
static int* EE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The exponentiale html character entity reference model.
 *
 * Name: exponentiale
 * Character: ⅇ
 * Unicode code point: U+2147 (8519)
 * Description: double-struck italic small e
 */
static wchar_t* SMALL_EXPONENTIALE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"exponentiale";
static int* SMALL_EXPONENTIALE_DOUBLE_STRUCK_ITALIC_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ImaginaryI html character entity reference model.
 *
 * Name: ImaginaryI
 * Character: ⅈ
 * Unicode code point: U+2148 (8520)
 * Description: double-struck italic small i
 */
static wchar_t* IMAGINARYI_DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ImaginaryI";
static int* IMAGINARYI_DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ii html character entity reference model.
 *
 * Name: ii
 * Character: ⅈ
 * Unicode code point: U+2148 (8520)
 * Description: double-struck italic small i
 */
static wchar_t* II_DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ii";
static int* II_DOUBLE_STRUCK_ITALIC_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac13 html character entity reference model.
 *
 * Name: frac13
 * Character: ⅓
 * Unicode code point: U+2153 (8531)
 * Description: vulgar fraction one third
 */
static wchar_t* FRAC13_VULGAR_FRACTION_ONE_THIRD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac13";
static int* FRAC13_VULGAR_FRACTION_ONE_THIRD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac23 html character entity reference model.
 *
 * Name: frac23
 * Character: ⅔
 * Unicode code point: U+2154 (8532)
 * Description: vulgar fraction two thirds
 */
static wchar_t* FRAC23_VULGAR_FRACTION_TWO_THIRDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac23";
static int* FRAC23_VULGAR_FRACTION_TWO_THIRDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac15 html character entity reference model.
 *
 * Name: frac15
 * Character: ⅕
 * Unicode code point: U+2155 (8533)
 * Description: vulgar fraction one fifth
 */
static wchar_t* FRAC15_VULGAR_FRACTION_ONE_FIFTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac15";
static int* FRAC15_VULGAR_FRACTION_ONE_FIFTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac25 html character entity reference model.
 *
 * Name: frac25
 * Character: ⅖
 * Unicode code point: U+2156 (8534)
 * Description: vulgar fraction two fifths
 */
static wchar_t* FRAC25_VULGAR_FRACTION_TWO_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac25";
static int* FRAC25_VULGAR_FRACTION_TWO_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac35 html character entity reference model.
 *
 * Name: frac35
 * Character: ⅗
 * Unicode code point: U+2157 (8535)
 * Description: vulgar fraction three fifths
 */
static wchar_t* FRAC35_VULGAR_FRACTION_THREE_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac35";
static int* FRAC35_VULGAR_FRACTION_THREE_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac45 html character entity reference model.
 *
 * Name: frac45
 * Character: ⅘
 * Unicode code point: U+2158 (8536)
 * Description: vulgar fraction four fifths
 */
static wchar_t* FRAC45_VULGAR_FRACTION_FOUR_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac45";
static int* FRAC45_VULGAR_FRACTION_FOUR_FIFTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac16 html character entity reference model.
 *
 * Name: frac16
 * Character: ⅙
 * Unicode code point: U+2159 (8537)
 * Description: vulgar fraction one sixth
 */
static wchar_t* FRAC16_VULGAR_FRACTION_ONE_SIXTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac16";
static int* FRAC16_VULGAR_FRACTION_ONE_SIXTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac56 html character entity reference model.
 *
 * Name: frac56
 * Character: ⅚
 * Unicode code point: U+215a (8538)
 * Description: vulgar fraction five sixths
 */
static wchar_t* FRAC56_VULGAR_FRACTION_FIVE_SIXTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac56";
static int* FRAC56_VULGAR_FRACTION_FIVE_SIXTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac18 html character entity reference model.
 *
 * Name: frac18
 * Character: ⅛
 * Unicode code point: U+215b (8539)
 * Description: vulgar fraction one eighth
 */
static wchar_t* FRAC18_VULGAR_FRACTION_ONE_EIGHTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac18";
static int* FRAC18_VULGAR_FRACTION_ONE_EIGHTH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac38 html character entity reference model.
 *
 * Name: frac38
 * Character: ⅜
 * Unicode code point: U+215c (8540)
 * Description: vulgar fraction three eighths
 */
static wchar_t* FRAC38_VULGAR_FRACTION_THREE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac38";
static int* FRAC38_VULGAR_FRACTION_THREE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac58 html character entity reference model.
 *
 * Name: frac58
 * Character: ⅝
 * Unicode code point: U+215d (8541)
 * Description: vulgar fraction five eighths
 */
static wchar_t* FRAC58_VULGAR_FRACTION_FIVE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac58";
static int* FRAC58_VULGAR_FRACTION_FIVE_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frac78 html character entity reference model.
 *
 * Name: frac78
 * Character: ⅞
 * Unicode code point: U+215e (8542)
 * Description: vulgar fraction seven eighths
 */
static wchar_t* FRAC78_VULGAR_FRACTION_SEVEN_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frac78";
static int* FRAC78_VULGAR_FRACTION_SEVEN_EIGHTHS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftArrow html character entity reference model.
 *
 * Name: LeftArrow
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* CAMEL_LEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrow";
static int* CAMEL_LEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ShortLeftArrow html character entity reference model.
 *
 * Name: ShortLeftArrow
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* SHORTLEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ShortLeftArrow";
static int* SHORTLEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larr html character entity reference model.
 *
 * Name: larr
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* LARR_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larr";
static int* LARR_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftarrow html character entity reference model.
 *
 * Name: leftarrow
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* SMALL_LEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftarrow";
static int* SMALL_LEFTARROW_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The slarr html character entity reference model.
 *
 * Name: slarr
 * Character: ←
 * Unicode code point: U+2190 (8592)
 * Description: leftwards arrow
 */
static wchar_t* SLARR_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"slarr";
static int* SLARR_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ShortUpArrow html character entity reference model.
 *
 * Name: ShortUpArrow
 * Character: ↑
 * Unicode code point: U+2191 (8593)
 * Description: upwards arrow
 */
static wchar_t* SHORTUPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ShortUpArrow";
static int* SHORTUPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpArrow html character entity reference model.
 *
 * Name: UpArrow
 * Character: ↑
 * Unicode code point: U+2191 (8593)
 * Description: upwards arrow
 */
static wchar_t* CAMEL_UPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpArrow";
static int* CAMEL_UPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uarr html character entity reference model.
 *
 * Name: uarr
 * Character: ↑
 * Unicode code point: U+2191 (8593)
 * Description: upwards arrow
 */
static wchar_t* UARR_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uarr";
static int* UARR_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uparrow html character entity reference model.
 *
 * Name: uparrow
 * Character: ↑
 * Unicode code point: U+2191 (8593)
 * Description: upwards arrow
 */
static wchar_t* SMALL_UPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uparrow";
static int* SMALL_UPARROW_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightArrow html character entity reference model.
 *
 * Name: RightArrow
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* CAMEL_RIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrow";
static int* CAMEL_RIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ShortRightArrow html character entity reference model.
 *
 * Name: ShortRightArrow
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* SHORTRIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ShortRightArrow";
static int* SHORTRIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarr html character entity reference model.
 *
 * Name: rarr
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* RARR_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarr";
static int* RARR_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightarrow html character entity reference model.
 *
 * Name: rightarrow
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* SMALL_RIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightarrow";
static int* SMALL_RIGHTARROW_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The srarr html character entity reference model.
 *
 * Name: srarr
 * Character: →
 * Unicode code point: U+2192 (8594)
 * Description: rightwards arrow
 */
static wchar_t* SRARR_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"srarr";
static int* SRARR_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownArrow html character entity reference model.
 *
 * Name: DownArrow
 * Character: ↓
 * Unicode code point: U+2193 (8595)
 * Description: downwards arrow
 */
static wchar_t* CAMEL_DOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrow";
static int* CAMEL_DOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ShortDownArrow html character entity reference model.
 *
 * Name: ShortDownArrow
 * Character: ↓
 * Unicode code point: U+2193 (8595)
 * Description: downwards arrow
 */
static wchar_t* SHORTDOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ShortDownArrow";
static int* SHORTDOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The darr html character entity reference model.
 *
 * Name: darr
 * Character: ↓
 * Unicode code point: U+2193 (8595)
 * Description: downwards arrow
 */
static wchar_t* DARR_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"darr";
static int* DARR_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downarrow html character entity reference model.
 *
 * Name: downarrow
 * Character: ↓
 * Unicode code point: U+2193 (8595)
 * Description: downwards arrow
 */
static wchar_t* SMALL_DOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"downarrow";
static int* SMALL_DOWNARROW_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftRightArrow html character entity reference model.
 *
 * Name: LeftRightArrow
 * Character: ↔
 * Unicode code point: U+2194 (8596)
 * Description: left right arrow
 */
static wchar_t* CAMEL_LEFTRIGHTARROW_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftRightArrow";
static int* CAMEL_LEFTRIGHTARROW_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The harr html character entity reference model.
 *
 * Name: harr
 * Character: ↔
 * Unicode code point: U+2194 (8596)
 * Description: left right arrow
 */
static wchar_t* HARR_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harr";
static int* HARR_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftrightarrow html character entity reference model.
 *
 * Name: leftrightarrow
 * Character: ↔
 * Unicode code point: U+2194 (8596)
 * Description: left right arrow
 */
static wchar_t* SMALL_LEFTRIGHTARROW_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftrightarrow";
static int* SMALL_LEFTRIGHTARROW_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpDownArrow html character entity reference model.
 *
 * Name: UpDownArrow
 * Character: ↕
 * Unicode code point: U+2195 (8597)
 * Description: up down arrow
 */
static wchar_t* CAMEL_UPDOWNARROW_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpDownArrow";
static int* CAMEL_UPDOWNARROW_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The updownarrow html character entity reference model.
 *
 * Name: updownarrow
 * Character: ↕
 * Unicode code point: U+2195 (8597)
 * Description: up down arrow
 */
static wchar_t* SMALL_UPDOWNARROW_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"updownarrow";
static int* SMALL_UPDOWNARROW_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varr html character entity reference model.
 *
 * Name: varr
 * Character: ↕
 * Unicode code point: U+2195 (8597)
 * Description: up down arrow
 */
static wchar_t* VARR_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varr";
static int* VARR_UP_DOWN_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpperLeftArrow html character entity reference model.
 *
 * Name: UpperLeftArrow
 * Character: ↖
 * Unicode code point: U+2196 (8598)
 * Description: north west arrow
 */
static wchar_t* UPPERLEFTARROW_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpperLeftArrow";
static int* UPPERLEFTARROW_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nwarr html character entity reference model.
 *
 * Name: nwarr
 * Character: ↖
 * Unicode code point: U+2196 (8598)
 * Description: north west arrow
 */
static wchar_t* NWARR_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwarr";
static int* NWARR_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nwarrow html character entity reference model.
 *
 * Name: nwarrow
 * Character: ↖
 * Unicode code point: U+2196 (8598)
 * Description: north west arrow
 */
static wchar_t* NWARROW_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwarrow";
static int* NWARROW_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpperRightArrow html character entity reference model.
 *
 * Name: UpperRightArrow
 * Character: ↗
 * Unicode code point: U+2197 (8599)
 * Description: north east arrow
 */
static wchar_t* UPPERRIGHTARROW_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpperRightArrow";
static int* UPPERRIGHTARROW_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nearr html character entity reference model.
 *
 * Name: nearr
 * Character: ↗
 * Unicode code point: U+2197 (8599)
 * Description: north east arrow
 */
static wchar_t* NEARR_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nearr";
static int* NEARR_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nearrow html character entity reference model.
 *
 * Name: nearrow
 * Character: ↗
 * Unicode code point: U+2197 (8599)
 * Description: north east arrow
 */
static wchar_t* NEARROW_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nearrow";
static int* NEARROW_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LowerRightArrow html character entity reference model.
 *
 * Name: LowerRightArrow
 * Character: ↘
 * Unicode code point: U+2198 (8600)
 * Description: south east arrow
 */
static wchar_t* LOWERRIGHTARROW_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LowerRightArrow";
static int* LOWERRIGHTARROW_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The searr html character entity reference model.
 *
 * Name: searr
 * Character: ↘
 * Unicode code point: U+2198 (8600)
 * Description: south east arrow
 */
static wchar_t* SEARR_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"searr";
static int* SEARR_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The searrow html character entity reference model.
 *
 * Name: searrow
 * Character: ↘
 * Unicode code point: U+2198 (8600)
 * Description: south east arrow
 */
static wchar_t* SEARROW_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"searrow";
static int* SEARROW_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LowerLeftArrow html character entity reference model.
 *
 * Name: LowerLeftArrow
 * Character: ↙
 * Unicode code point: U+2199 (8601)
 * Description: south west arrow
 */
static wchar_t* LOWERLEFTARROW_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LowerLeftArrow";
static int* LOWERLEFTARROW_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The swarr html character entity reference model.
 *
 * Name: swarr
 * Character: ↙
 * Unicode code point: U+2199 (8601)
 * Description: south west arrow
 */
static wchar_t* SWARR_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swarr";
static int* SWARR_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The swarrow html character entity reference model.
 *
 * Name: swarrow
 * Character: ↙
 * Unicode code point: U+2199 (8601)
 * Description: south west arrow
 */
static wchar_t* SWARROW_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swarrow";
static int* SWARROW_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nlarr html character entity reference model.
 *
 * Name: nlarr
 * Character: ↚
 * Unicode code point: U+219a (8602)
 * Description: leftwards arrow with stroke
 */
static wchar_t* NLARR_LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlarr";
static int* NLARR_LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nleftarrow html character entity reference model.
 *
 * Name: nleftarrow
 * Character: ↚
 * Unicode code point: U+219a (8602)
 * Description: leftwards arrow with stroke
 */
static wchar_t* NLEFTARROW_LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nleftarrow";
static int* NLEFTARROW_LEFTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrarr html character entity reference model.
 *
 * Name: nrarr
 * Character: ↛
 * Unicode code point: U+219b (8603)
 * Description: rightwards arrow with stroke
 */
static wchar_t* NRARR_RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarr";
static int* NRARR_RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrightarrow html character entity reference model.
 *
 * Name: nrightarrow
 * Character: ↛
 * Unicode code point: U+219b (8603)
 * Description: rightwards arrow with stroke
 */
static wchar_t* NRIGHTARROW_RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrightarrow";
static int* NRIGHTARROW_RIGHTWARDS_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrarrw html character entity reference model.
 *
 * Name: nrarrw
 * Character: ↝̸
 * Unicode code point: U+219d;U+0338 (8605;824)
 * Description: rightwards wave arrow with slash
 */
static wchar_t* NRARRW_RIGHTWARDS_WAVE_ARROW_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarrw";
static int* NRARRW_RIGHTWARDS_WAVE_ARROW_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrw html character entity reference model.
 *
 * Name: rarrw
 * Character: ↝
 * Unicode code point: U+219d (8605)
 * Description: rightwards wave arrow
 */
static wchar_t* RARRW_RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrw";
static int* RARRW_RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightsquigarrow html character entity reference model.
 *
 * Name: rightsquigarrow
 * Character: ↝
 * Unicode code point: U+219d (8605)
 * Description: rightwards wave arrow
 */
static wchar_t* RIGHTSQUIGARROW_RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightsquigarrow";
static int* RIGHTSQUIGARROW_RIGHTWARDS_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Larr html character entity reference model.
 *
 * Name: Larr
 * Character: ↞
 * Unicode code point: U+219e (8606)
 * Description: leftwards two headed arrow
 */
static wchar_t* LARR_LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Larr";
static int* LARR_LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The twoheadleftarrow html character entity reference model.
 *
 * Name: twoheadleftarrow
 * Character: ↞
 * Unicode code point: U+219e (8606)
 * Description: leftwards two headed arrow
 */
static wchar_t* TWOHEADLEFTARROW_LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"twoheadleftarrow";
static int* TWOHEADLEFTARROW_LEFTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uarr html character entity reference model.
 *
 * Name: Uarr
 * Character: ↟
 * Unicode code point: U+219f (8607)
 * Description: upwards two headed arrow
 */
static wchar_t* UARR_UPWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uarr";
static int* UARR_UPWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rarr html character entity reference model.
 *
 * Name: Rarr
 * Character: ↠
 * Unicode code point: U+21a0 (8608)
 * Description: rightwards two headed arrow
 */
static wchar_t* RARR_RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rarr";
static int* RARR_RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The twoheadrightarrow html character entity reference model.
 *
 * Name: twoheadrightarrow
 * Character: ↠
 * Unicode code point: U+21a0 (8608)
 * Description: rightwards two headed arrow
 */
static wchar_t* TWOHEADRIGHTARROW_RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"twoheadrightarrow";
static int* TWOHEADRIGHTARROW_RIGHTWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Darr html character entity reference model.
 *
 * Name: Darr
 * Character: ↡
 * Unicode code point: U+21a1 (8609)
 * Description: downwards two headed arrow
 */
static wchar_t* DARR_DOWNWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Darr";
static int* DARR_DOWNWARDS_TWO_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrtl html character entity reference model.
 *
 * Name: larrtl
 * Character: ↢
 * Unicode code point: U+21a2 (8610)
 * Description: leftwards arrow with tail
 */
static wchar_t* LARRTL_LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrtl";
static int* LARRTL_LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftarrowtail html character entity reference model.
 *
 * Name: leftarrowtail
 * Character: ↢
 * Unicode code point: U+21a2 (8610)
 * Description: leftwards arrow with tail
 */
static wchar_t* LEFTARROWTAIL_LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftarrowtail";
static int* LEFTARROWTAIL_LEFTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrtl html character entity reference model.
 *
 * Name: rarrtl
 * Character: ↣
 * Unicode code point: U+21a3 (8611)
 * Description: rightwards arrow with tail
 */
static wchar_t* RARRTL_RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrtl";
static int* RARRTL_RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightarrowtail html character entity reference model.
 *
 * Name: rightarrowtail
 * Character: ↣
 * Unicode code point: U+21a3 (8611)
 * Description: rightwards arrow with tail
 */
static wchar_t* RIGHTARROWTAIL_RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightarrowtail";
static int* RIGHTARROWTAIL_RIGHTWARDS_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTeeArrow html character entity reference model.
 *
 * Name: LeftTeeArrow
 * Character: ↤
 * Unicode code point: U+21a4 (8612)
 * Description: leftwards arrow from bar
 */
static wchar_t* LEFTTEEARROW_LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTeeArrow";
static int* LEFTTEEARROW_LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mapstoleft html character entity reference model.
 *
 * Name: mapstoleft
 * Character: ↤
 * Unicode code point: U+21a4 (8612)
 * Description: leftwards arrow from bar
 */
static wchar_t* MAPSTOLEFT_LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mapstoleft";
static int* MAPSTOLEFT_LEFTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpTeeArrow html character entity reference model.
 *
 * Name: UpTeeArrow
 * Character: ↥
 * Unicode code point: U+21a5 (8613)
 * Description: upwards arrow from bar
 */
static wchar_t* UPTEEARROW_UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpTeeArrow";
static int* UPTEEARROW_UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mapstoup html character entity reference model.
 *
 * Name: mapstoup
 * Character: ↥
 * Unicode code point: U+21a5 (8613)
 * Description: upwards arrow from bar
 */
static wchar_t* MAPSTOUP_UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mapstoup";
static int* MAPSTOUP_UPWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTeeArrow html character entity reference model.
 *
 * Name: RightTeeArrow
 * Character: ↦
 * Unicode code point: U+21a6 (8614)
 * Description: rightwards arrow from bar
 */
static wchar_t* RIGHTTEEARROW_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTeeArrow";
static int* RIGHTTEEARROW_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The map html character entity reference model.
 *
 * Name: map
 * Character: ↦
 * Unicode code point: U+21a6 (8614)
 * Description: rightwards arrow from bar
 */
static wchar_t* MAP_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"map";
static int* MAP_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mapsto html character entity reference model.
 *
 * Name: mapsto
 * Character: ↦
 * Unicode code point: U+21a6 (8614)
 * Description: rightwards arrow from bar
 */
static wchar_t* MAPSTO_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mapsto";
static int* MAPSTO_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownTeeArrow html character entity reference model.
 *
 * Name: DownTeeArrow
 * Character: ↧
 * Unicode code point: U+21a7 (8615)
 * Description: downwards arrow from bar
 */
static wchar_t* DOWNTEEARROW_DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownTeeArrow";
static int* DOWNTEEARROW_DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mapstodown html character entity reference model.
 *
 * Name: mapstodown
 * Character: ↧
 * Unicode code point: U+21a7 (8615)
 * Description: downwards arrow from bar
 */
static wchar_t* MAPSTODOWN_DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mapstodown";
static int* MAPSTODOWN_DOWNWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hookleftarrow html character entity reference model.
 *
 * Name: hookleftarrow
 * Character: ↩
 * Unicode code point: U+21a9 (8617)
 * Description: leftwards arrow with hook
 */
static wchar_t* HOOKLEFTARROW_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hookleftarrow";
static int* HOOKLEFTARROW_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrhk html character entity reference model.
 *
 * Name: larrhk
 * Character: ↩
 * Unicode code point: U+21a9 (8617)
 * Description: leftwards arrow with hook
 */
static wchar_t* LARRHK_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrhk";
static int* LARRHK_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hookrightarrow html character entity reference model.
 *
 * Name: hookrightarrow
 * Character: ↪
 * Unicode code point: U+21aa (8618)
 * Description: rightwards arrow with hook
 */
static wchar_t* HOOKRIGHTARROW_RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hookrightarrow";
static int* HOOKRIGHTARROW_RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrhk html character entity reference model.
 *
 * Name: rarrhk
 * Character: ↪
 * Unicode code point: U+21aa (8618)
 * Description: rightwards arrow with hook
 */
static wchar_t* RARRHK_RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrhk";
static int* RARRHK_RIGHTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrlp html character entity reference model.
 *
 * Name: larrlp
 * Character: ↫
 * Unicode code point: U+21ab (8619)
 * Description: leftwards arrow with loop
 */
static wchar_t* LARRLP_LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrlp";
static int* LARRLP_LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The looparrowleft html character entity reference model.
 *
 * Name: looparrowleft
 * Character: ↫
 * Unicode code point: U+21ab (8619)
 * Description: leftwards arrow with loop
 */
static wchar_t* LOOPARROWLEFT_LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"looparrowleft";
static int* LOOPARROWLEFT_LEFTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The looparrowright html character entity reference model.
 *
 * Name: looparrowright
 * Character: ↬
 * Unicode code point: U+21ac (8620)
 * Description: rightwards arrow with loop
 */
static wchar_t* LOOPARROWRIGHT_RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"looparrowright";
static int* LOOPARROWRIGHT_RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrlp html character entity reference model.
 *
 * Name: rarrlp
 * Character: ↬
 * Unicode code point: U+21ac (8620)
 * Description: rightwards arrow with loop
 */
static wchar_t* RARRLP_RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrlp";
static int* RARRLP_RIGHTWARDS_ARROW_WITH_LOOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The harrw html character entity reference model.
 *
 * Name: harrw
 * Character: ↭
 * Unicode code point: U+21ad (8621)
 * Description: left right wave arrow
 */
static wchar_t* HARRW_LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harrw";
static int* HARRW_LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftrightsquigarrow html character entity reference model.
 *
 * Name: leftrightsquigarrow
 * Character: ↭
 * Unicode code point: U+21ad (8621)
 * Description: left right wave arrow
 */
static wchar_t* LEFTRIGHTSQUIGARROW_LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftrightsquigarrow";
static int* LEFTRIGHTSQUIGARROW_LEFT_RIGHT_WAVE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nharr html character entity reference model.
 *
 * Name: nharr
 * Character: ↮
 * Unicode code point: U+21ae (8622)
 * Description: left right arrow with stroke
 */
static wchar_t* NHARR_LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nharr";
static int* NHARR_LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nleftrightarrow html character entity reference model.
 *
 * Name: nleftrightarrow
 * Character: ↮
 * Unicode code point: U+21ae (8622)
 * Description: left right arrow with stroke
 */
static wchar_t* NLEFTRIGHTARROW_LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nleftrightarrow";
static int* NLEFTRIGHTARROW_LEFT_RIGHT_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lsh html character entity reference model.
 *
 * Name: Lsh
 * Character: ↰
 * Unicode code point: U+21b0 (8624)
 * Description: upwards arrow with tip leftwards
 */
static wchar_t* CAMEL_LSH_UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lsh";
static int* CAMEL_LSH_UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsh html character entity reference model.
 *
 * Name: lsh
 * Character: ↰
 * Unicode code point: U+21b0 (8624)
 * Description: upwards arrow with tip leftwards
 */
static wchar_t* SMALL_LSH_UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsh";
static int* SMALL_LSH_UPWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rsh html character entity reference model.
 *
 * Name: Rsh
 * Character: ↱
 * Unicode code point: U+21b1 (8625)
 * Description: upwards arrow with tip rightwards
 */
static wchar_t* CAMEL_RSH_UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rsh";
static int* CAMEL_RSH_UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rsh html character entity reference model.
 *
 * Name: rsh
 * Character: ↱
 * Unicode code point: U+21b1 (8625)
 * Description: upwards arrow with tip rightwards
 */
static wchar_t* SMALL_RSH_UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rsh";
static int* SMALL_RSH_UPWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldsh html character entity reference model.
 *
 * Name: ldsh
 * Character: ↲
 * Unicode code point: U+21b2 (8626)
 * Description: downwards arrow with tip leftwards
 */
static wchar_t* LDSH_DOWNWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldsh";
static int* LDSH_DOWNWARDS_ARROW_WITH_TIP_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rdsh html character entity reference model.
 *
 * Name: rdsh
 * Character: ↳
 * Unicode code point: U+21b3 (8627)
 * Description: downwards arrow with tip rightwards
 */
static wchar_t* RDSH_DOWNWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdsh";
static int* RDSH_DOWNWARDS_ARROW_WITH_TIP_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The crarr html character entity reference model.
 *
 * Name: crarr
 * Character: ↵
 * Unicode code point: U+21b5 (8629)
 * Description: downwards arrow with corner leftwards
 */
static wchar_t* CRARR_DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"crarr";
static int* CRARR_DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cularr html character entity reference model.
 *
 * Name: cularr
 * Character: ↶
 * Unicode code point: U+21b6 (8630)
 * Description: anticlockwise top semicircle arrow
 */
static wchar_t* CULARR_ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cularr";
static int* CULARR_ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curvearrowleft html character entity reference model.
 *
 * Name: curvearrowleft
 * Character: ↶
 * Unicode code point: U+21b6 (8630)
 * Description: anticlockwise top semicircle arrow
 */
static wchar_t* CURVEARROWLEFT_ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curvearrowleft";
static int* CURVEARROWLEFT_ANTICLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curarr html character entity reference model.
 *
 * Name: curarr
 * Character: ↷
 * Unicode code point: U+21b7 (8631)
 * Description: clockwise top semicircle arrow
 */
static wchar_t* CURARR_CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curarr";
static int* CURARR_CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curvearrowright html character entity reference model.
 *
 * Name: curvearrowright
 * Character: ↷
 * Unicode code point: U+21b7 (8631)
 * Description: clockwise top semicircle arrow
 */
static wchar_t* CURVEARROWRIGHT_CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curvearrowright";
static int* CURVEARROWRIGHT_CLOCKWISE_TOP_SEMICIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circlearrowleft html character entity reference model.
 *
 * Name: circlearrowleft
 * Character: ↺
 * Unicode code point: U+21ba (8634)
 * Description: anticlockwise open circle arrow
 */
static wchar_t* CIRCLEARROWLEFT_ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circlearrowleft";
static int* CIRCLEARROWLEFT_ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The olarr html character entity reference model.
 *
 * Name: olarr
 * Character: ↺
 * Unicode code point: U+21ba (8634)
 * Description: anticlockwise open circle arrow
 */
static wchar_t* OLARR_ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olarr";
static int* OLARR_ANTICLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circlearrowright html character entity reference model.
 *
 * Name: circlearrowright
 * Character: ↻
 * Unicode code point: U+21bb (8635)
 * Description: clockwise open circle arrow
 */
static wchar_t* CIRCLEARROWRIGHT_CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circlearrowright";
static int* CIRCLEARROWRIGHT_CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The orarr html character entity reference model.
 *
 * Name: orarr
 * Character: ↻
 * Unicode code point: U+21bb (8635)
 * Description: clockwise open circle arrow
 */
static wchar_t* ORARR_CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orarr";
static int* ORARR_CLOCKWISE_OPEN_CIRCLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftVector html character entity reference model.
 *
 * Name: LeftVector
 * Character: ↼
 * Unicode code point: U+21bc (8636)
 * Description: leftwards harpoon with barb upwards
 */
static wchar_t* LEFTVECTOR_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftVector";
static int* LEFTVECTOR_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftharpoonup html character entity reference model.
 *
 * Name: leftharpoonup
 * Character: ↼
 * Unicode code point: U+21bc (8636)
 * Description: leftwards harpoon with barb upwards
 */
static wchar_t* LEFTHARPOONUP_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftharpoonup";
static int* LEFTHARPOONUP_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lharu html character entity reference model.
 *
 * Name: lharu
 * Character: ↼
 * Unicode code point: U+21bc (8636)
 * Description: leftwards harpoon with barb upwards
 */
static wchar_t* LHARU_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lharu";
static int* LHARU_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownLeftVector html character entity reference model.
 *
 * Name: DownLeftVector
 * Character: ↽
 * Unicode code point: U+21bd (8637)
 * Description: leftwards harpoon with barb downwards
 */
static wchar_t* DOWNLEFTVECTOR_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftVector";
static int* DOWNLEFTVECTOR_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftharpoondown html character entity reference model.
 *
 * Name: leftharpoondown
 * Character: ↽
 * Unicode code point: U+21bd (8637)
 * Description: leftwards harpoon with barb downwards
 */
static wchar_t* LEFTHARPOONDOWN_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftharpoondown";
static int* LEFTHARPOONDOWN_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lhard html character entity reference model.
 *
 * Name: lhard
 * Character: ↽
 * Unicode code point: U+21bd (8637)
 * Description: leftwards harpoon with barb downwards
 */
static wchar_t* LHARD_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lhard";
static int* LHARD_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightUpVector html character entity reference model.
 *
 * Name: RightUpVector
 * Character: ↾
 * Unicode code point: U+21be (8638)
 * Description: upwards harpoon with barb rightwards
 */
static wchar_t* RIGHTUPVECTOR_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpVector";
static int* RIGHTUPVECTOR_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uharr html character entity reference model.
 *
 * Name: uharr
 * Character: ↾
 * Unicode code point: U+21be (8638)
 * Description: upwards harpoon with barb rightwards
 */
static wchar_t* UHARR_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uharr";
static int* UHARR_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upharpoonright html character entity reference model.
 *
 * Name: upharpoonright
 * Character: ↾
 * Unicode code point: U+21be (8638)
 * Description: upwards harpoon with barb rightwards
 */
static wchar_t* UPHARPOONRIGHT_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upharpoonright";
static int* UPHARPOONRIGHT_UPWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftUpVector html character entity reference model.
 *
 * Name: LeftUpVector
 * Character: ↿
 * Unicode code point: U+21bf (8639)
 * Description: upwards harpoon with barb leftwards
 */
static wchar_t* LEFTUPVECTOR_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpVector";
static int* LEFTUPVECTOR_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uharl html character entity reference model.
 *
 * Name: uharl
 * Character: ↿
 * Unicode code point: U+21bf (8639)
 * Description: upwards harpoon with barb leftwards
 */
static wchar_t* UHARL_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uharl";
static int* UHARL_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upharpoonleft html character entity reference model.
 *
 * Name: upharpoonleft
 * Character: ↿
 * Unicode code point: U+21bf (8639)
 * Description: upwards harpoon with barb leftwards
 */
static wchar_t* UPHARPOONLEFT_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upharpoonleft";
static int* UPHARPOONLEFT_UPWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightVector html character entity reference model.
 *
 * Name: RightVector
 * Character: ⇀
 * Unicode code point: U+21c0 (8640)
 * Description: rightwards harpoon with barb upwards
 */
static wchar_t* RIGHTVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightVector";
static int* RIGHTVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rharu html character entity reference model.
 *
 * Name: rharu
 * Character: ⇀
 * Unicode code point: U+21c0 (8640)
 * Description: rightwards harpoon with barb upwards
 */
static wchar_t* RHARU_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rharu";
static int* RHARU_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightharpoonup html character entity reference model.
 *
 * Name: rightharpoonup
 * Character: ⇀
 * Unicode code point: U+21c0 (8640)
 * Description: rightwards harpoon with barb upwards
 */
static wchar_t* RIGHTHARPOONUP_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightharpoonup";
static int* RIGHTHARPOONUP_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownRightVector html character entity reference model.
 *
 * Name: DownRightVector
 * Character: ⇁
 * Unicode code point: U+21c1 (8641)
 * Description: rightwards harpoon with barb downwards
 */
static wchar_t* DOWNRIGHTVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightVector";
static int* DOWNRIGHTVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rhard html character entity reference model.
 *
 * Name: rhard
 * Character: ⇁
 * Unicode code point: U+21c1 (8641)
 * Description: rightwards harpoon with barb downwards
 */
static wchar_t* RHARD_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rhard";
static int* RHARD_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightharpoondown html character entity reference model.
 *
 * Name: rightharpoondown
 * Character: ⇁
 * Unicode code point: U+21c1 (8641)
 * Description: rightwards harpoon with barb downwards
 */
static wchar_t* RIGHTHARPOONDOWN_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightharpoondown";
static int* RIGHTHARPOONDOWN_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightDownVector html character entity reference model.
 *
 * Name: RightDownVector
 * Character: ⇂
 * Unicode code point: U+21c2 (8642)
 * Description: downwards harpoon with barb rightwards
 */
static wchar_t* RIGHTDOWNVECTOR_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownVector";
static int* RIGHTDOWNVECTOR_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dharr html character entity reference model.
 *
 * Name: dharr
 * Character: ⇂
 * Unicode code point: U+21c2 (8642)
 * Description: downwards harpoon with barb rightwards
 */
static wchar_t* DHARR_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dharr";
static int* DHARR_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downharpoonright html character entity reference model.
 *
 * Name: downharpoonright
 * Character: ⇂
 * Unicode code point: U+21c2 (8642)
 * Description: downwards harpoon with barb rightwards
 */
static wchar_t* DOWNHARPOONRIGHT_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"downharpoonright";
static int* DOWNHARPOONRIGHT_DOWNWARDS_HARPOON_WITH_BARB_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftDownVector html character entity reference model.
 *
 * Name: LeftDownVector
 * Character: ⇃
 * Unicode code point: U+21c3 (8643)
 * Description: downwards harpoon with barb leftwards
 */
static wchar_t* LEFTDOWNVECTOR_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownVector";
static int* LEFTDOWNVECTOR_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dharl html character entity reference model.
 *
 * Name: dharl
 * Character: ⇃
 * Unicode code point: U+21c3 (8643)
 * Description: downwards harpoon with barb leftwards
 */
static wchar_t* DHARL_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dharl";
static int* DHARL_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downharpoonleft html character entity reference model.
 *
 * Name: downharpoonleft
 * Character: ⇃
 * Unicode code point: U+21c3 (8643)
 * Description: downwards harpoon with barb leftwards
 */
static wchar_t* DOWNHARPOONLEFT_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"downharpoonleft";
static int* DOWNHARPOONLEFT_DOWNWARDS_HARPOON_WITH_BARB_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightArrowLeftArrow html character entity reference model.
 *
 * Name: RightArrowLeftArrow
 * Character: ⇄
 * Unicode code point: U+21c4 (8644)
 * Description: rightwards arrow over leftwards arrow
 */
static wchar_t* RIGHTARROWLEFTARROW_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrowLeftArrow";
static int* RIGHTARROWLEFTARROW_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightleftarrows html character entity reference model.
 *
 * Name: rightleftarrows
 * Character: ⇄
 * Unicode code point: U+21c4 (8644)
 * Description: rightwards arrow over leftwards arrow
 */
static wchar_t* RIGHTLEFTARROWS_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightleftarrows";
static int* RIGHTLEFTARROWS_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rlarr html character entity reference model.
 *
 * Name: rlarr
 * Character: ⇄
 * Unicode code point: U+21c4 (8644)
 * Description: rightwards arrow over leftwards arrow
 */
static wchar_t* RLARR_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rlarr";
static int* RLARR_RIGHTWARDS_ARROW_OVER_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpArrowDownArrow html character entity reference model.
 *
 * Name: UpArrowDownArrow
 * Character: ⇅
 * Unicode code point: U+21c5 (8645)
 * Description: upwards arrow leftwards of downwards arrow
 */
static wchar_t* UPARROWDOWNARROW_UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpArrowDownArrow";
static int* UPARROWDOWNARROW_UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udarr html character entity reference model.
 *
 * Name: udarr
 * Character: ⇅
 * Unicode code point: U+21c5 (8645)
 * Description: upwards arrow leftwards of downwards arrow
 */
static wchar_t* UDARR_UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udarr";
static int* UDARR_UPWARDS_ARROW_LEFTWARDS_OF_DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftArrowRightArrow html character entity reference model.
 *
 * Name: LeftArrowRightArrow
 * Character: ⇆
 * Unicode code point: U+21c6 (8646)
 * Description: leftwards arrow over rightwards arrow
 */
static wchar_t* LEFTARROWRIGHTARROW_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrowRightArrow";
static int* LEFTARROWRIGHTARROW_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftrightarrows html character entity reference model.
 *
 * Name: leftrightarrows
 * Character: ⇆
 * Unicode code point: U+21c6 (8646)
 * Description: leftwards arrow over rightwards arrow
 */
static wchar_t* LEFTRIGHTARROWS_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftrightarrows";
static int* LEFTRIGHTARROWS_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrarr html character entity reference model.
 *
 * Name: lrarr
 * Character: ⇆
 * Unicode code point: U+21c6 (8646)
 * Description: leftwards arrow over rightwards arrow
 */
static wchar_t* LRARR_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrarr";
static int* LRARR_LEFTWARDS_ARROW_OVER_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftleftarrows html character entity reference model.
 *
 * Name: leftleftarrows
 * Character: ⇇
 * Unicode code point: U+21c7 (8647)
 * Description: leftwards paired arrows
 */
static wchar_t* LEFTLEFTARROWS_LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftleftarrows";
static int* LEFTLEFTARROWS_LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The llarr html character entity reference model.
 *
 * Name: llarr
 * Character: ⇇
 * Unicode code point: U+21c7 (8647)
 * Description: leftwards paired arrows
 */
static wchar_t* LLARR_LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"llarr";
static int* LLARR_LEFTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The upuparrows html character entity reference model.
 *
 * Name: upuparrows
 * Character: ⇈
 * Unicode code point: U+21c8 (8648)
 * Description: upwards paired arrows
 */
static wchar_t* UPUPARROWS_UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"upuparrows";
static int* UPUPARROWS_UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uuarr html character entity reference model.
 *
 * Name: uuarr
 * Character: ⇈
 * Unicode code point: U+21c8 (8648)
 * Description: upwards paired arrows
 */
static wchar_t* UUARR_UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uuarr";
static int* UUARR_UPWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightrightarrows html character entity reference model.
 *
 * Name: rightrightarrows
 * Character: ⇉
 * Unicode code point: U+21c9 (8649)
 * Description: rightwards paired arrows
 */
static wchar_t* RIGHTRIGHTARROWS_RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightrightarrows";
static int* RIGHTRIGHTARROWS_RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rrarr html character entity reference model.
 *
 * Name: rrarr
 * Character: ⇉
 * Unicode code point: U+21c9 (8649)
 * Description: rightwards paired arrows
 */
static wchar_t* RRARR_RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rrarr";
static int* RRARR_RIGHTWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ddarr html character entity reference model.
 *
 * Name: ddarr
 * Character: ⇊
 * Unicode code point: U+21ca (8650)
 * Description: downwards paired arrows
 */
static wchar_t* DDARR_DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ddarr";
static int* DDARR_DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The downdownarrows html character entity reference model.
 *
 * Name: downdownarrows
 * Character: ⇊
 * Unicode code point: U+21ca (8650)
 * Description: downwards paired arrows
 */
static wchar_t* DOWNDOWNARROWS_DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"downdownarrows";
static int* DOWNDOWNARROWS_DOWNWARDS_PAIRED_ARROWS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ReverseEquilibrium html character entity reference model.
 *
 * Name: ReverseEquilibrium
 * Character: ⇋
 * Unicode code point: U+21cb (8651)
 * Description: leftwards harpoon over rightwards harpoon
 */
static wchar_t* REVERSEEQUILIBRIUM_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseEquilibrium";
static int* REVERSEEQUILIBRIUM_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftrightharpoons html character entity reference model.
 *
 * Name: leftrightharpoons
 * Character: ⇋
 * Unicode code point: U+21cb (8651)
 * Description: leftwards harpoon over rightwards harpoon
 */
static wchar_t* LEFTRIGHTHARPOONS_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftrightharpoons";
static int* LEFTRIGHTHARPOONS_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrhar html character entity reference model.
 *
 * Name: lrhar
 * Character: ⇋
 * Unicode code point: U+21cb (8651)
 * Description: leftwards harpoon over rightwards harpoon
 */
static wchar_t* LRHAR_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrhar";
static int* LRHAR_LEFTWARDS_HARPOON_OVER_RIGHTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Equilibrium html character entity reference model.
 *
 * Name: Equilibrium
 * Character: ⇌
 * Unicode code point: U+21cc (8652)
 * Description: rightwards harpoon over leftwards harpoon
 */
static wchar_t* EQUILIBRIUM_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Equilibrium";
static int* EQUILIBRIUM_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightleftharpoons html character entity reference model.
 *
 * Name: rightleftharpoons
 * Character: ⇌
 * Unicode code point: U+21cc (8652)
 * Description: rightwards harpoon over leftwards harpoon
 */
static wchar_t* RIGHTLEFTHARPOONS_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightleftharpoons";
static int* RIGHTLEFTHARPOONS_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rlhar html character entity reference model.
 *
 * Name: rlhar
 * Character: ⇌
 * Unicode code point: U+21cc (8652)
 * Description: rightwards harpoon over leftwards harpoon
 */
static wchar_t* RLHAR_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rlhar";
static int* RLHAR_RIGHTWARDS_HARPOON_OVER_LEFTWARDS_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nLeftarrow html character entity reference model.
 *
 * Name: nLeftarrow
 * Character: ⇍
 * Unicode code point: U+21cd (8653)
 * Description: leftwards double arrow with stroke
 */
static wchar_t* NLEFTARROW_LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLeftarrow";
static int* NLEFTARROW_LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nlArr html character entity reference model.
 *
 * Name: nlArr
 * Character: ⇍
 * Unicode code point: U+21cd (8653)
 * Description: leftwards double arrow with stroke
 */
static wchar_t* NLARR_LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlArr";
static int* NLARR_LEFTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nLeftrightarrow html character entity reference model.
 *
 * Name: nLeftrightarrow
 * Character: ⇎
 * Unicode code point: U+21ce (8654)
 * Description: left right double arrow with stroke
 */
static wchar_t* NLEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLeftrightarrow";
static int* NLEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nhArr html character entity reference model.
 *
 * Name: nhArr
 * Character: ⇎
 * Unicode code point: U+21ce (8654)
 * Description: left right double arrow with stroke
 */
static wchar_t* NHARR_LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nhArr";
static int* NHARR_LEFT_RIGHT_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nRightarrow html character entity reference model.
 *
 * Name: nRightarrow
 * Character: ⇏
 * Unicode code point: U+21cf (8655)
 * Description: rightwards double arrow with stroke
 */
static wchar_t* NRIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nRightarrow";
static int* NRIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrArr html character entity reference model.
 *
 * Name: nrArr
 * Character: ⇏
 * Unicode code point: U+21cf (8655)
 * Description: rightwards double arrow with stroke
 */
static wchar_t* NRARR_RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrArr";
static int* NRARR_RIGHTWARDS_DOUBLE_ARROW_WITH_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLeftArrow html character entity reference model.
 *
 * Name: DoubleLeftArrow
 * Character: ⇐
 * Unicode code point: U+21d0 (8656)
 * Description: leftwards double arrow
 */
static wchar_t* DOUBLELEFTARROW_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLeftArrow";
static int* DOUBLELEFTARROW_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Leftarrow html character entity reference model.
 *
 * Name: Leftarrow
 * Character: ⇐
 * Unicode code point: U+21d0 (8656)
 * Description: leftwards double arrow
 */
static wchar_t* LEFTARROW_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Leftarrow";
static int* LEFTARROW_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lArr html character entity reference model.
 *
 * Name: lArr
 * Character: ⇐
 * Unicode code point: U+21d0 (8656)
 * Description: leftwards double arrow
 */
static wchar_t* LARR_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lArr";
static int* LARR_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleUpArrow html character entity reference model.
 *
 * Name: DoubleUpArrow
 * Character: ⇑
 * Unicode code point: U+21d1 (8657)
 * Description: upwards double arrow
 */
static wchar_t* DOUBLEUPARROW_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleUpArrow";
static int* DOUBLEUPARROW_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uparrow html character entity reference model.
 *
 * Name: Uparrow
 * Character: ⇑
 * Unicode code point: U+21d1 (8657)
 * Description: upwards double arrow
 */
static wchar_t* UPARROW_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uparrow";
static int* UPARROW_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uArr html character entity reference model.
 *
 * Name: uArr
 * Character: ⇑
 * Unicode code point: U+21d1 (8657)
 * Description: upwards double arrow
 */
static wchar_t* UARR_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uArr";
static int* UARR_UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleRightArrow html character entity reference model.
 *
 * Name: DoubleRightArrow
 * Character: ⇒
 * Unicode code point: U+21d2 (8658)
 * Description: rightwards double arrow
 */
static wchar_t* DOUBLERIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleRightArrow";
static int* DOUBLERIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Implies html character entity reference model.
 *
 * Name: Implies
 * Character: ⇒
 * Unicode code point: U+21d2 (8658)
 * Description: rightwards double arrow
 */
static wchar_t* IMPLIES_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Implies";
static int* IMPLIES_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rightarrow html character entity reference model.
 *
 * Name: Rightarrow
 * Character: ⇒
 * Unicode code point: U+21d2 (8658)
 * Description: rightwards double arrow
 */
static wchar_t* RIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rightarrow";
static int* RIGHTARROW_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rArr html character entity reference model.
 *
 * Name: rArr
 * Character: ⇒
 * Unicode code point: U+21d2 (8658)
 * Description: rightwards double arrow
 */
static wchar_t* RARR_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rArr";
static int* RARR_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleDownArrow html character entity reference model.
 *
 * Name: DoubleDownArrow
 * Character: ⇓
 * Unicode code point: U+21d3 (8659)
 * Description: downwards double arrow
 */
static wchar_t* DOUBLEDOWNARROW_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleDownArrow";
static int* DOUBLEDOWNARROW_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Downarrow html character entity reference model.
 *
 * Name: Downarrow
 * Character: ⇓
 * Unicode code point: U+21d3 (8659)
 * Description: downwards double arrow
 */
static wchar_t* DOWNARROW_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Downarrow";
static int* DOWNARROW_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dArr html character entity reference model.
 *
 * Name: dArr
 * Character: ⇓
 * Unicode code point: U+21d3 (8659)
 * Description: downwards double arrow
 */
static wchar_t* DARR_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dArr";
static int* DARR_DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLeftRightArrow html character entity reference model.
 *
 * Name: DoubleLeftRightArrow
 * Character: ⇔
 * Unicode code point: U+21d4 (8660)
 * Description: left right double arrow
 */
static wchar_t* DOUBLELEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLeftRightArrow";
static int* DOUBLELEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Leftrightarrow html character entity reference model.
 *
 * Name: Leftrightarrow
 * Character: ⇔
 * Unicode code point: U+21d4 (8660)
 * Description: left right double arrow
 */
static wchar_t* LEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Leftrightarrow";
static int* LEFTRIGHTARROW_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hArr html character entity reference model.
 *
 * Name: hArr
 * Character: ⇔
 * Unicode code point: U+21d4 (8660)
 * Description: left right double arrow
 */
static wchar_t* HARR_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hArr";
static int* HARR_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iff html character entity reference model.
 *
 * Name: iff
 * Character: ⇔
 * Unicode code point: U+21d4 (8660)
 * Description: left right double arrow
 */
static wchar_t* IFF_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iff";
static int* IFF_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleUpDownArrow html character entity reference model.
 *
 * Name: DoubleUpDownArrow
 * Character: ⇕
 * Unicode code point: U+21d5 (8661)
 * Description: up down double arrow
 */
static wchar_t* DOUBLEUPDOWNARROW_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleUpDownArrow";
static int* DOUBLEUPDOWNARROW_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Updownarrow html character entity reference model.
 *
 * Name: Updownarrow
 * Character: ⇕
 * Unicode code point: U+21d5 (8661)
 * Description: up down double arrow
 */
static wchar_t* UPDOWNARROW_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Updownarrow";
static int* UPDOWNARROW_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vArr html character entity reference model.
 *
 * Name: vArr
 * Character: ⇕
 * Unicode code point: U+21d5 (8661)
 * Description: up down double arrow
 */
static wchar_t* VARR_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vArr";
static int* VARR_UP_DOWN_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nwArr html character entity reference model.
 *
 * Name: nwArr
 * Character: ⇖
 * Unicode code point: U+21d6 (8662)
 * Description: north west double arrow
 */
static wchar_t* NWARR_NORTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwArr";
static int* NWARR_NORTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The neArr html character entity reference model.
 *
 * Name: neArr
 * Character: ⇗
 * Unicode code point: U+21d7 (8663)
 * Description: north east double arrow
 */
static wchar_t* NEARR_NORTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"neArr";
static int* NEARR_NORTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The seArr html character entity reference model.
 *
 * Name: seArr
 * Character: ⇘
 * Unicode code point: U+21d8 (8664)
 * Description: south east double arrow
 */
static wchar_t* SEARR_SOUTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"seArr";
static int* SEARR_SOUTH_EAST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The swArr html character entity reference model.
 *
 * Name: swArr
 * Character: ⇙
 * Unicode code point: U+21d9 (8665)
 * Description: south west double arrow
 */
static wchar_t* SWARR_SOUTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swArr";
static int* SWARR_SOUTH_WEST_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lleftarrow html character entity reference model.
 *
 * Name: Lleftarrow
 * Character: ⇚
 * Unicode code point: U+21da (8666)
 * Description: leftwards triple arrow
 */
static wchar_t* LLEFTARROW_LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lleftarrow";
static int* LLEFTARROW_LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lAarr html character entity reference model.
 *
 * Name: lAarr
 * Character: ⇚
 * Unicode code point: U+21da (8666)
 * Description: leftwards triple arrow
 */
static wchar_t* LAARR_LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lAarr";
static int* LAARR_LEFTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rrightarrow html character entity reference model.
 *
 * Name: Rrightarrow
 * Character: ⇛
 * Unicode code point: U+21db (8667)
 * Description: rightwards triple arrow
 */
static wchar_t* RRIGHTARROW_RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rrightarrow";
static int* RRIGHTARROW_RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rAarr html character entity reference model.
 *
 * Name: rAarr
 * Character: ⇛
 * Unicode code point: U+21db (8667)
 * Description: rightwards triple arrow
 */
static wchar_t* RAARR_RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rAarr";
static int* RAARR_RIGHTWARDS_TRIPLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zigrarr html character entity reference model.
 *
 * Name: zigrarr
 * Character: ⇝
 * Unicode code point: U+21dd (8669)
 * Description: rightwards squiggle arrow
 */
static wchar_t* ZIGRARR_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zigrarr";
static int* ZIGRARR_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftArrowBar html character entity reference model.
 *
 * Name: LeftArrowBar
 * Character: ⇤
 * Unicode code point: U+21e4 (8676)
 * Description: leftwards arrow to bar
 */
static wchar_t* LEFTARROWBAR_LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftArrowBar";
static int* LEFTARROWBAR_LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrb html character entity reference model.
 *
 * Name: larrb
 * Character: ⇤
 * Unicode code point: U+21e4 (8676)
 * Description: leftwards arrow to bar
 */
static wchar_t* LARRB_LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrb";
static int* LARRB_LEFTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightArrowBar html character entity reference model.
 *
 * Name: RightArrowBar
 * Character: ⇥
 * Unicode code point: U+21e5 (8677)
 * Description: rightwards arrow to bar
 */
static wchar_t* RIGHTARROWBAR_RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightArrowBar";
static int* RIGHTARROWBAR_RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrb html character entity reference model.
 *
 * Name: rarrb
 * Character: ⇥
 * Unicode code point: U+21e5 (8677)
 * Description: rightwards arrow to bar
 */
static wchar_t* RARRB_RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrb";
static int* RARRB_RIGHTWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownArrowUpArrow html character entity reference model.
 *
 * Name: DownArrowUpArrow
 * Character: ⇵
 * Unicode code point: U+21f5 (8693)
 * Description: downwards arrow leftwards of upwards arrow
 */
static wchar_t* DOWNARROWUPARROW_DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrowUpArrow";
static int* DOWNARROWUPARROW_DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duarr html character entity reference model.
 *
 * Name: duarr
 * Character: ⇵
 * Unicode code point: U+21f5 (8693)
 * Description: downwards arrow leftwards of upwards arrow
 */
static wchar_t* DUARR_DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"duarr";
static int* DUARR_DOWNWARDS_ARROW_LEFTWARDS_OF_UPWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The loarr html character entity reference model.
 *
 * Name: loarr
 * Character: ⇽
 * Unicode code point: U+21fd (8701)
 * Description: leftwards open-headed arrow
 */
static wchar_t* LOARR_LEFTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loarr";
static int* LOARR_LEFTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The roarr html character entity reference model.
 *
 * Name: roarr
 * Character: ⇾
 * Unicode code point: U+21fe (8702)
 * Description: rightwards open-headed arrow
 */
static wchar_t* ROARR_RIGHTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roarr";
static int* ROARR_RIGHTWARDS_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hoarr html character entity reference model.
 *
 * Name: hoarr
 * Character: ⇿
 * Unicode code point: U+21ff (8703)
 * Description: left right open-headed arrow
 */
static wchar_t* HOARR_LEFT_RIGHT_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hoarr";
static int* HOARR_LEFT_RIGHT_OPEN_HEADED_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ForAll html character entity reference model.
 *
 * Name: ForAll
 * Character: ∀
 * Unicode code point: U+2200 (8704)
 * Description: for all
 */
static wchar_t* CAMEL_FORALL_FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ForAll";
static int* CAMEL_FORALL_FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The forall html character entity reference model.
 *
 * Name: forall
 * Character: ∀
 * Unicode code point: U+2200 (8704)
 * Description: for all
 */
static wchar_t* SMALL_FORALL_FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"forall";
static int* SMALL_FORALL_FOR_ALL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The comp html character entity reference model.
 *
 * Name: comp
 * Character: ∁
 * Unicode code point: U+2201 (8705)
 * Description: complement
 */
static wchar_t* COMP_COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"comp";
static int* COMP_COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The complement html character entity reference model.
 *
 * Name: complement
 * Character: ∁
 * Unicode code point: U+2201 (8705)
 * Description: complement
 */
static wchar_t* COMPLEMENT_COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"complement";
static int* COMPLEMENT_COMPLEMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PartialD html character entity reference model.
 *
 * Name: PartialD
 * Character: ∂
 * Unicode code point: U+2202 (8706)
 * Description: partial differential
 */
static wchar_t* PARTIALD_PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PartialD";
static int* PARTIALD_PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The part html character entity reference model.
 *
 * Name: part
 * Character: ∂
 * Unicode code point: U+2202 (8706)
 * Description: partial differential
 */
static wchar_t* PART_PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"part";
static int* PART_PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npart html character entity reference model.
 *
 * Name: npart
 * Character: ∂̸
 * Unicode code point: U+2202;U+0338 (8706;824)
 * Description: partial differential with slash
 */
static wchar_t* NPART_PARTIAL_DIFFERENTIAL_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npart";
static int* NPART_PARTIAL_DIFFERENTIAL_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Exists html character entity reference model.
 *
 * Name: Exists
 * Character: ∃
 * Unicode code point: U+2203 (8707)
 * Description: there exists
 */
static wchar_t* EXISTS_THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Exists";
static int* EXISTS_THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The exist html character entity reference model.
 *
 * Name: exist
 * Character: ∃
 * Unicode code point: U+2203 (8707)
 * Description: there exists
 */
static wchar_t* EXIST_THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"exist";
static int* EXIST_THERE_EXISTS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotExists html character entity reference model.
 *
 * Name: NotExists
 * Character: ∄
 * Unicode code point: U+2204 (8708)
 * Description: there does not exist
 */
static wchar_t* NOTEXISTS_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotExists";
static int* NOTEXISTS_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nexist html character entity reference model.
 *
 * Name: nexist
 * Character: ∄
 * Unicode code point: U+2204 (8708)
 * Description: there does not exist
 */
static wchar_t* NEXIST_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nexist";
static int* NEXIST_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nexists html character entity reference model.
 *
 * Name: nexists
 * Character: ∄
 * Unicode code point: U+2204 (8708)
 * Description: there does not exist
 */
static wchar_t* NEXISTS_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nexists";
static int* NEXISTS_THERE_DOES_NOT_EXIST_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The empty html character entity reference model.
 *
 * Name: empty
 * Character: ∅
 * Unicode code point: U+2205 (8709)
 * Description: empty set
 */
static wchar_t* EMPTY_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"empty";
static int* EMPTY_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emptyset html character entity reference model.
 *
 * Name: emptyset
 * Character: ∅
 * Unicode code point: U+2205 (8709)
 * Description: empty set
 */
static wchar_t* EMPTYSET_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emptyset";
static int* EMPTYSET_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The emptyv html character entity reference model.
 *
 * Name: emptyv
 * Character: ∅
 * Unicode code point: U+2205 (8709)
 * Description: empty set
 */
static wchar_t* EMPTYV_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"emptyv";
static int* EMPTYV_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varnothing html character entity reference model.
 *
 * Name: varnothing
 * Character: ∅
 * Unicode code point: U+2205 (8709)
 * Description: empty set
 */
static wchar_t* VARNOTHING_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varnothing";
static int* VARNOTHING_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Del html character entity reference model.
 *
 * Name: Del
 * Character: ∇
 * Unicode code point: U+2207 (8711)
 * Description: nabla
 */
static wchar_t* DEL_NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Del";
static int* DEL_NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nabla html character entity reference model.
 *
 * Name: nabla
 * Character: ∇
 * Unicode code point: U+2207 (8711)
 * Description: nabla
 */
static wchar_t* NABLA_NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nabla";
static int* NABLA_NABLA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Element html character entity reference model.
 *
 * Name: Element
 * Character: ∈
 * Unicode code point: U+2208 (8712)
 * Description: element of
 */
static wchar_t* ELEMENT_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Element";
static int* ELEMENT_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The in html character entity reference model.
 *
 * Name: in
 * Character: ∈
 * Unicode code point: U+2208 (8712)
 * Description: element of
 */
static wchar_t* IN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"in";
static int* IN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isin html character entity reference model.
 *
 * Name: isin
 * Character: ∈
 * Unicode code point: U+2208 (8712)
 * Description: element of
 */
static wchar_t* ISIN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isin";
static int* ISIN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isinv html character entity reference model.
 *
 * Name: isinv
 * Character: ∈
 * Unicode code point: U+2208 (8712)
 * Description: element of
 */
static wchar_t* ISINV_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isinv";
static int* ISINV_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotElement html character entity reference model.
 *
 * Name: NotElement
 * Character: ∉
 * Unicode code point: U+2209 (8713)
 * Description: not an element of
 */
static wchar_t* NOTELEMENT_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotElement";
static int* NOTELEMENT_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notin html character entity reference model.
 *
 * Name: notin
 * Character: ∉
 * Unicode code point: U+2209 (8713)
 * Description: not an element of
 */
static wchar_t* NOTIN_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notin";
static int* NOTIN_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notinva html character entity reference model.
 *
 * Name: notinva
 * Character: ∉
 * Unicode code point: U+2209 (8713)
 * Description: not an element of
 */
static wchar_t* NOTINVA_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinva";
static int* NOTINVA_NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ReverseElement html character entity reference model.
 *
 * Name: ReverseElement
 * Character: ∋
 * Unicode code point: U+220b (8715)
 * Description: contains as member
 */
static wchar_t* REVERSEELEMENT_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseElement";
static int* REVERSEELEMENT_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SuchThat html character entity reference model.
 *
 * Name: SuchThat
 * Character: ∋
 * Unicode code point: U+220b (8715)
 * Description: contains as member
 */
static wchar_t* SUCHTHAT_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SuchThat";
static int* SUCHTHAT_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ni html character entity reference model.
 *
 * Name: ni
 * Character: ∋
 * Unicode code point: U+220b (8715)
 * Description: contains as member
 */
static wchar_t* NI_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ni";
static int* NI_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The niv html character entity reference model.
 *
 * Name: niv
 * Character: ∋
 * Unicode code point: U+220b (8715)
 * Description: contains as member
 */
static wchar_t* NIV_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"niv";
static int* NIV_CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotReverseElement html character entity reference model.
 *
 * Name: NotReverseElement
 * Character: ∌
 * Unicode code point: U+220c (8716)
 * Description: does not contain as member
 */
static wchar_t* NOTREVERSEELEMENT_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotReverseElement";
static int* NOTREVERSEELEMENT_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notni html character entity reference model.
 *
 * Name: notni
 * Character: ∌
 * Unicode code point: U+220c (8716)
 * Description: does not contain as member
 */
static wchar_t* NOTNI_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notni";
static int* NOTNI_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notniva html character entity reference model.
 *
 * Name: notniva
 * Character: ∌
 * Unicode code point: U+220c (8716)
 * Description: does not contain as member
 */
static wchar_t* NOTNIVA_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notniva";
static int* NOTNIVA_DOES_NOT_CONTAIN_AS_MEMBER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Product html character entity reference model.
 *
 * Name: Product
 * Character: ∏
 * Unicode code point: U+220f (8719)
 * Description: n-ary product
 */
static wchar_t* PRODUCT_N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Product";
static int* PRODUCT_N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prod html character entity reference model.
 *
 * Name: prod
 * Character: ∏
 * Unicode code point: U+220f (8719)
 * Description: n-ary product
 */
static wchar_t* PROD_N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prod";
static int* PROD_N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Coproduct html character entity reference model.
 *
 * Name: Coproduct
 * Character: ∐
 * Unicode code point: U+2210 (8720)
 * Description: n-ary coproduct
 */
static wchar_t* COPRODUCT_N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Coproduct";
static int* COPRODUCT_N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The coprod html character entity reference model.
 *
 * Name: coprod
 * Character: ∐
 * Unicode code point: U+2210 (8720)
 * Description: n-ary coproduct
 */
static wchar_t* COPROD_N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"coprod";
static int* COPROD_N_ARY_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sum html character entity reference model.
 *
 * Name: Sum
 * Character: ∑
 * Unicode code point: U+2211 (8721)
 * Description: n-ary summation
 */
static wchar_t* CAMEL_SUM_N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sum";
static int* CAMEL_SUM_N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sum html character entity reference model.
 *
 * Name: sum
 * Character: ∑
 * Unicode code point: U+2211 (8721)
 * Description: n-ary summation
 */
static wchar_t* SMALL_SUM_N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sum";
static int* SMALL_SUM_N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minus html character entity reference model.
 *
 * Name: minus
 * Character: −
 * Unicode code point: U+2212 (8722)
 * Description: minus sign
 */
static wchar_t* MINUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minus";
static int* MINUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The MinusPlus html character entity reference model.
 *
 * Name: MinusPlus
 * Character: ∓
 * Unicode code point: U+2213 (8723)
 * Description: minus-or-plus sign
 */
static wchar_t* MINUSPLUS_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"MinusPlus";
static int* MINUSPLUS_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mnplus html character entity reference model.
 *
 * Name: mnplus
 * Character: ∓
 * Unicode code point: U+2213 (8723)
 * Description: minus-or-plus sign
 */
static wchar_t* MNPLUS_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mnplus";
static int* MNPLUS_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mp html character entity reference model.
 *
 * Name: mp
 * Character: ∓
 * Unicode code point: U+2213 (8723)
 * Description: minus-or-plus sign
 */
static wchar_t* MP_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mp";
static int* MP_MINUS_OR_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dotplus html character entity reference model.
 *
 * Name: dotplus
 * Character: ∔
 * Unicode code point: U+2214 (8724)
 * Description: dot plus
 */
static wchar_t* DOTPLUS_DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotplus";
static int* DOTPLUS_DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plusdo html character entity reference model.
 *
 * Name: plusdo
 * Character: ∔
 * Unicode code point: U+2214 (8724)
 * Description: dot plus
 */
static wchar_t* PLUSDO_DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusdo";
static int* PLUSDO_DOT_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Backslash html character entity reference model.
 *
 * Name: Backslash
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* BACKSLASH_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Backslash";
static int* BACKSLASH_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The setminus html character entity reference model.
 *
 * Name: setminus
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* SETMINUS_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"setminus";
static int* SETMINUS_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The setmn html character entity reference model.
 *
 * Name: setmn
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* SETMN_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"setmn";
static int* SETMN_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smallsetminus html character entity reference model.
 *
 * Name: smallsetminus
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* SMALLSETMINUS_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smallsetminus";
static int* SMALLSETMINUS_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ssetmn html character entity reference model.
 *
 * Name: ssetmn
 * Character: ∖
 * Unicode code point: U+2216 (8726)
 * Description: set minus
 */
static wchar_t* SSETMN_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ssetmn";
static int* SSETMN_SET_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lowast html character entity reference model.
 *
 * Name: lowast
 * Character: ∗
 * Unicode code point: U+2217 (8727)
 * Description: asterisk operator
 */
static wchar_t* LOWAST_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lowast";
static int* LOWAST_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SmallCircle html character entity reference model.
 *
 * Name: SmallCircle
 * Character: ∘
 * Unicode code point: U+2218 (8728)
 * Description: ring operator
 */
static wchar_t* SMALLCIRCLE_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SmallCircle";
static int* SMALLCIRCLE_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compfn html character entity reference model.
 *
 * Name: compfn
 * Character: ∘
 * Unicode code point: U+2218 (8728)
 * Description: ring operator
 */
static wchar_t* COMPFN_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"compfn";
static int* COMPFN_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sqrt html character entity reference model.
 *
 * Name: Sqrt
 * Character: √
 * Unicode code point: U+221a (8730)
 * Description: square root
 */
static wchar_t* SQRT_SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sqrt";
static int* SQRT_SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The radic html character entity reference model.
 *
 * Name: radic
 * Character: √
 * Unicode code point: U+221a (8730)
 * Description: square root
 */
static wchar_t* RADIC_SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"radic";
static int* RADIC_SQUARE_ROOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Proportional html character entity reference model.
 *
 * Name: Proportional
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* PROPORTIONAL_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Proportional";
static int* PROPORTIONAL_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prop html character entity reference model.
 *
 * Name: prop
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* PROP_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prop";
static int* PROP_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The propto html character entity reference model.
 *
 * Name: propto
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* PROPTO_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"propto";
static int* PROPTO_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varpropto html character entity reference model.
 *
 * Name: varpropto
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* VARPROPTO_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varpropto";
static int* VARPROPTO_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vprop html character entity reference model.
 *
 * Name: vprop
 * Character: ∝
 * Unicode code point: U+221d (8733)
 * Description: proportional to
 */
static wchar_t* VPROP_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vprop";
static int* VPROP_PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The infin html character entity reference model.
 *
 * Name: infin
 * Character: ∞
 * Unicode code point: U+221e (8734)
 * Description: infinity
 */
static wchar_t* INFIN_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"infin";
static int* INFIN_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angrt html character entity reference model.
 *
 * Name: angrt
 * Character: ∟
 * Unicode code point: U+221f (8735)
 * Description: right angle
 */
static wchar_t* ANGRT_RIGHT_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrt";
static int* ANGRT_RIGHT_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ang html character entity reference model.
 *
 * Name: ang
 * Character: ∠
 * Unicode code point: U+2220 (8736)
 * Description: angle
 */
static wchar_t* ANG_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ang";
static int* ANG_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angle html character entity reference model.
 *
 * Name: angle
 * Character: ∠
 * Unicode code point: U+2220 (8736)
 * Description: angle
 */
static wchar_t* ANGLE_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angle";
static int* ANGLE_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nang html character entity reference model.
 *
 * Name: nang
 * Character: ∠⃒
 * Unicode code point: U+2220;U+20d2 (8736;8402)
 * Description: angle with vertical line
 */
static wchar_t* NANG_ANGLE_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nang";
static int* NANG_ANGLE_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsd html character entity reference model.
 *
 * Name: angmsd
 * Character: ∡
 * Unicode code point: U+2221 (8737)
 * Description: measured angle
 */
static wchar_t* ANGMSD_MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsd";
static int* ANGMSD_MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The measuredangle html character entity reference model.
 *
 * Name: measuredangle
 * Character: ∡
 * Unicode code point: U+2221 (8737)
 * Description: measured angle
 */
static wchar_t* MEASUREDANGLE_MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"measuredangle";
static int* MEASUREDANGLE_MEASURED_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angsph html character entity reference model.
 *
 * Name: angsph
 * Character: ∢
 * Unicode code point: U+2222 (8738)
 * Description: spherical angle
 */
static wchar_t* ANGSPH_SPHERICAL_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angsph";
static int* ANGSPH_SPHERICAL_ANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VerticalBar html character entity reference model.
 *
 * Name: VerticalBar
 * Character: ∣
 * Unicode code point: U+2223 (8739)
 * Description: divides
 */
static wchar_t* VERTICALBAR_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalBar";
static int* VERTICALBAR_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mid html character entity reference model.
 *
 * Name: mid
 * Character: ∣
 * Unicode code point: U+2223 (8739)
 * Description: divides
 */
static wchar_t* MID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mid";
static int* MID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The shortmid html character entity reference model.
 *
 * Name: shortmid
 * Character: ∣
 * Unicode code point: U+2223 (8739)
 * Description: divides
 */
static wchar_t* SHORTMID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shortmid";
static int* SHORTMID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smid html character entity reference model.
 *
 * Name: smid
 * Character: ∣
 * Unicode code point: U+2223 (8739)
 * Description: divides
 */
static wchar_t* SMID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smid";
static int* SMID_DIVIDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotVerticalBar html character entity reference model.
 *
 * Name: NotVerticalBar
 * Character: ∤
 * Unicode code point: U+2224 (8740)
 * Description: does not divide
 */
static wchar_t* NOTVERTICALBAR_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotVerticalBar";
static int* NOTVERTICALBAR_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nmid html character entity reference model.
 *
 * Name: nmid
 * Character: ∤
 * Unicode code point: U+2224 (8740)
 * Description: does not divide
 */
static wchar_t* NMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nmid";
static int* NMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nshortmid html character entity reference model.
 *
 * Name: nshortmid
 * Character: ∤
 * Unicode code point: U+2224 (8740)
 * Description: does not divide
 */
static wchar_t* NSHORTMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nshortmid";
static int* NSHORTMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsmid html character entity reference model.
 *
 * Name: nsmid
 * Character: ∤
 * Unicode code point: U+2224 (8740)
 * Description: does not divide
 */
static wchar_t* NSMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsmid";
static int* NSMID_DOES_NOT_DIVIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleVerticalBar html character entity reference model.
 *
 * Name: DoubleVerticalBar
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* DOUBLEVERTICALBAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleVerticalBar";
static int* DOUBLEVERTICALBAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The par html character entity reference model.
 *
 * Name: par
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* PAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"par";
static int* PAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parallel html character entity reference model.
 *
 * Name: parallel
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* PARALLEL_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"parallel";
static int* PARALLEL_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The shortparallel html character entity reference model.
 *
 * Name: shortparallel
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* SHORTPARALLEL_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"shortparallel";
static int* SHORTPARALLEL_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The spar html character entity reference model.
 *
 * Name: spar
 * Character: ∥
 * Unicode code point: U+2225 (8741)
 * Description: parallel to
 */
static wchar_t* SPAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"spar";
static int* SPAR_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotDoubleVerticalBar html character entity reference model.
 *
 * Name: NotDoubleVerticalBar
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NOTDOUBLEVERTICALBAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotDoubleVerticalBar";
static int* NOTDOUBLEVERTICALBAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npar html character entity reference model.
 *
 * Name: npar
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NPAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npar";
static int* NPAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nparallel html character entity reference model.
 *
 * Name: nparallel
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NPARALLEL_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nparallel";
static int* NPARALLEL_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nshortparallel html character entity reference model.
 *
 * Name: nshortparallel
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NSHORTPARALLEL_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nshortparallel";
static int* NSHORTPARALLEL_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nspar html character entity reference model.
 *
 * Name: nspar
 * Character: ∦
 * Unicode code point: U+2226 (8742)
 * Description: not parallel to
 */
static wchar_t* NSPAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nspar";
static int* NSPAR_NOT_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The and html character entity reference model.
 *
 * Name: and
 * Character: ∧
 * Unicode code point: U+2227 (8743)
 * Description: logical and
 */
static wchar_t* AND_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"and";
static int* AND_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wedge html character entity reference model.
 *
 * Name: wedge
 * Character: ∧
 * Unicode code point: U+2227 (8743)
 * Description: logical and
 */
static wchar_t* WEDGE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wedge";
static int* WEDGE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The or html character entity reference model.
 *
 * Name: or
 * Character: ∨
 * Unicode code point: U+2228 (8744)
 * Description: logical or
 */
static wchar_t* OR_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"or";
static int* OR_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vee html character entity reference model.
 *
 * Name: vee
 * Character: ∨
 * Unicode code point: U+2228 (8744)
 * Description: logical or
 */
static wchar_t* VEE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vee";
static int* VEE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cap html character entity reference model.
 *
 * Name: cap
 * Character: ∩
 * Unicode code point: U+2229 (8745)
 * Description: intersection
 */
static wchar_t* CAP_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cap";
static int* CAP_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The caps html character entity reference model.
 *
 * Name: caps
 * Character: ∩︀
 * Unicode code point: U+2229;U+fe00 (8745;65024)
 * Description: intersection with serifs
 */
static wchar_t* CAPS_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"caps";
static int* CAPS_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cup html character entity reference model.
 *
 * Name: cup
 * Character: ∪
 * Unicode code point: U+222a (8746)
 * Description: union
 */
static wchar_t* CUP_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cup";
static int* CUP_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cups html character entity reference model.
 *
 * Name: cups
 * Character: ∪︀
 * Unicode code point: U+222a;U+fe00 (8746;65024)
 * Description: union with serifs
 */
static wchar_t* CUPS_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cups";
static int* CUPS_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Integral html character entity reference model.
 *
 * Name: Integral
 * Character: ∫
 * Unicode code point: U+222b (8747)
 * Description: integral
 */
static wchar_t* INTEGRAL_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Integral";
static int* INTEGRAL_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The int html character entity reference model.
 *
 * Name: int
 * Character: ∫
 * Unicode code point: U+222b (8747)
 * Description: integral
 */
static wchar_t* INT_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"int";
static int* INT_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Int html character entity reference model.
 *
 * Name: Int
 * Character: ∬
 * Unicode code point: U+222c (8748)
 * Description: double integral
 */
static wchar_t* INT_DOUBLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Int";
static int* INT_DOUBLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iiint html character entity reference model.
 *
 * Name: iiint
 * Character: ∭
 * Unicode code point: U+222d (8749)
 * Description: triple integral
 */
static wchar_t* IIINT_TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiint";
static int* IIINT_TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tint html character entity reference model.
 *
 * Name: tint
 * Character: ∭
 * Unicode code point: U+222d (8749)
 * Description: triple integral
 */
static wchar_t* TINT_TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tint";
static int* TINT_TRIPLE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ContourIntegral html character entity reference model.
 *
 * Name: ContourIntegral
 * Character: ∮
 * Unicode code point: U+222e (8750)
 * Description: contour integral
 */
static wchar_t* CONTOURINTEGRAL_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ContourIntegral";
static int* CONTOURINTEGRAL_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The conint html character entity reference model.
 *
 * Name: conint
 * Character: ∮
 * Unicode code point: U+222e (8750)
 * Description: contour integral
 */
static wchar_t* CONINT_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"conint";
static int* CONINT_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oint html character entity reference model.
 *
 * Name: oint
 * Character: ∮
 * Unicode code point: U+222e (8750)
 * Description: contour integral
 */
static wchar_t* OINT_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oint";
static int* OINT_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Conint html character entity reference model.
 *
 * Name: Conint
 * Character: ∯
 * Unicode code point: U+222f (8751)
 * Description: surface integral
 */
static wchar_t* CONINT_SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Conint";
static int* CONINT_SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleContourIntegral html character entity reference model.
 *
 * Name: DoubleContourIntegral
 * Character: ∯
 * Unicode code point: U+222f (8751)
 * Description: surface integral
 */
static wchar_t* DOUBLECONTOURINTEGRAL_SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleContourIntegral";
static int* DOUBLECONTOURINTEGRAL_SURFACE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cconint html character entity reference model.
 *
 * Name: Cconint
 * Character: ∰
 * Unicode code point: U+2230 (8752)
 * Description: volume integral
 */
static wchar_t* CCONINT_VOLUME_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cconint";
static int* CCONINT_VOLUME_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cwint html character entity reference model.
 *
 * Name: cwint
 * Character: ∱
 * Unicode code point: U+2231 (8753)
 * Description: clockwise integral
 */
static wchar_t* CWINT_CLOCKWISE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cwint";
static int* CWINT_CLOCKWISE_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ClockwiseContourIntegral html character entity reference model.
 *
 * Name: ClockwiseContourIntegral
 * Character: ∲
 * Unicode code point: U+2232 (8754)
 * Description: clockwise contour integral
 */
static wchar_t* CLOCKWISECONTOURINTEGRAL_CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ClockwiseContourIntegral";
static int* CLOCKWISECONTOURINTEGRAL_CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cwconint html character entity reference model.
 *
 * Name: cwconint
 * Character: ∲
 * Unicode code point: U+2232 (8754)
 * Description: clockwise contour integral
 */
static wchar_t* CWCONINT_CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cwconint";
static int* CWCONINT_CLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CounterClockwiseContourIntegral html character entity reference model.
 *
 * Name: CounterClockwiseContourIntegral
 * Character: ∳
 * Unicode code point: U+2233 (8755)
 * Description: anticlockwise contour integral
 */
static wchar_t* COUNTERCLOCKWISECONTOURINTEGRAL_ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CounterClockwiseContourIntegral";
static int* COUNTERCLOCKWISECONTOURINTEGRAL_ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The awconint html character entity reference model.
 *
 * Name: awconint
 * Character: ∳
 * Unicode code point: U+2233 (8755)
 * Description: anticlockwise contour integral
 */
static wchar_t* AWCONINT_ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"awconint";
static int* AWCONINT_ANTICLOCKWISE_CONTOUR_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Therefore html character entity reference model.
 *
 * Name: Therefore
 * Character: ∴
 * Unicode code point: U+2234 (8756)
 * Description: therefore
 */
static wchar_t* CAMEL_THEREFORE_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Therefore";
static int* CAMEL_THEREFORE_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The there4 html character entity reference model.
 *
 * Name: there4
 * Character: ∴
 * Unicode code point: U+2234 (8756)
 * Description: therefore
 */
static wchar_t* THERE4_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"there4";
static int* THERE4_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The therefore html character entity reference model.
 *
 * Name: therefore
 * Character: ∴
 * Unicode code point: U+2234 (8756)
 * Description: therefore
 */
static wchar_t* SMALL_THEREFORE_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"therefore";
static int* SMALL_THEREFORE_THEREFORE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Because html character entity reference model.
 *
 * Name: Because
 * Character: ∵
 * Unicode code point: U+2235 (8757)
 * Description: because
 */
static wchar_t* CAMEL_BECAUSE_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Because";
static int* CAMEL_BECAUSE_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The becaus html character entity reference model.
 *
 * Name: becaus
 * Character: ∵
 * Unicode code point: U+2235 (8757)
 * Description: because
 */
static wchar_t* BECAUS_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"becaus";
static int* BECAUS_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The because html character entity reference model.
 *
 * Name: because
 * Character: ∵
 * Unicode code point: U+2235 (8757)
 * Description: because
 */
static wchar_t* SMALL_BECAUSE_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"because";
static int* SMALL_BECAUSE_BECAUSE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ratio html character entity reference model.
 *
 * Name: ratio
 * Character: ∶
 * Unicode code point: U+2236 (8758)
 * Description: ratio
 */
static wchar_t* RATIO_RATIO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ratio";
static int* RATIO_RATIO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Colon html character entity reference model.
 *
 * Name: Colon
 * Character: ∷
 * Unicode code point: U+2237 (8759)
 * Description: proportion
 */
static wchar_t* COLON_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Colon";
static int* COLON_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Proportion html character entity reference model.
 *
 * Name: Proportion
 * Character: ∷
 * Unicode code point: U+2237 (8759)
 * Description: proportion
 */
static wchar_t* PROPORTION_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Proportion";
static int* PROPORTION_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dotminus html character entity reference model.
 *
 * Name: dotminus
 * Character: ∸
 * Unicode code point: U+2238 (8760)
 * Description: dot minus
 */
static wchar_t* DOTMINUS_DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotminus";
static int* DOTMINUS_DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minusd html character entity reference model.
 *
 * Name: minusd
 * Character: ∸
 * Unicode code point: U+2238 (8760)
 * Description: dot minus
 */
static wchar_t* MINUSD_DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minusd";
static int* MINUSD_DOT_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mDDot html character entity reference model.
 *
 * Name: mDDot
 * Character: ∺
 * Unicode code point: U+223a (8762)
 * Description: geometric proportion
 */
static wchar_t* MDDOT_GEOMETRIC_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mDDot";
static int* MDDOT_GEOMETRIC_PROPORTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The homtht html character entity reference model.
 *
 * Name: homtht
 * Character: ∻
 * Unicode code point: U+223b (8763)
 * Description: homothetic
 */
static wchar_t* HOMTHT_HOMOTHETIC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"homtht";
static int* HOMTHT_HOMOTHETIC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tilde html character entity reference model.
 *
 * Name: Tilde
 * Character: ∼
 * Unicode code point: U+223c (8764)
 * Description: tilde operator
 */
static wchar_t* TILDE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tilde";
static int* TILDE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sim html character entity reference model.
 *
 * Name: sim
 * Character: ∼
 * Unicode code point: U+223c (8764)
 * Description: tilde operator
 */
static wchar_t* SIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sim";
static int* SIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thicksim html character entity reference model.
 *
 * Name: thicksim
 * Character: ∼
 * Unicode code point: U+223c (8764)
 * Description: tilde operator
 */
static wchar_t* THICKSIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thicksim";
static int* THICKSIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thksim html character entity reference model.
 *
 * Name: thksim
 * Character: ∼
 * Unicode code point: U+223c (8764)
 * Description: tilde operator
 */
static wchar_t* THKSIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thksim";
static int* THKSIM_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvsim html character entity reference model.
 *
 * Name: nvsim
 * Character: ∼⃒
 * Unicode code point: U+223c;U+20d2 (8764;8402)
 * Description: tilde operator with vertical line
 */
static wchar_t* NVSIM_TILDE_OPERATOR_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvsim";
static int* NVSIM_TILDE_OPERATOR_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The backsim html character entity reference model.
 *
 * Name: backsim
 * Character: ∽
 * Unicode code point: U+223d (8765)
 * Description: reversed tilde
 */
static wchar_t* BACKSIM_REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backsim";
static int* BACKSIM_REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsim html character entity reference model.
 *
 * Name: bsim
 * Character: ∽
 * Unicode code point: U+223d (8765)
 * Description: reversed tilde
 */
static wchar_t* BSIM_REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsim";
static int* BSIM_REVERSED_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The race html character entity reference model.
 *
 * Name: race
 * Character: ∽̱
 * Unicode code point: U+223d;U+0331 (8765;817)
 * Description: reversed tilde with underline
 */
static wchar_t* RACE_REVERSED_TILDE_WITH_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"race";
static int* RACE_REVERSED_TILDE_WITH_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ac html character entity reference model.
 *
 * Name: ac
 * Character: ∾
 * Unicode code point: U+223e (8766)
 * Description: inverted lazy s
 */
static wchar_t* AC_INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ac";
static int* AC_INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mstpos html character entity reference model.
 *
 * Name: mstpos
 * Character: ∾
 * Unicode code point: U+223e (8766)
 * Description: inverted lazy s
 */
static wchar_t* MSTPOS_INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mstpos";
static int* MSTPOS_INVERTED_LAZY_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acE html character entity reference model.
 *
 * Name: acE
 * Character: ∾̳
 * Unicode code point: U+223e;U+0333 (8766;819)
 * Description: inverted lazy s with double underline
 */
static wchar_t* ACE_INVERTED_LAZY_S_WITH_DOUBLE_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acE";
static int* ACE_INVERTED_LAZY_S_WITH_DOUBLE_UNDERLINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The acd html character entity reference model.
 *
 * Name: acd
 * Character: ∿
 * Unicode code point: U+223f (8767)
 * Description: sine wave
 */
static wchar_t* ACD_SINE_WAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"acd";
static int* ACD_SINE_WAVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VerticalTilde html character entity reference model.
 *
 * Name: VerticalTilde
 * Character: ≀
 * Unicode code point: U+2240 (8768)
 * Description: wreath product
 */
static wchar_t* VERTICALTILDE_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalTilde";
static int* VERTICALTILDE_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wr html character entity reference model.
 *
 * Name: wr
 * Character: ≀
 * Unicode code point: U+2240 (8768)
 * Description: wreath product
 */
static wchar_t* WR_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wr";
static int* WR_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wreath html character entity reference model.
 *
 * Name: wreath
 * Character: ≀
 * Unicode code point: U+2240 (8768)
 * Description: wreath product
 */
static wchar_t* WREATH_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wreath";
static int* WREATH_WREATH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotTilde html character entity reference model.
 *
 * Name: NotTilde
 * Character: ≁
 * Unicode code point: U+2241 (8769)
 * Description: not tilde
 */
static wchar_t* NOTTILDE_NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTilde";
static int* NOTTILDE_NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsim html character entity reference model.
 *
 * Name: nsim
 * Character: ≁
 * Unicode code point: U+2241 (8769)
 * Description: not tilde
 */
static wchar_t* NSIM_NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsim";
static int* NSIM_NOT_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The EqualTilde html character entity reference model.
 *
 * Name: EqualTilde
 * Character: ≂
 * Unicode code point: U+2242 (8770)
 * Description: minus tilde
 */
static wchar_t* EQUALTILDE_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EqualTilde";
static int* EQUALTILDE_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqsim html character entity reference model.
 *
 * Name: eqsim
 * Character: ≂
 * Unicode code point: U+2242 (8770)
 * Description: minus tilde
 */
static wchar_t* EQSIM_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqsim";
static int* EQSIM_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The esim html character entity reference model.
 *
 * Name: esim
 * Character: ≂
 * Unicode code point: U+2242 (8770)
 * Description: minus tilde
 */
static wchar_t* ESIM_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"esim";
static int* ESIM_MINUS_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotEqualTilde html character entity reference model.
 *
 * Name: NotEqualTilde
 * Character: ≂̸
 * Unicode code point: U+2242;U+0338 (8770;824)
 * Description: minus tilde with slash
 */
static wchar_t* NOTEQUALTILDE_MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotEqualTilde";
static int* NOTEQUALTILDE_MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nesim html character entity reference model.
 *
 * Name: nesim
 * Character: ≂̸
 * Unicode code point: U+2242;U+0338 (8770;824)
 * Description: minus tilde with slash
 */
static wchar_t* NESIM_MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nesim";
static int* NESIM_MINUS_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TildeEqual html character entity reference model.
 *
 * Name: TildeEqual
 * Character: ≃
 * Unicode code point: U+2243 (8771)
 * Description: asymptotically equal to
 */
static wchar_t* TILDEEQUAL_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeEqual";
static int* TILDEEQUAL_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sime html character entity reference model.
 *
 * Name: sime
 * Character: ≃
 * Unicode code point: U+2243 (8771)
 * Description: asymptotically equal to
 */
static wchar_t* SIME_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sime";
static int* SIME_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simeq html character entity reference model.
 *
 * Name: simeq
 * Character: ≃
 * Unicode code point: U+2243 (8771)
 * Description: asymptotically equal to
 */
static wchar_t* SIMEQ_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simeq";
static int* SIMEQ_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotTildeEqual html character entity reference model.
 *
 * Name: NotTildeEqual
 * Character: ≄
 * Unicode code point: U+2244 (8772)
 * Description: not asymptotically equal to
 */
static wchar_t* NOTTILDEEQUAL_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeEqual";
static int* NOTTILDEEQUAL_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsime html character entity reference model.
 *
 * Name: nsime
 * Character: ≄
 * Unicode code point: U+2244 (8772)
 * Description: not asymptotically equal to
 */
static wchar_t* NSIME_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsime";
static int* NSIME_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsimeq html character entity reference model.
 *
 * Name: nsimeq
 * Character: ≄
 * Unicode code point: U+2244 (8772)
 * Description: not asymptotically equal to
 */
static wchar_t* NSIMEQ_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsimeq";
static int* NSIMEQ_NOT_ASYMPTOTICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TildeFullEqual html character entity reference model.
 *
 * Name: TildeFullEqual
 * Character: ≅
 * Unicode code point: U+2245 (8773)
 * Description: approximately equal to
 */
static wchar_t* TILDEFULLEQUAL_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeFullEqual";
static int* TILDEFULLEQUAL_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cong html character entity reference model.
 *
 * Name: cong
 * Character: ≅
 * Unicode code point: U+2245 (8773)
 * Description: approximately equal to
 */
static wchar_t* CONG_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cong";
static int* CONG_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simne html character entity reference model.
 *
 * Name: simne
 * Character: ≆
 * Unicode code point: U+2246 (8774)
 * Description: approximately but not actually equal to
 */
static wchar_t* SIMNE_APPROXIMATELY_BUT_NOT_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simne";
static int* SIMNE_APPROXIMATELY_BUT_NOT_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotTildeFullEqual html character entity reference model.
 *
 * Name: NotTildeFullEqual
 * Character: ≇
 * Unicode code point: U+2247 (8775)
 * Description: neither approximately nor actually equal to
 */
static wchar_t* NOTTILDEFULLEQUAL_NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeFullEqual";
static int* NOTTILDEFULLEQUAL_NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncong html character entity reference model.
 *
 * Name: ncong
 * Character: ≇
 * Unicode code point: U+2247 (8775)
 * Description: neither approximately nor actually equal to
 */
static wchar_t* NCONG_NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncong";
static int* NCONG_NEITHER_APPROXIMATELY_NOR_ACTUALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The TildeTilde html character entity reference model.
 *
 * Name: TildeTilde
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* TILDETILDE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"TildeTilde";
static int* TILDETILDE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ap html character entity reference model.
 *
 * Name: ap
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* AP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ap";
static int* AP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approx html character entity reference model.
 *
 * Name: approx
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* APPROX_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"approx";
static int* APPROX_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asymp html character entity reference model.
 *
 * Name: asymp
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* ASYMP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"asymp";
static int* ASYMP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thickapprox html character entity reference model.
 *
 * Name: thickapprox
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* THICKAPPROX_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thickapprox";
static int* THICKAPPROX_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The thkap html character entity reference model.
 *
 * Name: thkap
 * Character: ≈
 * Unicode code point: U+2248 (8776)
 * Description: almost equal to
 */
static wchar_t* THKAP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"thkap";
static int* THKAP_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotTildeTilde html character entity reference model.
 *
 * Name: NotTildeTilde
 * Character: ≉
 * Unicode code point: U+2249 (8777)
 * Description: not almost equal to
 */
static wchar_t* NOTTILDETILDE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotTildeTilde";
static int* NOTTILDETILDE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nap html character entity reference model.
 *
 * Name: nap
 * Character: ≉
 * Unicode code point: U+2249 (8777)
 * Description: not almost equal to
 */
static wchar_t* NAP_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nap";
static int* NAP_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The napprox html character entity reference model.
 *
 * Name: napprox
 * Character: ≉
 * Unicode code point: U+2249 (8777)
 * Description: not almost equal to
 */
static wchar_t* NAPPROX_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napprox";
static int* NAPPROX_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ape html character entity reference model.
 *
 * Name: ape
 * Character: ≊
 * Unicode code point: U+224a (8778)
 * Description: almost equal or equal to
 */
static wchar_t* APE_ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ape";
static int* APE_ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The approxeq html character entity reference model.
 *
 * Name: approxeq
 * Character: ≊
 * Unicode code point: U+224a (8778)
 * Description: almost equal or equal to
 */
static wchar_t* APPROXEQ_ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"approxeq";
static int* APPROXEQ_ALMOST_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apid html character entity reference model.
 *
 * Name: apid
 * Character: ≋
 * Unicode code point: U+224b (8779)
 * Description: triple tilde
 */
static wchar_t* APID_TRIPLE_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apid";
static int* APID_TRIPLE_TILDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The napid html character entity reference model.
 *
 * Name: napid
 * Character: ≋̸
 * Unicode code point: U+224b;U+0338 (8779;824)
 * Description: triple tilde with slash
 */
static wchar_t* NAPID_TRIPLE_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napid";
static int* NAPID_TRIPLE_TILDE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The backcong html character entity reference model.
 *
 * Name: backcong
 * Character: ≌
 * Unicode code point: U+224c (8780)
 * Description: all equal to
 */
static wchar_t* BACKCONG_ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backcong";
static int* BACKCONG_ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bcong html character entity reference model.
 *
 * Name: bcong
 * Character: ≌
 * Unicode code point: U+224c (8780)
 * Description: all equal to
 */
static wchar_t* BCONG_ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bcong";
static int* BCONG_ALL_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CupCap html character entity reference model.
 *
 * Name: CupCap
 * Character: ≍
 * Unicode code point: U+224d (8781)
 * Description: equivalent to
 */
static wchar_t* CUPCAP_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CupCap";
static int* CUPCAP_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The asympeq html character entity reference model.
 *
 * Name: asympeq
 * Character: ≍
 * Unicode code point: U+224d (8781)
 * Description: equivalent to
 */
static wchar_t* ASYMPEQ_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"asympeq";
static int* ASYMPEQ_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvap html character entity reference model.
 *
 * Name: nvap
 * Character: ≍⃒
 * Unicode code point: U+224d;U+20d2 (8781;8402)
 * Description: equivalent to with vertical line
 */
static wchar_t* NVAP_EQUIVALENT_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvap";
static int* NVAP_EQUIVALENT_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bumpeq html character entity reference model.
 *
 * Name: Bumpeq
 * Character: ≎
 * Unicode code point: U+224e (8782)
 * Description: geometrically equivalent to
 */
static wchar_t* BUMPEQ_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bumpeq";
static int* BUMPEQ_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The HumpDownHump html character entity reference model.
 *
 * Name: HumpDownHump
 * Character: ≎
 * Unicode code point: U+224e (8782)
 * Description: geometrically equivalent to
 */
static wchar_t* HUMPDOWNHUMP_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HumpDownHump";
static int* HUMPDOWNHUMP_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bump html character entity reference model.
 *
 * Name: bump
 * Character: ≎
 * Unicode code point: U+224e (8782)
 * Description: geometrically equivalent to
 */
static wchar_t* BUMP_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bump";
static int* BUMP_GEOMETRICALLY_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotHumpDownHump html character entity reference model.
 *
 * Name: NotHumpDownHump
 * Character: ≎̸
 * Unicode code point: U+224e;U+0338 (8782;824)
 * Description: geometrically equivalent to with slash
 */
static wchar_t* NOTHUMPDOWNHUMP_GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotHumpDownHump";
static int* NOTHUMPDOWNHUMP_GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nbump html character entity reference model.
 *
 * Name: nbump
 * Character: ≎̸
 * Unicode code point: U+224e;U+0338 (8782;824)
 * Description: geometrically equivalent to with slash
 */
static wchar_t* NBUMP_GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nbump";
static int* NBUMP_GEOMETRICALLY_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The HumpEqual html character entity reference model.
 *
 * Name: HumpEqual
 * Character: ≏
 * Unicode code point: U+224f (8783)
 * Description: difference between
 */
static wchar_t* HUMPEQUAL_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HumpEqual";
static int* HUMPEQUAL_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bumpe html character entity reference model.
 *
 * Name: bumpe
 * Character: ≏
 * Unicode code point: U+224f (8783)
 * Description: difference between
 */
static wchar_t* BUMPE_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bumpe";
static int* BUMPE_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bumpeq html character entity reference model.
 *
 * Name: bumpeq
 * Character: ≏
 * Unicode code point: U+224f (8783)
 * Description: difference between
 */
static wchar_t* BUMPEQ_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bumpeq";
static int* BUMPEQ_DIFFERENCE_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotHumpEqual html character entity reference model.
 *
 * Name: NotHumpEqual
 * Character: ≏̸
 * Unicode code point: U+224f;U+0338 (8783;824)
 * Description: difference between with slash
 */
static wchar_t* NOTHUMPEQUAL_DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotHumpEqual";
static int* NOTHUMPEQUAL_DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nbumpe html character entity reference model.
 *
 * Name: nbumpe
 * Character: ≏̸
 * Unicode code point: U+224f;U+0338 (8783;824)
 * Description: difference between with slash
 */
static wchar_t* NBUMPE_DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nbumpe";
static int* NBUMPE_DIFFERENCE_BETWEEN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DotEqual html character entity reference model.
 *
 * Name: DotEqual
 * Character: ≐
 * Unicode code point: U+2250 (8784)
 * Description: approaches the limit
 */
static wchar_t* DOTEQUAL_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DotEqual";
static int* DOTEQUAL_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The doteq html character entity reference model.
 *
 * Name: doteq
 * Character: ≐
 * Unicode code point: U+2250 (8784)
 * Description: approaches the limit
 */
static wchar_t* DOTEQ_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"doteq";
static int* DOTEQ_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The esdot html character entity reference model.
 *
 * Name: esdot
 * Character: ≐
 * Unicode code point: U+2250 (8784)
 * Description: approaches the limit
 */
static wchar_t* ESDOT_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"esdot";
static int* ESDOT_APPROACHES_THE_LIMIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nedot html character entity reference model.
 *
 * Name: nedot
 * Character: ≐̸
 * Unicode code point: U+2250;U+0338 (8784;824)
 * Description: approaches the limit with slash
 */
static wchar_t* NEDOT_APPROACHES_THE_LIMIT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nedot";
static int* NEDOT_APPROACHES_THE_LIMIT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The doteqdot html character entity reference model.
 *
 * Name: doteqdot
 * Character: ≑
 * Unicode code point: U+2251 (8785)
 * Description: geometrically equal to
 */
static wchar_t* DOTEQDOT_GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"doteqdot";
static int* DOTEQDOT_GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eDot html character entity reference model.
 *
 * Name: eDot
 * Character: ≑
 * Unicode code point: U+2251 (8785)
 * Description: geometrically equal to
 */
static wchar_t* EDOT_GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eDot";
static int* EDOT_GEOMETRICALLY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The efDot html character entity reference model.
 *
 * Name: efDot
 * Character: ≒
 * Unicode code point: U+2252 (8786)
 * Description: approximately equal to or the image of
 */
static wchar_t* EFDOT_APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"efDot";
static int* EFDOT_APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fallingdotseq html character entity reference model.
 *
 * Name: fallingdotseq
 * Character: ≒
 * Unicode code point: U+2252 (8786)
 * Description: approximately equal to or the image of
 */
static wchar_t* FALLINGDOTSEQ_APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fallingdotseq";
static int* FALLINGDOTSEQ_APPROXIMATELY_EQUAL_TO_OR_THE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erDot html character entity reference model.
 *
 * Name: erDot
 * Character: ≓
 * Unicode code point: U+2253 (8787)
 * Description: image of or approximately equal to
 */
static wchar_t* ERDOT_IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"erDot";
static int* ERDOT_IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The risingdotseq html character entity reference model.
 *
 * Name: risingdotseq
 * Character: ≓
 * Unicode code point: U+2253 (8787)
 * Description: image of or approximately equal to
 */
static wchar_t* RISINGDOTSEQ_IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"risingdotseq";
static int* RISINGDOTSEQ_IMAGE_OF_OR_APPROXIMATELY_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Assign html character entity reference model.
 *
 * Name: Assign
 * Character: ≔
 * Unicode code point: U+2254 (8788)
 * Description: colon equals
 */
static wchar_t* ASSIGN_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Assign";
static int* ASSIGN_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colone html character entity reference model.
 *
 * Name: colone
 * Character: ≔
 * Unicode code point: U+2254 (8788)
 * Description: colon equals
 */
static wchar_t* COLONE_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"colone";
static int* COLONE_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The coloneq html character entity reference model.
 *
 * Name: coloneq
 * Character: ≔
 * Unicode code point: U+2254 (8788)
 * Description: colon equals
 */
static wchar_t* COLONEQ_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"coloneq";
static int* COLONEQ_COLON_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ecolon html character entity reference model.
 *
 * Name: ecolon
 * Character: ≕
 * Unicode code point: U+2255 (8789)
 * Description: equals colon
 */
static wchar_t* ECOLON_EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecolon";
static int* ECOLON_EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqcolon html character entity reference model.
 *
 * Name: eqcolon
 * Character: ≕
 * Unicode code point: U+2255 (8789)
 * Description: equals colon
 */
static wchar_t* EQCOLON_EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqcolon";
static int* EQCOLON_EQUALS_COLON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ecir html character entity reference model.
 *
 * Name: ecir
 * Character: ≖
 * Unicode code point: U+2256 (8790)
 * Description: ring in equal to
 */
static wchar_t* ECIR_RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ecir";
static int* ECIR_RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqcirc html character entity reference model.
 *
 * Name: eqcirc
 * Character: ≖
 * Unicode code point: U+2256 (8790)
 * Description: ring in equal to
 */
static wchar_t* EQCIRC_RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqcirc";
static int* EQCIRC_RING_IN_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circeq html character entity reference model.
 *
 * Name: circeq
 * Character: ≗
 * Unicode code point: U+2257 (8791)
 * Description: ring equal to
 */
static wchar_t* CIRCEQ_RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circeq";
static int* CIRCEQ_RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cire html character entity reference model.
 *
 * Name: cire
 * Character: ≗
 * Unicode code point: U+2257 (8791)
 * Description: ring equal to
 */
static wchar_t* CIRE_RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cire";
static int* CIRE_RING_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wedgeq html character entity reference model.
 *
 * Name: wedgeq
 * Character: ≙
 * Unicode code point: U+2259 (8793)
 * Description: estimates
 */
static wchar_t* WEDGEQ_ESTIMATES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wedgeq";
static int* WEDGEQ_ESTIMATES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The veeeq html character entity reference model.
 *
 * Name: veeeq
 * Character: ≚
 * Unicode code point: U+225a (8794)
 * Description: equiangular to
 */
static wchar_t* VEEEQ_EQUIANGULAR_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"veeeq";
static int* VEEEQ_EQUIANGULAR_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangleq html character entity reference model.
 *
 * Name: triangleq
 * Character: ≜
 * Unicode code point: U+225c (8796)
 * Description: delta equal to
 */
static wchar_t* TRIANGLEQ_DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangleq";
static int* TRIANGLEQ_DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trie html character entity reference model.
 *
 * Name: trie
 * Character: ≜
 * Unicode code point: U+225c (8796)
 * Description: delta equal to
 */
static wchar_t* TRIE_DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trie";
static int* TRIE_DELTA_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equest html character entity reference model.
 *
 * Name: equest
 * Character: ≟
 * Unicode code point: U+225f (8799)
 * Description: questioned equal to
 */
static wchar_t* EQUEST_QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equest";
static int* EQUEST_QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The questeq html character entity reference model.
 *
 * Name: questeq
 * Character: ≟
 * Unicode code point: U+225f (8799)
 * Description: questioned equal to
 */
static wchar_t* QUESTEQ_QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"questeq";
static int* QUESTEQ_QUESTIONED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotEqual html character entity reference model.
 *
 * Name: NotEqual
 * Character: ≠
 * Unicode code point: U+2260 (8800)
 * Description: not equal to
 */
static wchar_t* NOTEQUAL_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotEqual";
static int* NOTEQUAL_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ne html character entity reference model.
 *
 * Name: ne
 * Character: ≠
 * Unicode code point: U+2260 (8800)
 * Description: not equal to
 */
static wchar_t* NE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ne";
static int* NE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Congruent html character entity reference model.
 *
 * Name: Congruent
 * Character: ≡
 * Unicode code point: U+2261 (8801)
 * Description: identical to
 */
static wchar_t* CONGRUENT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Congruent";
static int* CONGRUENT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equiv html character entity reference model.
 *
 * Name: equiv
 * Character: ≡
 * Unicode code point: U+2261 (8801)
 * Description: identical to
 */
static wchar_t* EQUIV_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equiv";
static int* EQUIV_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bnequiv html character entity reference model.
 *
 * Name: bnequiv
 * Character: ≡⃥
 * Unicode code point: U+2261;U+20e5 (8801;8421)
 * Description: identical to with reverse slash
 */
static wchar_t* BNEQUIV_IDENTICAL_TO_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bnequiv";
static int* BNEQUIV_IDENTICAL_TO_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotCongruent html character entity reference model.
 *
 * Name: NotCongruent
 * Character: ≢
 * Unicode code point: U+2262 (8802)
 * Description: not identical to
 */
static wchar_t* NOTCONGRUENT_NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotCongruent";
static int* NOTCONGRUENT_NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nequiv html character entity reference model.
 *
 * Name: nequiv
 * Character: ≢
 * Unicode code point: U+2262 (8802)
 * Description: not identical to
 */
static wchar_t* NEQUIV_NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nequiv";
static int* NEQUIV_NOT_IDENTICAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The le html character entity reference model.
 *
 * Name: le
 * Character: ≤
 * Unicode code point: U+2264 (8804)
 * Description: less-than or equal to
 */
static wchar_t* LE_LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"le";
static int* LE_LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leq html character entity reference model.
 *
 * Name: leq
 * Character: ≤
 * Unicode code point: U+2264 (8804)
 * Description: less-than or equal to
 */
static wchar_t* LEQ_LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leq";
static int* LEQ_LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvle html character entity reference model.
 *
 * Name: nvle
 * Character: ≤⃒
 * Unicode code point: U+2264;U+20d2 (8804;8402)
 * Description: less-than or equal to with vertical line
 */
static wchar_t* NVLE_LESS_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvle";
static int* NVLE_LESS_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterEqual html character entity reference model.
 *
 * Name: GreaterEqual
 * Character: ≥
 * Unicode code point: U+2265 (8805)
 * Description: greater-than or equal to
 */
static wchar_t* GREATEREQUAL_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterEqual";
static int* GREATEREQUAL_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ge html character entity reference model.
 *
 * Name: ge
 * Character: ≥
 * Unicode code point: U+2265 (8805)
 * Description: greater-than or equal to
 */
static wchar_t* GE_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ge";
static int* GE_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geq html character entity reference model.
 *
 * Name: geq
 * Character: ≥
 * Unicode code point: U+2265 (8805)
 * Description: greater-than or equal to
 */
static wchar_t* GEQ_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"geq";
static int* GEQ_GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvge html character entity reference model.
 *
 * Name: nvge
 * Character: ≥⃒
 * Unicode code point: U+2265;U+20d2 (8805;8402)
 * Description: greater-than or equal to with vertical line
 */
static wchar_t* NVGE_GREATER_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvge";
static int* NVGE_GREATER_THAN_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessFullEqual html character entity reference model.
 *
 * Name: LessFullEqual
 * Character: ≦
 * Unicode code point: U+2266 (8806)
 * Description: less-than over equal to
 */
static wchar_t* LESSFULLEQUAL_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessFullEqual";
static int* LESSFULLEQUAL_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lE html character entity reference model.
 *
 * Name: lE
 * Character: ≦
 * Unicode code point: U+2266 (8806)
 * Description: less-than over equal to
 */
static wchar_t* LE_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lE";
static int* LE_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leqq html character entity reference model.
 *
 * Name: leqq
 * Character: ≦
 * Unicode code point: U+2266 (8806)
 * Description: less-than over equal to
 */
static wchar_t* LEQQ_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leqq";
static int* LEQQ_LESS_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nlE html character entity reference model.
 *
 * Name: nlE
 * Character: ≦̸
 * Unicode code point: U+2266;U+0338 (8806;824)
 * Description: less-than over equal to with slash
 */
static wchar_t* NLE_LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlE";
static int* NLE_LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nleqq html character entity reference model.
 *
 * Name: nleqq
 * Character: ≦̸
 * Unicode code point: U+2266;U+0338 (8806;824)
 * Description: less-than over equal to with slash
 */
static wchar_t* NLEQQ_LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nleqq";
static int* NLEQQ_LESS_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterFullEqual html character entity reference model.
 *
 * Name: GreaterFullEqual
 * Character: ≧
 * Unicode code point: U+2267 (8807)
 * Description: greater-than over equal to
 */
static wchar_t* GREATERFULLEQUAL_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterFullEqual";
static int* GREATERFULLEQUAL_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gE html character entity reference model.
 *
 * Name: gE
 * Character: ≧
 * Unicode code point: U+2267 (8807)
 * Description: greater-than over equal to
 */
static wchar_t* GE_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gE";
static int* GE_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geqq html character entity reference model.
 *
 * Name: geqq
 * Character: ≧
 * Unicode code point: U+2267 (8807)
 * Description: greater-than over equal to
 */
static wchar_t* GEQQ_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"geqq";
static int* GEQQ_GREATER_THAN_OVER_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterFullEqual html character entity reference model.
 *
 * Name: NotGreaterFullEqual
 * Character: ≧̸
 * Unicode code point: U+2267;U+0338 (8807;824)
 * Description: greater-than over equal to with slash
 */
static wchar_t* NOTGREATERFULLEQUAL_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterFullEqual";
static int* NOTGREATERFULLEQUAL_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngE html character entity reference model.
 *
 * Name: ngE
 * Character: ≧̸
 * Unicode code point: U+2267;U+0338 (8807;824)
 * Description: greater-than over equal to with slash
 */
static wchar_t* NGE_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngE";
static int* NGE_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngeqq html character entity reference model.
 *
 * Name: ngeqq
 * Character: ≧̸
 * Unicode code point: U+2267;U+0338 (8807;824)
 * Description: greater-than over equal to with slash
 */
static wchar_t* NGEQQ_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngeqq";
static int* NGEQQ_GREATER_THAN_OVER_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lnE html character entity reference model.
 *
 * Name: lnE
 * Character: ≨
 * Unicode code point: U+2268 (8808)
 * Description: less-than but not equal to
 */
static wchar_t* LNE_LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnE";
static int* LNE_LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lneqq html character entity reference model.
 *
 * Name: lneqq
 * Character: ≨
 * Unicode code point: U+2268 (8808)
 * Description: less-than but not equal to
 */
static wchar_t* LNEQQ_LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lneqq";
static int* LNEQQ_LESS_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lvertneqq html character entity reference model.
 *
 * Name: lvertneqq
 * Character: ≨︀
 * Unicode code point: U+2268;U+fe00 (8808;65024)
 * Description: less-than but not equal to - with vertical stroke
 */
static wchar_t* LVERTNEQQ_LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lvertneqq";
static int* LVERTNEQQ_LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lvnE html character entity reference model.
 *
 * Name: lvnE
 * Character: ≨︀
 * Unicode code point: U+2268;U+fe00 (8808;65024)
 * Description: less-than but not equal to - with vertical stroke
 */
static wchar_t* LVNE_LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lvnE";
static int* LVNE_LESS_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gnE html character entity reference model.
 *
 * Name: gnE
 * Character: ≩
 * Unicode code point: U+2269 (8809)
 * Description: greater-than but not equal to
 */
static wchar_t* GNE_GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnE";
static int* GNE_GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gneqq html character entity reference model.
 *
 * Name: gneqq
 * Character: ≩
 * Unicode code point: U+2269 (8809)
 * Description: greater-than but not equal to
 */
static wchar_t* GNEQQ_GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gneqq";
static int* GNEQQ_GREATER_THAN_BUT_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gvertneqq html character entity reference model.
 *
 * Name: gvertneqq
 * Character: ≩︀
 * Unicode code point: U+2269;U+fe00 (8809;65024)
 * Description: greater-than but not equal to - with vertical stroke
 */
static wchar_t* GVERTNEQQ_GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gvertneqq";
static int* GVERTNEQQ_GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gvnE html character entity reference model.
 *
 * Name: gvnE
 * Character: ≩︀
 * Unicode code point: U+2269;U+fe00 (8809;65024)
 * Description: greater-than but not equal to - with vertical stroke
 */
static wchar_t* GVNE_GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gvnE";
static int* GVNE_GREATER_THAN_BUT_NOT_EQUAL_TO___WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lt html character entity reference model.
 *
 * Name: Lt
 * Character: ≪
 * Unicode code point: U+226a (8810)
 * Description: much less-than
 */
static wchar_t* LT_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lt";
static int* LT_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NestedLessLess html character entity reference model.
 *
 * Name: NestedLessLess
 * Character: ≪
 * Unicode code point: U+226a (8810)
 * Description: much less-than
 */
static wchar_t* NESTEDLESSLESS_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NestedLessLess";
static int* NESTEDLESSLESS_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ll html character entity reference model.
 *
 * Name: ll
 * Character: ≪
 * Unicode code point: U+226a (8810)
 * Description: much less-than
 */
static wchar_t* LL_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ll";
static int* LL_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLessLess html character entity reference model.
 *
 * Name: NotLessLess
 * Character: ≪̸
 * Unicode code point: U+226a;U+0338 (8810;824)
 * Description: much less than with slash
 */
static wchar_t* NOTLESSLESS_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessLess";
static int* NOTLESSLESS_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nLtv html character entity reference model.
 *
 * Name: nLtv
 * Character: ≪̸
 * Unicode code point: U+226a;U+0338 (8810;824)
 * Description: much less than with slash
 */
static wchar_t* NLTV_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLtv";
static int* NLTV_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nLt html character entity reference model.
 *
 * Name: nLt
 * Character: ≪⃒
 * Unicode code point: U+226a;U+20d2 (8810;8402)
 * Description: much less than with vertical line
 */
static wchar_t* NLT_MUCH_LESS_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLt";
static int* NLT_MUCH_LESS_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gt html character entity reference model.
 *
 * Name: Gt
 * Character: ≫
 * Unicode code point: U+226b (8811)
 * Description: much greater-than
 */
static wchar_t* GT_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gt";
static int* GT_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NestedGreaterGreater html character entity reference model.
 *
 * Name: NestedGreaterGreater
 * Character: ≫
 * Unicode code point: U+226b (8811)
 * Description: much greater-than
 */
static wchar_t* NESTEDGREATERGREATER_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NestedGreaterGreater";
static int* NESTEDGREATERGREATER_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gg html character entity reference model.
 *
 * Name: gg
 * Character: ≫
 * Unicode code point: U+226b (8811)
 * Description: much greater-than
 */
static wchar_t* GG_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gg";
static int* GG_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterGreater html character entity reference model.
 *
 * Name: NotGreaterGreater
 * Character: ≫̸
 * Unicode code point: U+226b;U+0338 (8811;824)
 * Description: much greater than with slash
 */
static wchar_t* NOTGREATERGREATER_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterGreater";
static int* NOTGREATERGREATER_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nGtv html character entity reference model.
 *
 * Name: nGtv
 * Character: ≫̸
 * Unicode code point: U+226b;U+0338 (8811;824)
 * Description: much greater than with slash
 */
static wchar_t* NGTV_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nGtv";
static int* NGTV_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nGt html character entity reference model.
 *
 * Name: nGt
 * Character: ≫⃒
 * Unicode code point: U+226b;U+20d2 (8811;8402)
 * Description: much greater than with vertical line
 */
static wchar_t* NGT_MUCH_GREATER_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nGt";
static int* NGT_MUCH_GREATER_THAN_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The between html character entity reference model.
 *
 * Name: between
 * Character: ≬
 * Unicode code point: U+226c (8812)
 * Description: between
 */
static wchar_t* BETWEEN_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"between";
static int* BETWEEN_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The twixt html character entity reference model.
 *
 * Name: twixt
 * Character: ≬
 * Unicode code point: U+226c (8812)
 * Description: between
 */
static wchar_t* TWIXT_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"twixt";
static int* TWIXT_BETWEEN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotCupCap html character entity reference model.
 *
 * Name: NotCupCap
 * Character: ≭
 * Unicode code point: U+226d (8813)
 * Description: not equivalent to
 */
static wchar_t* NOTCUPCAP_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotCupCap";
static int* NOTCUPCAP_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLess html character entity reference model.
 *
 * Name: NotLess
 * Character: ≮
 * Unicode code point: U+226e (8814)
 * Description: not less-than
 */
static wchar_t* NOTLESS_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLess";
static int* NOTLESS_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nless html character entity reference model.
 *
 * Name: nless
 * Character: ≮
 * Unicode code point: U+226e (8814)
 * Description: not less-than
 */
static wchar_t* NLESS_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nless";
static int* NLESS_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nlt html character entity reference model.
 *
 * Name: nlt
 * Character: ≮
 * Unicode code point: U+226e (8814)
 * Description: not less-than
 */
static wchar_t* NLT_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlt";
static int* NLT_NOT_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreater html character entity reference model.
 *
 * Name: NotGreater
 * Character: ≯
 * Unicode code point: U+226f (8815)
 * Description: not greater-than
 */
static wchar_t* NOTGREATER_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreater";
static int* NOTGREATER_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngt html character entity reference model.
 *
 * Name: ngt
 * Character: ≯
 * Unicode code point: U+226f (8815)
 * Description: not greater-than
 */
static wchar_t* NGT_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngt";
static int* NGT_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngtr html character entity reference model.
 *
 * Name: ngtr
 * Character: ≯
 * Unicode code point: U+226f (8815)
 * Description: not greater-than
 */
static wchar_t* NGTR_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngtr";
static int* NGTR_NOT_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLessEqual html character entity reference model.
 *
 * Name: NotLessEqual
 * Character: ≰
 * Unicode code point: U+2270 (8816)
 * Description: neither less-than nor equal to
 */
static wchar_t* NOTLESSEQUAL_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessEqual";
static int* NOTLESSEQUAL_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nle html character entity reference model.
 *
 * Name: nle
 * Character: ≰
 * Unicode code point: U+2270 (8816)
 * Description: neither less-than nor equal to
 */
static wchar_t* NLE_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nle";
static int* NLE_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nleq html character entity reference model.
 *
 * Name: nleq
 * Character: ≰
 * Unicode code point: U+2270 (8816)
 * Description: neither less-than nor equal to
 */
static wchar_t* NLEQ_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nleq";
static int* NLEQ_NEITHER_LESS_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterEqual html character entity reference model.
 *
 * Name: NotGreaterEqual
 * Character: ≱
 * Unicode code point: U+2271 (8817)
 * Description: neither greater-than nor equal to
 */
static wchar_t* NOTGREATEREQUAL_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterEqual";
static int* NOTGREATEREQUAL_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nge html character entity reference model.
 *
 * Name: nge
 * Character: ≱
 * Unicode code point: U+2271 (8817)
 * Description: neither greater-than nor equal to
 */
static wchar_t* NGE_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nge";
static int* NGE_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngeq html character entity reference model.
 *
 * Name: ngeq
 * Character: ≱
 * Unicode code point: U+2271 (8817)
 * Description: neither greater-than nor equal to
 */
static wchar_t* NGEQ_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngeq";
static int* NGEQ_NEITHER_GREATER_THAN_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessTilde html character entity reference model.
 *
 * Name: LessTilde
 * Character: ≲
 * Unicode code point: U+2272 (8818)
 * Description: less-than or equivalent to
 */
static wchar_t* LESSTILDE_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessTilde";
static int* LESSTILDE_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesssim html character entity reference model.
 *
 * Name: lesssim
 * Character: ≲
 * Unicode code point: U+2272 (8818)
 * Description: less-than or equivalent to
 */
static wchar_t* LESSSIM_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesssim";
static int* LESSSIM_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsim html character entity reference model.
 *
 * Name: lsim
 * Character: ≲
 * Unicode code point: U+2272 (8818)
 * Description: less-than or equivalent to
 */
static wchar_t* LSIM_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsim";
static int* LSIM_LESS_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterTilde html character entity reference model.
 *
 * Name: GreaterTilde
 * Character: ≳
 * Unicode code point: U+2273 (8819)
 * Description: greater-than or equivalent to
 */
static wchar_t* GREATERTILDE_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterTilde";
static int* GREATERTILDE_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gsim html character entity reference model.
 *
 * Name: gsim
 * Character: ≳
 * Unicode code point: U+2273 (8819)
 * Description: greater-than or equivalent to
 */
static wchar_t* GSIM_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gsim";
static int* GSIM_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtrsim html character entity reference model.
 *
 * Name: gtrsim
 * Character: ≳
 * Unicode code point: U+2273 (8819)
 * Description: greater-than or equivalent to
 */
static wchar_t* GTRSIM_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrsim";
static int* GTRSIM_GREATER_THAN_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLessTilde html character entity reference model.
 *
 * Name: NotLessTilde
 * Character: ≴
 * Unicode code point: U+2274 (8820)
 * Description: neither less-than nor equivalent to
 */
static wchar_t* NOTLESSTILDE_NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessTilde";
static int* NOTLESSTILDE_NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nlsim html character entity reference model.
 *
 * Name: nlsim
 * Character: ≴
 * Unicode code point: U+2274 (8820)
 * Description: neither less-than nor equivalent to
 */
static wchar_t* NLSIM_NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nlsim";
static int* NLSIM_NEITHER_LESS_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterTilde html character entity reference model.
 *
 * Name: NotGreaterTilde
 * Character: ≵
 * Unicode code point: U+2275 (8821)
 * Description: neither greater-than nor equivalent to
 */
static wchar_t* NOTGREATERTILDE_NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterTilde";
static int* NOTGREATERTILDE_NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngsim html character entity reference model.
 *
 * Name: ngsim
 * Character: ≵
 * Unicode code point: U+2275 (8821)
 * Description: neither greater-than nor equivalent to
 */
static wchar_t* NGSIM_NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngsim";
static int* NGSIM_NEITHER_GREATER_THAN_NOR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessGreater html character entity reference model.
 *
 * Name: LessGreater
 * Character: ≶
 * Unicode code point: U+2276 (8822)
 * Description: less-than or greater-than
 */
static wchar_t* LESSGREATER_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessGreater";
static int* LESSGREATER_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lessgtr html character entity reference model.
 *
 * Name: lessgtr
 * Character: ≶
 * Unicode code point: U+2276 (8822)
 * Description: less-than or greater-than
 */
static wchar_t* LESSGTR_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lessgtr";
static int* LESSGTR_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lg html character entity reference model.
 *
 * Name: lg
 * Character: ≶
 * Unicode code point: U+2276 (8822)
 * Description: less-than or greater-than
 */
static wchar_t* LG_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lg";
static int* LG_LESS_THAN_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterLess html character entity reference model.
 *
 * Name: GreaterLess
 * Character: ≷
 * Unicode code point: U+2277 (8823)
 * Description: greater-than or less-than
 */
static wchar_t* GREATERLESS_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterLess";
static int* GREATERLESS_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gl html character entity reference model.
 *
 * Name: gl
 * Character: ≷
 * Unicode code point: U+2277 (8823)
 * Description: greater-than or less-than
 */
static wchar_t* GL_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gl";
static int* GL_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtrless html character entity reference model.
 *
 * Name: gtrless
 * Character: ≷
 * Unicode code point: U+2277 (8823)
 * Description: greater-than or less-than
 */
static wchar_t* GTRLESS_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrless";
static int* GTRLESS_GREATER_THAN_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLessGreater html character entity reference model.
 *
 * Name: NotLessGreater
 * Character: ≸
 * Unicode code point: U+2278 (8824)
 * Description: neither less-than nor greater-than
 */
static wchar_t* NOTLESSGREATER_NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessGreater";
static int* NOTLESSGREATER_NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntlg html character entity reference model.
 *
 * Name: ntlg
 * Character: ≸
 * Unicode code point: U+2278 (8824)
 * Description: neither less-than nor greater-than
 */
static wchar_t* NTLG_NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntlg";
static int* NTLG_NEITHER_LESS_THAN_NOR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterLess html character entity reference model.
 *
 * Name: NotGreaterLess
 * Character: ≹
 * Unicode code point: U+2279 (8825)
 * Description: neither greater-than nor less-than
 */
static wchar_t* NOTGREATERLESS_NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterLess";
static int* NOTGREATERLESS_NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntgl html character entity reference model.
 *
 * Name: ntgl
 * Character: ≹
 * Unicode code point: U+2279 (8825)
 * Description: neither greater-than nor less-than
 */
static wchar_t* NTGL_NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntgl";
static int* NTGL_NEITHER_GREATER_THAN_NOR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Precedes html character entity reference model.
 *
 * Name: Precedes
 * Character: ≺
 * Unicode code point: U+227a (8826)
 * Description: precedes
 */
static wchar_t* PRECEDES_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Precedes";
static int* PRECEDES_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pr html character entity reference model.
 *
 * Name: pr
 * Character: ≺
 * Unicode code point: U+227a (8826)
 * Description: precedes
 */
static wchar_t* PR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pr";
static int* PR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prec html character entity reference model.
 *
 * Name: prec
 * Character: ≺
 * Unicode code point: U+227a (8826)
 * Description: precedes
 */
static wchar_t* PREC_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prec";
static int* PREC_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Succeeds html character entity reference model.
 *
 * Name: Succeeds
 * Character: ≻
 * Unicode code point: U+227b (8827)
 * Description: succeeds
 */
static wchar_t* SUCCEEDS_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Succeeds";
static int* SUCCEEDS_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sc html character entity reference model.
 *
 * Name: sc
 * Character: ≻
 * Unicode code point: U+227b (8827)
 * Description: succeeds
 */
static wchar_t* SC_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sc";
static int* SC_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succ html character entity reference model.
 *
 * Name: succ
 * Character: ≻
 * Unicode code point: U+227b (8827)
 * Description: succeeds
 */
static wchar_t* SUCC_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succ";
static int* SUCC_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PrecedesSlantEqual html character entity reference model.
 *
 * Name: PrecedesSlantEqual
 * Character: ≼
 * Unicode code point: U+227c (8828)
 * Description: precedes or equal to
 */
static wchar_t* PRECEDESSLANTEQUAL_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesSlantEqual";
static int* PRECEDESSLANTEQUAL_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prcue html character entity reference model.
 *
 * Name: prcue
 * Character: ≼
 * Unicode code point: U+227c (8828)
 * Description: precedes or equal to
 */
static wchar_t* PRCUE_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prcue";
static int* PRCUE_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The preccurlyeq html character entity reference model.
 *
 * Name: preccurlyeq
 * Character: ≼
 * Unicode code point: U+227c (8828)
 * Description: precedes or equal to
 */
static wchar_t* PRECCURLYEQ_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"preccurlyeq";
static int* PRECCURLYEQ_PRECEDES_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SucceedsSlantEqual html character entity reference model.
 *
 * Name: SucceedsSlantEqual
 * Character: ≽
 * Unicode code point: U+227d (8829)
 * Description: succeeds or equal to
 */
static wchar_t* SUCCEEDSSLANTEQUAL_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsSlantEqual";
static int* SUCCEEDSSLANTEQUAL_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sccue html character entity reference model.
 *
 * Name: sccue
 * Character: ≽
 * Unicode code point: U+227d (8829)
 * Description: succeeds or equal to
 */
static wchar_t* SCCUE_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sccue";
static int* SCCUE_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succcurlyeq html character entity reference model.
 *
 * Name: succcurlyeq
 * Character: ≽
 * Unicode code point: U+227d (8829)
 * Description: succeeds or equal to
 */
static wchar_t* SUCCCURLYEQ_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succcurlyeq";
static int* SUCCCURLYEQ_SUCCEEDS_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PrecedesTilde html character entity reference model.
 *
 * Name: PrecedesTilde
 * Character: ≾
 * Unicode code point: U+227e (8830)
 * Description: precedes or equivalent to
 */
static wchar_t* PRECEDESTILDE_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesTilde";
static int* PRECEDESTILDE_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precsim html character entity reference model.
 *
 * Name: precsim
 * Character: ≾
 * Unicode code point: U+227e (8830)
 * Description: precedes or equivalent to
 */
static wchar_t* PRECSIM_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precsim";
static int* PRECSIM_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prsim html character entity reference model.
 *
 * Name: prsim
 * Character: ≾
 * Unicode code point: U+227e (8830)
 * Description: precedes or equivalent to
 */
static wchar_t* PRSIM_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prsim";
static int* PRSIM_PRECEDES_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSucceedsTilde html character entity reference model.
 *
 * Name: NotSucceedsTilde
 * Character: ≿̸
 * Unicode code point: U+227f;U+0338 (8831;824)
 * Description: succeeds or equivalent to with slash
 */
static wchar_t* NOTSUCCEEDSTILDE_SUCCEEDS_OR_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsTilde";
static int* NOTSUCCEEDSTILDE_SUCCEEDS_OR_EQUIVALENT_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SucceedsTilde html character entity reference model.
 *
 * Name: SucceedsTilde
 * Character: ≿
 * Unicode code point: U+227f (8831)
 * Description: succeeds or equivalent to
 */
static wchar_t* SUCCEEDSTILDE_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsTilde";
static int* SUCCEEDSTILDE_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scsim html character entity reference model.
 *
 * Name: scsim
 * Character: ≿
 * Unicode code point: U+227f (8831)
 * Description: succeeds or equivalent to
 */
static wchar_t* SCSIM_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scsim";
static int* SCSIM_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succsim html character entity reference model.
 *
 * Name: succsim
 * Character: ≿
 * Unicode code point: U+227f (8831)
 * Description: succeeds or equivalent to
 */
static wchar_t* SUCCSIM_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succsim";
static int* SUCCSIM_SUCCEEDS_OR_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotPrecedes html character entity reference model.
 *
 * Name: NotPrecedes
 * Character: ⊀
 * Unicode code point: U+2280 (8832)
 * Description: does not precede
 */
static wchar_t* NOTPRECEDES_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedes";
static int* NOTPRECEDES_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npr html character entity reference model.
 *
 * Name: npr
 * Character: ⊀
 * Unicode code point: U+2280 (8832)
 * Description: does not precede
 */
static wchar_t* NPR_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npr";
static int* NPR_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nprec html character entity reference model.
 *
 * Name: nprec
 * Character: ⊀
 * Unicode code point: U+2280 (8832)
 * Description: does not precede
 */
static wchar_t* NPREC_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nprec";
static int* NPREC_DOES_NOT_PRECEDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSucceeds html character entity reference model.
 *
 * Name: NotSucceeds
 * Character: ⊁
 * Unicode code point: U+2281 (8833)
 * Description: does not succeed
 */
static wchar_t* NOTSUCCEEDS_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceeds";
static int* NOTSUCCEEDS_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsc html character entity reference model.
 *
 * Name: nsc
 * Character: ⊁
 * Unicode code point: U+2281 (8833)
 * Description: does not succeed
 */
static wchar_t* NSC_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsc";
static int* NSC_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsucc html character entity reference model.
 *
 * Name: nsucc
 * Character: ⊁
 * Unicode code point: U+2281 (8833)
 * Description: does not succeed
 */
static wchar_t* NSUCC_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsucc";
static int* NSUCC_DOES_NOT_SUCCEED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSubset html character entity reference model.
 *
 * Name: NotSubset
 * Character: ⊂⃒
 * Unicode code point: U+2282;U+20d2 (8834;8402)
 * Description: subset of with vertical line
 */
static wchar_t* NOTSUBSET_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSubset";
static int* NOTSUBSET_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsubset html character entity reference model.
 *
 * Name: nsubset
 * Character: ⊂⃒
 * Unicode code point: U+2282;U+20d2 (8834;8402)
 * Description: subset of with vertical line
 */
static wchar_t* NSUBSET_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsubset";
static int* NSUBSET_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vnsub html character entity reference model.
 *
 * Name: vnsub
 * Character: ⊂⃒
 * Unicode code point: U+2282;U+20d2 (8834;8402)
 * Description: subset of with vertical line
 */
static wchar_t* VNSUB_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vnsub";
static int* VNSUB_SUBSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sub html character entity reference model.
 *
 * Name: sub
 * Character: ⊂
 * Unicode code point: U+2282 (8834)
 * Description: subset of
 */
static wchar_t* SUB_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sub";
static int* SUB_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subset html character entity reference model.
 *
 * Name: subset
 * Character: ⊂
 * Unicode code point: U+2282 (8834)
 * Description: subset of
 */
static wchar_t* SUBSET_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subset";
static int* SUBSET_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSuperset html character entity reference model.
 *
 * Name: NotSuperset
 * Character: ⊃⃒
 * Unicode code point: U+2283;U+20d2 (8835;8402)
 * Description: superset of with vertical line
 */
static wchar_t* NOTSUPERSET_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSuperset";
static int* NOTSUPERSET_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsupset html character entity reference model.
 *
 * Name: nsupset
 * Character: ⊃⃒
 * Unicode code point: U+2283;U+20d2 (8835;8402)
 * Description: superset of with vertical line
 */
static wchar_t* NSUPSET_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupset";
static int* NSUPSET_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vnsup html character entity reference model.
 *
 * Name: vnsup
 * Character: ⊃⃒
 * Unicode code point: U+2283;U+20d2 (8835;8402)
 * Description: superset of with vertical line
 */
static wchar_t* VNSUP_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vnsup";
static int* VNSUP_SUPERSET_OF_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Superset html character entity reference model.
 *
 * Name: Superset
 * Character: ⊃
 * Unicode code point: U+2283 (8835)
 * Description: superset of
 */
static wchar_t* SUPERSET_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Superset";
static int* SUPERSET_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sup html character entity reference model.
 *
 * Name: sup
 * Character: ⊃
 * Unicode code point: U+2283 (8835)
 * Description: superset of
 */
static wchar_t* SUP_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sup";
static int* SUP_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supset html character entity reference model.
 *
 * Name: supset
 * Character: ⊃
 * Unicode code point: U+2283 (8835)
 * Description: superset of
 */
static wchar_t* SUPSET_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supset";
static int* SUPSET_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsub html character entity reference model.
 *
 * Name: nsub
 * Character: ⊄
 * Unicode code point: U+2284 (8836)
 * Description: not a subset of
 */
static wchar_t* NSUB_NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsub";
static int* NSUB_NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsup html character entity reference model.
 *
 * Name: nsup
 * Character: ⊅
 * Unicode code point: U+2285 (8837)
 * Description: not a superset of
 */
static wchar_t* NSUP_NOT_A_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsup";
static int* NSUP_NOT_A_SUPERSET_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SubsetEqual html character entity reference model.
 *
 * Name: SubsetEqual
 * Character: ⊆
 * Unicode code point: U+2286 (8838)
 * Description: subset of or equal to
 */
static wchar_t* SUBSETEQUAL_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SubsetEqual";
static int* SUBSETEQUAL_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sube html character entity reference model.
 *
 * Name: sube
 * Character: ⊆
 * Unicode code point: U+2286 (8838)
 * Description: subset of or equal to
 */
static wchar_t* SUBE_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sube";
static int* SUBE_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subseteq html character entity reference model.
 *
 * Name: subseteq
 * Character: ⊆
 * Unicode code point: U+2286 (8838)
 * Description: subset of or equal to
 */
static wchar_t* SUBSETEQ_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subseteq";
static int* SUBSETEQ_SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SupersetEqual html character entity reference model.
 *
 * Name: SupersetEqual
 * Character: ⊇
 * Unicode code point: U+2287 (8839)
 * Description: superset of or equal to
 */
static wchar_t* SUPERSETEQUAL_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SupersetEqual";
static int* SUPERSETEQUAL_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supe html character entity reference model.
 *
 * Name: supe
 * Character: ⊇
 * Unicode code point: U+2287 (8839)
 * Description: superset of or equal to
 */
static wchar_t* SUPE_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supe";
static int* SUPE_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supseteq html character entity reference model.
 *
 * Name: supseteq
 * Character: ⊇
 * Unicode code point: U+2287 (8839)
 * Description: superset of or equal to
 */
static wchar_t* SUPSETEQ_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supseteq";
static int* SUPSETEQ_SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSubsetEqual html character entity reference model.
 *
 * Name: NotSubsetEqual
 * Character: ⊈
 * Unicode code point: U+2288 (8840)
 * Description: neither a subset of nor equal to
 */
static wchar_t* NOTSUBSETEQUAL_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSubsetEqual";
static int* NOTSUBSETEQUAL_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsube html character entity reference model.
 *
 * Name: nsube
 * Character: ⊈
 * Unicode code point: U+2288 (8840)
 * Description: neither a subset of nor equal to
 */
static wchar_t* NSUBE_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsube";
static int* NSUBE_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsubseteq html character entity reference model.
 *
 * Name: nsubseteq
 * Character: ⊈
 * Unicode code point: U+2288 (8840)
 * Description: neither a subset of nor equal to
 */
static wchar_t* NSUBSETEQ_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsubseteq";
static int* NSUBSETEQ_NEITHER_A_SUBSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSupersetEqual html character entity reference model.
 *
 * Name: NotSupersetEqual
 * Character: ⊉
 * Unicode code point: U+2289 (8841)
 * Description: neither a superset of nor equal to
 */
static wchar_t* NOTSUPERSETEQUAL_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSupersetEqual";
static int* NOTSUPERSETEQUAL_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsupe html character entity reference model.
 *
 * Name: nsupe
 * Character: ⊉
 * Unicode code point: U+2289 (8841)
 * Description: neither a superset of nor equal to
 */
static wchar_t* NSUPE_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupe";
static int* NSUPE_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsupseteq html character entity reference model.
 *
 * Name: nsupseteq
 * Character: ⊉
 * Unicode code point: U+2289 (8841)
 * Description: neither a superset of nor equal to
 */
static wchar_t* NSUPSETEQ_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupseteq";
static int* NSUPSETEQ_NEITHER_A_SUPERSET_OF_NOR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subne html character entity reference model.
 *
 * Name: subne
 * Character: ⊊
 * Unicode code point: U+228a (8842)
 * Description: subset of with not equal to
 */
static wchar_t* SUBNE_SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subne";
static int* SUBNE_SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subsetneq html character entity reference model.
 *
 * Name: subsetneq
 * Character: ⊊
 * Unicode code point: U+228a (8842)
 * Description: subset of with not equal to
 */
static wchar_t* SUBSETNEQ_SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsetneq";
static int* SUBSETNEQ_SUBSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varsubsetneq html character entity reference model.
 *
 * Name: varsubsetneq
 * Character: ⊊︀
 * Unicode code point: U+228a;U+fe00 (8842;65024)
 * Description: subset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* VARSUBSETNEQ_SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsubsetneq";
static int* VARSUBSETNEQ_SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vsubne html character entity reference model.
 *
 * Name: vsubne
 * Character: ⊊︀
 * Unicode code point: U+228a;U+fe00 (8842;65024)
 * Description: subset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* VSUBNE_SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vsubne";
static int* VSUBNE_SUBSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supne html character entity reference model.
 *
 * Name: supne
 * Character: ⊋
 * Unicode code point: U+228b (8843)
 * Description: superset of with not equal to
 */
static wchar_t* SUPNE_SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supne";
static int* SUPNE_SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supsetneq html character entity reference model.
 *
 * Name: supsetneq
 * Character: ⊋
 * Unicode code point: U+228b (8843)
 * Description: superset of with not equal to
 */
static wchar_t* SUPSETNEQ_SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsetneq";
static int* SUPSETNEQ_SUPERSET_OF_WITH_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varsupsetneq html character entity reference model.
 *
 * Name: varsupsetneq
 * Character: ⊋︀
 * Unicode code point: U+228b;U+fe00 (8843;65024)
 * Description: superset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* VARSUPSETNEQ_SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsupsetneq";
static int* VARSUPSETNEQ_SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vsupne html character entity reference model.
 *
 * Name: vsupne
 * Character: ⊋︀
 * Unicode code point: U+228b;U+fe00 (8843;65024)
 * Description: superset of with not equal to - variant with stroke through bottom members
 */
static wchar_t* VSUPNE_SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vsupne";
static int* VSUPNE_SUPERSET_OF_WITH_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cupdot html character entity reference model.
 *
 * Name: cupdot
 * Character: ⊍
 * Unicode code point: U+228d (8845)
 * Description: multiset multiplication
 */
static wchar_t* CUPDOT_MULTISET_MULTIPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupdot";
static int* CUPDOT_MULTISET_MULTIPLICATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UnionPlus html character entity reference model.
 *
 * Name: UnionPlus
 * Character: ⊎
 * Unicode code point: U+228e (8846)
 * Description: multiset union
 */
static wchar_t* UNIONPLUS_MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnionPlus";
static int* UNIONPLUS_MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uplus html character entity reference model.
 *
 * Name: uplus
 * Character: ⊎
 * Unicode code point: U+228e (8846)
 * Description: multiset union
 */
static wchar_t* UPLUS_MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uplus";
static int* UPLUS_MULTISET_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSquareSubset html character entity reference model.
 *
 * Name: NotSquareSubset
 * Character: ⊏̸
 * Unicode code point: U+228f;U+0338 (8847;824)
 * Description: square image of with slash
 */
static wchar_t* NOTSQUARESUBSET_SQUARE_IMAGE_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSubset";
static int* NOTSQUARESUBSET_SQUARE_IMAGE_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareSubset html character entity reference model.
 *
 * Name: SquareSubset
 * Character: ⊏
 * Unicode code point: U+228f (8847)
 * Description: square image of
 */
static wchar_t* SQUARESUBSET_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSubset";
static int* SQUARESUBSET_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsub html character entity reference model.
 *
 * Name: sqsub
 * Character: ⊏
 * Unicode code point: U+228f (8847)
 * Description: square image of
 */
static wchar_t* SQSUB_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsub";
static int* SQSUB_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsubset html character entity reference model.
 *
 * Name: sqsubset
 * Character: ⊏
 * Unicode code point: U+228f (8847)
 * Description: square image of
 */
static wchar_t* SQSUBSET_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsubset";
static int* SQSUBSET_SQUARE_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSquareSuperset html character entity reference model.
 *
 * Name: NotSquareSuperset
 * Character: ⊐̸
 * Unicode code point: U+2290;U+0338 (8848;824)
 * Description: square original of with slash
 */
static wchar_t* NOTSQUARESUPERSET_SQUARE_ORIGINAL_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSuperset";
static int* NOTSQUARESUPERSET_SQUARE_ORIGINAL_OF_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareSuperset html character entity reference model.
 *
 * Name: SquareSuperset
 * Character: ⊐
 * Unicode code point: U+2290 (8848)
 * Description: square original of
 */
static wchar_t* SQUARESUPERSET_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSuperset";
static int* SQUARESUPERSET_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsup html character entity reference model.
 *
 * Name: sqsup
 * Character: ⊐
 * Unicode code point: U+2290 (8848)
 * Description: square original of
 */
static wchar_t* SQSUP_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsup";
static int* SQSUP_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsupset html character entity reference model.
 *
 * Name: sqsupset
 * Character: ⊐
 * Unicode code point: U+2290 (8848)
 * Description: square original of
 */
static wchar_t* SQSUPSET_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsupset";
static int* SQSUPSET_SQUARE_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareSubsetEqual html character entity reference model.
 *
 * Name: SquareSubsetEqual
 * Character: ⊑
 * Unicode code point: U+2291 (8849)
 * Description: square image of or equal to
 */
static wchar_t* SQUARESUBSETEQUAL_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSubsetEqual";
static int* SQUARESUBSETEQUAL_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsube html character entity reference model.
 *
 * Name: sqsube
 * Character: ⊑
 * Unicode code point: U+2291 (8849)
 * Description: square image of or equal to
 */
static wchar_t* SQSUBE_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsube";
static int* SQSUBE_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsubseteq html character entity reference model.
 *
 * Name: sqsubseteq
 * Character: ⊑
 * Unicode code point: U+2291 (8849)
 * Description: square image of or equal to
 */
static wchar_t* SQSUBSETEQ_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsubseteq";
static int* SQSUBSETEQ_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareSupersetEqual html character entity reference model.
 *
 * Name: SquareSupersetEqual
 * Character: ⊒
 * Unicode code point: U+2292 (8850)
 * Description: square original of or equal to
 */
static wchar_t* SQUARESUPERSETEQUAL_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareSupersetEqual";
static int* SQUARESUPERSETEQUAL_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsupe html character entity reference model.
 *
 * Name: sqsupe
 * Character: ⊒
 * Unicode code point: U+2292 (8850)
 * Description: square original of or equal to
 */
static wchar_t* SQSUPE_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsupe";
static int* SQSUPE_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqsupseteq html character entity reference model.
 *
 * Name: sqsupseteq
 * Character: ⊒
 * Unicode code point: U+2292 (8850)
 * Description: square original of or equal to
 */
static wchar_t* SQSUPSETEQ_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqsupseteq";
static int* SQSUPSETEQ_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareIntersection html character entity reference model.
 *
 * Name: SquareIntersection
 * Character: ⊓
 * Unicode code point: U+2293 (8851)
 * Description: square cap
 */
static wchar_t* SQUAREINTERSECTION_SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareIntersection";
static int* SQUAREINTERSECTION_SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqcap html character entity reference model.
 *
 * Name: sqcap
 * Character: ⊓
 * Unicode code point: U+2293 (8851)
 * Description: square cap
 */
static wchar_t* SQCAP_SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcap";
static int* SQCAP_SQUARE_CAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqcaps html character entity reference model.
 *
 * Name: sqcaps
 * Character: ⊓︀
 * Unicode code point: U+2293;U+fe00 (8851;65024)
 * Description: square cap with serifs
 */
static wchar_t* SQCAPS_SQUARE_CAP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcaps";
static int* SQCAPS_SQUARE_CAP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SquareUnion html character entity reference model.
 *
 * Name: SquareUnion
 * Character: ⊔
 * Unicode code point: U+2294 (8852)
 * Description: square cup
 */
static wchar_t* SQUAREUNION_SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SquareUnion";
static int* SQUAREUNION_SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqcup html character entity reference model.
 *
 * Name: sqcup
 * Character: ⊔
 * Unicode code point: U+2294 (8852)
 * Description: square cup
 */
static wchar_t* SQCUP_SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcup";
static int* SQCUP_SQUARE_CUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sqcups html character entity reference model.
 *
 * Name: sqcups
 * Character: ⊔︀
 * Unicode code point: U+2294;U+fe00 (8852;65024)
 * Description: square cup with serifs
 */
static wchar_t* SQCUPS_SQUARE_CUP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sqcups";
static int* SQCUPS_SQUARE_CUP_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CirclePlus html character entity reference model.
 *
 * Name: CirclePlus
 * Character: ⊕
 * Unicode code point: U+2295 (8853)
 * Description: circled plus
 */
static wchar_t* CIRCLEPLUS_CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CirclePlus";
static int* CIRCLEPLUS_CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oplus html character entity reference model.
 *
 * Name: oplus
 * Character: ⊕
 * Unicode code point: U+2295 (8853)
 * Description: circled plus
 */
static wchar_t* OPLUS_CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oplus";
static int* OPLUS_CIRCLED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CircleMinus html character entity reference model.
 *
 * Name: CircleMinus
 * Character: ⊖
 * Unicode code point: U+2296 (8854)
 * Description: circled minus
 */
static wchar_t* CIRCLEMINUS_CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleMinus";
static int* CIRCLEMINUS_CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ominus html character entity reference model.
 *
 * Name: ominus
 * Character: ⊖
 * Unicode code point: U+2296 (8854)
 * Description: circled minus
 */
static wchar_t* OMINUS_CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ominus";
static int* OMINUS_CIRCLED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CircleTimes html character entity reference model.
 *
 * Name: CircleTimes
 * Character: ⊗
 * Unicode code point: U+2297 (8855)
 * Description: circled times
 */
static wchar_t* CIRCLETIMES_CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleTimes";
static int* CIRCLETIMES_CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The otimes html character entity reference model.
 *
 * Name: otimes
 * Character: ⊗
 * Unicode code point: U+2297 (8855)
 * Description: circled times
 */
static wchar_t* OTIMES_CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otimes";
static int* OTIMES_CIRCLED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The osol html character entity reference model.
 *
 * Name: osol
 * Character: ⊘
 * Unicode code point: U+2298 (8856)
 * Description: circled division slash
 */
static wchar_t* OSOL_CIRCLED_DIVISION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"osol";
static int* OSOL_CIRCLED_DIVISION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The CircleDot html character entity reference model.
 *
 * Name: CircleDot
 * Character: ⊙
 * Unicode code point: U+2299 (8857)
 * Description: circled dot operator
 */
static wchar_t* CIRCLEDOT_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"CircleDot";
static int* CIRCLEDOT_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The odot html character entity reference model.
 *
 * Name: odot
 * Character: ⊙
 * Unicode code point: U+2299 (8857)
 * Description: circled dot operator
 */
static wchar_t* ODOT_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odot";
static int* ODOT_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circledcirc html character entity reference model.
 *
 * Name: circledcirc
 * Character: ⊚
 * Unicode code point: U+229a (8858)
 * Description: circled ring operator
 */
static wchar_t* CIRCLEDCIRC_CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledcirc";
static int* CIRCLEDCIRC_CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ocir html character entity reference model.
 *
 * Name: ocir
 * Character: ⊚
 * Unicode code point: U+229a (8858)
 * Description: circled ring operator
 */
static wchar_t* OCIR_CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ocir";
static int* OCIR_CIRCLED_RING_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circledast html character entity reference model.
 *
 * Name: circledast
 * Character: ⊛
 * Unicode code point: U+229b (8859)
 * Description: circled asterisk operator
 */
static wchar_t* CIRCLEDAST_CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledast";
static int* CIRCLEDAST_CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oast html character entity reference model.
 *
 * Name: oast
 * Character: ⊛
 * Unicode code point: U+229b (8859)
 * Description: circled asterisk operator
 */
static wchar_t* OAST_CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oast";
static int* OAST_CIRCLED_ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circleddash html character entity reference model.
 *
 * Name: circleddash
 * Character: ⊝
 * Unicode code point: U+229d (8861)
 * Description: circled dash
 */
static wchar_t* CIRCLEDDASH_CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circleddash";
static int* CIRCLEDDASH_CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The odash html character entity reference model.
 *
 * Name: odash
 * Character: ⊝
 * Unicode code point: U+229d (8861)
 * Description: circled dash
 */
static wchar_t* ODASH_CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odash";
static int* ODASH_CIRCLED_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxplus html character entity reference model.
 *
 * Name: boxplus
 * Character: ⊞
 * Unicode code point: U+229e (8862)
 * Description: squared plus
 */
static wchar_t* BOXPLUS_SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxplus";
static int* BOXPLUS_SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plusb html character entity reference model.
 *
 * Name: plusb
 * Character: ⊞
 * Unicode code point: U+229e (8862)
 * Description: squared plus
 */
static wchar_t* PLUSB_SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusb";
static int* PLUSB_SQUARED_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxminus html character entity reference model.
 *
 * Name: boxminus
 * Character: ⊟
 * Unicode code point: U+229f (8863)
 * Description: squared minus
 */
static wchar_t* BOXMINUS_SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxminus";
static int* BOXMINUS_SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minusb html character entity reference model.
 *
 * Name: minusb
 * Character: ⊟
 * Unicode code point: U+229f (8863)
 * Description: squared minus
 */
static wchar_t* MINUSB_SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minusb";
static int* MINUSB_SQUARED_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxtimes html character entity reference model.
 *
 * Name: boxtimes
 * Character: ⊠
 * Unicode code point: U+22a0 (8864)
 * Description: squared times
 */
static wchar_t* BOXTIMES_SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxtimes";
static int* BOXTIMES_SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The timesb html character entity reference model.
 *
 * Name: timesb
 * Character: ⊠
 * Unicode code point: U+22a0 (8864)
 * Description: squared times
 */
static wchar_t* TIMESB_SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"timesb";
static int* TIMESB_SQUARED_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dotsquare html character entity reference model.
 *
 * Name: dotsquare
 * Character: ⊡
 * Unicode code point: U+22a1 (8865)
 * Description: squared dot operator
 */
static wchar_t* DOTSQUARE_SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dotsquare";
static int* DOTSQUARE_SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sdotb html character entity reference model.
 *
 * Name: sdotb
 * Character: ⊡
 * Unicode code point: U+22a1 (8865)
 * Description: squared dot operator
 */
static wchar_t* SDOTB_SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdotb";
static int* SDOTB_SQUARED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTee html character entity reference model.
 *
 * Name: RightTee
 * Character: ⊢
 * Unicode code point: U+22a2 (8866)
 * Description: right tack
 */
static wchar_t* RIGHTTEE_RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTee";
static int* RIGHTTEE_RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vdash html character entity reference model.
 *
 * Name: vdash
 * Character: ⊢
 * Unicode code point: U+22a2 (8866)
 * Description: right tack
 */
static wchar_t* VDASH_RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vdash";
static int* VDASH_RIGHT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTee html character entity reference model.
 *
 * Name: LeftTee
 * Character: ⊣
 * Unicode code point: U+22a3 (8867)
 * Description: left tack
 */
static wchar_t* LEFTTEE_LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTee";
static int* LEFTTEE_LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dashv html character entity reference model.
 *
 * Name: dashv
 * Character: ⊣
 * Unicode code point: U+22a3 (8867)
 * Description: left tack
 */
static wchar_t* DASHV_LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dashv";
static int* DASHV_LEFT_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownTee html character entity reference model.
 *
 * Name: DownTee
 * Character: ⊤
 * Unicode code point: U+22a4 (8868)
 * Description: down tack
 */
static wchar_t* DOWNTEE_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownTee";
static int* DOWNTEE_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The top html character entity reference model.
 *
 * Name: top
 * Character: ⊤
 * Unicode code point: U+22a4 (8868)
 * Description: down tack
 */
static wchar_t* TOP_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"top";
static int* TOP_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpTee html character entity reference model.
 *
 * Name: UpTee
 * Character: ⊥
 * Unicode code point: U+22a5 (8869)
 * Description: up tack
 */
static wchar_t* UPTEE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpTee";
static int* UPTEE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bot html character entity reference model.
 *
 * Name: bot
 * Character: ⊥
 * Unicode code point: U+22a5 (8869)
 * Description: up tack
 */
static wchar_t* BOT_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bot";
static int* BOT_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bottom html character entity reference model.
 *
 * Name: bottom
 * Character: ⊥
 * Unicode code point: U+22a5 (8869)
 * Description: up tack
 */
static wchar_t* BOTTOM_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bottom";
static int* BOTTOM_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The perp html character entity reference model.
 *
 * Name: perp
 * Character: ⊥
 * Unicode code point: U+22a5 (8869)
 * Description: up tack
 */
static wchar_t* PERP_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"perp";
static int* PERP_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The models html character entity reference model.
 *
 * Name: models
 * Character: ⊧
 * Unicode code point: U+22a7 (8871)
 * Description: models
 */
static wchar_t* MODELS_MODELS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"models";
static int* MODELS_MODELS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleRightTee html character entity reference model.
 *
 * Name: DoubleRightTee
 * Character: ⊨
 * Unicode code point: U+22a8 (8872)
 * Description: true
 */
static wchar_t* DOUBLERIGHTTEE_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleRightTee";
static int* DOUBLERIGHTTEE_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vDash html character entity reference model.
 *
 * Name: vDash
 * Character: ⊨
 * Unicode code point: U+22a8 (8872)
 * Description: true
 */
static wchar_t* VDASH_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vDash";
static int* VDASH_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vdash html character entity reference model.
 *
 * Name: Vdash
 * Character: ⊩
 * Unicode code point: U+22a9 (8873)
 * Description: forces
 */
static wchar_t* VDASH_FORCES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vdash";
static int* VDASH_FORCES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vvdash html character entity reference model.
 *
 * Name: Vvdash
 * Character: ⊪
 * Unicode code point: U+22aa (8874)
 * Description: triple vertical bar right turnstile
 */
static wchar_t* VVDASH_TRIPLE_VERTICAL_BAR_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vvdash";
static int* VVDASH_TRIPLE_VERTICAL_BAR_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VDash html character entity reference model.
 *
 * Name: VDash
 * Character: ⊫
 * Unicode code point: U+22ab (8875)
 * Description: double vertical bar double right turnstile
 */
static wchar_t* VDASH_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VDash";
static int* VDASH_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvdash html character entity reference model.
 *
 * Name: nvdash
 * Character: ⊬
 * Unicode code point: U+22ac (8876)
 * Description: does not prove
 */
static wchar_t* NVDASH_DOES_NOT_PROVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvdash";
static int* NVDASH_DOES_NOT_PROVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvDash html character entity reference model.
 *
 * Name: nvDash
 * Character: ⊭
 * Unicode code point: U+22ad (8877)
 * Description: not true
 */
static wchar_t* NVDASH_NOT_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvDash";
static int* NVDASH_NOT_TRUE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nVdash html character entity reference model.
 *
 * Name: nVdash
 * Character: ⊮
 * Unicode code point: U+22ae (8878)
 * Description: does not force
 */
static wchar_t* NVDASH_DOES_NOT_FORCE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nVdash";
static int* NVDASH_DOES_NOT_FORCE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nVDash html character entity reference model.
 *
 * Name: nVDash
 * Character: ⊯
 * Unicode code point: U+22af (8879)
 * Description: negated double vertical bar double right turnstile
 */
static wchar_t* NVDASH_NEGATED_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nVDash";
static int* NVDASH_NEGATED_DOUBLE_VERTICAL_BAR_DOUBLE_RIGHT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prurel html character entity reference model.
 *
 * Name: prurel
 * Character: ⊰
 * Unicode code point: U+22b0 (8880)
 * Description: precedes under relation
 */
static wchar_t* PRUREL_PRECEDES_UNDER_RELATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prurel";
static int* PRUREL_PRECEDES_UNDER_RELATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTriangle html character entity reference model.
 *
 * Name: LeftTriangle
 * Character: ⊲
 * Unicode code point: U+22b2 (8882)
 * Description: normal subgroup of
 */
static wchar_t* LEFTTRIANGLE_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangle";
static int* LEFTTRIANGLE_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vartriangleleft html character entity reference model.
 *
 * Name: vartriangleleft
 * Character: ⊲
 * Unicode code point: U+22b2 (8882)
 * Description: normal subgroup of
 */
static wchar_t* VARTRIANGLELEFT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vartriangleleft";
static int* VARTRIANGLELEFT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vltri html character entity reference model.
 *
 * Name: vltri
 * Character: ⊲
 * Unicode code point: U+22b2 (8882)
 * Description: normal subgroup of
 */
static wchar_t* VLTRI_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vltri";
static int* VLTRI_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTriangle html character entity reference model.
 *
 * Name: RightTriangle
 * Character: ⊳
 * Unicode code point: U+22b3 (8883)
 * Description: contains as normal subgroup
 */
static wchar_t* RIGHTTRIANGLE_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangle";
static int* RIGHTTRIANGLE_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vartriangleright html character entity reference model.
 *
 * Name: vartriangleright
 * Character: ⊳
 * Unicode code point: U+22b3 (8883)
 * Description: contains as normal subgroup
 */
static wchar_t* VARTRIANGLERIGHT_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vartriangleright";
static int* VARTRIANGLERIGHT_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vrtri html character entity reference model.
 *
 * Name: vrtri
 * Character: ⊳
 * Unicode code point: U+22b3 (8883)
 * Description: contains as normal subgroup
 */
static wchar_t* VRTRI_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vrtri";
static int* VRTRI_CONTAINS_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTriangleEqual html character entity reference model.
 *
 * Name: LeftTriangleEqual
 * Character: ⊴
 * Unicode code point: U+22b4 (8884)
 * Description: normal subgroup of or equal to
 */
static wchar_t* LEFTTRIANGLEEQUAL_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangleEqual";
static int* LEFTTRIANGLEEQUAL_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltrie html character entity reference model.
 *
 * Name: ltrie
 * Character: ⊴
 * Unicode code point: U+22b4 (8884)
 * Description: normal subgroup of or equal to
 */
static wchar_t* LTRIE_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltrie";
static int* LTRIE_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trianglelefteq html character entity reference model.
 *
 * Name: trianglelefteq
 * Character: ⊴
 * Unicode code point: U+22b4 (8884)
 * Description: normal subgroup of or equal to
 */
static wchar_t* TRIANGLELEFTEQ_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trianglelefteq";
static int* TRIANGLELEFTEQ_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvltrie html character entity reference model.
 *
 * Name: nvltrie
 * Character: ⊴⃒
 * Unicode code point: U+22b4;U+20d2 (8884;8402)
 * Description: normal subgroup of or equal to with vertical line
 */
static wchar_t* NVLTRIE_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvltrie";
static int* NVLTRIE_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTriangleEqual html character entity reference model.
 *
 * Name: RightTriangleEqual
 * Character: ⊵
 * Unicode code point: U+22b5 (8885)
 * Description: contains as normal subgroup or equal to
 */
static wchar_t* RIGHTTRIANGLEEQUAL_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangleEqual";
static int* RIGHTTRIANGLEEQUAL_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rtrie html character entity reference model.
 *
 * Name: rtrie
 * Character: ⊵
 * Unicode code point: U+22b5 (8885)
 * Description: contains as normal subgroup or equal to
 */
static wchar_t* RTRIE_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtrie";
static int* RTRIE_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trianglerighteq html character entity reference model.
 *
 * Name: trianglerighteq
 * Character: ⊵
 * Unicode code point: U+22b5 (8885)
 * Description: contains as normal subgroup or equal to
 */
static wchar_t* TRIANGLERIGHTEQ_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trianglerighteq";
static int* TRIANGLERIGHTEQ_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvrtrie html character entity reference model.
 *
 * Name: nvrtrie
 * Character: ⊵⃒
 * Unicode code point: U+22b5;U+20d2 (8885;8402)
 * Description: contains as normal subgroup or equal to with vertical line
 */
static wchar_t* NVRTRIE_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvrtrie";
static int* NVRTRIE_CONTAINS_AS_NORMAL_SUBGROUP_OR_EQUAL_TO_WITH_VERTICAL_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The origof html character entity reference model.
 *
 * Name: origof
 * Character: ⊶
 * Unicode code point: U+22b6 (8886)
 * Description: original of
 */
static wchar_t* ORIGOF_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"origof";
static int* ORIGOF_ORIGINAL_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The imof html character entity reference model.
 *
 * Name: imof
 * Character: ⊷
 * Unicode code point: U+22b7 (8887)
 * Description: image of
 */
static wchar_t* IMOF_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"imof";
static int* IMOF_IMAGE_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multimap html character entity reference model.
 *
 * Name: multimap
 * Character: ⊸
 * Unicode code point: U+22b8 (8888)
 * Description: multimap
 */
static wchar_t* MULTIMAP_MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"multimap";
static int* MULTIMAP_MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mumap html character entity reference model.
 *
 * Name: mumap
 * Character: ⊸
 * Unicode code point: U+22b8 (8888)
 * Description: multimap
 */
static wchar_t* MUMAP_MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mumap";
static int* MUMAP_MULTIMAP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hercon html character entity reference model.
 *
 * Name: hercon
 * Character: ⊹
 * Unicode code point: U+22b9 (8889)
 * Description: hermitian conjugate matrix
 */
static wchar_t* HERCON_HERMITIAN_CONJUGATE_MATRIX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hercon";
static int* HERCON_HERMITIAN_CONJUGATE_MATRIX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intcal html character entity reference model.
 *
 * Name: intcal
 * Character: ⊺
 * Unicode code point: U+22ba (8890)
 * Description: intercalate
 */
static wchar_t* INTCAL_INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intcal";
static int* INTCAL_INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intercal html character entity reference model.
 *
 * Name: intercal
 * Character: ⊺
 * Unicode code point: U+22ba (8890)
 * Description: intercalate
 */
static wchar_t* INTERCAL_INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intercal";
static int* INTERCAL_INTERCALATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The veebar html character entity reference model.
 *
 * Name: veebar
 * Character: ⊻
 * Unicode code point: U+22bb (8891)
 * Description: xor
 */
static wchar_t* VEEBAR_XOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"veebar";
static int* VEEBAR_XOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The barvee html character entity reference model.
 *
 * Name: barvee
 * Character: ⊽
 * Unicode code point: U+22bd (8893)
 * Description: nor
 */
static wchar_t* BARVEE_NOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"barvee";
static int* BARVEE_NOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angrtvb html character entity reference model.
 *
 * Name: angrtvb
 * Character: ⊾
 * Unicode code point: U+22be (8894)
 * Description: right angle with arc
 */
static wchar_t* ANGRTVB_RIGHT_ANGLE_WITH_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrtvb";
static int* ANGRTVB_RIGHT_ANGLE_WITH_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrtri html character entity reference model.
 *
 * Name: lrtri
 * Character: ⊿
 * Unicode code point: U+22bf (8895)
 * Description: right triangle
 */
static wchar_t* LRTRI_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrtri";
static int* LRTRI_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Wedge html character entity reference model.
 *
 * Name: Wedge
 * Character: ⋀
 * Unicode code point: U+22c0 (8896)
 * Description: n-ary logical and
 */
static wchar_t* WEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wedge";
static int* WEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigwedge html character entity reference model.
 *
 * Name: bigwedge
 * Character: ⋀
 * Unicode code point: U+22c0 (8896)
 * Description: n-ary logical and
 */
static wchar_t* BIGWEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigwedge";
static int* BIGWEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xwedge html character entity reference model.
 *
 * Name: xwedge
 * Character: ⋀
 * Unicode code point: U+22c0 (8896)
 * Description: n-ary logical and
 */
static wchar_t* XWEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xwedge";
static int* XWEDGE_N_ARY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vee html character entity reference model.
 *
 * Name: Vee
 * Character: ⋁
 * Unicode code point: U+22c1 (8897)
 * Description: n-ary logical or
 */
static wchar_t* VEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vee";
static int* VEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigvee html character entity reference model.
 *
 * Name: bigvee
 * Character: ⋁
 * Unicode code point: U+22c1 (8897)
 * Description: n-ary logical or
 */
static wchar_t* BIGVEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigvee";
static int* BIGVEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xvee html character entity reference model.
 *
 * Name: xvee
 * Character: ⋁
 * Unicode code point: U+22c1 (8897)
 * Description: n-ary logical or
 */
static wchar_t* XVEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xvee";
static int* XVEE_N_ARY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Intersection html character entity reference model.
 *
 * Name: Intersection
 * Character: ⋂
 * Unicode code point: U+22c2 (8898)
 * Description: n-ary intersection
 */
static wchar_t* INTERSECTION_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Intersection";
static int* INTERSECTION_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigcap html character entity reference model.
 *
 * Name: bigcap
 * Character: ⋂
 * Unicode code point: U+22c2 (8898)
 * Description: n-ary intersection
 */
static wchar_t* BIGCAP_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigcap";
static int* BIGCAP_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xcap html character entity reference model.
 *
 * Name: xcap
 * Character: ⋂
 * Unicode code point: U+22c2 (8898)
 * Description: n-ary intersection
 */
static wchar_t* XCAP_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xcap";
static int* XCAP_N_ARY_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Union html character entity reference model.
 *
 * Name: Union
 * Character: ⋃
 * Unicode code point: U+22c3 (8899)
 * Description: n-ary union
 */
static wchar_t* UNION_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Union";
static int* UNION_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigcup html character entity reference model.
 *
 * Name: bigcup
 * Character: ⋃
 * Unicode code point: U+22c3 (8899)
 * Description: n-ary union
 */
static wchar_t* BIGCUP_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigcup";
static int* BIGCUP_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xcup html character entity reference model.
 *
 * Name: xcup
 * Character: ⋃
 * Unicode code point: U+22c3 (8899)
 * Description: n-ary union
 */
static wchar_t* XCUP_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xcup";
static int* XCUP_N_ARY_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Diamond html character entity reference model.
 *
 * Name: Diamond
 * Character: ⋄
 * Unicode code point: U+22c4 (8900)
 * Description: diamond operator
 */
static wchar_t* CAMEL_DIAMOND_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Diamond";
static int* CAMEL_DIAMOND_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diam html character entity reference model.
 *
 * Name: diam
 * Character: ⋄
 * Unicode code point: U+22c4 (8900)
 * Description: diamond operator
 */
static wchar_t* DIAM_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diam";
static int* DIAM_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diamond html character entity reference model.
 *
 * Name: diamond
 * Character: ⋄
 * Unicode code point: U+22c4 (8900)
 * Description: diamond operator
 */
static wchar_t* SMALL_DIAMOND_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diamond";
static int* SMALL_DIAMOND_DIAMOND_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sdot html character entity reference model.
 *
 * Name: sdot
 * Character: ⋅
 * Unicode code point: U+22c5 (8901)
 * Description: dot operator
 */
static wchar_t* SDOT_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdot";
static int* SDOT_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Star html character entity reference model.
 *
 * Name: Star
 * Character: ⋆
 * Unicode code point: U+22c6 (8902)
 * Description: star operator
 */
static wchar_t* STAR_STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Star";
static int* STAR_STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sstarf html character entity reference model.
 *
 * Name: sstarf
 * Character: ⋆
 * Unicode code point: U+22c6 (8902)
 * Description: star operator
 */
static wchar_t* SSTARF_STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sstarf";
static int* SSTARF_STAR_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The divideontimes html character entity reference model.
 *
 * Name: divideontimes
 * Character: ⋇
 * Unicode code point: U+22c7 (8903)
 * Description: division times
 */
static wchar_t* DIVIDEONTIMES_DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"divideontimes";
static int* DIVIDEONTIMES_DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The divonx html character entity reference model.
 *
 * Name: divonx
 * Character: ⋇
 * Unicode code point: U+22c7 (8903)
 * Description: division times
 */
static wchar_t* DIVONX_DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"divonx";
static int* DIVONX_DIVISION_TIMES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bowtie html character entity reference model.
 *
 * Name: bowtie
 * Character: ⋈
 * Unicode code point: U+22c8 (8904)
 * Description: bowtie
 */
static wchar_t* BOWTIE_BOWTIE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bowtie";
static int* BOWTIE_BOWTIE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltimes html character entity reference model.
 *
 * Name: ltimes
 * Character: ⋉
 * Unicode code point: U+22c9 (8905)
 * Description: left normal factor semidirect product
 */
static wchar_t* LTIMES_LEFT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltimes";
static int* LTIMES_LEFT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rtimes html character entity reference model.
 *
 * Name: rtimes
 * Character: ⋊
 * Unicode code point: U+22ca (8906)
 * Description: right normal factor semidirect product
 */
static wchar_t* RTIMES_RIGHT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtimes";
static int* RTIMES_RIGHT_NORMAL_FACTOR_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leftthreetimes html character entity reference model.
 *
 * Name: leftthreetimes
 * Character: ⋋
 * Unicode code point: U+22cb (8907)
 * Description: left semidirect product
 */
static wchar_t* LEFTTHREETIMES_LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leftthreetimes";
static int* LEFTTHREETIMES_LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lthree html character entity reference model.
 *
 * Name: lthree
 * Character: ⋋
 * Unicode code point: U+22cb (8907)
 * Description: left semidirect product
 */
static wchar_t* LTHREE_LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lthree";
static int* LTHREE_LEFT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rightthreetimes html character entity reference model.
 *
 * Name: rightthreetimes
 * Character: ⋌
 * Unicode code point: U+22cc (8908)
 * Description: right semidirect product
 */
static wchar_t* RIGHTTHREETIMES_RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rightthreetimes";
static int* RIGHTTHREETIMES_RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rthree html character entity reference model.
 *
 * Name: rthree
 * Character: ⋌
 * Unicode code point: U+22cc (8908)
 * Description: right semidirect product
 */
static wchar_t* RTHREE_RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rthree";
static int* RTHREE_RIGHT_SEMIDIRECT_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The backsimeq html character entity reference model.
 *
 * Name: backsimeq
 * Character: ⋍
 * Unicode code point: U+22cd (8909)
 * Description: reversed tilde equals
 */
static wchar_t* BACKSIMEQ_REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"backsimeq";
static int* BACKSIMEQ_REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsime html character entity reference model.
 *
 * Name: bsime
 * Character: ⋍
 * Unicode code point: U+22cd (8909)
 * Description: reversed tilde equals
 */
static wchar_t* BSIME_REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsime";
static int* BSIME_REVERSED_TILDE_EQUALS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curlyvee html character entity reference model.
 *
 * Name: curlyvee
 * Character: ⋎
 * Unicode code point: U+22ce (8910)
 * Description: curly logical or
 */
static wchar_t* CURLYVEE_CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlyvee";
static int* CURLYVEE_CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cuvee html character entity reference model.
 *
 * Name: cuvee
 * Character: ⋎
 * Unicode code point: U+22ce (8910)
 * Description: curly logical or
 */
static wchar_t* CUVEE_CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuvee";
static int* CUVEE_CURLY_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curlywedge html character entity reference model.
 *
 * Name: curlywedge
 * Character: ⋏
 * Unicode code point: U+22cf (8911)
 * Description: curly logical and
 */
static wchar_t* CURLYWEDGE_CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlywedge";
static int* CURLYWEDGE_CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cuwed html character entity reference model.
 *
 * Name: cuwed
 * Character: ⋏
 * Unicode code point: U+22cf (8911)
 * Description: curly logical and
 */
static wchar_t* CUWED_CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuwed";
static int* CUWED_CURLY_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sub html character entity reference model.
 *
 * Name: Sub
 * Character: ⋐
 * Unicode code point: U+22d0 (8912)
 * Description: double subset
 */
static wchar_t* SUB_DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sub";
static int* SUB_DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Subset html character entity reference model.
 *
 * Name: Subset
 * Character: ⋐
 * Unicode code point: U+22d0 (8912)
 * Description: double subset
 */
static wchar_t* SUBSET_DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Subset";
static int* SUBSET_DOUBLE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sup html character entity reference model.
 *
 * Name: Sup
 * Character: ⋑
 * Unicode code point: U+22d1 (8913)
 * Description: double superset
 */
static wchar_t* SUP_DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sup";
static int* SUP_DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Supset html character entity reference model.
 *
 * Name: Supset
 * Character: ⋑
 * Unicode code point: U+22d1 (8913)
 * Description: double superset
 */
static wchar_t* SUPSET_DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Supset";
static int* SUPSET_DOUBLE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cap html character entity reference model.
 *
 * Name: Cap
 * Character: ⋒
 * Unicode code point: U+22d2 (8914)
 * Description: double intersection
 */
static wchar_t* CAP_DOUBLE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cap";
static int* CAP_DOUBLE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cup html character entity reference model.
 *
 * Name: Cup
 * Character: ⋓
 * Unicode code point: U+22d3 (8915)
 * Description: double union
 */
static wchar_t* CUP_DOUBLE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cup";
static int* CUP_DOUBLE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fork html character entity reference model.
 *
 * Name: fork
 * Character: ⋔
 * Unicode code point: U+22d4 (8916)
 * Description: pitchfork
 */
static wchar_t* FORK_PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fork";
static int* FORK_PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pitchfork html character entity reference model.
 *
 * Name: pitchfork
 * Character: ⋔
 * Unicode code point: U+22d4 (8916)
 * Description: pitchfork
 */
static wchar_t* PITCHFORK_PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pitchfork";
static int* PITCHFORK_PITCHFORK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The epar html character entity reference model.
 *
 * Name: epar
 * Character: ⋕
 * Unicode code point: U+22d5 (8917)
 * Description: equal and parallel to
 */
static wchar_t* EPAR_EQUAL_AND_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"epar";
static int* EPAR_EQUAL_AND_PARALLEL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lessdot html character entity reference model.
 *
 * Name: lessdot
 * Character: ⋖
 * Unicode code point: U+22d6 (8918)
 * Description: less-than with dot
 */
static wchar_t* LESSDOT_LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lessdot";
static int* LESSDOT_LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltdot html character entity reference model.
 *
 * Name: ltdot
 * Character: ⋖
 * Unicode code point: U+22d6 (8918)
 * Description: less-than with dot
 */
static wchar_t* LTDOT_LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltdot";
static int* LTDOT_LESS_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtdot html character entity reference model.
 *
 * Name: gtdot
 * Character: ⋗
 * Unicode code point: U+22d7 (8919)
 * Description: greater-than with dot
 */
static wchar_t* GTDOT_GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtdot";
static int* GTDOT_GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtrdot html character entity reference model.
 *
 * Name: gtrdot
 * Character: ⋗
 * Unicode code point: U+22d7 (8919)
 * Description: greater-than with dot
 */
static wchar_t* GTRDOT_GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrdot";
static int* GTRDOT_GREATER_THAN_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ll html character entity reference model.
 *
 * Name: Ll
 * Character: ⋘
 * Unicode code point: U+22d8 (8920)
 * Description: very much less-than
 */
static wchar_t* LL_VERY_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ll";
static int* LL_VERY_MUCH_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nLl html character entity reference model.
 *
 * Name: nLl
 * Character: ⋘̸
 * Unicode code point: U+22d8;U+0338 (8920;824)
 * Description: very much less-than with slash
 */
static wchar_t* NLL_VERY_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nLl";
static int* NLL_VERY_MUCH_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gg html character entity reference model.
 *
 * Name: Gg
 * Character: ⋙
 * Unicode code point: U+22d9 (8921)
 * Description: very much greater-than
 */
static wchar_t* GG_VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gg";
static int* GG_VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ggg html character entity reference model.
 *
 * Name: ggg
 * Character: ⋙
 * Unicode code point: U+22d9 (8921)
 * Description: very much greater-than
 */
static wchar_t* GGG_VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ggg";
static int* GGG_VERY_MUCH_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nGg html character entity reference model.
 *
 * Name: nGg
 * Character: ⋙̸
 * Unicode code point: U+22d9;U+0338 (8921;824)
 * Description: very much greater-than with slash
 */
static wchar_t* NGG_VERY_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nGg";
static int* NGG_VERY_MUCH_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessEqualGreater html character entity reference model.
 *
 * Name: LessEqualGreater
 * Character: ⋚
 * Unicode code point: U+22da (8922)
 * Description: less-than equal to or greater-than
 */
static wchar_t* LESSEQUALGREATER_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessEqualGreater";
static int* LESSEQUALGREATER_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leg html character entity reference model.
 *
 * Name: leg
 * Character: ⋚
 * Unicode code point: U+22da (8922)
 * Description: less-than equal to or greater-than
 */
static wchar_t* LEG_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leg";
static int* LEG_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesseqgtr html character entity reference model.
 *
 * Name: lesseqgtr
 * Character: ⋚
 * Unicode code point: U+22da (8922)
 * Description: less-than equal to or greater-than
 */
static wchar_t* LESSEQGTR_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesseqgtr";
static int* LESSEQGTR_LESS_THAN_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesg html character entity reference model.
 *
 * Name: lesg
 * Character: ⋚︀
 * Unicode code point: U+22da;U+fe00 (8922;65024)
 * Description: less-than slanted equal to or greater-than
 */
static wchar_t* LESG_LESS_THAN_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesg";
static int* LESG_LESS_THAN_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterEqualLess html character entity reference model.
 *
 * Name: GreaterEqualLess
 * Character: ⋛
 * Unicode code point: U+22db (8923)
 * Description: greater-than equal to or less-than
 */
static wchar_t* GREATEREQUALLESS_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterEqualLess";
static int* GREATEREQUALLESS_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gel html character entity reference model.
 *
 * Name: gel
 * Character: ⋛
 * Unicode code point: U+22db (8923)
 * Description: greater-than equal to or less-than
 */
static wchar_t* GEL_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gel";
static int* GEL_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtreqless html character entity reference model.
 *
 * Name: gtreqless
 * Character: ⋛
 * Unicode code point: U+22db (8923)
 * Description: greater-than equal to or less-than
 */
static wchar_t* GTREQLESS_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtreqless";
static int* GTREQLESS_GREATER_THAN_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gesl html character entity reference model.
 *
 * Name: gesl
 * Character: ⋛︀
 * Unicode code point: U+22db;U+fe00 (8923;65024)
 * Description: greater-than slanted equal to or less-than
 */
static wchar_t* GESL_GREATER_THAN_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesl";
static int* GESL_GREATER_THAN_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cuepr html character entity reference model.
 *
 * Name: cuepr
 * Character: ⋞
 * Unicode code point: U+22de (8926)
 * Description: equal to or precedes
 */
static wchar_t* CUEPR_EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuepr";
static int* CUEPR_EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curlyeqprec html character entity reference model.
 *
 * Name: curlyeqprec
 * Character: ⋞
 * Unicode code point: U+22de (8926)
 * Description: equal to or precedes
 */
static wchar_t* CURLYEQPREC_EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlyeqprec";
static int* CURLYEQPREC_EQUAL_TO_OR_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cuesc html character entity reference model.
 *
 * Name: cuesc
 * Character: ⋟
 * Unicode code point: U+22df (8927)
 * Description: equal to or succeeds
 */
static wchar_t* CUESC_EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cuesc";
static int* CUESC_EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curlyeqsucc html character entity reference model.
 *
 * Name: curlyeqsucc
 * Character: ⋟
 * Unicode code point: U+22df (8927)
 * Description: equal to or succeeds
 */
static wchar_t* CURLYEQSUCC_EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curlyeqsucc";
static int* CURLYEQSUCC_EQUAL_TO_OR_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotPrecedesSlantEqual html character entity reference model.
 *
 * Name: NotPrecedesSlantEqual
 * Character: ⋠
 * Unicode code point: U+22e0 (8928)
 * Description: does not precede or equal
 */
static wchar_t* NOTPRECEDESSLANTEQUAL_DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedesSlantEqual";
static int* NOTPRECEDESSLANTEQUAL_DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nprcue html character entity reference model.
 *
 * Name: nprcue
 * Character: ⋠
 * Unicode code point: U+22e0 (8928)
 * Description: does not precede or equal
 */
static wchar_t* NPRCUE_DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nprcue";
static int* NPRCUE_DOES_NOT_PRECEDE_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSucceedsSlantEqual html character entity reference model.
 *
 * Name: NotSucceedsSlantEqual
 * Character: ⋡
 * Unicode code point: U+22e1 (8929)
 * Description: does not succeed or equal
 */
static wchar_t* NOTSUCCEEDSSLANTEQUAL_DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsSlantEqual";
static int* NOTSUCCEEDSSLANTEQUAL_DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsccue html character entity reference model.
 *
 * Name: nsccue
 * Character: ⋡
 * Unicode code point: U+22e1 (8929)
 * Description: does not succeed or equal
 */
static wchar_t* NSCCUE_DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsccue";
static int* NSCCUE_DOES_NOT_SUCCEED_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSquareSubsetEqual html character entity reference model.
 *
 * Name: NotSquareSubsetEqual
 * Character: ⋢
 * Unicode code point: U+22e2 (8930)
 * Description: not square image of or equal to
 */
static wchar_t* NOTSQUARESUBSETEQUAL_NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSubsetEqual";
static int* NOTSQUARESUBSETEQUAL_NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsqsube html character entity reference model.
 *
 * Name: nsqsube
 * Character: ⋢
 * Unicode code point: U+22e2 (8930)
 * Description: not square image of or equal to
 */
static wchar_t* NSQSUBE_NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsqsube";
static int* NSQSUBE_NOT_SQUARE_IMAGE_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSquareSupersetEqual html character entity reference model.
 *
 * Name: NotSquareSupersetEqual
 * Character: ⋣
 * Unicode code point: U+22e3 (8931)
 * Description: not square original of or equal to
 */
static wchar_t* NOTSQUARESUPERSETEQUAL_NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSquareSupersetEqual";
static int* NOTSQUARESUPERSETEQUAL_NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsqsupe html character entity reference model.
 *
 * Name: nsqsupe
 * Character: ⋣
 * Unicode code point: U+22e3 (8931)
 * Description: not square original of or equal to
 */
static wchar_t* NSQSUPE_NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsqsupe";
static int* NSQSUPE_NOT_SQUARE_ORIGINAL_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lnsim html character entity reference model.
 *
 * Name: lnsim
 * Character: ⋦
 * Unicode code point: U+22e6 (8934)
 * Description: less-than but not equivalent to
 */
static wchar_t* LNSIM_LESS_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnsim";
static int* LNSIM_LESS_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gnsim html character entity reference model.
 *
 * Name: gnsim
 * Character: ⋧
 * Unicode code point: U+22e7 (8935)
 * Description: greater-than but not equivalent to
 */
static wchar_t* GNSIM_GREATER_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnsim";
static int* GNSIM_GREATER_THAN_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precnsim html character entity reference model.
 *
 * Name: precnsim
 * Character: ⋨
 * Unicode code point: U+22e8 (8936)
 * Description: precedes but not equivalent to
 */
static wchar_t* PRECNSIM_PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precnsim";
static int* PRECNSIM_PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prnsim html character entity reference model.
 *
 * Name: prnsim
 * Character: ⋨
 * Unicode code point: U+22e8 (8936)
 * Description: precedes but not equivalent to
 */
static wchar_t* PRNSIM_PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prnsim";
static int* PRNSIM_PRECEDES_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scnsim html character entity reference model.
 *
 * Name: scnsim
 * Character: ⋩
 * Unicode code point: U+22e9 (8937)
 * Description: succeeds but not equivalent to
 */
static wchar_t* SCNSIM_SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnsim";
static int* SCNSIM_SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succnsim html character entity reference model.
 *
 * Name: succnsim
 * Character: ⋩
 * Unicode code point: U+22e9 (8937)
 * Description: succeeds but not equivalent to
 */
static wchar_t* SUCCNSIM_SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succnsim";
static int* SUCCNSIM_SUCCEEDS_BUT_NOT_EQUIVALENT_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLeftTriangle html character entity reference model.
 *
 * Name: NotLeftTriangle
 * Character: ⋪
 * Unicode code point: U+22ea (8938)
 * Description: not normal subgroup of
 */
static wchar_t* NOTLEFTTRIANGLE_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangle";
static int* NOTLEFTTRIANGLE_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nltri html character entity reference model.
 *
 * Name: nltri
 * Character: ⋪
 * Unicode code point: U+22ea (8938)
 * Description: not normal subgroup of
 */
static wchar_t* NLTRI_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nltri";
static int* NLTRI_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntriangleleft html character entity reference model.
 *
 * Name: ntriangleleft
 * Character: ⋪
 * Unicode code point: U+22ea (8938)
 * Description: not normal subgroup of
 */
static wchar_t* NTRIANGLELEFT_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntriangleleft";
static int* NTRIANGLELEFT_NOT_NORMAL_SUBGROUP_OF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotRightTriangle html character entity reference model.
 *
 * Name: NotRightTriangle
 * Character: ⋫
 * Unicode code point: U+22eb (8939)
 * Description: does not contain as normal subgroup
 */
static wchar_t* NOTRIGHTTRIANGLE_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangle";
static int* NOTRIGHTTRIANGLE_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrtri html character entity reference model.
 *
 * Name: nrtri
 * Character: ⋫
 * Unicode code point: U+22eb (8939)
 * Description: does not contain as normal subgroup
 */
static wchar_t* NRTRI_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrtri";
static int* NRTRI_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntriangleright html character entity reference model.
 *
 * Name: ntriangleright
 * Character: ⋫
 * Unicode code point: U+22eb (8939)
 * Description: does not contain as normal subgroup
 */
static wchar_t* NTRIANGLERIGHT_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntriangleright";
static int* NTRIANGLERIGHT_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLeftTriangleEqual html character entity reference model.
 *
 * Name: NotLeftTriangleEqual
 * Character: ⋬
 * Unicode code point: U+22ec (8940)
 * Description: not normal subgroup of or equal to
 */
static wchar_t* NOTLEFTTRIANGLEEQUAL_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangleEqual";
static int* NOTLEFTTRIANGLEEQUAL_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nltrie html character entity reference model.
 *
 * Name: nltrie
 * Character: ⋬
 * Unicode code point: U+22ec (8940)
 * Description: not normal subgroup of or equal to
 */
static wchar_t* NLTRIE_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nltrie";
static int* NLTRIE_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntrianglelefteq html character entity reference model.
 *
 * Name: ntrianglelefteq
 * Character: ⋬
 * Unicode code point: U+22ec (8940)
 * Description: not normal subgroup of or equal to
 */
static wchar_t* NTRIANGLELEFTEQ_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntrianglelefteq";
static int* NTRIANGLELEFTEQ_NOT_NORMAL_SUBGROUP_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotRightTriangleEqual html character entity reference model.
 *
 * Name: NotRightTriangleEqual
 * Character: ⋭
 * Unicode code point: U+22ed (8941)
 * Description: does not contain as normal subgroup or equal
 */
static wchar_t* NOTRIGHTTRIANGLEEQUAL_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangleEqual";
static int* NOTRIGHTTRIANGLEEQUAL_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrtrie html character entity reference model.
 *
 * Name: nrtrie
 * Character: ⋭
 * Unicode code point: U+22ed (8941)
 * Description: does not contain as normal subgroup or equal
 */
static wchar_t* NRTRIE_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrtrie";
static int* NRTRIE_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ntrianglerighteq html character entity reference model.
 *
 * Name: ntrianglerighteq
 * Character: ⋭
 * Unicode code point: U+22ed (8941)
 * Description: does not contain as normal subgroup or equal
 */
static wchar_t* NTRIANGLERIGHTEQ_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ntrianglerighteq";
static int* NTRIANGLERIGHTEQ_DOES_NOT_CONTAIN_AS_NORMAL_SUBGROUP_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vellip html character entity reference model.
 *
 * Name: vellip
 * Character: ⋮
 * Unicode code point: U+22ee (8942)
 * Description: vertical ellipsis
 */
static wchar_t* VELLIP_VERTICAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vellip";
static int* VELLIP_VERTICAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ctdot html character entity reference model.
 *
 * Name: ctdot
 * Character: ⋯
 * Unicode code point: U+22ef (8943)
 * Description: midline horizontal ellipsis
 */
static wchar_t* CTDOT_MIDLINE_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ctdot";
static int* CTDOT_MIDLINE_HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The utdot html character entity reference model.
 *
 * Name: utdot
 * Character: ⋰
 * Unicode code point: U+22f0 (8944)
 * Description: up right diagonal ellipsis
 */
static wchar_t* UTDOT_UP_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utdot";
static int* UTDOT_UP_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dtdot html character entity reference model.
 *
 * Name: dtdot
 * Character: ⋱
 * Unicode code point: U+22f1 (8945)
 * Description: down right diagonal ellipsis
 */
static wchar_t* DTDOT_DOWN_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dtdot";
static int* DTDOT_DOWN_RIGHT_DIAGONAL_ELLIPSIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The disin html character entity reference model.
 *
 * Name: disin
 * Character: ⋲
 * Unicode code point: U+22f2 (8946)
 * Description: element of with long horizontal stroke
 */
static wchar_t* DISIN_ELEMENT_OF_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"disin";
static int* DISIN_ELEMENT_OF_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isinsv html character entity reference model.
 *
 * Name: isinsv
 * Character: ⋳
 * Unicode code point: U+22f3 (8947)
 * Description: element of with vertical bar at end of horizontal stroke
 */
static wchar_t* ISINSV_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isinsv";
static int* ISINSV_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isins html character entity reference model.
 *
 * Name: isins
 * Character: ⋴
 * Unicode code point: U+22f4 (8948)
 * Description: small element of with vertical bar at end of horizontal stroke
 */
static wchar_t* ISINS_SMALL_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isins";
static int* ISINS_SMALL_ELEMENT_OF_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isindot html character entity reference model.
 *
 * Name: isindot
 * Character: ⋵
 * Unicode code point: U+22f5 (8949)
 * Description: element of with dot above
 */
static wchar_t* ISINDOT_ELEMENT_OF_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isindot";
static int* ISINDOT_ELEMENT_OF_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notindot html character entity reference model.
 *
 * Name: notindot
 * Character: ⋵̸
 * Unicode code point: U+22f5;U+0338 (8949;824)
 * Description: element of with dot above with slash
 */
static wchar_t* NOTINDOT_ELEMENT_OF_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notindot";
static int* NOTINDOT_ELEMENT_OF_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notinvc html character entity reference model.
 *
 * Name: notinvc
 * Character: ⋶
 * Unicode code point: U+22f6 (8950)
 * Description: element of with overbar
 */
static wchar_t* NOTINVC_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinvc";
static int* NOTINVC_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notinvb html character entity reference model.
 *
 * Name: notinvb
 * Character: ⋷
 * Unicode code point: U+22f7 (8951)
 * Description: small element of with overbar
 */
static wchar_t* NOTINVB_SMALL_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinvb";
static int* NOTINVB_SMALL_ELEMENT_OF_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The isinE html character entity reference model.
 *
 * Name: isinE
 * Character: ⋹
 * Unicode code point: U+22f9 (8953)
 * Description: element of with two horizontal strokes
 */
static wchar_t* ISINE_ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"isinE";
static int* ISINE_ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notinE html character entity reference model.
 *
 * Name: notinE
 * Character: ⋹̸
 * Unicode code point: U+22f9;U+0338 (8953;824)
 * Description: element of with two horizontal strokes with slash
 */
static wchar_t* NOTINE_ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notinE";
static int* NOTINE_ELEMENT_OF_WITH_TWO_HORIZONTAL_STROKES_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nisd html character entity reference model.
 *
 * Name: nisd
 * Character: ⋺
 * Unicode code point: U+22fa (8954)
 * Description: contains with long horizontal stroke
 */
static wchar_t* NISD_CONTAINS_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nisd";
static int* NISD_CONTAINS_WITH_LONG_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xnis html character entity reference model.
 *
 * Name: xnis
 * Character: ⋻
 * Unicode code point: U+22fb (8955)
 * Description: contains with vertical bar at end of horizontal stroke
 */
static wchar_t* XNIS_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xnis";
static int* XNIS_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nis html character entity reference model.
 *
 * Name: nis
 * Character: ⋼
 * Unicode code point: U+22fc (8956)
 * Description: small contains with vertical bar at end of horizontal stroke
 */
static wchar_t* NIS_SMALL_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nis";
static int* NIS_SMALL_CONTAINS_WITH_VERTICAL_BAR_AT_END_OF_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notnivc html character entity reference model.
 *
 * Name: notnivc
 * Character: ⋽
 * Unicode code point: U+22fd (8957)
 * Description: contains with overbar
 */
static wchar_t* NOTNIVC_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notnivc";
static int* NOTNIVC_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The notnivb html character entity reference model.
 *
 * Name: notnivb
 * Character: ⋾
 * Unicode code point: U+22fe (8958)
 * Description: small contains with overbar
 */
static wchar_t* NOTNIVB_SMALL_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"notnivb";
static int* NOTNIVB_SMALL_CONTAINS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The barwed html character entity reference model.
 *
 * Name: barwed
 * Character: ⌅
 * Unicode code point: U+2305 (8965)
 * Description: projective
 */
static wchar_t* BARWED_PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"barwed";
static int* BARWED_PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The barwedge html character entity reference model.
 *
 * Name: barwedge
 * Character: ⌅
 * Unicode code point: U+2305 (8965)
 * Description: projective
 */
static wchar_t* BARWEDGE_PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"barwedge";
static int* BARWEDGE_PROJECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Barwed html character entity reference model.
 *
 * Name: Barwed
 * Character: ⌆
 * Unicode code point: U+2306 (8966)
 * Description: perspective
 */
static wchar_t* BARWED_PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Barwed";
static int* BARWED_PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The doublebarwedge html character entity reference model.
 *
 * Name: doublebarwedge
 * Character: ⌆
 * Unicode code point: U+2306 (8966)
 * Description: perspective
 */
static wchar_t* DOUBLEBARWEDGE_PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"doublebarwedge";
static int* DOUBLEBARWEDGE_PERSPECTIVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftCeiling html character entity reference model.
 *
 * Name: LeftCeiling
 * Character: ⌈
 * Unicode code point: U+2308 (8968)
 * Description: left ceiling
 */
static wchar_t* LEFTCEILING_LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftCeiling";
static int* LEFTCEILING_LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lceil html character entity reference model.
 *
 * Name: lceil
 * Character: ⌈
 * Unicode code point: U+2308 (8968)
 * Description: left ceiling
 */
static wchar_t* LCEIL_LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lceil";
static int* LCEIL_LEFT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightCeiling html character entity reference model.
 *
 * Name: RightCeiling
 * Character: ⌉
 * Unicode code point: U+2309 (8969)
 * Description: right ceiling
 */
static wchar_t* RIGHTCEILING_RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightCeiling";
static int* RIGHTCEILING_RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rceil html character entity reference model.
 *
 * Name: rceil
 * Character: ⌉
 * Unicode code point: U+2309 (8969)
 * Description: right ceiling
 */
static wchar_t* RCEIL_RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rceil";
static int* RCEIL_RIGHT_CEILING_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftFloor html character entity reference model.
 *
 * Name: LeftFloor
 * Character: ⌊
 * Unicode code point: U+230a (8970)
 * Description: left floor
 */
static wchar_t* LEFTFLOOR_LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftFloor";
static int* LEFTFLOOR_LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lfloor html character entity reference model.
 *
 * Name: lfloor
 * Character: ⌊
 * Unicode code point: U+230a (8970)
 * Description: left floor
 */
static wchar_t* LFLOOR_LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfloor";
static int* LFLOOR_LEFT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightFloor html character entity reference model.
 *
 * Name: RightFloor
 * Character: ⌋
 * Unicode code point: U+230b (8971)
 * Description: right floor
 */
static wchar_t* RIGHTFLOOR_RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightFloor";
static int* RIGHTFLOOR_RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rfloor html character entity reference model.
 *
 * Name: rfloor
 * Character: ⌋
 * Unicode code point: U+230b (8971)
 * Description: right floor
 */
static wchar_t* RFLOOR_RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfloor";
static int* RFLOOR_RIGHT_FLOOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The drcrop html character entity reference model.
 *
 * Name: drcrop
 * Character: ⌌
 * Unicode code point: U+230c (8972)
 * Description: bottom right crop
 */
static wchar_t* DRCROP_BOTTOM_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"drcrop";
static int* DRCROP_BOTTOM_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dlcrop html character entity reference model.
 *
 * Name: dlcrop
 * Character: ⌍
 * Unicode code point: U+230d (8973)
 * Description: bottom left crop
 */
static wchar_t* DLCROP_BOTTOM_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dlcrop";
static int* DLCROP_BOTTOM_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The urcrop html character entity reference model.
 *
 * Name: urcrop
 * Character: ⌎
 * Unicode code point: U+230e (8974)
 * Description: top right crop
 */
static wchar_t* URCROP_TOP_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urcrop";
static int* URCROP_TOP_RIGHT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ulcrop html character entity reference model.
 *
 * Name: ulcrop
 * Character: ⌏
 * Unicode code point: U+230f (8975)
 * Description: top left crop
 */
static wchar_t* ULCROP_TOP_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ulcrop";
static int* ULCROP_TOP_LEFT_CROP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bnot html character entity reference model.
 *
 * Name: bnot
 * Character: ⌐
 * Unicode code point: U+2310 (8976)
 * Description: reversed not sign
 */
static wchar_t* BNOT_REVERSED_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bnot";
static int* BNOT_REVERSED_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The profline html character entity reference model.
 *
 * Name: profline
 * Character: ⌒
 * Unicode code point: U+2312 (8978)
 * Description: arc
 */
static wchar_t* PROFLINE_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profline";
static int* PROFLINE_ARC_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The profsurf html character entity reference model.
 *
 * Name: profsurf
 * Character: ⌓
 * Unicode code point: U+2313 (8979)
 * Description: segment
 */
static wchar_t* PROFSURF_SEGMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profsurf";
static int* PROFSURF_SEGMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The telrec html character entity reference model.
 *
 * Name: telrec
 * Character: ⌕
 * Unicode code point: U+2315 (8981)
 * Description: telephone recorder
 */
static wchar_t* TELREC_TELEPHONE_RECORDER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"telrec";
static int* TELREC_TELEPHONE_RECORDER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The target html character entity reference model.
 *
 * Name: target
 * Character: ⌖
 * Unicode code point: U+2316 (8982)
 * Description: position indicator
 */
static wchar_t* TARGET_POSITION_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"target";
static int* TARGET_POSITION_INDICATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ulcorn html character entity reference model.
 *
 * Name: ulcorn
 * Character: ⌜
 * Unicode code point: U+231c (8988)
 * Description: top left corner
 */
static wchar_t* ULCORN_TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ulcorn";
static int* ULCORN_TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ulcorner html character entity reference model.
 *
 * Name: ulcorner
 * Character: ⌜
 * Unicode code point: U+231c (8988)
 * Description: top left corner
 */
static wchar_t* ULCORNER_TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ulcorner";
static int* ULCORNER_TOP_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The urcorn html character entity reference model.
 *
 * Name: urcorn
 * Character: ⌝
 * Unicode code point: U+231d (8989)
 * Description: top right corner
 */
static wchar_t* URCORN_TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urcorn";
static int* URCORN_TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The urcorner html character entity reference model.
 *
 * Name: urcorner
 * Character: ⌝
 * Unicode code point: U+231d (8989)
 * Description: top right corner
 */
static wchar_t* URCORNER_TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urcorner";
static int* URCORNER_TOP_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dlcorn html character entity reference model.
 *
 * Name: dlcorn
 * Character: ⌞
 * Unicode code point: U+231e (8990)
 * Description: bottom left corner
 */
static wchar_t* DLCORN_BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dlcorn";
static int* DLCORN_BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The llcorner html character entity reference model.
 *
 * Name: llcorner
 * Character: ⌞
 * Unicode code point: U+231e (8990)
 * Description: bottom left corner
 */
static wchar_t* LLCORNER_BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"llcorner";
static int* LLCORNER_BOTTOM_LEFT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The drcorn html character entity reference model.
 *
 * Name: drcorn
 * Character: ⌟
 * Unicode code point: U+231f (8991)
 * Description: bottom right corner
 */
static wchar_t* DRCORN_BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"drcorn";
static int* DRCORN_BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrcorner html character entity reference model.
 *
 * Name: lrcorner
 * Character: ⌟
 * Unicode code point: U+231f (8991)
 * Description: bottom right corner
 */
static wchar_t* LRCORNER_BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrcorner";
static int* LRCORNER_BOTTOM_RIGHT_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The frown html character entity reference model.
 *
 * Name: frown
 * Character: ⌢
 * Unicode code point: U+2322 (8994)
 * Description: frown
 */
static wchar_t* FROWN_FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"frown";
static int* FROWN_FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sfrown html character entity reference model.
 *
 * Name: sfrown
 * Character: ⌢
 * Unicode code point: U+2322 (8994)
 * Description: frown
 */
static wchar_t* SFROWN_FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sfrown";
static int* SFROWN_FROWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smile html character entity reference model.
 *
 * Name: smile
 * Character: ⌣
 * Unicode code point: U+2323 (8995)
 * Description: smile
 */
static wchar_t* SMILE_SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smile";
static int* SMILE_SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ssmile html character entity reference model.
 *
 * Name: ssmile
 * Character: ⌣
 * Unicode code point: U+2323 (8995)
 * Description: smile
 */
static wchar_t* SSMILE_SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ssmile";
static int* SSMILE_SMILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cylcty html character entity reference model.
 *
 * Name: cylcty
 * Character: ⌭
 * Unicode code point: U+232d (9005)
 * Description: cylindricity
 */
static wchar_t* CYLCTY_CYLINDRICITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cylcty";
static int* CYLCTY_CYLINDRICITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The profalar html character entity reference model.
 *
 * Name: profalar
 * Character: ⌮
 * Unicode code point: U+232e (9006)
 * Description: all around-profile
 */
static wchar_t* PROFALAR_ALL_AROUND_PROFILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"profalar";
static int* PROFALAR_ALL_AROUND_PROFILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The topbot html character entity reference model.
 *
 * Name: topbot
 * Character: ⌶
 * Unicode code point: U+2336 (9014)
 * Description: apl functional symbol i-beam
 */
static wchar_t* TOPBOT_APL_FUNCTIONAL_SYMBOL_I_BEAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topbot";
static int* TOPBOT_APL_FUNCTIONAL_SYMBOL_I_BEAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ovbar html character entity reference model.
 *
 * Name: ovbar
 * Character: ⌽
 * Unicode code point: U+233d (9021)
 * Description: apl functional symbol circle stile
 */
static wchar_t* OVBAR_APL_FUNCTIONAL_SYMBOL_CIRCLE_STILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ovbar";
static int* OVBAR_APL_FUNCTIONAL_SYMBOL_CIRCLE_STILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The solbar html character entity reference model.
 *
 * Name: solbar
 * Character: ⌿
 * Unicode code point: U+233f (9023)
 * Description: apl functional symbol slash bar
 */
static wchar_t* SOLBAR_APL_FUNCTIONAL_SYMBOL_SLASH_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"solbar";
static int* SOLBAR_APL_FUNCTIONAL_SYMBOL_SLASH_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angzarr html character entity reference model.
 *
 * Name: angzarr
 * Character: ⍼
 * Unicode code point: U+237c (9084)
 * Description: right angle with downwards zigzag arrow
 */
static wchar_t* ANGZARR_RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angzarr";
static int* ANGZARR_RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lmoust html character entity reference model.
 *
 * Name: lmoust
 * Character: ⎰
 * Unicode code point: U+23b0 (9136)
 * Description: upper left or lower right curly bracket section
 */
static wchar_t* LMOUST_UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lmoust";
static int* LMOUST_UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lmoustache html character entity reference model.
 *
 * Name: lmoustache
 * Character: ⎰
 * Unicode code point: U+23b0 (9136)
 * Description: upper left or lower right curly bracket section
 */
static wchar_t* LMOUSTACHE_UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lmoustache";
static int* LMOUSTACHE_UPPER_LEFT_OR_LOWER_RIGHT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rmoust html character entity reference model.
 *
 * Name: rmoust
 * Character: ⎱
 * Unicode code point: U+23b1 (9137)
 * Description: upper right or lower left curly bracket section
 */
static wchar_t* RMOUST_UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rmoust";
static int* RMOUST_UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rmoustache html character entity reference model.
 *
 * Name: rmoustache
 * Character: ⎱
 * Unicode code point: U+23b1 (9137)
 * Description: upper right or lower left curly bracket section
 */
static wchar_t* RMOUSTACHE_UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rmoustache";
static int* RMOUSTACHE_UPPER_RIGHT_OR_LOWER_LEFT_CURLY_BRACKET_SECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OverBracket html character entity reference model.
 *
 * Name: OverBracket
 * Character: ⎴
 * Unicode code point: U+23b4 (9140)
 * Description: top square bracket
 */
static wchar_t* OVERBRACKET_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBracket";
static int* OVERBRACKET_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tbrk html character entity reference model.
 *
 * Name: tbrk
 * Character: ⎴
 * Unicode code point: U+23b4 (9140)
 * Description: top square bracket
 */
static wchar_t* TBRK_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tbrk";
static int* TBRK_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UnderBracket html character entity reference model.
 *
 * Name: UnderBracket
 * Character: ⎵
 * Unicode code point: U+23b5 (9141)
 * Description: bottom square bracket
 */
static wchar_t* UNDERBRACKET_BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBracket";
static int* UNDERBRACKET_BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bbrk html character entity reference model.
 *
 * Name: bbrk
 * Character: ⎵
 * Unicode code point: U+23b5 (9141)
 * Description: bottom square bracket
 */
static wchar_t* BBRK_BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bbrk";
static int* BBRK_BOTTOM_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bbrktbrk html character entity reference model.
 *
 * Name: bbrktbrk
 * Character: ⎶
 * Unicode code point: U+23b6 (9142)
 * Description: bottom square bracket over top square bracket
 */
static wchar_t* BBRKTBRK_BOTTOM_SQUARE_BRACKET_OVER_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bbrktbrk";
static int* BBRKTBRK_BOTTOM_SQUARE_BRACKET_OVER_TOP_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OverParenthesis html character entity reference model.
 *
 * Name: OverParenthesis
 * Character: ⏜
 * Unicode code point: U+23dc (9180)
 * Description: top parenthesis
 */
static wchar_t* OVERPARENTHESIS_TOP_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverParenthesis";
static int* OVERPARENTHESIS_TOP_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UnderParenthesis html character entity reference model.
 *
 * Name: UnderParenthesis
 * Character: ⏝
 * Unicode code point: U+23dd (9181)
 * Description: bottom parenthesis
 */
static wchar_t* UNDERPARENTHESIS_BOTTOM_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderParenthesis";
static int* UNDERPARENTHESIS_BOTTOM_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The OverBrace html character entity reference model.
 *
 * Name: OverBrace
 * Character: ⏞
 * Unicode code point: U+23de (9182)
 * Description: top curly bracket
 */
static wchar_t* OVERBRACE_TOP_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"OverBrace";
static int* OVERBRACE_TOP_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UnderBrace html character entity reference model.
 *
 * Name: UnderBrace
 * Character: ⏟
 * Unicode code point: U+23df (9183)
 * Description: bottom curly bracket
 */
static wchar_t* UNDERBRACE_BOTTOM_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UnderBrace";
static int* UNDERBRACE_BOTTOM_CURLY_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trpezium html character entity reference model.
 *
 * Name: trpezium
 * Character: ⏢
 * Unicode code point: U+23e2 (9186)
 * Description: white trapezium
 */
static wchar_t* TRPEZIUM_WHITE_TRAPEZIUM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trpezium";
static int* TRPEZIUM_WHITE_TRAPEZIUM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The elinters html character entity reference model.
 *
 * Name: elinters
 * Character: ⏧
 * Unicode code point: U+23e7 (9191)
 * Description: electrical intersection
 */
static wchar_t* ELINTERS_ELECTRICAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"elinters";
static int* ELINTERS_ELECTRICAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blank html character entity reference model.
 *
 * Name: blank
 * Character: ␣
 * Unicode code point: U+2423 (9251)
 * Description: open box
 */
static wchar_t* BLANK_OPEN_BOX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blank";
static int* BLANK_OPEN_BOX_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The circledS html character entity reference model.
 *
 * Name: circledS
 * Character: Ⓢ
 * Unicode code point: U+24c8 (9416)
 * Description: circled latin capital letter s
 */
static wchar_t* CIRCLEDS_CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"circledS";
static int* CIRCLEDS_CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oS html character entity reference model.
 *
 * Name: oS
 * Character: Ⓢ
 * Unicode code point: U+24c8 (9416)
 * Description: circled latin capital letter s
 */
static wchar_t* OS_CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oS";
static int* OS_CIRCLED_LATIN_CAPITAL_LETTER_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The HorizontalLine html character entity reference model.
 *
 * Name: HorizontalLine
 * Character: ─
 * Unicode code point: U+2500 (9472)
 * Description: box drawings light horizontal
 */
static wchar_t* HORIZONTALLINE_BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"HorizontalLine";
static int* HORIZONTALLINE_BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxh html character entity reference model.
 *
 * Name: boxh
 * Character: ─
 * Unicode code point: U+2500 (9472)
 * Description: box drawings light horizontal
 */
static wchar_t* BOXH_BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxh";
static int* BOXH_BOX_DRAWINGS_LIGHT_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxv html character entity reference model.
 *
 * Name: boxv
 * Character: │
 * Unicode code point: U+2502 (9474)
 * Description: box drawings light vertical
 */
static wchar_t* BOXV_BOX_DRAWINGS_LIGHT_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxv";
static int* BOXV_BOX_DRAWINGS_LIGHT_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxdr html character entity reference model.
 *
 * Name: boxdr
 * Character: ┌
 * Unicode code point: U+250c (9484)
 * Description: box drawings light down and right
 */
static wchar_t* BOXDR_BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdr";
static int* BOXDR_BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxdl html character entity reference model.
 *
 * Name: boxdl
 * Character: ┐
 * Unicode code point: U+2510 (9488)
 * Description: box drawings light down and left
 */
static wchar_t* BOXDL_BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdl";
static int* BOXDL_BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxur html character entity reference model.
 *
 * Name: boxur
 * Character: └
 * Unicode code point: U+2514 (9492)
 * Description: box drawings light up and right
 */
static wchar_t* BOXUR_BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxur";
static int* BOXUR_BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxul html character entity reference model.
 *
 * Name: boxul
 * Character: ┘
 * Unicode code point: U+2518 (9496)
 * Description: box drawings light up and left
 */
static wchar_t* BOXUL_BOX_DRAWINGS_LIGHT_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxul";
static int* BOXUL_BOX_DRAWINGS_LIGHT_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvr html character entity reference model.
 *
 * Name: boxvr
 * Character: ├
 * Unicode code point: U+251c (9500)
 * Description: box drawings light vertical and right
 */
static wchar_t* BOXVR_BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvr";
static int* BOXVR_BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvl html character entity reference model.
 *
 * Name: boxvl
 * Character: ┤
 * Unicode code point: U+2524 (9508)
 * Description: box drawings light vertical and left
 */
static wchar_t* BOXVL_BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvl";
static int* BOXVL_BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxhd html character entity reference model.
 *
 * Name: boxhd
 * Character: ┬
 * Unicode code point: U+252c (9516)
 * Description: box drawings light down and horizontal
 */
static wchar_t* BOXHD_BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhd";
static int* BOXHD_BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxhu html character entity reference model.
 *
 * Name: boxhu
 * Character: ┴
 * Unicode code point: U+2534 (9524)
 * Description: box drawings light up and horizontal
 */
static wchar_t* BOXHU_BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhu";
static int* BOXHU_BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvh html character entity reference model.
 *
 * Name: boxvh
 * Character: ┼
 * Unicode code point: U+253c (9532)
 * Description: box drawings light vertical and horizontal
 */
static wchar_t* BOXVH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvh";
static int* BOXVH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxH html character entity reference model.
 *
 * Name: boxH
 * Character: ═
 * Unicode code point: U+2550 (9552)
 * Description: box drawings double horizontal
 */
static wchar_t* BOXH_BOX_DRAWINGS_DOUBLE_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxH";
static int* BOXH_BOX_DRAWINGS_DOUBLE_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxV html character entity reference model.
 *
 * Name: boxV
 * Character: ║
 * Unicode code point: U+2551 (9553)
 * Description: box drawings double vertical
 */
static wchar_t* BOXV_BOX_DRAWINGS_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxV";
static int* BOXV_BOX_DRAWINGS_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxdR html character entity reference model.
 *
 * Name: boxdR
 * Character: ╒
 * Unicode code point: U+2552 (9554)
 * Description: box drawings down single and right double
 */
static wchar_t* BOXDR_BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdR";
static int* BOXDR_BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxDr html character entity reference model.
 *
 * Name: boxDr
 * Character: ╓
 * Unicode code point: U+2553 (9555)
 * Description: box drawings down double and right single
 */
static wchar_t* BOXDR_BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDr";
static int* BOXDR_BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxDR html character entity reference model.
 *
 * Name: boxDR
 * Character: ╔
 * Unicode code point: U+2554 (9556)
 * Description: box drawings double down and right
 */
static wchar_t* BOXDR_BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDR";
static int* BOXDR_BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxdL html character entity reference model.
 *
 * Name: boxdL
 * Character: ╕
 * Unicode code point: U+2555 (9557)
 * Description: box drawings down single and left double
 */
static wchar_t* BOXDL_BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxdL";
static int* BOXDL_BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxDl html character entity reference model.
 *
 * Name: boxDl
 * Character: ╖
 * Unicode code point: U+2556 (9558)
 * Description: box drawings down double and left single
 */
static wchar_t* BOXDL_BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDl";
static int* BOXDL_BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxDL html character entity reference model.
 *
 * Name: boxDL
 * Character: ╗
 * Unicode code point: U+2557 (9559)
 * Description: box drawings double down and left
 */
static wchar_t* BOXDL_BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxDL";
static int* BOXDL_BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxuR html character entity reference model.
 *
 * Name: boxuR
 * Character: ╘
 * Unicode code point: U+2558 (9560)
 * Description: box drawings up single and right double
 */
static wchar_t* BOXUR_BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxuR";
static int* BOXUR_BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxUr html character entity reference model.
 *
 * Name: boxUr
 * Character: ╙
 * Unicode code point: U+2559 (9561)
 * Description: box drawings up double and right single
 */
static wchar_t* BOXUR_BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUr";
static int* BOXUR_BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxUR html character entity reference model.
 *
 * Name: boxUR
 * Character: ╚
 * Unicode code point: U+255a (9562)
 * Description: box drawings double up and right
 */
static wchar_t* BOXUR_BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUR";
static int* BOXUR_BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxuL html character entity reference model.
 *
 * Name: boxuL
 * Character: ╛
 * Unicode code point: U+255b (9563)
 * Description: box drawings up single and left double
 */
static wchar_t* BOXUL_BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxuL";
static int* BOXUL_BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxUl html character entity reference model.
 *
 * Name: boxUl
 * Character: ╜
 * Unicode code point: U+255c (9564)
 * Description: box drawings up double and left single
 */
static wchar_t* BOXUL_BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUl";
static int* BOXUL_BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxUL html character entity reference model.
 *
 * Name: boxUL
 * Character: ╝
 * Unicode code point: U+255d (9565)
 * Description: box drawings double up and left
 */
static wchar_t* BOXUL_BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxUL";
static int* BOXUL_BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvR html character entity reference model.
 *
 * Name: boxvR
 * Character: ╞
 * Unicode code point: U+255e (9566)
 * Description: box drawings vertical single and right double
 */
static wchar_t* BOXVR_BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvR";
static int* BOXVR_BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVr html character entity reference model.
 *
 * Name: boxVr
 * Character: ╟
 * Unicode code point: U+255f (9567)
 * Description: box drawings vertical double and right single
 */
static wchar_t* BOXVR_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVr";
static int* BOXVR_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVR html character entity reference model.
 *
 * Name: boxVR
 * Character: ╠
 * Unicode code point: U+2560 (9568)
 * Description: box drawings double vertical and right
 */
static wchar_t* BOXVR_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVR";
static int* BOXVR_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvL html character entity reference model.
 *
 * Name: boxvL
 * Character: ╡
 * Unicode code point: U+2561 (9569)
 * Description: box drawings vertical single and left double
 */
static wchar_t* BOXVL_BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvL";
static int* BOXVL_BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVl html character entity reference model.
 *
 * Name: boxVl
 * Character: ╢
 * Unicode code point: U+2562 (9570)
 * Description: box drawings vertical double and left single
 */
static wchar_t* BOXVL_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVl";
static int* BOXVL_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVL html character entity reference model.
 *
 * Name: boxVL
 * Character: ╣
 * Unicode code point: U+2563 (9571)
 * Description: box drawings double vertical and left
 */
static wchar_t* BOXVL_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVL";
static int* BOXVL_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxHd html character entity reference model.
 *
 * Name: boxHd
 * Character: ╤
 * Unicode code point: U+2564 (9572)
 * Description: box drawings down single and horizontal double
 */
static wchar_t* BOXHD_BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHd";
static int* BOXHD_BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxhD html character entity reference model.
 *
 * Name: boxhD
 * Character: ╥
 * Unicode code point: U+2565 (9573)
 * Description: box drawings down double and horizontal single
 */
static wchar_t* BOXHD_BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhD";
static int* BOXHD_BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxHD html character entity reference model.
 *
 * Name: boxHD
 * Character: ╦
 * Unicode code point: U+2566 (9574)
 * Description: box drawings double down and horizontal
 */
static wchar_t* BOXHD_BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHD";
static int* BOXHD_BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxHu html character entity reference model.
 *
 * Name: boxHu
 * Character: ╧
 * Unicode code point: U+2567 (9575)
 * Description: box drawings up single and horizontal double
 */
static wchar_t* BOXHU_BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHu";
static int* BOXHU_BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxhU html character entity reference model.
 *
 * Name: boxhU
 * Character: ╨
 * Unicode code point: U+2568 (9576)
 * Description: box drawings up double and horizontal single
 */
static wchar_t* BOXHU_BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxhU";
static int* BOXHU_BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxHU html character entity reference model.
 *
 * Name: boxHU
 * Character: ╩
 * Unicode code point: U+2569 (9577)
 * Description: box drawings double up and horizontal
 */
static wchar_t* BOXHU_BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxHU";
static int* BOXHU_BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxvH html character entity reference model.
 *
 * Name: boxvH
 * Character: ╪
 * Unicode code point: U+256a (9578)
 * Description: box drawings vertical single and horizontal double
 */
static wchar_t* BOXVH_BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxvH";
static int* BOXVH_BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVh html character entity reference model.
 *
 * Name: boxVh
 * Character: ╫
 * Unicode code point: U+256b (9579)
 * Description: box drawings vertical double and horizontal single
 */
static wchar_t* BOXVH_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVh";
static int* BOXVH_BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxVH html character entity reference model.
 *
 * Name: boxVH
 * Character: ╬
 * Unicode code point: U+256c (9580)
 * Description: box drawings double vertical and horizontal
 */
static wchar_t* BOXVH_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxVH";
static int* BOXVH_BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uhblk html character entity reference model.
 *
 * Name: uhblk
 * Character: ▀
 * Unicode code point: U+2580 (9600)
 * Description: upper half block
 */
static wchar_t* UHBLK_UPPER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uhblk";
static int* UHBLK_UPPER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lhblk html character entity reference model.
 *
 * Name: lhblk
 * Character: ▄
 * Unicode code point: U+2584 (9604)
 * Description: lower half block
 */
static wchar_t* LHBLK_LOWER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lhblk";
static int* LHBLK_LOWER_HALF_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The block html character entity reference model.
 *
 * Name: block
 * Character: █
 * Unicode code point: U+2588 (9608)
 * Description: full block
 */
static wchar_t* BLOCK_FULL_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"block";
static int* BLOCK_FULL_BLOCK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blk14 html character entity reference model.
 *
 * Name: blk14
 * Character: ░
 * Unicode code point: U+2591 (9617)
 * Description: light shade
 */
static wchar_t* BLK14_LIGHT_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk14";
static int* BLK14_LIGHT_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blk12 html character entity reference model.
 *
 * Name: blk12
 * Character: ▒
 * Unicode code point: U+2592 (9618)
 * Description: medium shade
 */
static wchar_t* BLK12_MEDIUM_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk12";
static int* BLK12_MEDIUM_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blk34 html character entity reference model.
 *
 * Name: blk34
 * Character: ▓
 * Unicode code point: U+2593 (9619)
 * Description: dark shade
 */
static wchar_t* BLK34_DARK_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blk34";
static int* BLK34_DARK_SHADE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Square html character entity reference model.
 *
 * Name: Square
 * Character: □
 * Unicode code point: U+25a1 (9633)
 * Description: white square
 */
static wchar_t* CAMEL_SQUARE_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Square";
static int* CAMEL_SQUARE_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squ html character entity reference model.
 *
 * Name: squ
 * Character: □
 * Unicode code point: U+25a1 (9633)
 * Description: white square
 */
static wchar_t* SQU_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"squ";
static int* SQU_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The square html character entity reference model.
 *
 * Name: square
 * Character: □
 * Unicode code point: U+25a1 (9633)
 * Description: white square
 */
static wchar_t* SMALL_SQUARE_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"square";
static int* SMALL_SQUARE_WHITE_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The FilledVerySmallSquare html character entity reference model.
 *
 * Name: FilledVerySmallSquare
 * Character: ▪
 * Unicode code point: U+25aa (9642)
 * Description: black small square
 */
static wchar_t* FILLEDVERYSMALLSQUARE_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"FilledVerySmallSquare";
static int* FILLEDVERYSMALLSQUARE_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacksquare html character entity reference model.
 *
 * Name: blacksquare
 * Character: ▪
 * Unicode code point: U+25aa (9642)
 * Description: black small square
 */
static wchar_t* BLACKSQUARE_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacksquare";
static int* BLACKSQUARE_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squarf html character entity reference model.
 *
 * Name: squarf
 * Character: ▪
 * Unicode code point: U+25aa (9642)
 * Description: black small square
 */
static wchar_t* SQUARF_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"squarf";
static int* SQUARF_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The squf html character entity reference model.
 *
 * Name: squf
 * Character: ▪
 * Unicode code point: U+25aa (9642)
 * Description: black small square
 */
static wchar_t* SQUF_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"squf";
static int* SQUF_BLACK_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The EmptyVerySmallSquare html character entity reference model.
 *
 * Name: EmptyVerySmallSquare
 * Character: ▫
 * Unicode code point: U+25ab (9643)
 * Description: white small square
 */
static wchar_t* EMPTYVERYSMALLSQUARE_WHITE_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EmptyVerySmallSquare";
static int* EMPTYVERYSMALLSQUARE_WHITE_SMALL_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rect html character entity reference model.
 *
 * Name: rect
 * Character: ▭
 * Unicode code point: U+25ad (9645)
 * Description: white rectangle
 */
static wchar_t* RECT_WHITE_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rect";
static int* RECT_WHITE_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The marker html character entity reference model.
 *
 * Name: marker
 * Character: ▮
 * Unicode code point: U+25ae (9646)
 * Description: black vertical rectangle
 */
static wchar_t* MARKER_BLACK_VERTICAL_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"marker";
static int* MARKER_BLACK_VERTICAL_RECTANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fltns html character entity reference model.
 *
 * Name: fltns
 * Character: ▱
 * Unicode code point: U+25b1 (9649)
 * Description: white parallelogram
 */
static wchar_t* FLTNS_WHITE_PARALLELOGRAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fltns";
static int* FLTNS_WHITE_PARALLELOGRAM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigtriangleup html character entity reference model.
 *
 * Name: bigtriangleup
 * Character: △
 * Unicode code point: U+25b3 (9651)
 * Description: white up-pointing triangle
 */
static wchar_t* BIGTRIANGLEUP_WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigtriangleup";
static int* BIGTRIANGLEUP_WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xutri html character entity reference model.
 *
 * Name: xutri
 * Character: △
 * Unicode code point: U+25b3 (9651)
 * Description: white up-pointing triangle
 */
static wchar_t* XUTRI_WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xutri";
static int* XUTRI_WHITE_UP_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacktriangle html character entity reference model.
 *
 * Name: blacktriangle
 * Character: ▴
 * Unicode code point: U+25b4 (9652)
 * Description: black up-pointing small triangle
 */
static wchar_t* BLACKTRIANGLE_BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangle";
static int* BLACKTRIANGLE_BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The utrif html character entity reference model.
 *
 * Name: utrif
 * Character: ▴
 * Unicode code point: U+25b4 (9652)
 * Description: black up-pointing small triangle
 */
static wchar_t* UTRIF_BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utrif";
static int* UTRIF_BLACK_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangle html character entity reference model.
 *
 * Name: triangle
 * Character: ▵
 * Unicode code point: U+25b5 (9653)
 * Description: white up-pointing small triangle
 */
static wchar_t* TRIANGLE_WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangle";
static int* TRIANGLE_WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The utri html character entity reference model.
 *
 * Name: utri
 * Character: ▵
 * Unicode code point: U+25b5 (9653)
 * Description: white up-pointing small triangle
 */
static wchar_t* UTRI_WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"utri";
static int* UTRI_WHITE_UP_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacktriangleright html character entity reference model.
 *
 * Name: blacktriangleright
 * Character: ▸
 * Unicode code point: U+25b8 (9656)
 * Description: black right-pointing small triangle
 */
static wchar_t* BLACKTRIANGLERIGHT_BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangleright";
static int* BLACKTRIANGLERIGHT_BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rtrif html character entity reference model.
 *
 * Name: rtrif
 * Character: ▸
 * Unicode code point: U+25b8 (9656)
 * Description: black right-pointing small triangle
 */
static wchar_t* RTRIF_BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtrif";
static int* RTRIF_BLACK_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rtri html character entity reference model.
 *
 * Name: rtri
 * Character: ▹
 * Unicode code point: U+25b9 (9657)
 * Description: white right-pointing small triangle
 */
static wchar_t* RTRI_WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtri";
static int* RTRI_WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangleright html character entity reference model.
 *
 * Name: triangleright
 * Character: ▹
 * Unicode code point: U+25b9 (9657)
 * Description: white right-pointing small triangle
 */
static wchar_t* TRIANGLERIGHT_WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangleright";
static int* TRIANGLERIGHT_WHITE_RIGHT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigtriangledown html character entity reference model.
 *
 * Name: bigtriangledown
 * Character: ▽
 * Unicode code point: U+25bd (9661)
 * Description: white down-pointing triangle
 */
static wchar_t* BIGTRIANGLEDOWN_WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigtriangledown";
static int* BIGTRIANGLEDOWN_WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xdtri html character entity reference model.
 *
 * Name: xdtri
 * Character: ▽
 * Unicode code point: U+25bd (9661)
 * Description: white down-pointing triangle
 */
static wchar_t* XDTRI_WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xdtri";
static int* XDTRI_WHITE_DOWN_POINTING_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacktriangledown html character entity reference model.
 *
 * Name: blacktriangledown
 * Character: ▾
 * Unicode code point: U+25be (9662)
 * Description: black down-pointing small triangle
 */
static wchar_t* BLACKTRIANGLEDOWN_BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangledown";
static int* BLACKTRIANGLEDOWN_BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dtrif html character entity reference model.
 *
 * Name: dtrif
 * Character: ▾
 * Unicode code point: U+25be (9662)
 * Description: black down-pointing small triangle
 */
static wchar_t* DTRIF_BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dtrif";
static int* DTRIF_BLACK_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dtri html character entity reference model.
 *
 * Name: dtri
 * Character: ▿
 * Unicode code point: U+25bf (9663)
 * Description: white down-pointing small triangle
 */
static wchar_t* DTRI_WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dtri";
static int* DTRI_WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangledown html character entity reference model.
 *
 * Name: triangledown
 * Character: ▿
 * Unicode code point: U+25bf (9663)
 * Description: white down-pointing small triangle
 */
static wchar_t* TRIANGLEDOWN_WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangledown";
static int* TRIANGLEDOWN_WHITE_DOWN_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacktriangleleft html character entity reference model.
 *
 * Name: blacktriangleleft
 * Character: ◂
 * Unicode code point: U+25c2 (9666)
 * Description: black left-pointing small triangle
 */
static wchar_t* BLACKTRIANGLELEFT_BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacktriangleleft";
static int* BLACKTRIANGLELEFT_BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltrif html character entity reference model.
 *
 * Name: ltrif
 * Character: ◂
 * Unicode code point: U+25c2 (9666)
 * Description: black left-pointing small triangle
 */
static wchar_t* LTRIF_BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltrif";
static int* LTRIF_BLACK_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltri html character entity reference model.
 *
 * Name: ltri
 * Character: ◃
 * Unicode code point: U+25c3 (9667)
 * Description: white left-pointing small triangle
 */
static wchar_t* LTRI_WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltri";
static int* LTRI_WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triangleleft html character entity reference model.
 *
 * Name: triangleleft
 * Character: ◃
 * Unicode code point: U+25c3 (9667)
 * Description: white left-pointing small triangle
 */
static wchar_t* TRIANGLELEFT_WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triangleleft";
static int* TRIANGLELEFT_WHITE_LEFT_POINTING_SMALL_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The loz html character entity reference model.
 *
 * Name: loz
 * Character: ◊
 * Unicode code point: U+25ca (9674)
 * Description: lozenge
 */
static wchar_t* LOZ_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loz";
static int* LOZ_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lozenge html character entity reference model.
 *
 * Name: lozenge
 * Character: ◊
 * Unicode code point: U+25ca (9674)
 * Description: lozenge
 */
static wchar_t* LOZENGE_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lozenge";
static int* LOZENGE_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cir html character entity reference model.
 *
 * Name: cir
 * Character: ○
 * Unicode code point: U+25cb (9675)
 * Description: white circle
 */
static wchar_t* CIR_WHITE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cir";
static int* CIR_WHITE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tridot html character entity reference model.
 *
 * Name: tridot
 * Character: ◬
 * Unicode code point: U+25ec (9708)
 * Description: white up-pointing triangle with dot
 */
static wchar_t* TRIDOT_WHITE_UP_POINTING_TRIANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tridot";
static int* TRIDOT_WHITE_UP_POINTING_TRIANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigcirc html character entity reference model.
 *
 * Name: bigcirc
 * Character: ◯
 * Unicode code point: U+25ef (9711)
 * Description: large circle
 */
static wchar_t* BIGCIRC_LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigcirc";
static int* BIGCIRC_LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xcirc html character entity reference model.
 *
 * Name: xcirc
 * Character: ◯
 * Unicode code point: U+25ef (9711)
 * Description: large circle
 */
static wchar_t* XCIRC_LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xcirc";
static int* XCIRC_LARGE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ultri html character entity reference model.
 *
 * Name: ultri
 * Character: ◸
 * Unicode code point: U+25f8 (9720)
 * Description: upper left triangle
 */
static wchar_t* ULTRI_UPPER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ultri";
static int* ULTRI_UPPER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The urtri html character entity reference model.
 *
 * Name: urtri
 * Character: ◹
 * Unicode code point: U+25f9 (9721)
 * Description: upper right triangle
 */
static wchar_t* URTRI_UPPER_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"urtri";
static int* URTRI_UPPER_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lltri html character entity reference model.
 *
 * Name: lltri
 * Character: ◺
 * Unicode code point: U+25fa (9722)
 * Description: lower left triangle
 */
static wchar_t* LLTRI_LOWER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lltri";
static int* LLTRI_LOWER_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The EmptySmallSquare html character entity reference model.
 *
 * Name: EmptySmallSquare
 * Character: ◻
 * Unicode code point: U+25fb (9723)
 * Description: white medium square
 */
static wchar_t* EMPTYSMALLSQUARE_WHITE_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"EmptySmallSquare";
static int* EMPTYSMALLSQUARE_WHITE_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The FilledSmallSquare html character entity reference model.
 *
 * Name: FilledSmallSquare
 * Character: ◼
 * Unicode code point: U+25fc (9724)
 * Description: black medium square
 */
static wchar_t* FILLEDSMALLSQUARE_BLACK_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"FilledSmallSquare";
static int* FILLEDSMALLSQUARE_BLACK_MEDIUM_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigstar html character entity reference model.
 *
 * Name: bigstar
 * Character: ★
 * Unicode code point: U+2605 (9733)
 * Description: black star
 */
static wchar_t* BIGSTAR_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigstar";
static int* BIGSTAR_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The starf html character entity reference model.
 *
 * Name: starf
 * Character: ★
 * Unicode code point: U+2605 (9733)
 * Description: black star
 */
static wchar_t* STARF_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"starf";
static int* STARF_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The star html character entity reference model.
 *
 * Name: star
 * Character: ☆
 * Unicode code point: U+2606 (9734)
 * Description: white star
 */
static wchar_t* STAR_WHITE_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"star";
static int* STAR_WHITE_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The phone html character entity reference model.
 *
 * Name: phone
 * Character: ☎
 * Unicode code point: U+260e (9742)
 * Description: black telephone
 */
static wchar_t* PHONE_BLACK_TELEPHONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"phone";
static int* PHONE_BLACK_TELEPHONE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The female html character entity reference model.
 *
 * Name: female
 * Character: ♀
 * Unicode code point: U+2640 (9792)
 * Description: female sign
 */
static wchar_t* FEMALE_FEMALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"female";
static int* FEMALE_FEMALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The male html character entity reference model.
 *
 * Name: male
 * Character: ♂
 * Unicode code point: U+2642 (9794)
 * Description: male sign
 */
static wchar_t* MALE_MALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"male";
static int* MALE_MALE_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The spades html character entity reference model.
 *
 * Name: spades
 * Character: ♠
 * Unicode code point: U+2660 (9824)
 * Description: black spade suit
 */
static wchar_t* SPADES_BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"spades";
static int* SPADES_BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The spadesuit html character entity reference model.
 *
 * Name: spadesuit
 * Character: ♠
 * Unicode code point: U+2660 (9824)
 * Description: black spade suit
 */
static wchar_t* SPADESUIT_BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"spadesuit";
static int* SPADESUIT_BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clubs html character entity reference model.
 *
 * Name: clubs
 * Character: ♣
 * Unicode code point: U+2663 (9827)
 * Description: black club suit
 */
static wchar_t* CLUBS_BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"clubs";
static int* CLUBS_BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The clubsuit html character entity reference model.
 *
 * Name: clubsuit
 * Character: ♣
 * Unicode code point: U+2663 (9827)
 * Description: black club suit
 */
static wchar_t* CLUBSUIT_BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"clubsuit";
static int* CLUBSUIT_BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hearts html character entity reference model.
 *
 * Name: hearts
 * Character: ♥
 * Unicode code point: U+2665 (9829)
 * Description: black heart suit
 */
static wchar_t* HEARTS_BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hearts";
static int* HEARTS_BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The heartsuit html character entity reference model.
 *
 * Name: heartsuit
 * Character: ♥
 * Unicode code point: U+2665 (9829)
 * Description: black heart suit
 */
static wchar_t* HEARTSUIT_BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"heartsuit";
static int* HEARTSUIT_BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diamondsuit html character entity reference model.
 *
 * Name: diamondsuit
 * Character: ♦
 * Unicode code point: U+2666 (9830)
 * Description: black diamond suit
 */
static wchar_t* DIAMONDSUIT_BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diamondsuit";
static int* DIAMONDSUIT_BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The diams html character entity reference model.
 *
 * Name: diams
 * Character: ♦
 * Unicode code point: U+2666 (9830)
 * Description: black diamond suit
 */
static wchar_t* DIAMS_BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"diams";
static int* DIAMS_BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sung html character entity reference model.
 *
 * Name: sung
 * Character: ♪
 * Unicode code point: U+266a (9834)
 * Description: eighth note
 */
static wchar_t* SUNG_EIGHTH_NOTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sung";
static int* SUNG_EIGHTH_NOTE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flat html character entity reference model.
 *
 * Name: flat
 * Character: ♭
 * Unicode code point: U+266d (9837)
 * Description: music flat sign
 */
static wchar_t* FLAT_MUSIC_FLAT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"flat";
static int* FLAT_MUSIC_FLAT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The natur html character entity reference model.
 *
 * Name: natur
 * Character: ♮
 * Unicode code point: U+266e (9838)
 * Description: music natural sign
 */
static wchar_t* NATUR_MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"natur";
static int* NATUR_MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The natural html character entity reference model.
 *
 * Name: natural
 * Character: ♮
 * Unicode code point: U+266e (9838)
 * Description: music natural sign
 */
static wchar_t* NATURAL_MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"natural";
static int* NATURAL_MUSIC_NATURAL_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sharp html character entity reference model.
 *
 * Name: sharp
 * Character: ♯
 * Unicode code point: U+266f (9839)
 * Description: music sharp sign
 */
static wchar_t* SHARP_MUSIC_SHARP_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sharp";
static int* SHARP_MUSIC_SHARP_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check html character entity reference model.
 *
 * Name: check
 * Character: ✓
 * Unicode code point: U+2713 (10003)
 * Description: check mark
 */
static wchar_t* CHECK_CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"check";
static int* CHECK_CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The checkmark html character entity reference model.
 *
 * Name: checkmark
 * Character: ✓
 * Unicode code point: U+2713 (10003)
 * Description: check mark
 */
static wchar_t* CHECKMARK_CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"checkmark";
static int* CHECKMARK_CHECK_MARK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cross html character entity reference model.
 *
 * Name: cross
 * Character: ✗
 * Unicode code point: U+2717 (10007)
 * Description: ballot x
 */
static wchar_t* CROSS_BALLOT_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cross";
static int* CROSS_BALLOT_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The malt html character entity reference model.
 *
 * Name: malt
 * Character: ✠
 * Unicode code point: U+2720 (10016)
 * Description: maltese cross
 */
static wchar_t* MALT_MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"malt";
static int* MALT_MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maltese html character entity reference model.
 *
 * Name: maltese
 * Character: ✠
 * Unicode code point: U+2720 (10016)
 * Description: maltese cross
 */
static wchar_t* MALTESE_MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"maltese";
static int* MALTESE_MALTESE_CROSS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sext html character entity reference model.
 *
 * Name: sext
 * Character: ✶
 * Unicode code point: U+2736 (10038)
 * Description: six pointed black star
 */
static wchar_t* SEXT_SIX_POINTED_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sext";
static int* SEXT_SIX_POINTED_BLACK_STAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The VerticalSeparator html character entity reference model.
 *
 * Name: VerticalSeparator
 * Character: ❘
 * Unicode code point: U+2758 (10072)
 * Description: light vertical bar
 */
static wchar_t* VERTICALSEPARATOR_LIGHT_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"VerticalSeparator";
static int* VERTICALSEPARATOR_LIGHT_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbbrk html character entity reference model.
 *
 * Name: lbbrk
 * Character: ❲
 * Unicode code point: U+2772 (10098)
 * Description: light left tortoise shell bracket ornament
 */
static wchar_t* LBBRK_LIGHT_LEFT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbbrk";
static int* LBBRK_LIGHT_LEFT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbbrk html character entity reference model.
 *
 * Name: rbbrk
 * Character: ❳
 * Unicode code point: U+2773 (10099)
 * Description: light right tortoise shell bracket ornament
 */
static wchar_t* RBBRK_LIGHT_RIGHT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbbrk";
static int* RBBRK_LIGHT_RIGHT_TORTOISE_SHELL_BRACKET_ORNAMENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsolhsub html character entity reference model.
 *
 * Name: bsolhsub
 * Character: ⟈
 * Unicode code point: U+27c8 (10184)
 * Description: reverse solidus preceding subset
 */
static wchar_t* BSOLHSUB_REVERSE_SOLIDUS_PRECEDING_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsolhsub";
static int* BSOLHSUB_REVERSE_SOLIDUS_PRECEDING_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The suphsol html character entity reference model.
 *
 * Name: suphsol
 * Character: ⟉
 * Unicode code point: U+27c9 (10185)
 * Description: superset preceding solidus
 */
static wchar_t* SUPHSOL_SUPERSET_PRECEDING_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suphsol";
static int* SUPHSOL_SUPERSET_PRECEDING_SOLIDUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftDoubleBracket html character entity reference model.
 *
 * Name: LeftDoubleBracket
 * Character: ⟦
 * Unicode code point: U+27e6 (10214)
 * Description: mathematical left white square bracket
 */
static wchar_t* LEFTDOUBLEBRACKET_MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDoubleBracket";
static int* LEFTDOUBLEBRACKET_MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lobrk html character entity reference model.
 *
 * Name: lobrk
 * Character: ⟦
 * Unicode code point: U+27e6 (10214)
 * Description: mathematical left white square bracket
 */
static wchar_t* LOBRK_MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lobrk";
static int* LOBRK_MATHEMATICAL_LEFT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightDoubleBracket html character entity reference model.
 *
 * Name: RightDoubleBracket
 * Character: ⟧
 * Unicode code point: U+27e7 (10215)
 * Description: mathematical right white square bracket
 */
static wchar_t* RIGHTDOUBLEBRACKET_MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDoubleBracket";
static int* RIGHTDOUBLEBRACKET_MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The robrk html character entity reference model.
 *
 * Name: robrk
 * Character: ⟧
 * Unicode code point: U+27e7 (10215)
 * Description: mathematical right white square bracket
 */
static wchar_t* ROBRK_MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"robrk";
static int* ROBRK_MATHEMATICAL_RIGHT_WHITE_SQUARE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftAngleBracket html character entity reference model.
 *
 * Name: LeftAngleBracket
 * Character: ⟨
 * Unicode code point: U+27e8 (10216)
 * Description: mathematical left angle bracket
 */
static wchar_t* LEFTANGLEBRACKET_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftAngleBracket";
static int* LEFTANGLEBRACKET_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lang html character entity reference model.
 *
 * Name: lang
 * Character: ⟨
 * Unicode code point: U+27e8 (10216)
 * Description: mathematical left angle bracket
 */
static wchar_t* LANG_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lang";
static int* LANG_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The langle html character entity reference model.
 *
 * Name: langle
 * Character: ⟨
 * Unicode code point: U+27e8 (10216)
 * Description: mathematical left angle bracket
 */
static wchar_t* LANGLE_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"langle";
static int* LANGLE_MATHEMATICAL_LEFT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightAngleBracket html character entity reference model.
 *
 * Name: RightAngleBracket
 * Character: ⟩
 * Unicode code point: U+27e9 (10217)
 * Description: mathematical right angle bracket
 */
static wchar_t* RIGHTANGLEBRACKET_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightAngleBracket";
static int* RIGHTANGLEBRACKET_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rang html character entity reference model.
 *
 * Name: rang
 * Character: ⟩
 * Unicode code point: U+27e9 (10217)
 * Description: mathematical right angle bracket
 */
static wchar_t* RANG_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rang";
static int* RANG_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rangle html character entity reference model.
 *
 * Name: rangle
 * Character: ⟩
 * Unicode code point: U+27e9 (10217)
 * Description: mathematical right angle bracket
 */
static wchar_t* RANGLE_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rangle";
static int* RANGLE_MATHEMATICAL_RIGHT_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lang html character entity reference model.
 *
 * Name: Lang
 * Character: ⟪
 * Unicode code point: U+27ea (10218)
 * Description: mathematical left double angle bracket
 */
static wchar_t* LANG_MATHEMATICAL_LEFT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lang";
static int* LANG_MATHEMATICAL_LEFT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rang html character entity reference model.
 *
 * Name: Rang
 * Character: ⟫
 * Unicode code point: U+27eb (10219)
 * Description: mathematical right double angle bracket
 */
static wchar_t* RANG_MATHEMATICAL_RIGHT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rang";
static int* RANG_MATHEMATICAL_RIGHT_DOUBLE_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The loang html character entity reference model.
 *
 * Name: loang
 * Character: ⟬
 * Unicode code point: U+27ec (10220)
 * Description: mathematical left white tortoise shell bracket
 */
static wchar_t* LOANG_MATHEMATICAL_LEFT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loang";
static int* LOANG_MATHEMATICAL_LEFT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The roang html character entity reference model.
 *
 * Name: roang
 * Character: ⟭
 * Unicode code point: U+27ed (10221)
 * Description: mathematical right white tortoise shell bracket
 */
static wchar_t* ROANG_MATHEMATICAL_RIGHT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roang";
static int* ROANG_MATHEMATICAL_RIGHT_WHITE_TORTOISE_SHELL_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LongLeftArrow html character entity reference model.
 *
 * Name: LongLeftArrow
 * Character: ⟵
 * Unicode code point: U+27f5 (10229)
 * Description: long leftwards arrow
 */
static wchar_t* CAMEL_LONGLEFTARROW_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongLeftArrow";
static int* CAMEL_LONGLEFTARROW_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The longleftarrow html character entity reference model.
 *
 * Name: longleftarrow
 * Character: ⟵
 * Unicode code point: U+27f5 (10229)
 * Description: long leftwards arrow
 */
static wchar_t* SMALL_LONGLEFTARROW_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"longleftarrow";
static int* SMALL_LONGLEFTARROW_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xlarr html character entity reference model.
 *
 * Name: xlarr
 * Character: ⟵
 * Unicode code point: U+27f5 (10229)
 * Description: long leftwards arrow
 */
static wchar_t* XLARR_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xlarr";
static int* XLARR_LONG_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LongRightArrow html character entity reference model.
 *
 * Name: LongRightArrow
 * Character: ⟶
 * Unicode code point: U+27f6 (10230)
 * Description: long rightwards arrow
 */
static wchar_t* CAMEL_LONGRIGHTARROW_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongRightArrow";
static int* CAMEL_LONGRIGHTARROW_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The longrightarrow html character entity reference model.
 *
 * Name: longrightarrow
 * Character: ⟶
 * Unicode code point: U+27f6 (10230)
 * Description: long rightwards arrow
 */
static wchar_t* SMALL_LONGRIGHTARROW_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"longrightarrow";
static int* SMALL_LONGRIGHTARROW_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xrarr html character entity reference model.
 *
 * Name: xrarr
 * Character: ⟶
 * Unicode code point: U+27f6 (10230)
 * Description: long rightwards arrow
 */
static wchar_t* XRARR_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xrarr";
static int* XRARR_LONG_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LongLeftRightArrow html character entity reference model.
 *
 * Name: LongLeftRightArrow
 * Character: ⟷
 * Unicode code point: U+27f7 (10231)
 * Description: long left right arrow
 */
static wchar_t* CAMEL_LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LongLeftRightArrow";
static int* CAMEL_LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The longleftrightarrow html character entity reference model.
 *
 * Name: longleftrightarrow
 * Character: ⟷
 * Unicode code point: U+27f7 (10231)
 * Description: long left right arrow
 */
static wchar_t* SMALL_LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"longleftrightarrow";
static int* SMALL_LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xharr html character entity reference model.
 *
 * Name: xharr
 * Character: ⟷
 * Unicode code point: U+27f7 (10231)
 * Description: long left right arrow
 */
static wchar_t* XHARR_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xharr";
static int* XHARR_LONG_LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLongLeftArrow html character entity reference model.
 *
 * Name: DoubleLongLeftArrow
 * Character: ⟸
 * Unicode code point: U+27f8 (10232)
 * Description: long leftwards double arrow
 */
static wchar_t* DOUBLELONGLEFTARROW_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongLeftArrow";
static int* DOUBLELONGLEFTARROW_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Longleftarrow html character entity reference model.
 *
 * Name: Longleftarrow
 * Character: ⟸
 * Unicode code point: U+27f8 (10232)
 * Description: long leftwards double arrow
 */
static wchar_t* LONGLEFTARROW_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Longleftarrow";
static int* LONGLEFTARROW_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xlArr html character entity reference model.
 *
 * Name: xlArr
 * Character: ⟸
 * Unicode code point: U+27f8 (10232)
 * Description: long leftwards double arrow
 */
static wchar_t* XLARR_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xlArr";
static int* XLARR_LONG_LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLongRightArrow html character entity reference model.
 *
 * Name: DoubleLongRightArrow
 * Character: ⟹
 * Unicode code point: U+27f9 (10233)
 * Description: long rightwards double arrow
 */
static wchar_t* DOUBLELONGRIGHTARROW_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongRightArrow";
static int* DOUBLELONGRIGHTARROW_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Longrightarrow html character entity reference model.
 *
 * Name: Longrightarrow
 * Character: ⟹
 * Unicode code point: U+27f9 (10233)
 * Description: long rightwards double arrow
 */
static wchar_t* LONGRIGHTARROW_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Longrightarrow";
static int* LONGRIGHTARROW_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xrArr html character entity reference model.
 *
 * Name: xrArr
 * Character: ⟹
 * Unicode code point: U+27f9 (10233)
 * Description: long rightwards double arrow
 */
static wchar_t* XRARR_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xrArr";
static int* XRARR_LONG_RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLongLeftRightArrow html character entity reference model.
 *
 * Name: DoubleLongLeftRightArrow
 * Character: ⟺
 * Unicode code point: U+27fa (10234)
 * Description: long left right double arrow
 */
static wchar_t* DOUBLELONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLongLeftRightArrow";
static int* DOUBLELONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Longleftrightarrow html character entity reference model.
 *
 * Name: Longleftrightarrow
 * Character: ⟺
 * Unicode code point: U+27fa (10234)
 * Description: long left right double arrow
 */
static wchar_t* LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Longleftrightarrow";
static int* LONGLEFTRIGHTARROW_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xhArr html character entity reference model.
 *
 * Name: xhArr
 * Character: ⟺
 * Unicode code point: U+27fa (10234)
 * Description: long left right double arrow
 */
static wchar_t* XHARR_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xhArr";
static int* XHARR_LONG_LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The longmapsto html character entity reference model.
 *
 * Name: longmapsto
 * Character: ⟼
 * Unicode code point: U+27fc (10236)
 * Description: long rightwards arrow from bar
 */
static wchar_t* LONGMAPSTO_LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"longmapsto";
static int* LONGMAPSTO_LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xmap html character entity reference model.
 *
 * Name: xmap
 * Character: ⟼
 * Unicode code point: U+27fc (10236)
 * Description: long rightwards arrow from bar
 */
static wchar_t* XMAP_LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xmap";
static int* XMAP_LONG_RIGHTWARDS_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dzigrarr html character entity reference model.
 *
 * Name: dzigrarr
 * Character: ⟿
 * Unicode code point: U+27ff (10239)
 * Description: long rightwards squiggle arrow
 */
static wchar_t* DZIGRARR_LONG_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dzigrarr";
static int* DZIGRARR_LONG_RIGHTWARDS_SQUIGGLE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvlArr html character entity reference model.
 *
 * Name: nvlArr
 * Character: ⤂
 * Unicode code point: U+2902 (10498)
 * Description: leftwards double arrow with vertical stroke
 */
static wchar_t* NVLARR_LEFTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvlArr";
static int* NVLARR_LEFTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvrArr html character entity reference model.
 *
 * Name: nvrArr
 * Character: ⤃
 * Unicode code point: U+2903 (10499)
 * Description: rightwards double arrow with vertical stroke
 */
static wchar_t* NVRARR_RIGHTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvrArr";
static int* NVRARR_RIGHTWARDS_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvHarr html character entity reference model.
 *
 * Name: nvHarr
 * Character: ⤄
 * Unicode code point: U+2904 (10500)
 * Description: left right double arrow with vertical stroke
 */
static wchar_t* NVHARR_LEFT_RIGHT_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvHarr";
static int* NVHARR_LEFT_RIGHT_DOUBLE_ARROW_WITH_VERTICAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Map html character entity reference model.
 *
 * Name: Map
 * Character: ⤅
 * Unicode code point: U+2905 (10501)
 * Description: rightwards two-headed arrow from bar
 */
static wchar_t* MAP_RIGHTWARDS_TWO_HEADED_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Map";
static int* MAP_RIGHTWARDS_TWO_HEADED_ARROW_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbarr html character entity reference model.
 *
 * Name: lbarr
 * Character: ⤌
 * Unicode code point: U+290c (10508)
 * Description: leftwards double dash arrow
 */
static wchar_t* LBARR_LEFTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbarr";
static int* LBARR_LEFTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bkarow html character entity reference model.
 *
 * Name: bkarow
 * Character: ⤍
 * Unicode code point: U+290d (10509)
 * Description: rightwards double dash arrow
 */
static wchar_t* BKAROW_RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bkarow";
static int* BKAROW_RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbarr html character entity reference model.
 *
 * Name: rbarr
 * Character: ⤍
 * Unicode code point: U+290d (10509)
 * Description: rightwards double dash arrow
 */
static wchar_t* RBARR_RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbarr";
static int* RBARR_RIGHTWARDS_DOUBLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lBarr html character entity reference model.
 *
 * Name: lBarr
 * Character: ⤎
 * Unicode code point: U+290e (10510)
 * Description: leftwards triple dash arrow
 */
static wchar_t* LBARR_LEFTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lBarr";
static int* LBARR_LEFTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dbkarow html character entity reference model.
 *
 * Name: dbkarow
 * Character: ⤏
 * Unicode code point: U+290f (10511)
 * Description: rightwards triple dash arrow
 */
static wchar_t* DBKAROW_RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dbkarow";
static int* DBKAROW_RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rBarr html character entity reference model.
 *
 * Name: rBarr
 * Character: ⤏
 * Unicode code point: U+290f (10511)
 * Description: rightwards triple dash arrow
 */
static wchar_t* RBARR_RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rBarr";
static int* RBARR_RIGHTWARDS_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RBarr html character entity reference model.
 *
 * Name: RBarr
 * Character: ⤐
 * Unicode code point: U+2910 (10512)
 * Description: rightwards two-headed triple dash arrow
 */
static wchar_t* RBARR_RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RBarr";
static int* RBARR_RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The drbkarow html character entity reference model.
 *
 * Name: drbkarow
 * Character: ⤐
 * Unicode code point: U+2910 (10512)
 * Description: rightwards two-headed triple dash arrow
 */
static wchar_t* DRBKAROW_RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"drbkarow";
static int* DRBKAROW_RIGHTWARDS_TWO_HEADED_TRIPLE_DASH_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DDotrahd html character entity reference model.
 *
 * Name: DDotrahd
 * Character: ⤑
 * Unicode code point: U+2911 (10513)
 * Description: rightwards arrow with dotted stem
 */
static wchar_t* DDOTRAHD_RIGHTWARDS_ARROW_WITH_DOTTED_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DDotrahd";
static int* DDOTRAHD_RIGHTWARDS_ARROW_WITH_DOTTED_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpArrowBar html character entity reference model.
 *
 * Name: UpArrowBar
 * Character: ⤒
 * Unicode code point: U+2912 (10514)
 * Description: upwards arrow to bar
 */
static wchar_t* UPARROWBAR_UPWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpArrowBar";
static int* UPARROWBAR_UPWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownArrowBar html character entity reference model.
 *
 * Name: DownArrowBar
 * Character: ⤓
 * Unicode code point: U+2913 (10515)
 * Description: downwards arrow to bar
 */
static wchar_t* DOWNARROWBAR_DOWNWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownArrowBar";
static int* DOWNARROWBAR_DOWNWARDS_ARROW_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Rarrtl html character entity reference model.
 *
 * Name: Rarrtl
 * Character: ⤖
 * Unicode code point: U+2916 (10518)
 * Description: rightwards two-headed arrow with tail
 */
static wchar_t* RARRTL_RIGHTWARDS_TWO_HEADED_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Rarrtl";
static int* RARRTL_RIGHTWARDS_TWO_HEADED_ARROW_WITH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The latail html character entity reference model.
 *
 * Name: latail
 * Character: ⤙
 * Unicode code point: U+2919 (10521)
 * Description: leftwards arrow-tail
 */
static wchar_t* LATAIL_LEFTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"latail";
static int* LATAIL_LEFTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ratail html character entity reference model.
 *
 * Name: ratail
 * Character: ⤚
 * Unicode code point: U+291a (10522)
 * Description: rightwards arrow-tail
 */
static wchar_t* RATAIL_RIGHTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ratail";
static int* RATAIL_RIGHTWARDS_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lAtail html character entity reference model.
 *
 * Name: lAtail
 * Character: ⤛
 * Unicode code point: U+291b (10523)
 * Description: leftwards double arrow-tail
 */
static wchar_t* LATAIL_LEFTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lAtail";
static int* LATAIL_LEFTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rAtail html character entity reference model.
 *
 * Name: rAtail
 * Character: ⤜
 * Unicode code point: U+291c (10524)
 * Description: rightwards double arrow-tail
 */
static wchar_t* RATAIL_RIGHTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rAtail";
static int* RATAIL_RIGHTWARDS_DOUBLE_ARROW_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrfs html character entity reference model.
 *
 * Name: larrfs
 * Character: ⤝
 * Unicode code point: U+291d (10525)
 * Description: leftwards arrow to black diamond
 */
static wchar_t* LARRFS_LEFTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrfs";
static int* LARRFS_LEFTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrfs html character entity reference model.
 *
 * Name: rarrfs
 * Character: ⤞
 * Unicode code point: U+291e (10526)
 * Description: rightwards arrow to black diamond
 */
static wchar_t* RARRFS_RIGHTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrfs";
static int* RARRFS_RIGHTWARDS_ARROW_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrbfs html character entity reference model.
 *
 * Name: larrbfs
 * Character: ⤟
 * Unicode code point: U+291f (10527)
 * Description: leftwards arrow from bar to black diamond
 */
static wchar_t* LARRBFS_LEFTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrbfs";
static int* LARRBFS_LEFTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrbfs html character entity reference model.
 *
 * Name: rarrbfs
 * Character: ⤠
 * Unicode code point: U+2920 (10528)
 * Description: rightwards arrow from bar to black diamond
 */
static wchar_t* RARRBFS_RIGHTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrbfs";
static int* RARRBFS_RIGHTWARDS_ARROW_FROM_BAR_TO_BLACK_DIAMOND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nwarhk html character entity reference model.
 *
 * Name: nwarhk
 * Character: ⤣
 * Unicode code point: U+2923 (10531)
 * Description: north west arrow with hook
 */
static wchar_t* NWARHK_NORTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwarhk";
static int* NWARHK_NORTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nearhk html character entity reference model.
 *
 * Name: nearhk
 * Character: ⤤
 * Unicode code point: U+2924 (10532)
 * Description: north east arrow with hook
 */
static wchar_t* NEARHK_NORTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nearhk";
static int* NEARHK_NORTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hksearow html character entity reference model.
 *
 * Name: hksearow
 * Character: ⤥
 * Unicode code point: U+2925 (10533)
 * Description: south east arrow with hook
 */
static wchar_t* HKSEAROW_SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hksearow";
static int* HKSEAROW_SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The searhk html character entity reference model.
 *
 * Name: searhk
 * Character: ⤥
 * Unicode code point: U+2925 (10533)
 * Description: south east arrow with hook
 */
static wchar_t* SEARHK_SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"searhk";
static int* SEARHK_SOUTH_EAST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hkswarow html character entity reference model.
 *
 * Name: hkswarow
 * Character: ⤦
 * Unicode code point: U+2926 (10534)
 * Description: south west arrow with hook
 */
static wchar_t* HKSWAROW_SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hkswarow";
static int* HKSWAROW_SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The swarhk html character entity reference model.
 *
 * Name: swarhk
 * Character: ⤦
 * Unicode code point: U+2926 (10534)
 * Description: south west arrow with hook
 */
static wchar_t* SWARHK_SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swarhk";
static int* SWARHK_SOUTH_WEST_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nwnear html character entity reference model.
 *
 * Name: nwnear
 * Character: ⤧
 * Unicode code point: U+2927 (10535)
 * Description: north west arrow and north east arrow
 */
static wchar_t* NWNEAR_NORTH_WEST_ARROW_AND_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nwnear";
static int* NWNEAR_NORTH_WEST_ARROW_AND_NORTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nesear html character entity reference model.
 *
 * Name: nesear
 * Character: ⤨
 * Unicode code point: U+2928 (10536)
 * Description: north east arrow and south east arrow
 */
static wchar_t* NESEAR_NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nesear";
static int* NESEAR_NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The toea html character entity reference model.
 *
 * Name: toea
 * Character: ⤨
 * Unicode code point: U+2928 (10536)
 * Description: north east arrow and south east arrow
 */
static wchar_t* TOEA_NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"toea";
static int* TOEA_NORTH_EAST_ARROW_AND_SOUTH_EAST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The seswar html character entity reference model.
 *
 * Name: seswar
 * Character: ⤩
 * Unicode code point: U+2929 (10537)
 * Description: south east arrow and south west arrow
 */
static wchar_t* SESWAR_SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"seswar";
static int* SESWAR_SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tosa html character entity reference model.
 *
 * Name: tosa
 * Character: ⤩
 * Unicode code point: U+2929 (10537)
 * Description: south east arrow and south west arrow
 */
static wchar_t* TOSA_SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tosa";
static int* TOSA_SOUTH_EAST_ARROW_AND_SOUTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The swnwar html character entity reference model.
 *
 * Name: swnwar
 * Character: ⤪
 * Unicode code point: U+292a (10538)
 * Description: south west arrow and north west arrow
 */
static wchar_t* SWNWAR_SOUTH_WEST_ARROW_AND_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"swnwar";
static int* SWNWAR_SOUTH_WEST_ARROW_AND_NORTH_WEST_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nrarrc html character entity reference model.
 *
 * Name: nrarrc
 * Character: ⤳̸
 * Unicode code point: U+2933;U+0338 (10547;824)
 * Description: wave arrow pointing directly right with slash
 */
static wchar_t* NRARRC_WAVE_ARROW_POINTING_DIRECTLY_RIGHT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nrarrc";
static int* NRARRC_WAVE_ARROW_POINTING_DIRECTLY_RIGHT_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrc html character entity reference model.
 *
 * Name: rarrc
 * Character: ⤳
 * Unicode code point: U+2933 (10547)
 * Description: wave arrow pointing directly right
 */
static wchar_t* RARRC_WAVE_ARROW_POINTING_DIRECTLY_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrc";
static int* RARRC_WAVE_ARROW_POINTING_DIRECTLY_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cudarrr html character entity reference model.
 *
 * Name: cudarrr
 * Character: ⤵
 * Unicode code point: U+2935 (10549)
 * Description: arrow pointing rightwards then curving downwards
 */
static wchar_t* CUDARRR_ARROW_POINTING_RIGHTWARDS_THEN_CURVING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cudarrr";
static int* CUDARRR_ARROW_POINTING_RIGHTWARDS_THEN_CURVING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldca html character entity reference model.
 *
 * Name: ldca
 * Character: ⤶
 * Unicode code point: U+2936 (10550)
 * Description: arrow pointing downwards then curving leftwards
 */
static wchar_t* LDCA_ARROW_POINTING_DOWNWARDS_THEN_CURVING_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldca";
static int* LDCA_ARROW_POINTING_DOWNWARDS_THEN_CURVING_LEFTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rdca html character entity reference model.
 *
 * Name: rdca
 * Character: ⤷
 * Unicode code point: U+2937 (10551)
 * Description: arrow pointing downwards then curving rightwards
 */
static wchar_t* RDCA_ARROW_POINTING_DOWNWARDS_THEN_CURVING_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdca";
static int* RDCA_ARROW_POINTING_DOWNWARDS_THEN_CURVING_RIGHTWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cudarrl html character entity reference model.
 *
 * Name: cudarrl
 * Character: ⤸
 * Unicode code point: U+2938 (10552)
 * Description: right-side arc clockwise arrow
 */
static wchar_t* CUDARRL_RIGHT_SIDE_ARC_CLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cudarrl";
static int* CUDARRL_RIGHT_SIDE_ARC_CLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrpl html character entity reference model.
 *
 * Name: larrpl
 * Character: ⤹
 * Unicode code point: U+2939 (10553)
 * Description: left-side arc anticlockwise arrow
 */
static wchar_t* LARRPL_LEFT_SIDE_ARC_ANTICLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrpl";
static int* LARRPL_LEFT_SIDE_ARC_ANTICLOCKWISE_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The curarrm html character entity reference model.
 *
 * Name: curarrm
 * Character: ⤼
 * Unicode code point: U+293c (10556)
 * Description: top arc clockwise arrow with minus
 */
static wchar_t* CURARRM_TOP_ARC_CLOCKWISE_ARROW_WITH_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"curarrm";
static int* CURARRM_TOP_ARC_CLOCKWISE_ARROW_WITH_MINUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cularrp html character entity reference model.
 *
 * Name: cularrp
 * Character: ⤽
 * Unicode code point: U+293d (10557)
 * Description: top arc anticlockwise arrow with plus
 */
static wchar_t* CULARRP_TOP_ARC_ANTICLOCKWISE_ARROW_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cularrp";
static int* CULARRP_TOP_ARC_ANTICLOCKWISE_ARROW_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrpl html character entity reference model.
 *
 * Name: rarrpl
 * Character: ⥅
 * Unicode code point: U+2945 (10565)
 * Description: rightwards arrow with plus below
 */
static wchar_t* RARRPL_RIGHTWARDS_ARROW_WITH_PLUS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrpl";
static int* RARRPL_RIGHTWARDS_ARROW_WITH_PLUS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The harrcir html character entity reference model.
 *
 * Name: harrcir
 * Character: ⥈
 * Unicode code point: U+2948 (10568)
 * Description: left right arrow through small circle
 */
static wchar_t* HARRCIR_LEFT_RIGHT_ARROW_THROUGH_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"harrcir";
static int* HARRCIR_LEFT_RIGHT_ARROW_THROUGH_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uarrocir html character entity reference model.
 *
 * Name: Uarrocir
 * Character: ⥉
 * Unicode code point: U+2949 (10569)
 * Description: upwards two-headed arrow from small circle
 */
static wchar_t* UARROCIR_UPWARDS_TWO_HEADED_ARROW_FROM_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uarrocir";
static int* UARROCIR_UPWARDS_TWO_HEADED_ARROW_FROM_SMALL_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lurdshar html character entity reference model.
 *
 * Name: lurdshar
 * Character: ⥊
 * Unicode code point: U+294a (10570)
 * Description: left barb up right barb down harpoon
 */
static wchar_t* LURDSHAR_LEFT_BARB_UP_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lurdshar";
static int* LURDSHAR_LEFT_BARB_UP_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldrushar html character entity reference model.
 *
 * Name: ldrushar
 * Character: ⥋
 * Unicode code point: U+294b (10571)
 * Description: left barb down right barb up harpoon
 */
static wchar_t* LDRUSHAR_LEFT_BARB_DOWN_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldrushar";
static int* LDRUSHAR_LEFT_BARB_DOWN_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftRightVector html character entity reference model.
 *
 * Name: LeftRightVector
 * Character: ⥎
 * Unicode code point: U+294e (10574)
 * Description: left barb up right barb up harpoon
 */
static wchar_t* LEFTRIGHTVECTOR_LEFT_BARB_UP_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftRightVector";
static int* LEFTRIGHTVECTOR_LEFT_BARB_UP_RIGHT_BARB_UP_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightUpDownVector html character entity reference model.
 *
 * Name: RightUpDownVector
 * Character: ⥏
 * Unicode code point: U+294f (10575)
 * Description: up barb right down barb right harpoon
 */
static wchar_t* RIGHTUPDOWNVECTOR_UP_BARB_RIGHT_DOWN_BARB_RIGHT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpDownVector";
static int* RIGHTUPDOWNVECTOR_UP_BARB_RIGHT_DOWN_BARB_RIGHT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownLeftRightVector html character entity reference model.
 *
 * Name: DownLeftRightVector
 * Character: ⥐
 * Unicode code point: U+2950 (10576)
 * Description: left barb down right barb down harpoon
 */
static wchar_t* DOWNLEFTRIGHTVECTOR_LEFT_BARB_DOWN_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftRightVector";
static int* DOWNLEFTRIGHTVECTOR_LEFT_BARB_DOWN_RIGHT_BARB_DOWN_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftUpDownVector html character entity reference model.
 *
 * Name: LeftUpDownVector
 * Character: ⥑
 * Unicode code point: U+2951 (10577)
 * Description: up barb left down barb left harpoon
 */
static wchar_t* LEFTUPDOWNVECTOR_UP_BARB_LEFT_DOWN_BARB_LEFT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpDownVector";
static int* LEFTUPDOWNVECTOR_UP_BARB_LEFT_DOWN_BARB_LEFT_HARPOON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftVectorBar html character entity reference model.
 *
 * Name: LeftVectorBar
 * Character: ⥒
 * Unicode code point: U+2952 (10578)
 * Description: leftwards harpoon with barb up to bar
 */
static wchar_t* LEFTVECTORBAR_LEFTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftVectorBar";
static int* LEFTVECTORBAR_LEFTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightVectorBar html character entity reference model.
 *
 * Name: RightVectorBar
 * Character: ⥓
 * Unicode code point: U+2953 (10579)
 * Description: rightwards harpoon with barb up to bar
 */
static wchar_t* RIGHTVECTORBAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightVectorBar";
static int* RIGHTVECTORBAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightUpVectorBar html character entity reference model.
 *
 * Name: RightUpVectorBar
 * Character: ⥔
 * Unicode code point: U+2954 (10580)
 * Description: upwards harpoon with barb right to bar
 */
static wchar_t* RIGHTUPVECTORBAR_UPWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpVectorBar";
static int* RIGHTUPVECTORBAR_UPWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightDownVectorBar html character entity reference model.
 *
 * Name: RightDownVectorBar
 * Character: ⥕
 * Unicode code point: U+2955 (10581)
 * Description: downwards harpoon with barb right to bar
 */
static wchar_t* RIGHTDOWNVECTORBAR_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownVectorBar";
static int* RIGHTDOWNVECTORBAR_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownLeftVectorBar html character entity reference model.
 *
 * Name: DownLeftVectorBar
 * Character: ⥖
 * Unicode code point: U+2956 (10582)
 * Description: leftwards harpoon with barb down to bar
 */
static wchar_t* DOWNLEFTVECTORBAR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftVectorBar";
static int* DOWNLEFTVECTORBAR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownRightVectorBar html character entity reference model.
 *
 * Name: DownRightVectorBar
 * Character: ⥗
 * Unicode code point: U+2957 (10583)
 * Description: rightwards harpoon with barb down to bar
 */
static wchar_t* DOWNRIGHTVECTORBAR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightVectorBar";
static int* DOWNRIGHTVECTORBAR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftUpVectorBar html character entity reference model.
 *
 * Name: LeftUpVectorBar
 * Character: ⥘
 * Unicode code point: U+2958 (10584)
 * Description: upwards harpoon with barb left to bar
 */
static wchar_t* LEFTUPVECTORBAR_UPWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpVectorBar";
static int* LEFTUPVECTORBAR_UPWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftDownVectorBar html character entity reference model.
 *
 * Name: LeftDownVectorBar
 * Character: ⥙
 * Unicode code point: U+2959 (10585)
 * Description: downwards harpoon with barb left to bar
 */
static wchar_t* LEFTDOWNVECTORBAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownVectorBar";
static int* LEFTDOWNVECTORBAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_TO_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTeeVector html character entity reference model.
 *
 * Name: LeftTeeVector
 * Character: ⥚
 * Unicode code point: U+295a (10586)
 * Description: leftwards harpoon with barb up from bar
 */
static wchar_t* LEFTTEEVECTOR_LEFTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTeeVector";
static int* LEFTTEEVECTOR_LEFTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTeeVector html character entity reference model.
 *
 * Name: RightTeeVector
 * Character: ⥛
 * Unicode code point: U+295b (10587)
 * Description: rightwards harpoon with barb up from bar
 */
static wchar_t* RIGHTTEEVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTeeVector";
static int* RIGHTTEEVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_UP_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightUpTeeVector html character entity reference model.
 *
 * Name: RightUpTeeVector
 * Character: ⥜
 * Unicode code point: U+295c (10588)
 * Description: upwards harpoon with barb right from bar
 */
static wchar_t* RIGHTUPTEEVECTOR_UPWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightUpTeeVector";
static int* RIGHTUPTEEVECTOR_UPWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightDownTeeVector html character entity reference model.
 *
 * Name: RightDownTeeVector
 * Character: ⥝
 * Unicode code point: U+295d (10589)
 * Description: downwards harpoon with barb right from bar
 */
static wchar_t* RIGHTDOWNTEEVECTOR_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightDownTeeVector";
static int* RIGHTDOWNTEEVECTOR_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownLeftTeeVector html character entity reference model.
 *
 * Name: DownLeftTeeVector
 * Character: ⥞
 * Unicode code point: U+295e (10590)
 * Description: leftwards harpoon with barb down from bar
 */
static wchar_t* DOWNLEFTTEEVECTOR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownLeftTeeVector";
static int* DOWNLEFTTEEVECTOR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DownRightTeeVector html character entity reference model.
 *
 * Name: DownRightTeeVector
 * Character: ⥟
 * Unicode code point: U+295f (10591)
 * Description: rightwards harpoon with barb down from bar
 */
static wchar_t* DOWNRIGHTTEEVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DownRightTeeVector";
static int* DOWNRIGHTTEEVECTOR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftUpTeeVector html character entity reference model.
 *
 * Name: LeftUpTeeVector
 * Character: ⥠
 * Unicode code point: U+2960 (10592)
 * Description: upwards harpoon with barb left from bar
 */
static wchar_t* LEFTUPTEEVECTOR_UPWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftUpTeeVector";
static int* LEFTUPTEEVECTOR_UPWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftDownTeeVector html character entity reference model.
 *
 * Name: LeftDownTeeVector
 * Character: ⥡
 * Unicode code point: U+2961 (10593)
 * Description: downwards harpoon with barb left from bar
 */
static wchar_t* LEFTDOWNTEEVECTOR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftDownTeeVector";
static int* LEFTDOWNTEEVECTOR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_FROM_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lHar html character entity reference model.
 *
 * Name: lHar
 * Character: ⥢
 * Unicode code point: U+2962 (10594)
 * Description: leftwards harpoon with barb up above leftwards harpoon with barb down
 */
static wchar_t* LHAR_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lHar";
static int* LHAR_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uHar html character entity reference model.
 *
 * Name: uHar
 * Character: ⥣
 * Unicode code point: U+2963 (10595)
 * Description: upwards harpoon with barb left beside upwards harpoon with barb right
 */
static wchar_t* UHAR_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uHar";
static int* UHAR_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rHar html character entity reference model.
 *
 * Name: rHar
 * Character: ⥤
 * Unicode code point: U+2964 (10596)
 * Description: rightwards harpoon with barb up above rightwards harpoon with barb down
 */
static wchar_t* RHAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rHar";
static int* RHAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dHar html character entity reference model.
 *
 * Name: dHar
 * Character: ⥥
 * Unicode code point: U+2965 (10597)
 * Description: downwards harpoon with barb left beside downwards harpoon with barb right
 */
static wchar_t* DHAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dHar";
static int* DHAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The luruhar html character entity reference model.
 *
 * Name: luruhar
 * Character: ⥦
 * Unicode code point: U+2966 (10598)
 * Description: leftwards harpoon with barb up above rightwards harpoon with barb up
 */
static wchar_t* LURUHAR_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"luruhar";
static int* LURUHAR_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ldrdhar html character entity reference model.
 *
 * Name: ldrdhar
 * Character: ⥧
 * Unicode code point: U+2967 (10599)
 * Description: leftwards harpoon with barb down above rightwards harpoon with barb down
 */
static wchar_t* LDRDHAR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ldrdhar";
static int* LDRDHAR_LEFTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ruluhar html character entity reference model.
 *
 * Name: ruluhar
 * Character: ⥨
 * Unicode code point: U+2968 (10600)
 * Description: rightwards harpoon with barb up above leftwards harpoon with barb up
 */
static wchar_t* RULUHAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ruluhar";
static int* RULUHAR_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rdldhar html character entity reference model.
 *
 * Name: rdldhar
 * Character: ⥩
 * Unicode code point: U+2969 (10601)
 * Description: rightwards harpoon with barb down above leftwards harpoon with barb down
 */
static wchar_t* RDLDHAR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rdldhar";
static int* RDLDHAR_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_ABOVE_LEFTWARDS_HARPOON_WITH_BARB_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lharul html character entity reference model.
 *
 * Name: lharul
 * Character: ⥪
 * Unicode code point: U+296a (10602)
 * Description: leftwards harpoon with barb up above long dash
 */
static wchar_t* LHARUL_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lharul";
static int* LHARUL_LEFTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The llhard html character entity reference model.
 *
 * Name: llhard
 * Character: ⥫
 * Unicode code point: U+296b (10603)
 * Description: leftwards harpoon with barb down below long dash
 */
static wchar_t* LLHARD_LEFTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"llhard";
static int* LLHARD_LEFTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rharul html character entity reference model.
 *
 * Name: rharul
 * Character: ⥬
 * Unicode code point: U+296c (10604)
 * Description: rightwards harpoon with barb up above long dash
 */
static wchar_t* RHARUL_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rharul";
static int* RHARUL_RIGHTWARDS_HARPOON_WITH_BARB_UP_ABOVE_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lrhard html character entity reference model.
 *
 * Name: lrhard
 * Character: ⥭
 * Unicode code point: U+296d (10605)
 * Description: rightwards harpoon with barb down below long dash
 */
static wchar_t* LRHARD_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lrhard";
static int* LRHARD_RIGHTWARDS_HARPOON_WITH_BARB_DOWN_BELOW_LONG_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The UpEquilibrium html character entity reference model.
 *
 * Name: UpEquilibrium
 * Character: ⥮
 * Unicode code point: U+296e (10606)
 * Description: upwards harpoon with barb left beside downwards harpoon with barb right
 */
static wchar_t* UPEQUILIBRIUM_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"UpEquilibrium";
static int* UPEQUILIBRIUM_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udhar html character entity reference model.
 *
 * Name: udhar
 * Character: ⥮
 * Unicode code point: U+296e (10606)
 * Description: upwards harpoon with barb left beside downwards harpoon with barb right
 */
static wchar_t* UDHAR_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"udhar";
static int* UDHAR_UPWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_DOWNWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ReverseUpEquilibrium html character entity reference model.
 *
 * Name: ReverseUpEquilibrium
 * Character: ⥯
 * Unicode code point: U+296f (10607)
 * Description: downwards harpoon with barb left beside upwards harpoon with barb right
 */
static wchar_t* REVERSEUPEQUILIBRIUM_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ReverseUpEquilibrium";
static int* REVERSEUPEQUILIBRIUM_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duhar html character entity reference model.
 *
 * Name: duhar
 * Character: ⥯
 * Unicode code point: U+296f (10607)
 * Description: downwards harpoon with barb left beside upwards harpoon with barb right
 */
static wchar_t* DUHAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"duhar";
static int* DUHAR_DOWNWARDS_HARPOON_WITH_BARB_LEFT_BESIDE_UPWARDS_HARPOON_WITH_BARB_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RoundImplies html character entity reference model.
 *
 * Name: RoundImplies
 * Character: ⥰
 * Unicode code point: U+2970 (10608)
 * Description: right double arrow with rounded head
 */
static wchar_t* ROUNDIMPLIES_RIGHT_DOUBLE_ARROW_WITH_ROUNDED_HEAD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RoundImplies";
static int* ROUNDIMPLIES_RIGHT_DOUBLE_ARROW_WITH_ROUNDED_HEAD_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erarr html character entity reference model.
 *
 * Name: erarr
 * Character: ⥱
 * Unicode code point: U+2971 (10609)
 * Description: equals sign above rightwards arrow
 */
static wchar_t* ERARR_EQUALS_SIGN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"erarr";
static int* ERARR_EQUALS_SIGN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simrarr html character entity reference model.
 *
 * Name: simrarr
 * Character: ⥲
 * Unicode code point: U+2972 (10610)
 * Description: tilde operator above rightwards arrow
 */
static wchar_t* SIMRARR_TILDE_OPERATOR_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simrarr";
static int* SIMRARR_TILDE_OPERATOR_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The larrsim html character entity reference model.
 *
 * Name: larrsim
 * Character: ⥳
 * Unicode code point: U+2973 (10611)
 * Description: leftwards arrow above tilde operator
 */
static wchar_t* LARRSIM_LEFTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"larrsim";
static int* LARRSIM_LEFTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrsim html character entity reference model.
 *
 * Name: rarrsim
 * Character: ⥴
 * Unicode code point: U+2974 (10612)
 * Description: rightwards arrow above tilde operator
 */
static wchar_t* RARRSIM_RIGHTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrsim";
static int* RARRSIM_RIGHTWARDS_ARROW_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rarrap html character entity reference model.
 *
 * Name: rarrap
 * Character: ⥵
 * Unicode code point: U+2975 (10613)
 * Description: rightwards arrow above almost equal to
 */
static wchar_t* RARRAP_RIGHTWARDS_ARROW_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rarrap";
static int* RARRAP_RIGHTWARDS_ARROW_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltlarr html character entity reference model.
 *
 * Name: ltlarr
 * Character: ⥶
 * Unicode code point: U+2976 (10614)
 * Description: less-than above leftwards arrow
 */
static wchar_t* LTLARR_LESS_THAN_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltlarr";
static int* LTLARR_LESS_THAN_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtrarr html character entity reference model.
 *
 * Name: gtrarr
 * Character: ⥸
 * Unicode code point: U+2978 (10616)
 * Description: greater-than above rightwards arrow
 */
static wchar_t* GTRARR_GREATER_THAN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrarr";
static int* GTRARR_GREATER_THAN_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subrarr html character entity reference model.
 *
 * Name: subrarr
 * Character: ⥹
 * Unicode code point: U+2979 (10617)
 * Description: subset above rightwards arrow
 */
static wchar_t* SUBRARR_SUBSET_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subrarr";
static int* SUBRARR_SUBSET_ABOVE_RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The suplarr html character entity reference model.
 *
 * Name: suplarr
 * Character: ⥻
 * Unicode code point: U+297b (10619)
 * Description: superset above leftwards arrow
 */
static wchar_t* SUPLARR_SUPERSET_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suplarr";
static int* SUPLARR_SUPERSET_ABOVE_LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lfisht html character entity reference model.
 *
 * Name: lfisht
 * Character: ⥼
 * Unicode code point: U+297c (10620)
 * Description: left fish tail
 */
static wchar_t* LFISHT_LEFT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfisht";
static int* LFISHT_LEFT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rfisht html character entity reference model.
 *
 * Name: rfisht
 * Character: ⥽
 * Unicode code point: U+297d (10621)
 * Description: right fish tail
 */
static wchar_t* RFISHT_RIGHT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfisht";
static int* RFISHT_RIGHT_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ufisht html character entity reference model.
 *
 * Name: ufisht
 * Character: ⥾
 * Unicode code point: U+297e (10622)
 * Description: up fish tail
 */
static wchar_t* UFISHT_UP_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ufisht";
static int* UFISHT_UP_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dfisht html character entity reference model.
 *
 * Name: dfisht
 * Character: ⥿
 * Unicode code point: U+297f (10623)
 * Description: down fish tail
 */
static wchar_t* DFISHT_DOWN_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dfisht";
static int* DFISHT_DOWN_FISH_TAIL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lopar html character entity reference model.
 *
 * Name: lopar
 * Character: ⦅
 * Unicode code point: U+2985 (10629)
 * Description: left white parenthesis
 */
static wchar_t* LOPAR_LEFT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lopar";
static int* LOPAR_LEFT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ropar html character entity reference model.
 *
 * Name: ropar
 * Character: ⦆
 * Unicode code point: U+2986 (10630)
 * Description: right white parenthesis
 */
static wchar_t* ROPAR_RIGHT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ropar";
static int* ROPAR_RIGHT_WHITE_PARENTHESIS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbrke html character entity reference model.
 *
 * Name: lbrke
 * Character: ⦋
 * Unicode code point: U+298b (10635)
 * Description: left square bracket with underbar
 */
static wchar_t* LBRKE_LEFT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrke";
static int* LBRKE_LEFT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbrke html character entity reference model.
 *
 * Name: rbrke
 * Character: ⦌
 * Unicode code point: U+298c (10636)
 * Description: right square bracket with underbar
 */
static wchar_t* RBRKE_RIGHT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrke";
static int* RBRKE_RIGHT_SQUARE_BRACKET_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbrkslu html character entity reference model.
 *
 * Name: lbrkslu
 * Character: ⦍
 * Unicode code point: U+298d (10637)
 * Description: left square bracket with tick in top corner
 */
static wchar_t* LBRKSLU_LEFT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrkslu";
static int* LBRKSLU_LEFT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbrksld html character entity reference model.
 *
 * Name: rbrksld
 * Character: ⦎
 * Unicode code point: U+298e (10638)
 * Description: right square bracket with tick in bottom corner
 */
static wchar_t* RBRKSLD_RIGHT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrksld";
static int* RBRKSLD_RIGHT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lbrksld html character entity reference model.
 *
 * Name: lbrksld
 * Character: ⦏
 * Unicode code point: U+298f (10639)
 * Description: left square bracket with tick in bottom corner
 */
static wchar_t* LBRKSLD_LEFT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lbrksld";
static int* LBRKSLD_LEFT_SQUARE_BRACKET_WITH_TICK_IN_BOTTOM_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rbrkslu html character entity reference model.
 *
 * Name: rbrkslu
 * Character: ⦐
 * Unicode code point: U+2990 (10640)
 * Description: right square bracket with tick in top corner
 */
static wchar_t* RBRKSLU_RIGHT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rbrkslu";
static int* RBRKSLU_RIGHT_SQUARE_BRACKET_WITH_TICK_IN_TOP_CORNER_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The langd html character entity reference model.
 *
 * Name: langd
 * Character: ⦑
 * Unicode code point: U+2991 (10641)
 * Description: left angle bracket with dot
 */
static wchar_t* LANGD_LEFT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"langd";
static int* LANGD_LEFT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rangd html character entity reference model.
 *
 * Name: rangd
 * Character: ⦒
 * Unicode code point: U+2992 (10642)
 * Description: right angle bracket with dot
 */
static wchar_t* RANGD_RIGHT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rangd";
static int* RANGD_RIGHT_ANGLE_BRACKET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lparlt html character entity reference model.
 *
 * Name: lparlt
 * Character: ⦓
 * Unicode code point: U+2993 (10643)
 * Description: left arc less-than bracket
 */
static wchar_t* LPARLT_LEFT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lparlt";
static int* LPARLT_LEFT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rpargt html character entity reference model.
 *
 * Name: rpargt
 * Character: ⦔
 * Unicode code point: U+2994 (10644)
 * Description: right arc greater-than bracket
 */
static wchar_t* RPARGT_RIGHT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rpargt";
static int* RPARGT_RIGHT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtlPar html character entity reference model.
 *
 * Name: gtlPar
 * Character: ⦕
 * Unicode code point: U+2995 (10645)
 * Description: double left arc greater-than bracket
 */
static wchar_t* GTLPAR_DOUBLE_LEFT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtlPar";
static int* GTLPAR_DOUBLE_LEFT_ARC_GREATER_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltrPar html character entity reference model.
 *
 * Name: ltrPar
 * Character: ⦖
 * Unicode code point: U+2996 (10646)
 * Description: double right arc less-than bracket
 */
static wchar_t* LTRPAR_DOUBLE_RIGHT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltrPar";
static int* LTRPAR_DOUBLE_RIGHT_ARC_LESS_THAN_BRACKET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vzigzag html character entity reference model.
 *
 * Name: vzigzag
 * Character: ⦚
 * Unicode code point: U+299a (10650)
 * Description: vertical zigzag line
 */
static wchar_t* VZIGZAG_VERTICAL_ZIGZAG_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vzigzag";
static int* VZIGZAG_VERTICAL_ZIGZAG_LINE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vangrt html character entity reference model.
 *
 * Name: vangrt
 * Character: ⦜
 * Unicode code point: U+299c (10652)
 * Description: right angle variant with square
 */
static wchar_t* VANGRT_RIGHT_ANGLE_VARIANT_WITH_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vangrt";
static int* VANGRT_RIGHT_ANGLE_VARIANT_WITH_SQUARE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angrtvbd html character entity reference model.
 *
 * Name: angrtvbd
 * Character: ⦝
 * Unicode code point: U+299d (10653)
 * Description: measured right angle with dot
 */
static wchar_t* ANGRTVBD_MEASURED_RIGHT_ANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angrtvbd";
static int* ANGRTVBD_MEASURED_RIGHT_ANGLE_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ange html character entity reference model.
 *
 * Name: ange
 * Character: ⦤
 * Unicode code point: U+29a4 (10660)
 * Description: angle with underbar
 */
static wchar_t* ANGE_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ange";
static int* ANGE_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The range html character entity reference model.
 *
 * Name: range
 * Character: ⦥
 * Unicode code point: U+29a5 (10661)
 * Description: reversed angle with underbar
 */
static wchar_t* RANGE_REVERSED_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"range";
static int* RANGE_REVERSED_ANGLE_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dwangle html character entity reference model.
 *
 * Name: dwangle
 * Character: ⦦
 * Unicode code point: U+29a6 (10662)
 * Description: oblique angle opening up
 */
static wchar_t* DWANGLE_OBLIQUE_ANGLE_OPENING_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dwangle";
static int* DWANGLE_OBLIQUE_ANGLE_OPENING_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uwangle html character entity reference model.
 *
 * Name: uwangle
 * Character: ⦧
 * Unicode code point: U+29a7 (10663)
 * Description: oblique angle opening down
 */
static wchar_t* UWANGLE_OBLIQUE_ANGLE_OPENING_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uwangle";
static int* UWANGLE_OBLIQUE_ANGLE_OPENING_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdaa html character entity reference model.
 *
 * Name: angmsdaa
 * Character: ⦨
 * Unicode code point: U+29a8 (10664)
 * Description: measured angle with open arm ending in arrow pointing up and right
 */
static wchar_t* ANGMSDAA_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdaa";
static int* ANGMSDAA_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdab html character entity reference model.
 *
 * Name: angmsdab
 * Character: ⦩
 * Unicode code point: U+29a9 (10665)
 * Description: measured angle with open arm ending in arrow pointing up and left
 */
static wchar_t* ANGMSDAB_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdab";
static int* ANGMSDAB_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_UP_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdac html character entity reference model.
 *
 * Name: angmsdac
 * Character: ⦪
 * Unicode code point: U+29aa (10666)
 * Description: measured angle with open arm ending in arrow pointing down and right
 */
static wchar_t* ANGMSDAC_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdac";
static int* ANGMSDAC_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdad html character entity reference model.
 *
 * Name: angmsdad
 * Character: ⦫
 * Unicode code point: U+29ab (10667)
 * Description: measured angle with open arm ending in arrow pointing down and left
 */
static wchar_t* ANGMSDAD_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdad";
static int* ANGMSDAD_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_DOWN_AND_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdae html character entity reference model.
 *
 * Name: angmsdae
 * Character: ⦬
 * Unicode code point: U+29ac (10668)
 * Description: measured angle with open arm ending in arrow pointing right and up
 */
static wchar_t* ANGMSDAE_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdae";
static int* ANGMSDAE_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdaf html character entity reference model.
 *
 * Name: angmsdaf
 * Character: ⦭
 * Unicode code point: U+29ad (10669)
 * Description: measured angle with open arm ending in arrow pointing left and up
 */
static wchar_t* ANGMSDAF_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdaf";
static int* ANGMSDAF_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_UP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdag html character entity reference model.
 *
 * Name: angmsdag
 * Character: ⦮
 * Unicode code point: U+29ae (10670)
 * Description: measured angle with open arm ending in arrow pointing right and down
 */
static wchar_t* ANGMSDAG_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdag";
static int* ANGMSDAG_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_RIGHT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The angmsdah html character entity reference model.
 *
 * Name: angmsdah
 * Character: ⦯
 * Unicode code point: U+29af (10671)
 * Description: measured angle with open arm ending in arrow pointing left and down
 */
static wchar_t* ANGMSDAH_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"angmsdah";
static int* ANGMSDAH_MEASURED_ANGLE_WITH_OPEN_ARM_ENDING_IN_ARROW_POINTING_LEFT_AND_DOWN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bemptyv html character entity reference model.
 *
 * Name: bemptyv
 * Character: ⦰
 * Unicode code point: U+29b0 (10672)
 * Description: reversed empty set
 */
static wchar_t* BEMPTYV_REVERSED_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bemptyv";
static int* BEMPTYV_REVERSED_EMPTY_SET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The demptyv html character entity reference model.
 *
 * Name: demptyv
 * Character: ⦱
 * Unicode code point: U+29b1 (10673)
 * Description: empty set with overbar
 */
static wchar_t* DEMPTYV_EMPTY_SET_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"demptyv";
static int* DEMPTYV_EMPTY_SET_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cemptyv html character entity reference model.
 *
 * Name: cemptyv
 * Character: ⦲
 * Unicode code point: U+29b2 (10674)
 * Description: empty set with small circle above
 */
static wchar_t* CEMPTYV_EMPTY_SET_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cemptyv";
static int* CEMPTYV_EMPTY_SET_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The raemptyv html character entity reference model.
 *
 * Name: raemptyv
 * Character: ⦳
 * Unicode code point: U+29b3 (10675)
 * Description: empty set with right arrow above
 */
static wchar_t* RAEMPTYV_EMPTY_SET_WITH_RIGHT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"raemptyv";
static int* RAEMPTYV_EMPTY_SET_WITH_RIGHT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The laemptyv html character entity reference model.
 *
 * Name: laemptyv
 * Character: ⦴
 * Unicode code point: U+29b4 (10676)
 * Description: empty set with left arrow above
 */
static wchar_t* LAEMPTYV_EMPTY_SET_WITH_LEFT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"laemptyv";
static int* LAEMPTYV_EMPTY_SET_WITH_LEFT_ARROW_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ohbar html character entity reference model.
 *
 * Name: ohbar
 * Character: ⦵
 * Unicode code point: U+29b5 (10677)
 * Description: circle with horizontal bar
 */
static wchar_t* OHBAR_CIRCLE_WITH_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ohbar";
static int* OHBAR_CIRCLE_WITH_HORIZONTAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The omid html character entity reference model.
 *
 * Name: omid
 * Character: ⦶
 * Unicode code point: U+29b6 (10678)
 * Description: circled vertical bar
 */
static wchar_t* OMID_CIRCLED_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"omid";
static int* OMID_CIRCLED_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The opar html character entity reference model.
 *
 * Name: opar
 * Character: ⦷
 * Unicode code point: U+29b7 (10679)
 * Description: circled parallel
 */
static wchar_t* OPAR_CIRCLED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"opar";
static int* OPAR_CIRCLED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The operp html character entity reference model.
 *
 * Name: operp
 * Character: ⦹
 * Unicode code point: U+29b9 (10681)
 * Description: circled perpendicular
 */
static wchar_t* OPERP_CIRCLED_PERPENDICULAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"operp";
static int* OPERP_CIRCLED_PERPENDICULAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The olcross html character entity reference model.
 *
 * Name: olcross
 * Character: ⦻
 * Unicode code point: U+29bb (10683)
 * Description: circle with superimposed x
 */
static wchar_t* OLCROSS_CIRCLE_WITH_SUPERIMPOSED_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olcross";
static int* OLCROSS_CIRCLE_WITH_SUPERIMPOSED_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The odsold html character entity reference model.
 *
 * Name: odsold
 * Character: ⦼
 * Unicode code point: U+29bc (10684)
 * Description: circled anticlockwise-rotated division sign
 */
static wchar_t* ODSOLD_CIRCLED_ANTICLOCKWISE_ROTATED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odsold";
static int* ODSOLD_CIRCLED_ANTICLOCKWISE_ROTATED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The olcir html character entity reference model.
 *
 * Name: olcir
 * Character: ⦾
 * Unicode code point: U+29be (10686)
 * Description: circled white bullet
 */
static wchar_t* OLCIR_CIRCLED_WHITE_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olcir";
static int* OLCIR_CIRCLED_WHITE_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ofcir html character entity reference model.
 *
 * Name: ofcir
 * Character: ⦿
 * Unicode code point: U+29bf (10687)
 * Description: circled bullet
 */
static wchar_t* OFCIR_CIRCLED_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ofcir";
static int* OFCIR_CIRCLED_BULLET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The olt html character entity reference model.
 *
 * Name: olt
 * Character: ⧀
 * Unicode code point: U+29c0 (10688)
 * Description: circled less-than
 */
static wchar_t* OLT_CIRCLED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"olt";
static int* OLT_CIRCLED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ogt html character entity reference model.
 *
 * Name: ogt
 * Character: ⧁
 * Unicode code point: U+29c1 (10689)
 * Description: circled greater-than
 */
static wchar_t* OGT_CIRCLED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ogt";
static int* OGT_CIRCLED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cirscir html character entity reference model.
 *
 * Name: cirscir
 * Character: ⧂
 * Unicode code point: U+29c2 (10690)
 * Description: circle with small circle to the right
 */
static wchar_t* CIRSCIR_CIRCLE_WITH_SMALL_CIRCLE_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirscir";
static int* CIRSCIR_CIRCLE_WITH_SMALL_CIRCLE_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cirE html character entity reference model.
 *
 * Name: cirE
 * Character: ⧃
 * Unicode code point: U+29c3 (10691)
 * Description: circle with two horizontal strokes to the right
 */
static wchar_t* CIRE_CIRCLE_WITH_TWO_HORIZONTAL_STROKES_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirE";
static int* CIRE_CIRCLE_WITH_TWO_HORIZONTAL_STROKES_TO_THE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The solb html character entity reference model.
 *
 * Name: solb
 * Character: ⧄
 * Unicode code point: U+29c4 (10692)
 * Description: squared rising diagonal slash
 */
static wchar_t* SOLB_SQUARED_RISING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"solb";
static int* SOLB_SQUARED_RISING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bsolb html character entity reference model.
 *
 * Name: bsolb
 * Character: ⧅
 * Unicode code point: U+29c5 (10693)
 * Description: squared falling diagonal slash
 */
static wchar_t* BSOLB_SQUARED_FALLING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bsolb";
static int* BSOLB_SQUARED_FALLING_DIAGONAL_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The boxbox html character entity reference model.
 *
 * Name: boxbox
 * Character: ⧉
 * Unicode code point: U+29c9 (10697)
 * Description: two joined squares
 */
static wchar_t* BOXBOX_TWO_JOINED_SQUARES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"boxbox";
static int* BOXBOX_TWO_JOINED_SQUARES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The trisb html character entity reference model.
 *
 * Name: trisb
 * Character: ⧍
 * Unicode code point: U+29cd (10701)
 * Description: triangle with serifs at bottom
 */
static wchar_t* TRISB_TRIANGLE_WITH_SERIFS_AT_BOTTOM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"trisb";
static int* TRISB_TRIANGLE_WITH_SERIFS_AT_BOTTOM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rtriltri html character entity reference model.
 *
 * Name: rtriltri
 * Character: ⧎
 * Unicode code point: U+29ce (10702)
 * Description: right triangle above left triangle
 */
static wchar_t* RTRILTRI_RIGHT_TRIANGLE_ABOVE_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rtriltri";
static int* RTRILTRI_RIGHT_TRIANGLE_ABOVE_LEFT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LeftTriangleBar html character entity reference model.
 *
 * Name: LeftTriangleBar
 * Character: ⧏
 * Unicode code point: U+29cf (10703)
 * Description: left triangle beside vertical bar
 */
static wchar_t* LEFTTRIANGLEBAR_LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LeftTriangleBar";
static int* LEFTTRIANGLEBAR_LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLeftTriangleBar html character entity reference model.
 *
 * Name: NotLeftTriangleBar
 * Character: ⧏̸
 * Unicode code point: U+29cf;U+0338 (10703;824)
 * Description: left triangle beside vertical bar with slash
 */
static wchar_t* NOTLEFTTRIANGLEBAR_LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLeftTriangleBar";
static int* NOTLEFTTRIANGLEBAR_LEFT_TRIANGLE_BESIDE_VERTICAL_BAR_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotRightTriangleBar html character entity reference model.
 *
 * Name: NotRightTriangleBar
 * Character: ⧐̸
 * Unicode code point: U+29d0;U+0338 (10704;824)
 * Description: vertical bar beside right triangle with slash
 */
static wchar_t* NOTRIGHTTRIANGLEBAR_VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotRightTriangleBar";
static int* NOTRIGHTTRIANGLEBAR_VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RightTriangleBar html character entity reference model.
 *
 * Name: RightTriangleBar
 * Character: ⧐
 * Unicode code point: U+29d0 (10704)
 * Description: vertical bar beside right triangle
 */
static wchar_t* RIGHTTRIANGLEBAR_VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RightTriangleBar";
static int* RIGHTTRIANGLEBAR_VERTICAL_BAR_BESIDE_RIGHT_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iinfin html character entity reference model.
 *
 * Name: iinfin
 * Character: ⧜
 * Unicode code point: U+29dc (10716)
 * Description: incomplete infinity
 */
static wchar_t* IINFIN_INCOMPLETE_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iinfin";
static int* IINFIN_INCOMPLETE_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The infintie html character entity reference model.
 *
 * Name: infintie
 * Character: ⧝
 * Unicode code point: U+29dd (10717)
 * Description: tie over infinity
 */
static wchar_t* INFINTIE_TIE_OVER_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"infintie";
static int* INFINTIE_TIE_OVER_INFINITY_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nvinfin html character entity reference model.
 *
 * Name: nvinfin
 * Character: ⧞
 * Unicode code point: U+29de (10718)
 * Description: infinity negated with vertical bar
 */
static wchar_t* NVINFIN_INFINITY_NEGATED_WITH_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nvinfin";
static int* NVINFIN_INFINITY_NEGATED_WITH_VERTICAL_BAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eparsl html character entity reference model.
 *
 * Name: eparsl
 * Character: ⧣
 * Unicode code point: U+29e3 (10723)
 * Description: equals sign and slanted parallel
 */
static wchar_t* EPARSL_EQUALS_SIGN_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eparsl";
static int* EPARSL_EQUALS_SIGN_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smeparsl html character entity reference model.
 *
 * Name: smeparsl
 * Character: ⧤
 * Unicode code point: U+29e4 (10724)
 * Description: equals sign and slanted parallel with tilde above
 */
static wchar_t* SMEPARSL_EQUALS_SIGN_AND_SLANTED_PARALLEL_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smeparsl";
static int* SMEPARSL_EQUALS_SIGN_AND_SLANTED_PARALLEL_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqvparsl html character entity reference model.
 *
 * Name: eqvparsl
 * Character: ⧥
 * Unicode code point: U+29e5 (10725)
 * Description: identical to and slanted parallel
 */
static wchar_t* EQVPARSL_IDENTICAL_TO_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqvparsl";
static int* EQVPARSL_IDENTICAL_TO_AND_SLANTED_PARALLEL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The blacklozenge html character entity reference model.
 *
 * Name: blacklozenge
 * Character: ⧫
 * Unicode code point: U+29eb (10731)
 * Description: black lozenge
 */
static wchar_t* BLACKLOZENGE_BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"blacklozenge";
static int* BLACKLOZENGE_BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lozf html character entity reference model.
 *
 * Name: lozf
 * Character: ⧫
 * Unicode code point: U+29eb (10731)
 * Description: black lozenge
 */
static wchar_t* LOZF_BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lozf";
static int* LOZF_BLACK_LOZENGE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The RuleDelayed html character entity reference model.
 *
 * Name: RuleDelayed
 * Character: ⧴
 * Unicode code point: U+29f4 (10740)
 * Description: rule-delayed
 */
static wchar_t* RULEDELAYED_RULE_DELAYED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"RuleDelayed";
static int* RULEDELAYED_RULE_DELAYED_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dsol html character entity reference model.
 *
 * Name: dsol
 * Character: ⧶
 * Unicode code point: U+29f6 (10742)
 * Description: solidus with overbar
 */
static wchar_t* DSOL_SOLIDUS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dsol";
static int* DSOL_SOLIDUS_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigodot html character entity reference model.
 *
 * Name: bigodot
 * Character: ⨀
 * Unicode code point: U+2a00 (10752)
 * Description: n-ary circled dot operator
 */
static wchar_t* BIGODOT_N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigodot";
static int* BIGODOT_N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xodot html character entity reference model.
 *
 * Name: xodot
 * Character: ⨀
 * Unicode code point: U+2a00 (10752)
 * Description: n-ary circled dot operator
 */
static wchar_t* XODOT_N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xodot";
static int* XODOT_N_ARY_CIRCLED_DOT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigoplus html character entity reference model.
 *
 * Name: bigoplus
 * Character: ⨁
 * Unicode code point: U+2a01 (10753)
 * Description: n-ary circled plus operator
 */
static wchar_t* BIGOPLUS_N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigoplus";
static int* BIGOPLUS_N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xoplus html character entity reference model.
 *
 * Name: xoplus
 * Character: ⨁
 * Unicode code point: U+2a01 (10753)
 * Description: n-ary circled plus operator
 */
static wchar_t* XOPLUS_N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xoplus";
static int* XOPLUS_N_ARY_CIRCLED_PLUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigotimes html character entity reference model.
 *
 * Name: bigotimes
 * Character: ⨂
 * Unicode code point: U+2a02 (10754)
 * Description: n-ary circled times operator
 */
static wchar_t* BIGOTIMES_N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigotimes";
static int* BIGOTIMES_N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xotime html character entity reference model.
 *
 * Name: xotime
 * Character: ⨂
 * Unicode code point: U+2a02 (10754)
 * Description: n-ary circled times operator
 */
static wchar_t* XOTIME_N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xotime";
static int* XOTIME_N_ARY_CIRCLED_TIMES_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The biguplus html character entity reference model.
 *
 * Name: biguplus
 * Character: ⨄
 * Unicode code point: U+2a04 (10756)
 * Description: n-ary union operator with plus
 */
static wchar_t* BIGUPLUS_N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"biguplus";
static int* BIGUPLUS_N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xuplus html character entity reference model.
 *
 * Name: xuplus
 * Character: ⨄
 * Unicode code point: U+2a04 (10756)
 * Description: n-ary union operator with plus
 */
static wchar_t* XUPLUS_N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xuplus";
static int* XUPLUS_N_ARY_UNION_OPERATOR_WITH_PLUS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bigsqcup html character entity reference model.
 *
 * Name: bigsqcup
 * Character: ⨆
 * Unicode code point: U+2a06 (10758)
 * Description: n-ary square union operator
 */
static wchar_t* BIGSQCUP_N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bigsqcup";
static int* BIGSQCUP_N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xsqcup html character entity reference model.
 *
 * Name: xsqcup
 * Character: ⨆
 * Unicode code point: U+2a06 (10758)
 * Description: n-ary square union operator
 */
static wchar_t* XSQCUP_N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xsqcup";
static int* XSQCUP_N_ARY_SQUARE_UNION_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iiiint html character entity reference model.
 *
 * Name: iiiint
 * Character: ⨌
 * Unicode code point: U+2a0c (10764)
 * Description: quadruple integral operator
 */
static wchar_t* IIIINT_QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iiiint";
static int* IIIINT_QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qint html character entity reference model.
 *
 * Name: qint
 * Character: ⨌
 * Unicode code point: U+2a0c (10764)
 * Description: quadruple integral operator
 */
static wchar_t* QINT_QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qint";
static int* QINT_QUADRUPLE_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fpartint html character entity reference model.
 *
 * Name: fpartint
 * Character: ⨍
 * Unicode code point: U+2a0d (10765)
 * Description: finite part integral
 */
static wchar_t* FPARTINT_FINITE_PART_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fpartint";
static int* FPARTINT_FINITE_PART_INTEGRAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cirfnint html character entity reference model.
 *
 * Name: cirfnint
 * Character: ⨐
 * Unicode code point: U+2a10 (10768)
 * Description: circulation function
 */
static wchar_t* CIRFNINT_CIRCULATION_FUNCTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirfnint";
static int* CIRFNINT_CIRCULATION_FUNCTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The awint html character entity reference model.
 *
 * Name: awint
 * Character: ⨑
 * Unicode code point: U+2a11 (10769)
 * Description: anticlockwise integration
 */
static wchar_t* AWINT_ANTICLOCKWISE_INTEGRATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"awint";
static int* AWINT_ANTICLOCKWISE_INTEGRATION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rppolint html character entity reference model.
 *
 * Name: rppolint
 * Character: ⨒
 * Unicode code point: U+2a12 (10770)
 * Description: line integration with rectangular path around pole
 */
static wchar_t* RPPOLINT_LINE_INTEGRATION_WITH_RECTANGULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rppolint";
static int* RPPOLINT_LINE_INTEGRATION_WITH_RECTANGULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scpolint html character entity reference model.
 *
 * Name: scpolint
 * Character: ⨓
 * Unicode code point: U+2a13 (10771)
 * Description: line integration with semicircular path around pole
 */
static wchar_t* SCPOLINT_LINE_INTEGRATION_WITH_SEMICIRCULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scpolint";
static int* SCPOLINT_LINE_INTEGRATION_WITH_SEMICIRCULAR_PATH_AROUND_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npolint html character entity reference model.
 *
 * Name: npolint
 * Character: ⨔
 * Unicode code point: U+2a14 (10772)
 * Description: line integration not including the pole
 */
static wchar_t* NPOLINT_LINE_INTEGRATION_NOT_INCLUDING_THE_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npolint";
static int* NPOLINT_LINE_INTEGRATION_NOT_INCLUDING_THE_POLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pointint html character entity reference model.
 *
 * Name: pointint
 * Character: ⨕
 * Unicode code point: U+2a15 (10773)
 * Description: integral around a point operator
 */
static wchar_t* POINTINT_INTEGRAL_AROUND_A_POINT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pointint";
static int* POINTINT_INTEGRAL_AROUND_A_POINT_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The quatint html character entity reference model.
 *
 * Name: quatint
 * Character: ⨖
 * Unicode code point: U+2a16 (10774)
 * Description: quaternion integral operator
 */
static wchar_t* QUATINT_QUATERNION_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"quatint";
static int* QUATINT_QUATERNION_INTEGRAL_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intlarhk html character entity reference model.
 *
 * Name: intlarhk
 * Character: ⨗
 * Unicode code point: U+2a17 (10775)
 * Description: integral with leftwards arrow with hook
 */
static wchar_t* INTLARHK_INTEGRAL_WITH_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intlarhk";
static int* INTLARHK_INTEGRAL_WITH_LEFTWARDS_ARROW_WITH_HOOK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pluscir html character entity reference model.
 *
 * Name: pluscir
 * Character: ⨢
 * Unicode code point: U+2a22 (10786)
 * Description: plus sign with small circle above
 */
static wchar_t* PLUSCIR_PLUS_SIGN_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pluscir";
static int* PLUSCIR_PLUS_SIGN_WITH_SMALL_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plusacir html character entity reference model.
 *
 * Name: plusacir
 * Character: ⨣
 * Unicode code point: U+2a23 (10787)
 * Description: plus sign with circumflex accent above
 */
static wchar_t* PLUSACIR_PLUS_SIGN_WITH_CIRCUMFLEX_ACCENT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusacir";
static int* PLUSACIR_PLUS_SIGN_WITH_CIRCUMFLEX_ACCENT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simplus html character entity reference model.
 *
 * Name: simplus
 * Character: ⨤
 * Unicode code point: U+2a24 (10788)
 * Description: plus sign with tilde above
 */
static wchar_t* SIMPLUS_PLUS_SIGN_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simplus";
static int* SIMPLUS_PLUS_SIGN_WITH_TILDE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plusdu html character entity reference model.
 *
 * Name: plusdu
 * Character: ⨥
 * Unicode code point: U+2a25 (10789)
 * Description: plus sign with dot below
 */
static wchar_t* PLUSDU_PLUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plusdu";
static int* PLUSDU_PLUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plussim html character entity reference model.
 *
 * Name: plussim
 * Character: ⨦
 * Unicode code point: U+2a26 (10790)
 * Description: plus sign with tilde below
 */
static wchar_t* PLUSSIM_PLUS_SIGN_WITH_TILDE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plussim";
static int* PLUSSIM_PLUS_SIGN_WITH_TILDE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The plustwo html character entity reference model.
 *
 * Name: plustwo
 * Character: ⨧
 * Unicode code point: U+2a27 (10791)
 * Description: plus sign with subscript two
 */
static wchar_t* PLUSTWO_PLUS_SIGN_WITH_SUBSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"plustwo";
static int* PLUSTWO_PLUS_SIGN_WITH_SUBSCRIPT_TWO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mcomma html character entity reference model.
 *
 * Name: mcomma
 * Character: ⨩
 * Unicode code point: U+2a29 (10793)
 * Description: minus sign with comma above
 */
static wchar_t* MCOMMA_MINUS_SIGN_WITH_COMMA_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mcomma";
static int* MCOMMA_MINUS_SIGN_WITH_COMMA_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minusdu html character entity reference model.
 *
 * Name: minusdu
 * Character: ⨪
 * Unicode code point: U+2a2a (10794)
 * Description: minus sign with dot below
 */
static wchar_t* MINUSDU_MINUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"minusdu";
static int* MINUSDU_MINUS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The loplus html character entity reference model.
 *
 * Name: loplus
 * Character: ⨭
 * Unicode code point: U+2a2d (10797)
 * Description: plus sign in left half circle
 */
static wchar_t* LOPLUS_PLUS_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"loplus";
static int* LOPLUS_PLUS_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The roplus html character entity reference model.
 *
 * Name: roplus
 * Character: ⨮
 * Unicode code point: U+2a2e (10798)
 * Description: plus sign in right half circle
 */
static wchar_t* ROPLUS_PLUS_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"roplus";
static int* ROPLUS_PLUS_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cross html character entity reference model.
 *
 * Name: Cross
 * Character: ⨯
 * Unicode code point: U+2a2f (10799)
 * Description: vector or cross product
 */
static wchar_t* CROSS_VECTOR_OR_CROSS_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cross";
static int* CROSS_VECTOR_OR_CROSS_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The timesd html character entity reference model.
 *
 * Name: timesd
 * Character: ⨰
 * Unicode code point: U+2a30 (10800)
 * Description: multiplication sign with dot above
 */
static wchar_t* TIMESD_MULTIPLICATION_SIGN_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"timesd";
static int* TIMESD_MULTIPLICATION_SIGN_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The timesbar html character entity reference model.
 *
 * Name: timesbar
 * Character: ⨱
 * Unicode code point: U+2a31 (10801)
 * Description: multiplication sign with underbar
 */
static wchar_t* TIMESBAR_MULTIPLICATION_SIGN_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"timesbar";
static int* TIMESBAR_MULTIPLICATION_SIGN_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smashp html character entity reference model.
 *
 * Name: smashp
 * Character: ⨳
 * Unicode code point: U+2a33 (10803)
 * Description: smash product
 */
static wchar_t* SMASHP_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smashp";
static int* SMASHP_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lotimes html character entity reference model.
 *
 * Name: lotimes
 * Character: ⨴
 * Unicode code point: U+2a34 (10804)
 * Description: multiplication sign in left half circle
 */
static wchar_t* LOTIMES_MULTIPLICATION_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lotimes";
static int* LOTIMES_MULTIPLICATION_SIGN_IN_LEFT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rotimes html character entity reference model.
 *
 * Name: rotimes
 * Character: ⨵
 * Unicode code point: U+2a35 (10805)
 * Description: multiplication sign in right half circle
 */
static wchar_t* ROTIMES_MULTIPLICATION_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rotimes";
static int* ROTIMES_MULTIPLICATION_SIGN_IN_RIGHT_HALF_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The otimesas html character entity reference model.
 *
 * Name: otimesas
 * Character: ⨶
 * Unicode code point: U+2a36 (10806)
 * Description: circled multiplication sign with circumflex accent
 */
static wchar_t* OTIMESAS_CIRCLED_MULTIPLICATION_SIGN_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"otimesas";
static int* OTIMESAS_CIRCLED_MULTIPLICATION_SIGN_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Otimes html character entity reference model.
 *
 * Name: Otimes
 * Character: ⨷
 * Unicode code point: U+2a37 (10807)
 * Description: multiplication sign in double circle
 */
static wchar_t* OTIMES_MULTIPLICATION_SIGN_IN_DOUBLE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Otimes";
static int* OTIMES_MULTIPLICATION_SIGN_IN_DOUBLE_CIRCLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The odiv html character entity reference model.
 *
 * Name: odiv
 * Character: ⨸
 * Unicode code point: U+2a38 (10808)
 * Description: circled division sign
 */
static wchar_t* ODIV_CIRCLED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"odiv";
static int* ODIV_CIRCLED_DIVISION_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triplus html character entity reference model.
 *
 * Name: triplus
 * Character: ⨹
 * Unicode code point: U+2a39 (10809)
 * Description: plus sign in triangle
 */
static wchar_t* TRIPLUS_PLUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triplus";
static int* TRIPLUS_PLUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The triminus html character entity reference model.
 *
 * Name: triminus
 * Character: ⨺
 * Unicode code point: U+2a3a (10810)
 * Description: minus sign in triangle
 */
static wchar_t* TRIMINUS_MINUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"triminus";
static int* TRIMINUS_MINUS_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tritime html character entity reference model.
 *
 * Name: tritime
 * Character: ⨻
 * Unicode code point: U+2a3b (10811)
 * Description: multiplication sign in triangle
 */
static wchar_t* TRITIME_MULTIPLICATION_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tritime";
static int* TRITIME_MULTIPLICATION_SIGN_IN_TRIANGLE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The intprod html character entity reference model.
 *
 * Name: intprod
 * Character: ⨼
 * Unicode code point: U+2a3c (10812)
 * Description: interior product
 */
static wchar_t* INTPROD_INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"intprod";
static int* INTPROD_INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iprod html character entity reference model.
 *
 * Name: iprod
 * Character: ⨼
 * Unicode code point: U+2a3c (10812)
 * Description: interior product
 */
static wchar_t* IPROD_INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iprod";
static int* IPROD_INTERIOR_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The amalg html character entity reference model.
 *
 * Name: amalg
 * Character: ⨿
 * Unicode code point: U+2a3f (10815)
 * Description: amalgamation or coproduct
 */
static wchar_t* AMALG_AMALGAMATION_OR_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"amalg";
static int* AMALG_AMALGAMATION_OR_COPRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The capdot html character entity reference model.
 *
 * Name: capdot
 * Character: ⩀
 * Unicode code point: U+2a40 (10816)
 * Description: intersection with dot
 */
static wchar_t* CAPDOT_INTERSECTION_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capdot";
static int* CAPDOT_INTERSECTION_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncup html character entity reference model.
 *
 * Name: ncup
 * Character: ⩂
 * Unicode code point: U+2a42 (10818)
 * Description: union with overbar
 */
static wchar_t* NCUP_UNION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncup";
static int* NCUP_UNION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncap html character entity reference model.
 *
 * Name: ncap
 * Character: ⩃
 * Unicode code point: U+2a43 (10819)
 * Description: intersection with overbar
 */
static wchar_t* NCAP_INTERSECTION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncap";
static int* NCAP_INTERSECTION_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The capand html character entity reference model.
 *
 * Name: capand
 * Character: ⩄
 * Unicode code point: U+2a44 (10820)
 * Description: intersection with logical and
 */
static wchar_t* CAPAND_INTERSECTION_WITH_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capand";
static int* CAPAND_INTERSECTION_WITH_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cupor html character entity reference model.
 *
 * Name: cupor
 * Character: ⩅
 * Unicode code point: U+2a45 (10821)
 * Description: union with logical or
 */
static wchar_t* CUPOR_UNION_WITH_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupor";
static int* CUPOR_UNION_WITH_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cupcap html character entity reference model.
 *
 * Name: cupcap
 * Character: ⩆
 * Unicode code point: U+2a46 (10822)
 * Description: union above intersection
 */
static wchar_t* CUPCAP_UNION_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupcap";
static int* CUPCAP_UNION_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The capcup html character entity reference model.
 *
 * Name: capcup
 * Character: ⩇
 * Unicode code point: U+2a47 (10823)
 * Description: intersection above union
 */
static wchar_t* CAPCUP_INTERSECTION_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capcup";
static int* CAPCUP_INTERSECTION_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cupbrcap html character entity reference model.
 *
 * Name: cupbrcap
 * Character: ⩈
 * Unicode code point: U+2a48 (10824)
 * Description: union above bar above intersection
 */
static wchar_t* CUPBRCAP_UNION_ABOVE_BAR_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupbrcap";
static int* CUPBRCAP_UNION_ABOVE_BAR_ABOVE_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The capbrcup html character entity reference model.
 *
 * Name: capbrcup
 * Character: ⩉
 * Unicode code point: U+2a49 (10825)
 * Description: intersection above bar above union
 */
static wchar_t* CAPBRCUP_INTERSECTION_ABOVE_BAR_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capbrcup";
static int* CAPBRCUP_INTERSECTION_ABOVE_BAR_ABOVE_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cupcup html character entity reference model.
 *
 * Name: cupcup
 * Character: ⩊
 * Unicode code point: U+2a4a (10826)
 * Description: union beside and joined with union
 */
static wchar_t* CUPCUP_UNION_BESIDE_AND_JOINED_WITH_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cupcup";
static int* CUPCUP_UNION_BESIDE_AND_JOINED_WITH_UNION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The capcap html character entity reference model.
 *
 * Name: capcap
 * Character: ⩋
 * Unicode code point: U+2a4b (10827)
 * Description: intersection beside and joined with intersection
 */
static wchar_t* CAPCAP_INTERSECTION_BESIDE_AND_JOINED_WITH_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"capcap";
static int* CAPCAP_INTERSECTION_BESIDE_AND_JOINED_WITH_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccups html character entity reference model.
 *
 * Name: ccups
 * Character: ⩌
 * Unicode code point: U+2a4c (10828)
 * Description: closed union with serifs
 */
static wchar_t* CCUPS_CLOSED_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccups";
static int* CCUPS_CLOSED_UNION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccaps html character entity reference model.
 *
 * Name: ccaps
 * Character: ⩍
 * Unicode code point: U+2a4d (10829)
 * Description: closed intersection with serifs
 */
static wchar_t* CCAPS_CLOSED_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccaps";
static int* CCAPS_CLOSED_INTERSECTION_WITH_SERIFS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ccupssm html character entity reference model.
 *
 * Name: ccupssm
 * Character: ⩐
 * Unicode code point: U+2a50 (10832)
 * Description: closed union with serifs and smash product
 */
static wchar_t* CCUPSSM_CLOSED_UNION_WITH_SERIFS_AND_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ccupssm";
static int* CCUPSSM_CLOSED_UNION_WITH_SERIFS_AND_SMASH_PRODUCT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The And html character entity reference model.
 *
 * Name: And
 * Character: ⩓
 * Unicode code point: U+2a53 (10835)
 * Description: double logical and
 */
static wchar_t* AND_DOUBLE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"And";
static int* AND_DOUBLE_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Or html character entity reference model.
 *
 * Name: Or
 * Character: ⩔
 * Unicode code point: U+2a54 (10836)
 * Description: double logical or
 */
static wchar_t* OR_DOUBLE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Or";
static int* OR_DOUBLE_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The andand html character entity reference model.
 *
 * Name: andand
 * Character: ⩕
 * Unicode code point: U+2a55 (10837)
 * Description: two intersecting logical and
 */
static wchar_t* ANDAND_TWO_INTERSECTING_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andand";
static int* ANDAND_TWO_INTERSECTING_LOGICAL_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oror html character entity reference model.
 *
 * Name: oror
 * Character: ⩖
 * Unicode code point: U+2a56 (10838)
 * Description: two intersecting logical or
 */
static wchar_t* OROR_TWO_INTERSECTING_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oror";
static int* OROR_TWO_INTERSECTING_LOGICAL_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The orslope html character entity reference model.
 *
 * Name: orslope
 * Character: ⩗
 * Unicode code point: U+2a57 (10839)
 * Description: sloping large or
 */
static wchar_t* ORSLOPE_SLOPING_LARGE_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orslope";
static int* ORSLOPE_SLOPING_LARGE_OR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The andslope html character entity reference model.
 *
 * Name: andslope
 * Character: ⩘
 * Unicode code point: U+2a58 (10840)
 * Description: sloping large and
 */
static wchar_t* ANDSLOPE_SLOPING_LARGE_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andslope";
static int* ANDSLOPE_SLOPING_LARGE_AND_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The andv html character entity reference model.
 *
 * Name: andv
 * Character: ⩚
 * Unicode code point: U+2a5a (10842)
 * Description: logical and with middle stem
 */
static wchar_t* ANDV_LOGICAL_AND_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andv";
static int* ANDV_LOGICAL_AND_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The orv html character entity reference model.
 *
 * Name: orv
 * Character: ⩛
 * Unicode code point: U+2a5b (10843)
 * Description: logical or with middle stem
 */
static wchar_t* ORV_LOGICAL_OR_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"orv";
static int* ORV_LOGICAL_OR_WITH_MIDDLE_STEM_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The andd html character entity reference model.
 *
 * Name: andd
 * Character: ⩜
 * Unicode code point: U+2a5c (10844)
 * Description: logical and with horizontal dash
 */
static wchar_t* ANDD_LOGICAL_AND_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"andd";
static int* ANDD_LOGICAL_AND_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ord html character entity reference model.
 *
 * Name: ord
 * Character: ⩝
 * Unicode code point: U+2a5d (10845)
 * Description: logical or with horizontal dash
 */
static wchar_t* ORD_LOGICAL_OR_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ord";
static int* ORD_LOGICAL_OR_WITH_HORIZONTAL_DASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wedbar html character entity reference model.
 *
 * Name: wedbar
 * Character: ⩟
 * Unicode code point: U+2a5f (10847)
 * Description: logical and with underbar
 */
static wchar_t* WEDBAR_LOGICAL_AND_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wedbar";
static int* WEDBAR_LOGICAL_AND_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sdote html character entity reference model.
 *
 * Name: sdote
 * Character: ⩦
 * Unicode code point: U+2a66 (10854)
 * Description: equals sign with dot below
 */
static wchar_t* SDOTE_EQUALS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sdote";
static int* SDOTE_EQUALS_SIGN_WITH_DOT_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simdot html character entity reference model.
 *
 * Name: simdot
 * Character: ⩪
 * Unicode code point: U+2a6a (10858)
 * Description: tilde operator with dot above
 */
static wchar_t* SIMDOT_TILDE_OPERATOR_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simdot";
static int* SIMDOT_TILDE_OPERATOR_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The congdot html character entity reference model.
 *
 * Name: congdot
 * Character: ⩭
 * Unicode code point: U+2a6d (10861)
 * Description: congruent with dot above
 */
static wchar_t* CONGDOT_CONGRUENT_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"congdot";
static int* CONGDOT_CONGRUENT_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ncongdot html character entity reference model.
 *
 * Name: ncongdot
 * Character: ⩭̸
 * Unicode code point: U+2a6d;U+0338 (10861;824)
 * Description: congruent with dot above with slash
 */
static wchar_t* NCONGDOT_CONGRUENT_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ncongdot";
static int* NCONGDOT_CONGRUENT_WITH_DOT_ABOVE_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The easter html character entity reference model.
 *
 * Name: easter
 * Character: ⩮
 * Unicode code point: U+2a6e (10862)
 * Description: equals with asterisk
 */
static wchar_t* EASTER_EQUALS_WITH_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"easter";
static int* EASTER_EQUALS_WITH_ASTERISK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apacir html character entity reference model.
 *
 * Name: apacir
 * Character: ⩯
 * Unicode code point: U+2a6f (10863)
 * Description: almost equal to with circumflex accent
 */
static wchar_t* APACIR_ALMOST_EQUAL_TO_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apacir";
static int* APACIR_ALMOST_EQUAL_TO_WITH_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The apE html character entity reference model.
 *
 * Name: apE
 * Character: ⩰
 * Unicode code point: U+2a70 (10864)
 * Description: approximately equal or equal to
 */
static wchar_t* APE_APPROXIMATELY_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"apE";
static int* APE_APPROXIMATELY_EQUAL_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The napE html character entity reference model.
 *
 * Name: napE
 * Character: ⩰̸
 * Unicode code point: U+2a70;U+0338 (10864;824)
 * Description: approximately equal or equal to with slash
 */
static wchar_t* NAPE_APPROXIMATELY_EQUAL_OR_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"napE";
static int* NAPE_APPROXIMATELY_EQUAL_OR_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eplus html character entity reference model.
 *
 * Name: eplus
 * Character: ⩱
 * Unicode code point: U+2a71 (10865)
 * Description: equals sign above plus sign
 */
static wchar_t* EPLUS_EQUALS_SIGN_ABOVE_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eplus";
static int* EPLUS_EQUALS_SIGN_ABOVE_PLUS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pluse html character entity reference model.
 *
 * Name: pluse
 * Character: ⩲
 * Unicode code point: U+2a72 (10866)
 * Description: plus sign above equals sign
 */
static wchar_t* PLUSE_PLUS_SIGN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pluse";
static int* PLUSE_PLUS_SIGN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Esim html character entity reference model.
 *
 * Name: Esim
 * Character: ⩳
 * Unicode code point: U+2a73 (10867)
 * Description: equals sign above tilde operator
 */
static wchar_t* ESIM_EQUALS_SIGN_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Esim";
static int* ESIM_EQUALS_SIGN_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Colone html character entity reference model.
 *
 * Name: Colone
 * Character: ⩴
 * Unicode code point: U+2a74 (10868)
 * Description: double colon equal
 */
static wchar_t* COLONE_DOUBLE_COLON_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Colone";
static int* COLONE_DOUBLE_COLON_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Equal html character entity reference model.
 *
 * Name: Equal
 * Character: ⩵
 * Unicode code point: U+2a75 (10869)
 * Description: two consecutive equals signs
 */
static wchar_t* EQUAL_TWO_CONSECUTIVE_EQUALS_SIGNS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Equal";
static int* EQUAL_TWO_CONSECUTIVE_EQUALS_SIGNS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ddotseq html character entity reference model.
 *
 * Name: ddotseq
 * Character: ⩷
 * Unicode code point: U+2a77 (10871)
 * Description: equals sign with two dots above and two dots below
 */
static wchar_t* DDOTSEQ_EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ddotseq";
static int* DDOTSEQ_EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eDDot html character entity reference model.
 *
 * Name: eDDot
 * Character: ⩷
 * Unicode code point: U+2a77 (10871)
 * Description: equals sign with two dots above and two dots below
 */
static wchar_t* EDDOT_EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eDDot";
static int* EDDOT_EQUALS_SIGN_WITH_TWO_DOTS_ABOVE_AND_TWO_DOTS_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The equivDD html character entity reference model.
 *
 * Name: equivDD
 * Character: ⩸
 * Unicode code point: U+2a78 (10872)
 * Description: equivalent with four dots above
 */
static wchar_t* EQUIVDD_EQUIVALENT_WITH_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"equivDD";
static int* EQUIVDD_EQUIVALENT_WITH_FOUR_DOTS_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltcir html character entity reference model.
 *
 * Name: ltcir
 * Character: ⩹
 * Unicode code point: U+2a79 (10873)
 * Description: less-than with circle inside
 */
static wchar_t* LTCIR_LESS_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltcir";
static int* LTCIR_LESS_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtcir html character entity reference model.
 *
 * Name: gtcir
 * Character: ⩺
 * Unicode code point: U+2a7a (10874)
 * Description: greater-than with circle inside
 */
static wchar_t* GTCIR_GREATER_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtcir";
static int* GTCIR_GREATER_THAN_WITH_CIRCLE_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltquest html character entity reference model.
 *
 * Name: ltquest
 * Character: ⩻
 * Unicode code point: U+2a7b (10875)
 * Description: less-than with question mark above
 */
static wchar_t* LTQUEST_LESS_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltquest";
static int* LTQUEST_LESS_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtquest html character entity reference model.
 *
 * Name: gtquest
 * Character: ⩼
 * Unicode code point: U+2a7c (10876)
 * Description: greater-than with question mark above
 */
static wchar_t* GTQUEST_GREATER_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtquest";
static int* GTQUEST_GREATER_THAN_WITH_QUESTION_MARK_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessSlantEqual html character entity reference model.
 *
 * Name: LessSlantEqual
 * Character: ⩽
 * Unicode code point: U+2a7d (10877)
 * Description: less-than or slanted equal to
 */
static wchar_t* LESSSLANTEQUAL_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessSlantEqual";
static int* LESSSLANTEQUAL_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The leqslant html character entity reference model.
 *
 * Name: leqslant
 * Character: ⩽
 * Unicode code point: U+2a7d (10877)
 * Description: less-than or slanted equal to
 */
static wchar_t* LEQSLANT_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"leqslant";
static int* LEQSLANT_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The les html character entity reference model.
 *
 * Name: les
 * Character: ⩽
 * Unicode code point: U+2a7d (10877)
 * Description: less-than or slanted equal to
 */
static wchar_t* LES_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"les";
static int* LES_LESS_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotLessSlantEqual html character entity reference model.
 *
 * Name: NotLessSlantEqual
 * Character: ⩽̸
 * Unicode code point: U+2a7d;U+0338 (10877;824)
 * Description: less-than or slanted equal to with slash
 */
static wchar_t* NOTLESSSLANTEQUAL_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotLessSlantEqual";
static int* NOTLESSSLANTEQUAL_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nleqslant html character entity reference model.
 *
 * Name: nleqslant
 * Character: ⩽̸
 * Unicode code point: U+2a7d;U+0338 (10877;824)
 * Description: less-than or slanted equal to with slash
 */
static wchar_t* NLEQSLANT_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nleqslant";
static int* NLEQSLANT_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nles html character entity reference model.
 *
 * Name: nles
 * Character: ⩽̸
 * Unicode code point: U+2a7d;U+0338 (10877;824)
 * Description: less-than or slanted equal to with slash
 */
static wchar_t* NLES_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nles";
static int* NLES_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterSlantEqual html character entity reference model.
 *
 * Name: GreaterSlantEqual
 * Character: ⩾
 * Unicode code point: U+2a7e (10878)
 * Description: greater-than or slanted equal to
 */
static wchar_t* GREATERSLANTEQUAL_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterSlantEqual";
static int* GREATERSLANTEQUAL_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The geqslant html character entity reference model.
 *
 * Name: geqslant
 * Character: ⩾
 * Unicode code point: U+2a7e (10878)
 * Description: greater-than or slanted equal to
 */
static wchar_t* GEQSLANT_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"geqslant";
static int* GEQSLANT_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ges html character entity reference model.
 *
 * Name: ges
 * Character: ⩾
 * Unicode code point: U+2a7e (10878)
 * Description: greater-than or slanted equal to
 */
static wchar_t* GES_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ges";
static int* GES_GREATER_THAN_OR_SLANTED_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotGreaterSlantEqual html character entity reference model.
 *
 * Name: NotGreaterSlantEqual
 * Character: ⩾̸
 * Unicode code point: U+2a7e;U+0338 (10878;824)
 * Description: greater-than or slanted equal to with slash
 */
static wchar_t* NOTGREATERSLANTEQUAL_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotGreaterSlantEqual";
static int* NOTGREATERSLANTEQUAL_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ngeqslant html character entity reference model.
 *
 * Name: ngeqslant
 * Character: ⩾̸
 * Unicode code point: U+2a7e;U+0338 (10878;824)
 * Description: greater-than or slanted equal to with slash
 */
static wchar_t* NGEQSLANT_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ngeqslant";
static int* NGEQSLANT_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nges html character entity reference model.
 *
 * Name: nges
 * Character: ⩾̸
 * Unicode code point: U+2a7e;U+0338 (10878;824)
 * Description: greater-than or slanted equal to with slash
 */
static wchar_t* NGES_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nges";
static int* NGES_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesdot html character entity reference model.
 *
 * Name: lesdot
 * Character: ⩿
 * Unicode code point: U+2a7f (10879)
 * Description: less-than or slanted equal to with dot inside
 */
static wchar_t* LESDOT_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdot";
static int* LESDOT_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gesdot html character entity reference model.
 *
 * Name: gesdot
 * Character: ⪀
 * Unicode code point: U+2a80 (10880)
 * Description: greater-than or slanted equal to with dot inside
 */
static wchar_t* GESDOT_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdot";
static int* GESDOT_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesdoto html character entity reference model.
 *
 * Name: lesdoto
 * Character: ⪁
 * Unicode code point: U+2a81 (10881)
 * Description: less-than or slanted equal to with dot above
 */
static wchar_t* LESDOTO_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdoto";
static int* LESDOTO_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gesdoto html character entity reference model.
 *
 * Name: gesdoto
 * Character: ⪂
 * Unicode code point: U+2a82 (10882)
 * Description: greater-than or slanted equal to with dot above
 */
static wchar_t* GESDOTO_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdoto";
static int* GESDOTO_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesdotor html character entity reference model.
 *
 * Name: lesdotor
 * Character: ⪃
 * Unicode code point: U+2a83 (10883)
 * Description: less-than or slanted equal to with dot above right
 */
static wchar_t* LESDOTOR_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesdotor";
static int* LESDOTOR_LESS_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_RIGHT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gesdotol html character entity reference model.
 *
 * Name: gesdotol
 * Character: ⪄
 * Unicode code point: U+2a84 (10884)
 * Description: greater-than or slanted equal to with dot above left
 */
static wchar_t* GESDOTOL_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesdotol";
static int* GESDOTOL_GREATER_THAN_OR_SLANTED_EQUAL_TO_WITH_DOT_ABOVE_LEFT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lap html character entity reference model.
 *
 * Name: lap
 * Character: ⪅
 * Unicode code point: U+2a85 (10885)
 * Description: less-than or approximate
 */
static wchar_t* LAP_LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lap";
static int* LAP_LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lessapprox html character entity reference model.
 *
 * Name: lessapprox
 * Character: ⪅
 * Unicode code point: U+2a85 (10885)
 * Description: less-than or approximate
 */
static wchar_t* LESSAPPROX_LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lessapprox";
static int* LESSAPPROX_LESS_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gap html character entity reference model.
 *
 * Name: gap
 * Character: ⪆
 * Unicode code point: U+2a86 (10886)
 * Description: greater-than or approximate
 */
static wchar_t* GAP_GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gap";
static int* GAP_GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtrapprox html character entity reference model.
 *
 * Name: gtrapprox
 * Character: ⪆
 * Unicode code point: U+2a86 (10886)
 * Description: greater-than or approximate
 */
static wchar_t* GTRAPPROX_GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtrapprox";
static int* GTRAPPROX_GREATER_THAN_OR_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lne html character entity reference model.
 *
 * Name: lne
 * Character: ⪇
 * Unicode code point: U+2a87 (10887)
 * Description: less-than and single-line not equal to
 */
static wchar_t* LNE_LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lne";
static int* LNE_LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lneq html character entity reference model.
 *
 * Name: lneq
 * Character: ⪇
 * Unicode code point: U+2a87 (10887)
 * Description: less-than and single-line not equal to
 */
static wchar_t* LNEQ_LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lneq";
static int* LNEQ_LESS_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gne html character entity reference model.
 *
 * Name: gne
 * Character: ⪈
 * Unicode code point: U+2a88 (10888)
 * Description: greater-than and single-line not equal to
 */
static wchar_t* GNE_GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gne";
static int* GNE_GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gneq html character entity reference model.
 *
 * Name: gneq
 * Character: ⪈
 * Unicode code point: U+2a88 (10888)
 * Description: greater-than and single-line not equal to
 */
static wchar_t* GNEQ_GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gneq";
static int* GNEQ_GREATER_THAN_AND_SINGLE_LINE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lnap html character entity reference model.
 *
 * Name: lnap
 * Character: ⪉
 * Unicode code point: U+2a89 (10889)
 * Description: less-than and not approximate
 */
static wchar_t* LNAP_LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnap";
static int* LNAP_LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lnapprox html character entity reference model.
 *
 * Name: lnapprox
 * Character: ⪉
 * Unicode code point: U+2a89 (10889)
 * Description: less-than and not approximate
 */
static wchar_t* LNAPPROX_LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lnapprox";
static int* LNAPPROX_LESS_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gnap html character entity reference model.
 *
 * Name: gnap
 * Character: ⪊
 * Unicode code point: U+2a8a (10890)
 * Description: greater-than and not approximate
 */
static wchar_t* GNAP_GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnap";
static int* GNAP_GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gnapprox html character entity reference model.
 *
 * Name: gnapprox
 * Character: ⪊
 * Unicode code point: U+2a8a (10890)
 * Description: greater-than and not approximate
 */
static wchar_t* GNAPPROX_GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gnapprox";
static int* GNAPPROX_GREATER_THAN_AND_NOT_APPROXIMATE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lEg html character entity reference model.
 *
 * Name: lEg
 * Character: ⪋
 * Unicode code point: U+2a8b (10891)
 * Description: less-than above double-line equal above greater-than
 */
static wchar_t* LEG_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lEg";
static int* LEG_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesseqqgtr html character entity reference model.
 *
 * Name: lesseqqgtr
 * Character: ⪋
 * Unicode code point: U+2a8b (10891)
 * Description: less-than above double-line equal above greater-than
 */
static wchar_t* LESSEQQGTR_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesseqqgtr";
static int* LESSEQQGTR_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gEl html character entity reference model.
 *
 * Name: gEl
 * Character: ⪌
 * Unicode code point: U+2a8c (10892)
 * Description: greater-than above double-line equal above less-than
 */
static wchar_t* GEL_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gEl";
static int* GEL_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtreqqless html character entity reference model.
 *
 * Name: gtreqqless
 * Character: ⪌
 * Unicode code point: U+2a8c (10892)
 * Description: greater-than above double-line equal above less-than
 */
static wchar_t* GTREQQLESS_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtreqqless";
static int* GTREQQLESS_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsime html character entity reference model.
 *
 * Name: lsime
 * Character: ⪍
 * Unicode code point: U+2a8d (10893)
 * Description: less-than above similar or equal
 */
static wchar_t* LSIME_LESS_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsime";
static int* LSIME_LESS_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gsime html character entity reference model.
 *
 * Name: gsime
 * Character: ⪎
 * Unicode code point: U+2a8e (10894)
 * Description: greater-than above similar or equal
 */
static wchar_t* GSIME_GREATER_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gsime";
static int* GSIME_GREATER_THAN_ABOVE_SIMILAR_OR_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lsimg html character entity reference model.
 *
 * Name: lsimg
 * Character: ⪏
 * Unicode code point: U+2a8f (10895)
 * Description: less-than above similar above greater-than
 */
static wchar_t* LSIMG_LESS_THAN_ABOVE_SIMILAR_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lsimg";
static int* LSIMG_LESS_THAN_ABOVE_SIMILAR_ABOVE_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gsiml html character entity reference model.
 *
 * Name: gsiml
 * Character: ⪐
 * Unicode code point: U+2a90 (10896)
 * Description: greater-than above similar above less-than
 */
static wchar_t* GSIML_GREATER_THAN_ABOVE_SIMILAR_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gsiml";
static int* GSIML_GREATER_THAN_ABOVE_SIMILAR_ABOVE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lgE html character entity reference model.
 *
 * Name: lgE
 * Character: ⪑
 * Unicode code point: U+2a91 (10897)
 * Description: less-than above greater-than above double-line equal
 */
static wchar_t* LGE_LESS_THAN_ABOVE_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lgE";
static int* LGE_LESS_THAN_ABOVE_GREATER_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The glE html character entity reference model.
 *
 * Name: glE
 * Character: ⪒
 * Unicode code point: U+2a92 (10898)
 * Description: greater-than above less-than above double-line equal
 */
static wchar_t* GLE_GREATER_THAN_ABOVE_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"glE";
static int* GLE_GREATER_THAN_ABOVE_LESS_THAN_ABOVE_DOUBLE_LINE_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lesges html character entity reference model.
 *
 * Name: lesges
 * Character: ⪓
 * Unicode code point: U+2a93 (10899)
 * Description: less-than above slanted equal above greater-than above slanted equal
 */
static wchar_t* LESGES_LESS_THAN_ABOVE_SLANTED_EQUAL_ABOVE_GREATER_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lesges";
static int* LESGES_LESS_THAN_ABOVE_SLANTED_EQUAL_ABOVE_GREATER_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gesles html character entity reference model.
 *
 * Name: gesles
 * Character: ⪔
 * Unicode code point: U+2a94 (10900)
 * Description: greater-than above slanted equal above less-than above slanted equal
 */
static wchar_t* GESLES_GREATER_THAN_ABOVE_SLANTED_EQUAL_ABOVE_LESS_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gesles";
static int* GESLES_GREATER_THAN_ABOVE_SLANTED_EQUAL_ABOVE_LESS_THAN_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The els html character entity reference model.
 *
 * Name: els
 * Character: ⪕
 * Unicode code point: U+2a95 (10901)
 * Description: slanted equal to or less-than
 */
static wchar_t* ELS_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"els";
static int* ELS_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqslantless html character entity reference model.
 *
 * Name: eqslantless
 * Character: ⪕
 * Unicode code point: U+2a95 (10901)
 * Description: slanted equal to or less-than
 */
static wchar_t* EQSLANTLESS_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqslantless";
static int* EQSLANTLESS_SLANTED_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The egs html character entity reference model.
 *
 * Name: egs
 * Character: ⪖
 * Unicode code point: U+2a96 (10902)
 * Description: slanted equal to or greater-than
 */
static wchar_t* EGS_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egs";
static int* EGS_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eqslantgtr html character entity reference model.
 *
 * Name: eqslantgtr
 * Character: ⪖
 * Unicode code point: U+2a96 (10902)
 * Description: slanted equal to or greater-than
 */
static wchar_t* EQSLANTGTR_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eqslantgtr";
static int* EQSLANTGTR_SLANTED_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The elsdot html character entity reference model.
 *
 * Name: elsdot
 * Character: ⪗
 * Unicode code point: U+2a97 (10903)
 * Description: slanted equal to or less-than with dot inside
 */
static wchar_t* ELSDOT_SLANTED_EQUAL_TO_OR_LESS_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"elsdot";
static int* ELSDOT_SLANTED_EQUAL_TO_OR_LESS_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The egsdot html character entity reference model.
 *
 * Name: egsdot
 * Character: ⪘
 * Unicode code point: U+2a98 (10904)
 * Description: slanted equal to or greater-than with dot inside
 */
static wchar_t* EGSDOT_SLANTED_EQUAL_TO_OR_GREATER_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"egsdot";
static int* EGSDOT_SLANTED_EQUAL_TO_OR_GREATER_THAN_WITH_DOT_INSIDE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The el html character entity reference model.
 *
 * Name: el
 * Character: ⪙
 * Unicode code point: U+2a99 (10905)
 * Description: double-line equal to or less-than
 */
static wchar_t* EL_DOUBLE_LINE_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"el";
static int* EL_DOUBLE_LINE_EQUAL_TO_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eg html character entity reference model.
 *
 * Name: eg
 * Character: ⪚
 * Unicode code point: U+2a9a (10906)
 * Description: double-line equal to or greater-than
 */
static wchar_t* EG_DOUBLE_LINE_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eg";
static int* EG_DOUBLE_LINE_EQUAL_TO_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The siml html character entity reference model.
 *
 * Name: siml
 * Character: ⪝
 * Unicode code point: U+2a9d (10909)
 * Description: similar or less-than
 */
static wchar_t* SIML_SIMILAR_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"siml";
static int* SIML_SIMILAR_OR_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simg html character entity reference model.
 *
 * Name: simg
 * Character: ⪞
 * Unicode code point: U+2a9e (10910)
 * Description: similar or greater-than
 */
static wchar_t* SIMG_SIMILAR_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simg";
static int* SIMG_SIMILAR_OR_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simlE html character entity reference model.
 *
 * Name: simlE
 * Character: ⪟
 * Unicode code point: U+2a9f (10911)
 * Description: similar above less-than above equals sign
 */
static wchar_t* SIMLE_SIMILAR_ABOVE_LESS_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simlE";
static int* SIMLE_SIMILAR_ABOVE_LESS_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The simgE html character entity reference model.
 *
 * Name: simgE
 * Character: ⪠
 * Unicode code point: U+2aa0 (10912)
 * Description: similar above greater-than above equals sign
 */
static wchar_t* SIMGE_SIMILAR_ABOVE_GREATER_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"simgE";
static int* SIMGE_SIMILAR_ABOVE_GREATER_THAN_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The LessLess html character entity reference model.
 *
 * Name: LessLess
 * Character: ⪡
 * Unicode code point: U+2aa1 (10913)
 * Description: double nested less-than
 */
static wchar_t* LESSLESS_DOUBLE_NESTED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"LessLess";
static int* LESSLESS_DOUBLE_NESTED_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotNestedLessLess html character entity reference model.
 *
 * Name: NotNestedLessLess
 * Character: ⪡̸
 * Unicode code point: U+2aa1;U+0338 (10913;824)
 * Description: double nested less-than with slash
 */
static wchar_t* NOTNESTEDLESSLESS_DOUBLE_NESTED_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotNestedLessLess";
static int* NOTNESTEDLESSLESS_DOUBLE_NESTED_LESS_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The GreaterGreater html character entity reference model.
 *
 * Name: GreaterGreater
 * Character: ⪢
 * Unicode code point: U+2aa2 (10914)
 * Description: double nested greater-than
 */
static wchar_t* GREATERGREATER_DOUBLE_NESTED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"GreaterGreater";
static int* GREATERGREATER_DOUBLE_NESTED_GREATER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotNestedGreaterGreater html character entity reference model.
 *
 * Name: NotNestedGreaterGreater
 * Character: ⪢̸
 * Unicode code point: U+2aa2;U+0338 (10914;824)
 * Description: double nested greater-than with slash
 */
static wchar_t* NOTNESTEDGREATERGREATER_DOUBLE_NESTED_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotNestedGreaterGreater";
static int* NOTNESTEDGREATERGREATER_DOUBLE_NESTED_GREATER_THAN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The glj html character entity reference model.
 *
 * Name: glj
 * Character: ⪤
 * Unicode code point: U+2aa4 (10916)
 * Description: greater-than overlapping less-than
 */
static wchar_t* GLJ_GREATER_THAN_OVERLAPPING_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"glj";
static int* GLJ_GREATER_THAN_OVERLAPPING_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gla html character entity reference model.
 *
 * Name: gla
 * Character: ⪥
 * Unicode code point: U+2aa5 (10917)
 * Description: greater-than beside less-than
 */
static wchar_t* GLA_GREATER_THAN_BESIDE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gla";
static int* GLA_GREATER_THAN_BESIDE_LESS_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ltcc html character entity reference model.
 *
 * Name: ltcc
 * Character: ⪦
 * Unicode code point: U+2aa6 (10918)
 * Description: less-than closed by curve
 */
static wchar_t* LTCC_LESS_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ltcc";
static int* LTCC_LESS_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gtcc html character entity reference model.
 *
 * Name: gtcc
 * Character: ⪧
 * Unicode code point: U+2aa7 (10919)
 * Description: greater-than closed by curve
 */
static wchar_t* GTCC_GREATER_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gtcc";
static int* GTCC_GREATER_THAN_CLOSED_BY_CURVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lescc html character entity reference model.
 *
 * Name: lescc
 * Character: ⪨
 * Unicode code point: U+2aa8 (10920)
 * Description: less-than closed by curve above slanted equal
 */
static wchar_t* LESCC_LESS_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lescc";
static int* LESCC_LESS_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gescc html character entity reference model.
 *
 * Name: gescc
 * Character: ⪩
 * Unicode code point: U+2aa9 (10921)
 * Description: greater-than closed by curve above slanted equal
 */
static wchar_t* GESCC_GREATER_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gescc";
static int* GESCC_GREATER_THAN_CLOSED_BY_CURVE_ABOVE_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smt html character entity reference model.
 *
 * Name: smt
 * Character: ⪪
 * Unicode code point: U+2aaa (10922)
 * Description: smaller than
 */
static wchar_t* SMT_SMALLER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smt";
static int* SMT_SMALLER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lat html character entity reference model.
 *
 * Name: lat
 * Character: ⪫
 * Unicode code point: U+2aab (10923)
 * Description: larger than
 */
static wchar_t* LAT_LARGER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lat";
static int* LAT_LARGER_THAN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smte html character entity reference model.
 *
 * Name: smte
 * Character: ⪬
 * Unicode code point: U+2aac (10924)
 * Description: smaller than or equal to
 */
static wchar_t* SMTE_SMALLER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smte";
static int* SMTE_SMALLER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The smtes html character entity reference model.
 *
 * Name: smtes
 * Character: ⪬︀
 * Unicode code point: U+2aac;U+fe00 (10924;65024)
 * Description: smaller than or slanted equal
 */
static wchar_t* SMTES_SMALLER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"smtes";
static int* SMTES_SMALLER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The late html character entity reference model.
 *
 * Name: late
 * Character: ⪭
 * Unicode code point: U+2aad (10925)
 * Description: larger than or equal to
 */
static wchar_t* LATE_LARGER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"late";
static int* LATE_LARGER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lates html character entity reference model.
 *
 * Name: lates
 * Character: ⪭︀
 * Unicode code point: U+2aad;U+fe00 (10925;65024)
 * Description: larger than or slanted equal
 */
static wchar_t* LATES_LARGER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lates";
static int* LATES_LARGER_THAN_OR_SLANTED_EQUAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bumpE html character entity reference model.
 *
 * Name: bumpE
 * Character: ⪮
 * Unicode code point: U+2aae (10926)
 * Description: equals sign with bumpy above
 */
static wchar_t* BUMPE_EQUALS_SIGN_WITH_BUMPY_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bumpE";
static int* BUMPE_EQUALS_SIGN_WITH_BUMPY_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotPrecedesEqual html character entity reference model.
 *
 * Name: NotPrecedesEqual
 * Character: ⪯̸
 * Unicode code point: U+2aaf;U+0338 (10927;824)
 * Description: precedes above single-line equals sign with slash
 */
static wchar_t* NOTPRECEDESEQUAL_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotPrecedesEqual";
static int* NOTPRECEDESEQUAL_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npre html character entity reference model.
 *
 * Name: npre
 * Character: ⪯̸
 * Unicode code point: U+2aaf;U+0338 (10927;824)
 * Description: precedes above single-line equals sign with slash
 */
static wchar_t* NPRE_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npre";
static int* NPRE_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The npreceq html character entity reference model.
 *
 * Name: npreceq
 * Character: ⪯̸
 * Unicode code point: U+2aaf;U+0338 (10927;824)
 * Description: precedes above single-line equals sign with slash
 */
static wchar_t* NPRECEQ_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"npreceq";
static int* NPRECEQ_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The PrecedesEqual html character entity reference model.
 *
 * Name: PrecedesEqual
 * Character: ⪯
 * Unicode code point: U+2aaf (10927)
 * Description: precedes above single-line equals sign
 */
static wchar_t* PRECEDESEQUAL_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"PrecedesEqual";
static int* PRECEDESEQUAL_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pre html character entity reference model.
 *
 * Name: pre
 * Character: ⪯
 * Unicode code point: U+2aaf (10927)
 * Description: precedes above single-line equals sign
 */
static wchar_t* PRE_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pre";
static int* PRE_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The preceq html character entity reference model.
 *
 * Name: preceq
 * Character: ⪯
 * Unicode code point: U+2aaf (10927)
 * Description: precedes above single-line equals sign
 */
static wchar_t* PRECEQ_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"preceq";
static int* PRECEQ_PRECEDES_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The NotSucceedsEqual html character entity reference model.
 *
 * Name: NotSucceedsEqual
 * Character: ⪰̸
 * Unicode code point: U+2ab0;U+0338 (10928;824)
 * Description: succeeds above single-line equals sign with slash
 */
static wchar_t* NOTSUCCEEDSEQUAL_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"NotSucceedsEqual";
static int* NOTSUCCEEDSEQUAL_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsce html character entity reference model.
 *
 * Name: nsce
 * Character: ⪰̸
 * Unicode code point: U+2ab0;U+0338 (10928;824)
 * Description: succeeds above single-line equals sign with slash
 */
static wchar_t* NSCE_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsce";
static int* NSCE_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsucceq html character entity reference model.
 *
 * Name: nsucceq
 * Character: ⪰̸
 * Unicode code point: U+2ab0;U+0338 (10928;824)
 * Description: succeeds above single-line equals sign with slash
 */
static wchar_t* NSUCCEQ_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsucceq";
static int* NSUCCEQ_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The SucceedsEqual html character entity reference model.
 *
 * Name: SucceedsEqual
 * Character: ⪰
 * Unicode code point: U+2ab0 (10928)
 * Description: succeeds above single-line equals sign
 */
static wchar_t* SUCCEEDSEQUAL_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"SucceedsEqual";
static int* SUCCEEDSEQUAL_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sce html character entity reference model.
 *
 * Name: sce
 * Character: ⪰
 * Unicode code point: U+2ab0 (10928)
 * Description: succeeds above single-line equals sign
 */
static wchar_t* SCE_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sce";
static int* SCE_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succeq html character entity reference model.
 *
 * Name: succeq
 * Character: ⪰
 * Unicode code point: U+2ab0 (10928)
 * Description: succeeds above single-line equals sign
 */
static wchar_t* SUCCEQ_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succeq";
static int* SUCCEQ_SUCCEEDS_ABOVE_SINGLE_LINE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prE html character entity reference model.
 *
 * Name: prE
 * Character: ⪳
 * Unicode code point: U+2ab3 (10931)
 * Description: precedes above equals sign
 */
static wchar_t* PRE_PRECEDES_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prE";
static int* PRE_PRECEDES_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scE html character entity reference model.
 *
 * Name: scE
 * Character: ⪴
 * Unicode code point: U+2ab4 (10932)
 * Description: succeeds above equals sign
 */
static wchar_t* SCE_SUCCEEDS_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scE";
static int* SCE_SUCCEEDS_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precneqq html character entity reference model.
 *
 * Name: precneqq
 * Character: ⪵
 * Unicode code point: U+2ab5 (10933)
 * Description: precedes above not equal to
 */
static wchar_t* PRECNEQQ_PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precneqq";
static int* PRECNEQQ_PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prnE html character entity reference model.
 *
 * Name: prnE
 * Character: ⪵
 * Unicode code point: U+2ab5 (10933)
 * Description: precedes above not equal to
 */
static wchar_t* PRNE_PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prnE";
static int* PRNE_PRECEDES_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scnE html character entity reference model.
 *
 * Name: scnE
 * Character: ⪶
 * Unicode code point: U+2ab6 (10934)
 * Description: succeeds above not equal to
 */
static wchar_t* SCNE_SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnE";
static int* SCNE_SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succneqq html character entity reference model.
 *
 * Name: succneqq
 * Character: ⪶
 * Unicode code point: U+2ab6 (10934)
 * Description: succeeds above not equal to
 */
static wchar_t* SUCCNEQQ_SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succneqq";
static int* SUCCNEQQ_SUCCEEDS_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prap html character entity reference model.
 *
 * Name: prap
 * Character: ⪷
 * Unicode code point: U+2ab7 (10935)
 * Description: precedes above almost equal to
 */
static wchar_t* PRAP_PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prap";
static int* PRAP_PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precapprox html character entity reference model.
 *
 * Name: precapprox
 * Character: ⪷
 * Unicode code point: U+2ab7 (10935)
 * Description: precedes above almost equal to
 */
static wchar_t* PRECAPPROX_PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precapprox";
static int* PRECAPPROX_PRECEDES_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scap html character entity reference model.
 *
 * Name: scap
 * Character: ⪸
 * Unicode code point: U+2ab8 (10936)
 * Description: succeeds above almost equal to
 */
static wchar_t* SCAP_SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scap";
static int* SCAP_SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succapprox html character entity reference model.
 *
 * Name: succapprox
 * Character: ⪸
 * Unicode code point: U+2ab8 (10936)
 * Description: succeeds above almost equal to
 */
static wchar_t* SUCCAPPROX_SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succapprox";
static int* SUCCAPPROX_SUCCEEDS_ABOVE_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The precnapprox html character entity reference model.
 *
 * Name: precnapprox
 * Character: ⪹
 * Unicode code point: U+2ab9 (10937)
 * Description: precedes above not almost equal to
 */
static wchar_t* PRECNAPPROX_PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"precnapprox";
static int* PRECNAPPROX_PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prnap html character entity reference model.
 *
 * Name: prnap
 * Character: ⪹
 * Unicode code point: U+2ab9 (10937)
 * Description: precedes above not almost equal to
 */
static wchar_t* PRNAP_PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"prnap";
static int* PRNAP_PRECEDES_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The scnap html character entity reference model.
 *
 * Name: scnap
 * Character: ⪺
 * Unicode code point: U+2aba (10938)
 * Description: succeeds above not almost equal to
 */
static wchar_t* SCNAP_SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"scnap";
static int* SCNAP_SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The succnapprox html character entity reference model.
 *
 * Name: succnapprox
 * Character: ⪺
 * Unicode code point: U+2aba (10938)
 * Description: succeeds above not almost equal to
 */
static wchar_t* SUCCNAPPROX_SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"succnapprox";
static int* SUCCNAPPROX_SUCCEEDS_ABOVE_NOT_ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pr html character entity reference model.
 *
 * Name: Pr
 * Character: ⪻
 * Unicode code point: U+2abb (10939)
 * Description: double precedes
 */
static wchar_t* PR_DOUBLE_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pr";
static int* PR_DOUBLE_PRECEDES_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sc html character entity reference model.
 *
 * Name: Sc
 * Character: ⪼
 * Unicode code point: U+2abc (10940)
 * Description: double succeeds
 */
static wchar_t* SC_DOUBLE_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sc";
static int* SC_DOUBLE_SUCCEEDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subdot html character entity reference model.
 *
 * Name: subdot
 * Character: ⪽
 * Unicode code point: U+2abd (10941)
 * Description: subset with dot
 */
static wchar_t* SUBDOT_SUBSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subdot";
static int* SUBDOT_SUBSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supdot html character entity reference model.
 *
 * Name: supdot
 * Character: ⪾
 * Unicode code point: U+2abe (10942)
 * Description: superset with dot
 */
static wchar_t* SUPDOT_SUPERSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supdot";
static int* SUPDOT_SUPERSET_WITH_DOT_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subplus html character entity reference model.
 *
 * Name: subplus
 * Character: ⪿
 * Unicode code point: U+2abf (10943)
 * Description: subset with plus sign below
 */
static wchar_t* SUBPLUS_SUBSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subplus";
static int* SUBPLUS_SUBSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supplus html character entity reference model.
 *
 * Name: supplus
 * Character: ⫀
 * Unicode code point: U+2ac0 (10944)
 * Description: superset with plus sign below
 */
static wchar_t* SUPPLUS_SUPERSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supplus";
static int* SUPPLUS_SUPERSET_WITH_PLUS_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The submult html character entity reference model.
 *
 * Name: submult
 * Character: ⫁
 * Unicode code point: U+2ac1 (10945)
 * Description: subset with multiplication sign below
 */
static wchar_t* SUBMULT_SUBSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"submult";
static int* SUBMULT_SUBSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supmult html character entity reference model.
 *
 * Name: supmult
 * Character: ⫂
 * Unicode code point: U+2ac2 (10946)
 * Description: superset with multiplication sign below
 */
static wchar_t* SUPMULT_SUPERSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supmult";
static int* SUPMULT_SUPERSET_WITH_MULTIPLICATION_SIGN_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subedot html character entity reference model.
 *
 * Name: subedot
 * Character: ⫃
 * Unicode code point: U+2ac3 (10947)
 * Description: subset of or equal to with dot above
 */
static wchar_t* SUBEDOT_SUBSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subedot";
static int* SUBEDOT_SUBSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supedot html character entity reference model.
 *
 * Name: supedot
 * Character: ⫄
 * Unicode code point: U+2ac4 (10948)
 * Description: superset of or equal to with dot above
 */
static wchar_t* SUPEDOT_SUPERSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supedot";
static int* SUPEDOT_SUPERSET_OF_OR_EQUAL_TO_WITH_DOT_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsubE html character entity reference model.
 *
 * Name: nsubE
 * Character: ⫅̸
 * Unicode code point: U+2ac5;U+0338 (10949;824)
 * Description: subset of above equals sign with slash
 */
static wchar_t* NSUBE_SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsubE";
static int* NSUBE_SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsubseteqq html character entity reference model.
 *
 * Name: nsubseteqq
 * Character: ⫅̸
 * Unicode code point: U+2ac5;U+0338 (10949;824)
 * Description: subset of above equals sign with slash
 */
static wchar_t* NSUBSETEQQ_SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsubseteqq";
static int* NSUBSETEQQ_SUBSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subE html character entity reference model.
 *
 * Name: subE
 * Character: ⫅
 * Unicode code point: U+2ac5 (10949)
 * Description: subset of above equals sign
 */
static wchar_t* SUBE_SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subE";
static int* SUBE_SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subseteqq html character entity reference model.
 *
 * Name: subseteqq
 * Character: ⫅
 * Unicode code point: U+2ac5 (10949)
 * Description: subset of above equals sign
 */
static wchar_t* SUBSETEQQ_SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subseteqq";
static int* SUBSETEQQ_SUBSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsupE html character entity reference model.
 *
 * Name: nsupE
 * Character: ⫆̸
 * Unicode code point: U+2ac6;U+0338 (10950;824)
 * Description: superset of above equals sign with slash
 */
static wchar_t* NSUPE_SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupE";
static int* NSUPE_SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nsupseteqq html character entity reference model.
 *
 * Name: nsupseteqq
 * Character: ⫆̸
 * Unicode code point: U+2ac6;U+0338 (10950;824)
 * Description: superset of above equals sign with slash
 */
static wchar_t* NSUPSETEQQ_SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nsupseteqq";
static int* NSUPSETEQQ_SUPERSET_OF_ABOVE_EQUALS_SIGN_WITH_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supE html character entity reference model.
 *
 * Name: supE
 * Character: ⫆
 * Unicode code point: U+2ac6 (10950)
 * Description: superset of above equals sign
 */
static wchar_t* SUPE_SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supE";
static int* SUPE_SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supseteqq html character entity reference model.
 *
 * Name: supseteqq
 * Character: ⫆
 * Unicode code point: U+2ac6 (10950)
 * Description: superset of above equals sign
 */
static wchar_t* SUPSETEQQ_SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supseteqq";
static int* SUPSETEQQ_SUPERSET_OF_ABOVE_EQUALS_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subsim html character entity reference model.
 *
 * Name: subsim
 * Character: ⫇
 * Unicode code point: U+2ac7 (10951)
 * Description: subset of above tilde operator
 */
static wchar_t* SUBSIM_SUBSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsim";
static int* SUBSIM_SUBSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supsim html character entity reference model.
 *
 * Name: supsim
 * Character: ⫈
 * Unicode code point: U+2ac8 (10952)
 * Description: superset of above tilde operator
 */
static wchar_t* SUPSIM_SUPERSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsim";
static int* SUPSIM_SUPERSET_OF_ABOVE_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subnE html character entity reference model.
 *
 * Name: subnE
 * Character: ⫋
 * Unicode code point: U+2acb (10955)
 * Description: subset of above not equal to
 */
static wchar_t* SUBNE_SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subnE";
static int* SUBNE_SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subsetneqq html character entity reference model.
 *
 * Name: subsetneqq
 * Character: ⫋
 * Unicode code point: U+2acb (10955)
 * Description: subset of above not equal to
 */
static wchar_t* SUBSETNEQQ_SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsetneqq";
static int* SUBSETNEQQ_SUBSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varsubsetneqq html character entity reference model.
 *
 * Name: varsubsetneqq
 * Character: ⫋︀
 * Unicode code point: U+2acb;U+fe00 (10955;65024)
 * Description: subset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* VARSUBSETNEQQ_SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsubsetneqq";
static int* VARSUBSETNEQQ_SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vsubnE html character entity reference model.
 *
 * Name: vsubnE
 * Character: ⫋︀
 * Unicode code point: U+2acb;U+fe00 (10955;65024)
 * Description: subset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* VSUBNE_SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vsubnE";
static int* VSUBNE_SUBSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supnE html character entity reference model.
 *
 * Name: supnE
 * Character: ⫌
 * Unicode code point: U+2acc (10956)
 * Description: superset of above not equal to
 */
static wchar_t* SUPNE_SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supnE";
static int* SUPNE_SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supsetneqq html character entity reference model.
 *
 * Name: supsetneqq
 * Character: ⫌
 * Unicode code point: U+2acc (10956)
 * Description: superset of above not equal to
 */
static wchar_t* SUPSETNEQQ_SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsetneqq";
static int* SUPSETNEQQ_SUPERSET_OF_ABOVE_NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The varsupsetneqq html character entity reference model.
 *
 * Name: varsupsetneqq
 * Character: ⫌︀
 * Unicode code point: U+2acc;U+fe00 (10956;65024)
 * Description: superset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* VARSUPSETNEQQ_SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"varsupsetneqq";
static int* VARSUPSETNEQQ_SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vsupnE html character entity reference model.
 *
 * Name: vsupnE
 * Character: ⫌︀
 * Unicode code point: U+2acc;U+fe00 (10956;65024)
 * Description: superset of above not equal to - variant with stroke through bottom members
 */
static wchar_t* VSUPNE_SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vsupnE";
static int* VSUPNE_SUPERSET_OF_ABOVE_NOT_EQUAL_TO___VARIANT_WITH_STROKE_THROUGH_BOTTOM_MEMBERS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The csub html character entity reference model.
 *
 * Name: csub
 * Character: ⫏
 * Unicode code point: U+2acf (10959)
 * Description: closed subset
 */
static wchar_t* CSUB_CLOSED_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csub";
static int* CSUB_CLOSED_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The csup html character entity reference model.
 *
 * Name: csup
 * Character: ⫐
 * Unicode code point: U+2ad0 (10960)
 * Description: closed superset
 */
static wchar_t* CSUP_CLOSED_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csup";
static int* CSUP_CLOSED_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The csube html character entity reference model.
 *
 * Name: csube
 * Character: ⫑
 * Unicode code point: U+2ad1 (10961)
 * Description: closed subset or equal to
 */
static wchar_t* CSUBE_CLOSED_SUBSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csube";
static int* CSUBE_CLOSED_SUBSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The csupe html character entity reference model.
 *
 * Name: csupe
 * Character: ⫒
 * Unicode code point: U+2ad2 (10962)
 * Description: closed superset or equal to
 */
static wchar_t* CSUPE_CLOSED_SUPERSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"csupe";
static int* CSUPE_CLOSED_SUPERSET_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subsup html character entity reference model.
 *
 * Name: subsup
 * Character: ⫓
 * Unicode code point: U+2ad3 (10963)
 * Description: subset above superset
 */
static wchar_t* SUBSUP_SUBSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsup";
static int* SUBSUP_SUBSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supsub html character entity reference model.
 *
 * Name: supsub
 * Character: ⫔
 * Unicode code point: U+2ad4 (10964)
 * Description: superset above subset
 */
static wchar_t* SUPSUB_SUPERSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsub";
static int* SUPSUB_SUPERSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The subsub html character entity reference model.
 *
 * Name: subsub
 * Character: ⫕
 * Unicode code point: U+2ad5 (10965)
 * Description: subset above subset
 */
static wchar_t* SUBSUB_SUBSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"subsub";
static int* SUBSUB_SUBSET_ABOVE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supsup html character entity reference model.
 *
 * Name: supsup
 * Character: ⫖
 * Unicode code point: U+2ad6 (10966)
 * Description: superset above superset
 */
static wchar_t* SUPSUP_SUPERSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supsup";
static int* SUPSUP_SUPERSET_ABOVE_SUPERSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The suphsub html character entity reference model.
 *
 * Name: suphsub
 * Character: ⫗
 * Unicode code point: U+2ad7 (10967)
 * Description: superset beside subset
 */
static wchar_t* SUPHSUB_SUPERSET_BESIDE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"suphsub";
static int* SUPHSUB_SUPERSET_BESIDE_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The supdsub html character entity reference model.
 *
 * Name: supdsub
 * Character: ⫘
 * Unicode code point: U+2ad8 (10968)
 * Description: superset beside and joined by dash with subset
 */
static wchar_t* SUPDSUB_SUPERSET_BESIDE_AND_JOINED_BY_DASH_WITH_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"supdsub";
static int* SUPDSUB_SUPERSET_BESIDE_AND_JOINED_BY_DASH_WITH_SUBSET_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The forkv html character entity reference model.
 *
 * Name: forkv
 * Character: ⫙
 * Unicode code point: U+2ad9 (10969)
 * Description: element of opening downwards
 */
static wchar_t* FORKV_ELEMENT_OF_OPENING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"forkv";
static int* FORKV_ELEMENT_OF_OPENING_DOWNWARDS_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The topfork html character entity reference model.
 *
 * Name: topfork
 * Character: ⫚
 * Unicode code point: U+2ada (10970)
 * Description: pitchfork with tee top
 */
static wchar_t* TOPFORK_PITCHFORK_WITH_TEE_TOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topfork";
static int* TOPFORK_PITCHFORK_WITH_TEE_TOP_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mlcp html character entity reference model.
 *
 * Name: mlcp
 * Character: ⫛
 * Unicode code point: U+2adb (10971)
 * Description: transversal intersection
 */
static wchar_t* MLCP_TRANSVERSAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mlcp";
static int* MLCP_TRANSVERSAL_INTERSECTION_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dashv html character entity reference model.
 *
 * Name: Dashv
 * Character: ⫤
 * Unicode code point: U+2ae4 (10980)
 * Description: vertical bar double left turnstile
 */
static wchar_t* DASHV_VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dashv";
static int* DASHV_VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The DoubleLeftTee html character entity reference model.
 *
 * Name: DoubleLeftTee
 * Character: ⫤
 * Unicode code point: U+2ae4 (10980)
 * Description: vertical bar double left turnstile
 */
static wchar_t* DOUBLELEFTTEE_VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"DoubleLeftTee";
static int* DOUBLELEFTTEE_VERTICAL_BAR_DOUBLE_LEFT_TURNSTILE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vdashl html character entity reference model.
 *
 * Name: Vdashl
 * Character: ⫦
 * Unicode code point: U+2ae6 (10982)
 * Description: long dash from left member of double vertical
 */
static wchar_t* VDASHL_LONG_DASH_FROM_LEFT_MEMBER_OF_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vdashl";
static int* VDASHL_LONG_DASH_FROM_LEFT_MEMBER_OF_DOUBLE_VERTICAL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Barv html character entity reference model.
 *
 * Name: Barv
 * Character: ⫧
 * Unicode code point: U+2ae7 (10983)
 * Description: short down tack with overbar
 */
static wchar_t* BARV_SHORT_DOWN_TACK_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Barv";
static int* BARV_SHORT_DOWN_TACK_WITH_OVERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vBar html character entity reference model.
 *
 * Name: vBar
 * Character: ⫨
 * Unicode code point: U+2ae8 (10984)
 * Description: short up tack with underbar
 */
static wchar_t* VBAR_SHORT_UP_TACK_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vBar";
static int* VBAR_SHORT_UP_TACK_WITH_UNDERBAR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vBarv html character entity reference model.
 *
 * Name: vBarv
 * Character: ⫩
 * Unicode code point: U+2ae9 (10985)
 * Description: short up tack above short down tack
 */
static wchar_t* VBARV_SHORT_UP_TACK_ABOVE_SHORT_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vBarv";
static int* VBARV_SHORT_UP_TACK_ABOVE_SHORT_DOWN_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vbar html character entity reference model.
 *
 * Name: Vbar
 * Character: ⫫
 * Unicode code point: U+2aeb (10987)
 * Description: double up tack
 */
static wchar_t* VBAR_DOUBLE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vbar";
static int* VBAR_DOUBLE_UP_TACK_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Not html character entity reference model.
 *
 * Name: Not
 * Character: ⫬
 * Unicode code point: U+2aec (10988)
 * Description: double stroke not sign
 */
static wchar_t* NOT_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Not";
static int* NOT_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bNot html character entity reference model.
 *
 * Name: bNot
 * Character: ⫭
 * Unicode code point: U+2aed (10989)
 * Description: reversed double stroke not sign
 */
static wchar_t* BNOT_REVERSED_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bNot";
static int* BNOT_REVERSED_DOUBLE_STROKE_NOT_SIGN_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rnmid html character entity reference model.
 *
 * Name: rnmid
 * Character: ⫮
 * Unicode code point: U+2aee (10990)
 * Description: does not divide with reversed negation slash
 */
static wchar_t* RNMID_DOES_NOT_DIVIDE_WITH_REVERSED_NEGATION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rnmid";
static int* RNMID_DOES_NOT_DIVIDE_WITH_REVERSED_NEGATION_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cirmid html character entity reference model.
 *
 * Name: cirmid
 * Character: ⫯
 * Unicode code point: U+2aef (10991)
 * Description: vertical line with circle above
 */
static wchar_t* CIRMID_VERTICAL_LINE_WITH_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cirmid";
static int* CIRMID_VERTICAL_LINE_WITH_CIRCLE_ABOVE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The midcir html character entity reference model.
 *
 * Name: midcir
 * Character: ⫰
 * Unicode code point: U+2af0 (10992)
 * Description: vertical line with circle below
 */
static wchar_t* MIDCIR_VERTICAL_LINE_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"midcir";
static int* MIDCIR_VERTICAL_LINE_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The topcir html character entity reference model.
 *
 * Name: topcir
 * Character: ⫱
 * Unicode code point: U+2af1 (10993)
 * Description: down tack with circle below
 */
static wchar_t* TOPCIR_DOWN_TACK_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topcir";
static int* TOPCIR_DOWN_TACK_WITH_CIRCLE_BELOW_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nhpar html character entity reference model.
 *
 * Name: nhpar
 * Character: ⫲
 * Unicode code point: U+2af2 (10994)
 * Description: parallel with horizontal stroke
 */
static wchar_t* NHPAR_PARALLEL_WITH_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nhpar";
static int* NHPAR_PARALLEL_WITH_HORIZONTAL_STROKE_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parsim html character entity reference model.
 *
 * Name: parsim
 * Character: ⫳
 * Unicode code point: U+2af3 (10995)
 * Description: parallel with tilde operator
 */
static wchar_t* PARSIM_PARALLEL_WITH_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"parsim";
static int* PARSIM_PARALLEL_WITH_TILDE_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nparsl html character entity reference model.
 *
 * Name: nparsl
 * Character: ⫽⃥
 * Unicode code point: U+2afd;U+20e5 (11005;8421)
 * Description: double solidus operator with reverse slash
 */
static wchar_t* NPARSL_DOUBLE_SOLIDUS_OPERATOR_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nparsl";
static int* NPARSL_DOUBLE_SOLIDUS_OPERATOR_WITH_REVERSE_SLASH_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The parsl html character entity reference model.
 *
 * Name: parsl
 * Character: ⫽
 * Unicode code point: U+2afd (11005)
 * Description: double solidus operator
 */
static wchar_t* PARSL_DOUBLE_SOLIDUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"parsl";
static int* PARSL_DOUBLE_SOLIDUS_OPERATOR_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ascr html character entity reference model.
 *
 * Name: Ascr
 * Character: 𝒜
 * Unicode code point: U+d49c (54428)
 * Description: mathematical script capital a
 */
static wchar_t* ASCR_MATHEMATICAL_SCRIPT_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ascr";
static int* ASCR_MATHEMATICAL_SCRIPT_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Cscr html character entity reference model.
 *
 * Name: Cscr
 * Character: 𝒞
 * Unicode code point: U+d49e (54430)
 * Description: mathematical script capital c
 */
static wchar_t* CSCR_MATHEMATICAL_SCRIPT_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Cscr";
static int* CSCR_MATHEMATICAL_SCRIPT_CAPITAL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dscr html character entity reference model.
 *
 * Name: Dscr
 * Character: 𝒟
 * Unicode code point: U+d49f (54431)
 * Description: mathematical script capital d
 */
static wchar_t* DSCR_MATHEMATICAL_SCRIPT_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dscr";
static int* DSCR_MATHEMATICAL_SCRIPT_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gscr html character entity reference model.
 *
 * Name: Gscr
 * Character: 𝒢
 * Unicode code point: U+d4a2 (54434)
 * Description: mathematical script capital g
 */
static wchar_t* GSCR_MATHEMATICAL_SCRIPT_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gscr";
static int* GSCR_MATHEMATICAL_SCRIPT_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jscr html character entity reference model.
 *
 * Name: Jscr
 * Character: 𝒥
 * Unicode code point: U+d4a5 (54437)
 * Description: mathematical script capital j
 */
static wchar_t* JSCR_MATHEMATICAL_SCRIPT_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jscr";
static int* JSCR_MATHEMATICAL_SCRIPT_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kscr html character entity reference model.
 *
 * Name: Kscr
 * Character: 𝒦
 * Unicode code point: U+d4a6 (54438)
 * Description: mathematical script capital k
 */
static wchar_t* KSCR_MATHEMATICAL_SCRIPT_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kscr";
static int* KSCR_MATHEMATICAL_SCRIPT_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Nscr html character entity reference model.
 *
 * Name: Nscr
 * Character: 𝒩
 * Unicode code point: U+d4a9 (54441)
 * Description: mathematical script capital n
 */
static wchar_t* NSCR_MATHEMATICAL_SCRIPT_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nscr";
static int* NSCR_MATHEMATICAL_SCRIPT_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Oscr html character entity reference model.
 *
 * Name: Oscr
 * Character: 𝒪
 * Unicode code point: U+d4aa (54442)
 * Description: mathematical script capital o
 */
static wchar_t* OSCR_MATHEMATICAL_SCRIPT_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oscr";
static int* OSCR_MATHEMATICAL_SCRIPT_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pscr html character entity reference model.
 *
 * Name: Pscr
 * Character: 𝒫
 * Unicode code point: U+d4ab (54443)
 * Description: mathematical script capital p
 */
static wchar_t* PSCR_MATHEMATICAL_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pscr";
static int* PSCR_MATHEMATICAL_SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Qscr html character entity reference model.
 *
 * Name: Qscr
 * Character: 𝒬
 * Unicode code point: U+d4ac (54444)
 * Description: mathematical script capital q
 */
static wchar_t* QSCR_MATHEMATICAL_SCRIPT_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qscr";
static int* QSCR_MATHEMATICAL_SCRIPT_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sscr html character entity reference model.
 *
 * Name: Sscr
 * Character: 𝒮
 * Unicode code point: U+d4ae (54446)
 * Description: mathematical script capital s
 */
static wchar_t* SSCR_MATHEMATICAL_SCRIPT_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sscr";
static int* SSCR_MATHEMATICAL_SCRIPT_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tscr html character entity reference model.
 *
 * Name: Tscr
 * Character: 𝒯
 * Unicode code point: U+d4af (54447)
 * Description: mathematical script capital t
 */
static wchar_t* TSCR_MATHEMATICAL_SCRIPT_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tscr";
static int* TSCR_MATHEMATICAL_SCRIPT_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uscr html character entity reference model.
 *
 * Name: Uscr
 * Character: 𝒰
 * Unicode code point: U+d4b0 (54448)
 * Description: mathematical script capital u
 */
static wchar_t* USCR_MATHEMATICAL_SCRIPT_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uscr";
static int* USCR_MATHEMATICAL_SCRIPT_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vscr html character entity reference model.
 *
 * Name: Vscr
 * Character: 𝒱
 * Unicode code point: U+d4b1 (54449)
 * Description: mathematical script capital v
 */
static wchar_t* VSCR_MATHEMATICAL_SCRIPT_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vscr";
static int* VSCR_MATHEMATICAL_SCRIPT_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Wscr html character entity reference model.
 *
 * Name: Wscr
 * Character: 𝒲
 * Unicode code point: U+d4b2 (54450)
 * Description: mathematical script capital w
 */
static wchar_t* WSCR_MATHEMATICAL_SCRIPT_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wscr";
static int* WSCR_MATHEMATICAL_SCRIPT_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Xscr html character entity reference model.
 *
 * Name: Xscr
 * Character: 𝒳
 * Unicode code point: U+d4b3 (54451)
 * Description: mathematical script capital x
 */
static wchar_t* XSCR_MATHEMATICAL_SCRIPT_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xscr";
static int* XSCR_MATHEMATICAL_SCRIPT_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Yscr html character entity reference model.
 *
 * Name: Yscr
 * Character: 𝒴
 * Unicode code point: U+d4b4 (54452)
 * Description: mathematical script capital y
 */
static wchar_t* YSCR_MATHEMATICAL_SCRIPT_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yscr";
static int* YSCR_MATHEMATICAL_SCRIPT_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Zscr html character entity reference model.
 *
 * Name: Zscr
 * Character: 𝒵
 * Unicode code point: U+d4b5 (54453)
 * Description: mathematical script capital z
 */
static wchar_t* ZSCR_MATHEMATICAL_SCRIPT_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Zscr";
static int* ZSCR_MATHEMATICAL_SCRIPT_CAPITAL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ascr html character entity reference model.
 *
 * Name: ascr
 * Character: 𝒶
 * Unicode code point: U+d4b6 (54454)
 * Description: mathematical script small a
 */
static wchar_t* ASCR_MATHEMATICAL_SCRIPT_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ascr";
static int* ASCR_MATHEMATICAL_SCRIPT_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bscr html character entity reference model.
 *
 * Name: bscr
 * Character: 𝒷
 * Unicode code point: U+d4b7 (54455)
 * Description: mathematical script small b
 */
static wchar_t* BSCR_MATHEMATICAL_SCRIPT_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bscr";
static int* BSCR_MATHEMATICAL_SCRIPT_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cscr html character entity reference model.
 *
 * Name: cscr
 * Character: 𝒸
 * Unicode code point: U+d4b8 (54456)
 * Description: mathematical script small c
 */
static wchar_t* CSCR_MATHEMATICAL_SCRIPT_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cscr";
static int* CSCR_MATHEMATICAL_SCRIPT_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dscr html character entity reference model.
 *
 * Name: dscr
 * Character: 𝒹
 * Unicode code point: U+d4b9 (54457)
 * Description: mathematical script small d
 */
static wchar_t* DSCR_MATHEMATICAL_SCRIPT_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dscr";
static int* DSCR_MATHEMATICAL_SCRIPT_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fscr html character entity reference model.
 *
 * Name: fscr
 * Character: 𝒻
 * Unicode code point: U+d4bb (54459)
 * Description: mathematical script small f
 */
static wchar_t* FSCR_MATHEMATICAL_SCRIPT_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fscr";
static int* FSCR_MATHEMATICAL_SCRIPT_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hscr html character entity reference model.
 *
 * Name: hscr
 * Character: 𝒽
 * Unicode code point: U+d4bd (54461)
 * Description: mathematical script small h
 */
static wchar_t* HSCR_MATHEMATICAL_SCRIPT_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hscr";
static int* HSCR_MATHEMATICAL_SCRIPT_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iscr html character entity reference model.
 *
 * Name: iscr
 * Character: 𝒾
 * Unicode code point: U+d4be (54462)
 * Description: mathematical script small i
 */
static wchar_t* ISCR_MATHEMATICAL_SCRIPT_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iscr";
static int* ISCR_MATHEMATICAL_SCRIPT_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jscr html character entity reference model.
 *
 * Name: jscr
 * Character: 𝒿
 * Unicode code point: U+d4bf (54463)
 * Description: mathematical script small j
 */
static wchar_t* JSCR_MATHEMATICAL_SCRIPT_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jscr";
static int* JSCR_MATHEMATICAL_SCRIPT_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kscr html character entity reference model.
 *
 * Name: kscr
 * Character: 𝓀
 * Unicode code point: U+d4c0 (54464)
 * Description: mathematical script small k
 */
static wchar_t* KSCR_MATHEMATICAL_SCRIPT_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kscr";
static int* KSCR_MATHEMATICAL_SCRIPT_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lscr html character entity reference model.
 *
 * Name: lscr
 * Character: 𝓁
 * Unicode code point: U+d4c1 (54465)
 * Description: mathematical script small l
 */
static wchar_t* LSCR_MATHEMATICAL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lscr";
static int* LSCR_MATHEMATICAL_SCRIPT_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mscr html character entity reference model.
 *
 * Name: mscr
 * Character: 𝓂
 * Unicode code point: U+d4c2 (54466)
 * Description: mathematical script small m
 */
static wchar_t* MSCR_MATHEMATICAL_SCRIPT_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mscr";
static int* MSCR_MATHEMATICAL_SCRIPT_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nscr html character entity reference model.
 *
 * Name: nscr
 * Character: 𝓃
 * Unicode code point: U+d4c3 (54467)
 * Description: mathematical script small n
 */
static wchar_t* NSCR_MATHEMATICAL_SCRIPT_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nscr";
static int* NSCR_MATHEMATICAL_SCRIPT_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pscr html character entity reference model.
 *
 * Name: pscr
 * Character: 𝓅
 * Unicode code point: U+d4c5 (54469)
 * Description: mathematical script small p
 */
static wchar_t* PSCR_MATHEMATICAL_SCRIPT_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pscr";
static int* PSCR_MATHEMATICAL_SCRIPT_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qscr html character entity reference model.
 *
 * Name: qscr
 * Character: 𝓆
 * Unicode code point: U+d4c6 (54470)
 * Description: mathematical script small q
 */
static wchar_t* QSCR_MATHEMATICAL_SCRIPT_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qscr";
static int* QSCR_MATHEMATICAL_SCRIPT_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rscr html character entity reference model.
 *
 * Name: rscr
 * Character: 𝓇
 * Unicode code point: U+d4c7 (54471)
 * Description: mathematical script small r
 */
static wchar_t* RSCR_MATHEMATICAL_SCRIPT_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rscr";
static int* RSCR_MATHEMATICAL_SCRIPT_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sscr html character entity reference model.
 *
 * Name: sscr
 * Character: 𝓈
 * Unicode code point: U+d4c8 (54472)
 * Description: mathematical script small s
 */
static wchar_t* SSCR_MATHEMATICAL_SCRIPT_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sscr";
static int* SSCR_MATHEMATICAL_SCRIPT_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tscr html character entity reference model.
 *
 * Name: tscr
 * Character: 𝓉
 * Unicode code point: U+d4c9 (54473)
 * Description: mathematical script small t
 */
static wchar_t* TSCR_MATHEMATICAL_SCRIPT_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tscr";
static int* TSCR_MATHEMATICAL_SCRIPT_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uscr html character entity reference model.
 *
 * Name: uscr
 * Character: 𝓊
 * Unicode code point: U+d4ca (54474)
 * Description: mathematical script small u
 */
static wchar_t* USCR_MATHEMATICAL_SCRIPT_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uscr";
static int* USCR_MATHEMATICAL_SCRIPT_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vscr html character entity reference model.
 *
 * Name: vscr
 * Character: 𝓋
 * Unicode code point: U+d4cb (54475)
 * Description: mathematical script small v
 */
static wchar_t* VSCR_MATHEMATICAL_SCRIPT_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vscr";
static int* VSCR_MATHEMATICAL_SCRIPT_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wscr html character entity reference model.
 *
 * Name: wscr
 * Character: 𝓌
 * Unicode code point: U+d4cc (54476)
 * Description: mathematical script small w
 */
static wchar_t* WSCR_MATHEMATICAL_SCRIPT_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wscr";
static int* WSCR_MATHEMATICAL_SCRIPT_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xscr html character entity reference model.
 *
 * Name: xscr
 * Character: 𝓍
 * Unicode code point: U+d4cd (54477)
 * Description: mathematical script small x
 */
static wchar_t* XSCR_MATHEMATICAL_SCRIPT_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xscr";
static int* XSCR_MATHEMATICAL_SCRIPT_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yscr html character entity reference model.
 *
 * Name: yscr
 * Character: 𝓎
 * Unicode code point: U+d4ce (54478)
 * Description: mathematical script small y
 */
static wchar_t* YSCR_MATHEMATICAL_SCRIPT_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yscr";
static int* YSCR_MATHEMATICAL_SCRIPT_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zscr html character entity reference model.
 *
 * Name: zscr
 * Character: 𝓏
 * Unicode code point: U+d4cf (54479)
 * Description: mathematical script small z
 */
static wchar_t* ZSCR_MATHEMATICAL_SCRIPT_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zscr";
static int* ZSCR_MATHEMATICAL_SCRIPT_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Afr html character entity reference model.
 *
 * Name: Afr
 * Character: 𝔄
 * Unicode code point: U+d504 (54532)
 * Description: mathematical fraktur capital a
 */
static wchar_t* AFR_MATHEMATICAL_FRAKTUR_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Afr";
static int* AFR_MATHEMATICAL_FRAKTUR_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bfr html character entity reference model.
 *
 * Name: Bfr
 * Character: 𝔅
 * Unicode code point: U+d505 (54533)
 * Description: mathematical fraktur capital b
 */
static wchar_t* BFR_MATHEMATICAL_FRAKTUR_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bfr";
static int* BFR_MATHEMATICAL_FRAKTUR_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dfr html character entity reference model.
 *
 * Name: Dfr
 * Character: 𝔇
 * Unicode code point: U+d507 (54535)
 * Description: mathematical fraktur capital d
 */
static wchar_t* DFR_MATHEMATICAL_FRAKTUR_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dfr";
static int* DFR_MATHEMATICAL_FRAKTUR_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Efr html character entity reference model.
 *
 * Name: Efr
 * Character: 𝔈
 * Unicode code point: U+d508 (54536)
 * Description: mathematical fraktur capital e
 */
static wchar_t* EFR_MATHEMATICAL_FRAKTUR_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Efr";
static int* EFR_MATHEMATICAL_FRAKTUR_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ffr html character entity reference model.
 *
 * Name: Ffr
 * Character: 𝔉
 * Unicode code point: U+d509 (54537)
 * Description: mathematical fraktur capital f
 */
static wchar_t* FFR_MATHEMATICAL_FRAKTUR_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ffr";
static int* FFR_MATHEMATICAL_FRAKTUR_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gfr html character entity reference model.
 *
 * Name: Gfr
 * Character: 𝔊
 * Unicode code point: U+d50a (54538)
 * Description: mathematical fraktur capital g
 */
static wchar_t* GFR_MATHEMATICAL_FRAKTUR_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gfr";
static int* GFR_MATHEMATICAL_FRAKTUR_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jfr html character entity reference model.
 *
 * Name: Jfr
 * Character: 𝔍
 * Unicode code point: U+d50d (54541)
 * Description: mathematical fraktur capital j
 */
static wchar_t* JFR_MATHEMATICAL_FRAKTUR_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jfr";
static int* JFR_MATHEMATICAL_FRAKTUR_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kfr html character entity reference model.
 *
 * Name: Kfr
 * Character: 𝔎
 * Unicode code point: U+d50e (54542)
 * Description: mathematical fraktur capital k
 */
static wchar_t* KFR_MATHEMATICAL_FRAKTUR_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kfr";
static int* KFR_MATHEMATICAL_FRAKTUR_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lfr html character entity reference model.
 *
 * Name: Lfr
 * Character: 𝔏
 * Unicode code point: U+d50f (54543)
 * Description: mathematical fraktur capital l
 */
static wchar_t* LFR_MATHEMATICAL_FRAKTUR_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lfr";
static int* LFR_MATHEMATICAL_FRAKTUR_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mfr html character entity reference model.
 *
 * Name: Mfr
 * Character: 𝔐
 * Unicode code point: U+d510 (54544)
 * Description: mathematical fraktur capital m
 */
static wchar_t* MFR_MATHEMATICAL_FRAKTUR_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mfr";
static int* MFR_MATHEMATICAL_FRAKTUR_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Nfr html character entity reference model.
 *
 * Name: Nfr
 * Character: 𝔑
 * Unicode code point: U+d511 (54545)
 * Description: mathematical fraktur capital n
 */
static wchar_t* NFR_MATHEMATICAL_FRAKTUR_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Nfr";
static int* NFR_MATHEMATICAL_FRAKTUR_CAPITAL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ofr html character entity reference model.
 *
 * Name: Ofr
 * Character: 𝔒
 * Unicode code point: U+d512 (54546)
 * Description: mathematical fraktur capital o
 */
static wchar_t* OFR_MATHEMATICAL_FRAKTUR_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ofr";
static int* OFR_MATHEMATICAL_FRAKTUR_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Pfr html character entity reference model.
 *
 * Name: Pfr
 * Character: 𝔓
 * Unicode code point: U+d513 (54547)
 * Description: mathematical fraktur capital p
 */
static wchar_t* PFR_MATHEMATICAL_FRAKTUR_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Pfr";
static int* PFR_MATHEMATICAL_FRAKTUR_CAPITAL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Qfr html character entity reference model.
 *
 * Name: Qfr
 * Character: 𝔔
 * Unicode code point: U+d514 (54548)
 * Description: mathematical fraktur capital q
 */
static wchar_t* QFR_MATHEMATICAL_FRAKTUR_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Qfr";
static int* QFR_MATHEMATICAL_FRAKTUR_CAPITAL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sfr html character entity reference model.
 *
 * Name: Sfr
 * Character: 𝔖
 * Unicode code point: U+d516 (54550)
 * Description: mathematical fraktur capital s
 */
static wchar_t* SFR_MATHEMATICAL_FRAKTUR_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sfr";
static int* SFR_MATHEMATICAL_FRAKTUR_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Tfr html character entity reference model.
 *
 * Name: Tfr
 * Character: 𝔗
 * Unicode code point: U+d517 (54551)
 * Description: mathematical fraktur capital t
 */
static wchar_t* TFR_MATHEMATICAL_FRAKTUR_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Tfr";
static int* TFR_MATHEMATICAL_FRAKTUR_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Ufr html character entity reference model.
 *
 * Name: Ufr
 * Character: 𝔘
 * Unicode code point: U+d518 (54552)
 * Description: mathematical fraktur capital u
 */
static wchar_t* UFR_MATHEMATICAL_FRAKTUR_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Ufr";
static int* UFR_MATHEMATICAL_FRAKTUR_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vfr html character entity reference model.
 *
 * Name: Vfr
 * Character: 𝔙
 * Unicode code point: U+d519 (54553)
 * Description: mathematical fraktur capital v
 */
static wchar_t* VFR_MATHEMATICAL_FRAKTUR_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vfr";
static int* VFR_MATHEMATICAL_FRAKTUR_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Wfr html character entity reference model.
 *
 * Name: Wfr
 * Character: 𝔚
 * Unicode code point: U+d51a (54554)
 * Description: mathematical fraktur capital w
 */
static wchar_t* WFR_MATHEMATICAL_FRAKTUR_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wfr";
static int* WFR_MATHEMATICAL_FRAKTUR_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Xfr html character entity reference model.
 *
 * Name: Xfr
 * Character: 𝔛
 * Unicode code point: U+d51b (54555)
 * Description: mathematical fraktur capital x
 */
static wchar_t* XFR_MATHEMATICAL_FRAKTUR_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xfr";
static int* XFR_MATHEMATICAL_FRAKTUR_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Yfr html character entity reference model.
 *
 * Name: Yfr
 * Character: 𝔜
 * Unicode code point: U+d51c (54556)
 * Description: mathematical fraktur capital y
 */
static wchar_t* YFR_MATHEMATICAL_FRAKTUR_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yfr";
static int* YFR_MATHEMATICAL_FRAKTUR_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The afr html character entity reference model.
 *
 * Name: afr
 * Character: 𝔞
 * Unicode code point: U+d51e (54558)
 * Description: mathematical fraktur small a
 */
static wchar_t* AFR_MATHEMATICAL_FRAKTUR_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"afr";
static int* AFR_MATHEMATICAL_FRAKTUR_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bfr html character entity reference model.
 *
 * Name: bfr
 * Character: 𝔟
 * Unicode code point: U+d51f (54559)
 * Description: mathematical fraktur small b
 */
static wchar_t* BFR_MATHEMATICAL_FRAKTUR_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bfr";
static int* BFR_MATHEMATICAL_FRAKTUR_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cfr html character entity reference model.
 *
 * Name: cfr
 * Character: 𝔠
 * Unicode code point: U+d520 (54560)
 * Description: mathematical fraktur small c
 */
static wchar_t* CFR_MATHEMATICAL_FRAKTUR_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"cfr";
static int* CFR_MATHEMATICAL_FRAKTUR_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dfr html character entity reference model.
 *
 * Name: dfr
 * Character: 𝔡
 * Unicode code point: U+d521 (54561)
 * Description: mathematical fraktur small d
 */
static wchar_t* DFR_MATHEMATICAL_FRAKTUR_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dfr";
static int* DFR_MATHEMATICAL_FRAKTUR_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The efr html character entity reference model.
 *
 * Name: efr
 * Character: 𝔢
 * Unicode code point: U+d522 (54562)
 * Description: mathematical fraktur small e
 */
static wchar_t* EFR_MATHEMATICAL_FRAKTUR_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"efr";
static int* EFR_MATHEMATICAL_FRAKTUR_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ffr html character entity reference model.
 *
 * Name: ffr
 * Character: 𝔣
 * Unicode code point: U+d523 (54563)
 * Description: mathematical fraktur small f
 */
static wchar_t* FFR_MATHEMATICAL_FRAKTUR_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffr";
static int* FFR_MATHEMATICAL_FRAKTUR_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gfr html character entity reference model.
 *
 * Name: gfr
 * Character: 𝔤
 * Unicode code point: U+d524 (54564)
 * Description: mathematical fraktur small g
 */
static wchar_t* GFR_MATHEMATICAL_FRAKTUR_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gfr";
static int* GFR_MATHEMATICAL_FRAKTUR_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hfr html character entity reference model.
 *
 * Name: hfr
 * Character: 𝔥
 * Unicode code point: U+d525 (54565)
 * Description: mathematical fraktur small h
 */
static wchar_t* HFR_MATHEMATICAL_FRAKTUR_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hfr";
static int* HFR_MATHEMATICAL_FRAKTUR_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ifr html character entity reference model.
 *
 * Name: ifr
 * Character: 𝔦
 * Unicode code point: U+d526 (54566)
 * Description: mathematical fraktur small i
 */
static wchar_t* IFR_MATHEMATICAL_FRAKTUR_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ifr";
static int* IFR_MATHEMATICAL_FRAKTUR_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jfr html character entity reference model.
 *
 * Name: jfr
 * Character: 𝔧
 * Unicode code point: U+d527 (54567)
 * Description: mathematical fraktur small j
 */
static wchar_t* JFR_MATHEMATICAL_FRAKTUR_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jfr";
static int* JFR_MATHEMATICAL_FRAKTUR_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kfr html character entity reference model.
 *
 * Name: kfr
 * Character: 𝔨
 * Unicode code point: U+d528 (54568)
 * Description: mathematical fraktur small k
 */
static wchar_t* KFR_MATHEMATICAL_FRAKTUR_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kfr";
static int* KFR_MATHEMATICAL_FRAKTUR_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lfr html character entity reference model.
 *
 * Name: lfr
 * Character: 𝔩
 * Unicode code point: U+d529 (54569)
 * Description: mathematical fraktur small l
 */
static wchar_t* LFR_MATHEMATICAL_FRAKTUR_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lfr";
static int* LFR_MATHEMATICAL_FRAKTUR_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mfr html character entity reference model.
 *
 * Name: mfr
 * Character: 𝔪
 * Unicode code point: U+d52a (54570)
 * Description: mathematical fraktur small m
 */
static wchar_t* MFR_MATHEMATICAL_FRAKTUR_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mfr";
static int* MFR_MATHEMATICAL_FRAKTUR_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nfr html character entity reference model.
 *
 * Name: nfr
 * Character: 𝔫
 * Unicode code point: U+d52b (54571)
 * Description: mathematical fraktur small n
 */
static wchar_t* NFR_MATHEMATICAL_FRAKTUR_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nfr";
static int* NFR_MATHEMATICAL_FRAKTUR_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ofr html character entity reference model.
 *
 * Name: ofr
 * Character: 𝔬
 * Unicode code point: U+d52c (54572)
 * Description: mathematical fraktur small o
 */
static wchar_t* OFR_MATHEMATICAL_FRAKTUR_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ofr";
static int* OFR_MATHEMATICAL_FRAKTUR_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pfr html character entity reference model.
 *
 * Name: pfr
 * Character: 𝔭
 * Unicode code point: U+d52d (54573)
 * Description: mathematical fraktur small p
 */
static wchar_t* PFR_MATHEMATICAL_FRAKTUR_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"pfr";
static int* PFR_MATHEMATICAL_FRAKTUR_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qfr html character entity reference model.
 *
 * Name: qfr
 * Character: 𝔮
 * Unicode code point: U+d52e (54574)
 * Description: mathematical fraktur small q
 */
static wchar_t* QFR_MATHEMATICAL_FRAKTUR_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qfr";
static int* QFR_MATHEMATICAL_FRAKTUR_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The rfr html character entity reference model.
 *
 * Name: rfr
 * Character: 𝔯
 * Unicode code point: U+d52f (54575)
 * Description: mathematical fraktur small r
 */
static wchar_t* RFR_MATHEMATICAL_FRAKTUR_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"rfr";
static int* RFR_MATHEMATICAL_FRAKTUR_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sfr html character entity reference model.
 *
 * Name: sfr
 * Character: 𝔰
 * Unicode code point: U+d530 (54576)
 * Description: mathematical fraktur small s
 */
static wchar_t* SFR_MATHEMATICAL_FRAKTUR_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sfr";
static int* SFR_MATHEMATICAL_FRAKTUR_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tfr html character entity reference model.
 *
 * Name: tfr
 * Character: 𝔱
 * Unicode code point: U+d531 (54577)
 * Description: mathematical fraktur small t
 */
static wchar_t* TFR_MATHEMATICAL_FRAKTUR_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"tfr";
static int* TFR_MATHEMATICAL_FRAKTUR_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ufr html character entity reference model.
 *
 * Name: ufr
 * Character: 𝔲
 * Unicode code point: U+d532 (54578)
 * Description: mathematical fraktur small u
 */
static wchar_t* UFR_MATHEMATICAL_FRAKTUR_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ufr";
static int* UFR_MATHEMATICAL_FRAKTUR_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vfr html character entity reference model.
 *
 * Name: vfr
 * Character: 𝔳
 * Unicode code point: U+d533 (54579)
 * Description: mathematical fraktur small v
 */
static wchar_t* VFR_MATHEMATICAL_FRAKTUR_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vfr";
static int* VFR_MATHEMATICAL_FRAKTUR_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wfr html character entity reference model.
 *
 * Name: wfr
 * Character: 𝔴
 * Unicode code point: U+d534 (54580)
 * Description: mathematical fraktur small w
 */
static wchar_t* WFR_MATHEMATICAL_FRAKTUR_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wfr";
static int* WFR_MATHEMATICAL_FRAKTUR_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xfr html character entity reference model.
 *
 * Name: xfr
 * Character: 𝔵
 * Unicode code point: U+d535 (54581)
 * Description: mathematical fraktur small x
 */
static wchar_t* XFR_MATHEMATICAL_FRAKTUR_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xfr";
static int* XFR_MATHEMATICAL_FRAKTUR_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yfr html character entity reference model.
 *
 * Name: yfr
 * Character: 𝔶
 * Unicode code point: U+d536 (54582)
 * Description: mathematical fraktur small y
 */
static wchar_t* YFR_MATHEMATICAL_FRAKTUR_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yfr";
static int* YFR_MATHEMATICAL_FRAKTUR_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zfr html character entity reference model.
 *
 * Name: zfr
 * Character: 𝔷
 * Unicode code point: U+d537 (54583)
 * Description: mathematical fraktur small z
 */
static wchar_t* ZFR_MATHEMATICAL_FRAKTUR_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zfr";
static int* ZFR_MATHEMATICAL_FRAKTUR_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Aopf html character entity reference model.
 *
 * Name: Aopf
 * Character: 𝔸
 * Unicode code point: U+d538 (54584)
 * Description: mathematical double-struck capital a
 */
static wchar_t* AOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Aopf";
static int* AOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Bopf html character entity reference model.
 *
 * Name: Bopf
 * Character: 𝔹
 * Unicode code point: U+d539 (54585)
 * Description: mathematical double-struck capital b
 */
static wchar_t* BOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Bopf";
static int* BOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Dopf html character entity reference model.
 *
 * Name: Dopf
 * Character: 𝔻
 * Unicode code point: U+d53b (54587)
 * Description: mathematical double-struck capital d
 */
static wchar_t* DOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Dopf";
static int* DOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Eopf html character entity reference model.
 *
 * Name: Eopf
 * Character: 𝔼
 * Unicode code point: U+d53c (54588)
 * Description: mathematical double-struck capital e
 */
static wchar_t* EOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Eopf";
static int* EOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Fopf html character entity reference model.
 *
 * Name: Fopf
 * Character: 𝔽
 * Unicode code point: U+d53d (54589)
 * Description: mathematical double-struck capital f
 */
static wchar_t* FOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Fopf";
static int* FOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Gopf html character entity reference model.
 *
 * Name: Gopf
 * Character: 𝔾
 * Unicode code point: U+d53e (54590)
 * Description: mathematical double-struck capital g
 */
static wchar_t* GOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Gopf";
static int* GOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Iopf html character entity reference model.
 *
 * Name: Iopf
 * Character: 𝕀
 * Unicode code point: U+d540 (54592)
 * Description: mathematical double-struck capital i
 */
static wchar_t* IOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Iopf";
static int* IOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Jopf html character entity reference model.
 *
 * Name: Jopf
 * Character: 𝕁
 * Unicode code point: U+d541 (54593)
 * Description: mathematical double-struck capital j
 */
static wchar_t* JOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Jopf";
static int* JOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Kopf html character entity reference model.
 *
 * Name: Kopf
 * Character: 𝕂
 * Unicode code point: U+d542 (54594)
 * Description: mathematical double-struck capital k
 */
static wchar_t* KOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Kopf";
static int* KOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Lopf html character entity reference model.
 *
 * Name: Lopf
 * Character: 𝕃
 * Unicode code point: U+d543 (54595)
 * Description: mathematical double-struck capital l
 */
static wchar_t* LOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Lopf";
static int* LOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Mopf html character entity reference model.
 *
 * Name: Mopf
 * Character: 𝕄
 * Unicode code point: U+d544 (54596)
 * Description: mathematical double-struck capital m
 */
static wchar_t* MOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Mopf";
static int* MOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Oopf html character entity reference model.
 *
 * Name: Oopf
 * Character: 𝕆
 * Unicode code point: U+d546 (54598)
 * Description: mathematical double-struck capital o
 */
static wchar_t* OOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Oopf";
static int* OOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Sopf html character entity reference model.
 *
 * Name: Sopf
 * Character: 𝕊
 * Unicode code point: U+d54a (54602)
 * Description: mathematical double-struck capital s
 */
static wchar_t* SOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Sopf";
static int* SOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Topf html character entity reference model.
 *
 * Name: Topf
 * Character: 𝕋
 * Unicode code point: U+d54b (54603)
 * Description: mathematical double-struck capital t
 */
static wchar_t* TOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Topf";
static int* TOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Uopf html character entity reference model.
 *
 * Name: Uopf
 * Character: 𝕌
 * Unicode code point: U+d54c (54604)
 * Description: mathematical double-struck capital u
 */
static wchar_t* UOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Uopf";
static int* UOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Vopf html character entity reference model.
 *
 * Name: Vopf
 * Character: 𝕍
 * Unicode code point: U+d54d (54605)
 * Description: mathematical double-struck capital v
 */
static wchar_t* VOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Vopf";
static int* VOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Wopf html character entity reference model.
 *
 * Name: Wopf
 * Character: 𝕎
 * Unicode code point: U+d54e (54606)
 * Description: mathematical double-struck capital w
 */
static wchar_t* WOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Wopf";
static int* WOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Xopf html character entity reference model.
 *
 * Name: Xopf
 * Character: 𝕏
 * Unicode code point: U+d54f (54607)
 * Description: mathematical double-struck capital x
 */
static wchar_t* XOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Xopf";
static int* XOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The Yopf html character entity reference model.
 *
 * Name: Yopf
 * Character: 𝕐
 * Unicode code point: U+d550 (54608)
 * Description: mathematical double-struck capital y
 */
static wchar_t* YOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"Yopf";
static int* YOPF_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The aopf html character entity reference model.
 *
 * Name: aopf
 * Character: 𝕒
 * Unicode code point: U+d552 (54610)
 * Description: mathematical double-struck small a
 */
static wchar_t* AOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"aopf";
static int* AOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_A_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bopf html character entity reference model.
 *
 * Name: bopf
 * Character: 𝕓
 * Unicode code point: U+d553 (54611)
 * Description: mathematical double-struck small b
 */
static wchar_t* BOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"bopf";
static int* BOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_B_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The copf html character entity reference model.
 *
 * Name: copf
 * Character: 𝕔
 * Unicode code point: U+d554 (54612)
 * Description: mathematical double-struck small c
 */
static wchar_t* COPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"copf";
static int* COPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_C_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dopf html character entity reference model.
 *
 * Name: dopf
 * Character: 𝕕
 * Unicode code point: U+d555 (54613)
 * Description: mathematical double-struck small d
 */
static wchar_t* DOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"dopf";
static int* DOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_D_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The eopf html character entity reference model.
 *
 * Name: eopf
 * Character: 𝕖
 * Unicode code point: U+d556 (54614)
 * Description: mathematical double-struck small e
 */
static wchar_t* EOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"eopf";
static int* EOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_E_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fopf html character entity reference model.
 *
 * Name: fopf
 * Character: 𝕗
 * Unicode code point: U+d557 (54615)
 * Description: mathematical double-struck small f
 */
static wchar_t* FOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fopf";
static int* FOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_F_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The gopf html character entity reference model.
 *
 * Name: gopf
 * Character: 𝕘
 * Unicode code point: U+d558 (54616)
 * Description: mathematical double-struck small g
 */
static wchar_t* GOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"gopf";
static int* GOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_G_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hopf html character entity reference model.
 *
 * Name: hopf
 * Character: 𝕙
 * Unicode code point: U+d559 (54617)
 * Description: mathematical double-struck small h
 */
static wchar_t* HOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"hopf";
static int* HOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_H_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The iopf html character entity reference model.
 *
 * Name: iopf
 * Character: 𝕚
 * Unicode code point: U+d55a (54618)
 * Description: mathematical double-struck small i
 */
static wchar_t* IOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"iopf";
static int* IOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_I_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jopf html character entity reference model.
 *
 * Name: jopf
 * Character: 𝕛
 * Unicode code point: U+d55b (54619)
 * Description: mathematical double-struck small j
 */
static wchar_t* JOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"jopf";
static int* JOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_J_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The kopf html character entity reference model.
 *
 * Name: kopf
 * Character: 𝕜
 * Unicode code point: U+d55c (54620)
 * Description: mathematical double-struck small k
 */
static wchar_t* KOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"kopf";
static int* KOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_K_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The lopf html character entity reference model.
 *
 * Name: lopf
 * Character: 𝕝
 * Unicode code point: U+d55d (54621)
 * Description: mathematical double-struck small l
 */
static wchar_t* LOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"lopf";
static int* LOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_L_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mopf html character entity reference model.
 *
 * Name: mopf
 * Character: 𝕞
 * Unicode code point: U+d55e (54622)
 * Description: mathematical double-struck small m
 */
static wchar_t* MOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"mopf";
static int* MOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_M_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The nopf html character entity reference model.
 *
 * Name: nopf
 * Character: 𝕟
 * Unicode code point: U+d55f (54623)
 * Description: mathematical double-struck small n
 */
static wchar_t* NOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"nopf";
static int* NOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_N_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The oopf html character entity reference model.
 *
 * Name: oopf
 * Character: 𝕠
 * Unicode code point: U+d560 (54624)
 * Description: mathematical double-struck small o
 */
static wchar_t* OOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"oopf";
static int* OOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_O_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The popf html character entity reference model.
 *
 * Name: popf
 * Character: 𝕡
 * Unicode code point: U+d561 (54625)
 * Description: mathematical double-struck small p
 */
static wchar_t* POPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"popf";
static int* POPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_P_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qopf html character entity reference model.
 *
 * Name: qopf
 * Character: 𝕢
 * Unicode code point: U+d562 (54626)
 * Description: mathematical double-struck small q
 */
static wchar_t* QOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"qopf";
static int* QOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Q_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ropf html character entity reference model.
 *
 * Name: ropf
 * Character: 𝕣
 * Unicode code point: U+d563 (54627)
 * Description: mathematical double-struck small r
 */
static wchar_t* ROPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ropf";
static int* ROPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_R_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sopf html character entity reference model.
 *
 * Name: sopf
 * Character: 𝕤
 * Unicode code point: U+d564 (54628)
 * Description: mathematical double-struck small s
 */
static wchar_t* SOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"sopf";
static int* SOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_S_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The topf html character entity reference model.
 *
 * Name: topf
 * Character: 𝕥
 * Unicode code point: U+d565 (54629)
 * Description: mathematical double-struck small t
 */
static wchar_t* TOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"topf";
static int* TOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_T_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uopf html character entity reference model.
 *
 * Name: uopf
 * Character: 𝕦
 * Unicode code point: U+d566 (54630)
 * Description: mathematical double-struck small u
 */
static wchar_t* UOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"uopf";
static int* UOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_U_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vopf html character entity reference model.
 *
 * Name: vopf
 * Character: 𝕧
 * Unicode code point: U+d567 (54631)
 * Description: mathematical double-struck small v
 */
static wchar_t* VOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"vopf";
static int* VOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_V_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wopf html character entity reference model.
 *
 * Name: wopf
 * Character: 𝕨
 * Unicode code point: U+d568 (54632)
 * Description: mathematical double-struck small w
 */
static wchar_t* WOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"wopf";
static int* WOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_W_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The xopf html character entity reference model.
 *
 * Name: xopf
 * Character: 𝕩
 * Unicode code point: U+d569 (54633)
 * Description: mathematical double-struck small x
 */
static wchar_t* XOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"xopf";
static int* XOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_X_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The yopf html character entity reference model.
 *
 * Name: yopf
 * Character: 𝕪
 * Unicode code point: U+d56a (54634)
 * Description: mathematical double-struck small y
 */
static wchar_t* YOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"yopf";
static int* YOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Y_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The zopf html character entity reference model.
 *
 * Name: zopf
 * Character: 𝕫
 * Unicode code point: U+d56b (54635)
 * Description: mathematical double-struck small z
 */
static wchar_t* ZOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"zopf";
static int* ZOPF_MATHEMATICAL_DOUBLE_STRUCK_SMALL_Z_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Gamma html character entity reference model.
 *
 * Name: b_Gamma
 * Character: 𝚪
 * Unicode code point: U+d6aa (54954)
 * Description: mathematical bold capital gamma
 */
static wchar_t* B_GAMMA_MATHEMATICAL_BOLD_CAPITAL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Gamma";
static int* B_GAMMA_MATHEMATICAL_BOLD_CAPITAL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Delta html character entity reference model.
 *
 * Name: b_Delta
 * Character: 𝚫
 * Unicode code point: U+d6ab (54955)
 * Description: mathematical bold capital delta
 */
static wchar_t* B_DELTA_MATHEMATICAL_BOLD_CAPITAL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Delta";
static int* B_DELTA_MATHEMATICAL_BOLD_CAPITAL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Theta html character entity reference model.
 *
 * Name: b_Theta
 * Character: 𝚯
 * Unicode code point: U+d6af (54959)
 * Description: mathematical bold capital theta
 */
static wchar_t* B_THETA_MATHEMATICAL_BOLD_CAPITAL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Theta";
static int* B_THETA_MATHEMATICAL_BOLD_CAPITAL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Lambda html character entity reference model.
 *
 * Name: b_Lambda
 * Character: 𝚲
 * Unicode code point: U+d6b2 (54962)
 * Description: mathematical bold capital lamda
 */
static wchar_t* B_LAMBDA_MATHEMATICAL_BOLD_CAPITAL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Lambda";
static int* B_LAMBDA_MATHEMATICAL_BOLD_CAPITAL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Xi html character entity reference model.
 *
 * Name: b_Xi
 * Character: 𝚵
 * Unicode code point: U+d6b5 (54965)
 * Description: mathematical bold capital xi
 */
static wchar_t* B_XI_MATHEMATICAL_BOLD_CAPITAL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Xi";
static int* B_XI_MATHEMATICAL_BOLD_CAPITAL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Pi html character entity reference model.
 *
 * Name: b_Pi
 * Character: 𝚷
 * Unicode code point: U+d6b7 (54967)
 * Description: mathematical bold capital pi
 */
static wchar_t* B_PI_MATHEMATICAL_BOLD_CAPITAL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Pi";
static int* B_PI_MATHEMATICAL_BOLD_CAPITAL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Sigma html character entity reference model.
 *
 * Name: b_Sigma
 * Character: 𝚺
 * Unicode code point: U+d6ba (54970)
 * Description: mathematical bold capital sigma
 */
static wchar_t* B_SIGMA_MATHEMATICAL_BOLD_CAPITAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Sigma";
static int* B_SIGMA_MATHEMATICAL_BOLD_CAPITAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Upsi html character entity reference model.
 *
 * Name: b_Upsi
 * Character: 𝚼
 * Unicode code point: U+d6bc (54972)
 * Description: mathematical bold capital upsilon
 */
static wchar_t* B_UPSI_MATHEMATICAL_BOLD_CAPITAL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Upsi";
static int* B_UPSI_MATHEMATICAL_BOLD_CAPITAL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Phi html character entity reference model.
 *
 * Name: b_Phi
 * Character: 𝚽
 * Unicode code point: U+d6bd (54973)
 * Description: mathematical bold capital phi
 */
static wchar_t* B_PHI_MATHEMATICAL_BOLD_CAPITAL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Phi";
static int* B_PHI_MATHEMATICAL_BOLD_CAPITAL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Psi html character entity reference model.
 *
 * Name: b_Psi
 * Character: 𝚿
 * Unicode code point: U+d6bf (54975)
 * Description: mathematical bold capital psi
 */
static wchar_t* B_PSI_MATHEMATICAL_BOLD_CAPITAL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Psi";
static int* B_PSI_MATHEMATICAL_BOLD_CAPITAL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Omega html character entity reference model.
 *
 * Name: b_Omega
 * Character: 𝛀
 * Unicode code point: U+d6c0 (54976)
 * Description: mathematical bold capital omega
 */
static wchar_t* B_OMEGA_MATHEMATICAL_BOLD_CAPITAL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Omega";
static int* B_OMEGA_MATHEMATICAL_BOLD_CAPITAL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_alpha html character entity reference model.
 *
 * Name: b_alpha
 * Character: 𝛂
 * Unicode code point: U+d6c2 (54978)
 * Description: mathematical bold small alpha
 */
static wchar_t* B_ALPHA_MATHEMATICAL_BOLD_SMALL_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_alpha";
static int* B_ALPHA_MATHEMATICAL_BOLD_SMALL_ALPHA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_beta html character entity reference model.
 *
 * Name: b_beta
 * Character: 𝛃
 * Unicode code point: U+d6c3 (54979)
 * Description: mathematical bold small beta
 */
static wchar_t* B_BETA_MATHEMATICAL_BOLD_SMALL_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_beta";
static int* B_BETA_MATHEMATICAL_BOLD_SMALL_BETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_gamma html character entity reference model.
 *
 * Name: b_gamma
 * Character: 𝛄
 * Unicode code point: U+d6c4 (54980)
 * Description: mathematical bold small gamma
 */
static wchar_t* B_GAMMA_MATHEMATICAL_BOLD_SMALL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_gamma";
static int* B_GAMMA_MATHEMATICAL_BOLD_SMALL_GAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_delta html character entity reference model.
 *
 * Name: b_delta
 * Character: 𝛅
 * Unicode code point: U+d6c5 (54981)
 * Description: mathematical bold small delta
 */
static wchar_t* B_DELTA_MATHEMATICAL_BOLD_SMALL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_delta";
static int* B_DELTA_MATHEMATICAL_BOLD_SMALL_DELTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_epsi html character entity reference model.
 *
 * Name: b_epsi
 * Character: 𝛆
 * Unicode code point: U+d6c6 (54982)
 * Description: mathematical bold small epsilon
 */
static wchar_t* B_EPSI_MATHEMATICAL_BOLD_SMALL_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_epsi";
static int* B_EPSI_MATHEMATICAL_BOLD_SMALL_EPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_zeta html character entity reference model.
 *
 * Name: b_zeta
 * Character: 𝛇
 * Unicode code point: U+d6c7 (54983)
 * Description: mathematical bold small zeta
 */
static wchar_t* B_ZETA_MATHEMATICAL_BOLD_SMALL_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_zeta";
static int* B_ZETA_MATHEMATICAL_BOLD_SMALL_ZETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_eta html character entity reference model.
 *
 * Name: b_eta
 * Character: 𝛈
 * Unicode code point: U+d6c8 (54984)
 * Description: mathematical bold small eta
 */
static wchar_t* B_ETA_MATHEMATICAL_BOLD_SMALL_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_eta";
static int* B_ETA_MATHEMATICAL_BOLD_SMALL_ETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_thetas html character entity reference model.
 *
 * Name: b_thetas
 * Character: 𝛉
 * Unicode code point: U+d6c9 (54985)
 * Description: mathematical bold small theta
 */
static wchar_t* B_THETAS_MATHEMATICAL_BOLD_SMALL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_thetas";
static int* B_THETAS_MATHEMATICAL_BOLD_SMALL_THETA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_iota html character entity reference model.
 *
 * Name: b_iota
 * Character: 𝛊
 * Unicode code point: U+d6ca (54986)
 * Description: mathematical bold small iota
 */
static wchar_t* B_IOTA_MATHEMATICAL_BOLD_SMALL_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_iota";
static int* B_IOTA_MATHEMATICAL_BOLD_SMALL_IOTA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_kappa html character entity reference model.
 *
 * Name: b_kappa
 * Character: 𝛋
 * Unicode code point: U+d6cb (54987)
 * Description: mathematical bold small kappa
 */
static wchar_t* B_KAPPA_MATHEMATICAL_BOLD_SMALL_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_kappa";
static int* B_KAPPA_MATHEMATICAL_BOLD_SMALL_KAPPA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_lambda html character entity reference model.
 *
 * Name: b_lambda
 * Character: 𝛌
 * Unicode code point: U+d6cc (54988)
 * Description: mathematical bold small lamda
 */
static wchar_t* B_LAMBDA_MATHEMATICAL_BOLD_SMALL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_lambda";
static int* B_LAMBDA_MATHEMATICAL_BOLD_SMALL_LAMDA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_mu html character entity reference model.
 *
 * Name: b_mu
 * Character: 𝛍
 * Unicode code point: U+d6cd (54989)
 * Description: mathematical bold small mu
 */
static wchar_t* B_MU_MATHEMATICAL_BOLD_SMALL_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_mu";
static int* B_MU_MATHEMATICAL_BOLD_SMALL_MU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_nu html character entity reference model.
 *
 * Name: b_nu
 * Character: 𝛎
 * Unicode code point: U+d6ce (54990)
 * Description: mathematical bold small nu
 */
static wchar_t* B_NU_MATHEMATICAL_BOLD_SMALL_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_nu";
static int* B_NU_MATHEMATICAL_BOLD_SMALL_NU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_xi html character entity reference model.
 *
 * Name: b_xi
 * Character: 𝛏
 * Unicode code point: U+d6cf (54991)
 * Description: mathematical bold small xi
 */
static wchar_t* B_XI_MATHEMATICAL_BOLD_SMALL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_xi";
static int* B_XI_MATHEMATICAL_BOLD_SMALL_XI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_pi html character entity reference model.
 *
 * Name: b_pi
 * Character: 𝛑
 * Unicode code point: U+d6d1 (54993)
 * Description: mathematical bold small pi
 */
static wchar_t* B_PI_MATHEMATICAL_BOLD_SMALL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_pi";
static int* B_PI_MATHEMATICAL_BOLD_SMALL_PI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_rho html character entity reference model.
 *
 * Name: b_rho
 * Character: 𝛒
 * Unicode code point: U+d6d2 (54994)
 * Description: mathematical bold small rho
 */
static wchar_t* B_RHO_MATHEMATICAL_BOLD_SMALL_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_rho";
static int* B_RHO_MATHEMATICAL_BOLD_SMALL_RHO_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_sigmav html character entity reference model.
 *
 * Name: b_sigmav
 * Character: 𝛓
 * Unicode code point: U+d6d3 (54995)
 * Description: mathematical bold small final sigma
 */
static wchar_t* B_SIGMAV_MATHEMATICAL_BOLD_SMALL_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_sigmav";
static int* B_SIGMAV_MATHEMATICAL_BOLD_SMALL_FINAL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_sigma html character entity reference model.
 *
 * Name: b_sigma
 * Character: 𝛔
 * Unicode code point: U+d6d4 (54996)
 * Description: mathematical bold small sigma
 */
static wchar_t* B_SIGMA_MATHEMATICAL_BOLD_SMALL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_sigma";
static int* B_SIGMA_MATHEMATICAL_BOLD_SMALL_SIGMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_tau html character entity reference model.
 *
 * Name: b_tau
 * Character: 𝛕
 * Unicode code point: U+d6d5 (54997)
 * Description: mathematical bold small tau
 */
static wchar_t* B_TAU_MATHEMATICAL_BOLD_SMALL_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_tau";
static int* B_TAU_MATHEMATICAL_BOLD_SMALL_TAU_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_upsi html character entity reference model.
 *
 * Name: b_upsi
 * Character: 𝛖
 * Unicode code point: U+d6d6 (54998)
 * Description: mathematical bold small upsilon
 */
static wchar_t* B_UPSI_MATHEMATICAL_BOLD_SMALL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_upsi";
static int* B_UPSI_MATHEMATICAL_BOLD_SMALL_UPSILON_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_phi html character entity reference model.
 *
 * Name: b_phi
 * Character: 𝛗
 * Unicode code point: U+d6d7 (54999)
 * Description: mathematical bold small phi
 */
static wchar_t* B_PHI_MATHEMATICAL_BOLD_SMALL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_phi";
static int* B_PHI_MATHEMATICAL_BOLD_SMALL_PHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_chi html character entity reference model.
 *
 * Name: b_chi
 * Character: 𝛘
 * Unicode code point: U+d6d8 (55000)
 * Description: mathematical bold small chi
 */
static wchar_t* B_CHI_MATHEMATICAL_BOLD_SMALL_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_chi";
static int* B_CHI_MATHEMATICAL_BOLD_SMALL_CHI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_psi html character entity reference model.
 *
 * Name: b_psi
 * Character: 𝛙
 * Unicode code point: U+d6d9 (55001)
 * Description: mathematical bold small psi
 */
static wchar_t* B_PSI_MATHEMATICAL_BOLD_SMALL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_psi";
static int* B_PSI_MATHEMATICAL_BOLD_SMALL_PSI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_omega html character entity reference model.
 *
 * Name: b_omega
 * Character: 𝛚
 * Unicode code point: U+d6da (55002)
 * Description: mathematical bold small omega
 */
static wchar_t* B_OMEGA_MATHEMATICAL_BOLD_SMALL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_omega";
static int* B_OMEGA_MATHEMATICAL_BOLD_SMALL_OMEGA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_epsiv html character entity reference model.
 *
 * Name: b_epsiv
 * Character: 𝛜
 * Unicode code point: U+d6dc (55004)
 * Description: mathematical bold epsilon symbol
 */
static wchar_t* B_EPSIV_MATHEMATICAL_BOLD_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_epsiv";
static int* B_EPSIV_MATHEMATICAL_BOLD_EPSILON_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_thetav html character entity reference model.
 *
 * Name: b_thetav
 * Character: 𝛝
 * Unicode code point: U+d6dd (55005)
 * Description: mathematical bold theta symbol
 */
static wchar_t* B_THETAV_MATHEMATICAL_BOLD_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_thetav";
static int* B_THETAV_MATHEMATICAL_BOLD_THETA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_kappav html character entity reference model.
 *
 * Name: b_kappav
 * Character: 𝛞
 * Unicode code point: U+d6de (55006)
 * Description: mathematical bold kappa symbol
 */
static wchar_t* B_KAPPAV_MATHEMATICAL_BOLD_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_kappav";
static int* B_KAPPAV_MATHEMATICAL_BOLD_KAPPA_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_phiv html character entity reference model.
 *
 * Name: b_phiv
 * Character: 𝛟
 * Unicode code point: U+d6df (55007)
 * Description: mathematical bold phi symbol
 */
static wchar_t* B_PHIV_MATHEMATICAL_BOLD_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_phiv";
static int* B_PHIV_MATHEMATICAL_BOLD_PHI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_rhov html character entity reference model.
 *
 * Name: b_rhov
 * Character: 𝛠
 * Unicode code point: U+d6e0 (55008)
 * Description: mathematical bold rho symbol
 */
static wchar_t* B_RHOV_MATHEMATICAL_BOLD_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_rhov";
static int* B_RHOV_MATHEMATICAL_BOLD_RHO_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_piv html character entity reference model.
 *
 * Name: b_piv
 * Character: 𝛡
 * Unicode code point: U+d6e1 (55009)
 * Description: mathematical bold pi symbol
 */
static wchar_t* B_PIV_MATHEMATICAL_BOLD_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_piv";
static int* B_PIV_MATHEMATICAL_BOLD_PI_SYMBOL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_Gammad html character entity reference model.
 *
 * Name: b_Gammad
 * Character: 𝟊
 * Unicode code point: U+d7ca (55242)
 * Description: mathematical bold capital digamma
 */
static wchar_t* B_GAMMAD_MATHEMATICAL_BOLD_CAPITAL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_Gammad";
static int* B_GAMMAD_MATHEMATICAL_BOLD_CAPITAL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The b_gammad html character entity reference model.
 *
 * Name: b_gammad
 * Character: 𝟋
 * Unicode code point: U+d7cb (55243)
 * Description: mathematical bold small digamma
 */
static wchar_t* B_GAMMAD_MATHEMATICAL_BOLD_SMALL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"b_gammad";
static int* B_GAMMAD_MATHEMATICAL_BOLD_SMALL_DIGAMMA_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fflig html character entity reference model.
 *
 * Name: fflig
 * Character: ﬀ
 * Unicode code point: U+fb00 (64256)
 * Description: latin small ligature ff
 */
static wchar_t* FFLIG_LATIN_SMALL_LIGATURE_FF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fflig";
static int* FFLIG_LATIN_SMALL_LIGATURE_FF_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The filig html character entity reference model.
 *
 * Name: filig
 * Character: ﬁ
 * Unicode code point: U+fb01 (64257)
 * Description: latin small ligature fi
 */
static wchar_t* FILIG_LATIN_SMALL_LIGATURE_FI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"filig";
static int* FILIG_LATIN_SMALL_LIGATURE_FI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fllig html character entity reference model.
 *
 * Name: fllig
 * Character: ﬂ
 * Unicode code point: U+fb02 (64258)
 * Description: latin small ligature fl
 */
static wchar_t* FLLIG_LATIN_SMALL_LIGATURE_FL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"fllig";
static int* FLLIG_LATIN_SMALL_LIGATURE_FL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ffilig html character entity reference model.
 *
 * Name: ffilig
 * Character: ﬃ
 * Unicode code point: U+fb03 (64259)
 * Description: latin small ligature ffi
 */
static wchar_t* FFILIG_LATIN_SMALL_LIGATURE_FFI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffilig";
static int* FFILIG_LATIN_SMALL_LIGATURE_FFI_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ffllig html character entity reference model.
 *
 * Name: ffllig
 * Character: ﬄ
 * Unicode code point: U+fb04 (64260)
 * Description: latin small ligature ffl
 */
static wchar_t* FFLLIG_LATIN_SMALL_LIGATURE_FFL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL = L"ffllig";
static int* FFLLIG_LATIN_SMALL_LIGATURE_FFL_HTML_CHARACTER_ENTITY_REFERENCE_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HTML_CHARACTER_ENTITY_REFERENCE_MODEL_CONSTANT_HEADER */
#endif
