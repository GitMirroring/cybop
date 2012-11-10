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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ASCII_DECODER_SOURCE
#define ASCII_DECODER_SOURCE

#include "../../../../constant/model/character_code/iso_8859/iso_8859_15_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/character/equal_character_comparator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the ASCII character data into UTF-32 wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source data
 */
void decode_ascii(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode ascii.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_character_equal((void*) &r, p1, (void*) NULL_ASCII_CHARACTER_CODE_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    //?? TODO: Continue here ...
}

/* ASCII_DECODER_SOURCE */
#endif
