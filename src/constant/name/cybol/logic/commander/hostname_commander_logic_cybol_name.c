/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
* The DNS Hostname logic cybol name.
*
*/
static wchar_t DNS_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'd', L'n', L's'};
static wchar_t* DNS_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME = DNS_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* DNS_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The FQDN Hostname logic cybol name.
*
*/
static wchar_t FQDN_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'f', L'q', L'd', L'n'};
static wchar_t* FQDN_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME = FQDN_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* FQDN_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The ip adress for the hostname logic cybol name.
*
* It shows the ip Adress.
*/
static wchar_t IP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'i', L'p'};
static wchar_t* IP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME = IP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* IP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The all ip adress for the hostname logic cybol name.
*
* It shows all ip Adresses.
*/
static wchar_t ALLIP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'a', L'l',L'l', L'i',L'p'};
static wchar_t* ALLIP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME = ALLIP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* ALLIP_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The short for the hostname logic cybol name.
*
* It shows short hostname.
*/
static wchar_t SHORT_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'h',L'o', L'r',L't'};
static wchar_t* SHORT_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME = SHORT_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* SHORT_HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/* HOSTNAME_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif

