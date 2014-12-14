/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE
#define ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE

#ifdef __APPLE__
    #include <termios.h>
#elif WIN32
    // The win32 api does not seem to define symbolic names for baudrates.
    // It does assign standard integer values instead:
    // http://msdn.microsoft.com/en-us/library/system.io.ports.serialport.baudrate%28v=vs.110%29.aspx?cs-save-lang=1&cs-lang=cpp#code-snippet-1
    #include "../../../constant/model/cyboi/state/extra_integer_state_cyboi_model.c"
    #include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#else
    #include <termios.h>
#endif

#include "../../../variable/symbolic_name/address_family_socket_symbolic_name.c"

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

#ifdef __APPLE__
    *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_UNSPEC; // 0
    #define AF_UNIX         1       // Unix domain sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_LOCAL        1       // POSIX name for AF_UNIX
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_INET         2       // Internet IP Protocol
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_AX25         3       // Amateur Radio AX.25
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_IPX          4       // Novell IPX
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_APPLETALK    5       // AppleTalk DDP
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_NETROM       6       // Amateur Radio NET/ROM
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_BRIDGE       7       // Multiprotocol bridge
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ATMPVC       8       // ATM PVCs
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_X25          9       // Reserved for X.25 project
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_INET6        10      // IP version 6
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ROSE         11      // Amateur Radio X.25 PLP
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_DECnet       12      // Reserved for DECnet project
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_NETBEUI      13      // Reserved for 802.2LLC project
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_SECURITY     14      // Security callback pseudo AF
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_KEY          15      // PF_KEY key management API
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_NETLINK      16
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ROUTE        AF_NETLINK // Alias to emulate 4.4BSD
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_PACKET       17      // Packet family
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ASH          18      // Ash
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ECONET       19      // Acorn Econet
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ATMSVC       20      // ATM SVCs
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_RDS          21      // RDS sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_SNA          22      // Linux SNA Project (nutters!)
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_IRDA         23      // IRDA sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_PPPOX        24      // PPPoX sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_WANPIPE      25      // Wanpipe API Sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_LLC          26      // Linux LLC
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_CAN          29      // Controller Area Network
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_TIPC         30      // TIPC sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_BLUETOOTH    31      // Bluetooth sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_IUCV         32      // IUCV sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_RXRPC        33      // RxRPC sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ISDN         34      // mISDN sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_PHONET       35      // Phonet sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_IEEE802154   36      // IEEE802154 sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_CAIF         37      // CAIF sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_ALG          38      // Algorithm sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_NFC          39      // NFC sockets
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
    #define AF_MAX          40      // For now..
    *TODO_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AF_TODO; // TODO
#elif WIN32
#elif GNU_LINUX_OPERATING_SYSTEM
#else
#endif
}

/* ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE */
#endif
