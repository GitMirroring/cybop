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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECORD_XDT_SELECTOR_SOURCE
#define RECORD_XDT_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Selects the xdt record.
 *
 * @param p0 the destination model item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the source record identification
 */
void select_xdt_record(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt record.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) TAG_END_XML_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign record name (identification).
            ...
        }
    }

--
    if (*id == *MEDICAL_PRACTICE_DATA_RECORD_XDT_NAME) {

        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_MEDIUM_HEADER_RECORD_XDT_NAME) {

        //?? TODO

    } else if (*id == *DATA_MEDIUM_FOOTER_RECORD_XDT_NAME) {

        //?? TODO

    } else if (*id == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

        // Decode package header (meta data 1).
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME, (void*) PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

        // Decode package footer (meta data 2).
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME, (void*) PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *MEDICAL_TREATMENT_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *REFERRAL_CASE_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) REFERRAL_CASE_RECORD_XDT_CYBOI_NAME, (void*) REFERRAL_CASE_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PRIVATE_BILLING_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME, (void*) PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME, (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *UNSTRUCTURED_CASES_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME, (void*) UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_MASTER_DATA_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *MEDICAL_TREATMENT_DATA_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EXAMINATION_REQUEST_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EXAMINATION_DATA_TRANSFER_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT);

    } else if (*id == *EXAMINATION_DATA_DISPLAY_RECORD_XDT_NAME) {

        // CAUTION! Hand over a null pointer in place of the model and model count!
        deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
            (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME_COUNT);
    }

    // Process xdt record content.
    deserialise_xdt_process_record(m, mc, ms, p3, p4);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* RECORD_XDT_SELECTOR_SOURCE */
#endif
