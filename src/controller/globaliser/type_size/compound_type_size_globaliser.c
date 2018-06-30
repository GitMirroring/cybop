/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE
#define COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE

#include "../../../variable/type_size/compound_type_size.c"
#include "../../../variable/type_size/integral_type_size.c"
#include "../../../variable/type_size/pointer_type_size.c"
#include "../../../variable/type_size/real_type_size.c"

/**
 * Initialises compound type size global variables.
 */
void globalise_type_size_compound() {

    // Elements: real + imaginary
    *COMPLEX_COMPOUND_TYPE_SIZE = *DOUBLE_REAL_TYPE_SIZE + *DOUBLE_REAL_TYPE_SIZE;

    // Elements: julian day + julian second
    *DATETIME_COMPOUND_TYPE_SIZE = *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE + *DOUBLE_REAL_TYPE_SIZE;

    // Elements: value + start + end
    //
    // CAUTION! This type size depends upon DATETIME_COMPOUND_TYPE_SIZE,
    // so that it can only be defined AFTER the "datetime" size.
    *DURATION_COMPOUND_TYPE_SIZE = *DATETIME_COMPOUND_TYPE_SIZE + *DATETIME_COMPOUND_TYPE_SIZE + *DATETIME_COMPOUND_TYPE_SIZE;

    // Elements: numerator + denominator
    *FRACTION_COMPOUND_TYPE_SIZE = *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE + *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE;

    // Elements:
    *IO_ENTRY_COMPOUND_TYPE_SIZE =

        // General
          *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE // enable
        + *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE // interrupt
        + *POINTER_TYPE_SIZE // handler
        // CAUTION! The sender HAS TO BE a pointer, since it is
        // allocated as model in cybol and needs to be manipulated
        // in cyboi. A simple integer value would be lost.
        + *POINTER_TYPE_SIZE // sender
        + *POINTER_TYPE_SIZE // client list

        //?? TODO: Only needed as long as sensing threads are used. Otherwise, these may be DELETED in the future.
        + *MUTEX_THREAD_TYPE_SIZE // mutex
        //?? TODO: Only needed as long as sensing threads are used. Otherwise, these may be DELETED in the future.
        + *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE // sleep time

        //
        // Serial port.
        //

        + *POINTER_TYPE_SIZE // file descriptor
        + *POINTER_TYPE_SIZE // original attributes

        //
        // Terminal.
        //

        + *POINTER_TYPE_SIZE // input terminal
        + *POINTER_TYPE_SIZE // output terminal
        + *POINTER_TYPE_SIZE // original attributes
        + *POINTER_TYPE_SIZE // input mode
        + *POINTER_TYPE_SIZE // output mode

        //
        // Display.
        //

        + *POINTER_TYPE_SIZE // event
        + *POINTER_TYPE_SIZE // window

        + *POINTER_TYPE_SIZE // connexion xcb
        + *POINTER_TYPE_SIZE // screen xcb
        + *POINTER_TYPE_SIZE // graphic context xcb
        + *POINTER_TYPE_SIZE // font xcb
        + *POINTER_TYPE_SIZE // colour map xcb

        + *POINTER_TYPE_SIZE // device context win32

        //
        // Socket.
        //

        + *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE // socket number

        // The end.
        ;
}

/* COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
