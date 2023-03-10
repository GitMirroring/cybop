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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SCHEME_URI_MODEL_CONSTANT_HEADER
#define SCHEME_URI_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** The ftp scheme uri model. */
static wchar_t* FTP_SCHEME_URI_MODEL = L"ftp";
static int* FTP_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http scheme uri model. */
static wchar_t* HTTP_SCHEME_URI_MODEL = L"http";
static int* HTTP_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ldap scheme uri model. */
static wchar_t* LDAP_SCHEME_URI_MODEL = L"ldap";
static int* LDAP_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mailto scheme uri model. */
static wchar_t* MAILTO_SCHEME_URI_MODEL = L"mailto";
static int* MAILTO_SCHEME_URI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The news scheme uri model. */
static wchar_t* NEWS_SCHEME_URI_MODEL = L"news";
static int* NEWS_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tel scheme uri model. */
static wchar_t* TEL_SCHEME_URI_MODEL = L"tel";
static int* TEL_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The telnet scheme uri model. */
static wchar_t* TELNET_SCHEME_URI_MODEL = L"telnet";
static int* TELNET_SCHEME_URI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The urn scheme uri model. */
static wchar_t* URN_SCHEME_URI_MODEL = L"urn";
static int* URN_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SCHEME_URI_MODEL_CONSTANT_HEADER */
#endif
