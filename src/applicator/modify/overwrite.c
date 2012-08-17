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

#ifndef OVERWRITE_SOURCE
#define OVERWRITE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/modification/overwrite_modification_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../executor/modifier/overwriter/part_overwriter.c"
#include "../../logger/logger.c"

/**
 * Overwrites the destination- with the source part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the type of data
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be overwritten
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 * - adjust (optional; the default is "true"; if null, the destination count WILL BE adjusted):
 *   the flag indicating whether or not the destination shall be adjusted to
 *   destination_index + count_of_elements_to_be_copied;
 *   otherwise, the destination count either remains as is or gets extended,
 *   if the number of elements exceeds the destination count, in order to avoid
 *   memory errors caused by crossing array boundaries
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_overwrite(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply overwrite.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part.
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model.
    void* dim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item.
    void* sim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item.
    void* adm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item count.
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item data.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model item data.
    void* dimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item data.
    void* simd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item data.
    void* admd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_knowledge((void*) &d, p0, (void*) DESTINATION_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) DESTINATION_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get source part.
    get_part_knowledge((void*) &s, p0, (void*) SOURCE_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) SOURCE_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get type part.
    get_part_knowledge((void*) &t, p0, (void*) TYPE_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) TYPE_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get count part.
    get_part_knowledge((void*) &c, p0, (void*) COUNT_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) COUNT_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get destination index part.
    get_part_knowledge((void*) &di, p0, (void*) DESTINATION_INDEX_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) DESTINATION_INDEX_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get source index part.
    get_part_knowledge((void*) &si, p0, (void*) SOURCE_INDEX_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) SOURCE_INDEX_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get adjust part.
    get_part_knowledge((void*) &ad, p0, (void*) ADJUST_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME, (void*) ADJUST_OVERWRITE_MODIFICATION_OPERATION_CYBOL_NAME_COUNT, p1, p2);

    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination index part model item.
    copy_array_forward((void*) &dim, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source index part model item.
    copy_array_forward((void*) &sim, si, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get adjust part model item.
    copy_array_forward((void*) &adm, ad, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source part model item count.
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get destination index part model item data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source index part model item data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get adjust part model item data.
    copy_array_forward((void*) &admd, adm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

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

/*??
//?? TEST BEGIN
fwprintf(stdout, L"TEST overwrite d*: %i\n", d);
fwprintf(stdout, L"TEST overwrite s*: %i\n", s);
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST overwrite dmd: %i\n", dmd);
fwprintf(stdout, L"TEST overwrite *dmd: %i\n", *((int*) dmd));
fwprintf(stdout, L"TEST overwrite dmc: %i\n", dmc);
fwprintf(stdout, L"TEST overwrite *dmc: %i\n", *((int*) dmc));
fwprintf(stdout, L"TEST overwrite s: %i\n", s);
fwprintf(stdout, L"TEST overwrite sm: %i\n", sm);
fwprintf(stdout, L"TEST overwrite smd: %i\n", smd);
fwprintf(stdout, L"TEST overwrite smd als wchar_t: %ls\n", (wchar_t*) smd);
fwprintf(stdout, L"TEST overwrite smd als char: %s\n", (char*) smd);
fwprintf(stdout, L"\n");
fwprintf(stdout, L"TEST overwrite *smd: %i\n", *((int*) smd));
fwprintf(stdout, L"TEST overwrite smc: %i\n", smc);
fwprintf(stdout, L"TEST overwrite *smc: %i\n", *((int*) smc));
fwprintf(stdout, L"TEST overwrite tmd: %i\n", tmd);
fwprintf(stdout, L"TEST overwrite *tmd: %i\n", *((int*) tmd));
fwprintf(stdout, L"TEST overwrite *cmd: %i\n", cmd);
//?? fwprintf(stdout, L"TEST overwrite cmd: %i\n", *((int*) cmd));
fwprintf(stdout, L"TEST overwrite dimd: %i\n", dimd);
//?? fwprintf(stdout, L"TEST overwrite dimd: %i\n", *((int*) dimd));
fwprintf(stdout, L"TEST overwrite simd: %i\n", simd);
//?? fwprintf(stdout, L"TEST overwrite simd: %i\n", *((int*) simd));
fwprintf(stdout, L"TEST overwrite admd: %i\n", admd);
//?? fwprintf(stdout, L"TEST overwrite admd: %i\n", *((int*) admd));
fwprintf(stdout, L"TEST overwrite count: %i\n", count);
fwprintf(stdout, L"TEST overwrite destination_index: %i\n", destination_index);
fwprintf(stdout, L"TEST overwrite source_index: %i\n", source_index);
fwprintf(stdout, L"TEST overwrite adjust: %i\n", adjust);
//?? TEST END
*/

    // Overwrite the destination- with the source part.
    overwrite_part(d, s, tmd, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust);

/*??
//?? TEST BEGIN
fwprintf(stdout, L"TEST overwrite POST dmd: %i\n", dmd);
fwprintf(stdout, L"TEST overwrite POST *dmd: %i\n", *((int*) dmd));
fwprintf(stdout, L"TEST overwrite POST dmc: %i\n", dmc);
fwprintf(stdout, L"TEST overwrite POST *dmc: %i\n", *((int*) dmc));
fwprintf(stdout, L"TEST overwrite POST smd: %i\n", smd);
fwprintf(stdout, L"TEST overwrite POST *smd: %i\n", *((int*) smd));
fwprintf(stdout, L"TEST overwrite POST smc: %i\n", smc);
fwprintf(stdout, L"TEST overwrite POST *smc: %i\n", *((int*) smc));
//?? TEST END
*/
}

/* OVERWRITE_SOURCE */
#endif
