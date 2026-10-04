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

#ifndef LOGIC_CYBOI_FORMAT_CONSTANT_HEADER
#define LOGIC_CYBOI_FORMAT_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! These constants should actually be put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// However, STATE and LOGIC constants have been split into TWO files,
// for reasons of better overview.
//
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..999
// - logic constants: 1000..2999
//

//
// access
//

/** The count access logic cyboi format. */
static int* COUNT_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty indicate access logic cyboi format. */
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1001_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The exists indicate access logic cyboi format. */
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1002_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format get access logic cyboi format. */
static int* FORMAT_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1003_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The name get access logic cyboi format. */
static int* NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1004_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type get access logic cyboi format. */
static int* TYPE_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_1005_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// activate
//

/** The disable activate logic cyboi format. */
static int* DISABLE_ACTIVATE_LOGIC_CYBOI_FORMAT = NUMBER_1020_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The enable activate logic cyboi format. */
static int* ENABLE_ACTIVATE_LOGIC_CYBOI_FORMAT = NUMBER_1021_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// calculate
//

/** The absolute calculate logic cyboi format. */
static int* ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The add calculate logic cyboi format. */
static int* ADD_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The decrement calculate logic cyboi format. */
static int* DECREMENT_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The divide calculate logic cyboi format. */
static int* DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The increment calculate logic cyboi format. */
static int* INCREMENT_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The maximum calculate logic cyboi format. */
static int* MAXIMUM_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The minimum calculate logic cyboi format. */
static int* MINIMUM_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1108_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The modulo calculate logic cyboi format. */
static int* MODULO_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiply calculate logic cyboi format. */
static int* MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The negate calculate logic cyboi format. */
static int* NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1112_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reduce calculate logic cyboi format. */
static int* REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1113_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The subtract calculate logic cyboi format. */
static int* SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_1114_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// cast
//

/** The byte cast logic cyboi format. */
static int* BYTE_CAST_LOGIC_CYBOI_FORMAT = NUMBER_1200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The character cast logic cyboi format. */
static int* CHARACTER_CAST_LOGIC_CYBOI_FORMAT = NUMBER_1201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The double cast logic cyboi format. */
static int* DOUBLE_CAST_LOGIC_CYBOI_FORMAT = NUMBER_1202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer cast logic cyboi format. */
static int* INTEGER_CAST_LOGIC_CYBOI_FORMAT = NUMBER_1203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// check
//

/** The equal check logic cyboi format. */
static int* EQUAL_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1250_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater check logic cyboi format. */
static int* GREATER_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1251_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal check logic cyboi format. */
static int* GREATER_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1252_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The less check logic cyboi format. */
static int* LESS_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1253_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The less-or-equal check logic cyboi format. */
static int* LESS_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1254_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal check logic cyboi format. */
static int* UNEQUAL_CHECK_LOGIC_CYBOI_FORMAT = NUMBER_1255_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// command
//

/** The archive command logic cyboi format. */
static int* ARCHIVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy command logic cyboi format. */
static int* COPY_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo command logic cyboi format. */
static int* ECHO_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list-directory-contents command logic cyboi format. */
static int* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1303_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move command logic cyboi format. */
static int* MOVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove command logic cyboi format. */
static int* REMOVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1305_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver command logic cyboi format. */
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1306_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change-permission command logic cyboi format. */
static int* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1307_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The word count command logic cyboi format. */
static int* WORD_COUNT_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1308_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create directory command logic cyboi format. */
static int* CREATE_DIRECTORY_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1309_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping command logic cyboi format. */
static int* PING_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep command logic cyboi format. */
static int* GREP_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1311_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traceroute command logic cyboi format. */
static int* TRACEROUTE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1312_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diff command logic cyboi format. */
static int* DIFF_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1313_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort command logic cyboi format. */
static int* SORT_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1314_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear command logic cyboi format. */
static int* CLEAR_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1315_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help command logic cyboi format. */
static int* HELP_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1316_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The config network command logic cyboi format. */
static int* CONFIG_NETWORK_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1317_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The date command logic cyboi format. */
static int* DATE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1318_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks command logic cyboi format. */
static int* LIST_TASKS_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1319_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change directory command logic cyboi format. */
static int* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1320_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kill process command logic cyboi format. */
static int* KILL_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1321_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare files command logic cyboi format. */
static int* COMPARE_FILES_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1322_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disk free command logic cyboi format. */
static int* DISK_FREE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1323_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find command command logic cyboi format. */
static int* FIND_COMMAND_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1324_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display content command logic cyboi format. */
static int* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1325_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find file command logic cyboi format. */
static int* FIND_FILE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1326_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sleep command logic cyboi format. */
static int* DELAY_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1327_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The spellcheck command logic cyboi format. */
static int* SPELLCHECK_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1328_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The memory free command logic cyboi format. */
static int* MEMORY_FREE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1329_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The who am i command logic cyboi format. */
static int* WHO_AM_I_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1330_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The who command logic cyboi format. */
static int* WHO_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1331_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The top command logic cyboi format. */
static int* TOP_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1332_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifconfig command logic cyboi format. */
static int* IFCONFIG_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1333_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id command logic cyboi format. */
static int* ID_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1334_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hostname command logic cyboi format. */
static int* HOSTNAME_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1335_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The userlog command logic cyboi format. */
static int* USERLOG_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1336_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The touch command logic cyboi format. */
static int* TOUCH_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1337_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifup command logic cyboi format. */
static int* IFUP_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1338_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disk usage command logic cyboi format. */
static int* DISK_USAGE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1339_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list open files command logic cyboi format. */
static int* LIST_OPEN_FILES_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1340_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pwd command logic cyboi format. */
static int* PWD_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1341_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The system messages command logic cyboi format. */
static int* SYSTEM_MESSAGES_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1342_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netstat command logic cyboi format. */
static int* NETSTAT_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_1343_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// communicate
//

