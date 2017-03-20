/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPEND_SOURCE
#define APPEND_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/append_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/modifier/appender/part_appender.c"
#include "../../executor/modifier/remover/part_remover.c"
#include "../../logger/logger.c"

/**
 * Appends the source- to the destination part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the operand type which is equal for both operands
 * - move (optional; if null, deep copying will be used by default):
 *   the flag indicating whether or not to remove source elements after having been copied;
 *   true = SHALLOW copy; false = DEEP copy;
 *   when moving elements, a shallow copy of the pointer suffices;
 *   when copying elements, then their whole sub tree needs to be cloned as deep copy
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be appended
 * - index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_append(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply append.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part type item.
    void* dt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model item.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part type item data.
    void* dtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model item data, count.
    void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item data.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part model item data.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) TYPE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get move part.
    get_part_name((void*) &m, p0, (void*) MOVE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) MOVE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get index part.
    get_part_name((void*) &i, p0, (void*) INDEX_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) INDEX_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get move part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get destination part type item data.
    copy_array_forward((void*) &dtd, dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source part type, model item data, count.
    copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get move part model item data.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit index that was given as parametre.
    copy_integer((void*) &index, imd);

    //
    // CAUTION! The following comparisons ARE IMPORTANT.
    //
    // If a wrong knowledge path is given, e.g. with non-existing node-names,
    // then a cybol operation might write data into a wrong destination,
    // e.g. source data of format "text/plain" (type wide character)
    // into a destination of format "element/part" (type pointer).
    //
    // Therefore, the destination- and source type
    // as well as the given type property are compared here.
    //

    if (*((int*) dtd) == *((int*) std)) {

        if (*((int*) dtd) == *((int*) tmd)) {

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &r, mmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // CAUTION! Do NOT easily change the compare logic here.
            // The "move" flag might be null, since it is optional.
            // Comparison ignores null values inside,
            // so that the comparison result remains unchanged.
            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The "move" flag is NOT set.
                // Therefore, the source gets DEEP copied to the destination.

                // Append the source- to the destination part as DEEP copy.
                append_part(d, s, tmd, (void*) &count, (void*) &index);

            } else {

                // The "move" flag IS set.
                // Therefore, the source gets SHALLOW copied to the destination,
                // i.e. only pointers/references to its child nodes get copied.
                // Afterwards, the source elements get REMOVED,
                // i.e. only pointers/references, but not allocated memory.
                // This is no problem, since the destination now holds
                // pointers/references to the original child nodes.

                // Append the source- to the destination part as SHALLOW copy.
                append_part(d, s, tmd, (void*) &count, (void*) &index);

                // Remove elements from source part.
                remove_part(s, std, (void*) &count, (void*) &index);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply append. The destination type and given type are different.");
            fwprintf(stdout, L"ERROR: Could not apply append. The destination type: %i and given type: %i are different.\n", *((int*) dtd), *((int*) tmd));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply append. The destination type and source type are different.");
        fwprintf(stdout, L"ERROR: Could not apply append. The destination type: %i and source type: %i are different.\n", *((int*) dtd), *((int*) std));
    }
}

/* APPEND_SOURCE */
#endif
