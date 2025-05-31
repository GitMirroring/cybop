/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMMUNICATION_HEADER
#define COMMUNICATION_HEADER

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
// communicator
//

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void receive_decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void receive_deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void receive_extract(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void receive_read(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void receive_select(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void send_compress(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18);
void send_encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void send_select(void* p0, void* p1, void* p2);
void send_serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void send_write(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

//
// converter
//

void decode(void* p0, void* p1, void* p2, void* p3);
void decode_ascii(void* p0, void* p1);
void decode_base_64(void* p0, void* p1, void* p2);
void decode_dos(void* p0, void* p1, void* p2, void* p3);
void decode_dos_437(void* p0, void* p1);
void decode_dos_850(void* p0, void* p1);
void decode_dos_character(void* p0, void* p1, void* p2);
void decode_dos_element(void* p0, void* p1, void* p2, void* p3);
void decode_dos_extension(void* p0, void* p1, void* p2);
void decode_iso_8859(void* p0, void* p1, void* p2, void* p3);
void decode_iso_8859_1(void* p0, void* p1);
void decode_iso_8859_15(void* p0, void* p1);
void decode_iso_8859_character(void* p0, void* p1, void* p2);
void decode_iso_8859_element(void* p0, void* p1, void* p2, void* p3);
void decode_iso_8859_extension(void* p0, void* p1, void* p2);
void decode_utf_16(void* p0, void* p1, void* p2);
void decode_utf_8(void* p0, void* p1, void* p2);
void decode_windows(void* p0, void* p1, void* p2, void* p3);
void decode_windows_1252(void* p0, void* p1);
void decode_windows_1252_special(void* p0, void* p1);
void decode_windows_character(void* p0, void* p1, void* p2);
void decode_windows_element(void* p0, void* p1, void* p2, void* p3);

void encode(void* p0, void* p1, void* p2, void* p3);
void encode_base_64(void* p0, void* p1, void* p2);
void encode_utf_16(void* p0, void* p1, void* p2);
void encode_utf_8(void* p0, void* p1, void* p2);

//
// packer
//

void compress(void* p0, void* p1, void* p2, void* p3);

void extract(void* p0, void* p1, void* p2, void* p3);

//
// representer
//

void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

//
// streamer
//

void read_basic(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void read_buffer(void* p0, void* p1, void* p2, void* p3);
void read_clock(void* p0);
void read_completeness(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void read_completion(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void read_count(void* p0, void* p1, void* p2);
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void read_deallocation(void* p0, void* p1, void* p2, void* p3);
void read_device(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void read_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void read_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void read_handler(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void read_inline(void* p0, void* p1, void* p2);
void read_interrupt_pipe(void* p0, void* p1, void* p2);
void read_length(void* p0, void* p1, void* p2, void* p3);
void read_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void read_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void read_signal(void* p0, void* p1, void* p2, void* p3);
void read_storage(void* p0, void* p1, void* p2, void* p3, void* p4);
void read_win32_console_message(void* p0, void* p1, void* p2, void* p3);
void read_win32_console_process(void* p0, void* p1, void* p2);
void read_win32_console_process_key(void* p0, void* p1, void* p2);
void read_win32_console_process_mouse(void* p0, void* p1, void* p2);
void read_win32_console_process_window_buffer_size(void* p0, void* p1, void* p2);
void read_win32_console_stream(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void read_winsock(void* p0, void* p1, void* p2, void* p3, void* p4);

void write_basic(void* p0, void* p1, void* p2, void* p3, void* p4);
void write_buffer(void* p0, void* p1, void* p2, void* p3, void* p4);
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void write_device(void* p0, void* p1, void* p2);
void write_display(void* p0, void* p1);
void write_entry(void* p0, void* p1, void* p2);
void write_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
int write_function(void* p0);
void write_inline(void* p0, void* p1, void* p2, void* p3, void* p4);
void write_interrupt_pipe(void* p0, void* p1, void* p2, void* p3);
void write_interrupt_pipe_exclusive(void* p0, void* p1, void* p2, void* p3);
void write_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void write_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void write_signal(void* p0, void* p1);
void write_thread(void* p0);
void write_unix_device(void* p0, void* p1, void* p2);
void write_win32_device(void* p0, void* p1, void* p2);
void write_win32_display(void* p0);
void write_winsock(void* p0, void* p1, void* p2, void* p3);
void write_xcb(void* p0, void* p1);

/* COMMUNICATION_HEADER */
#endif
