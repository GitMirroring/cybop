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
#ifndef BETWEEN_INTEGER_COMPARATOR_SOURCE
#define BETWEEN_INTEGER_COMPARATOR_SOURCE

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/modifier/copier/integer_copier.c"

/**
 * Compares the left- with the right integer for greaterness.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 left value
 * @param p2 right value
 * @param p3 compare value
 */

void compare_integer_between(void* p0, void* p1, void* p2, void* p3){

	if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

		int* cv=(int*)p3;

		if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

			int* rv = (int*) p2;

			if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

				int* lv = (int*) p1;

				if ((*lv > *cv) && (*cv < *rv)){

					copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
				}
			}
		}
	}
}
/* BETWEEN_INTEGER_COMPARATOR_SOURCE */
#endif
