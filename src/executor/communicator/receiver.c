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

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/communicator/receiver/file_system_receiver.c"
#include "../../executor/communicator/receiver/terminal_receiver.c"
#include "../../executor/communicator/receiver/inline_receiver.c"
#include "../../executor/communicator/receiver/latex_receiver.c"
#include "../../executor/communicator/receiver/socket_receiver.c"
#include "../../executor/communicator/receiver/x_window_system_receiver.c"
#include "../../executor/modifier/getter/knowledge_part_getter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Receives data via the given channel.
 *
 * CAUTION! Do NOT rename this function to "receive",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "read",
 * as that name is already used for glibc library's input.
 *
 * CAUTION! Some file formats (like the German xDT format for medical data exchange)
 * contain both, the model AND the properties, in one file. To cover these cases,
 * the model AND properties are received TOGETHER, in just one operation.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the type
 * @param p5 the channel
 * @param p6 the internal memory array
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive data.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The base internal.
            int base = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The communication partner-connected socket of this system.
            void** ps = NULL_POINTER_STATE_CYBOI_MODEL;

            // Get communication partner-connected socket of this system.
            i = base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &ps, p0, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);

    fwprintf(stdout, L"TEST ps: %i \n", *((int*) *ps));

            // Receive model by reading http request or response.
            //
            // CAUTION! The properties are handed over as well,
            // since they will store http headers as meta data.
            receive_socket(p0, p1, *ps, p20, p21, p18, p19, p1, p2);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) FILE_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Receive model by reading message data.
            //
            // CAUTION! The properties are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            receive_file_system(p0, p1, p2, p3, p4);

            // Receive properties by reading meta message data.
            //
            // CAUTION! Sometimes, the properties are read from a different source than the
            // model, for example the html attributes of an html table when creating a wui.
            //
            // Example:
            // <part name="receive_table_row" channel="inline" type="operation" model="receive">
            //     <property name="channel" channel="inline" type="character" model="file"/>
            //     <property name="language" channel="inline" type="character" model="compound"/>
            //     <property name="message" channel="inline" type="character" model="residenz/wui/address_table_row.cybol"/>
            //     <property name="meta" channel="inline" type="character" model="residenz/wui/address_table_row_properties.cybol"/>
            //     <property name="model" channel="inline" type="encapsulated" model=".residenz.temporary.translation.translate_record_to_wui.wui_patient_row"/>
            // </part>
//??            receive_file_system(p1, *NULL_POINTER_STATE_CYBOI_MODEL, mmd, mmc, lmd, lmc);

            //?? CAUTION! The function call above was commented out ON PURPOSE, since it caused a runtime error!
            //?? TODO: Figure out what happens inside, before uncommenting it again!
            //?? For the "inline" channel, this function call was commented out as well, as it is never needed.
            //?? For the "file" channel, however, it will be needed sometimes, for example for
            //?? xdt or html or http (if remembered correctly). Just figure this out later, when needed.
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
            // The terminal mutex.
            void** mt = NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminal input stream.
            void** is = NULL_POINTER_STATE_CYBOI_MODEL;

            // Get terminal mutex.
            get((void*) &mt, p0, (void*) TERMINAL_MUTEX_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);
            // Get terminal input stream.
            get((void*) &is, p0, (void*) TERMINAL_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);

            receive_terminal(p0, p1, *is, p12, p13, p1, p2, *mt);
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Receive model by reading message data.
            //
            // CAUTION! The properties are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            receive_inline(p0, p1, p2, p3, p4);

            //?? TODO: The following comment is outdated and may possibly be deleted.
            // CAUTION! Do NOT try to receive meta data here!
            // When calling the following function:
            // communicate_receiving_inline(p6, p7, p8, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p16, p17, p18, p19);
            // for some unclear reason the destination array is replaced and returned as null,
            // if source data do not exist. The normal behaviour, however, would be that
            // the destination array is left untouched if the source data are empty.
            // This has probably something to do with the function "replace_wide_character_vector",
            // but is this unclear.
            // It has not been investigated further, since inline data receiving does not
            // use meta data anyway, so that this will probably never be needed.
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Receive model by reading http request or response.
            //
            // CAUTION! The properties are handed over as well,
            // since they will store http headers as meta data.
//??            receive_socket(p0, p1, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) WWW_SERVICE_THREAD, (void*) &receive_socket_www, p1, p2, p3, p4, p5, p6, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) X_WINDOW_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            receive_x_window_system((void*) &p0, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive data. The channel is unknown.");
    }
}

/* RECEIVER_SOURCE */
#endif
