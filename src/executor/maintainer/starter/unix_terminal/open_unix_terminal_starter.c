/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OPEN_UNIX_TERMINAL_STARTER_SOURCE
#define OPEN_UNIX_TERMINAL_STARTER_SOURCE

//?? #include <stdio.h>
#include <termios.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/maintainer/starter/unix_terminal/edit_attributes_unix_terminal_starter.c"
#include "../../../../executor/maintainer/starter/unix_terminal/get_attributes_unix_terminal_starter.c"
#include "../../../../executor/maintainer/starter/unix_terminal/set_attributes_unix_terminal_starter.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/terminal_type_size.c"

/**
 * Opens the unix terminal.
 *
 * @param p0 the file descriptor
 * @param p1 the input/output entry
 */
void startup_unix_terminal_open(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix terminal open.");

        // The input- and output file stream.
//??        FILE* s = stdin; //?? TODO: OPTIONAL: stdout
        // Get file descriptor as integer from file stream.
//??        *f = fileno(s);

        //
        // Allocate original attributes.
        //
        // The structure of type "struct termios" stores the
        // ENTIRE collection of attributes of a terminal / serial port.
        // It is used with the functions "tcgetattr" and
        // "tcsetattr" to get and set the attributes.
        //
        // CAUTION! When setting serial port modes, one should call "tcgetattr" first
        // to get the current modes of the particular serial port device,
        // modify only those modes that you are really interested in,
        // and store the result with tcsetattr.
        //
        // It's a bad idea to simply initialize a "struct termios" structure
        // to a chosen set of attributes and pass it directly to "tcsetattr".
        // The programme may be run years from now, on systems that support
        // members not documented here. The way to avoid setting these members
        // to unreasonable values is to avoid changing them.
        //
        // What's more, different serial port devices may require
        // different mode settings in order to function properly.
        // So you should avoid blindly copying attributes
        // from one serial port device to another.
        //
        // When a member contains a collection of independent flags,
        // as the c_iflag, c_oflag and c_cflag members do,
        // even setting the entire member is a bad idea,
        // because particular operating systems have their own flags.
        // Instead, one should start with the current value of the member
        // and alter only those flags whose values matter in the programme,
        // leaving any other flags unchanged.
        //
        void* a = malloc(*TERMIOS_TERMINAL_TYPE_SIZE);

        //
        // Adapt terminal attributes.
        //
        // Although tcgetattr and tcsetattr specify the terminal device with a file descriptor,
        // the attributes are those of the terminal device itself and not of the file descriptor.
        // This means that the effects of changing terminal attributes are persistent;
        // if another process opens the terminal file later on, it will see the changed attributes
        // even though it doesn't have anything to do with the open file descriptor originally
        // specified in changing the attributes.
        //
        // Similarly, if a single process has multiple or duplicated file descriptors
        // for the same terminal device, changing the terminal attributes affects
        // input and output to all of these file descriptors.
        // This means, for example, that one can't open one file descriptor or stream
        // to read from a terminal in the normal line-buffered, echoed mode;
        // and simultaneously have another file descriptor for the same terminal
        // that one uses to read from it in single-character, non-echoed mode.
        // Instead, one has to explicitly switch the terminal back and forth between the two modes.
        //
        // Therefore, it does not matter whether the input- OR output
        // file descriptor is specified here. EITHER may be used.
        // The attribute changes affect the whole terminal,
        // that is input AND output.
        //

        // Read original terminal attributes.
        startup_unix_terminal_attributes_get(p0, a);

        // Store original terminal attributes in input/output memory.
        // CAUTION! Hand over pointer as REFERENCE here.
        copy_array_forward(p1, (void*) &a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Copy original to new terminal attributes.
        struct termios* o = (struct termios*) a;
        struct termios n = *o;

        // Edit new terminal attributes.
        startup_unix_terminal_attributes_edit((void*) &n);

        // Write new terminal attributes.
        startup_unix_terminal_attributes_set(p0, (void*) &n);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal open. The file descriptor is null.");
    }
}

/* OPEN_UNIX_TERMINAL_STARTER_SOURCE */
#endif
