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

#ifndef WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//

//
// Windows code pages are sets of characters or code pages
// (known as character encodings in other operating systems)
// used in Microsoft Windows from the 1980s and 1990s.
//
// Windows code pages were gradually superseded when Unicode
// was implemented in Windows, although they are still
// supported both within Windows and other platforms.
//
// There are two groups of code pages used in pre-Windows NT systems:
// OEM and ANSI code pages. Code pages in both of these groups
// are extended ASCII code pages.
//

//
// ANSI code pages (officially called "Windows code pages"
// after Microsoft accepted the former term being a misnomer)
// are used for native non-Unicode (say, byte oriented)
// applications using a graphical user interface on Windows systems.
//
// ANSI Windows code pages, and especially the code page 1252,
// were called that way since they were purportedly based
// on drafts submitted or intended for ANSI. However, ANSI
// and ISO have not standardized any of these code pages.
//
// Instead they are either supersets of the standard sets
// such as those of ISO 8859 and the various national standards
// (like Windows-1252 vs. ISO-8859-1), major modifications
// of these (making them incompatible to various degrees,
// like Windows-1250 vs. ISO-8859-2) or having no parallel
// encoding (like Windows-1257 vs. ISO-8859-4; ISO-8859-13
// was introduced much later).
//
// About twelve of the typography and business characters
// from CP1252 at code points 0x80-0x9F (in ISO 8859 occupied
// by C1 control codes, which are useless in Windows) are present
// in many other ANSI/Windows code pages at the same codes.
// These code pages are labelled by Internet Assigned Numbers
// Authority (IANA) as "Windows-number".
//
// Windows-1252 or CP-1252 is a character encoding of the
// Latin alphabet, used by default in the legacy components
// of Microsoft Windows in English and some other Western languages.
// It is one version within the group of Windows code pages.
// In LaTeX packages, it is referred to as ansinew.
//

//
// This file contains Windows-1252 character code constants.
//

//
// This encoding is a superset of ISO 8859-1, but differs
// from the IANA's ISO-8859-1 by using displayable characters
// rather than control characters in the 80 to 9F (hex) range.
// It is known to Windows by the code page number 1252,
// and by the IANA-approved name "windows‑1252".
// This code page also contains all the printable characters that are
// in ISO 8859-15 (though some are mapped to different code points).
//
// It is very common to mislabel Windows-1252 text with the charset
// label ISO-8859-1. A common result was that all the quotes and
// apostrophes (produced by "smart quotes" in Microsoft software)
// were replaced with question marks or boxes on non-Windows
// operating systems, making text difficult to read.
//
// Most modern web browsers and e-mail clients treat the MIME charset
// ISO-8859-1 as Windows-1252 in order to accommodate such mislabeling.
// This is now standard behavior in the draft HTML 5 specification,
// which requires that documents advertised as ISO-8859-1 actually
// be parsed with the Windows-1252 encoding.
//
// Historically, the phrase "ANSI code page" (ACP) is used in
// Windows to refer to various code pages considered as native.
// The intention was that most of these would be ANSI standards
// such as ISO-8859-1. Even though Windows-1252 was the first
// and by far most popular code page named so in Microsoft Windows
// parlance, the code page has never been an ANSI standard.
// Microsoft-affiliated bloggers now state that "The term ANSI
// as used to signify Windows code pages is a historical reference,
// but is nowadays a misnomer that continues to persist in
// the Windows community.
//

