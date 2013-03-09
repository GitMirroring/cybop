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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#include "../logger/logger.c"

/*??
int Cport[28], error;

struct termios new_port_settings, old_port_settings[28];

char comports[max_comports][13]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3","/dev/ttyS4","/dev/ttyS5",
                       "/dev/ttyS6","/dev/ttyS7","/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
                       "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15","/dev/ttyUSB0",
                       "/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5",
                       "/dev/ttyACM0", "/dev/ttyACM1", "/dev/ttyACM2", "/dev/ttyACM3", "/dev/ttyACM4","/dev/ttyACM5"};

int OpenComport(int comport_number, int baudrate) {

    int baudr;

    if((comport_number>27)||(comport_number<0))
    {
    printf("illegal comport number\n");
    return(1);
    }

    switch(baudrate)
    {
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
    default      : printf("invalid baudrate\n");
    return(1);
    break;
    }

    Cport[comport_number] = open(comports[comport_number], O_RDWR | O_NOCTTY | O_NDELAY);
    if(Cport[comport_number]==-1)
    {
    perror("unable to open comport ");
    return(1);
    }

    error = tcgetattr(Cport[comport_number], old_port_settings + comport_number);
    if(error==-1)
    {
    close(Cport[comport_number]);
    perror("unable to read portsettings ");
    return(1);
    }
    memset(&new_port_settings, 0, sizeof(new_port_settings));  // clear the new struct

    new_port_settings.c_cflag = baudr | CS8 | CLOCAL | CREAD;
    new_port_settings.c_iflag = IGNPAR;
    new_port_settings.c_oflag = 0;
    new_port_settings.c_lflag = 0;
    new_port_settings.c_cc[VMIN] = 0;      // block untill n bytes are received
    new_port_settings.c_cc[VTIME] = 0;     // block untill a timer expires (n * 100 mSec.)
    error = tcsetattr(Cport[comport_number], TCSANOW, &new_port_settings);
    if(error==-1)
    {
    close(Cport[comport_number]);
    perror("unable to adjust portsettings ");
    return(1);
    }

    return(0);
}
*/

/*??
int PollComport(int comport_number, unsigned char *buf, int size) {

    int n;

    #ifndef __STRICT_ANSI__                       // __STRICT_ANSI__ is defined when the -ansi option is used for gcc
    if(size>SSIZE_MAX)  size = (int)SSIZE_MAX;  // SSIZE_MAX is defined in limits.h
    #else
    if(size>4096)  size = 4096;
    #endif

    n = read(Cport[comport_number], buf, size);

    return(n);
}

int SendByte(int comport_number, unsigned char byte) {

    int n;

    n = write(Cport[comport_number], &byte, 1);
    if(n<0)  return(1);

    return(0);
}

int SendBuf(int comport_number, unsigned char *buf, int size) {

    return(write(Cport[comport_number], buf, size));
}

void CloseComport(int comport_number) {

    close(Cport[comport_number]);
    tcsetattr(Cport[comport_number], TCSANOW, old_port_settings + comport_number);
}

int IsCTSEnabled(int comport_number) {

    int status;

    status = ioctl(Cport[comport_number], TIOCMGET, &status);

    if(status&TIOCM_CTS) return(1);
    else return(0);
}
*/

/*??
void cprintf(int comport_number, const char *text) { // sends a string to serial port

    while(*text != 0)   SendByte(comport_number, *(text++));
}
*/

// ========== END OF LIB

/*??
int ReadChannel(int channel, int cport_nr) {

    unsigned char channel_command[8][4] = { "c01", "c02", "c03", "c04", "c05", "c06", "c07", "c08" } ;
    int rvalue, voltage, i, n;
    unsigned char buf[4], checksum;

    rvalue=SendBuf(cport_nr, channel_command[channel-1], 3);
    if (rvalue!=3)
    perror("Fehler: Kommando an Messkarte nicht gesendet!");

    for (i=0;i<=20;i++)
    {
    n = PollComport(cport_nr, buf, 4095);
    if(n > 0)
    {
    buf[n] = 0;   // always put a "null" at the end of a string!
    checksum = buf[0] + buf[1];
    if (checksum != buf[2])
    {
    perror("PrÃ¼fsumme falsch!");
    return(-1); // Fehler beim Vergleich der PrÃ¼fsumme
    }
    voltage = ((int)buf[0] * 256) + (int)buf[1];
    return(voltage);
    }
    usleep(100000);  // sleep for 100 milliSeconds
    } //end for
    return(-2); // Timeout 2s beim Polling des Ports
}  // end ReadChannel
*/

