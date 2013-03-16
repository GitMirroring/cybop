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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_TESTER
#define SERIAL_PORT_TESTER

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/modifier/copier/array_copier.c"
#include "../executor/modifier/copier/item_copier.c"
#include "../executor/modifier/copier/part_copier.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/allocator/item_allocator.c"
#include "../executor/memoriser/allocator/part_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"
#include "../executor/memoriser/deallocator/item_deallocator.c"
#include "../executor/memoriser/deallocator/part_deallocator.c"
#include "../executor/modifier/overwriter/item_overwriter.c"
#include "../executor/modifier/overwriter/part_overwriter.c"
#include "../executor/runner/nano_sleeper.c"
#include "../executor/runner/second_sleeper.c"
#include "../executor/runner/sleeper.c"
#include "../logger/logger.c"

int Cport[28], error;

struct termios new_port_settings, old_port_settings[28];

#define max_comports 28
char comports[max_comports][13] = {"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3","/dev/ttyS4","/dev/ttyS5",
                       "/dev/ttyS6","/dev/ttyS7","/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
                       "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15","/dev/ttyUSB0",
                       "/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5",
                       "/dev/ttyACM0", "/dev/ttyACM1", "/dev/ttyACM2", "/dev/ttyACM3", "/dev/ttyACM4","/dev/ttyACM5"};

int OpenComport(int comport_number, int baudrate) {

    int baudr;

    if ((comport_number > 27) || (comport_number < 0)) {

        fwprintf(stdout, L"illegal comport number\n");
        return(1);
    }

    switch(baudrate) {

        case      50 : baudr = B50;
        break;
        case      75 : baudr = B75;
        break;
        case     110 : baudr = B110;
        break;
        case     134 : baudr = B134;
        break;
        case     150 : baudr = B150;
        break;
        case     200 : baudr = B200;
        break;
        case     300 : baudr = B300;
        break;
        case     600 : baudr = B600;
        break;
        case    1200 : baudr = B1200;
        break;
        case    1800 : baudr = B1800;
        break;
        case    2400 : baudr = B2400;
        break;
        case    4800 : baudr = B4800;
        break;
        case    9600 : baudr = B9600;
        break;
        case   19200 : baudr = B19200;
        break;
        case   38400 : baudr = B38400;
        break;
        case   57600 : baudr = B57600;
        break;
        case  115200 : baudr = B115200;
        break;
        case  230400 : baudr = B230400;
        break;
        case  460800 : baudr = B460800;
        break;
        case  500000 : baudr = B500000;
        break;
        case  576000 : baudr = B576000;
        break;
        case  921600 : baudr = B921600;
        break;
        case 1000000 : baudr = B1000000;
        break;
        default      : fwprintf(stdout, L"invalid baudrate\n");
        return(1);
        break;
    }

    Cport[comport_number] = open(comports[comport_number], O_RDWR | O_NOCTTY | O_NDELAY);

    if (Cport[comport_number] == -1) {

        perror("unable to open comport ");
        return(1);
    }

    error = tcgetattr(Cport[comport_number], old_port_settings + comport_number);

    if (error == -1) {

        close(Cport[comport_number]);
        perror("unable to read portsettings ");
        return(1);
    }

    memset(&new_port_settings, 0, sizeof(new_port_settings));  // clear the new struct

fwprintf(stdout, L"TEST baudrate: %i\n", baudr);

    new_port_settings.c_cflag = baudr | CS8 | CLOCAL | CREAD;
    new_port_settings.c_iflag = IGNPAR;
    new_port_settings.c_oflag = 0;
    new_port_settings.c_lflag = 0;
    new_port_settings.c_cc[VMIN] = 0;      // block untill n bytes are received
    new_port_settings.c_cc[VTIME] = 0;     // block untill a timer expires (n * 100 mSec.)

    error = tcsetattr(Cport[comport_number], TCSANOW, &new_port_settings);

    if (error == -1) {

        close(Cport[comport_number]);
        perror("unable to adjust portsettings ");
        return(1);
    }

    return(0);
}

int PollComport(int comport_number, unsigned char* buf, int size) {

    int n;

#ifndef __STRICT_ANSI__                       // __STRICT_ANSI__ is defined when the -ansi option is used for gcc
    if (size > SSIZE_MAX) size = (int) SSIZE_MAX; // SSIZE_MAX is defined in limits.h
#else
    if (size > 4096) size = 4096;
#endif

    n = read(Cport[comport_number], buf, size);

    return (n);
}

int SendByte(int comport_number, unsigned char byte) {

    int n;

    n = write(Cport[comport_number], &byte, 1);

    if (n < 0)
        return (1);

    return (0);
}

int SendBuf(int comport_number, unsigned char* buf, int size) {

    return (write(Cport[comport_number], buf, size));
}

