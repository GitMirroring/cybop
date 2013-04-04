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

#ifndef LINE_SPEED_TERMINAL_MODE_SERIALISER_SOURCE
#define LINE_SPEED_TERMINAL_MODE_SERIALISER_SOURCE

#ifdef WIN32
    #include <windows.h>
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

//
// For POSIX.1 portability, one of the following symbols
// has to be used to represent the speed.
// Their precise numeric values are system-dependent,
// but each name has a fixed meaning:
// B110 stands for 110 bps, B300 for 300 bps, and so on.
// There is no portable way to represent any speed but these,
// but these are the only speeds that typical serial lines can support.
//
// B0  B50  B75  B110  B134  B150  B200
// B300  B600  B1200  B1800  B2400  B4800
// B9600  B19200  B38400  B57600  B115200
// B230400  B460800
//
// BSD defines two additional speed symbols as aliases:
// EXTA is an alias for B19200 and EXTB is an alias for B38400.
// These aliases are obsolete.
//
// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Line-Speed
//

/**
 * Serialises integer data into terminal mode line speed.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 */
void serialise_terminal_mode_line_speed(void* p0, void* p1) {
// not ported to WIN32 at the moment ...
#ifdef GNU_LINUX_OPERATING_SYSTEM
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise terminal mode line speed.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The baudrate.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_50_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B50;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_75_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B75;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_110_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B110;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_134_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B134;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_150_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B150;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B200;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_300_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B300;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B600;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B1200;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B1800;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B2400;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B4800;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B9600;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_19200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B19200;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_38400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B38400;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_57600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B57600;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_115200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B115200;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_230400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B230400;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_460800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B460800;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_500000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B500000;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_576000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B576000;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_921600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B921600;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1000000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            b = B1000000;

            overwrite_item_element(p0, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise terminal mode line speed. The line speed is unknown.");
    }
#endif
}

/* LINE_SPEED_TERMINAL_MODE_SERIALISER_SOURCE */
#endif
