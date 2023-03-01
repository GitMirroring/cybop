/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE
#define END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/selector/xdt/bdt/number_1210_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1250_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1271_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1290_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1297_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1298_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1299_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1301_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1303_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1305_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1330_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1400_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1500_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1502_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1503_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1600_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1702_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_1800_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_2002_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_201_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_203_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_207_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_212_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_213_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_250_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_252_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_2803_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3050_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_300_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_301_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_302_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_304_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_307_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3101_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3120_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3301_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3310_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3399_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3423_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3425_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3454_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3465_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3472_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3501_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3504_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3505_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3515_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3510_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3511_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3528_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3531_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3541_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3602_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3622_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3623_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3632_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3637_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3649_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3650_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3651_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3652_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3653_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3655_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3656_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3657_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3658_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3659_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3660_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3661_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3669_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3662_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3672_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3673_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3689_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3700_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_3702_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_4217_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_4218_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_4234_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_4235_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_4244_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5000_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5001_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5012_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5020_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5035_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_5042_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6000_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6001_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6007_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6011_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6200_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6201_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6202_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6206_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6207_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6208_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6210_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6212_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6226_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6228_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6230_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6235_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6285_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6290_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6300_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6302_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6306_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6310_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6312_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6325_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6330_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_6332_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_80_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8000_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8010_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8401_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8410_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8411_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8430_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8445_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8510_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_8520_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_919_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_920_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_925_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_9260_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_9801_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_9802_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_9806_end_compound_field_bdt_xdt_selector.c"
#include "../../../../executor/selector/xdt/bdt/number_9900_end_compound_field_bdt_xdt_selector.c"
#include "../../../../logger/logger.c"

/**
 * Checks if the source field is permitted to be a child of parent.
 *
 * If it is not, then the source field demarcates the end
 * of the compound parent field's children.
 *
 * @param p0 the end flag
 * @param p1 the source field name
 * @param p2 the parent field name
 */
