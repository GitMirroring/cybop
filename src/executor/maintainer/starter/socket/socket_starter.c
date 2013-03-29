/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_STARTER_SOURCE
#define SOCKET_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

/*??
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
*/

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
//?? #include "../../../../constant/model/cybol/address_cybol_model.c"
//?? #include "../../../../constant/model/cybol/communication_style_cybol_model.c"
//?? #include "../../../../constant/model/cybol/http_request_cybol_model.c"
//?? #include "../../../../constant/model/cybol/namespace_cybol_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
//?? #include "../../../../executor/memoriser/allocator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/socket_type_size.c"

/**
 * Starts up the socket.
 *
 * @param p0 the internal memory data
 * @param p1 the namespace model
 * @param p2 the namespace model count
 * @param p3 the style model
 * @param p4 the style model count
 * @param p5 the socket file name or host address model (depending on the socket type: local, ipv4, ipv6)
 * @param p6 the socket file name or host address model count
 * @param p7 the port model
 * @param p8 the base internal
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* base = (int*) p8;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket.");

        // The socket namespace.
        int sn = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The address namespace.
        int an = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The communication style.
        int st = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The ipv4 host address of this system.
        struct in_addr ha4;
        // The ipv6 host address of this system.
        struct in6_addr ha6;
        //
        // CAUTION! Do use pointers for the addresses declared below,
        // and not only the structure as type, so that the different
        // socket addresses can be processed uniformly below!
        //
        // The local socket address of this system.
        struct sockaddr_un* la = (struct sockaddr_un*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The ipv4 internet socket address of this system.
        struct sockaddr_in* ia4 = (struct sockaddr_in*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The ipv6 internet socket address of this system.
        struct sockaddr_in6* ia6 = (struct sockaddr_in6*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner local socket address.
        struct sockaddr_un* pla = (struct sockaddr_un*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner ipv4 internet socket address.
        struct sockaddr_in* pia4 = (struct sockaddr_in*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner ipv6 internet socket address.
        struct sockaddr_in6* pia6 = (struct sockaddr_in6*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The socket address size of this system.
        int* as = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner socket address size.
        int* pas = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The socket of this system.
        int* s = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner socket.
        int* ps = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The character buffer being used in the thread procedure receiving messages via socket.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        int* bc = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        int* bs = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The result.
        int r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Get socket- and address namespace.
        startup_socket_get_namespace((void*) &sn, (void*) &an, p1, p2);
        // Get socket communication style.
        startup_socket_get_style((void*) &st, p3, p4);

        // Get host address constant.
        if (an == AF_INET) {

            startup_socket_get_host_address((void*) &ha4, p5, p6, (void*) &an);

        } else if (an == AF_INET6) {

            startup_socket_get_host_address((void*) &ha6, p5, p6, (void*) &an);
        }

        // Allocate socket address size of this system.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &as, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Allocate communication partner socket address size.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &pas, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Allocate socket of this system.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Allocate communication partner socket.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &ps, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Initialise socket address size of this system.
        copy_integer(as, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Initialise communication partner socket address size.
        copy_integer(pas, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (an == AF_LOCAL) {

            // CAUTION! The following line CANNOT be used:
            // *as = sizeof(struct sockaddr_un);
            // because the compiler brings the error
            // "invalid application of 'sizeof' to incomplete type 'struct sockaddr_un'".
            // The reason is the "sun_path" field of the "sockaddr_un" structure,
            // which is a character array whose size is unknown at compilation time.
            //
            // The size of the "sun_path" character array is therefore set
            // to the fixed size of 108.
            // The number "108" is the limit as set by the gnu c library!
            // Its documentation called it a "magic number" and does not
            // know why this limit exists.
            //
            // With the known type "short int" of the "sun_family" field and
            // a fixed size "108" of the "sun_path" field, the overall size of
            // the "sockaddr_un" structure can be calculated as sum.
            calculate_integer_add(as, (void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
            calculate_integer_add(as, (void*) NUMBER_108_INTEGER_STATE_CYBOI_MODEL);
            calculate_integer_add(pas, (void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
            calculate_integer_add(pas, (void*) NUMBER_108_INTEGER_STATE_CYBOI_MODEL);

        } else if (an == AF_INET) {

            calculate_integer_add(as, (void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
            calculate_integer_add(pas, (void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        } else if (an == AF_INET6) {

            calculate_integer_add(as, (void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
            calculate_integer_add(pas, (void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
        }

        // Allocate socket address of this system.
        // Allocate communication partner socket address.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        if (an == AF_LOCAL) {

            la = (struct sockaddr_un*) malloc(*as);
            pla = (struct sockaddr_un*) malloc(*pas);

        } else if (an == AF_INET) {

            ia4 = (struct sockaddr_in*) malloc(*as);
            pia4 = (struct sockaddr_in*) malloc(*pas);

        } else if (an == AF_INET6) {

            ia6 = (struct sockaddr_in6*) malloc(*as);
            pia6 = (struct sockaddr_in6*) malloc(*pas);
        }

        // Initialise socket address of this system.
        // CAUTION! Do NOT initialise communication partner socket address!
        // It gets initialised only before sending, or at reception of a message.
        if (an == AF_LOCAL) {

            startup_socket_initialise_local_socket_address((void*) &la, p5, p6);

        } else if (an == AF_INET) {

            startup_socket_initialise_ipv4_socket_address((void*) &ia4, (void*) &ha4, p7);

        } else if (an == AF_INET6) {

            startup_socket_initialise_ipv6_socket_address((void*) &ia6, (void*) &ha6, p7);
        }

        // Allocate character buffer count and size.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &bc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate((void*) &bs, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Initialise character buffer count, size.
        // A possible initial size is 2048, which should
        // suffice for transferring standard data over tcp/ip.
        // Another possible size could be 8192.
        copy_integer(bc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        copy_integer(bs, (void*) NUMBER_2048_INTEGER_STATE_CYBOI_MODEL);

        // Allocate character buffer.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        // CAUTION! Allocate character buffer only AFTER
        // the buffer size has been initialised above!
        allocate((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Set socket address of this system.
        // Set communication partner socket address.
        if (an == AF_LOCAL) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &la, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pla, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (an == AF_INET) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &ia4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pia4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (an == AF_INET6) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &ia6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pia6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

        // Set socket address size of this system.
        i = *base + *SIZE_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &as, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set communication partner socket address size.
        i = *base + *ADDRESS_SIZE_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &pas, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set communication partner socket.
        i = *base + *COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &ps, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set character buffer.
        i = *base + *DATA_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        i = *base + *COUNT_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &bc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        i = *base + *SIZE_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &bs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the procedure
        // that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise server socket.
        //
        // param 0: namespace
        // param 1: style
        // param 2: protocol
        //
        // CAUTION! Use prefix "PF_" here and NOT "AF_"!
        // The latter is to be used for address family assignment.
        // See further below!
        *s = socket(sn, st, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (*s >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set non-blocking mode for the socket file descriptor.
            //
            // If the O_NONBLOCK flag (a bit) is set, read requests on the socket
            // (file) can return immediately with a failure status if there is no
            // input immediately available, instead of blocking. Likewise, write
            // requests can also return immediately with a failure status if the
            // output can't be written immediately.
            //
            // CAUTION! The "select" procedure was NOT used to make this socket
            // non-blocking, because it has some overhead in that other sockets
            // need to be considered and their file descriptors handed over as
            // parametre.
            // A simple "sleep" procedure is considered to be a more simple and
            // clean solution here.

/*??
            // Get file status flags.
            int fl = fcntl(*s, F_GETFL, NUMBER_0_INTEGER);

            if (fl != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

                // Set non-blocking flag (bit).
                fl |= O_NONBLOCK;

                // Store modified flag word in the file descriptor.
                fcntl(*s, F_SETFL, fl);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket / set non-blocking mode. The socket file descriptor flags could not be read.");
            }
*/

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling the procedure
            // that might cause an error.
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Bind socket number to socket address.
            if (an == AF_LOCAL) {

                r = bind(*s, (struct sockaddr*) la, *((socklen_t*) as));

            } else if (an == AF_INET) {

                r = bind(*s, (struct sockaddr*) ia4, *((socklen_t*) as));

    fwprintf(stdout, L"TEST: startup socket bind s: %i \n", *s);
    sleep(2);

            } else if (an == AF_INET6) {

                r = bind(*s, (struct sockaddr*) ia6, *((socklen_t*) as));
            }

            if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                if (st == SOCK_STREAM) {

                    // Reset result.
                    r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // CAUTION! Datagram sockets do NOT have connections,
                    // which is why the "listen" procedure is only called
                    // for stream sockets here.

                    // Enable socket to accept connections, thus making it a server socket.
                    // The second parametre determines the number of possible
                    // pending client connection requests.
                    r = listen(*s, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"TEST: startup socket listen s: %i \n", *s);
    sleep(2);

                    if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The argument socket is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The argument socket is not a socket.");

                        } else if (errno == EOPNOTSUPP) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The socket does not support this operation.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. An unknown error occured while listening at the socket.");
                        }
                    }
                }

            } else {

                if (errno == EBADF) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The socket argument is not a valid file descriptor.");

                } else if (errno == ENOTSOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The descriptor socket is not a socket.");

                } else if (errno == EADDRNOTAVAIL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The specified address is not available on this machine.");

                } else if (errno == EADDRINUSE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The specified address is already used by some other socket.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The socket socket already has an address.");

                } else if (errno == EACCES) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The permission to access the requested address is missing. (In the internet domain, only the super-user is allowed to specify a port number in the range 0 through IPPORT_RESERVED minus one; see the section called 'Internet Ports'.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. An unknown error occured while binding the socket to the address.");
                }
            }

        } else {

            if (errno == EPROTONOSUPPORT) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The protocol or style is not supported by the namespace specified.");

            } else if (errno == EMFILE) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The process already has too many file descriptors open.");

            } else if (errno == ENFILE) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The system already has too many file descriptors open.");

            } else if (errno == EACCES) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The process does not have the privilege to create a socket of the specified style or protocol.");

            } else if (errno == ENOBUFS) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The system ran out of internal buffer space.");

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. An unknown error occured while initialising the socket.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up socket. The base internal is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_STARTER_SOURCE */
#endif
