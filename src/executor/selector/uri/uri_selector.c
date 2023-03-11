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

#ifndef URI_SELECTOR_SOURCE
#define URI_SELECTOR_SOURCE

#include "../../../executor/checker/operation_checker.c"
#include "../../../executor/representer/deserialiser/uri/http_uri_deserialiser.c"
#include "logger.h"

/**
 * Selects uri.
 *
 * Examples:
 *
 * ftp://ftp.is.co.za/rfc/rfc1808.txt
 * http://www.ietf.org/rfc/rfc2396.txt
 * ldap://[2001:db8::7]/c=GB?objectClass?one
 * mailto:John.Doe@example.com
 * news:comp.infosystems.www.servers.unix
 * tel:+1-816-555-1212
 * telnet://192.0.2.16:80/
 * urn:oasis:names:specification:docbook:dtd:xml:4.1.2
 *
 * CAUTION! Each URI begins with a scheme name that refers to a
 * specification for assigning identifiers within that scheme.
 * As such, the URI syntax is a federated and extensible
 * naming system wherein each scheme's specification may
 * further restrict the syntax and semantics of identifiers
 * using that scheme.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the scheme
 * @param p5 the scheme count
 */
void select_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select uri.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) FTP_SCHEME_URI_MODEL, p5, (void*) FTP_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) HTTP_SCHEME_URI_MODEL, p5, (void*) HTTP_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** pos = (void**) p2;

                deserialise_http_uri(p0, p1, *pos, p3);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select uri. The source data position is null.");
                fwprintf(stdout, L"Error: Could not select uri. The source data position is null. scheme count p5: %i\n", p5);
                fwprintf(stdout, L"Error: Could not select uri. The source data position is null. scheme count *p5: %i\n", *((int*) p5));
            }
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) LDAP_SCHEME_URI_MODEL, p5, (void*) LDAP_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) MAILTO_SCHEME_URI_MODEL, p5, (void*) MAILTO_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) NEWS_SCHEME_URI_MODEL, p5, (void*) NEWS_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) TEL_SCHEME_URI_MODEL, p5, (void*) TEL_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) TELNET_SCHEME_URI_MODEL, p5, (void*) TELNET_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p4, (void*) URN_SCHEME_URI_MODEL, p5, (void*) URN_SCHEME_URI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select uri. The uri scheme is unknown.");
    }
}

/* URI_SELECTOR_SOURCE */
#endif
