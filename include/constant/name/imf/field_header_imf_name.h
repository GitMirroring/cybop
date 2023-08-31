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

#ifndef FIELD_HEADER_IMF_NAME_CONSTANT_HEADER
#define FIELD_HEADER_IMF_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The Bcc field header imf name. */
static unsigned char* BCC_FIELD_HEADER_IMF_NAME = "Bcc";
static int* BCC_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Cc field header imf name. */
static unsigned char* CC_FIELD_HEADER_IMF_NAME = "Cc";
static int* CC_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Comments field header imf name. */
static unsigned char* COMMENTS_FIELD_HEADER_IMF_NAME = "Comments";
static int* COMMENTS_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Date field header imf name. */
static unsigned char* DATE_FIELD_HEADER_IMF_NAME = "Date";
static int* DATE_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The From field header imf name. */
static unsigned char* FROM_FIELD_HEADER_IMF_NAME = "From";
static int* FROM_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The In-Reply-To field header imf name. */
static unsigned char* IN_REPLY_TO_FIELD_HEADER_IMF_NAME = "In-Reply-To";
static int* IN_REPLY_TO_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Keywords field header imf name. */
static unsigned char* KEYWORDS_FIELD_HEADER_IMF_NAME = "Keywords";
static int* KEYWORDS_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Message-ID field header imf name. */
static unsigned char* MESSAGE_ID_FIELD_HEADER_IMF_NAME = "Message-ID";
static int* MESSAGE_ID_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Received field header imf name. */
static unsigned char* RECEIVED_FIELD_HEADER_IMF_NAME = "Received";
static int* RECEIVED_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The References field header imf name. */
static unsigned char* REFERENCES_FIELD_HEADER_IMF_NAME = "References";
static int* REFERENCES_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Reply-To field header imf name. */
static unsigned char* REPLY_TO_FIELD_HEADER_IMF_NAME = "Reply-To";
static int* REPLY_TO_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Bcc field header imf name. */
static unsigned char* RESENT_BCC_FIELD_HEADER_IMF_NAME = "Resent-Bcc";
static int* RESENT_BCC_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Cc field header imf name. */
static unsigned char* RESENT_CC_FIELD_HEADER_IMF_NAME = "Resent-Cc";
static int* RESENT_CC_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Date field header imf name. */
static unsigned char* RESENT_DATE_FIELD_HEADER_IMF_NAME = "Resent-Date";
static int* RESENT_DATE_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-From field header imf name. */
static unsigned char* RESENT_FROM_FIELD_HEADER_IMF_NAME = "Resent-From";
static int* RESENT_FROM_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Message-ID field header imf name. */
static unsigned char* RESENT_MESSAGE_ID_FIELD_HEADER_IMF_NAME = "Resent-Message-ID";
static int* RESENT_MESSAGE_ID_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Reply-To (OBSOLETE) field header imf name. */
static unsigned char* RESENT_REPLY_TO_FIELD_HEADER_IMF_NAME = "Resent-Reply-To";
static int* RESENT_REPLY_TO_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-Sender field header imf name. */
static unsigned char* RESENT_SENDER_FIELD_HEADER_IMF_NAME = "Resent-Sender";
static int* RESENT_SENDER_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Resent-To field header imf name. */
static unsigned char* RESENT_TO_FIELD_HEADER_IMF_NAME = "Resent-To";
static int* RESENT_TO_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Return-Path field header imf name. */
static unsigned char* RETURN_PATH_FIELD_HEADER_IMF_NAME = "Return-Path";
static int* RETURN_PATH_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Sender field header imf name. */
static unsigned char* SENDER_FIELD_HEADER_IMF_NAME = "Sender";
static int* SENDER_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Subject field header imf name. */
static unsigned char* SUBJECT_FIELD_HEADER_IMF_NAME = "Subject";
static int* SUBJECT_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The To field header imf name. */
static unsigned char* TO_FIELD_HEADER_IMF_NAME = "To";
static int* TO_FIELD_HEADER_IMF_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FIELD_HEADER_IMF_NAME_CONSTANT_HEADER */
#endif
