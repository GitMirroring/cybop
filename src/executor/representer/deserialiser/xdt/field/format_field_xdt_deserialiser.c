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
 * Birgit Heller <birgit.h@arcor.de>
 * Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FORMAT_FIELD_XDT_DESERIALISER_SOURCE
#define FORMAT_FIELD_XDT_DESERIALISER_SOURCE

#include "../../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the xdt field format into a cyboi format.
 *
 * The fields listed in the xdt standard have
 * defined formats (types), e.g.:
 * - n = num = numeric
 * - f = float
 * - a = alnum = alphanumeric
 * - d = date
 * - 2xd = duration
 * - 4 = ??
 *
 * The following constants may be returned:
 * - INTEGER_NUMBER_STATE_CYBOI_FORMAT
 * - FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT
 * - PLAIN_TEXT_STATE_CYBOI_FORMAT
 * - YYYY_DATETIME_STATE_CYBOI_FORMAT
 * - DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT
 * - HHMM_DATETIME_STATE_CYBOI_FORMAT
 * - YYYYYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT
 * - MMYYYYMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT
 * - DDMMYYYYDDMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT
 * 
 * @param p0 the destination cyboi format data
 * @param p1 the source xdt field identification data
 */
void deserialise_xdt_field_format(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field format.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // BDT meta data
    //
    // German: Metadaten zur BDT-Übermittlung 
    // 0000 - 0049 0050 - 0079 0080 - 0099
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_51_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_52_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_53_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_54_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_55_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_57_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_58_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_80_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_78_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
        

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_79_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    //
    // Medical practice administrative data
    //
    // German: Praxisdaten
    // 01xx 02xx 03xx 04xx 05xx
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_102_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_103_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
   
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_104_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_105_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_111_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_121_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_122_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_123_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_124_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_125_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_132_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_201_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_203_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_205_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_208_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_209_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_211_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_212_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_213_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_215_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_216_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_219_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_220_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_221_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_306_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_307_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_308_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_309_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_423_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // ???
    //
    // ???
    // 09xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_919_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_920_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_921_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_925_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_926_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Medical practice management data
    //
    // German: Praxisverwaltungsdaten
    // 12xx 13xx 14xx 15xx 16xx 17xx 18xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1201_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1202_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1211_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1212_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1213_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1214_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1215_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1216_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1217_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1219_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1220_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1225_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1226_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1250_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1251_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1252_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1260_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1265_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1270_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1271_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1272_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1273_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1274_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1275_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1276_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1277_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1290_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1291_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1296_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1297_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1298_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1299_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }  
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1302_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1303_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1304_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1305_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1311_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1312_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1315_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1320_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1330_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1331_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1402_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1500_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1502_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1503_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1601_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1700_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1701_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1702_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1703_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1802_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Miscellaneous
    //
    // German: Verschiedenes
    // 20xx 25xx 2700 27xx (außer 2700) 28xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2002_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2019_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2099_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2802_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_2803_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Patient
    //
    // German: Patient
    // 3000 30xx 31xx 32xx 3300 33xx (außer 3300) 34xx 35xx 36xx 37xx 38xx 39xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3050_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3100_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3101_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3102_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3103_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3104_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3105_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3106_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3107_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3108_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3109_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3110_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3111_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3112_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3113_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3114_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3116_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3119_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3120_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3121_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3122_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3123_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3201_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3202_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3203_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3205_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3209_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3302_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3303_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3304_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3311_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3399_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3401_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3402_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3411_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3421_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3422_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3423_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3424_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            copy_integer(p0, (void*) DDMMYYYYDDMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3425_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3426_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3427_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3428_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3429_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3430_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3431_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3432_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3433_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3434_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3435_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3437_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3441_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3452_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3453_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3454_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3455_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3461_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3462_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3463_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3464_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3465_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3466_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3471_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3472_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3481_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3482_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3483_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3484_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3501_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3502_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3503_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3504_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            copy_integer(p0, (void*) DDMMYYYYDDMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3505_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3506_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3507_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3508_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3509_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3510_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3511_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3515_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3527_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3528_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3529_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3530_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3531_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3532_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3533_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3541_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3542_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3561_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3562_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3563_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3581_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3582_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3591_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3592_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3593_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3601_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3602_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3603_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3610_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3612_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3618_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3619_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3620_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3622_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3623_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3625_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3626_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3627_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3628_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3629_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3630_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3631_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3632_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3633_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3637_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3639_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3640_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3648_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3649_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3651_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3654_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3656_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3657_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3658_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3659_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3660_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3662_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3663_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3664_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3666_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3668_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3672_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3685_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
  
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3686_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3687_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            copy_integer(p0, (void*) HHMM_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3688_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3689_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3700_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3701_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_3917_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Visit
    //
    // German: Behandlungsfall
    // 41xx 42xx 45xx 46xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4102_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4103_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4104_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4106_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4109_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4110_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4111_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4112_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4113_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4121_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4122_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4202_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4203_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4204_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4205_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4208_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4209_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4217_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4219_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4220_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4221_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4229_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4231_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4237_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4239_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4240_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4241_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_4242_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Service
    //
    // German: Leistungsfeld
    // 5xxx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5009_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5015_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5098_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5099_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Medical documentation
    //
    // German: Medizinische Dokumentation
    // 600x 62xx 63xx 64xx 65xx 66xx 67xx 68xx 69xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6003_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6004_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6006_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6007_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6008_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6011_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6208_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6209_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6212_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6213_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6216_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6217_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6219_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6221_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6230_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6260_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6280_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6285_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            copy_integer(p0, (void*) DDMMYYYYDDMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6286_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6302_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6308_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6305_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6320_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6325_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6326_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6327_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6329_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6691_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6692_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6693_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6694_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_6801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    //
    // Special documentation
    //
    // German: Besondere Dokumentationsform
    // 70xx - 71xx 72xx 77xx - 79xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_7002_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_7228_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_7860_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_7861_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_7922_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Record description
    //
    // German: Satzbeschreibung
    // 80xx 8000 8100 8110 8111
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8010_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8011_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8013_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8100_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // ???
    //
    // ???
    // 82xx
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8202_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }

    //
    // Laboratory data
    //
    // German: Labordaten
    // 83xx 84xx 85xx 86xx 87xx 88xx 89xx (außer 8990)
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8315_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8316_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8401_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8402_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8410_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8411_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8412_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8413_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8416_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8418_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8420_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8421_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8422_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8428_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8429_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8430_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8431_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8432_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8437_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8438_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8439_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8440_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8441_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8442_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8443_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8444_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8445_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8446_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8447_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8448_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8449_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8450_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8460_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8461_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8462_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8470_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8480_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8485_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8486_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8487_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8490_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8510_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8520_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8521_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Signature
    //
    // German: Befundfreigabe/Signatur
    // 8990
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_8990_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Identification
    //
    // German: KVDT/BDT-Identifikationsfelder
    // 91xx 92xx 96xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9104_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9106_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9217_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9602_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9603_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            copy_integer(p0, (void*) DDMMYYYYDDMMYYYY_DURATION_DATETIME_STATE_CYBOI_FORMAT);
        }
    }
    
    //
    // Internal identification
    //
    // German: BDT-interne Identifikatoren (iden)
    // 98xx
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9810_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }

    //
    // File reference
    //
    // German: Referenzierte Dateien (spec)
    // 99xx
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9900_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9902_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9903_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9904_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9905_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9906_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9907_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9908_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9909_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9910_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9970_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9971_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9980_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_9981_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        }
    }

    //
    // Unknown field identification
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field format. The field identification is unknown.");

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Could not deserialise xdt field format. The field identification is unknown: %i\n", *((int*) p1));

        } else {

            fwprintf(stdout, L"Could not deserialise xdt field format. The field identification is null.\n");
        }
    }
}

/* FORMAT_FIELD_XDT_DESERIALISER_SOURCE */
#endif
