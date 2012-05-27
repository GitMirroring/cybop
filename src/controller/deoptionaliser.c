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

#ifndef DEOPTIONALISER_SOURCE
#define DEOPTIONALISER_SOURCE

#include "../controller/deoptionaliser/log_file_deoptionaliser.c"

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the log file stream
 */
void deoptionalise(void* p0) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Do NOT show the following message, as it would only disturb the user!
    // log_write((void*) stdout, L"Information: Deoptionalise command line argument options.\n");

    // Deoptionalise log file.
    deoptionalise_log_file(p0);
}

/* DEOPTIONALISER_SOURCE */
#endif