/** The euro sign windows-1252 character code model. U+20AC */
static unsigned char EURO_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x80 };
static unsigned char* EURO_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL = EURO_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The single low-9 quotation mark windows-1252 character code model. U+201A */
static unsigned char SINGLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x82 };
static unsigned char* SINGLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = SINGLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter f with hook windows-1252 character code model. U+0192 */
static unsigned char LATIN_SMALL_LETTER_F_WITH_HOOK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x83 };
static unsigned char* LATIN_SMALL_LETTER_F_WITH_HOOK_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_F_WITH_HOOK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The double low-9 quotation mark windows-1252 character code model. U+201E */
static unsigned char DOUBLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x84 };
static unsigned char* DOUBLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = DOUBLE_LOW_9_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The horizontal ellipsis windows-1252 character code model. U+2026 */
static unsigned char HORIZONTAL_ELLIPSIS_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x85 };
static unsigned char* HORIZONTAL_ELLIPSIS_WINDOWS_1252_CHARACTER_CODE_MODEL = HORIZONTAL_ELLIPSIS_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The dagger windows-1252 character code model. U+2020 */
static unsigned char DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x86 };
static unsigned char* DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL = DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The double dagger windows-1252 character code model. U+2021 */
static unsigned char DOUBLE_DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x87 };
static unsigned char* DOUBLE_DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL = DOUBLE_DAGGER_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The modifier letter circumflex accent windows-1252 character code model. U+02C6 */
static unsigned char MODIFIER_LETTER_CIRCUMFLEX_ACCENT_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x88 };
static unsigned char* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_WINDOWS_1252_CHARACTER_CODE_MODEL = MODIFIER_LETTER_CIRCUMFLEX_ACCENT_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The per mille sign windows-1252 character code model. U+2030 */
static unsigned char PER_MILLE_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x89 };
static unsigned char* PER_MILLE_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL = PER_MILLE_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter s with caron windows-1252 character code model. U+0160 */
static unsigned char LATIN_CAPITAL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8A };
static unsigned char* LATIN_CAPITAL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The single left-pointing angle quotation mark windows-1252 character code model. U+2039 */
static unsigned char SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8B };
static unsigned char* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital ligature oe windows-1252 character code model. U+0152 */
static unsigned char LATIN_CAPITAL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8C };
static unsigned char* LATIN_CAPITAL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter z with caron windows-1252 character code model. U+017D */
static unsigned char LATIN_CAPITAL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8E };
static unsigned char* LATIN_CAPITAL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The left single quotation mark windows-1252 character code model. U+2018 */
static unsigned char LEFT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x91 };
static unsigned char* LEFT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = LEFT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The right single quotation mark windows-1252 character code model. U+2019 */
static unsigned char RIGHT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x92 };
static unsigned char* RIGHT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = RIGHT_SINGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The left double quotation mark windows-1252 character code model. U+201C */
static unsigned char LEFT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x93 };
static unsigned char* LEFT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = LEFT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The right double quotation mark windows-1252 character code model. U+201D */
static unsigned char RIGHT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x94 };
static unsigned char* RIGHT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = RIGHT_DOUBLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The bullet windows-1252 character code model. U+2022 */
static unsigned char BULLET_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x95 };
static unsigned char* BULLET_WINDOWS_1252_CHARACTER_CODE_MODEL = BULLET_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The en dash windows-1252 character code model. U+2013 */
static unsigned char EN_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x96 };
static unsigned char* EN_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL = EN_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The em dash windows-1252 character code model. U+2014 */
static unsigned char EM_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x97 };
static unsigned char* EM_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL = EM_DASH_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The small tilde windows-1252 character code model. U+02DC */
static unsigned char SMALL_TILDE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x98 };
static unsigned char* SMALL_TILDE_WINDOWS_1252_CHARACTER_CODE_MODEL = SMALL_TILDE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The trade mark sign windows-1252 character code model. U+2122 */
static unsigned char TRADE_MARK_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x99 };
static unsigned char* TRADE_MARK_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL = TRADE_MARK_SIGN_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter s with caron windows-1252 character code model. U+0161 */
static unsigned char LATIN_SMALL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9A };
static unsigned char* LATIN_SMALL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_S_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The single right-pointing angle quotation mark windows-1252 character code model. U+203A */
static unsigned char SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9B };
static unsigned char* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL = SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small ligature oe windows-1252 character code model. U+0153 */
static unsigned char LATIN_SMALL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9C };
static unsigned char* LATIN_SMALL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_SMALL_LIGATURE_OE_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter z with caron windows-1252 character code model. U+017E */
static unsigned char LATIN_SMALL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9E };
static unsigned char* LATIN_SMALL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Z_WITH_CARON_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter y with diaeresis windows-1252 character code model. U+0178 */
static unsigned char LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9F };
static unsigned char* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_WINDOWS_1252_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/* WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
