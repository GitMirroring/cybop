/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

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

/** The TODO windows-1252 character code model. U+00A0 */
static char TODO_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static char* TODO_WINDOWS_1252_CHARACTER_CODE_MODEL = TODO_WINDOWS_1252_CHARACTER_CODE_MODEL_ARRAY;

/* WINDOWS_1252_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
