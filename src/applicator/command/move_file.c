/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MOVE_FILE_SOURCE
#define MOVE_FILE_SOURCE

#include <unistd.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/commander/move_file_commander_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../executor/commander/unix/move_file_unix_commander.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifdef WIN32
    #include "../../executor/commander/windows/move_file_windows_commander.c"
    #include "../../constant/model/command/win32_command_model.c"
#endif

/**
 * Moving files and directories from a path to another.
 *
 * Expected parametres:
 * - source (required): the path of the file or the directory which sould be moved
 * - destination (required): the new path of the source file or directory
 * - force (optional): the force option (never ask for permission to move any files or directories)
 * - interactive (optional): the interactive option (askes everytime for permission of moving a file or directory)
 * - verbal(optional): the verbal option (shows what have been moved)
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_move_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply move file.");

    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item data and count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item data and count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part.
    get_part_knowledge((void*) &s, p0, (void*) SOURCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SOURCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get destination part.
    get_part_knowledge((void*) &d, p0, (void*) DESTINATION_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) DESTINATION_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get force part.
    get_part_knowledge((void*) &f, p0, (void*) FORCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) FORCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get interactive part.
    get_part_knowledge((void*) &i, p0, (void*) INTERACTIVE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) INTERACTIVE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get verbal part.
    get_part_knowledge((void*) &v, p0, (void*) VERBAL_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) VERBAL_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);


    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get force part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get interactive part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get verbal part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);


    // Get source part model item data and count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get destination part model item data and count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get force part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get interactive part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get verbal part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);


#ifdef GNU_LINUX_OPERATING_SYSTEM
    move_file_unix_commander(smd, smc, dmd, dmc, fmd, imd, vmd);
#endif

#ifdef WIN32
    move_file_windows_commander(smd, smc, dmd, dmc, fmd, imd);
#endif
}

/* MOVE_FILE_SOURCE */
#endif
