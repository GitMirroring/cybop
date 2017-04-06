/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_MANAGER_SOURCE
#define INTERNAL_MEMORY_MANAGER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Starts up the internal memory.
 *
 * CAUTION! The internal memory items have a fixed position,
 * determined by constants. The items HAVE TO be assigned an
 * initial value, since all source code relies on them.
 *
 * Most values are compared against the *NULL_POINTER_STATE_CYBOI_MODEL constant
 * to find out whether they are set or not. If now initial values
 * would be arbitrary pointers, the programme would follow a wrong path,
 * because it would guess that an instance was properly allocated,
 * while in reality the value was just an arbitrary initial one.
 * Therefore, such values are initialised with the well-defined
 * *NULL_POINTER_STATE_CYBOI_MODEL.
 *
 * CAUTION! ONLY ONE parametre can be handed over to threads!
 * For example, the tcp socket is running in an own thread.
 * In cyboi, this one parametre is the internal memory.
 * Therefore, the knowledge memory and signal memory NEED TO BE ADDED
 * to the internal memory, in order to be forwardable to threads.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the knowledge memory part (pointer reference)
 * @param p2 the stack memory item (pointer reference)
 * @param p3 the signal memory item (pointer reference)
 * @param p4 the signal memory sleep time (pointer reference)
 * @param p5 the display enable flag (pointer reference)
 * @param p6 the display interrupt request flag (pointer reference)
 * @param p7 the display mutex (pointer reference)
 * @param p8 the display sleep time (pointer reference)
 * @param p9 the serial enable flag (pointer reference)
 * @param p10 the serial interrupt request flag (pointer reference)
 * @param p11 the serial mutex (pointer reference)
 * @param p12 the serial sleep time (pointer reference)
 * @param p13 the terminal enable flag (pointer reference)
 * @param p14 the terminal interrupt request flag (pointer reference)
 * @param p15 the terminal mutex (pointer reference)
 * @param p16 the terminal sleep time (pointer reference)
 * @param p17 the socket service enable flag (pointer reference)
 * @param p18 the socket service interrupt request flag (pointer reference)
 * @param p19 the socket service mutex (pointer reference)
 * @param p20 the socket service sleep time (pointer reference)
 */
void startup_internal_memory(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12,
    void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup internal memory.");

    //
    // Initialise all values with null.
    //

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (((void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT) == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Set null pointer at index.
        //
        // CAUTION! The "copy" (other than the "overwrite") function does
        // neither check array borders, nor extend the array's size.
        // For faster access, it was used here anyway, presuming that
        // the internal memory was allocated with correct size.
        //
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &j, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        j++;
    }

    //
    // Set special values.
    //

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Set knowledge memory internals.
    copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set stack memory internals.
    copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set signal memory internals.
    copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set signal memory sleep time.
    copy_array_forward(p0, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SLEEP_TIME_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    //
    //?? TODO: DELETE the following initialisations later,
    // as soon as the new i/o memory is used.
    //

    // Set display enable flag.
    copy_array_forward(p0, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set display interrupt request flag.
    copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set display mutex.
    copy_array_forward(p0, p7, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set display sleep time.
    copy_array_forward(p0, p8, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SLEEP_TIME_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Set serial enable flag.
    copy_array_forward(p0, p9, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENABLE_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set serial interrupt request flag.
    copy_array_forward(p0, p10, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_REQUEST_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set serial mutex.
    copy_array_forward(p0, p11, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set serial sleep time.
    copy_array_forward(p0, p12, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SLEEP_TIME_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Set terminal enable flag.
    copy_array_forward(p0, p13, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set terminal interrupt request flag.
    copy_array_forward(p0, p14, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set terminal mutex.
    copy_array_forward(p0, p15, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set terminal sleep time.
    copy_array_forward(p0, p16, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SLEEP_TIME_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    //?? The socket is NOT implemented here,
    //?? since an unpredictable number of sockets may exist.

    //
    //?? TODO: DELETE the initialisations above later,
    // as soon as the new i/o memory is used.
    //
}

/* INTERNAL_MEMORY_MANAGER_SOURCE */
#endif
