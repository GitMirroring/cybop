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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// authority
//

#include "../../../executor/representer/deserialiser/authority/authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/hostname_authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/password_authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/port_authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/userinfo_authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/username_authority_deserialiser.c"

#include "../../../executor/selector/authority/hostname_authority_selector.c"
#include "../../../executor/selector/authority/password_authority_selector.c"
#include "../../../executor/selector/authority/port_authority_selector.c"
#include "../../../executor/selector/authority/userinfo_authority_selector.c"
#include "../../../executor/selector/authority/username_authority_selector.c"

//
// blank line
//

#include "../../../executor/representer/deserialiser/blank_line_termination/blank_line_termination_deserialiser.c"
#include "../../../executor/representer/deserialiser/blank_line_termination/data_blank_line_termination_deserialiser.c"

#include "../../../executor/selector/blank_line/termination_blank_line_selector.c"

//
// ftp
//

#include "../../../executor/representer/deserialiser/ftp_line_end/data_ftp_line_end_deserialiser.c"
#include "../../../executor/representer/deserialiser/ftp_line_end/ftp_line_end_deserialiser.c"

#include "../../../executor/selector/ftp_line_end/ftp_line_end_selector.c"

//
// host address
//

#include "../../../executor/representer/deserialiser/host_address/inet6_host_address_deserialiser.c"
#include "../../../executor/representer/deserialiser/host_address/inet_host_address_deserialiser.c"

//
// http request
//

#include "../../../executor/representer/deserialiser/http_request/body_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/content_uri_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/header_argument_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/header_value_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/method_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/protocol_http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/uri_http_request_deserialiser.c"

#include "../../../executor/selector/http_request/header_argument_http_request_selector.c"
#include "../../../executor/selector/http_request/header_field_http_request_selector.c"
#include "../../../executor/selector/http_request/header_value_http_request_selector.c"
#include "../../../executor/selector/http_request/method_http_request_selector.c"
#include "../../../executor/selector/http_request/protocol_http_request_selector.c"
#include "../../../executor/selector/http_request/uri_http_request_selector.c"
#include "../../../executor/selector/http_request_content_length/header_http_request_content_length_selector.c"
#include "../../../executor/selector/http_request_content_length/value_http_request_content_length_selector.c"

#include "../../../executor/representer/serialiser/http_request/http_request_serialiser.c"

//
// http request content length
//

#include "../../../executor/representer/deserialiser/http_request_content_length/header_http_request_content_length_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request_content_length/http_request_content_length_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request_content_length/value_http_request_content_length_deserialiser.c"

//
// http request message length
//

#include "../../../executor/representer/deserialiser/http_request_message_length/http_request_message_length_deserialiser.c"

//
// http request uri
//

#include "../../../executor/representer/deserialiser/http_request_uri/absolute_path_http_request_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request_uri/absolute_uri_http_request_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request_uri/authority_form_http_request_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request_uri/no_resource_http_request_uri_deserialiser.c"

#include "../../../executor/selector/http_request_uri/absolute_path_http_request_uri_selector.c"
#include "../../../executor/selector/http_request_uri/absolute_uri_http_request_uri_selector.c"
#include "../../../executor/selector/http_request_uri/authority_form_http_request_uri_selector.c"
#include "../../../executor/selector/http_request_uri/no_resource_http_request_uri_selector.c"

//
// http response
//

#include "../../../executor/representer/deserialiser/http_response/http_response_deserialiser.c"

#include "../../../executor/representer/serialiser/http_response/body_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/content_length_header_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/encode_header_entry_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/header_entry_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/header_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/protocol_http_response_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/status_code_http_response_serialiser.c"

#include "../../../executor/selector/http_response/header_entry_http_response_selector.c"

//
// message length
//

#include "../../../executor/representer/deserialiser/message_length/message_length_deserialiser.c"

//
// network service
//

#include "../../../executor/representer/deserialiser/network_service/network_service_deserialiser.c"
#include "../../../executor/representer/serialiser/network_service/network_service_serialiser.c"

//
// socket
//

#include "../../../executor/representer/deserialiser/socket/address_family_socket_deserialiser.c"
#include "../../../executor/representer/deserialiser/socket/protocol_family_socket_deserialiser.c"
#include "../../../executor/representer/deserialiser/socket/protocol_socket_deserialiser.c"
#include "../../../executor/representer/deserialiser/socket/style_socket_deserialiser.c"

//
// uri
//

#include "../../../executor/representer/deserialiser/uri/http/authority_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http/fragment_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http/name_parametre_query_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http/parametre_query_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http/path_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http/query_http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/http_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/scheme_uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/uri_deserialiser.c"

#include "../../../executor/selector/uri/http/authority_http_uri_selector.c"
#include "../../../executor/selector/uri/http/fragment_http_uri_selector.c"
#include "../../../executor/selector/uri/http/name_parametre_query_http_uri_selector.c"
#include "../../../executor/selector/uri/http/parametre_query_http_uri_selector.c"
#include "../../../executor/selector/uri/http/path_http_uri_selector.c"
#include "../../../executor/selector/uri/http/query_http_uri_selector.c"
#include "../../../executor/selector/uri/scheme_uri_selector.c"
#include "../../../executor/selector/uri/uri_selector.c"

//
// web dav
//

//?? TODO
