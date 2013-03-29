/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GLOBALISER_SOURCE
#define GLOBALISER_SOURCE

#include "../controller/globaliser/conversion_globaliser.c"
#include "../controller/globaliser/integral_globaliser.c"
#include "../controller/globaliser/log_globaliser.c"
#include "../controller/globaliser/pointer_globaliser.c"
#include "../controller/globaliser/process_globaliser.c"
#include "../controller/globaliser/real_globaliser.c"
#include "../controller/globaliser/reallocation_factor_globaliser.c"
#include "../controller/globaliser/reference_counter_globaliser.c"
#include "../controller/globaliser/service_exit_globaliser.c"
#include "../controller/globaliser/signal_globaliser.c"
#include "../controller/globaliser/socket_globaliser.c"
#include "../controller/globaliser/thread_globaliser.c"
#include "../controller/globaliser/thread_identification_globaliser.c"
#include "../controller/globaliser/x_window_system_globaliser.c"

/**
 * Allocates and initialises global variables.
 */
void globalise() {

    //
    // CAUTION! These global variables are initialised here,
    // because not all of them represent primitive values.
    //
    // The latter might be assigned using {} right at definition, e.g.:
    // static int LOG_LEVEL_ARRAY[] = {0};
    // static int* LOG_LEVEL = LOG_LEVEL_ARRAY;
    //
    // But there are also other types like pthread_t or FILE,
    // for which only an array variable using a size was defined,
    // because initial values are more complex and should be
    // initialised here.
    //

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    //
    // CAUTION! The glibc manual states that the data type of the result
    // of the "sizeof" function may vary between compilers.
    // It therefore recommends to use type "size_t" (instead of "int")
    // as the preferred way to declare any arguments or variables
    // that hold the size of an object.
    //
    // See:
    // http://www.gnu.org/software/libtool/manual/libc/Important-Data-Types.html#Important-Data-Types
    //
    // However, cyboi assigns the sizes of all primitive types to special
    // global integer variables at system startup, in module "globaliser.c".
    // As long as these global integer variables are used, there is
    // no need to work with type "sizt_t" in cyboi source code.
    //
    // But do NOT forget to introduce a local variable of type "size_t"
    // and to assign the value of the cyboi-internal int variable to it!
    // Otherwise, memory errors will occur and valgrind memcheck report
    // something like "Invalid read of size 8", at least on 64 Bit machines.
    // On such systems, "size_t" has a size of 8 Byte (unsigned long int),
    // whereas an "int" has the usual size of 4 Byte.
    //

    globalise_conversion();
    globalise_integral();
    globalise_log();
    globalise_pointer();
    globalise_process();
    globalise_real();
    globalise_reallocation_factor();
    globalise_service_exit();
    globalise_signal();
    globalise_socket();
    globalise_thread();
    globalise_thread_identification();
    globalise_x_window_system();
    globalise_reference_counter();
}

/* GLOBALISER_SOURCE */
#endif
