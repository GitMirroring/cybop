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

#ifndef STANDARD_NODE_CYBOL_DECODER_SOURCE
#define STANDARD_NODE_CYBOL_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/converter/decoder/cybol/model_cybol_decoder.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the cybol standard node.
 *
 * @param p0 the destination item
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part properties data
 * @param p4 the source part properties count
 * @param p5 the source part model tree root node flag
 */
void decode_cybol_node_standard(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode cybol node standard.");

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

    // The runtime channel.
    int rc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The runtime encoding.
    int re = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The runtime type.
    // CAUTION! It is needed e.g. to retrieve the type of the part to be created.
    // Otherwise, it would not be known which part model to create.
    // The source type CANNOT be converted directly into the part's type,
    // because the part model has not been allocated yet when reading
    // the type for the first time.
    int rt = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The runtime model.
    // CAUTION! Certain operations expect well-defined parametres,
    // which are defined as constant inside cyboi.
    int rm = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Decode cybol source channel into cyboi runtime channel constant.
    //
    decode_cybol_channel((void*) &rc, scmd, scmc);
    //
    // Decode cybol source encoding into cyboi runtime encoding constant.
    //
    decode_cybol_encoding((void*) &re, semd, semc);
    //
    // Decode cybol source type into cyboi runtime type constant.
    //
    // A cybol type is of type "wchar_t"; a cyboi-internal type of type "int".
    // Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a cyboi "part".
    // Therefore, the type has to be converted here.
    //
    decode_cybol_type((void*) &rt, stmd, stmc);
    decode_cybol_model((void*) &rm, smmd, smmc);

    //
    // Create new part.
    //
    // CAUTION! This may only be done AFTER having retrieved the source
    // type, since that is needed for allocating the new part.
    //

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name, type, model, properties.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &rt);
    // Get part name, type, model, properties.
    copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    //
    // Process source part properties.
    //
    // CAUTION! What is the properties in a parsed xml/cybol file,
    // becomes the model in the cyboi-internal knowledge tree.
    //

    // Fill part name.
    overwrite_item_element(pn, snmd, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, snmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Fill part type.
    // CAUTION! Use the cyboi RUNTIME type constant as source here!
    // CAUTION! Do NOT use a simple "copy" function here, since this is an item.
    overwrite_item_element(pt, (void*) &rt, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Sometimes, a cybol model represents a type, e.g. when creating a part.
    // Other times, a cybol model represents a colour or other kinds of data.
    // This is indicated by a type with special value, e.g. "text/type".
    // In such cases, the cybol model's character array has to be converted into
    // an integer value, since cyboi processes types in this form internally.
    // See the "type" property's "model" attribute in the following examples:
    //
    // Example 1:
    //
    // <part name="create_counter" channel="inline" type="memorise/create" model="">
    //     <property name="name" channel="inline" type="text/plain" model="counter"/>
    //     <property name="type" channel="inline" type="text/type" model="memory/compound"/>
    //     <property name="element" channel="inline" type="text/plain" model="part"/>
    // </part>
    //
    // Example 2:
    //
    // <part name="mc_item" channel="inline" type="text/plain" model="m - Start Midnight Commander (MC)">
    //     <property name="position" channel="inline" type="number/integer" model="1,3,0"/>
    //     <property name="size" channel="inline" type="number/integer" model="68,1,1"/>
    //     <property name="background" channel="inline" type="text/plain" model="blue"/>
    //     <property name="foreground" channel="inline" type="text/plain" model="white"/>
    //     <property name="bold" channel="inline" type="logicvalue/boolean" model="true"/>
    // </part>
    //

    // The cyboi model flag indicating whether or not
    // the given model is a cyboi-internal constant.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_all_array((void*) &f, (void*) &rt, (void*) TYPE_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, lc, (void*) TYPE_TEXT_STATE_CYBOL_TYPE_COUNT);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Decode cybol source model (representing an type)
        // into cyboi runtime type constant.
        decode_type((void*) &rm, smmd, smmc);

        // Fill part model.
        // CAUTION! Use the cyboi RUNTIME model constant as source here!
        overwrite_item_element(pm, (void*) &rm, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    } else {

        // Fill part model and properties.
        // Receive and decode source model, properties into part model, properties.
        receive_data(pm, pp, smmd, smmc, (void*) &rt, (void*) &rc);
    }

    //
    // Process source part model.
    //
    // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
    // becomes the properties (meta data) in the cyboi-internal knowledge tree.
    //

    // Fill part properties.
    // Decode the new part's meta information,
    // by recursively calling this function itself.
    decode_cybol_model(pd, p1, p2, p5);

    //
    // Add part to destination.
    //

    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* STANDARD_NODE_CYBOL_DECODER_SOURCE */
#endif
