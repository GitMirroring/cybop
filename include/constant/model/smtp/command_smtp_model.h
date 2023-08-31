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

#ifndef COMMAND_SMTP_MODEL_CONSTANT_HEADER
#define COMMAND_SMTP_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! These constants are of type "wchar_t" even though the
// smtp protocol uses "char", because they have to be searched
// in a case-INsensitive way in the smtp command deserialiser
// and therefore get converted into wide character before anyway.
//

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
static wchar_t* AUTH_COMMAND_SMTP_MODEL = L"AUTH";
static int* AUTH_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ATRN command smtp model. */
static wchar_t* ATRN_COMMAND_SMTP_MODEL = L"ATRN";
static int* ATRN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The BDAT command smtp model. */
static wchar_t* BDAT_COMMAND_SMTP_MODEL = L"BDAT";
static int* BDAT_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The DATA command smtp model. */
static wchar_t* DATA_COMMAND_SMTP_MODEL = L"DATA";
static int* DATA_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EHLO command smtp model. */
static wchar_t* EHLO_COMMAND_SMTP_MODEL = L"EHLO";
static int* EHLO_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ETRN command smtp model. */
static wchar_t* ETRN_COMMAND_SMTP_MODEL = L"ETRN";
static int* ETRN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXPN command smtp model. */
static wchar_t* EXPN_COMMAND_SMTP_MODEL = L"EXPN";
static int* EXPN_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The HELO command smtp model. */
static wchar_t* HELO_COMMAND_SMTP_MODEL = L"HELO";
static int* HELO_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The HELP command smtp model. */
static wchar_t* HELP_COMMAND_SMTP_MODEL = L"HELP";
static int* HELP_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The MAIL command smtp model. */
static wchar_t* MAIL_COMMAND_SMTP_MODEL = L"MAIL";
static int* MAIL_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NOOP command smtp model. */
static wchar_t* NOOP_COMMAND_SMTP_MODEL = L"NOOP";
static int* NOOP_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The QUIT command smtp model. */
static wchar_t* QUIT_COMMAND_SMTP_MODEL = L"QUIT";
static int* QUIT_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RCPT command smtp model. */
static wchar_t* RCPT_COMMAND_SMTP_MODEL = L"RCPT";
static int* RCPT_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RSET command smtp model. */
static wchar_t* RSET_COMMAND_SMTP_MODEL = L"RSET";
static int* RSET_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SIZE command smtp model. */
static wchar_t* SIZE_COMMAND_SMTP_MODEL = L"SIZE";
static int* SIZE_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STARTTLS command smtp model. */
static wchar_t* STARTTLS_COMMAND_SMTP_MODEL = L"STARTTLS";
static int* STARTTLS_COMMAND_SMTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The VRFY command smtp model. */
static wchar_t* VRFY_COMMAND_SMTP_MODEL = L"VRFY";
static int* VRFY_COMMAND_SMTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_SMTP_MODEL_CONSTANT_HEADER */
#endif
