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

#ifndef JSON_HEADER
#define JSON_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/backslash_escape/backslash_escape_model.h"

#include "constant/model/json/json_model.h"

//
// name
//

#include "constant/name/cyboi/json/json_cyboi_name.h"

#include "constant/name/json/json_name.h"

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
// backslash escape
//

void deserialise_backslash_escape(void* p0, void* p1, void* p2);
void serialise_backslash_escape(void* p0, void* p1, void* p2);

//
// json
//

void deserialise_json(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_json_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_json_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_json_member(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_json_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_json_object(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_json_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_json_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

void select_json_number_end(void* p0, void* p1, void* p2, void* p3);
void select_json_string_end(void* p0, void* p1, void* p2, void* p3);
void select_json_string_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void select_json_value_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

void serialise_json(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void serialise_json_break(void* p0, void* p1);
void serialise_json_comma(void* p0, void* p1, void* p2);
void serialise_json_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_json_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16);
void serialise_json_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_json_format(void* p0, void* p1);
void serialise_json_indentation(void* p0, void* p1, void* p2);
void serialise_json_level(void* p0, void* p1);
void serialise_json_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_json_prefix(void* p0, void* p1, void* p2);
void serialise_json_separation(void* p0, void* p1);
void serialise_json_space(void* p0, void* p1);
void serialise_json_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_json_suffix(void* p0, void* p1, void* p2, void* p3);
void serialise_json_tabulator(void* p0);

//
// sign
//

void select_sign(void* p0, void* p1, void* p2, void* p3, void* p4);

/* JSON_HEADER */
#endif
