/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NETSTAT_COMMANDER_SOURCE
#define NETSTAT_COMMANDER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../variable/reallocation_factor.c"

//
// CAUTION! The options of many commands are SIMILAR on various platforms.
// Therefore, it might suffice to distinguish included files here
// and use IDENTICAL CONSTANTS whose values are determined
// by the include they stem from.
//
// However, there ARE commands on some platforms that do NOT
// exist on another. The same is true for command options.
// Therefore, it makes sense to distinguish between platforms
// at EVERY option, even if that produces some redundant code.
//
#ifdef __APPLE__
    #include "../../constant/name/command_option/unix/netstat_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#elif WIN32
    #include "../../constant/name/command_option/win32/netstat_win32_command_option_name.c"
    #include "../../constant/model/command/win32_command_model.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../constant/name/command_option/unix/netstat_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#else
    #include "../../constant/name/command_option/unix/netstat_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
* shows the netstat.
*
* @param rmd the rountingtable model data
* @param imd the interface model data
* @param gmd the groups model data
* @param smd the statistics model data
* @param mmd the masquerade model data
* @param vmd the long model data
* @param nmd the nohostname model data
* @param emd the extended model data
* @param pmd the program names model data
* @param lmd the listening sockets model data
* @param amd the all sockets model data
* @param omd the timers model data
* @param tmd the active connections model data
*
*
*/
void command_netstat(void* rmd, void* imd, void* gmd, void* smd, void* mmd, void* vmd, void* nmd, void* emd, void* pmd, void* lmd, void* amd, void* omd, void* tmd) {

  log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Command netstat.");


        // The arguments item.
        void* arg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The arguments item data, count.
        void* argd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* argc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate arguments item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &arg, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Append command.
#ifdef __APPLE__
        append_item_element(arg, (void*) NETSTAT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NETSTAT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
        append_item_element(arg, (void*) NETSTAT_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NETSTAT_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) NETSTAT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NETSTAT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
        append_item_element(arg, (void*) NETSTAT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NETSTAT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, rmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append routingtable option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
            append_item_element(arg, (void*) ROUTINGTABLE_NETSTAT_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROUTINGTABLE_NETSTAT_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, imd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append interface option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
}

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, gmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append groups option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, smd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append statistics option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, mmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append masquerade option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, vmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append long option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, nmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append no hostname option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, emd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append extended option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, pmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append program names option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, lmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append listening sockets option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, amd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append all sockets option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, omd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append timers option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, tmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append active connections option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
            append_item_element(arg, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32

#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
            append_item_element(arg, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

        }

        // Get arguments item data, count.
        copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Execute command line in shell.
        execute(argd, argc);

        // Deallocate arguments item.
        deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}


/* NETSTAT_COMMANDER_SOURCE */
#endif
