/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PROTOCOL_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER
#define PROTOCOL_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER

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
// The well-defined ip protocols below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/in.h
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx
//

/** The 0 dummy for tcp ip protocol socket symbolic name. */
int IP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 1 internet control message protocol (icmp) protocol socket symbolic name. */
int ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 2 internet group management protocol (igmp) protocol socket symbolic name. */
int IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 3 bluetooth radio frequency communications (bluetooth rfcomm) protocol socket symbolic name. */
int RFCOMM_BTHPROTO_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RFCOMM_BTHPROTO_PROTOCOL_SOCKET_SYMBOLIC_NAME = RFCOMM_BTHPROTO_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 4 ipip tunnels (older ka9q tunnels use 94) protocol socket symbolic name. */
int IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 6 transmission control protocol (tcp) protocol socket symbolic name. */
int TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 8 exterior gateway protocol (egp) protocol socket symbolic name. */
int EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME = EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 12 pup protocol socket symbolic name. */
int PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME = PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 17 user datagram protocol (udp) protocol socket symbolic name. */
int UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 22 xns idp protocol socket symbolic name. */
int IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 33 datagram congestion control protocol (dccp) protocol socket symbolic name. */
int DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 41 ipv6-in-ipv4 tunnelling (ipv6) protocol socket symbolic name. */
int IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 46 rsvp protocol socket symbolic name. */
int RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME = RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 47 cisco gre tunnels (rfc 1701, 1702) protocol socket symbolic name. */
int GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME = GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 50 encapsulation security payload protocol (esp) protocol socket symbolic name. */
int ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME = ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 51 authentication header (ah) protocol socket symbolic name. */
int AH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* AH_PROTOCOL_SOCKET_SYMBOLIC_NAME = AH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 58 internet control message protocol version 6 (icmpv6) protocol socket symbolic name. */
int ICMPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* ICMPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = ICMPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 94 ip option pseudo header for beet (beetph) protocol socket symbolic name. */
int BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME = BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 103 protocol independent multicast (pim) protocol socket symbolic name. */
int PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME = PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 108 compression header protocol (comp) protocol socket symbolic name. */
int COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 113 pgm for reliable multicast (rm) protocol socket symbolic name. */
int RM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RM_PROTOCOL_SOCKET_SYMBOLIC_NAME = RM_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 132 stream control transport protocol (sctp) protocol socket symbolic name. */
int SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME = SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 136 udp-lite (udplite) (RFC 3828) protocol socket symbolic name. */
int UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME = UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 255 raw ip packets (raw) protocol socket symbolic name. */
int RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME = RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME_ARRAY;

/* PROTOCOL_SOCKET_SYMBOLIC_NAME_VARIABLE_HEADER */
#endif
