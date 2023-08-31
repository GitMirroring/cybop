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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "client.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deallocates the internal memory.
 *
 * @param p0 the internal memory (pointer reference)
 */
void deallocate_internal_memory(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate internal memory.");
        //?? fwprintf(stdout, L"Debug: Deallocate internal memory. p0: %i\n", p0);

        //
        // Declaration
        //

        // The knowledge memory part.
        void* mk = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The stack memory part.
        void* mst = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The signal (event) memory part.
        void* ms = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The interrupt pipe.
        void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The interrupt mutex.
        void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The interrupt identification.
        void* ii = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The display input output entry.
        void* iod = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The file input output entry.
        void* iof = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The fifo pipeline input output entry.
        void* iop = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The serial input output entry.
        void* ios = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The socket input output entry.
        void* ioso = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The terminal input output entry.
        void* iot = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieval
        //

        // Get knowledge memory from internal memory.
        copy_array_forward((void*) &mk, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get stack memory from internal memory.
        copy_array_forward((void*) &mst, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get signal memory from internal memory.
        copy_array_forward((void*) &ms, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        // Get interrupt pipe from internal memory.
        copy_array_forward((void*) &ip, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get interrupt mutex from internal memory.
        copy_array_forward((void*) &im, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get interrupt identification from internal memory.
        copy_array_forward((void*) &ii, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        // Get display input output entry from internal memory.
        copy_array_forward((void*) &iod, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DISPLAY_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get file input output entry from internal memory.
        copy_array_forward((void*) &iof, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get fifo pipeline input output entry from internal memory.
        copy_array_forward((void*) &iop, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FIFO_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get serial input output entry from internal memory.
        copy_array_forward((void*) &ios, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERIAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get socket input output entry from internal memory.
        copy_array_forward((void*) &ioso, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOCKET_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get terminal input output entry from internal memory.
        copy_array_forward((void*) &iot, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        //
        // Deallocation
        //

        //
        // CAUTION! It is ESSENTIAL to deallocate resources in the
        // REVERSE ORDER as compared to allocation at startup.
        //
        // The input/output threads of client- and server entry lists
        // have to be exited BEFORE deallocating memory resources
        // since otherwise, memory errors would occur.
        // This is because threads access the interrupt pipe
        // and also knowledge memory resources.
        //
        // Therefore, deallocate resources in this order:
        // - input output (including threads)
        // - interrupt
        // - memory
        //
        // The reallocation of a non-existing array would lead to the error
        // "realloc(): invalid pointer".
        //

        // Deallocate display input output entry.
        deallocate_input_output_entry((void*) &iod, (void*) DISPLAY_CYBOI_CHANNEL, *i);
        // Deallocate file input output entry.
        deallocate_input_output_entry((void*) &iof, (void*) FILE_CYBOI_CHANNEL, *i);
        // Deallocate fifo pipeline input output entry.
        deallocate_input_output_entry((void*) &iop, (void*) FIFO_CYBOI_CHANNEL, *i);
        // Deallocate serial input output entry.
        deallocate_input_output_entry((void*) &ios, (void*) SERIAL_CYBOI_CHANNEL, *i);
        // Deallocate socket input output entry.
        deallocate_input_output_entry((void*) &ioso, (void*) SOCKET_CYBOI_CHANNEL, *i);
        // Deallocate terminal input output entry.
        deallocate_input_output_entry((void*) &iot, (void*) TERMINAL_CYBOI_CHANNEL, *i);

        //
        // Finalisation
        //

        //
        // Close interrupt pipe.
        //
        // CAUTION! Normally, this pipe finalisation and closing
        // would be done before deallocation. However, as an exception,
        // the input output entries of all CHANNELS have to get
        // deallocated yet BEFORE closing this interrupt pipe.
        //
        // The input output THREADS access the interrupt pipe,
        // so that they have to EXIT first since otherwise,
        // memory errors would occur.
        //
        close_pipe(ip);

        //
        // Deallocate interrupt pipe.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        // CAUTION! The size is TWO, since the pipe contains two file descriptors.
        //
        deallocate_array((void*) &ip, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate interrupt mutex.
        deallocate_mutex((void*) &im);
        //
        // Deallocate interrupt identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &ii, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Deallocate knowledge memory part.
        //
        // CAUTION! This is the knowledge memory tree root node.
        // It has to be deallocated MANUALLY here.
        //
        // Its REFERENCES COUNT was initially zero and never
        // got changed during programme execution, so that
        // this root part is NOT deallocated automatically.
        //
        deallocate_part((void*) &mk);
        // Deallocate stack memory part.
        deallocate_part((void*) &mst);
        // Deallocate signal memory part.
        deallocate_part((void*) &ms);

        //
        // Deallocate internal memory data.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        // CAUTION! The parts within internal memory should NOT be
        // considered for that, only those in knowledge memory.
        //
        deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate internal memory. The internal memory is null.");
        fwprintf(stdout, L"Error: Could not deallocate internal memory. The internal memory is null. p0: %i\n", p0);
    }
}
