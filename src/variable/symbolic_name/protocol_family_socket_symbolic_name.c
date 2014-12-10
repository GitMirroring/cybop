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

#ifndef PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE
#define PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE

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
// Protocol families, same as address families.
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/*??
#define PF_UNSPEC       AF_UNSPEC
#define PF_UNIX         AF_UNIX
#define PF_LOCAL        AF_LOCAL
#define PF_INET         AF_INET
#define PF_AX25         AF_AX25
#define PF_IPX          AF_IPX
#define PF_APPLETALK    AF_APPLETALK
#define PF_NETROM       AF_NETROM
#define PF_BRIDGE       AF_BRIDGE
#define PF_ATMPVC       AF_ATMPVC
#define PF_X25          AF_X25
#define PF_INET6        AF_INET6
#define PF_ROSE         AF_ROSE
#define PF_DECnet       AF_DECnet
#define PF_NETBEUI      AF_NETBEUI
#define PF_SECURITY     AF_SECURITY
#define PF_KEY          AF_KEY
#define PF_NETLINK      AF_NETLINK
#define PF_ROUTE        AF_ROUTE
#define PF_PACKET       AF_PACKET
#define PF_ASH          AF_ASH
#define PF_ECONET       AF_ECONET
#define PF_ATMSVC       AF_ATMSVC
#define PF_RDS          AF_RDS
#define PF_SNA          AF_SNA
#define PF_IRDA         AF_IRDA
#define PF_PPPOX        AF_PPPOX
#define PF_WANPIPE      AF_WANPIPE
#define PF_LLC          AF_LLC
#define PF_CAN          AF_CAN
#define PF_TIPC         AF_TIPC
#define PF_BLUETOOTH    AF_BLUETOOTH
#define PF_IUCV         AF_IUCV
#define PF_RXRPC        AF_RXRPC
#define PF_ISDN         AF_ISDN
#define PF_PHONET       AF_PHONET
#define PF_IEEE802154   AF_IEEE802154
#define PF_CAIF         AF_CAIF
#define PF_ALG          AF_ALG
#define PF_NFC          AF_NFC
#define PF_MAX          AF_MAX
*/

/* PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
