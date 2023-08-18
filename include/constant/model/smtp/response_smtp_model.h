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

#ifndef RESPONSE_SMTP_MODEL_CONSTANT_HEADER
#define RESPONSE_SMTP_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! These constants are of type "char", since they are used
// only if cyboi runs as smtp SERVER. The smtp protocol uses "char".
// If cyboi runs as smtp client, then the status code and text are
// taken as received from an external server, so that these constants
// here are NOT needed then.
//

//
// 1xx - accepted but confirmation necessary
//

/** The 101 response smtp model. */
static unsigned char* NUMERICAL_101_RESPONSE_SMTP_MODEL = "101 Server connection error (wrong server name or connection port)";
static int* NUMERICAL_101_RESPONSE_SMTP_MODEL_COUNT = NUMBER_66_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 2xx - success
//

/** The 211 response smtp model. */
static unsigned char* NUMERICAL_211_RESPONSE_SMTP_MODEL = "211 System status (response to HELP)";
static int* NUMERICAL_211_RESPONSE_SMTP_MODEL_COUNT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 214 response smtp model. */
static unsigned char* NUMERICAL_214_RESPONSE_SMTP_MODEL = "214 Help message (response to HELP)";
static int* NUMERICAL_214_RESPONSE_SMTP_MODEL_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 220 response smtp model. */
static unsigned char* NUMERICAL_220_RESPONSE_SMTP_MODEL = "220 The server is ready (response to the client's attempt to establish a TCP connection)";
static int* NUMERICAL_220_RESPONSE_SMTP_MODEL_COUNT = NUMBER_88_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 221 response smtp model. */
static unsigned char* NUMERICAL_221_RESPONSE_SMTP_MODEL = "221 The server closes the transmission channel";
static int* NUMERICAL_221_RESPONSE_SMTP_MODEL_COUNT = NUMBER_46_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 235 response smtp model. */
static unsigned char* NUMERICAL_235_RESPONSE_SMTP_MODEL = "235 Authentication successful (response to AUTH)";
static int* NUMERICAL_235_RESPONSE_SMTP_MODEL_COUNT = NUMBER_48_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 250 response smtp model. */
static unsigned char* NUMERICAL_250_RESPONSE_SMTP_MODEL = "250 The requested command is completed. As a rule, the code is followed by OK";
static int* NUMERICAL_250_RESPONSE_SMTP_MODEL_COUNT = NUMBER_77_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 251 response smtp model. */
static unsigned char* NUMERICAL_251_RESPONSE_SMTP_MODEL = "251 User is not local, but the server will forward the message to <forward-path>";
static int* NUMERICAL_251_RESPONSE_SMTP_MODEL_COUNT = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 252 response smtp model. */
static unsigned char* NUMERICAL_252_RESPONSE_SMTP_MODEL = "252 The server cannot verify the user (response to VRFY). The message will be accepted and attempted for delivery";
static int* NUMERICAL_252_RESPONSE_SMTP_MODEL_COUNT = NUMBER_113_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 3xx - accepted but more information necessary
//

/** The 334 response smtp model. */
static unsigned char* NUMERICAL_334_RESPONSE_SMTP_MODEL = "334 Response to the AUTH command when the requested security mechanism is accepted";
static int* NUMERICAL_334_RESPONSE_SMTP_MODEL_COUNT = NUMBER_82_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 354 response smtp model. */
static unsigned char* NUMERICAL_354_RESPONSE_SMTP_MODEL = "354 The server confirms mail content transfer (response to DATA). After that, the client starts sending the mail. Terminated with a period (.)";
static int* NUMERICAL_354_RESPONSE_SMTP_MODEL_COUNT = NUMBER_142_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 4xx - temporary server error (transient)
//

