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

#ifndef EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE

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
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
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
                    // The graphical part position name, type, model, properties.
                    void** pn = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The graphical part size name, type, model, properties.
                    void** sn = NULL_POINTER_STATE_CYBOI_MODEL;

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
 * Receives an x window system event.
 *
 * @param p0 the event type data (pointer reference)
 * @param p1 the event type count (pointer reference)
 * @param p2 the button mask
 * @param p3 the x mouse coordinate
 * @param p4 the y mouse coordinate
 * @param p5 the internal memory data
 */
void receive_x_window_system_event(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* y = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* x = (int*) p3;

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* b = (int*) p2;

                // The connection.
                void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The mutex.
                void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get connection.
                copy_array_forward((void*) &c, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNECTION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                // Get mutex.
                copy_array_forward((void*) &m, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

                if (m != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive x window system event.");

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

//??                fwprintf(stdout, L"TEST receive x window system e: %i\n", e);

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
                            //?? It works correctly also without conversion.
                            //?? Nothing explained in the tutorials ...
            //??                t = t & (~0x80);
                            int t_TEST = t & (~0x80);

                fwprintf(stdout, L"TEST receive x window system t_TEST: %i\n", t_TEST);

                            if (t == XCB_EXPOSE) {

                fwprintf(stdout, L"TEST receive x window system XCB_EXPOSE t: %i\n", t);

                                copy_pointer(p0, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

                                xcb_expose_event_t* ev = (xcb_expose_event_t*) e;

                                // Expose events are sensed when a window needs
                                // to be repainted, e.g. when being displayed after
                                // having been covered by another window before.

                                //?? TODO: Consider only the last in a row of multiple expose events,
                                // in order to avoid flickering of the display.
                                //?? if (ev->xexpose.count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                                //?? ... did work in xlib, but not with xcb anymore

                            } else if (t == XCB_BUTTON_PRESS) {

                fwprintf(stdout, L"TEST receive x window system XCB_BUTTON_PRESS t: %i\n", t);

                                copy_pointer(p0, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT);

                                xcb_button_press_event_t* ev = (xcb_button_press_event_t*) e;

                                if (ev != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    // Get button mask.
                                    *b = ev->state;
                                    // Get mouse coordinates.
                                    *x = ev->event_x;
                                    *y = ev->event_y;

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The button press event is null.");
                                }

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

                                //?? TODO: Move the following detection of a command into deserialiser!

                                // Determine command, depending on mouse button and event type.
                                // First, determine coordinates of the click within window-panel-sub_panel-etc.-button.
                                // Then, determine command that was assigned to button as property in cybol.
                                // Finally, send part pointed to by "command" (knowledge path) as signal to signal memory (queue).
                                sense_x_window_system_part(&cn, &cnc, &cns, &ca, &cac, &cas, &cm, &cmc, &cms, &cd, &cdc, &cds,
                                    *tmpm, *tmpmc, &(e.xbutton.x), &(e.xbutton.y), (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL,
                                    &t, &(e.xbutton.button), *k, *kc);
            */

                            } else if (t == XCB_BUTTON_RELEASE) {

                fwprintf(stdout, L"TEST receive x window system XCB_BUTTON_RELEASE t: %i\n", t);

                                copy_pointer(p0, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT);

                                xcb_button_release_event_t* ev = (xcb_button_release_event_t*) e;

                                if (ev != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    // Get button mask.
                                    *b = ev->state;
                                    // Get mouse coordinates.
                                    *x = ev->event_x;
                                    *y = ev->event_y;

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The button press event is null.");
                                }

                            } else if (t == XCB_MOTION_NOTIFY) {

                fwprintf(stdout, L"TEST receive x window system XCB_MOTION_NOTIFY t: %i\n", t);

                                copy_pointer(p0, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME_COUNT);

                                xcb_motion_notify_event_t* ev = (xcb_motion_notify_event_t*) e;

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

                            } else if (t == XCB_ENTER_NOTIFY) {

                fwprintf(stdout, L"TEST receive x window system XCB_ENTER_NOTIFY t: %i\n", t);

                                copy_pointer(p0, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

                                xcb_enter_notify_event_t* ev = (xcb_enter_notify_event_t*) e;

                                //?? an_event.xcrossing

                            } else if (XCB_LEAVE_NOTIFY) {

                fwprintf(stdout, L"TEST receive x window system XCB_LEAVE_NOTIFY t: %i\n", t);

                                copy_pointer(p0, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

                                xcb_leave_notify_event_t* ev = (xcb_leave_notify_event_t*) e;

                            } else if (t == XCB_KEY_PRESS) {

                fwprintf(stdout, L"TEST receive x window system XCB_KEY_PRESS t: %i\n", t);

                                copy_pointer(p0, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME_COUNT);

                                // Key press events relate to keyboard keys.
                                xcb_key_press_event_t* ev = (xcb_key_press_event_t*) e;

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

                            } else if (t == XCB_KEY_RELEASE) {

                fwprintf(stdout, L"TEST receive x window system XCB_KEY_RELEASE t: %i\n", t);

                                copy_pointer(p0, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME);
                                copy_pointer(p1, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME_COUNT);

                                xcb_key_release_event_t* ev = (xcb_key_release_event_t*) e;
                            }

                            // Deallocate event.
                            //
                            // CAUTION! An event gets created by the xcb library,
                            // but HAS TO BE destroyed manually here.
                            free(e);

                        } else {

                            //?? TODO: Sleep here? The event is null,
                            // so there are currently no events waiting.
                            // Don't forget to set mutex before!
                            // Reset interrupt?
                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The event is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The connection is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The mutex is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The button mask is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The x mouse coordinate is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The y mouse coordinate is null.");
    }
}

/* EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
