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

#ifndef HELP_CYBOI_MODEL_CONSTANT_HEADER
#define HELP_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The arguments help cyboi model. */
static wchar_t* ARGUMENTS_HELP_CYBOI_MODEL = L"Arguments have to be given!";
static int* ARGUMENTS_HELP_CYBOI_MODEL_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The usage help cyboi model. */
static wchar_t* USAGE_HELP_CYBOI_MODEL = L"Usage: cyboi ARG [--knowledge=ARG] [--loglevel=ARG] [--logfile=ARG] [--help] [--version]\n"
                                                  L"\tARG\t\tStarts cyboi in knowledge mode. Takes ARG as cybol knowledge file. This is the standard way to use cyboi.\n"
                                                  L"\t--knowledge=ARG\tStarts cyboi in knowledge mode. Takes ARG as cybol knowledge file. This is the long form.\n"
                                                  L"\t--loglevel=ARG\tSets the log level. The ARG may be one of: off, error, warning, information, debug. The default is off.\n"
                                                  L"\t--logfile=ARG\tLogs messages to the file specified by ARG.\n"
                                                  L"\t--help\t\tDisplays this help message.\n"
                                                  L"\t--version\tDisplays the current version.";
static int* USAGE_HELP_CYBOI_MODEL_COUNT = NUMBER_564_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examples help cyboi model. */
static wchar_t* EXAMPLES_HELP_CYBOI_MODEL = L"Examples:\n"
                                                  L"\tcyboi resmedicinae/run.cybol\n"
                                                  L"\tcyboi --knowledge=resmedicinae/run.cybol\n"
                                                  L"\tcyboi --knowledge=resmedicinae/run.cybol --loglevel=error --logfile=error.log";
static int* EXAMPLES_HELP_CYBOI_MODEL_COUNT = NUMBER_160_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bugs help cyboi model. */
static wchar_t* BUGS_HELP_CYBOI_MODEL = L"Report bugs to <cybop-developers@nongnu.org> or <christian.heller@cybop.org>.";
static int* BUGS_HELP_CYBOI_MODEL_COUNT = NUMBER_77_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HELP_CYBOI_MODEL_CONSTANT_HEADER */
#endif
