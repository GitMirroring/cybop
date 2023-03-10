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

#ifndef LOG_FILE_OPTIONALISER_SOURCE
#define LOG_FILE_OPTIONALISER_SOURCE

#include <sys/stat.h> // chmod
#include <stdio.h> // fopen
#include <unistd.h> // chown

#include "../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../logger/logger.c"

/**
 * Optionalises the log file option.
 *
 * @param p0 the log file stream (pointer reference)
 * @param p1 the terminated logfile name item (multibyte character data)
 */
void optionalise_log_file(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE** f = (FILE**) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write((void*) stdout, L"Debug: Optionalise log file.\n");

        // The terminated file name item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get terminated file name item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &td, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Open log file for writing only.
        // If the file already exists, it is truncated to zero length.
        // Otherwise a new file is created.
        //
        // FILE objects are allocated and managed internally by the input/ output
        // library functions. The library creates objects of type FILE.
        // Programs should deal only with pointers to these objects (FILE* values),
        // rather than the objects themselves.
        *f = fopen((char*) td, "w");

        if (((void*) *f) != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The file owner.
            int o = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The file group.
            int g = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

            // Set file owner.
#ifdef WIN32
            // ...
#else
            int e = chown((char*) td, o, g);
#endif

            // The file access rights.

            // Set file access rights.
#ifdef WIN32
            //?? TODO: When trying to cross-compile cyboi for windows,
            //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
            // ...
#else
            int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;
            chmod((char*) td, r);
#endif

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // log_write((void*) stdout, L"Error: Could not optionalise log file. An error occured when trying to open or create the file for writing.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Error: Could not optionalise log file. The file descriptor is null.\n");
    }
}

/* LOG_FILE_OPTIONALISER_SOURCE */
#endif
