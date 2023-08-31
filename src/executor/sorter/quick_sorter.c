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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "logger.h"

/*
 * Sorts the given data using the quick algorithm.
 *
 * @param
 * @param
 */
void sort_quick() {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort quick.");

}

    /**
     * Sort array using quick sort algorithm.
     *
     * @param a the array
     * @param l the left index
     * @param r the right index
     */
/*
    public static void sort_quick(int[] a, int l, int r) {

        // solange mehr als 1 Folgenelement existiert
        if (l < r) {

            // Variableninitialisierung mit Folgenrändern
            int i = l - 1;
            int j = r;
            int tmp = 0;

            while (true) {

                while (true) {

                    // Increment until greater element is found.
                    i++;

                    if (a[i] >= a[r]) {

                        break;
                    }
                }

                while (true) {

                    // Decrement until lesser element is found.
                    j--;

                    if ((a[j] <= a[r]) || (j <= i)) {

                        break;
                    }
                }

                // Break if indices meet.
                if (i >= j) {

                    break;
                }

                // Swap lesser with greater element.
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

            // Swap separating element.
            tmp = a[i];
            a[i] = a[r];
            a[r] = tmp;

            // Call this function recursively for left subsequence.
            sort_quick(a, l, i - 1);

            // Call this function recursively for right subsequence.
            sort_quick(a, i + 1, r);
        }
    }

    public static void main(String[] args) {

        int[] a = {34, 65, 43, -23, 8, 454, 34, 2, -9, 7, 6, 4, 12, 234, 54, 23, 76, 8, 98, 32};

        sort_quick(a, 0, a.length - 1);

        for (int i : a) {

            System.out.print(i + ", ");
        }

        System.out.println();
    }
*/
