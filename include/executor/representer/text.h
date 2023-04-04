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

#ifndef TEXT_HEADER
#define TEXT_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/text/ascii_newline_text_model.h"

#include "constant/model/text/newline_text_model.h"

//
// name
//

#include "constant/name/csv/delimiter_csv_name.h"
#include "constant/name/csv/quotation_csv_name.h"

#include "constant/name/cyboi/csv/csv_cyboi_name.h"

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
// ascii
//

void deserialise_ascii(void* p0, void* p1, void* p2);
void serialise_ascii(void* p0, void* p1, void* p2);

//
// csv
//

void deserialise_csv(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_csv_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_csv_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_csv_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_csv_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void deserialise_csv_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_csv_preparation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_csv_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_csv_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_csv_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

//
// joined string
//

void deserialise_joined_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_joined_string_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void deserialise_joined_string_list(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_joined_string_preparation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_joined_string_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_joined_string_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);

void select_joined_string_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void select_joined_string_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void select_joined_string_end_quotation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void select_joined_string_end_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// newline
//

void select_newline(void* p0, void* p1, void* p2, void* p3);

//
// textline list
//

void deserialise_textline_list(void* p0, void* p1, void* p2);
void deserialise_textline_list_content(void* p0, void* p1, void* p2);
void deserialise_textline_list_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_textline_list_index(void* p0, void* p1, void* p2, void* p3);
void deserialise_textline_list_part(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// whitespace
//

void deserialise_whitespace(void* p0, void* p1);

void select_whitespace(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_whitespace_non(void* p0, void* p1, void* p2);

/* TEXT_HEADER */
#endif
