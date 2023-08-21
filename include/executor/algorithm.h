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

#ifndef ALGORITHM_HEADER
#define ALGORITHM_HEADER

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// container
//

void contain_integer(void* p0, void* p1, void* p2, void* p3, void* p4);
void contain_integer_both(void* p0, void* p1, void* p2, void* p3);
void contain_integer_left(void* p0, void* p1, void* p2, void* p3);
void contain_integer_none(void* p0, void* p1, void* p2, void* p3);
void contain_integer_right(void* p0, void* p1, void* p2, void* p3);

//
// detector
//

void detect(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void detect_comparison(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void detect_moving(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// finder
//

void find_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void find_list(void* p0, void* p1, void* p2, void* p3);
void find_list_element(void* p0, void* p1, void* p2, void* p3);
void find_list_index(void* p0, void* p1, void* p2, void* p3);
void find_mode(void* p0, void* p1, void* p2, void* p3);

//
// mover
//

void move(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// searcher
//

void search(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

void search_linear(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void search_linear_comparison(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void search_linear_elementcount(void* p0, void* p1, void* p2);
void search_linear_fifo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void search_linear_lifo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void search_linear_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void search_linear_moving(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void search_linear_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void search_linear_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void search_linear_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void search_linear_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

//
// sorter
//

void sort(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

void sort_bubble(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void sort_bubble_bubble(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void sort_bubble_criterion(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void sort_bubble_operation(void* p0, void* p1);
void sort_bubble_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void sort_bubble_swap(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void sort_bubble_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

void sort_insertion();

void sort_quick();

void sort_selection();

/* ALGORITHM_HEADER */
#endif
