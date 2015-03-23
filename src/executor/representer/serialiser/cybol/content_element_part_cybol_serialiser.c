/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../../executor/representer/serialiser/cybol/channel_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/encoding_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/language_cybol_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_cybol_part(void* p0, void* p1, void* p2);

/**
 * Serialises the part element content into cybol.
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
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source channel data
 * @param p4 the source encoding data
 * @param p5 the source language data
 * @param p6 the source format data
 * @param p7 the source type data
 * @param p8 the source model data
 * @param p9 the source model count
 * @param p10 the source properties data
 * @param p11 the source properties count
 */
void serialise_cybol_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol part element content.");

    //?? TEST for root node ??

    // The destination part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part name, channel, encoding, language, format, model, properties item.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pe = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pl = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination name, channel, encoding, language, format, model part.
    void* dn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dl = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* df = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination name, channel, encoding, language, format, model part model item.
    void* dnm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dcm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dem = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dlm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmm = *NULL_POINTER_STATE_CYBOI_MODEL;

fwprintf(stdout, L"TEST serialise cybol part element content p7: %i\n", p7);
fwprintf(stdout, L"TEST serialise cybol part element content *p7: %i\n", *((int*) p7));

    // Allocate destination part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the cyboi runtime type (NOT the mime type format)!
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    // Allocate destination name, channel, encoding, language, format, model part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the cyboi runtime type (NOT the mime type format)!
    allocate_part((void*) &dn, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &dc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &de, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &dl, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &df, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_part((void*) &dm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Overwrite name of destination name, channel, encoding, language, format, model part.
    overwrite_part_element(dn, (void*) NAME_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NAME_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dc, (void*) CHANNEL_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHANNEL_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(de, (void*) ENCODING_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ENCODING_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dl, (void*) LANGUAGE_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LANGUAGE_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(df, (void*) FORMAT_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORMAT_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dm, (void*) MODEL_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);

    // Overwrite format of destination name, channel, encoding, language, format, model part.
    overwrite_part_element(dn, (void*) NAME_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dc, (void*) CHANNEL_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(de, (void*) ENCODING_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dl, (void*) LANGUAGE_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(df, (void*) FORMAT_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dm, (void*) MODEL_META_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);

    // Overwrite type of destination name, channel, encoding, language, format, model part.
    // CAUTION! Assigning the type IS ESSENTIAL for properly
    // deallocating the part and its child parts at shutdown.
    overwrite_part_element(dn, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dc, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(de, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(df, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(dm, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Get destination name, channel, encoding, language, format, model part model item.
    copy_array_forward((void*) &dnm, dn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dcm, dc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dem, de, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dlm, dl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dfm, df, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmm, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST serialise cybol part element content copy dnm: %i\n", dnm);

    // Overwrite model of destination name, channel, encoding, language, format, model part.
    overwrite_item_element(dnm, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST serialise cybol part element content dnm: %ls\n", (wchar_t*) dnm);
    serialise_cybol_channel(dcm, p3);
fwprintf(stdout, L"TEST serialise cybol part element content dcm: %i\n", *((int*) p3));
fwprintf(stdout, L"TEST serialise cybol part element content dcm: %i\n", *((int*) dcm));
    serialise_cybol_encoding(dem, p4);
fwprintf(stdout, L"TEST serialise cybol part element content dem: %i\n", *((int*) dem));
    serialise_cybol_language(dlm, p5);
fwprintf(stdout, L"TEST serialise cybol part element content dlm: %i\n", *((int*) dlm));
    serialise_cybol_format(dfm, p6);
fwprintf(stdout, L"TEST serialise cybol part element content dfm: %i\n", *((int*) dfm));
//??    serialise_cybol(dmm, p1, p2, p3, p4, p5, p6, p7, p8, p9, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
//?? fwprintf(stdout, L"TEST serialise cybol part element content dmm: %i\n", dmm);

fwprintf(stdout, L"TEST serialise cybol part element content p: %i\n", p);

    // Overwrite destination part.
    // CAUTION! Assigning the type IS ESSENTIAL for properly
    // deallocating the part and its child parts at shutdown.
    overwrite_part_element(p, (void*) NODE_XML_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NODE_XML_CYBOL_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) INLINE_CYBOI_CHANNEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) UTF_8_CYBOI_ENCODING, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ENCODING_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Get destination part model, properties item.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST serialise cybol part element content copy pn: %i\n", pn);

    // Append source properties to destination part's model.
    serialise_cybol_part(pm, p10, p11);

fwprintf(stdout, L"TEST serialise cybol part element content pm: %i\n", pm);

    // Append destination name, channel, encoding, language, format, model part to destination part's properties.
    append_item_element(pp, (void*) &dn, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(pp, (void*) &dc, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(pp, (void*) &de, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(pp, (void*) &dl, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(pp, (void*) &df, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(pp, (void*) &dm, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST serialise cybol part element content pp: %i\n", pp);

    // Add destination part to destination.
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    append_item_element(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* CONTENT_ELEMENT_PART_CYBOL_SERIALISER_SOURCE */
#endif
