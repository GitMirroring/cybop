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

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../../applicator/access/count.c"
#include "../../applicator/access/get.c"
#include "../../applicator/access/indicate.c"
#include "../../applicator/calculate/calculate.c"
#include "../../applicator/cast/cast.c"
#include "../../applicator/communicate/receive.c"
#include "../../applicator/communicate/send.c"
#include "../../applicator/compare/compare.c"
#include "../../applicator/file/archive_file.c"
#include "../../applicator/file/copy_file.c"
#include "../../applicator/file/list_directory_contents.c"
#include "../../applicator/flow/branch.c"
#include "../../applicator/flow/loop.c"
#include "../../applicator/flow/sequence.c"
#include "../../applicator/live/interrupt.c"
#include "../../applicator/live/sense.c"
#include "../../applicator/maintain/shutdown.c"
#include "../../applicator/maintain/startup.c"
//?? #include "../../applicator/manipulate/??.c"
#include "../../applicator/memorise/create.c"
#include "../../applicator/memorise/destroy.c"
#include "../../applicator/modify/append.c"
#include "../../applicator/modify/build.c"
#include "../../applicator/modify/empty.c"
#include "../../applicator/modify/fill.c"
#include "../../applicator/modify/insert.c"
#include "../../applicator/modify/overwrite.c"
#include "../../applicator/modify/remove.c"
#include "../../applicator/represent/deserialise.c"
#include "../../applicator/represent/serialise.c"
#include "../../applicator/run/run.c"
#include "../../applicator/run/sleep.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../logger/logger.c"

/**
 * Handles the operation.
 *
 * @param p0 the properties parametres data
 * @param p1 the properties parametres count
 * @param p2 the internal memory data
 * @param p3 the knowledge memory part
 * @param p4 the signal memory item
 * @param p5 the shutdown flag
 * @param p6 the operation format
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT);

//fwprintf(stdout, L"TEST handle operation: %i\n", p6);
//fwprintf(stdout, L"TEST handle operation: %i\n", *((int*) p6));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // access
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) COUNT_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_count(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_get(p0, p1, p3, (void*) NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_indicate(p0, p1, p3, (void*) EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_indicate(p0, p1, p3, (void*) EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) MODULO_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) MODULO_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p3, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // cast
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) CHARACTER_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, (void*) CHARACTER_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DOUBLE_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, (void*) DOUBLE_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) INTEGER_CAST_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_cast(p0, p1, p3, (void*) INTEGER_CAST_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_receive(p0, p1, p3, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SEND_COMMUNICATE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_send(p0, p1, p3, p2);
        }
    }

    //
    // compare
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SMALLER_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) SMALLER_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p3, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

/*??
    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DECODE_CONVERT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) ENCODE_CONVERT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode(p0, p1);
        }
    }
*/

    //
    // file
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) ARCHIVE_FILE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_archive_file(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) COPY_FILE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_copy_file(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_list_directory_contents(p0, p1, p3);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) BRANCH_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_branch(p0, p1, p3, p2, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) LOOP_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_loop(p0, p1, p3, p2, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SEQUENCE_FLOW_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sequence(p0, p1, p3, p2, p4, p5);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) EXIT_LIVE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) INTERRUPT_LIVE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_interrupt(p0, p1, p3, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SENSE_LIVE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sense(p0, p1, p3, p2);
        }
    }

/*??
    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) AND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            and(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NAND_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            nand(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            nor(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NOT_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            not(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) OR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            or(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) XNOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            xnor(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) XOR_LOGIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            xor(p0, p1);
        }
    }
*/

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_shutdown(p0, p1, p3, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) STARTUP_MAINTAIN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_startup(p0, p1, p3, p2);
        }
    }

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) CREATE_MEMORISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_create(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DESTROY_MEMORISE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_destroy(p0, p1, p3);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_append(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) BUILD_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_build(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_empty(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_fill(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_insert(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_overwrite(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_remove(p0, p1, p3);
        }
    }

    //
    // represent
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DESERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_deserialise(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_serialise(p0, p1, p3, p2);
        }
    }

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_run(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sleep(p0, p1, p3, (void*) NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sleep(p0, p1, p3, (void*) SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // unknown
    //
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // fwprintf(stdout, L"ERROR: Could not handle operation. The operation is unknown p6: %i\n", p6);
        fwprintf(stdout, L"ERROR: Could not handle operation. The operation is unknown *p6: %i\n", *((int*) p6));

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, "Could not handle operation. The operation is unknown.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
