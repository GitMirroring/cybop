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

#ifndef XDT_DESERIALISER_SOURCE
#define XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/xdt/basic/basic_xdt_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises xdt data.
 *
 * Parse data in two steps:
 * 1 parse all xdt fields and add them to a temporary part
 * 2 loop through the list of fields and interpret these
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 */
void deserialise_xdt(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt.");

/*??
    // Create temporary part.
    //?? TODO temporary_part

    // Deserialise all xdt fields.
    deserialise_xdt_basic(temporary_part, p2, p3);

    if-else
    deserialise_xdt_bdt(p0, p1, temporary_part_model_item_data, temporary_part_model_item_count);
    deserialise_xdt_gdt(p0, p1, temporary_part_model_item_data, temporary_part_model_item_count);
    deserialise_xdt_ldt(p0, p1, temporary_part_model_item_data, temporary_part_model_item_count);
*/
}

/* XDT_DESERIALISER_SOURCE */
#endif
