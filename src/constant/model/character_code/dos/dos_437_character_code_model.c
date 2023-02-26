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

#ifndef DOS_437_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define DOS_437_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains dos-437 character code constants.
//

//
// Code page 437 (CCSID 437) is the character set of the original IBM PC (personal computer).
// It is also known as CP437, OEM-US, OEM 437, PC-8 or DOS Latin US.
// The set includes all printable ASCII characters as well as some accented
// letters (diacritics), Greek letters, icons, and line-drawing symbols.
// It is sometimes referred to as the "OEM font" or "high ASCII", or as
// "extended ASCII" (one of many mutually incompatible ASCII extensions).
//
// This character set remains the primary set in the core of any EGA and
// VGA-compatible graphics card. As such, text shown when a PC reboots,
// before fonts can be loaded and rendered, is typically rendered using
// this character set. Many file formats developed at the time of the
// IBM PC are based on code page 437 as well.
//
// Reference:
// https://en.wikipedia.org/wiki/Code_page_437
//

//?? TODO: Add dos character codes here!
//?? Add further files for other character codes in this directory!

/* DOS_437_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
