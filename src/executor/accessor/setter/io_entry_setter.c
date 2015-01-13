/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef IO_ENTRY_SETTER_SOURCE
#define IO_ENTRY_SETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../executor/calculator/basic/pointer/add_pointer_calculator.c"
#include "../../../executor/modifier/copier/double_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Sets the destination io entry's element at the given index.
 *
 * @param p0 the destination
 * @param p1 the source element
 * @param p2 the source index
 */
void set_io_entry_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set io entry element.");

    // The element pointer.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element pointer.
    copy_pointer((void*) &e, (void*) &p0);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.

                calculate_pointer_add((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Copy element to destination.
                copy_integer(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.

                //
                // General.
                //

                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // enable

                // Copy element to destination.
                copy_integer(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) HANDLER_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.

                //
                // General.
                //

                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // enable
                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // interrupt

                // Copy element to destination.
                //
                // CAUTION! Hand over element as POINTER REFERENCE,
                // since a pointer is copied here.
                copy_pointer((void*) e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.

                //
                // General.
                //

                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // enable
                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // interrupt
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // handler

                //?? TODO: Only needed as long as sensing threads are used. Otherwise, these may be DELETED in the future.
                calculate_pointer_add((void*) &e, (void*) MUTEX_THREAD_TYPE_SIZE); // mutex
                //?? TODO: Only needed as long as sensing threads are used. Otherwise, these may be DELETED in the future.
                calculate_pointer_add((void*) &e, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE); // sleep time

                //
                // Serial port.
                //

                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // file descriptor
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // original attributes

                //
                // Terminal.
                //

                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // input terminal
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // output terminal
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // original attributes
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // input mode
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // output mode

                //
                // Display.
                //

                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // event
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // window

                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // connexion xcb
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // screen xcb
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // graphic context xcb
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // font xcb
                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // colour map xcb

                calculate_pointer_add((void*) &e, (void*) POINTER_TYPE_SIZE); // device context win32

                // Copy element to destination.
                copy_integer(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set io entry element. The given source index is not known.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set io entry element. The destination io entry is null.");
    }
}

/* IO_ENTRY_SETTER_SOURCE */
#endif
