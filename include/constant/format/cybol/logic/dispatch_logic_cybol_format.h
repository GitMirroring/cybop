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

#ifndef DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// Dispatch
//
// IANA media type: not defined
// Self-defined media type: dispatch
// This media type is a CYBOL extension.
//

/**
 * The dispatch/close logic cybol format.
 *
 * Description:
 *
 * Closes down a client resource that has been used for connecting to a device or service on the given channel.
 *
 * Examples:
 *
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <node name="close_stdout" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".app.stdout"/>
 * </node>
 *
 * <node name="handle_close" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".client_socket"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It is used for example for a window or client socket stub. If null, the default is false (standalone client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode. If null, the default is zero.
 * - identification (required) [text/cybol-path]: The file descriptor or client socket number or window id returned from cyboi when opening the resource.
 */
static wchar_t* CLOSE_DISPATCH_LOGIC_CYBOL_FORMAT = L"dispatch/close";
static int* CLOSE_DISPATCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dispatch/open logic cybol format.
 *
 * Description:
 *
 * Opens up a client resource for connecting to a device or service on the given channel.
 *
 * Examples:
 *
 * <node name="open_file_in_read_mode" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="app/config.cybol"/>
 * </node>
 *
 * <node name="open_file_in_write_mode" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="knowledge_tree_test.txt"/>
 *     <node name="mode" channel="inline" format="text/plain" model="write"/>
 * </node>
 *
 * <node name="open_stdout" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="device" channel="inline" format="text/plain" model="standard-output"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".stdout"/>
 * </node>
 *
 * <node name="open_stdin" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="device" channel="inline" format="text/plain" model="standard-input"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".var.stdin"/>
 * </node>
 *
 * <node name="open_serial_port" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="serial"/>
 *     <node name="filename" channel="inline" format="text/plain" model="/dev/ttyACM0"/>
 *     <node name="baudrate" channel="inline" format="number/integer" model="115200"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".dev.serial_0"/>
 * </node>
 *
 * <node name="open_fifo_named_pipe" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="fifo"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="app/special_file"/>
 *     <node name="mode" channel="inline" format="text/plain" model="write"/>
 * </node>
 *
 * <node name="open_serverside_client_socket_accepted_by_server_before" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <!-- Open client device in server mode. It was already pre-configured inside by the accepting server socket. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".client_socket_on_server"/>
 * </node>
 *
 * <node name="open_client_socket_connecting_to_a_server" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <!-- Open client device in client mode. It still has to be configured inside. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="namespace" channel="inline" format="text/plain" model="ipv4"/>
 *     <node name="style" channel="inline" format="text/plain" model="stream"/>
 *     <node name="protocol" channel="inline" format="text/plain" model="tcp"/>
 *     <node name="device" channel="inline" format="text/plain" model="127.0.0.1"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".standalone_client_socket"/>
 * </node>
 *
 * <!--
 *     In win32, each window catches its own events and is managed independently.
 *     Therefore, the "server" property does not have to be given here.
 *     TODO: This is yet to be implemented and tested in cyboi!
 * -->
 * <node name="open_client" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 *
 * <!--
 *     In the x window system (xcb api), a display server process manages
 *     the events of all windows centrally.
 *     Therefore, the "server" property has to be given here,
 *     in order for the window to get managed by the display server.
 * -->
 * <node name="open_window" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <!-- Open client window in server mode, so that it gets stored in the display server. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It is used for example for a window or client socket stub. If null, the default is false (standalone client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode. If null, the default is zero.
 * - namespace (optional) [text/cybol-path | text/plain]: The address family. It is relevant only with channel socket. Example values: ipv4 or ipv6.
 * - style (optional) [text/cybol-path | text/plain]: The communication style. It is relevant only with channel socket. Example values: stream or datagram.
 * - protocol (optional) [text/cybol-path | text/plain]: The protocol. It is relevant only with channel socket. Example values: tcp or udp.
 * - mode (optional) [text/cybol-path | text/plain]: The file open mode. Either read or write. If null, the default is read.
 * - device (optional) [text/cybol-path | text/plain]: The filename for channel file or serial or terminal or fifo. Example values: /path/to/file.txt or /dev/ttyS0 or standard-output or standard-input or standard-error-output. The filename for channel socket with namespace local (unix domain socket). Example values: localbuffer.socket. The host address for channel socket with namespace ipv4 or ipv6. Example values: localhost or 127.0.0.1. It is null (not given) for channel display, since a client window does not need it.
 * - identification (required) [text/cybol-path]: The file descriptor or client socket number or window id returned from cyboi when opening the resource.
 */
static wchar_t* OPEN_DISPATCH_LOGIC_CYBOL_FORMAT = L"dispatch/open";
static int* OPEN_DISPATCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
