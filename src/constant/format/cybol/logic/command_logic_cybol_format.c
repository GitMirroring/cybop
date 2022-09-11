/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
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
 * Archive the given files into a packed format.
 *
 * Description:
 *
Archives the given data into a file.
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
 * - TODO (required | optional) [text/cybol-path]: TODO
create	The option for creating an archive.	false	logicvalue/boolean
update	The option for updating an archive.	false	logicvalue/boolean
bzip2	The option for using the bzip2 compression algorithm.	false	logicvalue/boolean
 *
 * Expected parametres:
 * - create (optional): the option for creating an archive
 * - update (optional): the option for updating an archive
 * - bzip2 (optional): the option for using the bzip2 compression algorithm
 */
static wchar_t* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/archive";
static int* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-directory logic cybol format.
 *
 * Change the directory.
 *
 * Description:
 *
Changes the directory.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path (required): path to the directory
 * - not follow symbolic link (optional): Do not follow symbolic links
 * - follow symbolic link (optional): Follow symbolic links
 * - change current drive (optional): change the current drive in addition to changing folder
 */
static wchar_t* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-directory";
static int* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-permission logic cybol format.
 *
 * Changes the permission of a file or directory.
 *
 * Description:
 *
Changes the permission of a file or directory.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path (required): path to the file or directory
 * - user (required)
 * - group (required)
 * - other (required)
 * - recursive (optional): change files and directories recursively
 * - silent (optional): supress most error messages
 * - verbose (optional): output a diagnostic for every file processed
 */
static wchar_t* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-permission";
static int* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/clear logic cybol format.
 *
 * Clear the terminal (console) screen.
 *
 * Description:
 *
clear the screen
 *
 * Examples:
 *
 * <node name="clear" channel="inline" format="command/clear" model="">
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - none
 */
static wchar_t* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT = L"command/clear";
static int* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/compare-files logic cybol format.
 *
 * Compare two files.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path1 (required): path1 to the file
 * - path2 (required): path2 to the file
 * - print differing chars (optional, Unix): Print the differing characters.
 * - print offset (optional, Unix): Print the (decimal) offsets and (octal) values of all differing bytes.
 * - silent (optional, Unix): Do not print anything; only return an exit status indicating whether the files differ.
 * - case insensitive (optional, Win32): Do a case insensitive string comparison
 * - compare unicode (optional, Win32): Compare files as UNICODE text files.
 * - compare ascii (optional, Win32): Compare files as ASCII text files.
 * - display line numbers (optional, Win32): Display line numbers
 * - compress whitespace (optional, Win32): Compress white space
 */
static wchar_t* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT = L"command/compare-files";
static int* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/config-network logic cybol format.
 *
 * Configure the network.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - ??
 */
static wchar_t* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT = L"command/config-network";
static int* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/copy logic cybol format.
 *
 * Copy the given file into another.
 * Copies the file resource to a destination.
 *
 * Description:
 *
Copies the file resource to a destination.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - source (required): the source to be copied
 * - destination (required): the destination to copy to
 * - force (optional): the force option for not asking for permission for overwriting files or directories
 * - interactive (optional): the interactive option which askes everytime for permission of overwriting a file or directory
 * - preserve_all_attributes (optional): copied files and directories will have the same attributes as the originals
 * - preserve_links (optional): preserves links so that they are not dereferenced while copying
 * - recursive (optional): the option indicating that all sub directories should be copied as well
 * - update (optional): the update option which just copies more recent data to a destination path
 * - verbal (optional): shows which files and directories are being copied
 */
static wchar_t* COPY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/copy";
static int* COPY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/create-folder logic cybol format.
 *
 * Creates a directory also called folder in the file system.
 *
 * Description:
 *
Creates a folder.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path (required): path to the directory
 */
static wchar_t* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT = L"command/create-folder";
static int* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/date logic cybol format.
 *
 * Print out the date or change it.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - new date (optional): value of the new date
 *
 * - /T (optional): display option (display date, Win32 only)
 * - -I (optional): the ISO option (date in ISO format)
 * - -R (optional): the RFC option (date in RFC format)
 * - -u (optional): the UTC option (date in UTC format)
 */
static wchar_t* DATE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/date";
static int* DATE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/delay logic cybol format.
 *
 * Delay for a few seconds.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - time (required): time in seconds
 */
static wchar_t* DELAY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/delay";
static int* DELAY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/diff logic cybol format.
 *
 * Displays differences between two files.
 *
 * Description:
 *
