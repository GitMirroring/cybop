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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DOS_850_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define DOS_850_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains dos-850 character code constants.
//

//
// Code page 850 (CCSID 850) (also known as CP 850, IBM 00850, OEM 850, DOS Latin 1)
// is a code page used under DOS and Psion's EPOC16 operating systems in Western Europe.
// Depending on the country setting and system configuration, code page 850 is
// the primary code page and default OEM code page in many countries, including
// various English-speaking locales (e.g. in the United Kingdom, Ireland, and Canada),
// whilst other English-speaking locales (like the United States) default to
// use the hardware code page 437.
//
// Code page 850 differs from code page 437 in that many of the box-drawing
// characters, Greek letters, and various symbols were replaced with additional
// Latin letters with diacritics, thus greatly improving support for Western
// European languages (all characters from ISO 8859-1 are included). At the same
// time, the changes frequently caused display glitches with programs that made
// use of the box-drawing characters to display a GUI-like surface in text mode.
//
// In 1998, code page 858 was derived from this code page by changing code
// point 213 (D5hex) from a dotless i ‹ı› to the euro sign ‹€›.
// Despite this, IBM's PC DOS 2000, released in 1998, changed their definition
// of code page 850 to what they called modified code page 850 now including
// the euro sign at code point 213 instead of adding support for the new code
// page 858.
//
// Systems largely replaced code page 850 with Windows-1252 which contains
// all same letters, and later with Unicode.
//
// Reference:
// https://en.wikipedia.org/wiki/Code_page_850
//

//
// In computing, a hardware code page (HWCP) refers to a code page supported
// natively by a hardware device such as a display adapter or printer.
// The glyphs to present the characters are stored in the alphanumeric character
// generator's resident read-only memory (like ROM or flash) and are thus not
// user-changeable. They are available for use by the system without having to
// load any font definitions into the device first. Startup messages issued by
// a PC's System BIOS or displayed by an operating system before initializing
// its own code page switching logic and font management and before switching
// to graphics mode are displayed in a computer's default hardware code page.
//
// Reference:
// https://en.wikipedia.org/wiki/Hardware_code_page
//

//?? TODO: Add dos character codes here!
//?? Add further files for other character codes in this directory!

/* DOS_850_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
