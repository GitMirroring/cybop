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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RULE_XDT_FORMAT_CONSTANT_SOURCE
#define RULE_XDT_FORMAT_CONSTANT_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Format checking rules.
//

/**
 * The hhmm rule xdt type.
 *
 * HH: Stunde
 * MM: Minute
 *
 * Possible values: 0000-2359
 */
static int* HHMM_RULE_XDT_FORMAT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hhmmhhmm rule xdt type.
 *
 * HH: Stunde
 * MM: Minute
 */
static int* HHMMHHMM_RULE_XDT_FORMAT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The jjmmnnn rule xdt type.
 *
 * JJ: Jahr
 * MM: Monat
 * NNN: laufende Nummer
 */
static int* JJMMNNN_RULE_XDT_FORMAT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ttmmjjjj rule xdt type.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJ_RULE_XDT_FORMAT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The mmjj rule xdt type.
 *
 * MM: Monat
 * JJ: Jahr
 */
static int* MMJJ_RULE_XDT_FORMAT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The arztname zuordnungszeichen rule xdt type.
 *
 * Possible values: 0-9, A-Z, #, $, <, >, *
 */
static int* ARZTNAME_ZUORDNUNGSZEICHEN_RULE_XDT_FORMAT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The qjjjj rule xdt type.
 *
 * Q: Quartal
 * JJJJ: Jahr
 */
static int* QJJJJ_RULE_XDT_FORMAT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The vknr rule xdt type.
 *
 * Format: nnnnn
 */
static int* VKNR_RULE_XDT_FORMAT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The krankenkassennummer rule xdt type.
 *
 * Format: nnnnnnn
 */
static int* KRANKENKASSENNUMMER_RULE_XDT_FORMAT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ttmmjjjjttmmjjjj rule xdt type.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJTTMMJJJJ_RULE_XDT_FORMAT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The ttmmjjjj rule xdt type.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 *
 * Possible values:
 * TT=00-31
 * MM=00-12
 * JJJJ=0000-9999
 */
static int* TTMMJJJJ_BESCHRAENKT_RULE_XDT_FORMAT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Content checking rules.
//

/**
 * The feld angekreuzt rule xdt type.
 *
 * Possible values: 1
 *
 * Description:
 * 1: Feld angekreuzt/ vorhanden
 */
static int* FELD_ANGEKREUZT_RULE_XDT_FORMAT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Existence checking rules.
//

/**
 * The kassendatei vknr vorhanden rule xdt type.
 *
 * VKNR vorhanden und 5-stellig
 */
static int* KASSENDATEI_VKNR_VORHANDEN_RULE_XDT_FORMAT = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Context checking rules.
//

/**
 * The datum kleiner oder gleich maschinendatum rule xdt type.
 */
static int* DATUM_KLEINER_ODER_GLEICH_MASCHINENDATUM_RULE_XDT_FORMAT = NUMBER_304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RULE_XDT_FORMAT_CONSTANT_SOURCE */
#endif
