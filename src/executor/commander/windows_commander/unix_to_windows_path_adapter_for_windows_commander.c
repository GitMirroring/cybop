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

#ifndef UNIX_TO_WINDOWS_PATH_ADAPTER_FOR_WINDOWS_COMMANDER_SOURCE
#define UNIX_TO_WINDOWS_PATH_ADAPTER_FOR_WINDOWS_COMMANDER_SOURCE

#include <string.h>

#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"

/**
 * Converts unix paths into windows paths.
 * Note: It seems that extracting data and count from two or more text/plain, just the first count is saved and the second count is not accessable (TODO: Investigation)
 *
 * @param p0 the path model data
 * @param p1 the path model count
 */
void apply_unix_to_windows_path_adapter_for_windows_commander(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pmc = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The loop variable.
            int j = 0;
            // The current position.
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The character.
            wchar_t* c = *NULL_POINTER_STATE_CYBOI_MODEL;

            while (1) {

                if (j >= *pmc) {

                    break;
                }

                // Add offset.
                p = p0 + j * (sizeof(wchar_t));

                c = (wchar_t*) p;

                if (*c == *SOLIDUS_UNICODE_CHARACTER_CODE_MODEL) {

                    *c = *REVERSE_SOLIDUS_UNICODE_CHARACTER_CODE_MODEL;
                }

                // Increment loop variable.
                j++;
            }
        }
    }
}

/* UNIX_TO_WINDOWS_PATH_ADAPTER_FOR_WINDOWS_COMMANDER_SOURCE */
#endif
