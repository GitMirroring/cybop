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
 */

#ifndef RECORD_XDT_NAME_CONSTANT_HEADER
#define RECORD_XDT_NAME_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// Communication
//

/** The communication header "0001" record xdt name. */
static wchar_t* COMMUNICATION_HEADER_RECORD_XDT_NAME = L"0001";
static int* COMMUNICATION_HEADER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The communication footer "0002" record xdt name. */
static wchar_t* COMMUNICATION_FOOTER_RECORD_XDT_NAME = L"0002";
static int* COMMUNICATION_FOOTER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// File
//

/** The file header "0020" record xdt name. */
static wchar_t* FILE_HEADER_RECORD_XDT_NAME = L"0020";
static int* FILE_HEADER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file footer "0021" record xdt name. */
static wchar_t* FILE_FOOTER_RECORD_XDT_NAME = L"0021";
static int* FILE_FOOTER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// BDT transfer
//

/** The referenced specification "spec" (Referenzierte Datensatzbeschreibungen) record xdt name. */
static wchar_t* REFERENCED_SPECIFICATION_RECORD_XDT_NAME = L"spec";
static int* REFERENCED_SPECIFICATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internal identifier "iden" (Vergabe BDT-interner Identifikatoren) record xdt name. */
static wchar_t* INTERNAL_IDENTIFIER_RECORD_XDT_NAME = L"iden";
static int* INTERNAL_IDENTIFIER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Medical practice
//

/** The medical practice "0010" (Praxisstammdaten) record xdt name. */
static wchar_t* MEDICAL_PRACTICE_RECORD_XDT_NAME = L"0010";
static int* MEDICAL_PRACTICE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The addresses "adrs" (Adressen) record xdt name. */
static wchar_t* ADDRESSES_RECORD_XDT_NAME = L"adrs";
static int* ADDRESSES_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appointments "term" (Termine) record xdt name. */
static wchar_t* APPOINTMENTS_RECORD_XDT_NAME = L"term";
static int* APPOINTMENTS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diagnosis abbreviations "diag" (Diagnosenkürzel) record xdt name. */
static wchar_t* DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME = L"diag";
static int* DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service numbers "grnk" (Ziffernketten für Leistungen) record xdt name. */
static wchar_t* SERVICE_NUMBERS_RECORD_XDT_NAME = L"grnk";
static int* SERVICE_NUMBERS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The prescription abbreviations "hapo" (Verordnungskürzel) record xdt name. */
static wchar_t* PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME = L"hapo";
static int* PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment blocks "bbst" (Behandlungsbausteine) record xdt name. */
static wchar_t* TREATMENT_BLOCKS_RECORD_XDT_NAME = L"bbst";
static int* TREATMENT_BLOCKS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The text blocks "text" (Kürzel Textbausteine) record xdt name. */
static wchar_t* TEXT_BLOCKS_RECORD_XDT_NAME = L"text";
static int* TEXT_BLOCKS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Patient and treatment
//

/** The patient "6100" (Administrative und medizinische Patientenstammblattdaten) record xdt name. */
static wchar_t* PATIENT_RECORD_XDT_NAME = L"6100";
static int* PATIENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment "6200" (Behandlungsdaten) record xdt name. */
static wchar_t* MEDICAL_TREATMENT_RECORD_XDT_NAME = L"6200";
static int* MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Billing [Abrechnungsnotizen (Behandlungsscheine)]
//
// 1 KVDT-Abrechnungen
//

/** The kvdt medical treatment "0101" (Ärztliche Behandlung) record xdt name. */
static wchar_t* KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME = L"0101";
static int* KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt referral case "0102" (Überweisungsfall) record xdt name. */
static wchar_t* KVDT_REFERRAL_CASE_RECORD_XDT_NAME = L"0102";
static int* KVDT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medical treatment with cottage hospital affiliation "0103" (Belegärztliche Behandlung) record xdt name. */
static wchar_t* KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME = L"0103";
static int* KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medical emergency service "0104" (Notfalldienst/Vertretung/Notfall) record xdt name. */
static wchar_t* KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME = L"0104";
static int* KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt medical treatment "sad1" (SADT-ambulante Behandlung) record xdt name. */
static wchar_t* KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME = L"sad1";
static int* KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt referral case "sad2" (SADT-Überweisung) record xdt name. */
static wchar_t* KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME = L"sad2";
static int* KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt medical treatment with cottage hospital affiliation "sad3" (SADT-Belegärztliche Behandlung) record xdt name. */
static wchar_t* KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME = L"sad3";
static int* KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt cure medical treatment "0109" (Kurärztliche Behandlung) record xdt name. */
static wchar_t* KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME = L"0109";
static int* KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt gevk "GEVK" (GEVK) record xdt name. */
static wchar_t* KVDT_GEVK_RECORD_XDT_NAME = L"GEVK";
static int* KVDT_GEVK_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt haevg "HÄVG" (HÄVG) record xdt name. */
static wchar_t* KVDT_HAEVG_RECORD_XDT_NAME = L"HÄVG";
static int* KVDT_HAEVG_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medi "MEDI" (MEDI) record xdt name. */
static wchar_t* KVDT_MEDI_RECORD_XDT_NAME = L"MEDI";
static int* KVDT_MEDI_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt kv "KV" (KV) record xdt name. */
static wchar_t* KVDT_KV_RECORD_XDT_NAME = L"KV";
static int* KVDT_KV_RECORD_XDT_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Billing [Abrechnungsnotizen (Behandlungsscheine)]
//
// 2 Privatabrechnung
//

/** The private billing "padx" (Privatabrechnung) record xdt name. */
static wchar_t* PRIVATE_BILLING_RECORD_XDT_NAME = L"padx";
static int* PRIVATE_BILLING_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RECORD_XDT_NAME_CONSTANT_HEADER */
#endif
