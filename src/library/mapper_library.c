/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// channel
//

#include "../mapper/channel_to_internal_memory_mapper.c"
#include "../mapper/channel_to_type_mapper.c"

//
// digit
//

#include "../mapper/digit_wide_character_to_integer_mapper.c"
#include "../mapper/integer_to_digit_wide_character_mapper.c"

//
// error
//

#include "../mapper/errno_to_message_mapper.c"

#if defined(__linux__) || defined(__unix__)
    #include "../mapper/linux_errno_to_message_mapper.c"
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../mapper/windows_errno_to_message_mapper.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// type
//

#include "../mapper/type_to_size_mapper.c"
