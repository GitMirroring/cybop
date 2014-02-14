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

#ifndef COPY_FILE_SOURCE
#define COPY_FILE_SOURCE

#include <unistd.h>

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/commander/copy_file_commander_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"
#include "../../executor/commander/basic/copy_file_commander.c"

#ifdef __APPLE__
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/copy_file_unix_command_option_name.c"
#elif WIN32
    #include "../../../constant/model/command/win32_command_model.c"
    #include "../../../constant/name/command_option/win32/copy_file_win32_command_option_name.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/copy_file_unix_command_option_name.c"
#else
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/copy_file_unix_command_option_name.c"
#endif

/**
 * Copies the file resource to a destination.
 *
 * Expected parametres:
 * - source (required): the source to be copied
 * - destination (required): the destination to copy to
 * - force (optional): the force option for not asking for permission for overwriting files or directories
 * - interactive (optional): the interactive option which askes everytime for permission of overwriting a file or directory
 * - preserve_all_attributes (optional): copied files and directories will have the same attributes as the originals
 * - preserve_links (optional): preserves links so that they are not dereferenced while copying
 * - recursive (optional): the option indicating that all sub directories should be copied as well
 * - update (optional): the update option which just copies more recent data to a destination path
 * - verbal (optional): shows which files and directories are being copied
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_copy_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply copy file.");

    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preserve all attributes part.
    void* paa = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preserve links part.
    void* pl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The preserve all attributes part model item.
    void* paam = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preserve links part model item.
    void* plm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part model item.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source path part model item data and count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item data and count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interactive part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preserve all attributes part model item data.
    void* paamd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preserve links part model item data.
    void* plmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part model item data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part.
    get_part_knowledge((void*) &s, p0, (void*) SOURCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SOURCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get destination part.
    get_part_knowledge((void*) &d, p0, (void*) DESTINATION_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) DESTINATION_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get force part.
    get_part_knowledge((void*) &f, p0, (void*) FORCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) FORCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get interactive part.
    get_part_knowledge((void*) &i, p0, (void*) INTERACTIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) INTERACTIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get preserve all attributes part.
    get_part_knowledge((void*) &paa, p0, (void*) PRESERVE_ALL_ATTRIBUTES_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PRESERVE_ALL_ATTRIBUTES_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get preserve links part.
    get_part_knowledge((void*) &pl, p0, (void*) PRESERVE_LINKS_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PRESERVE_LINKS_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get recursive part.
    get_part_knowledge((void*) &r, p0, (void*) RECURSIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) RECURSIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get update part.
    get_part_knowledge((void*) &u, p0, (void*) UPDATE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) UPDATE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get verbal part.
    get_part_knowledge((void*) &v, p0, (void*) VERBAL_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) VERBAL_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get force part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get interactive part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get preserve all attributes part model item.
    copy_array_forward((void*) &paam, paa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get preserve links part model item.
    copy_array_forward((void*) &plm, pl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get recursive part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get update part model item.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
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
    // Get preserve all attributes part model item data.
    copy_array_forward((void*) &paamd, paam, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get preserve all attributes part model item data.
    copy_array_forward((void*) &plmd, plm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get recursive part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get update part model item data.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get verbal part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    copy_file_unix_commander(smd, smc, dmd, dmc, fmd, imd, paamd, plmd, rmd, umd, vmd);

}
/* COPY_FILE_SOURCE */
#endif
