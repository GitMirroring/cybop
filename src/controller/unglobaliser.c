/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNGLOBALISER_SOURCE
#define UNGLOBALISER_SOURCE

#include "../controller/unglobaliser/compound_unglobaliser.c"
#include "../controller/unglobaliser/conversion_unglobaliser.c"
#include "../controller/unglobaliser/display_unglobaliser.c"
#include "../controller/unglobaliser/integral_unglobaliser.c"
#include "../controller/unglobaliser/log_unglobaliser.c"
#include "../controller/unglobaliser/pointer_unglobaliser.c"
#include "../controller/unglobaliser/process_unglobaliser.c"
#include "../controller/unglobaliser/real_unglobaliser.c"
#include "../controller/unglobaliser/reallocation_factor_unglobaliser.c"
#include "../controller/unglobaliser/service_exit_unglobaliser.c"
#include "../controller/unglobaliser/signal_unglobaliser.c"
#include "../controller/unglobaliser/socket_unglobaliser.c"
#include "../controller/unglobaliser/thread_unglobaliser.c"
#include "../controller/unglobaliser/thread_identification_unglobaliser.c"

/**
 * Deallocates global variables.
 */
void unglobalise() {

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    unglobalise_compound();
    unglobalise_conversion();
    unglobalise_display();
    unglobalise_integral();
    unglobalise_log();
    unglobalise_pointer();
    unglobalise_process();
    unglobalise_real();
    unglobalise_reallocation_factor();
    unglobalise_service_exit();
    unglobalise_signal();
    unglobalise_socket();
    unglobalise_thread();
    unglobalise_thread_identification();
}

/* UNGLOBALISER_SOURCE */
#endif
