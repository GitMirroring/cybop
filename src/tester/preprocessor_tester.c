/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PREPROCESSOR_TESTER
#define PREPROCESSOR_TESTER

#include "../logger/logger.c"

/**
 * Tests the preprocessor directives.
 */
void test_preprocessor_directives() {

    log_write((void*) stdout, L"Test preprocessor directives:\n");

#ifdef GNU_LINUX_OPERATING_SYSTEM
    log_write((void*) stdout, L"GNU_LINUX\n");
#elif WINDOWS_OPERATING_SYSTEM
    log_write((void*) stdout, L"WINDOWS\n");
#elif WIN32
    log_write((void*) stdout, L"WIN32\n");
#else
    log_write((void*) stdout, L"OTHER\n");
/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/**
 * Tests the preprocessor.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_preprocessor() {

//    fwprintf(stdout, L"TEST preprocessor.\n");

//    test_preprocessor_directives();
}

/* PREPROCESSOR_TESTER */
#endif
