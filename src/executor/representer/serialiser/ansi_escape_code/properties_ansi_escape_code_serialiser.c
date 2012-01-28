/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/begin_tag_html_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the properties into ansi escape code.
 *
 * @param p0 the destination item
 * @param p1 the source properties data
 * @param p2 the source properties count
 * @param p3 the source whole properties data
 * @param p4 the source whole properties count
 */
void serialise_ansi_escape_code_properties(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code properties.");

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part.
    void* sh = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cell part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part.
    void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part.
    void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part.
    void* bo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hidden part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The inverse part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blink part.
    void* bl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The underline part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bold part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part.
    void* wp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part.
    void* ws = *NULL_POINTER_STATE_CYBOI_MODEL;

--
    // The tag part model.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The tag part model data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
--

    // The element name.
    void* en = *NULL_POINTER_STATE_CYBOI_MODEL;
    int enc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The remaining name.
    void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The loop count.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The name comparison result.
    int nr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The type comparison result.
    int ar = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get compound element (area to be repainted) name and remaining name,
    // as well as the flag indicating a part- or meta element.
    get_compound_element_name_and_remaining_name(p11, p12, (void*) &en, (void*) &enc, (void*) &rn, (void*) &rnc, (void*) &f);

    if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (f == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

        // Either, no hierarchical element name (repaint area) was given
        // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
        // but the whole textual user interface (tui) window is repainted,
        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
        // OR:
        // the expected compound element (area to be repainted) pointed to
        // by the hierarchical name is a "part" element (f == 0), not a "meta" element,
        // which is correct, so that the element can be processed/ repainted.

        // Get property parts by name.
        get_name_array((void*) &super, p1, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &sh, p1, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &l, p1, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &c, p1, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &p, p1, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &s, p1, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &bg, p1, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &fg, p1, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &bo, p1, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &h, p1, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &i, p1, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &bl, p1, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &u, p1, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);
        get_name_array((void*) &b, p1, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p2);

        //
        // Get default property parts from super part.
        //
        // If a standard property value DOES exist, it is NOT
        // overwritten with the default property value of the super part.
        // If a standard property value does NOT exist, the default
        // property value of the super part is used.
        //

        if (*sh == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &sh, supermd, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*l == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &l, supermd, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*c == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &c, supermd, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*p == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &p, supermd, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &s, supermd, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &bg, supermd, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &fg, supermd, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*bo == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &bo, supermd, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*h == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &h, supermd, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*i == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &i, supermd, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*bl == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &bl, supermd, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*u == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &u, supermd, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        if (*b == *NULL_POINTER_STATE_CYBOI_MODEL) {

            get_name_array((void*) &b, supermd, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc);
        }

        // Get property parts from whole part.
        get_name_array((void*) &wp, p3, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
        get_name_array((void*) &ws, p3, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
--
        compare_all_array((void*) &ar, p3, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT);

        if (ar != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The part model IS a compound.

            // CAUTION! Paint the compound's background etc.,
            // but do NOT hand over the model!
            // Since the model is a compound and not a valid character,
            // it will cause wrong characters or question marks to be printed on screen!
            // Therefore, do hand over a null pointer instead of the model!
            if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (rn == *NULL_POINTER_STATE_CYBOI_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                serialise_ansi_escape_code_shape(p0, h, i, bl, u, b, bg, fg, p, s, wp, ws, bo, c, l, sh);
            }

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* sc = (int*) p6;

/*??
                if (p6 == *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // CAUTION! If the loop count handed over as parametre is NULL,
                    // then the break flag will NEVER be set to true, because the loop
                    // variable comparison does (correctly) not consider null values.
                    // Therefore, in this case, the break flag is set to true already here.
                    // Initialising the break flag with true will NOT work either, since it:
                    // a) will be left untouched if a comparison operand is null;
                    // b) would have to be reset to true in each loop cycle.
                    copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }
*/

                // Iterate through compound parts.
                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (j >= *sc) {

                        break;
                    }

                    // Get part at index j.
                    get_compound_element_by_index(p5, p6, (void*) &j,
                        (void*) &n, (void*) &nc, (void*) &ns,
                        (void*) &a, (void*) &ac, (void*) &as,
                        (void*) &m, (void*) &mc, (void*) &ms,
                        (void*) &d, (void*) &dc, (void*) &ds);

                    // Compare expected name with that of the current compound part element.
                    compare_all_array((void*) &nr, *n, en, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *nc, (void*) &enc);

                    if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (nr != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

                        // Either, no hierarchical element name (repaint area) was given
                        // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                        // but the whole textual user interface (tui) window is repainted,
                        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                        // OR:
                        // the compound part name matches the next name in the
                        // given cascade of separated names, pointing to a knowledge model.

                        // Recursively process part model.
                        serialise_ansi_escape_code_part(p0, *a, *ac, *m, *mc, *d, *dc, p7, p8, rn, (void*) &rnc, p13, p14);
                    }

                    // Reset source part name, type, model, properties
                    // (parametres of the current compound part element).
                    n = NULL_POINTER_STATE_CYBOI_MODEL;
                    t = NULL_POINTER_STATE_CYBOI_MODEL;
                    ...

                    // Reset name comparison result.
                    nr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Increment loop count.
                    j++;
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise properties into ansi escape code. The source count parametre is null.");
            }

        } else {

            // The part model is NOT a compound.

            if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (rn == *NULL_POINTER_STATE_CYBOI_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_STATE_CYBOI_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                serialise_ansi_escape_code_shape(p0, h, i, bl, u, b, bg, fg, p, s, wp, ws, bo, c, l, sh);

                //?? TODO: Hand over model and type e.g. for printing text,
                // since this is NOT a compound/ whole.
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise properties into ansi escape code. The hierarchical compound element name contains a meta element, while only part elements are permitted.");
    }

------------------------------
    // Get tag part model.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get tag part model data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //?? serialise_ansi_escape_code_properties(p0, p3, p4, p5);
}

/* PROPERTIES_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
