/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "logger.h"
#include "xdt.h"

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
 * Deserialises xdt bdt data.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source bdt data
 * @param p3 the source bdt count
 */
void deserialise_xdt_bdt(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt bdt.");

    deserialise_xdt_bdt_records(p0, p1, p2, p3);
}
