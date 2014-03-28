/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 */

#ifndef RECORD_XDT_NAME_CONSTANT_SOURCE
#define RECORD_XDT_NAME_CONSTANT_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Communication
//

/** The communication header "0001" record xdt name. */
static wchar_t COMMUNICATION_HEADER_RECORD_XDT_NAME_ARRAY[] = {L'0', L'0', L'0', L'1'};
static wchar_t* COMMUNICATION_HEADER_RECORD_XDT_NAME = COMMUNICATION_HEADER_RECORD_XDT_NAME_ARRAY;
static int* COMMUNICATION_HEADER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The communication footer "0002" record xdt name. */
static wchar_t COMMUNICATION_FOOTER_RECORD_XDT_NAME_ARRAY[] = {L'0', L'0', L'0', L'2'};
static wchar_t* COMMUNICATION_FOOTER_RECORD_XDT_NAME = COMMUNICATION_FOOTER_RECORD_XDT_NAME_ARRAY;
static int* COMMUNICATION_FOOTER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// File
//

/** The file header "0020" record xdt name. */
static wchar_t FILE_HEADER_RECORD_XDT_NAME_ARRAY[] = {L'0', L'0', L'2', L'0'};
static wchar_t* FILE_HEADER_RECORD_XDT_NAME = FILE_HEADER_RECORD_XDT_NAME_ARRAY;
static int* FILE_HEADER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file footer "0021" record xdt name. */
static wchar_t FILE_FOOTER_RECORD_XDT_NAME_ARRAY[] = {L'0', L'0', L'2', L'1'};
static wchar_t* FILE_FOOTER_RECORD_XDT_NAME = FILE_FOOTER_RECORD_XDT_NAME_ARRAY;
static int* FILE_FOOTER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// BDT transfer
//

/** The referenced specification "spec" (Referenzierte Datensatzbeschreibungen) record xdt name. */
static wchar_t REFERENCED_SPECIFICATION_RECORD_XDT_NAME_ARRAY[] = {L's', L'p', L'e', L'c'};
static wchar_t* REFERENCED_SPECIFICATION_RECORD_XDT_NAME = REFERENCED_SPECIFICATION_RECORD_XDT_NAME_ARRAY;
static int* REFERENCED_SPECIFICATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internal identifier "iden" (Vergabe BDT-interner Identifikatoren) record xdt name. */
static wchar_t INTERNAL_IDENTIFIER_RECORD_XDT_NAME_ARRAY[] = {L'i', L'd', L'e', L'n'};
static wchar_t* INTERNAL_IDENTIFIER_RECORD_XDT_NAME = INTERNAL_IDENTIFIER_RECORD_XDT_NAME_ARRAY;
static int* INTERNAL_IDENTIFIER_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Medical practice
//

/** The medical practice "0010" (Praxisstammdaten) record xdt name. */
static wchar_t MEDICAL_PRACTICE_RECORD_XDT_NAME_ARRAY[] = {L'0', L'0', L'1', L'0'};
static wchar_t* MEDICAL_PRACTICE_RECORD_XDT_NAME = MEDICAL_PRACTICE_RECORD_XDT_NAME_ARRAY;
static int* MEDICAL_PRACTICE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The addresses "adrs" (Adressen) record xdt name. */
static wchar_t ADDRESSES_RECORD_XDT_NAME_ARRAY[] = {L'a', L'd', L'r', L's'};
static wchar_t* ADDRESSES_RECORD_XDT_NAME = ADDRESSES_RECORD_XDT_NAME_ARRAY;
static int* ADDRESSES_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The appointments "term" (Termine) record xdt name. */
static wchar_t APPOINTMENTS_RECORD_XDT_NAME_ARRAY[] = {L't', L'e', L'r', L'm'};
static wchar_t* APPOINTMENTS_RECORD_XDT_NAME = APPOINTMENTS_RECORD_XDT_NAME_ARRAY;
static int* APPOINTMENTS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diagnosis abbreviations "diag" (Diagnosenkürzel) record xdt name. */
static wchar_t DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME_ARRAY[] = {L'd', L'i', L'a', L'g'};
static wchar_t* DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME = DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME_ARRAY;
static int* DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service numbers "grnk" (Ziffernketten für Leistungen) record xdt name. */
static wchar_t SERVICE_NUMBERS_RECORD_XDT_NAME_ARRAY[] = {L'g', L'r', L'n', L'k'};
static wchar_t* SERVICE_NUMBERS_RECORD_XDT_NAME = SERVICE_NUMBERS_RECORD_XDT_NAME_ARRAY;
static int* SERVICE_NUMBERS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The prescription abbreviations "hapo" (Verordnungskürzel) record xdt name. */
static wchar_t PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME_ARRAY[] = {L'h', L'a', L'p', L'o'};
static wchar_t* PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME = PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME_ARRAY;
static int* PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment blocks "bbst" (Behandlungsbausteine) record xdt name. */
static wchar_t TREATMENT_BLOCKS_RECORD_XDT_NAME_ARRAY[] = {L'b', L'b', L's', L't'};
static wchar_t* TREATMENT_BLOCKS_RECORD_XDT_NAME = TREATMENT_BLOCKS_RECORD_XDT_NAME_ARRAY;
static int* TREATMENT_BLOCKS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The text blocks "text" (Kürzel Textbausteine) record xdt name. */
static wchar_t TEXT_BLOCKS_RECORD_XDT_NAME_ARRAY[] = {L't', L'e', L'x', L't'};
static wchar_t* TEXT_BLOCKS_RECORD_XDT_NAME = TEXT_BLOCKS_RECORD_XDT_NAME_ARRAY;
static int* TEXT_BLOCKS_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Patient and treatment
//

