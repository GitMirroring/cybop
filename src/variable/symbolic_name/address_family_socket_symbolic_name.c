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

#ifndef ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE
#define ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// A symbolic name is a pre-processor define, e.g.:
//
// #define PF_INET     2   /* IP protocol family.  */
// #define AF_INET     PF_INET
//

/** The xyz protocol family socket symbolic name. */
static int XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

//
// Supported address families.
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/*??
#define AF_UNSPEC       0
#define AF_UNIX         1       // Unix domain sockets
#define AF_LOCAL        1       // POSIX name for AF_UNIX
#define AF_INET         2       // Internet IP Protocol
#define AF_AX25         3       // Amateur Radio AX.25
#define AF_IPX          4       // Novell IPX
#define AF_APPLETALK    5       // AppleTalk DDP
#define AF_NETROM       6       // Amateur Radio NET/ROM
#define AF_BRIDGE       7       // Multiprotocol bridge
#define AF_ATMPVC       8       // ATM PVCs
#define AF_X25          9       // Reserved for X.25 project
#define AF_INET6        10      // IP version 6
#define AF_ROSE         11      // Amateur Radio X.25 PLP
#define AF_DECnet       12      // Reserved for DECnet project
#define AF_NETBEUI      13      // Reserved for 802.2LLC project
#define AF_SECURITY     14      // Security callback pseudo AF
#define AF_KEY          15      // PF_KEY key management API
#define AF_NETLINK      16
#define AF_ROUTE        AF_NETLINK // Alias to emulate 4.4BSD
#define AF_PACKET       17      // Packet family
#define AF_ASH          18      // Ash
#define AF_ECONET       19      // Acorn Econet
#define AF_ATMSVC       20      // ATM SVCs
#define AF_RDS          21      // RDS sockets
#define AF_SNA          22      // Linux SNA Project (nutters!)
#define AF_IRDA         23      // IRDA sockets
#define AF_PPPOX        24      // PPPoX sockets
#define AF_WANPIPE      25      // Wanpipe API Sockets
#define AF_LLC          26      // Linux LLC
#define AF_CAN          29      // Controller Area Network
#define AF_TIPC         30      // TIPC sockets
#define AF_BLUETOOTH    31      // Bluetooth sockets
#define AF_IUCV         32      // IUCV sockets
#define AF_RXRPC        33      // RxRPC sockets
#define AF_ISDN         34      // mISDN sockets
#define AF_PHONET       35      // Phonet sockets
#define AF_IEEE802154   36      // IEEE802154 sockets
#define AF_CAIF         37      // CAIF sockets
#define AF_ALG          38      // Algorithm sockets
#define AF_NFC          39      // NFC sockets
#define AF_MAX          40      // For now..
*/

/* ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