/** The 421 response smtp model. */
static unsigned char* NUMERICAL_421_RESPONSE_SMTP_MODEL = "421 The server is not available because it closes the transmission channel";
static int* NUMERICAL_421_RESPONSE_SMTP_MODEL_COUNT = NUMBER_74_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 422 response smtp model. */
static unsigned char* NUMERICAL_422_RESPONSE_SMTP_MODEL = "422 The recipient's mailbox has exceeded its storage limit";
static int* NUMERICAL_422_RESPONSE_SMTP_MODEL_COUNT = NUMBER_58_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 431 response smtp model. */
static unsigned char* NUMERICAL_431_RESPONSE_SMTP_MODEL = "431 File overload (too many messages sent to a particular domain)";
static int* NUMERICAL_431_RESPONSE_SMTP_MODEL_COUNT = NUMBER_65_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 441 response smtp model. */
static unsigned char* NUMERICAL_441_RESPONSE_SMTP_MODEL = "441 No response from the recipient's server";
static int* NUMERICAL_441_RESPONSE_SMTP_MODEL_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 442 response smtp model. */
static unsigned char* NUMERICAL_442_RESPONSE_SMTP_MODEL = "442 Connection dropped";
static int* NUMERICAL_442_RESPONSE_SMTP_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 446 response smtp model. */
static unsigned char* NUMERICAL_446_RESPONSE_SMTP_MODEL = "446 Internal loop has occurred";
static int* NUMERICAL_446_RESPONSE_SMTP_MODEL_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 450 response smtp model. */
static unsigned char* NUMERICAL_450_RESPONSE_SMTP_MODEL = "450 Mailbox unavailable (busy or temporarily blocked). Requested action aborted";
static int* NUMERICAL_450_RESPONSE_SMTP_MODEL_COUNT = NUMBER_79_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 451 response smtp model. */
static unsigned char* NUMERICAL_451_RESPONSE_SMTP_MODEL = "451 The server aborted the command due to a local error";
static int* NUMERICAL_451_RESPONSE_SMTP_MODEL_COUNT = NUMBER_55_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 452 response smtp model. */
static unsigned char* NUMERICAL_452_RESPONSE_SMTP_MODEL = "452 The server aborted the command due to insufficient system storage";
static int* NUMERICAL_452_RESPONSE_SMTP_MODEL_COUNT = NUMBER_69_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 454 response smtp model. */
static unsigned char* NUMERICAL_454_RESPONSE_SMTP_MODEL = "454 TLS not available due to a temporary reason (response to STARTTLS)";
static int* NUMERICAL_454_RESPONSE_SMTP_MODEL_COUNT = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 455 response smtp model. */
static unsigned char* NUMERICAL_455_RESPONSE_SMTP_MODEL = "455 Parameters cannot be accommodated";
static int* NUMERICAL_455_RESPONSE_SMTP_MODEL_COUNT = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 471 response smtp model. */
static unsigned char* NUMERICAL_471_RESPONSE_SMTP_MODEL = "471 Mail server error due to the local spam filter";
static int* NUMERICAL_471_RESPONSE_SMTP_MODEL_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 5xx - fatal server error (permanent)
//

