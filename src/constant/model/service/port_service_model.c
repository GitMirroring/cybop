/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Enrico Gallus <enrico.gallus@googlemail.com>
 */

#ifndef PORT_SERVICE_MODEL_CONSTANT_SOURCE
#define PORT_SERVICE_MODEL_CONSTANT_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// IANA assigned ports.
//
// Sorted here by their assigned number.
//

/** The tcp service multiplexer port service model. */
static int* TCP_MUX_PORT_SERVICE_MODEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp echo port service model. */
static int* TCP_ECHO_PORT_SERVICE_MODEL = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp echo port service model. */
static int* UDP_ECHO_PORT_SERVICE_MODEL = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp discard (sink null) port service model. */
static int* TCP_DISCARD_PORT_SERVICE_MODEL = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp discard (sink null) port service model. */
static int* UDP_DISCARD_PORT_SERVICE_MODEL = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp systat (user) port service model. */
static int* TCP_SYSTAT_PORT_SERVICE_MODEL = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp daytime port service model. */
static int* TCP_DAYTIME_PORT_SERVICE_MODEL = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp daytime port service model. */
static int* UDP_DAYTIME_PORT_SERVICE_MODEL = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp netstat port service model. */
static int* TCP_NETSTAT_PORT_SERVICE_MODEL = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp qotd (quote) port service model. */
static int* TCP_QOTD_PORT_SERVICE_MODEL = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp message send protocol port service model. */
static int* TCP_MSP_PORT_SERVICE_MODEL = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp message send protocol port service model. */
static int* UDP_MSP_PORT_SERVICE_MODEL = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp ttytst source port service model. */
static int* TCP_CHARGEN_PORT_SERVICE_MODEL = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp ttytst port service model. */
static int* UDP_CHARGEM_PORT_SERVICE_MODEL = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp file transfer protocol (ftp) data port service model. */
static int* TCP_FTP_DATA_PORT_SERVICE_MODEL = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp file transfer protocol (ftp) port service model. */
static int* TCP_FTP_PORT_SERVICE_MODEL = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp fspd port service model. */
static int* UDP_FSP_PORT_SERVICE_MODEL = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp secure shell (ssh) remote login protocol port service model. */
static int* TCP_SSH_PORT_SERVICE_MODEL = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp secure shell (ssh) remote login protocol port service model. */
static int* UDP_SSH_PORT_SERVICE_MODEL = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp telnet port service model. */
static int* TCP_TELNET_PORT_SERVICE_MODEL = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp mail transfer protocol (smtp) port service model. */
static int* TCP_SMTP_PORT_SERVICE_MODEL = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp timeserver protocol port service model. */
static int* TCP_TIME_PORT_SERVICE_MODEL = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp timeserver protocol port service model. */
static int* UDP_TIME_PORT_SERVICE_MODEL = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp ressource location port service model. */
static int* TCP_RLP_PORT_SERVICE_MODEL = NUMBER_39_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp nameserver port service model. */
static int* TCP_NAMESERVER_PORT_SERVICE_MODEL = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp nicname port service model. */
static int* TCP_WHOIS_PORT_SERVICE_MODEL = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp login host protocol (tacacs) port service model. */
static int* TCP_TACACS_PORT_SERVICE_MODEL = NUMBER_49_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp login host protocol (tacacs) port service model. */
static int* UDP_TACACS_PORT_SERVICE_MODEL = NUMBER_49_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp remote mail checking protocol port service model. */
static int* TCP_RE_MAIL_CK_PORT_SERVICE_MODEL = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp remote mail checking protocol port service model. */
static int* UDP_RE_MAIL_CK_PORT_SERVICE_MODEL = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp name domain server port service model. */
static int* TCP_DOMAIN_PORT_SERVICE_MODEL = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp remote mail checking protocol port service model. */
static int* UDP_DOMAIN_PORT_SERVICE_MODEL = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp mtp service model. (deprecated) */
static int* TCP_MTP_PORT_SERVICE_MODEL = NUMBER_57_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp tacacs database port service model. */
static int* TCP_TACACS_DS_PORT_SERVICE_MODEL = NUMBER_65_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp tacacs database port service model. */
static int* UDP_TACACS_DS_PORT_SERVICE_MODEL = NUMBER_65_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp bootp server port service model. */
static int* TCP_BOOTPS_PORT_SERVICE_MODEL = NUMBER_67_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp bootp server port service model. */
static int* UDP_BOOTPS_PORT_SERVICE_MODEL = NUMBER_67_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp bootp client port service model. */
static int* TCP_BOOTPC_PORT_SERVICE_MODEL = NUMBER_68_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp bootp client port service model. */
static int* UDP_BOOTPC_PORT_SERVICE_MODEL = NUMBER_68_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp file transfer protocol port service model. */
static int* UDP_TFTP_PORT_SERVICE_MODEL = NUMBER_69_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp internet gopher port service model. */
static int* TCP_GOPHER_PORT_SERVICE_MODEL = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp internet gopher port service model. */
static int* UDP_GOPHER_PORT_SERVICE_MODEL = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp net rjs port service model. */
static int* TCP_RJE_PORT_SERVICE_MODEL = NUMBER_77_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp finger port service model. */
static int* TCP_FINGER_PORT_SERVICE_MODEL = NUMBER_79_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp world wide web (www) hypertext transfer protocol (http) port service model. */
static int* TCP_WWW_PORT_SERVICE_MODEL = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp world wide web (www) hypertext transfer protocol (http) port service model. */
static int* UDP_WWW_PORT_SERVICE_MODEL = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp tty link port service model. */
static int* TCP_LINK_PORT_SERVICE_MODEL = NUMBER_87_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp kerberos port service model. */
static int* TCP_KERBEROS_PORT_SERVICE_MODEL = NUMBER_88_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp kerberos port service model. */
static int* UDP_KERBEROS_PORT_SERVICE_MODEL = NUMBER_88_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp supdup port service model. */
static int* TCP_SUPDUP_PORT_SERVICE_MODEL = NUMBER_95_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hostname port service model. */
static int* TCP_HOSTNAME_PORT_SERVICE_MODEL = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp iso-tsap as part of the ISODE port service model. */
static int* TCP_ISO_TSAP_PORT_SERVICE_MODEL = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp acr-nema of the company Digital Imag. & Comm. 300 port service model. */
static int* TCP_ACR_NEMA_PORT_SERVICE_MODEL = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp acr-nema of the company Digital Imag. & Comm. 300 port service model. */
static int* UDP_ACR_NEMA_PORT_SERVICE_MODEL = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp csnet nameserver port service model. */
static int* TCP_CSNET_NS_PORT_SERVICE_MODEL = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp csnet nameserver port service model. */
static int* UDP_CSNET_NS_PORT_SERVICE_MODEL = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp remote telnet port service model. */
static int* TCP_RTELNET_PORT_SERVICE_MODEL = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp remote telnet port service model. */
static int* UDP_RTELNET_PORT_SERVICE_MODEL = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp postoffice pop 2 port service model. */
static int* TCP_POP2_PORT_SERVICE_MODEL = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp postoffice pop 2 port service model. */
static int* UDP_POP2_PORT_SERVICE_MODEL = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp post office protocol version 3 (pop3) port service model. */
static int* TCP_POP3_PORT_SERVICE_MODEL = NUMBER_110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp post office protocol version 3 (pop3) port service model. */
static int* UDP_POP3_PORT_SERVICE_MODEL = NUMBER_110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp rpc 4.0 portmapper port service model. */
static int* TCP_SUNRPC_PORT_SERVICE_MODEL = NUMBER_111_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp rpc 4.0 portmapper port service model. */
static int* UDP_SUNRPC_PORT_SERVICE_MODEL = NUMBER_111_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp authentication tap ident port service model. */
static int* TCP_AUTH_PORT_SERVICE_MODEL = NUMBER_113_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp secure file transfer protocol port service model. */
static int* TCP_SFTP_PORT_SERVICE_MODEL = NUMBER_115_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp uucp-path port service model. */
static int* TCP_UUCP_PATH_PORT_SERVICE_MODEL = NUMBER_117_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp usenet new transfer protocol port service model. */
static int* TCP_NNTP_PORT_SERVICE_MODEL = NUMBER_119_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp network time protocol port service model. */
static int* TCP_NTP_PORT_SERVICE_MODEL = NUMBER_123_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp network time protocol port service model. */
static int* UDP_NTP_PORT_SERVICE_MODEL = NUMBER_123_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp pwdgen port service model. */
static int* TCP_PWDGEN_PORT_SERVICE_MODEL = NUMBER_129_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp pwdgen port service model. */
static int* UDP_PWDGEN_PORT_SERVICE_MODEL = NUMBER_129_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp location port service model. */
static int* TCP_LOC_SRV_PORT_SERVICE_MODEL = NUMBER_135_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp location port service model. */
static int* UDP_LOC_SRV_PORT_SERVICE_MODEL = NUMBER_135_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp netbios name port service model. */
static int* TCP_NETBIOS_NS_PORT_SERVICE_MODEL = NUMBER_137_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp netbios name port service model. */
static int* UDP_NETBIOS_NS_PORT_SERVICE_MODEL = NUMBER_137_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp netbios datagram port service model. */
static int* TCP_NETBIOS_DGM_PORT_SERVICE_MODEL = NUMBER_138_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp netbios datagram port service model. */
static int* UDP_NETBIOS_DGM_PORT_SERVICE_MODEL = NUMBER_138_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp netbios session port service model. */
static int* TCP_NETBIOS_SSN_PORT_SERVICE_MODEL = NUMBER_139_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp netbios session port service model. */
static int* UDP_NETBIOS_SSN_PORT_SERVICE_MODEL = NUMBER_139_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp interim mail access protocol 2 and 4 port service model. */
static int* TCP_IMAP2_PORT_SERVICE_MODEL = NUMBER_143_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp interim mail access protocol 2 and 4 port service model. */
static int* UDP_IMAP2_PORT_SERVICE_MODEL = NUMBER_143_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp single net managment protocol port service model. */
static int* TCP_SNMP_PORT_SERVICE_MODEL = NUMBER_161_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp single net managment protocol port service model. */
static int* UDP_SNMP_PORT_SERVICE_MODEL = NUMBER_161_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp traps for snmp port service model. */
static int* TCP_SNMP_TRAP_PORT_SERVICE_MODEL = NUMBER_162_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp traps for snmp port service model. */
static int* UDP_SNMP_TRAP_PORT_SERVICE_MODEL = NUMBER_162_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp iso managment over ip port service model. */
static int* TCP_CMIP_MAN_PORT_SERVICE_MODEL = NUMBER_163_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp iso managment over ip port service model. */
static int* UDP_CMIP_MAN_PORT_SERVICE_MODEL = NUMBER_163_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp iso managment over ip agent port service model. */
static int* TCP_CMIP_AGENT_PORT_SERVICE_MODEL = NUMBER_164_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp iso managment over ip agent port service model. */
static int* UDP_CMIP_AGENT_PORT_SERVICE_MODEL = NUMBER_164_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp mailer transport queue for zmailer port service model. */
static int* TCP_MAILQ_PORT_SERVICE_MODEL = NUMBER_174_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp mailer transport queue for zmailer port service model. */
static int* UDP_MAILQ_PORT_SERVICE_MODEL = NUMBER_174_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp x display manager control protocol port service model. */
static int* TCP_XDMCP_PORT_SERVICE_MODEL = NUMBER_177_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp x display manager control protocol port service model. */
static int* UDP_XDMCP_PORT_SERVICE_MODEL = NUMBER_177_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp nextstep window port service model. */
static int* TCP_NEXTSTEP_PORT_SERVICE_MODEL = NUMBER_178_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp nextstep window port service model. */
static int* UDP_NEXTSTEP_PORT_SERVICE_MODEL = NUMBER_178_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp border gateway protocol port service model. */
static int* TCP_BGP_PORT_SERVICE_MODEL = NUMBER_179_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp border gateway protocol port service model. */
static int* UDP_BGP_PORT_SERVICE_MODEL = NUMBER_179_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp cliff neuman's prospero port service model. */
static int* TCP_PROSPERO_PORT_SERVICE_MODEL = NUMBER_191_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp cliff neuman's prospero port service model. */
static int* UDP_PROSPERO_PORT_SERVICE_MODEL = NUMBER_191_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp internet relay chat port service model. */
static int* TCP_IRC_PORT_SERVICE_MODEL = NUMBER_194_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp internet relay chat port service model. */
static int* UDP_IRC_PORT_SERVICE_MODEL = NUMBER_194_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp snmp unix multiplexer port service model. */
static int* TCP_SMUX_PORT_SERVICE_MODEL = NUMBER_199_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp snmp unix multiplexer port service model. */
static int* UDP_SMUX_PORT_SERVICE_MODEL = NUMBER_199_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp appletalk routing port service model. */
static int* TCP_AT_RTMP_PORT_SERVICE_MODEL = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp appletalk routing port service model. */
static int* UDP_AT_RTMP_PORT_SERVICE_MODEL = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp appletalk name binding port service model. */
static int* TCP_AT_NBP_PORT_SERVICE_MODEL = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp appletalk name binding port service model. */
static int* UDP_AT_NBP_PORT_SERVICE_MODEL = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp appletalk echo port service model. */
static int* TCP_AT_ECHO_PORT_SERVICE_MODEL = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp appletalk echo port service model. */
static int* UDP_AT_ECHO_PORT_SERVICE_MODEL = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp appletalk zone information port service model. */
static int* TCP_AT_ZIS_PORT_SERVICE_MODEL = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp appletalk zone information port service model. */
static int* UDP_AT_ZIS_PORT_SERVICE_MODEL = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp quick mail transfer protocol port service model. */
static int* TCP_QMTP_PORT_SERVICE_MODEL = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp quick mail transfer protocol port service model. */
static int* UDP_QMTP_PORT_SERVICE_MODEL = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp niso z39.50 database port service model. */
static int* TCP_Z3950_PORT_SERVICE_MODEL = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp niso z39.50 database port service model. */
static int* UDP_Z3950_PORT_SERVICE_MODEL = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp icp port service model. */
static int* TCP_IPX_PORT_SERVICE_MODEL = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp icp port service model. */
static int* UDP_IPX_PORT_SERVICE_MODEL = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp interactive mail access port service model. */
static int* TCP_IMAP3_PORT_SERVICE_MODEL = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp interactive mail access port service model. */
static int* UDP_IMAP3_PORT_SERVICE_MODEL = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp perf analysis workbench port service model. */
static int* TCP_PAWSERV_PORT_SERVICE_MODEL = NUMBER_345_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp perf analysis workbench port service model. */
static int* UDP_PAWSERV_PORT_SERVICE_MODEL = NUMBER_345_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp zebra server port service model. */
static int* TCP_ZSERV_PORT_SERVICE_MODEL = NUMBER_346_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp zebra server port service model. */
static int* UDP_ZSERV_PORT_SERVICE_MODEL = NUMBER_346_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp fatmen server port service model. */
static int* TCP_FATSERV_PORT_SERVICE_MODEL = NUMBER_347_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp fatmen server port service model. */
static int* UDP_FATSERV_PORT_SERVICE_MODEL = NUMBER_347_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp coda portmapper port service model. */
static int* TCP_RPC2PORTMAP_PORT_SERVICE_MODEL = NUMBER_369_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp coda portmapper port service model. */
static int* UDP_RPC2PORTMAP_PORT_SERVICE_MODEL = NUMBER_369_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp coda authentication server port service model. */
static int* TCP_CODAAUTH2_PORT_SERVICE_MODEL = NUMBER_370_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp coda authentication server port service model. */
static int* UDP_CODAAUTH2_PORT_SERVICE_MODEL = NUMBER_370_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp clearcase port service model. */
static int* TCP_CLEARCASE_PORT_SERVICE_MODEL = NUMBER_371_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp clearcase port service model. */
static int* UDP_CLEARCASE_PORT_SERVICE_MODEL = NUMBER_371_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp unix listserv port service model. */
static int* TCP_ULISTSERV_PORT_SERVICE_MODEL = NUMBER_371_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp unix listserv port service model. */
static int* UDP_ULISTSERV_PORT_SERVICE_MODEL = NUMBER_371_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp lightweight directory access protocol port service model. */
static int* TCP_LDAP_PORT_SERVICE_MODEL = NUMBER_389_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp lightweight directory access protocol port service model. */
static int* UDP_LDAP_PORT_SERVICE_MODEL = NUMBER_389_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp interactive mail support protocol port service model. */
static int* TCP_IMSP_PORT_SERVICE_MODEL = NUMBER_406_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp interactive mail support protocol port service model. */
static int* UDP_IMSP_PORT_SERVICE_MODEL = NUMBER_406_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp server location port service model. */
static int* TCP_SVRLOC_PORT_SERVICE_MODEL = NUMBER_427_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp server location port service model. */
static int* UDP_SVRLOC_PORT_SERVICE_MODEL = NUMBER_427_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp hypertext transfer protocol over tls/ ssl (https) port service model. */
static int* TCP_HTTPS_PORT_SERVICE_MODEL = NUMBER_443_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp hypertext transfer protocol over tls/ ssl (https) port service model. */
static int* UDP_HTTPS_PORT_SERVICE_MODEL = NUMBER_443_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp simple network paging protocol port service model. */
static int* TCP_SNPP_PORT_SERVICE_MODEL = NUMBER_444_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp simple network paging protocol port service model. */
static int* UDP_SNPP_PORT_SERVICE_MODEL = NUMBER_444_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp microsoft naked cifs port service model. */
static int* TCP_MICROSOFT_DS_PORT_SERVICE_MODEL = NUMBER_445_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp microsoft naked cifs port service model. */
static int* UDP_MICROSOFT_DS_PORT_SERVICE_MODEL = NUMBER_445_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp kpasswd port service model. */
static int* TCP_KPASSWD_PORT_SERVICE_MODEL = NUMBER_464_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udü kpasswd port service model. */
static int* UDP_KPASSWD_PORT_SERVICE_MODEL = NUMBER_464_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp simple asynchronous file transfer port service model. */
static int* TCP_SAFT_PORT_SERVICE_MODEL = NUMBER_487_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp simple asynchronous file transfer port service model. */
static int* UDP_SAFT_PORT_SERVICE_MODEL = NUMBER_487_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp ipsec internet security association port service model. */
static int* TCP_ISAKMP_PORT_SERVICE_MODEL = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp ipsec internet security association port service model. */
static int* UDP_ISAKMP_PORT_SERVICE_MODEL = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp real time stream control protocol port service model. */
static int* TCP_RTSP_PORT_SERVICE_MODEL = NUMBER_554_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp real time stream control protocol port service model. */
static int* UDP_RTSP_PORT_SERVICE_MODEL = NUMBER_554_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp network queuing system port service model. */
static int* TCP_NQS_PORT_SERVICE_MODEL = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp network queuing system port service model. */
static int* UDP_NQS_PORT_SERVICE_MODEL = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp npmp local DQS port service model. */
static int* TCP_NPMP_LOCAL_PORT_SERVICE_MODEL = NUMBER_610_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp npmp local DQS port service model. */
static int* UDP_NPMP_LOCAL_PORT_SERVICE_MODEL = NUMBER_610_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp npmp gui DQS port service model. */
static int* TCP_NPMP_GUI_PORT_SERVICE_MODEL = NUMBER_611_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp npmp gui DQS port service model. */
static int* UDP_NPMP_GUI_PORT_SERVICE_MODEL = NUMBER_611_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp hmmp indication DQS port service model. */
static int* TCP_HMMP_IND_PORT_SERVICE_MODEL = NUMBER_612_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp hmmp indication DQS port service model. */
static int* UDP_HMMP_IND_PORT_SERVICE_MODEL = NUMBER_612_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp qmqp port service model. */
static int* TCP_QMQP_PORT_SERVICE_MODEL = NUMBER_628_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp qmqp port service model. */
static int* UDP_QMQP_PORT_SERVICE_MODEL = NUMBER_628_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet printing protocol port service model. */
static int* TCP_IPP_PORT_SERVICE_MODEL = NUMBER_631_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// UNIX specific services
//

