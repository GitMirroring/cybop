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
 * @version $RCSfile: html_converter.c,v $ $Revision: 1.25 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NODE_HTML_ENCODER_SOURCE
#define NODE_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/channel/cybol_channel.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/converter/encoder/html/begin_tag_html_encoder.c"
#include "../../../../executor/converter/encoder/html/end_tag_html_encoder.c"
#include "../../../../executor/converter/encoder/html/structured_tag_content_html_encoder.c"
#include "../../../../executor/converter/encoder/html/tag_content_html_encoder.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the html node into html format.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source details data
 * @param p4 the source details count
 * @param p5 the indentation level
 * @param p6 the source abstraction data
 */
void encode_html_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html node.");

    // The tag part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The tag part model.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The tag part model data, count.
    void* md = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;

    // Get tag part by name.
    get_name_array((void*) &p, p3, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
    // Get tag part model.
    copy_array_forward((void*) &m, p, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get tag part model data, count.
    copy_array_forward((void*) &md, m, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    encode_html_begin_tag(p0, md, mc, p3, p4, p5);

    // The new indentation level, which is the old incremented by one.
    calculate_integer_add(p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, p6, (void*) PART_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_html_structured_tag_content(p0, p1, p2, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_html_tag_content(p0, p1, p2, p5);
        }
    }

    encode_html_end_tag(p0, md, mc, p5);
}

/* NODE_HTML_ENCODER_SOURCE */
#endif
