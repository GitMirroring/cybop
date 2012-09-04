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

#ifndef PACKAGE_XDT_DESERIALISER_SOURCE
#define PACKAGE_XDT_DESERIALISER_SOURCE

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
 * Deserialises an xdt package.
 *
 * @param p0 the package size (pointer reference)
 * @param p1 the package header (pointer reference)
 * @param p2 the package header count (pointer reference)
 * @param p3 the package footer (pointer reference)
 * @param p4 the package footer count (pointer reference)
 * @param p5 the package content (pointer reference)
 * @param p6 the package content count (pointer reference)
 * @param p7 the source byte array (pointer reference)
 * @param p8 the source byte array count
 */
void deserialise_xdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p8;

        if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** s = (void**) p7;

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pcc = (int*) p6;

                if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    void** pc = (void**) p5;

                    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* pfc = (int*) p4;

                        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            void** pf = (void**) p3;

                            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                int* phc = (int*) p2;

                                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    void** ph = (void**) p1;

                                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                        int* ps = (int*) p0;

                                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt package.");

                                        // Reset package size.
                                        *ps = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                        // The remaining bytes in the source byte array.
                                        // They are used to check that the array border
                                        // is not crossed, and to leave the loop.
                                        int rem = *sc;
                                        // The record size.
                                        int rs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                        // The record identification.
                                        int rid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                        // The loop variable.
                                        int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                                        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                            if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                                break;
                                            }

                                            // Decode xdt record (size, identification, content).
                                            //
                                            // CAUTION! The package header and -footer count are
                                            // handed over as parametres to get the record content.
                                            // A local variable defined in this function may NOT
                                            // be used as its value is lost when returning from
                                            // this function. But a valid value has to be
                                            // returned to the calling function.
                                            deserialise_xdt_record((void*) &rs, (void*) &rid, p3, p4, p7, (void*) &rem);

/*??
                                            // Test values.
                                            fwprintf(stdout, L"Test: Decode xdt package. Record size rs: %i\n", rs);
                                            fwprintf(stdout, L"Test: Decode xdt package. Record identification id: %i\n", rid);
                                            fwprintf(stdout, L"Test: Decode xdt package. Record content count pfc: %i\n\n", *pfc);
*/

                                            if (rs > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                                // Decrement remaining bytes in the source byte array.
                                                rem = rem - rs;

                                                // Increment package size.
                                                *ps = *ps + rs;

                                                // Increment loop variable.
                                                j = j + rs;

                                                if (rid == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

                                                    // Store xdt package header.
                                                    //
                                                    // CAUTION! This is only the record content
                                                    // WITHOUT the record size and -identification!
                                                    *ph = *pf;
                                                    *phc = *pfc;

/*??
                                                    // Test values.
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package header: %i\n", *ph);
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package header count: %i\n\n", *phc);
*/

                                                    // Store xdt package content.
                                                    //
                                                    // CAUTION! Everything following this package
                                                    // header record up to the package footer
                                                    // record belongs to the package's content.
                                                    *pc = *s;

                                                    // Reset loop variable.
                                                    j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                                                } else if (rid == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

                                                    // CAUTION! The package footer does NOT
                                                    // have to be stored here explicitly.
                                                    // It was already handed over as parametre
                                                    // to the "deserialise_xdt_record" function,
                                                    // so that its value is already set.

/*??
                                                    // Test values.
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package footer: %i\n", *pf);
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package footer count: %i\n\n", *pfc);
*/

                                                    // Decrement package content count.
                                                    //
                                                    // CAUTION! The package content count pcc was
                                                    // reset when the data package header record
                                                    // was found and steadily increased since then.
                                                    //
                                                    // It needs to be decremented here, because
                                                    // the current record size rs was added above,
                                                    // but this data package footer record does
                                                    // NOT belong to the data package content
                                                    // and hence should not be counted.
                                                    *pcc = j - rs;

                                                    // CAUTION! Do NOT decrement the package
                                                    // size, as this package footer record
                                                    // DOES belong to the package!

                                                    // Set remaining bytes to zero, as the package footer
                                                    // has been detected and the loop can be left now.
                                                    rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                                }

                                            } else {

                                                // If the xdt record size is zero or smaller, then
                                                // increment the source xdt byte array index by one,
                                                // in order to ensure that this loop will finally
                                                // find an end.
                                                *s = *s + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                                                rem = rem - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                                                // Increment package size.
                                                *ps = *ps + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                                                // Increment loop variable.
                                                j = j + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                                            }
                                        }

                                    } else {

                                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package size is null.");
                                    }

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package header is null.");
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package header count is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package footer is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package footer count is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package content is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The package content count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The source byte array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt package. The source byte array count is null.");
    }
}

/**
 * Processes the xdt package.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source package
 * @param p4 the source package count
 */
void deserialise_xdt_process_package(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void* s = (void*) p3;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Process xdt package.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The record size.
            int rs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The record identification.
            int rid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The record content.
            void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;
            int rcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    break;
                }

                // Decode xdt record (size, identification, content).
                deserialise_xdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fwprintf(stdout, L"\nTest: Process xdt package. Record size rs: %i\n", rs);
                fwprintf(stdout, L"Test: Process xdt package. Record identification id: %i\n", rid);
                fwprintf(stdout, L"Test: Process xdt package. Record content count pfc: %i\n", rcc);
*/

                if (rs > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Increment source xdt byte array index,
                    // so that following records may be found
                    // in the next loop cycle.
//??                    s = s + rs;
                    rem = rem - rs;

                    deserialise_xdt_select_record(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);

                } else {

                    // If the xdt record size is zero or smaller, then
                    // increment the source xdt byte array index by one,
                    // in order to ensure that this loop will find an end.
                    s = s + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                    rem = rem - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not process xdt package. The source package is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not process xdt package. The source package count is null.");
    }
}

/* PACKAGE_XDT_DESERIALISER_SOURCE */
#endif
