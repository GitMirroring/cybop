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

#ifndef TAPE_ARCHIVER_SOURCE
#define TAPE_ARCHIVER_SOURCE
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/commander/tape_archiver_commander_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

#ifdef __APPLE__
    #include "../../executor/commander/unix/tape_archiver_unix_commander.c"
    #include "../../constant/model/command/unix_command_model.c"
#elif WIN32
    #include "../../executor/commander/windows/tape_archiver_windows_commander.c"
    #include "../../constant/model/command/win32_command_model.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../executor/commander/unix/tape_archiver_unix_commander.c"
    #include "../../constant/model/command/unix_command_model.c"
#else
    #include "../../executor/commander/unix/tape_archiver_unix_commander.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

/**
 * Packs/Unpacks a directory or file
 *
 * Expected parametres:
 * - source (required): the source for archiving
 * - destination (required): the destination where the source is being archived
 * - force (optional): the force option for not asking for permission for overwriting files or directories
 * - gzip (optional): the gunzip option to indicate gunzip compression or extraction
 * - unpack (optional): the option for unpacking / extraction or else it will pack
 * - verbal (optional): shows which files and directories are being copied
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_tape_archiver(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply copy file.");

    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part.
    void* g = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part model item.
    void* gm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part model item.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source path part model item data and count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item data and count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exclude part model item data and count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part model item data.
    void* gmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part model item data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part.
    get_part_knowledge((void*) &s, p0, (void*) SOURCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) SOURCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get destination part.
    get_part_knowledge((void*) &d, p0, (void*) DESTINATION_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) DESTINATION_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get force part.
    get_part_knowledge((void*) &f, p0, (void*) FORCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) FORCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get gzip part.
    get_part_knowledge((void*) &g, p0, (void*) GZIP_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) GZIP_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get unpack part.
    get_part_knowledge((void*) &u, p0, (void*) UNPACK_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) UNPACK_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get verbal part.
    get_part_knowledge((void*) &v, p0, (void*) VERBAL_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) VERBAL_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2);


    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get force part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get gzip part model item.
    copy_array_forward((void*) &gm, g, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get unpack part model item.
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
    // Get gzip part model item data.
    copy_array_forward((void*) &gmd, gm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get unpack part model item data.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get verbal part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

#ifdef __APPLE__
    tape_archiver_unix_commander(smd, smc, dmd, dmc, fmd, gmd, umd, vmd);
#elif WIN32
    tape_archiver_windows_commander(smd, smc, dmd, dmc, fmd, gmd, umd, vmd);
#elif GNU_LINUX_OPERATING_SYSTEM
    tape_archiver_unix_commander(smd, smc, dmd, dmc, fmd, gmd, umd, vmd);
#else
    tape_archiver_unix_commander(smd, smc, dmd, dmc, fmd, gmd, umd, vmd);
#endif
}
/* TAPE_ARCHIVER_SOURCE */
#endif