void select_xdt_bdt_field_compound_end(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt field compound end.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Record 0001
    //

    //
    // Record 0020
    //

    //
    // Record spec
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9900_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9900(p0, p1);
        }
    }

    //
    // Record iden
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9806_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9806(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9801(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9802_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9802(p0, p1);
        }
    }

    //
    // Record 0010
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9806_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9806(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9801(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1297_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1297(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1298_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1298(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1299_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1299(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_213_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_213(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_207(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_250_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_250(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_252_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_252(p0, p1);
        }
    }

    //
    // Record adrs
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1210(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_307_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_307(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1250_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1250(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1271_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1271(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1290_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1290(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1297_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1297(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1298_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1298(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1299_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1299(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3050_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3050(p0, p1);
        }
    }

    //
    // Record term
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1301(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1303_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1303(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1305_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1305(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1330_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1330(p0, p1);
        }
    }
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6201_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6201(p0, p1);
        }
    }

    //
    // Record diag
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1400(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6000(p0, p1);
        }
    }

    //
    // Record grnk
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1500_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1500(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1502_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1502(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5001(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1503_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1503(p0, p1);
        }
    }

    //
    // Record hapo
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1600(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6206(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_925_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_925(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_919_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_919(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6207(p0, p1);
        }
    }

    //
    // Record bbst
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1702_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1702(p0, p1);
        }
    }

    //
    // Record text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1800(p0, p1);
        }
    }

    //
    // Record 6100
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9801(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3632_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3632(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3528_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3528(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3120_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3120(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3602_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3602(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3310(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3650_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3650(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3653_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3653(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3655_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3655(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3657_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3657(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3659_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3659(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3661_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3661(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3669_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4218(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3702_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3702(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_920_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_920(p0, p1);
        }
    }

    //
    // Record 6200
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6200(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_80_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_80(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6011_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6011(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3622_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3622(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3623_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3623(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6230_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6230(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_925_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_925(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_919_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_919(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3637_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3637(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6325_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6325(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_2803_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_2803(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6210(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6285_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6285(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6290_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6290(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6300_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6300(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6306_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6306(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6310(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6312_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6312(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6330_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6330(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6332_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6332(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8401_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8401(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8410_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8410(p0, p1);
        }
    }


    //
    // Record 0101
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8000(p0, p1);
        }
    }

    //
    // Record 0102
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8000(p0, p1);
        }
    }

    //
    // Record 0103
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8000(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4234_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4234(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4235_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4235(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4244_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4244(p0, p1);
        }
    }

    //
    // Record 0104
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8000(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5020_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5020(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5035_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5035(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5042_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5042(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3672_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3672(p0, p1);
        }
    }

    //
    // Record 0109
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8000(p0, p1);
        }
    }

    //
    // Record sad1
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5000(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5001(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5012(p0, p1);
        }
    }

    //
    // Record sad2
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4218(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5000(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5001(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5012(p0, p1);
        }
    }

    //
    // Record sad3
    //
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5000(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5001(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_5012(p0, p1);
        }
    }

    //
    // Record gevk
    //

    //
    // Record hävg
    //

    //
    // Record medi
    //

    //
    // Record kv
    //

    //
    // Record padx
    //

    //
    // Record 0021
    //

    //
    // Record 0002
    //

    //
    // Record frei
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8010_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8010(p0, p1);
        }
    }

    //
    // Record 6310 (GDT)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6200(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6202_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6202(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6206(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6226_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6226(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6228_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6228(p0, p1);
        }
    }


    //
    // Record Obj_Allergien
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3656_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3656(p0, p1);
        }
    }

    //
    // Record Obj_Anhang
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6302_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6302(p0, p1);
        }
    }

    //
    // Record Obj_Basisdiagnostik
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3399_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3399(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3658_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3658(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3660_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3660(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3662_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3662(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3700_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3700(p0, p1);
        }
    }

    //
    // Record Obj_Betriebsstätte
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_203_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_203(p0, p1);
        }
    }

    //
    // Record Obj_Diabetes
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3423_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3423(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3425_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3425(p0, p1);
        }
    }

    //
    // Record Obj_Diagnose
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6001(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6007_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6007(p0, p1);
        }
    }

    //
    // Record Obj_Epilepsie
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3454_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3454(p0, p1);
        }
    }

    //
    // Record Obj_Impfungen
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3531_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3531(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8520_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8520(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3541_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3541(p0, p1);
        }
    }

    //
    // Record Obj_Implantat
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3465_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3465(p0, p1);
        }
    }

    //
    // Record Obj_Krankenversicherung
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_2002_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_2002(p0, p1);
        }
    }

    //
    // Record Obj_Laborergebnis
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8411_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8411(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8430_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8430(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8445_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8445(p0, p1);
        }
    }

    //
    // Record Obj_Medikationsplan
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3301(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6208_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6208(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6212_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6212(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8520_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8520(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3689_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3689(p0, p1);
        }
    }

    //
    // Record Obj_Mutterschaft
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_8510_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_8510(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3472_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3472(p0, p1);
        }
    }

    //
    // Record Obj_Patient
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3101_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3101(p0, p1);
        }
    }

    //
    // Record Obj_Röntgenpass
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3501_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3501(p0, p1);
        }
    }

    //
    // Record Obj_Standardadresse
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1271_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1271(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1290_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_1290(p0, p1);
        }
    }

    //
    // Record Obj_Strahlenpass
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3504_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3504(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3505_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3505(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3515_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3515(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3510_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3510(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3511_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3511(p0, p1);
        }
    }

    //
    // Record Obj_Dauermedikament (GDT)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3651_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3651(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3652_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3652(p0, p1);
        }
    }

    //
    // Record Obj_Dauerdiagnose (GDT)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3649_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3649(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3673_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_3673(p0, p1);
        }
    }

    //
    // Record Obj_Überweisung (GDT)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4217_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4217(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_4218(p0, p1);
        }
    }

    //
    // Record besa
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_201_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_201(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_212_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_212(p0, p1);
        }
    }

    //
    // Record adt0 (kvdt)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9260_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9260(p0, p1);
        }
    }

    //
    // Record rvsa (kvdt)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_300_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_300(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_301(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_302_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_302(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_304_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_304(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT log this case, since it is normal on the root level
        // of each record, where fields do NOT have a parent field.
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt bdt field compound end. The parent field name is unknown.");
        // fwprintf(stdout, L"Warning: Could not select xdt bdt field compound end. The parent field name is unknown. parent field name p2: %i\n", p2);
        // fwprintf(stdout, L"Warning: Could not select xdt bdt field compound end. The parent field name is unknown. parent field name *p2: %i\n", *((int*) p2));
        //
    }
}

/* END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE */
#endif
