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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XDT_HEADER
#define XDT_HEADER

//
// model
//

#include "constant/model/xdt/field_description_xdt_model.h"

//
// name
//

#include "constant/name/cyboi/xdt/field_xdt_cyboi_name.h"
#include "constant/name/cyboi/xdt/record_xdt_cyboi_name.h"

#include "constant/name/xdt/bdt_xdt_name.h"
#include "constant/name/xdt/field_xdt_name.h"
#include "constant/name/xdt/gdt_xdt_name.h"
#include "constant/name/xdt/record_xdt_name.h"

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

void deserialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_xdt_field_description(void* p0, void* p1);

/* XDT_HEADER */
#endif
