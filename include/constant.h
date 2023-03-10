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

#ifndef CONSTANT_HEADER
#define CONSTANT_HEADER

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// channel
//

#include "constant/channel/cyboi/cyboi_channel.h"
#include "constant/channel/cybol/cybol_channel.h"

//
// encoding
//

#include "constant/encoding/cyboi/cyboi_encoding.h"

#include "constant/encoding/cybol/base_cybol_encoding.h"
#include "constant/encoding/cybol/cybol_encoding.h"
#include "constant/encoding/cybol/dos_cybol_encoding.h"
#include "constant/encoding/cybol/iso_8859_cybol_encoding.h"
#include "constant/encoding/cybol/unicode_cybol_encoding.h"
#include "constant/encoding/cybol/windows_cybol_encoding.h"

//
// format
//

#include "constant/format/cyboi/logic_cyboi_format.h"
#include "constant/format/cyboi/state_cyboi_format.h"

#include "constant/format/cybol/logic/access_logic_cybol_format.h"
#include "constant/format/cybol/logic/activate_logic_cybol_format.h"
#include "constant/format/cybol/logic/calculate_logic_cybol_format.h"
#include "constant/format/cybol/logic/cast_logic_cybol_format.h"
#include "constant/format/cybol/logic/check_logic_cybol_format.h"
#include "constant/format/cybol/logic/command_logic_cybol_format.h"
#include "constant/format/cybol/logic/communicate_logic_cybol_format.h"
#include "constant/format/cybol/logic/compare_logic_cybol_format.h"
#include "constant/format/cybol/logic/contain_logic_cybol_format.h"
#include "constant/format/cybol/logic/convert_logic_cybol_format.h"
#include "constant/format/cybol/logic/dispatch_logic_cybol_format.h"
#include "constant/format/cybol/logic/feel_logic_cybol_format.h"
#include "constant/format/cybol/logic/flow_logic_cybol_format.h"
#include "constant/format/cybol/logic/live_logic_cybol_format.h"
#include "constant/format/cybol/logic/logify_logic_cybol_format.h"
#include "constant/format/cybol/logic/maintain_logic_cybol_format.h"
#include "constant/format/cybol/logic/manipulate_logic_cybol_format.h"
#include "constant/format/cybol/logic/memorise_logic_cybol_format.h"
#include "constant/format/cybol/logic/modify_logic_cybol_format.h"
#include "constant/format/cybol/logic/randomise_logic_cybol_format.h"
#include "constant/format/cybol/logic/represent_logic_cybol_format.h"
#include "constant/format/cybol/logic/run_logic_cybol_format.h"
#include "constant/format/cybol/logic/sort_logic_cybol_format.h"
#include "constant/format/cybol/logic/stream_logic_cybol_format.h"
#include "constant/format/cybol/logic/time_logic_cybol_format.h"

#include "constant/format/cybol/state/application_state_cybol_format.h"
#include "constant/format/cybol/state/application_vnd_state_cybol_format.h"
#include "constant/format/cybol/state/application_x_state_cybol_format.h"
#include "constant/format/cybol/state/audio_state_cybol_format.h"
#include "constant/format/cybol/state/bluetooth_state_cybol_format.h"
#include "constant/format/cybol/state/colour_state_cybol_format.h"
#include "constant/format/cybol/state/datetime_state_cybol_format.h"
#include "constant/format/cybol/state/drawing_state_cybol_format.h"
#include "constant/format/cybol/state/duration_state_cybol_format.h"
#include "constant/format/cybol/state/element_state_cybol_format.h"
#include "constant/format/cybol/state/example_state_cybol_format.h"
#include "constant/format/cybol/state/fonts_state_cybol_format.h"
#include "constant/format/cybol/state/image_state_cybol_format.h"
#include "constant/format/cybol/state/inode_state_cybol_format.h"
#include "constant/format/cybol/state/logicvalue_state_cybol_format.h"
#include "constant/format/cybol/state/media_state_cybol_format.h"
#include "constant/format/cybol/state/meta_state_cybol_format.h"
#include "constant/format/cybol/state/model_state_cybol_format.h"
#include "constant/format/cybol/state/multipart_state_cybol_format.h"
#include "constant/format/cybol/state/number_state_cybol_format.h"
#include "constant/format/cybol/state/print_state_cybol_format.h"
#include "constant/format/cybol/state/text_state_cybol_format.h"
#include "constant/format/cybol/state/uri_state_cybol_format.h"
#include "constant/format/cybol/state/video_state_cybol_format.h"

//
// language
//

#include "constant/language/cyboi/state_cyboi_language.h"

