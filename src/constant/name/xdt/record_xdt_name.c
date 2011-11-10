/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECORD_XDT_NAME_CONSTANT_SOURCE
#define RECORD_XDT_NAME_CONSTANT_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The xdt record identification count.
 *
 * All xdt record identifications have the same length: 4 ASCII characters (bytes).
 */
static int* XDT_RECORD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical practice data record xdt name. */
static int* MEDICAL_PRACTICE_DATA_RECORD_XDT_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium header record xdt name. */
static int* DATA_MEDIUM_HEADER_RECORD_XDT_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium footer record xdt name. */
static int* DATA_MEDIUM_FOOTER_RECORD_XDT_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package header record xdt name. */
static int* DATA_PACKAGE_HEADER_RECORD_XDT_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package footer record xdt name. */
static int* DATA_PACKAGE_FOOTER_RECORD_XDT_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment record xdt name. */
static int* MEDICAL_TREATMENT_RECORD_XDT_NAME = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral case record xdt name. */
static int* REFERRAL_CASE_RECORD_XDT_NAME = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment with cottage hospital affiliation record xdt name. */
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical emergency service record xdt name. */
static int* MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The private billing record xdt name. */
static int* PRIVATE_BILLING_RECORD_XDT_NAME = NUMBER_190_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The employers' liability insurance association billing record xdt name. */
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_NAME = NUMBER_191_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unstructured cases record xdt name. */
static int* UNSTRUCTURED_CASES_RECORD_XDT_NAME = NUMBER_199_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data record xdt name. */
static int* PATIENT_MASTER_DATA_RECORD_XDT_NAME = NUMBER_6100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The medical treatment data record xdt name. */
static int* MEDICAL_TREATMENT_DATA_RECORD_XDT_NAME = NUMBER_6200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data request record xdt name. */
static int* PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_NAME = NUMBER_6300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient master data transfer record xdt name. */
static int* PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_NAME = NUMBER_6301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination request record xdt name. */
static int* EXAMINATION_REQUEST_RECORD_XDT_NAME = NUMBER_6302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination data transfer record xdt name. */
static int* EXAMINATION_DATA_TRANSFER_RECORD_XDT_NAME = NUMBER_6310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The examination data display record xdt name. */
static int* EXAMINATION_DATA_DISPLAY_RECORD_XDT_NAME = NUMBER_6311_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RECORD_XDT_NAME_CONSTANT_SOURCE */
#endif
