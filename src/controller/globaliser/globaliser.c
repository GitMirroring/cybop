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

#ifndef GLOBALISER_SOURCE
#define GLOBALISER_SOURCE

#include "../../controller/globaliser/log_globaliser.c"
#include "../../controller/globaliser/reference_counter_globaliser.c"
#include "../../controller/globaliser/symbolic_name_globaliser.c"
#include "../../controller/globaliser/type_size_globaliser.c"

/**
 * Allocates and initialises global variables.
 */
void globalise() {

    //?? fwprintf(stdout, L"Debug: Globalise.\n");

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    //

    //
    // CAUTION! These global variables are initialised here,
    // because not all of them represent primitive values.
    //
    // The latter might be assigned using {} right at definition, e.g.:
    // static int LOG_LEVEL_ARRAY[] = {0};
    // static int* LOG_LEVEL = LOG_LEVEL_ARRAY;
    //
    // But there are also other types like thrd_t or FILE,
    // for which only an array variable using a size was defined,
    // because initial values are more complex and should be initialised here.
    //

    globalise_symbolic_name();
    globalise_type_size();
    globalise_log();
    globalise_reference_counter();
}

/* GLOBALISER_SOURCE */
#endif
