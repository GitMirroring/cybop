/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FILE_CYBOL_DESERIALISER_SOURCE
#define FILE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/encoding/cybol/unicode_cybol_encoding.c"
#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/language/cybol/state/text_state_cybol_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
//
// CAUTION! Do NOT include file "receiver",
// since it would cause a circular reference.
// Mention the function via forward declaration instead (see below).
// #include "../../../../executor/communicator/receiver/receiver.c"
//
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/dispatcher/closer/basic/basic_closer.c"
#include "../../../../executor/dispatcher/opener/file/file_opener.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

#ifdef WIN32 // compiler error without this line (but actually forward declaration of "receive_data" below should suffice):
    #include "../../../../executor/communicator/receiver/receiver.c"
#endif

//
// Forward declaration
//

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24);

/**
 * Deserialises a cybol file.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the channel data
 * @param p4 the encoding data
 * @param p5 the language data
 * @param p6 the format data
 * @param p7 the encoding item
 */
void deserialise_cybol_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol file.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol file. *p3: %i\n", *((int*) p3));

    // The encoding data.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    //?? TODO: Delete this block below in the future?
    //
    // Should ALL xml attributes be specified in cybol, also "encoding"?
    // This default here is temporary in order to not to have to specify it in each cybol file.
    //
    // CAUTION! The default encoding value MUST NOT be assigned
    // in general and for all parts above, since the function
    // "receive_data" below tests the encoding for null.
    // If the language is e.g. "message/binary", then NO encoding
    // is given, since it does not make sense for images etc.
    // Therefore, assign standard encoding ONLY for
    // channel "file" and language "text/cybol".
    //
    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pedi = (int*) p4;

        // The default value assigned to an item's "data" element is zero.
        if (*pedi == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // An encoding was NOT specified.
            //

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pldi = (int*) p5;

                if (*pldi == *CYBOL_TEXT_STATE_CYBOI_LANGUAGE) {

                    //
                    // This is the standard language "text/cybol".
                    //

                    //
                    // Assign "utf-8" as default encoding.
                    //
                    // Data read from a utf-8-encoded cybol file NEED to be converted.
                    //
                    // Set default encoding ONLY if channel is FILE, since otherwise,
                    // wrong conversions will occur in "communicator/receiver/"
                    // and cybol applications not run.
                    //
                    modify_item(p7, (void*) UTF_8_CYBOI_ENCODING, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

                    //
                    // Get part encoding item data.
                    //
                    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                    // Inside the structure, arrays may have been reallocated,
                    // with elements pointing to different memory areas now.
                    //
                    copy_array_forward((void*) &ed, p7, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                }
            }
        }
    }

    // The file identification (descriptor).
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Open file.
    open_file((void*) &id, p1, p2, (void*) READ_OPEN_MODE_FILE_MODEL, (void*) READ_OPEN_MODE_FILE_MODEL_COUNT);

    //
    // Fill part model item taken from cybol source part properties.
    //
    // CAUTION! What is the properties in a parsed xml/cybol file,
    // becomes the model in the cyboi-internal knowledge tree.
    //
    // CAUTION! Use the CYBOL cyboi destination type determined above
    // (and NOT the CYBOI destination type)!
    //
    receive_data(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, p5, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3);

    // Close file.
    close_basic((void*) &id);
}

/* FILE_CYBOL_DESERIALISER_SOURCE */
#endif
