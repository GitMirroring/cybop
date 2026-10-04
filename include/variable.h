/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VARIABLE_HEADER
#define VARIABLE_HEADER

//
// symbolic name
//

#include "variable/symbolic_name/address_family_socket_symbolic_name.h"
#include "variable/symbolic_name/baudrate_serial_symbolic_name.h"
#include "variable/symbolic_name/mutex_thread_symbolic_name.h"
#include "variable/symbolic_name/protocol_family_socket_symbolic_name.h"
#include "variable/symbolic_name/protocol_socket_symbolic_name.h"
#include "variable/symbolic_name/style_socket_symbolic_name.h"

//
// type size
//

#include "variable/type_size/compound_type_size.h"
#include "variable/type_size/display_type_size.h"
#include "variable/type_size/integral_type_size.h"
#include "variable/type_size/pointer_type_size.h"
#include "variable/type_size/real_type_size.h"
#include "variable/type_size/socket_type_size.h"
#include "variable/type_size/terminal_type_size.h"
#include "variable/type_size/thread_type_size.h"

//
// general
//

#include "variable/cmake_configuration.h"
#include "variable/log_setting.h"
#include "variable/reference_counter.h"
#include "variable/thread_identification.h"

/* VARIABLE_HEADER */
#endif
