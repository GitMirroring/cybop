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

//
// container
//

#include "../../executor/container/basic/integer/both_integer_container.c"
#include "../../executor/container/basic/integer/left_integer_container.c"
#include "../../executor/container/basic/integer/none_integer_container.c"
#include "../../executor/container/basic/integer/right_integer_container.c"
#include "../../executor/container/basic/integer_container.c"

//
// detector
//

#include "../../executor/detector/comparison_detector.c"
#include "../../executor/detector/detector.c"
#include "../../executor/detector/moving_detector.c"

//
// finder
//

#include "../../executor/finder/element_list_finder.c"
#include "../../executor/finder/entry_finder.c"
#include "../../executor/finder/list_finder.c"
#include "../../executor/finder/list_index_finder.c"
#include "../../executor/finder/mode_finder.c"

//
// mover
//

#include "../../executor/mover/mover.c"

//
// searcher
//

#include "../../executor/searcher/linear/comparison_linear_searcher.c"
#include "../../executor/searcher/linear/elementcount_linear_searcher.c"
#include "../../executor/searcher/linear/fifo_linear_searcher.c"
#include "../../executor/searcher/linear/lifo_linear_searcher.c"
#include "../../executor/searcher/linear/linear_searcher.c"
#include "../../executor/searcher/linear/model_linear_searcher.c"
#include "../../executor/searcher/linear/moving_linear_searcher.c"
#include "../../executor/searcher/linear/name_linear_searcher.c"
#include "../../executor/searcher/linear/part_linear_searcher.c"
#include "../../executor/searcher/linear/primitive_linear_searcher.c"
#include "../../executor/searcher/linear/type_linear_searcher.c"

#include "../../executor/searcher/searcher.c"

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
