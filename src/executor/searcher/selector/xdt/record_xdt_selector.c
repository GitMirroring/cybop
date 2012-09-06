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

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/name/xdt/package_xdt_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the xdt record.
 *
 * @param p0 the destination model item
 * @param p3 the source record data
 * @param p4 the source record count
 * @param p5 the source record identification
 */
void select_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* id = (int*) p5;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt record.");

//??        fwprintf(stdout, L"TEST: Select xdt record identification: %i\n", *id);

/*??
        // The part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

        if (*id == *MEDICAL_PRACTICE_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_HEADER_RECORD_XDT_NAME) {

            //?? TODO

        } else if (*id == *DATA_MEDIUM_FOOTER_RECORD_XDT_NAME) {

            //?? TODO

        } else if (*id == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

            // Decode package header (meta data 1).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME, (void*) PACKAGE_HEADER_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

            // Decode package footer (meta data 2).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME, (void*) PACKAGE_FOOTER_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *REFERRAL_CASE_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) REFERRAL_CASE_RECORD_XDT_CYBOI_NAME, (void*) REFERRAL_CASE_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *PRIVATE_BILLING_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME, (void*) PRIVATE_BILLING_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME, (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *UNSTRUCTURED_CASES_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME, (void*) UNSTRUCTURED_CASES_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME, (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME, (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *EXAMINATION_REQUEST_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_REQUEST_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *EXAMINATION_DATA_TRANSFER_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_CYBOI_NAME_COUNT);

        } else if (*id == *EXAMINATION_DATA_DISPLAY_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parametres do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            deserialise_xdt_deserialise_model((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT,
                (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME, (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_CYBOI_NAME_COUNT);
        }

        // Process xdt record content.
        deserialise_xdt_process_record(m, mc, ms, p3, p4);

        // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
        if ((n != *NULL_POINTER_STATE_CYBOI_MODEL) && (nc != *NULL_POINTER_STATE_CYBOI_MODEL) && (ns != *NULL_POINTER_STATE_CYBOI_MODEL)
            && (a != *NULL_POINTER_STATE_CYBOI_MODEL) && (ac != *NULL_POINTER_STATE_CYBOI_MODEL) && (as != *NULL_POINTER_STATE_CYBOI_MODEL)) {

            // Add xdt record to xdt package.
            //
            // CAUTION! Hand over the name as reference, as it gets changed by adding
            // an index as name suffix, to uniquely identify the record within the compound.
            append_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            //?? The following remark stems from the old parser version.
            //?? It is likely to be outdated and this block may possibly be removed.
            // Destroy all arrays, since they were not added to the compound.
            // CAUTION! If this was not done here, they would never be deallocated!
            // CAUTION! Use DESCENDING order, as opposed to array allocation!
        }
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt record. The record identification is null.");
    }
}

/* RECORD_XDT_SELECTOR_SOURCE */
#endif
