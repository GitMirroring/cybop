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

#ifndef FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Feel
//
// IANA media type: not defined
// Self-defined media type: feel
// This media type is a CYBOL extension.
//

/**
 * The feel/sense logic cybol format.
 *
 * Description:
 *
 * Starts sensing data input within a thread on the sender/client with the given identification.
 *
 * It fills the internal input buffer with those data that were received as input.
 *
 * Calling this operation is not necessary for channel "display" on a linux operating system with x window system, since "activate/enable" catches the events of all client windows.
 * On a windows operating system, however, one separate event thread is run per window, so that calling "feel/sense" is necessary.
 *
 * Examples:
 *
 *  <!-- Open terminal and sense input on it. -->
 * <node name="open_terminal_stdin" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <!-- The text "standard-input" is a pre-defined constant and is used instead of a filename here. -->
 *     <node name="device" channel="inline" format="text/plain" model="standard-input"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".var.stdin"/>
 * </node>
 * <node name="sense_terminal_input" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".var.stdin"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle"/>
 * </node>
 *
 * <node name="sense_data_on_serial_interface" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="serial"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".serial_id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle"/>
 * </node>
 *
 * <node name="sense_client_data_in_binary_format" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle_sense"/>
 *     <node name="closer" channel="inline" format="text/cybol-path" model=".logic.handle_close"/>
 * </node>
 *
 * <node name="sense_client_data_as_http_request" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-request"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle.sense"/>
 *     <node name="closer" channel="inline" format="text/cybol-path" model=".logic.handle.close"/>
 * </node>
 *
 * <!--
 *     This operation "feel/sense" for channel "display" does NOT run in a separate thread.
 *     It is just used to hand over a specific event handler for each window.
 * -->
 * <node name="assign_handler_for_client_window_events" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - sender (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 * - language (optional) [text/cybol-path | meta/language]: The language used for deserialisation. It is also defining which prefix or suffix indicates the message length, for example binary-crlf, http-request, xdt.
 * - handler (required) [text/cybol-path]: The callback cybol model to be executed when data were detected on the sender, in order to read them from the internal input buffer.
 * - closer (optional) [text/cybol-path]: The callback cybol model to be executed when the client does not respond and is to be closed.
 */
static wchar_t* SENSE_FEEL_LOGIC_CYBOL_FORMAT = L"feel/sense";
static int* SENSE_FEEL_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The feel/suspend logic cybol format.
 *
 * Description:
 *
 * Pauses data input sensing thread for the sender/client with the given identification.
 *
 * Examples:
 *
 * <node name="suspend_sensing_thread" channel="inline" format="feel/suspend" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - sender (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 */
static wchar_t* SUSPEND_FEEL_LOGIC_CYBOL_FORMAT = L"feel/suspend";
static int* SUSPEND_FEEL_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
