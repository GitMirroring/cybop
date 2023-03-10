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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SELECTION_SORTER_SOURCE
#define SELECTION_SORTER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../logger/logger.c"

/*
 * Sorts the given data using the selection algorithm.
 *
 * @param
 * @param
 */
void sort_selection() {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort selection.");

}

/* SELECTION_SORTER_SOURCE */
#endif

/*
    public static void sort_selection(int[] a) {

        int tmp = 0;
        int min = 0;

        for (int i = 0; i < a.length - 1; i++) {

            min = i;

            for (int j = i + 1; j < a.length; j++) {

                if (a[j] < a[min]) {

                    min = j;
                }
            }

            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }

    public static void main(String[] args) {

        int[] a = {34, 65, 43, -23, 8, 454, 34, 2, -9, 7, 6, 4, 12, 234, 54, 23, 76, 8, 98, 32};

        sort_selection(a);

        for (int i : a) {

            System.out.print(i + ", ");
        }

        System.out.println();
    }
*/
