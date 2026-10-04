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
 * @author Enrico Gallus <enrico.gallus@googlemail.com>
 */

#ifndef PROTOCOL_SERVICE_MODEL_CONSTANT_HEADER
#define PROTOCOL_SERVICE_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/**
 * The internet protocol (ip) service model.
 *
 * This is a pseudo protocol number.
 */
static int* IP_PROTOCOL_SERVICE_MODEL = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet control message protocol (icmp) service model. */
static int* IP_CONTROL_MESSAGE_PROTOCOL_SERVICE_MODEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet group management protocol (igmp) service model. */
static int* IP_GROUP_MANAGEMENT_PROTOCOL_SERVICE_MODEL = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gateway-gateway protocol (ggp) service model. */
static int* GATEWAY_GATEWAY_PROTOCOL_SERVICE_MODEL = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The IP encapsulated in IP (ip-encap) service model. */
static int* IP_ENCAPSULATED_IN_IP_PROTOCOL_SERVICE_MODEL = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ST datagram mode (st) service model. */
static int* ST_DATAGRAM_MODE_PROTOCOL_SERVICE_MODEL = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The transmission control protocol (tcp) service model. */
static int* TCP_PROTOCOL_SERVICE_MODEL = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The exterior gateway protocol (egp) service model. */
static int* EXTERIOR_GATEWAY_PROTOCOL_SERVICE_MODEL = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The any private interior gateway (igp) service model. */
static int* ANY_PRIVATE_INTERIOR_GATEWAY_PROTOCOL_SERVICE_MODEL = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The PARC universal packet protocol (pud) service model. */
static int* PARC_UNIVERSAL_PACKET_PROTOCOL_SERVICE_MODEL = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The user datagram protocol (udp) service model. */
static int* UDP_PROTOCOL_SERVICE_MODEL = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet protocol version 6 (ipv6) service model. */
static int* IPV6_PROTOCOL_SERVICE_MODEL = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The routing header for ipv6 service model. */
static int* IPV6_ROUTE_PROTOCOL_SERVICE_MODEL = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fragment header for ipv6 service model. */
static int* IPV6_FRAG_PROTOCOL_SERVICE_MODEL = NUMBER_44_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inter-domain routing protocol (idrp) service model. */
static int* INTER_DOMAIN_PROTOCOL_SERVICE_MODEL = NUMBER_45_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The icmp for ipv6 service model. */
static int* IPV6_ICMP_PROTOCOL_SERVICE_MODEL = NUMBER_58_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The no next header for ipv6 service model. */
static int* IPV6_NONXT_PROTOCOL_SERVICE_MODEL = NUMBER_59_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination options for ipv6 service model. */
static int* IPV6_OPTS_PROTOCOL_SERVICE_MODEL = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The radio shortest path first (cphb) service model. */
static int* RADIO_SHORTEST_PATH_FIRST_PROTOCOL_SERVICE_MODEL = NUMBER_73_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The versatile message transport (vmtp) service model. */
static int* VERSATILE_MESSAGE_TRANSPORT_PROTOCOL_SERVICE_MODEL = NUMBER_81_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The enhanced interior routing protocol (eigrp) service model. */
static int* ENHANCED_INTERIOR_ROUTING_PROTOCOL_SERVICE_MODEL = NUMBER_88_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The open shortest path first igp protocol service model. */
static int* OSPFIGP_PROTOCOL_SERVICE_MODEL = NUMBER_89_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ax.25 frames protocol service model. */
static int* AX_25_PROTOCOL_SERVICE_MODEL = NUMBER_93_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ip-within-ip encapsulation protocol service model. */
static int* IP_IP_PROTOCOL_SERVICE_MODEL = NUMBER_94_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ethernet-within-ip encapsulation protocol service model. */
static int* ETHERIP_PROTOCOL_SERVICE_MODEL = NUMBER_97_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yet another ip encapsulation protocol service model. */
static int* ENCAP_PROTOCOL_SERVICE_MODEL = NUMBER_98_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The any privat encryption scheme protocol service model. */
static int* PRIVAT_ENC_PROTOCOL_SERVICE_MODEL = NUMBER_99_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocal independent multicast protocol service model. */
static int* PIM_PROTOCOL_SERVICE_MODEL = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ip payload compression protocol service model. */
static int* IPCOMP_PROTOCOL_SERVICE_MODEL = NUMBER_108_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The virtual router redundancy protocol service model. */
static int* VRRP_PROTOCOL_SERVICE_MODEL = NUMBER_112_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The layer two tunneling protocol service model. */
static int* L2TP_PROTOCOL_SERVICE_MODEL = NUMBER_115_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The is-is over ipv4 protocol service model. */
static int* ISIS_PROTOCOL_SERVICE_MODEL = NUMBER_124_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The stream control transmission protocol service model. */
static int* SCTP_PROTOCOL_SERVICE_MODEL = NUMBER_132_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fibre channel protocol service model. */
static int* FC_PROTOCOL_SERVICE_MODEL = NUMBER_133_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp-lite protocol service model. */
static int* UDPLITE_PROTOCOL_SERVICE_MODEL = NUMBER_136_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpls-in-ip protocol service model. */
static int* MPLS_IN_IP_PROTOCOL_SERVICE_MODEL = NUMBER_137_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The manet protocol service model. */
static int* MANET_PROTOCOL_SERVICE_MODEL = NUMBER_138_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The host identity protocol service model. */
static int* HIP_PROTOCOL_SERVICE_MODEL = NUMBER_139_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shim6 protocol service model. */
static int* SHIM6_PROTOCOL_SERVICE_MODEL = NUMBER_140_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The wrapped encapsulating security payload protocol service model. */
static int* WESP_PROTOCOL_SERVICE_MODEL = NUMBER_141_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The robust header compression protocol service model. */
static int* ROHC_PROTOCOL_SERVICE_MODEL = NUMBER_142_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PROTOCOL_SERVICE_MODEL_CONSTANT_HEADER */
#endif
