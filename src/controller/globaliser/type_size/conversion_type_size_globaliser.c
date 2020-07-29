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

#ifndef CONVERSION_TYPE_SIZE_GLOBALISER_SOURCE
#define CONVERSION_TYPE_SIZE_GLOBALISER_SOURCE

#include <wchar.h>

#include "../../../variable/type_size/conversion_type_size.c"

/**
 * Initialises conversion type size global variables.
 */
void globalise_type_size_conversion() {

    // CAUTION! Do NOT use "struct mbstate_t" but ONLY "mbstate_t".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct mbstate_t'"
    *MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE = sizeof (mbstate_t);
}

/* CONVERSION_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
