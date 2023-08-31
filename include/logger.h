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

#ifndef LOGGER_HEADER
#define LOGGER_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

#include "constant/model/cyboi/log/error_message_log_cyboi_model.h"
#include "constant/model/cyboi/log/level_log_cyboi_model.h"
#include "constant/model/cyboi/log/level_name_log_cyboi_model.h"
#include "constant/model/cyboi/log/linux_error_message_log_cyboi_model.h"
#include "constant/model/cyboi/log/windows_error_message_log_cyboi_model.h"

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
// logger
//

void log_error(void* p0);

void log_level_name(void* p0, void* p1, void* p2);

void log_message(void* p0, void* p1, void* p2);
void log_message_terminated(void* p0, void* p1);

void log_windows_system_error(void* p0);

void log_write(void* p0, void* p1);

/* LOGGER_HEADER */
#endif
