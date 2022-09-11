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

#ifndef STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Stream
//
// IANA media type: not defined
// Self-defined media type: stream
// This media type is a CYBOL extension.
//

/**
 * The stream/read logic cybol format.
 *
 * Read data from a device.
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
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode (server-side client stub and NOT standalone client); if NULL, the default is false (client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - sender (required): the device identification, e.g. file descriptor
 * - language (optional): the language defining which prefix or suffix indicates the message length, e.g. binary-crlf, http-request, xdt; not needed for file reading since that ends with EOF
 * - message (required): the cybol path to the knowledge tree node storing the received data
 * - asynchronicity (optional): the flag indicating asynchronous reading from buffer in which data got stored by a sensing thread before; if NULL, the default is false (synchronous read)
 */
static wchar_t* READ_STREAM_LOGIC_CYBOL_FORMAT = L"stream/read";
static int* READ_STREAM_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The stream/write logic cybol format.
 *
 * Write data to a device.
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
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode; if NULL, the default is false (client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - receiver (required): the device identification, e.g. file descriptor
 * - message (required): the data to be written
 * - asynchronicity (optional): the flag indicating asynchronous writing within a thread; if NULL, the default is false (synchronous write)
 * - handler (optional): the callback cybol operation being executed when the thread finished reading data
 */
static wchar_t* WRITE_STREAM_LOGIC_CYBOL_FORMAT = L"stream/write";
static int* WRITE_STREAM_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
