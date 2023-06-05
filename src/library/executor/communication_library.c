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

//
// communicator
//

#include "../../executor/communicator/receiver/decode_receiver.c"
#include "../../executor/communicator/receiver/deserialise_receiver.c"
#include "../../executor/communicator/receiver/extract_receiver.c"
#include "../../executor/communicator/receiver/read_receiver.c"
#include "../../executor/communicator/receiver/receiver.c"
#include "../../executor/communicator/receiver/select_receiver.c"

#include "../../executor/communicator/sender/compress_sender.c"
#include "../../executor/communicator/sender/encode_sender.c"
#include "../../executor/communicator/sender/select_sender.c"
#include "../../executor/communicator/sender/sender.c"
#include "../../executor/communicator/sender/serialise_sender.c"
#include "../../executor/communicator/sender/write_sender.c"

//
// converter
//


#include "../../executor/converter/decoder/ascii/ascii_decoder.c"
#include "../../executor/converter/decoder/base_64/base_64_decoder.c"
#include "../../executor/converter/decoder/decoder.c"
#include "../../executor/converter/decoder/dos/character_dos_decoder.c"
#include "../../executor/converter/decoder/dos/dos_437_decoder.c"
#include "../../executor/converter/decoder/dos/dos_850_decoder.c"
#include "../../executor/converter/decoder/dos/dos_decoder.c"
#include "../../executor/converter/decoder/dos/element_dos_decoder.c"
#include "../../executor/converter/decoder/dos/extension_dos_decoder.c"
#include "../../executor/converter/decoder/iso_8859/character_iso_8859_decoder.c"
#include "../../executor/converter/decoder/iso_8859/element_iso_8859_decoder.c"
#include "../../executor/converter/decoder/iso_8859/extension_iso_8859_decoder.c"
#include "../../executor/converter/decoder/iso_8859/iso_8859_15_decoder.c"
#include "../../executor/converter/decoder/iso_8859/iso_8859_1_decoder.c"
#include "../../executor/converter/decoder/iso_8859/iso_8859_decoder.c"
#include "../../executor/converter/decoder/utf/utf_16_decoder.c"
#include "../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../executor/converter/decoder/windows/character_windows_decoder.c"
#include "../../executor/converter/decoder/windows/element_windows_decoder.c"
#include "../../executor/converter/decoder/windows/special_windows_1252_decoder.c"
#include "../../executor/converter/decoder/windows/windows_1252_decoder.c"
#include "../../executor/converter/decoder/windows/windows_decoder.c"

#include "../../executor/converter/encoder/base_64/base_64_encoder.c"
#include "../../executor/converter/encoder/encoder.c"
#include "../../executor/converter/encoder/utf/utf_16_encoder.c"
#include "../../executor/converter/encoder/utf/utf_8_encoder.c"

//
// packer
//

#include "../../executor/packer/compressor.c"
#include "../../executor/packer/extractor.c"

//
// representer
//

#include "../../executor/representer/deserialiser/deserialiser.c"
#include "../../executor/representer/serialiser/serialiser.c"

//
// streamer
//

#include "../../executor/streamer/reader/basic/basic_reader.c"
#include "../../executor/streamer/reader/buffer_reader.c"
#include "../../executor/streamer/reader/clock/clock_reader.c"
#include "../../executor/streamer/reader/completeness_reader.c"
#include "../../executor/streamer/reader/completion_reader.c"
#include "../../executor/streamer/reader/count_reader.c"
#include "../../executor/streamer/reader/deallocation_reader.c"
#include "../../executor/streamer/reader/device_reader.c"
#include "../../executor/streamer/reader/flag_reader.c"
#include "../../executor/streamer/reader/fragment_reader.c"
#include "../../executor/streamer/reader/handler_reader.c"
#include "../../executor/streamer/reader/inline/inline_reader.c"
#include "../../executor/streamer/reader/interrupt_pipe/interrupt_pipe_reader.c"
#include "../../executor/streamer/reader/length_reader.c"
#include "../../executor/streamer/reader/loop_reader.c"
#include "../../executor/streamer/reader/message_reader.c"
#include "../../executor/streamer/reader/reader.c"
#include "../../executor/streamer/reader/signal/signal_reader.c"
#include "../../executor/streamer/reader/storage_reader.c"

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/streamer/reader/win32_console/key_process_win32_console_reader.c"
    #include "../../executor/streamer/reader/win32_console/message_win32_console_reader.c"
    #include "../../executor/streamer/reader/win32_console/mouse_process_win32_console_reader.c"
    #include "../../executor/streamer/reader/win32_console/process_win32_console_reader.c"
    #include "../../executor/streamer/reader/win32_console/stream_win32_console_reader.c"
    #include "../../executor/streamer/reader/win32_console/window_buffer_size_process_win32_console_reader.c"
    #include "../../executor/streamer/reader/winsock/winsock_reader.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../executor/streamer/writer/basic/basic_writer.c"
#include "../../executor/streamer/writer/buffer_writer.c"
#include "../../executor/streamer/writer/device/device_writer.c"
#include "../../executor/streamer/writer/display/display_writer.c"
#include "../../executor/streamer/writer/entry_writer.c"
#include "../../executor/streamer/writer/flag_writer.c"
#include "../../executor/streamer/writer/function_writer.c"
#include "../../executor/streamer/writer/inline/inline_writer.c"
#include "../../executor/streamer/writer/interrupt_pipe/exclusive_interrupt_pipe_writer.c"
#include "../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"
#include "../../executor/streamer/writer/loop_writer.c"
#include "../../executor/streamer/writer/message_writer.c"
#include "../../executor/streamer/writer/signal/signal_writer.c"
#include "../../executor/streamer/writer/thread_writer.c"
#include "../../executor/streamer/writer/writer.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/streamer/writer/unix_device/unix_device_writer.c"
    #include "../../executor/streamer/writer/xcb/xcb_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/streamer/writer/unix_device/unix_device_writer.c"
    #include "../../executor/streamer/writer/xcb/xcb_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/streamer/writer/win32_device/win32_device_writer.c"
    #include "../../executor/streamer/writer/win32_display/win32_display_writer.c"
    #include "../../executor/streamer/writer/winsock/winsock_writer.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
