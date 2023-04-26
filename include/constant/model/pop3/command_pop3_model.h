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

#ifndef COMMAND_POP3_MODEL_CONSTANT_HEADER
#define COMMAND_POP3_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/** The APOP command pop3 model. */
static unsigned char* APOP_COMMAND_POP3_MODEL = "APOP";
static int* APOP_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The DELE command pop3 model. */
static unsigned char* DELE_COMMAND_POP3_MODEL = "DELE";
static int* DELE_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The LIST command pop3 model. */
static unsigned char* LIST_COMMAND_POP3_MODEL = "LIST";
static int* LIST_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NOOP command pop3 model. */
static unsigned char* NOOP_COMMAND_POP3_MODEL = "NOOP";
static int* NOOP_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The PASS command pop3 model. */
static unsigned char* PASS_COMMAND_POP3_MODEL = "PASS";
static int* PASS_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The QUIT command pop3 model. */
static unsigned char* QUIT_COMMAND_POP3_MODEL = "QUIT";
static int* QUIT_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RETR command pop3 model. */
static unsigned char* RETR_COMMAND_POP3_MODEL = "RETR";
static int* RETR_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RSET command pop3 model. */
static unsigned char* RSET_COMMAND_POP3_MODEL = "RSET";
static int* RSET_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STAT command pop3 model. */
static unsigned char* STAT_COMMAND_POP3_MODEL = "STAT";
static int* STAT_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The TOP command pop3 model. */
static unsigned char* TOP_COMMAND_POP3_MODEL = "TOP";
static int* TOP_COMMAND_POP3_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UIDL command pop3 model. */
static unsigned char* UIDL_COMMAND_POP3_MODEL = "UIDL";
static int* UIDL_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The USER command pop3 model. */
static unsigned char* USER_COMMAND_POP3_MODEL = "USER";
static int* USER_COMMAND_POP3_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_POP3_MODEL_CONSTANT_HEADER */
#endif
