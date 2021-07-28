/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FILE_READER_SOURCE
#define FILE_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/file/opentype_file_model.c"
#include "../../../../executor/porter/file_stream_closer.c"
#include "../../../../executor/porter/file_stream_opener.c"
#include "../../../../executor/streamer/reader/file/content_file_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads file with the given name into destination item.
 *
 * @param p0 the destination item
 * @param p1 the source file name data
 * @param p2 the source file name count
 */
void read_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read file.");

    // The file stream.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    open_file_stream((void*) &s, p1, p2, (void*) READ_OPENTYPE_FILE_MODEL);
    read_file_content(p0, s);
    close_file_stream(s);
}

/* FILE_READER_SOURCE */
#endif
