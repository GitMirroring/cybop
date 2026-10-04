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

#ifndef LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER
#define LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// The following error messages are taken from the glibc documentation.
//
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Error-Codes
//

//
// The following error codes are defined by the Linux/i386 kernel.
// They are not yet documented.
//

/** The ERESTART linux error message log cyboi model. */
static wchar_t* ERESTART_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Interrupted system call should be restarted.";

/** The ECHRNG linux error message log cyboi model. */
static wchar_t* ECHRNG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Channel number out of range.";

/** The EL2NSYNC linux error message log cyboi model. */
static wchar_t* EL2NSYNC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Level 2 not synchronized.";

/** The EL3HLT linux error message log cyboi model. */
static wchar_t* EL3HLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Level 3 halted.";

/** The EL3RST linux error message log cyboi model. */
static wchar_t* EL3RST_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Level 3 reset.";

/** The ELNRNG linux error message log cyboi model. */
static wchar_t* ELNRNG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Link number out of range.";

/** The EUNATCH linux error message log cyboi model. */
static wchar_t* EUNATCH_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol driver not attached.";

/** The ENOCSI linux error message log cyboi model. */
static wchar_t* ENOCSI_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No CSI structure available.";

/** The EL2HLT linux error message log cyboi model. */
static wchar_t* EL2HLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Level 2 halted.";

/** The EBADE linux error message log cyboi model. */
static wchar_t* EBADE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid exchange.";

/** The EBADR linux error message log cyboi model. */
static wchar_t* EBADR_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid request descriptor.";

/** The EXFULL linux error message log cyboi model. */
static wchar_t* EXFULL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Exchange full.";

/** The ENOANO linux error message log cyboi model. */
static wchar_t* ENOANO_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No anode.";

/** The EBADRQC linux error message log cyboi model. */
static wchar_t* EBADRQC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid request code.";

/** The EBADSLT linux error message log cyboi model. */
static wchar_t* EBADSLT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid slot.";

/** The EDEADLOCK linux error message log cyboi model. */
static wchar_t* EDEADLOCK_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"File locking deadlock error.";

/** The EBFONT linux error message log cyboi model. */
static wchar_t* EBFONT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Bad font file format.";

/** The ENONET linux error message log cyboi model. */
static wchar_t* ENONET_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Machine is not on the network.";

/** The ENOPKG linux error message log cyboi model. */
static wchar_t* ENOPKG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Package not installed.";

/** The EADV linux error message log cyboi model. */
static wchar_t* EADV_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Advertise error.";

/** The ESRMNT linux error message log cyboi model. */
static wchar_t* ESRMNT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Srmount error.";

/** The ECOMM linux error message log cyboi model. */
static wchar_t* ECOMM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Communication error on send.";

/** The EDOTDOT linux error message log cyboi model. */
static wchar_t* EDOTDOT_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RFS specific error.";

/** The ENOTUNIQ linux error message log cyboi model. */
static wchar_t* ENOTUNIQ_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Name not unique on network.";

/** The EBADFD linux error message log cyboi model. */
static wchar_t* EBADFD_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"File descriptor in bad state.";

/** The EREMCHG linux error message log cyboi model. */
static wchar_t* EREMCHG_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Remote address changed.";

/** The ELIBACC linux error message log cyboi model. */
static wchar_t* ELIBACC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Can not access a needed shared library.";

/** The ELIBBAD linux error message log cyboi model. */
static wchar_t* ELIBBAD_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Accessing a corrupted shared library.";

/** The ELIBSCN linux error message log cyboi model. */
static wchar_t* ELIBSCN_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L".lib section in a.out corrupted.";

/** The ELIBMAX linux error message log cyboi model. */
static wchar_t* ELIBMAX_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Attempting to link in too many shared libraries.";

/** The ELIBEXEC linux error message log cyboi model. */
static wchar_t* ELIBEXEC_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Cannot exec a shared library directly.";

/** The ESTRPIPE linux error message log cyboi model. */
static wchar_t* ESTRPIPE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Streams pipe error.";

/** The EUCLEAN linux error message log cyboi model. */
static wchar_t* EUCLEAN_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Structure needs cleaning.";

/** The ENOTNAM linux error message log cyboi model. */
static wchar_t* ENOTNAM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Not a XENIX named type file.";

/** The ENAVAIL linux error message log cyboi model. */
static wchar_t* ENAVAIL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No XENIX semaphores available.";

/** The EISNAM linux error message log cyboi model. */
static wchar_t* EISNAM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Is a named type file.";

/** The EREMOTEIO linux error message log cyboi model. */
static wchar_t* EREMOTEIO_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Remote I/O error.";

/** The ENOMEDIUM linux error message log cyboi model. */
static wchar_t* ENOMEDIUM_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No medium found.";

/** The EMEDIUMTYPE linux error message log cyboi model. */
static wchar_t* EMEDIUMTYPE_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Wrong medium type.";

/** The ENOKEY linux error message log cyboi model. */
static wchar_t* ENOKEY_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Required key not available.";

/** The EKEYEXPIRED linux error message log cyboi model. */
static wchar_t* EKEYEXPIRED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Key has expired.";

/** The EKEYREVOKED linux error message log cyboi model. */
static wchar_t* EKEYREVOKED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Key has been revoked.";

/** The EKEYREJECTED linux error message log cyboi model. */
static wchar_t* EKEYREJECTED_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Key was rejected by service.";

/** The ERFKILL linux error message log cyboi model. */
static wchar_t* ERFKILL_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation not possible due to RF-kill.";

/** The EHWPOISON linux error message log cyboi model. */
static wchar_t* EHWPOISON_LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Memory page has hardware error.";

/* LINUX_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER */
#endif
