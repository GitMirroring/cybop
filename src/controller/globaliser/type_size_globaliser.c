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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "controller.h"

/**
 * Initialises symbolic name (pre-processor-defined) global variables.
 */
void globalise_type_size() {

    //
    // Terminal.
    //

    globalise_type_size_display();
    globalise_type_size_integral();
    globalise_type_size_pointer();
    globalise_type_size_real();
    //
    // CAUTION! The integral type sizes have to be determined
    // BEFORE those following, since the former are used to calculate sizes.
    //
    globalise_type_size_socket();
    globalise_type_size_terminal();
    globalise_type_size_thread();

    //
    // CAUTION! The order of above function calls is arbitrary,
    // since most use the "sizeof" function and are independent
    // from each other.
    // However, the "globalise_type_size_compound" function depends upon
    // other type sizes, so that it can only be called AS LAST.
    //
    globalise_type_size_compound();
}
