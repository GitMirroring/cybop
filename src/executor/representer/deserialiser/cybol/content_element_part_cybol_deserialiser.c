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

#ifndef CONTENT_ELEMENT_PART_CYBOL_DESERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/channel/cybol/cybol_channel.c"
#include "../../../../constant/encoding/cybol/unicode_cybol_encoding.c"
#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/format/cybol/state/text_state_cybol_format.c"
#include "../../../../constant/language/cybol/state/text_state_cybol_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/name_getter/array_name_getter.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/encoding_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/format_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/language_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

#ifdef WIN32 // compiler error without this line (but actually forward declaration of "receive_data" below should suffice):
    #include "../../../../executor/communicator/receiver.c"
#endif

//
// Forward declaration.
//

void deserialise_cybol_part(void* p0, void* p1, void* p2);
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);

/**
 * Deserialises the cybol part element content.
 *
 * The source properties handed over contain one node each for
 * name, channel, encoding, language, format, model.
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
 * The temporary type and format items got introduced
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
 */
void deserialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol part element content.");

    //
    // Identify source node part properties parametres.
    //

    // The source name, channel, encoding, language, format, model part.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, language, format, model part model item.
    void* snm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sem = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* slm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source name, channel, encoding, language, format, model part model item data, count.
    //?? TODO: Assign default values? Better NOT. This can be done in a cybol editor tool.
    void* snmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* scmd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) INLINE_CYBOL_CHANNEL;
    void* scmc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) INLINE_CYBOL_CHANNEL_COUNT;
    void* semd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) UTF_8_UNICODE_CYBOL_ENCODING;
    void* semc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) UTF_8_UNICODE_CYBOL_ENCODING_COUNT;
    // As an exception, a default value is assigned for language,
    // so that cybol code may be slim and without xml "language" attribute.
    void* slmd = (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE;
    void* slmc = (void*) CYBOL_TEXT_STATE_CYBOL_LANGUAGE_COUNT;
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT;
    void* sfmc = *NULL_POINTER_STATE_CYBOI_MODEL; //?? (void*) PLAIN_TEXT_STATE_CYBOL_FORMAT_COUNT;
    void* smmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source name, channel, encoding, language, format, model part.
    get_name_array((void*) &sn, p3, (void*) NAME_CYBOL_NAME, (void*) NAME_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sc, p3, (void*) CHANNEL_CYBOL_NAME, (void*) CHANNEL_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &se, p3, (void*) ENCODING_CYBOL_NAME, (void*) ENCODING_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sl, p3, (void*) LANGUAGE_CYBOL_NAME, (void*) LANGUAGE_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sf, p3, (void*) FORMAT_CYBOL_NAME, (void*) FORMAT_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    get_name_array((void*) &sm, p3, (void*) MODEL_CYBOL_NAME, (void*) MODEL_CYBOL_NAME_COUNT, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

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
    copy_array_forward((void*) &snm, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scm, sc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sem, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slm, sl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source name, channel, encoding, language, format, model data, count.
    copy_array_forward((void*) &snmd, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snmc, snm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmd, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &scmc, scm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semd, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &semc, sem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmd, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &slmc, slm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sfmc, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmd, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smmc, smm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The root flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! This test is IMPORTANT!
    // If a source type attribute is NOT given, then this
    // is (hopefully) the cybol ROOT NODE and a part is allocated.
    //
    // CAUTION! It is true, a root flag was set initially when starting
    // to deserialise the cybol source, and forwarded as parametre.
    // However, that flag was only used to call the correct
    // function, but source data were just forwarded to it.
    // Another test (guess) for root node IS necessary here.
    // If no type is given, then this is a root node.
    //
    // CAUTION! Do ONLY compare those variables,
    // for which NO DEFAULT VALUE has been set above.
    //
    // CAUTION! If the cybol developer FORGOT to specify a format,
    // then the "part" type is used here by default, since it
    // does no real harm to create a node with (possibly) wrong type.
    // In the end, the CYBOL DEVELOPER has to care about that.
    //
    if ((sn == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (sc == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (se == *NULL_POINTER_STATE_CYBOI_MODEL)
//??        && (sl == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (sf == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (sm == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        copy_integer((void*) &r, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a standard node.
        //

        // The temporary format, type item.
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
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

        // Allocate temporary format, type item.
        allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

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
        modify_item(f, (void*) ASCII_TEXT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        modify_item(t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        // Decode cybol source format (mime type as string) into cyboi-internal format (an integer).
        deserialise_cybol_format(f, sfmd, sfmc);
        //
        // Get temporary format item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
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

/*??
        fwprintf(stdout, L"Debug: content element part cybol deserialiser *slmc: %i\n", *((int*) slmc));
        fwprintf(stdout, L"Debug: content element part cybol deserialiser slmd: %i\n", slmd);
        fwprintf(stdout, L"Debug: content element part cybol deserialiser *slmd: %ls\n", (wchar_t*) slmd);
        fwprintf(stdout, L"Debug: content element part cybol deserialiser sfmc: %i\n", *((int*) sfmc));
        fwprintf(stdout, L"Debug: content element part cybol deserialiser sfmd: %i\n", sfmd);
        fwprintf(stdout, L"Debug: content element part cybol deserialiser *sfmd: %ls\n", (wchar_t*) sfmd);
        fwprintf(stdout, L"Debug: content element part cybol deserialiser fd: %i\n", *((int*) fd));
        fwprintf(stdout, L"Debug: content element part cybol deserialiser td: %i\n", *((int*) td));
*/

        //
        // Allocate part.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        // CAUTION! Use the cyboi runtime type determined above
        // (NOT the mime type format)!
        //
        allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

        //
        // Get part name, channel, encoding, language, format, type, model, properties item.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pe, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENCODING_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pl, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pf, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

        // Fill part name item.
        modify_item(pn, snmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, snmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        // Fill part channel item.
        deserialise_cybol_channel(pc, scmd, scmc);
        // Fill part encoding item.
        deserialise_cybol_encoding(pe, semd, semc);
        // Fill part language item.
        deserialise_cybol_language(pl, slmd, slmc);
//??        modify_item(pl, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        // Fill part format item.
        modify_item(pf, fd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        // Fill part type item.
        modify_item(pt, td, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Get part channel item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &pcd, pc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        //
        // Get part encoding item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &ped, pe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        //
        // Get part language item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &pld, pl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser 1 ped: %i\n", ped);
        //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser 1 *ped: %i\n", *((int*) ped));

        //?? TODO: Delete this block below in the future.
        //?? ALL xml attributes should be specified in cybol,
        //?? also the "encoding". This default here is temporary
        //?? in order to not to have to specify it in each cybol file.
        //
        // CAUTION! The default encoding value MUST NOT be assigned
        // in general and for all parts above, since the function
        // "receive_data" below tests the encoding for null.
        // If the language is e.g. "message/binary", then NO encoding
        // is given, since it does not make sense for images etc.
        // Therefore, assign standard encoding ONLY for
        // channel "file" and language "text/cybol".
        //
        if (ped != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* pedi = (int*) ped;

            // The default value assigned to an item's "data" element is zero.
            if (*pedi == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // An encoding was NOT specified.

                if (pcd != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* pcdi = (int*) pcd;

                    if (*pcdi == *FILE_CYBOI_CHANNEL) {

                        //
                        // The channel is "file".
                        //
                        // CAUTION! There are currently just TWO channel options
                        // for parts defined in a cybol file:
                        // - inline: leave encoding undefined at value "null";
                        // - file: set encoding to "utf-8".
                        //
                        // Since inline models are available as wchar_t, decoding them is NOT necessary.
                        // Data read from a utf-8-encoded cybol file, on the other hand, NEED to be converted.
                        // Set default encoding ONLY if channel is "file"!
                        // Otherwise, wrong conversions will occur in "communicator/receiver/"
                        // and cybol applications not run.
                        //

                        if (pld != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* pldi = (int*) pld;

                            if (*pldi == *CYBOL_TEXT_STATE_CYBOI_LANGUAGE) {

                                //
                                // This is the standard language "text/cybol".
                                //

                                // Assign "utf-8" as default encoding.
                                modify_item(pe, (void*) UTF_8_CYBOI_ENCODING, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

                                //
                                // Get part encoding item data.
                                //
                                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                                // Inside the structure, arrays may have been reallocated,
                                // with elements pointing to different memory areas now.
                                //
                                copy_array_forward((void*) &ped, pe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                            }
                        }
                    }
                }
            }
        }

        //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser 2 ped: %i\n", ped);
        //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser 2 *ped: %i\n", *((int*) ped));

        //
        // Fill part model item taken from cybol source part properties.
        //
        // CAUTION! What is the properties in a parsed xml/cybol file,
        // becomes the model in the cyboi-internal knowledge tree.
        //
        // CAUTION! Use the CYBOL cyboi destination type determined above
        // (and NOT the CYBOI destination type)!
        //
        // CAUTION! A null pointer is handed over as second-last parametre here.
        // When reading cybol, the only possible two channels are "inline" and "file",
        // but the internal memory (second-last parametre) is only necessary for
        // "terminal", "display" and similar channels.
        //
        receive_data(pm, *NULL_POINTER_STATE_CYBOI_MODEL, smmd, smmc, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, fd, pld, ped, pcd);
        //
        // Fill part properties item taken from cybol source part model.
        //
        // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
        // becomes the properties (meta data) in the cyboi-internal knowledge tree.
        //
        deserialise_cybol_part(pp, p1, p2);

/*??
        //?? TEST ONLY:
        if (pld != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* pldi = (int*) pld;

            if (*pldi == *BINARY_MESSAGE_STATE_CYBOI_LANGUAGE) {

                //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser *smmc: %i\n", *((int*) smmc));
                //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser smmd: %s\n", (char*) smmd);
                void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* testc = *NULL_POINTER_STATE_CYBOI_MODEL;
                copy_array_forward((void*) &testc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &testd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser *testc: %i\n", *((int*) testc));
                //?? fwprintf(stdout, L"Debug: content element part cybol deserialiser testd: %s\n", (char*) testd);
            }
        }
*/

        //
        // Add part to destination.
        //
        // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
        // This is necessary in order to activate rubbish (garbage) collection.
        //
        modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Deallocate temporary format, type item.
        //
        // CAUTION! Deallocate these ONLY HERE, since they are used
        // as arguments to the function call "receive_data" above.
        //
        deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    } else {

        //
        // This is a root node.
        //

        //
        // Fill part properties taken from cybol source part model.
        //
        // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
        // becomes the properties (meta data) in the cyboi-internal knowledge tree.
        //
        deserialise_cybol_part(p0, p1, p2);
    }
}

/* CONTENT_ELEMENT_PART_CYBOL_DESERIALISER_SOURCE */
#endif
