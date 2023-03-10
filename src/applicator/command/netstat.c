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

#ifndef NETSTAT_SOURCE
#define NETSTAT_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/commander/netstat_commander.c"
#include "../../logger/logger.c"

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Shows the netstat.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_netstat(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply netstat.");

    //
    // Declaration
    //

    // The routing table part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interface part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The groups part.
    void* g = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The statistics part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The masquerade part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The nohostname part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The extended part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The program names part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The listening sockets part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all sockets part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The timers part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The active connections part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The routing table part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interface part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The groups part model item.
    void* gm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The statistics part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The masquerade part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The nohostname part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The extended part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The program names part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The listening sockets part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all sockets part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The timers part model item.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The active connections part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The routing table part model item data and count.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interface part model item data and count.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The groups part model item data and count.
    void* gmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The statistics part model item data and count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The masquerade part model item data and count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item data and count.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The nohostname part model item data and count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The extended part model item data and count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The program names part model item data and count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The listening sockets part model item data and count.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all sockets part model item data and count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The timers part model item data and count.
    void* omd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The active connections part model item data and count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get routing table part.
    get_part_name((void*) &r, p0, (void*) ROUTINGTABLE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) ROUTINGTABLE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get interface part.
    get_part_name((void*) &i, p0, (void*) INTERFACE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) INTERFACE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get groups part.
    get_part_name((void*) &g, p0, (void*) GROUPS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) GROUPS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get statistics part.
    get_part_name((void*) &s, p0, (void*) STATISTICS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) STATISTICS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get masquerade part.
    get_part_name((void*) &m, p0, (void*) MASQUERADE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) MASQUERADE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get long part.
    get_part_name((void*) &v, p0, (void*) LONG_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) LONG_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get no hostname part.
    get_part_name((void*) &n, p0, (void*) NOHOST_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) NOHOST_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get extended part.
    get_part_name((void*) &e, p0, (void*) EXTENDED_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) EXTENDED_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get program names part.
    get_part_name((void*) &p, p0, (void*) PROGNAMES_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) PROGNAMES_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get listening sockets part.
    get_part_name((void*) &l, p0, (void*) LISTENSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) LISTENSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get all sockets part.
    get_part_name((void*) &a, p0, (void*) ALLSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALLSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get timers part.
    get_part_name((void*) &o, p0, (void*) TIMERS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) TIMERS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get active connections part.
    get_part_name((void*) &t, p0, (void*) ACTIVECONN_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME, (void*) ACTIVECONN_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get routing table part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get interface part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get groups part model item.
    copy_array_forward((void*) &gm, g, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get statistics part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get masquerade part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get long part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get no hostname part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get extended part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get Program names part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get listening sockets part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get all sockets part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get timers part model item.
    copy_array_forward((void*) &om, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get active connections part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get routing table part model item data and count.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get interface part model item data and count.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get groups part model item data and count.
    copy_array_forward((void*) &gmd, gm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get statistics part model item data and count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get masquerade part model item data and count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get long part model item data and count.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get no hostname part model item data and count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get extended part model item data and count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get Program names part model item data and count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get listening sockets part model item data and count.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get all sockets part model item data and count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get timers part model item data and count.
    copy_array_forward((void*) &omd, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get active connections part model item data and count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_netstat(rmd, imd, gmd, smd, mmd, vmd, nmd, emd, pmd, lmd, amd, omd, tmd);
}

/* NETSTAT_SOURCE */
#endif
