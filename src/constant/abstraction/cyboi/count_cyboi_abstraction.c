/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: memory_abstraction.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_CYBOI_ABSTRACTION_CONSTANT_SOURCE
#define COUNT_CYBOI_ABSTRACTION_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/**
 * The cyboi abstraction count.
 *
 * This count is valid for ALL cyboi abstractions (logic and state),
 * as they are just integer numbers.
 */
static int* CYBOI_ABSTRACTION_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* COUNT_CYBOI_ABSTRACTION_CONSTANT_SOURCE */
#endif
