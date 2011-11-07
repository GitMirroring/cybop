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
 * @version $RCSfile: gnu_linux_console_converter.c,v $ $Revision: 1.38 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
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

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
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
 * Encodes a compound model into gnu/linux console control sequences.
 *
 * @param p0 the destination control sequence code item
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the source whole details (the compound containing the source part)
 * @param p10 the source whole details count
 * @param p11 the source part name (area to be repainted)
 * @param p12 the source part name count
 * @param p13 the knowledge memory
 * @param p14 the knowledge memory count
 */
void encode_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console.");

    // The source part name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;
    // The source part super properties name, abstraction, model, details.
    void** supern = NULL_POINTER_MEMORY_MODEL;
    void** supernc = NULL_POINTER_MEMORY_MODEL;
    void** superns = NULL_POINTER_MEMORY_MODEL;
    void** supera = NULL_POINTER_MEMORY_MODEL;
    void** superac = NULL_POINTER_MEMORY_MODEL;
    void** superas = NULL_POINTER_MEMORY_MODEL;
    void** superm = NULL_POINTER_MEMORY_MODEL;
    void** supermc = NULL_POINTER_MEMORY_MODEL;
    void** superms = NULL_POINTER_MEMORY_MODEL;
    void** superd = NULL_POINTER_MEMORY_MODEL;
    void** superdc = NULL_POINTER_MEMORY_MODEL;
    void** superds = NULL_POINTER_MEMORY_MODEL;
    // The source part shape name, abstraction, model, details.
    void** shn = NULL_POINTER_MEMORY_MODEL;
    void** shnc = NULL_POINTER_MEMORY_MODEL;
    void** shns = NULL_POINTER_MEMORY_MODEL;
    void** sha = NULL_POINTER_MEMORY_MODEL;
    void** shac = NULL_POINTER_MEMORY_MODEL;
    void** shas = NULL_POINTER_MEMORY_MODEL;
    void** shm = NULL_POINTER_MEMORY_MODEL;
    void** shmc = NULL_POINTER_MEMORY_MODEL;
    void** shms = NULL_POINTER_MEMORY_MODEL;
    void** shd = NULL_POINTER_MEMORY_MODEL;
    void** shdc = NULL_POINTER_MEMORY_MODEL;
    void** shds = NULL_POINTER_MEMORY_MODEL;
    // The source part layout name, abstraction, model, details.
    void** ln = NULL_POINTER_MEMORY_MODEL;
    void** lnc = NULL_POINTER_MEMORY_MODEL;
    void** lns = NULL_POINTER_MEMORY_MODEL;
    void** la = NULL_POINTER_MEMORY_MODEL;
    void** lac = NULL_POINTER_MEMORY_MODEL;
    void** las = NULL_POINTER_MEMORY_MODEL;
    void** lm = NULL_POINTER_MEMORY_MODEL;
    void** lmc = NULL_POINTER_MEMORY_MODEL;
    void** lms = NULL_POINTER_MEMORY_MODEL;
    void** ld = NULL_POINTER_MEMORY_MODEL;
    void** ldc = NULL_POINTER_MEMORY_MODEL;
    void** lds = NULL_POINTER_MEMORY_MODEL;
    // The source part cell name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The source part position name, abstraction, model, details.
    void** pn = NULL_POINTER_MEMORY_MODEL;
    void** pnc = NULL_POINTER_MEMORY_MODEL;
    void** pns = NULL_POINTER_MEMORY_MODEL;
    void** pa = NULL_POINTER_MEMORY_MODEL;
    void** pac = NULL_POINTER_MEMORY_MODEL;
    void** pas = NULL_POINTER_MEMORY_MODEL;
    void** pm = NULL_POINTER_MEMORY_MODEL;
    void** pmc = NULL_POINTER_MEMORY_MODEL;
    void** pms = NULL_POINTER_MEMORY_MODEL;
    void** pd = NULL_POINTER_MEMORY_MODEL;
    void** pdc = NULL_POINTER_MEMORY_MODEL;
    void** pds = NULL_POINTER_MEMORY_MODEL;
    // The source part size name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;
    // The source part background colour name, abstraction, model, details.
    void** bgn = NULL_POINTER_MEMORY_MODEL;
    void** bgnc = NULL_POINTER_MEMORY_MODEL;
    void** bgns = NULL_POINTER_MEMORY_MODEL;
    void** bga = NULL_POINTER_MEMORY_MODEL;
    void** bgac = NULL_POINTER_MEMORY_MODEL;
    void** bgas = NULL_POINTER_MEMORY_MODEL;
    void** bgm = NULL_POINTER_MEMORY_MODEL;
    void** bgmc = NULL_POINTER_MEMORY_MODEL;
    void** bgms = NULL_POINTER_MEMORY_MODEL;
    void** bgd = NULL_POINTER_MEMORY_MODEL;
    void** bgdc = NULL_POINTER_MEMORY_MODEL;
    void** bgds = NULL_POINTER_MEMORY_MODEL;
    // The source part foreground colour name, abstraction, model, details.
    void** fgn = NULL_POINTER_MEMORY_MODEL;
    void** fgnc = NULL_POINTER_MEMORY_MODEL;
    void** fgns = NULL_POINTER_MEMORY_MODEL;
    void** fga = NULL_POINTER_MEMORY_MODEL;
    void** fgac = NULL_POINTER_MEMORY_MODEL;
    void** fgas = NULL_POINTER_MEMORY_MODEL;
    void** fgm = NULL_POINTER_MEMORY_MODEL;
    void** fgmc = NULL_POINTER_MEMORY_MODEL;
    void** fgms = NULL_POINTER_MEMORY_MODEL;
    void** fgd = NULL_POINTER_MEMORY_MODEL;
    void** fgdc = NULL_POINTER_MEMORY_MODEL;
    void** fgds = NULL_POINTER_MEMORY_MODEL;
    // The source part border name, abstraction, model, details.
    void** bon = NULL_POINTER_MEMORY_MODEL;
    void** bonc = NULL_POINTER_MEMORY_MODEL;
    void** bons = NULL_POINTER_MEMORY_MODEL;
    void** boa = NULL_POINTER_MEMORY_MODEL;
    void** boac = NULL_POINTER_MEMORY_MODEL;
    void** boas = NULL_POINTER_MEMORY_MODEL;
    void** bom = NULL_POINTER_MEMORY_MODEL;
    void** bomc = NULL_POINTER_MEMORY_MODEL;
    void** boms = NULL_POINTER_MEMORY_MODEL;
    void** bod = NULL_POINTER_MEMORY_MODEL;
    void** bodc = NULL_POINTER_MEMORY_MODEL;
    void** bods = NULL_POINTER_MEMORY_MODEL;
    // The source part hidden property name, abstraction, model, details.
    void** hn = NULL_POINTER_MEMORY_MODEL;
    void** hnc = NULL_POINTER_MEMORY_MODEL;
    void** hns = NULL_POINTER_MEMORY_MODEL;
    void** ha = NULL_POINTER_MEMORY_MODEL;
    void** hac = NULL_POINTER_MEMORY_MODEL;
    void** has = NULL_POINTER_MEMORY_MODEL;
    void** hm = NULL_POINTER_MEMORY_MODEL;
    void** hmc = NULL_POINTER_MEMORY_MODEL;
    void** hms = NULL_POINTER_MEMORY_MODEL;
    void** hd = NULL_POINTER_MEMORY_MODEL;
    void** hdc = NULL_POINTER_MEMORY_MODEL;
    void** hds = NULL_POINTER_MEMORY_MODEL;
    // The source part inverse property name, abstraction, model, details.
    void** in = NULL_POINTER_MEMORY_MODEL;
    void** inc = NULL_POINTER_MEMORY_MODEL;
    void** ins = NULL_POINTER_MEMORY_MODEL;
    void** ia = NULL_POINTER_MEMORY_MODEL;
    void** iac = NULL_POINTER_MEMORY_MODEL;
    void** ias = NULL_POINTER_MEMORY_MODEL;
    void** im = NULL_POINTER_MEMORY_MODEL;
    void** imc = NULL_POINTER_MEMORY_MODEL;
    void** ims = NULL_POINTER_MEMORY_MODEL;
    void** id = NULL_POINTER_MEMORY_MODEL;
    void** idc = NULL_POINTER_MEMORY_MODEL;
    void** ids = NULL_POINTER_MEMORY_MODEL;
    // The source part blink property name, abstraction, model, details.
    void** bln = NULL_POINTER_MEMORY_MODEL;
    void** blnc = NULL_POINTER_MEMORY_MODEL;
    void** blns = NULL_POINTER_MEMORY_MODEL;
    void** bla = NULL_POINTER_MEMORY_MODEL;
    void** blac = NULL_POINTER_MEMORY_MODEL;
    void** blas = NULL_POINTER_MEMORY_MODEL;
    void** blm = NULL_POINTER_MEMORY_MODEL;
    void** blmc = NULL_POINTER_MEMORY_MODEL;
    void** blms = NULL_POINTER_MEMORY_MODEL;
    void** bld = NULL_POINTER_MEMORY_MODEL;
    void** bldc = NULL_POINTER_MEMORY_MODEL;
    void** blds = NULL_POINTER_MEMORY_MODEL;
    // The source part underline property name, abstraction, model, details.
    void** un = NULL_POINTER_MEMORY_MODEL;
    void** unc = NULL_POINTER_MEMORY_MODEL;
    void** uns = NULL_POINTER_MEMORY_MODEL;
    void** ua = NULL_POINTER_MEMORY_MODEL;
    void** uac = NULL_POINTER_MEMORY_MODEL;
    void** uas = NULL_POINTER_MEMORY_MODEL;
    void** um = NULL_POINTER_MEMORY_MODEL;
    void** umc = NULL_POINTER_MEMORY_MODEL;
    void** ums = NULL_POINTER_MEMORY_MODEL;
    void** ud = NULL_POINTER_MEMORY_MODEL;
    void** udc = NULL_POINTER_MEMORY_MODEL;
    void** uds = NULL_POINTER_MEMORY_MODEL;
    // The source part bold property name, abstraction, model, details.
    void** bn = NULL_POINTER_MEMORY_MODEL;
    void** bnc = NULL_POINTER_MEMORY_MODEL;
    void** bns = NULL_POINTER_MEMORY_MODEL;
    void** ba = NULL_POINTER_MEMORY_MODEL;
    void** bac = NULL_POINTER_MEMORY_MODEL;
    void** bas = NULL_POINTER_MEMORY_MODEL;
    void** bm = NULL_POINTER_MEMORY_MODEL;
    void** bmc = NULL_POINTER_MEMORY_MODEL;
    void** bms = NULL_POINTER_MEMORY_MODEL;
    void** bd = NULL_POINTER_MEMORY_MODEL;
    void** bdc = NULL_POINTER_MEMORY_MODEL;
    void** bds = NULL_POINTER_MEMORY_MODEL;
    // The source whole position name, abstraction, model, details.
    void** wpn = NULL_POINTER_MEMORY_MODEL;
    void** wpnc = NULL_POINTER_MEMORY_MODEL;
    void** wpns = NULL_POINTER_MEMORY_MODEL;
    void** wpa = NULL_POINTER_MEMORY_MODEL;
    void** wpac = NULL_POINTER_MEMORY_MODEL;
    void** wpas = NULL_POINTER_MEMORY_MODEL;
    void** wpm = NULL_POINTER_MEMORY_MODEL;
    void** wpmc = NULL_POINTER_MEMORY_MODEL;
    void** wpms = NULL_POINTER_MEMORY_MODEL;
    void** wpd = NULL_POINTER_MEMORY_MODEL;
    void** wpdc = NULL_POINTER_MEMORY_MODEL;
    void** wpds = NULL_POINTER_MEMORY_MODEL;
    // The source whole size name, abstraction, model, details.
    void** wsn = NULL_POINTER_MEMORY_MODEL;
    void** wsnc = NULL_POINTER_MEMORY_MODEL;
    void** wsns = NULL_POINTER_MEMORY_MODEL;
    void** wsa = NULL_POINTER_MEMORY_MODEL;
    void** wsac = NULL_POINTER_MEMORY_MODEL;
    void** wsas = NULL_POINTER_MEMORY_MODEL;
    void** wsm = NULL_POINTER_MEMORY_MODEL;
    void** wsmc = NULL_POINTER_MEMORY_MODEL;
    void** wsms = NULL_POINTER_MEMORY_MODEL;
    void** wsd = NULL_POINTER_MEMORY_MODEL;
    void** wsdc = NULL_POINTER_MEMORY_MODEL;
    void** wsds = NULL_POINTER_MEMORY_MODEL;

    // The element name.
    void* en = *NULL_POINTER_MEMORY_MODEL;
    int enc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The remaining name.
    void* rn = *NULL_POINTER_MEMORY_MODEL;
    int rnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The loop count.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The name comparison result.
    int nr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The abstraction comparison result.
    int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get compound element (area to be repainted) name and remaining name,
    // as well as the flag indicating a part- or meta element.
    get_compound_element_name_and_remaining_name(p11, p12, (void*) &en, (void*) &enc, (void*) &rn, (void*) &rnc, (void*) &f);

    if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (f == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

        // Either, no hierarchical element name (repaint area) was given
        // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
        // but the whole textual user interface (tui) window is repainted,
        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
        // OR:
        // the expected compound element (area to be repainted) pointed to
        // by the hierarchical name is a "part" element (f == 0), not a "meta" element,
        // which is correct, so that the element can be processed/ repainted.

        // Get part super properties from details.
        get_universal_compound_element_by_name(
            (void*) &supern, (void*) &supernc, (void*) &superns,
            (void*) &supera, (void*) &superac, (void*) &superas,
            (void*) &superm, (void*) &supermc, (void*) &superms,
            (void*) &superd, (void*) &superdc, (void*) &superds,
            p7, p8,
            (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part shape from details.
        get_universal_compound_element_by_name(
            (void*) &shn, (void*) &shnc, (void*) &shns,
            (void*) &sha, (void*) &shac, (void*) &shas,
            (void*) &shm, (void*) &shmc, (void*) &shms,
            (void*) &shd, (void*) &shdc, (void*) &shds,
            p7, p8,
            (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part layout from details.
        get_universal_compound_element_by_name(
            (void*) &ln, (void*) &lnc, (void*) &lns,
            (void*) &la, (void*) &lac, (void*) &las,
            (void*) &lm, (void*) &lmc, (void*) &lms,
            (void*) &ld, (void*) &ldc, (void*) &lds,
            p7, p8,
            (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part cell from details.
        get_universal_compound_element_by_name(
            (void*) &cn, (void*) &cnc, (void*) &cns,
            (void*) &ca, (void*) &cac, (void*) &cas,
            (void*) &cm, (void*) &cmc, (void*) &cms,
            (void*) &cd, (void*) &cdc, (void*) &cds,
            p7, p8,
            (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part position from details.
        get_universal_compound_element_by_name(
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds,
            p7, p8,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part size from details.
        get_universal_compound_element_by_name(
            (void*) &sn, (void*) &snc, (void*) &sns,
            (void*) &sa, (void*) &sac, (void*) &sas,
            (void*) &sm, (void*) &smc, (void*) &sms,
            (void*) &sd, (void*) &sdc, (void*) &sds,
            p7, p8,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part background colour from details.
        get_universal_compound_element_by_name(
            (void*) &bgn, (void*) &bgnc, (void*) &bgns,
            (void*) &bga, (void*) &bgac, (void*) &bgas,
            (void*) &bgm, (void*) &bgmc, (void*) &bgms,
            (void*) &bgd, (void*) &bgdc, (void*) &bgds,
            p7, p8,
            (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part foreground colour from details.
        get_universal_compound_element_by_name(
            (void*) &fgn, (void*) &fgnc, (void*) &fgns,
            (void*) &fga, (void*) &fgac, (void*) &fgas,
            (void*) &fgm, (void*) &fgmc, (void*) &fgms,
            (void*) &fgd, (void*) &fgdc, (void*) &fgds,
            p7, p8,
            (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part border from details.
        get_universal_compound_element_by_name(
            (void*) &bon, (void*) &bonc, (void*) &bons,
            (void*) &boa, (void*) &boac, (void*) &boas,
            (void*) &bom, (void*) &bomc, (void*) &boms,
            (void*) &bod, (void*) &bodc, (void*) &bods,
            p7, p8,
            (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part hidden property from details.
        get_universal_compound_element_by_name(
            (void*) &hn, (void*) &hnc, (void*) &hns,
            (void*) &ha, (void*) &hac, (void*) &has,
            (void*) &hm, (void*) &hmc, (void*) &hms,
            (void*) &hd, (void*) &hdc, (void*) &hds,
            p7, p8,
            (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part inverse property from details.
        get_universal_compound_element_by_name(
            (void*) &in, (void*) &inc, (void*) &ins,
            (void*) &ia, (void*) &iac, (void*) &ias,
            (void*) &im, (void*) &imc, (void*) &ims,
            (void*) &id, (void*) &idc, (void*) &ids,
            p7, p8,
            (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part blink property from details.
        get_universal_compound_element_by_name(
            (void*) &bln, (void*) &blnc, (void*) &blns,
            (void*) &bla, (void*) &blac, (void*) &blas,
            (void*) &blm, (void*) &blmc, (void*) &blms,
            (void*) &bld, (void*) &bldc, (void*) &blds,
            p7, p8,
            (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part underline property from details.
        get_universal_compound_element_by_name(
            (void*) &un, (void*) &unc, (void*) &uns,
            (void*) &ua, (void*) &uac, (void*) &uas,
            (void*) &um, (void*) &umc, (void*) &ums,
            (void*) &ud, (void*) &udc, (void*) &uds,
            p7, p8,
            (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part bold property from details.
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

        if (*shm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*lm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part layout from details.
            get_universal_compound_element_by_name(
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                *superm, *supermc,
                (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*cm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part cell from details.
            get_universal_compound_element_by_name(
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *superm, *supermc,
                (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*pm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*sm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*bgm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*fgm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*bom == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*hm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*im == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*blm == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*um == *NULL_POINTER_MEMORY_MODEL) {

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

        if (*bm == *NULL_POINTER_MEMORY_MODEL) {

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

        // Get source whole position from details.
        get_universal_compound_element_by_name(
            (void*) &wpn, (void*) &wpnc, (void*) &wpns,
            (void*) &wpa, (void*) &wpac, (void*) &wpas,
            (void*) &wpm, (void*) &wpmc, (void*) &wpms,
            (void*) &wpd, (void*) &wpdc, (void*) &wpds,
            p9, p10,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        // Get source whole size from details.
        get_universal_compound_element_by_name(
            (void*) &wsn, (void*) &wsnc, (void*) &wsns,
            (void*) &wsa, (void*) &wsac, (void*) &wsas,
            (void*) &wsm, (void*) &wsmc, (void*) &wsms,
            (void*) &wsd, (void*) &wsdc, (void*) &wsds,
            p9, p10,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        compare_all_array((void*) &ar, p3, (void*) PART_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p4, (void*) PART_MEMORY_ABSTRACTION_COUNT);

        if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The part model IS a compound.

            // CAUTION! Paint the compound's background etc.,
            // but do NOT hand over the model!
            // Since the model is a compound and not a valid character,
            // it will cause wrong characters or question marks to be printed on screen!
            // Therefore, do hand over a null pointer instead of the model!
            if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (rn == *NULL_POINTER_MEMORY_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_gnu_linux_console_shape(p0, p1, p2,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* sc = (int*) p6;

                // Iterate through compound parts.
                while (*TRUE_BOOLEAN_MEMORY_MODEL) {

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
                    compare_all_array((void*) &nr, *n, en, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, *nc, (void*) &enc);

                    if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (nr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                        // Either, no hierarchical element name (repaint area) was given
                        // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                        // but the whole textual user interface (tui) window is repainted,
                        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                        // OR:
                        // the compound part name matches the next name in the
                        // given cascade of separated names, pointing to a knowledge model.

                        // Recursively call this procedure for compound part model.
                        encode_gnu_linux_console(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p7, p8, rn, (void*) &rnc, p13, p14);
                    }

                    // Reset source part name, abstraction, model, details
                    // (parameters of the current compound part element).
                    n = NULL_POINTER_MEMORY_MODEL;
                    nc = NULL_POINTER_MEMORY_MODEL;
                    ns = NULL_POINTER_MEMORY_MODEL;
                    a = NULL_POINTER_MEMORY_MODEL;
                    ac = NULL_POINTER_MEMORY_MODEL;
                    as = NULL_POINTER_MEMORY_MODEL;
                    m = NULL_POINTER_MEMORY_MODEL;
                    mc = NULL_POINTER_MEMORY_MODEL;
                    ms = NULL_POINTER_MEMORY_MODEL;
                    d = NULL_POINTER_MEMORY_MODEL;
                    dc = NULL_POINTER_MEMORY_MODEL;
                    ds = NULL_POINTER_MEMORY_MODEL;

                    // Reset name comparison result.
                    nr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Increment loop count.
                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The source count parameter is null.");
            }

        } else {

            // The part model is NOT a compound.

            if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (rn == *NULL_POINTER_MEMORY_MODEL)) {
    //??        if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_gnu_linux_console_shape(p0, p1, p2, p5, p6, p3, p4,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The hierarchical compound element name contains a meta element, while only part elements are permitted.");
    }
}

/* TERMINAL_ENCODER_SOURCE */
#endif
