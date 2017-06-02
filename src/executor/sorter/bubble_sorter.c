/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUBBLE_SORTER_SOURCE
#define BUBBLE_SORTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/modifier/overwrite_modifier.c"
#include "../../logger/logger.c"

/*
 * Swaps the given integer values.
 *
 * @param p0 the first value
 * @param p1 the second value
 */
void swap_integer(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Swap integer.");

    // The temporary value.
    int t = 0;

    copy_integer((void*) &t, p0);
    copy_integer(p0, p1);
    copy_integer(p1, (void*) &t);
}

/*
 * Sorts the given data using the bubble algorithm.
 *
 * @param
 * @param
 */
void sort_bubble() {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble.");

}

/* BUBBLE_SORTER_SOURCE */
#endif

/*
    public static void sort_bubble(int[] a) {

        int tmp = 0;
        boolean swapped = false;

        for (int i = 1; i < a.length; i++) {

            swapped = false;

            // Optimierung 2: Sortiere nur den noch nicht sortierten Teil des Feldes.
            // (j < a.length - i) statt nur (j < a.length).
            for (int j = 0; j < a.length - i; j++) {

                if (a[j] > a[j + 1]) {

                    swap_integer(a[j], a[j + 1]);
                    swapped = true;
                }
            }

            // Optimierung 1: Beende Sortiervorgang, wenn nichts mehr zu sortieren ist.
            if (swapped == false) {

                break;
            }
        }
    }

    public static void main(String[] args) {

        int[] a = {34, 65, 43, -23, 8, 454, 34, 2, -9, 7, 6, 4, 12, 234, 54, 23, 76, 8, 98, 32};

        sort_bubble(a);

        for (int i : a) {

            System.out.print(i + ", ");
        }

        System.out.println();
    }
 */