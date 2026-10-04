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

#ifndef INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER
#define INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Interface
//
// IANA media type: not defined
// Self-defined media type: interface
// This media type is a CYBOL extension.
//
// This MIME type was taken from/inspired by the KDE desktop.
// It is used for text- and graphical user interfaces in CYBOI.
//

/**
 * The interface/graphical state cybol language.
 */
static wchar_t* GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE = L"interface/graphical";
static int* GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The interface/x-winamp-skin state cybol language.
 */
static wchar_t* X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE = L"interface/x-winamp-skin";
static int* X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER */
#endif
