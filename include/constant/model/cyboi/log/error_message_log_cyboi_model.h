/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER
#define ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// The following error messages are taken from the glibc documentation.
//
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Error-Codes
//

/** The EPERM error message log cyboi model. */
static wchar_t* EPERM_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation not permitted. Only the owner of the file (or other resource) or processes with special privileges can perform the operation.";

/** The ENOENT error message log cyboi model. */
static wchar_t* ENOENT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No such file or directory. This is a file doesnt exist error for ordinary files that are referenced in contexts where they are expected to already exist.";

/** The ESRCH error message log cyboi model. */
static wchar_t* ESRCH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No such process. No process matches the specified process ID.";

/** The EINTR error message log cyboi model. */
static wchar_t* EINTR_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Interrupted system call. An asynchronous signal occurred and prevented completion of the call. When this happens, you should try the call again. You can choose to have functions resume after a signal that is handled, rather than failing with EINTR; see Interrupted Primitives.";

/** The EIO error message log cyboi model. */
static wchar_t* EIO_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Input/output error. Usually used for physical read or write errors.";

/** The ENXIO error message log cyboi model. */
static wchar_t* ENXIO_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No such device or address. The system tried to use the device represented by a file you specified, and it couldnt find the device. This can mean that the device file was installed incorrectly, or that the physical device is missing or not correctly attached to the computer.";

/** The E2BIG error message log cyboi model. */
static wchar_t* E2BIG_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Argument list too long. Used when the arguments passed to a new program being executed with one of the exec functions (see Executing a File) occupy too much memory space. This condition never arises on GNU/Hurd systems.";

/** The ENOEXEC error message log cyboi model. */
static wchar_t* ENOEXEC_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Exec format error. Invalid executable file format. This condition is detected by the exec functions; see Executing a File.";

/** The EBADF error message log cyboi model. */
static wchar_t* EBADF_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Bad file descriptor. For example, I/O on a descriptor that has been closed or reading from a descriptor open only for writing (or vice versa).";

/** The ECHILD error message log cyboi model. */
static wchar_t* ECHILD_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No child processes. This error happens on operations that are supposed to manipulate child processes, when there arent any processes to manipulate.";

/** The EDEADLK error message log cyboi model. */
static wchar_t* EDEADLK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Resource deadlock avoided. Allocating a system resource would have resulted in a deadlock situation. The system does not guarantee that it will notice all such situations. This error means you got lucky and the system noticed; it might just hang. See File Locks, for an example.";

/** The ENOMEM error message log cyboi model. */
static wchar_t* ENOMEM_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Cannot allocate memory. The system cannot allocate more virtual memory because its capacity is full.";

/** The EACCES error message log cyboi model. */
static wchar_t* EACCES_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Permission denied. The file permissions do not allow the attempted operation.";

/** The EFAULT error message log cyboi model. */
static wchar_t* EFAULT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Bad address. An invalid pointer was detected. On GNU/Hurd systems, this error never happens; you get a signal instead.";

/** The ENOTBLK error message log cyboi model. */
static wchar_t* ENOTBLK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Block device required. A file that isnt a block special file was given in a situation that requires one. For example, trying to mount an ordinary file as a file system in Unix gives this error.";

/** The EBUSY error message log cyboi model. */
static wchar_t* EBUSY_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Device or resource busy. A system resource that cant be shared is already in use. For example, if you try to delete a file that is the root of a currently mounted filesystem, you get this error.";

/** The EEXIST error message log cyboi model. */
static wchar_t* EEXIST_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"File exists. An existing file was specified in a context where it only makes sense to specify a new file.";

/** The EXDEV error message log cyboi model. */
static wchar_t* EXDEV_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid cross-device link. An attempt to make an improper link across file systems was detected. This happens not only when you use link (see Hard Links) but also when you rename a file with rename (see Renaming Files).";

/** The ENODEV error message log cyboi model. */
static wchar_t* ENODEV_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No such device. The wrong type of device was given to a function that expects a particular sort of device.";

/** The ENOTDIR error message log cyboi model. */
static wchar_t* ENOTDIR_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Not a directory. A file that isnt a directory was specified when a directory is required.";

/** The EISDIR error message log cyboi model. */
static wchar_t* EISDIR_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Is a directory. You cannot open a directory for writing, or create or remove hard links to it.";

