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

#ifndef MODIFY_SOURCE
#define MODIFY_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/modifier/part_modifier.c"
#include "../../logger/logger.c"

/**
 * Modifies the destination- with the source part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the type of data
 * - move (optional; if null, deep copying will be used by default):
 *   the flag indicating whether or not to remove source elements after having been copied;
 *   true = SHALLOW copy; false = DEEP copy;
 *   when moving (copying + removing) elements, a shallow copy of the pointer suffices;
 *   when only copying elements, then their whole sub tree needs to be cloned as deep copy
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be modified
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 * - adjust (optional; the default is "true"; if null, the destination count WILL BE adjusted):
 *   the flag indicating whether or not the destination shall be adjusted to
 *   destination_index + count_of_elements_to_be_copied;
 *   otherwise, the destination count by default remains as is
 *   and only gets extended, if the number of elements exceeds the destination count,
 *   in order to avoid memory errors caused by crossing array boundaries
 * - model (optional): the flag indicating whether all children of the MODEL are to be deleted;
 *   however, at least ONE of "model" or "properties" HAS TO BE specified
 * - properties (optional): the flag indicating whether all children of the PROPERTIES are to be deleted;
 *   however, at least ONE of "model" or "properties" HAS TO BE specified
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_modify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply modify.");

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
    // The destination index part.
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;

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
    // The destination index part model item.
    void* dim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item.
    void* sim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item.
    void* adm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part model item.
    void* mom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part model item.
    void* prm = *NULL_POINTER_STATE_CYBOI_MODEL;

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
    // The destination index part model item data.
    void* dimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item data.
    void* simd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item data.
    void* admd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model model item data.
    void* momd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties model item data.
    void* prmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_MODIFICATION_LOGIC_CYBOL_NAME, (void*) TYPE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get move part.
    get_part_name((void*) &m, p0, (void*) MOVE_MODIFICATION_LOGIC_CYBOL_NAME, (void*) MOVE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination index part.
    get_part_name((void*) &di, p0, (void*) DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source index part.
    get_part_name((void*) &si, p0, (void*) SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get adjust part.
    get_part_name((void*) &ad, p0, (void*) ADJUST_MODIFICATION_LOGIC_CYBOL_NAME, (void*) ADJUST_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get model part.
    get_part_name((void*) &mo, p0, (void*) MODEL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) MODEL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get properties part.
    get_part_name((void*) &pr, p0, (void*) PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME, (void*) PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get destination part type item.
    copy_array_forward((void*) &dt, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get source part type, model item.
    copy_array_forward((void*) &st, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get move part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination index part model item.
    copy_array_forward((void*) &dim, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source index part model item.
    copy_array_forward((void*) &sim, si, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get adjust part model item.
    copy_array_forward((void*) &adm, ad, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get model model item.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get properties model item.
    copy_array_forward((void*) &prm, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

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
    // Get destination index part model item data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source index part model item data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get adjust part model item data.
    copy_array_forward((void*) &admd, adm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get model model item data.
    copy_array_forward((void*) &momd, mom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get properties model item data.
    copy_array_forward((void*) &prmd, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int destination_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int source_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // CAUTION! Set adjust count flag to "true" by default,
    // to avoid memory errors.
    int adjust = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit destination index that was given as parametre.
    copy_integer((void*) &destination_index, dimd);
    // Use the explicit source index that was given as parametre.
    copy_integer((void*) &source_index, simd);
    // Set adjust flag to the value that was given as parametre.
    copy_integer((void*) &adjust, admd);

    // Modify part by applying operation.
    modify_part(d, s, dtd/*??tmd*/, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust, momd, prmd, p5);

/*??
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

                // Overwrite the destination- with the source part as DEEP copy.
                //?? TODO: Specify deep copying flag with value TRUE, as soon as it is added to all affected functions in cyboi
                modify_part(d, s, tmd, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust);

            } else {

                // The "move" flag IS set.
                // Therefore, the source gets SHALLOW copied to the destination,
                // i.e. only pointers/references to its child nodes get copied.
                // Afterwards, the source elements get REMOVED,
                // i.e. only pointers/references, but not allocated memory.
                // This is no problem, since the destination now holds
                // pointers/references to the original child nodes.

                // Overwrite the destination- with the source part as SHALLOW copy.
                //?? TODO: Specify deep copying flag with value FALSE, as soon as it is added to all affected functions in cyboi
                modify_part(d, s, tmd, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust);

                // Remove elements from source part.
                remove_part(s, std, (void*) &count, (void*) &source_index);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply modify. The destination type and given type are different.");
            fwprintf(stdout, L"ERROR: Could not apply modify. The destination type: %i and given type: %i are different.\n", *((int*) dtd), *((int*) tmd));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply modify. The destination type and source type are different.");
        fwprintf(stdout, L"ERROR: Could not apply modify. The destination type: %i and source type: %i are different.\n", *((int*) dtd), *((int*) std));
    }
*/
}

/* MODIFY_SOURCE */
#endif
