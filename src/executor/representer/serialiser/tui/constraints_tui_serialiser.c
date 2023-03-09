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

#ifndef CONSTRAINTS_TUI_SERIALISER_SOURCE
#define CONSTRAINTS_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/language_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part/name_part_getter.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/serialiser/tui/initial_tui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Retrieves language properties (constraints) necessary for serialisation.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the language properties (constraints) data
 * @param p6 the language properties (constraints) count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the format
 */
void serialise_tui_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui constraints.");
    //?? fwprintf(stdout, L"Debug: Serialise tui constraints. source model count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Serialise tui constraints. source model count *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The newline part.
    void* nl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The positioning part.
    void* po = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sign flag part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number base part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The classic octal prefix flag part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal places part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The scientific notation flag part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The newline part model item.
    void* nlm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part model item.
    void* clm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The positioning part model item.
    void* pom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sign flag part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number base part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The classic octal prefix flag part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal places part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The scientific notation part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The newline part model item data.
    void* nlmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clear part model item data.
    void* clmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The positioning part model item data.
    void* pomd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sign flag part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number base part model item data, count.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The classic octal prefix flag part model item data, count.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part model item data, count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal places part model item data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The scientific notation part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get newline part.
    get_part_name((void*) &nl, p5, (void*) NEWLINE_LANGUAGE_STATE_CYBOL_NAME, (void*) NEWLINE_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get clear part.
    get_part_name((void*) &cl, p5, (void*) CLEAR_LANGUAGE_STATE_CYBOL_NAME, (void*) CLEAR_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get positioning part.
    get_part_name((void*) &po, p5, (void*) POSITIONING_LANGUAGE_STATE_CYBOL_NAME, (void*) POSITIONING_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get sign flag part.
    get_part_name((void*) &s, p5, (void*) SIGN_LANGUAGE_STATE_CYBOL_NAME, (void*) SIGN_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get number base part.
    get_part_name((void*) &b, p5, (void*) BASE_LANGUAGE_STATE_CYBOL_NAME, (void*) BASE_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get classic octal prefix flag part.
    get_part_name((void*) &c, p5, (void*) CLASSICOCTAL_LANGUAGE_STATE_CYBOL_NAME, (void*) CLASSICOCTAL_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get decimal separator part.
    get_part_name((void*) &d, p5, (void*) SEPARATOR_LANGUAGE_STATE_CYBOL_NAME, (void*) SEPARATOR_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get decimal places part.
    get_part_name((void*) &p, p5, (void*) DECIMALS_LANGUAGE_STATE_CYBOL_NAME, (void*) DECIMALS_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);
    // Get scientific notation part.
    get_part_name((void*) &n, p5, (void*) SCIENTIFIC_LANGUAGE_STATE_CYBOL_NAME, (void*) SCIENTIFIC_LANGUAGE_STATE_CYBOL_NAME_COUNT, p6, p7, p8, p9);

    // Get newline part model item.
    copy_array_forward((void*) &nlm, nl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get clear part model item.
    copy_array_forward((void*) &clm, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get positioning part model item.
    copy_array_forward((void*) &pom, po, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sign flag part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get number base part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get classic octal prefix flag part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get decimal separator part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get decimal places part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get scientific notation part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get newline part model item data.
    copy_array_forward((void*) &nlmd, nlm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get clear part model item data.
    copy_array_forward((void*) &clmd, clm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get positioning part model item data.
    copy_array_forward((void*) &pomd, pom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get sign flag part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get number base part model item data, count.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get classic octal prefix flag part model item data, count.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get decimal separator part model item data, count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get decimal places part model item data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get scientific notation part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // Set newline flag to TRUE (enabled) by default.
    int newline = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    // Set clear flag to FALSE (disabled) by default.
    int clear = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // Set positioning flag to FALSE (disabled) by default.
    int positioning = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    copy_integer((void*) &newline, nlmd);
    copy_integer((void*) &clear, clmd);
    copy_integer((void*) &positioning, pomd);

    //
    // Functionality
    //

    // Initialise tui serialiser.
    serialise_tui_initial(p0, p1, p2, p3, p4, smd, bmd, cmd, dmd, dmc, pmd, nmd, (void*) &newline, (void*) &clear, (void*) &positioning, p7, p8, p9, p10);
}

/* CONSTRAINTS_TUI_SERIALISER_SOURCE */
#endif
