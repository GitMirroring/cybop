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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REMOVE_FILE_SOURCE
#define REMOVE_FILE_SOURCE

#include <unistd.h>

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/commander/remove_file_commander_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"


#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../executor/commander/unix_commander/remove_file_unix_commander.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifdef WIN32
    #include "../../executor/commander/windows_commander/remove_file_windows_commander.c"
    #include "../../constant/model/command/win32_command_model.c"
#endif

/**
 * Removing files and directories from a path.
 *
 * Expected parametres:
 * - path: the path including wildcards for deleting files and directories

 * - interactive (optional): the interactive option (askes everytime for permission of deleting a file or directory)
 * - recursive(optional): the recursvie option (deletes any files in the current directory and in all of its subdirectories)
 * - verbal(optional): the verbal option (shows what have been deleted)
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_remove_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply remove file.");

    // The path part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item data and count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursvie part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get path part.
    get_part_knowledge((void*) &p, p0, (void*) PATH_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get force part.
    get_part_knowledge((void*) &f, p0, (void*) FORCE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) FORCE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get interactive part.
    get_part_knowledge((void*) &i, p0, (void*) INTERACTIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) INTERACTIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get recursive part.
    get_part_knowledge((void*) &r, p0, (void*) RECURSIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) RECURSIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get verbal part.
    get_part_knowledge((void*) &v, p0, (void*) VERBAL_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) RECURSIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);


    // Get path part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get force part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get interactive part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get recursive part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get verbal part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);


    // Get path part model item data and count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get force part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get interactive part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get recursive part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get verbal part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);


#ifdef GNU_LINUX_OPERATING_SYSTEM
    remove_file_unix_commander(pmd, pmc, fmd, imd, rmd, vmd);
#endif

#ifdef WIN32
    remove_file_windows_commander(pmd, pmc, fmd, imd, rmd);
#endif
}

/* REMOVE_FILE_SOURCE */
#endif
