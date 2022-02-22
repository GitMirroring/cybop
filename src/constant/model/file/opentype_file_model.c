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

#ifndef OPENTYPE_FILE_MODEL_CONSTANT_SOURCE
#define OPENTYPE_FILE_MODEL_CONSTANT_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! The BINARY MODE character "b" is ALWAYS added,
// for reading as well as for writing.
//
// When opening files in text mode, the following might happen:
// - line endings such as <lf> get changed into <lf>+<cr>,
//   especially on windows operating system
// - binary data files such as images get corrupted
//
// However, POSIX systems (including GNU systems) make no distinction
// between text and binary files:
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Opening-Streams
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Descriptors-and-Streams
//
// Since the "b" option is not permitted for function "fdopen",
// additional constants WITHOUT binary mode "b" are provided below.
//

/** The read opentype file model. */
static char* READ_OPENTYPE_FILE_MODEL = "rb";
static int* READ_OPENTYPE_FILE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The read without binary mode opentype file model. */
static char* READ_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL = "r";
static int* READ_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The write opentype file model. */
static char* WRITE_OPENTYPE_FILE_MODEL = "wb";
static int* WRITE_OPENTYPE_FILE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The write without binary mode opentype file model. */
static char* WRITE_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL = "w";
static int* WRITE_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* OPENTYPE_FILE_MODEL_CONSTANT_SOURCE */
#endif