/** The identify communicate logic cyboi format. */
static int* IDENTIFY_COMMUNICATE_LOGIC_CYBOI_FORMAT = NUMBER_1400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The receive communicate logic cyboi format. */
static int* RECEIVE_COMMUNICATE_LOGIC_CYBOI_FORMAT = NUMBER_1401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The send communicate logic cyboi format. */
static int* SEND_COMMUNICATE_LOGIC_CYBOI_FORMAT = NUMBER_1402_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// compare
//

/** The equal compare logic cyboi format. */
static int* EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater compare logic cyboi format. */
static int* GREATER_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal compare logic cyboi format. */
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The less compare logic cyboi format. */
static int* LESS_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1503_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The less-or-equal compare logic cyboi format. */
static int* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1504_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal compare logic cyboi format. */
static int* UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_1505_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// contain
//

/** The any contain logic cyboi format. */
static int* ANY_CONTAIN_LOGIC_CYBOI_FORMAT = NUMBER_1550_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left contain logic cyboi format. */
static int* LEFT_CONTAIN_LOGIC_CYBOI_FORMAT = NUMBER_1551_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right contain logic cyboi format. */
static int* RIGHT_CONTAIN_LOGIC_CYBOI_FORMAT = NUMBER_1552_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// convert
//

/** The decode convert logic cyboi format. */
static int* DECODE_CONVERT_LOGIC_CYBOI_FORMAT = NUMBER_1600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encode convert logic cyboi format. */
static int* ENCODE_CONVERT_LOGIC_CYBOI_FORMAT = NUMBER_1601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// dispatch
//

/** The close dispatch logic cyboi format. */
static int* CLOSE_DISPATCH_LOGIC_CYBOI_FORMAT = NUMBER_1650_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The open dispatch logic cyboi format. */
static int* OPEN_DISPATCH_LOGIC_CYBOI_FORMAT = NUMBER_1651_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// feel
//

/** The sense feel logic cyboi format. */
static int* SENSE_FEEL_LOGIC_CYBOI_FORMAT = NUMBER_1660_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The suspend feel logic cyboi format. */
static int* SUSPEND_FEEL_LOGIC_CYBOI_FORMAT = NUMBER_1661_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// flow
//

/** The branch flow logic cyboi format. */
static int* BRANCH_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop flow logic cyboi format. */
static int* LOOP_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop-each flow logic cyboi format. */
static int* LOOP_EACH_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1702_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop-for flow logic cyboi format. */
static int* LOOP_FOR_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1703_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop-times flow logic cyboi format. */
static int* LOOP_TIMES_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1704_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sequence flow logic cyboi format. */
static int* SEQUENCE_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_1705_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// live
//

/** The exit live logic cyboi format. */
static int* EXIT_LIVE_LOGIC_CYBOI_FORMAT = NUMBER_1800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logify
//

/** The and logify logic cyboi format. */
static int* AND_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1900_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nand logify logic cyboi format. */
static int* NAND_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1901_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The neg logify logic cyboi format. */
static int* NEG_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1902_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nor logify logic cyboi format. */
static int* NOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1903_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not logify logic cyboi format. */
static int* NOT_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1904_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The or logify logic cyboi format. */
static int* OR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1905_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xnor logify logic cyboi format. */
static int* XNOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1906_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xor logify logic cyboi format. */
static int* XOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_1907_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// maintain
//

