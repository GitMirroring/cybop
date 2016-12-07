/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_PROPERTIES_HANDLER_SOURCE
#define ELEMENT_PROPERTIES_HANDLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/memoriser/allocator/part_allocator.c"
#include "../../executor/modifier/appender/item_appender.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/overwriter/part_overwriter.c"
#include "../../logger/logger.c"

/**
 * Handles the properties element.
 *
 * It represents a variable value to be stored on stack memory.
 *
 * @param p0 the properties data
 * @param p1 the properties index
 * @param p2 the stack memory item
 */
void handle_properties_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle properties element.");

    // The source property part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source property part name, format, type, model, properties item.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source property part name, format, type, model, properties item data, count.
    void* snd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination variable part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source property part with given index.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);
    // Get source property part name, format, model, properties item.
    copy_array_forward((void*) &sn, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sf, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &st, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sp, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get source property part name, format, model, properties item data, count.
    copy_array_forward((void*) &snd, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snc, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfd, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spd, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spc, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Allocate destination variable part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, std);

    // Copy destination variable part name.
    overwrite_part_element(d, snd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, snc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    // Copy destination variable part format.
    overwrite_part_element(d, sfd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    // Copy destination variable part type.
    // CAUTION! Assigning the type IS ESSENTIAL for properly
    // deallocating the part and its child parts later.
    overwrite_part_element(d, std, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Copy destination variable part model.
    //
    //?? Later, this will have to be replaced by a copy/clone function call.
    //?? See: copy_item(), copy_part() for cloning.
    //
    overwrite_part_element(d, smd, std, smc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Copy destination variable part properties.
    //?? TODO! Not implemented yet.
    //?? Later, this will have to be replaced by a copy/clone function call.
    //?? See: copy_item(), copy_part() for cloning.

    //
    // Add destination variable part to stack memory.
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    //
    // The stack memory holds ONLY parts that were allocated especially,
    // as done above, with copied/cloned values.
    // Hence, these parts may get deallocated automatically by rubbish
    // (garbage) collection, since nothing else is referencing them.
    //
    append_item_element(p2, (void*) &d, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ELEMENT_PROPERTIES_HANDLER_SOURCE */
#endif