/** The EINVAL error message log cyboi model. */
static wchar_t* EINVAL_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid argument. This is used to indicate various kinds of problems with passing the wrong argument to a library function.";

/** The EMFILE error message log cyboi model. */
static wchar_t* EMFILE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many open files. The current process has too many files open and cant open any more. Duplicate descriptors do count toward this limit. In BSD and GNU, the number of open files is controlled by a resource limit that can usually be increased. If you get this error, you might want to increase the RLIMIT_NOFILE limit or make it unlimited; see Limits on Resources.";

/** The ENFILE error message log cyboi model. */
static wchar_t* ENFILE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many open files in system. There are too many distinct file openings in the entire system. Note that any number of linked channels count as just one file opening; see Linked Channels. This error never occurs on GNU/Hurd systems.";

/** The ENOTTY error message log cyboi model. */
static wchar_t* ENOTTY_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Inappropriate ioctl for device. Inappropriate I/O control operation, such as trying to set terminal modes on an ordinary file.";

/** The ETXTBSY error message log cyboi model. */
static wchar_t* ETXTBSY_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Text file busy. An attempt to execute a file that is currently open for writing, or write to a file that is currently being executed. Often using a debugger to run a program is considered having it open for writing and will cause this error. (The name stands for text file busy.) This is not an error on GNU/Hurd systems; the text is copied as necessary.";

/** The EFBIG error message log cyboi model. */
static wchar_t* EFBIG_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"File too large. The size of a file would be larger than allowed by the system.";

/** The ENOSPC error message log cyboi model. */
static wchar_t* ENOSPC_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No space left on device. Write operation on a file failed because the disk is full.";

/** The ESPIPE error message log cyboi model. */
static wchar_t* ESPIPE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Illegal seek. Invalid seek operation (such as on a pipe).";

/** The EROFS error message log cyboi model. */
static wchar_t* EROFS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Read-only file system. An attempt was made to modify something on a read-only file system.";

/** The EMLINK error message log cyboi model. */
static wchar_t* EMLINK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many links. The link count of a single file would become too large. rename can cause this error if the file being renamed already has as many links as it can take (see Renaming Files).";

/** The EPIPE error message log cyboi model. */
static wchar_t* EPIPE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Broken pipe. There is no process reading from the other end of a pipe. Every library function that returns this error code also generates a SIGPIPE signal; this signal terminates the program if not handled or blocked. Thus, your program will never actually see EPIPE unless it has handled or blocked SIGPIPE.";

/** The EDOM error message log cyboi model. */
static wchar_t* EDOM_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Numerical argument out of domain. Used by mathematical functions when an argument value does not fall into the domain over which the function is defined.";

/** The ERANGE error message log cyboi model. */
static wchar_t* ERANGE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Numerical result out of range. Used by mathematical functions when the result value is not representable because of overflow or underflow.";

/** The EAGAIN error message log cyboi model. */
static wchar_t* EAGAIN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Resource temporarily unavailable. The call might work if you try again later. The macro EWOULDBLOCK is another name for EAGAIN; they are always the same in the GNU C Library. This error can happen in a few different situations: An operation that would block was attempted on an object that has non-blocking mode selected. Trying the same operation again will block until some external condition makes it possible to read, write, or connect (whatever the operation). You can use select to find out when the operation will be possible; see Waiting for I/O. Portability Note: In many older Unix systems, this condition was indicated by EWOULDBLOCK, which was a distinct error code different from EAGAIN. To make your program portable, you should check for both codes and treat them the same. A temporary resource shortage made an operation impossible. fork can return this error. It indicates that the shortage is expected to pass, so your program can try the call again later and it may succeed. It is probably a good idea to delay for a few seconds before trying it again, to allow time for other processes to release scarce resources. Such shortages are usually fairly serious and affect the whole system, so usually an interactive program should report the error to the user and return to its command loop.";

/** The EWOULDBLOCK error message log cyboi model. */
static wchar_t* EWOULDBLOCK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation would block. In the GNU C Library, this is another name for EAGAIN (above). The values are always the same, on every operating system. C libraries in many older Unix systems have EWOULDBLOCK as a separate error code.";

