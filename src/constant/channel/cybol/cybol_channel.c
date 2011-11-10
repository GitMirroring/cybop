/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CHANNEL_CONSTANT_SOURCE
#define CYBOL_CHANNEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The common object request broker architecture (corba) cybol channel. */
static wchar_t CORBA_CYBOL_CHANNEL_ARRAY[] = {L'c', L'o', L'r', L'b', L'a'};
static wchar_t* CORBA_CYBOL_CHANNEL = CORBA_CYBOL_CHANNEL_ARRAY;
static int* CORBA_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi cybol channel. */
static wchar_t CYBOI_CYBOL_CHANNEL_ARRAY[] = {L'c', L'y', L'b', L'o', L'i'};
static wchar_t* CYBOI_CYBOL_CHANNEL = CYBOI_CYBOL_CHANNEL_ARRAY;
static int* CYBOI_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The file system cybol channel. */
static wchar_t FILE_SYSTEM_CYBOL_CHANNEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_SYSTEM_CYBOL_CHANNEL = FILE_SYSTEM_CYBOL_CHANNEL_ARRAY;
static int* FILE_SYSTEM_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The floppy cybol channel. */
static wchar_t FLOPPY_CYBOL_CHANNEL_ARRAY[] = {L'f', L'l', L'o', L'p', L'p', L'y'};
static wchar_t* FLOPPY_CYBOL_CHANNEL = FLOPPY_CYBOL_CHANNEL_ARRAY;
static int* FLOPPY_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The file transfer protocol (ftp) cybol channel. */
static wchar_t FTP_CYBOL_CHANNEL_ARRAY[] = {L'f', L't', L'p'};
static wchar_t* FTP_CYBOL_CHANNEL = FTP_CYBOL_CHANNEL_ARRAY;
static int* FTP_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The hypertext transfer protocol (http) location. */
static wchar_t HTTP_CYBOL_CHANNEL_ARRAY[] = {L'h', L't', L't', L'p'};
static wchar_t* HTTP_CYBOL_CHANNEL = HTTP_CYBOL_CHANNEL_ARRAY;
static int* HTTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The imap cybol channel. */
static wchar_t IMAP_CYBOL_CHANNEL_ARRAY[] = {L'i', L'm', L'a', L'p'};
static wchar_t* IMAP_CYBOL_CHANNEL = IMAP_CYBOL_CHANNEL_ARRAY;
static int* IMAP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The imaps cybol channel. */
static wchar_t IMAPS_CYBOL_CHANNEL_ARRAY[] = {L'i', L'm', L'a', L'p', L's'};
static wchar_t* IMAPS_CYBOL_CHANNEL = IMAPS_CYBOL_CHANNEL_ARRAY;
static int* IMAPS_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The inline cybol channel. */
static wchar_t INLINE_CYBOL_CHANNEL_ARRAY[] = {L'i', L'n', L'l', L'i', L'n', L'e'};
static wchar_t* INLINE_CYBOL_CHANNEL = INLINE_CYBOL_CHANNEL_ARRAY;
static int* INLINE_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The java messaging service (jms) cybol channel. */
static wchar_t JMS_CYBOL_CHANNEL_ARRAY[] = {L'j', L'm', L's'};
static wchar_t* JMS_CYBOL_CHANNEL = JMS_CYBOL_CHANNEL_ARRAY;
static int* JMS_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The lamport tex (latex) cybol channel. */
static wchar_t LATEX_CYBOL_CHANNEL_ARRAY[] = {L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_CYBOL_CHANNEL = LATEX_CYBOL_CHANNEL_ARRAY;
static int* LATEX_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The ldap cybol channel. */
static wchar_t LDAP_CYBOL_CHANNEL_ARRAY[] = {L'l', L'd', L'a', L'p'};
static wchar_t* LDAP_CYBOL_CHANNEL = LDAP_CYBOL_CHANNEL_ARRAY;
static int* LDAP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The nfs cybol channel. */
static wchar_t NFS_CYBOL_CHANNEL_ARRAY[] = {L'n', L'f', L's'};
static wchar_t* NFS_CYBOL_CHANNEL = NFS_CYBOL_CHANNEL_ARRAY;
static int* NFS_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The nntp cybol channel. */
static wchar_t NNTP_CYBOL_CHANNEL_ARRAY[] = {L'n', L'n', L't', L'p'};
static wchar_t* NNTP_CYBOL_CHANNEL = NNTP_CYBOL_CHANNEL_ARRAY;
static int* NNTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The remote method invocation (rmi) cybol channel. */
static wchar_t RMI_CYBOL_CHANNEL_ARRAY[] = {L'r', L'm', L'i'};
static wchar_t* RMI_CYBOL_CHANNEL = RMI_CYBOL_CHANNEL_ARRAY;
static int* RMI_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The secure file transfer protocol (sftp) cybol channel. */
static wchar_t SFTP_CYBOL_CHANNEL_ARRAY[] = {L's', L'f', L't', L'p'};
static wchar_t* SFTP_CYBOL_CHANNEL = SFTP_CYBOL_CHANNEL_ARRAY;
static int* SFTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The shell cybol channel. */
static wchar_t SHELL_CYBOL_CHANNEL_ARRAY[] = {L's', L'h', L'e', L'l', L'l'};
static wchar_t* SHELL_CYBOL_CHANNEL = SHELL_CYBOL_CHANNEL_ARRAY;
static int* SHELL_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The smb cybol channel. */
static wchar_t SMB_CYBOL_CHANNEL_ARRAY[] = {L's', L'm', L'b'};
static wchar_t* SMB_CYBOL_CHANNEL = SMB_CYBOL_CHANNEL_ARRAY;
static int* SMB_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The smtp cybol channel. */
static wchar_t SMTP_CYBOL_CHANNEL_ARRAY[] = {L's', L'm', L't', L'p'};
static wchar_t* SMTP_CYBOL_CHANNEL = SMTP_CYBOL_CHANNEL_ARRAY;
static int* SMTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The smtps cybol channel. */
static wchar_t SMTPS_CYBOL_CHANNEL_ARRAY[] = {L's', L'm', L't', L'p', L's'};
static wchar_t* SMTPS_CYBOL_CHANNEL = SMTPS_CYBOL_CHANNEL_ARRAY;
static int* SMTPS_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The simple object access protocol (soap) cybol channel. */
static wchar_t SOAP_CYBOL_CHANNEL_ARRAY[] = {L's', L'o', L'a', L'p'};
static wchar_t* SOAP_CYBOL_CHANNEL = SOAP_CYBOL_CHANNEL_ARRAY;
static int* SOAP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The socket cybol channel. */
static wchar_t SOCKET_CYBOL_CHANNEL_ARRAY[] = {L's', L'o', L'c', L'k', L'e', L't'};
static wchar_t* SOCKET_CYBOL_CHANNEL = SOCKET_CYBOL_CHANNEL_ARRAY;
static int* SOCKET_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The structured query language (sql) cybol channel. */
static wchar_t SQL_CYBOL_CHANNEL_ARRAY[] = {L's', L'q', L'l'};
static wchar_t* SQL_CYBOL_CHANNEL = SQL_CYBOL_CHANNEL_ARRAY;
static int* SQL_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The terminal cybol channel. */
static wchar_t TERMINAL_CYBOL_CHANNEL_ARRAY[] = {L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l'};
static wchar_t* TERMINAL_CYBOL_CHANNEL = TERMINAL_CYBOL_CHANNEL_ARRAY;
static int* TERMINAL_CYBOL_CHANNEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The world wide web (www) cybol channel. */
static wchar_t WWW_CYBOL_CHANNEL_ARRAY[] = {L'w', L'w', L'w'};
static wchar_t* WWW_CYBOL_CHANNEL = WWW_CYBOL_CHANNEL_ARRAY;
static int* WWW_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The x window system cybol channel. */
static wchar_t X_WINDOW_SYSTEM_CYBOL_CHANNEL_ARRAY[] = {L'x', L'-', L'w', L'i', L'n', L'd', L'o', L'w', L'-', L's', L'y', L's', L't', L'e', L'm'};
static wchar_t* X_WINDOW_SYSTEM_CYBOL_CHANNEL = X_WINDOW_SYSTEM_CYBOL_CHANNEL_ARRAY;
static int* X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOL_CHANNEL_CONSTANT_SOURCE */
#endif
