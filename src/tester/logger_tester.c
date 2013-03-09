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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_TESTER
#define LOGGER_TESTER

#include <stdio.h>

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../logger/logger.c"

/**
 * Tests the logger standard output.
 */
void test_logger_stdout() {

    log_write((void*) stdout, L"Test logger standard output.\n");
    log_write((void*) stdout, L"It works!\n");
}

/**
 * Tests the logger message.
 */
void test_logger_message() {

    // A log level other than 'OFF' needs to be set for testing!
    // For the logging test result, see the corresponding log file
    // that was given as command line argument!

    /** The log message as constant. */
    static wchar_t TEST_LOG_MESSAGE_ARRAY[] = {L'T', L'E', L'S', L'T', L' ', L'l', L'o', L'g', L' ', L'm', L'e', L's', L's', L'a', L'g', L'e', L'.'};
    static wchar_t* TEST_LOG_MESSAGE = TEST_LOG_MESSAGE_ARRAY;
    static int* TEST_LOG_MESSAGE_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    log_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) TEST_LOG_MESSAGE, (void*) TEST_LOG_MESSAGE_COUNT);
}

/**
 * Tests the logger terminated message.
 */
void test_logger_terminated_message() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test terminated log message.");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"It works!");
}

/**
 * Tests the logger.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_logger() {

//    fwprintf(stdout, L"TEST logger.\n");

//    test_logger_stdout();
//    test_logger_message();
//    test_logger_terminated_message();
}

/* LOGGER_TESTER */
#endif
