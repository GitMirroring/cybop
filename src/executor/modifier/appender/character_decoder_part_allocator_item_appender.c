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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_DECODER_PART_ALLOCATOR_ITEM_APPENDER_SOURCE
#define CHARACTER_DECODER_PART_ALLOCATOR_ITEM_APPENDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Converts the given characters to wide characters,
 * allocates a part using the wide characters as model
 * and finally appends it to the destination.
 *
 * This is a convenience method ("syntactic sugar")
 * to avoid redundant code, e.g. when converting models
 * with a lot of string processing going on.
 *
 * @param p0 the destination item
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source model
 * @param p4 the source model count
 */
void append_item_allocate_part_decode_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The wide character data, count, size.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate wide character data.
    allocate_array((void*) &d, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Decode multibyte character array into wide character data.
    decode_utf_8_unicode_character_vector((void*) &d, (void*) &c, (void*) &s, p3, p4);

    // Allocate part with wide character data as model and append it to destination item.
    append_item_allocate_part(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, d, (void*) &c, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

    // Deallocate wide character data.
    deallocate_array((void*) &d, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* CHARACTER_DECODER_PART_ALLOCATOR_ITEM_APPENDER_SOURCE */
#endif
