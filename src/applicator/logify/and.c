/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef AND_SOURCE
#define AND_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/logic/logic_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Applies the boolean logic AND operation.
 *
 * Properties:
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory
 */
void apply_and(void* p0, void* p1, void* p2) { 

  log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply Boolean-AND."); 
  
  // The output part. 
  void* o = *NULL_POINTER_STATE_CYBOI_MODEL; 
  // The input_1 part. 
  void* i1 = *NULL_POINTER_STATE_CYBOI_MODEL;
  // The input_2 part. 
  void* i2 = *NULL_POINTER_STATE_CYBOI_MODEL; 
  
  // Get input_1 part. 
  get_part_knowledge((void*) &i1, p0, (void*) INPUT_1_LOGIC_LOGIC_CYBOL_NAME, (void*) INPUT_1_LOGIC_LOGIC_CYBOL_NAME_COUNT, p1, p2);
  
   // Get input_2 part. 
  get_part_knowledge((void*) &i2, p0, (void*) INPUT_2_LOGIC_LOGIC_CYBOL_NAME, (void*) INPUT_2_LOGIC_LOGIC_CYBOL_NAME_COUNT, p1, p2); 
 
  // Get output part. 
  get_part_knowledge((void*) &o, p0, (void*) OUTPUT_LOGIC_LOGIC_CYBOL_NAME, (void*) OUTPUT_LOGIC_LOGIC_CYBOL_NAME_COUNT, p1, p2); 
 
  fwprintf(stdout, L"i1: %i\n", i1);
  fwprintf(stdout, L"i2: %i\n", *((int*) i2));
  fwprintf(stdout, L"o: %i\n", *((int*) o));
  
  // Calculate output by applying operation. 
  logify_boolean_and(o, i1, i2); 
  
  //fwprintf(stdout, L"i1: %i\n", *((int*) i1));
  //fwprintf(stdout, L"i2: %i\n", *((int*) i2));
  //fwprintf(stdout, L"o: %i\n", *((int*) o));
}

/* AND_SOURCE */
#endif
