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

#ifndef COORDINATES_TERMINAL_SERIALISER_SOURCE
#define COORDINATES_TERMINAL_SERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/terminal/escape_control_sequence_terminal_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_background_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_foreground_serialiser.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the terminal coordinates.
 *
 * @param p0 the destination control sequence code item
 * @param p3 the character
 * @param p4 the character count
 * @param p5 the hidden property
 * @param p6 the inverse property
 * @param p7 the blink property
 * @param p8 the underline property
 * @param p9 the bold property
 * @param p10 the background
 * @param p11 the background count
 * @param p12 the foreground
 * @param p13 the foreground count
 * @param p14 the position
 * @param p15 the position count
 * @param p16 the size
 * @param p17 the size count
 * @param p18 the whole model position
 * @param p19 the whole model position count
 * @param p20 the whole model size
 * @param p21 the whole model size count
 * @param p22 the border
 * @param p23 the border count
 * @param p24 the layout cell
 * @param p25 the layout cell count
 * @param p26 the layout
 * @param p27 the layout count
 */
void serialise_terminal_coordinates(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24, void* p25, void* p26, void* p27) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise terminal coordinates.");

    // The source part position x, y, z.
    int* px = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* py = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* pz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part size x, y, z.
    int* sx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* sy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* sz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The current position x, y, z.
    int cpx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cpy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cpz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The current size x, y, z.
    int csx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int csy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int csz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The source whole position coordinates.
    int* wpmx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wpmy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wpmz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source whole size coordinates.
    int* wsmx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wsmy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wsmz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The original area position coordinates, set to the zero origo.
    int oapx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oapy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oapz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The original area size coordinates, initialised with whole coordinates.
    int oasx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oasy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oasz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The free area position coordinates, initialised with original area position coordinates.
    int fapx = oapx;
    int fapy = oapy;
    int fapz = oapz;
    // The free area size coordinates, initialised with original area position coordinates.
    int fasx = oasx;
    int fasy = oasy;
    int fasz = oasz;

    // Get part position x, y, z.
    get((void*) &px, p14, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
    get((void*) &py, p14, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
    get((void*) &pz, p14, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
    // Get part size x, y, z.
    get((void*) &sx, p16, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
    get((void*) &sy, p16, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
    get((void*) &sz, p16, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);

    // Set current position coordinates, initialised with part position.
    cpx = *px;
    cpy = *py;
    cpz = *pz;
    // Set current size coordinates, initialised with part size.
    csx = *sx;
    csy = *sy;
    csz = *sz;

    if (p20 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Determine source whole position coordinates.
        get((void*) &wpmx, p18, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
        get((void*) &wpmy, p18, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
        get((void*) &wpmz, p18, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
        // Determine source whole size coordinates.
        get((void*) &wsmx, p20, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
        get((void*) &wsmy, p20, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);
        get((void*) &wsmz, p20, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE_COUNT);

        // Set original area position coordinates, initialised with whole position.
        oapx = *wpmx;
        oapy = *wpmy;
        oapz = *wpmz;
        // Set original area size coordinates, initialised with whole size.
        oasx = *wsmx;
        oasy = *wsmy;
        oasz = *wsmz;

        // Set free area position coordinates, initialised with original area position coordinates.
        fapx = oapx;
        fapy = oapy;
        fapz = oapz;
        // Set free area size coordinates, initialised with original area position coordinates.
        fasx = oasx;
        fasy = oasy;
        fasz = oasz;
    }

    // Calculate coordinates according to given layout.
    serialise_terminal_rectangle_layout((void*) &cpx, (void*) &cpy, (void*) &cpz, (void*) &csx, (void*) &csy, (void*) &csz,
        (void*) &fapx, (void*) &fapy, (void*) &fapz, (void*) &fasx, (void*) &fasy, (void*) &fasz,
        (void*) &oapx, (void*) &oapy, (void*) &oapz, (void*) &oasx, (void*) &oasy, (void*) &oasz,
        p24, p25, p26, p27);

    serialise_terminal_rectangle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,
        (void*) &cpx, (void*) &cpy, (void*) &cpz, (void*) &csx, (void*) &csy, (void*) &csz, p22, p23);
}

/* COORDINATES_TERMINAL_SERIALISER_SOURCE */
#endif
