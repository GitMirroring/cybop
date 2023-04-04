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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE
#define ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
    #include <sys/socket.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/socket.h>
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

//
// The C header file "sys/socket.h" does not actually define
// those constants, but instead includes "bits/socket.h".
// This file defines around 38 AF_ constants and
// 38 PF_ constants like this:
//
// #define PF_INET     2   /* IP protocol family.  */
// #define AF_INET     PF_INET
//
// https://stackoverflow.com/questions/2549461/what-is-the-difference-between-af-inet-and-pf-inet-constants
//

/**
 * Initialises address family socket symbolic name
 * (pre-processor-defined) global variables.
 */
void globalise_symbolic_name_socket_address_family() {

#if defined(__linux__) || defined(__unix__)
    *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNSPEC; // 0
    //
    // CAUTION! An ALTERNATIVE name for AF_LOCAL with the same ID 1 would be:
    // *UNIX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNIX; // 1 Unix domain sockets
    //
    *LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_LOCAL; // 1 POSIX name for AF_UNIX
    *INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET; // 2 Internet IP Protocol
    *AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_AX25; // 3 Amateur Radio AX.25
    *IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IPX; // 4 Novell IPX
    *APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_APPLETALK; // 5 AppleTalk DDP
    *NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETROM; // 6 Amateur Radio NET/ROM
    *BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_BRIDGE; // 7 Multiprotocol bridge
    *ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ATMPVC; // 8 ATM PVCs
    *X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_X25; // 9 Reserved for X.25 project
    *INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET6; // 10 IP version 6
    *ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ROSE; // 11 Amateur Radio X.25 PLP
    //?? *DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_DECNET; // 12 Reserved for DECnet project
    *NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETBEUI; // 13 Reserved for 802.2LLC project
    *SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_SECURITY; // 14 Security callback pseudo AF
    *KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_KEY; // 15 PF_KEY key management API
    //
    // CAUTION! An ALTERNATIVE name for AF_NETLINK with the same ID 16 would be:
    // *ROUTE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ROUTE; // 16 NETLINK alias to emulate 4.4BSD
    //
    *NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETLINK; // 16
    *PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PACKET; // 17 Packet family
    *ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ASH; // 18 Ash
    *ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ECONET; // 19 Acorn Econet
    *ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ATMSVC; // 20 ATM SVCs
    *RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_RDS; // 21 RDS sockets
    *SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_SNA; // 22 Linux SNA Project (nutters!)
    *IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IRDA; // 23 IRDA sockets
    *PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PPPOX; // 24 PPPoX sockets
    *WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_WANPIPE; // 25 Wanpipe API Sockets
    *LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_LLC; // 26 Linux LLC
    *CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_CAN; // 29 Controller Area Network
    *TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TIPC; // 30 TIPC sockets
    *BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_BLUETOOTH; // 31 Bluetooth sockets
    *IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IUCV; // 32 IUCV sockets
    *RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_RXRPC; // 33 RxRPC sockets
    *ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ISDN; // 34 mISDN sockets
    *PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PHONET; // 35 Phonet sockets
    *IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IEEE802154; // 36 IEEE802154 sockets
    //?? *CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_CAIF; // 37 CAIF sockets
    //?? *ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ALG; // 38 Algorithm sockets
    //?? *NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NFC; // 39 NFC sockets
#elif defined(__APPLE__) && defined(__MACH__)
    *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNSPEC; // 0
    //
    // CAUTION! An ALTERNATIVE name for AF_LOCAL with the same ID 1 would be:
    // *UNIX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNIX; // 1 Unix domain sockets
    //
    *LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_LOCAL; // 1 POSIX name for AF_UNIX
    *INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET; // 2 Internet IP Protocol
    // *AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_AX25; // 3 Amateur Radio AX.25
    *IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IPX; // 4 Novell IPX
    *APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_APPLETALK; // 5 AppleTalk DDP
    // *NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETROM; // 6 Amateur Radio NET/ROM
    // *BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_BRIDGE; // 7 Multiprotocol bridge
    // *ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ATMPVC; // 8 ATM PVCs
    // *X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_X25; // 9 Reserved for X.25 project
    *INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET6; // 10 IP version 6
    // *ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ROSE; // 11 Amateur Radio X.25 PLP
    // *DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_DECNET; // 12 Reserved for DECnet project
    // *NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETBEUI; // 13 Reserved for 802.2LLC project
    // *SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_SECURITY; // 14 Security callback pseudo AF
    // *KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_KEY; // 15 PF_KEY key management API
    //
    // CAUTION! An ALTERNATIVE name for AF_NETLINK with the same ID 16 would be:
    // *ROUTE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ROUTE; // 16 NETLINK alias to emulate 4.4BSD
    //
    // *NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETLINK; // 16
    // *PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PACKET; // 17 Packet family
    // *ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ASH; // 18 Ash
    // *ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ECONET; // 19 Acorn Econet
    // *ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ATMSVC; // 20 ATM SVCs
    // *RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_RDS; // 21 RDS sockets
    *SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_SNA; // 22 Linux SNA Project (nutters!)
    // *IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IRDA; // 23 IRDA sockets
    // *PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PPPOX; // 24 PPPoX sockets
    // *WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_WANPIPE; // 25 Wanpipe API Sockets
    // *LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_LLC; // 26 Linux LLC
    // *CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_CAN; // 29 Controller Area Network
    // *TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TIPC; // 30 TIPC sockets
    // *BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_BLUETOOTH; // 31 Bluetooth sockets
    // *IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IUCV; // 32 IUCV sockets
    // *RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_RXRPC; // 33 RxRPC sockets
    *ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ISDN; // 34 mISDN sockets
    // *PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_PHONET; // 35 Phonet sockets
    // *IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IEEE802154; // 36 IEEE802154 sockets
    //?? *CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_CAIF; // 37 CAIF sockets
    //?? *ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_ALG; // 38 Algorithm sockets
    //?? *NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NFC; // 39 NFC sockets
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNSPEC; // 0
    //
    // CAUTION! The local unix domain socket AF_LOCAL or AF_UNIX
    // with ID 1 does NOT exist in windows operating system.
    //
    *INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET; // 2 Internet IP Protocol
    *IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IPX; // 6 Novell IPX; CAUTION! The id is DIFFERENT from Linux.
    *APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_APPLETALK; // 16 AppleTalk DDP; CAUTION! The id is DIFFERENT from Linux.
    *NETBIOS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_NETBIOS; // 17 NETBIOS supported on 32-bit versions of Windows; CAUTION! It does NOT exist for Linux.
    //?? *INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_INET6; // 23 IP version 6; CAUTION! The id is DIFFERENT from Linux.
    //?? *IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_IRDA; // 26 IRDA sockets; CAUTION! The id is DIFFERENT from Linux.
    //?? *BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_BTH; // 32 Bluetooth sockets; CAUTION! The id is DIFFERENT from Linux.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE */
#endif
