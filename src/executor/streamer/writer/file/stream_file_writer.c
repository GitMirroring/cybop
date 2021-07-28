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

#ifndef STREAM_FILE_WRITER_SOURCE
#define STREAM_FILE_WRITER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/file/opentype_file_model.c"
#include "../../../../executor/porter/file_stream_closer.c"
#include "../../../../executor/porter/file_stream_flusher.c"
#include "../../../../executor/porter/file_stream_opener.c"
#include "../../../../executor/streamer/writer/file/content_file_writer.c"
#include "../../../../logger/logger.c"

/**
 * Writes source model into file with the given name.
 *
 * @param p0 the destination file name data
 * @param p1 the destination file name count
 * @param p2 the source model data
 * @param p3 the source model count
 */
void write_file_stream(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write file stream.");

    // The file stream.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    open_file_stream((void*) &s, p0, p1, (void*) WRITE_OPENTYPE_FILE_MODEL);
    write_file_content(s, p2, p3);
    flush_file_stream(s);
    close_file_stream(s);
}

/* STREAM_FILE_WRITER_SOURCE */
#endif