#include "constant/language/cybol/state/application_state_cybol_language.h"
#include "constant/language/cybol/state/chronology_state_cybol_language.h"
#include "constant/language/cybol/state/interface_state_cybol_language.h"
#include "constant/language/cybol/state/message_state_cybol_language.h"
#include "constant/language/cybol/state/number_state_cybol_language.h"
#include "constant/language/cybol/state/text_state_cybol_language.h"

//
// model
//

#include "constant/model/ansi_escape_code/ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/attribute_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/background_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/foreground_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/input_ansi_escape_code_model.h"

#include "constant/model/backslash_escape/backslash_escape_model.h"

#include "constant/model/character_code/ascii/ascii_character_code_model.h"

#include "constant/model/character_code/dos/dos_437_character_code_model.h"
#include "constant/model/character_code/dos/dos_850_character_code_model.h"

#include "constant/model/character_code/iso_6429/c0_iso_6429_character_code_model.h"
#include "constant/model/character_code/iso_6429/c1_iso_6429_character_code_model.h"

#include "constant/model/character_code/iso_8859/iso_8859_10_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_11_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_12_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_13_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_14_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_15_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_16_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_1_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_2_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_3_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_4_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_5_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_6_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_7_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_8_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_9_character_code_model.h"

#include "constant/model/character_code/unicode/unicode_character_code_model.h"

#include "constant/model/character_code/windows/windows_1252_character_code_model.h"

#include "constant/model/character_entity_reference/html_character_entity_reference_model.h"

#include "constant/model/command/unix_command_model.h"
#include "constant/model/command/win32_command_model.h"

#include "constant/model/cyboi/help/help_cyboi_model.h"

#include "constant/model/cyboi/identification/identification_cyboi_model.h"

#include "constant/model/cyboi/log/error_message_log_cyboi_model.h"
#include "constant/model/cyboi/log/level_log_cyboi_model.h"
#include "constant/model/cyboi/log/level_name_log_cyboi_model.h"
#include "constant/model/cyboi/log/linux_error_message_log_cyboi_model.h"
#include "constant/model/cyboi/log/windows_error_message_log_cyboi_model.h"

#include "constant/model/cyboi/operation_mode/operation_mode_cyboi_model.h"

#include "constant/model/cyboi/option/log_level_option_cyboi_model.h"

#include "constant/model/cyboi/state/boolean_state_cyboi_model.h"
#include "constant/model/cyboi/state/double_state_cyboi_model.h"
#include "constant/model/cyboi/state/extra_integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/mathematics_state_cyboi_model.h"
#include "constant/model/cyboi/state/negative_integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/pointer_state_cyboi_model.h"
#include "constant/model/cyboi/state/state_cyboi_model.h"

#include "constant/model/cyboi/state/colour/terminal_colour_state_cyboi_model.h"

#include "constant/model/cybol/border/border_cybol_model.h"

#include "constant/model/cybol/colour/terminal_colour_cybol_model.h"

#include "constant/model/cybol/device/terminal_device_cybol_model.h"

#include "constant/model/cybol/display/mode_display_cybol_model.h"

#include "constant/model/cybol/http/request_http_cybol_model.h"

#include "constant/model/cybol/layout/border_layout_cybol_model.h"
#include "constant/model/cybol/layout/direction_layout_cybol_model.h"
#include "constant/model/cybol/layout/layout_cybol_model.h"
#include "constant/model/cybol/layout/stretch_layout_cybol_model.h"

#include "constant/model/cybol/logic/element_create_logic_cybol_model.h"
#include "constant/model/cybol/logic/selection_compare_logic_cybol_model.h"
#include "constant/model/cybol/logic/selection_count_logic_cybol_model.h"

#include "constant/model/cybol/shape/shape_cybol_model.h"

#include "constant/model/cybol/socket/address_socket_cybol_model.h"
#include "constant/model/cybol/socket/mode_socket_cybol_model.h"
#include "constant/model/cybol/socket/namespace_socket_cybol_model.h"
#include "constant/model/cybol/socket/protocol_socket_cybol_model.h"
#include "constant/model/cybol/socket/service_socket_cybol_model.h"
#include "constant/model/cybol/socket/style_socket_cybol_model.h"

#include "constant/model/cybol/state/boolean_state_cybol_model.h"
#include "constant/model/cybol/state/empty_state_cybol_model.h"

#include "constant/model/cybol/xcb/cap_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/event_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/fill_rule_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/fill_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/join_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/line_style_xcb_cybol_model.h"

#include "constant/model/eeb/error_code_eeb_model.h"

#include "constant/model/file/open_mode_file_model.h"

