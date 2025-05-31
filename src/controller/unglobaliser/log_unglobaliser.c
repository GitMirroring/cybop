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

/**
 * Finalises log global variables.
 */
void unglobalise_log() {

    //
    // CAUTION! The LOG_MESSAGE was defined as static global variable.
    // It thus gets destroyed automatically and does NOT have to be freed here.
    //

    //
    // CAUTION! Do NOT try to free the log output of type FILE!
    // It was already closed in module "deoptionaliser.c".
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // Hence, the following line would NOT make sense and is FORBIDDEN:
    // free(LOG_OUTPUT);
    //
}
