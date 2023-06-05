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

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Decodes the dos character data element into utf-32 wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the encoding
 */
void decode_dos_element(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode dos element.");

    //
    // The source character.
    //
    // CAUTION! The character MUST NOT be initialised with null.
    // If the source character at the given index is not known
    // or cannot be converted due to a wrong encoding or an error,
    // the null character will be added to the destination.
    //
    // But this is going to cause trouble when deserialising the string,
    // since the null character often serves as termination.
    //
    // Therefore, do NOT use the following initialisation:
    // unsigned char c = *NULL_ASCII_CHARACTER_CODE_MODEL;
    //
    // Instead, the SPACE character is used by default.
    //
    unsigned char c = *SPACE_ASCII_CHARACTER_CODE_MODEL;

    // Get source character at given index.
    copy_array_forward((void*) &c, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    //?? fwprintf(stdout, L"Debug: decode dos element c as char: %c\n", c);
    //?? fwprintf(stdout, L"Debug: decode dos element c as int: %i\n", c);

    // Decode source character.
    decode_dos_character(p0, (void*) &c, p3);
}
