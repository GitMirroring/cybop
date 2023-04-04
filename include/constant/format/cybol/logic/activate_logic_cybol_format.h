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

#ifndef ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Activate
//
// IANA media type: not defined
// Self-defined media type: activate
// This media type is a CYBOL extension.
//

/**
 * The activate/disable logic cybol format.
 *
 * Description:
 *
 * Disables the communication channel, so that no more requests/events can be detected.
 *
 * Examples:
 *
 * <node name="disable_server_socket" channel="inline" format="activate/disable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 * </node>
 *
 * <node name="disable_display_server" channel="inline" format="activate/disable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - port (optional) [text/cybol-path | number/integer]: The service identification, for example http socket port 80. If null, the default is zero, for example with channel display.
 */
static wchar_t* DISABLE_ACTIVATE_LOGIC_CYBOL_FORMAT = L"activate/disable";
static int* DISABLE_ACTIVATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The activate/enable logic cybol format.
 *
 * Description:
 *
 * Enables the communication channel, so that requests/events can be detected.
 *
 * Calling the operation "feel/sense" afterwards is not necessary for channel "display" on a linux operating system with x window system, since "activate/enable" catches the events of all client windows.
 * On a windows operating system, however, one separate event thread is run per window, so that calling "feel/sense" after this "activate/enable" is necessary.
 *
 * Calling this operation "activate/enable" is not necessary for channels "terminal" or "serial", since clients get opened manually using "dispatch/open" and events can be detected right afterwards using the operation "feel/sense".
 *
 * The requesting client gets appended to an internal accept buffer list. It can be accessed in operation "dispatch/open" using the property "identification". However, this works only, if the "server" flag is set to true, so that the client is read from the accept buffer list.
 *
 * Examples:
 *
 * <node name="enable_server_socket" channel="inline" format="activate/enable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle.enable"/>
 * </node>
 *
 * <!--
 *     Complete socket example with operations: enable, open, sense, identify, close.
 * -->
 * <!--
 *     File "startup.cybol".
 * -->
 * <node name="enable_requests" channel="inline" format="activate/enable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle.enable"/>
 * </node>
 * <!--
 *     File "enable.cybol".
 *     This is the enable handler file belonging to the above call of ".logic.handle.enable".
 * -->
 * <node name="open_client" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <!-- Open client device in SERVER mode. It was already pre-configured inside by the accepting server socket. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 * </node>
 * <node name="sense_client_data" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-request"/>
 *     <!-- This is the callback function executed when the client sends data. -->
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle.sense"/>
 *     <!-- This is the callback function executed when the client does not respond and is to be closed. -->
 *     <node name="closer" channel="inline" format="text/cybol-path" model=".logic.handle.close"/>
 * </node>
 * <!-- File "sense.cybol" with processing instruction is left out here. -->
 * <!--
 *     File "close.cybol".
 *     This is the close handler file belonging to the above call of ".logic.handle.close".
 * -->
 * <!-- Get client belonging to the handler that was placed into the interrupt pipe. -->
 * <node name="get_client_id" channel="inline" format="communicate/identify" model="">
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 * </node>
 * <node name="handle_close" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 * </node>
 *
 * <!-- Fill internal input buffer of the corresponding windows with received events. -->
 * <node name="enable_display_server" channel="inline" format="activate/enable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 * </node>
 *
 * <node name="enable_display_server_and_add_general_handler" channel="inline" format="activate/enable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <!--
 *         For standard window event processing, use operation "feel/sense"
 *         which allows to hand over a SPECIFIC handler for each window.
 *         However, it is possible to assign another callback function here,
 *         which is OPTIONAL and would be executed upon arrival of EACH event,
 *         independently of any window.
 *     -->
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".handle_each_event"/>
 * </node>
 *
 * <!--
 *     Complete display example with operations: enable, sense, identify, receive.
 *     The "maintain/startup" and "dispatch/open" operations are assumed to have been called before.
 * -->
 * <node name="enable_server" channel="inline" format="activate/enable" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 * </node>
 * <node name="sense_client_window_events" channel="inline" format="feel/sense" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 *     <node name="handler" channel="inline" format="text/cybol-path" model=".logic.handle"/>
 * </node>
 * <!--
 *     File "handle.cybol".
 *     This is the event handler file belonging to the above call of ".logic.handle".
 * -->
 * <!-- Get window client belonging to the handler that was placed into the interrupt pipe. -->
 * <node name="get_window_id" channel="inline" format="communicate/identify" model="">
 *      <node name="identification" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 * <!-- The element hierarchy of the window given as "medium" gets searched through to identify a suitable action. -->
 * <node name="receive_next_event" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/gui-request">
 *         <node name="medium" channel="inline" format="text/cybol-path" model=".gui.window"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".gui.action"/>
 *     <!-- Read indirectly from internal buffer into which data have been written by activate/enable. -->
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - port (optional) [text/cybol-path | number/integer]: The service identification, for example http socket port 80. If null, the default is zero, for example with channel display.
 * - handler (optional) [text/cybol-path]: The callback cybol model to be executed upon arrival of a request/event.
 */
static wchar_t* ENABLE_ACTIVATE_LOGIC_CYBOL_FORMAT = L"activate/enable";
static int* ENABLE_ACTIVATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACTIVATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
