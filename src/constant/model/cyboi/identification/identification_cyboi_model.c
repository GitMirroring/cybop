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

#ifndef IDENTIFICATION_CYBOI_MODEL_CONSTANT_SOURCE
#define IDENTIFICATION_CYBOI_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The name identification cyboi model. */
static wchar_t* NAME_IDENTIFICATION_CYBOI_MODEL = L"Cybernetics Oriented Interpreter (CYBOI)";
static int* NAME_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The version identification cyboi model. */
static wchar_t* VERSION_IDENTIFICATION_CYBOI_MODEL = L"0.19.0";
static int* VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The slogan identification cyboi model. */
static wchar_t* SLOGAN_IDENTIFICATION_CYBOI_MODEL = L"A universal system.";
static int* SLOGAN_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copyright identification cyboi model. */
static wchar_t* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL = L"Copyright (C) 1999-2017. Christian Heller.";
static int* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The licence identification cyboi model. */
static wchar_t* LICENCE_IDENTIFICATION_CYBOI_MODEL = L"CYBOI comes with NO WARRANTY,\n"
                                                     L"to the extent permitted by law.\n"
                                                     L"You may redistribute copies of CYBOI\n"
                                                     L"under the terms of the GNU General Public License.\n"
                                                     L"For more information about these matters,\n"
                                                     L"see the files named COPYING.";
static int* LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help identification cyboi model. */
static wchar_t* HELP_IDENTIFICATION_CYBOI_MODEL = L"Arguments have to be given!\n"
                                                  L"Usage: cyboi ARG [--knowledge=ARG] [--loglevel=ARG] [--logfile=ARG] [--help] [--version]\n"
                                                  L"\tARG\t\tStarts cyboi in knowledge mode. Takes ARG as cybol knowledge file. This is the standard way to use cyboi.\n"
                                                  L"\t--knowledge=ARG\tStarts cyboi in knowledge mode. Takes ARG as cybol knowledge file. This is the long form.\n"
                                                  L"\t--loglevel=ARG\tSets the log level. The ARG may be one of: off, error, warning, information, debug. The default is off.\n"
                                                  L"\t--logfile=ARG\tLogs messages to the file specified by ARG.\n"
                                                  L"\t--help\t\tDisplays this help message.\n"
                                                  L"\t--version\tDisplays the current version.\n"
                                                  L"Examples:\n"
                                                  L"\tcyboi resmedicinae/run.cybol\n"
                                                  L"\tcyboi --knowledge=resmedicinae/run.cybol\n"
                                                  L"\tcyboi --knowledge=resmedicinae/run.cybol --loglevel=error --logfile=error.log\n"
                                                  L"Report bugs to <cybop-developers@nongnu.org> or <christian.heller@tuxtax.de>.";
static int* HELP_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_965_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* IDENTIFICATION_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
