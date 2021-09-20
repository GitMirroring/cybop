/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TERMINAL_AWAKENER_SOURCE
#define TERMINAL_AWAKENER_SOURCE

#include <sys/ioctl.h> // ioctl
#include <errno.h> // errno

#include "../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Let the system send an input to itself over terminal.
 *
 * @param p0 the input/output entry
 */
void awake_terminal(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake terminal.");
    fwprintf(stdout, L"Debug: Awake terminal. p0: %i\n", p0);

    //
    // Initialise error number.
    //
    // It is a global variable/function and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the procedure that might cause an error.
    //
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Write (push back) character to terminal input buffer,
    // so that it can be detected by the sensing thread read function.
    //
    // The TIOCSTI command is known to at least Linux and BSD.
    // The characters handed over are limited to 4096 on Linux.
    //
    // Example:
    // char* text = "text";
    // ioctl(STDIN_FILENO, TIOCSTI, text);
    //
    // CAUTION! Calling the function "write" does NOT work here.
    // It writes the characters to the terminal screen,
    // no matter if sent to STDIN_FILENO or STDOUT_FILENO.
    // But it is NOT recognised by the sensing thread.
    //
    int r = ioctl(STDIN_FILENO, TIOCSTI, LINE_FEED_ASCII_CHARACTER_CODE_MODEL);

    //
    // The meaning of the returned value depends upon the command used.
    //
    // Linux:
    // - success: zero or non-negative value
    // - error: -1 and errno set appropriately
    // - special case: sometimes used as output parameter
    //
    if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake terminal. Success.");
        fwprintf(stdout, L"Debug: Awake terminal. Success. r: %i\n", r);

    } else {

        //
        // An error occured.
        //

        //
        // Generic Error Codes
        //
        // https://www.kernel.org/doc/html/v4.11/media/uapi/gen-errors.html
        //

        // In glibc, EAGAIN and EWOULDBLOCK are identical.
        if (errno == EAGAIN) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"The ioctl can't be handled because the device is in state where it can't perform it. This could happen for example in case where device is sleeping and ioctl is performed to query statistics. It is also returned when the ioctl would need to wait for an event, but the device was opened in non-blocking mode.");
            fwprintf(stdout, L"Error: Could not awake terminal. The ioctl can't be handled because the device is in state where it can't perform it. This could happen for example in case where device is sleeping and ioctl is performed to query statistics. It is also returned when the ioctl would need to wait for an event, but the device was opened in non-blocking mode. errno EBADF: %i\n", errno);

        } else if (errno == EBADF) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. The file descriptor is not a valid.");
            fwprintf(stdout, L"Error: Could not awake terminal. The file descriptor is not a valid. errno EBADF: %i\n", errno);

        } else if (errno == EBUSY) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. The ioctl can't be handled because the device is busy. This is typically return while device is streaming, and an ioctl tried to change something that would affect the stream, or would require the usage of a hardware resource that was already allocated. The ioctl must not be retried without performing another action to fix the problem first (typically: stop the stream before retrying).");
            fwprintf(stdout, L"Error: Could not awake terminal. Could not awake terminal. The ioctl can't be handled because the device is busy. This is typically return while device is streaming, and an ioctl tried to change something that would affect the stream, or would require the usage of a hardware resource that was already allocated. The ioctl must not be retried without performing another action to fix the problem first (typically: stop the stream before retrying). errno EBADF: %i\n", errno);

        } else if (errno == EFAULT) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. There was a failure while copying data from/to userspace, probably caused by an invalid pointer reference.");
            fwprintf(stdout, L"Error: Could not awake terminal. There was a failure while copying data from/to userspace, probably caused by an invalid pointer reference. errno EBADF: %i\n", errno);

        } else if (errno == EINVAL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. One or more of the ioctl parameters are invalid or out of the allowed range. This is a widely used error code. See the individual ioctl requests for specific causes.");
            fwprintf(stdout, L"Error: Could not awake terminal. One or more of the ioctl parameters are invalid or out of the allowed range. This is a widely used error code. See the individual ioctl requests for specific causes. errno EBADF: %i\n", errno);

        } else if (errno == ENODEV) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. Device not found or was removed.");
            fwprintf(stdout, L"Error: Could not awake terminal. Device not found or was removed. errno EBADF: %i\n", errno);

        } else if (errno == ENOMEM) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. There's not enough memory to handle the desired operation.");
            fwprintf(stdout, L"Error: Could not awake terminal. There's not enough memory to handle the desired operation. errno EBADF: %i\n", errno);

        } else if (errno == ENOTTY) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. The ioctl is not supported by the driver, actually meaning that the required functionality is not available, or the file descriptor is not for a media device.");
            fwprintf(stdout, L"Error: Could not awake terminal. The ioctl is not supported by the driver, actually meaning that the required functionality is not available, or the file descriptor is not for a media device. errno EBADF: %i\n", errno);

        } else if (errno == ENOSPC) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. On USB devices, the stream ioctl's can return this error, meaning that this request would overcommit the usb bandwidth reserved for periodic transfers (up to 80% of the USB bandwidth).");
            fwprintf(stdout, L"Error: Could not awake terminal. On USB devices, the stream ioctl's can return this error, meaning that this request would overcommit the usb bandwidth reserved for periodic transfers (up to 80% of the USB bandwidth). errno EBADF: %i\n", errno);

        } else if (errno == EPERM) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. Permission denied. Can be returned if the device needs write permission, or some special capabilities is needed (e.g. root).");
            fwprintf(stdout, L"Error: Could not awake terminal. Permission denied. Can be returned if the device needs write permission, or some special capabilities is needed (e.g. root). errno EBADF: %i\n", errno);

        } else if (errno == EIO) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. I/O error. Typically used when there are problems communicating with a hardware device. This could indicate broken or flaky hardware. It's a 'Something is wrong, I give up!' type of error.");
            fwprintf(stdout, L"Error: Could not awake terminal. I/O error. Typically used when there are problems communicating with a hardware device. This could indicate broken or flaky hardware. It's a 'Something is wrong, I give up!' type of error. errno EBADF: %i\n", errno);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake terminal. An unknown error occured.");
            fwprintf(stdout, L"Error: Could not awake terminal. An unknown error occured. errno: %i\n", errno);
        }
    }
}

/* TERMINAL_AWAKENER_SOURCE */
#endif
