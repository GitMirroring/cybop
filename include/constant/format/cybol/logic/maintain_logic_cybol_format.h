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

#ifndef MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Maintain
//
// IANA media type: not defined
// Self-defined media type: maintain
// This media type is a CYBOL extension.
//

/**
 * The maintain/shutdown logic cybol format.
 *
 * Description:
 *
 * Shuts down the service running on the channel.
 *
 * Examples:
 *
 * <node name="shutdown_connexion_to_x_window_system_server" channel="inline" format="maintain/shutdown" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - port (optional) [text/cybol-path | number/integer]: The service identification.
 */
static wchar_t* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/shutdown";
static int* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maintain/startup logic cybol format.
 *
 * Description:
 *
 * Starts up a service on the channel.
 *
 * Examples:
 *
 * <node name="startup_local_unix_domain_socket_with_filename" channel="inline" format="maintain/startup" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="namespace" channel="inline" format="text/plain" model="local"/>
 *     <node name="style" channel="inline" format="text/plain" model="datagram"/>
 *     <node name="protocol" channel="inline" format="text/plain" model="udp"/>
 *     <node name="device" channel="inline" format="text/plain" model="cyboi.socket"/>
 *     <node name="connexions" channel="inline" format="number/integer" model="1"/>
 *     <node name="timeout" channel="inline" format="number/integer" model="5"/>
 * </node>
 *
 * <node name="startup_ipv4_stream_socket" channel="inline" format="maintain/startup" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="namespace" channel="inline" format="text/plain" model="ipv4"/>
 *     <node name="style" channel="inline" format="text/plain" model="stream"/>
 *     <node name="protocol" channel="inline" format="text/plain" model="tcp"/>
 *     <node name="device" channel="inline" format="text/plain" model="127.0.0.1"/>
 *     <node name="connexions" channel="inline" format="number/integer" model="10"/>
 *     <node name="timeout" channel="inline" format="number/integer" model="5"/>
 * </node>
 *
 * <!-- Startup display service and open a window afterwards. -->
 * <node name="connect_to_x_window_system_server" channel="inline" format="maintain/startup" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 * </node>
 * <node name="open_window" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <!-- Open client window in SERVER mode, so that it gets stored in the display server. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - port (optional) [text/cybol-path | number/integer]: The service identification.
 * - namespace (optional) [text/cybol-path | text/plain]: The address family, for example local, ipv4, ipv6.
 * - style (optional) [text/cybol-path | text/plain]: The communication style, for example stream, datagram, raw.
 * - protocol (optional) [text/cybol-path | text/plain]: The protocol, for example tcp, udp, rdp.
 * - device (optional) [text/cybol-path | text/plain]: The filename for channel socket with namespace local (unix domain socket). Example values: localbuffer.socket. The host address for channel socket with namespace ipv4 or ipv6. Example values: localhost or 127.0.0.1. It is null (not given) for channel display, since a client window does not need it.
 * - connexions (optional) [text/cybol-path | number/integer]: The maximum number of possible pending client requests, for example 10.
 * - timeout (optional) [text/cybol-path | number/integer]: The timeout in seconds set for each new client, for example 300.
 */
static wchar_t* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/startup";
static int* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
