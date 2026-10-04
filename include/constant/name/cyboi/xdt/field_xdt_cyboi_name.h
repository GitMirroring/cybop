/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FIELD_XDT_CYBOI_NAME_CONSTANT_HEADER
#define FIELD_XDT_CYBOI_NAME_CONSTANT_HEADER

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

/** The kbv test number field xdt cyboi name. */
static wchar_t* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME = L"kbv_test_number";
static int* KBV_TEST_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The responsible entity field xdt cyboi name. */
static wchar_t* RESPONSIBLE_ENTITY_FIELD_XDT_CYBOI_NAME = L"responsible_entity";
static int* RESPONSIBLE_ENTITY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The software field xdt cyboi name. */
static wchar_t* SOFTWARE_FIELD_XDT_CYBOI_NAME = L"software";
static int* SOFTWARE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hardware field xdt cyboi name. */
static wchar_t* HARDWARE_FIELD_XDT_CYBOI_NAME = L"hardware";
static int* HARDWARE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The software release field xdt cyboi name. */
static wchar_t* SOFTWARE_RELEASE_FIELD_XDT_CYBOI_NAME = L"software_release";
static int* SOFTWARE_RELEASE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician identification field xdt cyboi name. */
static wchar_t* PHYSICIAN_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"physician_identification";
static int* PHYSICIAN_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician practice type field xdt cyboi name. */
static wchar_t* PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_CYBOI_NAME = L"physician_practice_type";
static int* PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician name field xdt cyboi name. */
static wchar_t* PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME = L"physician_name";
static int* PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician category field xdt cyboi name. */
static wchar_t* PHYSICIAN_CATEGORY_FIELD_XDT_CYBOI_NAME = L"physician_category";
static int* PHYSICIAN_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician street field xdt cyboi name. */
static wchar_t* PHYSICIAN_STREET_FIELD_XDT_CYBOI_NAME = L"physician_street";
static int* PHYSICIAN_STREET_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician postcode and place field xdt cyboi name. */
static wchar_t* PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_CYBOI_NAME = L"physician_postcode_and_place";
static int* PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician with service indicator field xdt cyboi name. */
static wchar_t* PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_CYBOI_NAME = L"physician_with_service_indicator";
static int* PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician phone field xdt cyboi name. */
static wchar_t* PHYSICIAN_PHONE_FIELD_XDT_CYBOI_NAME = L"physician_phone";
static int* PHYSICIAN_PHONE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician fax field xdt cyboi name. */
static wchar_t* PHYSICIAN_FAX_FIELD_XDT_CYBOI_NAME = L"physician_fax";
static int* PHYSICIAN_FAX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician modem field xdt cyboi name. */
static wchar_t* PHYSICIAN_MODEM_FIELD_XDT_CYBOI_NAME = L"physician_modem";
static int* PHYSICIAN_MODEM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The physician number within practice field xdt cyboi name. */
static wchar_t* PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_CYBOI_NAME = L"physician_number_within_practice";
static int* PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 1 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_1_name";
static int* FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 1 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_1_value";
static int* FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 2 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_2_name";
static int* FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 2 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_2_value";
static int* FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 3 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_3_name";
static int* FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 3 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_3_value";
static int* FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 4 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_4_name";
static int* FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 4 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_4_value";
static int* FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 5 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_5_name";
static int* FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 5 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_5_value";
static int* FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 6 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_6_name";
static int* FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 6 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_6_value";
static int* FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 7 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_7_name";
static int* FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 7 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_7_value";
static int* FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 8 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_8_name";
static int* FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 8 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_8_value";
static int* FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 9 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_9_name";
static int* FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 9 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_9_value";
static int* FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 10 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_10_name";
static int* FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 10 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_10_value";
static int* FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 11 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_11_name";
static int* FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 11 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_11_value";
static int* FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 12 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_12_name";
static int* FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 12 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_12_value";
static int* FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 13 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_13_name";
static int* FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 13 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_13_value";
static int* FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 14 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_14_name";
static int* FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 14 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_14_value";
static int* FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 15 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_15_name";
static int* FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 15 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_15_value";
static int* FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 16 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_16_name";
static int* FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 16 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_16_value";
static int* FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 17 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_17_name";
static int* FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 17 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_17_value";
static int* FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 18 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_18_name";
static int* FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 18 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_18_value";
static int* FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 19 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_19_name";
static int* FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 19 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_19_value";
static int* FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 20 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_20_name";
static int* FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 20 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_20_value";
static int* FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 21 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_21_name";
static int* FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 21 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_21_value";
static int* FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 22 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_22_name";
static int* FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 22 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_22_value";
static int* FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 23 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_23_name";
static int* FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 23 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_23_value";
static int* FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 24 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_24_name";
static int* FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 24 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_24_value";
static int* FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 25 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_25_name";
static int* FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 0010 category 25 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_0010_category_25_value";
static int* FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient identification field xdt cyboi name. */
static wchar_t* PATIENT_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"patient_identification";
static int* PATIENT_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient name affix field xdt cyboi name. */
static wchar_t* PATIENT_NAME_AFFIX_FIELD_XDT_CYBOI_NAME = L"patient_name_affix";
static int* PATIENT_NAME_AFFIX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient last name field xdt cyboi name. */
static wchar_t* PATIENT_LAST_NAME_FIELD_XDT_CYBOI_NAME = L"patient_last_name";
static int* PATIENT_LAST_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient first name field xdt cyboi name. */
static wchar_t* PATIENT_FIRST_NAME_FIELD_XDT_CYBOI_NAME = L"patient_first_name";
static int* PATIENT_FIRST_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient birth date field xdt cyboi name. */
static wchar_t* PATIENT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME = L"patient_birth_date";
static int* PATIENT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient title field xdt cyboi name. */
static wchar_t* PATIENT_TITLE_FIELD_XDT_CYBOI_NAME = L"patient_title";
static int* PATIENT_TITLE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient health insurance number field xdt cyboi name. */
static wchar_t* PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME = L"patient_health_insurance_number";
static int* PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient residence field xdt cyboi name. */
static wchar_t* PATIENT_RESIDENCE_FIELD_XDT_CYBOI_NAME = L"patient_residence";
static int* PATIENT_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient street field xdt cyboi name. */
static wchar_t* PATIENT_STREET_FIELD_XDT_CYBOI_NAME = L"patient_street";
static int* PATIENT_STREET_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient health insurance type field xdt cyboi name. */
static wchar_t* PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_CYBOI_NAME = L"patient_health_insurance_type";
static int* PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient sex field xdt cyboi name. */
static wchar_t* PATIENT_SEX_FIELD_XDT_CYBOI_NAME = L"patient_sex";
static int* PATIENT_SEX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient employer field xdt cyboi name. */
static wchar_t* PATIENT_EMPLOYER_FIELD_XDT_CYBOI_NAME = L"patient_employer";
static int* PATIENT_EMPLOYER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient accident insurance name field xdt cyboi name. */
static wchar_t* PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_CYBOI_NAME = L"patient_accident_insurance_name";
static int* PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant last name field xdt cyboi name. */
static wchar_t* INSURANT_LAST_NAME_FIELD_XDT_CYBOI_NAME = L"insurant_last_name";
static int* INSURANT_LAST_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant first name field xdt cyboi name. */
static wchar_t* INSURANT_FIRST_NAME_FIELD_XDT_CYBOI_NAME = L"insurant_first_name";
static int* INSURANT_FIRST_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant birth date field xdt cyboi name. */
static wchar_t* INSURANT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME = L"insurant_birth_date";
static int* INSURANT_BIRTH_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant residence field xdt cyboi name. */
static wchar_t* INSURANT_RESIDENCE_FIELD_XDT_CYBOI_NAME = L"insurant_residence";
static int* INSURANT_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant street field xdt cyboi name. */
static wchar_t* INSURANT_STREET_FIELD_XDT_CYBOI_NAME = L"insurant_street";
static int* INSURANT_STREET_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The injured phone field xdt cyboi name. */
static wchar_t* INJURED_PHONE_FIELD_XDT_CYBOI_NAME = L"injured_phone";
static int* INJURED_PHONE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insurant sex field xdt cyboi name. */
static wchar_t* INSURANT_SEX_FIELD_XDT_CYBOI_NAME = L"insurant_sex";
static int* INSURANT_SEX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient x-ray number field xdt cyboi name. */
static wchar_t* PATIENT_X_RAY_NUMBER_FIELD_XDT_CYBOI_NAME = L"patient_x-ray_number";
static int* PATIENT_X_RAY_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient archive number field xdt cyboi name. */
static wchar_t* PATIENT_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME = L"patient_archive_number";
static int* PATIENT_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient employers' liability insurance association number field xdt cyboi name. */
static wchar_t* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_CYBOI_NAME = L"patient_employers_liability_insurance_association_number";
static int* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_56_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient since date field xdt cyboi name. */
static wchar_t* PATIENT_SINCE_DATE_FIELD_XDT_CYBOI_NAME = L"patient_since_date";
static int* PATIENT_SINCE_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient change of insurance inception date field xdt cyboi name. */
static wchar_t* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_CYBOI_NAME = L"patient_change_of_insurance_inception_date";
static int* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient profession field xdt cyboi name. */
static wchar_t* PATIENT_PROFESSION_FIELD_XDT_CYBOI_NAME = L"patient_profession";
static int* PATIENT_PROFESSION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient body height field xdt cyboi name. */
static wchar_t* PATIENT_BODY_HEIGHT_FIELD_XDT_CYBOI_NAME = L"patient_body_height";
static int* PATIENT_BODY_HEIGHT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient body weight field xdt cyboi name. */
static wchar_t* PATIENT_BODY_WEIGHT_FIELD_XDT_CYBOI_NAME = L"patient_body_weight";
static int* PATIENT_BODY_WEIGHT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient employer (redundant) field xdt cyboi name. */
static wchar_t* PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_CYBOI_NAME = L"patient_employer_redundant";
static int* PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient phone field xdt cyboi name. */
static wchar_t* PATIENT_PHONE_FIELD_XDT_CYBOI_NAME = L"patient_phone";
static int* PATIENT_PHONE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient nationality field xdt cyboi name. */
static wchar_t* PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME = L"patient_nationality";
static int* PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient mother tongue field xdt cyboi name. */
static wchar_t* PATIENT_MOTHER_TONGUE_FIELD_XDT_CYBOI_NAME = L"patient_mother_tongue";
static int* PATIENT_MOTHER_TONGUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient general practitioner identification field xdt cyboi name. */
static wchar_t* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"patient_general_practitioner_identification";
static int* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient residence to medical practice distance field xdt cyboi name. */
static wchar_t* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_CYBOI_NAME = L"patient_residence_to_medical_practice_distance";
static int* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_46_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient physician identification in group practice field xdt cyboi name. */
static wchar_t* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_CYBOI_NAME = L"patient_physician_identification_in_group_practice";
static int* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient prescription identification field xdt cyboi name. */
static wchar_t* PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"patient_prescription_identification";
static int* PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient permanent diagnoses begin date field xdt cyboi name. */
static wchar_t* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_CYBOI_NAME = L"patient_permanent_diagnoses_begin_date";
static int* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient permanent diagnoses field xdt cyboi name. */
static wchar_t* PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_CYBOI_NAME = L"patient_permanent_diagnoses";
static int* PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient permanent drugs begin date field xdt cyboi name. */
static wchar_t* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_CYBOI_NAME = L"patient_permanent_drugs_begin_date";
static int* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient permanent drugs field xdt cyboi name. */
static wchar_t* PATIENT_PERMANENT_DRUGS_FIELD_XDT_CYBOI_NAME = L"patient_permanent_drugs";
static int* PATIENT_PERMANENT_DRUGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient risk factors field xdt cyboi name. */
static wchar_t* PATIENT_RISK_FACTORS_FIELD_XDT_CYBOI_NAME = L"patient_risk_factors";
static int* PATIENT_RISK_FACTORS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient allergies field xdt cyboi name. */
static wchar_t* PATIENT_ALLERGIES_FIELD_XDT_CYBOI_NAME = L"patient_allergies";
static int* PATIENT_ALLERGIES_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient accidents field xdt cyboi name. */
static wchar_t* PATIENT_ACCIDENTS_FIELD_XDT_CYBOI_NAME = L"patient_accidents";
static int* PATIENT_ACCIDENTS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient surgeries field xdt cyboi name. */
static wchar_t* PATIENT_SURGERIES_FIELD_XDT_CYBOI_NAME = L"patient_surgeries";
static int* PATIENT_SURGERIES_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient anamnesis field xdt cyboi name. */
static wchar_t* PATIENT_ANAMNESIS_FIELD_XDT_CYBOI_NAME = L"patient_anamnesis";
static int* PATIENT_ANAMNESIS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient number of births field xdt cyboi name. */
static wchar_t* PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_CYBOI_NAME = L"patient_number_of_births";
static int* PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient number of children field xdt cyboi name. */
static wchar_t* PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_CYBOI_NAME = L"patient_number_of_children";
static int* PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient number of pregnancies field xdt cyboi name. */
static wchar_t* PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_CYBOI_NAME = L"patient_number_of_pregnancies";
static int* PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient permanent therapy field xdt cyboi name. */
static wchar_t* PATIENT_PERMANENT_THERAPY_FIELD_XDT_CYBOI_NAME = L"patient_permanent_therapy";
static int* PATIENT_PERMANENT_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The patient recall appointment date field xdt cyboi name. */
static wchar_t* PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_CYBOI_NAME = L"patient_recall_appointment_date";
static int* PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 1 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_1_name";
static int* FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 1 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_1_value";
static int* FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 2 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_2_name";
static int* FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 2 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_2_value";
static int* FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 3 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_3_name";
static int* FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 3 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_3_value";
static int* FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 4 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_4_name";
static int* FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 4 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_4_value";
static int* FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 5 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_5_name";
static int* FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 5 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_5_value";
static int* FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 6 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_6_name";
static int* FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 6 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_6_value";
static int* FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 7 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_7_name";
static int* FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 7 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_7_value";
static int* FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 8 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_8_name";
static int* FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 8 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_8_value";
static int* FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 9 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_9_name";
static int* FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 9 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_9_value";
static int* FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 10 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_10_name";
static int* FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6100 category 10 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6100_category_10_value";
static int* FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice quarter field xdt cyboi name. */
static wchar_t* INVOICE_QUARTER_FIELD_XDT_CYBOI_NAME = L"invoice_quarter";
static int* INVOICE_QUARTER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice issuance date field xdt cyboi name. */
static wchar_t* INVOICE_ISSUANCE_DATE_FIELD_XDT_CYBOI_NAME = L"invoice_issuance_date";
static int* INVOICE_ISSUANCE_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice validity date field xdt cyboi name. */
static wchar_t* INVOICE_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME = L"invoice_validity_date";
static int* INVOICE_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice insurance number field xdt cyboi name. */
static wchar_t* INVOICE_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME = L"invoice_insurance_number";
static int* INVOICE_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice insurance office field xdt cyboi name. */
static wchar_t* INVOICE_INSURANCE_OFFICE_FIELD_XDT_CYBOI_NAME = L"invoice_insurance_office";
static int* INVOICE_INSURANCE_OFFICE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice insurance sub category field xdt cyboi name. */
static wchar_t* INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME = L"invoice_insurance_sub_category";
static int* INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice billing category field xdt cyboi name. */
static wchar_t* INVOICE_BILLING_CATEGORY_FIELD_XDT_CYBOI_NAME = L"invoice_billing_category";
static int* INVOICE_BILLING_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice insurance card last read access field xdt cyboi name. */
static wchar_t* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_CYBOI_NAME = L"invoice_insurance_card_last_read_access";
static int* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_39_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice insurance card validity date field xdt cyboi name. */
static wchar_t* INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME = L"invoice_insurance_card_validity_date";
static int* INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice ik insurance number field xdt cyboi name. */
static wchar_t* INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME = L"invoice_ik_insurance_number";
static int* INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice vk insurance status field xdt cyboi name. */
static wchar_t* INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_CYBOI_NAME = L"invoice_vk_insurance_status";
static int* INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice vk east-west status field xdt cyboi name. */
static wchar_t* INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_CYBOI_NAME = L"invoice_vk_east-west_status";
static int* INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice billing scale field xdt cyboi name. */
static wchar_t* INVOICE_BILLING_SCALE_FIELD_XDT_CYBOI_NAME = L"invoice_billing_scale";
static int* INVOICE_BILLING_SCALE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice billing area field xdt cyboi name. */
static wchar_t* INVOICE_BILLING_AREA_FIELD_XDT_CYBOI_NAME = L"invoice_billing_area";
static int* INVOICE_BILLING_AREA_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral cause of pain field xdt cyboi name. */
static wchar_t* REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_CYBOI_NAME = L"referral_cause_of_pain";
static int* REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral supposed accouchement date field xdt cyboi name. */
static wchar_t* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_CYBOI_NAME = L"referral_supposed_accouchement_date";
static int* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral diagnosis field xdt cyboi name. */
static wchar_t* REFERRAL_DIAGNOSIS_FIELD_XDT_CYBOI_NAME = L"referral_diagnosis";
static int* REFERRAL_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral explanation field xdt cyboi name. */
static wchar_t* REFERRAL_EXPLANATION_FIELD_XDT_CYBOI_NAME = L"referral_explanation";
static int* REFERRAL_EXPLANATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral check box muvo lsr field xdt cyboi name. */
static wchar_t* REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_CYBOI_NAME = L"referral_check_box_muvo_lsr";
static int* REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral check box muvo hah field xdt cyboi name. */
static wchar_t* REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_CYBOI_NAME = L"referral_check_box_muvo_hah";
static int* REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral check box ab0 rh field xdt cyboi name. */
static wchar_t* REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_CYBOI_NAME = L"referral_check_box_ab0_rh";
static int* REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral check box ak field xdt cyboi name. */
static wchar_t* REFERRAL_CHECK_BOX_AK_FIELD_XDT_CYBOI_NAME = L"referral_check_box_ak";
static int* REFERRAL_CHECK_BOX_AK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral from physician number field xdt cyboi name. */
static wchar_t* REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME = L"referral_from_physician_number";
static int* REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referral to physician name field xdt cyboi name. */
static wchar_t* REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME = L"referral_to_physician_name";
static int* REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inpatient treatment referral by law field xdt cyboi name. */
static wchar_t* INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_CYBOI_NAME = L"inpatient_treatment_referral_by_law";
static int* INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inpatient treatment from to field xdt cyboi name. */
static wchar_t* INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_CYBOI_NAME = L"inpatient_treatment_from_to";
static int* INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inpatient treatment class field xdt cyboi name. */
static wchar_t* INPATIENT_TREATMENT_CLASS_FIELD_XDT_CYBOI_NAME = L"inpatient_treatment_class";
static int* INPATIENT_TREATMENT_CLASS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inpatient hospital name field xdt cyboi name. */
static wchar_t* INPATIENT_HOSPITAL_NAME_FIELD_XDT_CYBOI_NAME = L"inpatient_hospital_name";
static int* INPATIENT_HOSPITAL_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inpatient hospital stay field xdt cyboi name. */
static wchar_t* INPATIENT_HOSPITAL_STAY_FIELD_XDT_CYBOI_NAME = L"inpatient_hospital_stay";
static int* INPATIENT_HOSPITAL_STAY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The invoice sub category field xdt cyboi name. */
static wchar_t* INVOICE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME = L"invoice_sub_category";
static int* INVOICE_SUB_CATEGORY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The emergency subsequent treatment physician name field xdt cyboi name. */
static wchar_t* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME = L"emergency_subsequent_treatment_physician_name";
static int* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_45_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The emergency findings field xdt cyboi name. */
static wchar_t* EMERGENCY_FINDINGS_FIELD_XDT_CYBOI_NAME = L"emergency_findings";
static int* EMERGENCY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The emergency symptoms field xdt cyboi name. */
static wchar_t* EMERGENCY_SYMPTOMS_FIELD_XDT_CYBOI_NAME = L"emergency_symptoms";
static int* EMERGENCY_SYMPTOMS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident date field xdt cyboi name. */
static wchar_t* ACCIDENT_DATE_FIELD_XDT_CYBOI_NAME = L"accident_date";
static int* ACCIDENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident time field xdt cyboi name. */
static wchar_t* ACCIDENT_TIME_FIELD_XDT_CYBOI_NAME = L"accident_time";
static int* ACCIDENT_TIME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient admission in practice date field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_CYBOI_NAME = L"accident_patient_admission_in_practice_date";
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient admission in practice time field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_CYBOI_NAME = L"accident_patient_admission_in_practice_time";
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient labour time begin field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_CYBOI_NAME = L"accident_patient_labour_time_begin";
static int* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident location field xdt cyboi name. */
static wchar_t* ACCIDENT_LOCATION_FIELD_XDT_CYBOI_NAME = L"accident_location";
static int* ACCIDENT_LOCATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient employment as field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_CYBOI_NAME = L"accident_patient_employment_as";
static int* ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient employment since field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_CYBOI_NAME = L"accident_patient_employment_since";
static int* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient nationality field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME = L"accident_patient_nationality";
static int* ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident company field xdt cyboi name. */
static wchar_t* ACCIDENT_COMPANY_FIELD_XDT_CYBOI_NAME = L"accident_company";
static int* ACCIDENT_COMPANY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident course of events field xdt cyboi name. */
static wchar_t* ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_CYBOI_NAME = L"accident_course_of_events";
static int* ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident patient behaviour afterwards field xdt cyboi name. */
static wchar_t* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_CYBOI_NAME = L"accident_patient_behaviour_afterwards";
static int* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident first time treatment date field xdt cyboi name. */
static wchar_t* ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME = L"accident_first_time_treatment_date";
static int* ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident treatment by physician name field xdt cyboi name. */
static wchar_t* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME = L"accident_treatment_by_physician_name";
static int* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident kind of treatment field xdt cyboi name. */
static wchar_t* ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_CYBOI_NAME = L"accident_kind_of_first_treatment";
static int* ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident alcohol influence field xdt cyboi name. */
static wchar_t* ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME = L"accident_alcohol_influence";
static int* ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident signs for alcohol influence field xdt cyboi name. */
static wchar_t* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME = L"accident_signs_for_alcohol_influence";
static int* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident blood withdrawal field xdt cyboi name. */
static wchar_t* ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_CYBOI_NAME = L"accident_blood_withdrawal";
static int* ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident findings field xdt cyboi name. */
static wchar_t* ACCIDENT_FINDINGS_FIELD_XDT_CYBOI_NAME = L"accident_findings";
static int* ACCIDENT_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident x-ray result field xdt cyboi name. */
static wchar_t* ACCIDENT_X_RAY_RESULT_FIELD_XDT_CYBOI_NAME = L"accident_x-ray_result";
static int* ACCIDENT_X_RAY_RESULT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident kind of first treatment field xdt cyboi name. */
static wchar_t* ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_CYBOI_NAME = L"accident_kind_of_first_treatment";
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident abnormal changes independent from accident field xdt cyboi name. */
static wchar_t* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_CYBOI_NAME = L"accident_abnormal_changes_independent_from_accident";
static int* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident concerns against statements field xdt cyboi name. */
static wchar_t* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME = L"accident_concerns_against_statements";
static int* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident kind of concerns against statements field xdt cyboi name. */
static wchar_t* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME = L"accident_kind_of_concerns_against_statements";
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_44_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident concerns against classification as accident at work field xdt cyboi name. */
static wchar_t* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME = L"accident_concerns_against_classification_as_accident_at_work";
static int* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident kind of concerns against classification as accident at work field xdt cyboi name. */
static wchar_t* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME = L"accident_kind_of_concerns_against_classification_as_accident_at_work";
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_68_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident able to work field xdt cyboi name. */
static wchar_t* ACCIDENT_ABLE_TO_WORK_FIELD_XDT_CYBOI_NAME = L"accident_able_to_work";
static int* ACCIDENT_ABLE_TO_WORK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident able to work from field xdt cyboi name. */
static wchar_t* ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME = L"accident_able_to_work_from";
static int* ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident unable to work certificate issuance field xdt cyboi name. */
static wchar_t* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_CYBOI_NAME = L"accident_unable_to_work_certificate_issuance";
static int* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_44_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident special curative treatment necessary field xdt cyboi name. */
static wchar_t* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_CYBOI_NAME = L"accident_special_curative_treatment_necessary";
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_45_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident special curative treatment by field xdt cyboi name. */
static wchar_t* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME = L"accident_special_curative_treatment_by";
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident address of treating physician field xdt cyboi name. */
static wchar_t* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_CYBOI_NAME = L"accident_address_of_treating_physician";
static int* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident unable to work from field xdt cyboi name. */
static wchar_t* ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME = L"accident_unable_to_work_from";
static int* ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident expected duration of inability to work field xdt cyboi name. */
static wchar_t* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_CYBOI_NAME = L"accident_expected_duration_of_inability_to_work";
static int* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_47_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident kind of bill field xdt cyboi name. */
static wchar_t* ACCIDENT_KIND_OF_BILL_FIELD_XDT_CYBOI_NAME = L"accident_kind_of_bill";
static int* ACCIDENT_KIND_OF_BILL_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident general curative treatment by field xdt cyboi name. */
static wchar_t* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME = L"accident_general_curative_treatment_by";
static int* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident unable to work for longer than three days field xdt cyboi name. */
static wchar_t* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_CYBOI_NAME = L"accident_unable_to_work_for_longer_than_three_days";
static int* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident unability to work certified until field xdt cyboi name. */
static wchar_t* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_CYBOI_NAME = L"accident_unability_to_work_certified_until";
static int* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accident inspection required on field xdt cyboi name. */
static wchar_t* ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_CYBOI_NAME = L"accident_inspection_required_on";
static int* ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing number field xdt cyboi name. */
static wchar_t* BILLING_NUMBER_FIELD_XDT_CYBOI_NAME = L"billing_number";
static int* BILLING_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing address field xdt cyboi name. */
static wchar_t* BILLING_ADDRESS_FIELD_XDT_CYBOI_NAME = L"billing_address";
static int* BILLING_ADDRESS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing referring physician name field xdt cyboi name. */
static wchar_t* BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME = L"billing_referring_physician_name";
static int* BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing date field xdt cyboi name. */
static wchar_t* BILLING_DATE_FIELD_XDT_CYBOI_NAME = L"billing_date";
static int* BILLING_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing total sum field xdt cyboi name. */
static wchar_t* BILLING_TOTAL_SUM_FIELD_XDT_CYBOI_NAME = L"billing_total_sum";
static int* BILLING_TOTAL_SUM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing assignment declaration field xdt cyboi name. */
static wchar_t* BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_CYBOI_NAME = L"billing_assignment_declaration";
static int* BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing physician sub account field xdt cyboi name. */
static wchar_t* BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_CYBOI_NAME = L"billing_physician_sub_account";
static int* BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing attachment field xdt cyboi name. */
static wchar_t* BILLING_ATTACHMENT_FIELD_XDT_CYBOI_NAME = L"billing_attachment";
static int* BILLING_ATTACHMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing header field xdt cyboi name. */
static wchar_t* BILLING_HEADER_FIELD_XDT_CYBOI_NAME = L"billing_header";
static int* BILLING_HEADER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing footer field xdt cyboi name. */
static wchar_t* BILLING_FOOTER_FIELD_XDT_CYBOI_NAME = L"billing_footer";
static int* BILLING_FOOTER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service treatment date field xdt cyboi name. */
static wchar_t* SERVICE_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME = L"service_treatment_date";
static int* SERVICE_TREATMENT_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service gnr identification field xdt cyboi name. */
static wchar_t* SERVICE_GNR_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"service_gnr_identification";
static int* SERVICE_GNR_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service kind of examination field xdt cyboi name. */
static wchar_t* SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_CYBOI_NAME = L"service_kind_of_examination";
static int* SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service addressee field xdt cyboi name. */
static wchar_t* SERVICE_ADDRESSEE_FIELD_XDT_CYBOI_NAME = L"service_addressee";
static int* SERVICE_ADDRESSEE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service distance in kilometres field xdt cyboi name. */
static wchar_t* SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_CYBOI_NAME = L"service_distance_in_kilometres";
static int* SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service multiplier field xdt cyboi name. */
static wchar_t* SERVICE_MULTIPLIER_FIELD_XDT_CYBOI_NAME = L"service_multiplier";
static int* SERVICE_MULTIPLIER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service time field xdt cyboi name. */
static wchar_t* SERVICE_TIME_FIELD_XDT_CYBOI_NAME = L"service_time";
static int* SERVICE_TIME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service order-execution time field xdt cyboi name. */
static wchar_t* SERVICE_ORDER_EXECUTION_FIELD_XDT_CYBOI_NAME = L"service_order-execution_time";
static int* SERVICE_ORDER_EXECUTION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service dkm field xdt cyboi name. */
static wchar_t* SERVICE_DKM_FIELD_XDT_CYBOI_NAME = L"service_dkm";
static int* SERVICE_DKM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service free explanatory statement field xdt cyboi name. */
static wchar_t* SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_CYBOI_NAME = L"service_free_explanatory_statement";
static int* SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service explanatory drug field xdt cyboi name. */
static wchar_t* SERVICE_EXPLANATORY_DRUG_FIELD_XDT_CYBOI_NAME = L"service_explanatory_drug";
static int* SERVICE_EXPLANATORY_DRUG_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service material costs description field xdt cyboi name. */
static wchar_t* SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_CYBOI_NAME = L"service_material_costs_description";
static int* SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service material costs dpf field xdt cyboi name. */
static wchar_t* SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_CYBOI_NAME = L"service_material_costs_dpf";
static int* SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service percent of treatment field xdt cyboi name. */
static wchar_t* SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_CYBOI_NAME = L"service_percent_of_treatment";
static int* SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service organ field xdt cyboi name. */
static wchar_t* SERVICE_ORGAN_FIELD_XDT_CYBOI_NAME = L"service_organ";
static int* SERVICE_ORGAN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service location field xdt cyboi name. */
static wchar_t* SERVICE_LOCATION_FIELD_XDT_CYBOI_NAME = L"service_location";
static int* SERVICE_LOCATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service zone field xdt cyboi name. */
static wchar_t* SERVICE_ZONE_FIELD_XDT_CYBOI_NAME = L"service_zone";
static int* SERVICE_ZONE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service gnr description field xdt cyboi name. */
static wchar_t* SERVICE_GNR_DESCRIPTION_FIELD_XDT_CYBOI_NAME = L"service_gnr_description";
static int* SERVICE_GNR_DESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service fee field xdt cyboi name. */
static wchar_t* SERVICE_FEE_FIELD_XDT_CYBOI_NAME = L"service_fee";
static int* SERVICE_FEE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service factor field xdt cyboi name. */
static wchar_t* SERVICE_FACTOR_FIELD_XDT_CYBOI_NAME = L"service_factor";
static int* SERVICE_FACTOR_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service sum field xdt cyboi name. */
static wchar_t* SERVICE_SUM_FIELD_XDT_CYBOI_NAME = L"service_sum";
static int* SERVICE_SUM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service total sum field xdt cyboi name. */
static wchar_t* SERVICE_TOTAL_SUM_FIELD_XDT_CYBOI_NAME = L"service_total_sum";
static int* SERVICE_TOTAL_SUM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service point value field xdt cyboi name. */
static wchar_t* SERVICE_POINT_VALUE_FIELD_XDT_CYBOI_NAME = L"service_point_value";
static int* SERVICE_POINT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service name of fee field xdt cyboi name. */
static wchar_t* SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_FEE_FIELD_XDT_CYBOI_NAME = L"service_name_of_fee";
static int* SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_FEE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service name of certificate field xdt cyboi name. */
static wchar_t* SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_CYBOI_NAME = L"service_name_of_certificate";
static int* SERVICE_LIFECYCLE_LOGIC_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing diagnosis field xdt cyboi name. */
static wchar_t* BILLING_DIAGNOSIS_FIELD_XDT_CYBOI_NAME = L"billing_diagnosis";
static int* BILLING_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The billing icd key field xdt cyboi name. */
static wchar_t* BILLING_ICD_KEY_FIELD_XDT_CYBOI_NAME = L"billing_icd_key";
static int* BILLING_ICD_KEY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment data collection date field xdt cyboi name. */
static wchar_t* TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME = L"treatment_data_collection_date";
static int* TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment data collection time field xdt cyboi name. */
static wchar_t* TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME = L"treatment_data_collection_time";
static int* TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment current diagnosis field xdt cyboi name. */
static wchar_t* TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_CYBOI_NAME = L"treatment_current_diagnosis";
static int* TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment drug prescribed with prescription field xdt cyboi name. */
static wchar_t* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_CYBOI_NAME = L"treatment_drug_prescribed_with_prescription";
static int* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment drug prescribed without prescription field xdt cyboi name. */
static wchar_t* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_CYBOI_NAME = L"treatment_drug_prescribed_without_prescription";
static int* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_46_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment physician sample field xdt cyboi name. */
static wchar_t* TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_CYBOI_NAME = L"treatment_physician_sample";
static int* TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment findings field xdt cyboi name. */
static wchar_t* TREATMENT_FINDINGS_FIELD_XDT_CYBOI_NAME = L"treatment_findings";
static int* TREATMENT_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment external findings field xdt cyboi name. */
static wchar_t* TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_CYBOI_NAME = L"treatment_external_findings";
static int* TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment laboratory findings field xdt cyboi name. */
static wchar_t* TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_CYBOI_NAME = L"treatment_laboratory_findings";
static int* TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment x-ray findings field xdt cyboi name. */
static wchar_t* TREATMENT_X_RAY_FINDINGS_FIELD_XDT_CYBOI_NAME = L"treatment_x-ray_findings";
static int* TREATMENT_X_RAY_FINDINGS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment subsequent line count field xdt cyboi name. */
static wchar_t* TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_CYBOI_NAME = L"treatment_subsequent_line_count";
static int* TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment comment field xdt cyboi name. */
static wchar_t* TREATMENT_COMMENT_FIELD_XDT_CYBOI_NAME = L"treatment_comment";
static int* TREATMENT_COMMENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment formatted result table text field xdt cyboi name. */
static wchar_t* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_CYBOI_NAME = L"treatment_formatted_result_table_text";
static int* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment blood pressure field xdt cyboi name. */
static wchar_t* TREATMENT_BLOOD_PRESSURE_FIELD_XDT_CYBOI_NAME = L"treatment_blood_pressure";
static int* TREATMENT_BLOOD_PRESSURE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment symptoms field xdt cyboi name. */
static wchar_t* TREATMENT_SYMPTOMS_FIELD_XDT_CYBOI_NAME = L"treatment_symptoms";
static int* TREATMENT_SYMPTOMS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment therapy field xdt cyboi name. */
static wchar_t* TREATMENT_THERAPY_FIELD_XDT_CYBOI_NAME = L"treatment_therapy";
static int* TREATMENT_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment physical therapy field xdt cyboi name. */
static wchar_t* TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_CYBOI_NAME = L"treatment_physical_therapy";
static int* TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment referral content field xdt cyboi name. */
static wchar_t* TREATMENT_REFERRAL_CONTENT_FIELD_XDT_CYBOI_NAME = L"treatment_referral_content";
static int* TREATMENT_REFERRAL_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment work disability duration field xdt cyboi name. */
static wchar_t* TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_CYBOI_NAME = L"treatment_work_disability_duration";
static int* TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment work disability cause field xdt cyboi name. */
static wchar_t* TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_CYBOI_NAME = L"treatment_work_disability_cause";
static int* TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment hospitalisation field xdt cyboi name. */
static wchar_t* TREATMENT_HOSPITALISATION_FIELD_XDT_CYBOI_NAME = L"treatment_hospitalisation";
static int* TREATMENT_HOSPITALISATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The treatment hospitalisation cause field xdt cyboi name. */
static wchar_t* TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_CYBOI_NAME = L"treatment_hospitalisation_cause";
static int* TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter certificate kind field xdt cyboi name. */
static wchar_t* LETTER_CERTIFICATE_KIND_FIELD_XDT_CYBOI_NAME = L"letter_certificate_kind";
static int* LETTER_CERTIFICATE_KIND_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter certificate content field xdt cyboi name. */
static wchar_t* LETTER_CERTIFICATE_CONTENT_FIELD_XDT_CYBOI_NAME = L"letter_certificate_content";
static int* LETTER_CERTIFICATE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter file archive number field xdt cyboi name. */
static wchar_t* LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME = L"letter_file_archive_number";
static int* LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter file format field xdt cyboi name. */
static wchar_t* LETTER_FILE_FORMAT_FIELD_XDT_CYBOI_NAME = L"letter_file_format";
static int* LETTER_FILE_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter file content field xdt cyboi name. */
static wchar_t* LETTER_FILE_CONTENT_FIELD_XDT_CYBOI_NAME = L"letter_file_content";
static int* LETTER_FILE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter file url field xdt cyboi name. */
static wchar_t* LETTER_FILE_URL_FIELD_XDT_CYBOI_NAME = L"letter_file_url";
static int* LETTER_FILE_URL_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter attestation kind field xdt cyboi name. */
static wchar_t* LETTER_ATTESTATION_KIND_FIELD_XDT_CYBOI_NAME = L"letter_attestation_kind";
static int* LETTER_ATTESTATION_KIND_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter attestation content field xdt cyboi name. */
static wchar_t* LETTER_ATTESTATION_CONTENT_FIELD_XDT_CYBOI_NAME = L"letter_attestation_content";
static int* LETTER_ATTESTATION_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter addressee field xdt cyboi name. */
static wchar_t* LETTER_ADDRESSEE_FIELD_XDT_CYBOI_NAME = L"letter_addressee";
static int* LETTER_ADDRESSEE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter salutation field xdt cyboi name. */
static wchar_t* LETTER_SALUTATION_FIELD_XDT_CYBOI_NAME = L"letter_salutation";
static int* LETTER_SALUTATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter street field xdt cyboi name. */
static wchar_t* LETTER_STREET_FIELD_XDT_CYBOI_NAME = L"letter_street";
static int* LETTER_STREET_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter postcode field xdt cyboi name. */
static wchar_t* LETTER_POSTCODE_FIELD_XDT_CYBOI_NAME = L"letter_postcode";
static int* LETTER_POSTCODE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter residence field xdt cyboi name. */
static wchar_t* LETTER_RESIDENCE_FIELD_XDT_CYBOI_NAME = L"letter_residence";
static int* LETTER_RESIDENCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter complimentary close field xdt cyboi name. */
static wchar_t* LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME = L"letter_complimentary_close";
static int* LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter phone field xdt cyboi name. */
static wchar_t* LETTER_PHONE_FIELD_XDT_CYBOI_NAME = L"letter_phone";
static int* LETTER_PHONE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter fax field xdt cyboi name. */
static wchar_t* LETTER_FAX_FIELD_XDT_CYBOI_NAME = L"letter_fax";
static int* LETTER_FAX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter physician number field xdt cyboi name. */
static wchar_t* LETTER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME = L"letter_physician_number";
static int* LETTER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter content field xdt cyboi name. */
static wchar_t* LETTER_CONTENT_FIELD_XDT_CYBOI_NAME = L"letter_content";
static int* LETTER_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter image archive number field xdt cyboi name. */
static wchar_t* LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME = L"letter_image_archive_number";
static int* LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter graphic format field xdt cyboi name. */
static wchar_t* LETTER_GRAPHIC_FORMAT_FIELD_XDT_CYBOI_NAME = L"letter_graphic_format";
static int* LETTER_GRAPHIC_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter image content field xdt cyboi name. */
static wchar_t* LETTER_IMAGE_CONTENT_FIELD_XDT_CYBOI_NAME = L"letter_image_content";
static int* LETTER_IMAGE_CONTENT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 1 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_1_name";
static int* FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 1 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_1_value";
static int* FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 2 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_2_name";
static int* FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 2 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_2_value";
static int* FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 3 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_3_name";
static int* FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 3 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_3_value";
static int* FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 4 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_4_name";
static int* FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 4 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_4_value";
static int* FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 5 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_5_name";
static int* FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 5 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_5_value";
static int* FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 6 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_6_name";
static int* FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 6 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_6_value";
static int* FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 7 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_7_name";
static int* FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 7 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_7_value";
static int* FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 8 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_8_name";
static int* FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 8 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_8_value";
static int* FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 9 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_9_name";
static int* FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 9 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_9_value";
static int* FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 10 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_10_name";
static int* FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 10 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_10_value";
static int* FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 11 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_11_name";
static int* FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 11 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_11_value";
static int* FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 12 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_12_name";
static int* FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 12 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_12_value";
static int* FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 13 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_13_name";
static int* FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 13 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_13_value";
static int* FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 14 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_14_name";
static int* FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 14 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_14_value";
static int* FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 15 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_15_name";
static int* FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 15 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_15_value";
static int* FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 16 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_16_name";
static int* FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 16 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_16_value";
static int* FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 17 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_17_name";
static int* FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 17 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_17_value";
static int* FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 18 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_18_name";
static int* FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 18 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_18_value";
static int* FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 19 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_19_name";
static int* FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 19 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_19_value";
static int* FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 20 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_20_name";
static int* FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 20 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_20_value";
static int* FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 21 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_21_name";
static int* FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 21 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_21_value";
static int* FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 22 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_22_name";
static int* FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 22 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_22_value";
static int* FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 23 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_23_name";
static int* FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 23 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_23_value";
static int* FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 24 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_24_name";
static int* FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 24 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_24_value";
static int* FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 25 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_25_name";
static int* FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 25 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_25_value";
static int* FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 26 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_26_name";
static int* FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 26 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_26_value";
static int* FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 27 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_27_name";
static int* FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 27 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_27_value";
static int* FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 28 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_28_name";
static int* FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 28 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_28_value";
static int* FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 29 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_29_name";
static int* FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 29 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_29_value";
static int* FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 30 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_30_name";
static int* FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 30 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_30_value";
static int* FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 31 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_31_name";
static int* FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 31 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_31_value";
static int* FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 32 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_32_name";
static int* FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 32 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_32_value";
static int* FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 33 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_33_name";
static int* FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 33 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_33_value";
static int* FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 34 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_34_name";
static int* FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 34 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_34_value";
static int* FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 35 name field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_35_name";
static int* FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The free record 6200 category 35 value field xdt cyboi name. */
static wchar_t* FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_CYBOI_NAME = L"free_record_6200_category_35_value";
static int* FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The record identification field xdt cyboi name. */
static wchar_t* RECORD_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"record_identification";
static int* RECORD_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The record size field xdt cyboi name. */
static wchar_t* RECORD_SIZE_FIELD_XDT_CYBOI_NAME = L"record_size";
static int* RECORD_SIZE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The device receiver gdt id field xdt cyboi name. */
static wchar_t* DEVICE_RECEIVER_GDT_ID_FIELD_XDT_CYBOI_NAME = L"device_receiver_gdt_id";
static int* DEVICE_RECEIVER_GDT_ID_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The device sender gdt id field xdt cyboi name. */
static wchar_t* DEVICE_SENDER_GDT_ID_FIELD_XDT_CYBOI_NAME = L"device_sender_gdt_id";
static int* DEVICE_SENDER_GDT_ID_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings kind field xdt cyboi name. */
static wchar_t* FINDINGS_KIND_FIELD_XDT_CYBOI_NAME = L"findings_kind";
static int* FINDINGS_KIND_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings device specifics field xdt cyboi name. */
static wchar_t* FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_CYBOI_NAME = L"findings_device_specifics";
static int* FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings test identification field xdt cyboi name. */
static wchar_t* FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"findings_test_identification";
static int* FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings test name field xdt cyboi name. */
static wchar_t* FINDINGS_TEST_NAME_FIELD_XDT_CYBOI_NAME = L"findings_test_name";
static int* FINDINGS_TEST_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings test status field xdt cyboi name. */
static wchar_t* FINDINGS_TEST_STATUS_FIELD_XDT_CYBOI_NAME = L"findings_test_status";
static int* FINDINGS_TEST_STATUS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings test result value field xdt cyboi name. */
static wchar_t* FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_CYBOI_NAME = L"findings_test_result_value";
static int* FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings test result unit field xdt cyboi name. */
static wchar_t* FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_CYBOI_NAME = L"findings_test_result_unit";
static int* FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings limit indicator field xdt cyboi name. */
static wchar_t* FINDINGS_LIMIT_INDICATOR_FIELD_XDT_CYBOI_NAME = L"findings_limit_indicator";
static int* FINDINGS_LIMIT_INDICATOR_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample material identification field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"findings_sample_material_identification";
static int* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_39_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample material index field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_CYBOI_NAME = L"findings_sample_material_index";
static int* FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample material name field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_CYBOI_NAME = L"findings_sample_material_name";
static int* FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample material specification field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_CYBOI_NAME = L"findings_sample_material_specification";
static int* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample collection date field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME = L"findings_sample_collection_date";
static int* FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample collection time (old format) field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_CYBOI_NAME = L"findings_sample_collection_time_old_format";
static int* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings data stream units field xdt cyboi name. */
static wchar_t* FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_CYBOI_NAME = L"findings_data_stream_units";
static int* FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings data stream field xdt cyboi name. */
static wchar_t* FINDINGS_DATA_STREAM_FIELD_XDT_CYBOI_NAME = L"findings_data_stream";
static int* FINDINGS_DATA_STREAM_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings sample collection time field xdt cyboi name. */
static wchar_t* FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME = L"findings_sample_collection_time";
static int* FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings germ identification field xdt cyboi name. */
static wchar_t* FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_CYBOI_NAME = L"findings_germ_identification";
static int* FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings germ name field xdt cyboi name. */
static wchar_t* FINDINGS_GERM_NAME_FIELD_XDT_CYBOI_NAME = L"findings_germ_name";
static int* FINDINGS_GERM_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings germ number field xdt cyboi name. */
static wchar_t* FINDINGS_GERM_NUMBER_FIELD_XDT_CYBOI_NAME = L"findings_germ_number";
static int* FINDINGS_GERM_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings resistance method field xdt cyboi name. */
static wchar_t* FINDINGS_RESISTANCE_METHOD_FIELD_XDT_CYBOI_NAME = L"findings_resistance_method";
static int* FINDINGS_RESISTANCE_METHOD_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings active substance field xdt cyboi name. */
static wchar_t* FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_CYBOI_NAME = L"findings_active_substance";
static int* FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings active substance generic name field xdt cyboi name. */
static wchar_t* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_CYBOI_NAME = L"findings_active_substance_generic_name";
static int* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings mhk breakpoint value field xdt cyboi name. */
static wchar_t* FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_CYBOI_NAME = L"findings_mhk_breakpoint_value";
static int* FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings resistance interpretation field xdt cyboi name. */
static wchar_t* FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_CYBOI_NAME = L"findings_resistance_interpretation";
static int* FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings normal value text field xdt cyboi name. */
static wchar_t* FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_CYBOI_NAME = L"findings_normal_value_text";
static int* FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings normal value lower limit field xdt cyboi name. */
static wchar_t* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_CYBOI_NAME = L"findings_normal_value_lower_limit";
static int* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings normal value upper limit field xdt cyboi name. */
static wchar_t* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_CYBOI_NAME = L"findings_normal_value_upper_limit";
static int* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings remark field xdt cyboi name. */
static wchar_t* FINDINGS_REMARK_FIELD_XDT_CYBOI_NAME = L"findings_remark";
static int* FINDINGS_REMARK_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings result text field xdt cyboi name. */
static wchar_t* FINDINGS_RESULT_TEXT_FIELD_XDT_CYBOI_NAME = L"findings_result_text";
static int* FINDINGS_RESULT_TEXT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings complimentary close field xdt cyboi name. */
static wchar_t* FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME = L"findings_complimentary_close";
static int* FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The findings signature field xdt cyboi name. */
static wchar_t* FINDINGS_SIGNATURE_FIELD_XDT_CYBOI_NAME = L"findings_signature";
static int* FINDINGS_SIGNATURE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium sender physician number field xdt cyboi name. */
static wchar_t* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME = L"data_medium_sender_physician_number";
static int* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium creation date field xdt cyboi name. */
static wchar_t* DATA_MEDIUM_CREATION_DATE_FIELD_XDT_CYBOI_NAME = L"data_medium_creation_date";
static int* DATA_MEDIUM_CREATION_DATE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium running number field xdt cyboi name. */
static wchar_t* DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_CYBOI_NAME = L"data_medium_running_number";
static int* DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data medium character code field xdt cyboi name. */
static wchar_t* DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_CYBOI_NAME = L"data_medium_character_code";
static int* DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package size field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_SIZE_FIELD_XDT_CYBOI_NAME = L"data_package_size";
static int* DATA_PACKAGE_SIZE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package mediums count field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_CYBOI_NAME = L"data_package_mediums_count";
static int* DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package character set field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_CYBOI_NAME = L"data_package_character_set";
static int* DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package adt version field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_ADT_VERSION_FIELD_XDT_CYBOI_NAME = L"data_package_adt_version";
static int* DATA_PACKAGE_ADT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package bdt version field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_BDT_VERSION_FIELD_XDT_CYBOI_NAME = L"data_package_bdt_version";
static int* DATA_PACKAGE_BDT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package gdt version field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_GDT_VERSION_FIELD_XDT_CYBOI_NAME = L"data_package_gdt_version";
static int* DATA_PACKAGE_GDT_VERSION_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package archiving type field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_CYBOI_NAME = L"data_package_archiving_type";
static int* DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package storage period field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_CYBOI_NAME = L"data_package_storage_period";
static int* DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The data package transfer begin field xdt cyboi name. */
static wchar_t* DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_CYBOI_NAME = L"data_package_transfer_begin";
static int* DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The system internal parametre field xdt cyboi name. */
static wchar_t* SYSTEM_INTERNAL_PARAMETRE_FIELD_XDT_CYBOI_NAME = L"system_internal_parameter";
static int* SYSTEM_INTERNAL_PARAMETRE_FIELD_XDT_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FIELD_XDT_CYBOI_NAME_CONSTANT_HEADER */
#endif
