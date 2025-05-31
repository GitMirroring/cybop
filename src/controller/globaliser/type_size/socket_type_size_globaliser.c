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

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
    #include <netinet/in.h>
    #include <sys/un.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <netinet/in.h>
    #include <sys/un.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "variable.h"

/**
 * Initialises socket type size global variables.
 */
void globalise_type_size_socket() {

    //
    // Initialise local socket address size.
    //
    // CAUTION! The following line CANNOT be used:
    // *as = sizeof (struct sockaddr_un);
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
    // With the known type "signed short int" of the "sun_family" field and
    // a fixed size "108" of the "sun_path" field, the overall size of
    // the "sockaddr_un" structure can be calculated as sum.
    //

#if defined(__linux__) || defined(__unix__)
    *IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in_addr);
    *IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in6_addr);
    *IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in);
    *IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in6);
    *LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE + *NUMBER_108_INTEGER_STATE_CYBOI_MODEL;
#elif defined(__APPLE__) && defined(__MACH__)
    *IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in_addr);
    *IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in6_addr);
    *IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in);
    *IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in6);
    *LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE + *NUMBER_108_INTEGER_STATE_CYBOI_MODEL;
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in_addr);
    //?? *IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct in6_addr);
    *IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in);
    //?? *IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof (struct sockaddr_in6);
    //
    // CAUTION! The local unix domain socket AF_LOCAL or AF_UNIX
    // with ID 1 does NOT exist in windows operating system.
    //
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
