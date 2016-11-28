/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUBBLE_SORTER_SOURCE
#define BUBBLE_SORTER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../variable/reallocation_factor.c"

/*
 * The bubblesort algorithm
 *
 * Works space-economically over ONE
 * array.
 *
 */
void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubblesort(int *omd, int *elements) {
	int n = *elements;
	int* a1 = (int*) 0;
	int* a2 = (int*) 0;
	int newn = 1;
	int i = 0;

	while (1)
	{		
		if (n <= 1) break;		
		newn = 1;
		i = 0;
		
		while (1)
		{
			if (i >= (n - 1)) break;
			a1 = (omd + i);
			a2 = (omd + i + 1);
			if (*a1 > *a2)
			{
				swap(a1, a2);
				newn = i + 1;				
			}
			i++;
		}
		n = newn;
	}

}



/*
 * Sortes numbers by bubblesort-algorithm.
 *
 * @param imd the input model data
 * @param imc the input model count
 * @param omd the output model data
 * @param omc the output model count
 * 
 */
void sorter_bubble(void* imd, void* imc, void* omd, void* omc) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble.");
   	
	int i = -1;
	if(*((int* ) imc) == *((int* ) omc))
	{	
		while(++i < *((int* ) imc))
			*((int* ) omd + i) = *((int* ) imd + i);

		bubblesort((int*) omd, (int* ) omc);
	} 
	else
		fwprintf(stderr, L"input data count (%d) != output datacount (%d) !!\n", *((int* ) imc),*((int* ) omc));
}

/* BUBBLE_SORTER_SOURCE */
#endif