#include "constant/model/html/document_type_html_model.h"
#include "constant/model/html/tag_html_model.h"

#include "constant/model/http/protocol_version_http_model.h"
#include "constant/model/http/request_method_http_model.h"
#include "constant/model/http/status_code_http_model.h"
#include "constant/model/http/webdav_request_method_http_model.h"

#include "constant/model/json/json_model.h"

#include "constant/model/language/lcid_language_model.h"

#include "constant/model/numeral/base_numeral_model.h"

#include "constant/model/service/port_service_model.h"
#include "constant/model/service/protocol_service_model.h"

#include "constant/model/terminal/key_code_terminal_model.h"

#include "constant/model/text/ascii_newline_text_model.h"
#include "constant/model/text/newline_text_model.h"

#include "constant/model/time_scale/astronomy_time_scale_model.h"
#include "constant/model/time_scale/calendar_time_scale_model.h"
#include "constant/model/time_scale/duration_time_scale_model.h"
#include "constant/model/time_scale/gregorian_calendar_time_scale_model.h"
#include "constant/model/time_scale/julian_date_time_scale_model.h"
#include "constant/model/time_scale/week_time_scale_model.h"

#include "constant/model/uri/scheme_uri_model.h"
#include "constant/model/uri/separator_uri_model.h"

//
// name
//

#include "constant/name/authority/separator_authority_name.h"

#include "constant/name/binary/termination_binary_name.h"

#include "constant/name/character_reference/character_reference_name.h"

#include "constant/name/command_option/unix/archive_unix_command_option_name.h"
#include "constant/name/command_option/unix/change_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/change_permission_unix_command_option_name.h"
#include "constant/name/command_option/unix/compare_files_unix_command_option_name.h"
#include "constant/name/command_option/unix/config_network_unix_command_option_name.h"
#include "constant/name/command_option/unix/copy_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/create_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/date_unix_command_option_name.h"
#include "constant/name/command_option/unix/disk_free_unix_command_option_name.h"
#include "constant/name/command_option/unix/disk_usage_unix_command_option_name.h"
#include "constant/name/command_option/unix/display_content_unix_command_option_name.h"
#include "constant/name/command_option/unix/echo_message_unix_command_option_name.h"
#include "constant/name/command_option/unix/find_command_unix_command_option_name.h"
#include "constant/name/command_option/unix/find_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/help_unix_command_option_name.h"
#include "constant/name/command_option/unix/hostname_unix_command_option_name.h"
#include "constant/name/command_option/unix/id_unix_command_option_name.h"
#include "constant/name/command_option/unix/ifconfig_unix_command_option_name.h"
#include "constant/name/command_option/unix/ifup_unix_command_option_name.h"
#include "constant/name/command_option/unix/kill_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_directory_contents_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_open_files_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_tasks_unix_command_option_name.h"
#include "constant/name/command_option/unix/memory_free_unix_command_option_name.h"
#include "constant/name/command_option/unix/move_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/netstat_unix_command_option_name.h"
#include "constant/name/command_option/unix/ping_unix_command_option_name.h"
#include "constant/name/command_option/unix/present_working_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/remove_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/shell_unix_command_option_name.h"
#include "constant/name/command_option/unix/sort_unix_command_option_name.h"
#include "constant/name/command_option/unix/spellcheck_unix_command_option_name.h"
#include "constant/name/command_option/unix/system_messages_unix_command_option_name.h"
#include "constant/name/command_option/unix/tape_archiver_unix_command_option_name.h"
#include "constant/name/command_option/unix/top_unix_command_option_name.h"
#include "constant/name/command_option/unix/touch_unix_command_option_name.h"
#include "constant/name/command_option/unix/userlog_unix_command_option_name.h"
#include "constant/name/command_option/unix/who_unix_command_option_name.h"
#include "constant/name/command_option/unix/word_count_unix_command_option_name.h"

#include "constant/name/command_option/win32/change_directory_win32_command_option_name.h"
#include "constant/name/command_option/win32/compare_files_win32_command_option_name.h"
#include "constant/name/command_option/win32/config_network_win32_command_option_name.h"
#include "constant/name/command_option/win32/copy_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/date_win32_command_option_name.h"
#include "constant/name/command_option/win32/display_content_win32_command_option_name.h"
#include "constant/name/command_option/win32/echo_message_win32_command_option_name.h"
#include "constant/name/command_option/win32/find_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/help_win32_command_option_name.h"
#include "constant/name/command_option/win32/kill_win32_command_option_name.h"
#include "constant/name/command_option/win32/list_directory_contents_win32_command_option_name.h"
#include "constant/name/command_option/win32/list_tasks_win32_command_option_name.h"
#include "constant/name/command_option/win32/memory_free_win32_command_option_name.h"
#include "constant/name/command_option/win32/move_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/ping_win32_command_option_name.h"
#include "constant/name/command_option/win32/remove_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/sort_win32_command_option_name.h"
#include "constant/name/command_option/win32/tape_archiver_win32_command_option_name.h"

