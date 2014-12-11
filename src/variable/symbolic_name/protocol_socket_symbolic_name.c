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

#ifndef PROTOCOL_SOCKET_SYMBOLIC_NAME_SOURCE
#define PROTOCOL_SOCKET_SYMBOLIC_NAME_SOURCE

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
// The well-defined ip protocols below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/in.h
//

/** The dummy for tcp ip protocol socket symbolic name. */
static int IP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet control message protocol (icmp) protocol socket symbolic name. */
static int ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The internet group management protocol (igmp) protocol socket symbolic name. */
static int IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ipip tunnels (older ka9q tunnels use 94) protocol socket symbolic name. */
static int IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The transmission control protocol (tcp) protocol socket symbolic name. */
static int TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The exterior gateway protocol (egp) protocol socket symbolic name. */
static int EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME = EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The pup protocol socket symbolic name. */
static int PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME = PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The user datagram protocol (udp) protocol socket symbolic name. */
static int UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The xns idp protocol socket symbolic name. */
static int IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The datagram congestion control protocol (dccp) protocol socket symbolic name. */
static int DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The rsvp protocol socket symbolic name. */
static int RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME = RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The cisco gre tunnels (rfc 1701, 1702) protocol socket symbolic name. */
static int GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME = GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ipv6-in-ipv4 tunnelling (ipv6) protocol socket symbolic name. */
static int IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The encapsulation security payload protocol (esp) protocol socket symbolic name. */
static int ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME = ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The authentication header (ah) protocol socket symbolic name. */
static int AH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* AH_PROTOCOL_SOCKET_SYMBOLIC_NAME = AH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The ip option pseudo header for beet (beetph) protocol socket symbolic name. */
static int BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME = BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The protocol independent multicast (pim) protocol socket symbolic name. */
static int PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME = PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The compression header protocol (comp) protocol socket symbolic name. */
static int COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The stream control transport protocol (sctp) protocol socket symbolic name. */
static int SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME = SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The udp-lite (udplite) (RFC 3828) protocol socket symbolic name. */
static int UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME = UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The raw ip packets (raw) protocol socket symbolic name. */
static int RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME = RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/* PROTOCOL_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