/** The patient "6100" (Administrative und medizinische Patientenstammblattdaten) record xdt name. */
static wchar_t PATIENT_RECORD_XDT_NAME_ARRAY[] = {L'6', L'1', L'0', L'0'};
static wchar_t* PATIENT_RECORD_XDT_NAME = PATIENT_RECORD_XDT_NAME_ARRAY;
static int* PATIENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment "6200" (Behandlungsdaten) record xdt name. */
static wchar_t MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY[] = {L'6', L'2', L'0', L'0'};
static wchar_t* MEDICAL_TREATMENT_RECORD_XDT_NAME = MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY;
static int* MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Billing [Abrechnungsnotizen (Behandlungsscheine)]
//
// 1 KVDT-Abrechnungen
//

/** The kvdt medical treatment "0101" (Ärztliche Behandlung) record xdt name. */
static wchar_t KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY[] = {L'0', L'1', L'0', L'1'};
static wchar_t* KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME = KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY;
static int* KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt referral case "0102" (Überweisungsfall) record xdt name. */
static wchar_t KVDT_REFERRAL_CASE_RECORD_XDT_NAME_ARRAY[] = {L'0', L'1', L'0', L'2'};
static wchar_t* KVDT_REFERRAL_CASE_RECORD_XDT_NAME = KVDT_REFERRAL_CASE_RECORD_XDT_NAME_ARRAY;
static int* KVDT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medical treatment with cottage hospital affiliation "0103" (Belegärztliche Behandlung) record xdt name. */
static wchar_t KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_ARRAY[] = {L'0', L'1', L'0', L'3'};
static wchar_t* KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME = KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_ARRAY;
static int* KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medical emergency service "0104" (Notfalldienst/Vertretung/Notfall) record xdt name. */
static wchar_t KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME_ARRAY[] = {L'0', L'1', L'0', L'4'};
static wchar_t* KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME = KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME_ARRAY;
static int* KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt medical treatment "sad1" (SADT-ambulante Behandlung) record xdt name. */
static wchar_t KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY[] = {L's', L'a', L'd', L'1'};
static wchar_t* KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME = KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY;
static int* KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt referral case "sad2" (SADT-Überweisung) record xdt name. */
static wchar_t KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME_ARRAY[] = {L's', L'a', L'd', L'2'};
static wchar_t* KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME = KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME_ARRAY;
static int* KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt sadt medical treatment with cottage hospital affiliation "sad3" (SADT-Belegärztliche Behandlung) record xdt name. */
static wchar_t KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_ARRAY[] = {L's', L'a', L'd', L'3'};
static wchar_t* KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME = KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_ARRAY;
static int* KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt cure medical treatment "0109" (Kurärztliche Behandlung) record xdt name. */
static wchar_t KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY[] = {L'0', L'1', L'0', L'9'};
static wchar_t* KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME = KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME_ARRAY;
static int* KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt gevk "GEVK" (GEVK) record xdt name. */
static wchar_t KVDT_GEVK_RECORD_XDT_NAME_ARRAY[] = {L'G', L'E', L'V', L'K'};
static wchar_t* KVDT_GEVK_RECORD_XDT_NAME = KVDT_GEVK_RECORD_XDT_NAME_ARRAY;
static int* KVDT_GEVK_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt haevg "HÄVG" (HÄVG) record xdt name. */
static wchar_t KVDT_HAEVG_RECORD_XDT_NAME_ARRAY[] = {L'H', L'Ä', L'V', L'G'};
static wchar_t* KVDT_HAEVG_RECORD_XDT_NAME = KVDT_HAEVG_RECORD_XDT_NAME_ARRAY;
static int* KVDT_HAEVG_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt medi "MEDI" (MEDI) record xdt name. */
static wchar_t KVDT_MEDI_RECORD_XDT_NAME_ARRAY[] = {L'M', L'E', L'D', L'I'};
static wchar_t* KVDT_MEDI_RECORD_XDT_NAME = KVDT_MEDI_RECORD_XDT_NAME_ARRAY;
static int* KVDT_MEDI_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kvdt kv "KV" (KV) record xdt name. */
static wchar_t KVDT_KV_RECORD_XDT_NAME_ARRAY[] = {L'K', L'V'};
static wchar_t* KVDT_KV_RECORD_XDT_NAME = KVDT_KV_RECORD_XDT_NAME_ARRAY;
static int* KVDT_KV_RECORD_XDT_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Billing [Abrechnungsnotizen (Behandlungsscheine)]
//
// 2 Privatabrechnung
//

/** The private billing "padx" (Privatabrechnung) record xdt name. */
static wchar_t PRIVATE_BILLING_RECORD_XDT_NAME_ARRAY[] = {L'p', L'a', L'd', L'x'};
static wchar_t* PRIVATE_BILLING_RECORD_XDT_NAME = PRIVATE_BILLING_RECORD_XDT_NAME_ARRAY;
static int* PRIVATE_BILLING_RECORD_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RECORD_XDT_NAME_CONSTANT_SOURCE */
#endif
