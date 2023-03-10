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
 * @author Enrico Gallus <enrico.gallus@googlemail.com>
 */

#ifndef PORT_SERVICE_MODEL_CONSTANT_HEADER
#define PORT_SERVICE_MODEL_CONSTANT_HEADER

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// IANA assigned ports.
//
// Sorted here by their assigned number.
//

/** The service multiplexer port service model. */
static int* MUX_PORT_SERVICE_MODEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo port service model (identical for tcp and udp). */
static int* ECHO_PORT_SERVICE_MODEL = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The discard (sink null) port service model (identical for tcp and udp). */
static int* DISCARD_PORT_SERVICE_MODEL = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The systat (user) port service model. */
static int* SYSTAT_PORT_SERVICE_MODEL = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The daytime port service model (identical for tcp and udp). */
static int* DAYTIME_PORT_SERVICE_MODEL = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netstat port service model. */
static int* NETSTAT_PORT_SERVICE_MODEL = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The qotd (quote) port service model. */
static int* QOTD_PORT_SERVICE_MODEL = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The message send protocol port service model (identical for tcp and udp). */
static int* MSP_PORT_SERVICE_MODEL = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ttytst source port service model (identical for tcp and udp). */
static int* CHARGEN_PORT_SERVICE_MODEL = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file transfer protocol (ftp) data port service model. */
static int* FTP_DATA_PORT_SERVICE_MODEL = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file transfer protocol (ftp) port service model (identical for tcp and udp). */
static int* FTP_PORT_SERVICE_MODEL = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The secure shell (ssh) remote login protocol port service model (identical for tcp and udp). */
static int* SSH_PORT_SERVICE_MODEL = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The telnet port service model. */
static int* TELNET_PORT_SERVICE_MODEL = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mail transfer protocol (smtp) port service model. */
static int* SMTP_PORT_SERVICE_MODEL = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The timeserver protocol port service model (identical for tcp and udp). */
static int* TIME_PORT_SERVICE_MODEL = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ressource location port service model. */
static int* RLP_PORT_SERVICE_MODEL = NUMBER_39_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nameserver port service model. */
static int* NAMESERVER_PORT_SERVICE_MODEL = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nicname port service model. */
static int* WHOIS_PORT_SERVICE_MODEL = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The login host protocol (tacacs) port service model (identical for tcp and udp). */
static int* TACACS_PORT_SERVICE_MODEL = NUMBER_49_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remote mail checking protocol port service model (identical for tcp and udp). */
static int* RE_MAIL_CK_PORT_SERVICE_MODEL = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The name domain server port service model (identical for tcp and udp). */
static int* DOMAIN_PORT_SERVICE_MODEL = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mtp service model. (deprecated) */
static int* MTP_PORT_SERVICE_MODEL = NUMBER_57_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tacacs database port service model (identical for tcp and udp). */
static int* TACACS_DS_PORT_SERVICE_MODEL = NUMBER_65_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bootp server port service model (identical for tcp and udp). */
static int* BOOTPS_PORT_SERVICE_MODEL = NUMBER_67_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bootp client port service model (identical for tcp and udp). */
static int* BOOTPC_PORT_SERVICE_MODEL = NUMBER_68_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file transfer protocol port service model. */
static int* TFTP_PORT_SERVICE_MODEL = NUMBER_69_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet gopher port service model (identical for tcp and udp). */
static int* GOPHER_PORT_SERVICE_MODEL = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The net rjs port service model. */
static int* RJE_PORT_SERVICE_MODEL = NUMBER_77_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The finger port service model. */
static int* FINGER_PORT_SERVICE_MODEL = NUMBER_79_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The world wide web (www) hypertext transfer protocol (http) port service model (identical for tcp and udp). */
static int* HTTP_PORT_SERVICE_MODEL = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tty link port service model. */
static int* LINK_PORT_SERVICE_MODEL = NUMBER_87_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberos port service model (identical for tcp and udp). */
static int* KERBEROS_PORT_SERVICE_MODEL = NUMBER_88_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The supdup port service model. */
static int* SUPDUP_PORT_SERVICE_MODEL = NUMBER_95_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hostname port service model. */
static int* HOSTNAME_PORT_SERVICE_MODEL = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-tsap as part of the ISODE port service model. */
static int* ISO_TSAP_PORT_SERVICE_MODEL = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The acr-nema of the company Digital Imag. & Comm. 300 port service model (identical for tcp and udp). */
static int* ACR_NEMA_PORT_SERVICE_MODEL = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The csnet nameserver port service model (identical for tcp and udp). */
static int* CSNET_NS_PORT_SERVICE_MODEL = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remote telnet port service model (identical for tcp and udp). */
static int* RTELNET_PORT_SERVICE_MODEL = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The postoffice pop 2 port service model (identical for tcp and udp). */
static int* POP2_PORT_SERVICE_MODEL = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The post office protocol version 3 (pop3) port service model (identical for tcp and udp). */
static int* POP3_PORT_SERVICE_MODEL = NUMBER_110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rpc 4.0 portmapper port service model (identical for tcp and udp). */
static int* SUNRPC_PORT_SERVICE_MODEL = NUMBER_111_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The authentication tap ident port service model. */
static int* AUTH_PORT_SERVICE_MODEL = NUMBER_113_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The secure file transfer protocol port service model. */
static int* SFTP_PORT_SERVICE_MODEL = NUMBER_115_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uucp-path port service model. */
static int* UUCP_PATH_PORT_SERVICE_MODEL = NUMBER_117_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The usenet new transfer protocol port service model. */
static int* NNTP_PORT_SERVICE_MODEL = NUMBER_119_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The network time protocol port service model (identical for tcp and udp). */
static int* NTP_PORT_SERVICE_MODEL = NUMBER_123_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pwdgen port service model (identical for tcp and udp). */
static int* PWDGEN_PORT_SERVICE_MODEL = NUMBER_129_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The location port service model (identical for tcp and udp). */
static int* LOC_SRV_PORT_SERVICE_MODEL = NUMBER_135_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netbios name port service model (identical for tcp and udp). */
static int* NETBIOS_NS_PORT_SERVICE_MODEL = NUMBER_137_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netbios datagram port service model (identical for tcp and udp). */
static int* NETBIOS_DGM_PORT_SERVICE_MODEL = NUMBER_138_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netbios session port service model (identical for tcp and udp). */
static int* NETBIOS_SSN_PORT_SERVICE_MODEL = NUMBER_139_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interim mail access protocol 2 and 4 port service model (identical for tcp and udp). */
static int* IMAP2_PORT_SERVICE_MODEL = NUMBER_143_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The single net managment protocol port service model (identical for tcp and udp). */
static int* SNMP_PORT_SERVICE_MODEL = NUMBER_161_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traps for snmp port service model (identical for tcp and udp). */
static int* SNMP_TRAP_PORT_SERVICE_MODEL = NUMBER_162_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso managment over ip port service model (identical for tcp and udp). */
static int* CMIP_MAN_PORT_SERVICE_MODEL = NUMBER_163_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso managment over ip agent port service model (identical for tcp and udp). */
static int* CMIP_AGENT_PORT_SERVICE_MODEL = NUMBER_164_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mailer transport queue for zmailer port service model (identical for tcp and udp). */
static int* MAILQ_PORT_SERVICE_MODEL = NUMBER_174_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x display manager control protocol port service model (identical for tcp and udp). */
static int* XDMCP_PORT_SERVICE_MODEL = NUMBER_177_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nextstep window port service model (identical for tcp and udp). */
static int* NEXTSTEP_PORT_SERVICE_MODEL = NUMBER_178_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The border gateway protocol port service model (identical for tcp and udp). */
static int* BGP_PORT_SERVICE_MODEL = NUMBER_179_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cliff neuman's prospero port service model (identical for tcp and udp). */
static int* PROSPERO_PORT_SERVICE_MODEL = NUMBER_191_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet relay chat port service model (identical for tcp and udp). */
static int* IRC_PORT_SERVICE_MODEL = NUMBER_194_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The snmp unix multiplexer port service model (identical for tcp and udp). */
static int* SMUX_PORT_SERVICE_MODEL = NUMBER_199_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appletalk routing port service model (identical for tcp and udp). */
static int* AT_RTMP_PORT_SERVICE_MODEL = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appletalk name binding port service model (identical for tcp and udp). */
static int* AT_NBP_PORT_SERVICE_MODEL = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appletalk echo port service model (identical for tcp and udp). */
static int* AT_ECHO_PORT_SERVICE_MODEL = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appletalk zone information port service model (identical for tcp and udp). */
static int* AT_ZIS_PORT_SERVICE_MODEL = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The quick mail transfer protocol port service model (identical for tcp and udp). */
static int* QMTP_PORT_SERVICE_MODEL = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The niso z39.50 database port service model (identical for tcp and udp). */
static int* Z3950_PORT_SERVICE_MODEL = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The icp port service model (identical for tcp and udp). */
static int* IPX_PORT_SERVICE_MODEL = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive mail access port service model (identical for tcp and udp). */
static int* IMAP3_PORT_SERVICE_MODEL = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The perf analysis workbench port service model (identical for tcp and udp). */
static int* PAWSERV_PORT_SERVICE_MODEL = NUMBER_345_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The zebra server port service model (identical for tcp and udp). */
static int* ZSERV_PORT_SERVICE_MODEL = NUMBER_346_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fatmen server port service model (identical for tcp and udp). */
static int* FATSERV_PORT_SERVICE_MODEL = NUMBER_347_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The coda portmapper port service model (identical for tcp and udp). */
static int* RPC2PORTMAP_PORT_SERVICE_MODEL = NUMBER_369_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The coda authentication server port service model (identical for tcp and udp). */
static int* CODAAUTH2_PORT_SERVICE_MODEL = NUMBER_370_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clearcase and unix listserv port service model (identical for tcp and udp). */
static int* CLEARCASE_PORT_SERVICE_MODEL = NUMBER_371_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The lightweight directory access protocol port service model (identical for tcp and udp). */
static int* LDAP_PORT_SERVICE_MODEL = NUMBER_389_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive mail support protocol port service model (identical for tcp and udp). */
static int* IMSP_PORT_SERVICE_MODEL = NUMBER_406_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server location port service model (identical for tcp and udp). */
static int* SVRLOC_PORT_SERVICE_MODEL = NUMBER_427_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hypertext transfer protocol over tls/ ssl (https) port service model (identical for tcp and udp). */
static int* HTTPS_PORT_SERVICE_MODEL = NUMBER_443_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The simple network paging protocol port service model (identical for tcp and udp). */
static int* SNPP_PORT_SERVICE_MODEL = NUMBER_444_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The microsoft naked cifs port service model (identical for tcp and udp). */
static int* MICROSOFT_DS_PORT_SERVICE_MODEL = NUMBER_445_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kpasswd port service model (identical for tcp and udp). */
static int* KPASSWD_PORT_SERVICE_MODEL = NUMBER_464_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The simple asynchronous file transfer port service model (identical for tcp and udp). */
static int* SAFT_PORT_SERVICE_MODEL = NUMBER_487_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ipsec internet security association port service model (identical for tcp and udp). */
static int* ISAKMP_PORT_SERVICE_MODEL = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The real time stream control protocol port service model (identical for tcp and udp). */
static int* RTSP_PORT_SERVICE_MODEL = NUMBER_554_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The network queuing system port service model (identical for tcp and udp). */
static int* NQS_PORT_SERVICE_MODEL = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The npmp local DQS port service model (identical for tcp and udp). */
static int* NPMP_LOCAL_PORT_SERVICE_MODEL = NUMBER_610_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The npmp gui DQS port service model (identical for tcp and udp). */
static int* NPMP_GUI_PORT_SERVICE_MODEL = NUMBER_611_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hmmp indication DQS port service model (identical for tcp and udp). */
static int* HMMP_IND_PORT_SERVICE_MODEL = NUMBER_612_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The qmqp port service model (identical for tcp and udp). */
static int* QMQP_PORT_SERVICE_MODEL = NUMBER_628_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internet printing protocol port service model. */
static int* IPP_PORT_SERVICE_MODEL = NUMBER_631_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// UNIX specific services
//

