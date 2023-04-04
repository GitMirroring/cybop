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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XDT_SERIALISER_SOURCE
#define XDT_SERIALISER_SOURCE

//
// Library interface
//

#include "logger.h"

//
// The "x DatenTransfer" (xDT) is the German version of
// "Electronic Data Interchange" (EDI) for medical practices.
// Here is an extract from xDT documentation, issued by the
// "Kassenaerztliche Bundesvereinigung" (KBV) at:
// http://www.kbv.de/ita/4274.html
//
// Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
//
// Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
// Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
// Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
// Natuerlich gibt es Parallelen, beispielsweise zu
// "EDI for Administration, Commerce and Transport" (EDIFACT),
// die in der artverwandten Zielsetzung begruendet liegen.
// Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
//
// Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
// Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
// die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
//
// Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
// numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
// feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
// vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
// werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
// gleichbedeutend mit Carriage return und Linefeed, verlangt.
//
// Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
// ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
// Eintrag der Feldtabelle herangezogen.
//
// Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
//
// Struktur eines Datenfeldes
//
// -----------------------------------------------------------------------------
// Feldteil         Laenge [Byte]       Bedeutung
// -----------------------------------------------------------------------------
// Laenge           3                   Feldlaenge in Bytes
// Kennung          4                   Feldkennung
// Inhalt           variabel            Abrechnungsinformationen
// Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
//                                      ASCII-Wert 10 = LF (Zeilenvorschub)
// -----------------------------------------------------------------------------
//
// Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
// available at:
// http://www.apw-wiegand.de/
//
// Patientennummerkonvertierung:
// Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
// Stelle 1: immer 1
// Stelle 2-3: Parallelabrechnungsnummer (meist 01)
// Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
// Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
// ab Stelle 8: ab Stelle 3 der APW-PatNr
//

/**
 * Serialises source into xdt.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 */
void serialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xdt.");
}

/* XDT_SERIALISER_SOURCE */
#endif