/*??
int main ( int argc, char *argv[] ) {

    int rvalue,i,r,x,n,pin1,pin2,status=-1;
    unsigned char buf[4];
    unsigned char m_value[7];
    int channel,channel1,channel2;
    int cport_nr=-1, mode=0, verbose=0;
    int voltage=0,voltage1=0,voltage2=0, reverse=0;
    double temperature=0;
    unsigned char usage[] = { "Aufruf: indoor_climate <OPTION> <COMPORT>\n \
                                -t KANAL          Temperatur von KANAL (0 bis 8) messen\n \
                                -a KANAL KANAL    Status der Klimaanlage abfragen\n \
                                -c COMPORT        Nummer des COMPORTs (0 bis 22)\n \
                                -r                Status KlimagerÃ¤t umkehren\n \
                                -l                Liste der COMPORTs ausgeben\n \
                                -v                AusfÃ¼hrliche Ausgabe\n\n" };

  if (argc==1)
  {
    printf("%s", usage);
    return(1);
  }

  for (i = 1; i < argc; i++)
  {
    if(      !strcmp( argv[i], "-t"     ) ) {
                                              if (mode==0)
                                                mode = 1; // mode 1 --> Temperatur
                                                else
                                                {
                                                  printf("%s", usage);
                                                  return(1);
                                                }
                                              if ((argc-1)>i) channel = strtol(argv[i+1], NULL, 10);
                                              if ((channel < 1) || (channel > 8))
                                              {
                                                printf("%s", usage);
                                                return(1);
                                              }
                                              i++;
                                            }
    else if( !strcmp( argv[i], "-a"     ) ) {
                                              if (mode==0)
                                                mode = 2; // mode 1 --> Temperatur
                                                else
                                                {
                                                  printf("%s", usage);
                                                  return(1);
                                                }
                                              if ((argc-1)>(i+1))
                                              {
                                                channel1 = strtol(argv[i+1], NULL, 10);
                                                channel2 = strtol(argv[i+2], NULL, 10);
                                              }
                                              if ((channel1 < 1) || (channel1 > 8) || (channel2 < 1) || (channel2 > 8)  )
                                              {
                                                printf("%s", usage);
                                                return(1);
                                              }
                                              i+=2;
                                            }
    else if( !strcmp( argv[i], "-c"     ) ) {
                                              if ((argc-1)>i) cport_nr = strtol(argv[i+1], NULL, 10);
                                              if ((cport_nr < 0) || (cport_nr >= max_comports))
                                              {
                                                printf("%s", usage);
                                                return(1);
                                              }
                                              i++;
                                            }
    else if( !strcmp( argv[i], "-r"     ) ) {
                                              if (reverse==0)
                                                  reverse = 1; // test 1 -->    KlimagerÃ¤tstatus

                                             else
                                              {
                                                printf("%s",usage);
                                                return (1);
                                              }
                                            }

    else if( !strcmp( argv[i], "-v"     ) ) {
                                              if (verbose==0)
                                                  verbose=1;
                                              else
                                              {
                                                printf("%s", usage);
                                                return(1);
                                              }
                                            }
    else if( !strcmp( argv[i], "-l"     ) ) {
                                              printf("Definiert sind folgende Comports:\n\n");
                                              for (i=1;i<max_comports;i++)
                                              {
                                                printf("%s\n", comports[i]);
                                              }
                                            printf("\n\n");
                                            return(1);
                                            }
    else if( !strcmp( argv[i], "--help" ) ) { printf("%s", usage);   //Help Nachricht ausgeben
                                              return(1);
                                            }
    else        {
                    printf("Unbekannter Parameter: %s\n", argv[i]);
                    printf("%s", usage);
                    return(1);
                }
    }

    if ((mode==1) && (reverse==1)) // diese Parameter sollten nicht kombiniert werden
    {
    printf("%s", usage);   //Help Nachricht ausgeben
    return(1);
    }

    if (verbose==1)
    {
    printf("Comport Nummer: %i ( %s )\n", cport_nr, comports[cport_nr]);
    if (mode==1) printf("Temperatur auf Kanal %i messen.\n", channel);
    if (mode==2) printf("Status KlimagerÃ¤t auf den KanÃ¤len %i und %i messen.\n", channel1, channel2);
    if (reverse==1) printf("Status KlimagerÃ¤t invertiert ausgeben.\n");
    printf("\n\n");
    }


    rvalue=OpenComport(cport_nr, 115200);
    if (rvalue!=0)
    {
    perror("Fehler: Port nicht initialisiert!");
    return(1);
    }


    if (mode==1)         //Messung Temperatur
    {
    for (i=1;i<=5;i++)
    {
    voltage=ReadChannel(channel, cport_nr);
    if (voltage >= 0)
    temperature += voltage;
    else
    {
    perror("Fehler bei der Messung der Temperatur.");
    return(1);
    }
    }
    temperature = temperature/50;
    printf("Sensorkanal: %i    Temperatur: %.1f Â°C\n", channel, temperature);    //Anzuzeigende Raumtemperatur
    } // Ende Temperaturmessung


    if (mode==2)         //Status KlimagerÃ¤t
    {
    for (r=1;r<=5;r++) // mehrere Ausleseversuche, falls Relais gerade umschaltet
    {
    for (i=1;i<=3;i++)
    {
    voltage1=ReadChannel(channel1, cport_nr);
    voltage2=ReadChannel(channel2, cport_nr);
    if ((voltage1 >= 0) && (voltage2 >= 0))
    {
    if (voltage1 <= 700) pin1+=1; // Spannung kleiner als 0,7 V --> Kontakt geschlossen
    if (voltage2 <= 700) pin2+=1; // Spannung kleiner als 0,7 V --> Kontakt geschlossen
    }
    } // end for
    if      ((pin1==3) && (pin2==0)) status=1; // GerÃ¤t ist an
    else if ((pin1==0) && (pin2==3)) status=0; // GerÃ¤t ist ausgeben
    else
    {
    pin1=0; pin2=0;
    }
    if (status != -1) break;
    } // end for meherere Ausleseversuche
    if (status != -1)
    {
    if (reverse == 1)
    if (status == 1) status = 0; else status = 1;
    printf("SensorkanÃ¤le: %i und %i    Status: %i \n", channel1, channel2, status);         //Anzuzeigender Status
    }
    else
    {
    perror("Fehler bei der Statusbestimmung des KlimagerÃ¤tes.");
    return(1);
    }
    } // Ende Status KlimagerÃ¤t

    if (verbose==1) printf("\n\nSchlieÃe Port...  \n\n");
    CloseComport(cport_nr);

    return(0);
}
*/

/**
 * Tests the serial port receive.
 */
void test_serial_port_receive() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test serial port receive.");
}

/**
 * Tests the serial port.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_serial_port() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test serial port.");

    test_serial_port_receive();
}

/* SERIAL_PORT_TESTER */
#endif
