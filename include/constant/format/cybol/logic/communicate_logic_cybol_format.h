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

#ifndef COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

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
 * Description:
 *
 * Identifies the device or client that has placed a request (handler) into the interrupt pipe.
 *
 * Examples:
 *
 * <!-- Get gui client window belonging to the handler that was placed into the interrupt pipe. -->
 * <node name="get_window_id" channel="inline" format="communicate/identify" model="">
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 * </node>
 *
 * <!-- Get client socket belonging to the handler that was placed into the interrupt pipe. -->
 * <node name="get_client_socket_id" channel="inline" format="communicate/identify" model="">
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".client_socket"/>
 * </node>
 *
 * Properties:
 *
 * - identification (required) [text/cybol-path]: The device or client identification, for example a file descriptor.
 */
static wchar_t* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/identify";
static int* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/receive logic cybol format.
 *
 * Description:
 *
 * Receives a message via the communication channel.
 *
 * Caution! Some file formats (like the German xDT format for medical data exchange) contain both, the model and the properties, in one file.
 * To cover these cases, the model and properties are received together, in just one operation.
 *
 * Examples:
 *
 * <!-- Initialise an application tree from file at startup. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="counter/simple/app.cybol"/>
 * </node>
 * <node name="initialise_app" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model="."/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Read extensible markup language (xml) data from file. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="serialisation/xml/test/reference.xml"/>
 * </node>
 * <node name="deserialise_data" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="application/xml">
 *         <node name="normalisation" channel="inline" format="logicvalue/boolean" model="false"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".data"/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Read javascript object notation (json) data from file. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="serialisation/json/test/scenario/default.json"/>
 * </node>
 * <node name="deserialise_data" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="application/json"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".data"/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Read character (comma) separated values (csv) from file. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/cybol-path" model="#filename"/>
 * </node>
 * <node name="receive_file" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/csv">
 *         <node name="delimiter" channel="inline" format="text/cybol-path" model="#delimiter"/>
 *         <node name="quotation" channel="inline" format="text/cybol-path" model="#quotation"/>
 *         <node name="header" channel="inline" format="text/cybol-path" model="#header"/>
 *     </node>
 *     <!--
 *         CAUTION! A possibly existing header will be written into the destination message PROPERTIES.
 *         There is NO need to specify the cybol property "header" as sub node of "message" here,
 *         since it is generated under that name automatically by the deserialiser inside.
 *
 *         CAUTION! The message has to be part of the HEAP memory,
 *         since it would not be extensible if lying on the stack.
 *     -->
 *     <node name="message" channel="inline" format="text/cybol-path" model="{#table}"/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Read user input command on terminal. -->
 * <node name="receive_command" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".var.stdin"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model="#command"/>
 *     <!-- Read data from buffer in which they got stored by the sensing thread started through feel/sense before. -->
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <!-- Receive a gui window event on display. -->
 * <node name="receive_event" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/gui-request">
 *         <node name="medium" channel="inline" format="text/cybol-path" model=".gui.window"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".gui.action"/>
 *     <!-- Read indirectly from internal buffer into which data have been written by activate/enable before. -->
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <!-- Receive a binary file whose path has been given for example via internet url. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/cybol-path" model=".var.path"/>
 * </node>
 * <node name="receive_file" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.file"/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Receive client http request on the server side via network socket. -->
 * <node name="receive_request" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-request"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.request"/>
 *     <!-- Read indirectly from internal buffer into which data have been written by the sensing thread. -->
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <!-- Receive client binary request on the server side via network socket. -->
 * <node name="receive_request" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".request"/>
 *     <!-- Read indirectly from internal buffer into which data have been written by the sensing thread. -->
 *     <node name="asynchronicity" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <!-- Receive server response on the client side via network socket. -->
 * <node name="receive_response" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".server_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".response"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - sender (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 * - encoding (optional) [text/cybol-path | meta/encoding]: The encoding, for example utf-8 or utf-32 or ascii.
 * - language (optional) [text/cybol-path | meta/language]: The language used for deserialisation. It is also defining which prefix or suffix indicates the message length, for example binary-crlf, http-request, xdt.
 * - format (optional) [text/cybol-path | meta/format]: The format (type) of the message data.
 * - message (required) [text/cybol-path]: The knowledge tree node storing the received data.
 * - asynchronicity (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating asynchronous reading from buffer in which data got stored by a sensing thread before. If null, the default is false (synchronous read).
 *
 * Constraints for Property Language:
 *
 * - decimal_separator (optional) [text/plain]: The symbol (or character sequence) used to separate the integer part from the fractional part of a floating point (decimal) number.
 * - thousands_separator (optional) [text/plain]: The symbol (or character sequence) used for digit grouping.
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it twice (doubled). Used with joined strings or character (comma) separated values (csv).
 * - header (optional) [logicvalue/boolean]: The flag indicating whether or not the source data contain a header, so that the deserialiser can treat the first line differently. Used with character (comma) separated values (csv). Caution! It should not be mixed up with the headermodel property in represent/serialise or communicate/send.
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just one space. Used with xml or html, for example. If null, then the default is true (normalisation enabled).
 * - maximum (optional) [number/integer]: The maximum number of bytes to be transmitted. Used with serial (port) interface.
 * - minimum (optional) [number/integer]: The minimum number of bytes to be transmitted. Used with serial (port) interface.
 * - medium (optional) [text/cybol-path]: The window to which the mouse button or keyboard key refers. It is needed to search through the hierarchy of gui elements via mouse coordinates, for a suitable action. Used with graphical user interface (gui).
 *
 * CAUTION! When changing these constraints, then copy them 1:1 to file "represent_logic_cybol_format.h".
 */
static wchar_t* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/receive";
static int* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/send logic cybol format.
 *
 * Description:
 *
 * Sends a message via the communication channel.
 *
 * Examples:
 *
 * <!-- Place a signal (event) into the cyboi system signal memory (event queue). -->
 * <node name="send_exit_signal" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="signal"/>
 *     <node name="message" channel="inline" format="live/exit" model=""/>
 * </node>
 *
 * <!-- Send a signal that was read from a cybol file before. -->
 * <node name="send_signal_taken_from_file" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="signal"/>
 *     <node name="message" channel="file" format="element/part" model="exit/file/exit.cybol"/>
 * </node>
 *
 * <!-- Send plain text to terminal. -->
 * <node name="say_hello" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".var.stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/plain" model="Hello World!"/>
 * </node>
 *
 * <!-- Print an http request's uri query action on terminal. -->
 * <node name="print_query" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.request:uri:query.action"/>
 * </node>
 *
 * <!-- Print http request as pure ascii data on terminal. -->
 * <node name="print_request" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="application/octet-stream"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".request"/>
 * </node>
 *
 * <!-- Send boolean value (flag) to terminal. -->
 * <node name="log_flag" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="logicvalue/boolean"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".result_flag"/>
 * </node>
 *
 * <!-- Send integer number to terminal. -->
 * <node name="print_number" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".index"/>
 * </node>
 *
 * <!-- Send decimal fraction number to terminal. -->
 * <node name="print_adc_value" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/fraction-decimal"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".settings.adc"/>
 * </node>
 *
 * <!-- Send main menu as text user interface (tui) to terminal. -->
 * <node name="send_menu" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui">
 *         <node name="clear" channel="inline" format="logicvalue/boolean" model="true"/>
 *         <node name="positioning" channel="inline" format="logicvalue/boolean" model="true"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".tui.main"/>
 * </node>
 *
 * <node name="set_cursor" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/tui">
 *         <!-- The clear flag is false by default and therefore does not have to be added here. -->
 *         <node name="positioning" channel="inline" format="logicvalue/boolean" model="true"/>
 *     </node>
 *     <!-- Use text/plain instead of element/part, since the cursor has just the position property but an empty model. -->
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".tui.cursor"/>
 * </node>
 *
 * <!-- Draw graphical user interface (gui) window on display. -->
 * <node name="refresh_display" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="display"/>
 *     <!-- This flag is IMPORTANT for finding the correct client entry in the server list. -->
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".gui.window_id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/gui-response"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".gui.window"/>
 * </node>
 *
 * <!-- Write runtime knowledge tree into file, which is useful for testing. -->
 * <node name="open_file" channel="inline" format="dispatch/open" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="device" channel="inline" format="text/plain" model="counter/simple/test_counter_simple.txt"/>
 *     <node name="mode" channel="inline" format="text/plain" model="write"/>
 * </node>
 * <node name="send_knowledge_tree_root" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/model-diagram"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model="."/>
 * </node>
 * <node name="close_file" channel="inline" format="dispatch/close" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="identification" channel="inline" format="text/cybol-path" model=".id"/>
 * </node>
 *
 * <!-- Write binary data into a file. -->
 * <node name="test_file_content" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.file"/>
 * </node>
 *
 * <!-- Serialise web user interface (wui) and store it as html file. -->
 * <node name="generate_html" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/html">
 *         <node name="indentation" channel="inline" format="logicvalue/boolean" model="true"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".wui.index"/>
 * </node>
 *
 * <!-- Serialise a webpage into html within the knowledge tree and afterwards save it as file. -->
 * <node name="serialise_webpage" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.webpage"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".wui.index"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/html"/>
 * </node>
 * <node name="write_serialised_webpage_into_file" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.webpage"/>
 * </node>
 *
 * <!-- Assemble http response with webpage plus metadata and store it as file. -->
 * <node name="test_http_response" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-response"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.webpage">
 *         <node name="Server" channel="inline" format="text/plain" model="CYBOI/0.22.0 (Linux) CYBOL/2.0.0"/>
 *         <node name="Connection" channel="inline" format="text/plain" model="close"/>
 *         <node name="Content-Type" channel="inline" format="text/plain" model="text/html"/>
 *     </node>
 * </node>
 *
 * <!-- Send ascii text "Hello World!" as binary data via socket. -->
 * <node name="send_hello" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="message" channel="inline" format="application/octet-stream" model="Hello World!"/>
 * </node>
 *
 * <!-- Send text data as http response via socket. -->
 * <node name="send_file" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-response"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.file"/>
 * </node>
 *
 * <!-- Send empty text http-response to indicate end of communication. -->
 * <node name="send_empty_message" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-response"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <node name="message" channel="inline" format="text/plain" model=""/>
 * </node>
 *
 * <!-- Send html encapsulated as http-response. -->
 * <node name="send" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="server" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="port" channel="inline" format="number/integer" model="1971"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".var.client_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/http-response"/>
 *     <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *     <!--
 *         For the http response, the following headers are recommended:
 *         - Date
 *         - Server
 *         - Content-Length
 *         - Content-Type
 *
 *         CAUTION! An "encoding" is NOT given when using the language "message/http-response",
 *         since it would cause the WHOLE http message to get encoded.
 *         But the http header should be ASCII (single-byte characters) only.
 *         Likewise, binary attachments such as images should NOT get encoded.
 *
 *         CAUTION! It does NOT work adding the constraint "encoding" right here.
 *         It does properly appear in the knowledge tree, but is NOT recognised in the operation "send".
 *         The reason is that the format "text/cybol-path" points to another part ".webpage"
 *         whose properties are used INSTEAD of those constraints that might be specified here.
 *         In order to verify this, one might use the format "text/plain" testwise,
 *         with which the constraints are recognised properly.
 *         Therefore, the necessary "encoding" is added at the part ".webpage" DIRECTLY.
 *     -->
 *     <node name="message" channel="inline" format="text/cybol-path" model=".var.webpage">
 *         <node name="Connection" channel="inline" format="text/plain" model="keep-alive"/>
 *         <!--
 *         <node name="Content-Type" channel="inline" format="text/plain" model="text/html; charset=utf-8"/>
 *         -->
 *         <!--
 *             The client has 300 s == 5 min to make any additional requests before the connection is closed.
 *             The client can send up to 1000 more requests.
 *         -->
 *         <node name="Keep-Alive" channel="inline" format="text/plain" model="timeout=300, max=1000"/>
 *     </node>
 * </node>
 *
 * <!-- Send request on client side to server via socket. -->
 * <node name="send_request" channel="inline" format="communicate/send" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 *     <node name="receiver" channel="inline" format="text/cybol-path" model=".server_socket"/>
 *     <node name="language" channel="inline" format="meta/language" model="message/binary-crlf"/>
 *     <node name="message" channel="inline" format="application/octet-stream" model="say-hello"/>
 * </node>
 *
 * Properties:
 *
 * - channel (required) [text/cybol-path | meta/channel]: The communication channel.
 * - server (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating server mode. It means server-side client stub and not standalone client. If null, the default is false (client mode).
 * - port (optional) [text/cybol-path | number/integer]: The service identification. It is relevant only in server mode.
 * - receiver (required) [text/cybol-path]: The device identification, for example a file descriptor. Handing it over as hard-coded integer value does not make sense, since the operating system or server assigns it. Therefore, state a cybol-path.
 * - encoding (optional) [text/cybol-path | meta/encoding]: The encoding, for example utf-8 or utf-32 or ascii.
 * - language (optional) [text/cybol-path | meta/language]: The language used for serialisation, for example model-diagram, html, binary-crlf, http-response, xdt.
 * - format (optional) [text/cybol-path | meta/format]: The format (type) of the message data.
 * - message (required) [text/cybol-path | application/octet-stream | any]: The data to be sent.
 * - asynchronicity (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating asynchronous writing within a thread. If null, the default is false (synchronous write).
 * - handler (optional) [text/cybol-path]: The callback cybol operation being executed when the thread finished writing data.
 *
 * Constraints for Property Language:
 *
 * - sign (optional) [logicvalue/boolean]: The flag indicating whether or not a plus sign is to be displayed for positive numbers. Negative numbers have a minus sign in any case. If null, the default is false (no plus sign for positive numbers).
 * - base (optional) [number/integer]: The number base for example 2 for binary (dual), 8 for octal, 10 for decimal, 16 for hexadecimal. If null, the default is 10 (decimal number base).
 * - classicoctal (optional) [logicvalue/boolean]: The flag indicating whether or not the octal number base prefix is to be displayed as 0 as in classic c/c++ or using modern style 0o as in perl and python. If null, the default is false (modern style with prefix 0o).
 * - grouping (optional) [text/plain]: The symbol or character sequence used for digit grouping in thousands. If null, the default is not to use any thousands separator at all.
 * - separator (optional) [text/plain]: The symbol or character sequence used to separate the integer part from the fractional part of a floating point decimal number. If null, the default is to use the full stop (dot).
 * - decimals (optional) [number/integer]: The number of post-point decimal places (decimals). If null, the default is 4.
 * - scientific (optional) [logicvalue/boolean]: The flag indicating whether or not the decimal fraction gets displayed with mantissa and exponent. If null, the default is false (standard representation without exponent).
 * - polar (optional) [logicvalue/boolean]: The flag indicating whether or not to write the complex number using polar coordinates. If null, the default is false (using the cartesian form).
 * - newline (optional) [logicvalue/boolean]: The flag indicating whether or not a line break is added at the end of the printed characters. If null, the default is true (line gets broken). Used with text (pseudo) terminal.
 * - clear (optional) [logicvalue/boolean]: The flag indicating whether or not the terminal screen is cleared before printing characters on it. If null, the default is false (no clearing). Used with text (pseudo) terminal.
 * - positioning (optional) [logicvalue/boolean]: The flag indicating whether or not the cursor position may get changed. If null, the default is false (no repositioning). Used with text (pseudo) terminal.
 * - indentation (optional) [logicvalue/boolean]: The flag indicating whether or not the serialised data get beautified (pretty-formatted) by indenting the single lines depending on the hierarchy level. Used with xml or html, for example.
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it twice (doubled). Used with joined strings or character (comma) separated values (csv).
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just one space. Used with xml or html, for example. If null, then the default is true (normalisation enabled).
 * - width (optional) [number/integer]: The number of characters (or digits) belonging to a value. Free places get filled up with the character given in the fill property. This was defined in the original specification of character (comma) separated values (csv), in order to have fields (values) with equal width. Used with joined strings or csv.
 * - fill (optional) [text/plain]: The characters (or digit) to be used to fill free places in a value whose width is greater.
 * - headermodel (optional) [text/cybol-path]: The header data to be written as first line, yet before the actual content. Used with character (comma) separated values (csv). Caution! It should not be mixed up with the header property flag in represent/deserialise or communicate/receive.
 *
 * CAUTION! When changing these constraints, then copy them 1:1 to file "represent_logic_cybol_format.h".
 */
static wchar_t* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/send";
static int* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
