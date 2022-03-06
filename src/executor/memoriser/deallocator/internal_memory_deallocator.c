/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTERNAL_MEMORY_DEALLOCATOR_SOURCE
#define INTERNAL_MEMORY_DEALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/dispatcher/closer/basic/basic_closer.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../executor/memoriser/deallocator/input_output_entry_deallocator.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the internal memory.
 *
 * @param p0 the internal memory (pointer reference)
 */
void deallocate_internal_memory(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate internal memory.");
        fwprintf(stdout, L"Debug: Deallocate internal memory. p0: %i\n", p0);

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
        // The interrupt handler list item.
        void* ih = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The interrupt mutex.
        void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The display input output entry.
        void* iod = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The file input output entry.
        void* iof = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The pipeline input output entry.
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
        // Get interrupt handler list item from internal memory.
        copy_array_forward((void*) &ih, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLERS_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get interrupt mutex from internal memory.
        copy_array_forward((void*) &im, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        // Get display input output entry from internal memory.
        copy_array_forward((void*) &iod, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DISPLAY_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get file input output entry from internal memory.
        copy_array_forward((void*) &iof, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get pipeline input output entry from internal memory.
        copy_array_forward((void*) &iop, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPELINE_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get serial input output entry from internal memory.
        copy_array_forward((void*) &ios, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERIAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get socket input output entry from internal memory.
        copy_array_forward((void*) &ioso, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOCKET_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get terminal input output entry from internal memory.
        copy_array_forward((void*) &iot, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        //
        // Shutdown
        //

        //
        // Shutdown resources (e.g. client- and server lists).
        //
        // CAUTION! Exit ALL threads BEFORE deallocating memory resources
        // since otherwise, memory errors would occur.
        //
        // The reallocation of a non-existing array would lead to the error
        // "realloc(): invalid pointer".
        //
        // Example:
        // - the exit flag is not set
        // - the sensing child thread enters a source code block
        // - the main thread receives some shutdown cybol operation
        // - the main thread sets the exit flag only now
        // - the main thread shuts down and deallocates the destination item
        // - the sensing child thread decodes characters
        // - the sensing child thread possibly reallocates the (now non-existing) destination item
        // - this leads to memory errors such as "corrupted double-linked list"
        //
        //?? TODO
        ?? manage_shutdown(i);

        //
        // Finalisation
        //

        // The read/write interrupt pipe file descriptors.
        int rd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        int wd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Get read/write interrupt pipe file descriptors.
        copy_array_forward((void*) &rd, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        copy_array_forward((void*) &wd, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        // Close read/write interrupt pipe file descriptors.
        close_basic((void*) &rd);
        close_basic((void*) &wd);

        ?? mutex destroy

        //
        // Deallocation
        //

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
        // Deallocate interrupt pipe.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        // CAUTION! The size is TWO, since the pipe contains two file descriptors.
        //
        deallocate_array((void*) &ip, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate interrupt handler list item.
        deallocate_item((void*) &ih, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Deallocate interrupt mutex.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &im, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);

        // Deallocate display input output entry.
        deallocate_input_output_entry((void*) &iod);
        // Deallocate file input output entry.
        deallocate_input_output_entry((void*) &iof);
        // Deallocate pipelineinput output entry.
        deallocate_input_output_entry((void*) &iop);
        // Deallocate serial input output entry.
        deallocate_input_output_entry((void*) &ios);
        // Deallocate socket input output entry.
        deallocate_input_output_entry((void*) &ioso);
        // Deallocate terminal input output entry.
        deallocate_input_output_entry((void*) &iot);

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

/* INTERNAL_MEMORY_DEALLOCATOR_SOURCE */
#endif
