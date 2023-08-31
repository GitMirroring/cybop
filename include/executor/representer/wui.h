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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WUI_HEADER
#define WUI_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/character_entity_reference/html_character_entity_reference_model.h"

#include "constant/model/html/document_type_html_model.h"
#include "constant/model/html/tag_html_model.h"

//
// name
//

#include "constant/name/character_reference/character_reference_name.h"

#include "constant/name/percent_encoding/percent_encoding_name.h"

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
// character reference
//

void deserialise_character_reference(void* p0, void* p1, void* p2);
void deserialise_character_reference_any(void* p0, void* p1, void* p2);
void deserialise_character_reference_decimal(void* p0, void* p1, void* p2);
void deserialise_character_reference_entity(void* p0, void* p1, void* p2);
void deserialise_character_reference_hexadecimal(void* p0, void* p1, void* p2);
void deserialise_character_reference_html(void* p0, void* p1, void* p2);

void select_character_reference_begin(void* p0, void* p1, void* p2);
void select_character_reference_end(void* p0, void* p1, void* p2, void* p3);

void serialise_character_reference(void* p0, void* p1, void* p2, void* p3);
void serialise_character_reference_character(void* p0, void* p1, void* p2);
void serialise_character_reference_data(void* p0, void* p1, void* p2, void* p3);
void serialise_character_reference_html(void* p0, void* p1);
void serialise_character_reference_xml(void* p0, void* p1);

//
// css
//

//?? TODO

//
// html
//

void deserialise_html(void* p0, void* p1, void* p2);

void serialise_html(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_html_attribute(void* p0, void* p1, void* p2);
void serialise_html_attributes(void* p0, void* p1, void* p2);
void serialise_html_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_html_break(void* p0, void* p1);
void serialise_html_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_html_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void serialise_html_doctype(void* p0, void* p1, void* p2, void* p3);
void serialise_html_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_html_empty(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_html_end(void* p0, void* p1, void* p2);
void serialise_html_filled(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void serialise_html_indentation(void* p0, void* p1, void* p2);
void serialise_html_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_html_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_html_void(void* p0, void* p1, void* p2);

//
// percent encoding
//

void deserialise_percent_encoding(void* p0, void* p1, void* p2);
void deserialise_percent_encoding_character(void* p0, void* p1, void* p2);
void deserialise_percent_encoding_data(void* p0, void* p1, void* p2);

void select_percent_encoding_begin(void* p0, void* p1, void* p2);

void serialise_percent_encoding(void* p0, void* p1, void* p2);
void serialise_percent_encoding_byte(void* p0, void* p1);
void serialise_percent_encoding_bytes(void* p0, void* p1);
void serialise_percent_encoding_character(void* p0, void* p1);
void serialise_percent_encoding_data(void* p0, void* p1, void* p2);

/* WUI_HEADER */
#endif
