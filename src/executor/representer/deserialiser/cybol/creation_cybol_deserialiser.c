/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Creates a new node based on the given cybol data.
 *
 * @param p0 the destination item
 * @param p1 the source cybol tree name data
 * @param p2 the source cybol tree name count
 * @param p3 the source cybol tree channel data
 * @param p4 the source cybol tree channel count
 * @param p5 the source cybol tree format data
 * @param p6 the source cybol tree format count
 * @param p7 the source cybol tree model data
 * @param p8 the source cybol tree model count
 * @param p9 the source cybol tree properties data
 * @param p10 the source cybol tree properties count
 * @param p11 the language properties (constraints) data
 * @param p12 the language properties (constraints) count
 * @param p13 the knowledge memory part (pointer reference)
 * @param p14 the stack memory item
 * @param p15 the internal memory data
 * @param p16 the language
 * @param p17 the decimal separator data
 * @param p18 the decimal separator count
 * @param p19 the thousands separator data
 * @param p20 the thousands separator count
 * @param p21 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p22 the root node flag
 * @param p23 the initial fileread flag
 */
void deserialise_cybol_creation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol creation.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. name data p1: %ls\n", (wchar_t*) p1);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. name count *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. channel data p3: %ls\n", (wchar_t*) p3);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. channel count *p4: %i\n", *((int*) p4));
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. format data p5: %ls\n", (wchar_t*) p5);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. format count *p6: %i\n", *((int*) p6));
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. model data p7: %ls\n", (wchar_t*) p7);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. model count *p8: %i\n", *((int*) p8));

    //
    // Declaration
    //

    // The temporary channel, format, type item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary channel, format, type item data.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The new destination part.
    void* dp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The new destination part name, channel, format, type, model, properties item.
    void* dpn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dpf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dpt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dpm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dpp = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocation
    //

    // Allocate temporary channel, format, type item.
    allocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    //
    // Initialisation
    //

    //
    // Initialise temporary format, type item.
    //
    // CAUTION! Assign format "ascii_text" and type "character_text" by default.
    // If the language is e.g. "message/binary", then NO FORMAT has to be given.
    // Without format, the deserialised type will be null as well.
    // But a type IS NECESSARY for allocating the part below.
    // Therefore, use type "char" in these cases.
    // (It might be any other type as well.)
    //
    // CAUTION! A type IS ESSENTIAL in order to avoid memory leaks.
    // Logic formats like "live/exit" do not have a counterpart as type.
    // Also, invalid formats may have been used in a cybol file.
    // Therefore, for these cases, assign a default type here.
    //
    // CAUTION! Do NOT delegate this initialisation to the functions
    // "deserialise_cybol_format" and "deserialise_cybol_type" respectively,
    // since it is not in their context and responsibility.
    //
    modify_item(f, (void*) ASCII_TEXT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
    modify_item(t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Deserialisation
    //

    // Deserialise channel.
    deserialise_cybol_channel(c, p3, p4);
    // Deserialise cybol source format (mime type as string) into cyboi-internal format (an integer).
    deserialise_cybol_format(f, p5, p6);

    //
    // Get temporary channel, format item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &cd, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    //
    // Decode cyboi-internal type into cyboi runtime type.
    //
    // CAUTION! Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a cyboi "part".
    // Therefore, a runtime type has to be figured out here.
    // It is needed for allocating the new part.
    //
    deserialise_cybol_type(t, fd);
    //
    // Get temporary type item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Allocation
    //

    //
    // Allocate new destination part.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! Use the cyboi runtime type determined above
    // (NOT the mime type format)!
    //
    allocate_part((void*) &dp, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

    //
    // Retrieval
    //

    //
    // Get new destination part name, format, type, model, properties item.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &dpn, dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dpf, dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dpt, dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dpm, dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dpp, dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    //
    // Assignment
    //

    // Fill new destination part name item.
    modify_item(dpn, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
    // Fill new destination part format item.
    modify_item(dpf, fd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
    // Fill new destination part type item.
    modify_item(dpt, td, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

/*
    //?? TESTING ONLY BEGIN
    #include "inspector.h"
    fwprintf(stdout, L"Debug: Deserialise cybol creation. The source cybol tree model data p7: %i\n", p7);
    fwprintf(stdout, L"Debug: Deserialise cybol creation. The source cybol tree model count p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Deserialise cybol creation. The source cybol tree model count *p8: %i\n", *((int*) p8));
    inspect_knowledge_data((void*) L"inspect_1", (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL, p7, p8, p13, p14, p15);
    //?? TESTING ONLY END
*/

    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. Fill new destination part model item. fd: %i\n", fd);

    // Fill new destination part model item by processing cybol tree data depending on channel (inline or file).
    deserialise_cybol_source(dpm, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, fd, cd);

    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. Fill new destination part properties item. fd: %i\n", fd);

    // Fill new destination part properties item.
    deserialise_cybol_source(dpp, p9, p10, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INLINE_CYBOI_CHANNEL);

    //
    // Addition
    //

    //?? fwprintf(stdout, L"Debug: Deserialise cybol creation. Add new destination part to destination. fd: %i\n", fd);

    //
    // Add new destination part to destination item.
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    //
    modify_item(p0, (void*) &dp, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Deallocation
    //

    // Deallocate temporary channel, format, type item.
    deallocate_item((void*) &c, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}
