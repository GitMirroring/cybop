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

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects an xdt record by filtering the record name.
 *
 * @param p0 the destination root model item
 * @param p1 the destination record model item (pointer reference)
 * @param p2 the destination record model item
 * @param p3 the source part model data
 * @param p4 the source part model count
 * @param p5 the source part name data
 * @param p6 the source part name count
 * @param p7 the source part (pointer reference)
 */
void select_xdt_bdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt record.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Communication
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) COMMUNICATION_HEADER_RECORD_XDT_NAME, p2, (void*) COMMUNICATION_HEADER_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_communication_header();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) COMMUNICATION_FOOTER_RECORD_XDT_NAME, p2, (void*) COMMUNICATION_FOOTER_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_communication_footer();
        }
    }

    //
    // File
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) FILE_HEADER_RECORD_XDT_NAME, p2, (void*) FILE_HEADER_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_file_header();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) FILE_FOOTER_RECORD_XDT_NAME, p2, (void*) FILE_FOOTER_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_file_footer();
        }
    }

    //
    // BDT transfer
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) REFERENCED_SPECIFICATION_RECORD_XDT_NAME, p2, (void*) REFERENCED_SPECIFICATION_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_referenced_specification();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) INTERNAL_IDENTIFIER_RECORD_XDT_NAME, p2, (void*) INTERNAL_IDENTIFIER_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_internal_identifier();
        }
    }

    //
    // Medical practice
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) MEDICAL_PRACTICE_RECORD_XDT_NAME, p2, (void*) MEDICAL_PRACTICE_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_medical_practice();
            //?? deserialise_xdt_bdt_record(void* p0, void* p1, void* p2, void* p3);
            //?? deserialise_xdt_bdt_record();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) ADDRESSES_RECORD_XDT_NAME, p2, (void*) ADDRESSES_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_addresses();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) APPOINTMENTS_RECORD_XDT_NAME, p2, (void*) APPOINTMENTS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_appointments();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME, p2, (void*) DIAGNOSIS_ABBREVIATIONS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_diagnosis_abbreviations();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) SERVICE_NUMBERS_RECORD_XDT_NAME, p2, (void*) SERVICE_NUMBERS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_service_numbers();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME, p2, (void*) PRESCRIPTION_ABBREVIATIONS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_prescription_abbreviations();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) TREATMENT_BLOCKS_RECORD_XDT_NAME, p2, (void*) TREATMENT_BLOCKS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_treatment_blocks();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) TEXT_BLOCKS_RECORD_XDT_NAME, p2, (void*) TEXT_BLOCKS_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_text_blocks();
        }
    }

    //
    // Patient and treatment
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) PATIENT_RECORD_XDT_NAME, p2, (void*) PATIENT_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_patient();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) MEDICAL_TREATMENT_RECORD_XDT_NAME, p2, (void*) MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_medical_treatment();
        }
    }

    //
    // Billing [Abrechnungsnotizen (Behandlungsscheine)]
    //
    // 1 KVDT-Abrechnungen
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME, p2, (void*) KVDT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_medical_treatment();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_REFERRAL_CASE_RECORD_XDT_NAME, p2, (void*) KVDT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_referral_case();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME, p2, (void*) KVDT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_medical_treatment_with_cottage_hospital_affiliation();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME, p2, (void*) KVDT_MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_medical_emergency_service();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME, p2, (void*) KVDT_SADT_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_sadt_medical_treatment();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME, p2, (void*) KVDT_SADT_REFERRAL_CASE_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_sadt_referral_case();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME, p2, (void*) KVDT_SADT_MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_sadt_medical_treatment_with_cottage_hospital_affiliation();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME, p2, (void*) KVDT_CURE_MEDICAL_TREATMENT_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_cure_medical_treatment();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_GEVK_RECORD_XDT_NAME, p2, (void*) KVDT_GEVK_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_gevk();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_HAEVG_RECORD_XDT_NAME, p2, (void*) KVDT_HAEVG_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_haevg();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_MEDI_RECORD_XDT_NAME, p2, (void*) KVDT_MEDI_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_medi();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) KVDT_KV_RECORD_XDT_NAME, p2, (void*) KVDT_KV_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_kvdt_kv();
        }
    }

    //
    // Billing [Abrechnungsnotizen (Behandlungsscheine)]
    //
    // 2 Privatabrechnung
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) PRIVATE_BILLING_RECORD_XDT_NAME, p2, (void*) PRIVATE_BILLING_RECORD_XDT_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_xdt_bdt_record_private_billing();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt bdt record. The record is unknown.");
    }
}
