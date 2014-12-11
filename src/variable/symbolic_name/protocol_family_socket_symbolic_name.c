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

//
// The protocol families below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/socket.h
//

/** The unspec protocol family socket symbolic name. */
static int UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The local protocol family socket symbolic name. */
static int LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet ip protocol version 4 (inet) protocol family socket symbolic name. */
static int INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio ax.25 (ax25) protocol family socket symbolic name. */
static int AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = AX25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The novell ipx protocol family socket symbolic name. */
static int IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The appletalk ddp protocol family socket symbolic name. */
static int APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio net/rom (netrom) protocol family socket symbolic name. */
static int NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETROM_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The multiprotocol bridge protocol family socket symbolic name. */
static int BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BRIDGE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The atmpvc protocol family socket symbolic name. */
static int ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMPVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The x.25 project (x25) protocol family socket symbolic name. */
static int X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = X25_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet ip protocol version 6 (inet6) protocol family socket symbolic name. */
static int INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The amateur radio x.25 plp (rose) protocol family socket symbolic name. */
static int ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ROSE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The decnet project (decnet) protocol family socket symbolic name. */
static int DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = DECNET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 802.2llc project (netbeui) protocol family socket symbolic name. */
static int NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETBEUI_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The security callback pseudo protocol family (security) protocol family socket symbolic name. */
static int SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SECURITY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The pf_key key management api (key) protocol family socket symbolic name. */
static int KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = KEY_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The netlink protocol family socket symbolic name. */
static int NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NETLINK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The packet protocol family socket symbolic name. */
static int PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PACKET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ash protocol family socket symbolic name. */
static int ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ASH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The acorn econet protocol family socket symbolic name. */
static int ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ECONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The atmsvc protocol family socket symbolic name. */
static int ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ATMSVC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The rds protocol family socket symbolic name. */
static int RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RDS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The linux sna project (sna) protocol family socket symbolic name. */
static int SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = SNA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The irda protocol family socket symbolic name. */
static int IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The pppox protocol family socket symbolic name. */
static int PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PPPOX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The wanpipe protocol family socket symbolic name. */
static int WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = WANPIPE_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The linux llc protocol family socket symbolic name. */
static int LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = LLC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The controller area network (can) protocol family socket symbolic name. */
static int CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The tipc protocol family socket symbolic name. */
static int TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = TIPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The bluetooth protocol family socket symbolic name. */
static int BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The iucv protocol family socket symbolic name. */
static int IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IUCV_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The rxrpc protocol family socket symbolic name. */
static int RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = RXRPC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The isdn protocol family socket symbolic name. */
static int ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ISDN_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The phonet protocol family socket symbolic name. */
static int PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = PHONET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ieee802154 protocol family socket symbolic name. */
static int IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = IEEE802154_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The caif protocol family socket symbolic name. */
static int CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = CAIF_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The algorithm sockets (alg) protocol family socket symbolic name. */
static int ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = ALG_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The nfc protocol family socket symbolic name. */
static int NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = NFC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