/** The EINPROGRESS error message log cyboi model. */
static wchar_t* EINPROGRESS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation now in progress. An operation that cannot complete immediately was initiated on an object that has non-blocking mode selected. Some functions that must always block (such as connect; see Connecting) never return EAGAIN. Instead, they return EINPROGRESS to indicate that the operation has begun and will take some time. Attempts to manipulate the object before the call completes return EALREADY. You can use the select function to find out when the pending operation has completed; see Waiting for I/O.";

/** The EALREADY error message log cyboi model. */
static wchar_t* EALREADY_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation already in progress. An operation is already in progress on an object that has non-blocking mode selected.";

/** The ENOTSOCK error message log cyboi model. */
static wchar_t* ENOTSOCK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Socket operation on non-socket. A file that isnt a socket was specified when a socket is required.";

/** The EMSGSIZE error message log cyboi model. */
static wchar_t* EMSGSIZE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Message too long. The size of a message sent on a socket was larger than the supported maximum size.";

/** The EPROTOTYPE error message log cyboi model. */
static wchar_t* EPROTOTYPE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol wrong type for socket. The socket type does not support the requested communications protocol.";

/** The ENOPROTOOPT error message log cyboi model. */
static wchar_t* ENOPROTOOPT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol not available. You specified a socket option that doesnt make sense for the particular protocol being used by the socket. See Socket Options.";

/** The EPROTONOSUPPORT error message log cyboi model. */
static wchar_t* EPROTONOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol not supported. The socket domain does not support the requested communications protocol (perhaps because the requested protocol is completely invalid). See Creating a Socket.";

/** The ESOCKTNOSUPPORT error message log cyboi model. */
static wchar_t* ESOCKTNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Socket type not supported. The socket type is not supported.";

/** The EOPNOTSUPP error message log cyboi model. */
static wchar_t* EOPNOTSUPP_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation not supported. The operation you requested is not supported. Some socket functions dont make sense for all types of sockets, and others may not be implemented for all communications protocols. On GNU/Hurd systems, this error can happen for many calls when the object does not support the particular operation; it is a generic indication that the server knows nothing to do for that call.";

/** The EPFNOSUPPORT error message log cyboi model. */
static wchar_t* EPFNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol family not supported. The socket communications protocol family you requested is not supported.";

/** The EAFNOSUPPORT error message log cyboi model. */
static wchar_t* EAFNOSUPPORT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Address family not supported by protocol. The address family specified for a socket is not supported; it is inconsistent with the protocol being used on the socket. See Sockets.";

/** The EADDRINUSE error message log cyboi model. */
static wchar_t* EADDRINUSE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Address already in use. The requested socket address is already in use. See Socket Addresses.";

/** The EADDRNOTAVAIL error message log cyboi model. */
static wchar_t* EADDRNOTAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Cannot assign requested address. The requested socket address is not available; for example, you tried to give a socket a name that doesnt match the local host name. See Socket Addresses.";

/** The ENETDOWN error message log cyboi model. */
static wchar_t* ENETDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Network is down. A socket operation failed because the network was down.";

/** The ENETUNREACH error message log cyboi model. */
static wchar_t* ENETUNREACH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Network is unreachable. A socket operation failed because the subnet containing the remote host was unreachable.";

/** The ENETRESET error message log cyboi model. */
static wchar_t* ENETRESET_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Network dropped connection on reset. A network connection was reset because the remote host crashed.";

/** The ECONNABORTED error message log cyboi model. */
static wchar_t* ECONNABORTED_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Software caused connection abort. A network connection was aborted locally.";

/** The ECONNRESET error message log cyboi model. */
static wchar_t* ECONNRESET_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Connection reset by peer. A network connection was closed for reasons outside the control of the local host, such as by the remote machine rebooting or an unrecoverable protocol violation.";

/** The ENOBUFS error message log cyboi model. */
static wchar_t* ENOBUFS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No buffer space available. The kernels buffers for I/O operations are all in use. In GNU, this error is always synonymous with ENOMEM; you may get one or the other from network operations.";

/** The EISCONN error message log cyboi model. */
static wchar_t* EISCONN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Transport endpoint is already connected. You tried to connect a socket that is already connected. See Connecting.";

/** The ENOTCONN error message log cyboi model. */
static wchar_t* ENOTCONN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Transport endpoint is not connected. The socket is not connected to anything. You get this error when you try to transmit data over a socket, without first specifying a destination for the data. For a connectionless socket (for datagram protocols, such as UDP), you get EDESTADDRREQ instead.";

