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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_GLOBALISER_SOURCE
#define X_WINDOW_SYSTEM_GLOBALISER_SOURCE

#include <X11/Xlib.h>

#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/x_window_system_type_size.c"

/**
 * Initialises x window system global variables.
 */
void globalise_x_window_system() {

    // CAUTION! Do NOT use "struct XGCValues" but ONLY "XGCValues".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct XGCValues'"
    *XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE = sizeof(XGCValues);
}

/* X_WINDOW_SYSTEM_GLOBALISER_SOURCE */
#endif
