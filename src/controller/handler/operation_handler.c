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

#include "../../constant/model/cybol/operation_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../controller/handler/operation/arithmetic_operation_handler.c"
#include "../../controller/handler/operation/communication_operation_handler.c"
#include "../../controller/handler/operation/comparison_operation_handler.c"
#include "../../controller/handler/operation/file_operation_handler.c"
#include "../../controller/handler/operation/flow_operation_handler.c"
#include "../../controller/handler/operation/lifecycle_operation_handler.c"
#include "../../controller/handler/operation/memory_operation_handler.c"
#include "../../controller/handler/operation/run_operation_handler.c"
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

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL_COUNT);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, p0);
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n");

fwprintf(stdout, L"TEST handle operation: %i\n", *((int*) pp));

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    //
    // Calculate.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ADD_ARITHMETIC_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_addition(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_division(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_multiplication(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_subtraction(p3, p4, p5);
        }
    }

    //
    // Communicate.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            communicate_receiving(p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            communicate_sending(p3, p4, p5, p6, p7, p8, p9);
        }
    }

    //
    // Compare.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) EQUAL_COMPARISON_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_equality(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GREATER_COMPARISON_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_greaterness(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GREATER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_greaterness_or_equality(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SMALLER_COMPARISON_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_smallerness(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SMALLER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_smallerness_or_equality(p3, p4, p5);
        }
    }

    //
    // File.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) ARCHIVE_FILE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            file_archiving(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) COPY_FILE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            file_copying(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            file_directory_contents_listing(p3, p4, p5);
        }
    }

    //
    // Flow.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) BRANCH_FLOW_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            guide_branch(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) LOOP_FLOW_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            guide_loop(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SEQUENCE_FLOW_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            guide_sequence(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    //
    // Live.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            communicate_sensing(p3, p4, p5, p6);
        }
    }

    //
    // Maintain.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL_COUNT);

            copy_integer(p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) INTERRUPT_LIFECYCLE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            maintain_interrupting(p3, p4, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            maintain_shutting(p3, p4, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            maintain_starting(p3, p4, p6, p7);
        }
    }

    //
    // Memorise.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_building(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) COPY_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_copying(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) COUNT_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_counting(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) CREATE_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_creating(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DESTROY_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_destructing(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) GET_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            memorise_getting(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) MOVE_MEMORY_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

//??            memorise_moving(p3, p4, p5);
        }
    }

    //
    // Run.
    //

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) PROGRAMME_RUN_OPERATION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            run_programme(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, "Could not handle operation. The operation is unknown.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
