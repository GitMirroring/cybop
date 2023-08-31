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

#ifndef RECORD_XDT_CYBOI_NAME_CONSTANT_HEADER
#define RECORD_XDT_CYBOI_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The medical practice data record xdt cyboi name. */
static wchar_t* MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME = L"medical_practice_data";
static int* MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium header record xdt cyboi name. */
/*?? This constant is (probably) not needed.
static wchar_t* DATA_MEDIUM_HEADER_RECORD_XDT_CYBOI_NAME = L"data_medium_header";
static int* DATA_MEDIUM_HEADER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/** The data medium footer record xdt cyboi name. */
/*?? This constant is not needed.
static wchar_t* DATA_MEDIUM_FOOTER_RECORD_XDT_CYBOI_NAME = L"data_medium_footer";
static int* DATA_MEDIUM_FOOTER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/** The package header record xdt cyboi name. */
static wchar_t* PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME = L"header";
static int* PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The package footer record xdt cyboi name. */
static wchar_t* PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME = L"footer";
static int* PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment record xdt cyboi name. */
static wchar_t* MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME = L"medical_treatment";
static int* MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral case record xdt cyboi name. */
static wchar_t* REFERRAL_CASE_RECORD_XDT_CYBOI_NAME = L"referral_case";
static int* REFERRAL_CASE_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment with cottage hospital affiliation record xdt cyboi name. */
static wchar_t* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME = L"medical_treatment_with_cottage_hospital_affiliation";
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical emergency service record xdt cyboi name. */
static wchar_t* MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME = L"medical_emergency_service";
static int* MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The private billing record xdt cyboi name. */
static wchar_t* PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME = L"private_billing";
static int* PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The employers' liability insurance association billing record xdt cyboi name. */
static wchar_t* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME = L"employers_liability_insurance_association_billing";
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_49_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unstructured cases record xdt cyboi name. */
static wchar_t* UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME = L"unstructured_cases";
static int* UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data record xdt cyboi name. */
static wchar_t* PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME = L"patient_master_data";
static int* PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment data record xdt cyboi name. */
static wchar_t* MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME = L"medical_treatment_data";
static int* MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data request record xdt cyboi name. */
static wchar_t* PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME = L"patient_master_data_request";
static int* PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data transfer record xdt cyboi name. */
static wchar_t* PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME = L"patient_master_data_transfer";
static int* PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination request record xdt cyboi name. */
static wchar_t* EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME = L"examination_request";
static int* EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination data transfer record xdt cyboi name. */
static wchar_t* EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME = L"examination_data_transfer";
static int* EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination data display record xdt cyboi name. */
static wchar_t* EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME = L"examination_data_display";
static int* EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RECORD_XDT_CYBOI_NAME_CONSTANT_HEADER */
#endif
