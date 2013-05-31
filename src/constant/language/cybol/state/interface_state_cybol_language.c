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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// This MIME type was taken from/ inspired by the KDE desktop.
// It is used for text- and graphical user interfaces in CYBOI.
//

/**
 * The interface/graphical cybol language.
 */
static wchar_t GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e', L'/', L'g', L'r', L'a', L'p', L'h', L'i', L'c', L'a', L'l'};
static wchar_t* GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE = GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* GRAPHICAL_INTERFACE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The interface/x-winamp-skin cybol language.
 */
static wchar_t X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e', L'/', L'x', L'-', L'w', L'i', L'n', L'a', L'm', L'p', L'-', L's', L'k', L'i', L'n'};
static wchar_t* X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE = X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* X_WINAMP_SKIN_INTERFACE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INTERFACE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
