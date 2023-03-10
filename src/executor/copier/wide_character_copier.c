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

#ifndef WIDE_CHARACTER_COPIER_SOURCE
#define WIDE_CHARACTER_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../logger/logger.c"

/**
 * Copies the wide character.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_wide_character(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* se = (wchar_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* de = (wchar_t*) p0;

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            //
            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy wide character.");
            //

            // Assign source- to destination.
            *de = *se;

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy wide character. The destination is null.");
            //
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy wide character. The source is null.");
        //
    }
}

/* WIDE_CHARACTER_COPIER_SOURCE */
#endif
