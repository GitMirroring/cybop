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

#ifndef RECORD_XDT_DESERIALISER_SOURCE
#define RECORD_XDT_DESERIALISER_SOURCE

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
 * Deserialises an xdt record.
 *
 * @param p0 the record size (pointer reference)
 * @param p1 the record identification (pointer reference)
 * @param p2 the record content (pointer reference)
 * @param p3 the record content count (pointer reference)
 * @param p4 the source byte array (pointer reference)
 * @param p5 the source byte array count
 */
void deserialise_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** s = (void**) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* rcc = (int*) p3;

                if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    void** rc = (void**) p2;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* rs = (int*) p0;

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record.");

                        // Reset record size.
                        *rs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The remaining bytes in the source byte array.
                        // They are used to check that the array border is not crossed.
                        int rem = (*sc * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                        // The field size.
                        int fs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The field identification.
                        int fid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The field content.
                        void* fc = *NULL_POINTER_STATE_CYBOI_MODEL;
                        int fcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The verification flag.
                        int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The next field count.
                        int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The decode/ parse mode:
                        // 0 - looking for the begin of a record
                        // 1 - within a record, looking for the begin of the next
                        //     record, which demarcates the end of this record
                        int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                            if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                break;
                            }

                            // Decode xdt field (size, identification, content).
                            deserialise_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, p4, (void*) &rem);

/*??
                            // Test values.
                            fwprintf(stdout, L"Test: Decode xdt record. Field size fs: %i\n", fs);
                            fwprintf(stdout, L"Test: Decode xdt record. Field identification id: %i\n", fid);
                            fwprintf(stdout, L"Test: Decode xdt record. Field content count fcc: %i\n", fcc);
*/

                            if (v == *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

                                // The verification flag is set, which means that
                                // the xdt field was decoded correctly and the carriage
                                // return plus line feed characters were reached.

                                // Decrement remaining bytes in the source byte array.
                                rem = rem - fs;

                                // Increment record size.
                                *rs = *rs + fs;
                                // Increment record content count.
                                *rcc = *rcc + fs;

                                if (fid == *RECORD_IDENTIFICATION_FIELD_XDT_NAME) {

                                    if (m == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                        // Set decode/parse mode to "1".
                                        // This is the begin of a record.
                                        m = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                                        // Decode xdt record identification.
//??                                        deserialise_cybol_integer(p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, fc, (void*) &fcc);

                                    } else {

                                        // The current decode mode is "1", which means that
                                        // the begin of a record had been detected before.
                                        // So, this record identification field already
                                        // belongs to the next following record.
                                        // The previous record's end has thus been reached.

                                        // Decrement source xdt byte array index,
                                        // so that the record identification field
                                        // that had been detected right before
                                        // can be found once more as it represents
                                        // the beginning of the next xdt record.
                                        *s = *s - fs;

                                        // CAUTION! The record size and -content count
                                        // were reset when the record size field was
                                        // found and steadily increased since then.
                                        //
                                        // Both need to be decremented here, because
                                        // the current field size fs was added above!
                                        //
                                        // Since this record identification field
                                        // already belongs to the next record,
                                        // it MUST NOT be counted here!

                                        // Decrement record size.
                                        *rs = *rs - fs;
                                        // Decrement record content count.
                                        *rcc = *rcc - fs;

                                        // Set remaining bytes to zero, as the next record
                                        // has been detected and the loop can be left now.
                                        rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                    }

                                } else if (fid == *RECORD_SIZE_FIELD_XDT_NAME) {

                                    // Decode xdt record size.
                                    //
                                    // CAUTION! Do NOT use the following line:
                                    // deserialise_cybol_integer(p0, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, fc, (void*) &fcc);
                                    //
                                    // This is because the record content size is
                                    // counted using the loop variable j.
                                    // This is safer than relying on the given record size.

                                    // Store xdt record content.
                                    //
                                    // CAUTION! Everything following this record
                                    // size field belongs to its content.
                                    // The pointer s was already increased above,
                                    // so that the record size and -identification
                                    // are NOT included!
                                    // The current value of s points to the beginning
                                    // of the first field of the record's CONTENT.
                                    *rc = *s;

                                    // Reset record content count, in order to
                                    // count the xdt record content now following.
                                    *rcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                }

                            } else {

                                // The verification flag is NOT set, which means
                                // that the xdt field was NOT decoded correctly.

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                                // Reset next field count.
                                nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                                // Count the number of bytes to the next carriage return-
                                // plus line feed character.
                                deserialise_xdt_next_field((void*) &nc, *s, (void*) &rem);

                                // Increment source xdt byte array index, so that following
                                // fields may be found in the next loop cycle.
                                *s = *s + nc;
                                rem = rem - nc;

                                // Increment record size.
                                *rs = *rs + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                                // Increment record content count.
                                *rcc = *rcc + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            }
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. The record size is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. The record content is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. The record content count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. The source byte array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record. The source byte array count is null.");
    }
}

/**
 * Processes the xdt record.
 *
 * @param p0 the destination compound
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source record
 * @param p4 the source record count
 */
void deserialise_xdt_process_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void* s = (void*) p3;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Process xdt record.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The field identification.
            int fid = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The field content.
            void* fc = *NULL_POINTER_STATE_CYBOI_MODEL;
            int fcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The verification flag.
            int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The next field count.
            int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    break;
                }

                // Decode xdt field (size, identification, content).
                deserialise_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fwprintf(stdout, L"Test: Process xdt record. Field size fs: %i\n", fs);
                fwprintf(stdout, L"Test: Process xdt record. Field identification id: %i\n", fid);
                fwprintf(stdout, L"Test: Process xdt record. Field content count fcc: %i\n", fcc);
*/

                if (v == *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

                    // The verification flag is set, which means that
                    // the xdt field was decoded correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source xdt byte array index,
                    // so that following fields may be found
                    // in the next loop cycle.
//??                    s = s + fs;
                    rem = rem - fs;

                    deserialise_xdt_select_field(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

                } else {

                    // The verification flag is NOT set, which means
                    // that the xdt field was NOT decoded correctly.

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not process xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    deserialise_xdt_next_field((void*) &nc, s, (void*) &rem);

                    // Increment source xdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rem = rem - nc;
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not process xdt record. The source record is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not process xdt record. The source record count is null.");
    }
}

/* RECORD_XDT_DESERIALISER_SOURCE */
#endif
