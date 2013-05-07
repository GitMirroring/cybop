/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include <xcb/xcb.h>
/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <pthread.h>
#include <signal.h>
*/

#ifdef WIN32
    #include <winsock2.h>
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../../logger/logger.c"

/**
 * Determine the graphical part's mouse command.
 *
 * The activated button is identified first.
 * Afterwards, the event type is identified.
 * Finally, the corresponding mouse command is returned as result.
 *
 * @param p0 the command name (pointer reference)
 * @param p1 the command name count (pointer reference)
 * @param p2 the command name size (pointer reference)
 * @param p3 the command type (pointer reference)
 * @param p4 the command type count (pointer reference)
 * @param p5 the command type size (pointer reference)
 * @param p6 the command model (pointer reference)
 * @param p7 the command model count (pointer reference)
 * @param p8 the command model size (pointer reference)
 * @param p9 the command properties (pointer reference)
 * @param p10 the command properties count (pointer reference)
 * @param p11 the command properties size (pointer reference)
 * @param p12 the whole properties
 * @param p13 the whole properties count
 * @param p14 the event type
 * @param p15 the mouse button
 * @param p16 the knowledge memory
 * @param p17 the knowledge memory count
 */
void sense_x_window_system_mouse_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

/*??
    if (p15 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p15;

        if (p14 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* t = (int*) p14;

            if (*b == Button1) {

                if (*t == XCB_BUTTON_PRESS) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11,
                        p12, p13,
                        (void*) LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p16, p17);

                } else if (*t == XCB_BUTTON_RELEASE) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11,
                        p12, p13,
                        (void*) LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p16, p17);
                }

            } else if (*b == Button2) {
            } else if (*b == Button3) {
            } else if (*b == Button4) {
            } else if (*b == Button5) {
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system mouse command. The event type is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system mouse command. The mouse button is null.");
    }
*/
}

/**
 * Determine the graphical part's command.
 *
 * The event type gets identified, in order to call the corresponding procedure.
 * Mouse press or -release events have to be handled differently than drag'n'drop.
 *
 * @param p0 the command name (pointer reference)
 * @param p1 the command name count (pointer reference)
 * @param p2 the command name size (pointer reference)
 * @param p3 the command type (pointer reference)
 * @param p4 the command type count (pointer reference)
 * @param p5 the command type size (pointer reference)
 * @param p6 the command model (pointer reference)
 * @param p7 the command model count (pointer reference)
 * @param p8 the command model size (pointer reference)
 * @param p9 the command properties (pointer reference)
 * @param p10 the command properties count (pointer reference)
 * @param p11 the command properties size (pointer reference)
 * @param p12 the whole properties
 * @param p13 the whole properties count
 * @param p14 the event type
 * @param p15 the mouse button
 * @param p16 the knowledge memory
 * @param p17 the knowledge memory count
 */
void sense_x_window_system_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p14 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p14;

        if ((*t == XCB_BUTTON_PRESS) || (*t == XCB_BUTTON_RELEASE)) {

            sense_x_window_system_mouse_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

/*??
        } else if (*t == MouseMove) {

            // Drag'n'Drop needs to be handled differently than simple mouse clicks.
*/
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system command. The event type is null.");
    }
}

/**
 * Determine the graphical part that was activated by mouse,
 * in order to determine its command.
 *
 * The given tree of graphical parts is looped element by element, diving
 * deeper and deeper into those parts that belong to the area which was
 * selected by mouse, until the final part in which the mouse action happened
 * is reached.
 *
 * While reading the graphical parts, their mouse command is stored.
 * Commands of smaller parts embedded in bigger, surrounding wholes overwrite
 * any previously stored commands of their wholes. Finally, the mouse command
 * is returned as result of this procedure.
 *
 * @param p0 the command name (pointer reference)
 * @param p1 the command name count (pointer reference)
 * @param p2 the command name size (pointer reference)
 * @param p3 the command type (pointer reference)
 * @param p4 the command type count (pointer reference)
 * @param p5 the command type size (pointer reference)
 * @param p6 the command model (pointer reference)
 * @param p7 the command model count (pointer reference)
 * @param p8 the command model size (pointer reference)
 * @param p9 the command properties (pointer reference)
 * @param p10 the command properties count (pointer reference)
 * @param p11 the command properties size (pointer reference)
 * @param p12 the whole model
 * @param p13 the whole model count
 * @param p14 the mouse x coordinate within the graphical whole
 * @param p15 the mouse y coordinate within the graphical whole
 * @param p16 the mouse z coordinate within the graphical whole
 * @param p17 the event type
 * @param p18 the mouse button
 * @param p19 the knowledge memory
 * @param p20 the knowledge memory count
 */
