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

#ifndef CLIENT_STARTER_SOURCE
#define CLIENT_STARTER_SOURCE

#include <threads.h> // mtx_t, mtx_init, thrd_error

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/copier/pointer_copier.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../logger/logger.c"
#include "../../variable/symbolic_name/mutex_thread_symbolic_name.c"

/**
 * Allocates the client entry content.
 *
 * @param p0 the client entry
 * @param p1 the interrupt pipe (pointer reference)
 * @param p2 the interrupt mutex (pointer reference)
 * @param p3 the input/output identification (pointer reference, input/output base + socket port)
 * @param p4 the client identification
 * @param p5 the thread function (pointer reference)
 * @param p6 the function argument (pointer reference)
 */
void startup_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup client.");
    fwprintf(stdout, L"Debug: Startup client. p0: %i\n", p0);

    //
    // Declaration.
    //

    // The identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The access mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thread identification.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thread function.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The function argument.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocation.
    //

    //
    // Allocate identification.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &id, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Allocate buffer item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &b, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate access mutex.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
    //
    // Allocate thread identification.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &t, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
    //
    // Allocate thread function.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &f, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
    //
    // Allocate function argument.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &a, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
    //
    // Allocate exit flag.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &ex, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    //
    // Initialisation.
    //

    // Initialise identification.
    copy_integer(id, p4);
    // The access mutex with casted type.
    mtx_t* mt = (mtx_t*) m;
    // Initialise access mutex.
    int r = mtx_init(mt, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

    if (r == thrd_error) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The mutex object creation failed.");
        fwprintf(stdout, L"Error: Could not startup io. The mutex object creation failed. r: %i\n", r);
    }

    // Initialise thread identification.
    copy_integer(t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    //
    // Initialise thread function.
    //
    // CAUTION! Hand over function as pointer REFERENCE.
    //
    copy_pointer(f, p5);
    //
    // Initialise function argument.
    //
    // CAUTION! Hand over client entry itself, but as pointer REFERENCE.
    //
    copy_pointer(a, p6);
    // Initialise exit flag.
    copy_integer(ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Storing.
    //

    // Set identification into client entry.
    copy_array_forward(p0, (void*) &id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set buffer item into client entry.
    copy_array_forward(p0, (void*) &b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Startup client. b: %i\n", b);
    // Set access mutex into client entry.
    copy_array_forward(p0, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_MESSAGE_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set thread identification into client entry.
    copy_array_forward(p0, (void*) &t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set thread function into client entry.
    copy_array_forward(p0, (void*) &f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FUNCTION_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set function argument into client entry.
    copy_array_forward(p0, (void*) &a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ARGUMENT_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set exit flag into client entry.
    copy_array_forward(p0, (void*) &ex, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //
    // Set interrupt pipe into client entry.
    //
    // CAUTION! This reference is actually stored in internal memory.
    // However, it gets stored in client entry HERE a SECOND time,
    // in order to be able to pass it to the corresponding thread,
    // which does accept only ONE function argument.
    //
    copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PIPE_INTERRUPT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //
    // Set interrupt mutex into client entry.
    //
    // CAUTION! This reference is actually stored in internal memory.
    // However, it gets stored in client entry HERE a SECOND time,
    // in order to be able to pass it to the corresponding thread,
    // which does accept only ONE function argument.
    //
    copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_INTERRUPT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //
    // Set input/output identification (input/output base + socket port) into client entry.
    //
    // CAUTION! This reference is actually stored in input/output entry.
    // However, it gets stored in client entry HERE a SECOND time,
    // in order to be able to pass it to the corresponding thread,
    // which does accept only ONE function argument.
    //
    copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_OUTPUT_IDENTIFICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* CLIENT_STARTER_SOURCE */
#endif
