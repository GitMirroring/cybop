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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FLAG_OPENER_SOURCE
#define FLAG_OPENER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/configurator/initialiser/initialiser.c"
#include "../../../executor/dispatcher/opener/device_opener.c"
#include "../../../executor/dispatcher/opener/stub_opener.c"
#include "../../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../../logger/logger.c"

/**
 * Opens a client either as standalone device or from request buffer, depending on the given server flag.
 *
 * CAUTION! Do NOT rename this function to "open_client",
 * as that name is already used by file "opener.c".
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the port
 * @param p2 the host address data (network communication) OR filename data (device, file, local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (device, file, local unix domain socket)
 * @param p4 the file open mode data
 * @param p5 the file open mode count
 * @param p6 the family data (namespace)
 * @param p7 the family count
 * @param p8 the style data (communication type)
 * @param p9 the style count
 * @param p10 the protocol data
 * @param p11 the protocol count
 * @param p12 the client entry
 * @param p13 the channel
 * @param p14 the server flag
 */
void open_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open flag.");
    //?? fwprintf(stdout, L"Debug: Open flag. server flag p14: %i\n", p14);
    //?? fwprintf(stdout, L"Debug: Open flag. server flag *p14: %i\n", *((int*) p14));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The channel comparison result.
    int rc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since standalone client has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p14, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    compare_integer_equal((void*) &rc, p13, (void*) SOCKET_CYBOI_CHANNEL);
    logify_boolean_and((void*) &r, (void*) &rc);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is either a STANDALONE client or a WINDOW.
        //
        // CAUTION! The client windows get a special treatment.
        // They are stored in the corresponding display server entry
        // and therefore require the server flag to be set to TRUE.
        // However, the windows have to be opened MANUALLY by the
        // developer through calling the cybol operation "dispatch/open".
        // Therefore, the "open_device" function HAS TO BE called.
        //

        // Open device.
        open_device(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);

        //
        // Initialise device.
        //
        //?? TODO:
        //
        // Add baudrate for serial device here
        // that was read from a cybol property.
        // As temporary solution, NULL is handed over.
        //
        initialise(p0, p12, *NULL_POINTER_STATE_CYBOI_MODEL, p13);

    } else {

        //
        // This is a client STUB on the server side of a SOCKET channel.
        //
        // When a server socket receives a client request, then
        // that request is stored as client socket number (stub).
        // It is pre-configured by the server socket and thus
        // does NOT need to be configured here again.
        // Therefore, the "open_device" function is NOT called.
        //

        // Open client stub.
        open_stub(p0, p12);
    }
}

/* FLAG_OPENER_SOURCE */
#endif
