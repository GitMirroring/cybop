/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVICE_SOCKET_CYBOL_MODEL_CONSTANT_HEADER
#define SERVICE_SOCKET_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The file transfer protocol (ftp) service socket cybol model. */
static wchar_t* FTP_SERVICE_SOCKET_CYBOL_MODEL = L"ftp";
static int* FTP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hypertext transfer protocol (http) service socket cybol model. */
static wchar_t* HTTP_SERVICE_SOCKET_CYBOL_MODEL = L"http";
static int* HTTP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hypertext transfer protocol secure (https) service socket cybol model. */
static wchar_t* HTTPS_SERVICE_SOCKET_CYBOL_MODEL = L"https";
static int* HTTPS_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imap service socket cybol model. */
static wchar_t* IMAP_SERVICE_SOCKET_CYBOL_MODEL = L"imap";
static int* IMAP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imaps service socket cybol model. */
static wchar_t* IMAPS_SERVICE_SOCKET_CYBOL_MODEL = L"imaps";
static int* IMAPS_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nntp service socket cybol model. */
static wchar_t* NNTP_SERVICE_SOCKET_CYBOL_MODEL = L"nntp";
static int* NNTP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The post office protocol 3 (pop3) service socket cybol model. */
static wchar_t* POP3_SERVICE_SOCKET_CYBOL_MODEL = L"pop3";
static int* POP3_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The secure file transfer protocol (sftp) service socket cybol model. */
static wchar_t* SFTP_SERVICE_SOCKET_CYBOL_MODEL = L"sftp";
static int* SFTP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smtp service socket cybol model. */
static wchar_t* SMTP_SERVICE_SOCKET_CYBOL_MODEL = L"smtp";
static int* SMTP_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smtps service socket cybol model. */
static wchar_t* SMTPS_SERVICE_SOCKET_CYBOL_MODEL = L"smtps";
static int* SMTPS_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The secure shell (ssh) service socket cybol model. */
static wchar_t* SSH_SERVICE_SOCKET_CYBOL_MODEL = L"ssh";
static int* SSH_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The telnet service socket cybol model. */
static wchar_t* TELNET_SERVICE_SOCKET_CYBOL_MODEL = L"telnet";
static int* TELNET_SERVICE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SERVICE_SOCKET_CYBOL_MODEL_CONSTANT_HEADER */
#endif
