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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CYBOL_HEADER
#define CYBOL_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// channel
//

#include "constant/channel/cybol/cybol_channel.h"

//
// encoding
//

#include "constant/encoding/cybol/base_cybol_encoding.h"
#include "constant/encoding/cybol/cybol_encoding.h"
#include "constant/encoding/cybol/dos_cybol_encoding.h"
#include "constant/encoding/cybol/iso_8859_cybol_encoding.h"
#include "constant/encoding/cybol/unicode_cybol_encoding.h"
#include "constant/encoding/cybol/windows_cybol_encoding.h"

//
// format
//

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

#include "constant/language/cybol/state/application_state_cybol_language.h"
#include "constant/language/cybol/state/chronology_state_cybol_language.h"
#include "constant/language/cybol/state/interface_state_cybol_language.h"
#include "constant/language/cybol/state/message_state_cybol_language.h"
#include "constant/language/cybol/state/number_state_cybol_language.h"
#include "constant/language/cybol/state/text_state_cybol_language.h"

//
// model
//

#include "constant/model/cybol/border/border_cybol_model.h"

#include "constant/model/cybol/display/mode_display_cybol_model.h"

#include "constant/model/cybol/logic/element_create_logic_cybol_model.h"
#include "constant/model/cybol/logic/selection_compare_logic_cybol_model.h"
#include "constant/model/cybol/logic/selection_count_logic_cybol_model.h"

#include "constant/model/cybol/shape/shape_cybol_model.h"

//
// name
//

#include "constant/name/cyboi/knowledge/memory_separator_knowledge_cyboi_name.h"
#include "constant/name/cyboi/knowledge/separator_knowledge_cyboi_name.h"

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

#include "constant/name/cybol/state/keyboard/keyboard_state_cybol_name.h"

#include "constant/name/cybol/state/wui/tag_wui_state_cybol_name.h"

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
// cybol
//

void deserialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_cybol_byte(void* p0, void* p1, void* p2);
void deserialise_cybol_channel(void* p0, void* p1, void* p2);
void deserialise_cybol_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_cybol_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_cybol_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_cybol_encoding(void* p0, void* p1, void* p2);
void deserialise_cybol_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_cybol_format(void* p0, void* p1, void* p2);
void deserialise_cybol_language(void* p0, void* p1, void* p2);
void deserialise_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21);
void deserialise_cybol_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_cybol_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_cybol_standard(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20);
void deserialise_cybol_test(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_cybol_type(void* p0, void* p1);

void serialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_cybol_byte(void* p0, void* p1, void* p2);
void serialise_cybol_channel(void* p0, void* p1);
void serialise_cybol_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_cybol_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_cybol_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void serialise_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_cybol_encoding(void* p0, void* p1);
void serialise_cybol_format(void* p0, void* p1);
void serialise_cybol_language(void* p0, void* p1);
void serialise_cybol_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_cybol_type(void* p0, void* p1);

//
// knowledge
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_knowledge_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_knowledge_identification(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_knowledge_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_knowledge_reference(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

void select_knowledge_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void select_knowledge_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_knowledge_identification(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void select_knowledge_memory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_knowledge_move(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_knowledge_root(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

//
// model diagram
//

void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_model_diagram_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_model_diagram_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void serialise_model_diagram_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_model_diagram_indentation(void* p0, void* p1, void* p2);
void serialise_model_diagram_indentation_branch(void* p0, void* p1);
void serialise_model_diagram_indentation_line(void* p0, void* p1, void* p2, void* p3);
void serialise_model_diagram_line(void* p0);
void serialise_model_diagram_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/* CYBOL_HEADER */
#endif
