/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XCB_SHUTTER_SOURCE
#define XCB_SHUTTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 */
void shutdown_xcb(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown xcb.");
    fwprintf(stdout, L"Test: Shutdown xcb. p0: %i\n", p0);

    //
    // Declaration.
    //

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The graphic context.
    void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    //
    // Retrieve various values from input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Hand over values as pointer REFERENCE.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //

    // Get connexion from input/output entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get graphic context from input/output entry.
    copy_array_forward((void*) &gc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get event buffer item from input/output entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    fwprintf(stdout, L"Test: Shutdown xcb. c: %i\n", c);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        fwprintf(stdout, L"Test: Shutdown xcb. inside c: %i\n", c);

        // Cast connexion to correct type.
        xcb_connection_t* ct = (xcb_connection_t*) c;

        //
        // A display DOES exist in input/output entry.
        //

        //
        // Finalisation.
        //

        //
        // CAUTION! Resetting the values is not necessary,
        // since the input/output entry gets deallocated anyway.
        //

        //
        // Deallocation.
        //

        //
        // CAUTION! Use descending order as compared to startup,
        // for the following deallocations.
        //

        // The event buffer item data, count.
        void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The event.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Get event buffer item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        fwprintf(stdout, L"Debug: Shutdown xcb. bc: %i\n", bc);
        fwprintf(stdout, L"Debug: Shutdown xcb. *bc: %i\n", *((int*) bc));

        //
        // CAUTION! Locking using a mutex is NOT necessary here anymore,
        // since the corresponding sensing thread has exited already.
        //

        // Loop event buffer and deallocate (free) all events.
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Reset comparison result.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_greater_or_equal((void*) &r, bc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
            fwprintf(stdout, L"Debug: Shutdown xcb. loop r: %i\n", r);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The buffer contains at least one event.
                //

                // Get event from event buffer.
                copy_array_forward((void*) &e, bd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                fwprintf(stdout, L"Debug: Shutdown xcb. e: %i\n", e);

                //
                // Remove event from event buffer item.
                //
                // CAUTION! Set the adjust count flag to TRUE since otherwise,
                // the destination item will hold a wrong "count" number
                // leading to unpredictable errors in further processing.
                //
                modify_item(b, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
                fwprintf(stdout, L"Debug: Shutdown xcb. after remove *bc: %i\n", *((int*) bc));

                if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
                    free(e);
                    fwprintf(stdout, L"Debug: Shutdown xcb. after free e: %i\n", e);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown xcb. The event is null.");
                    fwprintf(stdout, L"Error: Could not shutdown xcb. The event is null. e: %i\n", e);
                }

            } else {

                //
                // The event buffer is empty.
                //

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown xcb. The event buffer is empty.");
                fwprintf(stdout, L"Debug: Shutdown xcb. The event buffer is empty. *bc: %i\n", *((int*) bc));

                break;
            }
        }

        fwprintf(stdout, L"Debug: Shutdown xcb. gc: %i\n", gc);

        if (gc != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Test: Shutdown xcb. inside gc: %i\n", gc);

            //
            // Cast graphic context to integer.
            //
            // CAUTION! The graphic context is defined as:
            // typedef uint32_t xcb_gcontext_t;
            //
            // CAUTION! Dereference value ONLY VIA uint32_t
            // and do NOT dereference xcb_gcontext_t value directly
            // as shown in the following example, since it is
            // leading to a memory segmentation fault:
            //
            // xcb_gcontext_t* gct = (xcb_gcontext_t*) gc;
            // ... *gct ...
            //
            uint32_t* gci = (uint32_t*) gc;
            fwprintf(stdout, L"Test: Shutdown xcb. gci: %i\n", gci);
            fwprintf(stdout, L"Test: Shutdown xcb. *gci: %i\n", *gci);
            // Cast graphic context to correct type.
            xcb_gcontext_t gct = (xcb_gcontext_t) *gci;
            fwprintf(stdout, L"Test: Shutdown xcb. free gct: %i\n", gct);
            // Free graphic context.
            xcb_free_gc(ct, gct);
            fwprintf(stdout, L"Test: Shutdown xcb. post free gct: %i\n", gct);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown xcb. The graphic context is null.");
            fwprintf(stdout, L"Warning: Could not shutdown xcb. The graphic context is null. gc: %i\n", gc);
        }

        // Deallocate event buffer item.
        deallocate_item((void*) &b, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Deallocate graphic context.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &gc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // CAUTION! Do NOT deallocate the screen manually here.
        // It was retrieved via the connexion and gets
        // deallocated automatically via the connexion below.
        //

        fwprintf(stdout, L"Test: Shutdown xcb. disconnect ct: %i\n", ct);

        //
        // Close connexion.
        //
        // CAUTION! Do NOT deallocate the connexion manually here.
        // Nothing was allocated for the connexion at startup either.
        // The called function closes the file descriptor and
        // frees ALL memory associated with the connexion.
        //
        xcb_disconnect(ct);

        fwprintf(stdout, L"Test: Shutdown xcb. post disconnect ct: %i\n", ct);

        //
        // CAUTION! Resetting the values is not necessary,
        // since the input/output entry gets deallocated anyway.
        //

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown xcb. The connexion is null.");
        fwprintf(stdout, L"Warning: Could not shutdown xcb. The connexion is null. c: %i\n", c);
    }
}

/* XCB_SHUTTER_SOURCE */
#endif
