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

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

//
// Library interface
//

#include "applicator_library.h"

//
// Executable interface
//

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Handles the operation.
 *
 * @param p0 the properties parametres data
 * @param p1 the properties parametres count
 * @param p2 the internal memory data
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the signal memory item
 * @param p6 the internal memory data (pointer reference)
 * @param p7 the shutdown flag
 * @param p8 the operation format
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle operation.");
    //?? fwprintf(stdout, L"Debug: Handle operation. p8: %i\n", p8);
    //?? fwprintf(stdout, L"Debug: Handle operation. p8: %i\n", *((int*) p8));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // access
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) COUNT_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_count(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_indicate(p0, p1, p3, p4, p2, (void*) EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_indicate(p0, p1, p3, p4, p2, (void*) EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FORMAT_GET_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_get(p0, p1, p3, p4, p2, (void*) FORMAT_GET_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GET_INDEX_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_get_index(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_get(p0, p1, p3, p4, p2, (void*) NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TYPE_GET_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_get(p0, p1, p3, p4, p2, (void*) TYPE_GET_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // activate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DISABLE_ACTIVATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_disable(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ENABLE_ACTIVATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_enable(p0, p1, p3, p4, p2);
        }
    }

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MAXIMUM_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) MAXIMUM_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MINIMUM_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) MINIMUM_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MODULO_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) MODULO_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // cast
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CHARACTER_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, p4, p2, (void*) CHARACTER_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DOUBLE_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, p4, p2, (void*) DOUBLE_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) INTEGER_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, p4, p2, (void*) INTEGER_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // check
    //
    // CAUTION! The COMPARE_LOGIC_CYBOI_FORMAT (and NOT CHECK_LOGIC_CYBOI_FORMAT)
    // constants are handed over as argument to function "apply_compare".
    //
    // The last argument is a flag indicating that lexicographic comparison is to be used.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GREATER_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GREATER_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LESS_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LESS_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) UNEQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // command
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ARCHIVE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_archive_file(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_change_directory(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CHANGE_PERMISSION_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_change_permission(p0, p1, p3, p4, p2);
        }
    }

     if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CLEAR_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_clear_screen(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CONFIG_NETWORK_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_config_network(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) COMPARE_FILES_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare_files(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) COPY_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_copy_file(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CREATE_DIRECTORY_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_create_directory(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DATE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_date(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DELAY_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_delay(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DIFF_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_diff(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DISK_FREE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_disk_free(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DISK_USAGE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_disk_usage(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DISPLAY_CONTENT_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_display_content(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ECHO_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_echo_message(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FIND_COMMAND_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_find_command(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FIND_FILE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_find_file(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GREP_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_grep(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) HELP_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_help(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) HOSTNAME_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_hostname(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ID_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_id(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) IFCONFIG_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_ifconfig(p0, p1, p3, p4, p2);
        }
    }

     if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) IFUP_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_ifup();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) KILL_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_kill(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_list_directory_contents(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LIST_OPEN_FILES_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_list_open_files(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LIST_TASKS_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_list_tasks(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MEMORY_FREE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_memory_free(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) MOVE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_move_file(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NETSTAT_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_netstat(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) PING_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_ping(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) PWD_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_pwd(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REMOVE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_remove_file(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SORT_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_command_sort(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SPELLCHECK_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_spellcheck(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SYSTEM_MESSAGES_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_system_messages(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TAPE_ARCHIVER_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_tape_archiver(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TOP_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_top(p0, p1, p3, p4, p2);
        }
    }

     if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TOUCH_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_touch(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TRACEROUTE_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_traceroute(p0, p1, p3, p4, p2);
        }
    }


     if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) USERLOG_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_userlog(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) WHO_AM_I_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_who_am_i();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) WHO_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_who(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) WORD_COUNT_COMMAND_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_word_count(p0, p1, p3, p4, p2);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) IDENTIFY_COMMUNICATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_identify(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_receive(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SEND_COMMUNICATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_send(p0, p1, p3, p4, p2);
        }
    }

    //
    // compare
    //
    // CAUTION! The last argument is a flag indicating that lexicographic comparison is NOT used.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, p4, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // contain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ANY_CONTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) ANY_CONTAIN_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LEFT_CONTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) LEFT_CONTAIN_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) RIGHT_CONTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) RIGHT_CONTAIN_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DECODE_CONVERT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_decode(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ENCODE_CONVERT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_encode(p0, p1, p3, p4, p2);
        }
    }

    //
    // dispatch
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CLOSE_DISPATCH_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_close(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) OPEN_DISPATCH_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_open(p0, p1, p3, p4, p2, p6);
        }
    }

    //
    // feel
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SENSE_FEEL_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sense(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SUSPEND_FEEL_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_suspend(p0, p1, p3, p4, p2);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) BRANCH_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_branch(p0, p1, p3, p4, p2, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LOOP_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_loop(p0, p1, p3, p4, p2, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SEQUENCE_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sequence(p0, p1, p3, p4, p2, p5, p6, p7);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EXIT_LIVE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set exit flag.");
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) AND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) AND_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NAND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) NAND_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) NOR_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NOT_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) NOT_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NEG_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) NEG_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) OR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) OR_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) XNOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) XNOR_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) XOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_logify(p0, p1, p3, p4, p2, (void*) XOR_LOGIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_shutdown(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) STARTUP_MAINTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_startup(p0, p1, p3, p4, p2, p6);
        }
    }

    //
    // manipulate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SET_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) SET_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, p4, p2, (void*) TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CREATE_MEMORISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_create(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DESTROY_MEMORISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_destroy(p0, p1, p3, p4, p2);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) LOWER_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) LOWER_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NORMALISE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) NORMALISE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REPEAT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) REPEAT_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REPLACE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) REPLACE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) REVERSE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) REVERSE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) STRIP_LEADING_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) STRIP_LEADING_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) STRIP_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) STRIP_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) STRIP_TRAILING_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) STRIP_TRAILING_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) UPPER_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_modify(p0, p1, p3, p4, p2, (void*) UPPER_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // randomise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) RETRIEVE_RANDOMISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_retrieve(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SOW_RANDOMISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sow(p0, p1, p3, p4, p2);
        }
    }

    //
    // represent
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DESERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_deserialise(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_serialise(p0, p1, p3, p4, p2);
        }
    }

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_run(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sleep(p0, p1, p3, p4, p2, (void*) NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sleep(p0, p1, p3, p4, p2, (void*) SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // sort
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) BUBBLE_SORT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sort(p0, p1, p3, p4, p2, (void*) BUBBLE_SORT_LOGIC_CYBOI_FORMAT);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) INSERTION_SORT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sort(p0, p1, p3, p4, p2, (void*) INSERTION_SORT_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) QUICK_SORT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sort(p0, p1, p3, p4, p2, (void*) QUICK_SORT_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SELECTION_SORT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sort(p0, p1, p3, p4, p2, (void*) SELECTION_SORT_LOGIC_CYBOI_FORMAT);
        }
    }
*/

    //
    // stream
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) READ_STREAM_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_read(p0, p1, p3, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) WRITE_STREAM_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_write(p0, p1, p3, p4, p2);
        }
    }

    //
    // time
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) CURRENT_TIME_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_time(p0, p1, p3, p4, p2);
        }
    }

    //
    // unknown
    //
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, "Could not handle operation. The operation is unknown.");
        fwprintf(stdout, L"Warning: Could not handle operation. The operation is unknown. p8: %i\n", p8);
        fwprintf(stdout, L"Warning: Could not handle operation. The operation is unknown. *p8: %i\n", *((int*) p8));
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
