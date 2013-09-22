/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FIELD_DESCRIPTION_XDT_MODEL_CONSTANT_SOURCE
#define FIELD_DESCRIPTION_XDT_MODEL_CONSTANT_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The id 0001 field description xdt model. */
static wchar_t* ID_0001_FIELD_DESCRIPTION_XDT_MODEL = (wchar_t[]) {L"BDT Version"};
static int* ID_0001_FIELD_DESCRIPTION_XDT_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id 0102 field description xdt model. */
static wchar_t* ID_0102_FIELD_DESCRIPTION_XDT_MODEL = (wchar_t[]) {L"Softwareverantwortlicher (SV)"};
static int* ID_0102_FIELD_DESCRIPTION_XDT_MODEL_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id 0103 field description xdt model. */
static wchar_t* ID_0103_FIELD_DESCRIPTION_XDT_MODEL = L"Name der Software";
static int* ID_0103_FIELD_DESCRIPTION_XDT_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id 0104 field description xdt model. */
static wchar_t ID_0104_FIELD_DESCRIPTION_XDT_MODEL_ARRAY[] = {L'H', L'a', L'r', L'd', L'w', L'a', L'r', L'e'};
static wchar_t* ID_0104_FIELD_DESCRIPTION_XDT_MODEL = ID_0104_FIELD_DESCRIPTION_XDT_MODEL_ARRAY;
static int* ID_0104_FIELD_DESCRIPTION_XDT_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id 8100 field description xdt model. */
static wchar_t ID_8100_FIELD_DESCRIPTION_XDT_MODEL_ARRAY[] = {L'T', L'E', L'S', L'T', L' ', L'8', L'1', L'0', L'0', L' ', L'E', L'N', L'T', L'R', L'Y'};
static wchar_t* ID_8100_FIELD_DESCRIPTION_XDT_MODEL = ID_8100_FIELD_DESCRIPTION_XDT_MODEL_ARRAY;
static int* ID_8100_FIELD_DESCRIPTION_XDT_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FIELD_DESCRIPTION_XDT_MODEL_CONSTANT_SOURCE */
#endif
