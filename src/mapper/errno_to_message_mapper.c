/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <errno.h> // EPERM, ENOENT etc.
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "mapper.h"

//
// Forward declaration
//

void log_message_terminated(void* p0, void* p1);

/**
 * Maps the errno value to an error message.
 *
 * @param p0 the error message (pointer reference)
 * @param p1 the errno value
 */
void map_errno_to_message(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* e = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map errno to message.");

        //
        // CAUTION! Some error codes have got commented out,
        // since they were not known to the compiler.
        //

        if (*e == EPERM) {

            copy_pointer(p0, (void*) &EPERM_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOENT) {

            copy_pointer(p0, (void*) &ENOENT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESRCH) {

            copy_pointer(p0, (void*) &ESRCH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EINTR) {

            copy_pointer(p0, (void*) &EINTR_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EIO) {

            copy_pointer(p0, (void*) &EIO_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENXIO) {

            copy_pointer(p0, (void*) &ENXIO_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == E2BIG) {

            copy_pointer(p0, (void*) &E2BIG_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOEXEC) {

            copy_pointer(p0, (void*) &ENOEXEC_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADF) {

            copy_pointer(p0, (void*) &EBADF_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECHILD) {

            copy_pointer(p0, (void*) &ECHILD_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EDEADLK) {

            copy_pointer(p0, (void*) &EDEADLK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOMEM) {

            copy_pointer(p0, (void*) &ENOMEM_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EACCES) {

            copy_pointer(p0, (void*) &EACCES_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EFAULT) {

            copy_pointer(p0, (void*) &EFAULT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTBLK) {

            copy_pointer(p0, (void*) &ENOTBLK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBUSY) {

            copy_pointer(p0, (void*) &EBUSY_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EEXIST) {

            copy_pointer(p0, (void*) &EEXIST_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EXDEV) {

            copy_pointer(p0, (void*) &EXDEV_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENODEV) {

            copy_pointer(p0, (void*) &ENODEV_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTDIR) {

            copy_pointer(p0, (void*) &ENOTDIR_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EISDIR) {

            copy_pointer(p0, (void*) &EISDIR_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EINVAL) {

            copy_pointer(p0, (void*) &EINVAL_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EMFILE) {

            copy_pointer(p0, (void*) &EMFILE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENFILE) {

            copy_pointer(p0, (void*) &ENFILE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTTY) {

            copy_pointer(p0, (void*) &ENOTTY_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ETXTBSY) {

            copy_pointer(p0, (void*) &ETXTBSY_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EFBIG) {

            copy_pointer(p0, (void*) &EFBIG_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOSPC) {

            copy_pointer(p0, (void*) &ENOSPC_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESPIPE) {

            copy_pointer(p0, (void*) &ESPIPE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EROFS) {

            copy_pointer(p0, (void*) &EROFS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EMLINK) {

            copy_pointer(p0, (void*) &EMLINK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EPIPE) {

            copy_pointer(p0, (void*) &EPIPE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EDOM) {

            copy_pointer(p0, (void*) &EDOM_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ERANGE) {

            copy_pointer(p0, (void*) &ERANGE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EAGAIN) {

            copy_pointer(p0, (void*) &EAGAIN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EWOULDBLOCK) {

            copy_pointer(p0, (void*) &EWOULDBLOCK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EINPROGRESS) {

            copy_pointer(p0, (void*) &EINPROGRESS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EALREADY) {

            copy_pointer(p0, (void*) &EALREADY_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTSOCK) {

            copy_pointer(p0, (void*) &ENOTSOCK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EMSGSIZE) {

            copy_pointer(p0, (void*) &EMSGSIZE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EPROTOTYPE) {

            copy_pointer(p0, (void*) &EPROTOTYPE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOPROTOOPT) {

            copy_pointer(p0, (void*) &ENOPROTOOPT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EPROTONOSUPPORT) {

            copy_pointer(p0, (void*) &EPROTONOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESOCKTNOSUPPORT) {

            copy_pointer(p0, (void*) &ESOCKTNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EOPNOTSUPP) {

            copy_pointer(p0, (void*) &EOPNOTSUPP_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EPFNOSUPPORT) {

            copy_pointer(p0, (void*) &EPFNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EAFNOSUPPORT) {

            copy_pointer(p0, (void*) &EAFNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EADDRINUSE) {

            copy_pointer(p0, (void*) &EADDRINUSE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EADDRNOTAVAIL) {

            copy_pointer(p0, (void*) &EADDRNOTAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENETDOWN) {

            copy_pointer(p0, (void*) &ENETDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENETUNREACH) {

            copy_pointer(p0, (void*) &ENETUNREACH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENETRESET) {

            copy_pointer(p0, (void*) &ENETRESET_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECONNABORTED) {

            copy_pointer(p0, (void*) &ECONNABORTED_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECONNRESET) {

            copy_pointer(p0, (void*) &ECONNRESET_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOBUFS) {

            copy_pointer(p0, (void*) &ENOBUFS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EISCONN) {

            copy_pointer(p0, (void*) &EISCONN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTCONN) {

            copy_pointer(p0, (void*) &ENOTCONN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EDESTADDRREQ) {

            copy_pointer(p0, (void*) &EDESTADDRREQ_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ESHUTDOWN) {

            copy_pointer(p0, (void*) &ESHUTDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ETOOMANYREFS) {

            copy_pointer(p0, (void*) &ETOOMANYREFS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ETIMEDOUT) {

            copy_pointer(p0, (void*) &ETIMEDOUT_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECONNREFUSED) {

            copy_pointer(p0, (void*) &ECONNREFUSED_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ELOOP) {

            copy_pointer(p0, (void*) &ELOOP_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENAMETOOLONG) {

            copy_pointer(p0, (void*) &ENAMETOOLONG_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EHOSTDOWN) {

            copy_pointer(p0, (void*) &EHOSTDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EHOSTUNREACH) {

            copy_pointer(p0, (void*) &EHOSTUNREACH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTEMPTY) {

            copy_pointer(p0, (void*) &ENOTEMPTY_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EPROCLIM) {

            // copy_pointer(p0, (void*) &EPROCLIM_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EUSERS) {

            copy_pointer(p0, (void*) &EUSERS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

#if defined(__linux__) || defined(__unix__)
        } else if (*e == EDQUOT) {

            copy_pointer(p0, (void*) &EDQUOT_ERROR_MESSAGE_LOG_CYBOI_MODEL);
#elif defined(__APPLE__) && defined(__MACH__)
        } else if (*e == EDQUOT) {

            copy_pointer(p0, (void*) &EDQUOT_ERROR_MESSAGE_LOG_CYBOI_MODEL);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            //?? Add Win32 support
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        } else if (*e == ESTALE) {

            copy_pointer(p0, (void*) &ESTALE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EREMOTE) {

            copy_pointer(p0, (void*) &EREMOTE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EBADRPC) {

            // copy_pointer(p0, (void*) &EBADRPC_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == ERPCMISMATCH) {

            // copy_pointer(p0, (void*) &ERPCMISMATCH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EPROGUNAVAIL) {

            // copy_pointer(p0, (void*) &EPROGUNAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EPROGMISMATCH) {

            // copy_pointer(p0, (void*) &EPROGMISMATCH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EPROCUNAVAIL) {

            // copy_pointer(p0, (void*) &EPROCUNAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOLCK) {

            copy_pointer(p0, (void*) &ENOLCK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EFTYPE) {

            // copy_pointer(p0, (void*) &EFTYPE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EAUTH) {

            // copy_pointer(p0, (void*) &EAUTH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == ENEEDAUTH) {

            // copy_pointer(p0, (void*) &ENEEDAUTH_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOSYS) {

            copy_pointer(p0, (void*) &ENOSYS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTSUP) {

            copy_pointer(p0, (void*) &ENOTSUP_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EILSEQ) {

            copy_pointer(p0, (void*) &EILSEQ_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EBACKGROUND) {

            // copy_pointer(p0, (void*) &EBACKGROUND_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EDIED) {

            // copy_pointer(p0, (void*) &EDIED_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == ED) {

            // copy_pointer(p0, (void*) &ED_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EGREGIOUS) {

            // copy_pointer(p0, (void*) &EGREGIOUS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EIEIO) {

            // copy_pointer(p0, (void*) &EIEIO_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        // } else if (*e == EGRATUITOUS) {

            // copy_pointer(p0, (void*) &EGRATUITOUS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EBADMSG) {

            copy_pointer(p0, (void*) &EBADMSG_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EIDRM) {

            copy_pointer(p0, (void*) &EIDRM_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EMULTIHOP) {

            copy_pointer(p0, (void*) &EMULTIHOP_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENODATA) {

            copy_pointer(p0, (void*) &ENODATA_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOLINK) {

            copy_pointer(p0, (void*) &ENOLINK_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOMSG) {

            copy_pointer(p0, (void*) &ENOMSG_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOSR) {

            copy_pointer(p0, (void*) &ENOSR_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOSTR) {

            copy_pointer(p0, (void*) &ENOSTR_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EOVERFLOW) {

            copy_pointer(p0, (void*) &EOVERFLOW_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EPROTO) {

            copy_pointer(p0, (void*) &EPROTO_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ETIME) {

            copy_pointer(p0, (void*) &ETIME_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ECANCELED) {

            copy_pointer(p0, (void*) &ECANCELED_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == EOWNERDEAD) {

            copy_pointer(p0, (void*) &EOWNERDEAD_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == ENOTRECOVERABLE) {

            copy_pointer(p0, (void*) &ENOTRECOVERABLE_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else {

#if defined(__linux__) || defined(__unix__)
            map_errno_to_message_linux(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
            map_errno_to_message_linux(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            map_errno_to_message_windows(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map errno to message. The errno value is null.");
        fwprintf(stdout, L"Error: Could not map errno to message. The errno value is null. p1: %i\n", p1);
    }
}