#include "constant/name/csv/delimiter_csv_name.h"
#include "constant/name/csv/quotation_csv_name.h"

#include "constant/name/cyboi/authority/authority_cyboi_name.h"

#include "constant/name/cyboi/csv/csv_cyboi_name.h"

#include "constant/name/cyboi/http/header_http_cyboi_name.h"
#include "constant/name/cyboi/http/http_cyboi_name.h"
#include "constant/name/cyboi/http/variable_http_cyboi_name.h"

#include "constant/name/cyboi/http/header/entity_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/general_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/request_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/response_header_http_cyboi_name.h"

#include "constant/name/cyboi/json/json_cyboi_name.h"

#include "constant/name/cyboi/knowledge/memory_separator_knowledge_cyboi_name.h"
#include "constant/name/cyboi/knowledge/separator_knowledge_cyboi_name.h"

#include "constant/name/cyboi/option/option_cyboi_name.h"

#include "constant/name/cyboi/state/client_state_cyboi_name.h"
#include "constant/name/cyboi/state/complex_state_cyboi_name.h"
#include "constant/name/cyboi/state/datetime_state_cyboi_name.h"
#include "constant/name/cyboi/state/duration_state_cyboi_name.h"
#include "constant/name/cyboi/state/fraction_state_cyboi_name.h"
#include "constant/name/cyboi/state/input_output_state_cyboi_name.h"
#include "constant/name/cyboi/state/internal_memory_state_cyboi_name.h"
#include "constant/name/cyboi/state/item_state_cyboi_name.h"
#include "constant/name/cyboi/state/part_state_cyboi_name.h"
#include "constant/name/cyboi/state/primitive_state_cyboi_name.h"
#include "constant/name/cyboi/state/server_state_cyboi_name.h"
#include "constant/name/cyboi/state/vector_state_cyboi_name.h"

#include "constant/name/cyboi/uri/uri_cyboi_name.h"

#include "constant/name/cybol/cybol_name.h"
#include "constant/name/cybol/super_cybol_name.h"
#include "constant/name/cybol/xml_cybol_name.h"

#include "constant/name/cybol/logic/access/count_access_logic_cybol_name.h"
#include "constant/name/cybol/logic/access/get_access_logic_cybol_name.h"
#include "constant/name/cybol/logic/access/get_index_access_logic_cybol_name.h"
#include "constant/name/cybol/logic/access/indicate_access_logic_cybol_name.h"

#include "constant/name/cybol/logic/activation/disable_activation_logic_cybol_name.h"
#include "constant/name/cybol/logic/activation/enable_activation_logic_cybol_name.h"

#include "constant/name/cybol/logic/calculation/calculation_logic_cybol_name.h"

#include "constant/name/cybol/logic/cast/cast_logic_cybol_name.h"

#include "constant/name/cybol/logic/commander/archive_file_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/change_directory_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/change_permission_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/clear_screen_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/compare_files_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/config_network_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/copy_file_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/create_directory_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/date_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/delay_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/diff_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/disk_free_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/disk_usage_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/display_content_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/echo_message_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/find_command_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/find_file_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/grep_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/help_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/hostname_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/id_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/ifconfig_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/ifup_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/kill_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/list_directory_contents_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/list_open_files_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/list_tasks_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/memory_free_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/move_file_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/netstat_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/ping_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/present_working_directory_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/remove_file_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/sort_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/spellcheck_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/system_messages_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/tape_archiver_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/top_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/touch_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/traceroute_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/userlog_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/who_commander_logic_cybol_name.h"
#include "constant/name/cybol/logic/commander/word_count_commander_logic_cybol_name.h"

#include "constant/name/cybol/logic/communication/identify_communication_logic_cybol_name.h"
#include "constant/name/cybol/logic/communication/receive_communication_logic_cybol_name.h"
#include "constant/name/cybol/logic/communication/send_communication_logic_cybol_name.h"

#include "constant/name/cybol/logic/comparison/comparison_logic_cybol_name.h"

#include "constant/name/cybol/logic/containment/containment_logic_cybol_name.h"

#include "constant/name/cybol/logic/conversion/decode_conversion_logic_cybol_name.h"
#include "constant/name/cybol/logic/conversion/encode_conversion_logic_cybol_name.h"