Compares two files.
 *
 * Examples:
 *
 * <node name="diff" channel="inline" format="command/diff" model="">
 *     <node name="file1" channel="inline" format="text/plain" model="shell_command_diff\diff1.txt"/>
 *     <node name="file2" channel="inline" format="text/plain" model="shell_command_diff\diff2.txt"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
file1	first file to compare	true	text/plain
file2	second file to compare	true	text/plain
 *
 * Expected parametres:
 * - first file (required): first file to compare
 * - second file (required): second file to compare
 */
static wchar_t* DIFF_COMMAND_LOGIC_CYBOL_FORMAT = L"command/diff";
static int* DIFF_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/disk-free logic cybol format.
 *
 * Display free disk space.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - all (optional): the all option (lists filesystems with a size of 0 blocks)
 * - human(optional): the human option (human-readable output)
 * - kilobytes(optional): the kilobytes option (print sizes in kilobytes)
 * - local (optional): the local option (limit the listing to local filesystems)
 * - megabytes(optional): the megabytes option (print sizes in megabytes)
 * - type(optional): the print type option (print each filesystems type)
 */
static wchar_t* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/disk-free";
static int* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/disk-usage logic cybol format.
 *
 * Shows the usage of a directory.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - human(optional): the human option (human-readable output)
 * - summarize(optional): the summarize option (prints a summarize)
 * - all(optional): the all option (prints all)
 * - bytes(optional): the bytes option (prints sizes in bytes)
 * - total(optional): the total option (prints total usage)
 */
static wchar_t* DISK_USAGE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/disk-usage";
static int* DISK_USAGE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/display-content logic cybol format.
 *
 * Display the content of one or more text files
 *
 * Description:
 *
Display the content.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
path	the listing for the given path (the default is the current directory)	false	text/plain
squeze	???	false	logicvalue/boolean
number-lines	???	false	logicvalue/boolean
clear	???	false	logicvalue/boolean
 *
 * Expected parametres:
 * - path (required): path to the file
 * - clear screen (optional): Clear screen before displaying page
 * - display line numbers (optional): number all output lines
 * - squeeze (optional): Squeeze multiple blank lines into a single line
 */
static wchar_t* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/display-content";
static int* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/echo logic cybol format.
 *
 * Echo a given message to the standard output.
 *
 * Description:
 *
Echos the message to standard output.
 *
 * Examples:
 *
 * <node name="echo" channel="inline" format="command/echo" model="">
 *     <node name="message" channel="inline" format="text/plain"
      model="hello, this is an echo over standard output"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
message	the message which should be directed to the standard output	false	text/plain
 *
 * Expected parametres:
 * - message (optional): the message which should be directed to the standard output
 */
static wchar_t* ECHO_COMMAND_LOGIC_CYBOL_FORMAT = L"command/echo";
static int* ECHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-command logic cybol format.
 *
 * Locates the binary, source, and manual page files for a command.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - command (required): command to be processed
 * - binary (optional, Unix): Search only for binaries.
 * - manual (optional, Unix): Search only for manual sections.
 * - source (optional, Unix): Search only for source files.
 */
static wchar_t* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-command";
static int* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-file logic cybol format.
 *
 * Find a file.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path: the path including wildcards for deleting files and directories
 * - insensitive (optional): the insensitive option (ignore upper/lowercase when searching for a file, Unix only)
 * - recursive(optional): the recursive option (recursive search, Windows only)
 */
static wchar_t* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-file";
static int* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/grep logic cybol format.
 *
 * Searches for a pattern in the file and prints out those lines matching the pattern.
 *
 * Description:
 *
Searches for pattern in file.
 *
 * Examples:
 *
 * <node name="grep" channel="inline" format="command/grep" model="">
 *     <node name="pattern" channel="inline" format="text/plain" model="test"/>
 *     <node name="file" channel="inline" format="text/plain" model="shell_command_grep/grep.txt"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
pattern	the pattern to search for	true	text/plain
file	the file to search in	true	text/plain
 *
 * Expected parametres:
 * - pattern (required): pattern, to search for
 * - file (required): file, to search in
 */
static wchar_t* GREP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/grep";
static int* GREP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/help logic cybol format.
 *
 * Display information about a system command.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - pattern (required): the command for which information should be displayed
 */
static wchar_t* HELP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/help";
static int* HELP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/hostname logic cybol format.
 *
 * Display the name of the host (machine).
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - none
 *
 * Options: d, f, i, I, s
 */
static wchar_t* HOSTNAME_COMMAND_LOGIC_CYBOL_FORMAT = L"command/hostname";
static int* HOSTNAME_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/id logic cybol format.
 *
 * Display id.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* ID_COMMAND_LOGIC_CYBOL_FORMAT = L"command/id";
