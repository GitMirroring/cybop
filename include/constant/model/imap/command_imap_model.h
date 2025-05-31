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

#ifndef COMMAND_IMAP_MODEL_CONSTANT_HEADER
#define COMMAND_IMAP_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/** The APPEND command imap model. */
static unsigned char* APPEND_COMMAND_IMAP_MODEL = "APPEND";
static int* APPEND_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The AUTHENTICATE command imap model. */
static unsigned char* AUTHENTICATE_COMMAND_IMAP_MODEL = "AUTHENTICATE";
static int* AUTHENTICATE_COMMAND_IMAP_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The CAPABILITY command imap model. */
static unsigned char* CAPABILITY_COMMAND_IMAP_MODEL = "CAPABILITY";
static int* CAPABILITY_COMMAND_IMAP_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The CLOSE command imap model. */
static unsigned char* CLOSE_COMMAND_IMAP_MODEL = "CLOSE";
static int* CLOSE_COMMAND_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The COPY command imap model. */
static unsigned char* COPY_COMMAND_IMAP_MODEL = "COPY";
static int* COPY_COMMAND_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The CREATE command imap model. */
static unsigned char* CREATE_COMMAND_IMAP_MODEL = "CREATE";
static int* CREATE_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The DELETE command imap model. */
static unsigned char* DELETE_COMMAND_IMAP_MODEL = "DELETE";
static int* DELETE_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ENABLE command imap model. */
static unsigned char* ENABLE_COMMAND_IMAP_MODEL = "ENABLE";
static int* ENABLE_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXAMINE command imap model. */
static unsigned char* EXAMINE_COMMAND_IMAP_MODEL = "EXAMINE";
static int* EXAMINE_COMMAND_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXPUNGE command imap model. */
static unsigned char* EXPUNGE_COMMAND_IMAP_MODEL = "EXPUNGE";
static int* EXPUNGE_COMMAND_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The FETCH command imap model. */
static unsigned char* FETCH_COMMAND_IMAP_MODEL = "FETCH";
static int* FETCH_COMMAND_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The IDLE command imap model. */
static unsigned char* IDLE_COMMAND_IMAP_MODEL = "IDLE";
static int* IDLE_COMMAND_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The LIST command imap model. */
static unsigned char* LIST_COMMAND_IMAP_MODEL = "LIST";
static int* LIST_COMMAND_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The LOGIN command imap model. */
static unsigned char* LOGIN_COMMAND_IMAP_MODEL = "LOGIN";
static int* LOGIN_COMMAND_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The LOGOUT command imap model. */
static unsigned char* LOGOUT_COMMAND_IMAP_MODEL = "LOGOUT";
static int* LOGOUT_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The MOVE command imap model. */
static unsigned char* MOVE_COMMAND_IMAP_MODEL = "MOVE";
static int* MOVE_COMMAND_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NAMESPACE command imap model. */
static unsigned char* NAMESPACE_COMMAND_IMAP_MODEL = "NAMESPACE";
static int* NAMESPACE_COMMAND_IMAP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NOOP command imap model. */
static unsigned char* NOOP_COMMAND_IMAP_MODEL = "NOOP";
static int* NOOP_COMMAND_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RENAME command imap model. */
static unsigned char* RENAME_COMMAND_IMAP_MODEL = "RENAME";
static int* RENAME_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SEARCH command imap model. */
static unsigned char* SEARCH_COMMAND_IMAP_MODEL = "SEARCH";
static int* SEARCH_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SELECT command imap model. */
static unsigned char* SELECT_COMMAND_IMAP_MODEL = "SELECT";
static int* SELECT_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STARTTLS command imap model. */
static unsigned char* STARTTLS_COMMAND_IMAP_MODEL = "STARTTLS";
static int* STARTTLS_COMMAND_IMAP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STATUS command imap model. */
static unsigned char* STATUS_COMMAND_IMAP_MODEL = "STATUS";
static int* STATUS_COMMAND_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STORE command imap model. */
static unsigned char* STORE_COMMAND_IMAP_MODEL = "STORE";
static int* STORE_COMMAND_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SUBSCRIBE command imap model. */
static unsigned char* SUBSCRIBE_COMMAND_IMAP_MODEL = "SUBSCRIBE";
static int* SUBSCRIBE_COMMAND_IMAP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UID command imap model. */
static unsigned char* UID_COMMAND_IMAP_MODEL = "UID";
static int* UID_COMMAND_IMAP_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UNSELECT command imap model. */
static unsigned char* UNSELECT_COMMAND_IMAP_MODEL = "UNSELECT";
static int* UNSELECT_COMMAND_IMAP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UNSUBSCRIBE command imap model. */
static unsigned char* UNSUBSCRIBE_COMMAND_IMAP_MODEL = "UNSUBSCRIBE";
static int* UNSUBSCRIBE_COMMAND_IMAP_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_IMAP_MODEL_CONSTANT_HEADER */
#endif