/** The shutdown maintain logic cyboi format. */
static int* SHUTDOWN_MAINTAIN_LOGIC_CYBOI_FORMAT = NUMBER_2000_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The startup maintain logic cyboi format. */
static int* STARTUP_MAINTAIN_LOGIC_CYBOI_FORMAT = NUMBER_2001_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// manipulate
//

/** The check manipulate logic cyboi format. */
static int* CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear manipulate logic cyboi format. */
static int* CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate left manipulate logic cyboi format. */
static int* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate right manipulate logic cyboi format. */
static int* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The set manipulate logic cyboi format. */
static int* SET_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift left manipulate logic cyboi format. */
static int* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift right manipulate logic cyboi format. */
static int* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The toggle manipulate logic cyboi format. */
static int* TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_2107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// memorise
//

/** The create memorise logic cyboi format. */
static int* CREATE_MEMORISE_LOGIC_CYBOI_FORMAT = NUMBER_2200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy memorise logic cyboi format. */
static int* DESTROY_MEMORISE_LOGIC_CYBOI_FORMAT = NUMBER_2201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// modify
//

/** The append modify logic cyboi format. */
static int* APPEND_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty modify logic cyboi format. */
static int* EMPTY_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fill modify logic cyboi format. */
static int* FILL_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2303_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insert modify logic cyboi format. */
static int* INSERT_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The lowercase modify logic cyboi format. */
static int* LOWERCASE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2305_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The normalise modify logic cyboi format. */
static int* NORMALISE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2306_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overwrite modify logic cyboi format. */
static int* OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2307_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove modify logic cyboi format. */
static int* REMOVE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2309_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The repeat modify logic cyboi format. */
static int* REPEAT_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The replace modify logic cyboi format. */
static int* REPLACE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2311_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reverse modify logic cyboi format. */
static int* REVERSE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2312_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shuffle modify logic cyboi format. */
static int* SHUFFLE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2313_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The strip leading modify logic cyboi format. */
static int* STRIP_LEADING_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2314_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The strip modify logic cyboi format. */
static int* STRIP_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2315_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The strip trailing modify logic cyboi format. */
static int* STRIP_TRAILING_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2316_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uppercase modify logic cyboi format. */
static int* UPPERCASE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_2317_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// randomise
//

/** The retrieve randomise logic cyboi format. */
static int* RETRIEVE_RANDOMISE_LOGIC_CYBOI_FORMAT = NUMBER_2350_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sow randomise logic cyboi format. */
static int* SOW_RANDOMISE_LOGIC_CYBOI_FORMAT = NUMBER_2351_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// represent
//

/** The deserialise represent logic cyboi format. */
static int* DESERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT = NUMBER_2400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The serialise represent logic cyboi format. */
static int* SERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT = NUMBER_2401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// run
//

/** The run logic cyboi format. */
static int* RUN_LOGIC_CYBOI_FORMAT = NUMBER_2450_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nano sleep run logic cyboi format. */
static int* NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT = NUMBER_2451_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The second sleep run logic cyboi format. */
static int* SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT = NUMBER_2452_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// search
//

/** The search/binary logic cybol format. */
static int* BINARY_SEARCH_LOGIC_CYBOI_FORMAT = NUMBER_2500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The search/interpolation logic cybol format. */
static int* INTERPOLATION_SEARCH_LOGIC_CYBOI_FORMAT = NUMBER_2501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The search/linear logic cybol format. */
static int* LINEAR_SEARCH_LOGIC_CYBOI_FORMAT = NUMBER_2502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// sort
//

/** The sort/bubble logic cybol format. */
static int* BUBBLE_SORT_LOGIC_CYBOI_FORMAT = NUMBER_2600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort/insertion logic cybol format. */
static int* INSERTION_SORT_LOGIC_CYBOI_FORMAT = NUMBER_2601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort/quick logic cybol format. */
static int* QUICK_SORT_LOGIC_CYBOI_FORMAT = NUMBER_2602_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort/selection logic cybol format. */
static int* SELECTION_SORT_LOGIC_CYBOI_FORMAT = NUMBER_2603_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// stream
//

/** The read stream logic cyboi format. */
static int* READ_STREAM_LOGIC_CYBOI_FORMAT = NUMBER_2700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The write stream logic cyboi format. */
static int* WRITE_STREAM_LOGIC_CYBOI_FORMAT = NUMBER_2701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// time
//

/** The current time logic cyboi format. */
static int* CURRENT_TIME_LOGIC_CYBOI_FORMAT = NUMBER_2800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIC_CYBOI_FORMAT_CONSTANT_HEADER */
#endif
