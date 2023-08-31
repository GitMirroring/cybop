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

#ifndef MAPPER_HEADER
#define MAPPER_HEADER

//
// channel
//

void map_channel_to_internal_memory(void* p0, void* p1);
void map_channel_to_type(void* p0, void* p1);

//
// digit
//

void map_digit_wide_character_to_integer(void* p0, void* p1);
void map_integer_to_digit_wide_character(void* p0, void* p1);

//
// error
//

void map_errno_to_message(void* p0, void* p1);
void map_errno_to_message_linux(void* p0, void* p1);
void map_errno_to_message_windows(void* p0, void* p1);

//
// type
//

void map_type_to_size(void* p0, void* p1);

/* MAPPER_HEADER */
#endif
