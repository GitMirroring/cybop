/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The CYBOL type constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

//
// Manipulate bits (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: manipulate
// This media type is a CYBOL extension.
//

/**
 * The manipulate/check logic cybol format.
 *
 * It corresponds to the "BT" (bit) or "BTST" (bit test) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L'c', L'h', L'e', L'c', L'k'};
static wchar_t* CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT = CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/clear logic cybol format.
 *
 * It corresponds to the "BTR" (bit reset) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L'c', L'l', L'e', L'a', L'r'};
static wchar_t* CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT = CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/rotate-left logic cybol format.
 *
 * It corresponds to the "ROL" (rotate left) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L'r', L'o', L't', L'a', L't', L'e', L'-', L'l', L'e', L'f', L't'};
static wchar_t* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT = ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/rotate-right logic cybol format.
 *
 * It corresponds to the "ROR" (rotate right) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L'r', L'o', L't', L'a', L't', L'e', L'-', L'r', L'i', L'g', L'h', L't'};
static wchar_t* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT = ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/set logic cybol format.
 *
 * It corresponds to the "BTS" (bit set) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t SET_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L's', L'e', L't'};
static wchar_t* SET_MANIPULATE_LOGIC_CYBOL_FORMAT = SET_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* SET_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/shift-left logic cybol format.
 *
 * It corresponds to the "SHL" (shift left) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L's', L'h', L'i', L'f', L't', L'-', L'l', L'e', L'f', L't'};
static wchar_t* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT = SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/shift-right logic cybol format.
 *
 * It corresponds to the "SHR" (shift right) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L's', L'h', L'i', L'f', L't', L'-', L'r', L'i', L'g', L'h', L't'};
static wchar_t* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT = SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/toggle logic cybol format.
 *
 * It corresponds to the "CHG" (change) assembler command.
 *
 * This is a CYBOL extension.
 */
static wchar_t TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'a', L'n', L'i', L'p', L'u', L'l', L'a', L't', L'e', L'/', L't', L'o', L'g', L'g', L'l', L'e'};
static wchar_t* TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT = TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT_ARRAY;
static int* TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