void CloseComport(int comport_number) {

    close(Cport[comport_number]);
    tcsetattr(Cport[comport_number], TCSANOW, old_port_settings + comport_number);
}

int IsCTSEnabled(int comport_number) {

    int status;

    status = ioctl(Cport[comport_number], TIOCMGET, &status);

    if (status & TIOCM_CTS)
        return (1);
    else
        return (0);
}

/*??
void cprintf(int comport_number, const char *text) { // sends a string to serial port

    while(*text != 0)   SendByte(comport_number, *(text++));
}
*/

// ========== END OF LIB

int ReadChannel(int channel, int cport_nr) {

    unsigned char channel_command[8][4] = {"c01", "c02", "c03", "c04", "c05", "c06", "c07", "c08"};
    int rvalue, voltage, i, n;
    unsigned char buf[4], checksum;

    rvalue = SendBuf(cport_nr, channel_command[channel-1], 3);

    if (rvalue != 3)
        perror("Fehler: Kommando an Messkarte nicht gesendet!");

    for (i = 0; i <= 20; i++) {

        n = PollComport(cport_nr, buf, 4095);

fwprintf(stdout, L"TEST buf[0]: %i\n", buf[0]);
fwprintf(stdout, L"TEST buf[1]: %i\n", buf[1]);
fwprintf(stdout, L"TEST buf[2]: %i\n", buf[2]);

        if (n > 0) {

            buf[n] = 0;   // always put a "null" at the end of a string!
            checksum = buf[0] + buf[1];

fwprintf(stdout, L"TEST checksum calc: %i\n", checksum);

            if (checksum != buf[2]) {

                perror("PrÃ¼fsumme falsch!");

                return (-1); // Fehler beim Vergleich der PrÃ¼fsumme
            }

            voltage = ((int) buf[0] * 256) + (int) buf[1];

fwprintf(stdout, L"TEST voltage: %i\n", voltage);

            return (voltage);
        }

        usleep(100000); // sleep for 100 milliSeconds
    }

    return (-2); // Timeout 2s beim Polling des Ports
}

/**
 * Tests the serial port temperature.
 */
void test_serial_port_temperature() {

    fwprintf(stdout, L"TEST serial port temperature.\n");

    int rvalue, i, r, x, n, pin1, pin2, status = -1;
    unsigned char buf[4];
    unsigned char m_value[7];
    int channel, channel1, channel2;
    // Nummer des COMPORTs (0 bis 22); /dev/ttyACM0 is 22
    int cport_nr = 22;
    int voltage = 0, voltage1 = 0, voltage2 = 0, reverse = 0;
    double temperature = 0;
    // Kanal kann sein: 1 ... 8
    channel = 1;

    fwprintf(stdout, L"Comport Nummer: %i ( %s )\n", cport_nr, comports[cport_nr]);
    fwprintf(stdout, L"Temperatur auf Kanal %i messen.\n", channel);
    fwprintf(stdout, L"\n\n");

    rvalue = OpenComport(cport_nr, 115200);

    if (rvalue != 0) {

        perror("Fehler: Port nicht initialisiert!");
    }

    // Messung Temperatur

    // Mehrere Ausleseversuche, falls Relais gerade umschaltet.
    for (i = 1; i <= 5; i++) {

        voltage = ReadChannel(channel, cport_nr);

        if (voltage >= 0) {

            temperature += voltage;

        } else {

            perror("Fehler bei der Messung der Temperatur.");
        }
    }

    temperature = temperature / 50;

    // Anzuzeigende Raumtemperatur
    fwprintf(stdout, L"Sensorkanal: %i Temperatur: %.1f °C\n", channel, temperature);

    fwprintf(stdout, L"\n\nSchließe Port...  \n\n");
    CloseComport(cport_nr);
}

/**
 * Tests the serial port sleep.
 */
void test_serial_port_sleep() {

    fwprintf(stdout, L"TEST serial port sleep.\n");

    // The duration.
    int d = 0;

    fwprintf(stdout, L"TEST serial port sleep for 1 ms ...\n");
    d = 1000000;
    sleep_nano((void*) &d);

    fwprintf(stdout, L"TEST serial port sleep for 1 s ...\n");
    d = 1;
    sleep_second((void*) &d);

    fwprintf(stdout, L"TEST serial port sleep for 5 s ...\n");
    d = 5;
    sleep_second((void*) &d);

    fwprintf(stdout, L"TEST serial port general call sleep for 20 us ...\n");
    d = 20000;
    sleep_duration((void*) &d, (void*) NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT);

    fwprintf(stdout, L"TEST serial port general call sleep for 3 s ...\n");
    d = 3;
    sleep_duration((void*) &d, (void*) SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT);
}

/**
 * Tests the serial port.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_serial_port() {

    fwprintf(stdout, L"TEST serial port.\n");

    test_serial_port_temperature();
//    test_serial_port_sleep();
}

/* SERIAL_PORT_TESTER */
#endif
