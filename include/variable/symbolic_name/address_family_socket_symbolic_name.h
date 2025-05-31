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

#ifndef ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER
#define ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER

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
// The address families below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/** The 0 unspec address family socket symbolic name. */
int UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 1 local address family socket symbolic name. */
int LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 2 internet ip protocol version 4 (inet) address family socket symbolic name. */
int INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 3 amateur radio ax.25 (ax25) address family socket symbolic name. */
int AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 4 (6 in win32) novell ipx address family socket symbolic name. */
int IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 5 (16 in win32) appletalk ddp address family socket symbolic name. */
int APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 6 amateur radio net/rom (netrom) address family socket symbolic name. */
int NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 7 multiprotocol bridge address family socket symbolic name. */
int BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 8 atmpvc address family socket symbolic name. */
int ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 9 x.25 project (x25) address family socket symbolic name. */
int X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 10 (23 in win32) internet ip protocol version 6 (inet6) address family socket symbolic name. */
int INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 11 amateur radio x.25 plp (rose) address family socket symbolic name. */
int ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 12 decnet project (decnet) address family socket symbolic name. */
int DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 13 802.2llc project (netbeui) address family socket symbolic name. */
int NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 14 security callback pseudo address family (security) address family socket symbolic name. */
int SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 15 pf_key key management api (key) address family socket symbolic name. */
int KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 16 netlink address family socket symbolic name. */
int NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 packet address family socket symbolic name. */
int PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 (in win32; not used in linux; identical to "packet" address family) netbios address family socket symbolic name. */
int NETBIOS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NETBIOS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETBIOS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 18 ash address family socket symbolic name. */
int ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 19 acorn econet address family socket symbolic name. */
int ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 20 atmsvc address family socket symbolic name. */
int ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 21 rds address family socket symbolic name. */
int RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 22 linux sna project (sna) address family socket symbolic name. */
int SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 23 (26 in win32) irda address family socket symbolic name. */
int IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 24 pppox address family socket symbolic name. */
int PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 25 wanpipe address family socket symbolic name. */
int WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 26 linux llc address family socket symbolic name. */
int LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 29 controller area network (can) address family socket symbolic name. */
int CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 30 tipc address family socket symbolic name. */
int TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 31 (32 in win32) bluetooth address family socket symbolic name. */
int BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 32 iucv address family socket symbolic name. */
int IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 33 rxrpc address family socket symbolic name. */
int RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 34 isdn address family socket symbolic name. */
int ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 35 phonet address family socket symbolic name. */
int PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 36 ieee802154 address family socket symbolic name. */
int IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 37 caif address family socket symbolic name. */
int CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 38 algorithm sockets (alg) address family socket symbolic name. */
int ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 39 nfc address family socket symbolic name. */
int NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER */
#endif
