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

#ifndef PART_CLONER_SOURCE
#define PART_CLONER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Clones the source part into the destination part.
 *
 * Essentially, the "clone" function does nothing else than combining:
 * - allocation of a destination or cloning of a source element
 * - copying content from source to destination
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source part
 */
void clone_part(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Clone part.");

        // The destination part references, name, type, model, properties item.
        void* dr = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dn = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dl = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* df = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dt = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dp = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source part name, type, model, properties item.
        // CAUTION! The source part references are NOT needed,
        // since the destination part HAS TO have its very own reference counter,
        // for rubbish (garbage) collection to work properly.
        void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source part type data.
        void* std = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source part name, type, model, properties item.
        copy_array_forward((void*) &sn, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENCODING_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sl, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sf, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &st, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sp, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        // Get source part type data.
        copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Allocate destination part references item.
        allocate_item((void*) &dr, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Initialise destination part references item with ZERO,
        // for rubbish (garbage) collection to work properly.
        overwrite_item_element(dr, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Clone source part name, type, model, properties item.
        // CAUTION! A simple and fast approach using the "memcpy"
        // function call does NOT work here!
        // It would lead to a shallow copy with pointers just copied
        // but referencing the same elements as the source part!
        // Therefore, each single element has to be processed in a loop,
        // in order to dive into its structure and copy child nodes as well.
        clone_item((void*) &dn, sn, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
        clone_item((void*) &dc, sc, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_item((void*) &de, se, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_item((void*) &dl, sl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_item((void*) &df, sf, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_item((void*) &dt, st, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_item((void*) &dm, sm, std);
        clone_item((void*) &dp, sp, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        // Allocate destination part.
        allocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        // Set destination part references, name, channel, encoding, language, format, type, model, properties.
        copy_array_forward(*p, (void*) &dr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) REFERENCES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NAME_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHANNEL_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &de, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENCODING_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) LANGUAGE_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &df, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FORMAT_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TYPE_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MODEL_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PROPERTIES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not clone part. The destination part is null.");
    }
}

/* PART_CLONER_SOURCE */
#endif
