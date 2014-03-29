/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE
#define TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/option/test_unit_option_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/test/unit_test_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Selects the command line test unit option.
 *
 * @param p0 the test unit
 * @param p1 the test unit name data
 * @param p2 the test unit name count
 */
void select_command_line_test_unit(void* p0, void* p1, void* p2) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Select command line log level.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ALL_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ALL_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ALL_UNIT_TEST_CYBOI_MODEL);
        }
    }

/*Applictaor test units*/
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_TEST_UNIT_OPTION_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_ACCESS_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_ACCESS_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_ACCESS_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_CALCULATE_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_CALCULATE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_CALCULATE_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_CAST_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_CAST_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_CAST_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_COMMAND_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_COMMAND_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_COMMAND_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_COMPARE_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_COMPARE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_COMPARE_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_FLOW_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_FLOW_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_FLOW_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_LIVE_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_LIVE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_LIVE_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_MAINTAIN_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_MAINTAIN_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_MAINTAIN_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_MANIPULATE_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_MANIPULATE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_MANIPULATE_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_MEMORISE_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_MEMORISE_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_MEMORISE_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_MODIFY_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_MODIFY_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_MODIFY_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_REPRESENT_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_REPRESENT_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_REPRESENT_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPLICATOR_RUN_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) APPLICATOR_RUN_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLICATOR_RUN_UNIT_TEST_CYBOI_MODEL);
        }
    }

/* End of applicator test units*/

/*Controller test units*/
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_CHECKER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_CHECKER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_CHECKER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_DEOPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_DEOPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_DEOPTIONALISER_UNIT_OPTION_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_GLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_GLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_GLOBALISER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_HANDLER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_HANDLER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_HANDLER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_MANAGER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_MANAGER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_MANAGER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_OPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_OPTIONALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_OPTIONALISER_UNIT_OPTION_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CONTROLLER_UNGLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) CONTROLLER_UNGLOBALISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CONTROLLER_UNGLOBALISER_UNIT_TEST_CYBOI_MODEL);
        }
    }
/*End of controller test units*/

/*Executer test units*/
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_ACCESSOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_ACCESSOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_CALCULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_CALCULATOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_CASTER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_CASTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_CASTER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_COMMANDER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_COMMANDER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_COMMUNICATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_COMMUNICATOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_COMPARATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_COMPARATOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_CONVERTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_CONVERTER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_LIFEGUARD_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_LIFEGUARD_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_LOGIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_LOGIFIER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_MAINTAINER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_MAINTAINER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_MANIPULATOR_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_MANIPULATOR_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_MEMORISER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_MEMORISER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_MODIFIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_MODIFIER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_REFERENCER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_REFERENCER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_REPRESENTER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_REPRESENTER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_RUNNER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_RUNNER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXECUTOR_SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) EXECUTOR_SEARCHER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXECUTOR_SEARCHER_UNIT_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Warning: Could not select command line test unit. The test unit name is unknown.\n");
    }
}

/* TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE */
#endif
