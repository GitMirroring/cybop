/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_OVERWRITER_SOURCE
#define PART_OVERWRITER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/converter/decoder/wide_character_abstraction_decoder.c"
#include "../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Overwrites the destination part element given by the
 * destination part element index with the source array.
 *
 * The destination part element may be either of:
 * name, abstraction, model, details.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination part index
 * @param p5 the source array index
 * @param p6 the adjust flag
 * @param p7 the destination part element index
 */
void overwrite_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part element.");

    // The destination part element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get destination part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p7);

    // Overwrite item as element of the part container.
    overwrite_item_element(e, p1, p2, p3, p4, p5, p6, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Overwrites the destination- with the source part.
 *
 * The name, abstraction, details of the destination part
 * remain unchanged. Only the model gets overwritten.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the adjust flag
 */
void overwrite_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part.");

    // The destination model.
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;

    // Get destination model.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Overwrite destination- with source part model item.
    overwrite_item(dm, sm, p2, p3, p4, p5, p6);
}

/**
 * Overwrites the destination- with the source part.
 *
 * CAUTION! The destination part already HAS TO EXIST!
 *
 * CAUTION! This function copies ALL elements: name, abstraction, model, details.
 *
 * @param p0 the destination part
 * @param p1 the source part
 */
void overwrite_part_all(void* p0, void* p1) {

    //?? TODO: Parametres arrive here as normal pointer (NOT pointer reference) to a part.
    //?? They come across array-copy-overwrite etc. and CANNOT be changed to pointer references.
    //?? Figure out how to solve the problem that destination child parts yet have to be allocated
    //?? and where to do this AND where to create the destination part itself!

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part all.");

    // The destination name, abstraction, model, details.
    void* dn = *NULL_POINTER_MEMORY_MODEL;
    void* da = *NULL_POINTER_MEMORY_MODEL;
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source name, abstraction, model, details.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    // The source part elements data, count.
    void* snc = *NULL_POINTER_MEMORY_MODEL;
    void* sad = *NULL_POINTER_MEMORY_MODEL;
    void* sac = *NULL_POINTER_MEMORY_MODEL;
    void* smc = *NULL_POINTER_MEMORY_MODEL;
    void* sdc = *NULL_POINTER_MEMORY_MODEL;

    // Get source name, abstraction, model, details.
    copy_array_forward((void*) &sn, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &sa, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &sm, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &sd, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get source item data, count.
    copy_array_forward((void*) &snc, sn, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sad, sa, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sac, sa, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sdc, sd, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // Allocate destination part.
    // CAUTION! Use source part abstraction for allocation!
    allocate_part(p0, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, sad);

    // Get destination name, abstraction, model, details.
    // CAUTION! These items can only be retrieved AFTER
    // having created the destination part above.
    copy_array_forward((void*) &dn, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &da, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &dm, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &dd, p0, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // Overwrite destination- with source part model item.
    overwrite_item(dn, sn, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, snc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    overwrite_item(da, sa, (void*) INTEGER_MEMORY_ABSTRACTION, sac, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    overwrite_item(dm, sm, sad, smc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    overwrite_item(dd, sd, (void*) PART_MEMORY_ABSTRACTION, sdc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* PART_OVERWRITER_SOURCE */
#endif
