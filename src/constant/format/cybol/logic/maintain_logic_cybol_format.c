/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
 * Shutdown sensing service.
 *
 * Description:
 *
Shuts down the service running on the given channel.
 *
 * Examples:
 *
 * <node name="shutdown_serial_port" channel="inline" format="maintain/shutdown" model="">
 *     <node name="channel" channel="inline" format="text/cybol-path" model=".settings.device"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
channel	the channel on which to shutdown a service (terminal, www, x-window-system, ...)	true	path/* | meta/channel
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. socket, display
 * - port (optional): the service identification, e.g. socket port 80
 */
static wchar_t* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/shutdown";
static int* SHUTDOWN_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The maintain/startup logic cybol format.
 *
 * Startup sensing service.
 *
 * Description:
 *
Starts up a service on the given channel.
 *
 * Examples:
 *
 * <node name="startup_terminal" channel="inline" format="maintain/startup" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 * </node>

<node name="startup_socket" channel="inline" format="maintain/startup" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="namespace" channel="inline" format="text/plain" model="ipv4"/>
 *     <node name="style" channel="inline" format="text/plain" model="stream"/>
 *     <node name="protocol" channel="inline" format="text/plain" model="tcp"/>
 *     <node name="address" channel="inline" format="text/cybol-path" model=".app.var.address"/>
 *     <node name="id" channel="inline" format="text/cybol-path" model=".app.var.port"/>
 *     <node name="mode" channel="inline" format="text/plain" model="server"/>
 *     <node name="blocking" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="connexions" channel="inline" format="number/integer" model="1"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
channel	the channel on which to startup a service (terminal, display, tcp_socket, unix_socket, ...)	true	path/* | meta/channel
namespace	the address family, e.g. ip6	false	text/plain
style	the communication style, e.g. stream	false	text/plain
address	the host address	false	text/plain
protocol	the protocol, e.g. tcp	false	text/cybol-path
id	the service identification if having multiple terminals/displays/sockets etc., e.g. socket port 80; either port or service may be specified; port has higher priority; if missing, zero will be used (first io entry)	false	text/cybol-path
server		false	text/plain
blocking	the socket status, i.e. whether or not a socket is blocking	false	logicvalue/boolean
connexions	the number of possible pending client requests	false	number/integer
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. socket, display
 * - port (optional): the service identification, e.g. socket port 80
 * - namespace (optional): the address family, e.g. local, ipv4, ipv6
 * - style (optional): the communication style, e.g. stream, datagram, raw
 * - protocol (optional): the protocol, e.g. tcp, udp, rdp
 * - device (optional):
 *      = filename for channel "socket" with namespace "local" (unix domain socket), e.g. localbuffer.socket
 *      = host address for channel "socket" with namespace "ipv4" or "ipv6", e.g. localhost or 127.0.0.1
 *      = null for channel "display", since the display server does not need it (therefore it is OPTIONAL)
 * - connexions (optional): the maximum number of possible pending client requests, e.g. 10
 * - timeout (optional): the timeout in seconds set for each new client, e.g. 300
 */
static wchar_t* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT = L"maintain/startup";
static int* STARTUP_MAINTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MAINTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
