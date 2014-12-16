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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SENDER_SOURCE
#define SOCKET_SENDER_SOURCE

//?? TEST for test file; DELETE later!
#include <sys/stat.h>
#include <fcntl.h>
//?? TEST END

/*??
#include <netinet/in.h>
#include <sys/socket.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cybol/communication_mode_cybol_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/datagram_socket_sender.c"
#include "../../../../executor/communicator/sender/raw_socket_sender.c"
#include "../../../../executor/communicator/sender/stream_socket_sender.c"
#include "../../../../executor/representer/serialiser.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/socket_type_size.c"

/**
 * Sends a message via socket.
 *
 * @param p11 the message type
 * @param p12 the message type count
 * @param p13 the message model
 * @param p14 the message model count
 * @param p15 the message properties
 * @param p16 the message properties count
 * @param p17 the knowledge memory
 * @param p18 the knowledge memory count
 * @param p19 the language
 * @param p20 the language count
 */
void send_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

//?? --- START TEST ---
    // The log file name.
    char* n = "http_response";
    // The log file status flags.
    int status = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, status);

    if (f >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The file owner.
        int o = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // The file group.
        int g = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // Log html to output.
        write(f, p13, *((int*) p14));

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        log_write(stdout, L"Error: Could not open socket sending http_response file. A file error occured.\n");
    }
//?? --- END TEST ---

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send socket.");

    //?? TODO: Distinguish between stream/datagram/raw socket here. Nothing more.

    // Send message via socket in server mode.
    send_stream_socket((void*) *s, p13, p14, (void*) &sa, (void*) &sas, p9, p10);
}

/* SOCKET_SENDER_SOURCE */
#endif
