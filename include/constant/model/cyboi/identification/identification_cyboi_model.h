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

#ifndef IDENTIFICATION_CYBOI_MODEL_CONSTANT_HEADER
#define IDENTIFICATION_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"
#include "variable.h"

//
// The pre-processor macros used below may be found in file "variable/cmake_configuration.h":
//
// - PROJECT_VERSION_CMAKE_CONFIGURATION
// - COPYRIGHT_INFORMATION_CMAKE_CONFIGURATION
//

/** The name identification cyboi model. */
static wchar_t* NAME_IDENTIFICATION_CYBOI_MODEL = L"Cybernetics Oriented Interpreter (CYBOI)";
static int* NAME_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The version identification cyboi model. */
static wchar_t* VERSION_IDENTIFICATION_CYBOI_MODEL = PROJECT_VERSION_CMAKE_CONFIGURATION;
static int* VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The slogan identification cyboi model. */
static wchar_t* SLOGAN_IDENTIFICATION_CYBOI_MODEL = L"The universal knowledge processing system.";
static int* SLOGAN_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copyright identification cyboi model. */
static wchar_t* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL = COPYRIGHT_INFORMATION_CMAKE_CONFIGURATION;
static int* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The licence identification cyboi model. */
static wchar_t* LICENCE_IDENTIFICATION_CYBOI_MODEL = L"CYBOI comes with NO WARRANTY,\n"
                                                     L"to the extent permitted by law.\n"
                                                     L"You may redistribute copies of CYBOI\n"
                                                     L"under the terms of the GNU General Public License.\n"
                                                     L"For more information about these matters,\n"
                                                     L"see the files named COPYING.";
static int* LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* IDENTIFICATION_CYBOI_MODEL_CONSTANT_HEADER */
#endif
