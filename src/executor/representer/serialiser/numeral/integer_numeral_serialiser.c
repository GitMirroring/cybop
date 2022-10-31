/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTEGER_NUMERAL_SERIALISER_SOURCE
#define INTEGER_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the integer value into a wide character sequence.
 *
 * @param p0 the destination item
 * @param p1 the source number
 * @param p2 the number base
 * @param p3 the sign flag
 * @param p4 the prefix flag
 */
void serialise_numeral_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral integer.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. source number p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. source number *p1: %i\n", *((int*) p1));

    if (zahl < 0) {

        // Append minus sign to destination item.
        append(p0, MINUS);

    } else {

        if (sign-flag != FALSE) {

            // Append plus sign to destination item.
            append(p0, PLUS);
        }
    }

    // Eliminate sign from number.
    calculate_absolute((void*) &n);

    if (prefix-flag != FALSE) {

        if (base == BINARY) {

            // Append binary prefix 0b.
            modify_item("0b", APPEND);

        } else if (base == DECIMAL) {

            //
            // Append NOTHING, since decimal numbers do NOT have a prefix.
            //

        } else if (base == OCTAL) {

            if (classic_flag == FALSE) {

                // Append octal prefix 0o.
                modify_item("0o", APPEND);

            } else {

                // Append octal prefix 0o.
                modify_item("0", APPEND);
            }

        } else if (base == HEXADECIMAL) {

            // Append hexadecimal prefix 0x.
            modify_item("0x", APPEND);

        } else {

            log(Warning: unknown);
        }
    }

    //
    // Append pre-point value.
    //
    // Beispielzahl: 124
    // Basis: 10
    //
    while (TRUE) {

        if (zahl <= 0) {

            break;
        }

        // Calculate remainder.
        rest(4) = zahl mod base(10);

        // Insert remainder as digit at the BEGINNING.
        insert_at_index_zero(rest);

        // Divide number by base.
        zahl = zahl / base(10);
    }
}

/* INTEGER_NUMERAL_SERIALISER_SOURCE */
#endif
