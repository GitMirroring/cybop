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
// accessor
//

#include "../../executor/accessor/counter/array_counter.c"
#include "../../executor/accessor/counter/item_counter.c"
#include "../../executor/accessor/counter/part_counter.c"

#include "../../executor/accessor/getter/complex_getter.c"
#include "../../executor/accessor/getter/datetime_getter.c"
#include "../../executor/accessor/getter/duration_getter.c"
#include "../../executor/accessor/getter/fraction_getter.c"
#include "../../executor/accessor/getter/getter.c"
#include "../../executor/accessor/getter/item_getter.c"
#include "../../executor/accessor/getter/part/index_part_getter.c"
#include "../../executor/accessor/getter/part/knowledge_part_getter.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/getter/part_getter.c"
#include "../../executor/accessor/getter/terminal_mode/terminal_mode_getter.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/accessor/getter/terminal_mode/unix_terminal_mode_getter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/accessor/getter/terminal_mode/unix_terminal_mode_getter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/accessor/getter/terminal_mode/win32_console_mode_getter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../executor/accessor/indicator/item_indicator.c"
#include "../../executor/accessor/indicator/part_indicator.c"

#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/accessor/name_getter/item_name_getter.c"
#include "../../executor/accessor/name_getter/part_name_getter.c"

#include "../../executor/accessor/setter/complex_setter.c"
#include "../../executor/accessor/setter/datetime_setter.c"
#include "../../executor/accessor/setter/duration_setter.c"
#include "../../executor/accessor/setter/fraction_setter.c"
#include "../../executor/accessor/setter/item_setter.c"
#include "../../executor/accessor/setter/part_setter.c"
#include "../../executor/accessor/setter/socket_address/inet6_socket_address_setter.c"
#include "../../executor/accessor/setter/socket_address/inet_socket_address_setter.c"
#include "../../executor/accessor/setter/socket_address/local_socket_address_setter.c"
#include "../../executor/accessor/setter/terminal_mode/terminal_mode_setter.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/accessor/setter/terminal_mode/unix_terminal_mode_setter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/accessor/setter/terminal_mode/unix_terminal_mode_setter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/accessor/setter/terminal_mode/win32_console_mode_setter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// copier
//

#include "../../executor/copier/array/backward_array_copier.c"
#include "../../executor/copier/array/backward_elements_array_copier.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/copier/array/forward_elements_array_copier.c"

#include "../../executor/copier/character_copier.c"

#include "../../executor/copier/complex_copier.c"

#include "../../executor/copier/copier.c"

#include "../../executor/copier/datetime_copier.c"

#include "../../executor/copier/double_copier.c"

#include "../../executor/copier/duration_copier.c"

#include "../../executor/copier/fraction_copier.c"

#include "../../executor/copier/integer_copier.c"
#include "../../executor/copier/integer_from_character_integer_copier.c"

#include "../../executor/copier/offset_copier.c"

#include "../../executor/copier/part_copier.c"

#include "../../executor/copier/pointer_copier.c"

#include "../../executor/copier/terminal_mode/terminal_mode_copier.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/copier/terminal_mode/unix_terminal_mode_copier.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/copier/terminal_mode/unix_terminal_mode_copier.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/copier/terminal_mode/win32_console_mode_copier.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../executor/copier/thread_identification_copier.c"

#include "../../executor/copier/wide_character_copier.c"

//
// memoriser
//

#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../executor/memoriser/allocator/client_entry_allocator.c"
#include "../../executor/memoriser/allocator/input_output_entry_allocator.c"
#include "../../executor/memoriser/allocator/internal_memory_allocator.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/allocator/mutex_allocator.c"
#include "../../executor/memoriser/allocator/part_allocator.c"
#include "../../executor/memoriser/allocator/server_entry_allocator.c"
#include "../../executor/memoriser/allocator/socket_address/inet6_socket_address_allocator.c"
#include "../../executor/memoriser/allocator/socket_address/inet_socket_address_allocator.c"
#include "../../executor/memoriser/allocator/socket_address/local_socket_address_allocator.c"
#include "../../executor/memoriser/allocator/socket_address/socket_address_allocator.c"
#include "../../executor/memoriser/allocator/terminal_mode_allocator.c"

