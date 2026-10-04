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

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
    #include <netinet/in.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <netinet/in.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "variable.h"

//
// The well-defined ip protocols below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/in.h
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx
//

/**
 * Initialises protocol socket symbolic name
 * (pre-processor-defined) global variables.
 */
void globalise_symbolic_name_socket_protocol() {

#if defined(__linux__) || defined(__unix__)
    *IP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IP; // 0 Dummy protocol for TCP
    *ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ICMP; // 1 Internet Control Message Protocol
    *IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IGMP; // 2 Internet Group Management Protocol
    *IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IPIP; // 4 IPIP tunnels (older KA9Q tunnels use 94)
    *TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_TCP; // 6 Transmission Control Protocol
    *EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_EGP; // 8 Exterior Gateway Protocol
    *PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_PUP; // 12 PUP protocol
    *UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_UDP; // 17 User Datagram Protocol
    *IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IDP; // 22 XNS IDP protocol
    *DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_DCCP; // 33 Datagram Congestion Control Protocol
    *IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IPV6; // 41 IPv6-in-IPv4 tunnelling
    *RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_RSVP; // 46 RSVP protocol
    *GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_GRE; // 47 Cisco GRE tunnels (rfc 1701,1702)
    *ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ESP; // 50 Encapsulation Security Payload protocol
    *AH_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_AH; // 51 Authentication Header protocol
    //?? *BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_BEETPH; // 94 IP option pseudo header for BEET
    *PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_PIM; // 103 Protocol Independent Multicast
    *COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_COMP; // 108 Compression Header protocol
    *SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_SCTP; // 132 Stream Control Transport Protocol
    *UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_UDPLITE; // 136 UDP-Lite (RFC 3828)
    *RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_RAW; // 255 Raw IP packets
#elif defined(__APPLE__) && defined(__MACH__)
    *IP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IP; // 0 Dummy protocol for TCP
    *ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ICMP; // 1 Internet Control Message Protocol
    *IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IGMP; // 2 Internet Group Management Protocol
    *IPIP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IPIP; // 4 IPIP tunnels (older KA9Q tunnels use 94)
    *TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_TCP; // 6 Transmission Control Protocol
    *EGP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_EGP; // 8 Exterior Gateway Protocol
    *PUP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_PUP; // 12 PUP protocol
    *UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_UDP; // 17 User Datagram Protocol
    *IDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IDP; // 22 XNS IDP protocol
    // *DCCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_DCCP; // 33 Datagram Congestion Control Protocol
    *IPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IPV6; // 41 IPv6-in-IPv4 tunnelling
    *RSVP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_RSVP; // 46 RSVP protocol
    *GRE_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_GRE; // 47 Cisco GRE tunnels (rfc 1701,1702)
    *ESP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ESP; // 50 Encapsulation Security Payload protocol
    *AH_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_AH; // 51 Authentication Header protocol
    // *BEETPH_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_BEETPH; // 94 IP option pseudo header for BEET
    *PIM_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_PIM; // 103 Protocol Independent Multicast
    // *COMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_COMP; // 108 Compression Header protocol
    *SCTP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_SCTP; // 132 Stream Control Transport Protocol
    // *UDPLITE_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_UDPLITE; // 136 UDP-Lite (RFC 3828)
    *RAW_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_RAW; // 255 Raw IP packets
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *ICMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ICMP; // 1 Internet Control Message Protocol (ICMP)
    *IGMP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_IGMP; // 2 Internet Group Management Protocol (IGMP)
    //?? *RFCOMM_BTHPROTO_PROTOCOL_SOCKET_SYMBOLIC_NAME = BTHPROTO_RFCOMM; // 3 Bluetooth Radio Frequency Communications (Bluetooth RFCOMM)
    *TCP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_TCP; // 6 Transmission Control Protocol (TCP)
    *UDP_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_UDP; // 17 User Datagram Protocol (UDP)
    //?? *ICMPV6_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_ICMPV6; // 58 Internet Control Message Protocol Version 6 (ICMPv6)
    //?? *RM_PROTOCOL_SOCKET_SYMBOLIC_NAME = IPPROTO_RM; // 113 PGM protocol for reliable multicast (RM)
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
