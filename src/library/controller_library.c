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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONTROLLER_LIBRARY_SOURCE
#define CONTROLLER_LIBRARY_SOURCE

//
// controller
//

#include "../controller/checker/checker.c"
/*??
#include "../controller/checker/client/all_client_checker.c"
#include "../controller/checker/client/available_element_client_checker.c"
#include "../controller/checker/client/element_client_checker.c"
#include "../controller/checker/client/empty_element_client_checker.c"
#include "../controller/checker/client/list_client_checker.c"
*/
#include "../controller/checker/empty_checker.c"
#include "../controller/checker/found_checker.c"
/*??
#include "../controller/checker/io/accept_io_checker.c"
#include "../controller/checker/io/receive_io_checker.c"
#include "../controller/checker/io/socket_io_checker.c"
*/
#include "../controller/checker/signal_checker.c"

#include "../controller/deoptionaliser/deoptionaliser.c"
#include "../controller/deoptionaliser/log_file_deoptionaliser.c"

#include "../controller/globaliser/globaliser.c"
#include "../controller/globaliser/log_globaliser.c"
#include "../controller/globaliser/reference_counter_globaliser.c"
#include "../controller/globaliser/symbolic_name/address_family_socket_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name/baudrate_serial_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name/mutex_thread_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name/protocol_family_socket_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name/protocol_socket_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name/style_socket_symbolic_name_globaliser.c"
#include "../controller/globaliser/symbolic_name_globaliser.c"
#include "../controller/globaliser/type_size/compound_type_size_globaliser.c"
#include "../controller/globaliser/type_size/display_type_size_globaliser.c"
#include "../controller/globaliser/type_size/integral_type_size_globaliser.c"
#include "../controller/globaliser/type_size/pointer_type_size_globaliser.c"
#include "../controller/globaliser/type_size/real_type_size_globaliser.c"
#include "../controller/globaliser/type_size/socket_type_size_globaliser.c"
#include "../controller/globaliser/type_size/terminal_type_size_globaliser.c"
#include "../controller/globaliser/type_size/thread_type_size_globaliser.c"
#include "../controller/globaliser/type_size_globaliser.c"

#include "../controller/handler/element_handler.c"
#include "../controller/handler/handler.c"
#include "../controller/handler/operation_handler.c"
#include "../controller/handler/part_handler.c"

#include "../controller/helper.c"

#include "../controller/informant.c"

#include "../controller/initiator.c"

#include "../controller/manager.c"

#include "../controller/optionaliser/log_file_optionaliser.c"
#include "../controller/optionaliser/optionaliser.c"

#include "../controller/orienter.c"

#include "../controller/unglobaliser/log_unglobaliser.c"
#include "../controller/unglobaliser/unglobaliser.c"

/* CONTROLLER_LIBRARY_SOURCE */
#endif
