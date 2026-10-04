/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <math.h> // M_PI, sin, cos
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Transforms a complex number from polar into cartesian coordinates.
 *
 * @param p0 the destination cartesian coordinates real part
 * @param p1 the destination cartesian coordinates imaginary part
 * @param p2 the source polar coordinates absolute value
 * @param p3 the source polar coordinates argument
 */
void calculate_complex_cartesian_polar(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        double* sa = (double*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            double* sv = (double*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                double* di = (double*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    double* dr = (double*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate complex cartesian polar.");
                    fwprintf(stdout, L"Debug: Calculate complex cartesian polar. absolute value p2: %i\n", p2);
                    fwprintf(stdout, L"Debug: Calculate complex cartesian polar. absolute value *p2: %i\n", *((int*) p2));
                    fwprintf(stdout, L"Debug: Calculate complex cartesian polar. argument p3: %i\n", p3);
                    fwprintf(stdout, L"Debug: Calculate complex cartesian polar. argument *p3: %i\n", *((int*) p3));

                    *dr = (*sv) * (cos(*sa * M_PI / 180.0f));
                    *di = (*sv) * (sin(*sa * M_PI / 180.0f));

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex cartesian polar. The destination cartesian coordinates real part is null.");
                    fwprintf(stdout, L"Error: Could not calculate complex cartesian polar. The destination cartesian coordinates real part is null. real part p0: %i\n", p0);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex cartesian polar. The destination cartesian coordinates imaginary part is null.");
                fwprintf(stdout, L"Error: Could not calculate complex cartesian polar. The destination cartesian coordinates imaginary part is null. imaginary part p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex cartesian polar. The source polar coordinates absolute value is null.");
            fwprintf(stdout, L"Error: Could not calculate complex cartesian polar. The source polar coordinates absolute value is null. absolute value p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate complex cartesian polar. The source polar coordinates argument is null.");
        fwprintf(stdout, L"Error: Could not calculate complex cartesian polar. The source polar coordinates argument is null. argument p3: %i\n", p3);
    }
}
