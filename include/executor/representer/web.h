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

#ifndef WEB_HEADER
#define WEB_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/cybol/http/request_http_cybol_model.h"

#include "constant/model/cybol/socket/address_socket_cybol_model.h"
#include "constant/model/cybol/socket/mode_socket_cybol_model.h"
#include "constant/model/cybol/socket/namespace_socket_cybol_model.h"
#include "constant/model/cybol/socket/protocol_socket_cybol_model.h"
#include "constant/model/cybol/socket/service_socket_cybol_model.h"
#include "constant/model/cybol/socket/style_socket_cybol_model.h"

#include "constant/model/http/protocol_version_http_model.h"
#include "constant/model/http/request_method_http_model.h"
#include "constant/model/http/status_code_http_model.h"
#include "constant/model/http/webdav_request_method_http_model.h"

#include "constant/model/uri/scheme_uri_model.h"
#include "constant/model/uri/separator_uri_model.h"

//
// name
//

#include "constant/name/authority/separator_authority_name.h"

#include "constant/name/cyboi/authority/authority_cyboi_name.h"

#include "constant/name/cyboi/http/header/entity_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/general_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/request_header_http_cyboi_name.h"
#include "constant/name/cyboi/http/header/response_header_http_cyboi_name.h"

#include "constant/name/cyboi/http/header_http_cyboi_name.h"
#include "constant/name/cyboi/http/http_cyboi_name.h"
#include "constant/name/cyboi/http/variable_http_cyboi_name.h"

#include "constant/name/cyboi/uri/uri_cyboi_name.h"

#include "constant/name/ftp/separator_ftp_name.h"

#include "constant/name/http/header/entity_header_http_name.h"
#include "constant/name/http/header/general_header_http_name.h"
#include "constant/name/http/header/request_header_http_name.h"
#include "constant/name/http/header/response_header_http_name.h"

#include "constant/name/http_request_uri/http_request_uri_name.h"

#include "constant/name/http/header_http_name.h"
#include "constant/name/http/separator_http_name.h"
#include "constant/name/http/variable_http_name.h"

#include "constant/name/uri/separator_uri_name.h"

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// authority
//

void deserialise_authority(void* p0, void* p1, void* p2, void* p3);
void deserialise_authority_hostname(void* p0, void* p1, void* p2, void* p3);
void deserialise_authority_password(void* p0, void* p1, void* p2, void* p3);
void deserialise_authority_port(void* p0, void* p1, void* p2, void* p3);
void deserialise_authority_userinfo(void* p0, void* p1, void* p2, void* p3);
void deserialise_authority_username(void* p0, void* p1, void* p2, void* p3);

void select_authority_hostname(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_authority_password(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_authority_port(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_authority_userinfo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_authority_username(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// blank line
//

void deserialise_blank_line_termination(void* p0, void* p1, void* p2);
void deserialise_blank_line_termination_data(void* p0, void* p1, void* p2);

void select_blank_line_termination(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// ftp
//

void deserialise_ftp_line_end(void* p0, void* p1, void* p2);
void deserialise_ftp_line_end_data(void* p0, void* p1, void* p2);

void select_ftp_line_end(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// host address
//

void deserialise_host_address_inet(void* p0, void* p1, void* p2);
void deserialise_host_address_inet6(void* p0, void* p1, void* p2);

//
// http request
//

void deserialise_http_request(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_body(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_header_argument(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_http_request_method(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_protocol(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_uri(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_request_uri_content(void* p0, void* p1, void* p2);

void select_http_request_content_length_header(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_http_request_content_length_value(void* p0, void* p1, void* p2, void* p3);
void select_http_request_header_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void select_http_request_header_field(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_request_protocol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

void serialise_http_request(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// http request content length
//

void deserialise_http_request_content_length(void* p0, void* p1, void* p2);
void deserialise_http_request_content_length_header(void* p0, void* p1, void* p2);
void deserialise_http_request_content_length_value(void* p0, void* p1, void* p2);

//
// http request message length
//

void deserialise_http_request_message_length(void* p0, void* p1, void* p2);

//
// http request uri
//

void deserialise_absolute_path_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_absolute_uri_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_authority_form_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_no_resource_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);

void select_absolute_path_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_absolute_uri_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_authority_form_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_no_resource_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// http response
//

void deserialise_http_response(void* p0, void* p1, void* p2, void* p3);

void select_http_response_header_entry(void* p0, void* p1, void* p2, void* p3, void* p4);

void serialise_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_http_response_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_http_response_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_http_response_header_content_length(void* p0, void* p1);
void serialise_http_response_header_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_http_response_header_entry_encode(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_http_response_protocol(void* p0);
void serialise_http_response_status_code(void* p0);

//
// message length
//

void deserialise_message_length(void* p0, void* p1, void* p2, void* p3);

//
// network service
//

void deserialise_network_service(void* p0, void* p1, void* p2);
void serialise_network_service(void* p0, void* p1);

//
// socket
//

void deserialise_socket_family_address(void* p0, void* p1, void* p2);
void deserialise_socket_family_protocol(void* p0, void* p1, void* p2);
void deserialise_socket_protocol(void* p0, void* p1, void* p2);
void deserialise_socket_style(void* p0, void* p1, void* p2);

//
// uri
//

void deserialise_http_uri(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_authority(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_authority_content(void* p0, void* p1, void* p2);
void deserialise_http_uri_fragment(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_path(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_query(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_query_content(void* p0, void* p1, void* p2);
void deserialise_http_uri_query_parametre(void* p0, void* p1, void* p2, void* p3);
void deserialise_http_uri_query_parametre_name(void* p0, void* p1, void* p2, void* p3);
void deserialise_uri(void* p0, void* p1, void* p2, void* p3);
void deserialise_uri_scheme(void* p0, void* p1, void* p2, void* p3);

void select_http_uri_authority(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_uri_fragment(void* p0, void* p1, void* p2);
void select_http_uri_path(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_uri_query(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_uri_query_parametre(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_http_uri_query_parametre_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void select_uri_scheme(void* p0, void* p1, void* p2, void* p3);

//
// web dav
//

//?? TODO

/* WEB_HEADER */
#endif
