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

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"

/**
 * Creates an empty part consisting of name and type only.
 *
 * The model and properties may get filled with data using a "decode" operation,
 * which is called when a "receive" logic operation is found in cybol.
 *
 * The new knowledge model gets added to either of:
 * - whole model's part hierarchy
 * - whole model's meta hierarchy
 * - knowledge memory's root directly, if no whole element is given
 *
 * Expected parametres:
 * - name (required): the name of the part to be created
 * - type (required): the type (type) of the part to be created
 * - element (optional; if null, the new part will be added to the whole- or knowledge memory MODEL and NOT properties):
 *   the kind of element (knowledge model) to be created (part, meta);
 *   a part element will be added to the whole model's part hierarchy;
 *   a meta element to the whole model's properties hierarchy;
 *   this parametre is optional, but recommended for faster processing
 * - whole (optional; if null, the new part will be added to the knowledge memory root):
 *   the compound to which to add to the new part
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_create(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply create.");

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model data, count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get name part.
    get_name_array((void*) &n, p0, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get type part.
    get_name_array((void*) &a, p0, (void*) TYPE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) TYPE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get element part.
    get_name_array((void*) &e, p0, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get whole part.
    get_name_array((void*) &w, p0, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get name part model.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get element part model.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get name part model data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get element part model data, count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, amd);

    // Fill part.
    overwrite_part_element(p, nmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, nmc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, amd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &r, emd, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // A whole part exists.

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to whole model.");

                // Append part (handed over as array reference) to whole model (being a part itself).
                // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(w, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

            } else {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to knowledge memory root model.");

                // The whole part is null.
                //
                // CAUTION! The new part allocated above HAS TO BE added to the
                // knowledge memory tree, so that it can be deallocated properly at
                // system shutdown and is not lost somewhere in Random Access Memory (RAM).
                // Therefore, if the whole part is null, the knowledge memory is used instead.

                // Append part (handed over as array reference) to knowledge memory root model (being a part itself).
                // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(p2, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &r, emd, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // A whole part exists.

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to whole properties.");

                // Append part (handed over as array reference) to whole properties (being a part itself).
                // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(w, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

            } else {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to knowledge memory root properties.");

                // The whole part is null.
                //
                // CAUTION! The new part allocated above HAS TO BE added to the
                // knowledge memory tree, so that it can be deallocated properly at
                // system shutdown and is not lost somewhere in Random Access Memory (RAM).
                // Therefore, if the whole part is null, the knowledge memory is used instead.

                // Append part (handed over as array reference) to knowledge memory root properties (being a part itself).
                // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(p2, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The kind of element is null, i.e. it was NOT given as parametre.
        // Therefore, add part to whole- or knowledge memory MODEL, by default.

        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // A whole part exists.

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to whole model.");

            // Append part (handed over as array reference) to whole model (being a part itself).
            // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
            // The reason is that deep copying would be used to assign the part inside,
            // instead of just assigning the part reference in a shallow copying manner.
            append_part_element(w, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add part to knowledge memory root.");

            // The whole part is null.
            //
            // CAUTION! The new part allocated above HAS TO BE added to the
            // knowledge memory tree, so that it can be deallocated properly at
            // system shutdown and is not lost somewhere in Random Access Memory (RAM).
            // Therefore, if the whole part is null, the knowledge memory is used instead.

            // Append part (handed over as array reference) to knowledge memory root model (being a part itself).
            // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
            // The reason is that deep copying would be used to assign the part inside,
            // instead of just assigning the part reference in a shallow copying manner.
            append_part_element(p2, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        }
    }
}

/* CREATE_SOURCE */
#endif
