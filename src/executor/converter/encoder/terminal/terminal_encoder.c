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

#ifndef TERMINAL_ENCODER_SOURCE
#define TERMINAL_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/terminal/escape_control_sequence_terminal_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes a compound model into terminal control sequences.
 *
 * @param p0 the destination escape control sequence item
 * @param p3 the source part type
 * @param p4 the source part type count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part properties
 * @param p8 the source part properties count
 * @param p9 the source whole properties (the compound containing the source part)
 * @param p10 the source whole properties count
 * @param p11 the source part name (area to be repainted)
 * @param p12 the source part name count
 */
void encode_terminal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode gnu/linux console.");

    // The source part name, type, model, properties.
    void** n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part super properties name, type, model, properties.
    void** supern = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part shape name, type, model, properties.
    void** shn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part layout name, type, model, properties.
    void** ln = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part cell name, type, model, properties.
    void** cn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part position name, type, model, properties.
    void** pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part size name, type, model, properties.
    void** sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part background colour name, type, model, properties.
    void** bgn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part foreground colour name, type, model, properties.
    void** fgn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part border name, type, model, properties.
    void** bon = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part hidden property name, type, model, properties.
    void** hn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part inverse property name, type, model, properties.
    void** in = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part blink property name, type, model, properties.
    void** bln = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part underline property name, type, model, properties.
    void** un = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part bold property name, type, model, properties.
    void** bn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source whole position name, type, model, properties.
    void** wpn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source whole size name, type, model, properties.
    void** wsn = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The element name.
    void* en = *NULL_POINTER_STATE_CYBOI_MODEL;
    int enc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The remaining name.
    void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The loop count.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The name comparison result.
    int nr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The type comparison result.
    int ar = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get compound element (area to be repainted) name and remaining name,
    // as well as the flag indicating a part- or meta element.
    get_compound_element_name_and_remaining_name(p11, p12, (void*) &en, (void*) &enc, (void*) &rn, (void*) &rnc, (void*) &f);

    if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (f == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

        // Either, no hierarchical element name (repaint area) was given
        // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
        // but the whole textual user interface (tui) window is repainted,
        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
        // OR:
        // the expected compound element (area to be repainted) pointed to
        // by the hierarchical name is a "part" element (f == 0), not a "meta" element,
        // which is correct, so that the element can be processed/ repainted.

        // Get part super properties from properties.
        get_universal_compound_element_by_name(
            (void*) &supern, (void*) &supernc, (void*) &superns,
            (void*) &supera, (void*) &superac, (void*) &superas,
            (void*) &superm, (void*) &supermc, (void*) &superms,
            (void*) &superd, (void*) &superdc, (void*) &superds,
            p7, p8,
            (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part shape from properties.
        get_universal_compound_element_by_name(
            (void*) &shn, (void*) &shnc, (void*) &shns,
            (void*) &sha, (void*) &shac, (void*) &shas,
            (void*) &shm, (void*) &shmc, (void*) &shms,
            (void*) &shd, (void*) &shdc, (void*) &shds,
            p7, p8,
            (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part layout from properties.
        get_universal_compound_element_by_name(
            (void*) &ln, (void*) &lnc, (void*) &lns,
            (void*) &la, (void*) &lac, (void*) &las,
            (void*) &lm, (void*) &lmc, (void*) &lms,
            (void*) &ld, (void*) &ldc, (void*) &lds,
            p7, p8,
            (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part cell from properties.
        get_universal_compound_element_by_name(
            (void*) &cn, (void*) &cnc, (void*) &cns,
            (void*) &ca, (void*) &cac, (void*) &cas,
            (void*) &cm, (void*) &cmc, (void*) &cms,
            (void*) &cd, (void*) &cdc, (void*) &cds,
            p7, p8,
            (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part position from properties.
        get_universal_compound_element_by_name(
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds,
            p7, p8,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part size from properties.
        get_universal_compound_element_by_name(
            (void*) &sn, (void*) &snc, (void*) &sns,
            (void*) &sa, (void*) &sac, (void*) &sas,
            (void*) &sm, (void*) &smc, (void*) &sms,
            (void*) &sd, (void*) &sdc, (void*) &sds,
            p7, p8,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part background colour from properties.
        get_universal_compound_element_by_name(
            (void*) &bgn, (void*) &bgnc, (void*) &bgns,
            (void*) &bga, (void*) &bgac, (void*) &bgas,
            (void*) &bgm, (void*) &bgmc, (void*) &bgms,
            (void*) &bgd, (void*) &bgdc, (void*) &bgds,
            p7, p8,
            (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part foreground colour from properties.
        get_universal_compound_element_by_name(
            (void*) &fgn, (void*) &fgnc, (void*) &fgns,
            (void*) &fga, (void*) &fgac, (void*) &fgas,
            (void*) &fgm, (void*) &fgmc, (void*) &fgms,
            (void*) &fgd, (void*) &fgdc, (void*) &fgds,
            p7, p8,
            (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part border from properties.
        get_universal_compound_element_by_name(
            (void*) &bon, (void*) &bonc, (void*) &bons,
            (void*) &boa, (void*) &boac, (void*) &boas,
            (void*) &bom, (void*) &bomc, (void*) &boms,
            (void*) &bod, (void*) &bodc, (void*) &bods,
            p7, p8,
            (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part hidden property from properties.
        get_universal_compound_element_by_name(
            (void*) &hn, (void*) &hnc, (void*) &hns,
            (void*) &ha, (void*) &hac, (void*) &has,
            (void*) &hm, (void*) &hmc, (void*) &hms,
            (void*) &hd, (void*) &hdc, (void*) &hds,
            p7, p8,
            (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part inverse property from properties.
        get_universal_compound_element_by_name(
            (void*) &in, (void*) &inc, (void*) &ins,
            (void*) &ia, (void*) &iac, (void*) &ias,
            (void*) &im, (void*) &imc, (void*) &ims,
            (void*) &id, (void*) &idc, (void*) &ids,
            p7, p8,
            (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part blink property from properties.
        get_universal_compound_element_by_name(
            (void*) &bln, (void*) &blnc, (void*) &blns,
            (void*) &bla, (void*) &blac, (void*) &blas,
            (void*) &blm, (void*) &blmc, (void*) &blms,
            (void*) &bld, (void*) &bldc, (void*) &blds,
            p7, p8,
            (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part underline property from properties.
        get_universal_compound_element_by_name(
            (void*) &un, (void*) &unc, (void*) &uns,
            (void*) &ua, (void*) &uac, (void*) &uas,
            (void*) &um, (void*) &umc, (void*) &ums,
            (void*) &ud, (void*) &udc, (void*) &uds,
            p7, p8,
            (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part bold property from properties.
        get_universal_compound_element_by_name(
            (void*) &bn, (void*) &bnc, (void*) &bns,
            (void*) &ba, (void*) &bac, (void*) &bas,
            (void*) &bm, (void*) &bmc, (void*) &bms,
            (void*) &bd, (void*) &bdc, (void*) &bds,
            p7, p8,
            (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        //
        // Get default property values from super part.
        //
        // If a standard property value DOES exist, it is NOT
        // overwritten with the default property value of the super part.
        // If a standard property value does NOT exist, the default
        // property value of the super part is used.
        //

        if (*shm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part shape from super part.
            get_universal_compound_element_by_name(
                (void*) &shn, (void*) &shnc, (void*) &shns,
                (void*) &sha, (void*) &shac, (void*) &shas,
                (void*) &shm, (void*) &shmc, (void*) &shms,
                (void*) &shd, (void*) &shdc, (void*) &shds,
                *superm, *supermc,
                (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*lm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get source part layout from properties.
            get_universal_compound_element_by_name(
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                *superm, *supermc,
                (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*cm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get source part cell from properties.
            get_universal_compound_element_by_name(
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *superm, *supermc,
                (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*pm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part position from super part.
            get_universal_compound_element_by_name(
                (void*) &pn, (void*) &pnc, (void*) &pns,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds,
                *superm, *supermc,
                (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*sm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part size from super part.
            get_universal_compound_element_by_name(
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                *superm, *supermc,
                (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bgm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part background colour from super part.
            get_universal_compound_element_by_name(
                (void*) &bgn, (void*) &bgnc, (void*) &bgns,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds,
                *superm, *supermc,
                (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*fgm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part foreground colour from super part.
            get_universal_compound_element_by_name(
                (void*) &fgn, (void*) &fgnc, (void*) &fgns,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds,
                *superm, *supermc,
                (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bom == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part border from super part.
            get_universal_compound_element_by_name(
                (void*) &bon, (void*) &bonc, (void*) &bons,
                (void*) &boa, (void*) &boac, (void*) &boas,
                (void*) &bom, (void*) &bomc, (void*) &boms,
                (void*) &bod, (void*) &bodc, (void*) &bods,
                *superm, *supermc,
                (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*hm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part hidden property from super part.
            get_universal_compound_element_by_name(
                (void*) &hn, (void*) &hnc, (void*) &hns,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds,
                *superm, *supermc,
                (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*im == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part inverse property from super part.
            get_universal_compound_element_by_name(
                (void*) &in, (void*) &inc, (void*) &ins,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids,
                *superm, *supermc,
                (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*blm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part blink property from super part.
            get_universal_compound_element_by_name(
                (void*) &bln, (void*) &blnc, (void*) &blns,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds,
                *superm, *supermc,
                (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*um == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part underline property from super part.
            get_universal_compound_element_by_name(
                (void*) &un, (void*) &unc, (void*) &uns,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds,
                *superm, *supermc,
                (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bm == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get part bold property from super part.
            get_universal_compound_element_by_name(
                (void*) &bn, (void*) &bnc, (void*) &bns,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds,
                *superm, *supermc,
                (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        // Get source whole position from properties.
        get_universal_compound_element_by_name(
            (void*) &wpn, (void*) &wpnc, (void*) &wpns,
            (void*) &wpa, (void*) &wpac, (void*) &wpas,
            (void*) &wpm, (void*) &wpmc, (void*) &wpms,
            (void*) &wpd, (void*) &wpdc, (void*) &wpds,
            p9, p10,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        // Get source whole size from properties.
        get_universal_compound_element_by_name(
            (void*) &wsn, (void*) &wsnc, (void*) &wsns,
            (void*) &wsa, (void*) &wsac, (void*) &wsas,
            (void*) &wsm, (void*) &wsmc, (void*) &wsms,
            (void*) &wsd, (void*) &wsdc, (void*) &wsds,
            p9, p10,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        compare_all_array((void*) &ar, p3, (void*) PART_MEMORY_TYPE, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p4, (void*) PART_MEMORY_TYPE_COUNT);

        if (ar != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The part model IS a compound.

            // CAUTION! Paint the compound's background etc.,
            // but do NOT hand over the model!
            // Since the model is a compound and not a valid character,
            // it will cause wrong characters or question marks to be printed on screen!
            // Therefore, do hand over a null pointer instead of the model!
            if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (rn == *NULL_POINTER_STATE_CYBOI_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_terminal_shape(p0, p1, p2,
                    *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* sc = (int*) p6;

                // Iterate through compound parts.
                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (j >= *sc) {

                        break;
                    }

                    // Get part at index j.
                    get_compound_element_by_index(p5, p6, (void*) &j,
                        (void*) &n, (void*) &nc, (void*) &ns,
                        (void*) &a, (void*) &ac, (void*) &as,
                        (void*) &m, (void*) &mc, (void*) &ms,
                        (void*) &d, (void*) &dc, (void*) &ds);

                    // Compare expected name with that of the current compound part element.
                    compare_all_array((void*) &nr, *n, en, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, *nc, (void*) &enc);

                    if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (nr != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

                        // Either, no hierarchical element name (repaint area) was given
                        // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                        // but the whole textual user interface (tui) window is repainted,
                        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                        // OR:
                        // the compound part name matches the next name in the
                        // given cascade of separated names, pointing to a knowledge model.

                        // Recursively call this procedure for compound part model.
                        encode_terminal(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p7, p8, rn, (void*) &rnc, p13, p14);
                    }

                    // Reset source part name, type, model, properties
                    // (parameters of the current compound part element).
                    n = NULL_POINTER_STATE_CYBOI_MODEL;
                    nc = NULL_POINTER_STATE_CYBOI_MODEL;
                    ns = NULL_POINTER_STATE_CYBOI_MODEL;
                    a = NULL_POINTER_STATE_CYBOI_MODEL;
                    ac = NULL_POINTER_STATE_CYBOI_MODEL;
                    as = NULL_POINTER_STATE_CYBOI_MODEL;
                    m = NULL_POINTER_STATE_CYBOI_MODEL;
                    mc = NULL_POINTER_STATE_CYBOI_MODEL;
                    ms = NULL_POINTER_STATE_CYBOI_MODEL;
                    d = NULL_POINTER_STATE_CYBOI_MODEL;
                    dc = NULL_POINTER_STATE_CYBOI_MODEL;
                    ds = NULL_POINTER_STATE_CYBOI_MODEL;

                    // Reset name comparison result.
                    nr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Increment loop count.
                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode compound model into terminal control sequences. The source count parameter is null.");
            }

        } else {

            // The part model is NOT a compound.

            if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (rn == *NULL_POINTER_STATE_CYBOI_MODEL)) {
    //??        if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_terminal_shape(p0, p1, p2, p5, p6, p3, p4,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode compound model into terminal control sequences. The hierarchical compound element name contains a meta element, while only part elements are permitted.");
    }
}

/* TERMINAL_ENCODER_SOURCE */
#endif
