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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_STARTER_SOURCE
#define SERIAL_PORT_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/maintainer/starter/serial_port/get_attributes_serial_port_starter.c"
#include "../../../logger/logger.c"

/**
 * Starts up the serial port.
 *
 * @param p0 the internal memory data
 * @param p1 the filename
 */
void startup_serial_port(void* p0, void* p1) {

    // The serial port file descriptor.
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get serial port file descriptor.
    copy_array_forward((void*) &sp, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create new serial port resources if none exist.
    if (spi == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port.");

        // Allocate serial port file descriptor.
        allocate_array((void*) &sp, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (sp != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* spi = (int*) sp;

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling the procedure
            // that might cause an error.
            copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            // Create file descriptor for the given filename.
            *spi = open((char*) p1, O_RDWR | O_NOCTTY | O_NDELAY);

            // The normal return value from "open" is a
            // non-negative integer file descriptor.
            // In the case of an error, a value of
            // minus one is returned instead.
            if (*spi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                startup_serial_port_attributes_get(p0, sp);

                // Set serial port file descriptor.
                copy_array_forward(p0, (void*) &sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FILE_DESCRIPTOR_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            } else {

                //
                // File name errors.
                //

                if (errno == EACCES) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The process does not have search permission for a directory component of the file name.");

                } else if (errno == ENAMETOOLONG) {

                    // In the GNU system, there is no imposed limit
                    // on overall file name length, but some file systems
                    // may place limits on the length of a component.
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");

                } else if (errno == ENOENT) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. This error is reported when a file referenced as a directory component in the file name doesn't exist, or when a component is a symbolic link whose target file does not exist.");

                } else if (errno == ENOTDIR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. A file that is referenced as a directory component in the file name exists, but it isn't a directory.");

                } else if (errno == ELOOP) {

                    // The system has an arbitrary limit on the number
                    // of symbolic links that may be resolved in looking up
                    // a single file name, as a primitive way to detect loops.
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. Too many symbolic links were resolved while trying to look up the file name.");

                //
                // Opening errors.
                //

                } else if (errno == EACCES) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The file exists but is not readable/writable as requested by the flags argument or the file does not exist and the directory is unwritable so it cannot be created.");

                } else if (errno == EEXIST) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. Both O_CREAT and O_EXCL are set, and the named file already exists.");

                } else if (errno == EINTR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The open operation was interrupted by a signal.");

                } else if (errno == EISDIR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The flags argument specified write access, and the file is a directory.");

                } else if (errno == EMFILE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The process has too many files open.");

                } else if (errno == ENFILE) {

                    // This problem cannot happen on the GNU system.
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The entire system, or perhaps the file system which contains the directory, cannot support any additional open files at the moment.");

                } else if (errno == ENOENT) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The named file does not exist, and O_CREAT is not specified.");

                } else if (errno == ENOSPC) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The directory or file system that would contain the new file cannot be extended, because there is no disk space left.");

                } else if (errno == ENXIO) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The flags O_NONBLOCK and O_WRONLY are both set in the argument, the file named by filename is a FIFO, and no process has the file open for reading.");

                } else if (errno == EROFS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The file resides on a read-only file system and any of O_WRONLY, O_RDWR, and O_TRUNC are set in the flags argument, or O_CREAT is set and the file does not already exist.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The serial port file descriptor is null.");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. A serial port file descriptor already exists.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SERIAL_PORT_STARTER_SOURCE */
#endif
