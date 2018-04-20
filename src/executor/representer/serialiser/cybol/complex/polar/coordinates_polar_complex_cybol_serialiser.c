/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE
#define COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE

#include <math.h>

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the cartesian coordinates into polar coordinates.
 *
 * @param p0 the destination polar coordinates absolute value
 * @param p1 the destination polar coordinates argument
 * @param p2 the source cartesian coordinates real part
 * @param p3 the source cartesian coordinates imaginary part
 */
void serialise_cybol_complex_polar_coordinates(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        double* si = (double*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            double* sr = (double*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                double* da = (double*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    double* dv = (double*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol complex polar coordinates.");

                    *dv = sqrt(((*sr * *sr) + (*si * *si)));

                    // \src\executor\representer\serialiser\cybol\complex\polar\coordinates_polar_complex_cybol_serialiser.c(66):
                    // warning C4244: 'Funktion': Konvertierung von 'double' in 'int', möglicher Datenverlust
                    // *da = (180 * (M_PI - atan(*si / abs(*sr)))) / M_PI;
                    // changed to:

                    *da = (180 * (M_PI - atan(*si / fabs(*sr)))) / M_PI;

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise complex number. The destination polar coordinates absolute value is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise complex number. The destination polar coordinates argument is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise complex number. The source cartesian coordinates real part is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise complex number. The source cartesian coordinates imaginary part is null.");
    }
}

/* COORDINATES_POLAR_COMPLEX_CYBOL_SERIALISER_SOURCE */
#endif
