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

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/option/log_level_option_cyboi_model.c"
#include "../constant/model/cyboi/operation_mode_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/name/cyboi/option_cyboi_name.c"
#include "../constant/type/cyboi/logic_cyboi_type.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/comparator/all/array_all_comparator.c"
#include "../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../executor/modifier/copier/integer_copier.c"
#include "../executor/modifier/overwriter/array_overwriter.c"
#include "../executor/modifier/overwriter/item_overwriter.c"

/**
 * Optionalises the log level option.
 *
 * @param p0 the log level
 * @param p1 the log level name
 * @param p2 the log level name count
 */
void optionalise_log_level(void* p0, void* p1, void* p2) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Optionalise log level.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OFF_LOG_LEVEL_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) OFF_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) OFF_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ERROR_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WARNING_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DEBUG_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Warning: Could not optionalise log level. The log level name is unknown.\n");
    }
}

/**
 * Optionalises the log file option.
 *
 * @param p0 the log file (pointer reference)
 * @param p1 the log file name
 * @param p2 the log file name count
 */
void optionalise_log_file(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE** f = (FILE**) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write((void*) stdout, L"Debug: Optionalise log file.\n");

        // The terminated file name item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The terminated file name item data, count.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate terminated file name item.
        // CAUTION! Do NOT use a wide character array here!
        // The glibc file stream functions below expect standard (multibyte) character arrays.
        allocate_item((void*) &t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Get terminated file name item data, count.
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Encode wide character option into multibyte character array.
        encode_utf_8(t, p1, p2);

        // Add null termination character to terminated file name.
        append_item_element(t, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Open log file for writing only.
        // If the file already exists, it is truncated to zero length.
        // Otherwise a new file is created.
        //
        // FILE objects are allocated and managed internally by the input/ output
        // library functions. The library creates objects of type FILE.
        // Programs should deal only with pointers to these objects (FILE* values),
        // rather than the objects themselves.
        *f = fopen((char*) td, "w");

        if (*f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The file owner.
            int o = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The file group.
            int g = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

            // Set file owner.
            chown((char*) td, o, g);

            // The file access rights.
            //?? TODO: When trying to cross-compile cyboi for windows,
            //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
            int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

            // Set file access rights.
            chmod((char*) td, r);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            log_write((void*) stdout, L"Error: Could not optionalise log file. An error occured when trying to open or create the file for writing.\n");
        }

        // Deallocate terminated file name item.
        deallocate_item((void*) &t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Error: Could not optionalise log file. The file descriptor is null.\n");
    }
}

/**
 * Deoptionalises the log file option.
 *
 * @param p0 the log file stream (pointer reference)
 */
void deoptionalise_log_file(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE** f = (FILE**) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write((void*) stdout, L"Debug: Deoptionalise log file.\n");

        // CAUTION! This test is necessary! Do NOT delete it!
        // Checking the file stream argument above is not sufficient,
        // since a segmentation fault will occur here,
        // if no log file is given as command line argument at system startup.
        if (*f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Close log file.
            fclose(*f);

            // Reset log file pointer.
            // CAUTION! Hand over the log file stream AS REFERENCE!
            // This is necessary, because it is reset to null here.
            // If this was not done, subsequent logger calls would cause segmentation faults,
            // because the null pointer test within the logger would be successful,
            // even though the LOG_OUTPUT pointer would be invalid.
            *f = *NULL_POINTER_STATE_CYBOI_MODEL;

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Do NOT show the following message, as it would only disturb the user!
            // log_write((void*) stdout, L"Warning: Could not deoptionalise log file. No log file was given at system startup.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Do NOT show the following message, as it would only disturb the user!
        log_write((void*) stdout, L"Error: Could not deoptionalise log file. The file descriptor is null.\n");
    }
}

/**
 * Optionalises the given command line argument option.
 *
 * This function finds out whether an option is actually a value
 * or vice versa, by just comparing with known cyboi options.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the value
 * @param p5 the value count
 * @param p6 the option
 * @param p7 the option count
 */
void optionalise_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Optionalise option.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) HELP_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) HELP_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set help operation mode.
            copy_integer(p0, (void*) HELP_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) KNOWLEDGE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) KNOWLEDGE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy file path from value to cybol knowledge file path.
            overwrite_item_element(p1, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Set knowledge operation mode.
            copy_integer(p0, (void*) KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_FILE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) LOG_FILE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set log file to store log messages in.
            optionalise_log_file(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_LEVEL_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) LOG_LEVEL_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set log level, which is a global variable.
            optionalise_log_level(p2, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) TEST_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) TEST_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set test operation mode.
            copy_integer(p0, (void*) TEST_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) VERSION_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) VERSION_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set version operation mode.
            copy_integer(p0, (void*) VERSION_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! This function call HAS TO BE COMMENTED OUT,
        // in order to avoid disturbing messages at system startup!
        // The last option argument read from command line is
        // always null, so that this warning would ALWAYS appear.
        // log_write((void*) stdout, L"Warning: Could not optionalise option. The command line option is unknown.\n");
    }
}