void sense_x_window_system_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20) {

/*??
    if (p16 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* mz = (int*) p16;

        if (p15 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* my = (int*) p15;

            if (p14 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* mx = (int*) p14;

                if (p13 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* wmc = (int*) p13;

                    // The graphical part name, type, model, properties.
                    void** n = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** nc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** a = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** as = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** m = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** mc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** d = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** dc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The graphical part position name, type, model, properties.
                    void** pn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pa = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The graphical part size name, type, model, properties.
                    void** sn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** snc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sa = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** smc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sds = NULL_POINTER_STATE_CYBOI_MODEL;

                    // The graphical part position coordinates.
                    int** pmx = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                    int** pmy = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                    int** pmz = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                    // The graphical part size coordinates.
                    int** smx = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                    int** smy = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                    int** smz = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

                    // The new mouse coordinates.
                    int nx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    int ny = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    int nz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // The loop count.
                    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                        if (j >= *wmc) {

                            break;
                        }

                        // Get graphical part at index j.
                        get_compound_element_by_index(p12, p13, (void*) &j,
                            (void*) &n, (void*) &nc, (void*) &ns,
                            (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms,
                            (void*) &d, (void*) &dc, (void*) &ds);

                        // Get graphical part position from properties.
                        get_universal_compound_element_by_name(
                            (void*) &pn, (void*) &pnc, (void*) &pns,
                            (void*) &pa, (void*) &pac, (void*) &pas,
                            (void*) &pm, (void*) &pmc, (void*) &pms,
                            (void*) &pd, (void*) &pdc, (void*) &pds,
                            *d, *dc,
                            (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            p19, p20);
                        // Get graphical part size from properties.
                        get_universal_compound_element_by_name(
                            (void*) &sn, (void*) &snc, (void*) &sns,
                            (void*) &sa, (void*) &sac, (void*) &sas,
                            (void*) &sm, (void*) &smc, (void*) &sms,
                            (void*) &sd, (void*) &sdc, (void*) &sds,
                            *d, *dc,
                            (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            p19, p20);

                        // Determine graphical part position coordinates.
                        get((void*) &pmx, *pm, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        get((void*) &pmy, *pm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        get((void*) &pmz, *pm, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        // Determine source part size coordinates.
                        get((void*) &smx, *sm, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        get((void*) &smy, *sm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        get((void*) &smz, *sm, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

                        if ((*mx >= **pmx) && (*my >= **pmy) && (*mz >= **pmz)
                            && (*mx < (**pmx + **smx)) && (*my < (**pmy + **smy)) && (*mz < (**pmz + **smz))) {

                            // The event happened within the graphical part's area.

                            // Sense the graphical part's command.
                            sense_x_window_system_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, *d, *dc, p17, p18, p19, p20);

                            compare_all_array((void*) &r, *a, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *ac, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

                            if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                // The graphical part model is a compound.

                                // Calculate the new mouse coordinates, relative to the part model.
                                nx = *mx - **pmx;
                                ny = *my - **pmy;
                                nz = *mz - **pmz;

                                // Recursively call this procedure for compound part model.
                                sense_x_window_system_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, *m, *mc, &nx, &ny, &nz, p17, p18, p19, p20);
                            }
                        }

                        // Reset graphical part name, type, model, properties.
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
                        // Reset graphical part position name, type, model, properties.
                        pn = NULL_POINTER_STATE_CYBOI_MODEL;
                        pnc = NULL_POINTER_STATE_CYBOI_MODEL;
                        pns = NULL_POINTER_STATE_CYBOI_MODEL;
                        pa = NULL_POINTER_STATE_CYBOI_MODEL;
                        pac = NULL_POINTER_STATE_CYBOI_MODEL;
                        pas = NULL_POINTER_STATE_CYBOI_MODEL;
                        pm = NULL_POINTER_STATE_CYBOI_MODEL;
                        pmc = NULL_POINTER_STATE_CYBOI_MODEL;
                        pms = NULL_POINTER_STATE_CYBOI_MODEL;
                        pd = NULL_POINTER_STATE_CYBOI_MODEL;
                        pdc = NULL_POINTER_STATE_CYBOI_MODEL;
                        pds = NULL_POINTER_STATE_CYBOI_MODEL;
                        // Reset graphical part size name, type, model, properties.
                        sn = NULL_POINTER_STATE_CYBOI_MODEL;
                        snc = NULL_POINTER_STATE_CYBOI_MODEL;
                        sns = NULL_POINTER_STATE_CYBOI_MODEL;
                        sa = NULL_POINTER_STATE_CYBOI_MODEL;
                        sac = NULL_POINTER_STATE_CYBOI_MODEL;
                        sas = NULL_POINTER_STATE_CYBOI_MODEL;
                        sm = NULL_POINTER_STATE_CYBOI_MODEL;
                        smc = NULL_POINTER_STATE_CYBOI_MODEL;
                        sms = NULL_POINTER_STATE_CYBOI_MODEL;
                        sd = NULL_POINTER_STATE_CYBOI_MODEL;
                        sdc = NULL_POINTER_STATE_CYBOI_MODEL;
                        sds = NULL_POINTER_STATE_CYBOI_MODEL;

                        // Reset graphical part position coordinates.
                        pmx = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                        pmy = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                        pmz = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                        // Reset graphical part size coordinates.
                        smx = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                        smy = (int**) NULL_POINTER_STATE_CYBOI_MODEL;
                        smz = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

                        // Reset new mouse coordinates.
                        nx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        ny = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        nz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                        // Reset comparison result.
                        r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                        // Increment loop count.
                        j++;
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system part. The whole model count is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system part. The mouse x coordinate is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system part. The mouse y coordinate is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system part. The mouse z coordinate is null.");
    }
*/
}

