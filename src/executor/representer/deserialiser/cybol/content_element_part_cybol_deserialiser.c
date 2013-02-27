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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_NODE_CYBOL_DESERIALISER_SOURCE
#define CONTENT_NODE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/accessor/name_getter/array_name_getter.c"
#include "../../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/encoding_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/format_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/language_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declaration.
//

void deserialise_cybol_part(void* p0, void* p1, void* p2, void* p3, void* p4);
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Deserialises the cybol part element content.
 *
 * The source properties handed over contain one node each for
 * name, channel, encoding, format, model.
 *
 * Example:
 *
 *  | compound [The root node has no name.]
 * +-node_$0 | compound
 * | +-node_$0 | compound
 * | | +-node_$0 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | left
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.count
 * | | +-node_$1 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | right
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.maximum
 * | | +-node_$2 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | result
 * | | | #-channel | wide_character | inline
 * | | | #-format | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.break
 * | | #- | wide_character | part [This is the xml tag name.]
 * | | #-name | wide_character | compare_count
 * | | #-channel | wide_character | inline
 * | | #-format | wide_character | operation/plain
 * | | #-model | wide_character | greater_or_equal
 * | +-node_$1 | compound
 * ...
 * | #- | wide_character | model [This is the xml tag name.]
 *
 * The temporary type and abstraction items got introduced
 * only to avoid repeated allocation of a corresponding variable
 * on the heap, in this function.
 * The parametre handed over lies on the stack and is just a pointer
 * to an item that was allocated JUST ONCE outside this function,
 * which is more efficient than allocating repeatedly within this function.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the temporary type item
 * @param p6 the temporary format item
 */
void deserialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol part element content.");

    //
    // Identify source node part properties parametres.
    //

    // The source name, channel, encoding, language, format, model part.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
*/
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, language, format, model part model item.
    void* snm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scm = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
    void* sem = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* slm = *NULL_POINTER_STATE_CYBOI_MODEL;
*/
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, language, format, model part model item data, count.
    void* snmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmc = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
    void* semd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* semc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* slmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* slmc = *NULL_POINTER_STATE_CYBOI_MODEL;
*/
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source name, channel, encoding, language, format, model part.
    get_name_array((void*) &sn, p3, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &sc, p3, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p4);