/** The tcp exec port service model. */
static int* TCP_EXEC_PORT_SERVICE_MODEL = NUMBER_512_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp comsat biff port service model. */
static int* UDP_BIFF_PORT_SERVICE_MODEL = NUMBER_512_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp login port service model. */
static int* TCP_LOGIN_PORT_SERVICE_MODEL = NUMBER_513_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp who port service model. */
static int* UDP_WHO_PORT_SERVICE_MODEL = NUMBER_513_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp shell port service model. */
static int* TCP_SHELL_PORT_SERVICE_MODEL = NUMBER_514_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp syslog port service model. */
static int* UDP_SYSLOG_PORT_SERVICE_MODEL = NUMBER_514_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp line printer spooler port service model. */
static int* TCP_PRINTER_PORT_SERVICE_MODEL = NUMBER_515_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp talk port service model. */
static int* UDP_TALK_PORT_SERVICE_MODEL = NUMBER_517_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp ntalk port service model. */
static int* UDP_NTALK_PORT_SERVICE_MODEL = NUMBER_518_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp route port service model. */
static int* UDP_ROUTE_PORT_SERVICE_MODEL = NUMBER_520_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp time server port service model. */
static int* UDP_TIMED_PORT_SERVICE_MODEL = NUMBER_525_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp tempo port service model. */
static int* TCP_TEMPO_PORT_SERVICE_MODEL = NUMBER_526_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp rpc courier port service model. */
static int* TCP_COURIER_PORT_SERVICE_MODEL = NUMBER_530_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp conference chat port service model. */
static int* TCP_CONFERENCE_PORT_SERVICE_MODEL = NUMBER_531_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp readnews netnews port service model. */
static int* TCP_NETNEWS_PORT_SERVICE_MODEL = NUMBER_532_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp netwall for emergency broadcasts port service model. */
static int* UDP_NETWALL_PORT_SERVICE_MODEL = NUMBER_533_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp gnustep distributed objects port service model. */
static int* TCP_GDOMAP_PORT_SERVICE_MODEL = NUMBER_538_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp gnustep distributed objects port service model. */
static int* UDP_GDOMAP_PORT_SERVICE_MODEL = NUMBER_538_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp uucp daemon port service model. */
static int* TCP_UUCP_PORT_SERVICE_MODEL = NUMBER_540_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberized rlogin v5 port service model. */
static int* TCP_KLOGIN_PORT_SERVICE_MODEL = NUMBER_543_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberized rsh v5 port service model. */
static int* TCP_KSHELL_PORT_SERVICE_MODEL = NUMBER_544_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp dhcp v6 client port service model. */
static int* TCP_DHCPV6_CLIENT_PORT_SERVICE_MODEL = NUMBER_546_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp dhcp v6 client port service model. */
static int* UDP_DHCPV6_CLIENT_PORT_SERVICE_MODEL = NUMBER_546_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp dhcp v6 server port service model. */
static int* TCP_DHCP6_SERVER_PORT_SERVICE_MODEL = NUMBER_547_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp dhcp v6 server port service model. */
static int* UDP_DHCP6_SERVER_PORT_SERVICE_MODEL = NUMBER_547_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp afp over tcp port service model. */
static int* TCP_AFPOVERTCP_PORT_SERVICE_MODEL = NUMBER_548_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp afp over tcp port service model. */
static int* UDP_AFPOVERTCP_PORT_SERVICE_MODEL = NUMBER_548_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp idfp port service model. */
static int* TCP_IDFP_PORT_SERVICE_MODEL = NUMBER_549_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp idfp port service model. */
static int* UDP_IDFP_PORT_SERVICE_MODEL = NUMBER_549_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp brunhoff remote filesystem port service model. */
static int* TCP_REMOTEFS_PORT_SERVICE_MODEL = NUMBER_556_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp nntp over ssl port service model. */
static int* TCP_NNTPS_PORT_SERVICE_MODEL = NUMBER_563_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp nntp over ssl port service model. */
static int* UDP_NNTPS_PORT_SERVICE_MODEL = NUMBER_563_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp submission port service model. */
static int* TCP_SUBMISSION_PORT_SERVICE_MODEL = NUMBER_587_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp submission port service model. */
static int* UDP_SUBMISSION_PORT_SERVICE_MODEL = NUMBER_587_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp ldap over ssl port service model. */
static int* TCP_LDAPS_PORT_SERVICE_MODEL = NUMBER_636_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp ldap over ssl port service model. */
static int* UDP_LDAPS_PORT_SERVICE_MODEL = NUMBER_636_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp tinc control port port service model. */
static int* TCP_TINC_PORT_SERVICE_MODEL = NUMBER_655_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp tinc control port port service model. */
static int* UDP_TINC_PORT_SERVICE_MODEL = NUMBER_655_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp silc port service model. */
static int* TCP_SILC_PORT_SERVICE_MODEL = NUMBER_706_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp silc port service model. */
static int* UDP_SILC_PORT_SERVICE_MODEL = NUMBER_706_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp kerberos kadmin v5 port service model. */
static int* TCP_KERBEROS_ADM_PORT_SERVICE_MODEL = NUMBER_749_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp network dictionary webster port service model. */
static int* TCP_WEBSTER_PORT_SERVICE_MODEL = NUMBER_765_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp network dictionary webster port service model. */
static int* UDP_WEBSTER_PORT_SERVICE_MODEL = NUMBER_765_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp rsync port service model. */
static int* TCP_RSYNC_PORT_SERVICE_MODEL = NUMBER_873_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp rsync port service model. */
static int* UDP_RSYNC_PORT_SERVICE_MODEL = NUMBER_873_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp ftp over ssl data port service model. */
static int* TCP_FTPS_DATA_PORT_SERVICE_MODEL = NUMBER_989_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp ftp over ssl port service model. */
static int* TCP_FTPS_PORT_SERVICE_MODEL = NUMBER_990_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp telnet over ssl port service model. */
static int* TCP_TELNETS_PORT_SERVICE_MODEL = NUMBER_992_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp telnet over ssl port service model. */
static int* UDP_TELNETS_PORT_SERVICE_MODEL = NUMBER_992_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp imap over ssl port service model. */
static int* TCP_IMAPS_PORT_SERVICE_MODEL = NUMBER_993_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp imap over ssl port service model. */
static int* UDP_IMAPS_PORT_SERVICE_MODEL = NUMBER_993_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp irc over sll port service model. */
static int* TCP_IRCS_PORT_SERVICE_MODEL = NUMBER_994_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp irc over sll port service model. */
static int* UDP_IRCS_PORT_SERVICE_MODEL = NUMBER_994_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp pop3 over ssl port service model. */
static int* TCP_POP3S_PORT_SERVICE_MODEL = NUMBER_995_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp pop3 over ssl port service model. */
static int* UDP_POP3S_PORT_SERVICE_MODEL = NUMBER_995_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tcp cybernetics oriented interpreter (cyboi) port service model. */
static int* TCP_CYBOI_PORT_SERVICE_MODEL = NUMBER_1971_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The udp cybernetics oriented interpreter (cyboi) port service model. */
static int* UDP_CYBOI_PORT_SERVICE_MODEL = NUMBER_1971_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PORT_SERVICE_MODEL_CONSTANT_SOURCE */
#endif