/**
 * Optionalises the command line argument.
 *
 * It is assumed that the argument is an option followed by a value.
 * Both are determined here and evaluated later in function "optionalise_option".
 *
 * Example:
 * --loglevel debug
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the arguments (pointer reference)
 * @param p5 the arguments count
 * @param p6 the index
 */
void optionalise_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Information: Optionalise command line argument.\n");

    // The value index, which is equal to the loop variable increased by one.
    // CAUTION! Do NOT misuse the index parametre *j handed over to this function!
    // The parametre j is the loop index and MUST NOT be altered here!
    // Therefore, a new local variable i is introduced.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The command line argument option as multibyte character array.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The command line argument value as multibyte character array.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The option, value as wide character item.
    void* ow = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vw = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The option, value as wide character item data, count.
    void* owd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* owc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vwd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* vwc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate option, value wide character item.
    allocate_item((void*) &ow, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &vw, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get option, value wide character item data, count.
    copy_array_forward((void*) &owd, ow, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &owc, ow, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &vwd, vw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &vwc, vw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Get command line argument option.
    // Example: "--loglevel"
    copy_array_forward((void*) &o, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    if (o != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Get command line argument option count (number of characters).
        //
        // CAUTION! There are two possibilities to determine it:
        //
        // 1 Force the user to give it as extra command line parametre
        //   (this would be proper, but not very user-friendly)
        //
        // 2 Rely on the null termination character to determine it
        //   (this is a rather dirty workaround, but the "strlen" function can be used)
        //
        // Possibility 2 is applied here.
        //
        oc = strlen((char*) o);

        // Decode multibyte command line argument option into wide character.
        decode_utf_8(ow, o, (void*) &oc);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument option is null.\n");
    }

    // Calculate value index, which is equal to the loop index increased by one.
    copy_integer((void*) &i, p6);
    calculate_integer_add((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // CAUTION! It was already tested through the loop break flag that
    // the index handed over as parametre to here lies within the array.
    // However, the value belonging to an option has an index which is
    // INCREASED BY ONE, so that it might lie OUTSIDE the argument array.
    // Therefore, that incremented index is tested here again,
    // in order to avoid an access violation error!
    compare_integer_smaller((void*) &r, (void*) &i, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Get command line argument value, standing after the option.
        // Example: "debug"
        copy_array_forward((void*) &v, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (v != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get command line argument value count (number of characters).
            //
            // There are two possibilities to determine it:
            // 1 Force the user to give it as extra command line parametre
            //   (this would be proper, but not very user-friendly)
            // 2 Rely on the null termination character to determine it
            //   (this is a rather dirty workaround, but the strlen function can be used)
            //
            // Possibility 2 is applied here.
            vc = strlen((char*) v);

            // Decode multibyte command line argument value into wide character.
            decode_utf_8(vw, v, (void*) &vc);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            log_write((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument value is null.\n");
        }
    }

    // Optionalise the option and its value.
    // CAUTION! The value gets handed over as reference, as it gets
    // copied for the cybol knowledge file name.
    optionalise_option(p0, p1, p2, p3, vwd, vwc, owd, owc);

    // Deallocate option, value wide character item.
    deallocate_item((void*) &ow, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &vw, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Optionalises the given command line argument options.
 *
 * The GNU Standards for Command Line Interfaces to be found at:
 * http://www.gnu.org/prep/standards/html_node/Command_002dLine-Interfaces.html
 * write:
 * "All programs should support two standard options: '--version' and '--help'."
 * Therefore, this function checks for these two command line argument options.
 *
 * A further option that was added is '--test'. It is just to ease cyboi
 * development because that way, programmers can easily call test functions.
 *
 * The standard option used to run cybol applications is '--knowledge'.
 * Behind it, the cybol file name needs to be given as argument.
 * The cyboi interpreter then starts up the system.
 *
 * Optionally, a '--loglevel' and 'logfile' may be given, each followed by a value.
 * In the case of the loglevel, the value may be one of:
 * - off
 * - error
 * - warning
 * - information
 * - debug
 * where 'debug' is the most verbose one.
 * The logfile expects just an arbitrary file name.
 *
 * If none of these options can be found, cyboi displays the help message.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the arguments (pointer reference)
 * @param p5 the arguments count
 */
void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Information: Optionalise command line arguments.\n");

    // The loop variable.
    //
    // CAUTION! Do NOT initialise it with 0, as the first command line
    // argument is the command itself, and not an option!
    int j = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p5);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        optionalise_argument(p0, p1, p2, p3, p4, p5, (void*) &j);

        // Increment loop variable.
        j++;
    }
}

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the log file stream
 */
void deoptionalise(void* p0) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Do NOT show the following message, as it would only disturb the user!
    // log_write((void*) stdout, L"Information: Deoptionalise command line argument options.\n");

    // Deoptionalise log file.
    deoptionalise_log_file(p0);
}

/* OPTIONALISER_SOURCE */
#endif
