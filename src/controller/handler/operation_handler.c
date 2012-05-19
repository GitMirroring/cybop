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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../../applicator/compare/compare.c"
#include "../../applicator/calculate/calculate.c"
#include "../../applicator/communicate/receive.c"
#include "../../applicator/communicate/send.c"
#include "../../applicator/file/archive_file.c"
#include "../../applicator/file/copy_file.c"
#include "../../applicator/file/list_directory_contents.c"
#include "../../applicator/flow/branch.c"
#include "../../applicator/flow/loop.c"
#include "../../applicator/flow/sequence.c"
#include "../../applicator/memorise/create.c"
#include "../../applicator/memorise/destroy.c"
#include "../../applicator/modify/append.c"
#include "../../applicator/modify/overwrite.c"
#include "../../applicator/run/run.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Handles the operation.
 *
 * @param p0 the properties parametres data
 * @param p1 the properties parametres count
 * @param p2 the direct execution flag
 * @param p3 the shutdown flag
 * @param p4 the knowledge memory part
 * @param p5 the internal memory array
 * @param p6 the signal memory item
 * @param p7 the signal memory interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the operation type
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_CYBOI_MODEL_COUNT);

//?? fwprintf(stdout, L"TEST handle operation: %i\n", p9);
//?? fwprintf(stdout, L"TEST handle operation: %i\n", *((int*) p9));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ADD_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) ADD_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_calculate(p0, p1, p4, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_receive(p0, p1, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SEND_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_send(p0, p1, p4, p5);
        }
    }

    //
    // compare
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GREATER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) GREATER_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SMALLER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) SMALLER_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_compare(p0, p1, p4, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_TYPE);
        }
    }

/*??
    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DECODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ENCODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise(p0, p1);
        }
    }
*/

    //
    // file
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ARCHIVE_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_archive_file(p0, p1, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) COPY_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_copy_file(p0, p1, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_list_directory_contents(p0, p1, p4);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) BRANCH_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_branch(p0, p1, p4, p5, p6, p7, p8, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) LOOP_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_loop(p0, p1, p4, p5, p6, p7, p8, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SEQUENCE_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_sequence(p0, p1, p4, p5, p6, p7, p8, p3);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) EXIT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) INTERRUPT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            interrupt(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SENSE_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            sense(p0, p1);
        }
    }

    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) AND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            and(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) NAND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            nand(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) NOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            nor(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) NOT_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            not(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) OR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            or(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) XNOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            xnor(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) XOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            xor(p0, p1);
        }
    }

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) STARTUP_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup(p0, p1);
        }
    }
*/

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) CREATE_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_create(p0, p1, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DESTROY_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_destroy(p0, p1, p4);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) APPEND_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_append(p0, p1, p4);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) BUILD_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            build(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) COUNT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            count(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GET_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            get(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) INSERT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            insert(p0, p1);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_overwrite(p0, p1, p4);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) REMOVE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            remove(p0, p1);
        }
    }
*/

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) RUN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            apply_run(p0, p1, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

    fwprintf(stdout, L"ERROR: Could not handle operation. The operation is unknown p9: %i\n", p9);
    fwprintf(stdout, L"ERROR: Could not handle operation. The operation is unknown *p9: %i\n", *((int*) p9));

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, "Could not handle operation. The operation is unknown.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