/** The EDESTADDRREQ error message log cyboi model. */
static wchar_t* EDESTADDRREQ_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Destination address required. No default destination address was set for the socket. You get this error when you try to transmit data over a connectionless socket, without first specifying a destination for the data with connect.";

/** The ESHUTDOWN error message log cyboi model. */
static wchar_t* ESHUTDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Cannot send after transport endpoint shutdown. The socket has already been shut down.";

/** The ETOOMANYREFS error message log cyboi model. */
static wchar_t* ETOOMANYREFS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many references: cannot splice.";

/** The ETIMEDOUT error message log cyboi model. */
static wchar_t* ETIMEDOUT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Connection timed out. A socket operation with a specified timeout received no response during the timeout period.";

/** The ECONNREFUSED error message log cyboi model. */
static wchar_t* ECONNREFUSED_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Connection refused. A remote host refused to allow the network connection (typically because it is not running the requested service).";

/** The ELOOP error message log cyboi model. */
static wchar_t* ELOOP_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many levels of symbolic links. Too many levels of symbolic links were encountered in looking up a file name. This often indicates a cycle of symbolic links.";

/** The ENAMETOOLONG error message log cyboi model. */
static wchar_t* ENAMETOOLONG_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"File name too long. Filename too long (longer than PATH_MAX; see Limits for Files) or host name too long (in gethostname or sethostname; see Host Identification).";

/** The EHOSTDOWN error message log cyboi model. */
static wchar_t* EHOSTDOWN_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Host is down. The remote host for a requested network connection is down.";

/** The EHOSTUNREACH error message log cyboi model. */
static wchar_t* EHOSTUNREACH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No route to host. The remote host for a requested network connection is not reachable.";

/** The ENOTEMPTY error message log cyboi model. */
static wchar_t* ENOTEMPTY_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Directory not empty. Directory not empty, where an empty directory was expected. Typically, this error occurs when you are trying to delete a directory.";

/** The EPROCLIM error message log cyboi model. */
static wchar_t* EPROCLIM_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many processes. This means that the per-user limit on new process would be exceeded by an attempted fork. See Limits on Resources, for details on the RLIMIT_NPROC limit.";

/** The EUSERS error message log cyboi model. */
static wchar_t* EUSERS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Too many users. The file quota system is confused because there are too many users.";

/** The EDQUOT error message log cyboi model. */
static wchar_t* EDQUOT_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Disk quota exceeded. The users disk quota was exceeded.";

/** The ESTALE error message log cyboi model. */
static wchar_t* ESTALE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Stale file handle. This indicates an internal confusion in the file system which is due to file system rearrangements on the server host for NFS file systems or corruption in other file systems. Repairing this condition usually requires unmounting, possibly repairing and remounting the file system.";

/** The EREMOTE error message log cyboi model. */
static wchar_t* EREMOTE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Object is remote. An attempt was made to NFS-mount a remote file system with a file name that already specifies an NFS-mounted file. (This is an error on some operating systems, but we expect it to work properly on GNU/Hurd systems, making this error code impossible.)";

/** The EBADRPC error message log cyboi model. */
static wchar_t* EBADRPC_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RPC struct is bad.";

/** The ERPCMISMATCH error message log cyboi model. */
static wchar_t* ERPCMISMATCH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RPC version wrong.";

/** The EPROGUNAVAIL error message log cyboi model. */
static wchar_t* EPROGUNAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RPC program not available.";

/** The EPROGMISMATCH error message log cyboi model. */
static wchar_t* EPROGMISMATCH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RPC program version wrong.";

/** The EPROCUNAVAIL error message log cyboi model. */
static wchar_t* EPROCUNAVAIL_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"RPC bad procedure for program.";

/** The ENOLCK error message log cyboi model. */
static wchar_t* ENOLCK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No locks available. This is used by the file locking facilities; see File Locks. This error is never generated by GNU/Hurd systems, but it can result from an operation to an NFS server running another operating system.";

/** The EFTYPE error message log cyboi model. */
static wchar_t* EFTYPE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Inappropriate file type or format. The file was the wrong type for the operation, or a data file had the wrong format. On some systems chmod returns this error if you try to set the sticky bit on a non-directory file; see Setting Permissions.";

