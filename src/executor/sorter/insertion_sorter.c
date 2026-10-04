/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/*
 * Sorts the given data using the insertion algorithm.
 *
 * @param
 * @param
 */
void sort_insertion() {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort insertion.");

}

/*
    public static void sort_insertion(int[] a) {

        int tmp = 0;
        int j = 0;

        for (int i = 1; i < a.length; i++) {

            tmp = a[i];
            j = i;

            while ((j > 0) && (a[j - 1] > tmp)) {

                a[j] = a[j - 1];

                j--;
            }

            a[j] = tmp;
        }
    }

    public static void main(String[] args) {

        int[] a = {34, 65, 43, -23, 8, 454, 34, 2, -9, 7, 6, 4, 12, 234, 54, 23, 76, 8, 98, 32};

        sort_insertion(a);

        for (int i : a) {

            System.out.print(i + ", ");
        }

        System.out.println();
    }
*/