#include "../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../executor/memoriser/deallocator/client_entry_deallocator.c"
#include "../../executor/memoriser/deallocator/input_output_entry_deallocator.c"
#include "../../executor/memoriser/deallocator/internal_memory_deallocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../executor/memoriser/deallocator/mutex_deallocator.c"
#include "../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../executor/memoriser/deallocator/server_entry_deallocator.c"
#include "../../executor/memoriser/deallocator/socket_address_deallocator.c"
#include "../../executor/memoriser/deallocator/terminal_mode_deallocator.c"

#include "../../executor/memoriser/offset_adder.c"

#include "../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../executor/memoriser/reallocator/item_reallocator.c"

//
// modifier
//

#include "../../executor/modifier/appender/part_appender.c"
#include "../../executor/modifier/appender/wide_character_from_character_part_appender.c"

#include "../../executor/modifier/filler/filler.c"

#include "../../executor/modifier/inserter/inserter.c"
#include "../../executor/modifier/inserter/inside_inserter.c"

#include "../../executor/modifier/lowercaser/item_lowercaser.c"
#include "../../executor/modifier/lowercaser/letter_lowercaser.c"
#include "../../executor/modifier/lowercaser/lowercaser.c"
#include "../../executor/modifier/lowercaser/string_lowercaser.c"

#include "../../executor/modifier/normaliser/item_normaliser.c"
#include "../../executor/modifier/normaliser/normaliser.c"
#include "../../executor/modifier/normaliser/reference_normaliser.c"
#include "../../executor/modifier/normaliser/search_normaliser.c"
#include "../../executor/modifier/normaliser/string_normaliser.c"
#include "../../executor/modifier/normaliser/type_normaliser.c"
#include "../../executor/modifier/normaliser/whitespace_normaliser.c"

#include "../../executor/modifier/overwriter/integer_from_character_overwriter.c"
#include "../../executor/modifier/overwriter/overwriter.c"
#include "../../executor/modifier/overwriter/wide_character_from_character_overwriter.c"

#include "../../executor/modifier/remover/inside_remover.c"
#include "../../executor/modifier/remover/remover.c"

#include "../../executor/modifier/repeater/item_repeater.c"
#include "../../executor/modifier/repeater/repeater.c"
#include "../../executor/modifier/repeater/string_repeater.c"

#include "../../executor/modifier/replacer/item_replacer.c"
#include "../../executor/modifier/replacer/reference_replacer.c"
#include "../../executor/modifier/replacer/replacer.c"
#include "../../executor/modifier/replacer/sequence_replacer.c"
#include "../../executor/modifier/replacer/string_replacer.c"

#include "../../executor/modifier/reverser/item_reverser.c"
#include "../../executor/modifier/reverser/reverser.c"
#include "../../executor/modifier/reverser/string_reverser.c"

#include "../../executor/modifier/shuffler/shuffler.c"

#include "../../executor/modifier/stripper/item_leading_stripper.c"
#include "../../executor/modifier/stripper/item_trailing_stripper.c"
#include "../../executor/modifier/stripper/leading_stripper.c"
#include "../../executor/modifier/stripper/string_leading_stripper.c"
#include "../../executor/modifier/stripper/string_trailing_stripper.c"
#include "../../executor/modifier/stripper/stripper.c"
#include "../../executor/modifier/stripper/trailing_stripper.c"

#include "../../executor/modifier/uppercaser/item_uppercaser.c"
#include "../../executor/modifier/uppercaser/letter_uppercaser.c"
#include "../../executor/modifier/uppercaser/string_uppercaser.c"
#include "../../executor/modifier/uppercaser/uppercaser.c"

#include "../../executor/modifier/array_modifier.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../executor/modifier/part_modifier.c"
#include "../../executor/modifier/verify_modifier.c"

//
// referencer
//

#include "../../executor/referencer/array_referencer.c"
#include "../../executor/referencer/elements_array_referencer.c"
#include "../../executor/referencer/part_referencer.c"
#include "../../executor/referencer/referencer.c"

//
// stacker
//

#include "../../executor/stacker/popper/part_popper.c"
#include "../../executor/stacker/popper/popper.c"

#include "../../executor/stacker/pusher/model_pusher.c"
#include "../../executor/stacker/pusher/part_pusher.c"
#include "../../executor/stacker/pusher/pusher.c"

//
// verifier
//

#include "../../executor/verifier/double_index_count_verifier.c"
#include "../../executor/verifier/index_count_verifier.c"
