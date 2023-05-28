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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ALGORITHM_LIBRARY_SOURCE
#define ALGORITHM_LIBRARY_SOURCE

//
// container
//

#include "../../executor/container/basic/integer/both_integer_container.c"
#include "../../executor/container/basic/integer/left_integer_container.c"
#include "../../executor/container/basic/integer/none_integer_container.c"
#include "../../executor/container/basic/integer/right_integer_container.c"
#include "../../executor/container/basic/integer_container.c"

//
// finder
//

#include "../../executor/finder/array_finder.c"
#include "../../executor/finder/element_list_finder.c"
#include "../../executor/finder/entry_finder.c"
#include "../../executor/finder/fifo_array_finder.c"
#include "../../executor/finder/item_finder.c"
#include "../../executor/finder/lifo_array_finder.c"
#include "../../executor/finder/list_finder.c"
#include "../../executor/finder/list_index_finder.c"
#include "../../executor/finder/mode_finder.c"
#include "../../executor/finder/part_finder.c"

//
// searcher
//

#include "../../executor/searcher/TODO_array_searcher.c"

//
// sorter
//

#include "../../executor/sorter/bubble/bubble_bubble_sorter.c"
#include "../../executor/sorter/bubble/bubble_sorter.c"
#include "../../executor/sorter/bubble/criterion_bubble_sorter.c"
#include "../../executor/sorter/bubble/operation_bubble_sorter.c"
#include "../../executor/sorter/bubble/part_bubble_sorter.c"
#include "../../executor/sorter/bubble/swap_bubble_sorter.c"
#include "../../executor/sorter/bubble/type_bubble_sorter.c"

#include "../../executor/sorter/insertion_sorter.c"

#include "../../executor/sorter/quick_sorter.c"

#include "../../executor/sorter/selection_sorter.c"

#include "../../executor/sorter/sorter.c"

/* ALGORITHM_LIBRARY_SOURCE */
#endif