/**
 * Receives user input to the x window system.
 *
 * @param p0 the internal memory data
--
 * @param p0 the destination window (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source display
 * @param p4 the source count
 */
//?? void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
void receive_x_window_system(void* p0) {

/*??
    // The knowledge memory.
    void** k = NULL_POINTER_STATE_CYBOI_MODEL;
    void** kc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ks = NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory.
    void** s = NULL_POINTER_STATE_CYBOI_MODEL;
    void** sc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ss = NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER_STATE_CYBOI_MODEL;
    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory interrupt request flag.
    sig_atomic_t** sirq = (sig_atomic_t**) NULL_POINTER_STATE_CYBOI_MODEL;
    // The user interface root.
    void** r = NULL_POINTER_STATE_CYBOI_MODEL;
    void** rc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** rs = NULL_POINTER_STATE_CYBOI_MODEL;
    // The user interface commands.
    void** c = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cs = NULL_POINTER_STATE_CYBOI_MODEL;
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    int** w = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

    // Get knowledge memory internal.
    get((void*) &k, p0, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &kc, p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &ks, p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get signal memory internal.
    get((void*) &s, p0, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &sc, p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &ss, p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get signal memory mutex.
    get((void*) &smt, p0, (void*) MUTEX_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get x window system mutex.
    get((void*) &xmt, p0, (void*) MUTEX_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get interrupt request internal.
    get((void*) &sirq, p0, (void*) INTERRUPT_REQUEST_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get user interface root internal.
    get((void*) &r, p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &rc, p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &rs, p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get user interface commands internal.
    get((void*) &c, p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &cc, p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &cs, p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    // Get x window system internals.
    get((void*) &d, p0, (void*) DISPLAY_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    get((void*) &w, p0, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    // The command name, type, model, properties.
    void** cn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** ca = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cdc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** cds = NULL_POINTER_STATE_CYBOI_MODEL;

    //?? TODO: The temporary graphical part name, type, model, properties.
    void** tmpn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpa = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpdc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** tmpds = NULL_POINTER_STATE_CYBOI_MODEL;

    // The signal identification.
    void** id = NULL_POINTER_STATE_CYBOI_MODEL;
*/

    // The connection.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connection.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNECTION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get mutex.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    if (m != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            pthread_mutex_lock((pthread_mutex_t*) m);

            // Get next event.
            //
            // A special thread with "sense" function was used to
            // detect events. But this is the main thread.
            // The event detected before shall be received here.
            //
            // There are two ways to receive events:
            // - blocking: xcb_wait_for_event
            // - non-blocking: xcb_poll_for_event
            //
            // The "xcb_wait_for_event" function blocks until an event
            // is queued in the x server, then dequeues it from the
            // queue, then returns it as a newly allocated structure.
            //
            // The "xcb_poll_for_event" function dequeues and returns
            // an event immediately. It returns NULL if no event is
            // available at the time of the call. If an error occurs,
            // the parameter error will be filled with the error status.
            //
            // Decision:
            //
            // Since this is the main thread, it MUST NOT block.
            // Therefore, the non-blocking "xcb_poll_for_event"
            // function is used here.
            //
            // CAUTION! Whenever an event is queued in the x server,
            // it gets dequeued from the queue here and is then
            // returned as a newly allocated structure.
            // It is cyboi's responsibility to FREE the
            // returned event structure.
            xcb_generic_event_t* e = xcb_poll_for_event((xcb_connection_t*) c);

            pthread_mutex_unlock((pthread_mutex_t*) m);

    fwprintf(stdout, L"TEST receive x window system e: %i\n", e);

            if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Get response type.
                //
                // CAUTION! The type of the returned value is "uint8_t".
                // Since it is just one byte in size, it may be assigned
                // to an "int" variable of four byte without problems.
                int t = e->response_type;

    fwprintf(stdout, L"TEST receive x window system t: %i\n", t);

                // Convert type using bit operation AND.
                // The hexadecimal value 0x80 is decimal 128.
                //
                //?? TODO: Why is this conversion necessary?
                //?? Nothing explained in the tutorials ...
//??                t = t & (~0x80);
                int t_TEST = t & (~0x80);

    fwprintf(stdout, L"TEST receive x window system t_TEST: %i\n", t_TEST);

                if (t == XCB_EXPOSE) {

    fwprintf(stdout, L"TEST receive x window system XCB_EXPOSE t: %i\n", t);

                    //?? TEST only!
//??                    send_x_window_system(*NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) X_WINDOW_SYSTEM_MESSAGE_STATE_CYBOI_LANGUAGE, p0);

                    // Expose events are sensed when a window needs to be repainted
                    // when being displayed after having been covered before.

    /*??
                    // Consider only the last in a row of multiple expose events.
                    if (e.xexpose.count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // Get actual command belonging to the x window system expose event.
                        get_universal_compound_element_by_name(
                            (void*) &cn, (void*) &cnc, (void*) &cns,
                            (void*) &ca, (void*) &cac, (void*) &cas,
                            (void*) &cm, (void*) &cmc, (void*) &cms,
                            (void*) &cd, (void*) &cdc, (void*) &cds,
                            *c, *cc,
                            (void*) EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            *k, *kc);

                fwprintf(stdout, L"TEST expose sense t: %i\n", t);

                        // Lock signal memory mutex.
                        pthread_mutex_lock(*smt);

                        // Get new signal identification by incrementing the current maximum signal's one.
                        get_new_signal_identification((void*) &id, *s, *sc);

                        // Add signal to signal memory.
            //??            replace_signal_memory(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) id);

                        // Set interrupt request flag, in order to notify the signal checker
                        // that a new signal has been placed in the signal memory.
                        **sirq = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                        // Unlock signal memory mutex.
                        pthread_mutex_unlock(*smt);
                    }
    */

    /*?? Probably NOT in XCB; was in Xlib!
                } else if (t == MappingNotify) {

                    // Mapping change events are sent when the keyboard mapping changes.

            //??        XRefreshKeyboardMapping(&e);
    */

                } else if ((t == XCB_BUTTON_PRESS) || (t == XCB_BUTTON_RELEASE)) {

    fwprintf(stdout, L"TEST receive x window system XCB_BUTTON_PRESS t: %i\n", t);

/*??
                    //?? TODO: This is a temporary solution!
                    //?? There is no meta information (such as position or size) known
                    //?? about the gui root node. Therefore, the actual window as its
                    //?? only part element is determined here and handed over to
                    //?? further procedures.
                    get_compound_element_by_index(*r, *rc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL,
                        (void*) &tmpn, (void*) &tmpnc, (void*) &tmpns,
                        (void*) &tmpa, (void*) &tmpac, (void*) &tmpas,
                        (void*) &tmpm, (void*) &tmpmc, (void*) &tmpms,
                        (void*) &tmpd, (void*) &tmpdc, (void*) &tmpds);

                    // Determine command, depending on mouse button and event type.
                    // First, determine coordinates of the click within window-panel-sub_panel-etc.-button.
                    // Then, determine command that was assigned to button as property in cybol.
                    // Finally, send part pointed to by "command" (knowledge path) as signal to signal memory (queue).
                    sense_x_window_system_part(&cn, &cnc, &cns, &ca, &cac, &cas, &cm, &cmc, &cms, &cd, &cdc, &cds,
                        *tmpm, *tmpmc, &(e.xbutton.x), &(e.xbutton.y), (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL,
                        &t, &(e.xbutton.button), *k, *kc);
*/

                } else if (t == XCB_MOTION_NOTIFY) {

    fwprintf(stdout, L"TEST receive x window system XCB_MOTION_NOTIFY t: %i\n", t);

/*??
                    //?? The an_event.xmotion.state variable (unsigned int state) contains
                    //?? a mask of the buttons (or keys) held down during this event - if any.
                    //?? This field is a bitwise OR of any of the following:
                    Button1Mask
                    Button2Mask
                    Button3Mask
                    Button4Mask
                    Button5Mask
                    ShiftMask
                    LockMask
                    ControlMask
                    Mod1Mask
                    Mod2Mask
                    Mod3Mask
                    Mod4Mask
                    Mod5Mask

                    //?? Example:
                    //?? If the 1st mouse button was held during this event,
                    //?? draw a pixel at the mouse pointer location.
                    if (an_event.xmotion.state & Button1Mask) {
                        XDrawPoint(display, the_win, gc_draw, x, y);
                    }
            */

                } else if ((t == XCB_ENTER_NOTIFY) || (XCB_LEAVE_NOTIFY)) {

    fwprintf(stdout, L"TEST receive x window system XCB_ENTER_NOTIFY t: %i\n", t);

                    //?? an_event.xcrossing

                } else if ((t == XCB_KEY_PRESS) || (t == XCB_KEY_RELEASE)) {

    fwprintf(stdout, L"TEST receive x window system XCB_KEY_PRESS t: %i\n", t);

                    // Key press events relate to keyboard keys.

            /*??
                    Example:
                    // Translate the key code to a key symbol.
                    KeySym key_symbol = XKeycodeToKeysym(display, an_event.xkey.keycode, 0);
                    switch (key_symbol) {
                        case XK_1:
                        case XK_KP_1:
                            // '1' key was pressed, either the normal '1',
                            // or the '1' on the keypad. draw the current pixel.
                            XDrawPoint(display, the_win, gc_draw, x, y);
                            break;
                        case XK_Delete:
                            // DEL key was pressed, erase the current pixel.
                            XDrawPoint(display, the_win, gc_erase, x, y);
                            break;
                        default:
                            // Anything else - check if it is a letter key
                            if (key_symbol >= XK_A && key_symbol <= XK_Z) {
                                int ascii_key = key_symbol - XK_A + 'A';
                                printf("Key pressed - '%c'\n", ascii_key);
                            }
                            if (key_symbol >= XK_a && key_symbol <= XK_z) {
                                int ascii_key = key_symbol - XK_a + 'a';
                                printf("Key pressed - '%c'\n", ascii_key);
                            }
                            break;
                    }
            */

            /*??
                    KeySym k;
                    char text[10];
                    char str_test[1000];
                    char str_zugriff[1000];
                    char str_menubar[100];
                    //??unsigned long //??double menu_foreground;
                    // The temporary variables.
                //??    int k;
                    int menu_eintrage_ende;
                    int window;
                    int i = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x;
            */

            /*??
                    i = XLookupString(&e, text, 10, &k, 0);

                    //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
                    //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte

                    if (i == 1 && text[0] == 'a') {

                        XClearArea (d, w, 0, 0, 0, 0, True);
                        Anwendung.menu_bar1.menus[0].angeklickt = 1;
                        Anwendung.menu_bar1.menus[1].angeklickt = 0;
                        Anwendung.menu_bar1.menus[2].angeklickt = 0;

                    } else if (i == 1 && text[0] == 'b') {

                        XClearArea (d, w, 0, 0, 0, 0, True);
                        Anwendung.menu_bar1.menus[0].angeklickt = 0;
                        Anwendung.menu_bar1.menus[1].angeklickt = 1;
                        Anwendung.menu_bar1.menus[2].angeklickt = 0;

                    } else if (i == 1 && text[0] == 'c') {

                        XClearArea (d, w, 0, 0, 0, 0, True);
                        Anwendung.menu_bar1.menus[0].angeklickt = 0;
                        Anwendung.menu_bar1.menus[1].angeklickt = 0;
                        Anwendung.menu_bar1.menus[2].angeklickt = 1;
                    }

                    if (i == 1 && text[0] == 'x') {

                        XClearArea (d, w, 0, 0, 0, 0, True);

                        Anwendung.menu_bar1.menus[0].angeklickt = 0;
                        Anwendung.menu_bar1.menus[1].angeklickt = 0;
                        Anwendung.menu_bar1.menus[2].angeklickt = 0;

                    } else if (i == 1 && text[0] == 'q') {

                        f = 1;
                    }
            */

                    //?? To erase graphical areas (such as an open menu), use:
                    //?? XClearArea (d, w, 0, 0, 0, 0, True);

                    //?? What is this useful for?
                    //?? XDrawImageString(e.xexpose.display, e.xexpose.window, gc_menu_font, 100, 100, event.xbutton.x, wcslen(event.xbutton.x));
                }

                // Deallocate event.
                //
                // CAUTION! An event gets created by the xcb library,
                // but HAS TO BE destroyed manually here.
                free(e);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system. The event is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system. The connection is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system. The mutex is null.");
    }
}

/* X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
