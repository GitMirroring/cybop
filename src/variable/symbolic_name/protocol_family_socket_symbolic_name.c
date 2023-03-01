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
// CAUTION! They CANNOT be handed over as reference to a function
// since otherwise, the compiler will show an error like:
// error: lvalue required as unary ‘&’ operand
//
// Therefore, these global variables are defined to hold the
// original value of the symbolic name and be used instead.
//
// CAUTION! The definition of pure integer constants is NOT possible,
// since the values of symbolic names DIFFER between operating systems.
// Therefore, global variables are used and the values of
// symbolic names assigned at runtime, when cyboi starts up.
//

//
// The protocol families below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/** The 0 unspec protocol family socket symbolic name. */
static int UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 1 local protocol family socket symbolic name. */
static int LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 2 internet ip protocol version 4 (inet) protocol family socket symbolic name. */
static int INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 3 amateur radio ax.25 (ax25) protocol family socket symbolic name. */
static int AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 4 (6 in win32) novell ipx protocol family socket symbolic name. */
static int IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 5 (16 in win32) appletalk ddp protocol family socket symbolic name. */
static int APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 6 amateur radio net/rom (netrom) protocol family socket symbolic name. */
static int NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 7 multiprotocol bridge protocol family socket symbolic name. */
static int BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 8 atmpvc protocol family socket symbolic name. */
static int ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 9 x.25 project (x25) protocol family socket symbolic name. */
static int X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 10 (23 in win32) internet ip protocol version 6 (inet6) protocol family socket symbolic name. */
static int INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 11 amateur radio x.25 plp (rose) protocol family socket symbolic name. */
static int ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 12 decnet project (decnet) protocol family socket symbolic name. */
static int DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 13 802.2llc project (netbeui) protocol family socket symbolic name. */
static int NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 14 security callback pseudo protocol family (security) protocol family socket symbolic name. */
static int SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 15 pf_key key management api (key) protocol family socket symbolic name. */
static int KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 16 netlink protocol family socket symbolic name. */
static int NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 packet protocol family socket symbolic name. */
static int PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 (in win32; not used in linux; identical to "packet" address family) netbios protocol family socket symbolic name. */
static int NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 18 ash protocol family socket symbolic name. */
static int ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 19 acorn econet protocol family socket symbolic name. */
static int ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 20 atmsvc protocol family socket symbolic name. */
static int ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 21 rds protocol family socket symbolic name. */
static int RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 22 linux sna project (sna) protocol family socket symbolic name. */
static int SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 23 (26 in win32) irda protocol family socket symbolic name. */
static int IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 24 pppox protocol family socket symbolic name. */
static int PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 25 wanpipe protocol family socket symbolic name. */
static int WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 26 linux llc protocol family socket symbolic name. */
static int LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 29 controller area network (can) protocol family socket symbolic name. */
static int CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 30 tipc protocol family socket symbolic name. */
static int TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 31 (32 in win32) bluetooth protocol family socket symbolic name. */
static int BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 32 iucv protocol family socket symbolic name. */
static int IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 33 rxrpc protocol family socket symbolic name. */
static int RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 34 isdn protocol family socket symbolic name. */
static int ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 35 phonet protocol family socket symbolic name. */
static int PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 36 ieee802154 protocol family socket symbolic name. */
static int IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 37 caif protocol family socket symbolic name. */
static int CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 38 algorithm sockets (alg) protocol family socket symbolic name. */
static int ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 39 nfc protocol family socket symbolic name. */
static int NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
