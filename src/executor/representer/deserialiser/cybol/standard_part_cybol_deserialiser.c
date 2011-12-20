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

#ifndef STANDARD_PART_CYBOL_DESERIALISER_SOURCE
#define STANDARD_PART_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/cybol_name.c"
#include "../../../../constant/type/cyboi/cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/encoding_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/properties_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cyboi_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/name_getter/array_name_getter.c"
#include "../../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../../logger/logger.c"

//
// Forward declaration.
//

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Deserialises the cybol standard part.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the root part flag
 */
void deserialise_cybol_part_standard(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol part standard.");

    //
    // Identify source part properties parametres.
    //

    // The source name, channel, encoding, type, model part.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, type, model part model.
    void* snm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sem = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, type, model part model data, count.
    void* snmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* semd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* semc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source name, channel, encoding, type, model part.
    get_name_array((void*) &sn, p3, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &sc, p3, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &se, p3, (void*) ENCODING_CYBOL_NAME, (void*) ENCODING_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &st, p3, (void*) TYPE_CYBOL_NAME, (void*) TYPE_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &sm, p3, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p4);

    //
    // Get source name, channel, encoding, type, model part model.
    //
    // CAUTION! Do NOT use the following names here:
    // - NAME_PART_STATE_CYBOI_NAME
    // - CHANNEL_PART_STATE_CYBOI_NAME
    // - ENCODING_PART_STATE_CYBOI_NAME
    // - TYPE_PART_STATE_CYBOI_NAME
    // - MODEL_PART_STATE_CYBOI_NAME
    //
    // The corresponding parts were already retrieved above.
    // What is wanted here, is just their MODEL containing the actual data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &snm, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scm, sc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sem, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source name, channel, encoding, type, model part model data, count.
    copy_array_forward((void*) &snmd, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snmc, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmd, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmc, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semd, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semc, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stmc, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmd, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmc, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Convert some cybol source data (strings) into cyboi destination data (integer).
    //

    // The destination channel.
    int dc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination encoding.
    int de = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination type cybol form.
    // CAUTION! This is a cyboi integer representing a cybol mime type.
    int dtc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination type.
    // CAUTION! It is needed e.g. to retrieve the type of the part to be created.
    // Otherwise, it would not be known which part model to create.
    // CAUTION! The source type CANNOT be converted directly into the part's type,
    // because the part model has not been allocated yet when reading
    // the type for the first time.
    int dt = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The root flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Decode cybol source channel into cyboi destination channel.
    deserialise_cybol_channel((void*) &dc, scmd, scmc);
    // Decode cybol source encoding into cyboi destination encoding.
    deserialise_cybol_encoding((void*) &de, semd, semc);
    // Decode cybol source type into cybol cyboi destination type.
    deserialise_cybol_type((void*) &dtc, stmd, stmc);
    // Decode cybol cyboi destination type into cyboi destination type.
    // CAUTION! A cybol type is of type "wchar_t"; a cyboi-internal type of type "int".
    // Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a cyboi "part".
    // Therefore, the type has to be converted here.
    deserialise_cybol_cyboi_type((void*) &dt, (void*) &dtc);

    // CAUTION! This test is IMPORTANT!
    // If a source type attribute is not given,
    // then this is (hopefully) the cybol root tag
    // and a part is allocated.
    // If the cybol developer forgot to specify a type,
    // then the "part" type is used as default here.
    compare_integer_smaller((void*) &r, (void*) &dt, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer((void*) &dt, PART_ELEMENT_STATE_CYBOI_TYPE);
    }

    //
    // Create new part.
    //
    // CAUTION! This may only be done AFTER having retrieved the
    // source type, since that is needed for allocating the new part.
    //

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name, type, model, properties.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    // CAUTION! Use the CYBOI destination type determined above
    // (and NOT the CYBOL cyboi destination type)!
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &dt);
    // Get part name, type, model, properties.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Fill part name.
    overwrite_item_element(pn, snmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, snmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part type.
    // CAUTION! Use the CYBOI destination type determined above
    // (and NOT the CYBOL cyboi destination type)!
    // CAUTION! Do NOT use a simple "copy" function here, since this is an item.
    overwrite_item_element(pt, (void*) &dt, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part model taken from cybol source part properties.
    // CAUTION! What is the properties in a parsed xml/cybol file,
    // becomes the model in the cyboi-internal knowledge tree.
    // CAUTION! Use the CYBOL cyboi destination type determined above
    // (and NOT the CYBOI destination type)!
    // CAUTION! A null pointer is handed over as last parametre here.
    // When reading cybol, the only possible two channels are "inline" and "file".
    // The internal memory (last parametre) is only necessary for
    // "terminal", "x_window_system" and similar channels.
    receive_data(pm, pp, smmd, smmc, (void*) &dtc, (void*) &de, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &dc);
    // Fill part properties taken from cybol source part model.
    // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
    // becomes the properties (meta data) in the cyboi-internal knowledge tree.
    deserialise_cybol_properties(pp, p1, p2, p5);

    //
    // Add part to destination.
    //

    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* STANDARD_PART_CYBOL_DESERIALISER_SOURCE */
#endif
