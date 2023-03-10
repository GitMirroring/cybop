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

#ifndef STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

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
 * Description:
 *
 * Reads data from a device.
 *
 * Reading indirectly from device into the internal buffer does not make sense for channel "file". Therefore, do not set the "asynchronicity" flag in this case.
 *
 * Examples:
 *
 * <node name="read_from_file" channel="inline" format="stream/read" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".data"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - sender (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 * - language (optional) [text/cybol-path | meta/language]: The language defining which prefix or suffix indicates the message length, for example binary-crlf, http-request, xdt. It is not needed for file reading since that ends with EOF.
 * - message (required) [text/cybol-path]: The knowledge tree node storing the received data.
 * - asynchronicity (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating asynchronous reading from buffer in which data got stored by a sensing thread before. If null, the default is false (synchronous read).
 */
static wchar_t* READ_STREAM_LOGIC_CYBOL_FORMAT = L"stream/read";
static int* READ_STREAM_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The stream/write logic cybol format.
 *
 * Description:
 *
 * Writes data to a device.
 *
 * Examples:
 *
 * <node name="write_to_file" channel="inline" format="stream/write" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="message" channel="inline" format="application/octet-stream" model="Hello World!"/>
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="write_to_pipeline" channel="inline" format="stream/write" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="fifo"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="message" channel="inline" format="application/octet-stream" model="Hello World!"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - receiver (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 * - message (required) [text/cybol-path | application/octet-stream | any]: The data to be written.
 * - asynchronicity (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating asynchronous writing within a thread. If null, the default is false (synchronous write).
 * - handler (optional) [text/cybol-path]: The callback cybol operation being executed when the thread finished writing data.
 */
static wchar_t* WRITE_STREAM_LOGIC_CYBOL_FORMAT = L"stream/write";
static int* WRITE_STREAM_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STREAM_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
