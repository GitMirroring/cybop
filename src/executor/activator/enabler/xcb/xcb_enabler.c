/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XCB_ENABLER_SOURCE
#define XCB_ENABLER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/activator/enabler/xcb/buffer_xcb_enabler.c"
#include "../../../../executor/activator/enabler/xcb/client_xcb_enabler.c"
#include "../../../../executor/activator/enabler/xcb/event_xcb_enabler.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/finder/list_finder.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"
#include "../../../../logger/logger.c"

/**
 * Enables x window system event delivery via xcb.
 *
 * @param p0 the server entry
 */
void enable_xcb(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb.");
    //?? fwprintf(stdout, L"Debug: Enable xcb. server entry p0: %i\n", p0);

    //
    // Declaration
    //

    // The x window system connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client window identification.
    int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The clients list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item, mutex.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sensor handler.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get x window system connexion from server entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

    // Get next event from x window system via xcb connexion.
    enable_xcb_event((void*) &e, c);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get client window identification from event.
        enable_xcb_client((void*) &w, e);

        if (w >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Enable xcb. client window identification w: %i\n", w);

            // Get client list from server entry.
            copy_array_forward((void*) &cl, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);

            //?? fwprintf(stdout, L"Debug: Enable xcb. test server entry cl: %i\n", cl);

            // Get client entry from server clients list by device identification.
            find_list((void*) &ce, cl, (void*) &w, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

            //?? fwprintf(stdout, L"Debug: Enable xcb. test server entry ce: %i\n", ce);

            // Get input buffer item, mutex from client entry.
            copy_array_forward((void*) &bi, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
            copy_array_forward((void*) &bm, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
            // Get sensor handler from client entry.
            copy_array_forward((void*) &h, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SENSOR_HANDLER_INPUT_CLIENT_STATE_CYBOI_NAME);
            // Get internal memory from client entry.
            copy_array_forward((void*) &i, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_CLIENT_STATE_CYBOI_NAME);

            //?? fwprintf(stdout, L"Debug: Enable xcb. test server entry bi: %i\n", bi);
            //?? fwprintf(stdout, L"Debug: Enable xcb. test server entry h: %i\n", h);

            // Get interrupt pipe from internal memory.
            copy_array_forward((void*) &ip, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            // Get interrupt mutex from internal memory.
            copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

            // Get interrupt pipe write file descriptor from interrupt pipe.
            copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            //
            // Storage
            //

            compare_pointer_unequal((void*) &r, (void*) &h, NULL_POINTER_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Write event to correct client buffer.
                //
                // CAUTION! Hand over event as pointer REFERENCE.
                //
                enable_xcb_buffer(bi, (void*) &e, bm);

                // Hand over sensor handler and window id to interrupt pipe of main threaad.
                write_interrupt_pipe((void*) &ipw, (void*) &h, (void*) &w, im);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb. The handler is null.");
                fwprintf(stdout, L"Warning: Could not enable xcb. The handler is null. h: %i\n", h);

                //
                // Deallocate event.
                //
                // CAUTION! Free memory only if event is NOT null.
                //
                // CAUTION! It HAS TO BE destroyed manually here, since for:
                // - linux: it gets created automatically inside the xcb library
                // - win32: it gets created manually as message using the type MSG
                //
                // However, in BOTH CASES they are just pointers and hence
                // NOT platform-specific and therefore may get freed here.
                //
                deallocate_array((void*) &e, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
            }

        } else {

            //
            // CAUTION! There seem to be many unknown event response types,
            // so that the event is null and also the window identification is.
            // Therefore, this log message is commented out.
            //

            //?? log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb. The window identification is invalid.");
            //?? fwprintf(stdout, L"Error: Could not enable xcb. The window identification is invalid. w: %i\n", w);

            //
            // Deallocate event.
            //
            // CAUTION! Free memory only if event is NOT null.
            //
            // CAUTION! It HAS TO BE destroyed manually here, since for:
            // - linux: it gets created automatically inside the xcb library
            // - win32: it gets created manually as message using the type MSG
            //
            // However, in BOTH CASES they are just pointers and hence
            // NOT platform-specific and therefore may get freed here.
            //
            deallocate_array((void*) &e, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb. The event is null. This indicates an input/output error.");
        fwprintf(stdout, L"Error: Could not enable xcb. The event is null. This indicates an input/output error. e: %i\n", e);
    }
}

/* XCB_ENABLER_SOURCE */
#endif
