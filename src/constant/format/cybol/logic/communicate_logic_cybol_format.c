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
 * @version CYBOP 0.22.0 2022-02-22
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
