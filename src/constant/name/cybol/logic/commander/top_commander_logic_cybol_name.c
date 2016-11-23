/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
/**Starts top in Batch mode, which could be useful  for  sending output  from  top  to  other  programs or to a file.  In this
mode, top will not accept input and runs until the iterations
limit  you've  set with the `-n' command-line option or until
killed.*/
static wchar_t BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'b', L'a', L't', L'c', L'h'};
static wchar_t* BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME = BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* BATCH_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**Starts top with  the  last  remembered  `c'  state  reversed.
Thus,  if  top  was  displaying command lines, now that field
will show program names, and visa versa.  See the `c'  inter‐
active command for additional information.*/
static wchar_t COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd'};
static wchar_t* COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME = COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* COMMAND_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**Instructs top to display individual  threads.   Without  this
command-line  option  a  summation  of  all  threads  in each
process is shown.  Later this can be  changed  with  the  `H'
interactive command.*/
static wchar_t THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L't', L'h', L'r', L'e', L'a', L'd'};
static wchar_t* THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME = THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* THREAD_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**Starts top with the last remembered `i' state reversed.  When
this toggle is Off, tasks that have not used  any  CPU  since
the last update will not be displayed.  For additional infor‐
mation regarding this toggle see topic  4c.  TASK  AREA  Com‐
mands, SIZE. */
static wchar_t IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'i', L'd', L'l', L'e'};
static wchar_t* IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME = IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* IDLE_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**Starts top with secure mode forced, even for root.  This mode
is far better controlled  through  the  system  configuration
file (see topic 6. FILES). */
static wchar_t SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'e', L'c', L'u', L'r', L'e'};
static wchar_t* SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME = SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* SECURE_TOP_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TOP_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