static int* ID_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ifconfig logic cybol format.
 *
 * Display ifconfig.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* IFCONFIG_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ifconfig";
static int* IFCONFIG_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ifup logic cybol format.
 *
 * Shows if the interface is available.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* IFUP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ifup";
static int* IFUP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/kill logic cybol format.
 *
 * Kill a process.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parameters:
 * - pid (required): the number of process to be killed off
 */
static wchar_t* KILL_COMMAND_LOGIC_CYBOL_FORMAT = L"command/kill";
static int* KILL_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/list-directory-contents logic cybol format.
 *
 * List contents of the given directory.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
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
 * Shows open files in operating system.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
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
 * List all the processes currently running on the computer.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - keyword(optional): the keyword option (list all the keyword options)
 * - verbose(optional): the verbose option (verbose output)
 */
static wchar_t* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-tasks";
static int* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/memory-free logic cybol format.
 *
 * Shows the usage of the RAM.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
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
 * Moves a file or directory to a destination path.
 *
 * Description:
 *
Moving directories from a path to another.
 *
 * Examples:
 *
 * <node name="move_file" channel="inline" format="command/move" model="">
 *     <node name="source" channel="inline" format="text/plain"
      model="./shell_command_move_file/original.txt"/>
 *     <node name="destination" channel="inline" format="text/plain"
      model="./shell_command_move_file/moved_and_please_do_not_commit_me.txt"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="interactive" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="verbal" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
source	the path of the directory which sould be moved	true	text/plain
destination	the path of the directory which sould be moved	true	text/plain
force	the force option (never ask for permission to move any directories)	false	logicvalue/boolean
interactive	the interactive option (askes everytime for permission of moving a directory)	false	logicvalue/boolean
verbal	the verbal option (shows what have been moved)	false	logicvalue/boolean
 *
 * Expected parametres:
 * - source (required): the path of the file or the directory which sould be moved
 * - destination (required): the new path of the source file or directory
 * - force (optional): the force option (never ask for permission to move any files or directories)
 * - interactive (optional): the interactive option (askes everytime for permission of moving a file or directory)
 * - verbal(optional): the verbal option (shows what have been moved)
 */
static wchar_t* MOVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/move";
static int* MOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/netstat logic cybol format.
 *
 * Display network information.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - none
 *
 * Options: -r, i, g, s, M, v, n, e, p, l, a, o, t
 */
static wchar_t* NETSTAT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/netstat";
static int* NETSTAT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ping logic cybol format.
 *
 * Pings the given host via network.
 *
 * Description:
 *
Pings a given host.
 *
 * Examples:
 *
 * <node name="ping" channel="inline" format="command/ping" model="">
 *     <node name="host" channel="inline" format="text/plain" model="www.google.com"/>
 *     <node name="count" channel="inline" format="text/plain" model="5"/>
 *     <node name="interface" channel="inline" format="text/plain" model="eth0"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
host	the host to be pinged	true	text/plain
count	count of ping packets to send	false	text/plain
interface	interface to send packets on	false	text/plain
 *
 * Expected parametres:
 * - host (required): host, to be pinged
 * - count (optional): count of ping packets to send
 * - interface (optional): interface to send packets on
 */
static wchar_t* PING_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ping";
static int* PING_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/pwd logic cybol format.
 *
 * Shows the path of the present working directory.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - logical(optional): the logical option (logical output)
 * - physical(optional): the physical option (physical output)
 */
static wchar_t* PWD_COMMAND_LOGIC_CYBOL_FORMAT = L"command/pwd";
static int* PWD_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Removes a file or directory.
 *
 * Description:
 *
Moving directories from one path to another..
 *
 * Examples:
 *
 * <node name="remove_file" channel="inline" format="command/remove" model="">
 *     <node name="path" channel="inline" format="text/plain"
      model="./shell_command_remove_file/do_not_commit_if_this_is_deleted.txt"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="interactive" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbal" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
path	the path including wildcards for deleting directories	true	text/plain
interactive	the interactive option (askes everytime for permission of deleting a directory)	false	logicvalue/boolean
recursive	the recursvie option (deletes all of its subdirectories)	false	logicvalue/boolean
verbal	the verbal option (shows what have been moved)	false	logicvalue/boolean
 *
 * Expected parametres:
 * - path: the path including wildcards for deleting files and directories
 * - interactive (optional): the interactive option (askes everytime for permission of deleting a file or directory)
 * - recursive(optional): the recursive option (deletes any files in the current directory and in all of its subdirectories)
 * - verbal(optional): the verbal option (shows what have been deleted)
 */
