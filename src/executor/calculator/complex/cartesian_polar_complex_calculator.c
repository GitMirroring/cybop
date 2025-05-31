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

//
// System interface
//

#include <math.h> // M_PI, sqrt, atan, abs
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Transforms a complex number from cartesian into polar coordinates.
 *
 * @param p0 the destination polar coordinates absolute value
 * @param p1 the destination polar coordinates argument
 * @param p2 the source cartesian coordinates real part
 * @param p3 the source cartesian coordinates imaginary part
 */
void calculate_complex_polar_cartesian(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        double* si = (double*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            double* sr = (double*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                double* da = (double*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    double* dv = (double*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate complex polar cartesian.");
                    fwprintf(stdout, L"Debug: Calculate complex polar cartesian. real part p2: %i\n", p2);
                    fwprintf(stdout, L"Debug: Calculate complex polar cartesian. real part *p2: %i\n", *((int*) p2));
                    fwprintf(stdout, L"Debug: Calculate complex polar cartesian. imaginary part p3: %i\n", p3);
                    fwprintf(stdout, L"Debug: Calculate complex polar cartesian. imaginary part *p3: %i\n", *((int*) p3));

                    *dv = sqrt((((*sr) * (*sr)) + ((*si) * (*si))));
                    *da = (180.0f * (M_PI - atan((*si) / abs(*sr)))) / M_PI;

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex polar cartesian. The destination polar coordinates absolute value is null.");
                    fwprintf(stdout, L"Error: Could not calculate complex polar cartesian. The destination polar coordinates absolute value is null. absolute value p0: %i\n", p0);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex polar cartesian. The destination polar coordinates argument is null.");
                fwprintf(stdout, L"Error: Could not calculate complex polar cartesian. The destination polar coordinates argument is null. argument p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex polar cartesian. The source cartesian coordinates real part is null.");
            fwprintf(stdout, L"Error: Could not calculate complex polar cartesian. The source cartesian coordinates real part is null. real part p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex polar cartesian. The source cartesian coordinates imaginary part is null.");
        fwprintf(stdout, L"Error: Could not calculate complex polar cartesian. The source cartesian coordinates imaginary part is null. imaginary part p3: %i\n", p3);
    }
}