/** The 500 response smtp model. */
static unsigned char* NUMERICAL_500_RESPONSE_SMTP_MODEL = "500 Syntax error (also a command line may be too long). The server cannot recognize the command";
static int* NUMERICAL_500_RESPONSE_SMTP_MODEL_COUNT = NUMBER_95_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 501 response smtp model. */
static unsigned char* NUMERICAL_501_RESPONSE_SMTP_MODEL = "501 Syntax error in parameters or arguments";
static int* NUMERICAL_501_RESPONSE_SMTP_MODEL_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 502 response smtp model. */
static unsigned char* NUMERICAL_502_RESPONSE_SMTP_MODEL = "502 The server has not implemented the command";
static int* NUMERICAL_502_RESPONSE_SMTP_MODEL_COUNT = NUMBER_46_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 503 response smtp model. */
static unsigned char* NUMERICAL_503_RESPONSE_SMTP_MODEL = "503 Improper sequence of commands";
static int* NUMERICAL_503_RESPONSE_SMTP_MODEL_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 504 response smtp model. */
static unsigned char* NUMERICAL_504_RESPONSE_SMTP_MODEL = "504 The server has not implemented a command parameter";
static int* NUMERICAL_504_RESPONSE_SMTP_MODEL_COUNT = NUMBER_54_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 510 response smtp model. */
static unsigned char* NUMERICAL_510_RESPONSE_SMTP_MODEL = "510 Invalid email address";
static int* NUMERICAL_510_RESPONSE_SMTP_MODEL_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 512 response smtp model. */
static unsigned char* NUMERICAL_512_RESPONSE_SMTP_MODEL = "512 A DNS error (recheck the address of your recipients)";
static int* NUMERICAL_512_RESPONSE_SMTP_MODEL_COUNT = NUMBER_56_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 523 response smtp model. */
static unsigned char* NUMERICAL_523_RESPONSE_SMTP_MODEL = "523 The total size of your mailing exceeds the recipient server limits";
static int* NUMERICAL_523_RESPONSE_SMTP_MODEL_COUNT = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 530 response smtp model. */
static unsigned char* NUMERICAL_530_RESPONSE_SMTP_MODEL = "530 Authentication problem that mostly requires the STARTTLS command to run";
static int* NUMERICAL_530_RESPONSE_SMTP_MODEL_COUNT = NUMBER_75_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 535 response smtp model. */
static unsigned char* NUMERICAL_535_RESPONSE_SMTP_MODEL = "535 Authentication failed";
static int* NUMERICAL_535_RESPONSE_SMTP_MODEL_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 538 response smtp model. */
static unsigned char* NUMERICAL_538_RESPONSE_SMTP_MODEL = "538 Encryption required for a requested authentication mechanism";
static int* NUMERICAL_538_RESPONSE_SMTP_MODEL_COUNT = NUMBER_64_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 541 response smtp model. */
static unsigned char* NUMERICAL_541_RESPONSE_SMTP_MODEL = "541 Message rejected by spam filter";
static int* NUMERICAL_541_RESPONSE_SMTP_MODEL_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 550 response smtp model. */
static unsigned char* NUMERICAL_550_RESPONSE_SMTP_MODEL = "550 Mailbox is unavailable. Server aborted the command because the mailbox was not found or for policy reasons. Alternatively: Authentication is required for relay";
static int* NUMERICAL_550_RESPONSE_SMTP_MODEL_COUNT = NUMBER_163_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 551 response smtp model. */
static unsigned char* NUMERICAL_551_RESPONSE_SMTP_MODEL = "551 User not local. The <forward-path> will be specified";
static int* NUMERICAL_551_RESPONSE_SMTP_MODEL_COUNT = NUMBER_56_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 552 response smtp model. */
static unsigned char* NUMERICAL_552_RESPONSE_SMTP_MODEL = "552 The server aborted the command because the mailbox is full";
static int* NUMERICAL_552_RESPONSE_SMTP_MODEL_COUNT = NUMBER_62_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 553 response smtp model. */
static unsigned char* NUMERICAL_553_RESPONSE_SMTP_MODEL = "553 Syntactically incorrect mail address";
static int* NUMERICAL_553_RESPONSE_SMTP_MODEL_COUNT = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 554 response smtp model. */
static unsigned char* NUMERICAL_554_RESPONSE_SMTP_MODEL = "554 The transaction failed due to an unknown error OR: No SMTP service here as a response to the client's attempts to establish a connection";
static int* NUMERICAL_554_RESPONSE_SMTP_MODEL_COUNT = NUMBER_140_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The 555 response smtp model. */
static unsigned char* NUMERICAL_555_RESPONSE_SMTP_MODEL = "555 Parameters not recognized / not implemented (response to MAIL FROM or RCPT TO)";
static int* NUMERICAL_555_RESPONSE_SMTP_MODEL_COUNT = NUMBER_82_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RESPONSE_SMTP_MODEL_CONSTANT_HEADER */
#endif