#include "constant/name/cybol/logic/dispatching/close_dispatching_logic_cybol_name.h"
#include "constant/name/cybol/logic/dispatching/open_dispatching_logic_cybol_name.h"

#include "constant/name/cybol/logic/feeling/sense_feeling_logic_cybol_name.h"
#include "constant/name/cybol/logic/feeling/suspend_feeling_logic_cybol_name.h"

#include "constant/name/cybol/logic/flow/branch_flow_logic_cybol_name.h"
#include "constant/name/cybol/logic/flow/loop_flow_logic_cybol_name.h"
#include "constant/name/cybol/logic/flow/sequence_flow_logic_cybol_name.h"

#include "constant/name/cybol/logic/logic/logic_logic_cybol_name.h"

#include "constant/name/cybol/logic/maintenance/shutdown_maintenance_logic_cybol_name.h"
#include "constant/name/cybol/logic/maintenance/startup_maintenance_logic_cybol_name.h"

#include "constant/name/cybol/logic/manipulation/manipulation_logic_cybol_name.h"

#include "constant/name/cybol/logic/memory/create_memory_logic_cybol_name.h"
#include "constant/name/cybol/logic/memory/destroy_memory_logic_cybol_name.h"

#include "constant/name/cybol/logic/modification/modification_logic_cybol_name.h"

#include "constant/name/cybol/logic/randomisation/retrieve_randomisation_logic_cybol_name.h"
#include "constant/name/cybol/logic/randomisation/sow_randomisation_logic_cybol_name.h"

#include "constant/name/cybol/logic/representation/representation_logic_cybol_name.h"

#include "constant/name/cybol/logic/run/programme_run_logic_cybol_name.h"
#include "constant/name/cybol/logic/run/sleep_run_logic_cybol_name.h"

#include "constant/name/cybol/logic/sort/sort_logic_cybol_name.h"

#include "constant/name/cybol/logic/streaming/read_streaming_logic_cybol_name.h"
#include "constant/name/cybol/logic/streaming/write_streaming_logic_cybol_name.h"

#include "constant/name/cybol/logic/timing/current_timing_logic_cybol_name.h"

#include "constant/name/cybol/state/handler_state_cybol_name.h"
#include "constant/name/cybol/state/language_state_cybol_name.h"
#include "constant/name/cybol/state/message_state_cybol_name.h"
#include "constant/name/cybol/state/separator_date_state_cybol_name.h"
#include "constant/name/cybol/state/separator_duration_state_cybol_name.h"
#include "constant/name/cybol/state/separator_number_state_cybol_name.h"
#include "constant/name/cybol/state/separator_time_state_cybol_name.h"

#include "constant/name/cybol/state/gui/event_gui_state_cybol_name.h"
#include "constant/name/cybol/state/gui/gui_state_cybol_name.h"

#include "constant/name/cybol/state/keyboard/keyboard_state_cybol_name.h"

#include "constant/name/cybol/state/layout/grid_layout_state_cybol_name.h"

#include "constant/name/cybol/state/tui/tui_state_cybol_name.h"

#include "constant/name/cybol/state/wui/tag_wui_state_cybol_name.h"

#include "constant/name/ftp/separator_ftp_name.h"

#include "constant/name/http/header_http_name.h"
#include "constant/name/http/separator_http_name.h"
#include "constant/name/http/variable_http_name.h"

#include "constant/name/http/header/entity_header_http_name.h"
#include "constant/name/http/header/general_header_http_name.h"
#include "constant/name/http/header/request_header_http_name.h"
#include "constant/name/http/header/response_header_http_name.h"

#include "constant/name/http_request_uri/http_request_uri_name.h"

#include "constant/name/imf/field_header_imf_name.h"
#include "constant/name/imf/separator_imf_name.h"

#include "constant/name/json/json_name.h"

#include "constant/name/numeral/base_numeral_name.h"
#include "constant/name/numeral/decimal_numeral_name.h"
#include "constant/name/numeral/exponent_numeral_name.h"
#include "constant/name/numeral/fraction_numeral_name.h"
#include "constant/name/numeral/power_numeral_name.h"
#include "constant/name/numeral/sign_numeral_name.h"
#include "constant/name/numeral/thousands_numeral_name.h"

#include "constant/name/percent_encoding/percent_encoding_name.h"

#include "constant/name/uri/separator_uri_name.h"

#include "constant/name/xml/xml_name.h"

//
// type
//

#include "constant/type/cyboi/state_cyboi_type.h"

/* CONSTANT_HEADER */
#endif
