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

#ifndef BAUDRATE_SERIAL_SYMBOLIC_NAME_VARIABLE_HEADER
#define BAUDRATE_SERIAL_SYMBOLIC_NAME_VARIABLE_HEADER

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// A symbolic name is a pre-processor define, e.g.:
//
// #define PF_INET     2   /* IP protocol family.  */
// #define AF_INET     PF_INET
//
// CAUTION! They CANNOT be handed over as reference to a function
// since otherwise, the compiler will show an error like:
// error: lvalue required as unary ‘&’ operand
//
// Therefore, these global variables are defined to hold the
// original value of the symbolic name and be used instead.
//
// CAUTION! The definition of pure integer constants is NOT possible,
// since the values of symbolic names DIFFER between operating systems.
// Therefore, global variables are used and the values of
// symbolic names assigned at runtime, when cyboi starts up.
//

//
// The baudrates below were mostly taken from:
//
// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Line-Speed
//

/** The b0 baudrate serial symbolic name. */
int B0_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B0_BAUDRATE_SERIAL_SYMBOLIC_NAME = B0_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b50 baudrate serial symbolic name. */
int B50_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B50_BAUDRATE_SERIAL_SYMBOLIC_NAME = B50_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b75 baudrate serial symbolic name. */
int B75_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B75_BAUDRATE_SERIAL_SYMBOLIC_NAME = B75_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b110 baudrate serial symbolic name. */
int B110_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B110_BAUDRATE_SERIAL_SYMBOLIC_NAME = B110_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b134 baudrate serial symbolic name. */
int B134_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B134_BAUDRATE_SERIAL_SYMBOLIC_NAME = B134_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b150 baudrate serial symbolic name. */
int B150_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B150_BAUDRATE_SERIAL_SYMBOLIC_NAME = B150_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b200 baudrate serial symbolic name. */
int B200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B200_BAUDRATE_SERIAL_SYMBOLIC_NAME = B200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b300 baudrate serial symbolic name. */
int B300_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B300_BAUDRATE_SERIAL_SYMBOLIC_NAME = B300_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b600 baudrate serial symbolic name. */
int B600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B600_BAUDRATE_SERIAL_SYMBOLIC_NAME = B600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b1200 baudrate serial symbolic name. */
int B1200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B1200_BAUDRATE_SERIAL_SYMBOLIC_NAME = B1200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b1800 baudrate serial symbolic name. */
int B1800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B1800_BAUDRATE_SERIAL_SYMBOLIC_NAME = B1800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b2400 baudrate serial symbolic name. */
int B2400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B2400_BAUDRATE_SERIAL_SYMBOLIC_NAME = B2400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b4800 baudrate serial symbolic name. */
int B4800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B4800_BAUDRATE_SERIAL_SYMBOLIC_NAME = B4800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b9600 baudrate serial symbolic name. */
int B9600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B9600_BAUDRATE_SERIAL_SYMBOLIC_NAME = B9600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b19200 baudrate serial symbolic name. */
int B19200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B19200_BAUDRATE_SERIAL_SYMBOLIC_NAME = B19200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b38400 baudrate serial symbolic name. */
int B38400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B38400_BAUDRATE_SERIAL_SYMBOLIC_NAME = B38400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b57600 baudrate serial symbolic name. */
int B57600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B57600_BAUDRATE_SERIAL_SYMBOLIC_NAME = B57600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b115200 baudrate serial symbolic name. */
int B115200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B115200_BAUDRATE_SERIAL_SYMBOLIC_NAME = B115200_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b230400 baudrate serial symbolic name. */
int B230400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B230400_BAUDRATE_SERIAL_SYMBOLIC_NAME = B230400_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b460800 baudrate serial symbolic name. */
int B460800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B460800_BAUDRATE_SERIAL_SYMBOLIC_NAME = B460800_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b500000 baudrate serial symbolic name. */
int B500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B500000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b576000 baudrate serial symbolic name. */
int B576000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B576000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B576000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b921600 baudrate serial symbolic name. */
int B921600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B921600_BAUDRATE_SERIAL_SYMBOLIC_NAME = B921600_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b1000000 baudrate serial symbolic name. */
int B1000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B1000000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B1000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b1152000 baudrate serial symbolic name. */
int B1152000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B1152000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B1152000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b1500000 baudrate serial symbolic name. */
int B1500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B1500000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B1500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b2000000 baudrate serial symbolic name. */
int B2000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B2000000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B2000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b2500000 baudrate serial symbolic name. */
int B2500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B2500000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B2500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b3000000 baudrate serial symbolic name. */
int B3000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B3000000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B3000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b3500000 baudrate serial symbolic name. */
int B3500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B3500000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B3500000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/** The b4000000 baudrate serial symbolic name. */
int B4000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY[1];
int* B4000000_BAUDRATE_SERIAL_SYMBOLIC_NAME = B4000000_BAUDRATE_SERIAL_SYMBOLIC_NAME_ARRAY;

/* BAUDRATE_SERIAL_SYMBOLIC_NAME_VARIABLE_HEADER */
#endif
