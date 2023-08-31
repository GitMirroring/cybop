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

#ifndef RESPONSE_IMAP_MODEL_CONSTANT_HEADER
#define RESPONSE_IMAP_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/** The BAD response imap model. */
static unsigned char* BAD_RESPONSE_IMAP_MODEL = "BAD";
static int* BAD_RESPONSE_IMAP_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The BYE response imap model. */
static unsigned char* BYE_RESPONSE_IMAP_MODEL = "BYE";
static int* BYE_RESPONSE_IMAP_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The CAPABILITY response imap model. */
static unsigned char* CAPABILITY_RESPONSE_IMAP_MODEL = "CAPABILITY";
static int* CAPABILITY_RESPONSE_IMAP_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ENABLED response imap model. */
static unsigned char* ENABLED_RESPONSE_IMAP_MODEL = "ENABLED";
static int* ENABLED_RESPONSE_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ESEARCH response imap model. */
static unsigned char* v_RESPONSE_IMAP_MODEL = "ESEARCH";
static int* ESEARCH_RESPONSE_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXISTS response imap model. */
static unsigned char* EXISTS_RESPONSE_IMAP_MODEL = "EXISTS";
static int* EXISTS_RESPONSE_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The EXPUNGE response imap model. */
static unsigned char* EXPUNGE_RESPONSE_IMAP_MODEL = "EXPUNGE";
static int* EXPUNGE_RESPONSE_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The FETCH response imap model. */
static unsigned char* FETCH_RESPONSE_IMAP_MODEL = "FETCH";
static int* FETCH_RESPONSE_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The FLAGS response imap model. */
static unsigned char* FLAGS_RESPONSE_IMAP_MODEL = "FLAGS";
static int* FLAGS_RESPONSE_IMAP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The LIST response imap model. */
static unsigned char* LIST_RESPONSE_IMAP_MODEL = "LIST";
static int* LIST_RESPONSE_IMAP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NAMESPACE response imap model. */
static unsigned char* NAMESPACE_RESPONSE_IMAP_MODEL = "NAMESPACE";
static int* NAMESPACE_RESPONSE_IMAP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NO response imap model. */
static unsigned char* NO_RESPONSE_IMAP_MODEL = "NO";
static int* NO_RESPONSE_IMAP_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The OK response imap model. */
static unsigned char* OK_RESPONSE_IMAP_MODEL = "OK";
static int* OK_RESPONSE_IMAP_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The PREAUTH response imap model. */
static unsigned char* PREAUTH_RESPONSE_IMAP_MODEL = "PREAUTH";
static int* PREAUTH_RESPONSE_IMAP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The STATUS response imap model. */
static unsigned char* STATUS_RESPONSE_IMAP_MODEL = "STATUS";
static int* STATUS_RESPONSE_IMAP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RESPONSE_IMAP_MODEL_CONSTANT_HEADER */
#endif