/** The exec port service model (identical for tcp and udp). */
static int* EXEC_PORT_SERVICE_MODEL = NUMBER_512_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The login port service model (identical for tcp and udp). */
static int* LOGIN_PORT_SERVICE_MODEL = NUMBER_513_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shell port service model (identical for tcp and udp). */
static int* SHELL_PORT_SERVICE_MODEL = NUMBER_514_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line printer spooler port service model. */
static int* PRINTER_PORT_SERVICE_MODEL = NUMBER_515_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The talk port service model. */
static int* TALK_PORT_SERVICE_MODEL = NUMBER_517_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ntalk port service model. */
static int* NTALK_PORT_SERVICE_MODEL = NUMBER_518_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The route port service model. */
static int* ROUTE_PORT_SERVICE_MODEL = NUMBER_520_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The time server port service model. */
static int* TIMED_PORT_SERVICE_MODEL = NUMBER_525_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tempo port service model. */
static int* TEMPO_PORT_SERVICE_MODEL = NUMBER_526_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rpc courier port service model. */
static int* COURIER_PORT_SERVICE_MODEL = NUMBER_530_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The conference chat port service model. */
static int* CONFERENCE_PORT_SERVICE_MODEL = NUMBER_531_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The readnews netnews port service model. */
static int* NETNEWS_PORT_SERVICE_MODEL = NUMBER_532_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netwall for emergency broadcasts port service model. */
static int* NETWALL_PORT_SERVICE_MODEL = NUMBER_533_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gnustep distributed objects port service model (identical for tcp and udp). */
static int* GDOMAP_PORT_SERVICE_MODEL = NUMBER_538_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uucp daemon port service model. */
static int* UUCP_PORT_SERVICE_MODEL = NUMBER_540_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberized rlogin v5 port service model. */
static int* KLOGIN_PORT_SERVICE_MODEL = NUMBER_543_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberized rsh v5 port service model. */
static int* KSHELL_PORT_SERVICE_MODEL = NUMBER_544_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dhcp v6 client port service model (identical for tcp and udp). */
static int* DHCPV6_CLIENT_PORT_SERVICE_MODEL = NUMBER_546_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dhcp v6 server port service model (identical for tcp and udp). */
static int* DHCP6_SERVER_PORT_SERVICE_MODEL = NUMBER_547_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The afp over tcp port service model (identical for tcp and udp). */
static int* AFPOVERTCP_PORT_SERVICE_MODEL = NUMBER_548_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The idfp port service model (identical for tcp and udp). */
static int* IDFP_PORT_SERVICE_MODEL = NUMBER_549_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The brunhoff remote filesystem port service model. */
static int* REMOTEFS_PORT_SERVICE_MODEL = NUMBER_556_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nntp over ssl port service model (identical for tcp and udp). */
static int* NNTPS_PORT_SERVICE_MODEL = NUMBER_563_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The submission port service model (identical for tcp and udp). */
static int* SUBMISSION_PORT_SERVICE_MODEL = NUMBER_587_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ldap over ssl port service model (identical for tcp and udp). */
static int* LDAPS_PORT_SERVICE_MODEL = NUMBER_636_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tinc control port port service model (identical for tcp and udp). */
static int* TINC_PORT_SERVICE_MODEL = NUMBER_655_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The silc port service model (identical for tcp and udp). */
static int* SILC_PORT_SERVICE_MODEL = NUMBER_706_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kerberos kadmin v5 port service model. */
static int* KERBEROS_ADM_PORT_SERVICE_MODEL = NUMBER_749_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The network dictionary webster port service model (identical for tcp and udp). */
static int* WEBSTER_PORT_SERVICE_MODEL = NUMBER_765_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rsync port service model (identical for tcp and udp). */
static int* RSYNC_PORT_SERVICE_MODEL = NUMBER_873_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ftp over ssl data port service model. */
static int* FTPS_DATA_PORT_SERVICE_MODEL = NUMBER_989_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ftp over ssl port service model. */
static int* FTPS_PORT_SERVICE_MODEL = NUMBER_990_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The telnet over ssl port service model (identical for tcp and udp). */
static int* TELNETS_PORT_SERVICE_MODEL = NUMBER_992_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imap over ssl port service model (identical for tcp and udp). */
static int* IMAPS_PORT_SERVICE_MODEL = NUMBER_993_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The irc over sll port service model (identical for tcp and udp). */
static int* IRCS_PORT_SERVICE_MODEL = NUMBER_994_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pop3 over ssl port service model (identical for tcp and udp). */
static int* POP3S_PORT_SERVICE_MODEL = NUMBER_995_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PORT_SERVICE_MODEL_CONSTANT_HEADER */
#endif
