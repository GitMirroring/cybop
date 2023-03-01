/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LINUX_ERRNO_TO_MESSAGE_MAPPER_SOURCE
#define LINUX_ERRNO_TO_MESSAGE_MAPPER_SOURCE

#include <errno.h> // ERESTART, ECHRNG etc.

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/linux_error_message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../executor/copier/pointer_copier.c"
// CAUTION! Do NOT include this file due to circular dependencies.
// #include "../logger/logger.c"

//
// Forward declarations
//

void log_message_terminated(void* p0, void* p1);

/**
 * Maps the linux errno value to an error message.
 *
 * @param p0 the error message (pointer reference)
 * @param p1 the errno value
 */
void map_errno_to_message_linux(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* e = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map errno to message linux.");

        //
        // CAUTION! The following error codes are defined by the Linux/i386 kernel.
        // They were copied from the glibc manual, which states that they are not yet documented.
        //

        //
        // CAUTION! Some error codes have got commented out,
        // since they were not known to the compiler.
        //

        if (*e == ERESTART) {

            copy_pointer(p0, (void*) &ERESTART_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECHRNG) {

            copy_pointer(p0, (void*) &ECHRNG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EL2NSYNC) {

            copy_pointer(p0, (void*) &EL2NSYNC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EL3HLT) {

            copy_pointer(p0, (void*) &EL3HLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EL3RST) {

            copy_pointer(p0, (void*) &EL3RST_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELNRNG) {

            copy_pointer(p0, (void*) &ELNRNG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EUNATCH) {

            copy_pointer(p0, (void*) &EUNATCH_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOCSI) {

            copy_pointer(p0, (void*) &ENOCSI_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EL2HLT) {

            copy_pointer(p0, (void*) &EL2HLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADE) {

            copy_pointer(p0, (void*) &EBADE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADR) {

            copy_pointer(p0, (void*) &EBADR_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EXFULL) {

            copy_pointer(p0, (void*) &EXFULL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOANO) {

            copy_pointer(p0, (void*) &ENOANO_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADRQC) {

            copy_pointer(p0, (void*) &EBADRQC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADSLT) {

            copy_pointer(p0, (void*) &EBADSLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EDEADLOCK) {

            copy_pointer(p0, (void*) &EDEADLOCK_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBFONT) {

            copy_pointer(p0, (void*) &EBFONT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENONET) {

            copy_pointer(p0, (void*) &ENONET_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOPKG) {

            copy_pointer(p0, (void*) &ENOPKG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EADV) {

            copy_pointer(p0, (void*) &EADV_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESRMNT) {

            copy_pointer(p0, (void*) &ESRMNT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECOMM) {

            copy_pointer(p0, (void*) &ECOMM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EDOTDOT) {

            copy_pointer(p0, (void*) &EDOTDOT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTUNIQ) {

            copy_pointer(p0, (void*) &ENOTUNIQ_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADFD) {

            copy_pointer(p0, (void*) &EBADFD_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EREMCHG) {

            copy_pointer(p0, (void*) &EREMCHG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELIBACC) {

            copy_pointer(p0, (void*) &ELIBACC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELIBBAD) {

            copy_pointer(p0, (void*) &ELIBBAD_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELIBSCN) {

            copy_pointer(p0, (void*) &ELIBSCN_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELIBMAX) {

            copy_pointer(p0, (void*) &ELIBMAX_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELIBEXEC) {

            copy_pointer(p0, (void*) &ELIBEXEC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESTRPIPE) {

            copy_pointer(p0, (void*) &ESTRPIPE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EUCLEAN) {

            copy_pointer(p0, (void*) &EUCLEAN_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTNAM) {

            copy_pointer(p0, (void*) &ENOTNAM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENAVAIL) {

            copy_pointer(p0, (void*) &ENAVAIL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EISNAM) {

            copy_pointer(p0, (void*) &EISNAM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EREMOTEIO) {

            copy_pointer(p0, (void*) &EREMOTEIO_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOMEDIUM) {

            copy_pointer(p0, (void*) &ENOMEDIUM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EMEDIUMTYPE) {

            copy_pointer(p0, (void*) &EMEDIUMTYPE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOKEY) {

            copy_pointer(p0, (void*) &ENOKEY_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EKEYEXPIRED) {

            copy_pointer(p0, (void*) &EKEYEXPIRED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EKEYREVOKED) {

            copy_pointer(p0, (void*) &EKEYREVOKED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EKEYREJECTED) {

            copy_pointer(p0, (void*) &EKEYREJECTED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ERFKILL) {

            copy_pointer(p0, (void*) &ERFKILL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EHWPOISON) {

            copy_pointer(p0, (void*) &EHWPOISON_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map errno to message linux. The errno value is unknown.");
            fwprintf(stdout, L"Warning: Could not map errno to message linux. The errno value is unknown. p1: %i\n", p1);
            fwprintf(stdout, L"Warning: Could not map errno to message linux. The errno value is unknown. *p1: %i\n", *((int*) p1));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map errno to message linux. The errno value is null.");
        fwprintf(stdout, L"Error: Could not map errno to message linux. The errno value is null. p1: %i\n", p1);
    }
}

/* LINUX_ERRNO_TO_MESSAGE_MAPPER_SOURCE */
#endif
