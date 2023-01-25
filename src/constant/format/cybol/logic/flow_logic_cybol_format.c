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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Flow
//
// IANA media type: not defined
// Self-defined media type: flow
// This media type is a CYBOL extension.
//

/**
 * The flow/branch logic cybol format.
 *
 * Description:
 *
 * Branches the programme flow, depending on the criterion flag.
 *
 * Examples:
 *
 * <!-- Read models from file. -->
 * <node name="branch_voltage" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".settings.voltage_criterion"/>
 *     <node name="true" channel="file" format="element/part" model="indoor_climate/add_voltage.cybol"/>
 *     <node name="false" channel="file" format="element/part" model="indoor_climate/report_voltage_failure.cybol"/>
 * </node>
 *
 * <!-- Branch with one model. -->
 * <node name="if-then" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".app.var.flag_loose"/>
 *     <node name="true" channel="inline" format="text/cybol-path" model=".app.print_win"/>
 * </node>
 *
 * <!-- Branch with two models. -->
 * <node name="if-then-else" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".domain.flag"/>
 *     <node name="true" channel="inline" format="text/cybol-path" model=".domain.true_model"/>
 *     <node name="false" channel="inline" format="text/cybol-path" model=".domain.false_model"/>
 * </node>
 *
 * <!-- Verify existence of given url path. -->
 * <node name="evaluate_query" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".var.query_exists"/>
 *     <node name="true" channel="inline" format="text/cybol-path" model=".logic.evaluate_query"/>
 *     <!--
 *         CAUTION! Sending a response is important, even if the query was empty or not understood,
 *         since some browsers request a "/favicon.ico" or other things and if no response was sent,
 *         the browser would wait forever and block requests from other clients.
 *     -->
 *     <node name="false" channel="inline" format="text/cybol-path" model=".logic.send.empty_message"/>
 * </node>
 *
 * <!-- Fill cell with default value if database value is empty. -->
 * <node name="translate_cell" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model="#empty"/>
 *     <node name="true" channel="inline" format="text/cybol-path" model=".logic.translate.db_to_wui.cell_default"/>
 *     <node name="false" channel="inline" format="text/cybol-path" model=".logic.translate.db_to_wui.cell"/>
 * </node>
 *
 * <!-- Call operation directly inline (not as cybol-path) and hand over properties as operation parametres. -->
 * <node name="process_model_as_compound_or_primitive" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model="#compound_flag"/>
 *     <node name="true" channel="inline" format="communicate/send" model="">
 *         <node name="channel" channel="inline" format="meta/channel" model="terminal"/>
 *         <node name="receiver" channel="inline" format="text/cybol-path" model=".stdout"/>
 *         <node name="language" channel="inline" format="meta/language" model="message/tui"/>
 *         <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 *         <node name="message" channel="inline" format="text/plain" model="Do nothing, since this is a compound model."/>
 *     </node>
 *     <node name="false" channel="inline" format="modify/overwrite" model="">
 *         <node name="destination" channel="inline" format="text/cybol-path" model=".wui.index.body.content.(#wui_record_name).table.(#wui_field_name).model"/>
 *         <node name="source" channel="inline" format="text/cybol-path" model="#field_model_text"/>
 *     </node>
 * </node>
 *
 * Properties:
 *
 * - criterion (required) [text/cybol-path | logicvalue/boolean]: The flag defining which of the two models to execute.
 * - true (optional) [text/cybol-path | element/part]: The logic knowledge model to be executed if the criterion is true.
 * - false (optional) [text/cybol-path | element/part]: The logic knowledge model to be executed if the criterion is false.
 */
static wchar_t* BRANCH_FLOW_LOGIC_CYBOL_FORMAT = L"flow/branch";
static int* BRANCH_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/loop logic cybol format.
 *
 * Description:
 *
 * Loops the programme flow endlessly, until the break flag is set.
 *
 * Examples:
 *
 * <!-- Read model from heap (knowledge tree). -->
 * <node name="print_numbers" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model=".break"/>
 *     <node name="model" channel="inline" format="text/cybol-path" model=".model"/>
 * </node>
 *
 * <!-- Read model from stack. -->
 * <node name="loop_rows" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model="#row_break"/>
 *     <node name="model" channel="inline" format="text/cybol-path" model="#row_model"/>
 * </node>
 *
 * <!-- Read model from file. -->
 * <node name="collect_voltages" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model=".settings.adc_break"/>
 *     <node name="model" channel="file" format="element/part" model="adc/collect_voltages.cybol"/>
 * </node>
 *
 * <!-- Translate data records of the german medical standard xdt. -->
 * <node name="loop_records" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="path/knowledge" model=".temporary.xdt.record.break"/>
 *     <node name="model" channel="inline" format="path/knowledge" model=".logic.translate.record"/>
 * </node>
 *
 * <!-- Generate several webpages. -->
 * <node name="loop_page" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model="#page_break"/>
 *     <node name="model" channel="inline" format="text/cybol-path" model=".logic.generate.page"/>
 * </node>
 *
 * <!-- Call randomiser as model. -->
 * <node name="generate_mines_in_game_minesweeper" channel="inline" format="flow/loop" model="">
 *     <node name="break" channel="inline" format="text/cybol-path" model=".app.break"/>
 *     <node name="model" channel="inline" format="text/cybol-path" model=".app.logic.randomiser"/>
 * </node>
 *
 * Properties:
 *
 * - break (required) [text/cybol-path | logicvalue/boolean]: The break flag that causes the loop to be left.
 * - model (required) [text/cybol-path | element/part]: The logic knowledge model to be executed repeatedly by the loop.
 */
static wchar_t* LOOP_FLOW_LOGIC_CYBOL_FORMAT = L"flow/loop";
static int* LOOP_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The flow/sequence logic cybol format.
 *
 * Description:
 *
 * Executes the given programme flow as sequence.
 *
 * This encapsulating operation "flow/sequence" is provided here to have all three constructs of structural programming implemented together, which are "sequence", "loop" and "branch".
 *
 * However, in principle, logic models may be executed standalone directly or with encapsulating operation "flow/sequence". Both kinds of execution are possible.
 *
 * Examples:
 *
 * <node name="start_player_input" channel="inline" format="flow/sequence" model="">
 *     <node name="model" channel="inline" format="text/cybol-path" model=".app.setrandom"/>
 * </node>
 *
 * <node name="send_index" channel="inline" format="flow/sequence" model="">
 *     <node name="model" channel="inline" format="text/cybol-path" model=".logic.send.index"/>
 * </node>
 *
 * <node name="execute_action" channel="inline" format="flow/sequence" model="">
 *     <node name="model" channel="inline" format="text/cybol-path" model="{.path}"/>
 * </node>
 *
 * <node name="translate_uri_to_wui" channel="inline" format="flow/sequence" model="">
 *     <node name="model" channel="inline" format="text/cybol-path" model=".logic.translate.uri_to_wui.column"/>
 * </node>
 *
 * <!-- Direct execution of logic model without encapsulating operation "flow/sequence". -->
 * <node name="navigate_to_week" channel="inline" format="text/cybol-path" model=".logic.navigate.week"/>
 *
 * Properties:
 *
 * - model (required) [text/cybol-path | element/part]: The logic knowledge model to be executed as sequence.
 */
static wchar_t* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT = L"flow/sequence";
static int* SEQUENCE_FLOW_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FLOW_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
