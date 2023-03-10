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
 * @author Franziska Wehner>
 */

#ifndef APPLICATION_X_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define APPLICATION_X_STATE_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Application (non-standard)
//
// IANA media type: application/x-
//

/**
 * The application/x-httpd-php state cybol format.
 *
 * PHP files
 *
 * Common file suffixes: php, phtml
 */
static wchar_t* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-httpd-php";
static int* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-httpd-php-source state cybol format.
 *
 * PHP source files
 */
static wchar_t* X_HTTPD_PHP_SOURCE_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-httpd-php-source";
static int* X_HTTPD_PHP_SOURCE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-javascript state cybol format.
 *
 * TODO: Description:
 *
 * A JavaScript program script.
 *
 * Common file suffixes: js
 *
 * There are three MIME assignments for javascript data:
 * - application/javascript (official)
 * - application/x-javascript (outdated)
 * - text/javascript (unofficial)
 *
 * Preference should be given to the OFFICIAL mime type "application/javascript".
 *
 * TODO: Examples:
 *
 * <node name="program_source_code" channel="file" format="application/x-javascript" model="path/to/file.js"/>
 */
static wchar_t* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-javascript";
static int* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-latex state cybol format.
 *
 * LaTeX files.
 * Common file suffixes: tex
 */
static wchar_t* X_LATEX_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-latex";
static int* X_LATEX_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-rar-compressed state cybol format.
 *
 * RAR archive files
 */
static wchar_t* X_RAR_COMPRESSED_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-rar-compressed";
static int* X_RAR_COMPRESSED_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shockwave-flash state cybol format.
 *
 * Adobe shockwave flash files documented in Adobe TechNote tn_4151 and Adobe TechNote tn_16509.
 *
 * Common file suffixes: swf, cab
 */
static wchar_t* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-shockwave-flash";
static int* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-stuffit state cybol format.
 *
 * StuffIt archive files.
 *
 * Common file suffixes: sit
 */
static wchar_t* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-stuffit";
static int* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tar state cybol format.
 *
 * Tarball files.
 * Common file suffixes: tar
 */
static wchar_t* X_TAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-tar";
static int* X_TAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* APPLICATION_X_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
