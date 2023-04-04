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

#ifndef XML_HEADER
#define XML_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// name
//

#include "constant/name/xml/xml_name.h"

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
// dtd
//

//?? TODO

//
// xml
//

void deserialise_xml(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_xml_attribute(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_xml_attribute_name(void* p0, void* p1, void* p2, void* p3);
void deserialise_xml_attribute_value(void* p0, void* p1, void* p2, void* p3);
void deserialise_xml_check_compound(void* p0, void* p1, void* p2);
void deserialise_xml_check_content(void* p0, void* p1, void* p2);
void deserialise_xml_comment(void* p0, void* p1);
void deserialise_xml_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_xml_declaration(void* p0, void* p1, void* p2);
void deserialise_xml_definition(void* p0, void* p1, void* p2);
void deserialise_xml_element(void* p0, void* p1, void* p2);
void deserialise_xml_end_tag(void* p0, void* p1);
void deserialise_xml_normalisation(void* p0, void* p1, void* p2, void* p3);
void deserialise_xml_string(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_xml_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void select_xml_attribute_begin_or_tag_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_xml_attribute_name(void* p0, void* p1, void* p2, void* p3);
void select_xml_attribute_value(void* p0, void* p1, void* p2, void* p3);
void select_xml_check_compound(void* p0, void* p1, void* p2, void* p3);
void select_xml_check_content(void* p0, void* p1, void* p2, void* p3);
void select_xml_comment(void* p0, void* p1, void* p2);
void select_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_xml_declaration(void* p0, void* p1, void* p2, void* p3);
void select_xml_definition(void* p0, void* p1, void* p2);
void select_xml_end_tag(void* p0, void* p1, void* p2);

void serialise_xml(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_xml_attribute(void* p0, void* p1, void* p2);
void serialise_xml_attributes(void* p0, void* p1, void* p2);
void serialise_xml_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_xml_break(void* p0, void* p1);
void serialise_xml_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void serialise_xml_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_xml_empty(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_xml_end(void* p0, void* p1, void* p2);
void serialise_xml_filled(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16);
void serialise_xml_indentation(void* p0, void* p1, void* p2);
void serialise_xml_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_xml_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

//
// xsd
//

//?? TODO

/* XML_HEADER */
#endif