/** The EAUTH error message log cyboi model. */
static wchar_t* EAUTH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Authentication error.";

/** The ENEEDAUTH error message log cyboi model. */
static wchar_t* ENEEDAUTH_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Need authenticator.";

/** The ENOSYS error message log cyboi model. */
static wchar_t* ENOSYS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Function not implemented. This indicates that the function called is not implemented at all, either in the C library itself or in the operating system. When you get this error, you can be sure that this particular function will always fail with ENOSYS unless you install a new version of the C library or the operating system.";

/** The ENOTSUP error message log cyboi model. */
static wchar_t* ENOTSUP_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Not supported. A function returns this error when certain parameter values are valid, but the functionality they request is not available. This can mean that the function does not implement a particular command or option value or flag bit at all. For functions that operate on some object given in a parameter, such as a file descriptor or a port, it might instead mean that only that specific object (file descriptor, port, etc.) is unable to support the other parameters given; different file descriptors might support different ranges of parameter values. If the entire function is not available at all in the implementation, it returns ENOSYS instead.";

/** The EILSEQ error message log cyboi model. */
static wchar_t* EILSEQ_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Invalid or incomplete multibyte or wide character. While decoding a multibyte character the function came along an invalid or an incomplete sequence of bytes or the given wide character is invalid.";

/** The EBACKGROUND error message log cyboi model. */
static wchar_t* EBACKGROUND_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Inappropriate operation for background process. On GNU/Hurd systems, servers supporting the term protocol return this error for certain operations when the caller is not in the foreground process group of the terminal. Users do not usually see this error because functions such as read and write translate it into a SIGTTIN or SIGTTOU signal. See Job Control, for information on process groups and these signals.";

/** The EDIED error message log cyboi model. */
static wchar_t* EDIED_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Translator died. On GNU/Hurd systems, opening a file returns this error when the file is translated by a program and the translator program dies while starting up, before it has connected to the file.";

/** The ED error message log cyboi model. */
static wchar_t* ED_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"?. The experienced user will know what is wrong.";

/** The EGREGIOUS error message log cyboi model. */
static wchar_t* EGREGIOUS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"You really blew it this time. You did what?";

/** The EIEIO error message log cyboi model. */
static wchar_t* EIEIO_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Computer bought the farm. Go home and have a glass of warm, dairy-fresh milk.";

/** The EGRATUITOUS error message log cyboi model. */
static wchar_t* EGRATUITOUS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Gratuitous error. This error code has no purpose.";

/** The EBADMSG error message log cyboi model. */
static wchar_t* EBADMSG_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Bad message.";

/** The EIDRM error message log cyboi model. */
static wchar_t* EIDRM_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Identifier removed.";

/** The EMULTIHOP error message log cyboi model. */
static wchar_t* EMULTIHOP_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Multihop attempted.";

/** The ENODATA error message log cyboi model. */
static wchar_t* ENODATA_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No data available.";

/** The ENOLINK error message log cyboi model. */
static wchar_t* ENOLINK_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Link has been severed.";

/** The ENOMSG error message log cyboi model. */
static wchar_t* ENOMSG_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No message of desired type.";

/** The ENOSR error message log cyboi model. */
static wchar_t* ENOSR_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Out of streams resources.";

/** The ENOSTR error message log cyboi model. */
static wchar_t* ENOSTR_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Device not a stream.";

/** The EOVERFLOW error message log cyboi model. */
static wchar_t* EOVERFLOW_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Value too large for defined data type.";

/** The EPROTO error message log cyboi model. */
static wchar_t* EPROTO_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Protocol error.";

/** The ETIME error message log cyboi model. */
static wchar_t* ETIME_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Timer expired.";

/** The ECANCELED error message log cyboi model. */
static wchar_t* ECANCELED_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Operation canceled. An asynchronous operation was canceled before it completed. See Asynchronous I/O. When you call aio_cancel, the normal result is for the operations affected to complete with this error; see Cancel AIO Operations.";

/** The EOWNERDEAD error message log cyboi model. */
static wchar_t* EOWNERDEAD_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Owner died.";

/** The ENOTRECOVERABLE error message log cyboi model. */
static wchar_t* ENOTRECOVERABLE_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"State not recoverable.";

/* ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER */
#endif