static wchar_t* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/remove";
static int* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/sort logic cybol format.
 *
 * Sorts a file.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - file (required): file, to be sorted
 * - output (optional): path to output file
 */
static wchar_t* SORT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/sort";
static int* SORT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/spellcheck logic cybol format.
 *
 * Spellcheck a file.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
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
 * Shows system messages from /var/log.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
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
 * Packs or unpacks a directory or file.
 *
 * Description:
 *
Moving files and directories from a path to another..
 *
 * Examples:
 *
<!-- pack -->

<node name="pack_text_file_with_tape_archiver" channel="inline" format="command/tape-archiver" model="">
 *     <node name="source" channel="inline" format="text/plain"
      model="./shell_command_tape_archiver_pack/i_should_be_packed_soon.txt"/>
 *     <node name="destination" channel="inline" format="text/plain"
      model="./shell_command_tape_archiver_pack/i_am_packed_now.tar"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="gzip" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="unpack" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbal" channel="inline" format="logicvalue/boolean" model="true"/>
  * </node>

<!-- unpack -->

<node name="unpack_tar_with_text_file" channel="inline" format="command/tape-archiver" model="">
 *     <node name="source" channel="inline" format="text/plain"
      model="./shell_command_tape_archiver_unpack/package.tar"/>
 *     <node name="destination" channel="inline" format="text/plain"
      model="./shell_command_tape_archiver_unpack"/>
 *     <node name="force" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="gzip" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="unpack" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="recursive" channel="inline" format="logicvalue/boolean" model="false"/>
 *     <node name="verbal" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
source	the source for archiving	true	text/plain
destination	the destination where the source is being archived	true	text/plain
force	the force option for not asking for permission for overwriting files or directories	false	logicvalue/boolean
gzip	the gunzip option to indicate gunzip compression or extraction	false	logicvalue/boolean
unpack	the option for unpacking / extraction or else it will pack	false	logicvalue/boolean
recursive	???	false	logicvalue/boolean
verbal	shows which files and directories are being copied	false	logicvalue/boolean
 *
 * Expected parametres:
 * - source (required): the source for archiving
 * - destination (required): the destination where the source is being archived
 * - force (optional): the force option for not asking for permission for overwriting files or directories
 * - gzip (optional): the gunzip option to indicate gunzip compression or extraction
 * - unpack (optional): the option for unpacking / extraction or else it will pack
 * - verbal (optional): shows which files and directories are being copied
 */
static wchar_t* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT = L"command/tape-archiver";
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/top logic cybol format.
 *
 * Display top.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* TOP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/top";
static int* TOP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/touch logic cybol format.
 *
 * Creates a new file.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - path
 * - reference
 * - timestamp
 */
static wchar_t* TOUCH_COMMAND_LOGIC_CYBOL_FORMAT = L"command/touch";
static int* TOUCH_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/traceroute logic cybol format.
 *
 * Traces and displays the packet route to the given host.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - host (required): host, to trace the route to
 */
static wchar_t* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/traceroute";
static int* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/userlog logic cybol format.
 *
 * Shows the users currently logged in to the machine.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - none
 *
 * Options: -h, u, s, o
 */
static wchar_t* USERLOG_COMMAND_LOGIC_CYBOL_FORMAT = L"command/userlog";
static int* USERLOG_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/who logic cybol format.
 *
 * Display information about the current user.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* WHO_COMMAND_LOGIC_CYBOL_FORMAT = L"command/who";
static int* WHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/who-am-i logic cybol format.
 *
 * Display the login name of the current user.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* WHO_AM_I_COMMAND_LOGIC_CYBOL_FORMAT = L"command/who-am-i";
static int* WHO_AM_I_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/word count logic cybol format.
 *
 * Outputs the number of rows, words and bytes for every file.
 *
 * Description:
 *
Count different occurences.
 *
 * Examples:
 *
 * <node name="chmod_file" channel="inline" format="command/word-count" model="">
 *     <node name="path" channel="inline" format="text/plain"
      model="./shell_command_word_count/example.txt"/>
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
path	path to the file or directory	true	text/plain
bytes	Outputs the number of bytes	false	logicvalue/boolean
chars	Outputs the number of chars	false	logicvalue/boolean
lines	Outputs the number of lines	false	logicvalue/boolean
max-line-length	Outputs the length of the longest line	false	logicvalue/boolean
words	Outputs the number of words	false	logicvalue/boolean
 *
 * Expected parametres:
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
