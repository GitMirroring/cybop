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

#ifndef PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER
#define PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER

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
int UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 1 local protocol family socket symbolic name. */
int LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 2 internet ip protocol version 4 (inet) protocol family socket symbolic name. */
int INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 3 amateur radio ax.25 (ax25) protocol family socket symbolic name. */
int AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 4 (6 in win32) novell ipx protocol family socket symbolic name. */
int IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 5 (16 in win32) appletalk ddp protocol family socket symbolic name. */
int APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 6 amateur radio net/rom (netrom) protocol family socket symbolic name. */
int NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 7 multiprotocol bridge protocol family socket symbolic name. */
int BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 8 atmpvc protocol family socket symbolic name. */
int ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 9 x.25 project (x25) protocol family socket symbolic name. */
int X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 10 (23 in win32) internet ip protocol version 6 (inet6) protocol family socket symbolic name. */
int INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 11 amateur radio x.25 plp (rose) protocol family socket symbolic name. */
int ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 12 decnet project (decnet) protocol family socket symbolic name. */
int DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 13 802.2llc project (netbeui) protocol family socket symbolic name. */
int NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 14 security callback pseudo protocol family (security) protocol family socket symbolic name. */
int SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 15 pf_key key management api (key) protocol family socket symbolic name. */
int KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 16 netlink protocol family socket symbolic name. */
int NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 packet protocol family socket symbolic name. */
int PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 (in win32; not used in linux; identical to "packet" address family) netbios protocol family socket symbolic name. */
int NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 18 ash protocol family socket symbolic name. */
int ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 19 acorn econet protocol family socket symbolic name. */
int ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 20 atmsvc protocol family socket symbolic name. */
int ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 21 rds protocol family socket symbolic name. */
int RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 22 linux sna project (sna) protocol family socket symbolic name. */
int SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 23 (26 in win32) irda protocol family socket symbolic name. */
int IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 24 pppox protocol family socket symbolic name. */
int PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 25 wanpipe protocol family socket symbolic name. */
int WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 26 linux llc protocol family socket symbolic name. */
int LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 29 controller area network (can) protocol family socket symbolic name. */
int CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 30 tipc protocol family socket symbolic name. */
int TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 31 (32 in win32) bluetooth protocol family socket symbolic name. */
int BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 32 iucv protocol family socket symbolic name. */
int IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 33 rxrpc protocol family socket symbolic name. */
int RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 34 isdn protocol family socket symbolic name. */
int ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 35 phonet protocol family socket symbolic name. */
int PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 36 ieee802154 protocol family socket symbolic name. */
int IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 37 caif protocol family socket symbolic name. */
int CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 38 algorithm sockets (alg) protocol family socket symbolic name. */
int ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 39 nfc protocol family socket symbolic name. */
int NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER */
#endif
