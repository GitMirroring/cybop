/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef QUICK_SORTER_SOURCE
#define QUICK_SORTER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/modifier/overwrite_modifier.c"
#include "../../executor/runner/executor.c"
#include "../../variable/reallocation_factor.c"

/*
 * The quicksort algorithm
 *
 * Works space-economically over ONE
 * array.
 */
void quicksort(int *a, int *e) {

    int *g;
    int *k;
    int tmp;
    if(e - a <= 1)
        return;
    g = a;
    k = e - 1;

    do {
        while((*g <= *e) && (g < e))
            ++g;
        while((*k >= *e) && (k > a))
            --k;
        if(g > k)
            break;
        tmp = *k;
        *k = *g;
        *g = tmp;

    } while(g < k);
    tmp = *g;
    *g = *e;
    *e = tmp;

    quicksort(a, k);
    quicksort(g, e);
}

/*
 * Sorts numbers by quicksort-algorithm.
 * THIS: http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/022_c_algorithmen_003.htm#mjde22312f4b61457b2efb0f9f17a7b269 sorts even own types (not restricted to int).
 *
 * @param imd the input model data
 * @param imc the input model count
 * @param omd the output model data
 * @param omc the output model count
 * @param oms the output model size
 */
void sorter_quick(void* imd, void* imc, void* omd, void* omc, void* oms) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort quick.");

fwprintf(stdout, L"TEST quick oms: %i\n", oms);
fwprintf(stdout, L"TEST quick *oms: %i\n", *((int*) oms));
fwprintf(stdout, L"TEST quick omc: %i\n", omc);
fwprintf(stdout, L"TEST quick *omc: %i\n", *((int*) omc));
fwprintf(stdout, L"TEST quick omd: %i\n", omd);
fwprintf(stdout, L"TEST quick *omd: %i\n", *((int*) omd));
fwprintf(stdout, L"TEST quick **omd: %i\n", **((int**) omd));

    // Fill destination array in order to preserve input array values.
    modify_overwrite(omd, imd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, imc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, omc, oms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

fwprintf(stdout, L"TEST quick oms: %i\n", oms);
fwprintf(stdout, L"TEST quick *oms: %i\n", *((int*) oms));
fwprintf(stdout, L"TEST quick omc: %i\n", omc);
fwprintf(stdout, L"TEST quick *omc: %i\n", *((int*) omc));
fwprintf(stdout, L"TEST quick omd: %i\n", omd);
fwprintf(stdout, L"TEST quick *omd: %i\n", *((int*) omd));
fwprintf(stdout, L"TEST quick **omd: %i\n", **((int**) omd));

fwprintf(stdout, L"TEST quick sizeof(void*): %i\n", sizeof(void*));
fwprintf(stdout, L"TEST quick sizeof(int): %i\n", sizeof(int));
fwprintf(stdout, L"TEST quick (*((int*) omc) - 1) * sizeof(int): %i\n", (*((int*) omc) - 1) * sizeof(int));
fwprintf(stdout, L"TEST quick *((void**) omd) + ((*((int*) omc) - 1) * sizeof(int)): %i\n", *((void**) omd) + ((*((int*) omc) - 1) * sizeof(int)));

    void* address = *((void**) omd) + ((*((int*) omc) - 1) * sizeof(int));
fwprintf(stdout, L"TEST quick address: %i\n", address);

    // Call actual bubble sort algorithm.
    quicksort((int*) *((void**) omd), (int*) address);
//??    quicksort((int*) *((void**) omd), ((int*) *((void**) omd)) + (*((int*) omc) - 1));

/*??
        int i = -1;
        if(*((int* ) imc) == *((int* ) omc))
        {
                while(++i < *((int* ) imc))
                        *((int* ) *((int**) omd) + i) = *((int* ) imd + i);

                quicksort((int*) *((int**) omd), (int*) *((int**) omd) + (*((int* ) omc) - 1));
        }
        else
                fwprintf(stderr, L"input data count (%d) != output datacount (%d) !!\n", *((int* ) imc),*((int* ) omc));
*/
}

/* QUICK_SORTER_SOURCE */
#endif
