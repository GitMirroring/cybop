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

#ifndef COMMAND_SMTP_MODEL_CONSTANT_HEADER
#define COMMAND_SMTP_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// The following OBSOLETE commands are NOT considered:
//
// RELAY
// SAML
// SEND
// SOML
// TLS
// TURN
//

/** The AUTH command smtp model. */
static unsigned char* AUTH_COMMAND_SMTP_MODEL = "AUTH";
static int* AUTH_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ATRN command smtp model. */
static unsigned char* ATRN_COMMAND_SMTP_MODEL = "ATRN";
static int* ATRN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The BDAT command smtp model. */
static unsigned char* BDAT_COMMAND_SMTP_MODEL = "BDAT";
static int* BDAT_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The DATA command smtp model. */
static unsigned char* DATA_COMMAND_SMTP_MODEL = "DATA";
static int* DATA_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EHLO command smtp model. */
static unsigned char* EHLO_COMMAND_SMTP_MODEL = "EHLO";
static int* EHLO_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ETRN command smtp model. */
static unsigned char* ETRN_COMMAND_SMTP_MODEL = "ETRN";
static int* ETRN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXPN command smtp model. */
static unsigned char* EXPN_COMMAND_SMTP_MODEL = "EXPN";
static int* EXPN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The HELO command smtp model. */
static unsigned char* HELO_COMMAND_SMTP_MODEL = "HELO";
static int* HELO_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The HELP command smtp model. */
static unsigned char* HELP_COMMAND_SMTP_MODEL = "HELP";
static int* HELP_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The MAIL FROM command smtp model. */
static unsigned char* MAIL_FROM_COMMAND_SMTP_MODEL = "MAIL FROM";
static int* MAIL_FROM_COMMAND_SMTP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NOOP command smtp model. */
static unsigned char* NOOP_COMMAND_SMTP_MODEL = "NOOP";
static int* NOOP_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The QUIT command smtp model. */
static unsigned char* QUIT_COMMAND_SMTP_MODEL = "QUIT";
static int* QUIT_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RCPT TO command smtp model. */
static unsigned char* RCPT_TO_COMMAND_SMTP_MODEL = "RCPT TO";
static int* RCPT_TO_COMMAND_SMTP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RSET command smtp model. */
static unsigned char* RSET_COMMAND_SMTP_MODEL = "RSET";
static int* RSET_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SIZE command smtp model. */
static unsigned char* SIZE_COMMAND_SMTP_MODEL = "SIZE";
static int* SIZE_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STARTTLS command smtp model. */
static unsigned char* STARTTLS_COMMAND_SMTP_MODEL = "STARTTLS";
static int* STARTTLS_COMMAND_SMTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The VRFY command smtp model. */
static unsigned char* VRFY_COMMAND_SMTP_MODEL = "VRFY";
static int* VRFY_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_SMTP_MODEL_CONSTANT_HEADER */
#endif
