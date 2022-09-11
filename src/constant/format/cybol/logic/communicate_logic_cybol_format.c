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

#ifndef COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Communicate
//
// IANA media type: not defined
// Self-defined media type: communicate
// This media type is a CYBOL extension.
//

/**
 * The communicate/identify logic cybol format.
 *
 * Identifies the device or client that has placed a request (handler) into the interrupt pipe.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Properties:
 * - identification (required): the device or client identification, e.g. file descriptor
 */
static wchar_t* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/identify";
static int* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/receive logic cybol format.
 *
 * Receive data via a communication channel.
 * Receives a message via the given channel.
 *
 * CAUTION! Some file formats (like the German xDT format for medical data exchange)
 * contain both, the model AND the properties, in one file. To cover these cases,
 * the model AND properties are received TOGETHER, in just one operation.
 *
 *
 * Description:
 *
Receives a message via the given channel.
 *
 * Examples:
 *
 * <node name="initialise" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/plain" model="ui/app.cybol"/>
 *     <node name="model" channel="inline" format="text/cybol-path" model=".app"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
channel	the channel via which to receive the message (terminal, display, www etc.)	true	path/* | meta/channel
encoding	the encoding (utf-8, utf-32 for inline channel etc.)	true	meta/encoding
language	the language of the data received (cybol, http_request, xdt etc.)	true	meta/language
format	the format of the data received (boolean, character, integer etc.)	true	meta/format
message	the source (knowledge template) from where to receive data, e.g. the gui root window	true	path/knowledge | text/plain
meta	the source (knowledge template) from where to receive meta data (properties)	false	text/cybol-path
model	the model to be filled with the data received	true	text/cybol-path
minimum	the minimum number of bytes to be received in one call of the read function	false	number/integer
maximum	the maximum number of bytes to be received in one call of the read function	false	number/integer
style	the style of socket communication, only if channel is www, cyboi or similar	false	???
 *
 * Properties:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode (server-side client stub and NOT standalone client); if NULL, the default is false (client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - sender (required): the device identification, e.g. file descriptor
 * - encoding (required): the encoding, e.g. utf-8, utf-32
 * - language (optional): the language defining which prefix or suffix indicates the message length, e.g. binary-crlf, http-request, xdt; not needed for file reading since that ends with EOF
 * - normalisation (optional): the flag indicating whether or not the received message is to be normalised, i.e. leading and trailing whitespaces as well as line breaks removed and multiple ones merged into just ONE, e.g. from text in between two tags of an html or xml file; if NULL, the default is TRUE (normalisation enabled)
 * - medium (optional): the user interface window model hierarchy used to identify nested components and their action via mouse coordinates
 * - format (optional): the format of the data, e.g. logicvalue/boolean, number/integer, text/plain
 * - message (required): the cybol path to the knowledge tree node storing the received data
 * - minimum (optional): the minimum number of bytes to be received in one call of the read function (for serial port)
 * - maximum (optional): the maximum number of bytes to be received in one call of the read function (for serial port)
 * - asynchronicity (optional): the flag indicating asynchronous reading from buffer in which data got stored by a sensing thread before; if NULL, the default is false (synchronous read)
 */
static wchar_t* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/receive";
static int* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/send logic cybol format.
 *
 * Send data via a communication channel.
 * Sends a message via the given channel.
 *
 * Description:
 *
Sends a message via the given channel.
 *
 * Examples:
 *
 * <node name="print_adc" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/cli"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/plain" model="Current adc rounded in voltage:"/>
 *     <node name="newline" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>

<node name="print_adc_value" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/cli"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/fraction-decimal"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".settings.adc"/>
 *     <node name="newline" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
channel	the channel via which to send the message (e.g. http)	true	path/* | meta/channel
encoding	the encoding to be used, e.g. ascii; the default is utf-8	false	meta/encoding
language	the language into which to serialise the message before sending it (e.g. html, model-diagram etc.)	true	meta/language
format	the format into which to serialise the message before sending (e.g. element/part, number/integer)	true	meta/format
message	the source message to be sent to another system	true	path/knowledge | text/plain
receiver	the destination receiving the message	false	text/plain
mode	the mode of communication, only if channel is http	false	???
namespace	the namespace of the socket, only if channel is http	false	???
style	the style of communicationl, only if channel is http	false	text/plain
area	the user interface area to be repainted, only if type is tui or gui	false	???
clear	the flag indicating whether or not to clear the screen before painting a user interface, only if type is terminal or tui	false	logicvalue/boolean
newline	the flag indicating whether or not to add a new line after having printed the message on screen, only if channel is terminal	false	logicvalue/boolean
null_termination	the flag indicating whether or not to add an ascii null termination character '\0' at the end of the (multibyte) message (after encoding)	false	logicvalue/boolean
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode; if NULL, the default is false (client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - receiver (required): the device identification, e.g. file descriptor
 * - encoding (optional): the encoding to be used, e.g. ascii; the default is utf-8
 * - language (required): the language into which to serialise the message before sending it (e.g. html, model-diagram etc.)
 * - indentation (optional): the flag indicating whether or not the generated message is to be pretty-formatted (e.g. indented html tags with line breaks)
 * - format (required): the format into which to serialise the message before sending (e.g. element/part, number/integer)
 * - message (required): the data to be sent
 * - clear (optional, only if type is terminal or tui): the flag indicating whether or not to clear the screen before painting a user interface
 * - newline (optional, only if channel is terminal): the flag indicating whether or not to add a new line after having printed the message on screen
 * - asynchronicity (optional): the flag indicating asynchronous writing within a thread; if NULL, the default is false (synchronous write)
 * - handler (optional): the callback cybol operation being executed when the thread finished reading data
 */
static wchar_t* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/send";
static int* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
