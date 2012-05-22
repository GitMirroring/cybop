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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INODE_STATE_CYBOL_TYPE_CONSTANT_SOURCE
#define INODE_STATE_CYBOL_TYPE_CONSTANT_SOURCE

#include <stddef.h>
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// This MIME type was taken from/ inspired by the KDE desktop.
// It is not sure yet, whether it will be useful in the context of CYBOI.
//

/**
 * The inode/socket cybol type.
 */
static wchar_t SOCKET_INODE_STATE_CYBOL_TYPE_ARRAY[] = {L'i', L'n', L'o', L'd', L'e', L'/', L's', L'o', L'c', L'k', L'e', L't'};
static wchar_t* SOCKET_INODE_STATE_CYBOL_TYPE = SOCKET_INODE_STATE_CYBOL_TYPE_ARRAY;
static int* SOCKET_INODE_STATE_CYBOL_TYPE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INODE_STATE_CYBOL_TYPE_CONSTANT_SOURCE */
#endif
