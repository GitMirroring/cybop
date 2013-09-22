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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILL_SOURCE
#define FILL_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/fill_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/filler/part_filler.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Fills the part up with a given element.
 *
 * Expected parametres:
 * - part (required): the part
 * - element (required): the element
 * - count (optional; if null, the part model count will be used instead):
 *   the number of elements to be filled in
 * - index (optional; if null, an index of zero will be used instead):
 *   the index from which to start copying elements to
 * - adjust (optional; the default is "true"; if null, the count WILL BE adjusted):
 *   the flag indicating whether or not the part shall be adjusted to
 *   index + count_of_elements_to_be_copied;
 *   otherwise, the count either remains as is or gets extended,
 *   if the number of elements exceeds the count, in order to avoid
 *   memory errors caused by crossing array boundaries
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_fill(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply fill.");

    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The part part type, model item.
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The part part type, model item data, count.
    void* ptd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part part.
    get_part_knowledge((void*) &p, p0, (void*) PART_FILL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) PART_FILL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get element part.
    get_part_knowledge((void*) &e, p0, (void*) ELEMENT_FILL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) ELEMENT_FILL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get count part.
    get_part_knowledge((void*) &c, p0, (void*) COUNT_FILL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_FILL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get index part.
    get_part_knowledge((void*) &i, p0, (void*) INDEX_FILL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) INDEX_FILL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get adjust part.
    get_part_knowledge((void*) &a, p0, (void*) ADJUST_FILL_MODIFICATION_LOGIC_CYBOL_NAME, (void*) ADJUST_FILL_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get part part type, model item.
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get element part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get adjust part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part part type, model item data, count.
    copy_array_forward((void*) &ptd, pt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get element part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get adjust part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // CAUTION! Set adjust count flag to "true" by default,
    // to avoid memory errors.
    int adjust = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the part model count by default.
    copy_integer((void*) &count, pmc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit index that was given as parametre.
    copy_integer((void*) &index, imd);
    // Set adjust flag to the value that was given as parametre.
    copy_integer((void*) &adjust, amd);

    // Fill part up with given element.
    fill_part(p, emd, ptd, (void*) &count, (void*) &index, (void*) &adjust);
}

/* FILL_SOURCE */
#endif