/*??
    get_name_array((void*) &se, p3, (void*) ENCODING_CYBOL_NAME, (void*) ENCODING_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &sl, p3, (void*) LANGUAGE_CYBOL_NAME, (void*) LANGUAGE_CYBOL_NAME_COUNT, p4);
*/
    get_name_array((void*) &sf, p3, (void*) FORMAT_CYBOL_NAME, (void*) FORMAT_CYBOL_NAME_COUNT, p4);
    get_name_array((void*) &sm, p3, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p4);

    //
    // Get source name, channel, encoding, language, format, model item.
    //
    // CAUTION! Do NOT use the following names here:
    // - NAME_PART_STATE_CYBOI_NAME
    // - CHANNEL_PART_STATE_CYBOI_NAME
    // - ENCODING_PART_STATE_CYBOI_NAME
    // - LANGUAGE_PART_STATE_CYBOI_NAME
    // - FORMAT_PART_STATE_CYBOI_NAME
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
/*??
    copy_array_forward((void*) &sem, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slm, sl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
*/
    copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source name, channel, encoding, language, format, model data, count.
    copy_array_forward((void*) &snmd, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snmc, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmd, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmc, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
/*??
    copy_array_forward((void*) &semd, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semc, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmd, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmc, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
*/
    copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfmc, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmd, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmc, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The root flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! This test is IMPORTANT!
    // If a source type attribute is NOT given, then this
    // is (hopefully) the cybol ROOT NODE and a part is allocated.
    //
    // CAUTION! It is true, a root flag was set initially when starting
    // to deserialise the cybol source, and forwarded as parametre.
    // However, that flag was only used to call the correct
    // function, but source data were just forwarded to it.
    // Another test (guess) for root node IS necessary here.
    // If not type is given, then this is a root node.
    //
    // CAUTION! If the cybol developer FORGOT to specify a format,
    // then the "part" type is used here by default, since it
    // does no real harm to create a node with (possibly) wrong type.
    // In the end, the CYBOL DEVELOPER has to care about that.
    if ((sn == *NULL_POINTER_STATE_CYBOI_MODEL) && (sc == *NULL_POINTER_STATE_CYBOI_MODEL)
//??        && (se == *NULL_POINTER_STATE_CYBOI_MODEL) && (sl == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (sf == *NULL_POINTER_STATE_CYBOI_MODEL) && (sm == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        copy_integer((void*) &r, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This is a standard node.

        // The temporary format, type item data.
        void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part name, channel, encoding, language, format, type, model, properties item.
        void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pe = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pl = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pf = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part channel, encoding, language data.
        void* pcd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* ped = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pld = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Reset temporary format item.
        // The count does NOT have to be set, since the p6 has a fixed size and count of one.
        overwrite_item_element(p6, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Reset temporary type item.
        overwrite_item_element(p5, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Decode cybol source format (mime type as string) into cyboi-internal format (an integer).
        deserialise_cybol_format(p6, sfmd, sfmc);
        // Get temporary format item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &fd, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Decode cyboi-internal type into cyboi runtime type.
        // CAUTION! Both are not always equal in their meaning.
        // For example, an "xdt" file is converted into a cyboi "part".
        // Therefore, a runtime type has to be figured out here.
        // It is needed for allocating the new part.
        deserialise_cybol_type(p5, fd);
        // Get temporary type item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &td, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

/*??
fwprintf(stdout, L"TEST content element part cybol deserialiser sfmd: %i\n", sfmd);
fwprintf(stdout, L"TEST content element part cybol deserialiser *sfmd: %ls\n", (wchar_t*) sfmd);
fwprintf(stdout, L"TEST content element part cybol deserialiser sfmc: %i\n", *((int*) sfmc));
fwprintf(stdout, L"TEST content element part cybol deserialiser fd: %i\n", *((int*) fd));
fwprintf(stdout, L"TEST content element part cybol deserialiser td: %i\n", *((int*) td));
*/

        // Allocate part.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        // CAUTION! Use the cyboi runtime type determined above
        // (NOT the mime type format)!
        allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

        // Get part name, channel, encoding, language, format, type, model, properties item.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pe, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENCODING_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pl, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pf, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

        // Fill part name item.
        overwrite_item_element(pn, snmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, snmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Fill part channel item.
        deserialise_cybol_channel(pc, scmd, scmc);
        // Fill part encoding item.
//??        deserialise_cybol_encoding(pe, semd, semc);
        overwrite_item_element(pe, (void*) UTF_8_CYBOI_ENCODING, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Fill part language item.
//??        deserialise_cybol_language(pl, slmd, slmc);
        overwrite_item_element(pl, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Fill part format item.
        overwrite_item_element(pf, fd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Fill part type item.
        overwrite_item_element(pt, td, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Get part channel item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &pcd, pc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Get part encoding item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &ped, pe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Get part language item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &pld, pl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Fill part model item taken from cybol source part properties.
        // CAUTION! What is the properties in a parsed xml/cybol file,
        // becomes the model in the cyboi-internal knowledge tree.
        // CAUTION! Use the CYBOL cyboi destination type determined above
        // (and NOT the CYBOI destination type)!
        // CAUTION! A null pointer is handed over as second-last parametre here.
        // When reading cybol, the only possible two channels are "inline" and "file",
        // but the internal memory (second-last parametre) is only necessary for
        // "terminal", "x_window_system" and similar channels.
        receive_data(pm, *NULL_POINTER_STATE_CYBOI_MODEL, smmd, smmc, fd, pld, ped, *NULL_POINTER_STATE_CYBOI_MODEL, pcd);
        // Fill part properties item taken from cybol source part model.
        // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
        // becomes the properties (meta data) in the cyboi-internal knowledge tree.
        deserialise_cybol_part(pp, p1, p2, p5, p6);

        // Add part to destination.
        // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
        // This is necessary in order to activate rubbish (garbage) collection.
        append_item_element(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        // This is a root node.

        // Fill part properties taken from cybol source part model.
        // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
        // becomes the properties (meta data) in the cyboi-internal knowledge tree.
        deserialise_cybol_part(p0, p1, p2, p5, p6);
    }
}

/* CONTENT_NODE_CYBOL_DESERIALISER_SOURCE */
#endif
