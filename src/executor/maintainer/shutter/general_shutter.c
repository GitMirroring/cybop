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

#ifndef GENERAL_SHUTTER_SOURCE
#define GENERAL_SHUTTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../executor/accessor/setter/internal_memory_setter.c"
#include "../../../executor/activator/service_disabler.c"
#include "../../../executor/maintainer/io_shutter.c"
#include "../../../executor/maintainer/specific_shutter.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Shuts down general things of the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the socket port (service identification)
 * @param p2 the channel
 * @param p3 the input/output base
 */
void shutdown_general(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! This log message has been commented out
    // due to the large number of potential calls caused
    // by the the number of socket services (65536).
    // See file "shutdown_manager.c".
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown general.");
    //?? fwprintf(stdout, L"Debug: Shutdown general. p2: %i\n", p2);

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p3, p1);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) DOES exist in internal memory.
        //

        //
        // Disable channel and exit sensing thread.
        //
        // CAUTION! This has to be done BEFORE deallocating resources below.
        //
        // Display:
        //
        // The sensing thread writes received events into the buffer.
        // These events have to be deallocated (freed) yet.
        //
        // Therefore, the sensing thread has to be exited FIRST
        // and then the main thread can loop the buffer and deallocate
        // all events before deallocating the buffer itself.
        //
        // Terminal:
        //
        // The main thread resets the terminal properties on shutdown, so that
        // default echoing and canonical input (with <enter> key) are reactivated.
        // But then, the call of function "ioctl" might not work promptly,
        // if the terminal is waiting for the <enter> key.
        //
        // Therefore, the sensing thread has to be exited FIRST
        // as long as ioctl fake input can be received prompt.
        //
        disable_service(p0, p3, p1, p2);
        // Execute channel-specific shutdown functions.
        shutdown_specific(io, p2);
        // Shutdown input/output entry.
        shutdown_io(io);
        //
        // Deallocate input/output entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &io, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) IO_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Reset input/output entry in internal memory.
        //
        // CAUTION! It is ESSENTIAL to assign NULL here,
        // since cyboi tests for null pointers and otherwise,
        // wild pointers would lead to memory corruption.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the internal memory array's count and size are CONSTANT.
        //
        // CAUTION! Hand over null as pointer reference NULL_POINTER_STATE_CYBOI_MODEL
        // and NOT as dereferenced pointer *NULL_POINTER_STATE_CYBOI_MODEL.
        //
        // CAUTION! Place this function BELOW the call of function "disable_channel" above,
        // since that is accessing the input/output entry inside, in order to exit the thread.
        //
        set_internal_memory_element(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, p3, p1);

    } else {

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown general. The input/output entry value is null, i.e. it does not exist in internal memory.");
        // fwprintf(stdout, L"Warning: Could not shutdown general. The input/output entry value is null, i.e. it does not exist in internal memory.\n");
    }
}

/* GENERAL_SHUTTER_SOURCE */
#endif
