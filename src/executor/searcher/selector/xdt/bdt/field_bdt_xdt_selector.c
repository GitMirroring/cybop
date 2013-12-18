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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FIELD_BDT_XDT_SELECTOR_SOURCE
#define FIELD_BDT_XDT_SELECTOR_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/representer/deserialiser/xdt/bdt/compound_field_bdt_xdt_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Selects a compound xdt bdt field by filtering its name (number).
 * 
 * CAUTION! Other, non-compound fields are ignored here.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source record model (fields) data
 * @param p3 the source record model (fields) count
 * @param p4 the source record model (fields) index
 * @param p5 the source record name data
 * @param p6 the source record name count
 * @param p7 the source field part (pointer reference)
 * @param p8 the source field model data
 * @param p9 the source field model count
 * @param p10 the source field name data
 * @param p11 the source field name count
 * @param p12 the source field name as integer
 */
void select_xdt_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt field.");

    //
    // Only COMPOUND xdt fields need special treatment here, since they
    // represent new parent nodes to which child nodes will be added.
    //
    // Those xdt fields with primitive data type are NOT filtered here.
    // They may be processed uniformly by just adding the source part
    // to the destination in the last if-branch below, at the bottom.
    //

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

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9900_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    //
    // Record iden
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9806_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9802_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    //
    // Record 0010
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9806_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1297_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1298_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1299_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record adrs
    //
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1210_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_307_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1250_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1271_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1290_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1297_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1298_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1299_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                            
    //
    // Record term
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1301_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1303_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1305_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1330_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                            
    //
    // Record diag
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1400_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                
    //
    // Record grnk
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1500_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1502_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1503_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                       
    //
    // Record hapo
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1600_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                       
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                       
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_925_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                       
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_919_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                       
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6207_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                           
    //
    // Record bbst
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1702_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                              
    //
    // Record text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_1800_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    //
    // Record 6100
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9801_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                              
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3632_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3528_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                              
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3120_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                              
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3602_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                              
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3310_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                                                                                                  
    //
    // Record 6200
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_80_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6011_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3622_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3623_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6230_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_925_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_919_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_3637_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6325_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_9971_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_2803_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    //
    // Record 0101
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    //
    // Record 0102
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record 0103
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record 0104
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record 0109
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record sad1
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
            
    //
    // Record sad2
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_4218_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
        
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                    
    //
    // Record sad3
    //
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5000_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5001_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
                    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
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
    // Record 6310 (GDT)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6206_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) NUMBER_6226_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_bdt_field_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    //
    // Record Obj_Allergien
    //

    //
    // Record Obj_Anhang
    //

    //
    // Record Obj_Basisdiagnostik
    //

    //
    // Record Obj_Betriebsstätte
    //

    //
    // Record Obj_Diabetis
    //

    //
    // Record Obj_Diagnose
    //

    //
    // Record Obj_Epilipsie
    //

    //
    // Record Obj_Impfungen
    //

    //
    // Record Obj_Implantat
    //

    //
    // Record Obj_Laborergebnis
    //

    //
    // Record Obj_Medikationsplan
    //

    //
    // Record Obj_Mutterschaft
    //

    //
    // Record Obj_Patient
    //

    //
    // Record Obj_Röntgenpass
    //

    //
    // Record Obj_Standardadresse
    //

    //
    // Record Obj_Strahlenpass
    //
    
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The COMPOUND xdt fields have been filtered above.
        // All xdt fields with PRIMITIVE data type are processed
        // uniformly and just added to the destination here.

        // Append source field part to destination model item.
        // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
        // This is necessary in order to activate rubbish (garbage) collection.
        append_item_element(p0, p7, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* FIELD_BDT_XDT_SELECTOR_SOURCE */
#endif
