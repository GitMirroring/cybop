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

#ifndef ITEM_ALLOCATOR_SOURCE
#define ITEM_ALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reference_counter.c"

/**
 * Allocates the item.
 *
 * @param p0 the item (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_item(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** i = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate item.");

                // The allocation size.
                int size = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

                //
                // Copy size that was handed over as argument.
                //
                // CAUTION! The following values are ONLY copied,
                // if the source value is NOT NULL.
                // This is tested inside the "copy_integer" function.
                // Otherwise, the destination value remains as is.
                //
                copy_integer((void*) &size, p1);

                if (size >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (size == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        //
                        // The given size is ZERO.
                        //
                        // CAUTION! This may be REGULAR data with EMPTY model, for example:
                        //
                        // <node name="exit_application" channel="inline" format="live/exit" model=""/>
                        // <node name="command_or_event" channel="inline" format="text/plain" model=""/>
                        // <node name="some_string" channel="inline" format="text/plain" model=""/>
                        //
                        // Assign the value of ONE as DEFAULT, since in memory allocation handling,
                        // the size MUST NOT be negative or zero, but have at least a value of ONE.
                        //

                        // Copy one as default value.
                        copy_integer((void*) &size, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                    }

                    // The data, count, size.
                    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

                    //
                    // Allocate data, count, size.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    allocate_array((void*) &d, (void*) &size, p2);

                    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        //
                        // Allocate count, size.
                        //
                        // CAUTION! Due to memory allocation handling, the size MUST NOT
                        // be negative or zero, but have at least a value of ONE.
                        //
                        allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
                        allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

                        //
                        // Initialise count, size.
                        //
                        // CAUTION! The data does NOT have to be initialised and remains empty.
                        // The count is set to zero, since the data does not contain any elements yet.
                        // The size is set to the value that was assigned further above.
                        //
                        copy_integer(c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                        copy_integer(s, (void*) &size);

                        // Allocate item.
                        allocate_array(p0, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

                        // Set data, count, size.
                        copy_array_forward(*i, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                        copy_array_forward(*i, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COUNT_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                        copy_array_forward(*i, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SIZE_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                    } else {

                        //
                        // Reasons might be:
                        // - given size is zero
                        // - given size is negative
                        // - no more system heap memory
                        //
                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The data is null.");
                        fwprintf(stdout, L"Error: Could not allocate item. The data is null. data d: %i\n", d);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The given size is negative which should NEVER happen.");
                    fwprintf(stdout, L"Error: Could not allocate item. The given size is negative which should NEVER happen. size: %i\n", size);
                }

                //
                // Increment item reference counter.
                //
                // CAUTION! This is ONLY needed for debugging.
                //
                // CAUTION! Do NOT place this counter inside the data array block above
                // since otherwise, it might not get incremented if the data array does
                // not get allocated which may happen sometimes for whatever reason.
                // But since this counter gets decremented ANYWAY when
                // deallocating the item, this would result in DIFFERENT values,
                // even THOUGH all memory is FINE, even when checking with valgrind.
                //
                (*ITEM_REFERENCE_COUNTER)++;

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The item is null.");
                fwprintf(stdout, L"Error: Could not allocate item. The item is null. item p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The size is null.");
            fwprintf(stdout, L"Error: Could not allocate item. The size is null. size p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The type is null.");
        fwprintf(stdout, L"Error: Could not allocate item. The type is null. type p2: %i\n", p2);
    }
}

/* ITEM_ALLOCATOR_SOURCE */
#endif
