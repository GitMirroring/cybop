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

#ifndef COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Command
//
// IANA media type: not defined
// Self-defined media type: command
// This media type is a CYBOL extension.
//

/**
 * The command/archive logic cybol format.
 *
 * Description:
 *
 * Archives the given files into a packed format via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="archive" channel="inline" format="command/archive" model="">
 *     <node name="create" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="update" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="bzip2" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * Properties:
 *
 * - create (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating the creation of an archive.
 * - update (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating the updating of an archive.
 * - bzip2 (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating usage of the bzip2 compression algorithm.
 */
static wchar_t* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/archive";
static int* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-directory logic cybol format.
 *
 * Description:
 *
 * Changes the current working directory via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="change_directory" channel="inline" format="command/change-directory" model="">
 *     <node name="directory" channel="inline" format="text/plain" model="../src/controller/"/>
 * </node>
 *
 * Properties:
 *
 * - directory (required) [text/cybol-path | text/plain]: The new working directory.
 */
static wchar_t* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-directory";
static int* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-permission logic cybol format.
 *
 * Description:
 *
 * Changes the permission of a file or directory via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="TODO" channel="inline" format="command/TODO" model="">
 *     <node name="TODO" channel="inline" format="text/cybol-path" model=""/>
 * </node>
 *
 * Properties:
 *
 * - path (required) [text/cybol-path | text/plain]: The filesystem path to the file or directory.
 * - user (required) [text/cybol-path | text/plain]: TODO
 * - group (required) [text/cybol-path | text/plain]: TODO
 * - other (required) [text/cybol-path | text/plain]: TODO
 * - recursive (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating recursive processing.
 * - silent (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating suppression of errors.
 * - verbose (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that a diagnostic output is wanted for every file.
 */
static wchar_t* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-permission";
static int* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/clear logic cybol format.
 *
 * Description:
 *
 * Clears the terminal (console) screen via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="clear" channel="inline" format="command/clear" model=""/>
 *
 * Properties:
 */
static wchar_t* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT = L"command/clear";
static int* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/compare-files logic cybol format.
 *
 * Description:
 *
 * Compares two files via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT = L"command/compare-files";
static int* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/config-network logic cybol format.
 *
 * Description:
 *
 * Configures the network via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT = L"command/config-network";
static int* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/copy logic cybol format.
 *
 * Description:
 *
 * Copies the given file into another via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - source (required) [text/cybol-path | text/plain]: The source file to be copied.
 * - destination (required) [text/cybol-path | text/plain]: The destination to copy to.
 * - force (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating not to ask for permission for overwriting files or directories.
 * - interactive (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating to ask everytime for permission of overwriting a file or directory.
 * - preserve_all_attributes (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that copied files and directories will have the same attributes as the originals.
 * - preserve_links (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that links are preserved so that they are not dereferenced while copying.
 * - recursive (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that all sub directories should be copied as well.
 * - update (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that just more recent data are copied to a destination path.
 * - verbose (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that the names of copied files and directories are shown.
 */
static wchar_t* COPY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/copy";
static int* COPY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/create-directory logic cybol format.
 *
 * Description:
 *
 * Creates a directory (folder) in the file system via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - path (required) [text/cybol-path]: The filesystem path to the directory to be created.
 */
static wchar_t* CREATE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/create-directory";
static int* CREATE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/date logic cybol format.
 *
 * Description:
 *
 * Prints out the date or changes it via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - new (optional) [text/cybol-path]: The value of the new date.
 */
static wchar_t* DATE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/date";
static int* DATE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/delay logic cybol format.
 *
 * Description:
 *
 * Delays execution for the given number of seconds via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - time (required) [text/cybol-path | number/integer]: The time in seconds.
 */
static wchar_t* DELAY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/delay";
static int* DELAY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/diff logic cybol format.
 *
 * Description:
 *
 * Displays differences between two files via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="diff" channel="inline" format="command/diff" model="">
 *     <node name="first" channel="inline" format="text/plain" model="shell_command_diff/diff_1.txt"/>
 *     <node name="second" channel="inline" format="text/plain" model="shell_command_diff/diff_2.txt"/>
 * </node>
 *
 * Properties:
 *
 * - first (required) [text/cybol-path | text/plain]: The first file.
 * - second (required) [text/cybol-path | text/plain]: The second file.
 */
static wchar_t* DIFF_COMMAND_LOGIC_CYBOL_FORMAT = L"command/diff";
static int* DIFF_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/disk-free logic cybol format.
 *
 * Description:
 *
 * Displays the free disk space via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - all (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that files with a size of 0 blocks shall be listed.
 * - human (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating human-readable output.
 * - kilobytes (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating size output in kilobytes.
 * - local (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that only local filesystems shall be listed.
 * - megabytes (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating size output in megabytes.
 * - type (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating output of each filesystem's type.
 */
static wchar_t* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/disk-free";
static int* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/disk-usage logic cybol format.
 *
 * Description:
 *
 * Shows the usage of a directory via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - human (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating human-readable output.
 * - summarise (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that a summary shall be printed.
 * - all (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that all shall be printed.
 * - bytes (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating size output in bytes.
 * - total (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that the total usage shall be printed.
 */
static wchar_t* DISK_USAGE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/disk-usage";
static int* DISK_USAGE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/display-content logic cybol format.
 *
 * Description:
 *
 * Displays the content of one or more text files via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - path (optional) [text/cybol-path | text/plain]: The file whose content is to be printed.
 * - clear (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating to clear the screen before display.
 * - numbers (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that output lines shall be numbered.
 * - squeeze (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating that multiple blank lines shall be merged into a single line.
 */
static wchar_t* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/display-content";
static int* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/echo logic cybol format.
 *
 * Description:
 *
 * Prints the given message to standard output via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="echo_text" channel="inline" format="command/echo" model="">
 *     <node name="message" channel="inline" format="text/plain" model="Hello World!"/>
 * </node>
 *
 * Properties:
 *
 * - message (optional) [text/cybol-path | text/plain]: The message to be sent to standard output.
 */
static wchar_t* ECHO_COMMAND_LOGIC_CYBOL_FORMAT = L"command/echo";
static int* ECHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-command logic cybol format.
 *
 * Description:
 *
 * Locates the command binary, source, or manual page files via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - command (required): command to be processed
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - binary (optional, Unix): Search only for binaries.
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - manual (optional, Unix): Search only for manual sections.
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - source (optional, Unix): Search only for source files.
 */
static wchar_t* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-command";
static int* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-file logic cybol format.
 *
 * Description:
 *
 * Finds a file via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - path: the path including wildcards for deleting files and directories
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - insensitive (optional): the insensitive option (ignore upper/lowercase when searching for a file, Unix only)
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - recursive(optional): the recursive option (recursive search, Windows only)
 */
static wchar_t* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-file";
static int* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/grep logic cybol format.
 *
 * Description:
 *
 * Searches for a pattern in the file and prints out those lines matching the pattern via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="grep" channel="inline" format="command/grep" model="">
 *     <node name="pattern" channel="inline" format="text/plain" model="test"/>
 *     <node name="file" channel="inline" format="text/plain" model="test/grep.txt"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - pattern (required): pattern, to search for
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - file (required): file, to search in
 */
static wchar_t* GREP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/grep";
static int* GREP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/help logic cybol format.
 *
 * Description:
 *
 * Displays information about a system command via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - pattern (required): the command for which information should be displayed
 */
static wchar_t* HELP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/help";
static int* HELP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/hostname logic cybol format.
 *
 * Description:
 *
 * Displays the name of the host (machine) via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - options: d, f, i, I, s
 */
static wchar_t* HOSTNAME_COMMAND_LOGIC_CYBOL_FORMAT = L"command/hostname";
static int* HOSTNAME_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/id logic cybol format.
 *
 * Description:
 *
 * Displays the identification (id) of the user or group via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* ID_COMMAND_LOGIC_CYBOL_FORMAT = L"command/id";
static int* ID_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ifconfig logic cybol format.
 *
 * Description:
 *
 * Calls ifconfig via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* IFCONFIG_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ifconfig";
static int* IFCONFIG_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ifup logic cybol format.
 *
 * Description:
 *
 * Shows if the network interface is available, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* IFUP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ifup";
static int* IFUP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/kill logic cybol format.
 *
 * Description:
 *
 * Kills an application or system process via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - pid (required): the number of process to be killed off
 */
static wchar_t* KILL_COMMAND_LOGIC_CYBOL_FORMAT = L"command/kill";
static int* KILL_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/list-directory-contents logic cybol format.
 *
 * Description:
 *
 * Lists the contents of the given directory via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - path (optional): the listing for the given path (the default is the current directory)
 * - all (optional): the list all option (showing hidden, current . and upper .. directory)
 * - long (optional): the long listing option (showing user rights etc.)
 * - one row per entry (optional): the listing for showing one file or directory per row
 * - recursive (optional): the list for all files and directories, looking up all directories recursively for additional files and directories for the listing
 * - short (optional): the short version of the files and directory listing
 * - sort by file size (optional): sorts the current listing by file size
 * - sort by modification date (optional): sorts the current listing by the file and directory modification date
 * - sort by extension (optional): sorts the current listing alphabetically by file extension
 */
static wchar_t* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-directory-contents";
static int* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/list-open-files logic cybol format.
 *
 * Description:
 *
 * Shows open files in operating system via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - listuid(optional): the list-uid option (list-uid output)
 * - listfilesize(optional): the list-file-size option (prints the file size)
 * - listtasks(optional): the list-tasks option (lists tasks)
 * - disabletasks(optional): the disable-tasks option (disables tasks)
 * - terselisting(optional): the terse-listing option (shows the terse listing)
 */
static wchar_t* LIST_OPEN_FILES_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-open-files";
static int* LIST_OPEN_FILES_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/list-tasks logic cybol format.
 *
 * Description:
 *
 * Lists all processes currently running on the computer, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - keyword(optional): the keyword option (list all the keyword options)
 * - verbose(optional): the verbose option (verbose output)
 */
static wchar_t* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-tasks";
static int* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/memory-free logic cybol format.
 *
 * Description:
 *
 * Shows the usage of Random Access Memory (RAM), via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - human(optional): the human option (human-readable output)
 * - kilobytes(optional): the kilobytes option (print sizes in kilobytes)
 * - megabytes(optional): the megabytes option (print sizes in megabytes)
 * - gigabytes(optional): the gigabytes option (print sizes in gigabytes)
 * - total(optional): the total option (print total for RAM + swap)
 */
static wchar_t* MEMORY_FREE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/memory-free";
static int* MEMORY_FREE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/move logic cybol format.
 *
 * Description:
 *
 * Moves a file or directory to a destination path, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="move_file" channel="inline" format="command/move" model="">
 *     <node name="destination" channel="inline" format="text/plain" model="./shell_command_move_file/moved_and_please_do_not_commit_me.txt"/>
 *     <node name="source" channel="inline" format="text/plain" model="./shell_command_move_file/original.txt"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="interactive" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="verbose" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - source (required): the path of the file or the directory which sould be moved
 * - destination (required): the new path of the source file or directory
 * - force (optional): the force option (never ask for permission to move any files or directories)
 * - interactive (optional): the interactive option (askes everytime for permission of moving a file or directory)
 * - verbose(optional): the verbose option (shows what have been moved)
 */
static wchar_t* MOVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/move";
static int* MOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/netstat logic cybol format.
 *
 * Description:
 *
 * Displays network information via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - options: -r, i, g, s, M, v, n, e, p, l, a, o, t
 */
static wchar_t* NETSTAT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/netstat";
static int* NETSTAT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ping logic cybol format.
 *
 * Description:
 *
 * Pings the given host via network, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="ping" channel="inline" format="command/ping" model="">
 *     <node name="host" channel="inline" format="text/plain" model="www.cybop.org"/>
 *     <node name="count" channel="inline" format="text/plain" model="5"/>
 *     <node name="interface" channel="inline" format="text/plain" model="eth0"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - host (required): host, to be pinged
 * - count (optional): count of ping packets to send
 * - interface (optional): interface to send packets on
 */
static wchar_t* PING_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ping";
static int* PING_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/pwd logic cybol format.
 *
 * Description:
 *
 * Prints the path of the current working directory, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - logical(optional): the logical option (logical output)
 * - physical(optional): the physical option (physical output)
 */
static wchar_t* PWD_COMMAND_LOGIC_CYBOL_FORMAT = L"command/pwd";
static int* PWD_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Description:
 *
 * Removes a file or directory via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="remove_file" channel="inline" format="command/remove" model="">
 *     <node name="path" channel="inline" format="text/plain" model="./shell_command_remove_file/do_not_commit_if_this_is_deleted.txt"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="interactive" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbose" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - path: the path including wildcards for deleting files and directories
 * - interactive (optional): the interactive option (askes everytime for permission of deleting a file or directory)
 * - recursive(optional): the recursive option (deletes any files in the current directory and in all of its subdirectories)
 * - verbose(optional): the verbose option (shows what have been deleted)
 */
static wchar_t* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/remove";
static int* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/sort logic cybol format.
 *
 * Description:
 *
 * Sorts the lines of a text file, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - file (required): file, to be sorted
 * - output (optional): path to output file
 */
static wchar_t* SORT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/sort";
static int* SORT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/spellcheck logic cybol format.
 *
 * Description:
 *
 * Spellchecks a file via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - path (required): path to the directory
 * - not follow symbolic link (optional): Do not follow symbolic links
 * - follow symbolic link (optional): Follow symbolic links
 * - change current drive (optional): change the current drive in addition to changing folder
 */
static wchar_t* SPELLCHECK_COMMAND_LOGIC_CYBOL_FORMAT = L"command/spellcheck";
static int* SPELLCHECK_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/system-messages logic cybol format.
 *
 * Description:
 *
 * Shows system messages from /var/log via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - human(optional): the human option (human-readable output)
 * - ctime(optional): the time-stamp option (print time in real time)
 * - kernel(optional): the kernel option (shows kernel messages)
 * - color(optional): the color option (colorizes the output)
 * - userspace(optional): the userspace option (shows messages of the userspace)
 */
static wchar_t* SYSTEM_MESSAGES_COMMAND_LOGIC_CYBOL_FORMAT = L"command/system-messages";
static int* SYSTEM_MESSAGES_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/tape-archiver logic cybol format.
 *
 * Description:
 *
 * Packs or unpacks a directory or file, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="pack_text_file_with_tape_archiver" channel="inline" format="command/tape-archiver" model="">
 *     <node name="source" channel="inline" format="text/plain" model="./shell_command_tape_archiver_pack/i_should_be_packed_soon.txt"/>
 *     <node name="destination" channel="inline" format="text/plain" model="./shell_command_tape_archiver_pack/i_am_packed_now.tar"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="gzip" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="unpack" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbose" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="unpack_tar_with_text_file" channel="inline" format="command/tape-archiver" model="">
 *     <node name="source" channel="inline" format="text/plain" model="./shell_command_tape_archiver_unpack/package.tar"/>
 *     <node name="destination" channel="inline" format="text/plain" model="./shell_command_tape_archiver_unpack"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="gzip" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="unpack" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbose" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - source (required): the source for archiving
 * - destination (required): the destination where the source is being archived
 * - force (optional): the force option for not asking for permission for overwriting files or directories
 * - gzip (optional): the gunzip option to indicate gunzip compression or extraction
 * - unpack (optional): the option for unpacking / extraction or else it will pack
 * - verbose (optional): shows which files and directories are being copied
 */
static wchar_t* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT = L"command/tape-archiver";
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/top logic cybol format.
 *
 * Description:
 *
 * Displays the linux processes, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* TOP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/top";
static int* TOP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/touch logic cybol format.
 *
 * Description:
 *
 * Changes the timestamp of a file via shell command. May be used to create a new file.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - path
 * - reference
 * - timestamp
 */
static wchar_t* TOUCH_COMMAND_LOGIC_CYBOL_FORMAT = L"command/touch";
static int* TOUCH_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/traceroute logic cybol format.
 *
 * Description:
 *
 * Traces and displays the packet route to the given host, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - host (required) [text/cybol-path | text/plain]: The host to trace the route to.
 */
static wchar_t* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/traceroute";
static int* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/userlog logic cybol format.
 *
 * Description:
 *
 * Shows the users currently logged in to the machine, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - options: -h, u, s, o
 */
static wchar_t* USERLOG_COMMAND_LOGIC_CYBOL_FORMAT = L"command/userlog";
static int* USERLOG_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/who logic cybol format.
 *
 * Description:
 *
 * Displays information about the current user, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* WHO_COMMAND_LOGIC_CYBOL_FORMAT = L"command/who";
static int* WHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/who-am-i logic cybol format.
 *
 * Description:
 *
 * Displays the login name of the current user, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * Properties:
 */
static wchar_t* WHO_AM_I_COMMAND_LOGIC_CYBOL_FORMAT = L"command/who-am-i";
static int* WHO_AM_I_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/word count logic cybol format.
 *
 * Description:
 *
 * Counts different occurences and outputs the number of rows, words and bytes for every file, via shell command.
 *
 * TODO: COMPLETE AND VERIFY YET!
 *
 * Examples:
 *
 * <node name="count_words" channel="inline" format="command/word-count" model="">
 *     <node name="path" channel="inline" format="text/plain" model="./shell_command_word_count/example.txt"/>
 *     <node name="bytes" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="chars" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="lines" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="max-line-length" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="words" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * - path (required): path to the file or directory
 * - bytes (optional): Outputs the number of bytes
 * - chars (optional): Outputs the number of chars
 * - lines (optional): Outputs the number of lines
 * - max-line-length (optional): Outputs the length of the longest line
 * - words (optional): Outputs the number of words
 */
static wchar_t* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/word-count";
static int* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
