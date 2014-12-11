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

//
// The address families below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/** The unspec address family socket symbolic name. */
static int UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The local address family socket symbolic name. */
static int LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet ip protocol version 4 (inet) address family socket symbolic name. */
static int INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio ax.25 (ax25) address family socket symbolic name. */
static int AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = AX25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The novell ipx address family socket symbolic name. */
static int IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IPX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The appletalk ddp address family socket symbolic name. */
static int APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = APPLETALK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio net/rom (netrom) address family socket symbolic name. */
static int NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETROM_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The multiprotocol bridge address family socket symbolic name. */
static int BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = BRIDGE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The atmpvc address family socket symbolic name. */
static int ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ATMPVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The x.25 project (x25) address family socket symbolic name. */
static int X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = X25_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet ip protocol version 6 (inet6) address family socket symbolic name. */
static int INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio x.25 plp (rose) address family socket symbolic name. */
static int ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ROSE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The decnet project (decnet) address family socket symbolic name. */
static int DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = DECNET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 802.2llc project (netbeui) address family socket symbolic name. */
static int NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETBEUI_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The security callback pseudo address family (security) address family socket symbolic name. */
static int SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = SECURITY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The pf_key key management api (key) address family socket symbolic name. */
static int KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = KEY_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The netlink address family socket symbolic name. */
static int NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NETLINK_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The packet address family socket symbolic name. */
static int PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PACKET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ash address family socket symbolic name. */
static int ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ASH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The acorn econet address family socket symbolic name. */
static int ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ECONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The atmsvc address family socket symbolic name. */
static int ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ATMSVC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The rds address family socket symbolic name. */
static int RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = RDS_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The linux sna project (sna) address family socket symbolic name. */
static int SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = SNA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The irda address family socket symbolic name. */
static int IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The pppox address family socket symbolic name. */
static int PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PPPOX_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The wanpipe address family socket symbolic name. */
static int WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = WANPIPE_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The linux llc address family socket symbolic name. */
static int LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = LLC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The controller area network (can) address family socket symbolic name. */
static int CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = CAN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The tipc address family socket symbolic name. */
static int TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = TIPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The bluetooth address family socket symbolic name. */
static int BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The iucv address family socket symbolic name. */
static int IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IUCV_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The rxrpc address family socket symbolic name. */
static int RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = RXRPC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The isdn address family socket symbolic name. */
static int ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ISDN_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The phonet address family socket symbolic name. */
static int PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = PHONET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ieee802154 address family socket symbolic name. */
static int IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = IEEE802154_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The caif address family socket symbolic name. */
static int CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = CAIF_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The algorithm sockets (alg) address family socket symbolic name. */
static int ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = ALG_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The nfc address family socket symbolic name. */
static int NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME = NFC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
