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

#ifndef KNOWLEDGE_HEADER
#define KNOWLEDGE_HEADER

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// accessor
//

void count_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void count_array_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void count_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void count_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void get(void* p0, void* p1, void* p2);
void get_complex_element(void* p0, void* p1, void* p2);
void get_console_mode_win32(void* p0, void* p1);
void get_datetime_element(void* p0, void* p1, void* p2);
void get_duration_element(void* p0, void* p1, void* p2);
void get_fraction_element(void* p0, void* p1, void* p2);
void get_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void get_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void get_part_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void get_part_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4);
void get_part_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void get_terminal_mode(void* p0, void* p1);
void get_terminal_mode_unix(void* p0, void* p1);

void indicate_item(void* p0, void* p1, void* p2);
void indicate_part(void* p0, void* p1, void* p2);

void get_name_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void get_name_item(void* p0, void* p1, void* p2, void* p3);
void get_name_item_element(void* p0, void* p1, void* p2, void* p3, void* p4);
void get_name_part(void* p0, void* p1, void* p2, void* p3);
void get_name_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void set_complex_element(void* p0, void* p1, void* p2);
void set_datetime_element(void* p0, void* p1, void* p2);
void set_duration_element(void* p0, void* p1, void* p2);
void set_fraction_element(void* p0, void* p1, void* p2);
void set_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void set_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void set_socket_address_inet(void* p0, void* p1, void* p2);
void set_socket_address_inet6(void* p0, void* p1, void* p2);
void set_socket_address_local(void* p0, void* p1, void* p2);
void set_terminal_mode(void* p0, void* p1);
void set_unix_terminal_mode(void* p0, void* p1);
void set_win32_console_mode(void* p0, void* p1);

//
// copier
//

void copy(void* p0, void* p1, void* p2, void* p3);

void copy_array_backward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void copy_array_elements_backward(void* p0, void* p1, void* p2, void* p3, void* p4);
void copy_array_elements_forward(void* p0, void* p1, void* p2, void* p3, void* p4);
void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void copy_character(void* p0, void* p1);
void copy_complex(void* p0, void* p1);
void copy_console_mode_win32(void* p0, void* p1);
void copy_datetime(void* p0, void* p1);
void copy_double(void* p0, void* p1);
void copy_duration(void* p0, void* p1);
void copy_fraction(void* p0, void* p1);
void copy_integer(void* p0, void* p1);
void copy_integer_integer_from_character(void* p0, void* p1, void* p2);
void copy_offset(void* p0, void* p1, void* p2, void* p3, void* p4);
void copy_part(void* p0, void* p1);
void copy_pointer(void* p0, void* p1);

void copy_terminal_mode(void* p0, void* p1);
void copy_terminal_mode_unix(void* p0, void* p1);

void copy_thread_identification(void* p0, void* p1);
void copy_wide_character(void* p0, void* p1);

//
// memoriser
//

void add_offset(void* p0, void* p1, void* p2);

void allocate_array(void* p0, void* p1, void* p2);
void allocate_client_entry(void* p0, void* p1);
void allocate_input_output_entry(void* p0);
void allocate_internal_memory(void* p0);
void allocate_item(void* p0, void* p1, void* p2);
void allocate_mutex(void* p0);
void allocate_part(void* p0, void* p1, void* p2);
void allocate_server_entry(void* p0);
void allocate_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void allocate_socket_address_inet(void* p0, void* p1, void* p2, void* p3, void* p4);
void allocate_socket_address_inet6(void* p0, void* p1, void* p2, void* p3, void* p4);
void allocate_socket_address_local(void* p0, void* p1, void* p2, void* p3);
void allocate_terminal_mode(void* p0);

void deallocate_array(void* p0, void* p1, void* p2, void* p3);
void deallocate_client_entry(void* p0, void* p1);
void deallocate_input_output_entry(void* p0, void* p1, void* p2);
void deallocate_internal_memory(void* p0);
void deallocate_item(void* p0, void* p1);
void deallocate_mutex(void* p0);
void deallocate_part(void* p0);
void deallocate_server_entry(void* p0);
void deallocate_socket_address(void* p0, void* p1, void* p2);
void deallocate_terminal_mode(void* p0);

void reallocate_array(void* p0, void* p1, void* p2, void* p3);
void reallocate_item(void* p0, void* p1, void* p2);

//
// modifier
//

void append_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void append_part_wide_character_from_character(void* p0, void* p1, void* p2, void* p3, void* p4);

void fill(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

void insert(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void insert_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

void lower(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void lower_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void lower_letter(void* p0, void* p1);
void lower_string(void* p0, void* p1, void* p2);

void modify_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void modify_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void modify_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void modify_verify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void normalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void normalise_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void normalise_reference(void* p0, void* p1, void* p2);
void normalise_search(void* p0, void* p1, void* p2);
void normalise_string(void* p0, void* p1, void* p2);
void normalise_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void normalise_whitespace(void* p0, void* p1, void* p2);

void overwrite(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void overwrite_integer_from_character(void* p0, void* p1, void* p2);
void overwrite_wide_character_from_character(void* p0, void* p1, void* p2);

void remove_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void remove_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void repeat(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void repeat_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void repeat_string(void* p0, void* p1, void* p2, void* p3);

void replace(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void replace_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void replace_reference(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void replace_sequence(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void replace_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void reverse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void reverse_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void reverse_string(void* p0, void* p1, void* p2);

void strip(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void strip_leading(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void strip_leading_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void strip_leading_string(void* p0, void* p1, void* p2);
void strip_trailing(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void strip_trailing_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void strip_trailing_string(void* p0, void* p1, void* p2);

void upper(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void upper_item(void* p0, void* p1, void* p2, void* p3, void* p4);
void upper_letter(void* p0, void* p1);
void upper_string(void* p0, void* p1, void* p2);

//
// referencer
//

void reference(void* p0, void* p1, void* p2, void* p3, void* p4);
void reference_array(void* p0, void* p1, void* p2, void* p3, void* p4);
void reference_array_elements(void* p0, void* p1, void* p2);
void reference_part(void* p0, void* p1, void* p2);

//
// stacker
//

void pop(void* p0, void* p1);
void pop_part(void* p0, void* p1, void* p2);
void push(void* p0, void* p1, void* p2, void* p3, void* p4);
void push_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void push_part(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// verifier
//

void verify_double_index_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void verify_index_count(void* p0, void* p1, void* p2, void* p3);

/* KNOWLEDGE_HEADER */
#endif
